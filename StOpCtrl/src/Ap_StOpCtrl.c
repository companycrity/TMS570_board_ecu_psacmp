/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_StOpCtrl.c
 *     Workspace:  C:/SynergyWorkArea/Working/StOpCtrl-czmgrw/StOpCtrl/autosar
 *     SW-C Type:  Ap_StOpCtrl
 *  Generated at:  Tue Aug  4 16:42:25 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_StOpCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name	: StOpCtrl.c
* Module Description: Implementation of SF05 State Output Control
* Project           : CBD
* Author            : Jeremy Warmbier
*
* Module File Name: Ap_StOpCtrl.c
*
****************************************************************************
 * Version Control:
 * %version:          24 %
 * %derived_by:       czmgrw %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   ------- ---------  ---------------------------------------------------------------------------  ----------
 * 01/12/11  3       JJW       New generation of Davinci template
 * 01/13/11  4       JJW       Initial ramping queue implementation
 * 01/14/11  5       JJW       Corrected IRV buffered write of AttenFactor
 *                             Added F2 ramp actions
 * 01/14/11  6       JJW       Corrected Operate request logic
 * 02/28/11  8       LWW       Added F1Flag check in Per2
 * 03/26/11  9       JJW       System Framework Update
 * 03/26/11  10      JJW       Remove F1 Fault Flag, implement Cancel Ramp Request Server Runnable
 * 04/11/11  11      LWW       Updated for states and modes design changes
 * 04/11/11  12      LWW       Changed ramping calculation order for A_2265
 * 06/01/11  13      JJW       Template update to provide SrlComSvcDft access for ramp defeat
 * 01/05/12  14      NRAR      Updated as per FDD SF05, Ver OO1c
 * 01/06/12  15      NRAR      D_MAXRAMP_XPMS_F32 Value is changed
 * 01/12/12  16      NRAR      DiagStsF1Active variable name is updated to standard form DiagStsDiagRmpActive
 * 08/11/12  20      BWL       Anom #3272 PrevTargetRampMult is the last target, and PrevOutputRampMult is the last output.
 * 09/23/12  21      Selva     Checkpoints added and mempmap macros corrected		                          6247
 * 01/21/15	 22		 SB		   Updated to SF-5 v003: Added Requirement Tags									  12968
 * 04/10/15	 23		 KK and KMC	Updated to SF-05 v004 based on FDD v4.0.0									  13125
 * 07/24/15  24      JK        Anomaly fix for v004 in the if/else logic in the target selection block        13503
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_StOpCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "GlobalMacro.h"
#include <float.h>

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */ 

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 
#define D_BIGSLEW_ULSPS_F32			500.0F
#define D_RATELIMITLO_ULSPS_F32		0.01F
#define D_RATELIMITHI_ULSPS_F32		500.0F
#define D_TARGETSCALELO_ULS_F32 	0.0F
#define D_TARGETSCALEHI_ULS_F32 	1.0F
#define D_EPSILON_ULS_F32			FLT_EPSILON
#define D_SECTOMILLISEC_MSPSEC_F32	1000.0F
#define D_OPER_CNT_U08				1u
#define D_LOA_CNT_U08				2u
#define D_STRTSTOP_CNT_U08			3u
#define D_DIAG_CNT_U08				4u


#define STOPCTRL_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32,  STOPCTRL_VAR_NOINIT) StOpCtrl_ScaleSV_Uls_M_f32;				
STATIC volatile VAR(float32,  STOPCTRL_VAR_CLEARED) StOpCtrl_RateLimit_UlspS_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32,  STOPCTRL_VAR_CLEARED) StOpCtrl_TargetScale_Uls_D_f32;		/* PRQA S 3218 */
#define STOPCTRL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

#define STOPCTRL_START_SEC_VAR_INIT_08
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint8, STOPCTRL_VAR_CLEARED) StOpCtrl_State_Cnt_M_u08 = D_OPER_CNT_U08;						
STATIC VAR(uint8, STOPCTRL_VAR_CLEARED) StOpCtrl_RateSource_Cnt_M_u08 = D_OPER_CNT_U08;					/* PRQA S 3218 */
#define STOPCTRL_STOP_SEC_VAR_INIT_08
#include "MemMap.h"/* PRQA S 5087 */

