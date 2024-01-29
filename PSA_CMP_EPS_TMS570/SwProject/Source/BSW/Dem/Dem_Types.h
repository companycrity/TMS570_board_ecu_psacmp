/* Kernbauer Version: 1.15 Konfiguration: Diag_AsrDem_Vector Erzeugungsgangnummer: 1 */


/*********************************************************************************************************************/
/*!
 * \file     Dem_Types.h
 * \brief    Typedefs for DEM
 * \par      copyright
 * \verbatim
 *  Copyright (c) 2000-2010 by Vector Informatik GmbH. All rights reserved.
 *
 *  This software is copyright protected and proprietary to Vector Informatik GmbH.
 *  Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *  All other rights remain with Vector Informatik GmbH.
 *
 * \endverbatim
 */
/*  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dem_Types.h
 *      Project:  MICROSAR DEM
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Typedefs for DEM
 *
 *  Manufacturer: Vector (MSR R11)
 *  Kernbauer LL: 02.14.00
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 * \author                       Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *- Stefan Huebner                Hrs           Vector Informatik GmbH
 *- Patricia Speidel              Pst           Vector Informatik GmbH
 *- Alexander Ditte               Ade           Vector Informatik GmbH
 *- Matthias Heil                 Mhe           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 * \version  Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *- 02.00.03  2008-06-17  Hrs     -             Initial Version (Vector AUTOSAR 3.0 Evaluation Bundle)
 *- 02.00.04  2008-06-18  Hrs    ESCAN00026509  call EcuM_GeneratorCompatibilityError() with invalid postbuild configuration
 *- 02.01.00  2008-06-18  Hrs     -             limit Dem_DtcChronoRefType by preconfig; generate typedef
 *-                       Hrs    ESCAN00026513  Extension for MSR3.0 generator version checks
 *-           2008-06-24  Hrs    ESCAN00027816  DTC will not be cleared completely
 *-                       Hrs    ESCAN00027850  Invalid Postbuild size of data element EventPriority
 *-           2008-06-25  Hrs     -             Dem_MaxDataValueType always available as typedef
 *- 02.01.01  2008-07-09  Hrs     -             Remove warning about unused argument in Dem_UpdateExtendedRecord()
 *- 02.01.02  2008-07-11  Hrs    ESCAN00028341  Complex vars not assigned correctly with GNU compiler on ARM7/9 controller
 *- 02.02.01  2008-08-06  Pst    -              Update to core 3.00.00
 *- 02.04.00  2008-09-17  Hrs     -             Fix Star12/Cosmic problems with INLINE functions
 *- 02.05.00  2008-11-17  Pst     -             Adapt for GenTool 2.04.00: DTCOrigin in generated differently
 *-                       Pst    ESCAN00029823  PreCompile and Linktime CRC check
 *-                       Pst     -             Dem_UnsetBitWarningIndicatorRequested(EventId) with PASSED
 *-                       Pst     -             Introduced DEM_CONFIRMEDDTC_MEANS_STOREDDTC
 *-                       Pst     -             Implemented FreezeFrame handling
 *-                       Pst     -             Changed handling of event destination
 *-                       Pst    ESCAN00031325  GetIndicatorStatus returns active indicator
 *-           2008-11-28  Pst    ESCAN00028351  Complex vars not assigned correctly with GNU compiler on ARM7/9 controller
 *-                       Pst    ESCAN00031704  Bsw event queue + add. queue > 255 elements leads to unpredictable data access.
 *-                       Pst    ESCAN00031183  Release configuration variant "PreCompile" (also: ESCAN00030119)
 *-                       Pst    ESCAN00029158  Data corruption after PostBuild
 *-           2008-12-18  Hrs    ESCAN00028755  DiagService 14(hex) results OK but DTC was not cleared
 *-                       Hrs    ESCAN00032015  EcuM_GeneratorCompatibilityError(): CRC error due different StatusAvailabilityMask
 *-                       Hrs    ESCAN00032034  Invalid RTE context for callback(s) in Dem_ResetEventStatus()
 *-                       Hrs     -             MISRA improvements
 *-                       Hrs    ESCAN00032302  Runtime is too long if a large event queue is configured
 *-           2009-01-14  Pst    ESCAN00032353  Compile error Cosmic compiler caused by inline function usage
 *-           2009-01-15  Pst    ESCAN00032420  Incorrect argument check with DET
 *-           2009-01-16  Hrs/PstESCAN00032019  Add specific error return codes for Interfaces that do their task later in Dem_MainFuction
 *- 02.06.00  2009-02-03  Hrs    ESCAN00032835  Add support for J1939 complex device driver
 *-                       Hrs    ESCAN00032257  Add support for internal occurrence counter (needs GenTool_Geny v2.06.00 or later)
 *- 02.07.00  2009-03-25  Hrs    ESCAN00034135  Memory Abstraction: incompatible far pointer assignment in Dem_GetFreezeFrameDataIdentifierByDTC()
 *-                       Hrs    ESCAN00032537  Remove unused INLINE functions Dem_IsBit...() in Dem.c
 *-                       Hrs    ESCAN00033116  Change INLINE functions to STATIC_INLINE resp. Macro
 *-                       Hrs    ESCAN00033509  Compiler warnings due to unused INLINE functions
 *-           2009-03-27  Hrs    ESCAN00034212  Compiler Warning: condition is always true
 *- 02.08.00  2009-04-29  Ade    ESCAN00033880  Debounce algorithm 'Time based' shall be supported
 *-           2009-05-13  Ade    ESCAN00035070  Used PrimemIndex instead of ChronoIndex
 *-           2009-06-30  Hrs    ESCAN00035235  Wrong return value for Dem_NvDataInit() callback function
 *-           2009-06-30  Hrs    ESCAN00035888  Service 0x19 0x05, 0x06 runtime optimization
 *-           2009-06-30  Hrs    ESCAN00036021  Add support for variant handling
 *-           2009-07-06  Hrs    ESCAN00036186  pre-processor checks for building the library
 *-           2009-07-07  Hrs    ESCAN00035803  Compiler warning: undefined behavior: the order of volatile accesses is undefined
 *-           2009-07-23  Hrs     -             MISRA improvements
 *-           2009-07-30  Hrs    ESCAN00036752  DCM: Optimized 0x19 0x04/0x05 DEM interaction
 *-           2009-08-12  Hrs     -             Rework Dem_ConfigType
 *-                       Hrs     -             Invalid Response to DCM for DTCs without configured snapshot records
 *- 02.08.03  2009-09-14  Hrs     -             Avoid MISRA violation on not using return value of Dem_AQPush() with DEM_DEV_ERROR_DETECT == STD_OFF
 *-           2009-10-27  Hrs    ESCAN00038154  DET trigger caused by event without snapshot records during 19 03 request
 *-                       Hrs    ESCAN00038434  ServiceId 0x3d was ambivalent (was used with different services/APIs as ApiId with Det_ReportError() )
 *-           2009-11-03  Hrs    ESCAN00038377  With configuration variant PreCompile the API Dem_GetVersionInfo was implemented as macro
 *-                       Hrs    ESCAN00038596  Runtime optimization for implementation of service 19 02/08/0A/0F/13/14
 *-                       Hrs    ESCAN00038166  The status bits warningIndicatorRequest and pendingDTC are wrongly considered to detect status changes
 *-                       Hrs    ESCAN00034411  When event is not stored in the primary memory, occurrence counter was not reported
 *-           2009-11-04  Hrs    ESCAN00038267  Unexpected positive response on requests with unsupported extended records (19 06)
 *- 02.09.00  2010-02-10  Mhe    ESCAN00040744  Adapt version check to new GENy dll 2.10.00
 *- 02.10.00  2010-02-12  Hrs    ESCAN00040807  Prepare source code for non-library deliveries
 *- 02.11.00  2010-03-03  Pst    ESCAN00040736  Harmonize format of justification for MISRA violations to support CDK
 *-           2010-03-08  Pst    ESCAN00040293  Configuration of Warning Indicator Bit was not possible in CANdelaStudio
 *-                       Pst    ESCAN00044699  WarningIndicator Bit is toggling with TestFailed Bit
 *-           2010-04-01  Hrs    ESCAN00039686  Compile error: missing compiler abstraction with cast (Dem_MaxDataValueType *) and (Dem_MaxExtendedDataRecordType *)
 *-           2010-04-27  Hrs    ESCAN00042368  Negative response of DCM/CANdesc on requests 0x19 0x04/0x05/0x06 when no snapshot / extended record is stored
 *- 02.12.00  2010-07-02  Pst     -             Update of generator version
 *- 02.13.00  2010-08-11  Hrs    ESCAN00043460  Refactoring: Reduce length of identifiers
 *-           2010-08-11  Hrs    ESCAN00044591  Sort list of API IDs
 *- 02.13.01  2010-10-12  Hrs    ESCAN00045945  Compiler error when using microcontroller with Paged RAM
 *- 02.14.00  2010-11-30  Hrs    ESCAN00047312  Avoid nesting of Compiler Abstraction macros - P2VAR(P2CONST(...), ...)
 *-           2010-11-30  Hrs    ESCAN00045036  Unify the call sequence of Dem_TriggerOnEvent() and DemCfg_GetInitMonitorFPtr()
 *-           2010-11-30  Hrs    ESCAN00046243  Adapt AUTOSAR version check
 *-           2010-12-01  Hrs    ESCAN00047083  Remove NvM_GetErrorStatus() from Dem_Init()
 */
