/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Cd_SrlComDriver.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Cd_SrlComDriver
 *  Generated at:  Tue Apr 24 15:29:11 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Cd_SrlComDriver>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          15 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#15
 * 06/12/16    2       WH       Update for msgs 50D, 3CD, 34D                              			          EA3#8404
 * 06/14/16    3       WH       Update msg 412 to SCIR 4E (multimode)                      			          EA3#8404
 * 06/27/16    4       WH       Update outpus for msg 3F2                               			          EA3#8404
 * 12/18/16    5       AR       Added call-out functions to disable CAN interrupts             			      EA3#13252
 * 03/09/17    6       AR       Update for SCIR version 2C                                  			      EA3#14168
 * 03/22/17    7       AR       Change cal name k_BusOffTimeout_mS_M_u32 to k_BusOffTimeout_mS_u16            EA3#14817
 * 04/21/17    8       AR       CALIBRATION_VOL set based out of input from Serial com out                    EA3#15385
 * 12/06/17    9       RK       Serial Com refactoring related to CPU Load optimization and MISRA			  EA3#18157
 * 02/08/18    10      RK       Fix for CAN bus off recovery scenario										  EA3#17854
 * 03/21/18    11      RK       CTC Inhibition									                              EA3#13314
 * 04/12/18    12      RK       Fix for missing TRQ_LIMIT_STATE signal			                              EA3#19464
 * 04/30/18    13      RK       IS_DAT_DIRA	confirmed when CAN Tx confirmation arrives                        EA3#19442
 * 04/30/18	   14      RK       SCIR update for 05.02.00                                                      EA3#19811
 * 05/17/18	   15      RK       OFF->WarmInit transition - VehicleSpeedValid set to False					  EA3#20072
 */
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
  CPLE_VOLANT
    Scaling range Max limit is wrong. Tool does not let to set real value, only decimal

  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


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


#include "il_inc.h"
#include "tpmc.h"
#include "desc.h"
#include "appdesc.h"
#include "Dem.h"
#include "EPS_DiagSrvcs_ISO.h"
#include "SystemTime.h"
#include "CalConstants.h"
#include "Ap_DfltConfigData.h"
#include "Nvm.h"
#include "Interrupts.h"

#define D_BUSOFF_RECOVERY_TIME_SHORT_MS_U16		50u
#define D_BUSOFF_RECOVERY_TIME_LONG_MS_U16		250u
#define D_BUSOFF_RECOVERY_LIMIT_CNT_U16			10u
#define D_BUSOFF_NTC_LIMIT_CNT_U16				16u
#define D_BUSOFF_COUNTER_LIMIT_CNT_U16			255u

#define SRLCOMDRIVER_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  CD_SRLCOMDRIVER_VAR) BusOffTimer_mS_M_u32;
STATIC VAR(uint32,  CD_SRLCOMDRIVER_VAR) BusActiveTimer_mS_M_u32;
STATIC VAR(uint32,  CD_SRLCOMDRIVER_VAR) ISDATDIRAMsgTxTime_MSec_M_u32; /* PRQA S 3218 */
#define SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMDRIVER_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, CD_SRLCOMDRIVER_VAR) BusOffCounter_Cnt_M_u16;
#define SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMDRIVER_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNDAEMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNVOLMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDAT4V2BSI552MsgDLCError_Cnt_M_u08;
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDATBSI3F2MsgDLCError_Cnt_M_u08;
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDATBSI412MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDATBSI432MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYN2CMMMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNAASMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNABRMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNCMM208MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNCMM388MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNVOLMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYN2FRE3CDMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDYNCDS34DMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDATABR50DMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) ISDATBSI572MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, CD_SRLCOMDRIVER_VAR) PROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
#define SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMDRIVER_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) BusOffEvent_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) TxEnabledInit_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) ElectronicIntegration_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) ISDATDIRAMsgTxInProgress_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) TxEnabled_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) LXASelected_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) ESCOffsCfgSeld_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) CAVHCSelected_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) CityParkSelected_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) STTdSelected_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) MultimodeSelected_Cnt_M_lgc;
STATIC VAR(boolean, CD_SRLCOMDRIVER_VAR) ReInitializeComponent_M_lgc;
#define SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, CDD_SRLCOMDRIVER_CODE) SrlComDriver_ReInit(void);
STATIC FUNC(boolean, CD_SRLCOMDRIVER_CODE) SrlComDriver_BusOff(void);
STATIC FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_SendIsSupvDira(void);

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
 * ANGLE_VOLANT: Integer in interval [-7800...7800]
 * ANGLE_VOLANT_ORIGINE: Integer in interval [0...3]
 * AUTOR_ARRET_MOT_DA: Boolean
 * Boolean: Boolean (standard type)
 * CALIBRATION_VOL: Boolean
 * CAUSE_DESACTIV_CPK: Integer in interval [0...7]
 * CHKSUM_TRME_DYN_DAE: Integer in interval [0...15]
 * CHKSUM_VOL: Integer in interval [0...15]
 * CODE_DEFAUT: Integer in interval [0...255]
 * CODE_DEFAUT_VOL: Integer in interval [0...15]
 * CPLE_VOLANT: Integer in interval [-128...127]
 * CPLE_VOLANT_OPTMSE: Integer in interval [-100...100]
 * CPT_PROCESS_4B_A_VOL: Integer in interval [0...15]
 * CPT_PROCESS_4B_DAE: Integer in interval [0...15]
 * DDE_REDEM_DA: Boolean
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * EPS_STATE_LKA: Integer in interval [0...15]
 * ETAT_ASSIST_DA: Integer in interval [0...7]
 * ETAT_CAPT_VOL: Boolean
 * ETAT_DAE_CAV3_VIRTUEL: Integer in interval [0...7]
 * ETAT_DAE_CPK: Integer in interval [0...3]
 * ETAT_DA_2004: Integer in interval [0...3]
 * ETAT_DA_2010: Integer in interval [0...3]
 * ETAT_DA_DYN: Integer in interval [0...3]
 * ETAT_LIGNE_APC: Boolean
 * ETAT_SECU_ANGLE_COL: Boolean
 * FLG_AVOL_ICN: Boolean
 * FLG_INIT_AVOL: Boolean
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SENS_ROT_VOL: Boolean
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * STATUS_CONFABSENT: Integer in interval [0...4294967295]
 * STEERWHL_HOLD_BY_DRV: Boolean
 * TRIM_VOL: Boolean
 * TRQ_LIMIT_STATE: Boolean
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 * VITESSE_COLONNE: Integer in interval [-2000...2000]
 * VITESSE_ROT_VOL: Integer in interval [0...254]
 * VITESSE_ROT_VOL_OPTIMISE: Integer in interval [0...255]
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
 *   NTC_Num_MotBasdHwAgFlt (153U)
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * NxtrOpCycle: Enumeration of integer in interval [0...0] with enumerators
 *   NxtrDefaultOpCycle (0U)
 * NxtrOpCycleState: Enumeration of integer in interval [1...2] with enumerators
 *   NXTR_CYCLE_STATE_START (1U)
 *   NXTR_CYCLE_STATE_END (2U)
 *
 * Array Types:
 * ============
 * CanMsgType: Array with 8 element(s) of type UInt8
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * IS_DAT_DIRA_Msg: Record with elements
 *   CpleVolant of type CPLE_VOLANT
 *   EtatDa2004 of type ETAT_DA_2004
 *   EtatDaDyn of type ETAT_DA_DYN
 *   EtatDa2010 of type ETAT_DA_2010
 *   TrqLimitState of type TRQ_LIMIT_STATE
 *   SteerwhlHoldByDrv of type STEERWHL_HOLD_BY_DRV
 *   EpsStateLka of type EPS_STATE_LKA
 *   AutorArretMotDa of type AUTOR_ARRET_MOT_DA
 *   DdeRedemDa of type DDE_REDEM_DA
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
 * IS_DYN_VOL_MsgAdd: Record with elements
 *   EtatCaptVol of type ETAT_CAPT_VOL
 *   CalibrationVol of type CALIBRATION_VOL
 *   TrimVol of type TRIM_VOL
 *   CodeDefaultVol of type CODE_DEFAUT_VOL
 *   VitesseRotVolOptimise of type VITESSE_ROT_VOL_OPTIMISE
 *   AngleVolantOrigine of type ANGLE_VOLANT_ORIGINE
 *   FlgAvolIcn of type FLG_AVOL_ICN
 *   FlgInitAvol of type FLG_INIT_AVOL
 * IS_DYN_VOL_MsgBase: Record with elements
 *   AngleVolant of type ANGLE_VOLANT
 *   VitesseRotVol of type VITESSE_ROT_VOL
 *   SensRotVol of type SENS_ROT_VOL
 *   CptProcess4bAVol of type CPT_PROCESS_4B_A_VOL
 *   ChksumVol of type CHKSUM_VOL
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


