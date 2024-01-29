/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_LoaMgr.c
 *     Workspace:  C:/_Synergy_Projects/EA3_Working/LoaMgr/autosar
 *     SW-C Type:  Ap_LoaMgr
 *  Generated at:  Thu Mar 15 08:28:10 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_LoaMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2015-2018 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_LoaMgr.c
 * Module Description: Implementation of SF49A
 * Project           : CBD
 * Author            : Spandana Balani
 **********************************************************************************************************************
 * Version Control:
 * %version:          EA3#12 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/01/15  1        SB        Initial Version                                                               13143
 * 04/12/15  2        Selva     Initial implementation missed initialization of module level variables
 *                               & passing wrong parameters to NTC                                            13143
 * 09/23/15  3        JK        Anomaly fix EA3#1374 - LoaMgr Inverter Inputs                                 EA3#3211
 * 11/24/15  4        SB        Updated to SF049_LoaMgr v002                                                  EA3#4145
 * 01/24/16  5        SB        Updated to SF049_LoaMgr v003                                                  EA3#5313
 * 07/19/16  6        SB        Updated to SF049_LoaMgr v4.1.0                                                EA3#8983
 * 07/22/16  7        SB        Added missing requirement tags                                                EA3#8983
 * 12/04/17  8        MB        Added exclusive area                                                          EA3#18042
 * 02/16/18  9        ML        Update to fix Anomaly EA3#18821                                               EA3#18836
 * 03/15/18  10       ML        Update to fix Anomalies EA3#18863, EA3#19291                                  EA3#19295
 * 04/27/18  11       KByrski   Updated to SF049_LoaMgr v4.3.0                                                EA3#19487
 * 06/05/18  12       KByrski   Updated to SF049_LoaMgr v4.4.0 (Anomaly EA3#20083)                            EA3#20193
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_LoaMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables, state variables, and filter constants because of memory map */
/* MISRA-C:2004 Rule 16.10: There is no appropriate action to take on the return value for Rte_Write, GetNTCStatus, SetNTCStatus,
                            GetNTCFailed, and GetNTCActive */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 

/********************************************* Embedded Local Constants **********************************************/
#define D_IVTRLOAMTGTNMASK_CNT_U08              0x02U
#define D_LOABIGSLEW_ULSPS_F32                  500.0F
#define D_LOAMINSLEW_ULSPS_F32                  0.01F
#define D_LOASCAONE_ULS_F32                     D_ONE_ULS_F32
#define D_LOASCAZERO_ULS_F32                    D_ZERO_ULS_F32
#define D_LOASTNORM_CNT_U08                     LOAST_NORM 
#define D_LOASTCTRLDSHUTDWN_CNT_U08             LOAST_CTRLDSHTDWNREQD
#define D_LOASTRPDSHUTDWN_CNT_U08               LOAST_RPDSHTDWNREQD
#define D_LOASTSWMTGTN_CNT_U08                  LOAST_SWBASDMTGTN
#define D_MOTCURRLOAMTGTNMASK_CNT_U08           0x01U
#define D_MAXHWTQIDPTSIGALLWD_CNT_U08           0x04U
#define D_MAXIVTRIDPTSIGALLWD_CNT_U08           0x02U
#define D_MAXMOTCURRIDPTSIGALLWD_CNT_U08        0x02U
#define D_MAXMOTPOSNIDPTSIGALLWD_CNT_U08        0x03U

/*********************************************** Module level variables **********************************************/
#define LOAMGR_START_SEC_VAR_CLEARED_08
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_HwTqIdptSigSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_MotAgIdptSigSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_MotCurrIdptSigSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_IvtrIdptSigSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_HwTqRespSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_MotAgRespSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_MotCurrRespSV_Cnt_M_u08;
STATIC VAR(uint8, AP_LOAMGR_VAR) LoaMgr_IvtrRespSV_Cnt_M_u08;
#define LOAMGR_STOP_SEC_VAR_CLEARED_08
#include "MemMap.h" /* PRQA S 5087 */

#define LOAMGR_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_LOAMGR_VAR) LoaMgr_LoaScaleFctr_Uls_M_f32;
STATIC VAR(float32, AP_LOAMGR_VAR) LoaMgr_LoaRateLimit_UlspS_M_f32;
#define LOAMGR_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define LOAMGR_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_SnsrlsMotAgAvail_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_AgSV_Cnt_M_lgc;           /* PRQA S 3218 */
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_MaxMtgtnResp_Cnt_M_u08;   /* PRQA S 3218 */
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_VltgMdSrcSV_Cnt_M_u08;    /* PRQA S 3218 */
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_TloaAvail_Cnt_M_lgc;
STATIC VAR(boolean, AP_LOAMGR_VAR) LoaMgr_TloaDi_Cnt_M_lgc;
#define LOAMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define LOAMGR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LOA_State_enum, AUTOMATIC) LoaMgr_LOASt_State_M_enum;
#define LOAMGR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************** Function Prototypes *************************************************/
STATIC FUNC(uint8, AP_LOAMGR_APPL_CODE) CalcIvtrState(VAR(boolean, AUTOMATIC) IvtrInactv_Cnt_T_logl);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) LatchInputs(VAR(uint8, AUTOMATIC) HwTqIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) MtrPosIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) MotCurrIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) IvtrIdptSig_Cnt_T_u08);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) RqstRespConds(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum);
STATIC FUNC(uint8, AP_LOAMGR_APPL_CODE) RqstHwTqResp(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) ArbResp(void);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) ChooseFinalResp(VAR(uint8, AUTOMATIC) MultiMtgtnResp_Cnt_T_u08);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) AssignScale(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum);
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) SwBasMtgtn(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum);

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
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 * SteerMod_enum: Enumeration of integer in interval [0...2] with enumerators
 *   STEERMOD_BASEPS (0u)
 *   STEERMOD_SEMIATNMS (1u)
 *   STEERMOD_FULLYATNMS (2u)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * LOA_State_enum: D_LOASTATEINIT_CNT_ENUM = 0u
 * SteerMod_enum: D_STEERMODINIT_CNT_ENUM = 0u
 * UInt8: D_FOUR_CNT_U08 = 4u
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_THREE_CNT_U08 = 3u
 * UInt8: D_TWO_CNT_U08 = 2u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_LOAMGR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LoaMgr_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LoaMgr_Init1
 *********************************************************************************************************************/

    LoaMgr_SnsrlsMotAgAvail_Cnt_M_lgc   = k_LoaMgr_SnsrlsMotAgAvail_Cnt_lgc;                                /* REQ: SF049A #173 I */
    LoaMgr_HwTqIdptSigSV_Cnt_M_u08      = D_MAXHWTQIDPTSIGALLWD_CNT_U08;                                    /* REQ: SF049A #175 I */
    LoaMgr_MotCurrIdptSigSV_Cnt_M_u08   = D_MAXMOTCURRIDPTSIGALLWD_CNT_U08;                                 /* REQ: SF049A #177 I */
    LoaMgr_MotAgIdptSigSV_Cnt_M_u08     = D_MAXMOTPOSNIDPTSIGALLWD_CNT_U08;                                 /* REQ: SF049A #176 I */
    LoaMgr_IvtrIdptSigSV_Cnt_M_u08      = D_MAXIVTRIDPTSIGALLWD_CNT_U08;                                    /* REQ: SF049A #178 I */

    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaRpdShutdn, 0x00U, NTC_STATUS_PASSED);               /* REQ: SF049A #115 I */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaCtrldShutdn, 0x00U, NTC_STATUS_PASSED);             /* REQ: SF049A #118 I */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_HwTqIdptSigTooLow, 0x00U, NTC_STATUS_PASSED);   /* REQ: SF049A #127 I */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_MotAgIdptSigTooLow, 0x00U, NTC_STATUS_PASSED);  /* REQ: SF049A #136 I */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_MotCurrIdptSigTooLow, 0x00U, NTC_STATUS_PASSED);/* REQ: SF049A #145 I */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_IvtrIdptSigTooLow, 0x00U, NTC_STATUS_PASSED);   /* REQ: SF049A #154 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LoaMgr_Per1
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
 *   Boolean Rte_IRead_LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_HwTqIdptSig_Cnt_u08(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_LoaScaDi_Cnt_lgc(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_MotCurrIdptSig_Cnt_u08(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_MtrPosIdptSig_Cnt_u08(void)
 *   SteerMod_enum Rte_IRead_LoaMgr_Per1_SteerMod_Cnt_enum(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_TloaAvail_Cnt_lgc(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_TloaDi_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LoaRateLimit_UlspS_f32(Float data)
 *   Std_ReturnType Rte_Write_LoaScaleFctr_Uls_f32(Float data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_LOASt_State_enum(LOA_State_enum data)
 *   LOA_State_enum *Rte_IWriteRef_LoaMgr_Per1_LOASt_State_enum(void)
 *   void Rte_IWrite_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaLoaScaleAndRate(void)
 *   void Rte_Exit_EaLoaScaleAndRate(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LoaMgr_Per1
 *********************************************************************************************************************/

    VAR(uint8, AUTOMATIC) HwTqIdptSig_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrIdptSig_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotCurrIdptSig_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MtrPosIdptSig_Cnt_T_u08;
    VAR(boolean, AUTOMATIC) DiagcStsIvtr1Inactv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DiagcStsIvtr2Inactv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LoaScaDi_Cnt_T_lgc;
    VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum;
    VAR(uint8,AUTOMATIC) Ivtr1Sts_Cnt_T_u08;
    VAR(uint8,AUTOMATIC) Ivtr2Sts_Cnt_T_u08;

    /* Read Inputs */
    DiagcStsIvtr1Inactv_Cnt_T_lgc   = Rte_IRead_LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc();  /* REQ: SF049A #44 I  */
    DiagcStsIvtr2Inactv_Cnt_T_lgc   = Rte_IRead_LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc();  /* REQ: SF049A #184 I */
    HwTqIdptSig_Cnt_T_u08           = Rte_IRead_LoaMgr_Per1_HwTqIdptSig_Cnt_u08();          /* REQ: SF049A #12 I  */
    MotCurrIdptSig_Cnt_T_u08        = Rte_IRead_LoaMgr_Per1_MotCurrIdptSig_Cnt_u08();       /* REQ: SF049A #43 I  */
    MtrPosIdptSig_Cnt_T_u08         = Rte_IRead_LoaMgr_Per1_MtrPosIdptSig_Cnt_u08();        /* REQ: SF049A #14 I  */
    LoaMgr_TloaAvail_Cnt_M_lgc      = Rte_IRead_LoaMgr_Per1_TloaAvail_Cnt_lgc();            /* REQ: SF049A #13 I  */
    LoaMgr_TloaDi_Cnt_M_lgc         = Rte_IRead_LoaMgr_Per1_TloaDi_Cnt_lgc();               /* REQ: SF049A #189 I */
    SteerMod_Cnt_T_enum             = Rte_IRead_LoaMgr_Per1_SteerMod_Cnt_enum();            /* REQ: SF049A #206 I */
    LoaScaDi_Cnt_T_lgc              = Rte_IRead_LoaMgr_Per1_LoaScaDi_Cnt_lgc();             /* REQ: SF049A #202 I */

    /* REQ: SF049A #183 I */
    /* Calc_Ivtr_State */
    Ivtr1Sts_Cnt_T_u08 = CalcIvtrState(DiagcStsIvtr1Inactv_Cnt_T_lgc);
    Ivtr2Sts_Cnt_T_u08 = CalcIvtrState(DiagcStsIvtr2Inactv_Cnt_T_lgc);
    IvtrIdptSig_Cnt_T_u08 = Ivtr1Sts_Cnt_T_u08 + Ivtr2Sts_Cnt_T_u08;
    /* ENDREQ: SF049A #183 I */

    /* Latch Inputs */
    LatchInputs(HwTqIdptSig_Cnt_T_u08,MtrPosIdptSig_Cnt_T_u08, MotCurrIdptSig_Cnt_T_u08, IvtrIdptSig_Cnt_T_u08);

    /* Request Responses */
    RqstRespConds(SteerMod_Cnt_T_enum);

    /* Arbitrate Responses */
     ArbResp();

    /* Set Faults */
    /* REQ: SF049A #115 I */ /* REQ: SF049A #118 I */
    if(LoaMgr_LOASt_State_M_enum == LOAST_RPDSHTDWNREQD)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaRpdShutdn, 0x00U, NTC_STATUS_FAILED);
    }
    else if(LoaMgr_LOASt_State_M_enum == LOAST_CTRLDSHTDWNREQD)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaCtrldShutdn, 0x00U, NTC_STATUS_FAILED);
    }
    else
    {
    }
    /* ENDREQ: SF049A #115 I */ /* ENDREQ: SF049A #118 I */
    /* REQ: SF049A #127 I */
    if(LoaMgr_HwTqIdptSigSV_Cnt_M_u08 <= k_LoaMgr_HwTqIdptSigFltThd_Cnt_u08)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_HwTqIdptSigTooLow, 0x00U, NTC_STATUS_FAILED);
    }
    /* ENDREQ: SF049A #127 I */
    /* REQ: SF049A #136 I */
    if(LoaMgr_MotAgIdptSigSV_Cnt_M_u08 <= k_LoaMgr_MotAgIdptSigFltThd_Cnt_u08)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_MotAgIdptSigTooLow, 0x00U, NTC_STATUS_FAILED);
    }
    /* ENDREQ: SF049A #136 I */
    /* REQ: SF049A #145 I */
    if(LoaMgr_MotCurrIdptSigSV_Cnt_M_u08 <= k_LoaMgr_MotCurrIdptSigFltThd_Cnt_u08)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_MotCurrIdptSigTooLow, 0x00U, NTC_STATUS_FAILED);
    }
    /* ENDREQ: SF049A #145 I */
    /* REQ: SF049A #154 I */
    if(LoaMgr_IvtrIdptSigSV_Cnt_M_u08 <= k_LoaMgr_IvtrIdptSigFltThd_Cnt_u08)
    {
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LoaMgr_IvtrIdptSigTooLow, 0x00U, NTC_STATUS_FAILED);
    }
    /* ENDREQ: SF049A #154 I */
    /* Assign Scale */
    AssignScale(SteerMod_Cnt_T_enum);
    /* REQ: SF049A #203 I */
    if(LoaScaDi_Cnt_T_lgc == TRUE)
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32 = D_LOASCAONE_ULS_F32;
    }
    /* ENDREQ: SF049A #203 I */
    /* Limit on Outputs */
    LoaMgr_LoaRateLimit_UlspS_M_f32     = Limit_m(LoaMgr_LoaRateLimit_UlspS_M_f32, D_LOAMINSLEW_ULSPS_F32, D_LOABIGSLEW_ULSPS_F32); /* REQ: SF049A #110 I */
    LoaMgr_LoaScaleFctr_Uls_M_f32       = Limit_m(LoaMgr_LoaScaleFctr_Uls_M_f32, D_LOASCAZERO_ULS_F32, D_LOASCAONE_ULS_F32);        /* REQ: SF049A #111 I */


    Rte_IWrite_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc);         /* REQ: SF049A #46 I */
    Rte_IWrite_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc);         /* REQ: SF049A #49 I */
    Rte_IWrite_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc);       /* REQ: SF049A #47 I */
    Rte_IWrite_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc);   /* REQ: SF049A #48 I */
    Rte_IWrite_LoaMgr_Per1_LOASt_State_enum(LoaMgr_LOASt_State_M_enum);                     /* REQ: SF049A #16 I */

    /* These 2 outputs need to be direct writes so the exclusive area can protect the writes from interruptions. Using buffered writes would only have the exclusive area */
    /* protect the write to the buffer, not the write from the buffer to the RTE */
    Rte_Enter_EaLoaScaleAndRate();
    (void)Rte_Write_LoaRateLimit_UlspS_f32(LoaMgr_LoaRateLimit_UlspS_M_f32);         /* REQ: SF049A #18 I */
    (void)Rte_Write_LoaScaleFctr_Uls_f32(LoaMgr_LoaScaleFctr_Uls_M_f32);             /* REQ: SF049A #17 I */
    Rte_Exit_EaLoaScaleAndRate();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_LOAMGR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*******************************************************************************
 * Name        :   CalcIvtrState
 * Description :   Implementation of "Calculate Inverter State" section.
 * Inputs      :   IvtrInactv_Cnt_T_logl
 * Outputs     :   IvtrSts_Cnt_T_u08
 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(uint8, AP_LOAMGR_APPL_CODE) CalcIvtrState(VAR(boolean, AUTOMATIC) IvtrInactv_Cnt_T_logl)
{
    VAR(uint8, AUTOMATIC) IvtrSts_Cnt_T_u08;

    if (IvtrInactv_Cnt_T_logl == TRUE)
    {
        IvtrSts_Cnt_T_u08 = 0U;
    }
    else
    {
        IvtrSts_Cnt_T_u08 = 1U;
    }

    return IvtrSts_Cnt_T_u08;
}

