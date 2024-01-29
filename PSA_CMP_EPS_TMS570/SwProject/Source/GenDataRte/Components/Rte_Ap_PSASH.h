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
 *          File:  Components/Rte_Ap_PSASH.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSASH_H
# define _RTE_AP_PSASH_H

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


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AbsActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaAuthn_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaCmdReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaEna_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaHwAgCmd_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ApaPosSrvoFlt_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaState_Cnt_enum (0U)
#  define Rte_InitValue_ApaStateTransitionCause_Cnt_enum (0U)
#  define Rte_InitValue_AssistStallLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_CpkOk_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrvrIntvDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_EPSStateForLxa_Cnt_enum (0U)
#  define Rte_InitValue_EscActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscEna_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscFltPrsnt_Cnt_lgc (TRUE)
#  define Rte_InitValue_FTermActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_HOWState_Cnt_s08 (0)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTrqRate_HwNmpS_f32 (0.0F)
#  define Rte_InitValue_LpaSeld_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaApaConflictReqNTC_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaCorrnFacReqLimd_Uls_f32 (0.0F)
#  define Rte_InitValue_LxaDrvrAbsntDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaDrvrAbsntHwVelDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaDrvrAbsntWarn_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaHwAgCmd_HwDeg_f32 (0.0F)
#  define Rte_InitValue_LxaHwAgDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaInactivOnDrvrBhvr_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaInpVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaState_Cnt_enum (0U)
#  define Rte_InitValue_LxaTqFacReq_Uls_f32 (0.0F)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_PosSrvoEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ThermLimitPerc_Uls_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

#  define RTE_STOP_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_PSASH_Per1_AbsActv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_AbsActv_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaAuthn_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaCmdReq_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaEna_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaHwAgCmd_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaHwAgCmd_HwDeg_f32.value)

#  define Rte_IRead_PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaPosSrvoFlt_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaRelaxReq_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_AssistStallLimit_MtrNm_f32.value)

#  define Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_CpkOk_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_EscActv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_EscActv_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_EscEna_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_EscEna_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_EscFltPrsnt_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_EscFltPrsnt_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_FTermActv_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_HOWState_Cnt_s08() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HOWState_Cnt_s08.value)

#  define Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_PsaAgArbn_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_PSASH_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value)

#  define Rte_IRead_PSASH_Per1_LpaSeld_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LpaSeld_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_LxaHwAgCmd_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaHwAgCmd_HwDeg_f32.value)

#  define Rte_IRead_PSASH_Per1_LxaInpVld_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaInpVld_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_LxaSelected_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaSelected_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_LxaState_Cnt_enum() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaState_Cnt_enum.value)

#  define Rte_IRead_PSASH_Per1_LxaTqFacReq_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaTqFacReq_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_OutputRampMult_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ThermLimitPerc_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaStateTransitionCause_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_ApaStateTransitionCause_Cnt_enum() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaStateTransitionCause_Cnt_enum.value)

#  define Rte_IWrite_PSASH_Per1_ApaState_Cnt_enum(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaState_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_ApaState_Cnt_enum() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaState_Cnt_enum.value)

#  define Rte_IWrite_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_DrvrIntvDetd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_DrvrIntvDetd_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_DrvrIntvDetd_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_EPSStateForLxa_Cnt_enum(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_EPSStateForLxa_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_EPSStateForLxa_Cnt_enum() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_EPSStateForLxa_Cnt_enum.value)

#  define Rte_IWrite_PSASH_Per1_HwTrqRate_HwNmpS_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HwTrqRate_HwNmpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_HwTrqRate_HwNmpS_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HwTrqRate_HwNmpS_f32.value)

#  define Rte_IWrite_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaApaConflictReqNTC_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaApaConflictReqNTC_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaCorrnFacReqLimd_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaCorrnFacReqLimd_Uls_f32.value)

#  define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntDetd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntDetd_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntHwVelDetd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntHwVelDetd_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntWarn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaDrvrAbsntWarn_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaHwAgDetd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaHwAgDetd_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaHwAgDetd_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaInactivOnDrvrBhvr_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_LxaInactivOnDrvrBhvr_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoEnable_Cnt_lgc.value)

#  define Rte_IWrite_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoHwAngle_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoHwAngle_HwDeg_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr9_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PSASH_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Init1(void);

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Per1(void);

# define RTE_STOP_SEC_AP_PSASH_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_PSASH_H */
