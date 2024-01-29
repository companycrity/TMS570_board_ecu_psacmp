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
 *          File:  Rte_Cd_Nhet1CfgAndUse.h
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/Nhet1CfgAndUse/autosar
 *     SW-C Type:  Cd_Nhet1CfgAndUse
 *  Generated at:  Sat Jul 23 11:31:25 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Cd_Nhet1CfgAndUse> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_NHET1CFGANDUSE_H
# define _RTE_CD_NHET1CFGANDUSE_H

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

typedef P2CONST(struct Rte_CDS_Cd_Nhet1CfgAndUse, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq1Polarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HwTq1Qlfr_State_enum ((SigQlfr_State_enum)0u)
# define Rte_InitValue_HwTq1RollgCntr_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HwTq1Val_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTq2Polarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HwTq2Qlfr_State_enum ((SigQlfr_State_enum)0u)
# define Rte_InitValue_HwTq2RollgCntr_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HwTq2Val_HwNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_Nhet1CfgAndUse_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_Nhet1CfgAndUse_Per2_HwTq1Polarity_Cnt_s08() \
  (Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1Polarity_Cnt_s08->value)

# define Rte_IRead_Nhet1CfgAndUse_Per2_HwTq2Polarity_Cnt_s08() \
  (Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2Polarity_Cnt_s08->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08->value)

# define Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32(data) \
  ( \
  Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32() \
  (&Rte_Inst_Cd_Nhet1CfgAndUse->Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Cd_Nhet1CfgAndUse_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_CD_NHET1CFGANDUSE_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Nhet1CfgAndUse_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_NHET1CFGANDUSE_APPL_CODE) Nhet1CfgAndUse_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Nhet1CfgAndUse_Per2
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
 *   SInt8 Rte_IRead_Nhet1CfgAndUse_Per2_HwTq1Polarity_Cnt_s08(void)
 *   SInt8 Rte_IRead_Nhet1CfgAndUse_Per2_HwTq2Polarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Qlfr_State_enum(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq1Val_HwNm_f32(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Qlfr_State_enum(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_Nhet1CfgAndUse_Per2_HwTq2Val_HwNm_f32(void)
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

FUNC(void, RTE_CD_NHET1CFGANDUSE_APPL_CODE) Nhet1CfgAndUse_Per2(void);

# define RTE_STOP_SEC_CD_NHET1CFGANDUSE_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1469290385
#    error "The magic number of the generated file <C:/Users/rzk04c/Documents/Synergy/EA3/Nhet1CfgAndUse/tools/contract/Cd_Nhet1CfgAndUse/Rte_Cd_Nhet1CfgAndUse.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1469290385
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_NHET1CFGANDUSE_H */