/* Latch Inputs */
/*******************************************************************************
 * Name        :   LatchInputs
 * Description :   Implementation of "Latch_Inputs" section.
 * Inputs      :   HwTqIdptSig_Cnt_T_u08, MtrPosIdptSig_Cnt_T_u08,
                    MotCurrIdptSig_Cnt_T_u08,IvtrIdptSig_Cnt_T_u08
 * Outputs     :   None
 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) LatchInputs(VAR(uint8, AUTOMATIC) HwTqIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) MtrPosIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) MotCurrIdptSig_Cnt_T_u08,
                                                   VAR(uint8, AUTOMATIC) IvtrIdptSig_Cnt_T_u08)
{
    VAR(uint8, AUTOMATIC) RngLimdHwTqIdptSig_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) RngLimdMtrPosIdptSig_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) RngLimdMtrCurrIdptSig_Cnt_T_u08;
    VAR(uint8,AUTOMATIC) HwTqIdptMin_Cnt_T_u08;
    VAR(uint8,AUTOMATIC) MtrPosIdptMin_Cnt_T_u08;
    VAR(uint8,AUTOMATIC) MotCurrIdptMin_Cnt_T_u08;
    VAR(uint8,AUTOMATIC) IvtrIdptMin_Cnt_T_u08;

    /* RngLimHwTqIdptSig */ /* REQ: SF049A #186 I */
    if (HwTqIdptSig_Cnt_T_u08 > D_MAXHWTQIDPTSIGALLWD_CNT_U08)
    {
        RngLimdHwTqIdptSig_Cnt_T_u08 = 0U;
    }
    else
    {
        RngLimdHwTqIdptSig_Cnt_T_u08 = HwTqIdptSig_Cnt_T_u08;
    }
    /* ENDREQ: SF049A #186 I */
    /* RngLimMtrPosIdptSig */ /* REQ: SF049A #187 I */
    if (MtrPosIdptSig_Cnt_T_u08 > D_MAXMOTPOSNIDPTSIGALLWD_CNT_U08)
    {
        RngLimdMtrPosIdptSig_Cnt_T_u08 = 0U;
    }
    else
    {
        RngLimdMtrPosIdptSig_Cnt_T_u08 = MtrPosIdptSig_Cnt_T_u08;
    }
    /* ENDREQ: SF049A #187 I */
    /* RngMtrCurrIdptSig */ /* REQ: SF049A #188 I */
    if (MotCurrIdptSig_Cnt_T_u08 > D_MAXMOTCURRIDPTSIGALLWD_CNT_U08)
    {
        RngLimdMtrCurrIdptSig_Cnt_T_u08 = 0U;
    }
    else
    {
        RngLimdMtrCurrIdptSig_Cnt_T_u08 = MotCurrIdptSig_Cnt_T_u08;
    }
    /* ENDREQ: SF049A #188 I */
    /* Inverter Independent Signal do not need a Range Check
        as the maximum value the signal can attain is only 2. */

    HwTqIdptMin_Cnt_T_u08       = Min_m(RngLimdHwTqIdptSig_Cnt_T_u08, LoaMgr_HwTqIdptSigSV_Cnt_M_u08);      /* REQ: SF049A #175 I */
    MtrPosIdptMin_Cnt_T_u08     = Min_m(RngLimdMtrPosIdptSig_Cnt_T_u08, LoaMgr_MotAgIdptSigSV_Cnt_M_u08);   /* REQ: SF049A #176 I */
    MotCurrIdptMin_Cnt_T_u08    = Min_m(RngLimdMtrCurrIdptSig_Cnt_T_u08, LoaMgr_MotCurrIdptSigSV_Cnt_M_u08);/* REQ: SF049A #177 I */
    IvtrIdptMin_Cnt_T_u08       = Min_m(IvtrIdptSig_Cnt_T_u08, LoaMgr_IvtrIdptSigSV_Cnt_M_u08);             /* REQ: SF049A #178 I */

    LoaMgr_HwTqIdptSigSV_Cnt_M_u08      = HwTqIdptMin_Cnt_T_u08;                                            /* REQ: SF049A #175 I */
    LoaMgr_MotAgIdptSigSV_Cnt_M_u08     = MtrPosIdptMin_Cnt_T_u08;                                          /* REQ: SF049A #176 I */
    LoaMgr_MotCurrIdptSigSV_Cnt_M_u08   = MotCurrIdptMin_Cnt_T_u08;                                         /* REQ: SF049A #177 I */
    LoaMgr_IvtrIdptSigSV_Cnt_M_u08      = IvtrIdptMin_Cnt_T_u08;                                            /* REQ: SF049A #178 I */
    /* at this point the RespSV_Cnt_M variables are equal to the current loop's Resp_T_ values */
    /* downstream functions use the _M_ variables for simplicity to avoid unneeded parameter passing */
}

