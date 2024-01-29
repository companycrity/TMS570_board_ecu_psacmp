/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PsaAgArbn.c
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PsaAgArbn-nz2999/PsaAgArbn/autosar
 *     SW-C Type:  Ap_PsaAgArbn
 *  Generated at:  Tue Apr 24 14:59:44 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PsaAgArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2017-2018 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_PsaAgArbn.c
 * Module Description: PSA Angle Arbitration
 * Project           : CBD
 * Author            : Jayakrishnan Thundathil
 **********************************************************************************************************************
 * Version Control:
 * %version:          8 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 10/02/17  1        JK        CF39A Initial Creation                                                        EA3#13858
 * 21/03/17  2        JK        Anomaly fix EA3#14700                                                         EA3#14766
 * 04/04/17  3        JK        Updated to FDD v1.2.0                                                         EA3#15033
 * 04/26/17  4        ML        Updated to FDD v1.3.0                                                         EA3#15338
 * 05/17/17  5        ML        Updated Constant Values                                                       EA3#15870
 * 02/13/18  6        KByrski   Updated to FDD v2.0.0                                                         EA3#18855
 * 04/13/18  7        KByrski   Updated to FDD v2.1.0                                                         EA3#19604
 * 04/24/18  8        KByrski   Updated to FDD v2.2.0                                                         EA3#19673
 *********************************************************************************************************************/
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


 Runnable Entities:
 ==================
  PsaAgArbn_Init1
    Function initialization. It sets the NTC to PASSED, checks NVM validity and writes default values for Used Offset and Computed Offset.

  PsaAgArbn_Per1
    Periodic Runnable executed at every 0.002 sec zone 10b.

  PsaAgArbn_SCom_PsaAaCmd
    Diagnostic Service to write values for UsedOffset and NVM RAM block.

 *********************************************************************************************************************/

#include "Rte_Ap_PsaAgArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "CalConstants.h"
#include "interpolation.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.Rule suppressed by line at each occurrence. */

/* PRQA S 4395 EOF
 * MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.The rule is suppressed for the entire file */

/* MISRA-C: 2004 Rule 16.10 : Deviation required for casting the return value to void for all RTE function calls */

/********************************************* Embedded Local Constants **********************************************/
#define D_ABSLTHWPOSNMAXLIM_HWDEG_F32           (1600.0F)
#define D_ABSLTHWPOSNMINLIM_HWDEG_F32           (-1600.0F)
#define D_ALGNDRELPOSNSTSINI_CNT_U08            (0U)
#define D_ALGNDRELPOSNSTSVLD_CNT_U08            (100U)
#define D_NVMMAXOFFSLIM_HWDEG_F32               (1679.0F)
#define D_NVMMINOFFSLIM_HWDEG_F32               (-1679.0F)
#define D_OFFSCOEFF_ULS_F32                     (0.5F)
#define D_OFFSMAXLIM_HWDEG_F32                  (1679.0F)
#define D_OFFSMINLIM_HWDEG_F32                  (0.0F)
#define D_RELHWPOSNMAXLIM_HWDEG_F32             (1630.0F)
#define D_RELHWPOSNMINLIM_HWDEG_F32             (-1630.0F)
#define D_RELPOSNSNSRSTSFAIL_CNT_U08            (255U)
#define D_RELPOSNSTSVLD_CNT_U08                 (100U)
#define D_SRCDIAG_CNT_U08                       (1U)
#define D_SRCESC_CNT_U08                        (2U)
#define D_SRCNONE_CNT_U08                       (0U)
#define D_ZERO_HWDEG_F32                        (0.0F)

typedef enum {
    PSAAGAN_INIT = 0U,
    PSAAGAN_POWERCUT = 1U,
    PSAAGAN_PROCESSING = 2U,
    PSAAGAN_DEFECT = 3U
} PsaAgAn_EscOffsSt_Enum;

typedef enum {
    PSAAGAN_MODININ = 0U,
    PSAAGAN_MODREL = 1U,
    PSAAGAN_MODABSLT = 2U,
    PSAAGAN_MODFAIL = 3U
} PsaAgAn_PsaAgArbnSnsrMod_Enum;

/*********************************************** Module level variables **********************************************/
#define PSAAGARBN_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_EscProc_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_ResetEsc_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_AbsltHwPosnLvl2_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_AgArbnOffsFlt_Cnt_M_lgc;                                /* PRQA S 3218 */
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_StInit_Cnt_M_lgc;
STATIC volatile VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_AgArbnOffsFltDetd_Cnt_D_lgc;                   /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_AgArbnOffsFlt_Cnt_D_lgc;                       /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSAAGARBN_VAR) PsaAgAn_VehCdn_Cnt_D_lgc;                              /* PRQA S 3218 */
#define PSAAGARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define PSAAGARBN_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_PSAAGARBN_VAR) PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32;
STATIC VAR(uint32, AP_PSAAGARBN_VAR) PsaAgAn_VehCondTimer_mS_M_u32;                                   /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PSAAGARBN_VAR) PsaAgAn_OffsOverlap_HwDeg_D_f32;                       /* PRQA S 3218 */
#define PSAAGARBN_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define PSAAGARBN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_PSAAGARBN_VAR) PsaAgAn_HwTrqLPF_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AP_PSAAGARBN_VAR) PsaAgAn_MtrVelLPF_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AP_PSAAGARBN_VAR) PsaAgAn_PinionTrqLPF_Uls_M_str;
STATIC VAR(PsaAgAnLrndOffs_Str, AP_PSAAGARBN_VAR) PsaAgAn_UsedOffs_Uls_M_str;
STATIC VAR(PsaAgAnLrndOffs_Str, AP_PSAAGARBN_VAR) PsaAgAn_ComputedOffs_Uls_M_str;
STATIC VAR(PsaAgAn_PsaAgArbnSnsrMod_Enum, AP_PSAAGARBN_VAR) PsaAgAn_PrevSnsrMod_Cnt_M_enum;           /* PRQA S 3218 */
STATIC VAR(PsaAgAn_PsaAgArbnSnsrMod_Enum, AP_PSAAGARBN_VAR) PsaAgAn_SnsrMod_Cnt_M_enum;
STATIC VAR(PsaAgAn_EscOffsSt_Enum, AP_PSAAGARBN_VAR) PsaAgAn_EscOffsSt_Cnt_M_enum;                    /* PRQA S 3218 */
#define PSAAGARBN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************** Function Prototypes *************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) ESCOffsMngr(VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc,
                                                      VAR(float32, AUTOMATIC) EscOffsFromSerlCom_HwDeg_T_f32,
                                                      VAR(float32, AUTOMATIC) EscPrecisionFromSerlCom_HwDeg_T_f32);

STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) OffsConsistencyFltMngt(VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc,
                                                                 VAR(float32, AUTOMATIC) EscMinOffset_HwDeg_T_f32,
                                                                 VAR(float32, AUTOMATIC) EscMaxOffset_HwDeg_T_f32);

STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SnsrMon(VAR(uint8,   AUTOMATIC) CumMechMtrPosStatus_Cnt_T_u08,
                                                  VAR(boolean, AUTOMATIC) EscOffsEna_Cnt_T_lgc,
                                                  VAR(uint8,   AUTOMATIC) AlignedCumMechMtrPosStatus_Cnt_T_u08,
                                                  VAR(float32, AUTOMATIC) AlignedRelHwPos_HwDeg_T_f32,
                                                  VAR(float32, AUTOMATIC) RelHwPos_HwDeg_T_f32);

STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SnsrSupv(void);

STATIC FUNC(PsaAgArbnSt_Enum, AP_PSAAGARBN_APPL_CODE) RecommendedState(void);

STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) GenRawAbsltHwPosnSignals(P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnVld_Cnt_T_lgc,
                                                                   P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnLvl1_Cnt_T_lgc,
                                                                   P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnLvl2_Cnt_T_lgc,
                                                                   P2VAR(float32, AUTOMATIC, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
                                                                   P2VAR(float32, AUTOMATIC, AUTOMATIC) AbsltHwPosnPrecision_HwDeg_T_f32);

STATIC FUNC(boolean, AP_PSAAGARBN_APPL_CODE) VehCondChk(VAR(float32, AUTOMATIC) FiltMtrVelCRF_MtrRadpS_T_f32,
                                                        VAR(float32, AUTOMATIC) FiltPinionTrq_HwNm_T_f32,
                                                        VAR(float32, AUTOMATIC) FiltHwTrq_HwNm_T_f32,
                                                        VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
                                                        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc);

STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SwitchOffs(VAR(boolean, AUTOMATIC) VehCond_Cnt_T_lgc);

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
 *   NTC_Num_IMCLossOfCom (125u)
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
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151u)
 *   NTC_Num_EcuConfigMismatch (152u)
 *   NTC_Num_MotBasdHwAgFlt (153u)
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
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_PHAScratchPadTrf (503u)
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
 * PsaAgArbnDiagCmdReq_Enum: Enumeration of integer in interval [0...2] with enumerators
 *   PSAAGARBNDIAGCMDREQ_DIAGNOACTN (0u)
 *   PSAAGARBNDIAGCMDREQ_DIAGRSTREQ (1u)
 *   PSAAGARBNDIAGCMDREQ_DIAGCENTR (2u)
 * PsaAgArbnSt_Enum: Enumeration of integer in interval [0...7] with enumerators
 *   PSAAGARBNST_STININ (0u)
 *   PSAAGARBNST_STPND (1u)
 *   PSAAGARBNST_STNOSYNCN (2u)
 *   PSAAGARBNST_STESCSYNCN (3u)
 *   PSAAGARBNST_STDIAGSYNCN (4u)
 *   PSAAGARBNST_STALTVSYNCN (5u)
 *   PSAAGARBNST_UNUSED (6u)
 *   PSAAGARBNST_STFAIL (7u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * PsaAgAnLrndOffs_Str: Record with elements
 *   MaxOffset of type Float
 *   MinOffset of type Float
 *   MaxSrc of type UInt8
 *   MinSrc of type UInt8
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
 * PsaAgArbnSt_Enum: D_PSAAGARBNSTINIT_CNT_ENUM = 0u
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
 *   PsaAgAnLrndOffs_Str *Rte_Pim_PsaAgArbnLrndOffsData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSAAGARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PsaAgArbn_Init1_EscOffsEna_Cnt_lgc(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PsaAgArbn_Init1
 *********************************************************************************************************************/

    VAR(boolean, AUTOMATIC) EscOffsEna_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NTCActive_Cnt_T_lgc;
    VAR(NvM_RequestResultType, AUTOMATIC) NVMStsReqRes_Cnt_T_enum;

    EscOffsEna_Cnt_T_lgc = Rte_IRead_PsaAgArbn_Init1_EscOffsEna_Cnt_lgc();

    (void) Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(&NVMStsReqRes_Cnt_T_enum);
    (void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_EEPROMCloseFailed, &NTCActive_Cnt_T_lgc);

    if ((NVMStsReqRes_Cnt_T_enum != NVM_REQ_OK) ||
        ((EscOffsEna_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
         ((Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc != D_SRCNONE_CNT_U08) ||
          (Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc != D_SRCNONE_CNT_U08))) ||
        (NTCActive_Cnt_T_lgc != FALSE))
    {
        /* Direct Write Block with Default Values */
        Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
        Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
        Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
        Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

        (void) Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(TRUE);
    }

    if ((Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc == D_SRCNONE_CNT_U08) ||
        (Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc == D_SRCNONE_CNT_U08))
    {
        /* Write Default Offsets when no Src */
        Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
        Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
        Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
        Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;
    }

    PsaAgAn_UsedOffs_Uls_M_str.MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
    PsaAgAn_UsedOffs_Uls_M_str.MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
    PsaAgAn_UsedOffs_Uls_M_str.MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
    PsaAgAn_UsedOffs_Uls_M_str.MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

    PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
    PsaAgAn_ComputedOffs_Uls_M_str.MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
    PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
    PsaAgAn_ComputedOffs_Uls_M_str.MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

    /* Init Low Pass Filters */
    LPF_Init_f32_m(D_ZERO_ULS_F32, k_PsaAgAn_HwTrqFilt_Hz_f32,     D_2MS_SEC_F32, &PsaAgAn_HwTrqLPF_Uls_M_str);
    LPF_Init_f32_m(D_ZERO_ULS_F32, k_PsaAgAn_MtrVelFilt_Hz_f32,    D_2MS_SEC_F32, &PsaAgAn_MtrVelLPF_Uls_M_str);
    LPF_Init_f32_m(D_ZERO_ULS_F32, k_PsaAgAn_PinionTrqFilt_Hz_f32, D_2MS_SEC_F32, &PsaAgAn_PinionTrqLPF_Uls_M_str);

    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0U, NTC_STATUS_PASSED);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_Per1
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
 *   UInt8 Rte_IRead_PsaAgArbn_Per1_AlignedCumMechMtrPosStatus_Cnt_u08(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_AlignedRelHwPos_HwDeg_f32(void)
 *   UInt8 Rte_IRead_PsaAgArbn_Per1_CumMechMtrPosStatus_Cnt_u08(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscAckFromSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscDataVldFromSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscOffsEna_Cnt_lgc(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_EscOffsFromSerlCom_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_RelHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_SensorlessAuthority_Uls_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_SensorlessHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_TorqueCmdCRF_MtrNm_f32(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(PsaAgArbnSt_Enum data)
 *   PsaAgArbnSt_Enum *Rte_IWriteRef_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PsaAgArbn_Per1
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) AlignedRelHwPos_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(float32, AUTOMATIC) MtrVelCRF_MtrRadpS_T_f32;
    VAR(float32, AUTOMATIC) RelHwPos_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) SensorlessAuthority_Uls_T_f32;
    VAR(float32, AUTOMATIC) SensorlessHwPos_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) EscOffsFromSerlCom_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) EscPrecisionFromSerlCom_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) TorqueCmdCRF_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
    VAR(uint8,   AUTOMATIC) AlignedCumMechMtrPosStatus_Cnt_T_u08;
    VAR(uint8,   AUTOMATIC) CumMechMtrPosStatus_Cnt_T_u08;
    VAR(boolean, AUTOMATIC) EscOffsEna_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EscAckFromSerlCom_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;

    VAR(float32, AUTOMATIC) AbsltHwPosnPrecision_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
    VAR(boolean, AUTOMATIC) AbsltHwPosnVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) AbsltHwPosnLvl1_Cnt_T_lgc;

    VAR(float32, AUTOMATIC) FiltHwTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) FiltPinionTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) FiltMtrVelCRF_MtrRadpS_T_f32;
    VAR(float32, AUTOMATIC) AbsltHwAuthority_Uls_T_f32;
    VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32;
    VAR(uint16, AUTOMATIC) AbsltHwPosnPrecision_HwDeg_T_u16p0;
    VAR(uint16, AUTOMATIC) AbsltHwAuthority_Uls_T_u1p15;
    VAR(PsaAgArbnSt_Enum, AUTOMATIC) RecomSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) VehCond_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ResetDone_Cnt_T_lgc;
    VAR(PsaAgArbnSt_Enum, AUTOMATIC) AgArbnStToSerlCom_Cnt_T_enum;

    AlignedCumMechMtrPosStatus_Cnt_T_u08  = Rte_IRead_PsaAgArbn_Per1_AlignedCumMechMtrPosStatus_Cnt_u08();
    AlignedRelHwPos_HwDeg_T_f32           = Rte_IRead_PsaAgArbn_Per1_AlignedRelHwPos_HwDeg_f32();
    CumMechMtrPosStatus_Cnt_T_u08         = Rte_IRead_PsaAgArbn_Per1_CumMechMtrPosStatus_Cnt_u08();
    EscOffsEna_Cnt_T_lgc                  = Rte_IRead_PsaAgArbn_Per1_EscOffsEna_Cnt_lgc();
    HwTorque_HwNm_T_f32                   = Rte_IRead_PsaAgArbn_Per1_HwTorque_HwNm_f32();
    MtrVelCRF_MtrRadpS_T_f32              = Rte_IRead_PsaAgArbn_Per1_MtrVelCRF_MtrRadpS_f32();
    RelHwPos_HwDeg_T_f32                  = Rte_IRead_PsaAgArbn_Per1_RelHwPos_HwDeg_f32();
    SensorlessAuthority_Uls_T_f32         = Rte_IRead_PsaAgArbn_Per1_SensorlessAuthority_Uls_f32();
    SensorlessHwPos_HwDeg_T_f32           = Rte_IRead_PsaAgArbn_Per1_SensorlessHwPos_HwDeg_f32();
    EscAckFromSerlCom_Cnt_T_lgc           = Rte_IRead_PsaAgArbn_Per1_EscAckFromSerlCom_Cnt_lgc();
    EscDataVldFromSerlCom_Cnt_T_lgc       = Rte_IRead_PsaAgArbn_Per1_EscDataVldFromSerlCom_Cnt_lgc();
    EscOffsFromSerlCom_HwDeg_T_f32        = Rte_IRead_PsaAgArbn_Per1_EscOffsFromSerlCom_HwDeg_f32();
    EscPrecisionFromSerlCom_HwDeg_T_f32   = Rte_IRead_PsaAgArbn_Per1_EscPrecisionFromSerlCom_HwDeg_f32();
    TorqueCmdCRF_MtrNm_T_f32              = Rte_IRead_PsaAgArbn_Per1_TorqueCmdCRF_MtrNm_f32();
    VehicleSpeedValid_Cnt_T_lgc           = Rte_IRead_PsaAgArbn_Per1_VehicleSpeedValid_Cnt_lgc();
    VehicleSpeed_Kph_T_f32                = Rte_IRead_PsaAgArbn_Per1_VehicleSpeed_Kph_f32();

    /* Relative Handwheel Position and Offset Management */
    /* ESC Offset Manager */
    ESCOffsMngr(EscDataVldFromSerlCom_Cnt_T_lgc,
                EscOffsFromSerlCom_HwDeg_T_f32,
                EscPrecisionFromSerlCom_HwDeg_T_f32);

    /* Sensor Monitoring */
    SnsrMon(CumMechMtrPosStatus_Cnt_T_u08,
            EscOffsEna_Cnt_T_lgc,
            AlignedCumMechMtrPosStatus_Cnt_T_u08,
            AlignedRelHwPos_HwDeg_T_f32,
            RelHwPos_HwDeg_T_f32);

    /* Sensor Supervision */
    SnsrSupv();

    /* Recommended State */
    RecomSt_Cnt_T_enum = RecommendedState();

    /* ESC Offset State */
    if (PsaAgAn_StInit_Cnt_M_lgc != D_FALSE_CNT_LGC)
    {
        if ((PsaAgAn_SnsrMod_Cnt_M_enum == PSAAGAN_MODFAIL) &&
            (EscOffsEna_Cnt_T_lgc != D_FALSE_CNT_LGC))
        {
            PsaAgAn_EscOffsSt_Cnt_M_enum = PSAAGAN_DEFECT;
        }

        switch (PsaAgAn_EscOffsSt_Cnt_M_enum)
        {
            case PSAAGAN_INIT:
                if ((PsaAgAn_SnsrMod_Cnt_M_enum == PSAAGAN_MODABSLT) &&
                    (RecomSt_Cnt_T_enum != PSAAGARBNST_STNOSYNCN))
                {
                    PsaAgAn_EscOffsSt_Cnt_M_enum = PSAAGAN_PROCESSING;
                }
                else if ((PsaAgAn_SnsrMod_Cnt_M_enum != PSAAGAN_MODININ) &&
                         (EscOffsEna_Cnt_T_lgc != D_FALSE_CNT_LGC))
                {
                    PsaAgAn_EscOffsSt_Cnt_M_enum = PSAAGAN_POWERCUT;
                }
                else
                {
                    /* Remain in Init state */
                }
            break;

            case PSAAGAN_POWERCUT:
                if (EscAckFromSerlCom_Cnt_T_lgc != D_FALSE_CNT_LGC)
                {
                    PsaAgAn_EscOffsSt_Cnt_M_enum = PSAAGAN_PROCESSING;
                }
            break;

            case PSAAGAN_PROCESSING:
                if (PsaAgAn_ResetEsc_Cnt_M_lgc != D_FALSE_CNT_LGC)
                {
                    PsaAgAn_EscOffsSt_Cnt_M_enum = PSAAGAN_POWERCUT;
                }
            break;

            /* PSAAGAN_DEFECT */
            default:
            break;
        }
    }

    switch (PsaAgAn_EscOffsSt_Cnt_M_enum)
    {
        case PSAAGAN_INIT:
            PsaAgAn_EscProc_Cnt_M_lgc = D_FALSE_CNT_LGC;
            ResetDone_Cnt_T_lgc = D_FALSE_CNT_LGC;
            AgArbnStToSerlCom_Cnt_T_enum = PSAAGARBNST_STININ;
        break;

        case PSAAGAN_POWERCUT:
            PsaAgAn_EscProc_Cnt_M_lgc = D_FALSE_CNT_LGC;
            ResetDone_Cnt_T_lgc = D_TRUE_CNT_LGC;
            AgArbnStToSerlCom_Cnt_T_enum = PSAAGARBNST_STPND;
        break;

        case PSAAGAN_PROCESSING:
            PsaAgAn_EscProc_Cnt_M_lgc = D_TRUE_CNT_LGC;
            ResetDone_Cnt_T_lgc = D_FALSE_CNT_LGC;
            AgArbnStToSerlCom_Cnt_T_enum = RecomSt_Cnt_T_enum;
        break;

        /* PSAAGAN_DEFECT */
        default:
            PsaAgAn_EscProc_Cnt_M_lgc = D_FALSE_CNT_LGC;
            ResetDone_Cnt_T_lgc = D_TRUE_CNT_LGC;
            AgArbnStToSerlCom_Cnt_T_enum = PSAAGARBNST_STFAIL;
        break;
    }

    if (ResetDone_Cnt_T_lgc != D_FALSE_CNT_LGC)
    {
        /* ClearResetFlag */
        PsaAgAn_ResetEsc_Cnt_M_lgc = D_FALSE_CNT_LGC;
    }

    /* Veh Conditions */
    /* Filtering */
    FiltMtrVelCRF_MtrRadpS_T_f32 = LPF_OpUpdate_f32_m(MtrVelCRF_MtrRadpS_T_f32, &PsaAgAn_MtrVelLPF_Uls_M_str);
    FiltHwTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &PsaAgAn_HwTrqLPF_Uls_M_str);

    /* PinionTqCalcFil */
    PinionTrq_HwNm_T_f32 = HwTorque_HwNm_T_f32 + (TorqueCmdCRF_MtrNm_T_f32 * k_CmnSysTrqRatio_HwNmpMtrNm_f32);
    FiltPinionTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(PinionTrq_HwNm_T_f32, &PsaAgAn_PinionTrqLPF_Uls_M_str);

    /* Vehicle */
    VehCond_Cnt_T_lgc = VehCondChk(FiltMtrVelCRF_MtrRadpS_T_f32,
                                   FiltPinionTrq_HwNm_T_f32,
                                   FiltHwTrq_HwNm_T_f32,
                                   VehicleSpeed_Kph_T_f32,
                                   VehicleSpeedValid_Cnt_T_lgc);

    /* Switch Offset */
    SwitchOffs(VehCond_Cnt_T_lgc);

    /* Raw AbsltHwPosn - for SrlComTx */
    GenRawAbsltHwPosnSignals(&AbsltHwPosnVld_Cnt_T_lgc,
                             &AbsltHwPosnLvl1_Cnt_T_lgc,
                             &PsaAgAn_AbsltHwPosnLvl2_Cnt_M_lgc,
                             &AbsltHwPosn_HwDeg_T_f32,
                             &AbsltHwPosnPrecision_HwDeg_T_f32);

    /* AbsltHwPosn with AUTHORITY (Nexteer Standard) */
    AbsltHwPosnPrecision_HwDeg_T_u16p0 = FPM_FloatToFixed_m(AbsltHwPosnPrecision_HwDeg_T_f32, u16p0_T);
    AbsltHwAuthority_Uls_T_u1p15 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PsaAgAn_AbsltHwPosnPrecX_HwDeg_u16p0,
                                                               t_PsaAgAn_AbsltHwAuthyY_Uls_u1p15,
                                                               TableSize_m(t_PsaAgAn_AbsltHwPosnPrecX_HwDeg_u16p0),
                                                               AbsltHwPosnPrecision_HwDeg_T_u16p0);
    AbsltHwAuthority_Uls_T_f32 = FPM_FixedToFloat_m(AbsltHwAuthority_Uls_T_u1p15, u1p15_T);

    if ((AbsltHwPosnVld_Cnt_T_lgc != D_FALSE_CNT_LGC) &&
        (AbsltHwAuthority_Uls_T_f32 >= SensorlessAuthority_Uls_T_f32))
    {
        /* Authority based on Precision */
        HandwheelPosition_HwDeg_T_f32 = AbsltHwPosn_HwDeg_T_f32;
        HandwheelAuthority_Uls_T_f32 = AbsltHwAuthority_Uls_T_f32;
    }
    else
    {
        /* Authority based on Sensorless Authority */
        HandwheelPosition_HwDeg_T_f32 = SensorlessHwPos_HwDeg_T_f32;
        HandwheelAuthority_Uls_T_f32 = SensorlessAuthority_Uls_T_f32;
    }

    HandwheelPosition_HwDeg_T_f32 = Limit_m(HandwheelPosition_HwDeg_T_f32, D_ABSLTHWPOSNMINLIM_HWDEG_F32, D_ABSLTHWPOSNMAXLIM_HWDEG_F32);
    HandwheelAuthority_Uls_T_f32 = Limit_m(HandwheelAuthority_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);

    /* Indicating the end of first iteration */
    PsaAgAn_StInit_Cnt_M_lgc = D_TRUE_CNT_LGC;

    (void) Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(AbsltHwPosnLvl1_Cnt_T_lgc);
    (void) Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(PsaAgAn_AbsltHwPosnLvl2_Cnt_M_lgc);
    (void) Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(AbsltHwPosnPrecision_HwDeg_T_f32);
    (void) Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(AbsltHwPosnVld_Cnt_T_lgc);
    (void) Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(AbsltHwPosn_HwDeg_T_f32);
    (void) Rte_IWrite_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(HandwheelAuthority_Uls_T_f32);
    (void) Rte_IWrite_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(HandwheelPosition_HwDeg_T_f32);
    (void) Rte_IWrite_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc);
    (void) Rte_IWrite_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32);
    (void) Rte_IWrite_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(AgArbnStToSerlCom_Cnt_T_enum);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_SCom_PsaAaCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PsaAaCmd> of PortPrototype <PsaAgArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PsaAgArbn_SCom_PsaAaCmd
 *********************************************************************************************************************/

    switch (DiagCmd_Cnt_enum)
    {
        /* DiagRstReq */
        case PSAAGARBNDIAGCMDREQ_DIAGRSTREQ:
            PsaAgAn_ResetEsc_Cnt_M_lgc = D_TRUE_CNT_LGC;
            PsaAgAn_EscProc_Cnt_M_lgc = D_FALSE_CNT_LGC;

            Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
            Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
            Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
            Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

            PsaAgAn_UsedOffs_Uls_M_str.MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
            PsaAgAn_UsedOffs_Uls_M_str.MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
            PsaAgAn_UsedOffs_Uls_M_str.MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
            PsaAgAn_UsedOffs_Uls_M_str.MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

            PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
            PsaAgAn_ComputedOffs_Uls_M_str.MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
            PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
            PsaAgAn_ComputedOffs_Uls_M_str.MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

            (void) Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(NULL_PTR);
        break;

        /* DiagCentr */
        case PSAAGARBNDIAGCMDREQ_DIAGCENTR:
            if (PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc != D_FALSE_CNT_LGC)
            {
                PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc = D_SRCDIAG_CNT_U08;
                PsaAgAn_ComputedOffs_Uls_M_str.MinSrc = D_SRCDIAG_CNT_U08;
                PsaAgAn_UsedOffs_Uls_M_str.MaxSrc = D_SRCDIAG_CNT_U08;
                PsaAgAn_UsedOffs_Uls_M_str.MinSrc = D_SRCDIAG_CNT_U08;

                PsaAgAn_UsedOffs_Uls_M_str.MaxOffset = Limit_m(PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 + (k_PsaAgAn_DiagPrec_HwDeg_f32 + k_PsaAgAn_EpsPrec_HwDeg_f32),
                                                               D_NVMMINOFFSLIM_HWDEG_F32,
                                                               D_NVMMAXOFFSLIM_HWDEG_F32);
                PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset = PsaAgAn_UsedOffs_Uls_M_str.MaxOffset;

                PsaAgAn_UsedOffs_Uls_M_str.MinOffset = Limit_m(PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 - (k_PsaAgAn_DiagPrec_HwDeg_f32 + k_PsaAgAn_EpsPrec_HwDeg_f32),
                                                               D_NVMMINOFFSLIM_HWDEG_F32,
                                                               D_NVMMAXOFFSLIM_HWDEG_F32);
                PsaAgAn_ComputedOffs_Uls_M_str.MinOffset = PsaAgAn_UsedOffs_Uls_M_str.MinOffset;

                if (PsaAgAn_SnsrMod_Cnt_M_enum == PSAAGAN_MODABSLT)
                {
                    /* DirectlyWriteNVM */
                    Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = PsaAgAn_UsedOffs_Uls_M_str.MaxOffset;
                    Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = PsaAgAn_UsedOffs_Uls_M_str.MinOffset;
                    Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = PsaAgAn_UsedOffs_Uls_M_str.MaxSrc;
                    Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = PsaAgAn_UsedOffs_Uls_M_str.MinSrc;

                    (void) Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(NULL_PTR);
                }
            }
        break;

        /* DefaultDiagNoActn */
        default:
        break;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSAAGARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define RTE_START_SEC_AP_PSAAGARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * Name:        ESCOffsMngr
 * Description: Implements the "ESC Offset Manager" and "ESC Comparison" blocks in FDD
 * Inputs:      EscDataVldFromSerlCom_Cnt_T_lgc
 *              EscOffsFromSerlCom_HwDeg_T_f32
 *              EscPrecisionFromSerlCom_HwDeg_T_f32
 * Outputs:     None
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) ESCOffsMngr(VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc,
                                                      VAR(float32, AUTOMATIC) EscOffsFromSerlCom_HwDeg_T_f32,
                                                      VAR(float32, AUTOMATIC) EscPrecisionFromSerlCom_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) EscMaxOffs_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) EscMinOffs_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) UseEscOffs_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) EscOffs_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) Prcsn_HwDeg_T_f32;

    if ((PsaAgAn_EscProc_Cnt_M_lgc != D_FALSE_CNT_LGC) &&
        (EscDataVldFromSerlCom_Cnt_T_lgc != D_FALSE_CNT_LGC))
    {
        UseEscOffs_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        UseEscOffs_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    Prcsn_HwDeg_T_f32 = EscPrecisionFromSerlCom_HwDeg_T_f32 + k_PsaAgAn_EpsPrec_HwDeg_f32;
    EscOffs_HwDeg_T_f32 = EscOffsFromSerlCom_HwDeg_T_f32 * k_PsaAgAn_OffsetPolarity_HwDeg_f32;

    EscMaxOffs_HwDeg_T_f32 = EscOffs_HwDeg_T_f32 + Prcsn_HwDeg_T_f32;
    EscMinOffs_HwDeg_T_f32 = EscOffs_HwDeg_T_f32 - Prcsn_HwDeg_T_f32;

    /* Offset Consistency NTC */
    OffsConsistencyFltMngt(EscDataVldFromSerlCom_Cnt_T_lgc, EscMinOffs_HwDeg_T_f32, EscMaxOffs_HwDeg_T_f32);

    /* ESC Comparison */
    if (UseEscOffs_Cnt_T_lgc != D_FALSE_CNT_LGC)
    {
        if ((((EscMaxOffs_HwDeg_T_f32 - EscMinOffs_HwDeg_T_f32) <= (PsaAgAn_UsedOffs_Uls_M_str.MaxOffset - PsaAgAn_UsedOffs_Uls_M_str.MinOffset)) &&
             (PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc == D_FALSE_CNT_LGC)) ||
            (PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc != D_FALSE_CNT_LGC))
        {
            /* UpdateComputedOffset */
            PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset = Limit_m(EscMaxOffs_HwDeg_T_f32, D_NVMMINOFFSLIM_HWDEG_F32, D_NVMMAXOFFSLIM_HWDEG_F32);
            PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc = D_SRCESC_CNT_U08;
            PsaAgAn_ComputedOffs_Uls_M_str.MinOffset = Limit_m(EscMinOffs_HwDeg_T_f32, D_NVMMINOFFSLIM_HWDEG_F32, D_NVMMAXOFFSLIM_HWDEG_F32);
            PsaAgAn_ComputedOffs_Uls_M_str.MinSrc = D_SRCESC_CNT_U08;

            if (PsaAgAn_SnsrMod_Cnt_M_enum == PSAAGAN_MODABSLT)
            {
                /* SetRamBlk */
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = PsaAgAn_ComputedOffs_Uls_M_str.MinOffset;
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = PsaAgAn_ComputedOffs_Uls_M_str.MinSrc;

                (void) Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(TRUE);
            }
        }
    }

}

