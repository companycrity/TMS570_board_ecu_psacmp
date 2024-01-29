/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComOutput.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Wed May 16 11:14:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComOutput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          21 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#17
 * 06/27/16    2       WH       Updates for msg 3f2 outputs from CF13A, update condt. for angle colone
 *                              and temporary pass-through for CF24 outputs while the component gets fixed.		EA3#9194
 * 06/28/16    3       WH       Updated the index of tuning states                                              EA3#9194
 * 06/29/16    4       WH       Removed the dependency of EPSStateLXA on LXAState                               EA3#9194
 * 11/17/16    6       WH       Removed the temp workaround for cf24                                            EA3#12653
 * 03/09/17    6       AR       Update for SCIR version 2C                                  			        EA3#14168
 * 03/15/17    7       AR       updated for MCDC coverage issue                               			        EA3#14168
 * 03/22/17    8       AR       Update for SCIR version 2D                               			            EA3#14816
 * 04/21/17    9       AR       CALIBRATION_VOL set based out of input from CF039 (AbsltHwPosnLvl2) and 
								Handwheel Torque  validity check considers NTC 0x1FC instead of NTC 0x1FB       EA3#15385
 * 05/23/17    10      AR       Update for SCIR version 2F                               			            EA3#16010
 * 12/06/17    13      RK       Serial Com refactoring related to CPU Load optimization and MISRA               EA3#18157
 * 12/15/17    14      RK       Changed types of RTE signals after CF13 CF14 and CF24 update                    EA3#18482
 * 02/09/18	   15      MB       Added HW Tourque valid condition for CPLE_VOLANT_OPTMSE							EA3#17938
 *                     MB       STATUS_CONFABSENT signal set permamently to 0.									EA3#17893
 *                     RK       STTd updated on Customer request												EA3#13267
 * 03/19/18    16      MB      Changes due to new revisions of CF13 and CF14.                                   EA3#19230
 *                                                                                                              EA3#19233
 * 03/21/18    17      RK      Removed Node Absent NTCs						                                	EA3#19032
 * 03/22/18    18      RK      Timer for ETAT_SECU_ANGLE_COL resets until Tx is ON								EA3#17853
 * 04/30/18    19      MB      Behavior of LXA and CPK flags updated for case not covered in CFs				EA3#18231
 * 05/17/18	   20	   MB	   SCIR 4C update - validity flags code/spec inconsistency                          EA3#20049
 * 							   5CD message changes																EA3#20046
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


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComOutput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "il_inc.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "string.h"

#define D_CPLEVOLANTOPTMSELOLMT_HWNM_F32		(-10.0f)
#define D_CPLEVOLANTOPTMSEHILMT_HWNM_F32		10.0f
#define D_CPLEVOLANTOPTMSESCALE_HWNMPCNT_F32	0.1f
#define D_ANGLECOLONNELOLMT_HWDEG_F32			(-1630.0f)
#define D_ANGLECOLONNEHILMT_HWDEG_F32			1630.0f
#define D_ANGLECOLONNESCALE_HWDEGPCNT_F32		0.1f
#define D_VITESSECOLONNELOLMT_HWDEGPS_F32		(-2000.0f)
#define D_VITESSECOLONNEHILMT_HWDEGPS_F32		2000.0f
#define D_CPLEVOLANTLOLMT_HWNM_F32				(-32.0f)
#define D_CPLEVOLANTHILMT_HWNM_F32				31.5f
#define D_CPLEVOLANTSCALE_HWNMPCNT_F32			0.25f
#define D_ABSHWPOSHILIM_HWDEG_F32			    780.0F
#define D_ABSHWPOSLOLIM_HWDEG_F32			    (-780.0F)
#define D_VITESSEROTVOLLOLMT_HWDEGPS_F32	    0.0F
#define D_VITESSEROTVOLHILMT_HWDEGPS_F32	    1016.0F
#define D_ANGLEVOLANTSCALE_HWDEG_F32	        0.1f
#define D_ANGLEVOLANTSCALE_HWDEGPS_F32	        4.0f
#define D_STATUSCONFABSENTDEFAULT_U32			0u

#define ApplyRounding_f32(x)	( ((x) < 0.0f) ? ((x) - 0.5f) : ((x) + 0.5f) ) /* PRQA S 3453 */