/******************************************************************************************************************//**
 *
 *  ************    This is version and change information of high level part only                           **********
 *  ************    Please find the version number of the whole module in the previous file header.          **********
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 * \author                       Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *- Stefan Huebner               Hrs           Vector Informatik GmbH
 *- Patricia Speidel             Pst           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 * \version  Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *- 02.00.00  2007-12-07  Hrs     -             Initial Version (after KB split) implementing ASR DEM 2.1.1
 *-                                             Check for wrong (unsupported) DTCorigin in Dem_GetStatusOfDTC (Dem171)
 *-                                             Fix severity filtering in Dem_SetDTCFilter() to support filter mask instead value
 *-                                             Replace nil function pointer from Vector's V_NULL to Autosar's NULL_PTR
 *-                                             Use BCD coding for DEM_SW_MAJOR_VERSION DEM_SW_MINOR_VERSION DEM_SW_PATCH_VERSION
 *-                                             Improve MISRA compliance
 *-                                             Use Dem_DataRecordSizeType instead of DataSizeType
 *-                                             Remove dependency to vector standard types
 *-                                             Replace DemAssert by Dem_DetReportError()
 *- 02.00.01  2008-01-18  Hrs     -             Modified KB split to support further OEM (transparent for existing ones)
 *- 02.00.02  2008-02-01  Hrs     -             Prepare for showing Beta-Disclaimer (if appropriate)
 *- 02.00.03  2008-03-25  Hrs     ESCAN00025430 Port interface Dem_GetDTCOfEvent returns DTC number 0xFFFFFFFF for event ID 0 and internal event IDs
 *- 02.00.04  2008-03-27  Hrs     -             Change DetReportError value in Dem_UpdateSnapshotRecord()
 *-                                             Internal rework to support further OEM
 *- 02.00.05  2008-03-28  Hrs     -             Different decision for support/not support of RTE in Dem_IntTypes.h 
 *- 02.00.06  2008-03-28  Hrs     -             In Dem_IsSupportedDtcOrigin would be no return value if DEM_TYPE_OF_ORIGIN_SUPPORTED was not defined 
 *- 02.00.07  2008-04-02  Hrs     -             [internal] KB-Hook for Version header
 *- 02.01.00  2008-04-09  Hrs     ESCAN00025861 The event status of internal events (BSW errors) was not updated
 *- 02.01.01  2008-04-09  Hrs     ESCAN00025919 Dem_ResetEventStatus() changed event status after calling Dem_DisableEventStatusUpdate()
 *- 02.01.02  2008-04-28  Hrs     ESCAN00026262 Rename files and #include statements according coding styles
 *- 03.00.00  2008-07-29  Hrs     -             Initial KB R3.0 (based on core 02.01.02)
 *-                               ESCAN00026730 No parameter check in function Dem_EnableEventStatusUpdate() for invalid argument values of 'DTCKind'
 *-           2008-08-04  Hrs     ESCAN00024538 <Xxx>_DemInitMonitor{EventName} is triggered by Dem_ClearDTC() only if the DTC is stored (in PrimaryMem)
 *-           2008-08-05  Pst     ESCAN00029069 Declaration of prototype is incompatible with "uint8 Dem_IsValidSsRecordNumber(uint8)"
 *- 03.00.01  2008-08-27  Hrs     -             Add versioncheck for Std_Types.h
 *-           2008-09-08  Hrs     -             Reorder content of Dem_AQElementType to circumvent alignment problems
 *-                               ESCAN00029157 Data corruption after PostBuild
 */
 /* ************    This is version and change information of high level part only                           **********
 *  ************    Please find the version number of the whole module in the previous file header.          **********
 *********************************************************************************************************************/