/* Request Responses */
/*******************************************************************************
 * Name        :   RqstRespConds
 * Description :   Implementation of "Request Responses" section.
 *                 It chooses appropriate calibrated response to
                   each individual minimum signal count.

 * Inputs      :   SteerMod_Cnt_T_enum
 * Outputs     :   None

 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) RqstRespConds(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum)
{
    VAR(boolean, AUTOMATIC) SmpAvail_Cnt_T_lgc;
    VAR(uint8, AUTOMATIC) HwTqResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotAgResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotCurrResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MtrPosIdptMin_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MtrCurrIdptMin_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrIdptMin_Cnt_T_u08;

    MtrPosIdptMin_Cnt_T_u08  = LoaMgr_MotAgIdptSigSV_Cnt_M_u08;
    MtrCurrIdptMin_Cnt_T_u08 = LoaMgr_MotCurrIdptSigSV_Cnt_M_u08;
    IvtrIdptMin_Cnt_T_u08    = LoaMgr_IvtrIdptSigSV_Cnt_M_u08;

    /* HwTq Response */
    HwTqResp_Cnt_T_u08 = RqstHwTqResp(SteerMod_Cnt_T_enum); /* REQ: SF049A #60 I */ /* REQ: SF049A #193 I */

    /* MotAg Response */ /* REQ: SF049A #62 I */ /* REQ: SF049A #198 I */ /* REQ: SF049A #197 I */
    SmpAvail_Cnt_T_lgc = LoaMgr_SnsrlsMotAgAvail_Cnt_M_lgc;
    switch (MtrPosIdptMin_Cnt_T_u08)
    {
        case 1u:
        {
            if (SmpAvail_Cnt_T_lgc == TRUE)
            {
                MotAgResp_Cnt_T_u08 = k_LoaMgr_MotAgSmaAvailResp_Cnt_u08;
            }
            else
            {
                MotAgResp_Cnt_T_u08 = k_LoaMgr_MotAgIdptSig1NoSmaResp_Cnt_u08;
            }
        }
        break;

        case 2u:
            MotAgResp_Cnt_T_u08 = k_LoaMgr_MotAgIdptSig2Resp_Cnt_u08;
        break;

        case 3u:
            MotAgResp_Cnt_T_u08 = k_LoaMgr_MotAgIdptSig3Resp_Cnt_u08;
        break;

        default:
        {
            if (SmpAvail_Cnt_T_lgc == TRUE)
            {
                MotAgResp_Cnt_T_u08 = k_LoaMgr_MotAgSmaAvailResp_Cnt_u08;
            }
            else
            {
                MotAgResp_Cnt_T_u08 = D_LOASTRPDSHUTDWN_CNT_U08;
            }
        }
        break;
    }
    /* ENDREQ: SF049A #62 I */ /* ENDREQ: SF049A #198 I */ /* ENDREQ: SF049A #197 I */

    /* MotCurr Response */ /* REQ: SF049A #64 I */
    switch (MtrCurrIdptMin_Cnt_T_u08)
    {
        case 1u:
            MotCurrResp_Cnt_T_u08 = k_LoaMgr_MotCurrIdptSig1Resp_Cnt_u08;
        break;

        case 2u:
            MotCurrResp_Cnt_T_u08 = k_LoaMgr_MotCurrIdptSig2Resp_Cnt_u08;
        break;

        default:
            MotCurrResp_Cnt_T_u08 = k_LoaMgr_MotCurrIdptSig0Resp_Cnt_u08;
        break;
    }
    /* ENDREQ: SF049A #64 I */

    /* Inverter Response */ /* REQ: SF049A #65 I */
    switch (IvtrIdptMin_Cnt_T_u08)
    {
        case 1u:
            IvtrResp_Cnt_T_u08 = k_LoaMgr_IvtrIdptSig1Resp_Cnt_u08;
        break;

        case 2u:
            IvtrResp_Cnt_T_u08 = k_LoaMgr_IvtrIdptSig2Resp_Cnt_u08;
        break;
        /* REQ: SF049A #200 I */
        default:
            IvtrResp_Cnt_T_u08 = D_LOASTRPDSHUTDWN_CNT_U08;
        break;
        /* ENDREQ: SF049A #200 I */
    }
    /* ENDREQ: SF049A #65 I */

    /* REQ: SF049A #176 I */
    MotAgResp_Cnt_T_u08     = Max_m(LoaMgr_MotAgRespSV_Cnt_M_u08, MotAgResp_Cnt_T_u08);
    MotCurrResp_Cnt_T_u08   = Max_m(LoaMgr_MotCurrRespSV_Cnt_M_u08, MotCurrResp_Cnt_T_u08);
    IvtrResp_Cnt_T_u08      = Max_m(LoaMgr_IvtrRespSV_Cnt_M_u08, IvtrResp_Cnt_T_u08);
    /* ENDREQ: SF049A #176 I */

    LoaMgr_HwTqRespSV_Cnt_M_u08     = HwTqResp_Cnt_T_u08;                                   /* REQ: SF049A #175 I */ /* REQ: SF049A #207 I */
    LoaMgr_MotAgRespSV_Cnt_M_u08    = MotAgResp_Cnt_T_u08;                                  /* REQ: SF049A #177 I */
    LoaMgr_MotCurrRespSV_Cnt_M_u08  = MotCurrResp_Cnt_T_u08;                                /* REQ: SF049A #178 I */
    LoaMgr_IvtrRespSV_Cnt_M_u08     = IvtrResp_Cnt_T_u08;                                   /* REQ: SF049A #179 I */

    /* at this point the RespSV_Cnt_M variables are equal to the current loop's Resp_T_ values */
    /* downstream functions use the _M_ variables for simplicity to avoid unneeded parameter passing */

}