/**********************************************************************************************************************
 * Name:        OffsConsistencyFltMngt
 * Description: Implements the "Offset Consistency NTC" block in FDD
 * Inputs:      EscDataVldFromSerlCom_Cnt_T_lgc
 *              EscMinOffset_HwDeg_T_f32
 *              EscMaxOffset_HwDeg_T_f32
 * Outputs:     None
 * Usage Notes: Called by ESCOffsMngr
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) OffsConsistencyFltMngt(VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc,
                                                                 VAR(float32, AUTOMATIC) EscMinOffset_HwDeg_T_f32,
                                                                 VAR(float32, AUTOMATIC) EscMaxOffset_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) OffsOverlap_HwDeg_T_f32;

    if ((PsaAgAn_UsedOffs_Uls_M_str.MinSrc != D_SRCNONE_CNT_U08) &&
        (PsaAgAn_UsedOffs_Uls_M_str.MaxSrc != D_SRCNONE_CNT_U08) &&
        (EscDataVldFromSerlCom_Cnt_T_lgc != D_FALSE_CNT_LGC))
    {
        /* NTC Management */
        PsaAgAn_AgArbnOffsFlt_Cnt_D_lgc = PsaAgAn_AgArbnOffsFlt_Cnt_M_lgc;

        OffsOverlap_HwDeg_T_f32 = Min_m(EscMaxOffset_HwDeg_T_f32, PsaAgAn_UsedOffs_Uls_M_str.MaxOffset) -
                                  Max_m(EscMinOffset_HwDeg_T_f32, PsaAgAn_UsedOffs_Uls_M_str.MinOffset) -
                                  k_PsaAgAn_MinPrecFail_HwDeg_f32;

        PsaAgAn_OffsOverlap_HwDeg_D_f32 = OffsOverlap_HwDeg_T_f32;

        if (OffsOverlap_HwDeg_T_f32 < D_ZERO_ULS_F32)
        {
            /* SetNTC */
            PsaAgAn_AgArbnOffsFlt_Cnt_M_lgc = D_TRUE_CNT_LGC;
            PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc = D_TRUE_CNT_LGC;

            (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0U, NTC_STATUS_FAILED);
        }
        else
        {
            /* CheckForClearNTC */
            if (((PsaAgAn_UsedOffs_Uls_M_str.MaxOffset - PsaAgAn_UsedOffs_Uls_M_str.MinOffset) < (EscMaxOffset_HwDeg_T_f32 - EscMinOffset_HwDeg_T_f32)) &&
                (PsaAgAn_AgArbnOffsFlt_Cnt_M_lgc != D_FALSE_CNT_LGC))
            {
                /* Clear NTC */
                PsaAgAn_AgArbnOffsFlt_Cnt_M_lgc = D_FALSE_CNT_LGC;
                PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc = D_FALSE_CNT_LGC;

                (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0U, NTC_STATUS_PASSED);
            }
        }
    }
}

