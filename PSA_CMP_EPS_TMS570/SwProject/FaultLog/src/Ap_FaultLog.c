/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_FaultLog.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_FaultLog
 *  Generated at:  Mon Oct 30 15:31:28 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_FaultLog>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          2 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author  Change Description                                                                 SCR #
 * --------  -------  ------  ---------------------------------------------------------------------------------  -----
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#4
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

#include "Rte_Ap_FaultLog.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "CalConstants.h"
#include "GlobalMacro.h"
#include "Dem_PBcfg.h"
#include "il_inc.h"
#include "Nvm.h"


#define D_NUMDTCS_CNT_U16			52u
#define D_BUFSIZE_CNT_U16			120u

#define D_WORDMASK_CNT_U32			0xFFFFul
#define D_BYTEMASK_CNT_U32			0xFFul
#define D_1BITMASK_CNT_U08			0x01u
#define D_2BITMASK_CNT_U08			0x03u
#define D_3BITMASK_CNT_U08			0x07u
#define D_4BITMASK_CNT_U08			0x0Fu
#define D_BYTESHIFT_CNT_S16			8
#define D_0BITSHIFT_CNT_S16			0
#define D_3BITSHIFT_CNT_S16			3
#define D_4BITSHIFT_CNT_S16			4
#define D_5BITSHIFT_CNT_S16			5
#define D_6BITSHIFT_CNT_S16			6
#define D_7BITSHIFT_CNT_S16			7
#define D_FAILBITMASK_CNT_U08		1u
#define D_BYTEWORDMASK_CNT_U32		0xFFFFFFul
#define D_3BYTESHIFT_CNT_S16		24
#define D_FIRSTFRAMEID_CNT_U08		1u
#define D_SECONDFRAMEID_CNT_U08		2u
#define D_JDD2010EPSNODEID_CNT_U08	0x95u
#define D_JDD2004EPSNODEID_CNT_U08	0x15u

#define D_CTVINVALID_CNT_U32		0xFFFFFFFFul
#define D_CTVUNKNOWN_CNT_U32		0xFFFFFFFEul
#define D_RAZGCTUNKNOWN_CNT_U08		0xFFu
#define D_RAZGCTINVALID_CNT_U08		0xFEu

#define D_CTLMAX_CNT_U16				65535u
#define D_RHINVALID_CNT_U32				0xFFFFFFFFul
#define D_HUNDREDMSDELAYLOOPS_CNT_U16	10u
#define D_ONESECDELAYLOOPS_CNT_U16		100u
#define D_TXNUMOFATTEMPTS_CNT_U16		3u
#define D_TXNUMOFPROCESSES_CNT_U16		3u

#define D_JDD2010BYTE1INIT_CNT_U08		0xFFu
#define D_JDD2010BYTE2INIT_CNT_U08		0xFFu
#define D_JDD2010BYTE3INIT_CNT_U08		0xFFu
#define D_JDD2010BYTE4INIT_CNT_U08		0xF8u
#define D_JDD2010BYTE5INIT_CNT_U08		0x0Fu
#define D_JDD2010BYTE6INIT_CNT_U08		0xF0u
#define D_JDD2010RESERVEDINIT_CNT_U08	0xFFu

#define D_JDD2004BYTE1INIT_CNT_U08		0xFFu
#define D_JDD2004BYTE2INIT_CNT_U08		0xFFu
#define D_JDD2004BYTE3INIT_CNT_U08		0x7Fu
#define D_JDD2004BYTE4INIT_CNT_U08		0x7Fu
#define D_JDD2004BYTE5INIT_CNT_U08		0x7Fu
#define D_JDD2004BYTE6INIT_CNT_U08		0xFFu
#define D_JDD2004RESERVED1INIT_CNT_U08	0xFFu
#define D_JDD2004RESERVED2INIT_CNT_U08	0x7Fu

#define D_NUMBEROFFRAMES_CNT_U08	2u
#define D_DTCSTATEPASSED_CNT_U08	0u
#define D_DTCSTATEFAILED_CNT_U08	1u
#define D_JDD2010TYPEOFMESSAGE_CNT_U08	1u
#define D_JDD2004TYPEOFMESSAGE_CNT_U08	0u
#define D_RCDAUTOMATESTATE_CNT_U08	7u
#define D_KILOMETRAGEMSB_CNT_U32	0x800000ul

#define D_STATUSFAILED_CNT_U08		0x01u
#define D_STATUSPASSED_CNT_U08		0x02u
#define D_STATUSEMPTY_CNT_U08		0xFFu

#define D_STATEIDLE_CNT_U08			0u
#define D_STATEFIRSTMSGTX_CNT_U08	1u
#define D_STATEWAITFORACK_CNT_U08	2u
#define D_STATEONESECDELAY_CNT_U08	3u

#define D_VEHSPDLOLMT_KPH_F32		0.0f
#define D_VEHSPDHILMT_KPH_F32		254.0f
#define D_HWTRQLOLMT_HWNM_F32		(-10.0f)
#define D_HWTRQHILMT_HWNM_F32		10.0f
#define D_HWTRQSCALE_HWNMPCNT_F32	0.125f
#define D_HWPOSLOLMT_HWDEG_F32		(-776.0f)
#define D_HWPOSHILMT_HWDEG_F32		776.0f
#define D_HWPOSSCALE_HWDEGPCNT_F32	8.0f
#define D_MTRTRQLOLMT_MTRNM_F32		(-3.5f)
#define D_MTRTRQHILMT_MTRNM_F32		3.5f
#define D_MTRTRQSCALE_MTRNMPCNT_F32	0.03125f
#define D_VBATTLOLMT_VOLT_F32		0.0f
#define D_VBATTHILMT_VOLT_F32		28.0f
#define D_VBATTSCALE_VOLTPCNT_F32	0.125f
#define D_CTRLTEMPLOLMT_DEGC_F32	(-40.0f)
#define D_CTRLTEMPHILMT_DEGC_F32	160.0f
#define D_CTRLTEMPOFFSET_DEGC_F32	40.0f


