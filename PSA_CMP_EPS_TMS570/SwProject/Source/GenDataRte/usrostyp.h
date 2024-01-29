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
 *          File:  usrostyp.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  User Types header file (osCAN specific)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _USROSTYP_H
# define _USROSTYP_H

# include "Rte_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AbsHwPos_EOLVehCntrOffset_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AbsHwPos_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_PullCmpLTComp_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BatteryVoltage_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BatteryVoltage_OvervoltageData_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BatteryVoltage_OvervoltageData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_10msaEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_10msaStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_10msbEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_10msbStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_4msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp10_ChkPtAp10_4msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_10msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_10msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_10msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_10msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_4msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp9_ChkPtAp9_4msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CtrlPolarityBrshlss_Polarity_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CurrParamComp_EOLNomMtrParamBlk_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CustBattDiag_EpsEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CustBattDiag_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_DemIf_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_DemIf_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_DiagSvc_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_DiagSvc_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_FaultLog_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_LearnedEOTData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PSASH_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PSASH_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Return_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SignlCondn_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_ElecInt_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_EpsEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_ShutdownTime_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComOutput_EpsEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComOutput_IndStatusETATDA2_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_CloseCheckData_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_CloseCheckData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_TOD_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_TypeHData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCanc_EOLCogTrqCanc_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCanc_EOLCogTrqRplComp_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCmdScl_TrqCmdScl_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehDyn_NVM_VehDynReset_Srv_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehDyn_NVM_VehDynReset_Srv_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehDyn_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehDyn_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehPwrMd_EpsEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehPwrMd_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehPwrMd_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_IS_DAT_DIRA_Get(IS_DAT_DIRA_Msg *IsDatDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_IS_DYN_VOL_Get(IS_DYN_VOL_MsgBase *IsDynVolBase, IS_DYN_VOL_MsgAdd *IsDynVolAdd);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_SrlComDriver_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_AvgFricLrn_SCom_InitLearnedTables(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_AvgFricLrn_SCom_ResetToZero(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_BatteryVoltage_SCom_ClearTransOvData(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_CmMtrCurr_SCom_CalGain(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_CmMtrCurr_SCom_CalOffset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_IoHwAb_Adc_ResetAdcEnable(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_LrnEOT_Scom_ResetEOT(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_SrlComDriver_SCom_ElecIntStart(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_SrlComDriver_SCom_ElecIntStop(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_SrlComDriver_SCom_SendMsgOnChange(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_VehDyn_SCom_ResetCenter(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CDDInterface9_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLCurrTempOffset_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTqArbn_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTqCorrln_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetDrvReset_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt1Data_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_FetDrvReset_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_SysFault2_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_SysFault3_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon2_WdMonitor_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_FetDrvCntl_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_PwrSwitchEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdMonitor_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdReset_OP_SET(IoHwAb_BoolType signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


#endif /* _USROSTYP_H */
