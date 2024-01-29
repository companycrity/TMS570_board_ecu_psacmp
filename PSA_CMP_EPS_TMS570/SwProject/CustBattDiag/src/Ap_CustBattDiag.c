/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_CustBattDiag.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_CustBattDiag
 *  Generated at:  Thu Nov  2 14:14:07 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_CustBattDiag>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
* %version:          5 %
* %derived_by:       nz3337 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                               CR#
* --------  -------  --------  -------------------------------------------------------------------------------  ------
* 09/19/14   1       SAH       Initial version for PSA BMPV - Based on draft SCIR Rev 001C                      12267
* 01/14/15   2       OT        Changed DefaultVehSpd input to use VehicleSpeedValid instead, cleanup            12862
* 07/16/15   3       OT        Updates for SCIR 003B                                                            13475
* 09/14/15   4       OT        Corrected E8 timer criteria                                                   EA3#2957
* 11/04/15   5       OT        Implement NTC E9                                                              EA3#4186
* 11/24/15   6       OT        Corrected cals for NTC E9                                                     EA3#4835
* 04/29/16   7       WH        Updated test enable criteria for E0-E9, removed E3/E4                         EA3#7994
* 05/14/16   8       WH        Updated NTC activation conditions for E1,E2			                         EA3#7994
* 05/17/16   9       WH        Updated NTC activation conditions for E1,E2			                         EA3#7994
* 05/18/16   10      WH        Updated NTC E1 bug			                                                 EA3#7994
* 03/22/17   11      AR        Calibration name changes			                                             EA3#14801
* 12/11/17   12      RK        Changed battery diatnostic window (time window applied only for voltage
*                              conditions) for NTC E0, E1, E2, E6 and E9. Refactoring for E5, E7 and E8.     EA3#18425
* 04/09/18   5       MB        Fix for low path coverage issues found in Unit Tests							 EA3# 19854
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


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_CustBattDiag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "il_inc.h"
#include "fixmath.h"
#include "CalConstants.h"


#define D_TESTFAILED_CNT_U08	0u
#define D_TESTPASSED_CNT_U08	1u
#define	D_INDEADBAND_CNT_U08  	2u

#define D_NTC_E0_FAILURE_ETAT_MT_FLAG_CNT_U16	\
/*0x2*/(((uint16)1U << kETAT_MT_Starting            ) | \
/*0x5*/ ((uint16)1U << kETAT_MT_Driven_Restart      ) | \
/*0x6*/ ((uint16)1U << kETAT_MT_Degraded_Restart    ) | \
/*0xA*/ ((uint16)1U << kETAT_MT_Autonomous_Starting ) | \
/*0xD*/ ((uint16)1U << kETAT_MT_Autonomous_Restart  ))

#define D_NTC_E1_FAILURE_ETAT_MT_FLAG_CNT_U16	\
/*0x1*/(((uint16)1U << kETAT_MT_Cut                 ) | \
/*0x3*/ ((uint16)1U << kETAT_MT_Engine_Running      ))

#define D_NTC_E2_FAILURE_ETAT_MT_FLAG_CNT_U16	\
/*0x1*/(((uint16)1U << kETAT_MT_Cut                 ) | \
/*0x3*/ ((uint16)1U << kETAT_MT_Engine_Running      ) | \
/*0x4*/ ((uint16)1U << kETAT_MT_Stopped             ) | \
/*0x5*/ ((uint16)1U << kETAT_MT_Driven_Restart      ) | \
/*0x6*/ ((uint16)1U << kETAT_MT_Degraded_Restart    ) | \
/*0xD*/ ((uint16)1U << kETAT_MT_Autonomous_Restart  ))

#define D_NTC_E6_FAILURE_ETAT_MT_FLAG_CNT_U16	\
/*0x4*/ ((uint16)1U << kETAT_MT_Stopped)

#define D_NTC_E9_FAILURE_ETAT_MT_FLAG_CNT_U16	\
/*0x1*/(((uint16)1U << kETAT_MT_Cut                 ) | \
/*0x3*/ ((uint16)1U << kETAT_MT_Engine_Running      ) | \
/*0x4*/ ((uint16)1U << kETAT_MT_Stopped             ))

/* Those are artificial/imaginary voltages used for ignition voltage.
 * Status of ignition voltage is evaluated base on some high level logic signal instead
 * of real voltage measurement. Those conditions are mapped to below voltages
 * and this way they can be qualified as any other voltage signal.
 * Whole this thing is done to have common way of fault qualification */
