/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_AssistFirewall.c
 *     Workspace:  C:/Synergy_projects/AssistFirewall-lz4p8n/AssistFirewall/autosar/Ap_AssistFirewall.dcf
 *     SW-C Type:  Ap_AssistFirewall
 *  Generated at:  Tue May 14 13:51:19 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_AssistFirewall>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 25 13:00:00 2012
 * %version:          13 %
 * %derived_by:       lz4p8n %
 * %date_modified:    Tue May 14 14:33:46 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev     Author    Change Description                                                                SCR #
 * -------   ------  --------  --------------------------------------------------------------------------------  ------
 * 04/25/12  1       OT        Initial Version                                                                   5299
 * 05/10/12  2       OT        Fixed conflicting calibration names
 * 05/18/12  3       OT        Added fault injection point (anomaly 3327)                                        5475
 * 05/23/12  4       OT        UTP Fix (including port access to fault injection for Per1)                       5475
 * 05/31/12  5       OT        Updated to SF-34 v002                                                             5585
 * 06/08/12  6       OT        Updated to SF-34 v003                                                             5627
 * 06/11/12  7       OT        Fixed error accumulator struct assignment
 * 06/20/12  8       OT        Updated to SF-34 v004                                                             5714
 * 08/01/12  9       NRAR      Updated to SF-34 V005,V006                                                        5902
 * 16/09/12  10      BWL       Added watchdog checkpoints                                                        6212
 * 02/01/13	 12		 VK		   Updates to meet SF-34 v007														 7208
 * 05/14/13  13		 SP		   Updates to meet SF-34 v008														 7818
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_AssistFirewall.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Ap_AssistFirewall_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "interpolation.h"


#define ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWUprBound_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWLwrBound_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWSumInput_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWLowFreqInput_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWLowFreqLimited_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWActiveRaw_Uls_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWUprBoundFilt_MtrNm_D_f32;
STATIC volatile VAR(float32, ASSISTFIREWALL_VAR) AsstFWLwrBoundFilt_MtrNm_D_f32;
STATIC VAR(float32, ASSISTFIREWALL_VAR) CombAsstSV_MtrNm_M_f32;
#define ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16,  ASSISTFIREWALL_VAR) ActiveRawAcc_Cnt_M_u16;
#define ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, ASSISTFIREWALL_VAR) UprBoundKSV_M_str;
STATIC VAR(LPF32KSV_Str, ASSISTFIREWALL_VAR) LwrBoundKSV_M_str;
STATIC VAR(HPF32KSV_Str, ASSISTFIREWALL_VAR) HiFreqKSV_M_str;
STATIC VAR(LPF32KSV_Str, ASSISTFIREWALL_VAR) ActiveKSV_M_str;
#define ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN	
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, ASSISTFIREWALL_VAR) PNCountStatus_Cnt_M_lgc;
STATIC volatile VAR(boolean, ASSISTFIREWALL_VAR) AsstFWOverBound_Cnt_D_lgc;
STATIC VAR(boolean, ASSISTFIREWALL_VAR) AsstReducedPerfSV_Cnt_M_lgc;
#define ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
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
 * Boolean: Boolean (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
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
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
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
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
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
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
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
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ASSISTFIREWALL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistFirewall_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTFIREWALL_APPL_CODE) AssistFirewall_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistFirewall_Init1
 *********************************************************************************************************************/
	
	
	LPF_KUpdate_f32_m(k_AsstFWFiltKn_Hz_f32, D_2MS_SEC_F32, &UprBoundKSV_M_str);
	LPF_KUpdate_f32_m(k_AsstFWFiltKn_Hz_f32, D_2MS_SEC_F32, &LwrBoundKSV_M_str);
	HPF_KUpdate_f32_m(k_AsstFWFiltKn_Hz_f32, D_2MS_SEC_F32, &HiFreqKSV_M_str);
	LPF_KUpdate_f32_m(k_AsstFWFWActiveLPF_Hz_f32, D_2MS_SEC_F32, &ActiveKSV_M_str);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistFirewall_Per1
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
 *   Float Rte_IRead_AssistFirewall_Per1_BaseAssistCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistFirewall_Per1_Defeat_AsstTbl_Service_Cnt_lgc(void)
 *   Float Rte_IRead_AssistFirewall_Per1_HighFreqAssist_MtrNm_f32(void)
 *   Float Rte_IRead_AssistFirewall_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_AssistFirewall_Per1_HysteresisComp_MtrNm_f32(void)
 *   ManufModeType Rte_IRead_AssistFirewall_Per1_MEC_Counter_Cnt_enum(void)
 *   Float Rte_IRead_AssistFirewall_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AssistFirewall_Per1_AsstFirewallActive_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AssistFirewall_Per1_AsstFirewallActive_Uls_f32(void)
 *   void Rte_IWrite_AssistFirewall_Per1_CombinedAssist_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistFirewall_Per1_CombinedAssist_MtrNm_f32(void)
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