/**********************************************************************************************************************
 * Name:        SnsrMon
 * Description: Implements the "Sensor Monitoring" state flow in FDD
 * Inputs:      CumMechMtrPosStatus_Cnt_T_u08
 *              EscOffsEna_Cnt_T_lgc
 *              AlignedCumMechMtrPosStatus_Cnt_T_u08
 *              AlignedRelHwPos_HwDeg_T_f32
 *              RelHwPos_HwDeg_T_f32
 * Outputs:     PsaAgAn_SnsrMod_Cnt_M_enum
 *              PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32
 *              PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SnsrMon(VAR(uint8,   AUTOMATIC) CumMechMtrPosStatus_Cnt_T_u08,
                                                  VAR(boolean, AUTOMATIC) EscOffsEna_Cnt_T_lgc,
                                                  VAR(uint8,   AUTOMATIC) AlignedCumMechMtrPosStatus_Cnt_T_u08,
                                                  VAR(float32, AUTOMATIC) AlignedRelHwPos_HwDeg_T_f32,
                                                  VAR(float32, AUTOMATIC) RelHwPos_HwDeg_T_f32)
{
    if (PsaAgAn_StInit_Cnt_M_lgc != D_FALSE_CNT_LGC)
    {
        switch (PsaAgAn_SnsrMod_Cnt_M_enum)
        {
            case PSAAGAN_MODININ:
                if (CumMechMtrPosStatus_Cnt_T_u08 == D_RELPOSNSNSRSTSFAIL_CNT_U08)
                {
                    PsaAgAn_SnsrMod_Cnt_M_enum = PSAAGAN_MODFAIL;
                }
                else if ((EscOffsEna_Cnt_T_lgc != D_FALSE_CNT_LGC) &&
                         (AlignedCumMechMtrPosStatus_Cnt_T_u08 == D_ALGNDRELPOSNSTSVLD_CNT_U08) &&
                         (CumMechMtrPosStatus_Cnt_T_u08 == D_RELPOSNSTSVLD_CNT_U08))
                {
                    PsaAgAn_SnsrMod_Cnt_M_enum = PSAAGAN_MODABSLT;
                }
                else if ((AlignedCumMechMtrPosStatus_Cnt_T_u08 != D_ALGNDRELPOSNSTSINI_CNT_U08) &&
                         (CumMechMtrPosStatus_Cnt_T_u08 == D_RELPOSNSTSVLD_CNT_U08))
                {
                    PsaAgAn_SnsrMod_Cnt_M_enum = PSAAGAN_MODREL;
                }
                else
                {
                    /* Remain in Init State */
                }
            break;

            case PSAAGAN_MODABSLT:
                if ((AlignedCumMechMtrPosStatus_Cnt_T_u08 != D_ALGNDRELPOSNSTSVLD_CNT_U08) ||
                    (CumMechMtrPosStatus_Cnt_T_u08 != D_RELPOSNSTSVLD_CNT_U08))
                {
                    PsaAgAn_SnsrMod_Cnt_M_enum = PSAAGAN_MODFAIL;
                }
            break;

            case PSAAGAN_MODREL:
                if (CumMechMtrPosStatus_Cnt_T_u08 != D_RELPOSNSTSVLD_CNT_U08)
                {
                    PsaAgAn_SnsrMod_Cnt_M_enum = PSAAGAN_MODFAIL;
                }
            break;

            /* case PSAAGAN_MODFAIL: */
            default:
            break;
        }
    }

    switch (PsaAgAn_SnsrMod_Cnt_M_enum)
    {
        case PSAAGAN_MODININ:
            PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 = D_ZERO_HWDEG_F32;
            PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc = D_FALSE_CNT_LGC;
        break;

        case PSAAGAN_MODABSLT:
            PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 = AlignedRelHwPos_HwDeg_T_f32;
            PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc = D_TRUE_CNT_LGC;
        break;

        case PSAAGAN_MODREL:
            PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 = RelHwPos_HwDeg_T_f32;
            PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc = D_TRUE_CNT_LGC;
        break;

        /* case PSAAGAN_MODFAIL:*/
        default:
            PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 = D_ZERO_HWDEG_F32;
            PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc = D_FALSE_CNT_LGC;
        break;
    }

    PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 = Limit_m(PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32, D_RELHWPOSNMINLIM_HWDEG_F32, D_RELHWPOSNMAXLIM_HWDEG_F32);
}


