/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DiagSvc.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_DiagSvc
 *  Generated at:  Sun Dec  3 14:13:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DiagSvc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          5 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#7
 * 07/28/16    2       WH       Updated for new hwtrq modules and hwtrq validity determination					EA3#9275
 * 11/11/16    3       WH       Updated for DSR 1b changes														EA3#12452
 * 14/03/17    4       AR       Updated for CMP DSR version 002A                                                EA3#14457
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_DiagSvc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "DiagSvc.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "CalConstants.h"
#define DIAGMGR_C
#include "DiagMgr_Cfg.h"

#define HierByte(x)	((uint8)(((x) >> 16) & 0xFFu)) /* PRQA S 3453 */
#define HiByte(x)	((uint8)(((x) >> 8) & 0xFFu)) /* PRQA S 3453 */
#define LoByte(x)	((uint8)((x) & 0xFFu)) /* PRQA S 3453 */

#define ApplyRounding_f32(x)	( ((x) < 0.0f) ? ((x) - 0.5f) : ((x) + 0.5f) ) /* PRQA S 3453 */

#define D_STATEDISABLE_CNT_U08      0u
#define D_STATEOFF_CNT_U08          1u
#define D_STATEOPERATE_CNT_U08      2u    
#define D_STATEWARMINIT_CNT_U08     3u
#define D_STATETRANS_CNT_U08        4u

#define MaxMileageVal  16777215u
#define MinMileageVal  0u


CONST(PowerPackConfigType_Str, DIAGSVC_CONST) D_POWERPACKCONFIGINIT_CNT_STR = { 0xFFu,
																		  0xFFu,
																		  0xFFu};

CONST(TuningSelectType_Str, DIAGSVC_CONST) D_TUNINGSELECTINIT_CNT_STR = { 0x03u,
																		  0x00u,
																		  0x01u,
                                                                          0x01u,
                                                                          0x01u,
																		  0xFDu,
																		  0xFFFFu,
																		  0xFFFFFFFFu,
																		  0xFFFFu,
																		  0xFFFFFFFFu,
																		  0u };

CONST(AuthenticationZoneType_Str, DIAGSVC_CONST) D_AUTHENTICATIONZONEINIT_CNT_STR = { {0x98u, 0xFFu, 0xFFu, 0xFFu, 0x80u},
																					  {0x98u, 0xFFu, 0xFFu, 0xFFu, 0x80u},
																					  0x00u };

CONST(EMCStandardizationLabelType_Str, DIAGSVC_CONST) D_STDLABELINIT_CNT_STR = { {0x44u, 0x41u, 0x45u, 0x20u, 0x20u},
																				 {0x20u, 0x20u, 0x20u, 0x20u,
																				  0x20u, 0x20u, 0x20u, 0x20u,
																				  0x20u, 0x20u, 0x20u, 0x20u,
																				  0x20u, 0x20u, 0x20u, 0x20u},
																				 0x00u };

CONST(uint8, DIAGSVC_CONST) D_SECURITYKEYINIT_CNT_U08[3u] = { 0xFFu, 0xFFu, 0u };

CONST(uint8, DIAGSVC_CONST) D_CUSTECUINIT_CNT_U08[13u] = { 0x36u, 0x30u, 0x54u, 0x59u, 0x42u,
														   0x47u, 0x30u, 0x37u, 0x37u, 0x37u,
														   0x38u, 0x36u, 0x38u };


#define DIAGSVC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(TuningSelectType_Str, DIAGSVC_VAR) TuningSelect_G_str;
VAR(PowerPackConfigType_Str, DIAGSVC_VAR) PowerPackConfig_G_str;
VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogA_G_str;
VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogB_G_str;
VAR(AuthenticationZoneType_Str, DIAGSVC_VAR) AuthenticationZone_G_str;
VAR(ECUManufacturingDateType_Str, DIAGSVC_VAR) ECUManufacturingDate_G_str;
VAR(EMCStandardizationLabelType_Str, DIAGSVC_VAR) EMCStandardizationLabel_G_str;
#define DIAGSVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define DIAGSVC_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, DIAGSVC_VAR) Deprecated_PowerLatchFlag_Cnt_G_lgc;
#define DIAGSVC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


