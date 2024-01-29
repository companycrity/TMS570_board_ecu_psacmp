/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Cd_Nhet1CfgAndUse.c
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/Nhet1CfgAndUse/autosar
 *     SW-C Type:  Cd_Nhet1CfgAndUse
 *  Generated at:  Sat Jul 23 11:31:21 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Cd_Nhet1CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Cd_Nhet1CfgAndUse.c
* Module Description: ES-35D (Nhet1 configuration and use) branched out from ES-35C
* Project           : CBD   
* Author            : Avinash James 
*****************************************************************************/
/* Version Control:
 * Date Created:      Thr Jun 16 08:50:22 2016 %
 * %version:          1 %
 * %derived_by:       rzk04c %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/19/16  1        AJM       Nhet1 Configuration and Use, implementation of FDD_35D						 EA3#9625
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Cd_Nhet1CfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Cd_Nhet1CfgAndUse.h"
#include "Nhet1CfgAndUse_Cfg.h"
#include <string.h> 	/* Provides memset() and memcpy() definitions */			
#include "CalConstants.h"
#include "GlobalMacro.h"


/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 17.4: This deviation is required because of AUTOSAR macro for passing the array.  Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */


/* PRQA S 312 EOF 
 * MISRA-C:2004 Rule 11.5: This deviation is required for memcpy of the NHET code into the NHETs.  The rule is suppressed for the entire file */

/* PRQA S 303 EOF 
 * MISRA-C:2004 Rule 11.3: This deviation is required for register access.  The rule is suppressed for the entire file */
 

#define D_CELEMENT_CNT_U16	8U	            /* Number of elements (words) to transfer in a single event */											
#define D_CFRAME_CNT_U16	(D_CBUFLEN_CNT_U16/D_CELEMENT_CNT_U16)	/* Number of frame counts */	
#define D_BASEADDNHETRAM_CNT_U32  0xFF460000UL
#define D_WCAPHTUADDR1_CNT_U32 	(D_BASEADDNHETRAM_CNT_U32 + (uint32)(16U*(uint16)pHET_T1MSGCNTST_0) + 8UL)
													/* Need to define which instruction exactly is read from in NHET RAM */
													/* Be sure to count in bytes and include byte offset to DATA field */
													/* 0xff460000 is base address of HET RAM.  Only two options, NHET1, or NHET2 base address... */
													/* THe "16" is length in bytes of each HET instruction.  Never changes */
													/* The "pHET_T1MSGCNTST_0" is the instruction number to access with HTU, starting from 0 */
													/* the "8" is the byte offset to get the data field, this could change if you access control field... */

#define D_WCAPHTUADDR2_CNT_U32 	(D_BASEADDNHETRAM_CNT_U32 +(uint32)(16U*(uint16)pHET_T2MSGCNTST_0) + 8UL)
													/* Need to define which instruction exactly is read from in NHET RAM  */
													/* Be sure to count in bytes and include byte offset to DATA field */
													/* 0xff460000 is base address of HET RAM.  Only two options, NHET1, or NHET2 base address...*/
													/* THe "16" is length in bytes of each HET instruction.  Never changes*/
													/* The "pHET_T2MSGCNTST_0" is the instruction number to access with HTU, starting from 0*/
													/* the "8" is the byte offset to get the data field, this could change if you access control field...*/
#define D_NUMRAWDATA_CNT_U08	8U

#define D_STATUSFAULT_CNT_U08		0x04u 
#define D_PROTOCOLFAULT_CNT_U08		0x08u
#define D_CRCFAULT_CNT_U08			0x10u 

#define D_SYNCTICKS_ULS_F32			56.0f
#define D_HWTRQSCALE_HWNMPCNT_F32	(20.0f/4095.0f)
#define D_HWTRQOFFSET_HWNM_F32		10.0f	

#define D_TESTNOTOK_CNT_U08		0U
#define D_TESTOK_CNT_U08		1U

#define D_HWTQVALLOWLIMIT_HWNM_F32   (-10.0f)
#define D_HWTQVALHIGHLIMIT_HWNM_F32   10.0f

#define D_SENTSYNCDELAY_CNT_U32   148000UL