#define D_IMAGINARY_IGN_ON_VOLTS_U10P6			(FPM_InitFixedPoint_m( 12.0f, u10p6_T))
#define D_IMAGINARY_IGN_ON_VOLTS_THRESH_U10P6	(FPM_InitFixedPoint_m(  8.0f, u10p6_T))
#define D_IMAGINARY_IGN_UNKNWN_VOLTS_U10P6		(FPM_InitFixedPoint_m(  6.0f, u10p6_T))
#define D_IMAGINARY_IGN_OFF_VOLTS_THRESH_U10P6	(FPM_InitFixedPoint_m(  4.0f, u10p6_T))
#define D_IMAGINARY_IGN_OFF_VOLTS_U10P6			(FPM_InitFixedPoint_m(  0.0f, u10p6_T))

typedef enum{
	CustBattDiagNtc_E0,
	CustBattDiagNtc_E1,
	CustBattDiagNtc_E2,
	CustBattDiagNtc_E5,
	CustBattDiagNtc_E6,
	CustBattDiagNtc_E7,
	CustBattDiagNtc_E8,
	CustBattDiagNtc_E9,
	CustBattDiagNtc_No
} CustBattDiagNtc_T;

typedef struct {
	const uint16	*upperWindowThresh_Cnt_u16;
	const u10p6_T	*upperVoltage_volt_u10p6;
	const uint16	*lowerWindowThresh_Cnt_u16;
	const u10p6_T	*lowerVoltage_volt_u10p6;
	const NTCNumber NtcNum;
	const NxtrDiagMgrStatus upperStatus;
	const NxtrDiagMgrStatus lowerStatus;
} CustBattDiagNtcConfig_T;

typedef struct {
	uint32 detectWindow_Cnt_M_u32;
	uint32 notDetectWindow_Cnt_M_u32;
} CustBattDiagNtcTimer_T;

#define CUSTBATTDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(CustBattDiagNtcTimer_T, AP_CUSTBATTDIAG_VAR) CustBattDiagNtcTimer_Str[CustBattDiagNtc_No]; /* PRQA S 3218 */
#define CUSTBATTDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define CUSTBATTDIAG_START_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */
/* Those are thresholds for imaginary Ignition Voltage */
STATIC CONST(u10p6_T, AP_CUSTBATTDIAG_CONST) k_LOINotDetect_Volts_u10p6 =	D_IMAGINARY_IGN_ON_VOLTS_THRESH_U10P6;
STATIC CONST(u10p6_T, AP_CUSTBATTDIAG_CONST) k_LOIDetect_Volts_u10p6 = 		D_IMAGINARY_IGN_OFF_VOLTS_THRESH_U10P6;
#define CUSTBATTDIAG_STOP_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */

#define CUSTBATTDIAG_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(CustBattDiagNtcConfig_T, AP_CUSTBATTDIAG_CONST) CustBattDiagNtcConfig_Str[CustBattDiagNtc_No] = /* PRQA S 3218 */
{
	{	/* CustBattDiagNtc_E0 */
		&k_LVCNotDetect_ms_u16p0,
		&k_LVCNotDetect_Volts_u10p6,
		&k_LVCDetect_ms_u16p0,
		&k_LVCDetect_Volts_u10p6,
		NTC_Num_VLF_00,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E1 */
		&k_LVHSNotDetect_ms_u16p0,
		&k_LVHSNotDetect_Volts_u10p6,
		&k_LVHSDetect_ms_u16p0,
		&k_LVHSDetect_Volts_u10p6,
		NTC_Num_VLF_01,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E2 */
		&k_LVLSNotDetect_ms_u16p0,
		&k_LVLSNotDetect_Volts_u10p6,
		&k_LVLSDetect_ms_u16p0,
		&k_LVLSDetect_Volts_u10p6,
		NTC_Num_VLF_02,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E5 */
		&k_CBDiagc_UnderVltgNotDetd_mS_u16p0,
		&k_UVNotDetect_Volts_u10p6,
		&k_CBDiagc_UnderVltgDetd_mS_u16p0,
		&k_UVDetect_Volts_u10p6,
		NTC_Num_VLF_05,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E6 */
		&k_LVSMNotDetect_ms_u16p0,
		&k_LVSMNotDetect_Volts_u10p6,
		&k_LVSMDetect_ms_u16p0,
		&k_LVSMDetect_Volts_u10p6,
		NTC_Num_VLF_06,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E7 */
		&k_CBDiagc_OverVltgDetd_mS_u16p0,
		&k_CBDiagc_OverVltgDetd_Volt_u10p6,
		&k_CBDiagc_OverVltgNotDetd_mS_u16p0,
		&k_CBDiagc_OverVltgNotDetd_Volt_u10p6,
		NTC_Num_VLF_07,
		NTC_STATUS_FAILED,
		NTC_STATUS_PASSED /* This is over voltage fault. Lower range is OK */
	},
	{	/* CustBattDiagNtc_E8 */
		&k_LOINotDetect_ms_u16p0,
		&k_LOINotDetect_Volts_u10p6,
		&k_LOIDetect_ms_u16p0,
		&k_LOIDetect_Volts_u10p6,
		NTC_Num_VLF_08,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	},
	{	/* CustBattDiagNtc_E9 */
		&k_LVNNotDetect_ms_u16p0,
		&k_LVNNotDetect_Volts_u10p6,
		&k_LVNDetect_ms_u16p0,
		&k_LVNDetect_Volts_u10p6,
		NTC_Num_VLF_09,
		NTC_STATUS_PASSED, /* This is under voltage fault. Upper range is OK */
		NTC_STATUS_FAILED
	}
};
#define CUSTBATTDIAG_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, AP_CUSTBATTDIAG_CODE) CustBattDiag_ReportFaultWithHisteresis(
														VAR(CustBattDiagNtc_T, AUTOMATIC) ntc,
		 	 	 	 	 	 	 	 	 	 	 	 	VAR(boolean, AUTOMATIC) lowVoltageExtraCryteria_Cnt_T_lgc,
													/*	VAR(boolean, AUTOMATIC) highVoltageExtraCryteria_Cnt_T_lgc,	*/ /* For now deactivated cause no one uses it */
														VAR(u10p6_T, AUTOMATIC) Voltage_Volts_T_u10p6,
														VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32);


STATIC FUNC(u10p6_T, AP_CUSTBATTDIAG_CODE) CustBattDiag_GetImaginaryIgnVoltage(
														VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
														VAR(boolean, AUTOMATIC) EngOn_Cnt_T_lgc,
														VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32);

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


#define RTE_START_SEC_AP_CUSTBATTDIAG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustBattDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CustBattDiag_Per1_Batt_Volt_f32(void)
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

