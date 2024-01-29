/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_HwTqCorrln.c
 *     Workspace:  C:/SynergyWorkArea/Working/HwTqCorrln_2TqADAS/autosar
 *     SW-C Type:  Sa_HwTqCorrln
 *  Generated at:  Wed Oct 19 11:03:03 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_HwTqCorrln>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2016,2017 Nexteer 
* Nexteer Confidential
*
* Module File Name: Sa_HwTrqCorrln.c
* Module Description: Implements the "Hand Wheel Torque Correlation" ES057C
* Project           : CBD   
* Author            : Akilan Rathakrishnan
*****************************************************************************
* Version Control:
* Date Created:      Fri Jun 03 16:38:06 2016
* %version:          3 %
* %derived_by:       czmgrw %
*---------------------------------------------------------------------------------------------------------------------
* Date       Rev      Author    Change Description                                                               SCR #
* --------   -------  --------  ------------------------------------------------------------------------------  -------
* 06/03/16    1       Akilan     Initial implementation of FDD ES057C HwTqCorrln_v1.0.0                        EA3#8660
* 10/24/16    2       JK         Updated to FDD ES057C HwTqCorrln_v2.0.0                                      EA3#11177
* 06/05/17    3       JK         Removed extra checking logic from NTC 065                                    EA3#15721
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks

 *********************************************************************************************************************/

#include "Rte_Sa_HwTqCorrln.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "os.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "interpolation.h"

/* MISRA-C:2004 Rule 8.7: This deviation is required for Module Level Variable. Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 10.4: This deviations is allowed when using the Nexteer Fixed Point Math and Filter macros. Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements. Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 16.10:There is no appropriate action to take on the return value on  Rte_Call_NxtrDiagMgr_GetNTCActive, Rte_Call_NxtrDiagMgr_SetNTCStatus and SetRamBlockStatus */

#define D_DIFFTRQSCALE_CNT_F32               (0.5F)
#define D_SSLPFDELTALIM_HWNM_F32             (0.1F)
#define D_TQMAXSTALL_CNT_U08                 (200U)

#define D_HWTQNSTALLCNTRMAX_CNT_U08          (255U)
#define D_CORRLNBITAB_CNT_U16			     (0x03U)
#define D_IDPTSIG_CNT_U08                    (2U)
#define D_LPFSAMPLEINT_SEC_F32			     (0.1F) 
#define D_TDIAGLPFSAMPLEINT_SEC_F32		     (0.004F)