#if defined(DEM_TYPES_H)
#else
#define DEM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* for typedef Dem_DtcStatusByteType  we require  #include "Dem_Cfg.h" */
#if defined(DEM_CFG_H) || defined(__DEM_CFG_H__)
#else
#error "Wrong #include sequence: Please include \"Dem_Cfg.h\" before including file \"Dem_Types.h\""
#endif

/**
 * File Rte_Type.h contains the typedefs and defines which are required as PortInterface argument
 * and also used in the DEM. If we are not using the RTE, the types will be defined by ourself below
 */
#if (DEM_USE_RTE == STD_ON)
#include "Rte_Type.h"
#endif



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define DEM_NVDATA_PATTERN_SIZE                         4


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*
 * If we don't have RTE, that defines PortInterface typedefs and defines, we will do it ourself here:
 * With RTE, these definitions are imported above via  #include "Rte_Type.h".
 * The Vector RTE (RTE_VENDOR_ID==0x1Eu) will suppress (optimize) some defines/typedefs, if a port is not configured.
 * In this case we define the types here to avoid compile errors.
 * For NON-Vector RTE, we cannot detect the suppression of the definition, so such RTE must always generate 
 * all required datatype definitions.
 */
#if defined(RTE_VENDOR_ID)
# if (RTE_VENDOR_ID == 0x1Eu)
#   define DEM_USE_RTE_FROM_VECTOR  STD_ON
# else
#   define DEM_USE_RTE_FROM_VECTOR  STD_OFF
# endif
#else
#  define DEM_USE_RTE_FROM_VECTOR  STD_OFF
#endif


