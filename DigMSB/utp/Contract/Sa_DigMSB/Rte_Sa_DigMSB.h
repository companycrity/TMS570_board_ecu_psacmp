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
 *          File:  Rte_Sa_DigMSB.h
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/DigMSB-nz2999/DigMSB/autosar
 *     SW-C Type:  Sa_DigMSB
 *  Generated at:  Fri Apr 20 11:29:54 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_DigMSB> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_DIGMSB_H
# define _RTE_SA_DIGMSB_H

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

typedef P2CONST(struct Rte_CDS_Sa_DigMSB, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedCumMechMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_AlignedCumMechMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_AlignedCumMechMtrPosStatus_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_AssistAssemblyPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_CorrectedElecMtrPos_Rev_u0p16 ((UInt16)0u)
# define Rte_InitValue_CumMechMtrPos_Rev_f32 ((Float)0)
# define Rte_InitValue_CumMechMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_CumMechMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_CumMechMtrPosStatus_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_Die1RxError_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die1RxMtrPos_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die1RxRevCtr_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die1UnderVoltgFltAccum_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die2RxError_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die2RxMtrPos_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_Die2RxRevCtr_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_EnergyModeState_Cnt_enum ((EnergyModeStateType)0u)
# define Rte_InitValue_MechMtrPos2_Rev_u0p16 ((UInt16)0u)
# define Rte_InitValue_MtrPosPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_RxMtrPosParityAccum_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_SysCCumMechMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_TurnsCounterSelected_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_UncorrMechMtrPos1_Rev_u0p16 ((UInt16)0u)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_DigMSB_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGMSB_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_DigMSB_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_DigMSB_Init_TurnsCounterSelected_Cnt_lgc() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Init_TurnsCounterSelected_Cnt_lgc->value)

# define Rte_IRead_DigMSB_Per2_AssistAssemblyPolarity_Cnt_s08() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_AssistAssemblyPolarity_Cnt_s08->value)

# define Rte_IRead_DigMSB_Per2_CorrectedElecMtrPos_Rev_u0p16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_CorrectedElecMtrPos_Rev_u0p16->value)

# define Rte_IRead_DigMSB_Per2_CumMechMtrPos_Rev_f32() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPos_Rev_f32->value)

# define Rte_IRead_DigMSB_Per2_Die1RxError_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die1RxError_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die1RxMtrPos_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die1RxMtrPos_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die1RxRevCtr_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die1RxRevCtr_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die1UnderVoltgFltAccum_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die1UnderVoltgFltAccum_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die2RxError_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die2RxError_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die2RxMtrPos_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die2RxMtrPos_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_Die2RxRevCtr_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_Die2RxRevCtr_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_MtrPosPolarity_Cnt_s08() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_MtrPosPolarity_Cnt_s08->value)

# define Rte_IRead_DigMSB_Per2_RxMtrPosParityAccum_Cnt_u16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_RxMtrPosParityAccum_Cnt_u16->value)

# define Rte_IRead_DigMSB_Per2_UncorrMechMtrPos1_Rev_u0p16() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per2_UncorrMechMtrPos1_Rev_u0p16->value)

# define Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32->value)

# define Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32->value)

# define Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08->value)

# define Rte_IWrite_DigMSB_Per2_CumMechMtrPosCRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosCRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosCRF_Deg_f32() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosCRF_Deg_f32->value)

# define Rte_IWrite_DigMSB_Per2_CumMechMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosMRF_Deg_f32->value)

# define Rte_IWrite_DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08->value)

# define Rte_IWrite_DigMSB_Per2_MechMtrPos2_Rev_u0p16(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_MechMtrPos2_Rev_u0p16->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_MechMtrPos2_Rev_u0p16() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_MechMtrPos2_Rev_u0p16->value)

# define Rte_IWrite_DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Sa_DigMSB->DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Sa_DigMSB->DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32->value)

# define Rte_IRead_DigMSB_Per3_EnergyModeState_Cnt_enum() \
  (Rte_Inst_Sa_DigMSB->DigMSB_Per3_EnergyModeState_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Sa_DigMSB_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_DigMSB_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_DigMSBEOLData() (Rte_Inst_Sa_DigMSB->Pim_DigMSBEOLData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   DigMSBEOLType *Rte_Pim_DigMSBEOLData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_DIGMSB_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigMSB_Init
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
 *   Boolean Rte_IRead_DigMSB_Init_TurnsCounterSelected_Cnt_lgc(void)
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

FUNC(void, RTE_SA_DIGMSB_APPL_CODE) DigMSB_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigMSB_Per2
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
 *   SInt8 Rte_IRead_DigMSB_Per2_AssistAssemblyPolarity_Cnt_s08(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_CorrectedElecMtrPos_Rev_u0p16(void)
 *   Float Rte_IRead_DigMSB_Per2_CumMechMtrPos_Rev_f32(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die1RxError_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die1RxMtrPos_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die1RxRevCtr_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die1UnderVoltgFltAccum_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die2RxError_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die2RxMtrPos_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_Die2RxRevCtr_Cnt_u16(void)
 *   SInt8 Rte_IRead_DigMSB_Per2_MtrPosPolarity_Cnt_s08(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_RxMtrPosParityAccum_Cnt_u16(void)
 *   UInt16 Rte_IRead_DigMSB_Per2_UncorrMechMtrPos1_Rev_u0p16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_DigMSB_Per2_AlignedCumMechMtrPosStatus_Cnt_u08(void)
 *   void Rte_IWrite_DigMSB_Per2_CumMechMtrPosCRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosCRF_Deg_f32(void)
 *   void Rte_IWrite_DigMSB_Per2_CumMechMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_DigMSB_Per2_CumMechMtrPosStatus_Cnt_u08(void)
 *   void Rte_IWrite_DigMSB_Per2_MechMtrPos2_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_DigMSB_Per2_MechMtrPos2_Rev_u0p16(void)
 *   void Rte_IWrite_DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_DigMSB_Per2_SysCCumMechMtrPosMRF_Deg_f32(void)
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

FUNC(void, RTE_SA_DIGMSB_APPL_CODE) DigMSB_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigMSB_Per3
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
 *   EnergyModeStateType Rte_IRead_DigMSB_Per3_EnergyModeState_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGMSB_APPL_CODE) DigMSB_Per3(void);

# define RTE_STOP_SEC_SA_DIGMSB_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1524212949
#    error "The magic number of the generated file <C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/DigMSB-nz2999/DigMSB/utp/contract/Sa_DigMSB/Rte_Sa_DigMSB.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1524212949
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_DIGMSB_H */
