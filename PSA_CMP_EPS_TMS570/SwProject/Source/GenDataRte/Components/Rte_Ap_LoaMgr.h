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
 *          File:  Components/Rte_Ap_LoaMgr.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LOAMGR_H
# define _RTE_AP_LOAMGR_H

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

# include "Rte_Hook.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_LoaMgr_LoaRateLimit_UlspS_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_LoaMgr_LoaScaleFctr_Uls_f32;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DiagcStsIvtr1Inactv_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagcStsIvtr2Inactv_Cnt_lgc (FALSE)
#  define Rte_InitValue_HwTqIdptSig_Cnt_u08 (4U)
#  define Rte_InitValue_HwTqLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_IvtrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_LOASt_State_enum (0U)
#  define Rte_InitValue_LoaRateLimit_UlspS_f32 (1.0F)
#  define Rte_InitValue_LoaScaDi_Cnt_lgc (FALSE)
#  define Rte_InitValue_LoaScaleFctr_Uls_f32 (1.0F)
#  define Rte_InitValue_MotAgLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MotCurrIdptSig_Cnt_u08 (2U)
#  define Rte_InitValue_MotCurrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrPosIdptSig_Cnt_u08 (3U)
#  define Rte_InitValue_SteerMod_Cnt_enum (0U)
#  define Rte_InitValue_TloaAvail_Cnt_lgc (FALSE)
#  define Rte_InitValue_TloaDi_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_LoaMgr_Per1_DiagcStsIvtr1Inactv_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_DiagcStsIvtr1Inactv_Cnt_lgc.value)

#  define Rte_IRead_LoaMgr_Per1_DiagcStsIvtr2Inactv_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_DiagcStsIvtr2Inactv_Cnt_lgc.value)

#  define Rte_IRead_LoaMgr_Per1_HwTqIdptSig_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_TB.Rte_I_HwTqCorrln_HwTqIdptSig_Cnt_u08.value)

#  define Rte_IRead_LoaMgr_Per1_LoaScaDi_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LoaScaDi_Cnt_lgc.value)

#  define Rte_IRead_LoaMgr_Per1_MotCurrIdptSig_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotCurrIdptSig_Cnt_u08.value)

#  define Rte_IRead_LoaMgr_Per1_MtrPosIdptSig_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MtrPosIdptSig_Cnt_u08.value)

#  define Rte_IRead_LoaMgr_Per1_SteerMod_Cnt_enum() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_SteerMod_Cnt_enum.value)

#  define Rte_IRead_LoaMgr_Per1_TloaAvail_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_TloaAvail_Cnt_lgc.value)

#  define Rte_IRead_LoaMgr_Per1_TloaDi_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_TloaDi_Cnt_lgc.value)

#  define Rte_IWrite_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_HwTqLoaMtgtnEn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LoaMgr_Per1_HwTqLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_HwTqLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IWrite_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LoaMgr_Per1_IvtrLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IWrite_LoaMgr_Per1_LOASt_State_enum(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LOASt_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_LoaMgr_Per1_LOASt_State_enum() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LOASt_State_enum.value)

#  define Rte_IWrite_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotAgLoaMtgtnEn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LoaMgr_Per1_MotAgLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotAgLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IWrite_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LoaMgr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_LoaRateLimit_UlspS_f32 Rte_Write_Ap_LoaMgr_LoaRateLimit_UlspS_f32
#  define Rte_Write_Ap_LoaMgr_LoaRateLimit_UlspS_f32(data) (Rte_LoaMgr_LoaRateLimit_UlspS_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LoaScaleFctr_Uls_f32 Rte_Write_Ap_LoaMgr_LoaScaleFctr_Uls_f32
#  define Rte_Write_Ap_LoaMgr_LoaScaleFctr_Uls_f32(data) (Rte_LoaMgr_LoaScaleFctr_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr10_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr10_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_EaLoaScaleAndRate() \
  { \
    Rte_EnterHook_Ap_LoaMgr_EaLoaScaleAndRate_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Ap_LoaMgr_EaLoaScaleAndRate_Return(); \
  }

#  define Rte_Exit_EaLoaScaleAndRate() \
  { \
    Rte_ExitHook_Ap_LoaMgr_EaLoaScaleAndRate_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Ap_LoaMgr_EaLoaScaleAndRate_Return(); \
  }


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_LOAMGR_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Init1(void);

FUNC(void, RTE_AP_LOAMGR_APPL_CODE) LoaMgr_Per1(void);

# define RTE_STOP_SEC_AP_LOAMGR_APPL_CODE
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


#endif /* _RTE_AP_LOAMGR_H */
