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
 *          File:  Rte_Ap_CtrlPolarityBrshlss.h
 *     Workspace:  C:/Ford_Intergration/Ford_S550_P552/CtrlPolarityBrshlss/autosar/Ap_CtrlPolarityBrshlss.dcf
 *     SW-C Type:  Ap_CtrlPolarityBrshlss
 *  Generated at:  Tue Mar 24 09:41:42 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_CtrlPolarityBrshlss> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CTRLPOLARITYBRSHLSS_H
# define _RTE_AP_CTRLPOLARITYBRSHLSS_H

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

typedef P2CONST(struct Rte_CDS_Ap_CtrlPolarityBrshlss, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssiMechPolarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn1Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn2Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn3Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn4Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn5Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn6Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn7Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwPosn8Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq1Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq2Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq3Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq4Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq5Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq6Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq7Polarity_Cnt_s08 (0)
# define Rte_InitValue_HwTq8Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotElecMeclPolarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn1Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn2Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn3Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn4Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn5Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn6Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn7Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotMeclPosn8Polarity_Cnt_s08 (0)
# define Rte_InitValue_MotVelPolarity_Cnt_s08 (0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CtrlPolarityBrshlss_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CtrlPolarityBrshlss_Polarity_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CtrlPolarityBrshlss_Polarity_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_DATA) DstPtr);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AssiMechPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08
# define Rte_Write_HwPosn1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08
# define Rte_Write_HwPosn2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08
# define Rte_Write_HwPosn3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08
# define Rte_Write_HwPosn4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08
# define Rte_Write_HwPosn5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08
# define Rte_Write_HwPosn6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08
# define Rte_Write_HwPosn7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08
# define Rte_Write_HwPosn8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08
# define Rte_Write_HwTq1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08
# define Rte_Write_HwTq2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08
# define Rte_Write_HwTq3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08
# define Rte_Write_HwTq4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08
# define Rte_Write_HwTq5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08
# define Rte_Write_HwTq6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08
# define Rte_Write_HwTq7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08
# define Rte_Write_HwTq8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08
# define Rte_Write_MotElecMeclPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08
# define Rte_Write_MotMeclPosn1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08
# define Rte_Write_MotMeclPosn8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08
# define Rte_Write_MotVelPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_CtrlPolarityBrshlss_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_Polarity_WriteBlock Rte_Call_Ap_CtrlPolarityBrshlss_Polarity_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_Polarity_Cnt_Str() (Rte_Inst_Ap_CtrlPolarityBrshlss->Pim_Polarity_Cnt_Str)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Polarity_DataType *Rte_Pim_Polarity_Cnt_Str(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AssiMechPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotElecMeclPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotVelPolarity_Cnt_s08(SInt8 data)
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

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_ReadPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Polarity_SCom_ReadPolarity(UInt32 *PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_VAR) PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Polarity_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_Polarity_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

# define RTE_STOP_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1427203617
#    error "The magic number of the generated file <C:/Ford_Intergration/Ford_S550_P552/CtrlPolarityBrshlss/utp/contract/Ap_CtrlPolarityBrshlss/Rte_Ap_CtrlPolarityBrshlss.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1427203617
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CTRLPOLARITYBRSHLSS_H */
