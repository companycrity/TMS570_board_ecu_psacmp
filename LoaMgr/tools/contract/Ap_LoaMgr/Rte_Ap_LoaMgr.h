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
 *          File:  Rte_Ap_LoaMgr.h
 *     Workspace:  C:/_Synergy_Projects/EA3_Working/LoaMgr/autosar
 *     SW-C Type:  Ap_LoaMgr
 *  Generated at:  Thu Mar 15 08:28:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_LoaMgr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LOAMGR_H
# define _RTE_AP_LOAMGR_H

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

typedef P2CONST(struct Rte_CDS_Ap_LoaMgr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagcStsIvtr1Inactv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagcStsIvtr2Inactv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwTqIdptSig_Cnt_u08 ((UInt8)4u)
# define Rte_InitValue_HwTqLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_IvtrLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LOASt_State_enum ((LOA_State_enum)0u)
# define Rte_InitValue_LoaRateLimit_UlspS_f32 ((Float)1)
# define Rte_InitValue_LoaScaDi_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LoaScaleFctr_Uls_f32 ((Float)1)
# define Rte_InitValue_MotAgLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MotCurrIdptSig_Cnt_u08 ((UInt8)2u)
# define Rte_InitValue_MotCurrLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrPosIdptSig_Cnt_u08 ((UInt8)3u)
# define Rte_InitValue_SteerMod_Cnt_enum ((SteerMod_enum)0u)
# define Rte_InitValue_TloaAvail_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TloaDi_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_LoaMgr_LoaRateLimit_UlspS_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_LoaMgr_LoaScaleFctr_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LOAMGR_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LOAMGR_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_LOAMGR_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LoaMgr_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

FUNC(void, RTE_CODE) Rte_Enter_Ap_LoaMgr_EaLoaScaleAndRate(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_LoaMgr_EaLoaScaleAndRate(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc->value)

# define Rte_IRead_LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc->value)

# define Rte_IRead_LoaMgr_Per1_HwTqIdptSig_Cnt_u08() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_HwTqIdptSig_Cnt_u08->value)

# define Rte_IRead_LoaMgr_Per1_LoaScaDi_Cnt_lgc() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_LoaScaDi_Cnt_lgc->value)

# define Rte_IRead_LoaMgr_Per1_MotCurrIdptSig_Cnt_u08() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MotCurrIdptSig_Cnt_u08->value)

# define Rte_IRead_LoaMgr_Per1_MtrPosIdptSig_Cnt_u08() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MtrPosIdptSig_Cnt_u08->value)

# define Rte_IRead_LoaMgr_Per1_SteerMod_Cnt_enum() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_SteerMod_Cnt_enum->value)

# define Rte_IRead_LoaMgr_Per1_TloaAvail_Cnt_lgc() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_TloaAvail_Cnt_lgc->value)

# define Rte_IRead_LoaMgr_Per1_TloaDi_Cnt_lgc() \
  (Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_TloaDi_Cnt_lgc->value)

# define Rte_IWrite_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IWrite_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IWrite_LoaMgr_Per1_LOASt_State_enum(data) \
  ( \
  Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_LOASt_State_enum->value = (data) \
  )

# define Rte_IWriteRef_LoaMgr_Per1_LOASt_State_enum() \
  (&Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_LOASt_State_enum->value)

# define Rte_IWrite_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IWrite_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Inst_Ap_LoaMgr->LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_LoaRateLimit_UlspS_f32 Rte_Write_Ap_LoaMgr_LoaRateLimit_UlspS_f32
# define Rte_Write_LoaScaleFctr_Uls_f32 Rte_Write_Ap_LoaMgr_LoaScaleFctr_Uls_f32


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_LoaMgr_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_LoaMgr_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_EaLoaScaleAndRate Rte_Enter_Ap_LoaMgr_EaLoaScaleAndRate
# define Rte_Exit_EaLoaScaleAndRate Rte_Exit_Ap_LoaMgr_EaLoaScaleAndRate




# define RTE_START_SEC_AP_LOAMGR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LoaMgr_Init1
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LoaMgr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_HwTqIdptSig_Cnt_u08(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_LoaScaDi_Cnt_lgc(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_MotCurrIdptSig_Cnt_u08(void)
 *   UInt8 Rte_IRead_LoaMgr_Per1_MtrPosIdptSig_Cnt_u08(void)
 *   SteerMod_enum Rte_IRead_LoaMgr_Per1_SteerMod_Cnt_enum(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_TloaAvail_Cnt_lgc(void)
 *   Boolean Rte_IRead_LoaMgr_Per1_TloaDi_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LoaRateLimit_UlspS_f32(Float data)
 *   Std_ReturnType Rte_Write_LoaScaleFctr_Uls_f32(Float data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_LOASt_State_enum(LOA_State_enum data)
 *   LOA_State_enum *Rte_IWriteRef_LoaMgr_Per1_LOASt_State_enum(void)
 *   void Rte_IWrite_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(void)
 *   void Rte_IWrite_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaLoaScaleAndRate(void)
 *   void Rte_Exit_EaLoaScaleAndRate(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Per1(void);

# define RTE_STOP_SEC_AP_LOAMGR_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1521119282
#    error "The magic number of the generated file <C:/_Synergy_Projects/EA3_Working/LoaMgr/tools/contract/Ap_LoaMgr/Rte_Ap_LoaMgr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1521119282
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LOAMGR_H */
