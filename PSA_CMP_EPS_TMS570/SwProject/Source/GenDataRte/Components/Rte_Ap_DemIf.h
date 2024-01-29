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
 *          File:  Components/Rte_Ap_DemIf.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DEMIF_H
# define _RTE_AP_DEMIF_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_DemIf_CTCFailed_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BatteryVoltage_Volt_f32 (0.0F)
#  define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
#  define Rte_InitValue_CTCFailed_Cnt_lgc (FALSE)
#  define Rte_InitValue_CTerm_Cnt_lgc (FALSE)
#  define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
#  define Rte_InitValue_EtatMt_Cnt_u08 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd6_SystemState6_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_6, RTE_VAR_NOINIT) Rte_Task_10ms_6;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_DemIf_Per_BatteryVoltage_Volt_f32() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_DemIf_DemIf_Per.Rte_BatteryVoltage_Volt_f32.value)

#  define Rte_IRead_DemIf_Per_BusOff_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_DemIf_DemIf_Per.Rte_BusOff_Cnt_lgc.value)

#  define Rte_IRead_DemIf_Per_CTerm_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_DemIf_DemIf_Per.Rte_CTerm_Cnt_lgc.value)

#  define Rte_IRead_DemIf_Per_ElectronicIntegration_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_DemIf_DemIf_Per.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IRead_DemIf_Per_EtatMt_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_DemIf_DemIf_Per.Rte_EtatMt_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CTCFailed_Cnt_lgc Rte_Write_Ap_DemIf_CTCFailed_Cnt_lgc
#  define Rte_Write_Ap_DemIf_CTCFailed_Cnt_lgc(data) (Rte_DemIf_CTCFailed_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd6_SystemState6_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Ignition_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DemShutdown(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Per(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc);

# define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_DemIf_E_NOT_OK (1U)

#  define RTE_E_EpsEn_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_DEMIF_H */
