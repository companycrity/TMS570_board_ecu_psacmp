/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_LmtCod.c
 *     Workspace:  C:/Synergy_KK/working/LmtCod-nz4qtt/LmtCod/autosar
 *     SW-C Type:  Ap_LmtCod
 *  Generated at:  Wed Mar 11 18:06:39 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_LmtCod>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/****************************************************************************
* Copyright 2014, 2017 Nexteer
* Nexteer Confidential
*
* Module File Name: LmtCod.c
* Module Description: Initial Implementation of SF38A
* Project           : CBD
* Author            : Niveditha Reddy
*
* Module File Name: Ap_LmtCod.c
*
****************************************************************************
* Version Control:
* Date Created:      Fri Dec  2 16:41:06 2011
* %version:          EA3#6 %
* %derived_by:       nz2796 %
* %date_modified:    Mon Jul  8 17:20:02 2013 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
*           1					Component creation.
* 09/21/12  2        Selva      checkpoint added                                                              6232
* 05/17/13  3        BDO        Update to SF38 v002                                                           8292
* 07/09/13  4        Selva      Update to SF38 v003                                                           8892
* 03/04/15  5        KK		    Update to SF38 v004                                                           13089
* 08/08/17  6        ML         Update to fix Anomaly EA3#16823                                             EA3#16925
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_LmtCod.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "Interpolation.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* PRQA S 4395 EOF
   MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/* PRQA S 3332 EOF
* MISRA-C: 2004 Rule 19.11: This deviation is required for fault injection points
* Warning 3332 is not seen in current file because constant BC_LMTCOD_FAULTINJECTIONPOINT is defined in compiler_cfg header file */
 
#define D_GAINHILIMIT_ULS_F32 	1.0F
#define D_GAINLOLIMIT_ULS_F32 	0.0F
#define D_TRQHILIMIT_MTRNM_F32 	8.8F
#define D_TRQLOLIMIT_MTRNM_F32 	0.0F