#define NHET1CFGANDUSE_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(uint8, CD_NHET1CFGANDUSE_CONST) T_SENTCRC_CNT_U08[16] = {0u,13u,7u,10u,14u,3u,9u,4u,1u,12u,6u,11u,15u,2u,8u,5u}; /* PRQA S 3218 */
#define NHET1CFGANDUSE_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */
#define NHET1CFGANDUSE_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, AUTOMATIC) Nhet1CfgAndUse_Htu1RstFail_Cnt_G_lgc; /* Global variable for peripheral startup diagnostic -- HTU1 failed to exit reset */
#define NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
#define NHET1CFGANDUSE_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, CD_NHET1CFGANDUSE_VAR)   Nhet1CfgAndUse_HwTq1PrevPulseCount_Cnt_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, CD_NHET1CFGANDUSE_VAR)   Nhet1CfgAndUse_HwTq2PrevPulseCount_Cnt_M_u32; /* PRQA S 3218 */
STATIC VAR(float32, CD_NHET1CFGANDUSE_VAR)  Nhet1CfgAndUse_HwTq1Val_HwNm_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, CD_NHET1CFGANDUSE_VAR)  Nhet1CfgAndUse_HwTq2Val_HwNm_M_f32; /* PRQA S 3218 */
STATIC VAR(uint32,   CD_NHET1CFGANDUSE_VAR) 		  	Nhet1CfgAndUse_TotalUpdates_Cnt_M_u32; /* PRQA S 3218 */
#define NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define NHET1CFGANDUSE_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq1RollgCntr_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq2RollgCntr_Cnt_M_u08; /* PRQA S 3218 */
#define NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define NHET1CFGANDUSE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(SigQlfr_State_enum, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq1Qlfr_Cnt_M_enum; /* PRQA S 3218 */
STATIC VAR(SigQlfr_State_enum, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HwTq2Qlfr_Cnt_M_enum; /* PRQA S 3218 */
STATIC VAR(DiagSettings_Str,  CD_NHET1CFGANDUSE_VAR)  Nhet1CfgAndUse_Diag_Cnt_M_str;
volatile VAR(HtuDataTrq_Str, CD_NHET1CFGANDUSE_VAR) Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str;
#define NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


typedef enum
{
	PULSE_MSGCOUNTST = 0U,
	PULSE_SYNC,
	PULSE_STATUS,
	PULSE_D0,
	PULSE_D1,
	PULSE_D2,
	PULSE_CRC,
	PULSE_MSGCOUNTEND
} NhetDataIndex_Enum;


STATIC INLINE FUNC(void, NHET1CFGANDUSE_CODE) HTU1_Init(void);
STATIC FUNC(uint8, NHET1CFGANDUSE_CODE) HwTqProtocolFault( P2CONST(uint32,  AUTOMATIC, AUTOMATIC) RawData_Cnt_T_u32,
													     P2VAR(uint32,   AUTOMATIC, AUTOMATIC) PrevPulseCount_Cnt_T_u32,
													     P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRaw_Cnt_T_f32,
													     P2VAR(uint8, AUTOMATIC, AUTOMATIC) NTCParam_Cnt_T_u08 );

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
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PeripheralStartupFlt (55u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73u)
 *   NTC_Num_IvtrPwrDiscnctFailr (74u)
 *   NTC_Num_PowerRelayInit2Flt (75u)
 *   NTC_Num_GateDrvFltInProcess (76u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90u)
 *   NTC_Num_SysVltgCorrlnFlt (91u)
 *   NTC_Num_Inv2GateDrvFltInProcess (92u)
 *   NTC_Num_Inv2GateDrvFlt (93u)
 *   NTC_Num_Inv2OnStateSingleFET (94u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_LoaRpdShutdn (170u)
 *   NTC_Num_LoaCtrldShutdn (171u)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172u)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173u)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174u)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_LxaTrqOvMode (235u)
 *   NTC_Num_LxaHwTrqMode (236u)
 *   NTC_Num_LxaHwVelMode (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 * SigQlfr_State_enum: Enumeration of integer in interval [0...2] with enumerators
 *   SIGQLFR_NORES (0u)
 *   SIGQLFR_PASS (1u)
 *   SIGQLFR_FAIL (2u)
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
 * Float: D_ZERO_ULS_F32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_CD_NHET1CFGANDUSE_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Nhet1CfgAndUse_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_NHET1CFGANDUSE_APPL_CODE) Nhet1CfgAndUse_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Nhet1CfgAndUse_Per1
 *********************************************************************************************************************/

	/* The trigger for HET sync word is written directly in memory */
	HET_SYNCRST_0.memory.data_word = 0x80U;  

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Nhet1CfgAndUse_Per2
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
 *   SInt8 Rte_IRead_Nhet1CfgAndUse_Per2_HwTq1Polarity_Cnt_s08(void)
 *   SInt8 Rte_IRead_Nhet1CfgAndUse_Per2_HwTq2Polarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_NHET1CFGANDUSE_APPL_CODE) Nhet1CfgAndUse_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Nhet1CfgAndUse_Per2
 *********************************************************************************************************************/

	/*** Temporary Variables ***/
	/* Module Inputs */
	VAR(sint8, AUTOMATIC)     HwTq1Polarity_Cnt_T_s08;  
	VAR(sint8, AUTOMATIC)     HwTq2Polarity_Cnt_T_s08; 
	VAR(uint32, AUTOMATIC)    NhetHtuSent1Raw_Cnt_T_u32[D_NUMRAWDATA_CNT_U08];
	VAR(uint32, AUTOMATIC)    NhetHtuSent2Raw_Cnt_T_u32[D_NUMRAWDATA_CNT_U08];
	
	/* Module internal */
	VAR(uint8,  AUTOMATIC)    TestOk_Cnt_T_u08;
	VAR(float32,  AUTOMATIC)  HwTq1Raw_Cnt_T_f32;
	VAR(float32,  AUTOMATIC)  HwTq2Raw_Cnt_T_f32;
	VAR(uint8,  AUTOMATIC)    NTCParam_Cnt_T_u08;
	
	/*** ------------------ ***/
	/* Read RTE Inputs */
	/* Note: FDD contains one more i/p called 'SVS_clear_lgc' which is not implemented in EA3.0 */
	HwTq1Polarity_Cnt_T_s08 = Rte_IRead_Nhet1CfgAndUse_Per2_HwTq1Polarity_Cnt_s08();
	HwTq2Polarity_Cnt_T_s08 = Rte_IRead_Nhet1CfgAndUse_Per2_HwTq2Polarity_Cnt_s08();
	
	/* Read N2HET_1 data (Torque_1 sensor SENT data) */
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_MSGCOUNTST]   	= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[0];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_SYNC]     		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[1];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_STATUS]   		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[2];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_D0]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[3];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_D1]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[4];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_D2]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[5];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_CRC]      		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[6];
	NhetHtuSent1Raw_Cnt_T_u32[PULSE_MSGCOUNTEND] 	= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[7];

	/* Read N2HET_1 data (Torque_2 sensor SENT data) */
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_MSGCOUNTST]   	= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[0];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_SYNC]     		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[1];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_STATUS]   		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[2];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_D0]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[3];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_D1]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[4];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_D2]       		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[5];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_CRC]      		= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[6];
	NhetHtuSent2Raw_Cnt_T_u32[PULSE_MSGCOUNTEND] 	= Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[7];
	
	/* -------------------------------- Torque_1 sensor SENT data processing ---------------------------------- */												 													 
	TestOk_Cnt_T_u08 = HwTqProtocolFault( NhetHtuSent1Raw_Cnt_T_u32, &Nhet1CfgAndUse_HwTq1PrevPulseCount_Cnt_M_u32,
											                         &HwTq1Raw_Cnt_T_f32,
											                         &NTCParam_Cnt_T_u08 );	
	
	/* Calculate HandWheel Torque 1 and polarity evaluation; And updates fault accumulator and sets NTC */
	/* Note: FDD says to implement ISOFaultDebounce which is not implemented for EA3.0 */
	if ( TestOk_Cnt_T_u08 == D_TESTNOTOK_CNT_U08 )  /* When fault presents */
	{
		Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08 = (uint8)DiagPStep_m((uint16)Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str); /* Increment fault accumulator */
		
		if( DiagFailed_m((uint16)Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str) == TRUE ) /* Check accumulator for NTC failed and  signal qualifier failed. */
		{
			Nhet1CfgAndUse_HwTq1Qlfr_Cnt_M_enum = SIGQLFR_FAIL;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, NTCParam_Cnt_T_u08, NTC_STATUS_FAILED);
		}
	}
	else  /* When No fault presents */
	{
		/* Calculate HandWheel Torque 1 and polarity evaluation */
		Nhet1CfgAndUse_HwTq1Val_HwNm_M_f32 = ( (HwTq1Raw_Cnt_T_f32 * D_HWTRQSCALE_HWNMPCNT_F32) - D_HWTRQOFFSET_HWNM_F32 ) * (float32)HwTq1Polarity_Cnt_T_s08;
	
		Nhet1CfgAndUse_HwTq1RollgCntr_Cnt_M_u08++; /* Update rolling counter */
		
		Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08 = (uint8)DiagNStep_m((uint16)Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str); /* Decrement fault accumulator */
		
		if(Nhet1CfgAndUse_HwTq1ErrAcc_Cnt_M_u08 == 0x0U) /* Check accumulator for NTC passed and  signal qualifier passed. */
		{
			Nhet1CfgAndUse_HwTq1Qlfr_Cnt_M_enum = SIGQLFR_PASS;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0U, NTC_STATUS_PASSED);
		}
	}
		/* ------------------------------------------------------------------------------------------------ */
	/* ----------------------------- ******************************************* ------------------------------ */
	/* -------------------------------- Torque_2 sensor SENT data processing ---------------------------------- */												 													 
	TestOk_Cnt_T_u08 = HwTqProtocolFault( NhetHtuSent2Raw_Cnt_T_u32, &Nhet1CfgAndUse_HwTq2PrevPulseCount_Cnt_M_u32,
											                         &HwTq2Raw_Cnt_T_f32,
											                         &NTCParam_Cnt_T_u08 );	
	
		/* Calculate HandWheel Torque 2 and polarity evaluation; And updates fault accumulator and sets NTC */
		/* Note: FDD says to implement ISOFaultDebounce which is not implemented for EA3.0 */
	if ( TestOk_Cnt_T_u08 == D_TESTNOTOK_CNT_U08 )  /* When fault presents */
	{
		Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08 = (uint8)DiagPStep_m((uint16)Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str); /* Increment fault accumulator */
		
		if( DiagFailed_m((uint16)Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str) == TRUE ) /* Check accumulator for NTC failed and  signal qualifier failed. */
		{
			Nhet1CfgAndUse_HwTq2Qlfr_Cnt_M_enum = SIGQLFR_FAIL;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, NTCParam_Cnt_T_u08, NTC_STATUS_FAILED);
		}
	}
	else  /* When No fault presents */
	{
		/* Calculate HandWheel Torque 2 and polarity evaluation */
		Nhet1CfgAndUse_HwTq2Val_HwNm_M_f32 = ( (HwTq2Raw_Cnt_T_f32 * D_HWTRQSCALE_HWNMPCNT_F32) - D_HWTRQOFFSET_HWNM_F32 ) * (float32)HwTq2Polarity_Cnt_T_s08;
	
		Nhet1CfgAndUse_HwTq2RollgCntr_Cnt_M_u08++; /* Update rolling counter */
		
		Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08 = (uint8)DiagNStep_m((uint16)Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08, Nhet1CfgAndUse_Diag_Cnt_M_str); /* Decrement fault accumulator */
		
		if(Nhet1CfgAndUse_HwTq2ErrAcc_Cnt_M_u08 == 0x0U) /* Check accumulator for NTC passed and  signal qualifier passed. */
		{
			Nhet1CfgAndUse_HwTq2Qlfr_Cnt_M_enum = SIGQLFR_PASS;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0U, NTC_STATUS_PASSED);
		}
	}
		/* ------------------------------------------------------------------------------------------------ */
	/* ----------------------------- ******************************************* ------------------------------ */
    Nhet1CfgAndUse_HwTq1Val_HwNm_M_f32 = Limit_m(Nhet1CfgAndUse_HwTq1Val_HwNm_M_f32, D_HWTQVALLOWLIMIT_HWNM_F32, D_HWTQVALHIGHLIMIT_HWNM_F32);
	Nhet1CfgAndUse_HwTq2Val_HwNm_M_f32 = Limit_m(Nhet1CfgAndUse_HwTq2Val_HwNm_M_f32, D_HWTQVALLOWLIMIT_HWNM_F32, D_HWTQVALHIGHLIMIT_HWNM_F32);
	
	/* Read RTE Outputs */
	(void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(Nhet1CfgAndUse_HwTq1Qlfr_Cnt_M_enum);
    (void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(Nhet1CfgAndUse_HwTq1RollgCntr_Cnt_M_u08);
    (void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32( Nhet1CfgAndUse_HwTq1Val_HwNm_M_f32 );

    (void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(Nhet1CfgAndUse_HwTq2Qlfr_Cnt_M_enum);
    (void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(Nhet1CfgAndUse_HwTq2RollgCntr_Cnt_M_u08);
    (void) Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32( Nhet1CfgAndUse_HwTq2Val_HwNm_M_f32 );
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CD_NHET1CFGANDUSE_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
  * Name:        Nhet1CfgAndUse_Init
  * Description: NHET_1 and HTU initialization
  * Inputs:      None
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, Nhet1CfgAndUse_CODE) Nhet1CfgAndUse_Init(void)
{
	
	/* ----------------------------- Start initialization of NHET 1 Peripheral ----------------------------- */
	/* TI naming: NHET 1 registers named NHET0; NHET 2 registers named NHET1 */


	NHET0->NHETGCR =
			(uint32)	(1UL << 24U) |					/* 0: Enable output buffers */
			(uint32)	(1UL << 18U) |					/* 0: When NHET is running, program fields are read-only */
			(uint32)	(1UL << 17U) |					/* 1: NHET doesn't stop when a software breakpoint is encountered.*/
			(uint32)	(0UL << 16U) |					/* 1: NHET is slave */
			(uint32)	(0UL <<  0U) ;					/* 0: Stop NHET */
	
	if( (NHET0->NHETGCR & 0x01UL) == 0UL )
	{
		/* Copy the HET0 program */
		(void) memcpy((void *) &e_HETPROGRAM0_UN, (const void *) HET_INIT0_PST, sizeof(HET_INIT0_PST));
		
		NHET0->NHETPFR =			/* Timer Prescale */
				(uint32)	(7UL << 8U) |				/* 7 -> lr=128 */
				(uint32)	(0UL << 0U) ;				/* HRPFC : High Res Pre-Scale Factor */
		
		NHET0->NHETREQENS =			/* HET Request Enable */
				(uint32)	(1UL << 4U) |				/* HTU/DMA Req line4 enable*/
				(uint32)	(1UL << 2U) |				/* HTU/DMA Req line2 enable */
				(uint32)	(1UL << 1U) ;				/* HTU/DMA Req line1 enable */

		NHET0->NHETREQDS =			/* HET Request Destination */
				(uint32)	(1UL << 4U) |				/* TDS4: Req line4 assign to DMA */
				(uint32)	(0UL << 2U) |				/* TDS2: Req line2 assign to HTU */
				(uint32)	(0UL << 1U) ;	            /* TDS1: Req line1 assign to HTU */
			
		NHET0->NHETDIR =			/* HET Direction Register */
		(uint32)	(1UL << 30U) |				/* Output : Torque 2 Sync */
		(uint32)	(0UL << 28U) |				/* Input : Torque 2 SENT  */
		(uint32)	(1UL << 18U) |				/* Output : SPI 1m */
		(uint32)	(1UL << 16U) |				/* Output : ePWM Sync */
		(uint32)	(1UL << 14U) |				/* Output : SPI 50u */
		(uint32)	(1UL << 12U) |				/* Output : Torque 1 Sync */
		(uint32)	(0UL << 10U) ;	            /* Input : Torque 1 SENT */


		NHET0->NHETPULDIS =			/* HET PULL Disable Register */
				(uint32)	(0UL << 30U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 28U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 18U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 16U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 14U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 12U) |				/* Enable Pull Functionality */
				(uint32)	(0UL << 10U) ;	            /* Enable Pull Functionality */
		
		NHET0->NHETPSL =			/* HET PULL Select Register */
				(uint32)	(1UL << 30U) |				/* Pull Up enable */
				(uint32)	(0UL << 28U) |				/* Pull Down enable*/
				(uint32)	(0UL << 18U) |				/* Pull Down enable*/
				(uint32)		(0UL << 16U) |				/* Pull Down enable */
				(uint32)		(0UL << 14U) |				/* Pull Down enable */
				(uint32)		(1UL << 12U) |				/* Pull Up enable */
				(uint32)	(0UL << 10U) ;	            /* Pull Down enable */
			
			
		NHET0->NHETPCR =			/* HET Parity Control Register */
				(uint32)	(0x0AUL << 0U) ;			/* Parity Check enable - Read/Write */
			
		NHET0->NHETSFPRLD =			/* Suppression Filter Preload Register */
				(uint32)	(0x03UL << 16U) |			/* CCDIV: CCLK = VCLK2/4 =80MHz/4=50 */
				(uint32)	(0x22UL << 0U)  ;			/* CPRLD : Counter Pre load (1.7us=34 x50ns), where 34 = 0x22h */
		
		NHET0->NHETSFENA =			/* Suppression Filter Enable Register */
				(uint32)	(0x01UL << 28U) |			/* Enable Filter  */
				(uint32)	(0x01UL << 10U) ;			/* Enable Filter  */
			
		NHET0->NHETPINDIS =			/* HET Pin Disable Register */
				(uint32)	(0x00UL << 30U) |
				(uint32)	(0x00UL << 12U) ;
	
	
		/* Initialize HET0 program data words */
		HET_T1TRGMIN_0.memory.data_word = (uint32)( D_SENTSYNCDELAY_CNT_U32 - 1000UL);
		HET_T2TRGMIN_0.memory.data_word = (uint32)( D_SENTSYNCDELAY_CNT_U32 - 1000UL);
		HET_T1TRGMAX_0.memory.data_word = D_SENTSYNCDELAY_CNT_U32; 
		HET_T2TRGMAX_0.memory.data_word = D_SENTSYNCDELAY_CNT_U32; 


		HET_SYNCMIN_0.memory.data_word =  k_SENTSyncTrgMin_Cnt_u32; 
		
		HET_SPI50U_BUF1_0.memory.data_word = (uint32)k_SPI50UOff_Cnt_u16;
		HET_SPI1m_BUF1_0.memory.data_word =  (uint32)k_SPI1mOff_Cnt_u16;
		/* Initialize HET Transfer Unit (HTU) 1 */
		HTU1_Init(); 

		
		NHET0->NHETGCR |= (uint32) 0x01UL;	/* Enable NHET */
	}
	/* ------------------------------ End initialization of NHET 1 Peripheral ------------------------------ */
	
	
	/* Initialize the Diag structure by the pStep and nStep cals */
	Nhet1CfgAndUse_Diag_Cnt_M_str.Threshold = 255U;
	Nhet1CfgAndUse_Diag_Cnt_M_str.PStep = (uint16)k_TSPstep_Cnt_u08;
	Nhet1CfgAndUse_Diag_Cnt_M_str.NStep = (uint16)k_TSNstep_Cnt_u08;
	
}
 
/*****************************************************************************
  * Name:        HTU1_Init
  * Description: This function initializes the HTU 1 module
  * Inputs:      None
  * Outputs:     None
  *
*****************************************************************************/
STATIC INLINE FUNC(void, NHET1CFGANDUSE_CODE) HTU1_Init(void)
{
	/* TI naming: HTU 1 registers named HTU0; HTU 2 registers named HTU1 */
	
 	/* check for HTU reset bit cleared; if not set flag */
	if (( HTU0REG->GC & 1UL ) == 1U)
	{
		/* Set global variable flag HTU 1 reset failed status for uDiag component */
		Nhet1CfgAndUse_Htu1RstFail_Cnt_G_lgc = TRUE;
	}
	else
	{
		/* Clear global variable flag HTU 1 reset failed status for uDiag component */
		Nhet1CfgAndUse_Htu1RstFail_Cnt_G_lgc = FALSE;
		
		/* Init HTU0 registers */
   
		/***********************************************************
		* Configure the control packet for input capture HET code *
		***********************************************************/

		/* Start by clearing the HTU memory....HTU Req 1
			Reset DIR, Size, Transfer mode means  HTU IHADDRCT = 0*/
		HTU0DCP1->IHADDRCT  = 	0U ; 
							
		HTU0DCP1->IFADDRA  =  0U;						/*clear the address of Buffer A */
		HTU0DCP1->IFADDRB  =  0U;						/*clear the address of Buffer B */

		HTU0DCP1->ITCOUNT  =  0U; 	/* IETCOUNT Element count reset to 0  */
							    	/*Frame count set to 0 to make sure it is cleared before set	*/		
													
     				

		/* Start by clearing the HTU memory....HTU Req 2*/

		HTU0DCP2->IHADDRCT  = 	0U;
							
		HTU0DCP2->IFADDRA  =  0U;						/*clear the address of Buffer A */
		HTU0DCP2->IFADDRB  =  0U;						/*clear the address of Buffer B */

		HTU0DCP2->ITCOUNT  =  0U; 			/* IETCOUNT Element count reset to 0  */
							    			/*Frame count set to 0 to make sure it is cleared before set	*/		


		/*HET instruction requests on HTU line 1 configure the control packet*/
	
		HTU0DCP1->IFADDRA = (uint32)&(Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq1_Cnt_u32[0]);
		/*Initial frame address set to the RAM buffer*/
		HTU0DCP1->ITCOUNT =
				(uint32)( (uint32)D_CELEMENT_CNT_U16 << 16U) | 	/* IETCOUNT */
				(uint32)( (uint32)D_CFRAME_CNT_U16	 << 0U)  ; 	/* IFTCOUNT */
								
		HTU0DCP1->IHADDRCT =
				(uint32)	 (0UL << 23U) | 	/* DIR */	/* set to 1 for Main memory is read and then written to NHET RAM*/
				(uint32)	 (0UL << 22U) | 	/* SIZE */
				(uint32)	 (0UL << 21U) | 	/* ADDMH */
				(uint32)	 (0UL << 20U) | 	/* ADDFM */
				(uint32)	 (1UL << 18U) | 	/* TMBA */		/* Circular buffer mode  */
				(uint32)	 (0UL << 16U) | 	/* TMBB */		/* One shot mode */
				(uint32)	((D_WCAPHTUADDR1_CNT_U32 & 0x0FFCUL) << 0U); 	/* IHADDR */
							/*address of NHET instruction data field location to start( Least significant 12 bits, with LSB 2 bits masked out)*/
	
												   
		/*HET instruction requests on HTU line 2 configure the control packet*/
	
		HTU0DCP2->IFADDRA = (uint32)&(Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str.HtuDataTrq2_Cnt_u32[0]);
		/*Initial frame address set to the RAM buffer*/
		HTU0DCP2->ITCOUNT = ((uint32)D_CELEMENT_CNT_U16 << 16U) | 	/* IETCOUNT */
							((uint32)D_CFRAME_CNT_U16	 << 0U)  ; 	/* IFTCOUNT */
						
		HTU0DCP2->IHADDRCT =

				(uint32)	 (0UL << 23U) | 	/* DIR */	/* set to 1 for Main memory is read and then written to NHET RAM*/
				(uint32)	 (0UL << 22U) | 	/* SIZE */
				(uint32)	 (0UL << 21U) | 	/* ADDMH */
				(uint32)	 (0UL << 20U) | 	/* ADDFM */
				(uint32)	 (1UL << 18U) | 	/* TMBA */		/* Circular buffer  Buffer A*/
				(uint32)	 (0UL << 16U) | 	/* TMBB */		/*  One shot mode  Buffer B*/
				(uint32)	((D_WCAPHTUADDR2_CNT_U32 & 0x0FFCUL) << 0U); 	/* IHADDR */
							/*address of NHET instruction data field location to start( Least significant 12 bits, with LSB 2 bits masked out)*/




		HTU0REG->CPENA =
				(uint32) 	(1UL << 2U) | /* DCP1 : CP B is disabled and CP A is enabled */
				(uint32)	(0UL << 3U) | /* DCP1 : CP B is disabled and CP A is enabled */
				(uint32)	(1UL << 4U) | /* DCP2 : CP B is disabled and CP A is enabled */
				(uint32)	(0UL << 5U) ; /* DCP2 : CP B is disabled and CP A is enabled */
							
		HTU0REG->PCR = 	(uint32) (0x0AUL << 0U) ;  /* Parity check is enable */

		/* Configure 1 region memory protection: */
		HTU0REG->MPCS =
				(uint32)	(0UL << 17U) |	/* MPEFT1 */	/*Cleared on reset*/
				(uint32)	(0UL << 16U) |	/* MPEFT0 */	/*Cleared on reset*/
				(uint32)	(0UL << 5U) |	/* INTENA01 */
				(uint32)	(0UL << 4U) |	/* ACCR01 */
				(uint32)	(0UL << 3U) |	/* REG01ENA */
				(uint32)	(1UL << 2U) |	/* INTENA0 */   /* Error Signaling is enabled region 0 */
				(uint32)	(1UL << 1U) |	/* ACCR */      /* HTU access forbidden outside region 0 */
				(uint32)	(1UL << 0U);	/* REG0ENA */   /* Protection outside the memory region region 0 enable */

		/* Region 0 memory protection covers the TCM RAM buffer containing the new values for the data fields of the Nhet instructions */
		HTU0REG->MP0S = (uint32)(&Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str);
		HTU0REG->MP0E = (uint32)(&Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str) + (uint32)(sizeof(Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str)-4U);

		/* enable the HTU */
		HTU0REG->GC	   =
				(uint32)	(1UL << 16U) |      /* Enable the HTU */
				(uint32)	(1UL << 8U)  |      /* Allow HTU to continue on debug */
				(uint32)	(0UL << 0U)  ;   	  /* No Reset request issued to the HTU module. */




	}				  
}





/*****************************************************************************
  * Name:        HwTqProtocolFault
  * Description: Created for common processing for T3 and T4
  * Inputs:      *RawData_Cnt_T_u32			- raw input data array
  *              *PrevPulseCount_Cnt_T_u32	- state variable for pulse count
  *              *HwTrqRaw_Cnt_T_f32	    - calculated raw handwheel torque
  *              *NTCParam_Cnt_T_u08		- NTC parameter when fault
  * Outputs:     HwTrqTest_Cnt_T_u08      	- D_TESTNOTOK_CNT_U08 when test not okay, D_TESTOK_CNT_U08 when test okay
  *
*****************************************************************************/
STATIC FUNC(uint8, NHET1CFGANDUSE_CODE) HwTqProtocolFault( P2CONST(uint32,  AUTOMATIC, AUTOMATIC) RawData_Cnt_T_u32,
													     P2VAR(uint32,   AUTOMATIC, AUTOMATIC) PrevPulseCount_Cnt_T_u32,
													     P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRaw_Cnt_T_f32,
													     P2VAR(uint8, AUTOMATIC, AUTOMATIC) NTCParam_Cnt_T_u08 )
{
	
	VAR(float32, AUTOMATIC) SyncFactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) RawDataTicks_Cnt_T_f32;
	VAR(uint32,  AUTOMATIC) RawDataTicks_Cnt_T_u32;
	VAR(uint8,   AUTOMATIC) Data_Cnt_T_u08[D_NUMRAWDATA_CNT_U08 - 4U];
	VAR(uint8,   AUTOMATIC) i;
	VAR(uint8,   AUTOMATIC) CRC_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) HwTrq_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) HwTrqTest_Cnt_T_u08;
	
	
	*HwTrqRaw_Cnt_T_f32 = 0.0f; /* Initialize to zero */
	*NTCParam_Cnt_T_u08 = 0U; /* No fault */
	HwTrqTest_Cnt_T_u08 = D_TESTOK_CNT_U08;
	
	if (RawData_Cnt_T_u32[PULSE_MSGCOUNTST] != RawData_Cnt_T_u32[PULSE_MSGCOUNTEND]) /* PRQA S 492 */
	{
		*NTCParam_Cnt_T_u08 = D_PROTOCOLFAULT_CNT_U08;
		HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
	}
	else if (RawData_Cnt_T_u32[PULSE_MSGCOUNTST] == (*PrevPulseCount_Cnt_T_u32)) /* PRQA S 492 */
	{
		*NTCParam_Cnt_T_u08 = D_PROTOCOLFAULT_CNT_U08;
		HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
	}
	else
	{
		*PrevPulseCount_Cnt_T_u32 = RawData_Cnt_T_u32[PULSE_MSGCOUNTST]; /* PRQA S 492 */
		
		SyncFactor_Uls_T_f32 = D_SYNCTICKS_ULS_F32 / ((float32)RawData_Cnt_T_u32[PULSE_SYNC]); /* PRQA S 492 */
		
		RawDataTicks_Cnt_T_f32 = (((float32)RawData_Cnt_T_u32[PULSE_STATUS]) * SyncFactor_Uls_T_f32) + 0.5f; /* PRQA S 492 */ 
		RawDataTicks_Cnt_T_u32 = (uint32)RawDataTicks_Cnt_T_f32; 
		if( (RawDataTicks_Cnt_T_u32 < 12U) || (RawDataTicks_Cnt_T_u32  > 27U) )
		{
			*NTCParam_Cnt_T_u08 = D_PROTOCOLFAULT_CNT_U08;
			HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
		}
		else if(( 3U & (RawDataTicks_Cnt_T_u32-12U)) > 0U )
		{
			*NTCParam_Cnt_T_u08 = D_STATUSFAULT_CNT_U08;
			HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
		}
		else
		{

			i = (uint8)PULSE_D0;
			while( i <= (uint8)PULSE_CRC )
			{
			/* To make sure "RawDataTicks" is rounded off, the type of RawData is converted to float and used in the RawDataTicks calculation.
			  RawDataTicks is converted again to the nearest fixed point.
			  RawDataTicks should be a ratio of RawData to ticks per PULSE_SYNC of RawData */
				RawDataTicks_Cnt_T_f32 = (((float32)RawData_Cnt_T_u32[i]) * SyncFactor_Uls_T_f32) + 0.5f; /* PRQA S 492 */
				RawDataTicks_Cnt_T_u32 = (uint32)RawDataTicks_Cnt_T_f32; 

				if( (RawDataTicks_Cnt_T_u32 < 12U) || (RawDataTicks_Cnt_T_u32 > 27U) )
				{
					*NTCParam_Cnt_T_u08 = D_PROTOCOLFAULT_CNT_U08;
					HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
					i = (uint8)PULSE_CRC + 1U;  /* Break the loop if fault found */
				}
				else
				{
					Data_Cnt_T_u08[i-3U] = (uint8)(RawDataTicks_Cnt_T_u32 - 12U); /* Size of Data_Cnt_T_u08 is 4, so 3 is subtracted to adjust the array index */
				}

				i++;

			}
		}
	}	
	
	if(HwTrqTest_Cnt_T_u08 == D_TESTOK_CNT_U08)
	{
		CRC_Cnt_T_u08 = T_SENTCRC_CNT_U08[ T_SENTCRC_CNT_U08[ T_SENTCRC_CNT_U08[ T_SENTCRC_CNT_U08[5U] ^
																					 Data_Cnt_T_u08[0U] ] ^
																  Data_Cnt_T_u08[1U] ] ^
											   Data_Cnt_T_u08[2U] ];  /* For Data_Cnt_T_u08 index means following:
																					0 -> PULSE_D0
																					1 -> PULSE_D1
																					2 -> PULSE_D2
																					3 -> PULSE_CRC  */
												
		if( CRC_Cnt_T_u08 != Data_Cnt_T_u08[3U] ) /* index 3 means PULSE_CRC */
		{
			*NTCParam_Cnt_T_u08 = D_CRCFAULT_CNT_U08;
			HwTrqTest_Cnt_T_u08 = D_TESTNOTOK_CNT_U08;
		}
		else
		{
			/* Calculate raw HwTrq value */
			HwTrq_Cnt_T_u16 =  ( (uint16)Data_Cnt_T_u08[0U] << 8U      ) +                 /*shift change made according to FDD*/
							   ( (uint16)((uint16)Data_Cnt_T_u08[1U] << 4U) ) +
						       ( (uint16)((uint16)Data_Cnt_T_u08[2U] ) ) ;					/*shift change made according to FDD*/
			
		
			*HwTrqRaw_Cnt_T_f32 = (float32)HwTrq_Cnt_T_u16;
		}
	}
		
	return HwTrqTest_Cnt_T_u08;  
}

/*****************************************************************************
  * Name:        Nhet1CfgAndUse_Per3
  * Description: Period Update -- implements the "R4 Period Update SW Flowchart Design"
  *              in section 5.1.2.1 of the "35D_Nhet1CfgAndUse.doc" file in the FDD.
  * Inputs:      PWMPeriod_u16 calculated PWM Period(from PwmCdd)
  * Outputs:     PWMPeriod_Cnt_u16 period (to be used by Nhet)
  *              HET_BUF_RDY_FLAG Buffer Ready flag for Nhet (written to Nhet RAM)
  * Usage Notes: Called from the Motor Control ISR
  *
*****************************************************************************/
FUNC(void, NHET1CFGANDUSE_CODE) Nhet1CfgAndUse_Per3(void)
{

	VAR(uint16, AUTOMATIC) PWMPeriod_Cnt_T_u16;

	/* "Compute Period & PWM DUTY CYCLE" done in other components */
	/* Just read the updated period and write it for the HET here */
	Nhet1CfgAndUse_Read_PWMPeriod_u16(&PWMPeriod_Cnt_T_u16);

	/* The order of PWMPeriod write and buffer ready data word write should be maintained */
	Nhet1CfgAndUse_Write_PWMPeriod_Cnt_u16(PWMPeriod_Cnt_T_u16);

	/*** Load the BUF Ready Flag to NHET ***/
	HET_BUF_RDY_FLAG_0.memory.data_word = 0x80u;

	/***Increment Total Period Update Counter***/
	Nhet1CfgAndUse_TotalUpdates_Cnt_M_u32++;

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