/**********************************************************************************************************************
 * Name:        SnsrSupv
 * Description: Implements the part of "Sensor Supervision" block in FDD
 * Inputs:      None
 * Outputs:     None
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SnsrSupv(void)
{
    if (PsaAgAn_SnsrMod_Cnt_M_enum != PsaAgAn_PrevSnsrMod_Cnt_M_enum)
    {
        /* CheckMode */
        switch (PsaAgAn_SnsrMod_Cnt_M_enum)
        {
            /* MODABSLT */
            case PSAAGAN_MODABSLT:
                PsaAgAn_UsedOffs_Uls_M_str.MaxOffset = Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset;
                PsaAgAn_UsedOffs_Uls_M_str.MinOffset = Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset;
                PsaAgAn_UsedOffs_Uls_M_str.MaxSrc = Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc;
                PsaAgAn_UsedOffs_Uls_M_str.MinSrc = Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc;

                PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset = Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset;
                PsaAgAn_ComputedOffs_Uls_M_str.MinOffset = Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset;
                PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc = Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc;
                PsaAgAn_ComputedOffs_Uls_M_str.MinSrc = Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc;
            break;

            /* MODREL */
            case PSAAGAN_MODREL:
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

                (void) Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(TRUE);
            break;

            /* MODFAIL_Default */
            default:
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxOffset = k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinOffset = k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
                Rte_Pim_PsaAgArbnLrndOffsData()->MaxSrc = k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
                Rte_Pim_PsaAgArbnLrndOffsData()->MinSrc = k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;

                (void) Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(TRUE);
            break;
        }
    }

    PsaAgAn_PrevSnsrMod_Cnt_M_enum = PsaAgAn_SnsrMod_Cnt_M_enum;
}

