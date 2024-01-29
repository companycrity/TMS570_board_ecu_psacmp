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
 *          File:  Rte_Ap_TrqCanc.h
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/autosar
 *     SW-C Type:  Ap_TrqCanc
 *  Generated at:  Thu Jul 21 16:42:12 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TrqCanc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TRQCANC_H
# define _RTE_AP_TRQCANC_H

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

typedef P2CONST(struct Rte_CDS_Ap_TrqCanc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstLd_Henry_f32 ((Float)0)
# define Rte_InitValue_EstLq_Henry_f32 ((Float)0)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrTrqCmdMRFScl_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TrqCanc_EOLCogTrqCanc_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TrqCanc_EOLCogTrqCanc_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) DstPtr);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TrqCanc_EOLCogTrqRplComp_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TrqCanc_EOLCogTrqRplComp_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) DstPtr);
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

# define Rte_IRead_TrqCanc_Init_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Init_EstKe_VpRadpS_f32->value)

# define Rte_IRead_TrqCanc_Per1_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IRead_TrqCanc_Per1_EstLd_Henry_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_EstLd_Henry_f32->value)

# define Rte_IRead_TrqCanc_Per1_EstLq_Henry_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_EstLq_Henry_f32->value)

# define Rte_IRead_TrqCanc_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_TrqCanc_Per1_MtrCurrDaxRef_Amp_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_MtrCurrDaxRef_Amp_f32->value)

# define Rte_IRead_TrqCanc_Per1_MtrCurrQaxRef_Amp_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_MtrCurrQaxRef_Amp_f32->value)

# define Rte_IRead_TrqCanc_Per1_MtrTrqCmdMRFScl_MtrNm_f32() \
  (Rte_Inst_Ap_TrqCanc->TrqCanc_Per1_MtrTrqCmdMRFScl_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLCogTrqCanc_WriteBlock Rte_Call_Ap_TrqCanc_EOLCogTrqCanc_WriteBlock
# define Rte_Call_EOLCogTrqRplComp_WriteBlock Rte_Call_Ap_TrqCanc_EOLCogTrqRplComp_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_CogTrqCal() (*Rte_Inst_Ap_TrqCanc->Pim_CogTrqCal)
# else
#  define Rte_Pim_CogTrqCal() (Rte_Inst_Ap_TrqCanc->Pim_CogTrqCal)
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_CogTrqRplComp() (*Rte_Inst_Ap_TrqCanc->Pim_CogTrqRplComp)
# else
#  define Rte_Pim_CogTrqRplComp() (Rte_Inst_Ap_TrqCanc->Pim_CogTrqRplComp)
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt16 *Rte_Pim_CogTrqCal(void)
# else
 *   CoggingCancTrq *Rte_Pim_CogTrqCal(void)
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt16 *Rte_Pim_CogTrqRplComp(void)
# else
 *   CoggingCancTrqRplComp *Rte_Pim_CogTrqRplComp(void)
# endif
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_TRQCANC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCanc_Init
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
 *   Float Rte_IRead_TrqCanc_Init_EstKe_VpRadpS_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCanc_Per1
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
 *   Float Rte_IRead_TrqCanc_Per1_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_EstLd_Henry_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_EstLq_Henry_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_MtrCurrQaxRef_Amp_f32(void)
 *   Float Rte_IRead_TrqCanc_Per1_MtrTrqCmdMRFScl_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCanc_Scom_ReadCogTrqCal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadCogTrqCal> of PortPrototype <TrqCanc_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void TrqCanc_Scom_ReadCogTrqCal(UInt16 *CogTrqCalPtr, UInt16 ID)
# else
 *   void TrqCanc_Scom_ReadCogTrqCal(CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_ReadCogTrqCal(P2VAR(UInt16, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_ReadCogTrqCal(P2VAR(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCanc_Scom_SetCogTrqCal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCogTrqCal> of PortPrototype <TrqCanc_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLCogTrqCanc_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLCogTrqCanc_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLCogTrqRplComp_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLCogTrqRplComp_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
# else
 *   void TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif

# define RTE_STOP_SEC_AP_TRQCANC_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1469135432
#    error "The magic number of the generated file <C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/utp/contract/Ap_TrqCanc/Rte_Ap_TrqCanc.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1469135432
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TRQCANC_H */