/*******************************************************************************
 * Name        :   RqstHwTqResp
 * Description :   Implementation of "Request Responses" section.
 *                 It chooses appropriate calibrated response to
                    each individual minimum signal count.

 * Inputs      :   SteerMod_Cnt_T_enum
 * Outputs     :   HwTqResp_Cnt_T_u08

 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(uint8, AP_LOAMGR_APPL_CODE) RqstHwTqResp(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum)
{
    VAR(uint8, AUTOMATIC) HwTqResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) HwTqIdptMin_Cnt_T_u08;

    HwTqIdptMin_Cnt_T_u08   = LoaMgr_HwTqIdptSigSV_Cnt_M_u08;
    switch (HwTqIdptMin_Cnt_T_u08)
    {
        case 1u:
        {
            /* TLOA is ok */
            if ((LoaMgr_TloaAvail_Cnt_M_lgc == TRUE) && (LoaMgr_TloaDi_Cnt_M_lgc == FALSE))
            {
                HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig1TloaAvailResp_Cnt_u08;
            }
            /* TLOA is unavailable */
            else
            {
                HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig1NoTloaResp_Cnt_u08;
            }
        }
        break;

        case 2u:
        {
            /* TLOA is disabled */
            if (LoaMgr_TloaDi_Cnt_M_lgc == TRUE)
            {
                HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig2TloaDiResp_Cnt_u08;
            }
            /* TLOA is not disabled */
            else
            {
                HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig2TloaEnaResp_Cnt_u08;
            }
        }
        break;

        case 4u:
            HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig4Resp_Cnt_u08;
        break;

        /* Zero_or_Invalid */ /* REQ: SF049A #199 I */
        default:
        {
            /* TLOA is ok */
            if ((LoaMgr_TloaAvail_Cnt_M_lgc == TRUE) && (LoaMgr_TloaDi_Cnt_M_lgc == FALSE))
            {
                HwTqResp_Cnt_T_u08 = k_LoaMgr_HwTqIdptSig0TloaAvailResp_Cnt_u08;
            }
            /* TLOA is ok */
            else
            {
                HwTqResp_Cnt_T_u08 = D_LOASTCTRLDSHUTDWN_CNT_U08;
            }
        }
        break;
    }
    /* FullyAutonomousSteeringbasedSelection */ /* REQ: SF049A #207 I */
    if (SteerMod_Cnt_T_enum == STEERMOD_FULLYATNMS)
    {
        /* FullyAutonomous */
        HwTqResp_Cnt_T_u08 = D_LOASTNORM_CNT_U08;
    }
    else
    {
        /* NotFullyAutonomous */
        HwTqResp_Cnt_T_u08      = Max_m(LoaMgr_HwTqRespSV_Cnt_M_u08, HwTqResp_Cnt_T_u08);   /* REQ: SF049A #175 I */
    }
    /* ENDREQ: SF049A #207 I */
    return(HwTqResp_Cnt_T_u08);
}

