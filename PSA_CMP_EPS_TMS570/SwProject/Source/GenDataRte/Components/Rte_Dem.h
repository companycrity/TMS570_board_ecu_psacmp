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
 *          File:  Components/Rte_Dem.h
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DEM_H
# define _RTE_DEM_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DEMIF_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);
#  define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBDTCStatusChange_DemIf_DTCStatusChanged DemIf_DTCStatusChanged
#  define RTE_START_SEC_AP_FAULTLOG_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);
#  define RTE_STOP_SEC_AP_FAULTLOG_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBDTCStatusChange_FaultLog_DTCStatusChanged FaultLog_DTCStatusChanged
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd401_GetDataValueByDataIdentifier CBValByDID_0xd401_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd403_GetDataValueByDataIdentifier CBValByDID_0xd403_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd404_GetDataValueByDataIdentifier CBValByDID_0xd404_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd405_GetDataValueByDataIdentifier CBValByDID_0xd405_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd407_GetDataValueByDataIdentifier CBValByDID_0xd407_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd408_GetDataValueByDataIdentifier CBValByDID_0xd408_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd409_GetDataValueByDataIdentifier CBValByDID_0xd409_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd40b_GetDataValueByDataIdentifier CBValByDID_0xd40b_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd40c_GetDataValueByDataIdentifier CBValByDID_0xd40c_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd40d_GetDataValueByDataIdentifier CBValByDID_0xd40d_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd40f_GetDataValueByDataIdentifier CBValByDID_0xd40f_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd410_GetDataValueByDataIdentifier CBValByDID_0xd410_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd412_GetDataValueByDataIdentifier CBValByDID_0xd412_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd414_GetDataValueByDataIdentifier CBValByDID_0xd414_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd415_GetDataValueByDataIdentifier CBValByDID_0xd415_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd418_GetDataValueByDataIdentifier CBValByDID_0xd418_GetDataValueByDataIdentifier
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CBValByDID_0xd41b_GetDataValueByDataIdentifier CBValByDID_0xd41b_GetDataValueByDataIdentifier


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_DEM_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_DEM_APPL_CODE) Dem_MainFunction(void);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_DEM_APPL_VAR) DTC);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventStatus(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatus);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventTested(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType parg0, P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, RTE_DEM_APPL_VAR) EventIdFaultDetectionCounter);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetIndicatorStatus(UInt8 parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEM_APPL_VAR) IndicatorStatus);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus);

FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState);

# define RTE_STOP_SEC_DEM_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_CallbackGetDataValueByDataId_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_DEM_E_QUEUE_OVERFLOW (15U)

#  define RTE_E_DiagnosticMonitor_DEM_GET_DTCOFEVENT_WRONG_DTCKIND (4U)

#  define RTE_E_DiagnosticMonitor_DEM_GET_DTCOFEVENT_WRONG_EVENTID (5U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IndicatorStatus_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW (15U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_DEM_H */
