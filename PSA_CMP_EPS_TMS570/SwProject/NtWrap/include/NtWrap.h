/*******************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : NtWrap.h
* Module Description: Non-trusted function call wrapper definitions to allow
*						calling of SCom server functions not located in the
*						application with the Diag service handler.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*******************************************************************************/
/*******************************************************************************
* Version Control:
* %version:          6 %
* %derived_by:       nz3337 %
*-------------------------------------------------------------------------------
* Change History:
  * Date      Rev      Author    Change Description                                CR
* --------  -------  --------  -----------------------------------------           -----
* 06/07/16   1       WH        Initial version
* 07/27/16   2       WH        Updated for new NHET/epwm/polarity comps            EA3#9275
* 08/30/16   4       WH        Updated for FD30 and F004 function prototypes       EA3#10606
*******************************************************************************/

#ifndef NTWRAP_H
#define NTWRAP_H

#include "Std_Types.h"
#include "Rte_Type.h"
#include "Dem.h"
#include "Os.h"
#include "Wdg_TMS570LS3x.h"
#include "WdgM.h"


/***** RTE Client Function Prototypes *****/

extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustClrTrim(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustSetTrim(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtClearTrim(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_ResetToZero(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void);
extern FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_SetTrqTrim(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_IoHwAb_Adc_ResetAdcEnable(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ResetTimers(void);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);
extern FUNC(void,           RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ResetCenter(void);


/***** Non-RTE Client Function Prototypes *****/

extern FUNC(Dem_ReturnClearDTCType, NTWRAP_CODE) NtWrapC_Dem_ClearDTC(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);
extern FUNC(void, NTWRAP_CODE) TWrapC_CallFblStart(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_Adc_Init( void * ConfigSet );
extern FUNC(void, NTWRAP_CODE) TWrapC_Adc2_Init1(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_PwmCdd_Init(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_StaMd_Init0(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_Wdg_TMS570LS3x_Init( P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr );
extern FUNC(void, NTWRAP_CODE) TWrapC_WdgM_Init( P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr );
extern FUNC(void, NTWRAP_CODE) TWrapC_NvMProxy_Init(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_Dma_InvalidateSlowADCGroup(void);
extern FUNC(void, NTWRAP_CODE) TWrapC_ProcessF0FF( P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16);


/***** Non-Trusted Function Prototypes *****/

extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp6( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp9( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp10( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp11( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_CustClrTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_CustSetTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_NxtClearTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_NxtSetTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_ActivePull_SCom_SetLTComp( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_ActivePull_SCom_SetSTComp( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AstLmt_Scom_ManualTrqCmd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_InitLearnedTables( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_ResetToZero( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetOffsetOutputDefeat( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetEOLFric( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetSelect( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_BatteryVoltage_SCom_ClearTransOvData( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_CalGain( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_CalOffset( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_SetMtrCurrCals( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_DigHwTrqSENT_SCom_ClrTrqTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_DigHwTrqSENT_SCom_SetTrqTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_DigHwTrqSENT_SCom_WriteData( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_IoHwAb_Adc_ResetAdcEnable( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_LrnEOT_Scom_ResetEOT( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_Polarity_SCom_SetPolarity( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SCom_EOLNomMtrParam_Set( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_ElecIntStart( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_ElecIntStop( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_SendMsgOnChange( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_ManualVehSpd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_ResetTimers( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_VehSpdControl( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_TrqCanc_Scom_SetCogTrqCal( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_TrqCmdScl_SCom_Set( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_VehDyn_SCom_ResetCenter( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_PsaAgArbn_SCom_PsaAaCmd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );


/***** Trusted Function Prototypes *****/

extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp0( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_CallFblStart( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Adc_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Adc2_Init1( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_PwmCdd_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_StaMd_Init0( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Wdg_TMS570LS3x_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_WdgM_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_NvMProxy_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );
extern FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Dma_InvalidateSlowADCGroup( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams );

#endif

