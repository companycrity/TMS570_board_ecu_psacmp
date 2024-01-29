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
 *          File:  Rte_NtWrap.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  NtWrap
 *  Generated at:  Thu Feb  8 17:23:56 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <NtWrap> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NTWRAP_H
# define _RTE_NTWRAP_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_NtWrap, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AbsHwPos_SCom_CustClrTrim(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AbsHwPos_SCom_CustSetTrim(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AbsHwPos_SCom_NxtClearTrim(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AvgFricLrn_SCom_InitLearnedTables(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AvgFricLrn_SCom_ResetToZero(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_BatteryVoltage_SCom_ClearTransOvData(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_CmMtrCurr_SCom_CalGain(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_CmMtrCurr_SCom_CalOffset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_IoHwAb_Adc_ResetAdcEnable(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_LrnEOT_Scom_ResetEOT(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComDriver_SCom_ElecIntStart(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComDriver_SCom_ElecIntStop(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_VAR) BusOffCounter_Cnt_T_u16);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComDriver_SCom_SendMsgOnChange(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComInput_SCom_ResetTimers(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_TrqCmdScl_SCom_Set(Float Par_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NtWrap_C_VehDyn_SCom_ResetCenter(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_C_AbsHwPos_SCom_CustClrTrim Rte_Call_NtWrap_C_AbsHwPos_SCom_CustClrTrim
# define Rte_Call_C_AbsHwPos_SCom_CustSetTrim Rte_Call_NtWrap_C_AbsHwPos_SCom_CustSetTrim
# define Rte_Call_C_AbsHwPos_SCom_NxtClearTrim Rte_Call_NtWrap_C_AbsHwPos_SCom_NxtClearTrim
# define Rte_Call_C_AbsHwPos_SCom_NxtSetTrim Rte_Call_NtWrap_C_AbsHwPos_SCom_NxtSetTrim
# define Rte_Call_C_ActivePull_SCom_SetLTComp Rte_Call_NtWrap_C_ActivePull_SCom_SetLTComp
# define Rte_Call_C_ActivePull_SCom_SetSTComp Rte_Call_NtWrap_C_ActivePull_SCom_SetSTComp
# define Rte_Call_C_AstLmt_Scom_ManualTrqCmd Rte_Call_NtWrap_C_AstLmt_Scom_ManualTrqCmd
# define Rte_Call_C_AvgFricLrn_SCom_InitLearnedTables Rte_Call_NtWrap_C_AvgFricLrn_SCom_InitLearnedTables
# define Rte_Call_C_AvgFricLrn_SCom_ResetToZero Rte_Call_NtWrap_C_AvgFricLrn_SCom_ResetToZero
# define Rte_Call_C_AvgFricLrn_SCom_SetEOLFric Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetEOLFric
# define Rte_Call_C_AvgFricLrn_SCom_SetOffsetOutputDefeat Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetOffsetOutputDefeat
# define Rte_Call_C_AvgFricLrn_SCom_SetSelect Rte_Call_NtWrap_C_AvgFricLrn_SCom_SetSelect
# define Rte_Call_C_BatteryVoltage_SCom_ClearTransOvData Rte_Call_NtWrap_C_BatteryVoltage_SCom_ClearTransOvData
# define Rte_Call_C_CmMtrCurr_SCom_CalGain Rte_Call_NtWrap_C_CmMtrCurr_SCom_CalGain
# define Rte_Call_C_CmMtrCurr_SCom_CalOffset Rte_Call_NtWrap_C_CmMtrCurr_SCom_CalOffset
# define Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals Rte_Call_NtWrap_C_CmMtrCurr_SCom_SetMtrCurrCals
# define Rte_Call_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim Rte_Call_NtWrap_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim
# define Rte_Call_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim Rte_Call_NtWrap_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim
# define Rte_Call_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim Rte_Call_NtWrap_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim
# define Rte_Call_C_IoHwAb_Adc_ResetAdcEnable Rte_Call_NtWrap_C_IoHwAb_Adc_ResetAdcEnable
# define Rte_Call_C_LrnEOT_Scom_ResetEOT Rte_Call_NtWrap_C_LrnEOT_Scom_ResetEOT
# define Rte_Call_C_Polarity_SCom_SetPolarity Rte_Call_NtWrap_C_Polarity_SCom_SetPolarity
# define Rte_Call_C_PsaAgArbn_SCom_PsaAaCmd Rte_Call_NtWrap_C_PsaAgArbn_SCom_PsaAaCmd
# define Rte_Call_C_SCom_EOLNomMtrParam_Set Rte_Call_NtWrap_C_SCom_EOLNomMtrParam_Set
# define Rte_Call_C_SrlComDriver_SCom_ElecIntStart Rte_Call_NtWrap_C_SrlComDriver_SCom_ElecIntStart
# define Rte_Call_C_SrlComDriver_SCom_ElecIntStop Rte_Call_NtWrap_C_SrlComDriver_SCom_ElecIntStop
# define Rte_Call_C_SrlComDriver_SCom_GetBusOffCounter Rte_Call_NtWrap_C_SrlComDriver_SCom_GetBusOffCounter
# define Rte_Call_C_SrlComDriver_SCom_SendMsgOnChange Rte_Call_NtWrap_C_SrlComDriver_SCom_SendMsgOnChange
# define Rte_Call_C_SrlComInput_SCom_ManualVehSpd Rte_Call_NtWrap_C_SrlComInput_SCom_ManualVehSpd
# define Rte_Call_C_SrlComInput_SCom_ResetTimers Rte_Call_NtWrap_C_SrlComInput_SCom_ResetTimers
# define Rte_Call_C_SrlComInput_SCom_VehSpdControl Rte_Call_NtWrap_C_SrlComInput_SCom_VehSpdControl
# define Rte_Call_C_TrqCanc_Scom_SetCogTrqCal Rte_Call_NtWrap_C_TrqCanc_Scom_SetCogTrqCal
# define Rte_Call_C_TrqCmdScl_SCom_Set Rte_Call_NtWrap_C_TrqCmdScl_SCom_Set
# define Rte_Call_C_VehDyn_SCom_ResetCenter Rte_Call_NtWrap_C_VehDyn_SCom_ResetCenter




