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
 *          File:  Components/Rte_Sa_HwTqArbn.h
 *     Workspace:  C:/synergy_projects_working/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_HWTQARBN_H
# define _RTE_SA_HWTQARBN_H

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

#  define Rte_InitValue_HwTq1Qlfr_State_enum (0U)
#  define Rte_InitValue_HwTq1RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_HwTq1Val_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTq2Qlfr_State_enum (0U)
#  define Rte_InitValue_HwTq2RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_HwTq2Val_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTqCorrlnSts_Cnt_u16 (3U)
#  define Rte_InitValue_HwTqVal_HwNm_f32 (0.0F)
#  define Rte_InitValue_MEC_Counter_Cnt_u08 (0U)
#  define Rte_InitValue_SVC_ClearCodes_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;

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

#  define Rte_IRead_HwTqArbn_Per1_HwTq1Qlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq1Qlfr_State_enum.value)

#  define Rte_IRead_HwTqArbn_Per1_HwTq1RollgCntr_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq1RollgCntr_Cnt_u08.value)

#  define Rte_IRead_HwTqArbn_Per1_HwTq2Qlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq2Qlfr_State_enum.value)

#  define Rte_IRead_HwTqArbn_Per1_HwTq2RollgCntr_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq2RollgCntr_Cnt_u08.value)

#  define Rte_IRead_HwTqArbn_Per1_HwTqCorrlnSts_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_HwTqCorrln_HwTqCorrlnSts_Cnt_u16.value)

#  define Rte_IRead_HwTqArbn_Per2_HwTq1Val_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq1Val_HwNm_f32.value)

#  define Rte_IRead_HwTqArbn_Per2_HwTq2Val_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Nhet1CfgAndUse_HwTq2Val_HwNm_f32.value)

#  define Rte_IWrite_HwTqArbn_Per2_HwTqVal_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_HwTqArbn_HwTqVal_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTqArbn_Per2_HwTqVal_HwNm_f32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_HwTqArbn_HwTqVal_HwNm_f32.value)

#  define Rte_IRead_HwTqArbn_Per3_MEC_Counter_Cnt_u08() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Sa_HwTqArbn_HwTqArbn_Per3.Rte_MEC_Counter_Cnt_u08.value)

#  define Rte_IRead_HwTqArbn_Per3_SVC_ClearCodes_Cnt_lgc() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Sa_HwTqArbn_HwTqArbn_Per3.Rte_SVC_ClearCodes_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)21, arg1))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(EOLChOffsetTrim_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnEOLCh1OffsetTrimData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_HwTqArbnEOLCh1OffsetTrimData() \
  (&Rte_HwTqArbn_HwTqArbnEOLCh1OffsetTrimData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_HWTQARBN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Init1(void);

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per1(void);

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per2(void);

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per3(void);

FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(void);

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim(P2VAR(Float, AUTOMATIC, RTE_SA_HWTQARBN_APPL_VAR) EOLChOffsetTrim_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTQARBN_APPL_VAR) EOLChOffsetTrimPerf_Cnt_lgc);

FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(void);

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32);

# define RTE_STOP_SEC_SA_HWTQARBN_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect (34U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_SA_HWTQARBN_H */