/**********************************************************************************************************************
 * Name:        RecommendedState
 * Description: Implements the "Recommended State" block in FDD
 * Inputs:      None
 * Outputs:     RecomSt_Cnt_T_enum
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(PsaAgArbnSt_Enum, AP_PSAAGARBN_APPL_CODE) RecommendedState(void)
{
    VAR(PsaAgArbnSt_Enum, AUTOMATIC) RecomSt_Cnt_T_enum;

    if ((PsaAgAn_UsedOffs_Uls_M_str.MinSrc == D_SRCNONE_CNT_U08) ||
        (PsaAgAn_UsedOffs_Uls_M_str.MaxSrc == D_SRCNONE_CNT_U08))
    {
        /* StateNoSync */
        RecomSt_Cnt_T_enum = PSAAGARBNST_STNOSYNCN;
    }
    else if ((PsaAgAn_UsedOffs_Uls_M_str.MinSrc == D_SRCESC_CNT_U08) ||
             (PsaAgAn_UsedOffs_Uls_M_str.MaxSrc == D_SRCESC_CNT_U08))
    {
        /* StateESCSync */
        RecomSt_Cnt_T_enum = PSAAGARBNST_STESCSYNCN;
    }
    else
    {
        /* StateDiagSyncn */
        RecomSt_Cnt_T_enum = PSAAGARBNST_STDIAGSYNCN;
    }

    return RecomSt_Cnt_T_enum;
}