FUNC(void, RTE_AP_ASSISTFIREWALL_APPL_CODE) AssistFirewall_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AssistFirewall_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) BaseAssistCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HighFreqAssist_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HysteresisComp_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	
	VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(sint16,  AUTOMATIC) HwTorque_HwNm_T_s4p11;
	VAR(sint16,  AUTOMATIC) UprBound_MtrNm_T_s4p11;
	VAR(float32, AUTOMATIC) UprBound_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) UprBoundFilt_MtrNm_T_f32;
	VAR(sint16,  AUTOMATIC) LwrBound_MtrNm_T_s4p11;
	VAR(float32, AUTOMATIC) LwrBound_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) LwrBoundFilt_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) BaseAssistCmdLtd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HighFreqAssistLtd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HysteresisCompLtd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) SumInput_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) LowFreqInput_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HiFreqInput_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) LowFreqLimited_MtrNm_T_f32;
	VAR(DiagSettings_Str, AUTOMATIC) AsstFWPstepNstep_Cnt_T_str;
	VAR(uint16, AUTOMATIC) AbsHwTrq_HwNm_T_u8p8;
	VAR(sint16, AUTOMATIC) DefltAsstLookup_MtrNm_T_s4p11;
	VAR(float32, AUTOMATIC)	DefltAsst_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	DefltAsstLookup_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	AsstFWActive_Uls_T_f32;
	VAR(float32, AUTOMATIC)	AsstFWActiveRaw_Uls_T_f32;
	VAR(float32, AUTOMATIC)	AsstFWOverBound_Cnt_T_f32;
	
	VAR(boolean, AUTOMATIC) DefeatAsstTblSvc_Cnt_T_lgc;
	VAR(ManufModeType, AUTOMATIC) MECCounter_Cnt_T_enum;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AssistFirewall_Per1_CP0_CheckpointReached();
	
	BaseAssistCmd_MtrNm_T_f32 = Rte_IRead_AssistFirewall_Per1_BaseAssistCmd_MtrNm_f32();
	HighFreqAssist_MtrNm_T_f32 = Rte_IRead_AssistFirewall_Per1_HighFreqAssist_MtrNm_f32();
	HwTorque_HwNm_T_f32 = Rte_IRead_AssistFirewall_Per1_HwTorque_HwNm_f32();
	HysteresisComp_MtrNm_T_f32 = Rte_IRead_AssistFirewall_Per1_HysteresisComp_MtrNm_f32();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_AssistFirewall_Per1_VehicleSpeed_Kph_f32();
	
	DefeatAsstTblSvc_Cnt_T_lgc = Rte_IRead_AssistFirewall_Per1_Defeat_AsstTbl_Service_Cnt_lgc();
	MECCounter_Cnt_T_enum = Rte_IRead_AssistFirewall_Per1_MEC_Counter_Cnt_enum();
	
	AsstFWPstepNstep_Cnt_T_str.PStep = k_AsstFWPstep_Cnt_u16;
	AsstFWPstepNstep_Cnt_T_str.NStep = k_AsstFWNstep_Cnt_u16;
	AsstFWPstepNstep_Cnt_T_str.Threshold = t_AsstFWPstepNstepThresh_Cnt_u16[1];
	
	AbsHwTrq_HwNm_T_u8p8 = FPM_FloatToFixed_m(Abs_f32_m(HwTorque_HwNm_T_f32), u8p8_T);

	
	/* Sum and Filter Inputs */
	
	HysteresisCompLtd_MtrNm_T_f32 = Limit_m(HysteresisComp_MtrNm_T_f32, -k_AsstFWInpLimitHysComp_MtrNm_f32, k_AsstFWInpLimitHysComp_MtrNm_f32);
	HighFreqAssistLtd_MtrNm_T_f32 = Limit_m(HighFreqAssist_MtrNm_T_f32, -k_AsstFWInpLimitHFA_MtrNm_f32, k_AsstFWInpLimitHFA_MtrNm_f32);
	BaseAssistCmdLtd_MtrNm_T_f32 = Limit_m(BaseAssistCmd_MtrNm_T_f32, -k_AsstFWInpLimitBaseAsst_MtrNm_f32, k_AsstFWInpLimitBaseAsst_MtrNm_f32);
	
	SumInput_MtrNm_T_f32 = HysteresisCompLtd_MtrNm_T_f32 + HighFreqAssistLtd_MtrNm_T_f32 + BaseAssistCmdLtd_MtrNm_T_f32;
	
	
	HiFreqInput_MtrNm_T_f32 = HPF_OpUpdate_f32_m(SumInput_MtrNm_T_f32, &HiFreqKSV_M_str);
	
	LowFreqInput_MtrNm_T_f32 = SumInput_MtrNm_T_f32 - HiFreqInput_MtrNm_T_f32;
	
	
	
	/* Determine Saturation Bounds and Limit */
	
	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
	HwTorque_HwNm_T_s4p11 = FPM_FloatToFixed_m(HwTorque_HwNm_T_f32, s4p11_T);
	
	/* Instead of using MEC Counter the enum is being used. enum equals ProductionMode when MEC Counter is 0. */
	if((DefeatAsstTblSvc_Cnt_T_lgc != D_FALSE_CNT_LGC) && (MECCounter_Cnt_T_enum != ProductionMode)) 
	{
		CombAsstSV_MtrNm_M_f32 = SumInput_MtrNm_T_f32;
		AsstFWActive_Uls_T_f32 = 0.0F;
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWFltMode, 0x01U, NTC_STATUS_PASSED);
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWReached, 0x01U, NTC_STATUS_PASSED);
	}
	else
	{
		UprBound_MtrNm_T_s4p11 = BilinearXMYM_s16_s16XMs16YM_Cnt(	VehicleSpeed_Kph_T_u9p7,
																	HwTorque_HwNm_T_s4p11,
																	t_AsstFWVehSpd_Kph_u9p7,
																	TableSize_m(t_AsstFWVehSpd_Kph_u9p7),
																	t2_AsstFWUprBoundX_HwNm_s4p11[0],
																	t2_AsstFWUprBoundY_MtrNm_s4p11[0],
																	TableSize_m(t2_AsstFWUprBoundX_HwNm_s4p11[0]));
		
		UprBound_MtrNm_T_f32 = FPM_FixedToFloat_m(UprBound_MtrNm_T_s4p11, s4p11_T);
		
		UprBoundFilt_MtrNm_T_f32 = LPF_OpUpdate_f32_m(UprBound_MtrNm_T_f32, &UprBoundKSV_M_str);
		
		
		LwrBound_MtrNm_T_s4p11 = BilinearXMYM_s16_s16XMs16YM_Cnt(	VehicleSpeed_Kph_T_u9p7,
																	(D_NEGONE_CNT_S16 * HwTorque_HwNm_T_s4p11),
																	t_AsstFWVehSpd_Kph_u9p7,
																	TableSize_m(t_AsstFWVehSpd_Kph_u9p7),
																	t2_AsstFWUprBoundX_HwNm_s4p11[0],
																	t2_AsstFWUprBoundY_MtrNm_s4p11[0],
																	TableSize_m(t2_AsstFWUprBoundX_HwNm_s4p11[0]));
		
		LwrBound_MtrNm_T_f32 = FPM_FixedToFloat_m((D_NEGONE_CNT_S16 * LwrBound_MtrNm_T_s4p11), s4p11_T);
		
		LwrBoundFilt_MtrNm_T_f32 = LPF_OpUpdate_f32_m(LwrBound_MtrNm_T_f32, &LwrBoundKSV_M_str);
		
		LowFreqLimited_MtrNm_T_f32 = Limit_m(LowFreqInput_MtrNm_T_f32, LwrBoundFilt_MtrNm_T_f32, UprBoundFilt_MtrNm_T_f32);
		
		/*** Ver 005 change to calculate DefaultAssist ***/
		DefltAsstLookup_MtrNm_T_s4p11 = IntplVarXY_s16_u16Xs16Y_Cnt( t_AsstFWDefltAssistX_HwNm_u8p8,
																	  t_AsstFWDefltAssistY_MtrNm_s4p11,
																	  TableSize_m(t_AsstFWDefltAssistX_HwNm_u8p8),
																	  AbsHwTrq_HwNm_T_u8p8);
		DefltAsstLookup_MtrNm_T_f32 = FPM_FixedToFloat_m(DefltAsstLookup_MtrNm_T_s4p11, s4p11_T);

		DefltAsst_MtrNm_T_f32 = DefltAsstLookup_MtrNm_T_f32 * ((float32)Sign_f32_m(HwTorque_HwNm_T_f32));

		/****/
		/* Determine Activity and Output */
		
		if( (LowFreqInput_MtrNm_T_f32 < LwrBoundFilt_MtrNm_T_f32) ||
			(LowFreqInput_MtrNm_T_f32 > UprBoundFilt_MtrNm_T_f32) )
		{
			AsstFWOverBound_Cnt_T_f32 = D_ONE_ULS_F32;
			AsstFWOverBound_Cnt_D_lgc = TRUE;
			ActiveRawAcc_Cnt_M_u16 = DiagPStep_m(ActiveRawAcc_Cnt_M_u16, AsstFWPstepNstep_Cnt_T_str);
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWReached, 0x01U, NTC_STATUS_FAILED);

		}
		else
		{
			AsstFWOverBound_Cnt_T_f32 = D_ZERO_ULS_F32;
			AsstFWOverBound_Cnt_D_lgc = FALSE;
			ActiveRawAcc_Cnt_M_u16 = DiagNStep_m(ActiveRawAcc_Cnt_M_u16, AsstFWPstepNstep_Cnt_T_str);
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWReached, 0x01U, NTC_STATUS_PASSED);

		}
		
		if( ActiveRawAcc_Cnt_M_u16 >= t_AsstFWPstepNstepThresh_Cnt_u16[1] )
		{
			PNCountStatus_Cnt_M_lgc = TRUE;
		}
		else if( ActiveRawAcc_Cnt_M_u16 > t_AsstFWPstepNstepThresh_Cnt_u16[0] )
		{
			/* do nothing */
		}
		else
		{
			PNCountStatus_Cnt_M_lgc = FALSE;
		}
		
		if(((Abs_f32_m(SumInput_MtrNm_T_f32 - CombAsstSV_MtrNm_M_f32) > k_RestoreThresh_MtrNm_f32) && (AsstReducedPerfSV_Cnt_M_lgc == TRUE)) || (TRUE == PNCountStatus_Cnt_M_lgc))
		{
			CombAsstSV_MtrNm_M_f32 = DefltAsst_MtrNm_T_f32;
			AsstFWActiveRaw_Uls_T_f32 = D_ZERO_ULS_F32;
			AsstReducedPerfSV_Cnt_M_lgc = TRUE;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWFltMode, 0x01U, NTC_STATUS_FAILED);

		}
		else
		{
			CombAsstSV_MtrNm_M_f32 = HiFreqInput_MtrNm_T_f32 + LowFreqLimited_MtrNm_T_f32;
			AsstFWActiveRaw_Uls_T_f32 = AsstFWOverBound_Cnt_T_f32;
			AsstReducedPerfSV_Cnt_M_lgc = FALSE;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AssistFWFltMode, 0x01U, NTC_STATUS_PASSED);

		}
		
		CombAsstSV_MtrNm_M_f32 = Limit_m(CombAsstSV_MtrNm_M_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
		AsstFWActive_Uls_T_f32 = LPF_OpUpdate_f32_m(AsstFWActiveRaw_Uls_T_f32, &ActiveKSV_M_str);


		AsstFWUprBound_MtrNm_D_f32 = UprBound_MtrNm_T_f32;
		AsstFWLwrBound_MtrNm_D_f32 = LwrBound_MtrNm_T_f32;
		AsstFWUprBoundFilt_MtrNm_D_f32 = UprBoundFilt_MtrNm_T_f32;
		AsstFWLwrBoundFilt_MtrNm_D_f32 = LwrBoundFilt_MtrNm_T_f32;
		AsstFWSumInput_MtrNm_D_f32 = SumInput_MtrNm_T_f32;
		AsstFWLowFreqInput_MtrNm_D_f32 = LowFreqInput_MtrNm_T_f32;
		AsstFWLowFreqLimited_MtrNm_D_f32 = LowFreqLimited_MtrNm_T_f32;
		AsstFWActiveRaw_Uls_D_f32 = AsstFWActiveRaw_Uls_T_f32;
	}
	Rte_IWrite_AssistFirewall_Per1_CombinedAssist_MtrNm_f32(CombAsstSV_MtrNm_M_f32);
	Rte_IWrite_AssistFirewall_Per1_AsstFirewallActive_Uls_f32(AsstFWActive_Uls_T_f32);
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AssistFirewall_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ASSISTFIREWALL_APPL_CODE
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
