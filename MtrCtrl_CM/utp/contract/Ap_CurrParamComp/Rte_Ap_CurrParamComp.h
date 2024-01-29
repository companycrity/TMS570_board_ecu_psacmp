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
 *          File:  Rte_Ap_CurrParamComp.h
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/autosar
 *     SW-C Type:  Ap_CurrParamComp
 *  Generated at:  Thu Jul 21 16:41:49 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_CurrParamComp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CURRPARAMCOMP_H
# define _RTE_AP_CURRPARAMCOMP_H

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

typedef P2CONST(struct Rte_CDS_Ap_CurrParamComp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CuTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstLd_Henry_f32 ((Float)0)
# define Rte_InitValue_EstLq_Henry_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_MagTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_SiTempEst_DegC_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CurrParamComp_EOLNomMtrParamBlk_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CurrParamComp_EOLNomMtrParamBlk_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_DATA) DstPtr);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_CurrParamComp_Init_EstKe_VpRadpS_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstKe_VpRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Init_EstKe_VpRadpS_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstKe_VpRadpS_f32->value)

# define Rte_IWrite_CurrParamComp_Init_EstLd_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstLd_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Init_EstLd_Henry_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstLd_Henry_f32->value)

# define Rte_IWrite_CurrParamComp_Init_EstLq_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstLq_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Init_EstLq_Henry_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstLq_Henry_f32->value)

# define Rte_IWrite_CurrParamComp_Init_EstR_Ohm_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstR_Ohm_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Init_EstR_Ohm_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Init_EstR_Ohm_f32->value)

# define Rte_IRead_CurrParamComp_Per1_MtrCurrDaxRef_Amp_f32() \
  (Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_MtrCurrDaxRef_Amp_f32->value)

# define Rte_IRead_CurrParamComp_Per1_MtrCurrQaxRef_Amp_f32() \
  (Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_MtrCurrQaxRef_Amp_f32->value)

# define Rte_IWrite_CurrParamComp_Per1_EstKe_VpRadpS_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstKe_VpRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Per1_EstKe_VpRadpS_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IWrite_CurrParamComp_Per1_EstLd_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstLd_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Per1_EstLd_Henry_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstLd_Henry_f32->value)

# define Rte_IWrite_CurrParamComp_Per1_EstLq_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstLq_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Per1_EstLq_Henry_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstLq_Henry_f32->value)

# define Rte_IWrite_CurrParamComp_Per1_EstR_Ohm_f32(data) \
  ( \
  Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstR_Ohm_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrParamComp_Per1_EstR_Ohm_f32() \
  (&Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_CurrParamComp_Per2_CuTempEst_DegC_f32() \
  (Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per2_CuTempEst_DegC_f32->value)

# define Rte_IRead_CurrParamComp_Per2_MagTempEst_DegC_f32() \
  (Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per2_MagTempEst_DegC_f32->value)

# define Rte_IRead_CurrParamComp_Per2_SiTempEst_DegC_f32() \
  (Rte_Inst_Ap_CurrParamComp->CurrParamComp_Per2_SiTempEst_DegC_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLNomMtrParamBlk_WriteBlock Rte_Call_Ap_CurrParamComp_EOLNomMtrParamBlk_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_EOLNomMtrParam() (Rte_Inst_Ap_CurrParamComp->Pim_EOLNomMtrParam)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLNomMtrParamType *Rte_Pim_EOLNomMtrParam(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_CURRPARAMCOMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrParamComp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrParamComp_Init_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Init_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_CurrParamComp_Init_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Init_EstLd_Henry_f32(void)
 *   void Rte_IWrite_CurrParamComp_Init_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Init_EstLq_Henry_f32(void)
 *   void Rte_IWrite_CurrParamComp_Init_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Init_EstR_Ohm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) CurrParamComp_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrParamComp_Per1
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
 *   Float Rte_IRead_CurrParamComp_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   Float Rte_IRead_CurrParamComp_Per1_MtrCurrQaxRef_Amp_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrParamComp_Per1_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Per1_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_CurrParamComp_Per1_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Per1_EstLd_Henry_f32(void)
 *   void Rte_IWrite_CurrParamComp_Per1_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Per1_EstLq_Henry_f32(void)
 *   void Rte_IWrite_CurrParamComp_Per1_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_CurrParamComp_Per1_EstR_Ohm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) CurrParamComp_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrParamComp_Per2
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
 *   Float Rte_IRead_CurrParamComp_Per2_CuTempEst_DegC_f32(void)
 *   Float Rte_IRead_CurrParamComp_Per2_MagTempEst_DegC_f32(void)
 *   Float Rte_IRead_CurrParamComp_Per2_SiTempEst_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) CurrParamComp_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Get(Float *NomKe_VpRadpS_f32, Float *NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

# define RTE_STOP_SEC_AP_CURRPARAMCOMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1469126548
#    error "The magic number of the generated file <C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/utp/contract/Ap_CurrParamComp/Rte_Ap_CurrParamComp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1469126548
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CURRPARAMCOMP_H */
