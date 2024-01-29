/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Cd_SrlComDriver.c
 *     Workspace:  C:/Component/PSA_CMP_Synergy/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Cd_SrlComDriver
 *  Generated at:  Fri Apr 21 13:01:57 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Cd_SrlComDriver>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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

#include "Rte_Cd_SrlComDriver.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 * PsaAgArbnSt_Enum: Enumeration of integer in interval [0...7] with enumerators
 *   PSAAGARBNST_STININ (0U)
 *   PSAAGARBNST_STPND (1U)
 *   PSAAGARBNST_STNOSYNCN (2U)
 *   PSAAGARBNST_STESCSYNCN (3U)
 *   PSAAGARBNST_STDIAGSYNCN (4U)
 *   PSAAGARBNST_STALTVSYNCN (5U)
 *   PSAAGARBNST_UNUSED (6U)
 *   PSAAGARBNST_STFAIL (7U)
 *
 * Array Types:
 * ============
 * CanMsgType: Array with 8 element(s) of type UInt8
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
 * PsaAgArbnSt_Enum: D_PSAAGARBNSTINIT_CNT_ENUM = 0U
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


#define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Init1
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_Init1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_SrlComDriver_Per1_ANGLECOLONNE_Cnt_u16(void)
 *   UInt16 Rte_IRead_SrlComDriver_Per1_ANGLEVOLANT_Cnt_u16(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_AUTORARRETMOTDA_Cnt_u08(void)
 *   PsaAgArbnSt_Enum Rte_IRead_SrlComDriver_Per1_AgArbnStToSerlCom_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_CALIBRATIONVOL_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CAUSEDESACTIVCPK_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_CAVHCSelected_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CODEDEFAUT_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CPLEVOLANTOPTMSE_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CPLEVOLANT_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_DDEREDEMDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_EPSStateLKA_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATASSISTDA_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_ETATCAPTVOL_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDA2004_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDA2010_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDADYN_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDAECPK_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATLIGNEAPC_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATSECUANGLECOL_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_FLGAVOLICN_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_FLGINITAVOL_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_SENSROTVOL_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComDriver_Per1_STATUSCONFABSENT_Cnt_u32(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_STTdSelected_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_SteerWhlHoldByDrv_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc(void)
 *   UInt16 Rte_IRead_SrlComDriver_Per1_VITESSECOLONNE_Cnt_u16(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_VITESSEROTVOL_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComDriver_Per1_AccelLat_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_AccelLat_Cnt_u16(void)
 *   void Rte_IWrite_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(void)
 *   void Rte_IWrite_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ConfigVhl_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ConfigVhl_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ESPDeconnecte_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ESPDeconnecte_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatMT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatMT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATABR50DMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATABR50DMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATABR50DMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI572MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI572MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI572MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2FRE3CDMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2FRE3CDMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(const UInt8 *data)
#else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(const CanMsgType *data)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(void)
#endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(const UInt8 *data)
#else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(const CanMsgType *data)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(void)
#endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCDS34DMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCDS34DMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(const UInt8 *data)
#else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(const CanMsgType *data)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(void)
#endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_JourEcoule_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_JourEcoule_Cnt_u16(void)
 *   void Rte_IWrite_SrlComDriver_Per1_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_Kilometrage_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LKAState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LKAState_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LXAActivation_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LXAActivation_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ModeDiag_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ModeDiag_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const UInt8 *data)
#else
 *   void Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const CanMsgType *data)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(void)
#endif
 *   void Rte_IWrite_SrlComDriver_Per1_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_RegulABR_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_RegulABR_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_RegulESP_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_RegulESP_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ReqLampeDefEsp_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ReqLampeDefEsp_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ReqModeDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ReqModeDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ShuntPosition_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_Per1
 *********************************************************************************************************************/

#ifdef RTE_INIT_IMPLICIT_BUFFERS
  Rte_IWrite_SrlComDriver_Per1_AccelLat_Cnt_u16(Rte_InitValue_AccelLat_Cnt_u16);
  Rte_IWrite_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(Rte_InitValue_AnneeEcoule_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Rte_InitValue_BusOff_Cnt_lgc);
  Rte_IWrite_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(Rte_InitValue_ColumnAngleSetpoint_Cnt_u16);
  Rte_IWrite_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(Rte_InitValue_CompteurTemporelVehicule_Cnt_u32);
  Rte_IWrite_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(Rte_InitValue_ComputerRazGCT_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ConfigVhl_Cnt_u08(Rte_InitValue_ConfigVhl_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(Rte_InitValue_DiagIntegraElec_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(Rte_InitValue_DiagMuxOn_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(Rte_InitValue_DmdDelestDA_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ESPDeconnecte_Cnt_u08(Rte_InitValue_ESPDeconnecte_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(Rte_InitValue_EffacDefaultDiag_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_EtatMT_Cnt_u08(Rte_InitValue_EtatMT_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(Rte_InitValue_EtatPrincipSev_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(Rte_InitValue_EtatReseauElec_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATABR50DMsgDLCError_Cnt_u08(Rte_InitValue_ISDATABR50DMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDATABR50DMsgRxTime_MSec_u32(Rte_InitValue_ISDATABR50DMsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI572MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI572MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDATBSI572MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI572MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc);
  Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYN2FRE3CDMsgDLCError_Cnt_u08(Rte_InitValue_ISDYN2FRE3CDMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYN2FRE3CDMsgRxTime_MSec_u32(Rte_InitValue_ISDYN2FRE3CDMsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(T_CANMSGINIT_CNT_U08);
# else
  Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(&T_CANMSGINIT_CNT_U08);
# endif
  Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(T_CANMSGINIT_CNT_U08);
# else
  Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(&T_CANMSGINIT_CNT_U08);
# endif
  Rte_IWrite_SrlComDriver_Per1_ISDYNCDS34DMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCDS34DMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNCDS34DMsgRxTime_MSec_u32(Rte_InitValue_ISDYNCDS34DMsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(Rte_InitValue_ISDYNDAEFirstMessageSent_Cnt_lgc);
  Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(T_CANMSGINIT_CNT_U08);
# else
  Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(&T_CANMSGINIT_CNT_U08);
# endif
  Rte_IWrite_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32);
  Rte_IWrite_SrlComDriver_Per1_JourEcoule_Cnt_u16(Rte_InitValue_JourEcoule_Cnt_u16);
  Rte_IWrite_SrlComDriver_Per1_Kilometrage_Cnt_u32(Rte_InitValue_Kilometrage_Cnt_u32);
  Rte_IWrite_SrlComDriver_Per1_LKAState_Cnt_u08(Rte_InitValue_LKAState_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(Rte_InitValue_LKATrqFactReq_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_LXAActivation_Cnt_u08(Rte_InitValue_LXAActivation_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ModeDiag_Cnt_u08(Rte_InitValue_ModeDiag_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(T_CANMSGINIT_CNT_U08);
# else
  Rte_IWrite_SrlComDriver_Per1_PROTOHS1DYNUCF5CDMsg_Cnt_u08(&T_CANMSGINIT_CNT_U08);
# endif
  Rte_IWrite_SrlComDriver_Per1_PowerSupplies_Cnt_u08(Rte_InitValue_PowerSupplies_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_RegulABR_Cnt_u08(Rte_InitValue_RegulABR_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_RegulESP_Cnt_u08(Rte_InitValue_RegulESP_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ReqLampeDefEsp_Cnt_u08(Rte_InitValue_ReqLampeDefEsp_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_ReqModeDA_Cnt_u08(Rte_InitValue_ReqModeDA_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(Rte_InitValue_SecondeEcoulee_Cnt_u32);
  Rte_IWrite_SrlComDriver_Per1_ShuntPosition_Cnt_u08(Rte_InitValue_ShuntPosition_Cnt_u08);
  Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Rte_InitValue_TxEnabled_Cnt_lgc);
  Rte_IWrite_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(Rte_InitValue_VitesseVehicleBV_Cnt_u16);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStart> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStart(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_SCom_ElecIntStart
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStop> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStop(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_SCom_ElecIntStop
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_GetBusOffCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetBusOffCounter> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_SCom_GetBusOffCounter
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_Trns1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_Trns2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#include "MemMap.h"


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
