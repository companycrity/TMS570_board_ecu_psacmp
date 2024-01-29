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
 *          File:  Rte_Sa_HwTqArbn.h
 *     Workspace:  C:/Users/nz2378/Documents/work/CR_EA3_9800/Task_EA3_7839/SWC/HwTqArbn_2TqADAS/autosar
 *     SW-C Type:  Sa_HwTqArbn
 *  Generated at:  Tue Aug 16 15:47:24 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_HwTqArbn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_HWTQARBN_H
# define _RTE_SA_HWTQARBN_H

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

typedef P2CONST(struct Rte_CDS_Sa_HwTqArbn, TYPEDEF, RTE_CONST) Rte_Instance;


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
# define Rte_InitValue_HwTqVal_HwNm_f32 ((Float)0)
# define Rte_InitValue_MEC_Counter_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_SVC_ClearCodes_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqArbn_HwTqArbnEOLCh1OffsetTrim_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_HWTQARBN_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqArbn_HwTqArbnEOLCh1OffsetTrim_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_HWTQARBN_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTqArbn_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HwTqArbn_Per1_HwTq1Qlfr_State_enum() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per1_HwTq1Qlfr_State_enum->value)

# define Rte_IRead_HwTqArbn_Per1_HwTq1RollgCntr_Cnt_u08() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per1_HwTq1RollgCntr_Cnt_u08->value)

# define Rte_IRead_HwTqArbn_Per1_HwTq2Qlfr_State_enum() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per1_HwTq2Qlfr_State_enum->value)

# define Rte_IRead_HwTqArbn_Per1_HwTq2RollgCntr_Cnt_u08() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per1_HwTq2RollgCntr_Cnt_u08->value)

# define Rte_IRead_HwTqArbn_Per1_HwTqCorrlnSts_Cnt_u16() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per1_HwTqCorrlnSts_Cnt_u16->value)

# define Rte_IRead_HwTqArbn_Per2_HwTq1Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per2_HwTq1Val_HwNm_f32->value)

# define Rte_IRead_HwTqArbn_Per2_HwTq2Val_HwNm_f32() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per2_HwTq2Val_HwNm_f32->value)

# define Rte_IWrite_HwTqArbn_Per2_HwTqVal_HwNm_f32(data) \
  ( \
  Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per2_HwTqVal_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTqArbn_Per2_HwTqVal_HwNm_f32() \
  (&Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per2_HwTqVal_HwNm_f32->value)

# define Rte_IRead_HwTqArbn_Per3_MEC_Counter_Cnt_u08() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per3_MEC_Counter_Cnt_u08->value)

# define Rte_IRead_HwTqArbn_Per3_SVC_ClearCodes_Cnt_lgc() \
  (Rte_Inst_Sa_HwTqArbn->HwTqArbn_Per3_SVC_ClearCodes_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock Rte_Call_Sa_HwTqArbn_HwTqArbnEOLCh1OffsetTrim_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_HwTqArbn_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_HwTqArbnEOLCh1OffsetTrimData() (Rte_Inst_Sa_HwTqArbn->Pim_HwTqArbnEOLCh1OffsetTrimData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLChOffsetTrim_DataType *Rte_Pim_HwTqArbnEOLCh1OffsetTrimData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_HWTQARBN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbn_Per1
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
 *   SigQlfr_State_enum Rte_IRead_HwTqArbn_Per1_HwTq1Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqArbn_Per1_HwTq1RollgCntr_Cnt_u08(void)
 *   SigQlfr_State_enum Rte_IRead_HwTqArbn_Per1_HwTq2Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_HwTqArbn_Per1_HwTq2RollgCntr_Cnt_u08(void)
 *   UInt16 Rte_IRead_HwTqArbn_Per1_HwTqCorrlnSts_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbn_Per2
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
 *   Float Rte_IRead_HwTqArbn_Per2_HwTq1Val_HwNm_f32(void)
 *   Float Rte_IRead_HwTqArbn_Per2_HwTq2Val_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTqArbn_Per2_HwTqVal_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HwTqArbn_Per2_HwTqVal_HwNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbn_Per3
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
 *   UInt8 Rte_IRead_HwTqArbn_Per3_MEC_Counter_Cnt_u08(void)
 *   Boolean Rte_IRead_HwTqArbn_Per3_SVC_ClearCodes_Cnt_lgc(void)
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

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTqArbn_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim(Float *EOLChOffsetTrim_HwNm_f32, Boolean *EOLChOffsetTrimPerf_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim(P2VAR(Float, AUTOMATIC, RTE_SA_HWTQARBN_APPL_VAR) EOLChOffsetTrim_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTQARBN_APPL_VAR) EOLChOffsetTrimPerf_Cnt_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTqArbnEOLCh1OffsetTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTQARBN_APPL_CODE) HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32);

# define RTE_STOP_SEC_SA_HWTQARBN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect (34u)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1471363204
#    error "The magic number of the generated file <C:/Users/nz2378/Documents/work/CR_EA3_9800/Task_EA3_7839/SWC/HwTqArbn_2TqADAS/tools/contract/Sa_HwTqArbn/Rte_Sa_HwTqArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1471363204
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_HWTQARBN_H */