/* Arbitrate Responses */
/*******************************************************************************
 * Name        :   ArbResp
 * Description :   Individual responses can set boolean flags to true to direct downstream functions.
                   The combination of individual responses generates its own "multiple mitigation response".
                   The final LoaState response will be the worst case of individual and "multiple mitigation" responses

 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) ArbResp(void)
{
    VAR(boolean, AUTOMATIC) HwTqLoaMtgtnEn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) MotAgLoaMtgtnEn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) MotCurrLoaMtgtnEn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) IvtrLoaMtgtnEn_Cnt_T_lgc;
    VAR(uint8, AUTOMATIC) HwTq_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotAg_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) VltgMdRqstd_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MtgtnCount_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MultiMtgtnResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) HwTqResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotAgResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotCurrResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrResp_Cnt_T_u08;

    HwTqResp_Cnt_T_u08 = LoaMgr_HwTqRespSV_Cnt_M_u08;
    MotAgResp_Cnt_T_u08 = LoaMgr_MotAgRespSV_Cnt_M_u08;
    MotCurrResp_Cnt_T_u08 = LoaMgr_MotCurrRespSV_Cnt_M_u08;
    IvtrResp_Cnt_T_u08 = LoaMgr_IvtrRespSV_Cnt_M_u08;

    /** Count SwBasedMtgtns **/
    /* Mutually Exclusive Requests */ /* REQ: SF049A #68 I */ /* REQ: SF049A #69 I */
    if ((HwTqResp_Cnt_T_u08 == D_LOASTSWMTGTN_CNT_U08) ||
        (LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc == TRUE))
    {
        HwTqLoaMtgtnEn_Cnt_T_lgc = TRUE;
    }
    else
    {
        HwTqLoaMtgtnEn_Cnt_T_lgc = FALSE;
    }
    /* REQ: SF049A #70 I */ /* REQ: SF049A #71 I */
    if ((MotAgResp_Cnt_T_u08 == D_LOASTSWMTGTN_CNT_U08) ||
        (LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc == TRUE))
    {
        MotAgLoaMtgtnEn_Cnt_T_lgc = TRUE;
    }
    else
    {
        MotAgLoaMtgtnEn_Cnt_T_lgc = FALSE;
    }
    /* ENDREQ: SF049A #70 I */ /* ENDREQ: SF049A #71 I */
    /* Coexisting Requests */ /* REQ: SF049A #72 I */ /* REQ: SF049A #73 I */
    if ((MotCurrResp_Cnt_T_u08 == D_LOASTSWMTGTN_CNT_U08) ||
        (LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc == TRUE))
    {
        MotCurrLoaMtgtnEn_Cnt_T_lgc = TRUE;
    }
    else
    {
        MotCurrLoaMtgtnEn_Cnt_T_lgc = FALSE;
    }
    /* ENDREQ: SF049A #72 I */ /* ENDREQ: SF049A #73 I */
    /* REQ: SF049A #74 I */ /* REQ: SF049A #75 I */
    if ((IvtrResp_Cnt_T_u08 == D_LOASTSWMTGTN_CNT_U08) ||
        (LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc == TRUE))
    {
        IvtrLoaMtgtnEn_Cnt_T_lgc = TRUE;
    }
    else
    {
        IvtrLoaMtgtnEn_Cnt_T_lgc = FALSE;
    }
    /* ENDREQ: SF049A #68 I */ /* ENDREQ: SF049A #69 I */ /* ENDREQ: SF049A #74 I */ /* ENDREQ: SF049A #75 I */
    LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc     = HwTqLoaMtgtnEn_Cnt_T_lgc;
    LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc    = MotAgLoaMtgtnEn_Cnt_T_lgc;
    LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc  = MotCurrLoaMtgtnEn_Cnt_T_lgc;
    LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc     = IvtrLoaMtgtnEn_Cnt_T_lgc;

    /* Count Mtgtn Requests */ /* REQ: SF049A #79 I */
    /* logic simplified from model to reduce complexity/path count */
    HwTq_Cnt_T_u08 = 0u;
    MotAg_Cnt_T_u08 = 0u;
    VltgMdRqstd_Cnt_T_u08 = 0u; /* REQ: SF049A #78 I */
    if (LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        HwTq_Cnt_T_u08 = 1u;
    }
    if (LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        MotAg_Cnt_T_u08 = 1u;
    }
    /* REQ: SF049A #78 I */
    if ((LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc == TRUE) || (LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc == TRUE))
    {
        VltgMdRqstd_Cnt_T_u08 = 1u;
    }
    /* ENDREQ: SF049A #78 I */
    MtgtnCount_Cnt_T_u08 = HwTq_Cnt_T_u08 + MotAg_Cnt_T_u08 + VltgMdRqstd_Cnt_T_u08;
    /* ENDREQ: SF049A #79 I */
    /* REQ: SF049A #80 I */ /* REQ: SF049A #81 I */ /* REQ: SF049A #83 I */
    if ((MtgtnCount_Cnt_T_u08 <= 1u))
    {
        MultiMtgtnResp_Cnt_T_u08 = D_LOASTNORM_CNT_U08;
    }
    else
    {
        MultiMtgtnResp_Cnt_T_u08  = D_LOASTRPDSHUTDWN_CNT_U08;
    }
    /* ENDREQ: SF049A #80 I */ /* ENDREQ: SF049A #81 I */ /* ENDREQ: SF049A #83 I */
    /* Choose Final Response */
    ChooseFinalResp (MultiMtgtnResp_Cnt_T_u08);
}