#define DIAGSVC_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint8, DIAGSVC_VAR) Deprecated_SecurityKey_Cnt_G_u08[10u];
VAR(uint8, DIAGSVC_VAR) SecurityKey_Cnt_G_u08[3u];
VAR(uint8, DIAGSVC_VAR) SecurityViolation_Cnt_G_u08;
VAR(uint8, DIAGSVC_VAR) CustECUSrlNum_Cnt_G_u08[13u];
#define DIAGSVC_STOP_SEC_VAR_CLEARED_8
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
 * ANGLE_COLONNE: Integer in interval [-16300...16300]
 * Boolean: Boolean (standard type)
 * CAUSE_DESACTIV_CPK: Integer in interval [0...7]
 * CHKSUM_TRME_DYN_DAE: Integer in interval [0...15]
 * CODE_DEFAUT: Integer in interval [0...255]
 * CPLE_VOLANT_OPTMSE: Integer in interval [-100...100]
 * CPT_PROCESS_4B_DAE: Integer in interval [0...15]
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * ETAT_ASSIST_DA: Integer in interval [0...7]
 * ETAT_DAE_CAV3_VIRTUEL: Integer in interval [0...7]
 * ETAT_DAE_CPK: Integer in interval [0...3]
 * ETAT_LIGNE_APC: Boolean
 * ETAT_SECU_ANGLE_COL: Boolean
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * STATUS_CONFABSENT: Integer in interval [0...4294967295]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 * VITESSE_COLONNE: Integer in interval [-2000...2000]
 *
 * Enumeration Types:
 * ==================
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DEM_INDICATOR_OFF (0U)
 *   DEM_INDICATOR_CONTINUOUS (1U)
 *   DEM_INDICATOR_BLINKING (2U)
 *   DEM_INDICATOR_BLINK_CONT (3U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_PLLSlipNrcvrl (22U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90U)
 *   NTC_Num_SysVltgCorrlnFlt (91U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_EcuIdnFlt (95U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_IMCLossOfCom (125U)
 *   NTC_Num_ImcArbrFault (127U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_TurnCntr_SpiDataFlt (135U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_EcuCrossChk (150U)
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151U)
 *   NTC_Num_EcuConfigMismatch (152U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
 *   NTC_Num_AgCompDiagc (167U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_DataOtherFlt2Msg_Q (327U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AM (482U)
 *   NTC_Num_InvalidMsg_AM (483U)
 *   NTC_Num_CRCFltMsg_AM (484U)
 *   NTC_Num_PgrsCntFltMsg_AM (485U)
 *   NTC_Num_DataRngFltMsg_AM (486U)
 *   NTC_Num_InvalidMsg_AL (488U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_DataRngFltMsg_AL (492U)
 *   NTC_Num_DataOtherFltMsg_AL (494U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_PHAScratchPadTrf (503U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 *
 * Array Types:
 * ============
 * Dem_MaxDataValueType: Array with 3 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * IS_DYN_DAE_Msg: Record with elements
 *   CptProcess4bDae of type CPT_PROCESS_4B_DAE
 *   ChksumTrmeDynDae of type CHKSUM_TRME_DYN_DAE
 *   CpleVolantOptimse of type CPLE_VOLANT_OPTMSE
 *   CauseDesactivCpk of type CAUSE_DESACTIV_CPK
 *   EtatDaeCpk of type ETAT_DAE_CPK
 *   AngleColonne of type ANGLE_COLONNE
 *   EtatSecuAngleCol of type ETAT_SECU_ANGLE_COL
 *   EtatDaeCav3Virtuel of type ETAT_DAE_CAV3_VIRTUEL
 *   VitesseColonne of type VITESSE_COLONNE
 * IS_SUPV_DIRA_Msg: Record with elements
 *   CodeDefaut of type CODE_DEFAUT
 *   StatusConfabsent of type STATUS_CONFABSENT
 *   EtatAssistDa of type ETAT_ASSIST_DA
 *   EtatLigneApc of type ETAT_LIGNE_APC
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
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_CCWEOTINIT_HWDEG_F32 = -360.0F
 * Float: D_CWEOTINIT_HWDEG_F32 = 360.0F
 * Float: D_ESTKE_VPRADPS_F32 = 0.025F
 * Float: D_HALF_ULS_F32 = 0.5F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400.0F
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_SUPPLYCURRINIT_AMP_F32 = 166.67F
 * Float: D_TRQOSCFREQINIT_F32 = 50.0F
 * Float: D_TRQOSCFREQINIT_HZ_F32 = 50.0F
 * Float: D_TRQOVLFREQINIT_HZ_F32 = 3.0F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_VEHWHLBASEINIT_MM_F32 = 3000.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_CMPVEHLATAINIT_CNT_U16 = 1022U
 * UInt16: D_FIFTEEN_CNT_U16 = 15U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_SEVEN_CNT_U16 = 7U
 * UInt16: D_THREE_CNT_U16 = 3U
 * UInt16: D_TWOPTFIVE_VOLT_U3P13 = 20480U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_BATTVLTGCORRLNSTSINIT_CNT_U08 = 7U
 * UInt8: D_FOUR_CNT_U08 = 4U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_SEVEN_CNT_U08 = 7U
 * UInt8: D_THREE_CNT_U08 = 3U
 * UInt8: D_TWO_CNT_U08 = 2U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd401_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd401>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Mileage_Cnt_u32(UInt32 *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd401_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd401_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd401_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	

	VAR(uint32, AUTOMATIC) Mileage_Cnt_T_u32;
	
	(void)Rte_Read_Mileage_Cnt_u32(&Mileage_Cnt_T_u32);
	
    Mileage_Cnt_T_u32 = Limit_m(Mileage_Cnt_T_u32, MinMileageVal, MaxMileageVal);
	(*Data)[0u] = HierByte(Mileage_Cnt_T_u32); /* PRQA S 2985 */
	(*Data)[1u] = HiByte(Mileage_Cnt_T_u32);
    (*Data)[2u] = LoByte(Mileage_Cnt_T_u32);
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd403_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd403>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComVehSpd_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehicleSpeedValid_Cnt_lgc(Boolean *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd403_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd403_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd403_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) SrlComVehSpd_Kph_T_f32;
	VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Cnt_T_f32;
	VAR(uint16, AUTOMATIC) VehicleSpeed_Cnt_T_u16;
	
	(void)Rte_Read_SrlComVehSpd_Kph_f32(&SrlComVehSpd_Kph_T_f32);
	(void)Rte_Read_VehicleSpeedValid_Cnt_lgc(&VehicleSpeedValid_Cnt_T_lgc);
	
	if( VehicleSpeedValid_Cnt_T_lgc == FALSE )
	{
		VehicleSpeed_Cnt_T_u16 = 0xFFFFu;
	}
	else
	{
		VehicleSpeed_Cnt_T_f32 = SrlComVehSpd_Kph_T_f32 / 0.01f;
		VehicleSpeed_Cnt_T_f32 = ApplyRounding_f32(VehicleSpeed_Cnt_T_f32);
		VehicleSpeed_Cnt_T_u16 = (uint16)VehicleSpeed_Cnt_T_f32;
	}
	
	(*Data)[0u] = HiByte(VehicleSpeed_Cnt_T_u16); /* PRQA S 2985 */
	(*Data)[1u] = LoByte(VehicleSpeed_Cnt_T_u16);
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd404_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd404>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BatteryVoltage_Volt_f32(Float *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd404_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd404_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd404_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) BatteryVoltage_Volt_T_f32;
	VAR(float32, AUTOMATIC) BatteryVoltage_Cnt_T_f32;
	VAR(uint8, AUTOMATIC) BatteryVoltage_Cnt_T_u08;
	
	(void)Rte_Read_BatteryVoltage_Volt_f32(&BatteryVoltage_Volt_T_f32);
	
	BatteryVoltage_Volt_T_f32 = Limit_m(BatteryVoltage_Volt_T_f32, 0.0f, 28.0f);
	BatteryVoltage_Cnt_T_f32 = BatteryVoltage_Volt_T_f32 / 0.125f;
	BatteryVoltage_Cnt_T_f32 = ApplyRounding_f32(BatteryVoltage_Cnt_T_f32);
	BatteryVoltage_Cnt_T_u08 = (uint8)BatteryVoltage_Cnt_T_f32;
	
	(*Data)[0u] = BatteryVoltage_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd405_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd405>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ECUTemperature_DegC_f32(Float *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd405_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd405_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd405_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) ECUTemperature_DegC_T_f32;
	VAR(boolean, AUTOMATIC) Thermister_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) ECUTemperature_Cnt_T_f32;
	VAR(uint8, AUTOMATIC) ECUTemperature_Cnt_T_u08;
	
	(void)Rte_Read_ECUTemperature_DegC_f32(&ECUTemperature_DegC_T_f32);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Thermistor, &Thermister_Cnt_T_lgc);
	
	if( Thermister_Cnt_T_lgc == TRUE )
	{
		ECUTemperature_Cnt_T_u08 = 0xFFu;
	}
	else
	{
		ECUTemperature_DegC_T_f32 = Limit_m(ECUTemperature_DegC_T_f32, -40.0f, 214.0f);
		ECUTemperature_Cnt_T_f32 = ECUTemperature_DegC_T_f32 + 40.0f;
		ECUTemperature_Cnt_T_f32 = ApplyRounding_f32(ECUTemperature_Cnt_T_f32);
		ECUTemperature_Cnt_T_u08 = (uint8)ECUTemperature_Cnt_T_f32;
	}
	
	(*Data)[0u] = ECUTemperature_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd407_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd407>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EngineState_Cnt_u08(UInt8 *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd407_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd407_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd407_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(uint8, AUTOMATIC) EngineState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) InvalidMsgN_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgN_Cnt_T_lgc;
	
	(void)Rte_Read_EngineState_Cnt_u08(&EngineState_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_N, &InvalidMsgN_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_N, &MissingMsgN_Cnt_T_lgc);
	
	if( (InvalidMsgN_Cnt_T_lgc == TRUE) ||
		(MissingMsgN_Cnt_T_lgc == TRUE) )
	{
		EngineState_Cnt_T_u08 = 0x0Fu;
	}
	
	(*Data)[0u] = EngineState_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd408_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd408>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd408_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd408_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd408_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) IgnitionOnOff_Cnt_T_u08;
	
	(void)Rte_Call_EpsEn_OP_GET(&EpsEn_Cnt_T_lgc);
	
	if( EpsEn_Cnt_T_lgc == TRUE )
	{
		IgnitionOnOff_Cnt_T_u08 = 1u;
	}
	else
	{
		IgnitionOnOff_Cnt_T_u08 = 0u;
	}
	
	(*Data)[0u] = IgnitionOnOff_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd409_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd409>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd409_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd409_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd409_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(IS_SUPV_DIRA_Msg, AUTOMATIC) IsSupvDira_T_Str;

	(void)Rte_Call_IS_SUPV_DIRA_Get(&IsSupvDira_T_Str);
	
	(*Data)[0u] = IsSupvDira_T_Str.EtatAssistDa;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40b_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40b>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40b_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd40b_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd40b_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(boolean, AUTOMATIC) NTCActive_Cnt_T_lgc;
	VAR(uint16,  AUTOMATIC) NTCNumber_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) AppIdx_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) InfoIdx_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) NTCParam_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) i;
	
	NTCActive_Cnt_T_lgc = FALSE;
	
	for( i = 1u; (i < TableSize_m(k_FltRspTbl_Cnt_str)) && (NTCActive_Cnt_T_lgc == FALSE); i++ )
	{
		if( CDD_DemIdSnapshot_Cnt_G_u08 == k_FltRspTbl_Cnt_str[i].DEMEventID )
		{
			(void)Rte_Call_NxtrDiagMgr_GetNTCActive(i, &NTCActive_Cnt_T_lgc);
			
			if( NTCActive_Cnt_T_lgc == TRUE )
			{
				NTCNumber_Cnt_T_u16 = i;
			}
		}
	}
	
	
	if( NTCActive_Cnt_T_lgc == TRUE )
	{
		AppIdx_Cnt_T_u08 = T_DiagMgrNtcAppInfoMap_Cnt_Str[NTCNumber_Cnt_T_u16].AppIdx;
		
		if( AppIdx_Cnt_T_u08 < DIAGMGR_NUMAPPS )
		{
			InfoIdx_Cnt_T_u08 = T_DiagMgrNtcAppInfoMap_Cnt_Str[NTCNumber_Cnt_T_u16].InfoIdx;
			NTCParam_Cnt_T_u08 = T_DiagMgrNtcInfoPtr_Cnt_Str[AppIdx_Cnt_T_u08].NTCInfoPtr[InfoIdx_Cnt_T_u08].Param; /* PRQA S 491 */
		}
		else
		{
			NTCParam_Cnt_T_u08 = 0u;
		}
	}
	else
	{
		NTCNumber_Cnt_T_u16 = 0u;
		NTCParam_Cnt_T_u08 = 0u;
	}
	
	(*Data)[0u] = HiByte(NTCNumber_Cnt_T_u16); /* PRQA S 2985 */
	(*Data)[1u] = LoByte(NTCNumber_Cnt_T_u16);
	(*Data)[2u] = NTCParam_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40c_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40c>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40c_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd40c_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd40c_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
    VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
    SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();

    switch(SystemState_Cnt_T_enum)
    {
        case RTE_MODE_StaMd_Mode_DISABLE:
           (*Data)[0u] = D_STATEDISABLE_CNT_U08;
            break;
        
        case RTE_MODE_StaMd_Mode_OFF:
            (*Data)[0u] = D_STATEOFF_CNT_U08;
            break;
            
        case RTE_MODE_StaMd_Mode_OPERATE:
            (*Data)[0u] = D_STATEOPERATE_CNT_U08;
            break;
            
        case RTE_MODE_StaMd_Mode_WARMINIT:
           (*Data)[0u] = D_STATEWARMINIT_CNT_U08;
            break;            

        default:
            (*Data)[0u] = D_STATEDISABLE_CNT_U08;
            break;
    }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40d_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40d>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelAngle_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_HandwheelAuthority_Uls_f32(Float *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40d_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd40d_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd40d_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) HandwheelAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelAngle_Cnt_T_f32;
	VAR(uint16, AUTOMATIC) HandwheelAngle_Cnt_T_u16;
	
	(void)Rte_Read_HandwheelAngle_HwDeg_f32(&HandwheelAngle_HwDeg_T_f32);
	(void)Rte_Read_HandwheelAuthority_Uls_f32(&HandwheelAuthority_Uls_T_f32);
	
	if( HandwheelAuthority_Uls_T_f32 < 1.0f )
	{
		HandwheelAngle_Cnt_T_u16 = 0x7FFFu;
	}
	else
	{
		HandwheelAngle_HwDeg_T_f32 = Limit_m(-HandwheelAngle_HwDeg_T_f32, -1630.0f, 1630.0f);
		HandwheelAngle_Cnt_T_f32 = HandwheelAngle_HwDeg_T_f32 / 0.1f;
		HandwheelAngle_Cnt_T_f32 = ApplyRounding_f32(HandwheelAngle_Cnt_T_f32);
		HandwheelAngle_Cnt_T_u16 = (uint16)((sint16)HandwheelAngle_Cnt_T_f32);
	}
	
	(*Data)[0u] = HiByte(HandwheelAngle_Cnt_T_u16); /* PRQA S 2985 */
	(*Data)[1u] = LoByte(HandwheelAngle_Cnt_T_u16);
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40f_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40f>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelTorque_HwNm_f32(Float *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40f_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd40f_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd40f_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) HandwheelTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HandwheelTorque_Cnt_T_f32;
	VAR(uint8, AUTOMATIC) HandwheelTorque_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) T1vsT2_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T1OutofRange_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T2OutofRange_Cnt_T_lgc;
	
	(void)Rte_Read_HandwheelTorque_HwNm_f32(&HandwheelTorque_HwNm_T_f32);
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1vsT2, &T1vsT2_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1OutofRange, &T1OutofRange_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T2OutofRange, &T2OutofRange_Cnt_T_lgc);

	if( (T2OutofRange_Cnt_T_lgc == TRUE) || (T1OutofRange_Cnt_T_lgc == TRUE) ||
		(T1vsT2_Cnt_T_lgc == TRUE) )
	{
		HandwheelTorque_Cnt_T_u08 = 0x7Fu;
	}
	else
	{
		HandwheelTorque_HwNm_T_f32 = Limit_m(-HandwheelTorque_HwNm_T_f32, -10.0f, 10.0f);
		HandwheelTorque_Cnt_T_f32 = HandwheelTorque_HwNm_T_f32 / 0.1f;
		HandwheelTorque_Cnt_T_f32 = ApplyRounding_f32(HandwheelTorque_Cnt_T_f32);
		HandwheelTorque_Cnt_T_u08 = (uint8)((sint8)HandwheelTorque_Cnt_T_f32);
	}
	
	(*Data)[0u] = HandwheelTorque_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd410_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd410>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FinalTorqueCommand_MtrNm_f32(Float *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd410_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd410_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd410_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) FinalTorqueCommand_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) FinalTorqueCommand_Cnt_T_f32;
	VAR(uint8, AUTOMATIC) FinalTorqueCommand_Cnt_T_u08;
	
	(void)Rte_Read_FinalTorqueCommand_MtrNm_f32(&FinalTorqueCommand_MtrNm_T_f32);
	
	FinalTorqueCommand_MtrNm_T_f32 = Limit_m(FinalTorqueCommand_MtrNm_T_f32, -5.0f, 5.0f);
	FinalTorqueCommand_Cnt_T_f32 = FinalTorqueCommand_MtrNm_T_f32 / 0.1f;
	FinalTorqueCommand_Cnt_T_f32 = ApplyRounding_f32(FinalTorqueCommand_Cnt_T_f32);
	FinalTorqueCommand_Cnt_T_u08 = (uint8)((sint8)FinalTorqueCommand_Cnt_T_f32);
	
	(*Data)[0u] = FinalTorqueCommand_Cnt_T_u08;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd412_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd412>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd412_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd412_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd412_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) DutyCycleExceeded_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) AbsTempThermLimit_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) DeratingFlag_Cnt_T_u08;
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DutyCycleExceeded, &DutyCycleExceeded_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AbsTempThermLimit, &AbsTempThermLimit_Cnt_T_lgc);
	
	if( (DutyCycleExceeded_Cnt_T_lgc == TRUE) ||
		(AbsTempThermLimit_Cnt_T_lgc == TRUE) )
	{
		DeratingFlag_Cnt_T_u08 = 1u;
	}
	else
	{
		DeratingFlag_Cnt_T_u08 = 0u;
	}
	
	(*Data)[0u] = DeratingFlag_Cnt_T_u08;
	
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd414_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd414>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd414_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd414_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd414_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/
	
	VAR(IS_DYN_DAE_Msg, AUTOMATIC) IsDynDae_T_Str;
	
	(void)Rte_Call_IS_DYN_DAE_Get(&IsDynDae_T_Str);
	
	(*Data)[0u] = IsDynDae_T_Str.CauseDesactivCpk;
	
	return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd415_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd415>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd415_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd415_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd415_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/

	VAR(IS_DYN_DAE_Msg, AUTOMATIC) IsDynDae_T_Str;
	
	(void)Rte_Call_IS_DYN_DAE_Get(&IsDynDae_T_Str);
	
	(*Data)[0u] = IsDynDae_T_Str.EtatDaeCpk;
	
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd418_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd418>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelVelocity_HwRadpS_f32(Float *data)
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd418_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd418_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd418_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(uint16, AUTOMATIC) HandwheelVelocity_Cnt_T_u16;
	
	(void)Rte_Read_HandwheelVelocity_HwRadpS_f32(&HandwheelVelocity_HwRadpS_T_f32);
	
	HandwheelVelocity_HwRadpS_T_f32 = Limit_m(HandwheelVelocity_HwRadpS_T_f32, -2000.0f, 2000.0f);
	HandwheelVelocity_HwRadpS_T_f32 = ApplyRounding_f32(HandwheelVelocity_HwRadpS_T_f32);
	HandwheelVelocity_Cnt_T_u16 = (uint16)((sint16)HandwheelVelocity_HwRadpS_T_f32);
	
	(*Data)[0u] = HiByte(HandwheelVelocity_Cnt_T_u16); /* PRQA S 2985 */
	(*Data)[1u] = LoByte(HandwheelVelocity_Cnt_T_u16);
	
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd41b_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd41b>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd41b_GetDataValueByDataIdentifier(UInt8 *Data)
#else
 *   Std_ReturnType CBValByDID_0xd41b_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
#endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBValByDID_0xd41b_GetDataValueByDataIdentifier (returns application error)
 *********************************************************************************************************************/

  /*TODO: Update once CF013A is in. This signal does not exist at this point.*/
  (*Data)[0u] = 0xFFu;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagSvc_DummyFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
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

FUNC(void, RTE_AP_DIAGSVC_APPL_CODE) DiagSvc_DummyFunction(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagSvc_DummyFunction
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


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