STATIC FUNC (void, 	AP_STOPCTRL_CODE) TargetSelection (VAR(float32, AUTOMATIC) OperScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) LoaScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) StrtStopScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) OperRateLimit_UlspS_T_f32, 
														VAR(float32, AUTOMATIC) LoaRateLimit_UlspS_T_f32, 
														VAR(float32, AUTOMATIC) StrtStopRateLimit_UlspS_T_f32, 
														P2VAR(float32, AUTOMATIC, AP_STOPCTRL_APPL_VAR) SelRampValue_Uls_T_f32, 
														P2VAR(float32, AUTOMATIC, AP_STOPCTRL_APPL_VAR) SelRampRate_UlspS_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_STOPCTRL_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StOpCtrl_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_StOpCtrl_Per1_DiagRampRate_XpmS_f32(void)
 *   Float Rte_IRead_StOpCtrl_Per1_DiagRampValue_Uls_f32(void)
 *   Boolean Rte_IRead_StOpCtrl_Per1_DiagStsDiagRmpActive_Cnt_lgc(void)
 *   Float Rte_IRead_StOpCtrl_Per1_LoaRateLimit_UlspS_f32(void)
 *   Float Rte_IRead_StOpCtrl_Per1_LoaScaleFctr_Uls_f32(void)
 *   Float Rte_IRead_StOpCtrl_Per1_OperRampRate_XpmS_f32(void)
 *   Float Rte_IRead_StOpCtrl_Per1_OperRampValue_Uls_f32(void)
 *   Boolean Rte_IRead_StOpCtrl_Per1_RampSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_StOpCtrl_Per1_StrtStopRateLimit_UlspS_f32(void)
 *   Float Rte_IRead_StOpCtrl_Per1_StrtStopScaleFctr_Uls_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StOpCtrl_Per1_OutputRampMult_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_StOpCtrl_Per1_OutputRampMult_Uls_f32(void)
 *   void Rte_IWrite_StOpCtrl_Per1_SysStReqDi_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StOpCtrl_Per1_SysStReqDi_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STOPCTRL_APPL_CODE) StOpCtrl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StOpCtrl_Per1
 *********************************************************************************************************************/

	VAR(uint8, AUTOMATIC) ArbdSt_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) RampSrlComSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsDiagRmpActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	RampDwnStatusComplete_T_lgc;
	VAR(boolean, AUTOMATIC)	SysStReqDi_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) OperScaleFctr_Uls_T_f32;
	VAR(float32, AUTOMATIC) OperRampRate_XpmS_T_f32;
	VAR(float32, AUTOMATIC) OperRateLimit_UlspS_T_f32;
	VAR(float32, AUTOMATIC) DiagScaleFctr_Uls_T_f32;
	VAR(float32, AUTOMATIC) DiagRampRate_XpmS_T_f32;
	VAR(float32, AUTOMATIC) DiagRateLimit_UlspS_T_f32;
	VAR(float32, AUTOMATIC) ArbdRate_UlspS_T_f32;
    VAR(float32, AUTOMATIC) ArbdTarSca_Uls_T_f32;
    VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
    VAR(float32, AUTOMATIC) LoaRateLimit_UlspS_T_f32;
	VAR(float32, AUTOMATIC) LoaScaleFctr_Uls_T_f32;
	VAR(float32, AUTOMATIC) StrtStopRateLimit_UlspS_T_f32;
	VAR(float32, AUTOMATIC) StrtStopScaleFctr_Uls_T_f32;
	VAR(float32, AUTOMATIC) StepLimit_Uls_T_f32;
	VAR(float32, AUTOMATIC) SelRampValue_Uls_T_f32;
	VAR(float32, AUTOMATIC) SelRampRate_UlspS_T_f32;
	VAR(float32, AUTOMATIC) Scale_Uls_T_f32;

	/*Store Inputs to Module local copy*/

	OperRampRate_XpmS_T_f32 			= Rte_IRead_StOpCtrl_Per1_OperRampRate_XpmS_f32();			
	OperScaleFctr_Uls_T_f32 			= Rte_IRead_StOpCtrl_Per1_OperRampValue_Uls_f32();			
	DiagScaleFctr_Uls_T_f32				= Rte_IRead_StOpCtrl_Per1_DiagRampValue_Uls_f32();			
	DiagRampRate_XpmS_T_f32				= Rte_IRead_StOpCtrl_Per1_DiagRampRate_XpmS_f32();			
	DiagStsDiagRmpActive_Cnt_T_lgc		= Rte_IRead_StOpCtrl_Per1_DiagStsDiagRmpActive_Cnt_lgc();	
	RampSrlComSvcDft_Cnt_T_lgc			= Rte_IRead_StOpCtrl_Per1_RampSrlComSvcDft_Cnt_lgc();		
	LoaRateLimit_UlspS_T_f32			= Rte_IRead_StOpCtrl_Per1_LoaRateLimit_UlspS_f32();
	LoaScaleFctr_Uls_T_f32				= Rte_IRead_StOpCtrl_Per1_LoaScaleFctr_Uls_f32();
	StrtStopRateLimit_UlspS_T_f32		= Rte_IRead_StOpCtrl_Per1_StrtStopRateLimit_UlspS_f32();
	StrtStopScaleFctr_Uls_T_f32			= Rte_IRead_StOpCtrl_Per1_StrtStopScaleFctr_Uls_f32();

	OperRateLimit_UlspS_T_f32			= OperRampRate_XpmS_T_f32 * D_SECTOMILLISEC_MSPSEC_F32;		/* StOpCtrl needs rates in UlspS */
	DiagRateLimit_UlspS_T_f32			= DiagRampRate_XpmS_T_f32 * D_SECTOMILLISEC_MSPSEC_F32;		/* StOpCtrl needs rates in UlspS */

	TargetSelection (OperScaleFctr_Uls_T_f32, 
					LoaScaleFctr_Uls_T_f32, 
					StrtStopScaleFctr_Uls_T_f32, 
					OperRateLimit_UlspS_T_f32, 
					LoaRateLimit_UlspS_T_f32, 
					StrtStopRateLimit_UlspS_T_f32, 
					&SelRampValue_Uls_T_f32, 
					&SelRampRate_UlspS_T_f32);

	/*** Start of Diag Override ***/
	if (D_TRUE_CNT_LGC == DiagStsDiagRmpActive_Cnt_T_lgc)
	{
		ArbdTarSca_Uls_T_f32	= DiagScaleFctr_Uls_T_f32;
		ArbdRate_UlspS_T_f32 	= DiagRateLimit_UlspS_T_f32;
		ArbdSt_Cnt_T_u08 		= D_DIAG_CNT_U08;
	}

	else
	{
		ArbdTarSca_Uls_T_f32	= SelRampValue_Uls_T_f32;
		ArbdRate_UlspS_T_f32	= SelRampRate_UlspS_T_f32;
		ArbdSt_Cnt_T_u08		= StOpCtrl_State_Cnt_M_u08;
	}

	ArbdTarSca_Uls_T_f32 = Limit_m(ArbdTarSca_Uls_T_f32, D_TARGETSCALELO_ULS_F32, D_TARGETSCALEHI_ULS_F32);

	StOpCtrl_TargetScale_Uls_D_f32 = ArbdTarSca_Uls_T_f32; 	

	/*** End of Diag Override ***/


	/*** Start of Ramp Defeat ***/

	if (D_FALSE_CNT_LGC != RampSrlComSvcDft_Cnt_T_lgc)
	{
		ArbdRate_UlspS_T_f32 = D_BIGSLEW_ULSPS_F32; 				
	}

	else
	{
		ArbdRate_UlspS_T_f32 = Limit_m(ArbdRate_UlspS_T_f32, D_RATELIMITLO_ULSPS_F32, D_RATELIMITHI_ULSPS_F32);
	}

	StOpCtrl_RateLimit_UlspS_D_f32 = ArbdRate_UlspS_T_f32; 		

	/*** End of Ramp Defeat ***/

	/*** Start of Apply Slew ***/

	StepLimit_Uls_T_f32 		= ArbdRate_UlspS_T_f32 * D_2MS_SEC_F32;

	Scale_Uls_T_f32 			= Limit_m(ArbdTarSca_Uls_T_f32, (StOpCtrl_ScaleSV_Uls_M_f32 - StepLimit_Uls_T_f32), (StOpCtrl_ScaleSV_Uls_M_f32 + StepLimit_Uls_T_f32) );

	StOpCtrl_ScaleSV_Uls_M_f32	= Scale_Uls_T_f32;
		
	/*** End of Apply Slew ***/

	/*** Start of System State Request ***/

	if( Abs_f32_m(Scale_Uls_T_f32) > D_EPSILON_ULS_F32)
	{

		RampDwnStatusComplete_T_lgc = D_FALSE_CNT_LGC;
	}
	
	else
	{
		RampDwnStatusComplete_T_lgc = D_TRUE_CNT_LGC;
	}

	if( (ArbdSt_Cnt_T_u08 == D_OPER_CNT_U08)||
		(ArbdSt_Cnt_T_u08 == D_DIAG_CNT_U08) )
	{
		SysStReqDi_Cnt_T_lgc = RampDwnStatusComplete_T_lgc;
	}

	else
	{
		SysStReqDi_Cnt_T_lgc = D_FALSE_CNT_LGC;
	}

	/*** End of System State Request ***/

	/*** Limit Outputs ***/
	/* Output OutputRampMult_Uls_f32 limited in the code to meet the coding standards */
	/* not functionally needed in FDD since this limiting is also done earlier in the calculation */
	OutputRampMult_Uls_T_f32 = Limit_m(Scale_Uls_T_f32, D_TARGETSCALELO_ULS_F32, D_TARGETSCALEHI_ULS_F32);


	/* Write local copies to module outputs */
	Rte_IWrite_StOpCtrl_Per1_OutputRampMult_Uls_f32(OutputRampMult_Uls_T_f32);	
	Rte_IWrite_StOpCtrl_Per1_SysStReqDi_Cnt_lgc(SysStReqDi_Cnt_T_lgc);			

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_STOPCTRL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/******************************************************************************
  * Name:        TargetSelection
  * Description: Implements "Target Selection" model block in FDD -- selects ramp value from
  *              input scale factors and selects ramp rate from input rate limits,
  *              and keeps state variables for which scale and rate source were last used
  * Inputs:      OperScaleFctr_Uls_T_f32 : "Oper" state scale factor
  *              LoaScaleFctr_Uls_T_f32 :- "Loa" state scale factor
  *              StrtStopScaleFctr_Uls_T_f32 :- "StrtStop" state scale factor
  *              OperRateLimit_UlspS_T_f32 :- "OperSrc" rate limit
  *              LoaRateLimit_UlspS_T_f32 :- "LoaSrc" rate limit
  *              StrtStopRateLimit_UlspS_T_f32 :- "StrtStopSrc" rate limit
  * Outputs:     SelRampValue_Uls_T_f32 :- selected ramp value 
  *              SelRampRate_UlspS_T_f32 :- selected ramp rate 
  * Usage Notes:  NONE
  ****************************************************************************/