/* Choose Final Response */
/*******************************************************************************
 * Name        :   ChooseFinalResp
 * Description :   The final LoaState response will be the worst case of individual and "multiple mitigation" responses
 * Inputs      :   MultiMtgtnResp_Cnt_T_u08 :- multiple mitigation response
 * Outputs     :   None
 * Usage Notes :   None
 ******************************************************************************/
 STATIC FUNC(void, AP_LOAMGR_APPL_CODE) ChooseFinalResp(VAR(uint8, AUTOMATIC) MultiMtgtnResp_Cnt_T_u08)
 {
    VAR(uint8, AUTOMATIC) HwTqResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotAgResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MotCurrResp_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrResp_Cnt_T_u08;

    /* REQ: SF049A #84 I */
    HwTqResp_Cnt_T_u08 = LoaMgr_HwTqRespSV_Cnt_M_u08;
    MotAgResp_Cnt_T_u08 = LoaMgr_MotAgRespSV_Cnt_M_u08;
    MotCurrResp_Cnt_T_u08 = LoaMgr_MotCurrRespSV_Cnt_M_u08;
    IvtrResp_Cnt_T_u08 = LoaMgr_IvtrRespSV_Cnt_M_u08;

    LoaMgr_MaxMtgtnResp_Cnt_M_u08 = Max_m(MultiMtgtnResp_Cnt_T_u08, Max_m(HwTqResp_Cnt_T_u08, Max_m(MotAgResp_Cnt_T_u08,
                                                                    Max_m(MotCurrResp_Cnt_T_u08, IvtrResp_Cnt_T_u08))));
    switch (LoaMgr_MaxMtgtnResp_Cnt_M_u08)
    {
        case 0u: /* Normal Operation (least severe))*/
            LoaMgr_LOASt_State_M_enum = LOAST_NORM;
        break;
        case 1u: /* Reduced Performance */
            LoaMgr_LOASt_State_M_enum = LOAST_REDCD;
        break;
        case 2u:/* Software-based Mitigation */
            LoaMgr_LOASt_State_M_enum = LOAST_SWBASDMTGTN;
        break;
        case 3u:/* Fade Out */
            LoaMgr_LOASt_State_M_enum = LOAST_FADEOUT;
        break;
        case 4u:/* F2 */
            LoaMgr_LOASt_State_M_enum = LOAST_CTRLDSHTDWNREQD;
        break;
        default:/* F1 */
            LoaMgr_LOASt_State_M_enum = LOAST_RPDSHTDWNREQD;
        break;
    }
    /* ENDREQ: SF049A #84 I */
}