#define LMTCOD_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistEOTGain_Uls_M_f32; 		/* PRQA S 3218 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrOutputRampMult_Uls_M_f32; 		/* PRQA S 3218 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistEOTLimit_MtrNm_M_f32; 		/* PRQA S 3218 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistStallLimit_MtrNm_M_f32;	/* PRQA S 3218 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistVehSpdLimit_MtrNm_M_f32; 	/* PRQA S 3218 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrThermalLimit_MtrNm_M_f32; 		/* PRQA S 3218 */
#define LMTCOD_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 *
 * Enumeration Types:
 * ==================
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 *   FLTINJ_MTRVEL (160u)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_LMTCOD_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LmtCod_Per1
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
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AstVehSpdLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTGainLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_OutputRampMultLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_StallLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LMTCOD_APPL_CODE) LmtCod_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LmtCod_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) AssistEOTGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	AssistEOTLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	AssistStallLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	AssistVehSpdLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	OutputRampMult_Uls_T_f32;
	VAR(float32, AUTOMATIC)	ThermalLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16,  AUTOMATIC) GainIncSlew_UlspS_T_u9p7;
	VAR(float32, AUTOMATIC) GainIncSlew_UlspS_T_f32;
	VAR(uint16,  AUTOMATIC) TorqueIncSlew_MtrNmpS_T_u13p3;
	VAR(float32, AUTOMATIC) TorqueIncSlew_MtrNmpS_T_f32;

	AssistEOTGain_Uls_T_f32 		= Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32();
	AssistEOTLimit_MtrNm_T_f32 		= Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32();
	AssistStallLimit_MtrNm_T_f32 	= Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32();
	AssistVehSpdLimit_MtrNm_T_f32 	= Rte_IRead_LmtCod_Per1_AstVehSpdLimit_MtrNm_f32();
	OutputRampMult_Uls_T_f32 		= Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32();
	ThermalLimit_MtrNm_T_f32 		= Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32();
	VehicleSpeed_Kph_T_f32 			= Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32();


	#if (STD_ON == BC_LMTCOD_FAULTINJECTIONPOINT)
		/* REQ: SF038A #74 I */
		(void) Rte_Call_FltInjection_SCom_FltInjection(&AssistEOTGain_Uls_T_f32, FLTINJ_ASSTEOTGAIN_LMTCOD);
		/* ENDREQ: SF038A #74 I*/

		/* REQ: SF038A #75 I */
		(void) Rte_Call_FltInjection_SCom_FltInjection(&OutputRampMult_Uls_T_f32, FLTINJ_OUTPUTRAMPMULT_LMTCOD);
		/* ENDREQ: SF038A #75 I */

		/* REQ: SF038A #76 I */
		(void) Rte_Call_FltInjection_SCom_FltInjection(&AssistEOTLimit_MtrNm_T_f32, FLTINJ_ASSTEOTLIMIT_LMTCOD);
		/* ENDREQ: SF038A #76 I */
	#endif

	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);

	/* REQ: SF038A #90 I */

	/* Gain Recovery Rate Limit */
	GainIncSlew_UlspS_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(t_GainIncSlewTblX_Kph_u9p7,
														  t_GainIncSlewTblY_UlspS_u9p7,
														  TableSize_m(t_GainIncSlewTblX_Kph_u9p7),
														  VehicleSpeed_Kph_T_u9p7);

	GainIncSlew_UlspS_T_f32 = FPM_FixedToFloat_m(GainIncSlew_UlspS_T_u9p7, u9p7_T);

	/* Torque Recovery Rate Limit */
	TorqueIncSlew_MtrNmpS_T_u13p3 = IntplVarXY_u16_u16Xu16Y_Cnt(t_TorqueIncSlewTblX_Kph_u9p7,
														  t_TorqueIncSlewTblY_MtrNmpS_u13p3,
														  TableSize_m(t_TorqueIncSlewTblX_Kph_u9p7),
														  VehicleSpeed_Kph_T_u9p7);

	TorqueIncSlew_MtrNmpS_T_f32 = FPM_FixedToFloat_m(TorqueIncSlew_MtrNmpS_T_u13p3, u13p3_T);

	/* Start of Gain Rate Limit */

	CurrAssistEOTGain_Uls_M_f32 = Limit_m(AssistEOTGain_Uls_T_f32,(CurrAssistEOTGain_Uls_M_f32 - (k_GainDecSlew_UlspS_f32*D_2MS_SEC_F32)), (CurrAssistEOTGain_Uls_M_f32 + (GainIncSlew_UlspS_T_f32*D_2MS_SEC_F32) ));

	CurrOutputRampMult_Uls_M_f32 = Limit_m(OutputRampMult_Uls_T_f32,(CurrOutputRampMult_Uls_M_f32 - (k_GainDecSlew_UlspS_f32*D_2MS_SEC_F32)), (CurrOutputRampMult_Uls_M_f32 + (GainIncSlew_UlspS_T_f32*D_2MS_SEC_F32) ));
	/* ENDREQ: SF038A #90 */

	/* End of Gain Rate Limit */


	/* Start of Torque Rate Limit */

	/* REQ: SF038A #91 I */
	CurrAssistEOTLimit_MtrNm_M_f32 = Limit_m(AssistEOTLimit_MtrNm_T_f32,(CurrAssistEOTLimit_MtrNm_M_f32 - (k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32)), (CurrAssistEOTLimit_MtrNm_M_f32 + (TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));

	CurrAssistVehSpdLimit_MtrNm_M_f32 = Limit_m(AssistVehSpdLimit_MtrNm_T_f32,(CurrAssistVehSpdLimit_MtrNm_M_f32 - (k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32)), (CurrAssistVehSpdLimit_MtrNm_M_f32 + (TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));

	CurrAssistStallLimit_MtrNm_M_f32 = Limit_m(AssistStallLimit_MtrNm_T_f32,(CurrAssistStallLimit_MtrNm_M_f32 - (k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32)), (CurrAssistStallLimit_MtrNm_M_f32 + (TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));

	CurrThermalLimit_MtrNm_M_f32 = Limit_m(ThermalLimit_MtrNm_T_f32,(CurrThermalLimit_MtrNm_M_f32 - (k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32)), (CurrThermalLimit_MtrNm_M_f32 + (TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));

	/* End of Torque Rate Limit */


	/*** Static limits for outputs ***/

	CurrAssistEOTGain_Uls_M_f32 		= Limit_m(CurrAssistEOTGain_Uls_M_f32, D_GAINLOLIMIT_ULS_F32, D_GAINHILIMIT_ULS_F32); 			/* Limit Output CurrAssistEOTGain */
	CurrOutputRampMult_Uls_M_f32	    = Limit_m(CurrOutputRampMult_Uls_M_f32, D_GAINLOLIMIT_ULS_F32, D_GAINHILIMIT_ULS_F32);		    /* Limit Output FinalCurrOutputRampMult */
	CurrAssistEOTLimit_MtrNm_M_f32 		= Limit_m(CurrAssistEOTLimit_MtrNm_M_f32, D_TRQLOLIMIT_MTRNM_F32, D_TRQHILIMIT_MTRNM_F32); 		/* Limit Output CurrAssistEOTLimit */
	CurrAssistVehSpdLimit_MtrNm_M_f32	= Limit_m(CurrAssistVehSpdLimit_MtrNm_M_f32, D_TRQLOLIMIT_MTRNM_F32, D_TRQHILIMIT_MTRNM_F32); 	/* Limit Output CurrAssistVehSpdLimit */
	CurrAssistStallLimit_MtrNm_M_f32	= Limit_m(CurrAssistStallLimit_MtrNm_M_f32, D_TRQLOLIMIT_MTRNM_F32, D_TRQHILIMIT_MTRNM_F32); 	/* Limit Output CurrAssistStallLimit */
	CurrThermalLimit_MtrNm_M_f32		= Limit_m(CurrThermalLimit_MtrNm_M_f32, D_TRQLOLIMIT_MTRNM_F32, D_TRQHILIMIT_MTRNM_F32); 		/* Limit Output CurrThermalLimit */
	/* ENDREQ: SF038A #91 I */

	/* Write local copies to module outputs */

	Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(CurrAssistEOTGain_Uls_M_f32);
	Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(CurrAssistEOTLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(CurrOutputRampMult_Uls_M_f32);
	Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(CurrAssistStallLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(CurrThermalLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(CurrAssistVehSpdLimit_MtrNm_M_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_LMTCOD_APPL_CODE
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
