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
 *          File:  Rte_Sa_HwTqCorrln.h
 *     Workspace:  C:/SynergyWorkArea/Working/HwTqCorrln_2TqADAS/autosar
 *     SW-C Type:  Sa_HwTqCorrln
 *  Generated at:  Wed Oct 19 11:03:10 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_HwTqCorrln> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_HWTQCORRLN_H
# define _RTE_SA_HWTQCORRLN_H

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

typedef P2CONST(struct Rte_CDS_Sa_HwTqCorrln, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq1Qlfr_State_enum ((SigQlfr_State_enum)0u)
# define Rte_InitValue_HwTq1RollgCntr_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HwTq1Val_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTq2Qlfr_State_enum ((SigQlfr_State_enum)0u)
# define Rte_InitValue_HwTq2RollgCntr_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HwTq2Val_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTqCorrlnSts_Cnt_u16 ((UInt16)3u)
# define Rte_InitValue_HwTqIdptSig_Cnt_u08 ((UInt8)4u)
# define Rte_InitValue_HwTqVal_HwNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqCorrln_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqCorrln_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTQCORRLN_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqCorrln_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HwTqCorrln_Per1_HwTq1Qlfr_State_enum() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq1Qlfr_State_enum->value)

# define Rte_IRead_HwTqCorrln_Per1_HwTq1RollgCntr_Cnt_u08() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq1RollgCntr_Cnt_u08->value)

# define Rte_IRead_HwTqCorrln_Per1_HwTq1Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq1Val_HwNm_f32->value)

# define Rte_IRead_HwTqCorrln_Per1_HwTq2Qlfr_State_enum() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq2Qlfr_State_enum->value)

# define Rte_IRead_HwTqCorrln_Per1_HwTq2RollgCntr_Cnt_u08() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq2RollgCntr_Cnt_u08->value)

# define Rte_IRead_HwTqCorrln_Per1_HwTq2Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTq2Val_HwNm_f32->value)

# define Rte_IWrite_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16() \
  (&Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16->value)

# define Rte_IRead_HwTqCorrln_Per2_HwTq1Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per2_HwTq1Val_HwNm_f32->value)

# define Rte_IRead_HwTqCorrln_Per2_HwTq2Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per2_HwTq2Val_HwNm_f32->value)

# define Rte_IWrite_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(data) \
  ( \
  Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08() \
  (&Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08->value)

# define Rte_IRead_HwTqCorrln_Per3_HwTqVal_HwNm_f32() \
  (Rte_Inst_Sa_HwTqCorrln->HwTqCorrln_Per3_HwTqVal_HwNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus Rte_Call_Sa_HwTqCorrln_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Sa_HwTqCorrln_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_HwTqCorrln_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_HwTqCorrlnCh1CMCLPFSvData() (Rte_Inst_Sa_HwTqCorrln->Pim_HwTqCorrlnCh1CMCLPFSvData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Float *Rte_Pim_HwTqCorrlnCh1CMCLPFSvData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_HWTQCORRLN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per1
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
 *   SigQlfr_State_enum Rte_IRead_HwTqCorrln_Per1_HwTq1Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqCorrln_Per1_HwTq1RollgCntr_Cnt_u08(void)
 *   Float Rte_IRead_HwTqCorrln_Per1_HwTq1Val_HwNm_f32(void)
 *   SigQlfr_State_enum Rte_IRead_HwTqCorrln_Per1_HwTq2Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqCorrln_Per1_HwTq2RollgCntr_Cnt_u08(void)
 *   Float Rte_IRead_HwTqCorrln_Per1_HwTq2Val_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_HwTqCorrln_Per1_HwTqCorrlnSts_Cnt_u16(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per2
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
 *   Float Rte_IRead_HwTqCorrln_Per2_HwTq1Val_HwNm_f32(void)
 *   Float Rte_IRead_HwTqCorrln_Per2_HwTq2Val_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_HwTqCorrln_Per2_HwTqIdptSig_Cnt_u08(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqCorrln_Per3
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
 *   Float Rte_IRead_HwTqCorrln_Per3_HwTqVal_HwNm_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTqCorrlnCh1CMCLPFSvBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQCORRLN_APPL_CODE) HwTqCorrln_Per3(void);

# define RTE_STOP_SEC_SA_HWTQCORRLN_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1476894161
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/HwTqCorrln_2TqADAS/tools/contract/Sa_HwTqCorrln/Rte_Sa_HwTqCorrln.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1476894161
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_HWTQCORRLN_H */