/* StatusMaskType is used in DCM-API: SetDTCFilter, GetStatusOfDTC, GetDTCStatusAvailabilityMask and GetNextFilteredDTC
 *  and SW-C/FIM API TriggerOnDTCStatus. It contains status bits (typically) masked with the status availability mask.
 * This is one of the external status types, /see Dem_EventStatusExtendedType                                            */
#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_DTCStatusMaskType)))
typedef uint8 Dem_DTCStatusMaskType;                            /* DTCStatusMask as defined in ISO14229-1 */
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_DTCType)))
typedef uint32 Dem_DTCType;
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_DTCKindType)))
typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                             0x01  /* Select all DTCs */
#define DEM_DTC_KIND_EMISSION_REL_DTCS                    0x02  /* Select OBD-relevant DTCs */
#endif

/* DTC number type (Dem_EventIdType) is dependent on pre-configured, maximum possible DTC count (+1). */
#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_EventIdType)))
# if (DEM_MAX_NUMBER_OF_EVENTS <= 255)
typedef uint8  Dem_EventIdType;
# else
typedef uint16 Dem_EventIdType;
# endif
#endif

/* EventStatusExtendedType is used in SWC-API: ResetEventStatus, GetEventStatus, GetEventFailed and GetEventTested
 *  and SW-C/FIM API TriggerOnEventStatus. It contains the full set of status bits (unmasked).
 * This is one of the external status types, /see Dem_DTCStatusMaskType
 */
#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_EventStatusExtendedType)))
typedef uint8 Dem_EventStatusExtendedType;                /* DEM definition, currently(!) identical to Status bits of ISO 14229-1 */
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_FaultDetectionCounterType)))
typedef sint8 Dem_FaultDetectionCounterType;
#endif

/* typedef uint8 Dem_DTCTranslationFormatType;                     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_DTC_TRANSLATION_ISO15031_6                 0x01     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_DTC_TRANSLATION_ISO14229_1                 0x02     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_DTC_TRANSLATION_CUSTOMER                   0x03     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_DTC_TRANSLATION_INTERNAL                   0x04     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_EventStatusType)))
typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                           0x00  /* Event debouncing by Monitor Function - result is testPassed */
#define DEM_EVENT_STATUS_FAILED                           0x01  /* Event debouncing by Monitor Function - result is testFailed */
#define DEM_EVENT_STATUS_PREPASSED                        0x02  /* Event debouncing by DEM module - Monitor Function reports testPassed */
#define DEM_EVENT_STATUS_PREFAILED                        0x03  /* Event debouncing by DEM module - Monitor Function reports testFailed */
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_IndicatorStatusType)))
typedef uint8 Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF                                 0x00  /* Indicator off */
#define DEM_INDICATOR_CONTINUOUS                          0x01  /* Continuous on */
#define DEM_INDICATOR_BLINKING                            0x02  /* blinking mode */
#define DEM_INDICATOR_BLINK_CONT                          0x03  /* Continuous and blinking mode */
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_InitMonitorKindType)))
typedef uint8 Dem_InitMonitorKindType;
#define DEM_INIT_MONITOR_CLEAR                            0x01  /* Monitor Function of the EventId is cleared and all internal values and states are reset. */
#define DEM_INIT_MONITOR_RESTART                          0x02  /* Monitor Function of the EventId is requested to restart. */
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_OperationCycleIdType)))
typedef uint8 Dem_OperationCycleIdType;
#endif

