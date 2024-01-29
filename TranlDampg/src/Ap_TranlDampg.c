/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TranlDampg.c
 *     Workspace:  C:/Synergy_KK/working/TranlDampg-nz4qtt/TranlDampg/autosar
 *     SW-C Type:  Ap_TranlDampg
 *  Generated at:  Tue Mar 31 11:37:42 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TranlDampg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/****************************************************************************
* Copyright 2014 Nexteer
* Nexteer Confidential
*
* Module File Name: TranlDampg.c
* Module Description: Initial Implementation of FDD V001 (legacy of SF26)
* Project           : CBD
* Author            : Krishna Kanth Anne
*****************************************************************************
 *  Version Control:
 * Date Created:      Tue Jan 03 18:34:17 2012
 * %version:          2 %
 * %date_modified:    Mon Mar  9 14:05:36 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/17/12   1       KK     	     SF-50A Initial Creation		   										  13060
 * 03/31/12   2       KK     	     SF-50A V002 Implementation		   										  13190
 *---------------------------------------------------------------------------------------------------------------------
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_TranlDampg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "float.h"
#include "fixmath.h"
#include "interpolation.h"
#include "GlobalMacro.h"
#include "CalConstants.h"


/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* PRQA S 4395 EOF
   MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

#define D_TRANLDAMPG_MS_U16	( FPM_FloatToFixed_m(1.0f, u8p8_T) )

#define TRANLDAMPG_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_VelTrq_MtrNm_D_f32; 					/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_Trq_MtrNm_D_f32;						/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_PPSScale_Uls_D_f32;					/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_VehSpdBlnd_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_CRFMtrTrqCmd_MtrNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TranlDampg_ElpsdTime_mS_D_f32;					/* PRQA S 3218 */
STATIC VAR(uint32, AUTOMATIC) TranlDampg_LastF2Fault_mS_M_u32;							/* PRQA S 3218 */
#define TRANLDAMPG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */


#define TRANLDAMPG_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) TranlDampg_TmrX_mS_M_u16[2];								/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) TranlDampg_TmrY_mS_M_u16[2];								/* PRQA S 3218 */
#define TRANLDAMPG_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */

#define TRANLDAMPG_START_SEC_VAR_CLEARED_08	
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(sint8, AUTOMATIC) TranlDampg_VelxPosNegSign_Uls_D_s08;				/* PRQA S 3218 */
#define TRANLDAMPG_STOP_SEC_VAR_CLEARED_08
#include "MemMap.h"/* PRQA S 5087 */

#define TRANLDAMPG_START_SEC_VAR_CLEARED_BOOLEAN	
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(boolean, AUTOMATIC) TranlDampg_EnableTimer_Cnt_D_lgc;				/* PRQA S 3218 */
STATIC volatile VAR(boolean, AUTOMATIC) TranlDampg_Comp_Cnt_D_lgc;						/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) TranlDampg_CompPrv_Uls_M_lgc;							/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) TranlDampg_DiagStsF2ActivePrv_Cnt_M_lgc;					/* PRQA S 3218 */
#define TRANLDAMPG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */

#define TRANLDAMPG_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(LOA_State_enum,  AUTOMATIC) TranlDampg_LoaStatePrev_State_M_enum;			/* PRQA S 3218 */
#define TRANLDAMPG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */

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
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * LOA_State_enum: Enumeration of integer in interval [0...5] with enumerators
 *   LOAST_NORM (0u)
 *   LOAST_REDCD (1u)
 *   LOAST_SWBASDMTGTN (2u)
 *   LOAST_FADEOUT (3u)
 *   LOAST_CTRLDSHTDWNREQD (4u)
 *   LOAST_RPDSHTDWNREQD (5u)
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
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * LOA_State_enum: D_LOASTATEINIT_CNT_ENUM = 0u
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt8: D_ONE_CNT_U8 = 1u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRANLDAMPG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_TranlDampg_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRANLDAMPG_APPL_CODE) Ap_TranlDampg_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ap_TranlDampg_Init
 *********************************************************************************************************************/
	TranlDampg_TmrX_mS_M_u16[0]  = FPM_FloatToFixed_m(k_TrnDmp_TmrBkptOne_mS_f32, u16p0_T);
 	TranlDampg_TmrX_mS_M_u16[1]  = FPM_FloatToFixed_m(k_TrnDmp_BkptTwo_mS_f32, u16p0_T);
 	TranlDampg_TmrY_mS_M_u16[0]  = D_TRANLDAMPG_MS_U16;
 	TranlDampg_TmrY_mS_M_u16[1]  = FPM_FloatToFixed_m(k_TrnDmp_RampEnd_Uls_f32, u8p8_T);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_TranlDampg_Per1
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
 *   SInt8 Rte_IRead_Ap_TranlDampg_Per1_AssistAssyPolarity_Cnt_s08(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_Ap_TranlDampg_Per1_DiagStsF2Active_Cnt_lgc(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_HandwheelPosition_HwDeg_f32(void)
 *   LOA_State_enum Rte_IRead_Ap_TranlDampg_Per1_LoaSt_State_enum(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_SumLimTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRANLDAMPG_APPL_CODE) Ap_TranlDampg_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ap_TranlDampg_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) AbsCRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) TranlDampgMult_Uls_T_f32;
	VAR(float32, AUTOMATIC) TranlDampgVelTrq_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) PPSScale_Uls_T_f32;
	VAR(float32, AUTOMATIC) VehSpdBlnd_Uls_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) TranlDampgTrq_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) SumLimTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) VehSpdBlndRed_Uls_T_f32;
	VAR(float32, AUTOMATIC) ElapsedTime_mS_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmdSum_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTempTrqCmd_MtrNm_T_f32;

	VAR(sint8, AUTOMATIC) VelxPosNegSign_Uls_T_s08;
	VAR(sint8, AUTOMATIC) AssistAssyPolarity_Cnt_T_s08;
	VAR(sint8, AUTOMATIC) CRFMtrVelNegSign_Uls_T_s08;
	VAR(sint8, AUTOMATIC) CRFMtrVelSign_Uls_T_s08;
	VAR(sint8, AUTOMATIC) MtrPosSign_Uls_T_s08;
	
	VAR(uint16, AUTOMATIC) TranlDmpMult_Uls_T_u8p8;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7;
	VAR(uint16, AUTOMATIC) VehSpdBlnd_Uls_T_u9p7;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	
	VAR(boolean, AUTOMATIC) DiagStsF2Active_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CntrlDampComp_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EnableTimer_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrVelThrLo_Uls_T_lgc;
	VAR(boolean, AUTOMATIC) LatchPrvStat_Uls_T_lgc;

	VAR(LOA_State_enum, AUTOMATIC) LoaSt_State_T_Enum;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;
	

	SysState_Cnt_T_Enum 	  		= Rte_Mode_SystemState_Mode();
	CRFMtrVel_MtrRadpS_T_f32  		= Rte_IRead_Ap_TranlDampg_Per1_CRFMtrVel_MtrRadpS_f32();
	HandwheelPosition_HwDeg_T_f32	= Rte_IRead_Ap_TranlDampg_Per1_HandwheelPosition_HwDeg_f32();
	VehSpd_Kph_T_f32 		 		= Rte_IRead_Ap_TranlDampg_Per1_VehSpd_Kph_f32();
	SumLimTrqCmd_MtrNm_T_f32  		= Rte_IRead_Ap_TranlDampg_Per1_SumLimTrqCmd_MtrNm_f32();
	DiagStsF2Active_Cnt_T_lgc 		= Rte_IRead_Ap_TranlDampg_Per1_DiagStsF2Active_Cnt_lgc();
	AssistAssyPolarity_Cnt_T_s08	= Rte_IRead_Ap_TranlDampg_Per1_AssistAssyPolarity_Cnt_s08();
	LoaSt_State_T_Enum				= Rte_IRead_Ap_TranlDampg_Per1_LoaSt_State_enum();
	

	/*** Start of Compute Damping Torque ***/
		
	CRFMtrVelSign_Uls_T_s08 = Sign_f32_m(CRFMtrVel_MtrRadpS_T_f32);

	CRFMtrVelNegSign_Uls_T_s08 =  - CRFMtrVelSign_Uls_T_s08 ;
	
	AbsCRFMtrVel_MtrRadpS_T_f32 = Abs_f32_m(CRFMtrVel_MtrRadpS_T_f32);

	TranlDampgVelTrq_MtrNm_T_f32 = AbsCRFMtrVel_MtrRadpS_T_f32 * k_TrnDmp_DampCoeff_MtrNmpRadpS_f32;

	TranlDampgVelTrq_MtrNm_T_f32 = TranlDampgVelTrq_MtrNm_T_f32 * (float32)(sint32)CRFMtrVelNegSign_Uls_T_s08;

	/*** Start of Phase Plane Switching ***/
	
	MtrPosSign_Uls_T_s08 = Sign_f32_m(HandwheelPosition_HwDeg_T_f32);
	
	VelxPosNegSign_Uls_T_s08 = CRFMtrVelSign_Uls_T_s08 * MtrPosSign_Uls_T_s08;
	
	if( D_ZERO_ULS_F32 > (float32)(sint32)VelxPosNegSign_Uls_T_s08 )
		{
			VelxPosNegSign_Uls_T_s08 = D_ONE_CNT_S8;
		}
	
	else
		{
			VelxPosNegSign_Uls_T_s08 = D_ZERO_CNT_S8;
		}
	
	VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m( VehSpd_Kph_T_f32, u9p7_T );
	 
	VehSpdBlnd_Uls_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(t_TrnDmp_VehSpdBlndX_Kph_u9p7,
									t_TrnDmp_VehSpdBlndY_Uls_u9p7, 
									TableSize_m(t_TrnDmp_VehSpdBlndX_Kph_u9p7),
									VehSpd_Kph_T_u9p7);
									
	VehSpdBlnd_Uls_T_f32 = FPM_FixedToFloat_m(VehSpdBlnd_Uls_T_u9p7, u9p7_T);

	VehSpdBlndRed_Uls_T_f32 = D_ONE_ULS_F32 - VehSpdBlnd_Uls_T_f32;
	
	VehSpdBlndRed_Uls_T_f32 = (float32)(sint32)VelxPosNegSign_Uls_T_s08 * VehSpdBlndRed_Uls_T_f32;

	PPSScale_Uls_T_f32 = VehSpdBlndRed_Uls_T_f32 + VehSpdBlnd_Uls_T_f32 ;

	TranlDampg_PPSScale_Uls_D_f32 = PPSScale_Uls_T_f32;																			/* Update of display variable for PPSScale  */
	
	TranlDampg_VelxPosNegSign_Uls_D_s08 = VelxPosNegSign_Uls_T_s08;																/* Update of display variable for VelxPosNegSign */
	
	TranlDampg_VehSpdBlnd_Uls_D_f32 = VehSpdBlnd_Uls_T_f32;																		/* Update of display variable for VehSpdBlnd  */
	
	/*** End of Phase Plane Switching ***/

	TranlDampgVelTrq_MtrNm_T_f32 = TranlDampgVelTrq_MtrNm_T_f32 * PPSScale_Uls_T_f32;
	
	TranlDampg_VelTrq_MtrNm_D_f32 = TranlDampgVelTrq_MtrNm_T_f32;
	
	/*** End of Compute Damping Torque ***/
		
	
	/*** Start of Controlled Damping Factor ***/
	
	if (TranlDampg_DiagStsF2ActivePrv_Cnt_M_lgc != DiagStsF2Active_Cnt_T_lgc) 													/*  The situations to enable transitional damping w.r.t Diag status are when the Diag status is Active.*/
																																/*  F2 fault takes priority over LOA fault and resets the Elapsed Time*/
		{

			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TranlDampg_LastF2Fault_mS_M_u32);
			ElapsedTime_mS_T_f32 = D_ZERO_ULS_F32;

			if (D_TRUE_CNT_LGC == DiagStsF2Active_Cnt_T_lgc)
				{
					EnableTimer_Cnt_T_lgc = D_TRUE_CNT_LGC;
				}

			else																												/*  The situations not to enable transitional damping at all */
				{																												/*  Neutral code, has no effect when no LOA fault or F2 fault */
					EnableTimer_Cnt_T_lgc = D_FALSE_CNT_LGC;
				}
		}

	else																														/*  The situations to continue transitional damping when LOA fault of F2 fault persist */
		{
			if (D_TRUE_CNT_LGC == DiagStsF2Active_Cnt_T_lgc)
				{
					EnableTimer_Cnt_T_lgc = D_TRUE_CNT_LGC;
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TranlDampg_LastF2Fault_mS_M_u32, &ElapsedTime_mS_T_u16);
					ElapsedTime_mS_T_f32 = FPM_FixedToFloat_m(ElapsedTime_mS_T_u16, u16p0_T);
					ElapsedTime_mS_T_f32 = Limit_m(ElapsedTime_mS_T_f32, D_ZERO_ULS_F32, k_TrnDmp_BkptTwo_mS_f32);
				}


			else if ( (TranlDampg_LoaStatePrev_State_M_enum != LoaSt_State_T_Enum) &&											/*  The situations to enable transitional damping w.r.t LOA state are when the LOA state changes */
					  ( (LOAST_FADEOUT == LoaSt_State_T_Enum) ||																/*	to either SW Based Mitigation or Fade Out from any other state in previous cycle */
						(LOAST_SWBASDMTGTN == LoaSt_State_T_Enum) ) )
				{
					EnableTimer_Cnt_T_lgc = D_TRUE_CNT_LGC;
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TranlDampg_LastF2Fault_mS_M_u32, &ElapsedTime_mS_T_u16);
					ElapsedTime_mS_T_f32 = FPM_FixedToFloat_m(ElapsedTime_mS_T_u16, u16p0_T);
					ElapsedTime_mS_T_f32 = Limit_m(ElapsedTime_mS_T_f32, D_ZERO_ULS_F32, k_TrnDmp_BkptTwo_mS_f32);
				}

			else																												/*  The situations not to enable transitional damping at all */
				{																												/*  Neutral code, has no effect when no LOA fault or F2 fault */
					EnableTimer_Cnt_T_lgc = D_FALSE_CNT_LGC;
					ElapsedTime_mS_T_f32 = D_ZERO_ULS_F32;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TranlDampg_LastF2Fault_mS_M_u32);
				}
		}
	


	if( (ElapsedTime_mS_T_f32 >= k_TrnDmp_BkptTwo_mS_f32) ||
		(D_FALSE_CNT_LGC == EnableTimer_Cnt_T_lgc) )
		{
			TranlDampgMult_Uls_T_f32 = D_ZERO_ULS_F32;
		}
	
	else
		{
			TranlDmpMult_Uls_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt (TranlDampg_TmrX_mS_M_u16,
																	TranlDampg_TmrY_mS_M_u16,
																	TableSize_m(TranlDampg_TmrX_mS_M_u16),
																	ElapsedTime_mS_T_f32); /* PRQA S 4454 */
		
			TranlDampgMult_Uls_T_f32 = FPM_FixedToFloat_m(TranlDmpMult_Uls_T_u8p8, u8p8_T);
		}
	
	TranlDampgTrq_MtrNm_T_f32 = Limit_m( (TranlDampgVelTrq_MtrNm_T_f32 * TranlDampgMult_Uls_T_f32), -k_TrnDmp_DmpLimit_MtrNm_f32, k_TrnDmp_DmpLimit_MtrNm_f32);
	
	TranlDampg_Trq_MtrNm_D_f32 = TranlDampgTrq_MtrNm_T_f32;															/* Update of display variable for TranlDampTrq  */
	
	TranlDampg_ElpsdTime_mS_D_f32 = ElapsedTime_mS_T_f32;															/* Update of display variable for TranlDampElpsdTime */
	
	TranlDampg_EnableTimer_Cnt_D_lgc = EnableTimer_Cnt_T_lgc;														/* Update of display variable for EnableTimer */
	
	TranlDampg_LoaStatePrev_State_M_enum = LoaSt_State_T_Enum;														/* Update of previous value of LoaState with current value for usage in next cycle */
	
	TranlDampg_DiagStsF2ActivePrv_Cnt_M_lgc = DiagStsF2Active_Cnt_T_lgc;											/* Update of previous value of Diag status with current value for usage in next cycle */

	/*** End of Controlled Damping Factor ***/
	
	
	/*** Start of Switch Output Control ***/
	
	if( ((ElapsedTime_mS_T_f32 > k_TrnDmp_TmrBkptOne_mS_f32) &&														/* This If and else are only made to handle polyspace issue */
		(AbsCRFMtrVel_MtrRadpS_T_f32 < k_TrnDmp_VelThr_MtrRadpS_f32)) )												/* MtrVelThrLo_Uls_T_lgc would have the logical value computed in if or else condition*/
	{
		MtrVelThrLo_Uls_T_lgc = D_TRUE_CNT_LGC;																		/* Temporary logical value when Elapsed time is greater than BP1 */
																													/* and Abs(CRFMtrVel) is less than k_TrnDmp_VelThr_MtrRadpS_f32 */
	}

	else
	{
		MtrVelThrLo_Uls_T_lgc = D_FALSE_CNT_LGC;
	}

	if( ((ElapsedTime_mS_T_f32 > k_TrnDmp_TmrBkptOne_mS_f32) && 													/* This If and else are only made to handle polyspace issue */
		(ElapsedTime_mS_T_f32 > FLT_EPSILON) &&																		/* LatchPrvStat_Uls_T_lgc would have the logical value computed in if or else condition*/
		(TranlDampg_CompPrv_Uls_M_lgc == D_TRUE_CNT_LGC)) )

	{
		LatchPrvStat_Uls_T_lgc =  D_TRUE_CNT_LGC;																	/* Temporary logical value when Elapsed time is greater than BP1 */
																													/* and not 0 and latched value in previous cycle is true */
	}

	else
	{
		LatchPrvStat_Uls_T_lgc = D_FALSE_CNT_LGC;
	}

	if( (( MtrVelThrLo_Uls_T_lgc == D_TRUE_CNT_LGC) ||																/* This If and else are only made to handle polyspace issue */
		(LatchPrvStat_Uls_T_lgc == D_TRUE_CNT_LGC)) )																/* TranlDampg_CompPrv_Uls_M_lgc would have the logical value computed in if or else condition*/
	{
		TranlDampg_CompPrv_Uls_M_lgc = D_TRUE_CNT_LGC;																/* Temporary logical value indicating logical or of above 2 operations*/
	}

	else
	{
		TranlDampg_CompPrv_Uls_M_lgc = D_FALSE_CNT_LGC;
	}

	if( (ElapsedTime_mS_T_f32 >= k_TrnDmp_BkptTwo_mS_f32) || 														/* Decision when  Elapsed time reached BP2 or above logical operation is true */
		(D_TRUE_CNT_LGC == TranlDampg_CompPrv_Uls_M_lgc) )
		{
			CntrlDampComp_Cnt_T_lgc = D_TRUE_CNT_LGC;
			CRFMtrTrqCmdSum_MtrNm_T_f32 = D_ZERO_ULS_F32;
		}
	
	else																											/* Decision when Elapsed time did not reach BP2 nor latched value is true */
		{
			CntrlDampComp_Cnt_T_lgc = D_FALSE_CNT_LGC;
			CRFMtrTrqCmdSum_MtrNm_T_f32 = TranlDampgTrq_MtrNm_T_f32;
		}
		
	
	if( D_TRUE_CNT_LGC == DiagStsF2Active_Cnt_T_lgc )																/* Decision when Diag Status is active */
		{
			CRFMtrTempTrqCmd_MtrNm_T_f32 = CRFMtrTrqCmdSum_MtrNm_T_f32;
		}
	else																											/* Decision when Diag Status is not active */
		{
			CRFMtrTempTrqCmd_MtrNm_T_f32 = SumLimTrqCmd_MtrNm_T_f32 + CRFMtrTrqCmdSum_MtrNm_T_f32;
		}


	if (RTE_MODE_StaMd_Mode_OPERATE != SysState_Cnt_T_Enum)															/* Decision when System State is not RTE_MODE_StaMd_Mode_OPERATE */
		{
			CRFMtrTrqCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
		}

	else																											/* Decision when System State is RTE_MODE_StaMd_Mode_OPERATE */
		{
			CRFMtrTrqCmd_MtrNm_T_f32 = CRFMtrTempTrqCmd_MtrNm_T_f32;
		}
		

	MRFMtrTrqCmd_MtrNm_T_f32 = CRFMtrTrqCmd_MtrNm_T_f32 * (float32)AssistAssyPolarity_Cnt_T_s08;	

	TranlDampg_CRFMtrTrqCmd_MtrNm_D_f32 = CRFMtrTrqCmd_MtrNm_T_f32;													/* Update of display variable for CRFMtrTrqCmd  */
	TranlDampg_Comp_Cnt_D_lgc = CntrlDampComp_Cnt_T_lgc;															/* Update of display variable for TranlDampgComp */
	
	/*** End of Switch Output Control ***/
	
	
	/*** Start of Limit Outputs ***/
	
	MRFMtrTrqCmd_MtrNm_T_f32 = Limit_m(MRFMtrTrqCmd_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32); /* Limit Output MRFMtrTrqCmd */
	CRFMtrTrqCmd_MtrNm_T_f32 = Limit_m(CRFMtrTrqCmd_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32); /* Limit Output CRFMtrTrqCmd */
	
	/*** End of Limit Outputs ***/
	
	/* Write local copies to module outputs */	
	
	Rte_IWrite_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(CRFMtrTrqCmd_MtrNm_T_f32);
	Rte_IWrite_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(CntrlDampComp_Cnt_T_lgc);
	Rte_IWrite_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(MRFMtrTrqCmd_MtrNm_T_f32);
	Rte_IWrite_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(CRFMtrTrqCmd_MtrNm_T_f32);
	Rte_IWrite_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(MRFMtrTrqCmd_MtrNm_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRANLDAMPG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