#define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

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
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComDriver_Init1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_MultimodeSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_STTdSelected_Cnt_lgc(void)
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
	
	
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;
	
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
	BusOffTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BusActiveTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BusOffCounter_Cnt_M_u16 = 0u;
	CAVHCSelected_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_CAVHCSelected_Cnt_lgc();
	CityParkSelected_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_CityParkSelected_Cnt_lgc();
	STTdSelected_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_STTdSelected_Cnt_lgc();
	MultimodeSelected_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_MultimodeSelected_Cnt_lgc();
	ESCOffsCfgSeld_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc();
	LXASelected_Cnt_M_lgc = Rte_IRead_SrlComDriver_Init1_LXASelected_Cnt_lgc();

	IlRxStart();
	
	AppDesc_Init2();
	
	
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VVHType_Cnt_u08(UInt8 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AccelLat_Cnt_s16(SInt16 data)
 *   Std_ReturnType Rte_Write_AnneeEcoule_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ColumnAngleSetpoint_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_CompteurTemporelVehicule_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ComputerRazGCT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ConfigVhl_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DiagIntegraElec_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DiagMuxOn_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DmdDelestDA_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ESPDeconnecte_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EffacDefaultDiag_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatMT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatReseauElec_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATABR50DMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI572MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_ISDATDIRAMsgTxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 data)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNAASMsg_Cnt_u08(const UInt8 *data)