FUNC(void, RTE_AP_CUSTBATTDIAG_APPL_CODE) CustBattDiag_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CustBattDiag_Per1
 *********************************************************************************************************************/
	
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	VAR(float32, AUTOMATIC) BattVoltage_Volts_T_f32;
	VAR(uint16,  AUTOMATIC) BattVoltage_Volts_T_u10p6;
	
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */

	BattVoltage_Volts_T_f32 = Rte_IRead_CustBattDiag_Per1_Batt_Volt_f32();
	BattVoltage_Volts_T_u10p6 = FPM_FloatToFixed_m(BattVoltage_Volts_T_f32, u10p6_T); /* PRQA S 4395 */
	
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E5, TRUE, /* TRUE ,*/ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E7, TRUE, /* TRUE ,*/ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustBattDiag_Per2
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
 *   Float Rte_IRead_CustBattDiag_Per2_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_CTerm_Cnt_lgc(void)
 *   UInt8 Rte_IRead_CustBattDiag_Per2_DmdDelestDa_Cnt_u08(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_EngOn_Cnt_lgc(void)
 *   UInt8 Rte_IRead_CustBattDiag_Per2_EtatMT_Cnt_u08(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_SttdSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_CustBattDiag_Per2_VehicleSpeed_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTBATTDIAG_APPL_CODE) CustBattDiag_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CustBattDiag_Per2
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) BattVoltage_Volts_T_f32;
	VAR(u10p6_T,  AUTOMATIC) BattVoltage_Volts_T_u10p6;
	VAR(boolean, AUTOMATIC) EngOn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SttdSelcted_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) E0TestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) E1TestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) E2TestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) E6TestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) E9TestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC)	EtatMtBitfield_Cnt_T_u16;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(uint16,  AUTOMATIC)	ElapsedTime_T_u16p0;
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	VAR(boolean, AUTOMATIC) ValidEngineStatus_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) CTerm_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) DmdDelest_Cnt_T_u08;	   
    VAR(boolean, AUTOMATIC) InvalidMsg_Cnt_T_u08;
    VAR(boolean, AUTOMATIC) MissingMsg_Cnt_T_u08;
    VAR(boolean, AUTOMATIC) InvalidPwrCutReq_Cnt_T_u08;
    VAR(u10p6_T, AUTOMATIC) ImaginaryIgn_Volts_T_u10p6;

	BattVoltage_Volts_T_f32 = Rte_IRead_CustBattDiag_Per2_Batt_Volt_f32();
	BattVoltage_Volts_T_u10p6 = FPM_FloatToFixed_m(BattVoltage_Volts_T_f32, u10p6_T); /* PRQA S 4395 */

	VehSpd_Kph_T_f32 = Rte_IRead_CustBattDiag_Per2_VehicleSpeed_Kph_f32();
	EngOn_Cnt_T_lgc = Rte_IRead_CustBattDiag_Per2_EngOn_Cnt_lgc();
	EtatMtBitfield_Cnt_T_u16 = (uint16)1u << Rte_IRead_CustBattDiag_Per2_EtatMT_Cnt_u08();
	SttdSelcted_Cnt_T_lgc = Rte_IRead_CustBattDiag_Per2_SttdSelected_Cnt_lgc();
	ValidEngineStatus_Cnt_T_lgc = Rte_IRead_CustBattDiag_Per2_ValidEngineStatus_Cnt_lgc();
	VehSpdValid_Cnt_T_lgc = Rte_IRead_CustBattDiag_Per2_VehicleSpeedValid_Cnt_lgc();
    CTerm_Cnt_T_lgc = Rte_IRead_CustBattDiag_Per2_CTerm_Cnt_lgc();
    DmdDelest_Cnt_T_u08 = Rte_IRead_CustBattDiag_Per2_DmdDelestDa_Cnt_u08();
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3417 */ /* PRQA S 3426 */
    (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_Q, &InvalidMsg_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_Q, &MissingMsg_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_Q, &InvalidPwrCutReq_Cnt_T_u08);
	
    /* Handling NTC 0xE8 - Loss of Ignition */
	ImaginaryIgn_Volts_T_u10p6 = CustBattDiag_GetImaginaryIgnVoltage(SystemState_Cnt_T_enum, EngOn_Cnt_T_lgc, VehSpd_Kph_T_f32);
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E8, TRUE, /* TRUE ,*/ ImaginaryIgn_Volts_T_u10p6, SystemTime_mS_T_u32);
	
	/* Handling NTCs E0, E1, E2, E9 */
	E0TestStatus_Cnt_T_u08 = FALSE;
	E1TestStatus_Cnt_T_u08 = FALSE;
	E2TestStatus_Cnt_T_u08 = FALSE;
	E9TestStatus_Cnt_T_u08 = FALSE;

	if ((TRUE == CTerm_Cnt_T_lgc) &&
		(((uint8)kDMD_DELEST_DA_Not_Requested == DmdDelest_Cnt_T_u08) ||
		 (TRUE == MissingMsg_Cnt_T_u08)								  ||
		 (TRUE == InvalidPwrCutReq_Cnt_T_u08)						  ||
		 (TRUE == InvalidMsg_Cnt_T_u08) 								) )
	{
		if ((ValidEngineStatus_Cnt_T_lgc == TRUE) &&
			(0u != (EtatMtBitfield_Cnt_T_u16 & D_NTC_E0_FAILURE_ETAT_MT_FLAG_CNT_U16)))
		{
			E0TestStatus_Cnt_T_u08 = TRUE;
		}

		if ((ValidEngineStatus_Cnt_T_lgc == FALSE) ||
			(0u != (EtatMtBitfield_Cnt_T_u16 & D_NTC_E1_FAILURE_ETAT_MT_FLAG_CNT_U16)))
		{
			if (VehSpdValid_Cnt_T_lgc == TRUE)
			{
				if (VehSpd_Kph_T_f32 > k_CustBattDiaghispd_kph_f32)
				{
					E1TestStatus_Cnt_T_u08 = TRUE;
				}
			}
			else
			{
				if (SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE)
				{
					E1TestStatus_Cnt_T_u08 = TRUE;
				}
			}
		}

		if ((ValidEngineStatus_Cnt_T_lgc == FALSE) ||
			(0u != (EtatMtBitfield_Cnt_T_u16 & D_NTC_E2_FAILURE_ETAT_MT_FLAG_CNT_U16)))
		{
			if ((VehSpdValid_Cnt_T_lgc == TRUE) &&
				(VehSpd_Kph_T_f32 <= k_CustBattDiaglospd_kph_f32))
			{
				E2TestStatus_Cnt_T_u08 = TRUE;
			}
		}

		if ((ValidEngineStatus_Cnt_T_lgc == FALSE) ||
			(0u != (EtatMtBitfield_Cnt_T_u16 & D_NTC_E9_FAILURE_ETAT_MT_FLAG_CNT_U16)))
		{
			E9TestStatus_Cnt_T_u08 = TRUE;
		}
	}
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E0, E0TestStatus_Cnt_T_u08, /* TRUE, */ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E1, E1TestStatus_Cnt_T_u08, /* TRUE, */ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E2, E2TestStatus_Cnt_T_u08, /* TRUE, */ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E9, E9TestStatus_Cnt_T_u08, /* TRUE, */ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);

	/* Handling NTC E6 */
	E6TestStatus_Cnt_T_u08 = FALSE;

	if (SttdSelcted_Cnt_T_lgc == FALSE)
	{
		if ((ValidEngineStatus_Cnt_T_lgc == TRUE) &&
			(0u != (EtatMtBitfield_Cnt_T_u16 & D_NTC_E6_FAILURE_ETAT_MT_FLAG_CNT_U16)))
		{
			E6TestStatus_Cnt_T_u08 = TRUE;
		}
		CustBattDiag_ReportFaultWithHisteresis(CustBattDiagNtc_E6, E6TestStatus_Cnt_T_u08, /* TRUE, */ BattVoltage_Volts_T_u10p6, SystemTime_mS_T_u32);
	}

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_CUSTBATTDIAG_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Name          : CustBattDiag_ReportFaultWithHisteresis
 * Description   : For given NTC, basing on given conditions and voltage level, function qualifies/dequalifies fault
 *                 applying hysteresis on voltage and taking conditions straight (no hysteresis).
 * Inputs        : Input parameters:
 *                  CustBattDiagNtc_T ntc - enumerator selecting NTC configuration to be processed
 * 					boolean lowVoltageExtraCryteria_Cnt_T_lgc - logical condition to be met to qualify voltage
 * 					 to be under low voltage level. ("to be met" == TRUE)
 * 					boolean highVoltageExtraCryteria_Cnt_T_lgc - logical condition to be met to qualify voltage
 * 					 to be above high voltage level. ("to be met" == TRUE)
 * 					 (for now it's commented out cause no one is using it)
 * 					u10p6 Voltage_Volts_T_u10p6 - voltage signal for given ntc
 * 					uint32 SystemTime_mS_T_u32 - system time (product of Rte_Call_SystemTime_GetSystemTime_mS_u32)
 * 				   Static configuration:
 * 				    CustBattDiagNtcTimer_T CustBattDiagNtcTimer_Str - array with configuration for NTCs defined in
 * 				     enum CustBattDiagNtc_T
 * 				    CustBattDiagNtcTimer_T CustBattDiagNtcConfig_Str - static array with runtime parameters (timers)
 * 				     for NTCs defined in enum CustBattDiagNtc_T
 *
 * Outputs       : Status of the NTC configured in CustBattDiagNtcConfig_Str pointed by ntc input parameter
 *                 gets status reported via Rte_Call_NxtrDiagMgr_SetNTCStatus function.
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, AP_CUSTBATTDIAG_CODE) CustBattDiag_ReportFaultWithHisteresis(
														VAR(CustBattDiagNtc_T, AUTOMATIC) ntc,
		 	 	 	 	 	 	 	 	 	 	 	 	VAR(boolean, AUTOMATIC) lowVoltageExtraCryteria_Cnt_T_lgc,
													/*	VAR(boolean, AUTOMATIC) highVoltageExtraCryteria_Cnt_T_lgc,	*/ /* For now deactivated cause no one uses it */
														VAR(u10p6_T, AUTOMATIC) Voltage_Volts_T_u10p6,
														VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32)
{
	VAR(uint16,  AUTOMATIC)	ElapsedTime_Cnt_T_u16;

	/* Qualifying to lower limit */

	if ((FALSE == lowVoltageExtraCryteria_Cnt_T_lgc) ||
	    ( *(CustBattDiagNtcConfig_Str[ntc].lowerVoltage_volt_u10p6) <= Voltage_Volts_T_u10p6 ))
	{	/* Outside lower limit, reset timer */
		CustBattDiagNtcTimer_Str[ntc].detectWindow_Cnt_M_u32 = SystemTime_mS_T_u32;
	}
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CustBattDiagNtcTimer_Str[ntc].detectWindow_Cnt_M_u32, &ElapsedTime_Cnt_T_u16); /* PRQA S 3417 */ /* PRQA S 3426 */

	if (*(CustBattDiagNtcConfig_Str[ntc].lowerWindowThresh_Cnt_u16) <= ElapsedTime_Cnt_T_u16 )
	{
		/* Extra criteria met, time saturation succeeded */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(CustBattDiagNtcConfig_Str[ntc].NtcNum, 0x0U, CustBattDiagNtcConfig_Str[ntc].lowerStatus);
	}


	/* Qualifying to upper limit */

	if (/*(FALSE == highVoltageExtraCryteria_Cnt_T_lgc) || */ /* For now deactivated cause no one uses it */
		( *(CustBattDiagNtcConfig_Str[ntc].upperVoltage_volt_u10p6) >= Voltage_Volts_T_u10p6 ))
	{	/* Outside upper limit, reset timer */
		CustBattDiagNtcTimer_Str[ntc].notDetectWindow_Cnt_M_u32 = SystemTime_mS_T_u32;
	}
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CustBattDiagNtcTimer_Str[ntc].notDetectWindow_Cnt_M_u32, &ElapsedTime_Cnt_T_u16); /* PRQA S 3417 */ /* PRQA S 3426 */

	if (*(CustBattDiagNtcConfig_Str[ntc].upperWindowThresh_Cnt_u16) <= ElapsedTime_Cnt_T_u16 )
	{
		/* Extra criteria met, time saturation succeeded */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(CustBattDiagNtcConfig_Str[ntc].NtcNum, 0x0U,  CustBattDiagNtcConfig_Str[ntc].upperStatus);
	}
}