STATIC FUNC (void, 	AP_STOPCTRL_CODE) TargetSelection(  VAR(float32, AUTOMATIC) OperScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) LoaScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) StrtStopScaleFctr_Uls_T_f32, 
														VAR(float32, AUTOMATIC) OperRateLimit_UlspS_T_f32, 
														VAR(float32, AUTOMATIC) LoaRateLimit_UlspS_T_f32, 
														VAR(float32, AUTOMATIC) StrtStopRateLimit_UlspS_T_f32, 
														P2VAR(float32, AUTOMATIC, AP_STOPCTRL_APPL_VAR) SelRampValue_Uls_T_f32, 
														P2VAR(float32, AUTOMATIC, AP_STOPCTRL_APPL_VAR) SelRampRate_UlspS_T_f32)
{
	/*** Start of Target Selection ***/


	if ((StrtStopScaleFctr_Uls_T_f32 < OperScaleFctr_Uls_T_f32) &&
		(StrtStopScaleFctr_Uls_T_f32 < LoaScaleFctr_Uls_T_f32))
	{
		StOpCtrl_State_Cnt_M_u08 = D_STRTSTOP_CNT_U08;
	}

	else if (LoaScaleFctr_Uls_T_f32 < OperScaleFctr_Uls_T_f32)
	{
		StOpCtrl_State_Cnt_M_u08 = D_LOA_CNT_U08;
	}

	else
	{
		StOpCtrl_State_Cnt_M_u08 = D_OPER_CNT_U08;
	}

	switch (StOpCtrl_State_Cnt_M_u08)
	{
		case D_OPER_CNT_U08:
		{
			*SelRampValue_Uls_T_f32 = OperScaleFctr_Uls_T_f32;
			if (OperScaleFctr_Uls_T_f32 <= StOpCtrl_ScaleSV_Uls_M_f32)
			{
				StOpCtrl_RateSource_Cnt_M_u08 = D_OPER_CNT_U08;
			}
			/* else keep previous rate source */
		}
		break;
		
		case D_LOA_CNT_U08:
		{
			*SelRampValue_Uls_T_f32 = LoaScaleFctr_Uls_T_f32;
			if (LoaScaleFctr_Uls_T_f32 <= StOpCtrl_ScaleSV_Uls_M_f32)
			{
				StOpCtrl_RateSource_Cnt_M_u08 = D_LOA_CNT_U08;
			}
			/* else keep previous rate source */
		}
		break;
		
		case D_STRTSTOP_CNT_U08:
		default:
		/* default case required for MISRA -- can't get here -- do nothing */
		{
			*SelRampValue_Uls_T_f32 = StrtStopScaleFctr_Uls_T_f32;
			if (StrtStopScaleFctr_Uls_T_f32 <= StOpCtrl_ScaleSV_Uls_M_f32)
			{
				StOpCtrl_RateSource_Cnt_M_u08 = D_STRTSTOP_CNT_U08;
			}
			/* else keep previous rate source */
		}
		break;

	}	
		
	switch (StOpCtrl_RateSource_Cnt_M_u08)
	{
		case D_OPER_CNT_U08:
			*SelRampRate_UlspS_T_f32 = OperRateLimit_UlspS_T_f32;
		break;
		
		case D_LOA_CNT_U08:
			*SelRampRate_UlspS_T_f32 = LoaRateLimit_UlspS_T_f32;
		break;
			
		case D_STRTSTOP_CNT_U08:
		default:
			*SelRampRate_UlspS_T_f32 = StrtStopRateLimit_UlspS_T_f32;
		break;

	}
	/*** End of Target Selection ***/
}															
													



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