#else
 *   Std_ReturnType Rte_Write_ISDYNAASMsg_Cnt_u08(const CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Write_ISDYNAASMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNAASMsgRxTime_MSec_u32(UInt32 data)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNABRMsg_Cnt_u08(const UInt8 *data)
#else
 *   Std_ReturnType Rte_Write_ISDYNABRMsg_Cnt_u08(const CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Write_ISDYNABRMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNABRMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNVOLMsg_Cnt_u08(const UInt8 *data)
#else
 *   Std_ReturnType Rte_Write_ISDYNVOLMsg_Cnt_u08(const CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_JourEcoule_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_Kilometrage_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_LKAState_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_LKATrqFactReq_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_LXAActivation_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ModeDiag_Cnt_u08(UInt8 data)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const UInt8 *data)
#else
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_PowerSupplies_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_RegulABR_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_RegulESP_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ReqLampeDefEsp_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ReqModeDA_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_SecondeEcoulee_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ShuntPosition_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VitesseVehicleBV_Cnt_u16(UInt16 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DAT_DIRA_Get(IS_DAT_DIRA_Msg *IsDatDira)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DYN_VOL_Get(IS_DYN_VOL_MsgBase *IsDynVolBase, IS_DYN_VOL_MsgAdd *IsDynVolAdd)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_AvgFricLrnData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LearnedEOT_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_MotPosReset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_BusOff(void)
 *   void Rte_Exit_BusOff(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_Per1
 *********************************************************************************************************************/
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;    
	VAR(uint8,   AUTOMATIC) CPLEVOLANT_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ETATDA2004_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ETATDA2010_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) SystemCode_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DownloadDay_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DownloadMonth_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DownloadYear_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ApplicationCode_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) SoftwareVersion_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) SoftwareEditionMSB_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) SoftwareEditionLSB_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) BusOff_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TMFTestComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) FlashLogAValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) FlashLogBValid_Cnt_T_lgc;

	if (TRUE == ReInitializeComponent_M_lgc)
	{
		ReInitializeComponent_M_lgc = FALSE;
		SrlComDriver_ReInit();
	}

	ElectronicIntegration_Cnt_M_lgc = Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc();
	TMFTestComplete_Cnt_T_lgc = Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc();
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	
	/* Enable Tx */
	if( TxEnabledInit_Cnt_M_lgc == FALSE )
	{
		if( TMFTestComplete_Cnt_T_lgc == TRUE )
		{
			if( (ElectronicIntegration_Cnt_M_lgc == FALSE) &&
				(SystemState_Cnt_T_enum != RTE_MODE_StaMd_Mode_OFF) )
			{
				IlTxStart();
				TxEnabled_Cnt_M_lgc = TRUE;
				
				FlashLogAValid_Cnt_T_lgc = TestFlashLogValidity((NvM_BlockIdType)NVM_BLOCK_SER_FLASHLOGA, &FlashLogA_G_str);
				FlashLogBValid_Cnt_T_lgc = TestFlashLogValidity((NvM_BlockIdType)NVM_BLOCK_SER_FLASHLOGB, &FlashLogB_G_str);
				
				if( (FlashLogAValid_Cnt_T_lgc == TRUE) &&
					( (FlashLogBValid_Cnt_T_lgc == FALSE) ||
					  (FlashLogA_G_str.Count_Cnt_u16 > FlashLogB_G_str.Count_Cnt_u16) ) )
				{
					SystemCode_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[5u];
					DownloadDay_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[13u];
					DownloadMonth_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[14u];
					DownloadYear_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[15u];
					ApplicationCode_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[9u];
					SoftwareVersion_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[10u];
					SoftwareEditionMSB_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[11u];
					SoftwareEditionLSB_Cnt_T_u08 = FlashLogA_G_str.Data_Cnt_u08[12u];
				}
				else if( FlashLogBValid_Cnt_T_lgc == TRUE )
				{
					SystemCode_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[5u];
					DownloadDay_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[13u];
					DownloadMonth_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[14u];
					DownloadYear_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[15u];
					ApplicationCode_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[9u];
					SoftwareVersion_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[10u];
					SoftwareEditionMSB_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[11u];
					SoftwareEditionLSB_Cnt_T_u08 = FlashLogB_G_str.Data_Cnt_u08[12u];
				}
				else
				{
					SystemCode_Cnt_T_u08 = 0x6Au;
					DownloadDay_Cnt_T_u08 = D_MANUFDATEINIT_CNT_STR.Day_Cnt_u08;
					DownloadMonth_Cnt_T_u08 = D_MANUFDATEINIT_CNT_STR.Month_Cnt_u08;
					DownloadYear_Cnt_T_u08 = D_MANUFDATEINIT_CNT_STR.Year_Cnt_u08;
					ApplicationCode_Cnt_T_u08 = 1u;
					SoftwareVersion_Cnt_T_u08 = 0u;
					SoftwareEditionMSB_Cnt_T_u08 = 0xFFu;
					SoftwareEditionLSB_Cnt_T_u08 = 0x00u;
				}
				
				IlPutTxSystem_Code(SystemCode_Cnt_T_u08);
				IlPutTxDownload_Day(DownloadDay_Cnt_T_u08);
				IlPutTxDownload_Month(DownloadMonth_Cnt_T_u08);
				IlPutTxDownload_Year(DownloadYear_Cnt_T_u08);
				IlPutTxApplication_Code(ApplicationCode_Cnt_T_u08);
				IlPutTxSoftware_Version(SoftwareVersion_Cnt_T_u08);
				IlPutTxSoftware_Edition_MSB(SoftwareEditionMSB_Cnt_T_u08);
				IlPutTxSoftware_Edition_LSB(SoftwareEditionLSB_Cnt_T_u08);
			}
			
			TxEnabledInit_Cnt_M_lgc = TRUE;
		}
	}
	
	/* Bus Off */
	BusOff_Cnt_T_lgc = SrlComDriver_BusOff();
	
	TpTxTask();
	IlTxTask();
	CanTask();
	IlRxTask();
	TpRxTask();
	DescTask();
	AppDesc_Per1();
	EPSDiagSrvcs_Task();
	
	Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(BusOff_Cnt_T_lgc);

	Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(TxEnabled_Cnt_M_lgc);

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
	
	if( Rte_Mode_SystemState_Mode() != RTE_MODE_StaMd_Mode_OFF )
	{
		if( TxEnabledInit_Cnt_M_lgc == TRUE )
		{
			IlTxStop();
			TxEnabled_Cnt_M_lgc = FALSE;
		}
		
		(void)Dem_DisableEventStatusUpdate(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
	}
	
	ElectronicIntegration_Cnt_M_lgc = TRUE;
	
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
	
	if( Rte_Mode_SystemState_Mode() != RTE_MODE_StaMd_Mode_OFF )
	{
		if( TxEnabledInit_Cnt_M_lgc == TRUE )
		{
			IlTxStart();
			TxEnabled_Cnt_M_lgc = TRUE;
		}
		
		(void)Dem_EnableEventStatusUpdate(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
	}
	
	ElectronicIntegration_Cnt_M_lgc = FALSE;
	
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
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_BusOff(void)
 *   void Rte_Exit_BusOff(void)
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

	/* Access to BusOffCounter_Cnt_M_u16 is atomic. No Exclusive area required */
	/* Rte_Enter_BusOff(); */
	*BusOffCounter_Cnt_T_u16 = BusOffCounter_Cnt_M_u16;
	/* Rte_Exit_BusOff(); */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_SendMsgOnChange
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendMsgOnChange> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_SendMsgOnChange(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_SendMsgOnChange(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComDriver_SCom_SendMsgOnChange
 *********************************************************************************************************************/

	SrlComDriver_SendIsSupvDira();

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
	
	if( (TxEnabledInit_Cnt_M_lgc == TRUE) &&
		(ElectronicIntegration_Cnt_M_lgc == FALSE) )
	{
		IlTxStart();
		TxEnabled_Cnt_M_lgc = TRUE;
	}
	ReInitializeComponent_M_lgc = TRUE;
	
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
	
	if( (TxEnabledInit_Cnt_M_lgc == TRUE) &&
		(ElectronicIntegration_Cnt_M_lgc == FALSE) )
	{
		IlTxStop();
		TxEnabled_Cnt_M_lgc = FALSE;
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC FUNC(void, CDD_SRLCOMDRIVER_CODE) SrlComDriver_ReInit(void)
{
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
	if (FALSE == BusOffEvent_Cnt_M_lgc)
	{
		BusOffTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BusActiveTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BusOffCounter_Cnt_M_u16 = 0u;
	}

	ISDATDIRAMsgTxTime_MSec_M_u32 = 0u;
	ISDYNDAEMsgCount_Cnt_M_u08 = 0u;
	ISDYNVOLMsgCount_Cnt_M_u08 = 0u;
	ISDAT4V2BSI552MsgDLCError_Cnt_M_u08 = 0u;
	ISDATBSI3F2MsgDLCError_Cnt_M_u08 = 0u;
	ISDATBSI412MsgDLCError_Cnt_M_u08 = 0u;
	ISDATBSI432MsgDLCError_Cnt_M_u08 = 0u;
	ISDYN2CMMMsgDLCError_Cnt_M_u08 = 0u;
	ISDYNAASMsgDLCError_Cnt_M_u08 = 0u;
	ISDYNABRMsgDLCError_Cnt_M_u08 = 0u;
	ISDYNCMM208MsgDLCError_Cnt_M_u08 = 0u;
	ISDYNCMM388MsgDLCError_Cnt_M_u08 = 0u;
	ISDYNVOLMsgDLCError_Cnt_M_u08 = 0u;
	ISDYN2FRE3CDMsgDLCError_Cnt_M_u08 = 0u;
	ISDYNCDS34DMsgDLCError_Cnt_M_u08 = 0u;
	ISDATABR50DMsgDLCError_Cnt_M_u08 = 0u;
	ISDATBSI572MsgDLCError_Cnt_M_u08 = 0u;
	PROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08 = 0u;
	TxEnabledInit_Cnt_M_lgc = FALSE;
	ISDATDIRAMsgTxInProgress_Cnt_M_lgc = FALSE;
	/* TxEnabled_Cnt_M_lgc; */	/* Handled by the transition tasks already */
	ElectronicIntegration_Cnt_M_lgc = FALSE;
	(void)Rte_Write_AccelLat_Cnt_s16(Rte_InitValue_AccelLat_Cnt_s16);
	(void)Rte_Write_AnneeEcoule_Cnt_u08(Rte_InitValue_AnneeEcoule_Cnt_u08);
	Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Rte_InitValue_BusOff_Cnt_lgc);
	(void)Rte_Write_ColumnAngleSetpoint_Cnt_u16(Rte_InitValue_ColumnAngleSetpoint_Cnt_u16);
	(void)Rte_Write_CompteurTemporelVehicule_Cnt_u32(Rte_InitValue_CompteurTemporelVehicule_Cnt_u32);
	(void)Rte_Write_ComputerRazGCT_Cnt_u08(Rte_InitValue_ComputerRazGCT_Cnt_u08);
	(void)Rte_Write_ConfigVhl_Cnt_u08(Rte_InitValue_ConfigVhl_Cnt_u08);
	(void)Rte_Write_DiagIntegraElec_Cnt_u08(Rte_InitValue_DiagIntegraElec_Cnt_u08);
	(void)Rte_Write_DiagMuxOn_Cnt_u08(Rte_InitValue_DiagMuxOn_Cnt_u08);
	(void)Rte_Write_DmdDelestDA_Cnt_u08(Rte_InitValue_DmdDelestDA_Cnt_u08);
	(void)Rte_Write_ESPDeconnecte_Cnt_u08(Rte_InitValue_ESPDeconnecte_Cnt_u08);
	(void)Rte_Write_EffacDefaultDiag_Cnt_u08(Rte_InitValue_EffacDefaultDiag_Cnt_u08);
	(void)Rte_Write_EtatMT_Cnt_u08(Rte_InitValue_EtatMT_Cnt_u08);
	(void)Rte_Write_EtatPrincipSev_Cnt_u08(Rte_InitValue_EtatPrincipSev_Cnt_u08);
	(void)Rte_Write_EtatReseauElec_Cnt_u08(Rte_InitValue_EtatReseauElec_Cnt_u08);
	(void)Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08(Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32(Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08(Rte_InitValue_ISDATABR50DMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDATABR50DMsgRxTime_MSec_u32(Rte_InitValue_ISDATABR50DMsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDATBSI412MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDATBSI432MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08(Rte_InitValue_ISDATBSI572MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDATBSI572MsgRxTime_MSec_u32(Rte_InitValue_ISDATBSI572MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc(Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc);
	(void)Rte_Write_ISDATDIRAMsgTxTime_MSec_u32(Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32);
	(void)Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08(Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32(Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32);
	(void)Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08(Rte_InitValue_ISDYN2FRE3CDMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32(Rte_InitValue_ISDYN2FRE3CDMsgRxTime_MSec_u32);
	/*(void)Rte_Write_ISDYNAASMsg_Cnt_u08(const CanMsgType *data);*/ /* Will get updated when it comes, right before it will be used */
	(void)Rte_Write_ISDYNAASMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNAASMsgRxTime_MSec_u32(Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32);
	/*(void)Rte_Write_ISDYNABRMsg_Cnt_u08(const CanMsgType *data);*/ /* Will get updated when it comes, right before it will be used */
	(void)Rte_Write_ISDYNABRMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNABRMsgRxTime_MSec_u32(Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32);
	(void)Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCDS34DMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32(Rte_InitValue_ISDYNCDS34DMsgRxTime_MSec_u32);
	(void)Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32(Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32);
	(void)Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08(Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32(Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32);
	/*(void)Rte_Write_ISDYNVOLMsg_Cnt_u08(const CanMsgType *data);*/ /* Will get updated when it comes, right before it will be used */
	(void)Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08(Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08);
	(void)Rte_Write_ISDYNVOLMsgRxTime_MSec_u32(Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32);
	(void)Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32(Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32);
	(void)Rte_Write_JourEcoule_Cnt_u16(Rte_InitValue_JourEcoule_Cnt_u16);
	(void)Rte_Write_Kilometrage_Cnt_u32(Rte_InitValue_Kilometrage_Cnt_u32);
	(void)Rte_Write_LKAState_Cnt_u08(Rte_InitValue_LKAState_Cnt_u08);
	(void)Rte_Write_LKATrqFactReq_Cnt_u08(Rte_InitValue_LKATrqFactReq_Cnt_u08);
	(void)Rte_Write_LXAActivation_Cnt_u08(Rte_InitValue_LXAActivation_Cnt_u08);
	(void)Rte_Write_ModeDiag_Cnt_u08(Rte_InitValue_ModeDiag_Cnt_u08);
	/*(void)Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const CanMsgType *data);*/ /* Will get updated when it comes, right before it will be used */
	(void)Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08);
	(void)Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32);
	(void)Rte_Write_PowerSupplies_Cnt_u08(Rte_InitValue_PowerSupplies_Cnt_u08);
	(void)Rte_Write_RegulABR_Cnt_u08(Rte_InitValue_RegulABR_Cnt_u08);
	(void)Rte_Write_RegulESP_Cnt_u08(Rte_InitValue_RegulESP_Cnt_u08);
	(void)Rte_Write_ReqLampeDefEsp_Cnt_u08(Rte_InitValue_ReqLampeDefEsp_Cnt_u08);
	(void)Rte_Write_ReqModeDA_Cnt_u08(Rte_InitValue_ReqModeDA_Cnt_u08);
	(void)Rte_Write_SecondeEcoulee_Cnt_u32(Rte_InitValue_SecondeEcoulee_Cnt_u32);
	(void)Rte_Write_ShuntPosition_Cnt_u08(Rte_InitValue_ShuntPosition_Cnt_u08);
	Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Rte_InitValue_TxEnabled_Cnt_lgc);
	(void)Rte_Write_VitesseVehicleBV_Cnt_u16(Rte_InitValue_VitesseVehicleBV_Cnt_u16);
}

STATIC FUNC(boolean, CD_SRLCOMDRIVER_CODE) SrlComDriver_BusOff(void)
{
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) BusOff_Cnt_T_lgc;

	Rte_Enter_BusOff(); /* Prevent preemption by ApplCanBusOff() */
	if (TRUE == BusOffEvent_Cnt_M_lgc)
	{
		if(( D_BUSOFF_NTC_LIMIT_CNT_U16 <= BusOffCounter_Cnt_M_u16 ) &&
		   ( FALSE == ElectronicIntegration_Cnt_M_lgc ))
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1, 0u, NTC_STATUS_FAILED);
		}

		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusOffTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if( (D_BUSOFF_RECOVERY_TIME_LONG_MS_U16 <= ElapsedTime_mS_T_u16)		||
			( (D_BUSOFF_RECOVERY_TIME_SHORT_MS_U16 <= ElapsedTime_mS_T_u16) &&
			  (BusOffCounter_Cnt_M_u16 < D_BUSOFF_RECOVERY_LIMIT_CNT_U16)		) )
		{
			GetSystemTime_mS_u32(&BusActiveTimer_mS_M_u32);
			BusOffEvent_Cnt_M_lgc = FALSE;

			CanStart();
			CanResetBusOffEnd(kCanInitObj1); /* PRQA S 3138 */ /* This implementation is 3rd party code. I was reviewed and it's fine */
			CanOnline();
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusActiveTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if( k_BusOffTimeout_mS_u16 <= ElapsedTime_mS_T_u16 )
		{
			BusOffCounter_Cnt_M_u16 = 0u;
			if( FALSE == ElectronicIntegration_Cnt_M_lgc )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1, 0u, NTC_STATUS_PASSED);
			}
		}
	}

	if( BusOffCounter_Cnt_M_u16 > 0u )
	{
		BusOff_Cnt_T_lgc = TRUE;
	}
	else
	{
		BusOff_Cnt_T_lgc = FALSE;
	}
	Rte_Exit_BusOff();

	return BusOff_Cnt_T_lgc;
}

FUNC(void, CD_SRLCOMDRIVER_CODE) ApplCanBusOff(void)
{
	/* This callback is called from CAN ISR and has highest
	 * priority of all code related to Bus Off.
	 * No Exclusive Area required */
	/* Rte_Enter_BusOff(); */
	if( FALSE == BusOffEvent_Cnt_M_lgc )
	{
		CanOffline();
		CanResetBusOffStart((uint16)kCanInitObj1);
		CanStop();

		GetSystemTime_mS_u32(&BusOffTimer_mS_M_u32);

		if( D_BUSOFF_COUNTER_LIMIT_CNT_U16 > BusOffCounter_Cnt_M_u16 )
		{
			BusOffCounter_Cnt_M_u16++;
		}

		BusOffEvent_Cnt_M_lgc = TRUE;
	}
	/* Rte_Exit_BusOff(); */
}

FUNC(void, CD_SRLCOMDRIVER_CODE) ApplIlTxStart(void)
{
    if(ESCOffsCfgSeld_Cnt_M_lgc == FALSE)
    {
        /* Stop transmitting IS_DYN_VOL  305  when Turns counter not selected */
        (void)IlStopCycle((uint8)IlTxMsgHndIS_DYN_VOL);
    }
}

FUNC(void, CD_SRLCOMDRIVER_CODE) ApplCanMsgDlcFailed(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) VVHType_Cnt_t_u08;
	GetSystemTime_mS_u32(&time_Cnt_T_u32);

	switch( rxStruct->Handle )
	{
		case (uint16)CanRxIS_DYN_VOL:
            if(CAVHCSelected_Cnt_M_lgc == TRUE)
            {
                ISDYNVOLMsgDLCError_Cnt_M_u08++;
            	(void)Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08(ISDYNVOLMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
            	(void)Rte_Write_ISDYNVOLMsgRxTime_MSec_u32(time_Cnt_T_u32);
            }
			break;
		
		case (uint16)CanRxIS_DYN_CMM_388:
			(void)Rte_Read_VVHType_Cnt_u08(&VVHType_Cnt_t_u08);
			if (VVHType_Cnt_t_u08 < 2u)
			{
				ISDYNCMM388MsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08(ISDYNCMM388MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
			break;
		
		case (uint16)CanRxIS_DYN_CMM_208:
			ISDYNCMM208MsgDLCError_Cnt_M_u08++;
			(void)Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08(ISDYNCMM208MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32(time_Cnt_T_u32);
			break;
		
		case (uint16)CanRxIS_DYN2_CMM_348:
			ISDYN2CMMMsgDLCError_Cnt_M_u08++;
			(void)Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08(ISDYN2CMMMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32(time_Cnt_T_u32);
			break;
		
		case (uint16)CanRxIS_DYN_ABR:
			ISDYNABRMsgDLCError_Cnt_M_u08++;
			(void)Rte_Write_ISDYNABRMsgDLCError_Cnt_u08(ISDYNABRMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ISDYNABRMsgRxTime_MSec_u32(time_Cnt_T_u32);
			break;
		
		case (uint16)CanRxIS_DYN_AAS:
			if (TRUE == CityParkSelected_Cnt_M_lgc)
			{
				ISDYNAASMsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDYNAASMsgDLCError_Cnt_u08(ISDYNAASMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDYNAASMsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
			break;
		
		case (uint16)CanRxIS_DAT4_V2_BSI_552:
			ISDAT4V2BSI552MsgDLCError_Cnt_M_u08++;
			(void)Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08(ISDAT4V2BSI552MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32(time_Cnt_T_u32);
			break;
		
		case (uint16)CanRxIS_DAT_BSI_3F2:
			if ((TRUE == LXASelected_Cnt_M_lgc) || (TRUE == STTdSelected_Cnt_M_lgc))
			{
				ISDATBSI3F2MsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08(ISDATBSI3F2MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
			break;
		
		case (uint16)CanRxIS_DAT_BSI_412:
			if (TRUE == MultimodeSelected_Cnt_M_lgc)
			{
				ISDATBSI412MsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08(ISDATBSI412MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDATBSI412MsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
			break;
		
		case (uint16)CanRxIS_DAT_BSI_432:
			if (TRUE == k_JDD2010Selected_Cnt_lgc)
			{
				ISDATBSI432MsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08(ISDATBSI432MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDATBSI432MsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
			break;
            
        case (uint16)CanRxIS_DYN2_FRE_3CD:
			(void)Rte_Read_VVHType_Cnt_u08(&VVHType_Cnt_t_u08);
			if (2u == VVHType_Cnt_t_u08)
			{
				ISDYN2FRE3CDMsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08(ISDYN2FRE3CDMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
            break;
            
        case (uint16)CanRxIS_DYN_CDS_34D:
			if (TRUE == LXASelected_Cnt_M_lgc)
			{
				ISDYNCDS34DMsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08(ISDYNCDS34DMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
            break;
		
        case (uint16)CanRxIS_DAT_ABR_50D:
			if (TRUE == LXASelected_Cnt_M_lgc)
			{
				ISDATABR50DMsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08(ISDATABR50DMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDATABR50DMsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
            break;
            
		case (uint16)CanRxIS_DAT_BSI_572:   
			if(TRUE == ESCOffsCfgSeld_Cnt_M_lgc) /* Receive only when Turns counter selected */
			{
				ISDATBSI572MsgDLCError_Cnt_M_u08++;
				(void)Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08(ISDATBSI572MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
				(void)Rte_Write_ISDATBSI572MsgRxTime_MSec_u32(time_Cnt_T_u32);
			}
        	break;
		case (uint16)CanRxPROTO_HS1_DYN_UCF_5CD:
            if(TRUE == ESCOffsCfgSeld_Cnt_M_lgc) /* Receive only when Turns counter selected */
            {
                 PROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08++;

                 (void)Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(PROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
                 (void)Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(time_Cnt_T_u32);
            }                 
        	break;
		default:
			/* do nothing */
			break;
	}
}

void ApplCanAddCanInterruptDisable(CanChannelHandle channel)
{
    DisableCan1Interrupt();
}

void ApplCanAddCanInterruptRestore(CanChannelHandle channel)
{
    EnableCan1Interrupt();
}

FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxISDYNVOL(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) i;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	VAR(CanMsgType, AUTOMATIC) ISDYNVOLMsg_Cnt_T_u08;

    if(CAVHCSelected_Cnt_M_lgc == TRUE)
    {	
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

        DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be mixed */
        
        for( i = 0u; i < DLC_Cnt_T_u08; i++ )
        {
            ISDYNVOLMsg_Cnt_T_u08[i] = rxStruct->pChipData[i]; /* PRQA S 491 */
        }
        
        for( ; i < 8u; i++ )
        {
            ISDYNVOLMsg_Cnt_T_u08[i] = 0u;
        }

        (void)Rte_Write_ISDYNVOLMsg_Cnt_u08((const CanMsgType *)(&ISDYNVOLMsg_Cnt_T_u08));
        (void)Rte_Write_ISDYNVOLMsgRxTime_MSec_u32(time_Cnt_T_u32);
    }
	
	return kCanNoCopyData;
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDYNCMM388(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint16, AUTOMATIC) VitesseVehicleBV_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) VVHType_Cnt_t_u08;

	(void)Rte_Read_VVHType_Cnt_u08(&VVHType_Cnt_t_u08);
	if (VVHType_Cnt_t_u08 < 2u)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		VitesseVehicleBV_Cnt_T_u16 = IlGetRxVITESSE_VEHICLE_BV();

		(void)Rte_Write_VitesseVehicleBV_Cnt_u16(VitesseVehicleBV_Cnt_T_u16); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}

void SrlComDriver_RxISDATABR50D(CanReceiveHandle rcvObject)
{
	VAR(uint8, AUTOMATIC) RegulABR_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	if (TRUE == LXASelected_Cnt_M_lgc)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		RegulABR_Cnt_T_u08 = IlGetRxRegul_ABR();

		(void)Rte_Write_RegulABR_Cnt_u08(RegulABR_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_ISDATABR50DMsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}

void SrlComDriver_RxISDYN2FRE3CD(CanReceiveHandle rcvObject)
{
	VAR(sint16, AUTOMATIC) AccelLat_Cnt_T_s16;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) VVHType_Cnt_t_u08;

	(void)Rte_Read_VVHType_Cnt_u08(&VVHType_Cnt_t_u08);
	if (2u == VVHType_Cnt_t_u08)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		AccelLat_Cnt_T_s16 = (sint16)IlGetRxAccel_Lat();

		(void)Rte_Write_AccelLat_Cnt_s16(AccelLat_Cnt_T_s16); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}

void SrlComDriver_RxISDYNCDS34D(CanReceiveHandle rcvObject)
{
	VAR(uint8, AUTOMATIC) ReqLampeDefESP_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) RegulESP_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ESPDeconnecte_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	if (TRUE == LXASelected_Cnt_M_lgc)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		ReqLampeDefESP_Cnt_T_u08 = IlGetRxREQ_Lampe_DEF_ESP();
		RegulESP_Cnt_T_u08 = IlGetRxRegul_ESP();
		ESPDeconnecte_Cnt_T_u08 = IlGetRxESP_Deconnecte();

		(void)Rte_Write_ReqLampeDefEsp_Cnt_u08(ReqLampeDefESP_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_RegulESP_Cnt_u08(RegulESP_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_ESPDeconnecte_Cnt_u08(ESPDeconnecte_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */

		(void)Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}

FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDYNCMM208(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) DiagMuxOn_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	GetSystemTime_mS_u32(&time_Cnt_T_u32);

	DiagMuxOn_Cnt_T_u08 = IlGetRxDIAG_MUX_ON();

	(void)Rte_Write_DiagMuxOn_Cnt_u08(DiagMuxOn_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
	(void)Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32(time_Cnt_T_u32);
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDYN2CMM(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR (uint8, AUTOMATIC) EtatMT_Cnt_T_u08;
	VAR (uint32, AUTOMATIC) time_Cnt_T_u32;

	GetSystemTime_mS_u32(&time_Cnt_T_u32);
	EtatMT_Cnt_T_u08 = IlGetRxETAT_MT();

	(void)Rte_Write_EtatMT_Cnt_u08(EtatMT_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
	(void)Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32(time_Cnt_T_u32);
}


FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxISDYNABR(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) i;
	VAR(CanMsgType, AUTOMATIC) ISDYNABRMsg_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	GetSystemTime_mS_u32(&time_Cnt_T_u32);

	DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be fixed */

	for( i = 0u; i < DLC_Cnt_T_u08; i++ )
	{
		ISDYNABRMsg_Cnt_T_u08[i] = rxStruct->pChipData[i]; /* PRQA S 491 */
	}

	for( ; i < 8u; i++ )
	{
		ISDYNABRMsg_Cnt_T_u08[i] = 0u;
	}

	(void)Rte_Write_ISDYNABRMsg_Cnt_u08((const CanMsgType *)(&ISDYNABRMsg_Cnt_T_u08));
	(void)Rte_Write_ISDYNABRMsgRxTime_MSec_u32(time_Cnt_T_u32);

	return kCanNoCopyData;
}


FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxISDYNAAS(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) i;
	VAR(CanMsgType, AUTOMATIC) ISDYNAASMsg_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	
	if (TRUE == CityParkSelected_Cnt_M_lgc)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be fixed */

		for( i = 0u; i < DLC_Cnt_T_u08; i++ )
		{
			ISDYNAASMsg_Cnt_T_u08[i] = rxStruct->pChipData[i]; /* PRQA S 491 */
		}

		for( ; i < 8u; i++ )
		{
			ISDYNAASMsg_Cnt_T_u08[i] = 0u;
		}

		(void)Rte_Write_ISDYNAASMsg_Cnt_u08((const CanMsgType *)(&ISDYNAASMsg_Cnt_T_u08));
		(void)Rte_Write_ISDYNAASMsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
	return kCanNoCopyData;
}

/* TODO: 	This function shall only check DLC and return kCan(No)CopyData.
 *			There should be implemented Rx handler. Maybe problem is in checking DLC on Rx handler level? */
FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxISDAT4V2BSI552(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) Msg552_Cnt_T_u08[8u];
	VAR(uint8, AUTOMATIC) i;
	VAR(uint8, AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(uint32,AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) ComputerRazGCT_Cnt_T_u08;

	VAR(uint16, AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) Kilometrage_Cnt_T_u32;

	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
	
	GetSystemTime_mS_u32(&time_Cnt_T_u32);

	DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be fixed */

	for( i = 0u; i < DLC_Cnt_T_u08; i++ )
	{
		Msg552_Cnt_T_u08[i] = rxStruct->pChipData[i]; /* PRQA S 491 */
	}

	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		if( DLC_Cnt_T_u08 < 8u )
		{
			ISDAT4V2BSI552MsgDLCError_Cnt_M_u08++;
			(void)Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08(ISDAT4V2BSI552MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		}
		else
		{
			CompteurTemporelVehicule_Cnt_T_u32 = (uint32)( (((uint32)Msg552_Cnt_T_u08[0u]) << 24) |
														   (((uint32)Msg552_Cnt_T_u08[1u]) << 16) |
														   (((uint32)Msg552_Cnt_T_u08[2u]) <<  8) |
														   ((uint32)Msg552_Cnt_T_u08[3u]) );

			Kilometrage_Cnt_T_u32 = (uint32)( (((uint32)Msg552_Cnt_T_u08[4u]) << 16) |
											  (((uint32)Msg552_Cnt_T_u08[5u]) <<  8) |
											  ((uint32)Msg552_Cnt_T_u08[6u]) );

			ComputerRazGCT_Cnt_T_u08 = Msg552_Cnt_T_u08[7u];


			(void)Rte_Write_CompteurTemporelVehicule_Cnt_u32(CompteurTemporelVehicule_Cnt_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_Kilometrage_Cnt_u32(Kilometrage_Cnt_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ComputerRazGCT_Cnt_u08(ComputerRazGCT_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		}
	}
	else
	{
		SecondeEcoulee_Cnt_T_u32 = (uint32)( (((uint32)Msg552_Cnt_T_u08[0u]) << 12) |
											 (((uint32)Msg552_Cnt_T_u08[1u]) <<  4) |
											 ((((uint32)Msg552_Cnt_T_u08[2u]) & 0xF0ul) >> 4) );

		JourEcoule_Cnt_T_u16 = (uint16)( ((((uint16)Msg552_Cnt_T_u08[2u]) & 0x0Fu) << 8) |
										 ((uint16)Msg552_Cnt_T_u08[3u]) );

		AnneeEcoule_Cnt_T_u08 = Msg552_Cnt_T_u08[4u];

		(void)Rte_Write_SecondeEcoulee_Cnt_u32(SecondeEcoulee_Cnt_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_JourEcoule_Cnt_u16(JourEcoule_Cnt_T_u16); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_AnneeEcoule_Cnt_u08(AnneeEcoule_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
	}

	(void)Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32(time_Cnt_T_u32); /* Set as last because it's a trigger */

	return kCanNoCopyData;
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDATBSI3F2(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) DmdDelestDA_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) LKAState_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) LXAActivation_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) LKATrqFactReq_Cnt_T_u08;
	VAR(uint16,AUTOMATIC) ColumnAngleSetpoint_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	if ((TRUE == STTdSelected_Cnt_M_lgc) || (TRUE == LXASelected_Cnt_M_lgc))
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		if (TRUE == STTdSelected_Cnt_M_lgc)
		{
            DmdDelestDA_Cnt_T_u08 = IlGetRxDMD_DELEST_DA();
            (void)Rte_Write_DmdDelestDA_Cnt_u08(DmdDelestDA_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		}

		if (TRUE == LXASelected_Cnt_M_lgc)
		{
			LKAState_Cnt_T_u08 = IlGetRxLKA_STATE();
			LKATrqFactReq_Cnt_T_u08 = IlGetRxLKA_TRQ_FACT_REQ();
			LXAActivation_Cnt_T_u08 = IlGetRxLXA_ACTIVATION();
			ColumnAngleSetpoint_Cnt_T_u16 = IlGetRxCOLUMN_ANGLE_SETPOINT();

			(void)Rte_Write_LKAState_Cnt_u08(LKAState_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_LKATrqFactReq_Cnt_u08(LKATrqFactReq_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_LXAActivation_Cnt_u08(LXAActivation_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
			(void)Rte_Write_ColumnAngleSetpoint_Cnt_u16(ColumnAngleSetpoint_Cnt_T_u16); /* PRQA S 3417 */ /* PRQA S 3426 */
		}

		(void)Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}

FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxISDATBSI(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(vuint8, AUTOMATIC) ContinueCanCopy;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;
    GetSystemTime_mS_u32(&time_Cnt_T_u32);
	
	DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be mixed */

    if ( (TRUE == LXASelected_Cnt_M_lgc) && (DLC_Cnt_T_u08 < 8u) )
    {
        ISDATBSI3F2MsgDLCError_Cnt_M_u08++;
		(void)Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08(ISDATBSI3F2MsgDLCError_Cnt_M_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		/* This signal triggers message processing on SrlComInput level.
		 * Usually it's called from Rx handle but in this case there
		 * will be no Rx handler called so then trigger should come from here */
		(void)Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(time_Cnt_T_u32);

		ContinueCanCopy = kCanNoCopyData;
    }
    else
    {
        ContinueCanCopy = kCanCopyData;
    }
    
	return ContinueCanCopy;
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDATBSI412(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) ReqModeDA_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	if (TRUE == MultimodeSelected_Cnt_M_lgc)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		ReqModeDA_Cnt_T_u08 = IlGetRxReq_Mode_DA();

		(void)Rte_Write_ReqModeDA_Cnt_u08(ReqModeDA_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_ISDATBSI412MsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDATBSI432(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) ShuntPosition_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PowerSupplies_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EtatPrincipSev_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EtatReseauElec_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) time_Cnt_T_u32;

	if (TRUE == k_JDD2010Selected_Cnt_lgc)
	{
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		ShuntPosition_Cnt_T_u08 = IlGetRxShunt_Position();
		PowerSupplies_Cnt_T_u08 = IlGetRxPower_Supplies();
		EtatPrincipSev_Cnt_T_u08 = IlGetRxETAT_PRINCIP_SEV();
		EtatReseauElec_Cnt_T_u08 = IlGetRxETAT_RESEAU_ELEC();

		(void)Rte_Write_ShuntPosition_Cnt_u08(ShuntPosition_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_PowerSupplies_Cnt_u08(PowerSupplies_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_EtatPrincipSev_Cnt_u08(EtatPrincipSev_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
		(void)Rte_Write_EtatReseauElec_Cnt_u08(EtatReseauElec_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */

		(void)Rte_Write_ISDATBSI432MsgRxTime_MSec_u32(time_Cnt_T_u32);
	}
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISINTEELECTRONBSI(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{
	VAR(uint8, AUTOMATIC) EffacDefaultDiag_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ModeDiag_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DiagIntegraElec_Cnt_T_u08;

	VAR (uint32, AUTOMATIC) time_Cnt_T_u32;
	GetSystemTime_mS_u32(&time_Cnt_T_u32);

	EffacDefaultDiag_Cnt_T_u08 = IlGetRxEFFAC_DEFAULT_DIAG();
	ModeDiag_Cnt_T_u08 = IlGetRxMODE_DIAG();
	DiagIntegraElec_Cnt_T_u08 = IlGetRxDIAG_INTEGRA_ELEC();

	(void)Rte_Write_EffacDefaultDiag_Cnt_u08(EffacDefaultDiag_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
	(void)Rte_Write_ModeDiag_Cnt_u08(ModeDiag_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
	(void)Rte_Write_DiagIntegraElec_Cnt_u08(DiagIntegraElec_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */

	(void)Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32(time_Cnt_T_u32);
}


FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreTxISDATDIRA(CanTxInfoStruct ctis)
{
	VAR (IS_DAT_DIRA_Msg, AUTOMATIC) IsDatDiraMsg;

	if( ISDATDIRAMsgTxInProgress_Cnt_M_lgc == FALSE )
	{
		(void)Rte_Call_IS_DAT_DIRA_Get(&IsDatDiraMsg); /* PRQA S 3417 */ /* PRQA S 3426 */

        IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.CPLE_VOLANT 		= (uint8)IsDatDiraMsg.CpleVolant;
        IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.ETAT_DA_2004 		= IsDatDiraMsg.EtatDa2004;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.ETAT_DA_2010 		= IsDatDiraMsg.EtatDa2010;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.ETAT_DA_DYN 		= IsDatDiraMsg.EtatDaDyn;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.DDE_REDEM_DA 		= IsDatDiraMsg.DdeRedemDa;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.AUTOR_ARRET_MOT_DA 	= IsDatDiraMsg.AutorArretMotDa;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.EPS_STATE_LKA 		= IsDatDiraMsg.EpsStateLka;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.STEERWHL_HOLD_BY_DRV= IsDatDiraMsg.SteerwhlHoldByDrv;
		IS_DAT_DIRA_Group.IS_DAT_DIRA_Group.TRQ_LIMIT_STATE 	= IsDatDiraMsg.TrqLimitState;

		(void)IlPutTxIS_DAT_DIRA_Group();

		ISDATDIRAMsgTxInProgress_Cnt_M_lgc = TRUE;

		(void)Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc(ISDATDIRAMsgTxInProgress_Cnt_M_lgc); /* PRQA S 3417 */ /* PRQA S 3426 */
	}
	
	return kCanCopyData;
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_TxISDATDIRA(CanTransmitHandle txObject)
{
	GetSystemTime_mS_u32(&ISDATDIRAMsgTxTime_MSec_M_u32);
	ISDATDIRAMsgTxInProgress_Cnt_M_lgc = FALSE;
	(void)Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc(ISDATDIRAMsgTxInProgress_Cnt_M_lgc); /* PRQA S 3417 */ /* PRQA S 3426 */
	(void)Rte_Write_ISDATDIRAMsgTxTime_MSec_u32(ISDATDIRAMsgTxTime_MSec_M_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
}


FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreTxISDYNDAE(CanTxInfoStruct ctis)
{
	VAR(IS_DYN_DAE_Msg, AUTOMATIC) IsDynDaeMsg;
	VAR(uint8, AUTOMATIC) CheckSum_Cnt_T_u08;

	(void)Rte_Call_IS_DYN_DAE_Get(&IsDynDaeMsg); /* PRQA S 3417 */ /* PRQA S 3426 */

	ISDYNDAEMsgCount_Cnt_M_u08 = (ISDYNDAEMsgCount_Cnt_M_u08 + 1u) & 0x0Fu;

	IS_DYN_DAE_Group.IS_DYN_DAE_Group.CPT_PROCESS_4B_DAE = ISDYNDAEMsgCount_Cnt_M_u08;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.CPLE_VOLANT_OPTMSE = (uint8)IsDynDaeMsg.CpleVolantOptimse;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.ETAT_DAE_CPK = IsDynDaeMsg.EtatDaeCpk;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.CAUSE_DESACTIV_CPK = IsDynDaeMsg.CauseDesactivCpk;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.ANGLE_COLONNE_0 = (uint8)((uint16)IsDynDaeMsg.AngleColonne >> 0); /* PRQA S 2985 */
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.ANGLE_COLONNE_1 = (uint8)((uint16)IsDynDaeMsg.AngleColonne >> 8);
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.VITESSE_COLONNE_0 = (uint8)((uint16)IsDynDaeMsg.VitesseColonne >> 0) & 0x0Fu; /* PRQA S 2985 */
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.VITESSE_COLONNE_1 = (uint8)((uint16)IsDynDaeMsg.VitesseColonne >> 4) & 0xFFu; /* PRQA S 2985 */
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.ETAT_DAE_CAV3_VIRTUEL = IsDynDaeMsg.EtatDaeCav3Virtuel;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.ETAT_SECU_ANGLE_COL = IsDynDaeMsg.EtatSecuAngleCol;
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.CHKSUM_TRME_DYN_DAE = 4u;	/* TODO: Should be replaced with define coming from COM stack/CANdb */

	CheckSum_Cnt_T_u08 =
			(IS_DYN_DAE_Group._c[0] & 0x0Fu) + ((IS_DYN_DAE_Group._c[0] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[1] & 0x0Fu) + ((IS_DYN_DAE_Group._c[1] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[2] & 0x0Fu) + ((IS_DYN_DAE_Group._c[2] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[3] & 0x0Fu) + ((IS_DYN_DAE_Group._c[3] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[4] & 0x0Fu) + ((IS_DYN_DAE_Group._c[4] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[5] & 0x0Fu) + ((IS_DYN_DAE_Group._c[5] >> 4) & 0x0Fu) + /* PRQA S 2985 */
			(IS_DYN_DAE_Group._c[6] & 0x0Fu) + ((IS_DYN_DAE_Group._c[6] >> 4) & 0x0Fu); /* PRQA S 2985 */
	
	IS_DYN_DAE_Group.IS_DYN_DAE_Group.CHKSUM_TRME_DYN_DAE = (CheckSum_Cnt_T_u08 & 0x0Fu) ^ 0x0Fu;
	
	(void)IlPutTxIS_DYN_DAE_Group();
	return kCanCopyData;
}


STATIC FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_SendIsSupvDira(void)
{
	VAR(IS_SUPV_DIRA_Msg, AUTOMATIC) IsSupvDira;

	(void)Rte_Call_IS_SUPV_DIRA_Get(&IsSupvDira); /* PRQA S 3417 */ /* PRQA S 3426 */

	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.CODE_DEFAUT 			= IsSupvDira.CodeDefaut;
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.STATUS_CONFABSENT_0 	= (uint8)(IsSupvDira.StatusConfabsent >>  0); /* PRQA S 2985 */
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.STATUS_CONFABSENT_1 	= (uint8)(IsSupvDira.StatusConfabsent >>  8);
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.STATUS_CONFABSENT_2 	= (uint8)(IsSupvDira.StatusConfabsent >> 16);
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.STATUS_CONFABSENT_3 	= (uint8)(IsSupvDira.StatusConfabsent >> 24);
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.ETAT_LIGNE_APC 		= IsSupvDira.EtatLigneApc;
	IS_SUPV_DIRA_Group.IS_SUPV_DIRA_Group.ETAT_ASSIST_DA 		= IsSupvDira.EtatAssistDa;
	(void)IlPutTxIS_SUPV_DIRA_Group();
}


FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreTxISSUPVDIRA(CanTxInfoStruct ctis)
{
	SrlComDriver_SendIsSupvDira();

	return kCanCopyData;
}


FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_TxISDYNDAE(CanTransmitHandle txObject)
{

}

FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreRxPROTOHS1DYNUCF5CD(VAR(CanRxInfoStructPtr, AUTOMATIC) rxStruct) /* PRQA S 3673 */ /* Declaration of this function comes from third party code */
{
    
 	VAR(uint8, AUTOMATIC) DLC_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) i;
	VAR(CanMsgType, AUTOMATIC) PROTOHS1DYNUCF5CDMsg_Cnt_T_u08;
	VAR (uint32, AUTOMATIC) time_Cnt_T_u32;
    
    if(ESCOffsCfgSeld_Cnt_M_lgc == TRUE) /* Receive only when Turns counter selected */
    {    
		GetSystemTime_mS_u32(&time_Cnt_T_u32);

		DLC_Cnt_T_u08 = (uint8)CanRxActualDLC(rxStruct); /* PRQA S 488 */ /* PRQA S 1861 */ /* Violation of 1861 comes from third party code and cannot be mixed */
        
        for( i = 0u; i < DLC_Cnt_T_u08; i++ )
        {
            PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[i] = rxStruct->pChipData[i]; /* PRQA S 491 */
        }
        
        for( ; i < 8u; i++ )
        {
            PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[i] = 0u;
        }

        (void)Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08((const CanMsgType *)(&PROTOHS1DYNUCF5CDMsg_Cnt_T_u08));
        (void)Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(time_Cnt_T_u32);
    }
	
	return kCanNoCopyData;     
}

FUNC(vuint8, CD_SRLCOMDRIVER_CODE) SrlComDriver_PreTxISDYNVOL(CanTxInfoStruct ctis)
{
    VAR(uint8, AUTOMATIC) Checksum_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) i;
    VAR(IS_DYN_VOL_MsgBase, AUTOMATIC) IsDynVolBase;
    VAR(IS_DYN_VOL_MsgAdd, AUTOMATIC) IsDynVolAdd;

    (void)Rte_Call_IS_DYN_VOL_Get(&IsDynVolBase, &IsDynVolAdd); /* PRQA S 3417 */ /* PRQA S 3426 */

	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.ETAT_CAPT_VOL 			= IsDynVolAdd.EtatCaptVol;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.CALIBRATION_VOL 		= IsDynVolAdd.CalibrationVol;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.TRIM_VOL 				= IsDynVolAdd.TrimVol;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.CODE_DEFAUT_VOL 		= IsDynVolAdd.CodeDefaultVol;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.VITESSE_ROT_VOL_OPTIMISE = IsDynVolAdd.VitesseRotVolOptimise;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.ANGLE_VOLANT_ORIGINE 	= IsDynVolAdd.AngleVolantOrigine;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.FLG_INIT_AVOL 			= IsDynVolAdd.FlgInitAvol;
	IS_DYN_VOL_GroupAdd.IS_DYN_VOL_GroupAdd.FLG_AVOL_ICN 			= IsDynVolAdd.FlgAvolIcn;

	/* Increment the process counter */
	ISDYNVOLMsgCount_Cnt_M_u08 = (ISDYNVOLMsgCount_Cnt_M_u08 + 1u) & 0x0Fu;
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.CPT_PROCESS_4B_A_VOL = ISDYNVOLMsgCount_Cnt_M_u08;
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.ANGLE_VOLANT_0 	= (uint8)((uint16)IsDynVolBase.AngleVolant >> 0); /* PRQA S 2985 */
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.ANGLE_VOLANT_1 	= (uint8)((uint16)IsDynVolBase.AngleVolant >> 8);
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.VITESSE_ROT_VOL 	= IsDynVolBase.VitesseRotVol;
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.SENS_ROT_VOL 		= IsDynVolBase.SensRotVol;
	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.CHKSUM_VOL 		= 0u; /* TODO: Should be replaced with define coming from COM stack/CANdb */

    /* Calculate alpha from fist 5 bytes of the message.
     * Last two bytes of IS_DYN_VOL_GroupAdd are intentionally omitted */
	Checksum_Cnt_T_u08 =
			IS_DYN_VOL_GroupBase._c[0] ^
			IS_DYN_VOL_GroupBase._c[1] ^
			IS_DYN_VOL_GroupBase._c[2] ^
			IS_DYN_VOL_GroupBase._c[3] ^
			IS_DYN_VOL_GroupBase._c[4] ^
			IS_DYN_VOL_GroupAdd._c[0] ^	/* When IS_DYN_VOL_GroupAdd shadow buffer is shifted vs. message buffer, 0 cell is mapped to 3rd cell */
			IS_DYN_VOL_GroupAdd._c[1];

	IS_DYN_VOL_GroupBase.IS_DYN_VOL_GroupBase.CHKSUM_VOL = Checksum_Cnt_T_u08 ^ (Checksum_Cnt_T_u08 >> 4);

	(void)IlPutTxIS_DYN_VOL_GroupAdd();
	(void)IlPutTxIS_DYN_VOL_GroupBase();

    return kCanCopyData;
}



FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_RxISDATBSI572(VAR(CanReceiveHandle, AUTOMATIC) rcvObject)
{ 
	VAR (uint32, AUTOMATIC) time_Cnt_T_u32;
	VAR (uint8, AUTOMATIC) ConfigVhl_Cnt_T_u08;

    if(ESCOffsCfgSeld_Cnt_M_lgc == TRUE) /* Receive only when Turns counter selected */
    {  
        GetSystemTime_mS_u32(&time_Cnt_T_u32);
        ConfigVhl_Cnt_T_u08 =  IlGetRxCONFIG_VHL();

        (void)Rte_Write_ConfigVhl_Cnt_u08(ConfigVhl_Cnt_T_u08); /* PRQA S 3417 */ /* PRQA S 3426 */
        (void)Rte_Write_ISDATBSI572MsgRxTime_MSec_u32(time_Cnt_T_u32); /* Set as last because it's a trigger */
    }        
}

FUNC(void, CD_SRLCOMDRIVER_CODE) SrlComDriver_TxISDYNVOL(CanTransmitHandle txObject)
{
    /* Nothing to do */
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