/***********************************************************************************************************************
 * Name          : CustBattDiag_GetImaginaryIgnVoltage
 * Description   : Function converts high level logic signal conditions given on input to artificial ignition voltage
 *                 level which later can be qualified by generic functionality of this component.
 *
 * Inputs        : Input parameters:
 *                  Rte_ModeType_StaMd_Mode SystemState_Cnt_T_enum - system state from Rte_Mode_SystemState_Mode()
 * 					boolean EngOn_Cnt_T_lgc - EngOn status from Rte_IRead_CustBattDiag_Per2_EngOn_Cnt_lgc()
 * 					float32 VehSpd_Kph_T_f32 - Vehicle speed from Rte_IRead_CustBattDiag_Per2_VehicleSpeed_Kph_f32()
 * 				   Calibration parameters:
 * 				    k_CustBattDiagLOIspd_kph_f32 - used for Vehicle Speed qualification
 * Outputs       : Artificial/imaginary Ignition voltage
 * Usage Notes   : none
 **********************************************************************************************************************/
STATIC FUNC(u10p6_T, AP_CUSTBATTDIAG_CODE) CustBattDiag_GetImaginaryIgnVoltage(
														VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
														VAR(boolean, AUTOMATIC) EngOn_Cnt_T_lgc,
														VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32)
{
    VAR(u10p6_T, AUTOMATIC) ImaginaryIgn_Volts_T_u10p6;
	VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc;

	(void)Rte_Call_EpsEn_OP_GET(&EpsEn_Cnt_T_lgc);

	if( SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE )
	{
		if( EpsEn_Cnt_T_lgc == TRUE )
		{
			ImaginaryIgn_Volts_T_u10p6 = D_IMAGINARY_IGN_ON_VOLTS_U10P6;
		}
		else
		{
			if( (EngOn_Cnt_T_lgc == TRUE) ||
				(VehSpd_Kph_T_f32 > k_CustBattDiagLOIspd_kph_f32) )
			{
				ImaginaryIgn_Volts_T_u10p6 = D_IMAGINARY_IGN_OFF_VOLTS_U10P6;
			}
			else
			{
				ImaginaryIgn_Volts_T_u10p6 = D_IMAGINARY_IGN_UNKNWN_VOLTS_U10P6;
			}
		}
	}
	else
	{
		ImaginaryIgn_Volts_T_u10p6 = D_IMAGINARY_IGN_UNKNWN_VOLTS_U10P6;
	}

	return ImaginaryIgn_Volts_T_u10p6;
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
