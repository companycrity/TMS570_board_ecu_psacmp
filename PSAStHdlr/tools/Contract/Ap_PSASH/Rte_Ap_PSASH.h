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
 *          File:  Rte_Ap_PSASH.h
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSAStHdlr-nz2999/PSAStHdlr/autosar
 *     SW-C Type:  Ap_PSASH
 *  Generated at:  Mon Feb 12 15:44:56 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PSASH> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSASH_H
# define _RTE_AP_PSASH_H

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

typedef P2CONST(struct Rte_CDS_Ap_PSASH, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AbsActv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaAuthn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaCmdReq_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaEna_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaHwAgCmd_HwDeg_f32 ((Float)0)
# define Rte_InitValue_ApaPosSrvoFlt_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaRelaxReq_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaState_Cnt_enum ((PsaApaSt_Cnt_enum)0u)
# define Rte_InitValue_ApaStateTransitionCause_Cnt_enum ((PsaApaTranCause_Cnt_enum)0u)
# define Rte_InitValue_AssistStallLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_CpkOk_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrvrIntvDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EPSStateForLxa_Cnt_enum ((PsaEpsStLxa_Cnt_enum)0u)
# define Rte_InitValue_EscActv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EscEna_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EscFltPrsnt_Cnt_lgc ((Boolean)TRUE)
# define Rte_InitValue_FTermActv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HOWState_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTrqRate_HwNmpS_f32 ((Float)0)
# define Rte_InitValue_LpaSeld_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaApaConflictReqNTC_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaCorrnFacReqLimd_Uls_f32 ((Float)0)
# define Rte_InitValue_LxaDrvrAbsntDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaDrvrAbsntHwVelDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaDrvrAbsntWarn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaHwAgCmd_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LxaHwAgDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaInactivOnDrvrBhvr_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaInpVld_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaSelected_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaState_Cnt_enum ((PsaLxaSt_Cnt_enum)0u)
# define Rte_InitValue_LxaTqFacReq_Uls_f32 ((Float)0)
# define Rte_InitValue_OutputRampMult_Uls_f32 ((Float)0)
# define Rte_InitValue_PosSrvoEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 ((Float)0)
# define Rte_InitValue_ThermLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_PSASH_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PSASH_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PSASH_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PSASH_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PSASH_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_PSASH_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PSASH_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_PSASH_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PSASH_Per1_AbsActv_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_AbsActv_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaAuthn_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaCmdReq_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaEna_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_ApaHwAgCmd_HwDeg_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaHwAgCmd_HwDeg_f32->value)

# define Rte_IRead_PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ApaRelaxReq_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_AssistStallLimit_MtrNm_f32->value)

# define Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_CpkOk_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_EscActv_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_EscActv_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_EscEna_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_EscEna_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_EscFltPrsnt_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_EscFltPrsnt_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_FTermActv_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_HOWState_Cnt_s08() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_HOWState_Cnt_s08->value)

# define Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_PSASH_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_PSASH_Per1_LpaSeld_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LpaSeld_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_LxaHwAgCmd_HwDeg_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LxaHwAgCmd_HwDeg_f32->value)

# define Rte_IRead_PSASH_Per1_LxaInpVld_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LxaInpVld_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_LxaSelected_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LxaSelected_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_LxaState_Cnt_enum() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LxaState_Cnt_enum->value)

# define Rte_IRead_PSASH_Per1_LxaTqFacReq_Uls_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_LxaTqFacReq_Uls_f32->value)

# define Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_ThermLimitPerc_Uls_f32->value)

# define Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_PSASH->PSASH_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_ApaStateTransitionCause_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_ApaStateTransitionCause_Cnt_enum() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_ApaStateTransitionCause_Cnt_enum->value)

# define Rte_IWrite_PSASH_Per1_ApaState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_ApaState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_ApaState_Cnt_enum() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_ApaState_Cnt_enum->value)

# define Rte_IWrite_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_DrvrIntvDetd_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_DrvrIntvDetd_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_DrvrIntvDetd_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_EPSStateForLxa_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_EPSStateForLxa_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_EPSStateForLxa_Cnt_enum() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_EPSStateForLxa_Cnt_enum->value)

# define Rte_IWrite_PSASH_Per1_HwTrqRate_HwNmpS_f32(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_HwTrqRate_HwNmpS_f32->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_HwTrqRate_HwNmpS_f32() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_HwTrqRate_HwNmpS_f32->value)

# define Rte_IWrite_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32->value)

# define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaHwAgDetd_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaHwAgDetd_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaHwAgDetd_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_PosSrvoEnable_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_PosSrvoEnable_Cnt_lgc->value)

# define Rte_IWrite_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_PSASH->PSASH_Per1_PosSrvoHwAngle_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Inst_Ap_PSASH->PSASH_Per1_PosSrvoHwAngle_HwDeg_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_PSASH_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_PSASH_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PSASH_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_PSASH_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_PSASH_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_PSASH_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Init1
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Per1
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
 *   Boolean Rte_IRead_PSASH_Per1_AbsActv_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_ApaHwAgCmd_HwDeg_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscActv_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscEna_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscFltPrsnt_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc(void)
 *   SInt8 Rte_IRead_PSASH_Per1_HOWState_Cnt_s08(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_LpaSeld_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_LxaHwAgCmd_HwDeg_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_LxaInpVld_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_LxaSelected_Cnt_lgc(void)
 *   PsaLxaSt_Cnt_enum Rte_IRead_PSASH_Per1_LxaState_Cnt_enum(void)
 *   Float Rte_IRead_PSASH_Per1_LxaTqFacReq_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(PsaApaTranCause_Cnt_enum data)
 *   PsaApaTranCause_Cnt_enum *Rte_IWriteRef_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_ApaState_Cnt_enum(PsaApaSt_Cnt_enum data)
 *   PsaApaSt_Cnt_enum *Rte_IWriteRef_PSASH_Per1_ApaState_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_EPSStateForLxa_Cnt_enum(PsaEpsStLxa_Cnt_enum data)
 *   PsaEpsStLxa_Cnt_enum *Rte_IWriteRef_PSASH_Per1_EPSStateForLxa_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_HwTrqRate_HwNmpS_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_HwTrqRate_HwNmpS_f32(void)
 *   void Rte_IWrite_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
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

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Per1(void);

# define RTE_STOP_SEC_AP_PSASH_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1518437120
#    error "The magic number of the generated file <C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSAStHdlr-nz2999/PSAStHdlr/tools/contract/Ap_PSASH/Rte_Ap_PSASH.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1518437120
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PSASH_H */