/**********************************************************************************************************************
 * Name:        GenRawAbsltHwPosnSignals
 * Description: Implements the "Raw AbsltHwPosn - for SrlComTx" block in FDD
 * Inputs:      PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32
 *              PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc
 * Outputs:     AbsltHwPosnVld_Cnt_T_lgc
 *              AbsltHwPosnLvl1_Cnt_T_lgc
 *              AbsltHwPosnLvl2_Cnt_T_lgc
 *              AbsltHwPosn_HwDeg_T_f32
 *              AbsltHwPosnPrecision_HwDeg_T_f32
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) GenRawAbsltHwPosnSignals(P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnVld_Cnt_T_lgc,
                                                                   P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnLvl1_Cnt_T_lgc,
                                                                   P2VAR(boolean, AUTOMATIC, AUTOMATIC) AbsltHwPosnLvl2_Cnt_T_lgc,
                                                                   P2VAR(float32, AUTOMATIC, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
                                                                   P2VAR(float32, AUTOMATIC, AUTOMATIC) AbsltHwPosnPrecision_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) TempAbsltHwPosn_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) TempAbsltHwPosnPrecision_HwDeg_T_f32;

    /* CalcAbsltHwPosnAndPosnPrecision */
    TempAbsltHwPosnPrecision_HwDeg_T_f32 = (PsaAgAn_UsedOffs_Uls_M_str.MaxOffset - PsaAgAn_UsedOffs_Uls_M_str.MinOffset) * D_OFFSCOEFF_ULS_F32;
    TempAbsltHwPosn_HwDeg_T_f32 = (PsaAgAn_RelHwPosnToSerlCom_HwDeg_M_f32 - PsaAgAn_UsedOffs_Uls_M_str.MinOffset) - (TempAbsltHwPosnPrecision_HwDeg_T_f32);
    *AbsltHwPosn_HwDeg_T_f32 = Limit_m(TempAbsltHwPosn_HwDeg_T_f32, D_ABSLTHWPOSNMINLIM_HWDEG_F32, D_ABSLTHWPOSNMAXLIM_HWDEG_F32);
    *AbsltHwPosnPrecision_HwDeg_T_f32 = Limit_m(TempAbsltHwPosnPrecision_HwDeg_T_f32, D_OFFSMINLIM_HWDEG_F32, D_OFFSMAXLIM_HWDEG_F32);

    if (PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc != D_FALSE_CNT_LGC)
    {
        /* SetFalse */
        *AbsltHwPosnVld_Cnt_T_lgc = D_FALSE_CNT_LGC;
        *AbsltHwPosnLvl1_Cnt_T_lgc = D_FALSE_CNT_LGC;
        *AbsltHwPosnLvl2_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }
    else
    {
        /* CheckConditions */
        /* CalcAbsltHwPosnVld */
        if ((PsaAgAn_UsedOffs_Uls_M_str.MaxSrc != D_SRCNONE_CNT_U08) &&
            (PsaAgAn_UsedOffs_Uls_M_str.MinSrc != D_SRCNONE_CNT_U08) &&
            (PsaAgAn_RelHwPosnVldToSerlCom_Cnt_M_lgc != D_FALSE_CNT_LGC))
        {
            *AbsltHwPosnVld_Cnt_T_lgc = D_TRUE_CNT_LGC;
        }
        else
        {
            *AbsltHwPosnVld_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }

        /* CalcAbsltHwPosnLvl1 */
        if ((*AbsltHwPosnPrecision_HwDeg_T_f32 <= k_PsaAgAn_AbsHwPosLvl1_HwDeg_f32) &&
            (*AbsltHwPosnVld_Cnt_T_lgc != D_FALSE_CNT_LGC))
        {
            *AbsltHwPosnLvl1_Cnt_T_lgc = D_TRUE_CNT_LGC;
        }
        else
        {
            *AbsltHwPosnLvl1_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }

        /* CalcAbsltHwPosnLvl2 */
        if ((*AbsltHwPosnPrecision_HwDeg_T_f32 <= k_PsaAgAn_AbsHwPosLvl2_HwDeg_f32) &&
            (*AbsltHwPosnVld_Cnt_T_lgc != D_FALSE_CNT_LGC))
        {
            *AbsltHwPosnLvl2_Cnt_T_lgc = D_TRUE_CNT_LGC;
        }
        else
        {
            *AbsltHwPosnLvl2_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }
    }

    PsaAgAn_AbsltHwPosnLvl2_Cnt_M_lgc = *AbsltHwPosnLvl2_Cnt_T_lgc;
}