/* Module Internals */
#define HWTQCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) HwTqCor_Ch1Avl_Cnt_M_lgc;	        /* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) HwTqCor_CorrlnPass_Cnt_M_lgc;        /* PRQA S 3218 */
#define HWTQCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define HWTQCORRLN_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AUTOMATIC) HwTqCor_HwTq1LstStallCnt_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, AUTOMATIC) HwTqCor_HwTq1LstRollgCnt_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, AUTOMATIC) HwTqCor_HwTq2LstStallCnt_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, AUTOMATIC) HwTqCor_HwTq2LstRollgCnt_Cnt_M_u08;/* PRQA S 3218 */
#define HWTQCORRLN_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define HWTQCORRLN_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(float32, AUTOMATIC) HwTqCor_Ch1SumFiltOut_HwNm_D_f32;       /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) HwTqCor_Ch1LmtTqSum_HwNm_M_f32;         /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) HwTqCor_Ch1SSDiagFiltOut_HwNm_M_f32;    /* PRQA S 3218 */
#define HWTQCORRLN_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define HWTQCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) HwTqCor_Ch1CMCFiltKSV_M_str;	    /* PRQA S 3218 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) HwTqCor_Ch1SSFiltKSV_M_str;		    /* PRQA S 3218 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) HwTqCor_Ch1TraFiltKSV_M_str;		/* PRQA S 3218 */
#define HWTQCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Local functions prototype */
static FUNC(boolean, RTE_AP_DUALMOTPOSNCORRLN_APPL_CODE) CorrlnSigAvlChk(uint8 SigRollg_Cnt_T_u08,
                                                                         SigQlfr_State_enum SigQlfr_Cnt_T_enum,
                                                                         uint8 LstRollg_Cnt_T_u08,
                                                                         uint8 LstStall_Cnt_T_u08,
                                                                         uint8 MaxStall_Cnt_T_u08,
                                                                         P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntOutp_Cnt_T_u08);


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
 *   NTC_Num_PLLSlipNrcvrl (22u)
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
 *   NTC_Num_EcuIdnFlt (95u)
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
 *   NTC_Num_ImcArbrFault (127u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_TurnCntr_SpiDataFlt (135u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_EcuCrossChk (150u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
 *   NTC_Num_AgCompDiagc (167u)
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
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
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
 *   NTC_Num_DataOtherFlt2Msg_Q (327u)
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
 *   NTC_Num_MissingMsg_AM (482u)
 *   NTC_Num_InvalidMsg_AM (483u)
 *   NTC_Num_CRCFltMsg_AM (484u)
 *   NTC_Num_PgrsCntFltMsg_AM (485u)
 *   NTC_Num_DataRngFltMsg_AM (486u)
 *   NTC_Num_InvalidMsg_AL (488u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_DataRngFltMsg_AL (492u)
 *   NTC_Num_DataOtherFltMsg_AL (494u)
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
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
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
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
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt16: D_THREE_CNT_U16 = 3u
 * UInt8: D_FOUR_CNT_U08 = 4u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Float *Rte_Pim_HwTqCorrlnCh1CMCLPFSvData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_HWTQCORRLN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqCorrln_Init1
 *********************************************************************************************************************/
 
	/* Ch1 CMC LPF Init */
	LPF_Init_f32_m(*Rte_Pim_HwTqCorrlnCh1CMCLPFSvData(), k_HwTqCor_Ch1CMCLPFFc_Hz_f32, D_LPFSAMPLEINT_SEC_F32, &HwTqCor_Ch1CMCFiltKSV_M_str);

	/* Ch1 SS LPF Init */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HwTqCor_Ch1SSLPFFc_Hz_f32, D_LPFSAMPLEINT_SEC_F32, &HwTqCor_Ch1SSFiltKSV_M_str);
    
	/* Ch1 Trans Filt LPF Init */
	HwTqCor_Ch1TraFiltKSV_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per1
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
 *   SigQlfr_State_enum Rte_IRead_HwTqCorrln_Per1_HwTq1Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqCorrln_Per1_HwTq1RollgCntr_Cnt_u08(void)
 *   Float Rte_IRead_HwTqCorrln_Per1_HwTq1Val_HwNm_f32(void)
 *   SigQlfr_State_enum Rte_IRead_HwTqCorrln_Per1_HwTq2Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqCorrln_Per1_HwTq2RollgCntr_Cnt_u08(void)
 *   Float Rte_IRead_HwTqCorrln_Per1_HwTq2Val_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqCorrln_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) HwTq1Val_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTq2Val_HwNm_T_f32;
    VAR(float32, AUTOMATIC) TrqSum_HwNm_T_f32;
	VAR(SigQlfr_State_enum, AUTOMATIC) HwTq1Qlfr_State_T_enum;
	VAR(SigQlfr_State_enum, AUTOMATIC) HwTq2Qlfr_State_T_enum;
    VAR(uint16, AUTOMATIC) CorrlnSts_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) HwTq1RollgCntr_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) HwTq2RollgCntr_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) StallCntrOutp1_Cnt_T_u08;    
    VAR(uint8, AUTOMATIC) StallCntrOutp2_Cnt_T_u08; 
    VAR(boolean, AUTOMATIC) SigAvl0_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) SigAvl1_Cnt_T_lgc;    
    VAR(boolean, AUTOMATIC) NTC65_Cnt_T_lgc;    
    
    CorrlnSts_Cnt_T_u16 = 0x00U;
    
    HwTq1Qlfr_State_T_enum = Rte_IRead_HwTqCorrln_Per1_HwTq1Qlfr_State_enum();
    HwTq2Qlfr_State_T_enum = Rte_IRead_HwTqCorrln_Per1_HwTq2Qlfr_State_enum();
    
    HwTq1RollgCntr_Cnt_T_u08 = Rte_IRead_HwTqCorrln_Per1_HwTq1RollgCntr_Cnt_u08();
    HwTq2RollgCntr_Cnt_T_u08 = Rte_IRead_HwTqCorrln_Per1_HwTq2RollgCntr_Cnt_u08();
    
    HwTq1Val_HwNm_T_f32 = Rte_IRead_HwTqCorrln_Per1_HwTq1Val_HwNm_f32();
    HwTq2Val_HwNm_T_f32 = Rte_IRead_HwTqCorrln_Per1_HwTq2Val_HwNm_f32();

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_T1vsT2, &NTC65_Cnt_T_lgc);
    
	/* Correlation Signal availability */	
    
	/* SigAvlChk 0 */
    SigAvl0_Cnt_T_lgc = CorrlnSigAvlChk(HwTq1RollgCntr_Cnt_T_u08,
                                        HwTq1Qlfr_State_T_enum,
                                        HwTqCor_HwTq1LstRollgCnt_Cnt_M_u08,
                                        HwTqCor_HwTq1LstStallCnt_Cnt_M_u08,
                                        D_TQMAXSTALL_CNT_U08,
                                        &StallCntrOutp1_Cnt_T_u08);
    
    /* Update previous values */
    HwTqCor_HwTq1LstRollgCnt_Cnt_M_u08 = HwTq1RollgCntr_Cnt_T_u08;
    HwTqCor_HwTq1LstStallCnt_Cnt_M_u08 = StallCntrOutp1_Cnt_T_u08;
    
	/* SigAvlChk 1 */
    SigAvl1_Cnt_T_lgc = CorrlnSigAvlChk(HwTq2RollgCntr_Cnt_T_u08,
                                        HwTq2Qlfr_State_T_enum,
                                        HwTqCor_HwTq2LstRollgCnt_Cnt_M_u08,
                                        HwTqCor_HwTq2LstStallCnt_Cnt_M_u08,
                                        D_TQMAXSTALL_CNT_U08,
                                        &StallCntrOutp2_Cnt_T_u08);

    /* Update previous values */
    HwTqCor_HwTq2LstRollgCnt_Cnt_M_u08  = HwTq2RollgCntr_Cnt_T_u08;
    HwTqCor_HwTq2LstStallCnt_Cnt_M_u08  = StallCntrOutp2_Cnt_T_u08;

	/* Channel availability */    
    if( (SigAvl0_Cnt_T_lgc == TRUE) && ( SigAvl1_Cnt_T_lgc == TRUE))
    {
        HwTqCor_Ch1Avl_Cnt_M_lgc =  TRUE;        
    }
    else
    {
        HwTqCor_Ch1Avl_Cnt_M_lgc = FALSE;
    }
    
   
	/* Correlation */
	/* Immediate Correlation Check */
	TrqSum_HwNm_T_f32 = Abs_f32_m((HwTq1Val_HwNm_T_f32 - HwTq2Val_HwNm_T_f32) * D_DIFFTRQSCALE_CNT_F32);
	
	if(TrqSum_HwNm_T_f32 >= k_HwTqCor_Ch1ImdtCorrlnChkFailThd_HwNm_f32)
	{
		HwTqCor_CorrlnPass_Cnt_M_lgc = FALSE;
	}
	else if(TrqSum_HwNm_T_f32 <= k_HwTqCor_Ch1ImdtCorrlnChkPassThd_HwNm_f32)
	{
		HwTqCor_CorrlnPass_Cnt_M_lgc = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Determine Correlation Status Bits */    
    if((HwTqCor_CorrlnPass_Cnt_M_lgc == TRUE) && (HwTqCor_Ch1Avl_Cnt_M_lgc == TRUE) && (NTC65_Cnt_T_lgc == FALSE))
    {
		/* Generate CorrlnSts Output */	
        CorrlnSts_Cnt_T_u16 = D_CORRLNBITAB_CNT_U16;
    }    
    
    /* Write to RTE */
    Rte_IWrite_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(CorrlnSts_Cnt_T_u16);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_HwTqCorrln_Per2_HwTq1Val_HwNm_f32(void)
 *   Float Rte_IRead_HwTqCorrln_Per2_HwTq2Val_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqCorrln_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) HwTq1Val_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTq2Val_HwNm_T_f32;
    VAR(float32, AUTOMATIC) Ch1FiltFc_Hz_T_f32;
    VAR(float32, AUTOMATIC) Ch1SumFiltOut_HwNm_T_f32;
    VAR(float32, AUTOMATIC) Ch1AbsSumFiltOut_HwNm_T_f32;
    VAR(float32, AUTOMATIC) Ch1AbsSSDiagFiltOut_HwNm_T_f32;
    VAR(uint16, AUTOMATIC)  Ch1AbsTrqSum_HwNm_T_u6p10;
    VAR(uint16, AUTOMATIC)  Ch1FiltFc_Hz_T_u7p9;
	VAR(uint8, AUTOMATIC)   IdptSig_Cnt_T_u08;    
    VAR(boolean, AUTOMATIC) NTC65_Cnt_T_lgc;   
    
    HwTq1Val_HwNm_T_f32 = Rte_IRead_HwTqCorrln_Per2_HwTq1Val_HwNm_f32();
    HwTq2Val_HwNm_T_f32 = Rte_IRead_HwTqCorrln_Per2_HwTq2Val_HwNm_f32();
    
	/* Ch1 Correlation Fault Determination */
	/* TrqSum & Limit */
    HwTqCor_Ch1LmtTqSum_HwNm_M_f32 = (HwTq1Val_HwNm_T_f32 - HwTq2Val_HwNm_T_f32)* D_DIFFTRQSCALE_CNT_F32;
    HwTqCor_Ch1LmtTqSum_HwNm_M_f32 = Limit_m(HwTqCor_Ch1LmtTqSum_HwNm_M_f32,-k_HwTqCor_Ch1TqSumLim_HwNm_f32, k_HwTqCor_Ch1TqSumLim_HwNm_f32);
    
	/* Variable FC Lookup & LPF */
	Ch1AbsTrqSum_HwNm_T_u6p10 = FPM_FloatToFixed_m(Abs_f32_m(HwTqCor_Ch1LmtTqSum_HwNm_M_f32), u6p10_T);	/* PRQA S 4395 */
    Ch1FiltFc_Hz_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt(  t_HwTqCor_Ch1TraLPFIndAxis_HwNm_u6p10,
                                                        t_HwTqCor_Ch1TraLPFDepAxis_Hz_u7p9,
                                                        TableSize_m(t_HwTqCor_Ch1TraLPFIndAxis_HwNm_u6p10),
                                                        Ch1AbsTrqSum_HwNm_T_u6p10);

	Ch1FiltFc_Hz_T_f32 = FPM_FixedToFloat_m(Ch1FiltFc_Hz_T_u7p9, u7p9_T);
	
	LPF_KUpdate_f32_m(Ch1FiltFc_Hz_T_f32, D_TDIAGLPFSAMPLEINT_SEC_F32, &HwTqCor_Ch1TraFiltKSV_M_str);
	LPF_OpUpdate_f32_m(HwTqCor_Ch1LmtTqSum_HwNm_M_f32, &HwTqCor_Ch1TraFiltKSV_M_str);
	
	Ch1SumFiltOut_HwNm_T_f32 = (HwTqCor_Ch1TraFiltKSV_M_str.SV_Uls_f32 - Limit_m(HwTqCor_Ch1CMCFiltKSV_M_str.SV_Uls_f32, -k_HwTqCor_Ch1CMCLPFOpLim_HwNm_f32, k_HwTqCor_Ch1CMCLPFOpLim_HwNm_f32));
	/* Update display variable */
    HwTqCor_Ch1SumFiltOut_HwNm_D_f32 = Ch1SumFiltOut_HwNm_T_f32;
    
	Ch1AbsSumFiltOut_HwNm_T_f32  = Abs_f32_m(Ch1SumFiltOut_HwNm_T_f32);
	Ch1AbsSSDiagFiltOut_HwNm_T_f32 = Abs_f32_m(HwTqCor_Ch1SSDiagFiltOut_HwNm_M_f32);

	/* Set Fault, if prev Clear */
	if((Ch1AbsSSDiagFiltOut_HwNm_T_f32 >= k_HwTqCor_Ch1SSOpSetFltThd_HwNm_f32) || (Ch1AbsSumFiltOut_HwNm_T_f32 >= k_HwTqCor_Ch1TraSumOpSetFltThd_HwNm_f32))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1vsT2, 0x01u, NTC_STATUS_FAILED);
	}

	/* Clear Fault, if prev Set */        
	if((Ch1AbsSSDiagFiltOut_HwNm_T_f32 < k_HwTqCor_Ch1SSOpClrFltThd_HwNm_f32) && (Ch1AbsSumFiltOut_HwNm_T_f32 < k_HwTqCor_Ch1TraSumOpClrFltThd_HwNm_f32))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1vsT2, 0x00u, NTC_STATUS_PASSED);
	}

	/* Independent Signal Determination */    
	(void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_T1vsT2, &NTC65_Cnt_T_lgc);
    
    if((HwTqCor_Ch1Avl_Cnt_M_lgc == TRUE) && (NTC65_Cnt_T_lgc == FALSE))
    {
        IdptSig_Cnt_T_u08 = D_IDPTSIG_CNT_U08;
    }
    else
    {
        IdptSig_Cnt_T_u08 = 0U;        
    }
    /* Write to RTE */
    Rte_IWrite_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(IdptSig_Cnt_T_u08);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_HwTqCorrln_Per3_HwTqVal_HwNm_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqCorrln_Per3
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) HwTqVal_HwNm_T_f32;
	VAR(float32, AUTOMATIC) Ch1SSDiagFiltOut_HwNm_T_f32;
    VAR(float32, AUTOMATIC) HwTqCor_Ch1SSLimDiagFiltOut_HwNm_T_f32; 
    
    HwTqVal_HwNm_T_f32 = Rte_IRead_HwTqCorrln_Per3_HwTqVal_HwNm_f32();
    
	/* Ch1 Long Term Offset Compensation */
	Ch1SSDiagFiltOut_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTqCor_Ch1TraFiltKSV_M_str.SV_Uls_f32, &HwTqCor_Ch1SSFiltKSV_M_str);
	HwTqCor_Ch1SSLimDiagFiltOut_HwNm_T_f32 = Limit_m(Ch1SSDiagFiltOut_HwNm_T_f32,-(k_HwTqCor_Ch1SSOpSetFltThd_HwNm_f32 + D_SSLPFDELTALIM_HWNM_F32),(k_HwTqCor_Ch1SSOpSetFltThd_HwNm_f32 + D_SSLPFDELTALIM_HWNM_F32));
    
    SuspendAllInterrupts(); /* Enter exclusive area */  
    HwTqCor_Ch1SSDiagFiltOut_HwNm_M_f32 = HwTqCor_Ch1SSLimDiagFiltOut_HwNm_T_f32;
    ResumeAllInterrupts(); /* Exit exclusive area */
    
	if(Abs_f32_m(HwTqVal_HwNm_T_f32) < k_HwTqCor_Ch1CMCLPFActvnThd_HwNm_f32)
	{
        SuspendAllInterrupts(); /* Enter exclusive area */  
        LPF_OpUpdate_f32_m(HwTqCor_Ch1LmtTqSum_HwNm_M_f32, &HwTqCor_Ch1CMCFiltKSV_M_str);
        ResumeAllInterrupts(); /* Exit exclusive area */
		*Rte_Pim_HwTqCorrlnCh1CMCLPFSvData() = HwTqCor_Ch1CMCFiltKSV_M_str.SV_Uls_f32;
        /* Update NVM */
		(void) Rte_Call_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus(TRUE);
	} 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_HWTQCORRLN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define HWTQCORRLN_START_SEC_CODE