#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_OperationCycleStateType)))
typedef uint8 Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                             0x01  /* Start of operation cycle */
#define DEM_CYCLE_STATE_END                               0x02  /* End of operation cycle */
#endif


/*
 * The maximum buffer sizes for Snapshot-DID records resp. Ext.Data records are set by configuration.
 * Dem_MaxDataValueType          is the largest defined DID record
 * Dem_MaxExtendedDataRecordType is the largest defined ExtendedData record
 * For the API Argument definition we may use the unspecified size of the arrays instead:
 */
#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_MaxDataValueType)))
typedef uint8 Dem_MaxDataValueType[];                                                             /* PRQA S 3650 *//* The size of the array is undetermined - according AUTOSAR it is always accessed via pointer and the user magically knows its size. */
#endif
#if (DEM_USE_RTE == STD_OFF) || ((DEM_USE_RTE == STD_ON) && (DEM_USE_RTE_FROM_VECTOR == STD_ON) && (! defined(Rte_TypeDef_Dem_MaxExtendedDataRecordType)))
typedef uint8 Dem_MaxExtendedDataRecordType[];                                                    /* PRQA S 3650 *//* The size of the array is undetermined - according AUTOSAR it is always accessed via pointer and the user magically knows its size. */
#endif



typedef uint8 Dem_DTCOriginType;
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                     0x01  /* Event information located in the primary memory. */
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                      0x02  /* Event information located in the mirror memory. */
#define DEM_DTC_ORIGIN_PERMANENT                          0x03  /* not supported yet */
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY                   0x04  /* Event information located in the secondary memory. */

/*
 * These Dem_OperationCycle/HealingCycle IDs are predefined. 
 * Further defined cycles are simply mapped to these cycles.
 */
#define DEM_IGNITION                                      0
#define DEM_OBD_DCY                                       1
#define DEM_WARMUP                                        2
#define DEM_POWER                                         3

typedef uint8 Dem_ViewIdType;

/* internal DTC status info stored in NVRAM */
/* with R3.0 this definition is now identical to Dem_EventStatusExtendedType */
typedef uint8 Dem_DtcStatusByteType;
/*
(1u << 0) = 0x01 testFailed
(1u << 1) = 0x02 testFailedThisOperationCycle
(1u << 2) = 0x04 pendingDTC
(1u << 3) = 0x08 confirmedDTC
(1u << 4) = 0x10 testNotCompletedSinceLastClear
(1u << 5) = 0x20 testFailedSinceLastClear
(1u << 6) = 0x40 testNotCompletedThisOperationCycle
(1u << 7) = 0x80 warningIndicatorRequested
*/

#define DEM_EVENTSTATUSEXT_CLEARED_DTC                    0x50  /* ISO 14229-1 status of a cleared DTC */


/* internal DTC status info in RAM (never saved to NVRAM) */
typedef uint8 Dem_DtcInternalStatusType;
/*
 (1u << 0) = 0x01 filteredDTC
 (1u << 1) = 0x02 prestoredEvent
 (1u << 2) = 0x04 storedDTC, only if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
*/


#define DEM_GET_FFDATA_ID_ALL                             0xffffu           /* API Dem_GetFreezeFrameDataByDTC(): request ALL DIDs */

typedef uint32 Dem_DTCGroupType;
#define DEM_DTC_GROUP_EMISSION_REL_DTCS                   0x000000uL        /* ISO 14229-1 Annex D.1: groupOfDTC parameter, Emission-related systems */
/* other DEM_DTC_GROUP_xxx_DTCS are defined in Dem_Cfg.h (if necessary) */
#define DEM_DTC_GROUP_ALL_DTCS                            0xffffffuL        /* ISO 14229-1 Annex D.1: groupOfDTC parameter, All Groups (all DTCs) */

typedef uint8 Dem_DTCGroupKindType;         /* Bit coded DTCGroup */
#define DEM_DTC_GROUPKIND_EMISSION_REL                    (uint8)(1u<<0)
#define DEM_DTC_GROUPKIND_POWERTRAIN                      (uint8)(1u<<1)
#define DEM_DTC_GROUPKIND_CHASSIS                         (uint8)(1u<<2)
#define DEM_DTC_GROUPKIND_BODY                            (uint8)(1u<<3)
#define DEM_DTC_GROUPKIND_NETWORK_COM                     (uint8)(1u<<4)
#define DEM_DTC_GROUPKIND_ALL_DTCS                        (uint8)(0xffu)