#define GetByte0(a)		((uint8)(((uint32)(a)) & 0xFFu)) /* PRQA S 3453 */
#define GetByte1(a)		((uint8)((((uint32)(a)) >> 8) & 0xFFu)) /* PRQA S 3453 */
#define GetByte2(a)		((uint8)((((uint32)(a)) >> 16) & 0xFFu)) /* PRQA S 3453 */
#define GetByte3(a)		((uint8)((((uint32)(a)) >> 24) & 0xFFu)) /* PRQA S 3453 */


#define FAULTLOG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_FAULTLOG_VAR) RH_Cnt_M_u32[D_BUFSIZE_CNT_U16];
STATIC VAR(uint32, AP_FAULTLOG_VAR) DateValide_Cnt_M_u32;
STATIC VAR(uint32, AP_FAULTLOG_VAR) PrevISDAT4V2BSI552MsgRxTime_mS_M_u32; /* PRQA S 3218 */
#define FAULTLOG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define FAULTLOG_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_FAULTLOG_VAR) QueueBufIdx_Cnt_M_u16;
STATIC VAR(uint16, AP_FAULTLOG_VAR) CTL_Cnt_M_u16;
STATIC VAR(uint16, AP_FAULTLOG_VAR) CTLLoopCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_FAULTLOG_VAR) TxTimer_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_FAULTLOG_VAR) TxCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_FAULTLOG_VAR) TxProcessCount_Cnt_M_u16; /* PRQA S 3218 */
#define FAULTLOG_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define FAULTLOG_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_FAULTLOG_VAR) TxState_Cnt_M_u08;
#define FAULTLOG_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define FAULTLOG_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_FAULTLOG_VAR) Transmit_Cnt_M_lgc[D_BUFSIZE_CNT_U16];
STATIC VAR(boolean, AP_FAULTLOG_VAR) JDDSync_Cnt_M_lgc;
STATIC VAR(boolean, AP_FAULTLOG_VAR) SaveNvM_Cnt_M_lgc;
STATIC VAR(boolean, AP_FAULTLOG_VAR) TxAcknowledged_Cnt_M_lgc;
#define FAULTLOG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(void, AP_FAULTLOG_CODE) RemoveQueueEntry( VAR(uint16, AUTOMATIC) Index_Cnt_T_u16 );

