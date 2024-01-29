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
 *          File:  Rte_Ap_ThrmlDutyCycle.h
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Working/ThrmDutyCycle/autosar
 *     SW-C Type:  Ap_ThrmlDutyCycle
 *  Generated at:  Thu Oct 29 12:24:54 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ThrmlDutyCycle> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_THRMLDUTYCYCLE_H
# define _RTE_AP_THRMLDUTYCYCLE_H

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

typedef P2CONST(struct Rte_CDS_Ap_ThrmlDutyCycle, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CuTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_DefeatDutySvc_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DutyCycleLevel_Uls_f32 ((Float)0)
# define Rte_InitValue_FiltMeasTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_FilteredPkCurr_AmpSq_f32 ((Float)0)
# define Rte_InitValue_IgnTimeOff_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MagTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_MotorVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrPkCurr_AmpSq_f32 ((Float)0)
# define Rte_InitValue_SiTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_ThermLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_ThermalLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_VehTimeValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_ThrmlDutyCycle_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_THRMLDUTYCYCLE_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_THRMLDUTYCYCLE_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_SetRamBlockStatus(Boolean RamBlockStatus);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ThrmlDutyCycle_Init1_DefeatDutySvc_Cnt_lgc() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Init1_DefeatDutySvc_Cnt_lgc->value)

# define Rte_IRead_ThrmlDutyCycle_Init1_IgnTimeOff_Cnt_u32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Init1_IgnTimeOff_Cnt_u32->value)

# define Rte_IRead_ThrmlDutyCycle_Init1_VehTimeValid_Cnt_lgc() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Init1_VehTimeValid_Cnt_lgc->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_CuTempEst_DegC_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_CuTempEst_DegC_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_DefeatDutySvc_Cnt_lgc() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_DefeatDutySvc_Cnt_lgc->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_FiltMeasTemp_DegC_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_FiltMeasTemp_DegC_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_FilteredPkCurr_AmpSq_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_FilteredPkCurr_AmpSq_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_IgnTimeOff_Cnt_u32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_IgnTimeOff_Cnt_u32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_MagTempEst_DegC_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_MagTempEst_DegC_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_MotorVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_MotorVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_MtrPkCurr_AmpSq_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_MtrPkCurr_AmpSq_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_SiTempEst_DegC_f32() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_SiTempEst_DegC_f32->value)

# define Rte_IRead_ThrmlDutyCycle_Per1_VehTimeValid_Cnt_lgc() \
  (Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_VehTimeValid_Cnt_lgc->value)

# define Rte_IWrite_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32() \
  (&Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32->value)

# define Rte_IWrite_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32() \
  (&Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32->value)

# define Rte_IWrite_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32() \
  (&Rte_Inst_Ap_ThrmlDutyCycle->ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_ThrmlDutyCycle_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_ThrmlDutyCycle_FltStVar_GetErrorStatus Rte_Call_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_GetErrorStatus
# define Rte_Call_ThrmlDutyCycle_FltStVar_SetRamBlockStatus Rte_Call_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVar_SetRamBlockStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_ThrmlDutyCycle_FltStVal() (Rte_Inst_Ap_ThrmlDutyCycle->Pim_ThrmlDutyCycle_FltStVal)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   ThrmlDutyCycle_FltStVal_Datatype *Rte_Pim_ThrmlDutyCycle_FltStVal(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_THRMLDUTYCYCLE_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ThrmlDutyCycle_Init1
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
 *   Boolean Rte_IRead_ThrmlDutyCycle_Init1_DefeatDutySvc_Cnt_lgc(void)
 *   UInt32 Rte_IRead_ThrmlDutyCycle_Init1_IgnTimeOff_Cnt_u32(void)
 *   Boolean Rte_IRead_ThrmlDutyCycle_Init1_VehTimeValid_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_ThrmlDutyCycle_FltStVar_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_THRMLDUTYCYCLE_APPL_CODE) ThrmlDutyCycle_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ThrmlDutyCycle_Per1
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
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_CuTempEst_DegC_f32(void)
 *   Boolean Rte_IRead_ThrmlDutyCycle_Per1_DefeatDutySvc_Cnt_lgc(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_FiltMeasTemp_DegC_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_FilteredPkCurr_AmpSq_f32(void)
 *   UInt32 Rte_IRead_ThrmlDutyCycle_Per1_IgnTimeOff_Cnt_u32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MagTempEst_DegC_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MtrPkCurr_AmpSq_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_SiTempEst_DegC_f32(void)
 *   Boolean Rte_IRead_ThrmlDutyCycle_Per1_VehTimeValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(void)
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(void)
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_THRMLDUTYCYCLE_APPL_CODE) ThrmlDutyCycle_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ThrmlDutyCycle_Trns1
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ThrmlDutyCycle_FltStVar_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_THRMLDUTYCYCLE_APPL_CODE) ThrmlDutyCycle_Trns1(void);

# define RTE_STOP_SEC_AP_THRMLDUTYCYCLE_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1446141437
#    error "The magic number of the generated file <C:/Rijvi_Synergy_EA3/Core_Component/Working/ThrmDutyCycle/utp/contract/Rte_Ap_ThrmlDutyCycle.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1446141437
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_THRMLDUTYCYCLE_H */