typedef struct Dem_DTCGroupMappingTypeTag
{
  Dem_DTCGroupKindType  GroupKind;
  Dem_DTCType           DTCnumber;
} Dem_DTCGroupMappingType;


typedef uint8 Dem_DTCRequestType;
#define DEM_FIRST_FAILED_DTC                              0x01  /* first failed DTC requested */
#define DEM_MOST_RECENT_FAILED_DTC                        0x02  /* most recent failed DTC requested */
#define DEM_FIRST_DET_CONFIRMED_DTC                       0x03  /* first detected confirmed DTC requested */
#define DEM_MOST_REC_DET_CONFIRMED_DTC                    0x04  /* most recently detected confirmed DTC requested */

typedef uint8 Dem_EventPriorityType;
typedef uint8 Dem_DataByteType;
typedef uint8 Dem_IndicatorIdType;

typedef uint16 Dem_NvMBlockIdType;

typedef uint8 Dem_FilterWithSeverityType;
#define DEM_FILTER_WITH_SEVERITY_YES                      0x00  /* Severity information used */
#define DEM_FILTER_WITH_SEVERITY_NO                       0x01  /* Severity information not used */

typedef uint8 Dem_DTCSeverityType;
#define DEM_SEVERITY_NO_SEVERITY                          0x00  /* No severity information available */
#define DEM_SEVERITY_MAINTENANCE_ONLY                     0x20  /* maintenance required */
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT                   0x40  /* check at next halt */
#define DEM_SEVERITY_CHECK_IMMEDIATELY                    0x80  /* Check immediately */


/* Return values */
typedef uint8 Dem_ReturnSetDTCFilterType;
#define DEM_FILTER_ACCEPTED                               0x00  /* Filter was accepted */
#define DEM_WRONG_FILTER                                  0x01  /* Wrong filter selected */

typedef uint8 Dem_FilterForFaultDetectionCounterType;
#define DEM_FILTER_FOR_FDC_YES                            0x00  /* Fault Detection Counter information used */
#define DEM_FILTER_FOR_FDC_NO                             0x01  /* Fault Detection Counter information not used */
/* #define DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_YES       0x00     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO        0x01     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */

typedef uint8 Dem_ReturnSetViewFilterType;
#define DEM_VIEW_ID_ACCEPTED                              0x00  /* View ID was accepted */
#define DEM_WRONG_ID                                      0x01  /* Wrong View ID selected */

typedef uint8 Dem_ReturnGetStatusOfDTCType;
#define DEM_STATUS_OK                                     0x00  /* Status of DTC is OK */
#define DEM_STATUS_WRONG_DTC                              0x01  /* Wrong DTC */
#define DEM_STATUS_WRONG_DTCORIGIN                        0x02  /* Wrong DTC origin */
#define DEM_STATUS_WRONG_DTCKIND                          0x03  /* DTC kind wrong */
#define DEM_STATUS_FAILED                                 0x04  /* DTC failed */

typedef uint8 Dem_ReturnGetNextFilteredDTCType;
#define DEM_FILTERED_OK                                   0x00  /* Returned next filtered DTC */
#define DEM_FILTERED_NO_MATCHING_DTC                      0x01  /* No DTC matched */
#define DEM_FILTERED_WRONG_DTCKIND                        0x02  /* DTC kind wrong */

typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
#define DEM_NUMBER_OK                                     0x00  /* get of number of DTC was successful */
#define DEM_NUMBER_FAILED                                 0x01  /* get of number of DTC failed */
#define DEM_NUMBER_PENDING                                0x02  /* get of number of DTC is pending */

typedef uint8 Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                      0x00  /* DTC successfully cleared */
#define DEM_CLEAR_WRONG_DTC                               0x01  /* Wrong DTC */
#define DEM_CLEAR_WRONG_DTCORIGIN                         0x02  /* Wrong DTC origin */
#define DEM_CLEAR_WRONG_DTCKIND                           0x03  /* DTC kind wrong */
#define DEM_CLEAR_FAILED                                  0x04  /* DTC not cleared */
#define DEM_DTC_PENDING                                   0x05  /* Clearing of DTC is pending */

typedef uint8 Dem_ReturnControlDTCStorageType;
#define DEM_CONTROL_DTC_STORAGE_OK                        0x00  /* DTC storage control successful */
#define DEM_CONTROL_DTC_STORAGE_N_OK                      0x01  /* DTC storage control not successful */
#define DEM_CONTROL_DTC_WRONG_DTCGROUP                    0x02  /* DTC storage control not successful because group of DTC was wrong */