STATIC FUNC(void, AP_FAULTLOG_CODE) SendFirstMessage(void);
STATIC FUNC(void, AP_FAULTLOG_CODE) SendSecondMessage(void);


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
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_DTCType: Integer in interval [0...4294967295]
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCKindType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_DTC_KIND_ALL_DTCS (1U)
 *   DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
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
 * FaultDataArrayType: Array with 60 element(s) of type FaultDataType
 * QueueDataArrayType: Array with 120 element(s) of type QueueDataType
 *
 * Record Types:
 * =============
 * FaultDataType: Record with elements
 *   Byte1_Cnt_u08 of type UInt8
 *   Byte2_Cnt_u08 of type UInt8
 *   Byte3_Cnt_u08 of type UInt8
 *   Byte4_Cnt_u08 of type UInt8
 *   Byte5_Cnt_u08 of type UInt8
 *   Byte6_Cnt_u08 of type UInt8
 *   Reserved1_Cnt_u08 of type UInt8
 *   Reserved2_Cnt_u08 of type UInt8
 * FaultLogType: Record with elements
 *   CTCFailData of type FaultDataArrayType
 *   CTCPassData of type FaultDataArrayType
 *   QueueData of type QueueDataArrayType
 * QueueDataType: Record with elements
 *   QueueEventIdx_Cnt_u08 of type UInt8
 *   Status_Cnt_u08 of type UInt8
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   FaultLogType *Rte_Pim_FaultLog(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_FAULTLOG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_DTCStatusChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <CallbackDTCStatusChange>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BSIDataMissing_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_BatteryVoltage_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_CMMDataMissing_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_CtrlTemp_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_EngineState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatPrincipSev_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatReseauElec_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HandwheelPosition_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_HandwheelTorque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_Kilometrage_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_MotorTorque_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_PowerSupplies_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ShuntPosition_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_VehicleSpeed_Kph_f32(Float *data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FaultLog_DTCStatusChanged (returns application error)
 *********************************************************************************************************************/
	
	VAR(boolean, AUTOMATIC) BSIDataMissing_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) BatteryVoltage_Volt_T_f32;
	VAR(boolean, AUTOMATIC) CMMDataMissing_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) CtrlTemp_DegC_T_f32;
	VAR(uint8,   AUTOMATIC) EngineState_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) EtatPrincipSev_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) EtatReseauElec_Cnt_T_u08;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelTorque_HwNm_T_f32;
	VAR(uint32,  AUTOMATIC) Kilometrage_Cnt_T_u32;
	VAR(float32, AUTOMATIC) MotorTorque_MtrNm_T_f32;
	VAR(uint8,   AUTOMATIC) PowerSupplies_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ShuntPosition_Cnt_T_u08;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DutyCycleExceeded_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) AbsTempThermLimit_Cnt_T_lgc;
	
	VAR(uint16,  AUTOMATIC) DTCNumber_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) DTCFTB_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DTCFound_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) DTCIndex_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DTCStatus_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) AssistStatus_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DeratingFlag_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HandwheelTorque_Cnt_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_Cnt_T_f32;
	VAR(uint16,  AUTOMATIC) HandwheelPosition_Cnt_T_u16;
	VAR(float32, AUTOMATIC) MotorTorque_Cnt_T_f32;
	VAR(float32, AUTOMATIC) BatteryVoltage_Cnt_T_f32;
	VAR(float32, AUTOMATIC) CtrlTemp_Cnt_T_f32;
	VAR(uint8,   AUTOMATIC) Byte1_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Byte2_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Byte3_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Byte4_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Byte5_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Byte6_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Reserved1_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Reserved2_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) i;
	
	Rte_Read_BSIDataMissing_Cnt_lgc(&BSIDataMissing_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Read_BatteryVoltage_Volt_f32(&BatteryVoltage_Volt_T_f32); /* PRQA S 3200 */
	Rte_Read_CMMDataMissing_Cnt_lgc(&CMMDataMissing_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Read_CtrlTemp_DegC_f32(&CtrlTemp_DegC_T_f32); /* PRQA S 3200 */
	Rte_Read_EngineState_Cnt_u08(&EngineState_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_EtatPrincipSev_Cnt_u08(&EtatPrincipSev_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_EtatReseauElec_Cnt_u08(&EtatReseauElec_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_HandwheelPosition_HwDeg_f32(&HandwheelPosition_HwDeg_T_f32); /* PRQA S 3200 */
	Rte_Read_HandwheelTorque_HwNm_f32(&HandwheelTorque_HwNm_T_f32); /* PRQA S 3200 */
	Rte_Read_Kilometrage_Cnt_u32(&Kilometrage_Cnt_T_u32); /* PRQA S 3200 */
	Rte_Read_MotorTorque_MtrNm_f32(&MotorTorque_MtrNm_T_f32); /* PRQA S 3200 */
	Rte_Read_PowerSupplies_Cnt_u08(&PowerSupplies_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_ShuntPosition_Cnt_u08(&ShuntPosition_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_VehicleSpeed_Kph_f32(&VehicleSpeed_Kph_T_f32); /* PRQA S 3200 */
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	Rte_Call_EpsEn_OP_GET(&EpsEn_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DutyCycleExceeded, &DutyCycleExceeded_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AbsTempThermLimit, &AbsTempThermLimit_Cnt_T_lgc); /* PRQA S 3200 */
	
	if( BSIDataMissing_Cnt_T_lgc == TRUE )
	{
		PowerSupplies_Cnt_T_u08 = 0u;
		ShuntPosition_Cnt_T_u08 = 0u;
		EtatPrincipSev_Cnt_T_u08 = 0u;
		EtatReseauElec_Cnt_T_u08 = 0u;
	}
	
	if( CMMDataMissing_Cnt_T_lgc == TRUE )
	{
		EngineState_Cnt_T_u08 = 0u;
	}
	
	if( Kilometrage_Cnt_T_u32 > 0ul )
	{
		Kilometrage_Cnt_T_u32 |= D_KILOMETRAGEMSB_CNT_U32;
	}
	
	
	/* Check if failed bit changed */
	if( (DTCStatusOld & D_FAILBITMASK_CNT_U08) != (DTCStatusNew & D_FAILBITMASK_CNT_U08) )
	{
		
		/* Search for DTC index in DEM table */
		DTCNumber_Cnt_T_u16 = (uint16)((DTC >> D_BYTESHIFT_CNT_S16) & D_WORDMASK_CNT_U32);
		DTCFTB_Cnt_T_u08 = (uint8)(DTC & D_BYTEMASK_CNT_U32);
		
		DTCFound_Cnt_T_lgc = FALSE;
		
		for( i = 1u; (i < D_NUMDTCS_CNT_U16) && (DTCFound_Cnt_T_lgc == FALSE); i++ )
		{
			if( (Dem_DTCNumberTable[i] == DTCNumber_Cnt_T_u16) &&
				(Dem_DTC_FTB_Table[i] == DTCFTB_Cnt_T_u08) )
			{
				DTCFound_Cnt_T_lgc = TRUE;
				DTCIndex_Cnt_T_u08 = (uint8)i;
			}
		}
		
		if( DTCFound_Cnt_T_lgc == TRUE )
		{
			
			/* Determine new DTC status */
			if( (DTCStatusNew & D_FAILBITMASK_CNT_U08) == D_FAILBITMASK_CNT_U08 )
			{
				DTCStatus_Cnt_T_u08 = D_STATUSFAILED_CNT_U08;
				
				/* Search for and remove any existing entries in the queue */
				for( i = 0u; i < QueueBufIdx_Cnt_M_u16; i++ )
				{
					if( (Rte_Pim_FaultLog()->QueueData[i].QueueEventIdx_Cnt_u08 == DTCIndex_Cnt_T_u08) &&
						( (i > 0u) ||
						  (TxState_Cnt_M_u08 == D_STATEIDLE_CNT_U08) ) )
					{
						RemoveQueueEntry(i);
					}
				}
			}
			else
			{
				DTCStatus_Cnt_T_u08 = D_STATUSPASSED_CNT_U08;
			}
			
			
			/* Add entry to queue */
			if( QueueBufIdx_Cnt_M_u16 < D_BUFSIZE_CNT_U16 )
			{
				
				Rte_Pim_FaultLog()->QueueData[QueueBufIdx_Cnt_M_u16].QueueEventIdx_Cnt_u08 = DTCIndex_Cnt_T_u08;
				Rte_Pim_FaultLog()->QueueData[QueueBufIdx_Cnt_M_u16].Status_Cnt_u08 = DTCStatus_Cnt_T_u08;
				
				if( k_JDD2010Selected_Cnt_lgc == FALSE )
				{
					Transmit_Cnt_M_lgc[QueueBufIdx_Cnt_M_u16] = TRUE;
				}
				else if( JDDSync_Cnt_M_lgc == TRUE )
				{
					RH_Cnt_M_u32[QueueBufIdx_Cnt_M_u16] = DateValide_Cnt_M_u32 + CTL_Cnt_M_u16;
					Transmit_Cnt_M_lgc[QueueBufIdx_Cnt_M_u16] = TRUE;
				}
				else
				{
					RH_Cnt_M_u32[QueueBufIdx_Cnt_M_u16] = CTL_Cnt_M_u16;
					Transmit_Cnt_M_lgc[QueueBufIdx_Cnt_M_u16] = FALSE;
				}
				
				
				/* Save fault data */
				
				if( k_JDD2010Selected_Cnt_lgc == TRUE )
				{
					/* For JDD2010, Bytes 1 through 6 refer to the corresponding bytes in the second frame.  The reserved
					   bytes are unused.
					*/
					
					Byte1_Cnt_T_u08 = GetByte2(Kilometrage_Cnt_T_u32);
					Byte2_Cnt_T_u08 = GetByte1(Kilometrage_Cnt_T_u32);
					Byte3_Cnt_T_u08 = GetByte0(Kilometrage_Cnt_T_u32);
					
					Byte4_Cnt_T_u08 = ( (uint8)((BSIDataMissing_Cnt_T_lgc	& D_1BITMASK_CNT_U08) << D_7BITSHIFT_CNT_S16) |
										(uint8)((CMMDataMissing_Cnt_T_lgc	& D_1BITMASK_CNT_U08) << D_6BITSHIFT_CNT_S16) |
										(uint8)((D_RCDAUTOMATESTATE_CNT_U08	& D_3BITMASK_CNT_U08) << D_3BITSHIFT_CNT_S16) |
										(uint8)((PowerSupplies_Cnt_T_u08	& D_3BITMASK_CNT_U08) << D_0BITSHIFT_CNT_S16) );
					
					Byte5_Cnt_T_u08 = ( (uint8)((ShuntPosition_Cnt_T_u08	& D_2BITMASK_CNT_U08) << D_6BITSHIFT_CNT_S16) |
										(uint8)((EtatPrincipSev_Cnt_T_u08	& D_2BITMASK_CNT_U08) << D_4BITSHIFT_CNT_S16) |
										(uint8)((EngineState_Cnt_T_u08		& D_4BITMASK_CNT_U08) << D_0BITSHIFT_CNT_S16) );
					
					Byte6_Cnt_T_u08 = ( (uint8)((EtatReseauElec_Cnt_T_u08	& D_4BITMASK_CNT_U08) << D_4BITSHIFT_CNT_S16) );
					
					Reserved1_Cnt_T_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
					Reserved2_Cnt_T_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
				}
				else
				{
					/* For JDD2004, Bytes 1 through 3 refer to the corresponding bytes in the second frame.  Bytes 4
					   through 6 refer to the corresponding bytes in the first frame.  Reserved1 refers to Byte 3 in
					   the first frame, and Reserved2 refers to Byte 7 in the first frame.
					*/
					
					VehicleSpeed_Kph_T_f32 = Limit_m(VehicleSpeed_Kph_T_f32, D_VEHSPDLOLMT_KPH_F32, D_VEHSPDHILMT_KPH_F32);
					Reserved1_Cnt_T_u08 = (uint8)VehicleSpeed_Kph_T_f32;
					
					HandwheelTorque_HwNm_T_f32 = Limit_m(HandwheelTorque_HwNm_T_f32, D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32);
					HandwheelTorque_Cnt_T_f32 = HandwheelTorque_HwNm_T_f32 / D_HWTRQSCALE_HWNMPCNT_F32;
					Byte4_Cnt_T_u08 = (uint8)((sint8)HandwheelTorque_Cnt_T_f32);
					
					HandwheelPosition_HwDeg_T_f32 = Limit_m(HandwheelPosition_HwDeg_T_f32, D_HWPOSLOLMT_HWDEG_F32, D_HWPOSHILMT_HWDEG_F32);
					HandwheelPosition_Cnt_T_f32 = HandwheelPosition_HwDeg_T_f32 / D_HWPOSSCALE_HWDEGPCNT_F32;
					HandwheelPosition_Cnt_T_u16 = (uint16)((sint16)HandwheelPosition_Cnt_T_f32);
					Byte5_Cnt_T_u08 = GetByte1(HandwheelPosition_Cnt_T_u16);
					Byte6_Cnt_T_u08 = GetByte0(HandwheelPosition_Cnt_T_u16);
					
					MotorTorque_MtrNm_T_f32 = Limit_m(MotorTorque_MtrNm_T_f32, D_MTRTRQLOLMT_MTRNM_F32, D_MTRTRQHILMT_MTRNM_F32);
					MotorTorque_Cnt_T_f32 = MotorTorque_MtrNm_T_f32 / D_MTRTRQSCALE_MTRNMPCNT_F32;
					Reserved2_Cnt_T_u08 = (uint8)((sint8)MotorTorque_Cnt_T_f32);
					
					BatteryVoltage_Volt_T_f32 = Limit_m(BatteryVoltage_Volt_T_f32, D_VBATTLOLMT_VOLT_F32, D_VBATTHILMT_VOLT_F32);
					BatteryVoltage_Cnt_T_f32 = BatteryVoltage_Volt_T_f32 / D_VBATTSCALE_VOLTPCNT_F32;
					Byte1_Cnt_T_u08 = (uint8)((sint8)BatteryVoltage_Cnt_T_f32);
					
					CtrlTemp_DegC_T_f32 = Limit_m(CtrlTemp_DegC_T_f32, D_CTRLTEMPLOLMT_DEGC_F32, D_CTRLTEMPHILMT_DEGC_F32);
					CtrlTemp_Cnt_T_f32 = CtrlTemp_DegC_T_f32 + D_CTRLTEMPOFFSET_DEGC_F32;
					Byte2_Cnt_T_u08 = (uint8)((sint8)CtrlTemp_Cnt_T_f32);
					
					if( SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE )
					{
						AssistStatus_Cnt_T_lgc = TRUE;
					}
					else
					{
						AssistStatus_Cnt_T_lgc = FALSE;
					}
					DeratingFlag_Cnt_T_lgc = DutyCycleExceeded_Cnt_T_lgc | AbsTempThermLimit_Cnt_T_lgc;
					Byte3_Cnt_T_u08 = ( (uint8)((DeratingFlag_Cnt_T_lgc	& D_1BITMASK_CNT_U08) << D_6BITSHIFT_CNT_S16) |
										(uint8)((AssistStatus_Cnt_T_lgc	& D_1BITMASK_CNT_U08) << D_5BITSHIFT_CNT_S16) |
										(uint8)((EpsEn_Cnt_T_lgc		& D_1BITMASK_CNT_U08) << D_4BITSHIFT_CNT_S16) |
										(uint8)((EngineState_Cnt_T_u08	& D_4BITMASK_CNT_U08) << D_0BITSHIFT_CNT_S16) );
				}
				
				if( DTCStatus_Cnt_T_u08 == D_STATUSFAILED_CNT_U08 )
				{
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte1_Cnt_u08 = Byte1_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte2_Cnt_u08 = Byte2_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte3_Cnt_u08 = Byte3_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte4_Cnt_u08 = Byte4_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte5_Cnt_u08 = Byte5_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Byte6_Cnt_u08 = Byte6_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Reserved1_Cnt_u08 = Reserved1_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCFailData[DTCIndex_Cnt_T_u08].Reserved2_Cnt_u08 = Reserved2_Cnt_T_u08;
				}
				else
				{
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte1_Cnt_u08 = Byte1_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte2_Cnt_u08 = Byte2_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte3_Cnt_u08 = Byte3_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte4_Cnt_u08 = Byte4_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte5_Cnt_u08 = Byte5_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Byte6_Cnt_u08 = Byte6_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Reserved1_Cnt_u08 = Reserved1_Cnt_T_u08;
					Rte_Pim_FaultLog()->CTCPassData[DTCIndex_Cnt_T_u08].Reserved2_Cnt_u08 = Reserved2_Cnt_T_u08;
				}
				
				QueueBufIdx_Cnt_M_u16++;
				
				SaveNvM_Cnt_M_lgc = TRUE;
				
			}
			
		}
		
	}
	
	
	return RTE_E_OK;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Init1
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

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FaultLog_Init1
 *********************************************************************************************************************/
	
	
	VAR(NvM_RequestResultType, AUTOMATIC) BlockStatus_Cnt_T_enum;
	VAR(uint16, AUTOMATIC) i;
	
	
	NvM_GetErrorStatus(Rte_NvmBlock_FaultLog_FaultLog, &BlockStatus_Cnt_T_enum);
	
	
	if( BlockStatus_Cnt_T_enum != NVM_REQ_OK )
	{
		for( i = 0u; i < D_BUFSIZE_CNT_U16; i++ )
		{
			Rte_Pim_FaultLog()->QueueData[i].Status_Cnt_u08 = D_STATUSEMPTY_CNT_U08;
			Rte_Pim_FaultLog()->QueueData[i].QueueEventIdx_Cnt_u08 = 0u;
		}
		
		for( i = 0u; i < D_NUMDTCS_CNT_U16; i++ )
		{
			if( k_JDD2010Selected_Cnt_lgc == TRUE )
			{
				Rte_Pim_FaultLog()->CTCFailData[i].Byte1_Cnt_u08 = D_JDD2010BYTE1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte2_Cnt_u08 = D_JDD2010BYTE2INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte3_Cnt_u08 = D_JDD2010BYTE3INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte4_Cnt_u08 = D_JDD2010BYTE4INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte5_Cnt_u08 = D_JDD2010BYTE5INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte6_Cnt_u08 = D_JDD2010BYTE6INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Reserved1_Cnt_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Reserved2_Cnt_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte1_Cnt_u08 = D_JDD2010BYTE1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte2_Cnt_u08 = D_JDD2010BYTE2INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte3_Cnt_u08 = D_JDD2010BYTE3INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte4_Cnt_u08 = D_JDD2010BYTE4INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte5_Cnt_u08 = D_JDD2010BYTE5INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte6_Cnt_u08 = D_JDD2010BYTE6INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Reserved1_Cnt_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Reserved2_Cnt_u08 = D_JDD2010RESERVEDINIT_CNT_U08;
			}
			else
			{
				Rte_Pim_FaultLog()->CTCFailData[i].Byte1_Cnt_u08 = D_JDD2004BYTE1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte2_Cnt_u08 = D_JDD2004BYTE2INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte3_Cnt_u08 = D_JDD2004BYTE3INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte4_Cnt_u08 = D_JDD2004BYTE4INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte5_Cnt_u08 = D_JDD2004BYTE5INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Byte6_Cnt_u08 = D_JDD2004BYTE6INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Reserved1_Cnt_u08 = D_JDD2004RESERVED1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCFailData[i].Reserved2_Cnt_u08 = D_JDD2004RESERVED2INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte1_Cnt_u08 = D_JDD2004BYTE1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte2_Cnt_u08 = D_JDD2004BYTE2INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte3_Cnt_u08 = D_JDD2004BYTE3INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte4_Cnt_u08 = D_JDD2004BYTE4INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte5_Cnt_u08 = D_JDD2004BYTE5INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Byte6_Cnt_u08 = D_JDD2004BYTE6INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Reserved1_Cnt_u08 = D_JDD2004RESERVED1INIT_CNT_U08;
				Rte_Pim_FaultLog()->CTCPassData[i].Reserved2_Cnt_u08 = D_JDD2004RESERVED2INIT_CNT_U08;
			}
		}
		
		SaveNvM_Cnt_M_lgc = TRUE;
	}
	
	for( i = 0u; i < D_BUFSIZE_CNT_U16; i++ )
	{
		RH_Cnt_M_u32[i] = D_RHINVALID_CNT_U32;
		Transmit_Cnt_M_lgc[i] = FALSE;
	}
	
	QueueBufIdx_Cnt_M_u16 = 0u;
	while( (Rte_Pim_FaultLog()->QueueData[QueueBufIdx_Cnt_M_u16].Status_Cnt_u08 != D_STATUSEMPTY_CNT_U08) &&
		   (QueueBufIdx_Cnt_M_u16 < D_BUFSIZE_CNT_U16) )
	{
		if( k_JDD2010Selected_Cnt_lgc == FALSE )
		{
			Transmit_Cnt_M_lgc[QueueBufIdx_Cnt_M_u16] = TRUE;
		}
		
		QueueBufIdx_Cnt_M_u16++;
	}
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   UInt8 Rte_IRead_FaultLog_Per1_ComputerRazGCT_Cnt_u08(void)
 *   UInt32 Rte_IRead_FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   Boolean Rte_IRead_FaultLog_Per1_TxEnabled_Cnt_lgc(void)
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

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FaultLog_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint8,   AUTOMATIC) ComputerRazGCT_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDAT4V2BSI552MsgRxTime_mS_T_u32;
	VAR(boolean, AUTOMATIC) TxEnabled_Cnt_T_lgc;
	
	VAR(uint16,  AUTOMATIC) CTLPreSync_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) i;
	
	
	CompteurTemporelVehicule_Cnt_T_u32 = Rte_IRead_FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32();
	ComputerRazGCT_Cnt_T_u08 = Rte_IRead_FaultLog_Per1_ComputerRazGCT_Cnt_u08();
	ISDAT4V2BSI552MsgRxTime_mS_T_u32 = Rte_IRead_FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32();
	TxEnabled_Cnt_T_lgc = Rte_IRead_FaultLog_Per1_TxEnabled_Cnt_lgc();
	
	
	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		if( CTL_Cnt_M_u16 < D_CTLMAX_CNT_U16 )
		{
			CTLLoopCount_Cnt_M_u16++;
			
			if( CTLLoopCount_Cnt_M_u16 >= D_HUNDREDMSDELAYLOOPS_CNT_U16 )
			{
				CTL_Cnt_M_u16++;
				CTLLoopCount_Cnt_M_u16 = 0u;
			}
		}
		
		if( (ISDAT4V2BSI552MsgRxTime_mS_T_u32 != PrevISDAT4V2BSI552MsgRxTime_mS_M_u32) &&
			(CompteurTemporelVehicule_Cnt_T_u32 != D_CTVINVALID_CNT_U32) &&
			(CompteurTemporelVehicule_Cnt_T_u32 != D_CTVUNKNOWN_CNT_U32) )
		{
			DateValide_Cnt_M_u32 = CompteurTemporelVehicule_Cnt_T_u32;
			CTLPreSync_Cnt_T_u16 = CTL_Cnt_M_u16;
			CTL_Cnt_M_u16 = 0u;
			CTLLoopCount_Cnt_M_u16 = 0u;
			
			if( (ComputerRazGCT_Cnt_T_u08 != D_RAZGCTUNKNOWN_CNT_U08) &&
				(ComputerRazGCT_Cnt_T_u08 != D_RAZGCTINVALID_CNT_U08) )
			{
				DateValide_Cnt_M_u32 = (DateValide_Cnt_M_u32 & D_BYTEWORDMASK_CNT_U32) |
									   (((uint32)ComputerRazGCT_Cnt_T_u08) << D_3BYTESHIFT_CNT_S16);
			}
			
			/* Sync Event Processing */
			if( JDDSync_Cnt_M_lgc == FALSE )
			{
				for( i = 0u; i < QueueBufIdx_Cnt_M_u16; i++ )
				{
					if( Transmit_Cnt_M_lgc[i] == FALSE )
					{
						if( RH_Cnt_M_u32[i] != D_RHINVALID_CNT_U32 )
						{
							if( (((uint32)CTLPreSync_Cnt_T_u16) > DateValide_Cnt_M_u32) ||
								(CTLPreSync_Cnt_T_u16 == D_CTLMAX_CNT_U16) )
							{
								RH_Cnt_M_u32[i] = D_RHINVALID_CNT_U32;
							}
							else
							{
								RH_Cnt_M_u32[i] = RH_Cnt_M_u32[i] + (DateValide_Cnt_M_u32 - ((uint32)CTLPreSync_Cnt_T_u16));
							}
						}
						
						Transmit_Cnt_M_lgc[i] = TRUE;
					}
				}
				
				JDDSync_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			if( (JDDSync_Cnt_M_lgc == TRUE) &&
				(CTL_Cnt_M_u16 == D_CTLMAX_CNT_U16) )
			{
				JDDSync_Cnt_M_lgc = FALSE;
			}
		}
		
		PrevISDAT4V2BSI552MsgRxTime_mS_M_u32 = ISDAT4V2BSI552MsgRxTime_mS_T_u32;
	}
	
	
	/* Check for messages to transmit, state machine, etc */
	if( TxEnabled_Cnt_T_lgc == FALSE )
	{
		TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
	}
	else
	{
		if( TxState_Cnt_M_u08 == D_STATEFIRSTMSGTX_CNT_U08 )
		{
			TxTimer_Cnt_M_u16++;
			
			if( TxTimer_Cnt_M_u16 >= D_HUNDREDMSDELAYLOOPS_CNT_U16 )
			{
				SendSecondMessage();
				
				TxAcknowledged_Cnt_M_lgc = FALSE;
				TxTimer_Cnt_M_u16 = 0u;
				TxState_Cnt_M_u08 = D_STATEWAITFORACK_CNT_U08;
			}
		}
		else if( TxState_Cnt_M_u08 == D_STATEWAITFORACK_CNT_U08 )
		{
			
			if( TxAcknowledged_Cnt_M_lgc == TRUE )
			{
				RemoveQueueEntry(0u);
				TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
			}
			else
			{
				TxTimer_Cnt_M_u16++;
				
				if( TxTimer_Cnt_M_u16 >= D_HUNDREDMSDELAYLOOPS_CNT_U16 )
				{
					TxCount_Cnt_M_u16++;
					
					if( TxCount_Cnt_M_u16 >= D_TXNUMOFATTEMPTS_CNT_U16 )
					{
						if( k_JDD2010Selected_Cnt_lgc == TRUE )
						{
							TxTimer_Cnt_M_u16 = 0u;
							TxState_Cnt_M_u08 = D_STATEONESECDELAY_CNT_U08;
						}
						else
						{
							RemoveQueueEntry(0u);
							TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
						}
					}
					else
					{
						SendFirstMessage();
						
						TxTimer_Cnt_M_u16 = 0u;
						TxState_Cnt_M_u08 = D_STATEFIRSTMSGTX_CNT_U08;
					}
				}
			}
		}
		else if( TxState_Cnt_M_u08 == D_STATEONESECDELAY_CNT_U08 )
		{
			TxTimer_Cnt_M_u16++;
			
			if( TxTimer_Cnt_M_u16 >= D_ONESECDELAYLOOPS_CNT_U16 )
			{
				TxProcessCount_Cnt_M_u16++;
				
				if( TxProcessCount_Cnt_M_u16 >= D_TXNUMOFPROCESSES_CNT_U16 )
				{
					RemoveQueueEntry(0u);
					TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
				}
				else
				{
					SendFirstMessage();
					
					TxCount_Cnt_M_u16 = 0u;
					TxTimer_Cnt_M_u16 = 0u;
					TxState_Cnt_M_u08 = D_STATEFIRSTMSGTX_CNT_U08;
				}
			}
		}
		else
		{
			TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
		}
		
		if( TxState_Cnt_M_u08 == D_STATEIDLE_CNT_U08 )
		{
			if( TxTimer_Cnt_M_u16 < D_HUNDREDMSDELAYLOOPS_CNT_U16 )
			{
				TxTimer_Cnt_M_u16++;
			}
			
			if( (Transmit_Cnt_M_lgc[0u] == TRUE) &&
				(TxTimer_Cnt_M_u16 >= D_HUNDREDMSDELAYLOOPS_CNT_U16) )
			{
				SendFirstMessage();
				
				TxProcessCount_Cnt_M_u16 = 0u;
				TxCount_Cnt_M_u16 = 0u;
				TxTimer_Cnt_M_u16 = 0u;
				TxState_Cnt_M_u08 = D_STATEFIRSTMSGTX_CNT_U08;
			}
		}
	}
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Trns1
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

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FaultLog_Trns1
 *********************************************************************************************************************/
	
	if( SaveNvM_Cnt_M_lgc == TRUE )
	{
		NvM_WriteBlock(Rte_NvmBlock_FaultLog_FaultLog, NULL_PTR); /* PRQA S 3200 */
	}
	
	TxState_Cnt_M_u08 = D_STATEIDLE_CNT_U08;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_FAULTLOG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


FUNC(void, AP_FAULTLOG_CODE) FaultLog_RxISACQNEWJDD55F(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) DataAcqJDDBSI2_Cnt_T_u08;
	
	DataAcqJDDBSI2_Cnt_T_u08 = IlGetRxDATA_ACQ_JDD_BSI_2();
	
	if( (DataAcqJDDBSI2_Cnt_T_u08 == D_JDD2010EPSNODEID_CNT_U08) &&
		(k_JDD2010Selected_Cnt_lgc == TRUE) )
	{
		TxAcknowledged_Cnt_M_lgc = TRUE;
	}
}


FUNC(void, AP_FAULTLOG_CODE) FaultLog_RxISACQJDDCANBSI772(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) DataAcqJDDBSI_Cnt_T_u08;
	
	DataAcqJDDBSI_Cnt_T_u08 = IlGetRxDATA_ACQ_JDD_BSI();
	
	if( (DataAcqJDDBSI_Cnt_T_u08 == D_JDD2004EPSNODEID_CNT_U08) &&
		(k_JDD2010Selected_Cnt_lgc == FALSE) )
	{
		TxAcknowledged_Cnt_M_lgc = TRUE;
	}
}


STATIC FUNC(void, AP_FAULTLOG_CODE) RemoveQueueEntry( VAR(uint16, AUTOMATIC) Index_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) i;
	
	if( Index_Cnt_T_u16 < QueueBufIdx_Cnt_M_u16 )
	{
		for( i = Index_Cnt_T_u16; i < (QueueBufIdx_Cnt_M_u16 - 1u); i++ )
		{
			Rte_Pim_FaultLog()->QueueData[i].Status_Cnt_u08 = Rte_Pim_FaultLog()->QueueData[i+1u].Status_Cnt_u08;
			Rte_Pim_FaultLog()->QueueData[i].QueueEventIdx_Cnt_u08 = Rte_Pim_FaultLog()->QueueData[i+1u].QueueEventIdx_Cnt_u08;
			RH_Cnt_M_u32[i] = RH_Cnt_M_u32[i+1u];
			Transmit_Cnt_M_lgc[i] = Transmit_Cnt_M_lgc[i+1u];
		}
		
		Rte_Pim_FaultLog()->QueueData[i].Status_Cnt_u08 = D_STATUSEMPTY_CNT_U08;
		Rte_Pim_FaultLog()->QueueData[i].QueueEventIdx_Cnt_u08 = 0u;
		RH_Cnt_M_u32[i] = D_RHINVALID_CNT_U32;
		Transmit_Cnt_M_lgc[i] = FALSE;
		
		QueueBufIdx_Cnt_M_u16--;
		
		SaveNvM_Cnt_M_lgc = TRUE;
	}
	
}


STATIC FUNC(void, AP_FAULTLOG_CODE) SendFirstMessage(void)
{
	VAR(uint8,  AUTOMATIC) EventIndex_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) FaultCode_Cnt_T_u32;
	
	EventIndex_Cnt_T_u08 = Rte_Pim_FaultLog()->QueueData[0u].QueueEventIdx_Cnt_u08;
	
	FaultCode_Cnt_T_u32 = (((uint32)Dem_DTCNumberTable[EventIndex_Cnt_T_u08]) << D_BYTESHIFT_CNT_S16) |
						  ((uint32)Dem_DTC_FTB_Table[EventIndex_Cnt_T_u08]);
	
	IlPutTxNumber_of_Frames(D_NUMBEROFFRAMES_CNT_U08);
	
	if( Rte_Pim_FaultLog()->QueueData[0u].Status_Cnt_u08 == D_STATUSFAILED_CNT_U08 )
	{
		IlPutTxDTC_State(D_DTCSTATEFAILED_CNT_U08);
	}
	else
	{
		IlPutTxDTC_State(D_DTCSTATEPASSED_CNT_U08);
	}
	
	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		IlPutTxType_of_Message(D_JDD2010TYPEOFMESSAGE_CNT_U08);
		IlPutTxJDD_Byte1(GetByte2(FaultCode_Cnt_T_u32));
		IlPutTxJDD_Byte2(GetByte1(FaultCode_Cnt_T_u32));
		IlPutTxJDD_Byte3(GetByte0(FaultCode_Cnt_T_u32));
		IlPutTxJDD_Byte4(GetByte3(RH_Cnt_M_u32[0u]));
		IlPutTxJDD_Byte5(GetByte2(RH_Cnt_M_u32[0u]));
		IlPutTxJDD_Byte6(GetByte1(RH_Cnt_M_u32[0u]));
		IlPutTxJDD_Byte7(GetByte0(RH_Cnt_M_u32[0u]));
	}
	else
	{
		IlPutTxType_of_Message(D_JDD2004TYPEOFMESSAGE_CNT_U08);
		IlPutTxJDD_Byte1(GetByte2(FaultCode_Cnt_T_u32));
		IlPutTxJDD_Byte2(GetByte1(FaultCode_Cnt_T_u32));
		
		if( Rte_Pim_FaultLog()->QueueData[0u].Status_Cnt_u08 == D_STATUSFAILED_CNT_U08 )
		{
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Reserved1_Cnt_u08);
			IlPutTxJDD_Byte4(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte4_Cnt_u08);
			IlPutTxJDD_Byte5(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte5_Cnt_u08);
			IlPutTxJDD_Byte6(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte6_Cnt_u08);
			IlPutTxJDD_Byte7(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Reserved2_Cnt_u08);
		}
		else
		{
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Reserved1_Cnt_u08);
			IlPutTxJDD_Byte4(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte4_Cnt_u08);
			IlPutTxJDD_Byte5(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte5_Cnt_u08);
			IlPutTxJDD_Byte6(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte6_Cnt_u08);
			IlPutTxJDD_Byte7(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Reserved2_Cnt_u08);
		}
	}
	
	IlPutTxFrame_Number(D_FIRSTFRAMEID_CNT_U08);
}