/* Assign Scale */
/*******************************************************************************
 * Name        :   AssignScale
 * Description :   User sets calibration values for desired system scale factor and slew rate.
 *                 If the chosen LoaState is SwMtgtn, then the choice of scale and slew get more complicated
 * Inputs      :   SteerMod_Cnt_T_enum
 * Outputs     :   None

 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) AssignScale(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum)
{
    /* Assign Scale */
    /* REQ: SF049A #93 I */
    /* REQ: SF049A #94 I */
    /* REQ: SF049A #95 I */
    /* REQ: SF049A #96 I */
    /* REQ: SF049A #97 I */
    /* REQ: SF049A #99 I */
    /* REQ: SF049A #100 I */
    if(LoaMgr_LOASt_State_M_enum == LOAST_NORM)
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32 = D_LOASCAONE_ULS_F32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 =   D_LOABIGSLEW_ULSPS_F32;
    }
    else if(LoaMgr_LOASt_State_M_enum == LOAST_REDCD) /* REQ: SF049A #208 I */
    {
        /* FullyAutonomousSteeringbasedSelection */
        if(SteerMod_Cnt_T_enum == STEERMOD_FULLYATNMS)
        {
            /* FullyAutonomous */
            LoaMgr_LoaScaleFctr_Uls_M_f32 = D_LOASCAONE_ULS_F32;
            LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
        }
        else
        {
            /* NotFullyAutonomous */
            LoaMgr_LoaScaleFctr_Uls_M_f32 = k_LoaMgr_RedcdStSca_Uls_f32;
            LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_RedcdStRate_UlspS_f32;
        }
    }/* ENDREQ: SF049A #208 I */
    else if(LoaMgr_LOASt_State_M_enum == LOAST_SWBASDMTGTN)
    {
        /* Software based Mitigation */
        SwBasMtgtn(SteerMod_Cnt_T_enum);
    }
    else if(LoaMgr_LOASt_State_M_enum == LOAST_FADEOUT)
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_FadeOutStRate_UlspS_f32;
    }
    else if(LoaMgr_LOASt_State_M_enum == LOAST_CTRLDSHTDWNREQD)
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
    }
    else
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
    }
}