typedef uint8 Dem_ReturnControlEventUpdateType;
#define DEM_CONTROL_EVENT_UPDATE_OK                       0x00  /* Event storage control successful */
#define DEM_CONTROL_EVENT_UPDATE_N_OK                     0x01  /* Event storage control not successful */
#define DEM_CONTROL_EVENT_WRONG_DTCGROUP                  0x02  /* Event storage control not successful because group of DTC was wrong */

typedef uint8 Dem_ReturnGetDTCOfFreezeFrameRecordType;
#define DEM_GET_DTCOFFF_OK                                0x00  /* DTC successfully returned */
#define DEM_GET_DTCOFFF_WRONG_RECORD                      0x01  /* Wrong record */
#define DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD                 0x02  /* No DTC for record available */
#define DEM_GET_DTCOFFF_WRONG_DTCKIND                     0x03  /* DTC kind wrong */

typedef uint8 Dem_ReturnGetFreezeFrameDataIdentifierByDTCType;
#define DEM_GET_ID_OK                                     0x00  /* FreezeFrame data identifier successfully returned */
#define DEM_GET_ID_WRONG_DTC                              0x01  /* Wrong DTC */
#define DEM_GET_ID_WRONG_DTCORIGIN                        0x02  /* Wrong DTC origin */
#define DEM_GET_ID_WRONG_DTCKIND                          0x03  /* DTC kind wrong */
#define DEM_GET_ID_WRONG_FF_TYPE                          0x04  /* FreezeFrame type wrong */

typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                                     0x00  /* Extended data record successfully returned */
#define DEM_RECORD_WRONG_DTC                              0x01  /* Wrong DTC */
#define DEM_RECORD_WRONG_DTCORIGIN                        0x02  /* Origin wrong */
#define DEM_RECORD_WRONG_DTCKIND                          0x03  /* DTC kind wrong */
#define DEM_RECORD_WRONG_NUMBER                           0x04  /* Record number wrong */
#define DEM_RECORD_WRONG_BUFFERSIZE                       0x05  /* Provided buffer to small */

/* typedef uint8 Dem_ReturnGetDTCOfEventType;                      not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_DTCOFEVENT_OK                          0x00     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_DTCOFEVENT_WRONG_EVENTID               0x01     wrong definition by ch 11.3 in  DEM Spec V2.2.1 (R3.0 Rev 0002), see below */
/* #define DEM_GET_DTCOFEVENT_WRONG_TRANSLATION           0x02     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
#define DEM_GET_DTCOFEVENT_WRONG_EVENTID                  0x05  /* Wrong EventId (see Dem198) */
#define DEM_GET_DTCOFEVENT_WRONG_DTCKIND                  0x04  /* DTC kind wrong (see Dem198) */

typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                                     0x00  /* Status of DTC was OK */
#define DEM_OCCURR_WRONG_DTCKIND                          0x01  /* DTC kind wrong */
#define DEM_OCCURR_FAILED                                 0x02  /* DTC failed */

typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
#define DEM_GET_FFDATABYDTC_OK                            0x00  /* Size successfully returned */
#define DEM_GET_FFDATABYDTC_WRONG_DTC                     0x01  /* Wrong DTC */
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN               0x02  /* Wrong DTC origin */
#define DEM_GET_FFDATABYDTC_WRONG_DTCKIND                 0x03  /* DTC kind wrong */
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER            0x04  /* Wrong Record Number */
#define DEM_GET_FFDATABYDTC_WRONG_DATAID                  0x05  /* Wrong DataID */
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE              0x06  /* provided buffer size to small */

typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;
#define DEM_GET_SIZEOFEDRBYDTC_OK                         0x00  /* Size successfully returned */
#define DEM_GET_SIZEOFEDRBYDTC_W_DTC                      0x01  /* Wrong DTC */
#define DEM_GET_SIZEOFEDRBYDTC_W_DTCOR                    0x02  /* Wrong DTC origin */
#define DEM_GET_SIZEOFEDRBYDTC_W_DTCKI                    0x03  /* DTC kind wrong */
#define DEM_GET_SIZEOFEDRBYDTC_W_RNUM                     0x04  /* Wrong Record Number */
/* #define DEM_GET_SIZEOFEDRBYDTCTYPE_OK                  0x00     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC           0x01     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN     0x02     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND       0x03     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_RECORDNUMBER  0x04     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
  

typedef uint8 Dem_ReturnGetSizeOfFreezeFrameType;
#define DEM_GET_SIZEOFFF_OK                               0x00  /* Size successfully returned. */
#define DEM_GET_SIZEOFFF_WRONG_DTC                        0x01  /* Wrong DTC */
#define DEM_GET_SIZEOFFF_WRONG_DTCOR                      0x02  /* Wrong DTC origin */
#define DEM_GET_SIZEOFFF_WRONG_DTCKIND                    0x03  /* DTC kind wrong */
#define DEM_GET_SIZEOFFF_WRONG_RNUM                       0x04  /* Wrong Record Number */
/* #define DEM_GET_SIZEOFFREEZEFRAMETYPE_OK               0x00     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC        0x01     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN  0x02     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND    0x03     not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */
/* #define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_RECORDNUMBER  0x04  not used any more in  DEM Spec V2.2.1 (R3.0 Rev 0002) */