STATIC FUNC(void, AP_FAULTLOG_CODE) SendSecondMessage(void)
{
	VAR(uint8, AUTOMATIC) EventIndex_Cnt_T_u08;
	
	EventIndex_Cnt_T_u08 = Rte_Pim_FaultLog()->QueueData[0u].QueueEventIdx_Cnt_u08;
	
	IlPutTxNumber_of_Frames(D_NUMBEROFFRAMES_CNT_U08);
	
	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		IlPutTxType_of_Message(D_JDD2010TYPEOFMESSAGE_CNT_U08);
		
		if( Rte_Pim_FaultLog()->QueueData[0u].Status_Cnt_u08 == D_STATUSFAILED_CNT_U08 )
		{
			IlPutTxDTC_State(D_DTCSTATEFAILED_CNT_U08);
			IlPutTxJDD_Byte1(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte1_Cnt_u08);
			IlPutTxJDD_Byte2(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte2_Cnt_u08);
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte3_Cnt_u08);
			IlPutTxJDD_Byte4(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte4_Cnt_u08);
			IlPutTxJDD_Byte5(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte5_Cnt_u08);
			IlPutTxJDD_Byte6(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte6_Cnt_u08);
		}
		else
		{
			IlPutTxDTC_State(D_DTCSTATEPASSED_CNT_U08);
			IlPutTxJDD_Byte1(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte1_Cnt_u08);
			IlPutTxJDD_Byte2(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte2_Cnt_u08);
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte3_Cnt_u08);
			IlPutTxJDD_Byte4(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte4_Cnt_u08);
			IlPutTxJDD_Byte5(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte5_Cnt_u08);
			IlPutTxJDD_Byte6(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte6_Cnt_u08);
		}
		
		IlPutTxJDD_Byte7(0u);
	}
	else
	{
		IlPutTxType_of_Message(D_JDD2004TYPEOFMESSAGE_CNT_U08);
		
		if( Rte_Pim_FaultLog()->QueueData[0u].Status_Cnt_u08 == D_STATUSFAILED_CNT_U08 )
		{
			IlPutTxDTC_State(D_DTCSTATEFAILED_CNT_U08);
			IlPutTxJDD_Byte1(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte1_Cnt_u08);
			IlPutTxJDD_Byte2(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte2_Cnt_u08);
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCFailData[EventIndex_Cnt_T_u08].Byte3_Cnt_u08);
		}
		else
		{
			IlPutTxDTC_State(D_DTCSTATEPASSED_CNT_U08);
			IlPutTxJDD_Byte1(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte1_Cnt_u08);
			IlPutTxJDD_Byte2(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte2_Cnt_u08);
			IlPutTxJDD_Byte3(Rte_Pim_FaultLog()->CTCPassData[EventIndex_Cnt_T_u08].Byte3_Cnt_u08);
		}
		
		IlPutTxJDD_Byte4(0u);
		IlPutTxJDD_Byte5(0u);
		IlPutTxJDD_Byte6(0u);
		IlPutTxJDD_Byte7(0u);
	}
	
	IlPutTxFrame_Number(D_SECONDFRAMEID_CNT_U08);
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
