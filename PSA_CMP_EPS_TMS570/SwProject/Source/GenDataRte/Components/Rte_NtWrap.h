/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_NtWrap.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NTWRAP_H
# define _RTE_NTWRAP_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_CustClrTrim(void);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SCom_CustClrTrim() (AbsHwPos_SCom_CustClrTrim(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_CustSetTrim(void);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SCom_CustSetTrim AbsHwPos_SCom_CustSetTrim
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_NxtClearTrim(void);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SCom_NxtClearTrim() (AbsHwPos_SCom_NxtClearTrim(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SCom_NxtSetTrim AbsHwPos_SCom_NxtSetTrim
#  define RTE_START_SEC_AP_ACTIVEPULL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
#  define RTE_STOP_SEC_AP_ACTIVEPULL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_ActivePull_SCom_SetLTComp(arg1) (ActivePull_SCom_SetLTComp(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ACTIVEPULL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
#  define RTE_STOP_SEC_AP_ACTIVEPULL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_ActivePull_SCom_SetSTComp(arg1) (ActivePull_SCom_SetSTComp(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
#  define RTE_STOP_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AstLmt_Scom_ManualTrqCmd AstLmt_Scom_ManualTrqCmd
#  define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void);
#  define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AvgFricLrn_SCom_InitLearnedTables() (AvgFricLrn_SCom_InitLearnedTables(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void);
#  define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AvgFricLrn_SCom_ResetToZero() (AvgFricLrn_SCom_ResetToZero(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
#  define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AvgFricLrn_SCom_SetEOLFric(arg1) (AvgFricLrn_SCom_SetEOLFric(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
#  define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(arg1) (AvgFricLrn_SCom_SetOffsetOutputDefeat(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
#  define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AvgFricLrn_SCom_SetSelect(arg1, arg2, arg3) (AvgFricLrn_SCom_SetSelect(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_BATTERYVOLTAGE_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_SCom_ClearTransOvData(void);
#  define RTE_STOP_SEC_AP_BATTERYVOLTAGE_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_BatteryVoltage_SCom_ClearTransOvData() (BatteryVoltage_SCom_ClearTransOvData(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalGain(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_CalGain CmMtrCurr_SCom_CalGain
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalOffset(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_CalOffset CmMtrCurr_SCom_CalOffset
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals(arg1) (CmMtrCurr_SCom_SetMtrCurrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(void);
#  define RTE_STOP_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
#  define RTE_START_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(void);
#  define RTE_STOP_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
#  define RTE_START_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32);
#  define RTE_STOP_SEC_SA_HWTQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim(arg1) (HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_IOHWAB9_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_IOHWAB9_APPL_CODE) IoHwAb_Adc_ResetAdcEnable(void);
#  define RTE_STOP_SEC_IOHWAB9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_IoHwAb_Adc_ResetAdcEnable() (IoHwAb_Adc_ResetAdcEnable(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);
#  define RTE_STOP_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_LrnEOT_Scom_ResetEOT() (LrnEOT_Scom_ResetEOT(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
#  define RTE_STOP_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_Polarity_SCom_SetPolarity(arg1) (Polarity_SCom_SetPolarity(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_PSAAGARBN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum);
#  define RTE_STOP_SEC_AP_PSAAGARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_PsaAgArbn_SCom_PsaAaCmd(arg1) (PsaAgArbn_SCom_PsaAaCmd(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
#  define RTE_STOP_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_EOLNomMtrParam_Set(arg1, arg2) (SCom_EOLNomMtrParam_Set(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void);
#  define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComDriver_SCom_ElecIntStart() (SrlComDriver_SCom_ElecIntStart(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void);
#  define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComDriver_SCom_ElecIntStop() (SrlComDriver_SCom_ElecIntStop(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16);
#  define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComDriver_SCom_GetBusOffCounter(arg1) (SrlComDriver_SCom_GetBusOffCounter(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_SendMsgOnChange(void);
#  define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComDriver_SCom_SendMsgOnChange() (SrlComDriver_SCom_SendMsgOnChange(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);
#  define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComInput_SCom_ManualVehSpd(arg1) (SrlComInput_SCom_ManualVehSpd(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void);
#  define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComInput_SCom_ResetTimers() (SrlComInput_SCom_ResetTimers(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);
#  define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComInput_SCom_VehSpdControl(arg1) (SrlComInput_SCom_VehSpdControl(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif
#  define RTE_STOP_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(arg1, arg2) (TrqCanc_Scom_SetCogTrqCal(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
#  define RTE_STOP_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCmdScl_SCom_Set(arg1) (TrqCmdScl_SCom_Set(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHDYN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_VEHDYN_APPL_CODE) VehDyn_SCom_ResetCenter(void);
#  define RTE_STOP_SEC_AP_VEHDYN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_VehDyn_SCom_ResetCenter() (VehDyn_SCom_ResetCenter(), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustClrTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustSetTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtClearTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_ResetToZero(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_SetTrqTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_IoHwAb_Adc_ResetAdcEnable(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_SendMsgOnChange(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ResetTimers(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ResetCenter(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void);

# define RTE_STOP_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AbsHwPos_SCom_TrimNotPerformed (34U)

#  define RTE_E_AbsHwPos_SCom_ValueNotAccepted (49U)

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH (34U)

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_OK (1U)

#  define RTE_E_CmMtrCurr_SCom_ConditionNotCorrect (34U)

#  define RTE_E_CmMtrCurr_SCom_CurrentOutOfRange (20U)

#  define RTE_E_CmMtrCurr_SCom_VehSpdOutofRange (21U)

#  define RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect (34U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_NTWRAP_H */