#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNDEFINED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(IS_SUPV_DIRA_Msg,  AP_SRLCOMOUTPUT_VAR) IsSupvDiraPrev; /* PRQA S 3218 */
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNDEFINED
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  AP_SRLCOMOUTPUT_VAR) ETATSECUANGLECOLSigTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMOUTPUT_VAR) DDEREDEMDASigValidTimer_mS_M_u32;
STATIC VAR(float32, AP_SRLCOMOUTPUT_VAR) HandwheelAuthority_Uls_M_f32;
STATIC VAR(float32, AP_SRLCOMOUTPUT_VAR) HandwheelPosition_HwDeg_M_f32;
STATIC VAR(float32, AP_SRLCOMOUTPUT_VAR) HandwheelTorque_HwNm_M_f32;
STATIC VAR(float32, AP_SRLCOMOUTPUT_VAR) HandwheelVelocity_HwRadpS_M_f32;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) STTdSelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) DefaultHwaSCommExportValue_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) VehicleSpeedValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) DutyCycleExceeded_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) AbsTempThermLimit_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) RelHwPosnVldToSerlCom_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) IsSupvDiraFirstCall_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) ReInitializeComponent_M_lgc;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_ReInit(void);
STATIC FUNC(VITESSE_COLONNE, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetVitesseColonne(void);
STATIC FUNC(CPLE_VOLANT_OPTMSE, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetCpleVolantOptimse(void);
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE(void);

STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_VOL(void);

STATIC FUNC(CPLE_VOLANT, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetCpleVolant(VAR(boolean, AUTOMATIC) hwTorqueFault_T_lgc);
STATIC FUNC(ETAT_DA_2004, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetEtatDa2004(VAR(boolean, AUTOMATIC) EtatDa2_Cnt_T_lgc);
STATIC FUNC(ETAT_DA_2010, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetEtatDa2010(VAR(boolean, AUTOMATIC) EtatDa2_Cnt_T_lgc);
STATIC FUNC(boolean, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetHwTorqueFault(void);
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DAT_DIRA(void);

STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA(void);

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
 * IoHwAb_BoolType: Integer in interval [0...1]
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
 * PsaApaSt_Cnt_enum: Enumeration of integer in interval [0...3] with enumerators
 *   PSAAPAST_UNAVL (0U)
 *   PSAAPAST_AVL (1U)
 *   PSAAPAST_CTRLPRGS (2U)
 *   PSAAPAST_DFCT (3U)
 * PsaApaTranCause_Cnt_enum: Enumeration of integer in interval [0...7] with enumerators
 *   PSAAPATRANCAUSE_NOINTRPT (0U)
 *   PSAAPATRANCAUSE_DRVRINTV (1U)
 *   PSAAPATRANCAUSE_VEHSPDHI (2U)
 *   PSAAPATRANCAUSE_AGLERR (3U)
 *   PSAAPATRANCAUSE_MTRSTALL (4U)
 *   PSAAPATRANCAUSE_UNUSED (5U)
 *   PSAAPATRANCAUSE_THERMLIM (6U)
 *   PSAAPATRANCAUSE_OTHERERR (7U)
 * PsaEpsStLxa_Cnt_enum: Enumeration of integer in interval [0...4] with enumerators
 *   PSAEPSSTLXA_UNAUTHD (0U)
 *   PSAEPSSTLXA_AUTHD (1U)
 *   PSAEPSSTLXA_AVL (2U)
 *   PSAEPSSTLXA_ACTV (3U)
 *   PSAEPSSTLXA_DFCT (4U)
 * PsaTunModSt_Cnt_enum: Enumeration of integer in interval [0...3] with enumerators
 *   PSATUNMODST_NORM (0U)
 *   PSATUNMODST_SPORT (1U)
 *   PSATUNMODST_TUN (2U)
 *   PSATUNMODST_FAILD (3U)
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
 * PsaAgArbnSt_Enum: D_PSAAGARBNSTINIT_CNT_ENUM = 0U
 * PsaApaSt_Cnt_enum: D_PSAAPASTINIT_CNT_ENUM = 0U
 * PsaApaTranCause_Cnt_enum: D_PSAAPATRANCAUSEINIT_CNT_ENUM = 0U
 * PsaEpsStLxa_Cnt_enum: D_PSAEPSSTLXAINIT_CNT_ENUM = 0U
 * PsaTunModSt_Cnt_enum: D_PSATUNMODSTINIT_CNT_ENUM = 0U
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
 *   IS_DAT_DIRA_Msg *Rte_Pim_PimIsDatDiraMsg(void)
 *   IS_DYN_DAE_Msg *Rte_Pim_PimIsDynDaeMsg(void)
 *   IS_DYN_VOL_MsgAdd *Rte_Pim_PimIsDynVolAddMsg(void)
 *   IS_DYN_VOL_MsgBase *Rte_Pim_PimIsDynVolBaseMsg(void)
 *   IS_SUPV_DIRA_Msg *Rte_Pim_PimIsSupvDiraMsg(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DAT_DIRA_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DAT_DIRA>
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
 *   void Rte_Enter_IsDatDiraMsg(void)
 *   void Rte_Exit_IsDatDiraMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DAT_DIRA_Get(IS_DAT_DIRA_Msg *IsDatDira)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DAT_DIRA_Get(P2VAR(IS_DAT_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDatDira)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_IS_DAT_DIRA_Get
 *********************************************************************************************************************/
	Rte_Enter_IsDatDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	(void)memcpy(IsDatDira, Rte_Pim_PimIsDatDiraMsg(), sizeof(IS_DAT_DIRA_Msg));
	Rte_Exit_IsDatDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DYN_DAE_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DYN_DAE>
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
 *   void Rte_Enter_IsDynDaeMsg(void)
 *   void Rte_Exit_IsDynDaeMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynDae)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_IS_DYN_DAE_Get
 *********************************************************************************************************************/
	Rte_Enter_IsDynDaeMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	(void)memcpy(IsDynDae, Rte_Pim_PimIsDynDaeMsg(), sizeof(IS_DYN_DAE_Msg));
	Rte_Exit_IsDynDaeMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DYN_VOL_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DYN_VOL>
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
 *   void Rte_Enter_IsDynVolMsg(void)
 *   void Rte_Exit_IsDynVolMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DYN_VOL_Get(IS_DYN_VOL_MsgBase *IsDynVolBase, IS_DYN_VOL_MsgAdd *IsDynVolAdd)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_VOL_Get(P2VAR(IS_DYN_VOL_MsgBase, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolBase, P2VAR(IS_DYN_VOL_MsgAdd, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolAdd)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_IS_DYN_VOL_Get
 *********************************************************************************************************************/
	Rte_Enter_IsDynVolMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	(void)memcpy(IsDynVolBase, Rte_Pim_PimIsDynVolBaseMsg(), sizeof(IS_DYN_VOL_MsgBase));
	(void)memcpy(IsDynVolAdd, Rte_Pim_PimIsDynVolAddMsg(), sizeof(IS_DYN_VOL_MsgAdd));
	Rte_Exit_IsDynVolMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_SUPV_DIRA_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_SUPV_DIRA>
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
 *   void Rte_Enter_IsSupvDiraMsg(void)
 *   void Rte_Exit_IsSupvDiraMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsSupvDira)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_IS_SUPV_DIRA_Get
 *********************************************************************************************************************/
	Rte_Enter_IsSupvDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	(void)memcpy(IsSupvDira, Rte_Pim_PimIsSupvDiraMsg(), sizeof(IS_SUPV_DIRA_Msg));
	Rte_Exit_IsSupvDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init
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

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Init
 *********************************************************************************************************************/
	
	
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;
	
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
	ETATSECUANGLECOLSigTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DDEREDEMDASigValidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	IsSupvDiraFirstCall_Cnt_M_lgc = TRUE;
	
	Rte_Pim_PimIsDatDiraMsg()->DdeRedemDa = (uint8)kDDE_REDEM_DA_Request_Reboot;
	Rte_Pim_PimIsDatDiraMsg()->AutorArretMotDa = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TxEnabled_Cnt_lgc(Boolean *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   PsaApaTranCause_Cnt_enum Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_enum(void)
 *   PsaApaSt_Cnt_enum Rte_IRead_SrlComOutput_Per1_APAState_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl1_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl2_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32(void)
 *   PsaAgArbnSt_Enum Rte_IRead_SrlComOutput_Per1_AgArbnStToSerlCom_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DmdDelestDaVld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DrvrIntvDetd_Cnt_lgc(void)
 *   PsaEpsStLxa_Cnt_enum Rte_IRead_SrlComOutput_Per1_EPSStateForLxa_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   PsaTunModSt_Cnt_enum Rte_IRead_SrlComOutput_Per1_ETATDADYN_Cnt_enum(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_LxaTqLimnActv_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_RelHwPosnToSerlCom_HwDeg_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_SendMsgOnChange(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_IndStatusETATDA2_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsDatDiraMsg(void)
 *   void Rte_Exit_IsDatDiraMsg(void)
 *   void Rte_Enter_IsDynDaeMsg(void)
 *   void Rte_Exit_IsDynDaeMsg(void)
 *   void Rte_Enter_IsDynVolMsg(void)
 *   void Rte_Exit_IsDynVolMsg(void)
 *   void Rte_Enter_IsSupvDiraMsg(void)
 *   void Rte_Exit_IsSupvDiraMsg(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Per1
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) TxEnable_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;


	if (TRUE == ReInitializeComponent_M_lgc)
	{
		ReInitializeComponent_M_lgc = FALSE;
		SrlComOutput_ReInit();
	}

    (void)Rte_Read_TxEnabled_Cnt_lgc(&TxEnable_Cnt_T_lgc);

    if (FALSE == TxEnable_Cnt_T_lgc)
    {
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
		ETATSECUANGLECOLSigTimer_mS_M_u32 = SystemTime_mS_T_u32;
    }

	DefaultHwaSCommExportValue_Cnt_M_lgc = Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc();
	HandwheelAuthority_Uls_M_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32();
	HandwheelPosition_HwDeg_M_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32();
	HandwheelTorque_HwNm_M_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32();
	HandwheelVelocity_HwRadpS_M_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32();
	STTdSelected_Cnt_M_lgc = Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc();
	VehicleSpeedValid_Cnt_M_lgc = Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc();
    RelHwPosnVldToSerlCom_Cnt_M_lgc = Rte_IRead_SrlComOutput_Per1_RelHwPosnVldToSerlCom_Cnt_lgc();
    (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DutyCycleExceeded, &DutyCycleExceeded_Cnt_M_lgc);
    (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AbsTempThermLimit, &AbsTempThermLimit_Cnt_M_lgc);


	SrlComOutput_IS_DYN_DAE();

	SrlComOutput_IS_DYN_VOL();
    
	SrlComOutput_IS_DAT_DIRA();
	
	SrlComOutput_IS_SUPV_DIRA();
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Trns1
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

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Trns1
 *********************************************************************************************************************/

	ReInitializeComponent_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Name          : SrlComOutput_ReInit
 * Description   : Reinitializes static variable of the component
 * Inputs        : 	all static variables
 * Outputs       :  all static variables
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_ReInit(void)
{
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;

	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
	ETATSECUANGLECOLSigTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DDEREDEMDASigValidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	IsSupvDiraFirstCall_Cnt_M_lgc = TRUE;

	Rte_Enter_IsDatDiraMsg();
	Rte_Pim_PimIsDatDiraMsg()->CpleVolant = (CPLE_VOLANT)0;
	Rte_Pim_PimIsDatDiraMsg()->EtatDa2004 = (ETAT_DA_2004)0;
	Rte_Pim_PimIsDatDiraMsg()->EtatDaDyn = (ETAT_DA_DYN)0;
	Rte_Pim_PimIsDatDiraMsg()->EtatDa2010 = (ETAT_DA_2010)0;
	Rte_Pim_PimIsDatDiraMsg()->TrqLimitState = (TRQ_LIMIT_STATE)0;
	Rte_Pim_PimIsDatDiraMsg()->SteerwhlHoldByDrv = (STEERWHL_HOLD_BY_DRV)0;
	Rte_Pim_PimIsDatDiraMsg()->EpsStateLka = (EPS_STATE_LKA)0;
	Rte_Pim_PimIsDatDiraMsg()->AutorArretMotDa = (AUTOR_ARRET_MOT_DA)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
	Rte_Pim_PimIsDatDiraMsg()->DdeRedemDa = (DDE_REDEM_DA)kDDE_REDEM_DA_Request_Reboot;
	Rte_Exit_IsDatDiraMsg();

	Rte_Enter_IsDynDaeMsg();
	Rte_Pim_PimIsDynDaeMsg()->CptProcess4bDae = (CPT_PROCESS_4B_DAE)0;
	Rte_Pim_PimIsDynDaeMsg()->ChksumTrmeDynDae = (CHKSUM_TRME_DYN_DAE)0;
	Rte_Pim_PimIsDynDaeMsg()->CpleVolantOptimse = (CPLE_VOLANT_OPTMSE)0;
	Rte_Pim_PimIsDynDaeMsg()->CauseDesactivCpk = (CAUSE_DESACTIV_CPK)0;
	Rte_Pim_PimIsDynDaeMsg()->EtatDaeCpk = (ETAT_DAE_CPK)0;
	Rte_Pim_PimIsDynDaeMsg()->AngleColonne = (ANGLE_COLONNE)0;
	Rte_Pim_PimIsDynDaeMsg()->EtatSecuAngleCol = (ETAT_SECU_ANGLE_COL)0;
	Rte_Pim_PimIsDynDaeMsg()->EtatDaeCav3Virtuel = (ETAT_DAE_CAV3_VIRTUEL)0;
	Rte_Pim_PimIsDynDaeMsg()->VitesseColonne = (VITESSE_COLONNE)0;
	Rte_Exit_IsDynDaeMsg();

	Rte_Enter_IsDynVolMsg();
	Rte_Pim_PimIsDynVolAddMsg()->EtatCaptVol = (ETAT_CAPT_VOL)0;
	Rte_Pim_PimIsDynVolAddMsg()->CalibrationVol = (CALIBRATION_VOL)0;
	Rte_Pim_PimIsDynVolAddMsg()->TrimVol = (TRIM_VOL)0;
	Rte_Pim_PimIsDynVolAddMsg()->CodeDefaultVol = (CODE_DEFAUT_VOL)0;
	Rte_Pim_PimIsDynVolAddMsg()->VitesseRotVolOptimise = (VITESSE_ROT_VOL_OPTIMISE)0;
	Rte_Pim_PimIsDynVolAddMsg()->AngleVolantOrigine = (ANGLE_VOLANT_ORIGINE)0;
	Rte_Pim_PimIsDynVolAddMsg()->FlgAvolIcn = (FLG_AVOL_ICN)0;
	Rte_Pim_PimIsDynVolAddMsg()->FlgInitAvol = (FLG_INIT_AVOL)0;
	Rte_Pim_PimIsDynVolBaseMsg()->AngleVolant = (ANGLE_VOLANT)0;
	Rte_Pim_PimIsDynVolBaseMsg()->VitesseRotVol = (VITESSE_ROT_VOL)0;
	Rte_Pim_PimIsDynVolBaseMsg()->SensRotVol = (SENS_ROT_VOL)0;
	Rte_Pim_PimIsDynVolBaseMsg()->CptProcess4bAVol = (CPT_PROCESS_4B_A_VOL)0;
	Rte_Pim_PimIsDynVolBaseMsg()->ChksumVol = (CHKSUM_VOL)0;
	Rte_Exit_IsDynVolMsg();

	Rte_Enter_IsSupvDiraMsg();
	Rte_Pim_PimIsSupvDiraMsg()->CodeDefaut = (CODE_DEFAUT)0;
	Rte_Pim_PimIsSupvDiraMsg()->StatusConfabsent = (STATUS_CONFABSENT)0;
	Rte_Pim_PimIsSupvDiraMsg()->EtatAssistDa = (ETAT_ASSIST_DA)0;
	Rte_Pim_PimIsSupvDiraMsg()->EtatLigneApc = (ETAT_LIGNE_APC)0;

	IsSupvDiraPrev.CodeDefaut = (CODE_DEFAUT)0;
	IsSupvDiraPrev.StatusConfabsent = (STATUS_CONFABSENT)0;
	IsSupvDiraPrev.EtatAssistDa = (ETAT_ASSIST_DA)0;
	IsSupvDiraPrev.EtatLigneApc = (ETAT_LIGNE_APC)0;
	Rte_Exit_IsSupvDiraMsg();
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetVitesseColonne
 * Description   : Calculates VitesseColonne signal base on static global variables
 * Inputs        : 	DefaultHwaSCommExportValue_Cnt_M_lgc
 * 					HandwheelVelocity_HwRadpS_M_f32
 * Outputs       : VitesseColonne signal value
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(VITESSE_COLONNE, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetVitesseColonne(void)
{
	VAR(float32, AUTOMATIC) VitesseColonne_HwDegpS_T_f32;
	VAR(VITESSE_COLONNE, AUTOMATIC) VitesseColonne_T;

	if (TRUE == DefaultHwaSCommExportValue_Cnt_M_lgc)
	{
		VitesseColonne_T = (VITESSE_COLONNE)kVITESSE_COLONNE_Invalid;
	}
	else
	{
		VitesseColonne_HwDegpS_T_f32 = Limit_m(HandwheelVelocity_HwRadpS_M_f32 * D_180OVRPI_ULS_F32 * (-1.0f), D_VITESSECOLONNELOLMT_HWDEGPS_F32, D_VITESSECOLONNEHILMT_HWDEGPS_F32);
		VitesseColonne_HwDegpS_T_f32 = ApplyRounding_f32(VitesseColonne_HwDegpS_T_f32);
		VitesseColonne_T = (VITESSE_COLONNE)VitesseColonne_HwDegpS_T_f32; /* FIXME: Possibly bit size narrow down is required ( x & 0x0FFFu) */
	}

	return VitesseColonne_T;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetCpleVolantOptimse
 * Description   : Calculates CpleVolantOptimse signal base on static global variables
 * Inputs        : HandwheelTorque_HwNm_M_f32
 * Outputs       : CpleVolantOptimse signal value
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(CPLE_VOLANT_OPTMSE, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetCpleVolantOptimse(void)
{
	VAR(CPLE_VOLANT_OPTMSE, AUTOMATIC) CpleVolantOptimse_T;
	VAR(float32, AUTOMATIC) CpleVolantOptimse_Cnt_T_f32;
	VAR(boolean, AUTOMATIC) HandwheelTorqueFault_T_lgc;

	HandwheelTorqueFault_T_lgc = SrlComOutput_GetHwTorqueFault();

	if(TRUE == HandwheelTorqueFault_T_lgc)
	{
		CpleVolantOptimse_T = kCPLE_VOLANT_OPTMSE_Invalid;
	}
	else
	{
		CpleVolantOptimse_Cnt_T_f32 = Limit_m(HandwheelTorque_HwNm_M_f32, D_CPLEVOLANTOPTMSELOLMT_HWNM_F32, D_CPLEVOLANTOPTMSEHILMT_HWNM_F32) / D_CPLEVOLANTOPTMSESCALE_HWNMPCNT_F32;
		CpleVolantOptimse_Cnt_T_f32 = ApplyRounding_f32(CpleVolantOptimse_Cnt_T_f32);
		CpleVolantOptimse_T = (CPLE_VOLANT_OPTMSE) CpleVolantOptimse_Cnt_T_f32;
	}

	return CpleVolantOptimse_T;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_IS_DYN_DAE
 * Description   : Prepares signals for IS_DYN_DAE 0x2F5
 * Inputs        : Uses RTE interfaces and static variables
 * 					Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_CAVHCSelected_Cnt_lgc
 * 					Rte_Call_SystemTime_GetSystemTime_mS_u32
 * 					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16
 * 					Rte_Enter_IsDynDaeMsg
 * 					Rte_Exit_IsDynDaeMsg
 * 					DefaultHwaSCommExportValue_Cnt_M_lgc
 * 					RelHwPosnVldToSerlCom_Cnt_M_lgc
 * 					ETATSECUANGLECOLSigTimer_mS_M_u32
 * 					RelHwPosnToSerlCom_HwDeg_M_f32
 * 					HandwheelPosition_HwDeg_M_f32
 * 					HandwheelAuthority_Uls_M_f32
 * 					SrlComOutput_GetVitesseColonne
 * 					SrlComOutput_GetCpleVolantOptimse
 * Outputs       : Rte_Pim_PimIsDynDaeMsg
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE(void)
{
	VAR(boolean, AUTOMATIC) AVAorESCOffsCfgSeld_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CavHCandLXASelected_Cnt_T_lgc;
	VAR(CPLE_VOLANT_OPTMSE, AUTOMATIC) CpleVolantOptimse_T;
	VAR(float32, AUTOMATIC) ANGLECOLONNE_Cnt_T_f32;
	VAR(sint16,  AUTOMATIC) VITESSECOLONNE_HwDegpS_T_s16;
	VAR(sint16,  AUTOMATIC) ANGLECOLONNE_Cnt_T_s16;
	VAR(VITESSE_COLONNE, AUTOMATIC) VitesseColonne_T;
	VAR(uint8,   AUTOMATIC) ETATSECUANGLECOL_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) CityParkSelected_Cnt_T_lgc;
	VAR(float32, AP_SRLCOMOUTPUT_VAR) RelHwPosnToSerlCom_HwDeg_T_f32;

	RelHwPosnToSerlCom_HwDeg_T_f32 = Rte_IRead_SrlComOutput_Per1_RelHwPosnToSerlCom_HwDeg_f32();

	AVAorESCOffsCfgSeld_Cnt_T_lgc = (boolean)((TRUE == Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc()) ||
											  (TRUE == Rte_IRead_SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc() ));

	CavHCandLXASelected_Cnt_T_lgc = (boolean)((TRUE == Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc()) &&
											  (TRUE == Rte_IRead_SrlComOutput_Per1_CAVHCSelected_Cnt_lgc()  ));

	CityParkSelected_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc();

	/* CPLE_VOLANT_OPTMSE */
	CpleVolantOptimse_T = SrlComOutput_GetCpleVolantOptimse();

	/* ANGLE_COLONNE & ETAT_SECU_ANGLE_COL */
	if((TRUE == DefaultHwaSCommExportValue_Cnt_M_lgc) || (FALSE == RelHwPosnVldToSerlCom_Cnt_M_lgc))
	{
		ANGLECOLONNE_Cnt_T_s16 = kANGLE_COLONNE_Invalid;

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ETATSECUANGLECOLSigTimer_mS_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
		ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Not_Secure;
	}
	else
	{
		if (TRUE == AVAorESCOffsCfgSeld_Cnt_T_lgc)
		{
			ANGLECOLONNE_Cnt_T_f32 = Limit_m((RelHwPosnToSerlCom_HwDeg_T_f32 * (-1.0f)), D_ANGLECOLONNELOLMT_HWDEG_F32, D_ANGLECOLONNEHILMT_HWDEG_F32) / D_ANGLECOLONNESCALE_HWDEGPCNT_F32;
			ANGLECOLONNE_Cnt_T_f32 = ApplyRounding_f32(ANGLECOLONNE_Cnt_T_f32);
			ANGLECOLONNE_Cnt_T_s16 = (sint16)ANGLECOLONNE_Cnt_T_f32;
		}
		else if ((TRUE == CavHCandLXASelected_Cnt_T_lgc) && (1.0f <= HandwheelAuthority_Uls_M_f32))
		{
			ANGLECOLONNE_Cnt_T_f32 = Limit_m((HandwheelPosition_HwDeg_M_f32 * (-1.0f)), D_ANGLECOLONNELOLMT_HWDEG_F32, D_ANGLECOLONNEHILMT_HWDEG_F32) / D_ANGLECOLONNESCALE_HWDEGPCNT_F32;
			ANGLECOLONNE_Cnt_T_f32 = ApplyRounding_f32(ANGLECOLONNE_Cnt_T_f32);
			ANGLECOLONNE_Cnt_T_s16 = (sint16)ANGLECOLONNE_Cnt_T_f32;
		}
		else
		{
			ANGLECOLONNE_Cnt_T_s16 = kANGLE_COLONNE_Invalid;
		}

		if ( (TRUE == AVAorESCOffsCfgSeld_Cnt_T_lgc) ||
			 ( (TRUE == CavHCandLXASelected_Cnt_T_lgc) && (1.0f <= HandwheelAuthority_Uls_M_f32) ) )
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ETATSECUANGLECOLSigTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */

			if(k_ETATSECUANGLECOLSigTimeout_mS_u16 <= ElapsedTime_mS_T_u16)
			{
				ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Secure;
			}
			else
			{
				ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Not_Secure;
			}
		}
		else
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ETATSECUANGLECOLSigTimer_mS_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
			ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Not_Secure;
		}
	}

	/* VITESSE_COLONNE */
	VitesseColonne_T = SrlComOutput_GetVitesseColonne();

	Rte_Enter_IsDynDaeMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	/* Rte_Pim_PimIsDynDaeMsg()->CptProcess4bDae; */ /* Handled on lower layer */
	/* Rte_Pim_PimIsDynDaeMsg()->ChksumTrmeDynDae; */
	Rte_Pim_PimIsDynDaeMsg()->CpleVolantOptimse = CpleVolantOptimse_T;

	if(TRUE == CityParkSelected_Cnt_T_lgc)
	{
		Rte_Pim_PimIsDynDaeMsg()->EtatDaeCpk = Rte_IRead_SrlComOutput_Per1_APAState_Cnt_enum();
		Rte_Pim_PimIsDynDaeMsg()->CauseDesactivCpk = Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_enum();
	}
	else
	{
		Rte_Pim_PimIsDynDaeMsg()->EtatDaeCpk = (ETAT_DAE_CPK)kETAT_DAE_CPK_Unavailable;
		Rte_Pim_PimIsDynDaeMsg()->CauseDesactivCpk = (CAUSE_DESACTIV_CPK)kCAUSE_DESACTIV_CPK_No_Control_Interruption;
	}

	Rte_Pim_PimIsDynDaeMsg()->AngleColonne = ANGLECOLONNE_Cnt_T_s16;
	Rte_Pim_PimIsDynDaeMsg()->EtatSecuAngleCol = ETATSECUANGLECOL_Cnt_T_u08;
	Rte_Pim_PimIsDynDaeMsg()->EtatDaeCav3Virtuel = Rte_IRead_SrlComOutput_Per1_AgArbnStToSerlCom_Cnt_enum() & 0x07u;
	Rte_Pim_PimIsDynDaeMsg()->VitesseColonne = VitesseColonne_T;
	Rte_Exit_IsDynDaeMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_IS_DYN_VOL
 * Description   : Prepares signals for IS_DYN_VOL 0x305
 * Inputs        : Uses RTE interfaces and static variables
 * 					Rte_IRead_SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32
 * 					Rte_Enter_IsDynVolMsg
 * 					Rte_Exit_IsDynVolMsg
 * 					RelHwPosnVldToSerlCom_Cnt_M_lgc
 * 					DefaultHwaSCommExportValue_Cnt_M_lgc
 * 					RelHwPosnToSerlCom_HwDeg_M_f32
 * 					HandwheelVelocity_HwRadpS_M_f32
 * Outputs       : Rte_Pim_PimIsDynVolAddMsg and Rte_Pim_PimIsDynVolBaseMsg
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_VOL(void)
{
	VAR(boolean,  AUTOMATIC) AbsltHwPosnVld_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ETATCAPTVOL_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) ANGLEVOLANT_Cnt_T_f32;
	VAR(float32, AUTOMATIC) VITESSEROTVOL_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) VITESSEROTVOL_HwDegpS_T_f32;
	VAR(uint8,  AUTOMATIC) VITESSEROTVOL_HwDegpS_T_u08;
	VAR(boolean,  AUTOMATIC) SENSROTVOL_Cnt_T_lgc;
	VAR(sint16,  AUTOMATIC) ANGLEVOLANT_Cnt_T_s16;

	AbsltHwPosnVld_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc();/* From CF 39A*/

	/* ANGLE_VOLANT */
	if (TRUE == DefaultHwaSCommExportValue_Cnt_M_lgc)
	{
		ANGLEVOLANT_Cnt_T_s16 = kANGLE_VOLANT_Invalid;
	}
	else if (TRUE == AbsltHwPosnVld_Cnt_T_lgc)
	{
		ANGLEVOLANT_Cnt_T_f32 = (Rte_IRead_SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32() * (-1.0f))/D_ANGLEVOLANTSCALE_HWDEG_F32;
		ANGLEVOLANT_Cnt_T_f32 = ApplyRounding_f32(ANGLEVOLANT_Cnt_T_f32);
		ANGLEVOLANT_Cnt_T_s16 = (sint16)ANGLEVOLANT_Cnt_T_f32;
	}
	else
	{
		ANGLEVOLANT_Cnt_T_s16 = kANGLE_VOLANT_Invalid;
	}

	/* VITESSE_ROT_VOL*/
	if(TRUE == DefaultHwaSCommExportValue_Cnt_M_lgc)
	{
		VITESSEROTVOL_HwDegpS_T_u08 = (uint8)kVITESSE_ROT_VOL_Invalid;
	}
	else
	{
		VITESSEROTVOL_HwRadpS_T_f32 = Abs_f32_m(HandwheelVelocity_HwRadpS_M_f32);
		VITESSEROTVOL_HwDegpS_T_f32 = (Limit_m((VITESSEROTVOL_HwRadpS_T_f32 * D_180OVRPI_ULS_F32), D_VITESSEROTVOLLOLMT_HWDEGPS_F32, D_VITESSEROTVOLHILMT_HWDEGPS_F32)/D_ANGLEVOLANTSCALE_HWDEGPS_F32);
		VITESSEROTVOL_HwDegpS_T_f32 = ApplyRounding_f32(VITESSEROTVOL_HwDegpS_T_f32);
		VITESSEROTVOL_HwDegpS_T_u08 = (uint8)VITESSEROTVOL_HwDegpS_T_f32;
	}

	/* ETAT_CAPT_VOL*/
	if(	(TRUE == DefaultHwaSCommExportValue_Cnt_M_lgc) ||
		(FALSE == RelHwPosnVldToSerlCom_Cnt_M_lgc))
	{
		ETATCAPTVOL_Cnt_T_lgc =  FALSE;
	}
	else
	{
		ETATCAPTVOL_Cnt_T_lgc = TRUE;
	}

	/* SENS_ROT_VOL*/
	if(1 == Sign_f32_m(HandwheelVelocity_HwRadpS_M_f32)) /* Positive */
	{
		SENSROTVOL_Cnt_T_lgc = FALSE;
	}
	else
	{
		SENSROTVOL_Cnt_T_lgc = TRUE;
	}

    Rte_Enter_IsDynVolMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
    Rte_Pim_PimIsDynVolAddMsg()->EtatCaptVol = ETATCAPTVOL_Cnt_T_lgc;
	Rte_Pim_PimIsDynVolAddMsg()->CalibrationVol = (CALIBRATION_VOL)kCALIBRATION_VOL_Calibrated;
	Rte_Pim_PimIsDynVolAddMsg()->TrimVol = (TRIM_VOL)kTRIM_VOL_Trimmed;
	Rte_Pim_PimIsDynVolAddMsg()->CodeDefaultVol = (CODE_DEFAUT_VOL)kCODE_DEFAUT_VOL_No_Default___Failure;
	/* This signal intentionally duplicates IS_DYN_VOL_MsgBase::VitesseRotVol */
	Rte_Pim_PimIsDynVolAddMsg()->VitesseRotVolOptimise = VITESSEROTVOL_HwDegpS_T_u08;
	Rte_Pim_PimIsDynVolAddMsg()->AngleVolantOrigine = (ANGLE_VOLANT_ORIGINE)kANGLE_VOLANT_ORIGINE_Other;
	Rte_Pim_PimIsDynVolAddMsg()->FlgAvolIcn = (FLG_AVOL_ICN)(FALSE == Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl2_Cnt_lgc());
	Rte_Pim_PimIsDynVolAddMsg()->FlgInitAvol = (FLG_INIT_AVOL)(FALSE == Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl1_Cnt_lgc());
	Rte_Pim_PimIsDynVolBaseMsg()->AngleVolant = ANGLEVOLANT_Cnt_T_s16;
	Rte_Pim_PimIsDynVolBaseMsg()->VitesseRotVol = VITESSEROTVOL_HwDegpS_T_u08;
	Rte_Pim_PimIsDynVolBaseMsg()->SensRotVol = SENSROTVOL_Cnt_T_lgc;
	/* Rte_Pim_PimIsDynVolBaseMsg()->CptProcess4bAVol; */ /* Handled on lower layer */
	/* Rte_Pim_PimIsDynVolBaseMsg()->ChksumVol; */
	Rte_Exit_IsDynVolMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetCpleVolant
 * Description   : Calculates signal CpleVolant
 * Inputs        : hwTorqueFault_T_lgc
 * 				Uses RTE interfaces and static variables
 * 					Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32
 *
 * Outputs       : Provides signal CpleVolant
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(CPLE_VOLANT, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetCpleVolant(VAR(boolean, AUTOMATIC) hwTorqueFault_T_lgc)
{
	VAR(float32, AUTOMATIC) CpleVolant_Cnt_T_f32;
	VAR(CPLE_VOLANT, AUTOMATIC) CpleVolant_T;
	VAR(float32, AUTOMATIC) SrlComHwTrq_HwNm_T_f32 = Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32();

	if(TRUE == hwTorqueFault_T_lgc)
	{
		CpleVolant_T = kCPLE_VOLANT_Invalid;
	}
	else
	{
		CpleVolant_Cnt_T_f32 = Limit_m(SrlComHwTrq_HwNm_T_f32, D_CPLEVOLANTLOLMT_HWNM_F32, D_CPLEVOLANTHILMT_HWNM_F32) / D_CPLEVOLANTSCALE_HWNMPCNT_F32;
		CpleVolant_Cnt_T_f32 = ApplyRounding_f32(CpleVolant_Cnt_T_f32);
		CpleVolant_T = (CPLE_VOLANT)CpleVolant_Cnt_T_f32;
	}

	return CpleVolant_T;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetEtatDa2004
 * Description   : Calculates signal EtatDa2004
 * Inputs        : EtatDa2_Cnt_T_lgc
 * Outputs       : Provides signal EtatDa2004
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(ETAT_DA_2004, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetEtatDa2004(VAR(boolean, AUTOMATIC) EtatDa2_Cnt_T_lgc)
{
	VAR(ETAT_DA_2004, AUTOMATIC) EtatDa2004_T;

	if( (k_JDD2010Selected_Cnt_lgc == TRUE) ||
		(EtatDa2_Cnt_T_lgc == TRUE) )
	{
		EtatDa2004_T = (ETAT_DA_2004)kETAT_DA_2004_Orange_LED;
	}
	else
	{
		EtatDa2004_T = (ETAT_DA_2004)kETAT_DA_2004_No_Demand;
	}

	return EtatDa2004_T;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetEtatDa2010
 * Description   : Calculates signal EtatDa2010
 * Inputs        : EtatDa2_Cnt_T_lgc
 * Outputs       : Provides signal EtatDa2010
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(ETAT_DA_2010, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetEtatDa2010(VAR(boolean, AUTOMATIC) EtatDa2_Cnt_T_lgc)
{
	ETAT_DA_2010 EtatDa2010_T;

	if( (k_JDD2010Selected_Cnt_lgc == FALSE) ||
		(EtatDa2_Cnt_T_lgc == TRUE) )
	{
		EtatDa2010_T = (uint8)kETAT_DA_2010_Orange_LED;
	}
	else
	{
		EtatDa2010_T = (uint8)kETAT_DA_2010_No_Demand;
	}

	return EtatDa2010_T;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_GetHwTorqueFault
 * Description   : Calculates handwheel torque fault value
 * Inputs        : Uses RTE interfaces
 * 					Rte_Call_NxtrDiagMgr_GetNTCFailed for NTC_Num_T1vsT2, NTC_Num_T1OutofRange, NTC_Num_T2OutofRange, NTC_Num_AnaHWDiffTqOfstNotTrmd
 * Outputs       : handwheel torque fault value
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(boolean, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetHwTorqueFault(void)
{
	VAR(boolean, AUTOMATIC) T1vsT2_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T1OutofRange_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T2OutofRange_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) AnaHWDiffTqOfstNotTrmd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) hwTorqueFault_T_lgc;

	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1vsT2, &T1vsT2_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1OutofRange, &T1OutofRange_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T2OutofRange, &T2OutofRange_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AnaHWDiffTqOfstNotTrmd, &AnaHWDiffTqOfstNotTrmd_Cnt_T_lgc);

	hwTorqueFault_T_lgc = (boolean)((TRUE == T1vsT2_Cnt_T_lgc 					) ||
									(TRUE == T1OutofRange_Cnt_T_lgc 			) ||
									(TRUE == T2OutofRange_Cnt_T_lgc 			) ||
									(TRUE == AnaHWDiffTqOfstNotTrmd_Cnt_T_lgc	)	);

	return hwTorqueFault_T_lgc;
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_IS_DAT_DIRA
 * Description   : Prepares signals for IS_DAT_DIRA 0x495
 * Inputs        : Uses RTE interfaces and static variables
 * 					Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32
 * 					Rte_Call_NxtrDiagMgr_GetNTCFailed for NTC_Num_VLF_06, NTC_Num_VLF_08
 * 					Rte_Call_IndStatusETATDA2_GetIndicatorStatus
 * 					Rte_Call_SystemTime_GetSystemTime_mS_u32
 *					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16
 *					Rte_Enter_IsDatDiraMsg
 *					Rte_Exit_IsDatDiraMsg
 * 					SrlComOutput_GetHwTorqueFault
 * 					SrlComOutput_GetCpleVolant
 * 					SrlComOutput_GetEtatDa2004
 * 					SrlComOutput_GetEtatDa2010
 * 					STTdSelected_Cnt_M_lgc
 * 					DDEREDEMDASigValidTimer_mS_M_u32
 * 					DutyCycleExceeded_Cnt_M_lgc
 * 					AbsTempThermLimit_Cnt_M_lgc
 * 					HandwheelTorque_HwNm_M_f32
 * 					HandwheelVelocity_HwRadpS_M_f32
 * 					HandwheelPosition_HwDeg_M_f32
 * 					OutputRampMult_Uls_M_f32
 * 					DefaultHwaSCommExportValue_Cnt_M_lgc
 * 					HandwheelAuthority_Uls_M_f32
 * 					VehicleSpeedValid_Cnt_M_lgc
 * 					EPSEn_Cnt_M_lgc
 *
 * Outputs       : Rte_Pim_PimIsDatDiraMsg
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DAT_DIRA(void)
{
	VAR(boolean, AUTOMATIC) hwTorqueFault_T_lgc;
	VAR(boolean, AUTOMATIC) IgnitionFailure_Cnt_T_lgc;
	VAR(CPLE_VOLANT,  AUTOMATIC) CpleVolant_T;
	VAR(boolean, AUTOMATIC) EtatDa2_Cnt_T_lgc;
	VAR(ETAT_DA_2004,  AUTOMATIC) EtatDa2004_T;
	VAR(ETAT_DA_2010,  AUTOMATIC) EtatDa2010_T;
	VAR(boolean, AUTOMATIC) ValidEngineStatus_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(boolean, AUTOMATIC) LowVoltageStopMode_Cnt_T_lgc;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) AbsHandwheelTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelPosition_HwDeg_T_f32;
	VAR(uint8,  AUTOMATIC) DDEREDEMDA_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) AUTORARRETMOTDA_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DmdDelestDaVld_T_lgc;
	VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc;

	LxaSelected_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc();

	hwTorqueFault_T_lgc = SrlComOutput_GetHwTorqueFault();
	ValidEngineStatus_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32();
	DmdDelestDaVld_T_lgc = Rte_IRead_SrlComOutput_Per1_DmdDelestDaVld_Cnt_lgc();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_06, &LowVoltageStopMode_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_08, &IgnitionFailure_Cnt_T_lgc);

	(void)Rte_Call_IndStatusETATDA2_GetIndicatorStatus(&EtatDa2_Cnt_T_lgc);

	/* CPLE_VOLANT */
	CpleVolant_T = SrlComOutput_GetCpleVolant(hwTorqueFault_T_lgc);

	/* ETAT_DA_2004 */
	EtatDa2004_T = SrlComOutput_GetEtatDa2004(EtatDa2_Cnt_T_lgc);

	/* ETAT_DA_2010 */
	EtatDa2010_T = SrlComOutput_GetEtatDa2010(EtatDa2_Cnt_T_lgc);

	/* DDE_REDEM_DA and AUTOR_ARRET_MOT_DA */
	if( STTdSelected_Cnt_M_lgc == FALSE )
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32);

		if( (DutyCycleExceeded_Cnt_M_lgc == TRUE) ||
			(AbsTempThermLimit_Cnt_M_lgc == TRUE) ||
			(LowVoltageStopMode_Cnt_T_lgc == TRUE)||
			(ValidEngineStatus_Cnt_T_lgc == FALSE) )
		{
			DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
			AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
		}
		else
		{
			DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_No_Reboot_Required;
			AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
		}
	}
	else
	{
		/* Check for no STTd failures */
		if ( (hwTorqueFault_T_lgc == FALSE) &&
			 (VehicleSpeedValid_Cnt_M_lgc == TRUE) &&
			 (DefaultHwaSCommExportValue_Cnt_M_lgc == FALSE) && /* Invalid motor position */
			 (DmdDelestDaVld_T_lgc == TRUE) &&
			 (IgnitionFailure_Cnt_T_lgc == FALSE) )
		{
			AbsHandwheelTorque_HwNm_T_f32 = Abs_f32_m(HandwheelTorque_HwNm_M_f32);
			AbsHandwheelVelocity_HwRadpS_T_f32 = Abs_f32_m(HandwheelVelocity_HwRadpS_M_f32);
			AbsHandwheelPosition_HwDeg_T_f32 = Abs_f32_m(HandwheelPosition_HwDeg_M_f32);

			if ((AbsHandwheelTorque_HwNm_T_f32 		> k_DDEREDEMDAHwTrqThresh_HwNm_f32)		||
				(AbsHandwheelVelocity_HwRadpS_T_f32 > k_DDEREDEMDAHwVelThresh_HwRadpS_f32)	||
				(VehicleSpeed_Kph_T_f32 			> k_DDEREDEMDAVehSpdThresh_Kph_f32) 	||
				((HandwheelAuthority_Uls_M_f32 		> k_STTdMinHwAuthority_Uls_f32)	&&
				 (AbsHandwheelPosition_HwDeg_T_f32 	> k_DDEREDEMDAHwPosThresh_HwDeg_f32)) )
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
			}
			else
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_No_Reboot_Required;
			}

			if ((AbsHandwheelTorque_HwNm_T_f32 		< k_AUTORARRETMOTDAHwTrqThresh_HwNm_f32)		&&
				(AbsHandwheelVelocity_HwRadpS_T_f32 < k_AUTORARRETMOTDAHwVelThresh_HwRadpS_f32)	&&
				((HandwheelAuthority_Uls_M_f32 		< k_STTdMinHwAuthority_Uls_f32)	||
				 (AbsHandwheelPosition_HwDeg_T_f32 	< k_AUTORARRETMOTDAHwPosThresh_HwDeg_f32)))
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DDEREDEMDASigValidTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32);
				ElapsedTime_mS_T_u16 = 0u;
			}

			if (DDEREDEMDA_Cnt_T_u08 == (uint8)kDDE_REDEM_DA_Request_Reboot)
			{
				AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
			}
			else
			{
				if (ElapsedTime_mS_T_u16 >= k_AUTORARRETMOTDAValidThresh_mS_u16)
				{
					AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
				}
				else
				{
					AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
				}
			}
		}
		else
		{
			DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
			AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;

			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32);
		}
	}

	Rte_Enter_IsDatDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	Rte_Pim_PimIsDatDiraMsg()->CpleVolant = CpleVolant_T;
	Rte_Pim_PimIsDatDiraMsg()->EtatDa2004 = EtatDa2004_T;
	Rte_Pim_PimIsDatDiraMsg()->EtatDaDyn = Rte_IRead_SrlComOutput_Per1_ETATDADYN_Cnt_enum();
	Rte_Pim_PimIsDatDiraMsg()->EtatDa2010 = EtatDa2010_T;
	Rte_Pim_PimIsDatDiraMsg()->TrqLimitState = Rte_IRead_SrlComOutput_Per1_LxaTqLimnActv_Cnt_lgc();

	if(TRUE == LxaSelected_Cnt_T_lgc)
	{
		Rte_Pim_PimIsDatDiraMsg()->EpsStateLka = Rte_IRead_SrlComOutput_Per1_EPSStateForLxa_Cnt_enum();
		Rte_Pim_PimIsDatDiraMsg()->SteerwhlHoldByDrv = Rte_IRead_SrlComOutput_Per1_DrvrIntvDetd_Cnt_lgc();
	}
	else
	{
		Rte_Pim_PimIsDatDiraMsg()->EpsStateLka = (EPS_STATE_LKA)kEPS_STATE_LKA_Unauthorised;
		Rte_Pim_PimIsDatDiraMsg()->SteerwhlHoldByDrv = (STEERWHL_HOLD_BY_DRV)FALSE;
	}

	Rte_Pim_PimIsDatDiraMsg()->AutorArretMotDa = AUTORARRETMOTDA_Cnt_T_u08;
	Rte_Pim_PimIsDatDiraMsg()->DdeRedemDa = DDEREDEMDA_Cnt_T_u08;
	Rte_Exit_IsDatDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
}


/***********************************************************************************************************************
 * Name          : SrlComOutput_IS_SUPV_DIRA
 * Description   : Prepares signals for IS_SUPV_DIRA 0x795
 * Inputs        : Uses RTE interfaces and static variables
 * 					Rte_Call_NxtrDiagMgr_GetNTCFailed for NTC_Num_ReducedAsstLowVoltage
 * 					Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc
 * 					Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08
 * 					Rte_Enter_IsSupvDiraMsg
 * 					Rte_Exit_IsSupvDiraMsg
 *					Rte_Call_SrlComDriver_SCom_SendMsgOnChange
 *					memcmp
 *					memcpy
 * 					VehicleSpeedValid_Cnt_M_lgc
 * 					DutyCycleExceeded_Cnt_M_lgc
 * 					AbsTempThermLimit_Cnt_M_lgc
 * 					STTdSelected_Cnt_M_lgc
 * 					OutputRampMult_Uls_M_f32
 *					IsSupvDiraPrev
 *					IsSupvDiraFirstCall_Cnt_M_lgc
 * Outputs       : Rte_Pim_PimIsSupvDiraMsg
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA(void)
{
	VAR(uint8, AUTOMATIC) ETATASSISTDA_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc;

    (void)Rte_Call_EpsEn_OP_GET(&EPSEn_Cnt_T_lgc);

	/* ETAT_ASSIST_DA */
	if(TRUE == Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc())
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Assist_Not_Active;
	}
	else if( (FALSE == VehicleSpeedValid_Cnt_M_lgc) ||
			 (TRUE == DutyCycleExceeded_Cnt_M_lgc) ||
			 (TRUE == AbsTempThermLimit_Cnt_M_lgc) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Dmg_Assist_Active;
	}
	else if( (FALSE == STTdSelected_Cnt_M_lgc) &&
			 ((uint8)kETAT_MT_Stopped == Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08()) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_STTa_Assist_Active;
	}
	else if( (TRUE == STTdSelected_Cnt_M_lgc) &&
			 (0.0001f >= Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32()) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_STTd_Assist_Active;
	}
	else
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Nominal_Assist_Active;
	}

    /*** IS_SUPV_DIRA (Msg ID 795) ***/
	Rte_Enter_IsSupvDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */
	Rte_Pim_PimIsSupvDiraMsg()->CodeDefaut = Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc();
	Rte_Pim_PimIsSupvDiraMsg()->StatusConfabsent = D_STATUSCONFABSENTDEFAULT_U32;
	Rte_Pim_PimIsSupvDiraMsg()->EtatAssistDa = ETATASSISTDA_Cnt_T_u08;
	Rte_Pim_PimIsSupvDiraMsg()->EtatLigneApc = EPSEn_Cnt_T_lgc;
	Rte_Exit_IsSupvDiraMsg(); /* PRQA S 3112 */ /* PRQA S 3138 */

	/* Below Rte_Pim_PimIsSupvDiraMsg() access doen't have to be covered by Exclusive Area
	 * because this function itself is the only one who writes it and this function is
	 * not reentrant so there is no risk something will modify it in the middle of comparison or copy */
	if (0 != memcmp(&IsSupvDiraPrev, Rte_Pim_PimIsSupvDiraMsg(), sizeof(IS_SUPV_DIRA_Msg)))
	{
		if (FALSE == IsSupvDiraFirstCall_Cnt_M_lgc)
		{
			Rte_Call_SrlComDriver_SCom_SendMsgOnChange(); /* PRQA S 3426 */ /* PRQA S 3417 */ /* PRQA S 3200 */
		}
		(void)memcpy(&IsSupvDiraPrev, Rte_Pim_PimIsSupvDiraMsg(), sizeof(IS_SUPV_DIRA_Msg));
	}
	IsSupvDiraFirstCall_Cnt_M_lgc = FALSE;
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