# define RTE_START_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_CustClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustClrTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_CustClrTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AbsHwPos_SCom_CustClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustClrTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_CustSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_CustSetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AbsHwPos_SCom_CustSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustSetTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_NxtClearTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtClearTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_NxtClearTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AbsHwPos_SCom_NxtClearTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtClearTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_NxtSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AbsHwPos_SCom_TrimNotPerformed, RTE_E_AbsHwPos_SCom_ValueNotAccepted
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *   RTE_E_AbsHwPos_SCom_ValueNotAccepted
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_ActivePull_SCom_SetLTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLTComp> of PortPrototype <ActivePull_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_ActivePull_SCom_SetSTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSTComp> of PortPrototype <ActivePull_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AstLmt_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AstLmt_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH, RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_InitLearnedTables
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitLearnedTables> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_InitLearnedTables(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_ResetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToZero> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_ResetToZero(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_ResetToZero(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_ResetToZero(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLFric> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSelect> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_BatteryVoltage_SCom_ClearTransOvData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearTransOvData> of PortPrototype <BatteryVoltage_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_BatteryVoltage_SCom_ClearTransOvData(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_CalGain(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_CalOffset(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr_SCom_CalOffset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_ClrTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_SetTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTqArbn_SCom_SetTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_SetTrqTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_IoHwAb_Adc_ResetAdcEnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetAdcEnable> of PortPrototype <IoHwAb_Adc>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_IoHwAb_Adc_ResetAdcEnable(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_IoHwAb_Adc_ResetAdcEnable(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_IoHwAb_Adc_ResetAdcEnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_LrnEOT_Scom_ResetEOT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetEOT> of PortPrototype <LrnEOT_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_LrnEOT_Scom_ResetEOT(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_PsaAgArbn_SCom_PsaAaCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PsaAaCmd> of PortPrototype <PsaAgArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_ElecIntStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStart> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_ElecIntStart(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_ElecIntStop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStop> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_ElecIntStop(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_SendMsgOnChange
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendMsgOnChange> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_SendMsgOnChange(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_SendMsgOnChange(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_SendMsgOnChange(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_ResetTimers(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ResetTimers(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_TrqCanc_Scom_SetCogTrqCal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCogTrqCal> of PortPrototype <TrqCanc_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
# else
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
# endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
# else
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_TrqCmdScl_SCom_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TrqCmdScl_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TrqCmdScl_SCom_Set(Float Par_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_VehDyn_SCom_ResetCenter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetCenter> of PortPrototype <VehDyn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_VehDyn_SCom_ResetCenter(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_VehDyn_SCom_ResetCenter(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ResetCenter(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrap_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void);

# define RTE_STOP_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_AbsHwPos_SCom_TrimNotPerformed (34U)

# define RTE_E_AbsHwPos_SCom_ValueNotAccepted (49U)

# define RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH (34U)

# define RTE_E_AssistLmtFunc_Scom_RTE_E_OK (1U)

# define RTE_E_CmMtrCurr_SCom_ConditionNotCorrect (34U)

# define RTE_E_CmMtrCurr_SCom_CurrentOutOfRange (20U)

# define RTE_E_CmMtrCurr_SCom_VehSpdOutofRange (21U)

# define RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect (34U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1518103309
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/NtWrap/utp/contract/NtWrap/Rte_NtWrap.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1518103309
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_NTWRAP_H */