#include "MemMap.h"/* PRQA S 5087 */
 /*****************************************************************************************************************
  * Name        :   CorrlnSigAvlChk
  * Description :   Implementation of 'SigAvlChk0' and 'SigAvlChk1' blocks.
  *                 Checks Correlation Signal Availability.
  * Inputs      :   SigRollg_Cnt_T_u08, MaxStall_Cnt_T_u08, SigQlfr_Cnt_T_enum, LstRollg_Cnt_T_u08, LstStall_Cnt_T_u08
  * Outputs     :   *StallCntOutp_Cnt_T_u08 , SigAvl_Cnt_T_lgc
  * Usage Notes :   None
  ****************************************************************************************************************/
static FUNC(boolean, RTE_SA_HWTQCORRLN_APPL_CODE) CorrlnSigAvlChk(uint8 SigRollg_Cnt_T_u08,
                                                                          SigQlfr_State_enum SigQlfr_Cnt_T_enum,
                                                                          uint8 LstRollg_Cnt_T_u08,
                                                                          uint8 LstStall_Cnt_T_u08,
                                                                          uint8 MaxStall_Cnt_T_u08,
                                                                          P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntOutp_Cnt_T_u08)
{                      
    VAR(boolean, AUTOMATIC) SigAvl_Cnt_T_lgc;
    
    if (SigRollg_Cnt_T_u08 == LstRollg_Cnt_T_u08)
    {
        if(LstStall_Cnt_T_u08 == D_HWTQNSTALLCNTRMAX_CNT_U08)
        {
            *StallCntOutp_Cnt_T_u08 = D_HWTQNSTALLCNTRMAX_CNT_U08;
        }
        else
        {
            *StallCntOutp_Cnt_T_u08 = LstStall_Cnt_T_u08 + 1U;
        }
    }
    else
    {
        *StallCntOutp_Cnt_T_u08 = 0U;
    }
    
    if (*StallCntOutp_Cnt_T_u08 >= MaxStall_Cnt_T_u08)
    {
        SigAvl_Cnt_T_lgc = FALSE;
    }
    else
    {
        if(SigQlfr_Cnt_T_enum < SIGQLFR_FAIL)                                                           
        {
            SigAvl_Cnt_T_lgc = TRUE;
        }
        else
        {
            SigAvl_Cnt_T_lgc = FALSE;
        }
    }
    return SigAvl_Cnt_T_lgc;
}
#define HWTQCORRLN_STOP_SEC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