typedef uint8 Dem_ReturnGetViewIDOfDTCType;
#define DEM_VIEWID_OK                                     0x00  /* Status of ViewId is OK */
#define DEM_VIEWID_WRONG_DTC                              0x01  /* Wrong DTC */
#define DEM_VIEWID_WRONG_DTCKIND                          0x02  /* DTC kind wrong */

typedef uint8 Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                          0x00  /* Severity successfully returned.  */
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC                   0x01  /* Wrong DTC */
#define DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN             0x02  /* Wrong DTC origin  (unused) */ 
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY                  0x03  /* Severity information is not available */


typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_InitMonitorFPtrType) (Dem_InitMonitorKindType InitMonitorKind); /* PRQA S 0850 *//* MD_MSR_19.8 */

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_GetDataValueByDataIdentifierType) (P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) /* DataValueByDataIDBuffer */);   /* buffer argument's type is (uint8 *[]) see Bugzillas #22258 and #22401 */ /* PRQA S 0850, 3651 *//* MD_MSR_19.8, MD_DEM_3651 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_GetExtDataRecordFPtrType) (P2VAR(Dem_MaxExtendedDataRecordType, AUTOMATIC, DEM_APPL_DATA) /* ExtendedDataRecordBuffer */); /* buffer argument's type is (uint8 *[]) see Bugzillas #22258 and #22401 */ /* PRQA S 0850, 3651 *//* MD_MSR_19.8, MD_DEM_3651 */

typedef uint16 Dem_TriggerOnEventIndexType;
typedef uint16 Dem_TriggerOnDTCIndexType;

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_TriggerFunctionType) (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew);        /* PRQA S 0850 *//* MD_MSR_19.8 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_TriggerDTCFunctionType) (Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);        /* PRQA S 0850 *//* MD_MSR_19.8 */

typedef P2CONST(uint16, TYPEDEF, DEM_PBCFG) Dem_RecordDIDAddrType;

/* Action queue for storing API call triggers. Queue is drained in Dem_MainFunction() */
typedef struct
{
  union
  {                                                                                           /* PRQA S 0750 *//* MD_MSR_18.4 */
    struct
    {
      Dem_EventIdType     EventIdentifier;      /* uint8/uint16 */
      Dem_EventStatusType Status;               /* 2 bit */
    } event;
    struct
    {
      Dem_OperationCycleIdType    CycleId;      /* uint8 */
      Dem_OperationCycleStateType CycleState;   /* 2 bit */
    } opcycle;
    struct
    {
      Dem_DTCGroupKindType  BitcodedDtcGroup;   /* uint8 */
      Dem_DTCKindType       DTCKind;            /* 2 bit */
      Dem_DTCOriginType     DTCOrigin;          /* 2 bit */
    } dtc;
  } arg;
  uint8 Action; 
} Dem_AQElementType;

/*
typedef struct Dem_NonVolatileDataTypeTag {...} Dem_NonVolatileDataType;
  is in file Dem_Lcfg.h, as the size of Dem_NonVolatileDataType is dependent on
  the (PostBuild) selectable number of events, ...
  Someone might think the size is constant, when the typedef is written here together
  with other constant types.
*/



#if (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON) || (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_PREINIT_HAS_CONFIG_PARAM == STD_ON)
/* Support of configuration parameter with Dem_PreInit(), used with multiple configuration and variant handling */
typedef struct
{
  uint32 ConfigurationMask;   /* this parameter is a bitfield */
} Dem_ConfigType;
#endif /* DEM_SUPPORT_MULTIPLE_CONFIG || DEM_SUPPORT_VARIANT_HANDLING || DEM_PREINIT_HAS_CONFIG_PARAM */


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* DEM_TYPES_H */