/**********************************************************************************************************************
 * Name:        VehCondChk
 * Description: Implements CF039A_PsaAgArbn/PsaAgArbn/PsaAgArbn_Per1/Veh Conditions/Vehicle block in FDD
 * Inputs:      FiltAbsltMtrVelCRF_MtrRadpS_T_f32
 *              FiltAbsltPinionTrq_HwNm_T_f32
 *              FiltAbsltHwTrq_HwNm_T_f32
 *              VehicleSpeed_Kph_T_f32
 *              VehicleSpeedValid_Cnt_T_lgc
 * Outputs:     VehCond_Cnt_T_lgc
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(boolean, AP_PSAAGARBN_APPL_CODE) VehCondChk(VAR(float32, AUTOMATIC) FiltMtrVelCRF_MtrRadpS_T_f32,
                                                        VAR(float32, AUTOMATIC) FiltPinionTrq_HwNm_T_f32,
                                                        VAR(float32, AUTOMATIC) FiltHwTrq_HwNm_T_f32,
                                                        VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
                                                        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc)
{
    VAR(float32, AUTOMATIC) FiltAbsltMtrVelCRF_MtrRadpS_T_f32;
    VAR(float32, AUTOMATIC) FiltAbsltPinionTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) FiltAbsltHwTrq_HwNm_T_f32;
    VAR(uint32,  AUTOMATIC) ElpdTi_mS_T_u32;
    VAR(boolean, AUTOMATIC) VehCond_Cnt_T_lgc;

    FiltAbsltMtrVelCRF_MtrRadpS_T_f32 = Abs_f32_m(FiltMtrVelCRF_MtrRadpS_T_f32);
    FiltAbsltHwTrq_HwNm_T_f32 = Abs_f32_m(FiltHwTrq_HwNm_T_f32);
    FiltAbsltPinionTrq_HwNm_T_f32 = Abs_f32_m(FiltPinionTrq_HwNm_T_f32);

    if ((FiltAbsltMtrVelCRF_MtrRadpS_T_f32 <= k_PsaAgAn_VehCondMaxMtrVel_MtrRadpS_f32) &&
        (FiltAbsltPinionTrq_HwNm_T_f32 <= k_PsaAgAn_VehCondMaxPinTrq_HwNm_f32) &&
        (FiltAbsltHwTrq_HwNm_T_f32 <= k_PsaAgAn_VehCondMaxHwTrq_HwNm_f32) &&
        (VehicleSpeed_Kph_T_f32 <= k_PsaAgAn_VehCondMaxVehSpd_Kph_f32) &&
        (VehicleSpeedValid_Cnt_T_lgc != D_FALSE_CNT_LGC))
    {
        /* ElapsedTime */
        (void) Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(PsaAgAn_VehCondTimer_mS_M_u32, &ElpdTi_mS_T_u32);
        if (ElpdTi_mS_T_u32 > k_PsaAgAn_VehCondMinTi_mS_u32)
        {
            VehCond_Cnt_T_lgc = D_TRUE_CNT_LGC;
        }
        else
        {
            VehCond_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }
    }
    else
    {
        /* ResetTimer */
        (void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&PsaAgAn_VehCondTimer_mS_M_u32);
        VehCond_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    PsaAgAn_VehCdn_Cnt_D_lgc = VehCond_Cnt_T_lgc;

    return VehCond_Cnt_T_lgc;
}

/**********************************************************************************************************************
 * Name:        SwitchOffs
 * Description: Implements the "Switch Offset" block in FDD
 * Inputs:      VehCond_Cnt_T_lgc
 *              PsaAgAn_SnsrMod_Cnt_M_enum
 * Outputs:     None
 * Usage Notes: Called by PsaAgArbn_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSAAGARBN_APPL_CODE) SwitchOffs(VAR(boolean, AUTOMATIC) VehCond_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) Cond_Cnt_T_lgc;

    PsaAgAn_AgArbnOffsFltDetd_Cnt_D_lgc = PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc;

    if ((PsaAgAn_SnsrMod_Cnt_M_enum != PSAAGAN_MODFAIL) &&
        (PsaAgAn_SnsrMod_Cnt_M_enum != PSAAGAN_MODININ) &&
        ((VehCond_Cnt_T_lgc != D_FALSE_CNT_LGC) ||
         ((PsaAgAn_AbsltHwPosnLvl2_Cnt_M_lgc == D_FALSE_CNT_LGC) &&
          (PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc == D_FALSE_CNT_LGC))))
    {
        Cond_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        Cond_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    if ((Cond_Cnt_T_lgc != D_FALSE_CNT_LGC) &&
        (PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc != D_SRCNONE_CNT_U08))
    {
        /* switchMaxOffset */
        PsaAgAn_UsedOffs_Uls_M_str.MaxOffset = PsaAgAn_ComputedOffs_Uls_M_str.MaxOffset;
        PsaAgAn_UsedOffs_Uls_M_str.MaxSrc = PsaAgAn_ComputedOffs_Uls_M_str.MaxSrc;

        PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc = D_FALSE_CNT_LGC;
    }

    if ((Cond_Cnt_T_lgc != D_FALSE_CNT_LGC) &&
        (PsaAgAn_ComputedOffs_Uls_M_str.MinSrc != D_SRCNONE_CNT_U08))
    {
        /* switchMinOffset */
        PsaAgAn_UsedOffs_Uls_M_str.MinOffset = PsaAgAn_ComputedOffs_Uls_M_str.MinOffset;
        PsaAgAn_UsedOffs_Uls_M_str.MinSrc = PsaAgAn_ComputedOffs_Uls_M_str.MinSrc;

        PsaAgAn_AgArbnOffsFltDetd_Cnt_M_lgc = D_FALSE_CNT_LGC;
    }
}

#define RTE_STOP_SEC_AP_PSAAGARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