/* Software Based Mitigation */
/*******************************************************************************
 * Name        :   SwBasMtgtn
 * Description :   Implementation of "Software based Mitigation" section.
 *                 If the chosen LoaState is SwMtgtn, then the values for
 *                 desired system scale factor and slew rate.

 * Inputs      :   SteerMod_Cnt_T_enum
 * Outputs     :   None

 * Usage Notes :   None
 ******************************************************************************/
STATIC FUNC(void, AP_LOAMGR_APPL_CODE) SwBasMtgtn(VAR(SteerMod_enum, AUTOMATIC) SteerMod_Cnt_T_enum)
{
    VAR(uint8, AUTOMATIC) MotCurrSrc_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) IvtrSrc_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) VltgMdSrc_Cnt_T_u08;
    VAR(boolean, AUTOMATIC) NewValFlag_Cnt_T_lgc;

    /* Mask Booleans */ /* REQ: SF049A #103 I */
    if (LoaMgr_MotCurrLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        MotCurrSrc_Cnt_T_u08 = D_MOTCURRLOAMTGTNMASK_CNT_U08;
    }
    else
    {
        MotCurrSrc_Cnt_T_u08 = 0u;
    }
    if (LoaMgr_IvtrLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        IvtrSrc_Cnt_T_u08 = D_IVTRLOAMTGTNMASK_CNT_U08;
    }
    else
    {
        IvtrSrc_Cnt_T_u08 = 0u;
    }
    VltgMdSrc_Cnt_T_u08 = MotCurrSrc_Cnt_T_u08 + IvtrSrc_Cnt_T_u08;
    /* ENDREQ: SF049A #103 I */
    /* HwTqTrue */ /* REQ: SF049A #107 I */ /* REQ: SF049A #108 I */ /* REQ: SF049A #209 I */
    if (LoaMgr_HwTqLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        LoaMgr_LoaScaleFctr_Uls_M_f32 = k_LoaMgr_HwTqMtgtnSca_Uls_f32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_HwTqMtgtnRate_UlspS_f32;
    }
    /* MotAgTrue */ /* REQ: SF049A #101 I */ /* REQ: SF049A #102 I */
    else if (LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc == TRUE)
    {
        if ((k_LoaMgr_MotAgMtgtnScaZeroEn_Cnt_lgc == TRUE) && (LoaMgr_AgSV_Cnt_M_lgc == FALSE))
        {
            LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
            LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
        }
        else
        {
            LoaMgr_LoaScaleFctr_Uls_M_f32   = k_LoaMgr_MotAgMtgtnSca_Uls_f32;
            LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_MotAgMtgtnRate_UlspS_f32;
        }
    } /* ENDREQ: SF049A #101 I */ /* ENDREQ: SF049A #102 I */
    /* OthersTrue */
    else
    {
        if (VltgMdSrc_Cnt_T_u08 != LoaMgr_VltgMdSrcSV_Cnt_M_u08)
        {
            NewValFlag_Cnt_T_lgc = TRUE;
        }
        else
        {
            NewValFlag_Cnt_T_lgc = FALSE;
        }
        switch (VltgMdSrc_Cnt_T_u08)
        {
            /* CurrOnly */
            case 1u:
            {
                if ((NewValFlag_Cnt_T_lgc == TRUE) && (k_LoaMgr_MotCurrMtgtnScaZeroEn_Cnt_lgc == TRUE)) /* REQ: SF049A #105 I */
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
                }
                else
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = k_LoaMgr_MotCurrMtgtnSca_Uls_f32;                 /* REQ: SF049A #104 I */
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_MotCurrMtgtnRate_UlspS_f32;              /* REQ: SF049A #104 I */
                }
            }
            break;
            /* IvtrOnly */
            case 2u:
            {
                if ((NewValFlag_Cnt_T_lgc == TRUE) && (k_LoaMgr_IvtrMtgtnScaZeroEn_Cnt_lgc == TRUE))    /* REQ: SF049A #105 I */
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
                }
                else
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = k_LoaMgr_IvtrMtgtnSca_Uls_f32;                    /* REQ: SF049A #104 I */
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_IvtrMtgtnRate_UlspS_f32;                 /* REQ: SF049A #104 I */
                }
            }
            break;
            /* CurrIvtr */
            default:
            {
                if ((NewValFlag_Cnt_T_lgc == TRUE) && (k_LoaMgr_CurrIvtrMtgtnScaZeroEn_Cnt_lgc == TRUE))/* REQ: SF049A #105 I */
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = D_LOASCAZERO_ULS_F32;
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
                }
                else
                {
                    LoaMgr_LoaScaleFctr_Uls_M_f32   = k_LoaMgr_CurrIvtrMtgtnSca_Uls_f32;                /* REQ: SF049A #104 I */
                    LoaMgr_LoaRateLimit_UlspS_M_f32 = k_LoaMgr_CurrIvtrMtgtnRate_UlspS_f32;             /* REQ: SF049A #104 I */
                }
            }
            break;
        }
        LoaMgr_VltgMdSrcSV_Cnt_M_u08 = VltgMdSrc_Cnt_T_u08;
    }
    LoaMgr_AgSV_Cnt_M_lgc = LoaMgr_MotAgLoaMtgtnEn_Cnt_M_lgc;
    /* FullyAutonomousSteeringbasedSelection */
    if (SteerMod_Cnt_T_enum == STEERMOD_FULLYATNMS)
    {
        /* FullyAutonomous */
        LoaMgr_LoaScaleFctr_Uls_M_f32 = D_LOASCAONE_ULS_F32;
        LoaMgr_LoaRateLimit_UlspS_M_f32 = D_LOABIGSLEW_ULSPS_F32;
    }
    else
    {
        /* NotFullyAutonomous */
        /* Do Nothing */
    }
} /* ENDREQ: SF049A #107 I */ /* ENDREQ: SF049A #108 I */ /* ENDREQ: SF049A #209 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
