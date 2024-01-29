/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_AstLmt.h
 *     Workspace:  C:/Synergy_KK/working/AstLmt_CM-nz4qtt/AstLmt_CM/autosar
 *     SW-C Type:  Ap_AstLmt
 *  Generated at:  Mon Mar 30 14:59:12 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_AstLmt> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ASTLMT_H
# define _RTE_AP_ASTLMT_H

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

typedef P2CONST(struct Rte_CDS_Ap_AstLmt, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_AssistEOTDamping_MtrNm_f32 ((Float)0)
# define Rte_InitValue_AssistEOTGain_Uls_f32 ((Float)1)
# define Rte_InitValue_AssistEOTLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_AssistStallLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_AssistVehSpdLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_CombinedDamping_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DefeatLimitService_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EotActvCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_HwTqLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_LimitedReturn_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LrnPnCtrEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCtrTCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_OpTrqOvr_MtrNm_f32 ((Float)0)
# define Rte_InitValue_OutputRampMult_Uls_f32 ((Float)0)
# define Rte_InitValue_PowerLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_PreLimitForStall_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PreLimitTorque_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PullCompCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SumLimTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_TSMitCommand_MtrNm_f32 ((Float)0)
# define Rte_InitValue_ThermalLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_ThermalLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_TloaCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_TrqLimitMin_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)
# define Rte_InitValue_WheelImbalanceCmd_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AstLmt_VehSpd_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_ASTLMT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AstLmt_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_AstLmt_Per1_AssistCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistCmd_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_AssistEOTDamping_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistEOTDamping_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_AssistEOTGain_Uls_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistEOTGain_Uls_f32->value)

# define Rte_IRead_AstLmt_Per1_AssistEOTLimit_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistEOTLimit_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistStallLimit_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_AssistVehSpdLimit_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_AssistVehSpdLimit_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_CombinedDamping_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_CombinedDamping_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_DefeatLimitService_Cnt_lgc() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_DefeatLimitService_Cnt_lgc->value)

# define Rte_IRead_AstLmt_Per1_EotActvCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_EotActvCmd_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_HwTqLoaMtgtnEn_Cnt_lgc() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_HwTqLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IRead_AstLmt_Per1_LimitedReturn_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_LimitedReturn_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_LrnPnCtrEnable_Cnt_lgc() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_LrnPnCtrEnable_Cnt_lgc->value)

# define Rte_IRead_AstLmt_Per1_LrnPnCtrTCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_LrnPnCtrTCmd_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_OpTrqOvr_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_OpTrqOvr_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_AstLmt_Per1_PowerLimitPerc_Uls_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_PowerLimitPerc_Uls_f32->value)

# define Rte_IRead_AstLmt_Per1_PullCompCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_PullCompCmd_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_TSMitCommand_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_TSMitCommand_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_ThermalLimitPerc_Uls_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_ThermalLimitPerc_Uls_f32->value)

# define Rte_IRead_AstLmt_Per1_ThermalLimit_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_ThermalLimit_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_TloaCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_TloaCmd_MtrNm_f32->value)

# define Rte_IRead_AstLmt_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_VehSpd_Kph_f32->value)

# define Rte_IRead_AstLmt_Per1_WheelImbalanceCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AstLmt->AstLmt_Per1_WheelImbalanceCmd_MtrNm_f32->value)

# define Rte_IWrite_AstLmt_Per1_LimitPercentFiltered_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AstLmt->AstLmt_Per1_LimitPercentFiltered_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AstLmt_Per1_LimitPercentFiltered_Uls_f32() \
  (&Rte_Inst_Ap_AstLmt->AstLmt_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IWrite_AstLmt_Per1_PreLimitForStall_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AstLmt->AstLmt_Per1_PreLimitForStall_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AstLmt_Per1_PreLimitForStall_MtrNm_f32() \
  (&Rte_Inst_Ap_AstLmt->AstLmt_Per1_PreLimitForStall_MtrNm_f32->value)

# define Rte_IWrite_AstLmt_Per1_PreLimitTorque_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AstLmt->AstLmt_Per1_PreLimitTorque_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AstLmt_Per1_PreLimitTorque_MtrNm_f32() \
  (&Rte_Inst_Ap_AstLmt->AstLmt_Per1_PreLimitTorque_MtrNm_f32->value)

# define Rte_IWrite_AstLmt_Per1_SumLimTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AstLmt->AstLmt_Per1_SumLimTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AstLmt_Per1_SumLimTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_AstLmt->AstLmt_Per1_SumLimTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_AstLmt_Per1_TrqLimitMin_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AstLmt->AstLmt_Per1_TrqLimitMin_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AstLmt_Per1_TrqLimitMin_MtrNm_f32() \
  (&Rte_Inst_Ap_AstLmt->AstLmt_Per1_TrqLimitMin_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_VehSpd_Kph_f32 Rte_Read_Ap_AstLmt_VehSpd_Kph_f32


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_AstLmt_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_ASTLMT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AstLmt_Init
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AstLmt_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AstLmt_Per1_AssistCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_AssistEOTDamping_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_AssistEOTGain_Uls_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_AssistEOTLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_AssistVehSpdLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_CombinedDamping_MtrNm_f32(void)
 *   Boolean Rte_IRead_AstLmt_Per1_DefeatLimitService_Cnt_lgc(void)
 *   Float Rte_IRead_AstLmt_Per1_EotActvCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_AstLmt_Per1_HwTqLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_AstLmt_Per1_LimitedReturn_MtrNm_f32(void)
 *   Boolean Rte_IRead_AstLmt_Per1_LrnPnCtrEnable_Cnt_lgc(void)
 *   Float Rte_IRead_AstLmt_Per1_LrnPnCtrTCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_OpTrqOvr_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_PowerLimitPerc_Uls_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_PullCompCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_TSMitCommand_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_ThermalLimitPerc_Uls_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_ThermalLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_TloaCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_VehSpd_Kph_f32(void)
 *   Float Rte_IRead_AstLmt_Per1_WheelImbalanceCmd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AstLmt_Per1_LimitPercentFiltered_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AstLmt_Per1_LimitPercentFiltered_Uls_f32(void)
 *   void Rte_IWrite_AstLmt_Per1_PreLimitForStall_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AstLmt_Per1_PreLimitForStall_MtrNm_f32(void)
 *   void Rte_IWrite_AstLmt_Per1_PreLimitTorque_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AstLmt_Per1_PreLimitTorque_MtrNm_f32(void)
 *   void Rte_IWrite_AstLmt_Per1_SumLimTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AstLmt_Per1_SumLimTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_AstLmt_Per1_TrqLimitMin_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AstLmt_Per1_TrqLimitMin_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AstLmt_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AstLmt_Scom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VehSpd_Kph_f32(Float *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

# define RTE_STOP_SEC_AP_ASTLMT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH (34u)

# define RTE_E_AssistLmtFunc_Scom_RTE_E_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1427735996
#    error "The magic number of the generated file <C:/Synergy_KK/working/AstLmt_CM-nz4qtt/AstLmt_CM/tools/contract/Ap_AstLmt/Rte_Ap_AstLmt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1427735996
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ASTLMT_H */
