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
 *          File:  Components/Rte_Ap_CtrlPolarityBrshlss.h
 *     Workspace:  C:/synergy_projects_working/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CTRLPOLARITYBRSHLSS_H
# define _RTE_AP_CTRLPOLARITYBRSHLSS_H

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

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AssiMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn1Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn2Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn3Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn4Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn5Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn6Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn7Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosn8Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq1Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq2Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq3Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq4Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq5Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq6Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq7Polarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTq8Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotElecMeclPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn1Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn2Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn3Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn4Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn5Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn6Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn7Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn8Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotVelPolarity_Cnt_s08 (0)
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
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AssiMechPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosn8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTq8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotElecMeclPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn1Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn2Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn3Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn4Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn5Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn6Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn7Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotMeclPosn8Polarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MotVelPolarity_Cnt_s08 Rte_Write_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08
#  define Rte_Write_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08(data) (Rte_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Polarity_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)3, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(Polarity_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_Polarity_Cnt_Str() \
  (&Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_Init1(void);

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_VAR) PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

# define RTE_STOP_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_CTRLPOLARITYBRSHLSS_H */
