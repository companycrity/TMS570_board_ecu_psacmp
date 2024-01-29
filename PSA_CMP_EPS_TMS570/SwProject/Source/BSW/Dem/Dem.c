/* Kernbauer Version: 1.15 Konfiguration: Diag_AsrDem_Vector Erzeugungsgangnummer: 1 */


/*********************************************************************************************************************/
/*!
 * \file     Dem.c
 * \brief    Implementation of DEM
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
 *         File:  Dem.c
 *      Project:  MICROSAR DEM
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of DEM
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

/* configuration, interrupt handling implementations differ from the 
 * source identification define used here. The naming 
 * schemes for those files can be taken from this list: 
 * 
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE
 */
#define DEM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0857 EOF *//* MD_DEM_1.1_0857 */

#include "Dem.h"

/* Link-time dependent types */
#include "Dem_Lcfg.h"

/* PostBuild data structures and types */
# include "Dem_PBcfg.h"

#if (DEM_DEV_ERROR_DETECT == STD_ON)
/* Include Development Error Tracer */
# include "Det.h"
#endif

#if (DEM_USE_FIM_NOTIFICATION_API == STD_ON)
/* On event change call FIM API Fim_DemTriggerOnEventStatus() */
# include "FiM.h"
#endif

/* Check the state of preloaded NVRAM blocks and trigger the post-shutdown writing to NVRAM */
#if (DEM_USE_NVM == STD_ON)
# include "NvM.h"
#endif

/* Include for handling of critical sections */
# include "SchM_Dem.h"

/* Include for extended version check */
#if defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
#else
# include "v_ver.h"
#endif
#if ((!defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )) || ( DEM_CRC_CHECK == STD_ON ))
# include "EcuM_Cbk.h"
#endif

/* NEXTEER MANUAL EDIT - Dem snapshot data (DID D40A) */
#include "CDD_Data.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (DIAG_ASRDEM_VECTOR_VERSION         != 0x0214u) \
    || (DIAG_ASRDEM_VECTOR_RELEASE_VERSION != 0x00u)  )
  #error "Vendor specific version numbers of Dem.c and Dem.h are inconsistent"
#endif


/* AR3-F1155 - Version check for StandardTypes (Std_Types.h) */
#if (DEM_VERSION_INFO_API == STD_ON)
# if defined ( STD_TYPES_VENDOR_ID )
#  if ( STD_TYPES_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires datatype 'Std_VersionInfoType' with element 'instanceID' */
#   if (  (STD_TYPES_AR_MAJOR_VERSION == (0x01u)) && (STD_TYPES_AR_MINOR_VERSION == (0x03u)) )  /* Specification 1.3.0        is part of AUTOSAR Release R3.0 */
#   elif ((STD_TYPES_AR_MAJOR_VERSION == (0x01u)) && (STD_TYPES_AR_MINOR_VERSION == (0x02u)) )  /* Specification 1.2.1 [sic!] is part of AUTOSAR Release R3.1 Rev 0001-004 */
/* ATTENTION: Following specification versions are NOT SUPPORTED, as element 'instanceID' is MISSING.
   And yes, the versioning scheme of the spec "AUTOSAR_SWS_StandardTypes.pdf" is hmmm... interesting:
          unsupported: 1.1.1 (R2.1 Rev 0014)
          unsupported: 1.3.0 [sic!] (R3.1 Rev 5  and  R4.0 Rev 1)
*/
#   else
#    error "Dem: Incompatible AUTOSAR version of Std_Types.h."
#   endif
#  endif
# endif
#endif

/* AR3-F1155 - Version check for DET */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
# if defined ( DET_VENDOR_ID )
#   if ( DET_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires API Det_ReportError() */
#   if (  (DET_AR_MAJOR_VERSION == (0x02u)) && (DET_AR_MINOR_VERSION == (0x00u)) )  /* Specification 2.0.x is part of AUTOSAR Release R2.0 */
#   elif ((DET_AR_MAJOR_VERSION == (0x02u)) && (DET_AR_MINOR_VERSION == (0x01u)) )  /* Specification 2.1.x is part of AUTOSAR Release R2.1 */
#   elif ((DET_AR_MAJOR_VERSION == (0x02u)) && (DET_AR_MINOR_VERSION == (0x02u)) )  /* Specification 2.2.x is part of AUTOSAR Release R3.0, R3.1 */
#   else
#    error "Dem: Incompatible AUTOSAR version of Det."
#   endif
#  endif
# endif
#endif

/* AR3-F1155 - Version check for FiM */
#if (DEM_USE_FIM_NOTIFICATION_API == STD_ON)
# if defined ( FIM_VENDOR_ID )
#   if ( FIM_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires API Fim_DemTriggerOnEventStatus() */
#   if (  (FIM_AR_MAJOR_VERSION == (0x01u)) && (FIM_AR_MINOR_VERSION == (0x00u)) )  /* Specification 1.0.x is part of AUTOSAR Release R2.0 */
#   elif ((FIM_AR_MAJOR_VERSION == (0x01u)) && (FIM_AR_MINOR_VERSION == (0x01u)) )  /* Specification 1.1.x is part of AUTOSAR Release R2.1 */
#   elif ((FIM_AR_MAJOR_VERSION == (0x01u)) && (FIM_AR_MINOR_VERSION == (0x02u)) )  /* Specification 1.2.x is part of AUTOSAR Release R3.0 */
#   elif ((FIM_AR_MAJOR_VERSION == (0x01u)) && (FIM_AR_MINOR_VERSION == (0x03u)) )  /* Specification 1.3.x is part of AUTOSAR Release R3.1 */
#   else
#    error "Dem: Incompatible AUTOSAR version of FiM."
#   endif
#  endif
# endif
#endif

/* AR3-F1155 - Version check for NvM */
#if (DEM_USE_NVM == STD_ON)
# if defined ( NVM_VENDOR_ID )
#   if ( NVM_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires API NvM_SetRamBlockStatus() */
#   if (  (NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x01u)) )  /* Specification 2.1.x is part of AUTOSAR Release R2.0, R2.1 */
#   elif ((NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x02u)) )  /* Specification 2.2.x is part of AUTOSAR Release R3.0 Rev 0001-006 */
#   elif ((NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x03u)) )  /* Specification 2.3.x is part of AUTOSAR Release R3.0 Rev 7, R3.1 */
#   else
#    error "Dem: Incompatible AUTOSAR version of NvM."
#   endif
#  endif
# endif
#endif

/* AR3-F1155 - Version check for RTE */
#if (DEM_USE_RTE == STD_ON)
# if defined ( RTE_VENDOR_ID )
#  if ( RTE_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires type definitions from RTE via Rte_Types.h */
#   if (  (RTE_AR_MAJOR_VERSION == (0x02u)) && (RTE_AR_MINOR_VERSION == (0x00u)) )  /* Specification 2.0.x is part of AUTOSAR Release R3.0 */
#   elif ((RTE_AR_MAJOR_VERSION == (0x02u)) && (RTE_AR_MINOR_VERSION == (0x01u)) )  /* Specification 2.1.x is part of AUTOSAR Release R3.0 Rev 0004 */
#   elif ((RTE_AR_MAJOR_VERSION == (0x02u)) && (RTE_AR_MINOR_VERSION == (0x02u)) )  /* Specification 2.2.x is part of AUTOSAR Release R3.0 Rev 0006, R3.1 Rev 0004 */
#   elif ((RTE_AR_MAJOR_VERSION == (0x02u)) && (RTE_AR_MINOR_VERSION == (0x03u)) )  /* Specification 2.3.x is part of AUTOSAR Release R3.0 Rev 7,    R3.1 Rev 5 */
#   elif ((RTE_AR_MAJOR_VERSION == (0x02u)) && (RTE_AR_MINOR_VERSION == (0x04u)) )  /* Nexteer manual edit - assuming 2.4.x is compatible */
#   else
#    error "Dem: Incompatible AUTOSAR version of Rte."
#   endif
#  endif
# endif
#endif


/* Check for correct gentool version */
#if defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
#else
# if (  (DIAG_ASRDEM_GENTOOL_GENY_MAJOR_VERSION != 0x03u) \
     ||((DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION != 0x03u) && (DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION != 0xFFu)) \
     ||((DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION != 0x03u - 1u) && (DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION == 0xFFu)) ) 
  #error "Version check in Dem.c failed! Requires Gentool GENy (Diag_AsrDem.dll) in version 3.03.xx"
# endif
#endif

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/

/* Dem.c needs consistency between CRC check and configuration variant */
#if (( DEM_CRC_CHECK == STD_ON ) && ( DEM_CONFIG_VARIANT == 1 ))
# error "Consistency check in Dem.c failed! CRC check must be switched off for DEM Variant #1 PRE-COMPILE"
#endif

#if defined (V_EXTENDED_BUILD_LIB_CHECK)
# if ( DEM_CONFIG_VARIANT == 1 )
#  error "Consistency check in Dem.c failed! You can not use DEM Variant #1 PRE-COMPILE for building a library."
# endif
#endif

/** There are some buggy compilers, that cannot generate correct code for the statement a = b; if the variables a and b
 *  have complex type, i.e. their type is a structure and no simple data type like unsigned integer.
 *  We use a black list for such compilers, the DEM will implement a workaround for such assignments.
 */
#if ! defined (DEM_COMPILER_BUG__STRUCTCOPY)
# define DEM_COMPILER_BUG__STRUCTCOPY   STD_OFF
#endif


/** This version of this DEM is released for configuration variant LINK-TIME (2) only.
 */
#if ( DEM_CONFIG_VARIANT == 1 )
   /* GENy "Configuration Variant": 'Variant 1 (Pre-compile Configuration)' */
# error "Diag_AsrDem_Vector is NOT released as DEM configuration variant #1 PRE_COMPILE."
#elif ( DEM_CONFIG_VARIANT == 2 )
   /* GENy "Configuration Variant": 'Variant 2 (Link-time Configuration)' */
   /* "Diag_AsrDem_Vector is released as DEM configuration variant #2 LINK-TIME." */
#elif ( DEM_CONFIG_VARIANT == 3 )
   /* GENy "Configuration Variant": 'Variant 3 (Post-build Configuration)' */
# error "Diag_AsrDem_Vector is NOT released as DEM configuration variant #3 POST_BUILD."
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* end-of-table marker for Dem_DIDLookupTable[] */
#define DEM_DIDTABLE_END_OF_TABLE             0xffff


/* padding value for missing data in Xxx_DemGetExtendedDataRecord() or Xxx_DemGetDataValueByDataIdentifier() */
#define DEM_MISSING_DATA_PADDING_VALUE        0xffu

/* actions for the internal ActionQueue that is drained in Dem_MainFunction() */
#define DEM_AQACTION_NONE               0   /* doing nothing */
#define DEM_AQACTION_SETEVENT           1   /* queued: Dem_SetEventStatus() */
#define DEM_AQACTION_REPORTERROR        1   /* queued: Dem_ReportErrorStatus() is same as Dem_SetEventStatus() */
#define DEM_AQACTION_SETOPCYCLE         2   /* queued: Dem_SetOperationCycleState() */
#define DEM_AQACTION_CLEARALLDTC        3   /* queued: Dem_ClearDTC() -> Dem_InitChronoStack() */
#define DEM_AQACTION_CLEARDTCGROUP      4   /* queued: Dem_ClearDTC() -> loop over Dem_ClearSingleEvent() */
#define DEM_AQACTION_CLEARSINGLEEVENT   5   /* queued: Dem_ClearDTC() -> Dem_ClearSingleEvent() */
#define DEM_AQACTION_ENABLESTORAGE      6   /* queued: Dem_EnableDTCStorage() */
#define DEM_AQACTION_RESETWARNINDICATOR 7   /* unused */
#define DEM_AQACTION_RESETEVENTSTATUS   8   /* queued: Dem_ResetEventStatus() */
/* flag for unsuccessful action, used with ClearDTC */
#define DEM_AQACTION_FAILED                 0x80u   /* unsuccessful */ 

/* The status bit ConfirmedDTC may act as 'DTC is stored in PriMem' (STD_ON) or independent from storing (STD_OFF) */
#define DEM_CONFIRMEDDTC_MEANS_STOREDDTC    STD_ON


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/* (value) assemble/deassemble macros */
/* compose from byte stream a 16 bit (value) */
#define Dem_Make16Bit(hiByte, loByte)                         ((uint16)(((uint16)(hiByte)<<8)| \
                                                              ((uint16)(loByte))))                                          /* PRQA S 3453 *//* MD_MSR_19.7 */
/* compose from byte stream a 32 bit (value) */
#define Dem_Make32Bit(hiHiByte, hiLoByte, loHiByte, loLoByte) ((uint32)(((uint32)(hiHiByte)<<24)| \
                                                              ((uint32)(hiLoByte)<<16)| \
                                                              ((uint32)(loHiByte)<<8) | \
                                                              ((uint32)(loLoByte))))                                        /* PRQA S 3453 *//* MD_MSR_19.7 */
/* decompose 16 bit (value) in byte stream */
#define Dem_GetHiByte(value)                                  ((uint8)((uint16)(value)>>8))                                 /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetLoByte(value)                                  ((uint8)((value)))                                            /* PRQA S 3453 *//* MD_MSR_19.7 */

/* decompose 32 bit (value) in byte stream */
#define Dem_GetHiHiByte(value)                                ((uint8)((uint32)(value)>>24))                                /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetHiLoByte(value)                                ((uint8)((uint32)(value)>>16))                                /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetLoHiByte(value)                                ((uint8)((uint32)(value)>>8))                                 /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetLoLoByte(value)                                ((uint8)(value))                                              /* PRQA S 3453 *//* MD_MSR_19.7 */

/* Map the internal/NVRAM-stored event status format to Dem_EventStatusExtendedType. R3.0: one-to-one mapping */
#define Dem_MapStatusByteTypeToExtType(statusByte)            (statusByte)                                                  /* PRQA S 3453 *//* MD_MSR_19.7 */

/* This function is intentionally implemented as MACRO
 * Rationale:
 * With AUTOSAR's MemoryMapping we internally distinguish between different memory areas, that may be
 * later be used either e.g. with flat addressing or (on some hardware) with paged addressing or 
 * with internal RAM, external RAM, ROM, flash, EEPROM, SRAM, global pages, near pages, far pages, ...
 * For different purpose the DEM uses the memory areas: DEM_VAR, DEM_VAR_NOINIT_FAST, DEM_VAR_NOINIT,
 * DEM_PBCFG, DEM_APPL_DATA next to the const areas DEM_CONST, DEM_APPL_CODE next to the code areas
 * DEM_CODE and DEM_APPL_CONST.
 * The mapping of these memory areas to the correct addressing scheme will vary.
 * The MemCopy function has to be implemented once for each combination of copy from area X into area Y!
 * Practically, several nominal different areas X and Y might use in fact identical addressing. But
 * since this is C and not C++ we cannot use TEMPLATEs so we manage it using a MACRO instead.
 */
/* The MACRO does not check for destructive overlapping of the memory areas. It is copying straight
 * forward! Do not use if (srcAddr < tgtAddr) && (tgtAddr < &srcAddr[blockLen]) i.e. srcBuffer is
 * in front of dstBuffer and both buffers will (partly) overlap.
 *
 * Parameters: tgt, src           : memory addresses of destination and source buffer
 *             len                : size of data to copy in byte
 * Due AUTOSAR MemoryMapping is sadly constricted, you must use following code exactly as shown.
 * Especially the variable names "tgtAddr" and "srcAddr" are mandatory :-(
 *
 * Usage with TargetAddress: tgt = '<<targetBuffer>>'      TargetMemClass := '<<DEM_APPL_DATA>>'
 * =====      SourceAddress: src = '<<sourceBuffer>>'      SourceMemClass := '<<DEM_VAR>>'
 *            BlockLength:   len = '<<sizeof(struct x)>>'
    {
      P2VAR(uint8, AUTOMATIC,   <<DEM_APPL_DATA>>)    tgtAddr;
      P2CONST(uint8, AUTOMATIC, <<DEM_VAR>>)          srcAddr;
      DEM_MEMCOPY(<<targetBuffer>>, <<sourceBuffer>>, <<sizeof(struct x)>>);
    }
 */
#define DEM_MEMCOPY(tgt, src, len)                                               \
do                                                                               \
{                                                                                \
  uint16_least  blockLen;                                                        \
  blockLen = (uint16_least) (len);  tgtAddr = (tgt);  srcAddr = (src);           \
  for (; blockLen > 0 ; --blockLen)                                              \
  {                                                                              \
    *tgtAddr = *srcAddr;                                                         \
    tgtAddr = &tgtAddr[1];             /*  MISRA improvement for: tgtAddr++; */  \
    srcAddr = &srcAddr[1];             /*  MISRA improvement for: srcAddr++; */  \
  }                                                                              \
} while(0)

/* Status bit 'testFailed' ------------------------------------------------- */
#define DEM_IS_BIT_UNSET_TEST_FAILED( EventId )                   ((Dem_DtcStatusBytePtr[(EventId)] & (1u << 0)) == 0)            /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_TEST_FAILED( EventId )                     (!DEM_IS_BIT_UNSET_TEST_FAILED(EventId))                        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_TEST_FAILED( EventId )              \
  do {                                                  \
    if (DEM_IS_BIT_UNSET_TEST_FAILED(EventId) != FALSE) \
    {                                                   \
      if (*Dem_FirstFailedEventIdPtr == 0)              \
      { /* not set yet */                               \
        *Dem_FirstFailedEventIdPtr = (EventId);         \
      }                                                 \
      *Dem_MostRecentFailedEventIdPtr = (EventId);      \
    }                                                   \
    Dem_DtcStatusBytePtr[(EventId)] |= (1u << 0);       \
  } while (0)
#define DEM_UNSET_BIT_TEST_FAILED( EventId )                      do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 0)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'testFailedThisOperationCycle' ------------------------------- */
#define DEM_IS_BIT_UNSET_TEST_FAILED_THIS_OC( EventId )           ((Dem_DtcStatusBytePtr[(EventId)] & (1u << 1)) == 0)            /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_TEST_FAILED_THIS_OC( EventId )             (!DEM_IS_BIT_UNSET_TEST_FAILED_THIS_OC(EventId))                /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_TEST_FAILED_THIS_OC( EventId )                do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 1); } while (0)
#define DEM_UNSET_BIT_TEST_FAILED_THIS_OC( EventId )              do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 1)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'pendingDTC' ------------------------------------------------- */
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_ON)
# define DEM_IS_BIT_UNSET_PENDING_DTC( EventId )                  (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 2)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_IS_BIT_SET_PENDING_DTC( EventId )                    (!DEM_IS_BIT_UNSET_PENDING_DTC(EventId))                        /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_SET_BIT_PENDING_DTC( EventId )                       do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 2);  } while (0)
/* copy the testFailedThisOperationCycle bit into the pendingDTC bit */
# define DEM_COPY_BIT_PENDING_DTC( EventId )                  \
  do {                                                        \
    if ((Dem_DtcStatusBytePtr[(EventId)] & (1u << 1)) != 0)   \
    {                                                         \
      DEM_SET_BIT_PENDING_DTC(EventId);                       \
    }                                                         \
    else                                                      \
    {                                                         \
      DEM_UNSET_BIT_PENDING_DTC(EventId);                     \
    }                                                         \
  } while (0)
#endif
#define DEM_UNSET_BIT_PENDING_DTC( EventId )                      do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 2)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'confirmedDTC' ------------------------------------------------- */
#define DEM_IS_BIT_UNSET_CONFIRMED_DTC( EventId )                 (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 3)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_CONFIRMED_DTC( EventId )                   (!DEM_IS_BIT_UNSET_CONFIRMED_DTC(EventId))                      /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_CONFIRMED_DTC( EventId )                                          \
  do {                                                                                \
    if (DEM_IS_BIT_UNSET_CONFIRMED_DTC(EventId) != FALSE)                             \
    {                                                                                 \
      /* Update the global history with FirstConfirmed/MostRecent confirmed event */  \
      if (*Dem_FirstConfirmedEventIdPtr == 0)                                         \
      { /* not set yet */                                                             \
        *Dem_FirstConfirmedEventIdPtr = (EventId);                                    \
      }                                                                               \
      *Dem_MostRecentConfmdEventIdPtr = (EventId);                                    \
    }                                                                                 \
    Dem_DtcStatusBytePtr[(EventId)] |= (1u << 3);                                     \
  } while (0)
#define DEM_UNSET_BIT_CONFIRMED_DTC( EventId )                    do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 3)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'testNotCompletedSinceLastClear' ----------------------------- */
#define DEM_IS_BIT_UNSET_TEST_N_COMPL_SINCE_LC( EventId )         (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 4)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_TEST_N_COMPL_SINCE_LC( EventId )           (!DEM_IS_BIT_UNSET_TEST_N_COMPL_SINCE_LC(EventId))        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_TEST_N_COMPL_SINCE_LC( EventId )              do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 4); } while (0)
#define DEM_UNSET_BIT_TEST_N_COMPL_SINCE_LC( EventId )            do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 4)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'testFailedSinceLastClear' ----------------------------- */
#define DEM_IS_BIT_UNSET_TEST_FAILED_SINCE_LC( EventId )          (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 5)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_TEST_FAILED_SINCE_LC( EventId )            (!DEM_IS_BIT_UNSET_TEST_FAILED_SINCE_LC(EventId))               /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_TEST_FAILED_SINCE_LC( EventId )               do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 5); } while (0)
#define DEM_UNSET_BIT_TEST_FAILED_SINCE_LC( EventId )             do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 5)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'testNotCompletedThisOperationCycle' ------------------------- */
#define DEM_IS_BIT_UNSET_TEST_N_COMPL_THIS_OC( EventId )          (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 6)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_BIT_SET_TEST_N_COMPL_THIS_OC( EventId )            (!DEM_IS_BIT_UNSET_TEST_N_COMPL_THIS_OC(EventId))         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_BIT_TEST_N_COMPL_THIS_OC( EventId )               do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 6); } while (0)
#define DEM_UNSET_BIT_TEST_N_COMPL_THIS_OC( EventId )             do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 6)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* Status bit 'warningIndicatorRequested' ------------------------- */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
# define DEM_IS_BIT_UNSET_WARNING_INDICATOR_REQ( EventId )        (((Dem_DtcStatusBytePtr[(EventId)] & (1u << 7)) == 0))          /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_IS_BIT_SET_WARNING_INDICATOR_REQ( EventId )          (!DEM_IS_BIT_UNSET_WARNING_INDICATOR_REQ(EventId))              /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_SET_BIT_WARNING_INDICATOR_REQ( EventId )             do { Dem_DtcStatusBytePtr[(EventId)] |= (1u << 7); } while (0)
# define DEM_UNSET_BIT_WARNING_INDICATOR_REQ( EventId )           do { Dem_DtcStatusBytePtr[(EventId)] &= (Dem_DtcStatusByteType)(~((Dem_DtcStatusByteType)1u << 7)); } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif



/* Additional Status bits, used internal, never stored to NVRAM */

#define DEM_IS_UNSET_FILTERED_DTC( EventId )                      (((Dem_DtcInternalStatus[(EventId)] & (1u << 0)) == 0))         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_SET_FILTERED_DTC( EventId )                        (!DEM_IS_UNSET_FILTERED_DTC(EventId))                           /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_FILTERED_DTC( EventId )                           do { Dem_DtcInternalStatus[(EventId)] |= (1u << 0); } while (0)
#define DEM_UNSET_FILTERED_DTC( EventId )                         do { Dem_DtcInternalStatus[(EventId)] &= (Dem_DtcInternalStatusType)(~((Dem_DtcInternalStatusType)1u << 0)); } while (0)    /* PRQA S 0277 *//* MD_DEM_3.1_0277 */


#define DEM_IS_UNSET_PRESTORED_EVENT( EventId )                   (((Dem_DtcInternalStatus[(EventId)] & (1u << 1)) == 0))         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_IS_SET_PRESTORED_EVENT( EventId )                     (!DEM_IS_UNSET_PRESTORED_EVENT(EventId))                        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define DEM_SET_PRESTORED_EVENT( EventId )                        do { Dem_DtcInternalStatus[(EventId)] |= (1u << 1); } while (0)
#define DEM_UNSET_PRESTORED_EVENT( EventId )                      do { Dem_DtcInternalStatus[(EventId)] &= (Dem_DtcInternalStatusType)(~((Dem_DtcInternalStatusType)1u << 1)); } while (0)    /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

/* (internal) additional Status bits */
#if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
# define DEM_IS_UNSET_STORED_DTC( EventId )                       (((Dem_DtcInternalStatus[(EventId)] & (1u << 2)) == 0))         /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_IS_SET_STORED_DTC( EventId )                         (!DEM_IS_UNSET_STORED_DTC(EventId))                             /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_SET_STORED_DTC( EventId )                            do { Dem_DtcInternalStatus[(EventId)] |= (1u << 2); } while (0)
# define DEM_UNSET_STORED_DTC( EventId )                          do { Dem_DtcInternalStatus[(EventId)] &= (Dem_DtcInternalStatusType)(~((Dem_DtcInternalStatusType)1u << 2));  } while (0)   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#else
# define DEM_IS_UNSET_STORED_DTC( EventId )                       (DEM_IS_BIT_UNSET_CONFIRMED_DTC(EventId))                       /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_IS_SET_STORED_DTC( EventId )                         (!DEM_IS_UNSET_STORED_DTC(EventId))                             /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_SET_STORED_DTC( EventId )                            DEM_SET_BIT_CONFIRMED_DTC(EventId)                              /* PRQA S 3453 *//* MD_MSR_19.7 */
# define DEM_UNSET_STORED_DTC( EventId )                          DEM_UNSET_BIT_CONFIRMED_DTC(EventId)                            /* PRQA S 3453 *//* MD_MSR_19.7 */
#endif


#define Dem_SetBitInArray(i, arr)                       do { (arr)[(i)>>3] |= (uint8)  (1u << ((i)&7) ); } while (0)              /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_ClearBitInArray(i, arr)                     do { (arr)[(i)>>3] &= (uint8) (~(1u << ((i)&7) )); } while (0)            /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetBitInArray(i, arr)                       ((arr)[(i)>>3] & ( (uint8)  (1u << ((i)&7) )) )                           /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_IsBitSetInArray(i, arr)                     (Dem_GetBitInArray((i), (arr)) != ((uint8)0u))                            /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_IsBitClearedInArray(i, arr)                 (Dem_GetBitInArray((i), (arr)) == ((uint8)0u))                            /* PRQA S 3453 *//* MD_MSR_19.7 */




/* access EventIDs via Chrono Manager */
#define Dem_GetEventIdOfEntry(csIndex)                  (Dem_ChronoPriMemPtr[(csIndex)].dtcInternalNumber)                        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_GetPriMemIndexFromChronoIndex(csIndex)      (Dem_ChronoPriMemPtr[(csIndex)].ref)                                      /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_SetEventIdOfEntry( csIndex, eventId )       do { Dem_ChronoPriMemPtr[(csIndex)].dtcInternalNumber = (eventId); } while (0)  /* PRQA S 3453 *//* MD_MSR_19.7 */

/* direct access to Primary Memory buffer */
#define Dem_GetPrimaryStackBufferPtr(eventEntry)        (&Dem_PrimaryStackPtr[(eventEntry)*Dem_PriMemElementSize])                /* PRQA S 3453 *//* MD_MSR_19.7 */

/* offsets in each primary stack element for specific data */
#define Dem_PriMemExtendedRecordOffset()                0
#define Dem_PriMemSnapshotUsedCntOffset()               (Dem_PriMemExtendedRecordOffset()+DemCfg_GetMaxExtdataRecordSize())
#define Dem_PriMemSnapshotRecordsOffset()               (Dem_PriMemSnapshotUsedCntOffset()+1)
#define Dem_PriMemSnapshotNthRecordOffset(n)            (Dem_PriMemSnapshotRecordsOffset()+( (n) * DemCfg_GetMaxSnapshotRecordSize())) /* n := 0...DemCfg_GetCountOfSnapshotsPerDTC()-1 */      /* PRQA S 3453 *//* MD_MSR_19.7 */
/* offset for most recent record; here: first over-writable snapshot as there are several 'most recent' records */
#define Dem_PriMemSnapshot1stRecentOffset()             (Dem_PriMemSnapshotNthRecordOffset(DemCfg_Get1stOverwrtSnapshotIndex()))




#define Dem_AQSizeof() (Dem_ActionQueueCount)                       /* max. number of elements, that may be stored in Dem_ActionQueue[] */
#define Dem_AQUsed()   (Dem_ActionQueueUsed)                        /* (readonly) number of currently used elements */

/* Dem_AQElementType elem; elemPtr = &elem; */
#define Dem_AQSetAction(elemPtr, act)             ((elemPtr)->Action = (act))                                                     /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetAction(elemPtr)                  ((elemPtr)->Action)                                                             /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetEventStatus(elemPtr, stat)       ((elemPtr)->arg.event.Status = (stat))                                          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetEventStatus(elemPtr)             ((elemPtr)->arg.event.Status)                                                   /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetEventId(elemPtr, id)             ((elemPtr)->arg.event.EventIdentifier = (id))                                   /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetEventId(elemPtr)                 ((elemPtr)->arg.event.EventIdentifier)                                          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetOpCycleState(elemPtr, stat)      ((elemPtr)->arg.opcycle.CycleState = (stat))                                    /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetOpCycleState(elemPtr)            ((elemPtr)->arg.opcycle.CycleState)                                             /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetOpCycleId(elemPtr, id)           ((elemPtr)->arg.opcycle.CycleId = (id))                                         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetOpCycleId(elemPtr)               ((elemPtr)->arg.opcycle.CycleId)                                                /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetBitcodedDTCGroup(elemPtr, grp)   ((elemPtr)->arg.dtc.BitcodedDtcGroup = (grp))                                   /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetBitcodedDTCGroup(elemPtr)        ((elemPtr)->arg.dtc.BitcodedDtcGroup)                                           /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetDTCKind(elemPtr, kind)           ((elemPtr)->arg.dtc.DTCKind = (kind))                                           /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetDTCKind(elemPtr)                 ((elemPtr)->arg.dtc.DTCKind)                                                    /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQSetDTCOrigin(elemPtr, orig)         ((elemPtr)->arg.dtc.DTCOrigin = (orig))                                         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Dem_AQGetDTCOrigin(elemPtr)               ((elemPtr)->arg.dtc.DTCOrigin)                                                  /* PRQA S 3453 *//* MD_MSR_19.7 */


#if ( DEM_COMPILER_BUG__STRUCTCOPY == STD_ON )
#define Dem_AQCopy(dst, src)                                          \
  (dst).arg.event.EventIdentifier = (src).arg.event.EventIdentifier;  \
  (dst).arg.event.Status          = (src).arg.event.Status;           \
  (dst).arg.opcycle.CycleId       = (src).arg.opcycle.CycleId;        \
  (dst).arg.opcycle.CycleState    = (src).arg.opcycle.CycleState;     \
  (dst).arg.dtc.BitcodedDtcGroup  = (src).arg.dtc.BitcodedDtcGroup;   \
  (dst).arg.dtc.DTCKind           = (src).arg.dtc.DTCKind;            \
  (dst).arg.dtc.DTCOrigin         = (src).arg.dtc.DTCOrigin;          \
  (dst).Action                    = (src).Action                                                                                  /* PRQA S 3453 *//* MD_MSR_19.7 */
#else
#define Dem_AQCopy(dst, src)    ((dst) = (src))                                                                                   /* PRQA S 3453 *//* MD_MSR_19.7 */
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define DEM_START_SEC_CODE 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */

STATIC FUNC(Dem_DtcChronoRefType, DEM_CODE) Dem_GetChronoManagerIndex( Dem_EventIdType EventId );                         /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Dem_DtcChronoRefType, DEM_CODE) Dem_GetPriMemStackIndex( Dem_EventIdType EventId );                           /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_MemMove( P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA) tgtAddr, P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA) srcAddr, uint16 blockLen );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(boolean, DEM_CODE) Dem_IsEqualDtcStatusByte( P2CONST(Dem_DtcStatusByteType, AUTOMATIC, AUTOMATIC) first, CONSTP2CONST(Dem_DtcStatusByteType, AUTOMATIC, DEM_APPL_DATA) second );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_InitChronoStack( boolean notifyApplication );                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_AddNewDTCtoChronoStack( Dem_EventIdType EventId );                              /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateUserdataRecord_First( Dem_EventIdType EventId, Dem_DtcChronoRefType stackElementRef );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(uint8, DEM_CODE) Dem_GetMostRecentSnapshotIndex( Dem_DtcChronoRefType stackElementRef, P2VAR(boolean, AUTOMATIC, AUTOMATIC) isUnused );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateUserdataRecord_Recent( Dem_EventIdType EventId, Dem_DtcChronoRefType stackElementRef );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateSnapshotRecord( Dem_EventIdType EventId, P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) BufferPtr );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateExtendedRecord( Dem_EventIdType EventId, P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) BufferPtr, uint8 UpdateMode );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateUserdataRecord( Dem_EventIdType EventId, Dem_DtcChronoRefType stackElementRef, uint8 SnapshotRecordNumber, uint8 UpdateMode );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_UpdateDTCinPriM_NotAct2Act( Dem_EventIdType EventId );                                    /* PRQA S 0850 *//* MD_MSR_19.8 */

STATIC FUNC(void, DEM_CODE) Dem_DeleteDTCinChronoStack( Dem_DtcChronoRefType chronoIndex );                               /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Dem_DTCStatusMaskType, DEM_CODE) Dem_MapStatusByteTypeToMaskType( const Dem_DtcStatusByteType internalStatus );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoResetEventStatus( Dem_EventIdType EventId );                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoSetOperationCycleState( Dem_OperationCycleIdType CycleId, Dem_OperationCycleStateType CycleState );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoSetEventStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus );   /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(sint8, DEM_CODE) Dem_CalcNewFaultDetectionCntr( Dem_EventIdType EventId, P2VAR(Dem_EventStatusType, AUTOMATIC, AUTOMATIC) EventStatus );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoEnableDTCStorage( Dem_DTCGroupKindType BitcodedDTCGroup, Dem_DTCKindType DTCKind );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_GetOffsetSnapshotRecordDID( Dem_EventIdType EventId, uint8 RecordNumber, uint16 DID, P2VAR(uint16, AUTOMATIC, AUTOMATIC) offset, P2VAR(Dem_DataRecordSizeType, AUTOMATIC, AUTOMATIC) size );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_GetOffsetSnapshotRecordNth( Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Iterator, P2VAR(uint16, AUTOMATIC, AUTOMATIC) did, P2VAR(Dem_DataRecordSizeType, AUTOMATIC, AUTOMATIC) size );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_ClearSingleEvent( Dem_EventIdType EventId );                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoClearSingleEvent( Dem_EventIdType EventId );                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_DoClearGroupOfEvents( Dem_DTCGroupKindType BitcodedDTCGroup, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin );  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(Dem_EventIdType, DEM_CODE) Dem_GetEventIdOfDTC( Dem_DTCType Dtc, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin );  /* PRQA S 0850 *//* MD_MSR_19.8 */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(boolean, DEM_CODE) Dem_IsSupportedDtcOrigin( Dem_DTCOriginType DTCOrigin );                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
#endif
STATIC FUNC(boolean, DEM_CODE) Dem_IsValidSsRecordNumber( uint8 RecordNumber );                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(boolean, DEM_CODE) Dem_CheckUsedSsRecordNumber( uint8 RecordNumber, Dem_DtcChronoRefType priMemIndex );       /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_TriggerOnEvent( Dem_EventIdType EventId, Dem_DtcStatusByteType OldStatusByte );           /* PRQA S 0850 *//* MD_MSR_19.8 */

/* for ringbuffers: map relative index into absolute index of a ringbuffer-array */
STATIC FUNC(uint16_least, DEM_CODE) Dem_RingbufIndexRelToAbs( uint16_least rbRelIndex, uint16_least rbFirst, uint16_least rbSize );  /* PRQA S 0850 *//* MD_MSR_19.8 */

STATIC FUNC(boolean, DEM_CODE) Dem_AQPush( P2CONST(Dem_AQElementType, AUTOMATIC, AUTOMATIC) newElement );                 /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(boolean, DEM_CODE) Dem_AQIsQueued(P2CONST(Dem_AQElementType, AUTOMATIC, AUTOMATIC) newElement);               /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_AQPop( P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC) oldestElement );                    /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC), DEM_CODE) Dem_AQPeek( uint16 relIndex );                      /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC), DEM_CODE) Dem_AQPeekAbs(uint16 absIndex);                     /* PRQA S 0850 *//* MD_MSR_19.8 */

#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
STATIC FUNC(void, DEM_CODE) Dem_HandleTimeBasedDebounceEvents( void );                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_CalcNewDebounceTimerSlotValue( Dem_EventIdType EventId, P2CONST(Dem_EventStatusType, AUTOMATIC, AUTOMATIC) EventStatus ); /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC FUNC(void, DEM_CODE) Dem_ClearDebounceTimerSlot( Dem_EventIdType EventId );                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
#endif

#define DEM_STOP_SEC_CODE 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *   RAM definitions
 */

/*----- never initialized vars with high number of accesses */

#define DEM_START_SEC_VAR_FAST_8BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 

STATIC VAR(Dem_DTCGroupKindType, DEM_VAR_NOINIT_FAST) Dem_StorageState; /* Bit coded for all DTCGroupType: 1<<DTCGroup := permit event memory update, see Dem_DisableDTCStorage() */  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC VAR(Dem_DTCGroupKindType, DEM_VAR_NOINIT_FAST) Dem_StatusUpdate; /* Bit coded for all DTCGroupType: 1<<DTCGroup := permit API Dem_(Re)SetEventStatus, see Dem_DisableEventStatusUpdate() */  /* PRQA S 0850 *//* MD_MSR_19.8 */
#define DEM_FORBID_EXISTENT_RECORD_UPDATE   0x00
#define DEM_PERMIT_EXISTENT_RECORD_UPDATE   0xff
STATIC VAR(uint8, DEM_VAR_NOINIT_FAST) Dem_RecordUpdate; /* !0 := permit _changing_ existent DTCs/data records, see Dem_DisableDTCRecordUpdate() */  /* PRQA S 0850 *//* MD_MSR_19.8 */

#define DEM_IsUninitialized                 0     /* state before and after Dem_PreInit() - MainFunction not permitted */
#define DEM_IsDisabled                      1     /* state after Shutdown - MainFunction becomes NOP, ReportErrorStatus writes to BSW queue */
#define DEM_IsEnabled                       2     /* all APIs enabled, but BSW queue still awaits the processing in Dem_MainFunction */
#define DEM_IsEnabledAndRunning             3     /* all APIs enabled */

/* Cache for function Dem_GetEventIdOfDTC(): variables Dem_CvtDtc2EventIdCacheX;  with X=={Dtc,DTCKind,DTCOrigin,EventId} */
STATIC VAR(Dem_DTCKindType,   DEM_VAR_NOINIT_FAST) Dem_CvtDtc2EventIdCacheDTCKind;    /* buffered arg of Dem_GetEventIdOfDTC( ) */  /* PRQA S 0850, 3218 *//* MD_MSR_19.8, MD_DEM_8.7 */
STATIC VAR(Dem_DTCOriginType, DEM_VAR_NOINIT_FAST) Dem_CvtDtc2EventIdCacheDTCOrigin;  /* buffered arg of Dem_GetEventIdOfDTC( ) */  /* PRQA S 0850, 3218 *//* MD_MSR_19.8, MD_DEM_8.7 */
#if (DEM_MAX_NUMBER_OF_EVENTS <= 255)
STATIC VAR(Dem_EventIdType,   DEM_VAR_NOINIT_FAST) Dem_CvtDtc2EventIdCacheEventId;    /* buffered result of Dem_GetEventIdOfDTC( ) for uint8 EventId */  /* PRQA S 0850, 3218 *//* MD_MSR_19.8, MD_DEM_8.7 */
#endif

#define DEM_STOP_SEC_VAR_FAST_8BIT 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


#define DEM_START_SEC_VAR_FAST_16BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 
STATIC volatile VAR(uint16, DEM_VAR_NOINIT_FAST) Dem_ActionQueueUsed;     /* number of used elements in Dem_ActionQueue[] (used as BSW error buffer) */  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC volatile VAR(uint16, DEM_VAR_NOINIT_FAST) Dem_ActionQueueRbFirst;  /* first used element in Dem_ActionQueue[] (ringbuffer implementation) */  /* PRQA S 0850 *//* MD_MSR_19.8 */
#if (DEM_MAX_NUMBER_OF_EVENTS <= 255)
#else
STATIC VAR(Dem_EventIdType,   DEM_VAR_NOINIT_FAST) Dem_CvtDtc2EventIdCacheEventId;    /* buffered result of Dem_GetEventIdOfDTC( ) for uint16 EventId */  /* PRQA S 0850, 3218 *//* MD_MSR_19.8, MD_DEM_8.7 */
#endif
#define DEM_STOP_SEC_VAR_FAST_16BIT 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


#define DEM_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 
STATIC VAR(Dem_DTCType,       DEM_VAR_NOINIT_FAST) Dem_CvtDtc2EventIdCacheDtc;        /* buffered arg of Dem_GetEventIdOfDTC( ) */  /* PRQA S 0850, 3218 *//* MD_MSR_19.8, MD_DEM_8.7 */
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
VAR(uint32, DEM_VAR_NOINIT_FAST)                   Dem_ActiveVariant;  /* PRQA S 0850 *//* MD_MSR_19.8 */
# endif  /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
#define DEM_STOP_SEC_VAR_FAST_32BIT 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 

/*----- vars initialized by startup code */
/**
 * If your startup code doesn't support initialized variables, call Dem_InitMemory() instead as very first Dem API call
 */

#define DEM_START_SEC_VAR_8BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 
STATIC VAR(uint8, DEM_VAR)  Dem_InitializationStatus = DEM_IsUninitialized;                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON)
/* this flag violates the Vector coding convention and is a waste of RAM - implement by order of tne, 20090626 */
STATIC VAR(uint8, DEM_VAR)  Dem_VariantInitialized = DEM_IsUninitialized;                                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
#endif  /* DEM_SUPPORT_VARIANT_HANDLING */
#define DEM_STOP_SEC_VAR_8BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 

/*----- never initialized vars */

#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 

STATIC VAR(uint8, DEM_VAR_NOINIT)  Dem_NextFilteredSequence;                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
#define DEM_NextFilteredSeq_CHRONOLOGICAL   0x00
#define DEM_NextFilteredSeq_BYEVENTID       0x01
STATIC VAR(uint8, DEM_VAR_NOINIT)  Dem_NextFilteredSSRecordIdx;                                                           /* PRQA S 0850 *//* MD_MSR_19.8 */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 
STATIC VAR(uint16, DEM_VAR_NOINIT)  Dem_CountOfFilteredDTCs;                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */

/* Store data of completed Dem_ClearDTC() request, to handle the pending state towards the DCM
 * and distinguish between acknowledging a finished clear and accepting new clear request. */
STATIC VAR(Dem_AQElementType, DEM_VAR_NOINIT) Dem_FinishedClearDtcRequest;                                                /* PRQA S 0850 *//* MD_MSR_19.8 */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */


/**********************************************************************************************************************
 *   ROM definitions
 */

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */
STATIC CONST(uint8, DEM_CONST)  originalPattern[DEM_NVDATA_PATTERN_SIZE] = {0x9Au, 0xBDu, 0xA0u, 0xF3u};                  /* PRQA S 0850 *//* MD_MSR_19.8 */
STATIC CONST(uint8, DEM_CONST)  originalEndPattern[DEM_NVDATA_PATTERN_SIZE] = {DEM_SW_MAJOR_VERSION, DEM_SW_MINOR_VERSION, DIAG_ASRDEM__CORE_VERSION >> 8u, DIAG_ASRDEM__CORE_VERSION & 0x00FFu};  /* PRQA S 0850 *//* MD_MSR_19.8 */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 

/* Check is not required for PRE-COMPILE variant */
#if (DEM_CONFIG_VARIANT != 1)

/* Symbols for link-time version consistency checks, see Dem_Lcfg.c.
 * These variables show the version, OFFERED by THIS FILE (Dem.c or the created lib Dem.lib) !!
 * If Dem_Lcfg.c uses a different version, the linker fails with message similar to:
 *    Dem_Lcfg.obj : error LNK2001: unresolved external symbol _Dem_NeedDemLibVersion_SW_02_14_xx
 */
# define DEM_START_SEC_CONST_8BIT
# include "MemMap.h"                                                                                                      /* PRQA S 5087 *//* MD_MSR_19.1 */  
CONST(uint8, DEM_CONST)  Dem_NeedDemLibVersion_SW_02_14_xx = 0;                                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
CONST(uint8, DEM_CONST)  Dem_NeedDemLibOem_DEM_Vector = 0;                                                                /* PRQA S 0850 *//* MD_MSR_19.8 */
# define DEM_STOP_SEC_CONST_8BIT
# include "MemMap.h"                                                                                                      /* PRQA S 5087 *//* MD_MSR_19.1 */  


# if defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
# else
/* The name of this const variable is defined via v_ver.h and depends on the version of the C file.
 * The value of the const variable is also defined externally and is used for consistency checks, too.
 */
#  define DEM_START_SEC_CONST_32BIT
#  include "MemMap.h"                                                                                                     /* PRQA S 5087 *//* MD_MSR_19.1 */  
CONST( uint32, DEM_CONST ) DIAG_ASRDEM_VECTOR_LIB_SYMBOL = DIAG_ASRDEM_VECTOR_LIB_VERSION;                                /* PRQA S 3408, 0850 *//* MD_DEM_8.8_3408, MD_MSR_19.8 */
#  define DEM_STOP_SEC_CONST_32BIT
#  include "MemMap.h"                                                                                                     /* PRQA S 5087 *//* MD_MSR_19.1 */  
# endif  /* ! V_SUPPRESS_EXTENDED_VERSION_CHECK */
#endif  /* DEM_CONFIG_VARIANT != 1 */


/**********************************************************************************************************************
 *  FUNCTION IMPLEMENTATION
 *********************************************************************************************************************/
/* PRQA S 4700 EOF *//* MD_DEM_4700 */
#define DEM_START_SEC_CODE 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


/**********************************************************************************************************************
  Dem_ClientRunnable
**********************************************************************************************************************/
/** Required context for client ports.
 *  This function is a workaround for RTE where BSW need a runnable entity in ASR 3.0 (and former editions)
 * \note        CALLED BY    RTE
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClientRunnable(
  void
  )
{
}


/**********************************************************************************************************************
  Dem_GetChronoManagerIndex
**********************************************************************************************************************/
/** Scan for a certain internal DTC number and return its position (index) in the manager stack.
 * \return      Return index or *Dem_ChronoPriMemUsedPtr if not found.
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetPriMemStackIndex()
 *                                    Dem_UpdateDTCinPriM_NotAct2Act()
 *                                    Dem_ClearSingleEvent()
 * \param[in]   EventId  internal DTC number
 *********************************************************************************************************************/
STATIC FUNC(Dem_DtcChronoRefType, DEM_CODE)                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetChronoManagerIndex(
  Dem_EventIdType   EventId
  )
{
  Dem_DtcChronoRefType iter = 0;

  while ( (iter < *Dem_ChronoPriMemUsedPtr)
     && (Dem_ChronoPriMemPtr[iter].dtcInternalNumber != EventId))
  {
    ++iter;
  }
  /* if not found return *Dem_ChronoPriMemUsedPtr */
  return iter;
}


/**********************************************************************************************************************
  Dem_GetPriMemStackIndex
**********************************************************************************************************************/
/** Scan for a certain internal DTC number and return its position (index) in the chrono stack (PrimaryMemory).
 * \return      Return index or DemCfg_GetMaxCountOfPriMemStack() if not found.
 * \note        CALLED BY    Internal from function
 *                                    Dem_SetDTCFilterForRecords()
 *                                    Dem_GetNextFilteredRecord()
 *                                    Dem_DoSetEventStatus()
 *                                    Dem_GetFreezeFrameDataIdentifierByDTC()
 *                                    Dem_GetFreezeFrameDataByDTC()
 *                                    Dem_GetSizeOfFreezeFrame()
 *                                    Dem_GetExtendedDataRecordByDTC()
 *                                    Dem_GetSizeOfExtendedDataRecordByDTC()
 * \param[in]   EventId  internal DTC number
 * \pre         Use inside critical section, only. Or assure data consistency by other means.
 * \post        Leave function inside critical section.
 *********************************************************************************************************************/
STATIC FUNC(Dem_DtcChronoRefType, DEM_CODE)                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetPriMemStackIndex(
  Dem_EventIdType   EventId
  )
{
  Dem_DtcChronoRefType index = Dem_GetChronoManagerIndex(EventId);

  if (index < *Dem_ChronoPriMemUsedPtr)
  { /* event found in chrono manager, get index into primary memory stack */
    index = Dem_GetPriMemIndexFromChronoIndex(index);
  }
  else
  { /* event not found, return max. primary memory stack size: DemCfg_GetMaxCountOfPriMemStack() */
    index = DemCfg_GetMaxCountOfPriMemStack();
  }
  return index;
}


/**********************************************************************************************************************
  Dem_SetDTCFilter
**********************************************************************************************************************/
/** Set filter mask over DTCs for Dem_GetNextFilteredDTC()
 * \return      Dem_CountOfFilteredDTCs contains the number of DTCs in the Chrono/Historical Stack and is used
 *              as element count for reporting.
 * \return      Status of the operation of type Dem_ReturnSetDTCFilterType
 * \note        SERVICE ID   0x13
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1901 1907 1911 1912, 0x1902 190A 190F 1913 1915, 0x1908, 0x1914
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCStatusMask                   According ISO14229-1 StatusOfDTC.
 *                                              Values: 0x00: Report all supported DTCs
 *                                                      0x01...0xFF: Match DTCStatusMask as defined in ISO14229-1
 * \param[in]   DTCKind                         Defines the functional group of DTCs to be reported (e.g. all DTC,
 *                                              OBD-relevant DTC)
 * \param[in]   DTCOrigin                       If the DEM supports more than one event memory this parameter is
 *                                              used to select the source memory the DTCs shall be read from.
 * \param[in]   FilterWithSeverity              This flag defines whether severity information (ref. to parameter
 *                                              below) shall be used for filtering.
 * \param[in]   DTCSeverity                     This parameter contains the DTCSeverityMask according to ISO14229-1.
 * \param[in]   FilterForFaultDetectionCounter  This flag defines whether Fault Detection Counter information shall
 *                                              be used for filtering.
 * \retval      DEM_FILTER_ACCEPTED   Filter was accepted
 * \retval      DEM_WRONG_FILTER      Wrong filter selected
 * Handling of the severity mask 'DTCSeverity':
 * ISO14229-1 defines the 3 most significant bits as severity bits and advices to set the remaining 5 bits to 0.
 * When called with FilterWithSeverity=YES, this function operates as follows (m=severity mask bit, u=unused bit;
 * '0'/'1'=bit has exact value 0 or 1, '.'=don't care=value ignored, 'sss'=requested severity value)
 * - mmmuuuuu == requested DTCSeverity, result is the best match of following patterns:
 * - 00000000 => DEM_FILTER_ACCEPTED, always 0 filtered events
 * - 000..... => DEM_WRONG_FILTER
 * - sss..... => DEM_FILTER_ACCEPTED, '.' bits are simply ignored, count all events which match any of the 'sss' bits
 *********************************************************************************************************************/
FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE)                                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetDTCFilter(
  Dem_DTCStatusMaskType                   DTCStatusMask,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  Dem_FilterWithSeverityType              FilterWithSeverity,
  Dem_DTCSeverityType                     DTCSeverity,
  Dem_FilterForFaultDetectionCounterType  FilterForFaultDetectionCounter
  )
{
  Dem_ReturnSetDTCFilterType returnValue = DEM_WRONG_FILTER;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;
    Dem_DTCStatusMaskType lDTCStatusMask;
    uint16 numberOfRecords = 0;

    Dem_NextFilteredSSRecordIdx = 0;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
    /* check for valid arguments */
    if ( ((DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY) || (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY) || (DTCOrigin == DEM_DTC_ORIGIN_PERMANENT) || (DTCOrigin == DEM_DTC_ORIGIN_SECONDARY_MEMORY))
      && ((FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_YES) || (FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_NO))
      && ((DTCSeverity == DEM_SEVERITY_NO_SEVERITY) || ((DTCSeverity & ((DEM_SEVERITY_MAINTENANCE_ONLY) | (DEM_SEVERITY_CHECK_AT_NEXT_HALT) | (DEM_SEVERITY_CHECK_IMMEDIATELY))) != 0))
      && ((FilterForFaultDetectionCounter == DEM_FILTER_FOR_FDC_YES) || (FilterForFaultDetectionCounter == DEM_FILTER_FOR_FDC_NO))
      && ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS))
      )
#endif  /* DEM_DEV_ERROR_DETECT */
    {
      /* Each Filter with valid arguments is accepted (but might result in zero records) */
      returnValue = DEM_FILTER_ACCEPTED;

      /*
      Dem 062: The chronological order shall be reported if the DTC status mask parameter is set to
      'pending' and/or 'confirmed' (no other status bits are allowed to be set). The
      function shall start with the most recent DTC.
      */
      if ((DTCStatusMask == 0x04)   /* pendingDTC */
        ||(DTCStatusMask == 0x08)   /* confirmedDTC */
        ||(DTCStatusMask == 0x0C))  /* pendingDTC+confirmedDTC */
      {
        Dem_NextFilteredSequence = DEM_NextFilteredSeq_CHRONOLOGICAL;
      }
      else
      {
        Dem_NextFilteredSequence = DEM_NextFilteredSeq_BYEVENTID;
      }

      (void) Dem_GetDTCStatusAvailabilityMask(&lDTCStatusMask);
      lDTCStatusMask &= DTCStatusMask;
    
      /*
      With external FaultDetectionCounter(s) we might use a callback here - this forbids critical section here.
      Dem_(Un)setBitFilteredDTC is a write access, but needs not be protected against concurrent access.
      */

      /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
      for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
      {
        if ((((1u<<DTCOrigin) & DemCfg_GetDTCOrigin(EventId)) != 0)                               /* PRQA S 3415 *//* MD_DEM_12.4 */
          && (DTCKind == DemCfg_GetDTCKind(EventId))                                              /* PRQA S 3415 *//* MD_DEM_12.4 */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
          && (Dem_IsInActiveVariant(EventId))
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
          )
        {
          if (((lDTCStatusMask & Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId])) != 0)
            || (DTCStatusMask == 0))
          {
            if ( (FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_NO) ||
                ((FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_YES) && ((DTCSeverity & DemCfg_GetDTCSeverity(EventId)) != 0))           /* check is not redundant */ /* PRQA S 3355 *//* MD_DEM_13.7 */
               )
            {
              if ( (FilterForFaultDetectionCounter == DEM_FILTER_FOR_FDC_NO) ||
                  ((FilterForFaultDetectionCounter == DEM_FILTER_FOR_FDC_YES)                                                             /* check is not redundant */ /* PRQA S 3355 *//* MD_DEM_13.7 */
                    && (Dem_FaultDetectionCounterPtr[EventId] >= 1)
                    && (Dem_FaultDetectionCounterPtr[EventId] <= 0x7e)
                  )
                 )
              {
                DEM_SET_FILTERED_DTC(EventId);                                                    /* PRQA S 0715 NONCONFORMING *//* MD_DEM_1.1_0715 */
                ++numberOfRecords;
              }
              else
              {
                DEM_UNSET_FILTERED_DTC(EventId);                                                  /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
              }                                                                                   /* PRQA L:NONCONFORMING */
            }
            else
            {
              DEM_UNSET_FILTERED_DTC(EventId);                                                    /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
            }
          }
          else
          {
            DEM_UNSET_FILTERED_DTC(EventId);                                                      /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          }
        }
        else
        {
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
        }
      }
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* invalid argument(s) */
      Dem_DetReportError(DEM_SETDTCFILTER_APIID, DEM_E_PARAM_CONFIG);
    }
#endif

    /* internal preserve the record count, see Dem_GetNumberOfFilteredDTC() */
    Dem_CountOfFilteredDTCs = numberOfRecords;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_SETDTCFILTER_APIID, DEM_E_UNINIT);
  }
#endif
  /* invalid arguments - DEM_WRONG_FILTER already set */
  return returnValue;
}


/**********************************************************************************************************************
  Dem_SetDTCFilterForRecords
**********************************************************************************************************************/
/** Set Filter for all snapshot records currently stored in the primary event memory
 *  The filtered snapshot records can be retrieved by the function Dem_GetNextFilteredRecord().
 *  This filter always belongs to primary memory.
 * \return      Status of the operation of type Dem_ReturnSetDTCFilterType
 * \note        SERVICE ID   0x3f
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1903
 * \note        AUTOSAR R3.0 API
 * \param[out]  NumberOfFilteredRecords  Number of snapshot records currently stored in the event memory.
 * \retval      DEM_FILTER_ACCEPTED   Filter was accepted
 * \retval      DEM_WRONG_FILTER      Wrong filter selected
 *********************************************************************************************************************/
FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE)                                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetDTCFilterForRecords(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredRecords                                /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnSetDTCFilterType returnValue = DEM_WRONG_FILTER;
  Dem_EventIdType EventId;
  uint16 numberOfRecords = 0;

  Dem_NextFilteredSequence = DEM_NextFilteredSeq_CHRONOLOGICAL;
  Dem_NextFilteredSSRecordIdx = 0;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (NumberOfFilteredRecords == NULL_PTR)
  {
    Dem_DetReportError(DEM_SETDTCFILTERFORRECORDS_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    returnValue = DEM_FILTER_ACCEPTED;
    /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
    for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
    {
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (! (Dem_IsInActiveVariant(EventId)))
      { /* EventId is not defined for current configuration */
        continue;                                                                                 /* PRQA S 0770 *//* MD_DEM_14.5 */
      }
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      if (DEM_IS_SET_STORED_DTC(EventId)                                                          /* PRQA S 3415 *//* MD_DEM_12.4 */
        && (DemCfg_GetCountOfSnapshotRecNumbers(EventId) > 0) )
      {
        /* Each DTC has up to DemCfg_GetCountOfSnapshotsPerDTC() snapshot records */
        /* The current count is event specific */
        Dem_DtcChronoRefType primaryMemoryIndex = Dem_GetPriMemStackIndex(EventId);
        if (primaryMemoryIndex < DemCfg_GetMaxCountOfPriMemStack())
        {
          P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) priMemPtr;                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
          priMemPtr = Dem_GetPrimaryStackBufferPtr(primaryMemoryIndex);
          /* get the current used counter from the events PrimaryMemory entry */
          numberOfRecords = numberOfRecords + priMemPtr[Dem_PriMemSnapshotUsedCntOffset()];
          DEM_SET_FILTERED_DTC(EventId);
        }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        else
        {
          Dem_DetReportError(DEM_SETDTCFILTERFORRECORDS_APIID, DEM_E_INVALIDSTATE);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
        }
#endif
      }
      else
      {
        DEM_UNSET_FILTERED_DTC(EventId);                                                          /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
      }
    }
    *NumberOfFilteredRecords = numberOfRecords;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_SETDTCFILTERFORRECORDS_APIID, DEM_E_UNINIT);
  }
#endif

  /* internal preserve the record count, see Dem_GetNumberOfFilteredDTC() */
  Dem_CountOfFilteredDTCs = numberOfRecords;

  return returnValue;
}


/**********************************************************************************************************************
  Dem_SetViewFilter
**********************************************************************************************************************/
/** Sets a view filter.
 *  The function Dem_SetViewFilter shall set a mask to process only the events of a functional addressable function
 *  with the following DCM <-> DEM API calls.
 *  The DEM module's environment shall call the function Dem_SetViewFilter again with another ViewId to to change the
 *  view.
 *  The chosen ViewId is reset to the default value (0xFF -> all functional groups are visible) inside the DEM module
 *  when the DEM module's environment has called the function Dem_SetDTCFilter or the function Dem_Shutdown.
 *  The function Dem_SetViewFilter may be used in case that only a special functional group shall be addressed
 *  (e.g. wiper system, window lifter). After setting a ViewId only events from the selected group are accessible in
 *  the event memory.
 *  The DEM module's environment shall use the function Dem_SetViewFilter for function oriented diagnostics on ECUs
 *  with multiple functions.
 * \return      Status of the operation of type Dem_ReturnSetViewFilterType.
 * \note        SERVICE ID   0x14
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        CONFIG       The assignment of an EventId to a specific view has to be configured / calibrated.
 * \note        AUTOSAR R3.0 API
 * \param[in]   ViewId      The ViewId is a parameter used to select a specific view.
 * \retval      DEM_VIEW_ID_ACCEPTED  View ID was accepted
 * \retval      DEM_WRONG_ID          Wrong View ID selected
 * \attention   feature not supported for this OEM.
 *********************************************************************************************************************/
FUNC(Dem_ReturnSetViewFilterType, DEM_CODE)                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetViewFilter(
  Dem_ViewIdType ViewId
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_SETVIEWFILTER_APIID, DEM_E_UNINIT);
  }
  else
#endif
  {
    /* feature not supported for this OEM */
    DEM_IGNORE_UNUSED_ARG(ViewId);                                                                /* PRQA S 3112 *//* MD_DEM_14.2 */
  }
  return DEM_WRONG_ID;
}


/**********************************************************************************************************************
  Dem_GetStatusOfDTC
**********************************************************************************************************************/
/** Reads the DTCStatus of a DTC.
 *  If the DTC is not stored in one of the available event memories
 *  the parameter DTCOrigin is neglected e.g., when DTC status is pending.
 * \return      Status of the operation of type Dem_ReturnGetStatusOfDTCType.
 * \note        SERVICE ID   0x15
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1904 1906 1910, 0x1905, 0x1909, 0x190B 190C 190D 190E
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC       For this DTC its status is requested.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either only OBD-relevant DTCs or all DTCs.
 * \param[in]   DTCOrigin If the DEM supports more than one event memory this parameter is used to select the
 *                        source memory the DTCs shall be read from.
 * \param[out]  DTCStatus This parameter receives the status information of the requested DTC.
 *                        If the return value of the function call is other
 *                        than OK this parameter does not contain valid data.
 * \retval      DEM_STATUS_OK               Status of DTC is OK
 * \retval      DEM_STATUS_WRONG_DTC        Wrong DTC
 * \retval      DEM_STATUS_WRONG_DTCORIGIN  Wrong DTC origin
 * \retval      DEM_STATUS_WRONG_DTCKIND    DTC kind wrong
 * \retval      DEM_STATUS_FAILED           DTC failed
 * \note        The returned DTCStatus has set the unsupported status bits to '0', see StatusAvailabilityMask.
 * \note  Dem059 requires "parameter DTCOrigin is neglected, if the DTC is not stored in one of the available event
 *        memories". In this case (Dem171) the return value shall be WRONG_DTCORIGIN. With that return value, no
 *        'DTCStatus' is not returned to the caller (Dem212).
 *        Consequence: either the given DTCOrigin contains the DTC (success) or not (failure). In case of failure the
 *                     handling for "DTCOrigin is neglected" is obsolete, as no status will never be returned!
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE)                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetStatusOfDTC(
  Dem_DTCType                                             DTC,
  Dem_DTCKindType                                         DTCKind,
  Dem_DTCOriginType                                       DTCOrigin,
  P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_ReturnGetStatusOfDTCType returnValue = DEM_STATUS_FAILED;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DTCStatus == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETSTATUSOFDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((DEM_DTC_KIND_ALL_DTCS != DTCKind) && (DEM_DTC_KIND_EMISSION_REL_DTCS != DTCKind))
  {
    Dem_DetReportError(DEM_GETSTATUSOFDTC_APIID, DEM_E_PARAM_DATA);
    returnValue = DEM_STATUS_WRONG_DTCKIND;
  }
  else if (FALSE == Dem_IsSupportedDtcOrigin(DTCOrigin))
  {
    Dem_DetReportError(DEM_GETSTATUSOFDTC_APIID, DEM_E_PARAM_CONFIG);
    returnValue = DEM_STATUS_WRONG_DTCORIGIN;
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    /* check DTC/DTCKind/DTCOrigin */
    EventId = Dem_GetEventIdOfDTC(DTC, DTCKind, DTCOrigin);
    if (EventId != 0)
    {
      /* check, if DTC is currently stored at the given origin */
      switch (DTCOrigin)
      {
      case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
        *DTCStatus  = Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId]);
        returnValue = DEM_STATUS_OK;
        break;
      case DEM_DTC_ORIGIN_SECONDARY_MEMORY:
        /* ORIGIN_SECONDARY_MEMORY is not supported with this manufacturer and release */
        returnValue = DEM_STATUS_FAILED;
        break;
      case DEM_DTC_ORIGIN_MIRROR_MEMORY:
        /* ORIGIN_MIRROR_MEMORY is not supported with this manufacturer and release */
        returnValue = DEM_STATUS_FAILED;
        break;
      default:
        returnValue = DEM_STATUS_FAILED;
        break;
      }
    }
    else
    { /* no such DTC/DTCKind/DTCOrigin defined */
      returnValue = DEM_STATUS_WRONG_DTC;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETSTATUSOFDTC_APIID, DEM_E_UNINIT);
  }
#endif

  return returnValue;
}


/**********************************************************************************************************************
  Dem_GetDTCStatusAvailabilityMask
**********************************************************************************************************************/
/** Available bits in DTC status byte (UDS).
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x16
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1901 1907 1911 1912, 0x1902 190A 190F 1913 1915, 0x1908, 0x1909, 
 *                                           0x190B 190C 190D 190E and 0x1914
 *                           Internal from Dem_SetDTCFilter()
 * \note        AUTOSAR R3.0 API
 * \param[out]  DTCStatusMask   The value from type Dem_DTCStatusMaskType indicates the supported DTC status bits
 *                              from the DEM. All supported information is indicated by setting
 *                              the corresponding status bit to 1.
 * \retval      E_OK      get of DTC status mask was successful
 * \retval      E_NOT_OK  get of DTC status mask failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCStatusAvailabilityMask(
  P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatusMask                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DTCStatusMask == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    *DTCStatusMask = (Dem_DTCStatusMaskType)(
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_OFF)
      /* if the PendingDTC bit is internally not supported, we will set it to zero (0) [~0x04=0xFB]*/
      0xFBu &
#endif
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_OFF)
      /* if the WarningIndicator bit is internally not supported, we will set it to zero (0) [~0x80=0x7F]*/
      0x7Fu &
#endif
      Dem_StatusAvailabilityMask);
    returnValue = E_OK;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetNumberOfFilteredDTC
**********************************************************************************************************************/
/** The API shall be used to get the number of DTC matching the defined status mask.
 *  The DTC Status mask filter is set by the API Dem_SetDTCFilter().
 * \return      Dem_ReturnGetNumberOfFilteredDTCType
 * \note        SERVICE ID   0x17
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1901 1907 1911 1912, 0x1902 190A 190F 1913 1915, 0x1908, 0x1914
 * \note        AUTOSAR R3.0 API
 * \attention   DTC filter has been set up properly before function call (Dem_SetDTCFilter).
 * \param[out]  NumberOfFilteredDTC   The number of DTCs matching the defined status mask.
 * \retval      DEM_NUMBER_OK        get of number of DTC was successful
 * \retval      DEM_NUMBER_FAILED    get of number of DTC failed
 * \retval      DEM_NUMBER_PENDING   get of number of DTC is pending  (unused)
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredDTC                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_ReturnGetNumberOfFilteredDTCType returnValue = DEM_NUMBER_FAILED;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (NumberOfFilteredDTC == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETNUMBEROFFILTEREDDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    *NumberOfFilteredDTC = Dem_CountOfFilteredDTCs;
    returnValue = DEM_NUMBER_OK;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETNUMBEROFFILTEREDDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetNextFilteredDTC
**********************************************************************************************************************/
/** Get next filtered DTC and DTC status.
 *  The API shall be used to return the current DTC and its associated status from the DEM matching the filter
 *  criteria defined by the API call Dem_SetDTCFilter. After having returned the data the function skips to the
 *  next DTC matching the filter criteria.
 *  To receive all DTCs matching the filter criteria this function shall be called continuously until the return value
 *  of the function is 'NoMatchingDTC'.
 *  The chronological order shall be reported if the DTC status mask parameter is set to 'pending' and/or 'confirmed'
 *  (no other status bits are allowed to be set). The function shall start with the most recent DTC. The chronological
 *  order may vary with the customer specific attributes used by the algorithm for sorting the DTC records
 *  (e.g. pre-sorted records or time-stamp attributes of the records).
 * \return      Status of the operation to retrieve a DTC from the DEM.
 * \note        SERVICE ID   0x18
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1902 190A 190F 1913 1915, 0x1908, 0x1914
 * \note        AUTOSAR R3.0 API
 * \param[out]  DTC         Receives the DTC value returned by the function. If the return value of the function
 *                          is other than OK this parameter does not contain valid data.
 * \param[out]  DTCStatus   This parameter receives the status information of the requested DTC. If the return value
 *                          of the function call is other than OK this parameter does not contain valid data.
 * \retval      DEM_FILTERED_OK               Returned next filtered DTC
 * \retval      DEM_FILTERED_NO_MATCHING_DTC  No DTC matched
 * \retval      DEM_FILTERED_WRONG_DTCKIND    DTC kind wrong
 * \note        The returned DTCStatus has set the unsupported status bits to '0', see StatusAvailabilityMask
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTC(
 P2VAR(Dem_DTCType,           AUTOMATIC, DEM_APPL_DATA)  DTC,                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus                                /* PRQA S 0850 *//* MD_MSR_19.8 */
 )
{
  Dem_ReturnGetNextFilteredDTCType returnValue = DEM_FILTERED_NO_MATCHING_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTC == NULL_PTR) || (DTCStatus == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    if ( Dem_NextFilteredSequence == DEM_NextFilteredSeq_CHRONOLOGICAL )
    {
      Dem_DtcChronoRefType chronoIndex;
      for (chronoIndex = 0; chronoIndex < *Dem_ChronoPriMemUsedPtr; ++chronoIndex)
      {
        EventId = Dem_GetEventIdOfEntry(chronoIndex);
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC = DemCfg_GetDTCnumber(EventId);
          *DTCStatus = Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId]);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
      if (returnValue != DEM_FILTERED_OK)
      { /* No filtered event any more in the chrono stack */
        Dem_NextFilteredSequence = DEM_NextFilteredSeq_BYEVENTID;     /* skip searching chrono stack in next cycle */
      }
    }
    /* entry point, if (Dem_NextFilteredSequence == DEM_NextFilteredSeq_BYEVENTID) or nothing found in chrono stack: */
    if (DEM_FILTERED_NO_MATCHING_DTC == returnValue)                  /* continue scan, when CHRONOLOGICAL didn't find all DTC in ChronoStack */
    {
      /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
      for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
      { /* highest EventId has lowest DTC number */
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC = DemCfg_GetDTCnumber(EventId);
          *DTCStatus = Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId]);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTC_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetNextFilteredRecord
**********************************************************************************************************************/
/** Get filtered DTC and next Snapshot Record Number.
 *  The API shall be used to return the current DTC and its associated Snapshot Record numbers from the DEM matching
 *  the filter criteria defined by the API call Dem_SetDTCFilterForRecords. After having returned the data the function
 *  skips to the next Record matching the filter criteria.
 *  To receive all Records matching the filter criteria this function shall be called continuously until the return
 *  value of the function is 'NoMatchingDTC'.
 * \return      Status of the operation to retrieve a DTC from the DEM.
 * \note        SERVICE ID   0x3a
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1903
 * \note        AUTOSAR R3.0 API
 * \param[out]  DTC             Receives the DTC value returned by the function. If the return value of the function
 *                              is other than OK this parameter does not contain valid data.
 * \param[out]  SnapshotRecord  Snapshot Record Number for the reported DTC.
 * \retval      DEM_FILTERED_OK               Returned next filtered DTC
 * \retval      DEM_FILTERED_NO_MATCHING_DTC  No DTC matched
 * \retval      DEM_FILTERED_WRONG_DTCKIND    DTC kind wrong
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredRecord(
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,                                              /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  P2VAR(uint8,       AUTOMATIC, DEM_APPL_DATA)  SnapshotRecord                                    /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetNextFilteredDTCType returnValue = DEM_FILTERED_NO_MATCHING_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTC == NULL_PTR) || (SnapshotRecord == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDRECORD_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    if ( Dem_NextFilteredSequence == DEM_NextFilteredSeq_CHRONOLOGICAL )
    {
      Dem_DtcChronoRefType chronoIndex;
      for ( chronoIndex = 0; chronoIndex < *Dem_ChronoPriMemUsedPtr; ++chronoIndex)
      {
        EventId = Dem_GetEventIdOfEntry(chronoIndex);
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          /* Each DTC has up to DemCfg_GetCountOfSnapshotsPerDTC() snapshot records, but the current count is event specific */
          Dem_DtcChronoRefType primaryMemoryIndex = Dem_GetPriMemStackIndex(EventId);
          if (primaryMemoryIndex < DemCfg_GetMaxCountOfPriMemStack())
          {
            P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) priMemPtr = Dem_GetPrimaryStackBufferPtr(primaryMemoryIndex);        /* PRQA S 0850 *//* MD_MSR_19.8 */
            /* get the current used counter from the events PrimaryMemory entry */
            uint8  availableSnapshots = priMemPtr[Dem_PriMemSnapshotUsedCntOffset()];   /* number of actual FirstConfirmed + MostRecent snapshots */

            /* the records are numbered in ascending order starting with value 'DemCfg_GetFirstOccurredRecordNr()' */
            *SnapshotRecord = (uint8) (DemCfg_GetFirstOccurredRecordNr() + Dem_NextFilteredSSRecordIdx);
            *DTC = DemCfg_GetDTCnumber(EventId);
          
            ++Dem_NextFilteredSSRecordIdx;
          
            if (Dem_NextFilteredSSRecordIdx >= availableSnapshots)
            { /* done with this event, prepare the next */
              Dem_NextFilteredSSRecordIdx = 0;
              DEM_UNSET_FILTERED_DTC(EventId);                                                    /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
            }
            returnValue = DEM_FILTERED_OK;
          }
          else
          { /* EventId was set by SetFilter, but now no data available ?! */
            returnValue = DEM_FILTERED_WRONG_DTCKIND;
          }
          break;
        }
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDRECORD_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetNextFilteredDTCAndFDC
**********************************************************************************************************************/
/** Get next DTC and its associated Fault Detection Counter (FDC).
 *  The API shall be used to return the current DTC and its associated Fault Detection Counter (FDC) from the DEM
 *  matching the filter criteria defined by the API call Dem_SetDTCFilter. After having returned the data the function
 *  skips to the next DTC matching the filter criteria.
 *  To receive all DTCs matching the filter criteria this function shall be called continuously until the return value
 *  of the function is 'NoMatchingDTC'.
 * \return      Status of the operation to retrieve a DTC from the DEM.
 * \note        SERVICE ID   0x3b
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1914
 * \note        AUTOSAR R3.0 API
 * \param[out]  DTC             Receives the DTC value returned by the function. If the return value of the function
 *                              is other than OK this parameter does not contain valid data.
 * \param[out]  DTCFaultDetectionCounter    This parameter receives the Fault Detection Counter information of the
 *                              requested DTC. If the return value of the function call is other than DEM_FILTERED_OK
 *                              this parameter does not contain valid data.
 *                              (-128dec...127dec PASSED...FAILED according to ISO 14229-1)
 * \retval      DEM_FILTERED_OK               Returned next filtered DTC
 * \retval      DEM_FILTERED_NO_MATCHING_DTC  No DTC matched
 * \retval      DEM_FILTERED_WRONG_DTCKIND    DTC kind wrong
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTCAndFDC(
 P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(sint8,       AUTOMATIC, DEM_APPL_DATA)  DTCFaultDetectionCounter                           /* PRQA S 0850 *//* MD_MSR_19.8 */
 )
{
  Dem_ReturnGetNextFilteredDTCType returnValue = DEM_FILTERED_NO_MATCHING_DTC;
  sint8 fdc;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTC == NULL_PTR) || (DTCFaultDetectionCounter == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    /*
    With external FaultDetectionCounter(s) we might use a callback here - this forbids critical section here.
    DEM_UNSET_FILTERED_DTC is a write access, but needs not be protected against concurrent access.
    */

    if ( Dem_NextFilteredSequence == DEM_NextFilteredSeq_CHRONOLOGICAL )
    {
      Dem_DtcChronoRefType chronoIndex;
      for ( chronoIndex = 0; chronoIndex < *Dem_ChronoPriMemUsedPtr; ++chronoIndex)
      {
        EventId = Dem_GetEventIdOfEntry(chronoIndex);
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC = DemCfg_GetDTCnumber(EventId);
          fdc  = Dem_FaultDetectionCounterPtr[EventId];
          /* ISO 14229-1 (UDS Svc 19 14) restricts the FaultDetectionCounter to positive values (0...127) */
          *DTCFaultDetectionCounter = (sint8)((fdc > 0) ? (sint8)(fdc) : (sint8)0x0);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
      if (returnValue != DEM_FILTERED_OK)
      { /* No filtered event any more in the chrono stack */
        Dem_NextFilteredSequence = DEM_NextFilteredSeq_BYEVENTID;     /* skip searching chrono stack in next cycle */
      }
    }
    /* entry point, if (Dem_NextFilteredSequence == DEM_NextFilteredSeq_BYEVENTID) or nothing found in chrono stack: */
    if (DEM_FILTERED_NO_MATCHING_DTC == returnValue)                  /* continue scan, when CHRONOLOGICAL didn't find all DTC in ChronoStack */
    {
      /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
      for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
      { /* highest EventId has lowest DTC number */
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC = DemCfg_GetDTCnumber(EventId);
          fdc  = Dem_FaultDetectionCounterPtr[EventId];
          /* ISO 14229-1 (UDS Svc 19 14) restricts the FaultDetectionCounter to positive values (0...127) */
          *DTCFaultDetectionCounter = (sint8)((fdc > 0) ? (sint8)(fdc) : (sint8)0x0);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_UNINIT);
  }
#endif

  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetNextFilteredDTCAndSeverity
**********************************************************************************************************************/
/** Gets the current DTC and its Severity from the DEM.
 *  The function Dem_GetNextFilteredDTCAndSeverity shall return the current DTC and its associated Fault Severity
 *  from the DEM matching the filter criteria defined by the function call Dem_SetDTCFilter.
 *  After having returned the data the function Dem_GetNextFilteredDTCAndSeverity shall skip to the next DTC
 *  matching the filter criteria.
 *  The DEM module's environment shall call the function Dem_GetNextFilteredDTCAndSeverity continuously until
 *  the return value of the function is DEM_FILTERED_NO_MATCHING_DTC to receive all DTCs matching the filter criteria.
 * \return      Dem_ReturnGetNextFilteredDTCType
 * \note        SERVICE ID   0x3d
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1908
 * \note        AUTOSAR R3.0 API
 * \param[out]  DTC                 Receives the DTC value returned by the function. If the return value
 *                                  of the function is other than DEM_FILTERED_OK this parameter does not contain valid data.
 * \param[out]  DTCStatus           Receives the status value returned by the function. If the return value
 *                                  of the function is other than DEM_FILTERED_OK this parameter does not contain valid data.
 * \param[out]  DTCSeverity         Receives the severity value returned by the function. If the return value
 *                                  of the function is other than DEM_FILTERED_OK this parameter does not contain valid data.
 * \param[out]  DTCFunctionalUnit   Receives the functional unit value returned by the function. If the return value
 *                                  of the function is other than DEM_FILTERED_OK this parameter does not contain valid data.
 * \retval      DEM_FILTERED_OK               Returned next filtered DTC
 * \retval      DEM_FILTERED_NO_MATCHING_DTC  No DTC matched
 * \retval      DEM_FILTERED_WRONG_DTCKIND    DTC kind wrong
 * \note        The returned DTCStatus has set the unsupported status bits to '0', see StatusAvailabilityMask
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTCAndSeverity(
 P2VAR(Dem_DTCType,           AUTOMATIC, DEM_APPL_DATA)  DTC,                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus,                               /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCSeverityType,   AUTOMATIC, DEM_APPL_DATA)  DTCSeverity,                             /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(uint8,                 AUTOMATIC, DEM_APPL_DATA)  DTCFunctionalUnit                        /* PRQA S 0850 *//* MD_MSR_19.8 */
 )
{
  Dem_ReturnGetNextFilteredDTCType returnValue = DEM_FILTERED_NO_MATCHING_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTC == NULL_PTR) || (DTCStatus == NULL_PTR) || (DTCSeverity == NULL_PTR) || (DTCFunctionalUnit == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
# endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    if ( Dem_NextFilteredSequence == DEM_NextFilteredSeq_CHRONOLOGICAL )
    {
      Dem_DtcChronoRefType chronoIndex;
      for ( chronoIndex = 0; chronoIndex < *Dem_ChronoPriMemUsedPtr; ++chronoIndex)
      {
        EventId = Dem_GetEventIdOfEntry(chronoIndex);
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC                = DemCfg_GetDTCnumber(EventId);
          *DTCStatus          = Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId]);
          *DTCSeverity        = DemCfg_GetDTCSeverity(EventId);
          *DTCFunctionalUnit  = DemCfg_GetFunctionalUnit(EventId);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
      if (returnValue != DEM_FILTERED_OK)
      { /* No filtered event any more in the chrono stack */
        Dem_NextFilteredSequence = DEM_NextFilteredSeq_BYEVENTID;     /* skip searching chrono stack in next cycle */
      }
    }
    /* entry point, if (Dem_NextFilteredSequence == DEM_NextFilteredSeq_BYEVENTID) or nothing found in chrono stack: */
    if (DEM_FILTERED_NO_MATCHING_DTC == returnValue)                  /* continue scan, when CHRONOLOGICAL didn't find all DTC in ChronoStack */
    {
      /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
      for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
      { /* highest EventId has lowest DTC number */
        if (DEM_IS_SET_FILTERED_DTC(EventId))
        {
          *DTC                = DemCfg_GetDTCnumber(EventId);
          *DTCStatus          = Dem_MapStatusByteTypeToMaskType(Dem_DtcStatusBytePtr[EventId]);
          *DTCSeverity        = DemCfg_GetDTCSeverity(EventId);
          *DTCFunctionalUnit  = DemCfg_GetFunctionalUnit(EventId);
          DEM_UNSET_FILTERED_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
          returnValue = DEM_FILTERED_OK;
          break;
        }
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */

  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetTranslationType
**********************************************************************************************************************/
/** Gets the supported DTC formats of the ECU.
 * The supported formats are configured via DemTypeOfDTCSupported.
 * \return      The TranslationFormat provides the configured translation formats.
 *              Combination of different DTC formats is possible.
 * \note        SERVICE ID   0x3c
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1901 1907 1911 1912
 * \note        AUTOSAR R3.0 API
 * \retval      Bit 0 =='1': 2 byte ISO15031-6 DTC
 * \retval      Bit 1 =='1': 3 byte ISO14229-1 DTC
 * \retval      Bit 2 =='1': Customer specific DTC
 * \retval      Bit 3 =='1': SAEJ1939
 * \retval      Bit 4 =='1': WWH-OBD-format
*******************************************************************************/
FUNC(uint8, DEM_CODE)                                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetTranslationType(
  void
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ( ! ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled)))
  {
    Dem_DetReportError(DEM_GETTRANSLATIONTYPE_APIID, DEM_E_UNINIT);
  }
#endif
  return DemCfg_GetDTCTranslationFormat();
}

/**********************************************************************************************************************
  Dem_GetDTCByOccurrenceTime
**********************************************************************************************************************/
/** Access specific events stored at certain important points in time.
 *  The API provides the capability to access specific events stored at certain important points in time, The API call
 *  will return one DTC according to the Dem_DTCRequestType. If no DTC is matching the requested point in time the
 *  function will return the appropriate operation status (ref. to 8.2.2.11) and the DTC value will be zero (0).
 * \return      Status of the operation of type Dem_ReturnGetDTCByOccurrenceTimeType.
 * \note        SERVICE ID   0x19
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x190B 190C 190D 190E
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCRequest  This parameter defines the request type of the DTC.
 * \param[in]   DTCKind     This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[out]  DTC         Receives the DTC value returned by the function. If the return value of the function
 *                          is other than DEM_OCCURR_OK this parameter does not contain valid data.
 * \retval      DEM_OCCURR_OK             Status of DTC was OK
 * \retval      DEM_OCCURR_WRONG_DTCKIND  DTC kind wrong
 * \retval      DEM_OCCURR_FAILED         DTC failed
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCByOccurrenceTime(
  Dem_DTCRequestType                            DTCRequest,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC                                               /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetDTCByOccurrenceTimeType returnValue = DEM_OCCURR_FAILED;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DTC == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    switch (DTCRequest)
    {
    case DEM_FIRST_FAILED_DTC:
      EventId = *Dem_FirstFailedEventIdPtr;
      break;
    case DEM_MOST_RECENT_FAILED_DTC:
      EventId = *Dem_MostRecentFailedEventIdPtr;
      break;
    case DEM_FIRST_DET_CONFIRMED_DTC:
      EventId = *Dem_FirstConfirmedEventIdPtr;
      break;
    case DEM_MOST_REC_DET_CONFIRMED_DTC:
      EventId = *Dem_MostRecentConfmdEventIdPtr;
      break;
    default:
#if (DEM_DEV_ERROR_DETECT == STD_ON)
      /* invalid DTCRequest */
      Dem_DetReportError(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_PARAM_DATA);
#endif
      EventId = 0;
    }
    if (EventId != 0)
    {
      if ((DTCKind == DemCfg_GetDTCKind(EventId)))
      {
        *DTC = DemCfg_GetDTCnumber(EventId);
        returnValue = DEM_OCCURR_OK;
      }
      else
      {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
        { /* invalid DTCKind */
          Dem_DetReportError(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_PARAM_DATA);
        }
#endif
        returnValue = DEM_OCCURR_WRONG_DTCKIND;
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}


/**********************************************************************************************************************
  Dem_MemMove
**********************************************************************************************************************/
/** Copies a RAM data block to another RAM data block, blocks may overlap.
 *  This function copies a memory block of length 'blockLen' from address 'srcAddr' to address 'tgtAddr'.
 *  Typically the copying starts with the lowest address first, then copies the values at the next higher address, etc.
 *  until the whole 'blockLen' is copied. This will cause problems, if the source and the target buffer will overlap
 *  AND 'srcAddr' is lower than 'tgtAddr' (example: buffers contain 20 byte, srcAddr is address X so source buffer
 *  uses addresses X...X+19, tgtAddr is address X+10 (as buffers shall overlap here!). When copying srcAddr[0] to
 *  tgtAddr[0] we will overwrite part of the sourcebuffer at address X+10!). Solution for this case: copy from highest
 *  to lowest address (example: copy first srcAddr[19] to tgtAddr[19], then [18], ...).
 *  This distinction of cases is done in the code.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_UpdateUserdataRecord_Recent()
 *                                    Dem_UpdateUserdataRecord()
 *                                    Dem_GetFreezeFrameDataByDTC()
 * \note        Contrary to MemCopy() this function handles overlapping memory areas correctly.
 * \attention   The size of the destination buffer at 'tgtAddr' must be large enough to hold 'blockLen' bytes
 * \param[in]     srcAddr     Source buffer to copy from
 * \param[in]     blockLen    Number of bytes to copy (typically: size of source buffer)
 * \param[in,out] tgtAddr     (address of) Target buffer to copy into
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_MemMove(
  P2VAR(  uint8, AUTOMATIC, DEM_APPL_DATA)  tgtAddr,                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA)  srcAddr,                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  uint16                                    blockLen
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (srcAddr == NULL_PTR)
  {
    Dem_DetReportError(DEM_MEMMOVE_APIID, DEM_E_ZEROPTR_SOURCE );
  }
  else if (tgtAddr == NULL_PTR)
  {
    Dem_DetReportError(DEM_MEMMOVE_APIID, DEM_E_ZEROPTR_TARGET );
  }
  else
#endif
  {
    /* Check for destructive overlap */
    if ((srcAddr < tgtAddr) && (tgtAddr < &srcAddr[blockLen]))
    { /* Destructive overlapping, we have to copy backwards */
      srcAddr = &srcAddr[blockLen];
      tgtAddr = &tgtAddr[blockLen];
      for (; blockLen > 0; --blockLen)
      {
        tgtAddr = &tgtAddr[-1];                                      /*  MISRA improvement for: --tgtAddr; */
        srcAddr = &srcAddr[-1];                                      /*  MISRA improvement for: --srcAddr; */
        *tgtAddr = *srcAddr;
      }
    }
    else if (tgtAddr != srcAddr)
    { /* No overlapping, do a forward copy */
      for (; blockLen > 0 ; --blockLen)
      {
        *tgtAddr = *srcAddr;
        tgtAddr = &tgtAddr[1];                                       /*  MISRA improvement for: tgtAddr++; */
        srcAddr = &srcAddr[1];                                       /*  MISRA improvement for: srcAddr++; */
      }
    }
    else  /* src == dst, no copying */
    {}    /* satisfy MISRA-C:2004 Rule 14.10: requires else for if-else-if statements */
  }
}




/**********************************************************************************************************************
  Dem_IsEqualDtcStatusByte
**********************************************************************************************************************/
/** Compare two status bytes. Consider the supported bits.
 * \return      boolean
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_InitChronoStack()
 *                                    Dem_AddNewDTCtoChronoStack()
 *                                    Dem_DoResetEventStatus()
 *                                    Dem_DoSetOperationCycleState()
 *                                    Dem_DoSetEventStatus()
 *                                    Dem_ClearSingleEvent()
 * \param[in]   first     1st status byte to compare
 * \param[in]   second    2nd status byte to compare
 * \retval      TRUE      status bytes are equal
 * \retval      FALSE     status bytes are different
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_IsEqualDtcStatusByte(
  P2CONST(Dem_DtcStatusByteType, AUTOMATIC, AUTOMATIC)  first,                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  CONSTP2CONST(Dem_DtcStatusByteType, AUTOMATIC, DEM_APPL_DATA)  second                             /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  boolean               returnValue = TRUE;
  Dem_DtcStatusByteType mask;                                       /* mask of Bits that must be equal when comparing */
  
  mask = (Dem_DtcStatusByteType) (
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_OFF)
    /* if the PendingDTC bit is internally not supported, we will set it to zero (0) [~0x04=0xFB]*/
    0xFBu &
#endif
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_OFF)
    /* if the WarningIndicator bit is internally not supported, we will set it to zero (0) [~0x80=0x7F]*/
    0x7Fu &
#endif
    Dem_StatusAvailabilityMask);

  if ((mask & *first) != (mask & *second))
  {
    returnValue = FALSE;
  }
  return returnValue;
}



/**********************************************************************************************************************
  Dem_InitChronoStack
**********************************************************************************************************************/
/** Initialization of chrono stack and (re)setting of status bits.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_NvDataInit()
 *                                    Dem_MainFunction()
 * \param[in]   notifyApplication   "TRUE" will use the callback functions TriggerOnEvent and InitMonitor if any
 *                                  status bit of an event changes, "FALSE" won't call the callbacks.
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_InitChronoStack(
  boolean   notifyApplication
  )
{
  Dem_EventIdType EventId;
  Dem_DtcChronoRefType i;
  boolean isStatusUnchanged;
  Dem_DTCGroupKindType oldStatusUpdate;

  /* prevent APIs Dem_(Re)SetEventStatus while initializing the stack, save current status for later restore */
  oldStatusUpdate = Dem_StatusUpdate;
  Dem_StatusUpdate = 0x00;                /* prohibit the usage of API Dem_(Re)SetEventStatus */

  /* count down to prevent overflow */
  for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
  { /* reset all status bits of all events */
    Dem_DtcStatusByteType lDtcStatusByte;
    /* make a local copy of current status byte */
    lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

    /* Group UNSET macros and group SET macros to benefit from compiler optimizations */
    DEM_UNSET_BIT_TEST_FAILED(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
    DEM_UNSET_BIT_TEST_FAILED_THIS_OC(EventId);                                                   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_ON)
    DEM_UNSET_BIT_PENDING_DTC(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
    DEM_UNSET_BIT_CONFIRMED_DTC(EventId);                                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
    DEM_UNSET_STORED_DTC(EventId);                                                                /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
    DEM_UNSET_BIT_TEST_FAILED_SINCE_LC(EventId);                                                  /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
    DEM_UNSET_BIT_WARNING_INDICATOR_REQ(EventId);                                                 /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
    DEM_SET_BIT_TEST_N_COMPL_SINCE_LC(EventId);
    DEM_SET_BIT_TEST_N_COMPL_THIS_OC(EventId);
    /* apart from the very first initialization we trigger the callbacks */
    if (notifyApplication == TRUE)
    {
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (Dem_IsInActiveVariant(EventId) != FALSE)
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      {
        /* check if DTC status changed by last lines of code */
        isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);
        if (FALSE == isStatusUnchanged)
        { /* there is a change - notify application */
          Dem_TriggerOnEvent(EventId, lDtcStatusByte);
        }
        /* call related Xxx_DemInitMonitor{EventId}() function */
        if (!! DemCfg_GetInitMonitorFPtr(EventId))                                                /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
        {
          (void)(*DemCfg_GetInitMonitorFPtr(EventId))(DEM_INIT_MONITOR_CLEAR);
        }
      }
    }
    Dem_FaultDetectionCounterPtr[EventId] = 0;
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
    Dem_ClearDebounceTimerSlot(EventId);
#endif
#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
    /* reset occurrence counter */
    Dem_DtcOccurrenceCounterPtr[EventId] = 0;
#endif
  }

  for (i=0; i<DemCfg_GetMaxCountOfPriMemStack(); ++i)
  { /* reset the chronological references for all event slots */
    Dem_ChronoPriMemPtr[i].ref               = i;
    Dem_ChronoPriMemPtr[i].dtcInternalNumber = 0;
    /* Reset aging counters */
    Dem_DtcAgingCounterPtr[i]                = 0;
  }
  *Dem_ChronoPriMemUsedPtr = 0;

  *Dem_FirstFailedEventIdPtr      = 0;  /* invalid */
  *Dem_FirstConfirmedEventIdPtr   = 0;  /* invalid */
  *Dem_MostRecentFailedEventIdPtr = 0;  /* invalid */
  *Dem_MostRecentConfmdEventIdPtr = 0;  /* invalid */

  /* allow APIs Dem_(Re)SetEventStatus again with previous setting */
  Dem_StatusUpdate = oldStatusUpdate;
}

/**********************************************************************************************************************
  Dem_NvDataInit
**********************************************************************************************************************/
/** NVRAM-Manager Callback for initialization of non volatile memory.
 * \return      Std_ReturnType
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   yes
 * \note        CALLED BY    Internal from Dem_Init()
 *                           or by NvM, if NVRAM is empty or invalid
 * \retval      E_OK         To fulfill requirement NVM369 for InitBlockCallbackFunction 
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_NvDataInit( 
  void
  )
{
  uint8_least  i;
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) nvPtr;                                                   /* PRQA S 0850 *//* MD_MSR_19.8 */

  /* Initialize whole Dem_NvData buffer with value DEM_NVDATA_INIT_VALUE
   * We skip (part of) the Dem_NvData.terminatingPattern part, as it is written below */
  for (nvPtr = Dem_TerminatingPatternPtr;
       nvPtr > Dem_ConsistencyPatternPtr;
       nvPtr = &nvPtr[-1])                                      /*  MISRA improvement for: --nvPtr; */
  {
    *nvPtr = DEM_NVDATA_INIT_VALUE;
  }

  for (i=0; i<(uint8_least)DEM_NVDATA_PATTERN_SIZE; ++i)
  {
    Dem_ConsistencyPatternPtr[i] = originalPattern[i];
    Dem_TerminatingPatternPtr[i] = originalEndPattern[i];
  }

#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
  /* store currently active configuration variant */
  *Dem_ActiveConfigPtr = Dem_ActiveVariant;
#endif  /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */

  Dem_InitChronoStack(FALSE);           /* don't notify application */

  return E_OK;
}


/**********************************************************************************************************************
  Dem_MainFunction
**********************************************************************************************************************/
/** Periodic function with fixed cyclic timing.
 *  This function is used to process all not event based DEM internal functions. It shall be called
 *  periodically as cyclic task by the software system (e.g. by operating system).
 * \note        SERVICE ID   0x55
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        CONFIGURATION   The cyclic time for the main function has to be defined as an operating system task
 *                              or runable entity.
 * \note        AUTOSAR R3.0 API
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_MainFunction(
  void
  )
{
  if (DEM_IsDisabled != Dem_InitializationStatus)
  { /* DEM is in state DEM_IsUninitialized or DEM_IsEnabled/DEM_IsEnabledAndRunning */
    if (DEM_IsEnabled == Dem_InitializationStatus)
    { /* DEM was enabled right now. First we must handle the queued BSW errors,
      *  that were detected between Dem_PreInit and Dem_Init */
      uint16              aqIndex;
      Dem_AQElementType  *elemPtr;
      /* Are there actions in the queue to handle? */
      for (aqIndex = 0; aqIndex < Dem_AQUsed(); ++aqIndex)
      {
        /* Beware: the Dem_OperationCycleState of the BSW event(s) must be in State DEM_CYCLE_STATE_START
        **         for the events to be transfered into PrimaryMemory, else they get lost now! Use beforehand
        ** Dem_SetOperationCycleState (Dem_OperationCycleIdType CycleId, DEM_CYCLE_STATE_START); */

        /* Typically the cycle must be running, i.e. started before the events are notified to the DEM. When emptying the
        ** BSW-queue we permit here and now one exception: the cycle must be started before the queue is worked/emptied.
        ** So here we have to check for any SetOperationCycleState actions stored in the action queue, work them first,
        ** and then afterwards work the ReportErrorStatus actions in the queue.
        **
        ** This is implemented as: (a) scan the queue for startcycle actions, (b) handle them and nullify their entry
        ** in the queue, (c) rescan the queue for the remaining entries by using the default handling below. (Which is
        ** used each time Dem_MainFunction() is called.)
        */

        /* get element and don't remove it from queue but overwrite its action by 'none' */
        elemPtr = Dem_AQPeek( aqIndex );

        if (DEM_AQACTION_SETOPCYCLE == Dem_AQGetAction(elemPtr))
        {
          Dem_OperationCycleIdType    operationCycleId = Dem_AQGetOpCycleId( elemPtr );
          Dem_OperationCycleStateType cycleState       = Dem_AQGetOpCycleState( elemPtr );

          /* do the OperationCycleState change now ...*/
          (void) Dem_DoSetOperationCycleState( operationCycleId, cycleState );

          /* ... and inactivate the element in the action queue */
          Dem_AQSetAction(elemPtr, DEM_AQACTION_NONE);
        }
      }

      /* now we are in normal operation mode, work the remaining queue entries */
      Dem_InitializationStatus = DEM_IsEnabledAndRunning;
    }

    if (DEM_IsEnabledAndRunning == Dem_InitializationStatus)
    {
      Dem_AQElementType elem;

      /* Are there actions in the queue to handle? */
      while (Dem_AQUsed() > 0)
      {
        /* Enter Critical ========================================================== */
        Dem_EnterCritical();
        Dem_AQPop( &elem );
        Dem_LeaveCritical();
        /* Leave Critical ========================================================== */
        switch (Dem_AQGetAction(&elem))
        {
        case DEM_AQACTION_SETEVENT:
          {
            Dem_EventIdType     EventId     = Dem_AQGetEventId( &elem );
            Dem_EventStatusType EventStatus = Dem_AQGetEventStatus( &elem );
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
            if (! (Dem_IsInActiveVariant(EventId)))
            { /* this EventId is invalid in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
              Dem_DetReportError(DEM_MAINFUNCTION_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
              /* ignore this event */
            }
            else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
            {
              (void) Dem_DoSetEventStatus( EventId, EventStatus );
            }
          }
          break;
        case DEM_AQACTION_SETOPCYCLE:
          {
            Dem_OperationCycleIdType    operationCycleId = Dem_AQGetOpCycleId( &elem );
            Dem_OperationCycleStateType cycleState       = Dem_AQGetOpCycleState( &elem );
            (void) Dem_DoSetOperationCycleState( operationCycleId, cycleState );
          }
          break;
        case DEM_AQACTION_CLEARALLDTC:
          {
            /* for DCM notification on pending/finished requests, we store the current request as terminated */
            Dem_AQCopy(Dem_FinishedClearDtcRequest, elem);
            /* there is no LatchedFailsafe criteria, that may force to preserve the warning indicator bit
             * in this project, so 'clear all' equals 'init' and we use Dem_InitChronoStack() */
            Dem_InitChronoStack( TRUE );
          }
          break;
        case DEM_AQACTION_CLEARDTCGROUP:
          {
            Dem_DTCGroupKindType  BitcodedDTCGroup = Dem_AQGetBitcodedDTCGroup( &elem );
            Dem_DTCKindType       DtcKind          = Dem_AQGetDTCKind( &elem );
            Dem_DTCOriginType     DtcOrigin        = Dem_AQGetDTCOrigin( &elem );
            /* for DCM notification on pending/finished requests, we store the current request as terminated */
            Dem_AQCopy(Dem_FinishedClearDtcRequest, elem);
            if (E_NOT_OK == Dem_DoClearGroupOfEvents( BitcodedDTCGroup, DtcKind, DtcOrigin ))
            { /* set 'failed' bit to the action */
              Dem_AQSetAction(&Dem_FinishedClearDtcRequest, (DEM_AQACTION_CLEARDTCGROUP | DEM_AQACTION_FAILED));
            }
          }
          break;
        case DEM_AQACTION_CLEARSINGLEEVENT:
          {
            Dem_EventIdType       EventId          = Dem_AQGetEventId( &elem );
            /* for DCM notification on pending/finished requests, we store the current request as terminated */
            Dem_AQCopy(Dem_FinishedClearDtcRequest, elem);
            if (E_NOT_OK == Dem_DoClearSingleEvent(EventId))
            { /* set 'failed' bit to the action */
              Dem_AQSetAction(&Dem_FinishedClearDtcRequest, (DEM_AQACTION_CLEARSINGLEEVENT | DEM_AQACTION_FAILED));
            }
          }
          break;
        case DEM_AQACTION_ENABLESTORAGE:
          {
            Dem_DTCGroupKindType  BitcodedDTCGroup = Dem_AQGetBitcodedDTCGroup( &elem );
            Dem_DTCKindType       DtcKind          = Dem_AQGetDTCKind( &elem );
            (void) Dem_DoEnableDTCStorage(BitcodedDTCGroup, DtcKind);
          }
          break;
        case DEM_AQACTION_RESETEVENTSTATUS:
          {
            Dem_EventIdType     EventId     = Dem_AQGetEventId( &elem );
            (void) Dem_DoResetEventStatus( EventId );
          }
          break;
        case DEM_AQACTION_NONE:
        default:
          /* do nothing, ignore the element */
          break;
        }
      }
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
      Dem_HandleTimeBasedDebounceEvents();
#endif
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* DEM is in state DEM_IsUninitialized (or the state was undefined due missing Dem_PreInit!) */
      Dem_DetReportError(DEM_MAINFUNCTION_APIID, DEM_E_UNINIT);
    }
#endif
  }
  /* else: we are in state DEM_IsDisabled, so nothing to do */
}


/**********************************************************************************************************************
  Dem_InitMemory
**********************************************************************************************************************/
/** Initializes all pre-initialized ("static") global variables.
 *  This function is a Vector specific add on. If the startup code of your linker won't initialize global variables,
 *  you can use this function instead. If so, this will always be the very first API of the DEM to call.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   yes
 * \note        CALLED BY    Startup code of the ECU (ECU-SchM)
 * \attention   This function is a VECTOR specific extension to AUTOSAR.
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_InitMemory(
  void
  )
{
  Dem_InitializationStatus = DEM_IsUninitialized;
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON)
  Dem_VariantInitialized = DEM_IsUninitialized;
#endif  /* DEM_SUPPORT_VARIANT_HANDLING */
}


#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON)
/**********************************************************************************************************************
  Dem_InitDiagnosticVariant
**********************************************************************************************************************/
/** Initialize DEM with the currently active variants.
 *  Before Dem_PreInit() is called you can change the currently active variants by calling this function.
 *  Afterwards the currently active variants cannot be changed, so such calls are ignored.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    no
 * \note        CALLED BY    ECU-SchM
 * \param[in]   activeCfg    bitfield containing the additional, active variants.
 * \attention   This function must be called before Dem_PreInit().
 * \attention   This function must be called after Dem_InitMemory(), if you are using Dem_InitMemory() instead of
 *              any other compiler startup code.
 *********************************************************************************************************************/
FUNC(void, DEM_CODE) Dem_InitDiagnosticVariant(uint32 activeCfg)                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
{
  if (Dem_VariantInitialized == DEM_IsUninitialized)
  {
    /* remember this function as "called" */
    Dem_VariantInitialized = DEM_IsEnabled;
    /* store the current set of variants */
    Dem_ActiveVariant = activeCfg;
  }
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  { /* this function or Dem_PreInit() was already called - ignore further variant change */
    Dem_DetReportError(DEM_INITDIAGNOSTICVARIANT_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
  }
# endif  /* DEM_DEV_ERROR_DETECT */
}
#endif  /* DEM_SUPPORT_VARIANT_HANDLING */


/**********************************************************************************************************************
  Dem_PreInit
**********************************************************************************************************************/
/** Pre-Initialization of the DEM.
 *  This function shall be used to initialize the internal states necessary to process events reported by BSWs by
 *  using Dem_ReportError.
 *  DEM_PreInit shall be called by the ECU State Manager during the startup phase of the ECU before the
 *  NVRAM Manager has finished the restore of NVRAM data.
 * \note        SERVICE ID   0x01
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    ECU-SchM
 * \note        AUTOSAR R3.0 API
 * \param[in]   activeCfg    MICROSAR extension: with MultipleConfiguration - set current config set
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_PreInit(
#if (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON) || (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_PREINIT_HAS_CONFIG_PARAM == STD_ON)
  P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST) activeCfg                                         /* PRQA S 0850 *//* MD_MSR_19.8 */
#else
  void
#endif /* DEM_SUPPORT_MULTIPLE_CONFIG || DEM_SUPPORT_VARIANT_HANDLING || DEM_PREINIT_HAS_CONFIG_PARAM */
  )
{
  Dem_EventIdType EventId;
  uint16_least i;
#if (DEM_SUPPORT_MULTIPLE_CONFIG != STD_ON) && (DEM_SUPPORT_VARIANT_HANDLING != STD_ON) && (DEM_PREINIT_HAS_CONFIG_PARAM == STD_ON)
  /* the function argument 'activeCfg' is used only with multiple configuration or variant handling */
  DEM_IGNORE_UNUSED_ARG(activeCfg);                                                               /* PRQA S 3112 *//* MD_DEM_14.2 */
#endif /* ! DEM_SUPPORT_MULTIPLE_CONFIG && ! DEM_SUPPORT_VARIANT_HANDLING && DEM_PREINIT_HAS_CONFIG_PARAM */

  Dem_InitializationStatus = DEM_IsUninitialized;
  Dem_StorageState = 0x00;                /* permit event memory update for NO group of DTC, i.e. forbid the update */
  Dem_StatusUpdate = 0x00;                /* prohibit the usage of API Dem_(Re)SetEventStatus */
  Dem_RecordUpdate = DEM_FORBID_EXISTENT_RECORD_UPDATE;
  /* prepare the Dem_ReportErrorStatus() buffer for BSW errors */
  Dem_ActionQueueUsed = 0;                /* queue is empty */
  Dem_ActionQueueRbFirst = 0;             /* ringbuffer starts at 1st index */
  Dem_AQSetAction( &Dem_FinishedClearDtcRequest, DEM_AQACTION_NONE);  /* no current diagnostic clear request */

  i = (uint16_least) DemCfg_GetMaxCountOfOperationCycle();
  while (i != 0)
  {
    i--;
    Dem_OperationCycleState[i] = DEM_CYCLE_STATE_END;     /* NO OperationCycle is currently running */
  }

  /* clear the internal DTC status values */
  for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
  {
    DEM_UNSET_FILTERED_DTC(EventId);                                                              /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
    DEM_UNSET_PRESTORED_EVENT(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
    DEM_UNSET_STORED_DTC(EventId);                                                                /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
  }

  Dem_CountOfFilteredDTCs = 0;

  /* initialize the cache of Dem_GetEventIdOfDTC() */
  Dem_CvtDtc2EventIdCacheDtc = DEM_DTCNUMBER_INVALID;

#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON)
  /* If the function Dem_InitDiagnosticVariant() was called, add the base variant. Else use base variant only. */
  if (Dem_VariantInitialized == DEM_IsEnabled)
  { /* add the here given base variant to already set variant(s), \see Dem_InitDiagnosticVariant() */
    Dem_ActiveVariant |= activeCfg->ConfigurationMask;                                            /* PRQA S 3198 *//* Additional initialization for careless user. */
  }
  else
  { /* use base variant, given as parameter to this function */
    Dem_VariantInitialized = DEM_IsEnabled;   /* variant is set, no more changeable */
    Dem_ActiveVariant = activeCfg->ConfigurationMask;                                             /* PRQA S 3198 *//* Additional initialization for careless user. */
  }
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_ActiveVariant == 0)
  { /* no configuration defined at all */
    Dem_DetReportError(DEM_PREINIT_APIID, DEM_E_PARAM_CONFIG );
  }
# endif /* DEM_DEV_ERROR_DETECT */
#endif  /* DEM_SUPPORT_VARIANT_HANDLING */

#if (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
  /* store the current configuration set */
  Dem_ActiveVariant = activeCfg->ConfigurationMask;
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_ActiveVariant != 0)
  { /* There is one or more configuration set */
    uint32 maskLowestOneBit = Dem_ActiveVariant & ~(Dem_ActiveVariant - 1);   /* get the least significant '1' bit from config set */
    if (maskLowestOneBit != Dem_ActiveVariant)
    { /* more than one configuration defined, choose lowest one */
      Dem_DetReportError(DEM_PREINIT_APIID, DEM_E_PARAM_DATA );
    }
    Dem_ActiveVariant = maskLowestOneBit;
  }
  else
  { /* no configuration defined at all, choose config 1 */
    Dem_DetReportError(DEM_PREINIT_APIID, DEM_E_PARAM_CONFIG );
    Dem_ActiveVariant = 0x00000001uL;
  }
# endif /* DEM_DEV_ERROR_DETECT */

#endif  /* DEM_SUPPORT_MULTIPLE_CONFIG */
}


/**********************************************************************************************************************
  Dem_Init
**********************************************************************************************************************/
/** Initialize the DEM after restoring the non volatile data.
 *  This function shall be used during the startup phase of the ECU after the NVRAM Manager has finished the
 *  restore of NVRAM data. SW-Components including Monitor Functions are initialized afterwards.
 * \note        SERVICE ID   0x02
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    ECU-SchM
 * \note        AUTOSAR R3.0 API
 * \attention   This function has more than one 'return' path - triggered in case of fatal errors!
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_Init(
  void
  )
{
  uint8_least           i;
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
  uint16_least          j;
#endif
  boolean               nvInitRequired = FALSE;

  /* Block all external interruption during execution of Init */
  Dem_InitializationStatus = DEM_IsUninitialized;

  /*
   * The startup sequence will be responsible that the NVRAM stored data is available for use,
   * when execution reaches this line.
   *
   * The startup sequence must copy the NV data to DEM's buffer(s). Currently supported buffers/NV-blocks are:
   * [0]:  VAR(Dem_NonVolatileDataType,      DEM_APPL_DATA)        Dem_NvData;
   * All used BufferIds must be configured in DEM, see array Dem_NvramBlockIdTable[]
   * 
   * If there was no valid, previous data to restore, you (or NvM) MUST intialize the buffer by calling
   * -  Dem_NvDataInit();             for buffer Dem_NvData
   * BEFORE calling Dem_Init().
   */

  /* check, if the NVRAM needs a very first initialization */
#if (DEM_ENABLE_PATTERN_CHECK == STD_ON)
  /* compare all bytes of NVRAM data consistencyPattern/terminatingPattern for exact match with original(End)Pattern definition */
  for (i = 0;
      (i < (uint8_least)DEM_NVDATA_PATTERN_SIZE) && (Dem_ConsistencyPatternPtr[i] == originalPattern[i]) && (Dem_TerminatingPatternPtr[i] == originalEndPattern[i]);
      ++i)
  { /* this for-loop will abort, if any pattern byte is different */
    /* empty loop body */
  }
  if (i != (uint8_least)DEM_NVDATA_PATTERN_SIZE)
  { /* the pattern was different */
      nvInitRequired = TRUE;          /* we must initialize our RAM mirror */
  }
#endif

  /* Check for equal size of EventId datatype in static code and generated code.
   * A link-time check is not possible here, as the type is created by RTE and not by DEM generator */
  if ((uint8) sizeof(Dem_EventIdType) != Dem_SizeofEventIdType)
  {
    /* invalid config: Dem_PBCfg.c was compiled with different size for type Dem_EventIdType (typedef'd by RTE) */
#if ((!defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )) || ( DEM_CRC_CHECK == STD_ON ))
    EcuM_GeneratorCompatibilityError((uint16) DEM_MODULE_ID, (uint8) DEM_INSTANCE_ID);
#else
# if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_INIT_APIID, DEM_E_PARAM_CONFIG );
# endif
#endif
    /* leave the DEM in state Dem_InitializationStatus = DEM_IsUninitialized;
    *  to protect the ECU from further harm resulting from an invalid DEM PostBuild config */
    return;
  }
#if (DEM_CONFIG_VARIANT == 2) || (DEM_CONFIG_VARIANT == 3)
  /* check for correct written LinkTime/PostBuild data:
   * the PostBuild structure must begin with 0xDE<majorVers><minorVers><dontCare> and end with 0xDEDEDEDE
   */
  if ( ((Dem_PBConfig.Dem_PBCfgLeader & 0xFFFFFF00uL) != (0xDE000000uL + (((uint32) DIAG_ASRDEM_VERSION)<<8)))
    || ( Dem_PBConfig.Dem_PBCfgTrailer != 0xDEDEDEDEuL))
  {
    /* invalid config: Dem_PBCfg.c was generated for a different DEM version */
# if ((!defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )) || ( DEM_CRC_CHECK == STD_ON ))
    EcuM_GeneratorCompatibilityError((uint16) DEM_MODULE_ID, (uint8) DEM_INSTANCE_ID);
# else
#  if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_INIT_APIID, DEM_E_PARAM_DATA );
#  endif
# endif
    /* leave the DEM in state Dem_InitializationStatus = DEM_IsUninitialized;
    *  to protect the ECU from further harm resulting from an invalid DEM PostBuild config */
    return;
  }
# if ( DEM_CRC_CHECK == STD_ON )
  /* LinkTime check for invariant PreCompile values */
  if (Dem_PBConfig.PreCompileCRC != DEM_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) DEM_MODULE_ID, (uint8) DEM_INSTANCE_ID);
    return;
  }
#  if (DEM_CONFIG_VARIANT == 3)
  /* PostBuild check for invariant LinkTime values */
  if ( Dem_PBConfig.LinkTimeCRC != Dem_LinktimeCRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) DEM_MODULE_ID, (uint8) DEM_INSTANCE_ID);
    return;
  }
#  endif  /* POST-BUILD */
# endif  /* DEM_CRC_CHECK */
#endif  /* LINK-TIME or POST-BUILD */

  /* check, if the NVRAM stored configuration is different to the current configuration */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
  if (Dem_ActiveVariant != *Dem_ActiveConfigPtr)
  { /* the existing NvData were stored with a different config, so they are worthless */
    nvInitRequired = TRUE;          /* we must initialize our RAM mirror */
  }
#endif  /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */

  if (nvInitRequired != FALSE)
  { /* initialization of NVRAM mirror buffer, as previous state was invalid */
    (void) Dem_NvDataInit();
  }

#if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
  {
    Dem_DtcChronoRefType  chronoIndex;
    /* set the internal 'stored' bit for all DTCs in chronostack */
    chronoIndex = *Dem_ChronoPriMemUsedPtr;
    while (chronoIndex > 0)
    {
      --chronoIndex;
      DEM_SET_STORED_DTC(Dem_GetEventIdOfEntry(chronoIndex));
    }
  }
#endif

  Dem_StorageState = DEM_DTC_GROUPKIND_ALL_DTCS;
  Dem_StatusUpdate = DEM_DTC_GROUPKIND_ALL_DTCS;
  Dem_RecordUpdate = DEM_PERMIT_EXISTENT_RECORD_UPDATE;
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
  /* Initialize Timer and Timer slots for Time Based De-bounce algorithm  */
  Dem_DebounceTimer = 1;  /* Timer value 0 is not valid */
  for( j = 0; j < Dem_NumberOfDebounceTimerSlots; j++)
  {
    Dem_DebounceTimerSlots[j] = 0;
  }
#endif

  /* activate the DTC storage - first task of MainFunction is to empty the BSW queue */
  Dem_InitializationStatus = DEM_IsEnabled;

  /* transferring the entries from the BSW ReportError queue to the standard buffer
     is done in the cyclic Dem_MainFunction(), as here and now all Dem_OperationCycleState
     are DEM_CYCLE_STATE_END, so no DTC would be set by Dem_SetEventStatus
  */
  
} /* PRQA S 2006 *//* MD_DEM_14.7 */


/**********************************************************************************************************************
  Dem_Shutdown
**********************************************************************************************************************/
/** Shutdown the DEM.
 *  This function is used to finalize all pending operations in the DEM to prepare the internal states and event
 *  data for transfer to the NVRAM.
 * \note        SERVICE ID   0x03
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    ECU-SchM
 * \note        AUTOSAR R3.0 API
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_Shutdown(
  void
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_SHUTDOWN_APIID, DEM_E_UNINIT);
  }
  else
#endif
  {
    /* de-activate the DTC storage */
    Dem_InitializationStatus = DEM_IsDisabled;
    Dem_StorageState = 0x00;                /* permit event memory update for NO group of DTC, i.e. forbid the update */
    Dem_StatusUpdate = 0x00;                /* prohibit the usage of API Dem_(Re)SetEventStatus */
    Dem_RecordUpdate = DEM_FORBID_EXISTENT_RECORD_UPDATE;

#if (DEM_USE_NVM == STD_ON)
    {
      uint8_least i;

      /* Trigger the NvM to store the modified data to NVRAM */
      for (i = 0; i < (uint8_least)Dem_NvramBlockIdCount; ++i )
      {
        NvM_SetRamBlockStatus(Dem_NvramBlockIdTable[i], TRUE);
      }
      /* The system shutdown sequence now will save the data by calling NvM_WriteAll() */
    }
#endif
  }
}


/**********************************************************************************************************************
  Dem_AddNewDTCtoChronoStack
**********************************************************************************************************************/
/** Add DTC entry to the ChronoStack/PrimaryMemory.
 * \return      Std_ReturnType
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function Dem_DoSetEventStatus()
 * \param[in]   EventId   event that shall be stored
 * \retval      E_OK      success
 * \retval      E_NOT_OK  failure
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AddNewDTCtoChronoStack(
  Dem_EventIdType   EventId
  )
{
  /* Dem_DtcChronoRefType (chronoIndex) is 16bit in the case stackSize > 254 entries */
  /* Set index to the oldest element of the stack */
  Dem_DtcChronoRefType chronoIndex = 0;

  Std_ReturnType success = E_NOT_OK;

  /* check all conditions that prevent the adding to the PriMem
   * the final 'else' will be executed only, if the adding is possible and permitted */
  if (DemCfg_GetDtcSuppressFlag(EventId) != FALSE)
  { /* no, this event is configured for never being in the PriMem */
    /* success = E_NOT_OK;  is already set */
  }
  else if ((Dem_StorageState & DemCfg_GetDTCGroupKind(EventId)) == 0)     /* see Dem_DisableDTCStorage() */
  {
    /* The storage of DTCs in the event memory is disabled (for the DTC Group, this event belongs to) */
    /* success = E_NOT_OK;  is already set */
  }
  else
  { /* (try to) allocate a primary memory event slot */
    if (*Dem_ChronoPriMemUsedPtr == DemCfg_GetMaxCountOfPriMemStack())
    { /* Chrono-stack is full - check if we are permitted to delete DTCs there */
      if (Dem_RecordUpdate != DEM_FORBID_EXISTENT_RECORD_UPDATE)
      { /* we may delete existing DTCs */
        Dem_EventIdType sfn;
        Dem_DtcChronoRefType  lowestPriorEntry;
        Dem_EventPriorityType storedPriority, lowestPriority;
        /* find lowest prior DTC in PrimaryMemory (by scanning first elements of ChronoPriMem) */
        /* assume: first one is lowest prior DTC - then check if this assumption is correct */
        lowestPriorEntry = 0;
        lowestPriority = DemCfg_GetEventPriority(Dem_GetEventIdOfEntry(lowestPriorEntry));
        /* Start searching the lowest priority beginning at the oldest entry */
        for (chronoIndex=1; chronoIndex < DemCfg_GetMaxCountOfPriMemStack(); ++chronoIndex)
        {
          storedPriority = DemCfg_GetEventPriority(Dem_GetEventIdOfEntry(chronoIndex));
          if (storedPriority > lowestPriority)
          { /* priority of current chronostack element is lower (=higher number) than priority of "best" entry: update assumption */
            lowestPriority   = storedPriority;
            lowestPriorEntry = chronoIndex;
          }
        }
        /* now compare, if new DTC has higher priority than found (lowest) entry in chronostack */
        storedPriority = DemCfg_GetEventPriority(EventId);
        if (storedPriority <= lowestPriority)
        { /* new event has higher priority (=lower number) or equal priority than lowest event priority in chronostack */
          chronoIndex = lowestPriorEntry;                     /* mark lowest prior event for displacing */
        }
        else
        { /* new event has lower priority (=higher number) than all existing events in chronostack */
          /* chronoIndex = DemCfg_GetMaxCountOfPriMemStack(); */ /* no event detected to displace */
        }

        /* check if a discardable DTC was found */
        if (chronoIndex < DemCfg_GetMaxCountOfPriMemStack())
        { /* a deletable DTC is found, now remove that DTC */
          boolean               isStatusUnchanged;
          Dem_DtcStatusByteType lDtcStatusByte;

          /* make a local copy of current status byte to check (later) for status change */
          sfn = Dem_GetEventIdOfEntry(chronoIndex);
          lDtcStatusByte = Dem_DtcStatusBytePtr[sfn];

          /* displace the existing DTC from chronostack to allow the new DTC to be stored */
          Dem_DeleteDTCinChronoStack(chronoIndex);
          /* Update the status bits */
          DEM_UNSET_BIT_CONFIRMED_DTC(sfn);                                                       /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
          /* discarding the DTC is NOT 'ClearDiagnosticInformation AND NOT LatchedFailsafe' */
          /* DEM_UNSET_BIT_WARNING_INDICATOR_REQ(EventId); */
#endif


          /* check if DTC status changed by last line of code */
          isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[sfn]);
          if (FALSE == isStatusUnchanged)
          { /* there is a change - notify application about deleted DTC */
            Dem_TriggerOnEvent(sfn, lDtcStatusByte);
          }

          /* call related Xxx_DemInitMonitor{EventId}(CLEAR) function */
          if (!! DemCfg_GetInitMonitorFPtr(sfn))                                                  /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
          {
            (void)(*DemCfg_GetInitMonitorFPtr(sfn))(DEM_INIT_MONITOR_CLEAR);
          }

          /* existing DTC was deleted, we can use its slot in PriMem to store the new DTC */
          success = E_OK;
        }
        else
        { /* no adequate DTC found */
          /* success = E_NOT_OK;  is already set */
        }
      }
      else
      { /* deleting of DTCs is prohibited */
        /* success = E_NOT_OK;  is already set */
      }
    }
    else
    { /* Chrono-stack is not full */
      success = E_OK;
    }
  }

  if ((success == E_OK)                                                                           /* PRQA S 3415 *//* MD_DEM_12.4 */
        /* Due to MISRA a second check is necessary: */
     && (chronoIndex < DemCfg_GetMaxCountOfPriMemStack())
     )
  {
    /* set chronoIndex to the first free element */
    chronoIndex = *Dem_ChronoPriMemUsedPtr;

    /* Write new EventId number */
    Dem_SetEventIdOfEntry(chronoIndex, EventId);
    /* Fill the Snapshot/FreezeFrame record */
    Dem_UpdateUserdataRecord_First(EventId, Dem_GetPriMemIndexFromChronoIndex(chronoIndex));

    /* Update the global history with FirstConfirmed/MostRecent confirmed event */
    if (*Dem_FirstConfirmedEventIdPtr == 0)
    { /* not set yet */
      *Dem_FirstConfirmedEventIdPtr = EventId;
    }
    *Dem_MostRecentConfmdEventIdPtr = EventId;
    
    /* Event is stored in PrimaryMemory */
    DEM_SET_BIT_CONFIRMED_DTC(EventId);

    ++(*Dem_ChronoPriMemUsedPtr);
  }
  /* else: chronostack/PrimaryMemory is full but we are not allowed to delete an existing DTC there.
           Thus the new event will not be stored.  'success' is E_NOT_OK */
  return success;
}

/**********************************************************************************************************************
  Dem_UpdateUserdataRecord_First
**********************************************************************************************************************/
/** Write first snapshot record in the PrimaryMemory.
 *  Write the first occurred freezeframe/snapshot record and update the extended data record(s) (if necessary)
 *  'stackElementRef' always addresses buffer directly, never uses chronological indirection (even if available).
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function Dem_AddNewDTCtoChronoStack()
 * \param[in]   EventId           event that shall be updated
 * \param[in]   stackElementRef   reference (index) to the element of the stack
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateUserdataRecord_First(
  Dem_EventIdType       EventId,
  Dem_DtcChronoRefType  stackElementRef
  )
{
  /* set count of filled snapshots */
  {
    P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) usedCounter;                                         /* PRQA S 0850 *//* MD_MSR_19.8 */
    usedCounter = Dem_GetPrimaryStackBufferPtr(stackElementRef);
    usedCounter = &usedCounter[Dem_PriMemSnapshotUsedCntOffset()];              /*  MISRA improvement for: usedCounter += Dem_PriMemSnapshotUsedCntOffset() */
    if (DemCfg_GetCountOfSnapshotRecNumbers(EventId) == 0)
    {
      *usedCounter = 0u;  /* event does not use snapshots */
    }
    else
    {
      *usedCounter = 1u;  /* set count of filled snapshots := 1 */
    }
  }

  /* fill the first snapshot */
  Dem_UpdateUserdataRecord(EventId, stackElementRef, 0, 0);
}


/**********************************************************************************************************************
  Dem_GetMostRecentSnapshotIndex
**********************************************************************************************************************/
/** Find index of MostRecent snapshot for to write/overwrite in existing SnapShot/Freezeframe instance.
 *  Find SnapShot/Freezeframe instance to write/to overwrite in an existing Chrono-stack entry and return it's
 *  index as result. If there are unused snapshot records left, the next unused record will be used. If all available
 *  snapshot records are already in use, the last record is returned.
 *  If the element would be overwritten, return *'isUnused' := FALSE,
 *  if the element is currently empty, return *'isUnused' := TRUE
 *     and increment the internal elements-used counter.
 * \return      Index of snapshot record and flag to signal, that record is in use (will be overwritten) or not.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function Dem_UpdateUserdataRecord_Recent()
 * \param[in]   stackElementRef   reference (index) to the element of the stack
 * \param[out]  isUnused          'TRUE' if there was an unused snapshot record,
 *                                'FALSE' if one existing snapshot record will be overwritten.
 * \attention   The function will increment the internal number-of-used-snapshots counter of that stack element,
 *              if flag isUnused==TRUE is returned.
 * \pre         Use inside critical section, only. Or assure data consistency by other means.
 * \post        Leave function inside critical section.
 *********************************************************************************************************************/
STATIC FUNC(uint8, DEM_CODE)                                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetMostRecentSnapshotIndex(
  Dem_DtcChronoRefType                   stackElementRef,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC)   isUnused                                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) usedCounter;                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  uint8 indexToWrite;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (stackElementRef >= DemCfg_GetMaxCountOfPriMemStack())
  {
    Dem_DetReportError(DEM_GETMOSTRECENTSNAPSHOTINDEX_APIID, DEM_E_INV_CSTACK_REF );
    indexToWrite = 0;  
  }
  else
#endif
  {
    usedCounter = Dem_GetPrimaryStackBufferPtr(stackElementRef);
    usedCounter = &usedCounter[Dem_PriMemSnapshotUsedCntOffset()];            /* MISRA improvement for: usedCounter += Dem_PriMemSnapshotUsedCntOffset() */
    if (*usedCounter < DemCfg_GetCountOfSnapshotsPerDTC())
    { /* position to write: append new entry at end */
      indexToWrite = *usedCounter;
      ++(*usedCounter);                                                       /* increment counter for number-of-used-snapshots */
      *isUnused = TRUE;
    }
    else
    { /* position to write: overwrite last element */
      indexToWrite = (uint8)(DemCfg_GetCountOfSnapshotsPerDTC() - 1);
      *isUnused = FALSE;
    }
  }
  return indexToWrite;
}


/**********************************************************************************************************************
  Dem_UpdateUserdataRecord_Recent
**********************************************************************************************************************/
/** Update snapshot record in the Chrono-stack (PrimaryMemory).
 *  Write (one) most recent freezeframe/snapshot record and update the extended data record(s) (if necessary)
 *  'stackElementRef' always addresses buffer directly, never uses chronological indirection.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    no
 * \note        CALLED BY    Internal from function Dem_UpdateDTCinPriM_NotAct2Act()
 * \param[in]   EventId           event that shall be updated
 * \param[in]   stackElementRef   reference (index) to the element of the stack
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateUserdataRecord_Recent(
  Dem_EventIdType       EventId,
  Dem_DtcChronoRefType  stackElementRef
  )
{
  uint8   indexToWrite = 0;
  boolean isNewEntry;

  if (DemCfg_GetCountOfSnapshotRecNumbers(EventId) > 0)
  { /* the record uses snapshots */
    /* find record index to write */
    indexToWrite = Dem_GetMostRecentSnapshotIndex(stackElementRef, &isNewEntry);

    if ( (isNewEntry == FALSE)                                                                      /* PRQA S 3415 *//* MD_DEM_12.4 */
      && (indexToWrite > DemCfg_Get1stOverwrtSnapshotIndex()) )
    { /* before overwriting the last index, we must shift the previous ones */
      P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) eventEntry;                                          /* PRQA S 0850 *//* MD_MSR_19.8 */
      eventEntry = Dem_GetPrimaryStackBufferPtr(stackElementRef);
      Dem_MemMove(&eventEntry[Dem_PriMemSnapshot1stRecentOffset()],
        &eventEntry[Dem_PriMemSnapshot1stRecentOffset() + DemCfg_GetMaxSnapshotRecordSize()],
        DemCfg_GetMaxSnapshotRecordSize() * (indexToWrite-DemCfg_Get1stOverwrtSnapshotIndex()));
    }
    /* else: just append a snapshot or only 1 most recent record;
    usage counter is already incremented - so nothing to do here */
  }

  /* now write the new snapshot */
  Dem_UpdateUserdataRecord(EventId, stackElementRef, indexToWrite, 1);
}


/**********************************************************************************************************************
  Dem_UpdateSnapshotRecord
**********************************************************************************************************************/
/** (Over-)write snapshot/freezeframe record in the PrimaryMemory stack.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function
 *                                    Dem_UpdateUserdataRecord()
 *                                    Dem_PrestoreFreezeFrame()
 * \param[in]   EventId               event that shall be stored
 * \param[out]  BufferPtr             buffer, where the requested data is copied to
 * \pre         Use inside critical section, only. Or assure data consistency by other means.
 * \post        Leave function inside critical section.
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateSnapshotRecord(
  Dem_EventIdType                           EventId,
  P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA )  BufferPtr                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  uint16 SsRecIdx;                        /* index to Dem_SnapshotEntryTable[] */
  uint8  SsRecCount;                      /* number of DIDs for current EventId */
  uint8  SsRecDataSize;                   /* size of current DID's data value */
  uint16 SsRecBufIdx;                     /* offset in buffer */


  SsRecBufIdx = 0;

  SsRecIdx   = DemCfg_GetFirstSnapshot(EventId);                    /* first relevant index in Dem_SnapshotDataIDTable[] */
  SsRecCount = DemCfg_GetCountOfSnapshotDIDs(EventId);              /* DID count for this event ID */

  while (SsRecCount != 0)
  { /* iterate over all configured DIDs of this event */
    --SsRecCount;
    SsRecDataSize = DemCfg_GetSnapshotDIDDataSize(SsRecIdx);        /* data record size used for this DID */

    /* Check, if enough space is available in the Snapshot Data section */
    if ((SsRecBufIdx + SsRecDataSize) <= DemCfg_GetMaxSnapshotRecordSize())
    {
      Std_ReturnType result = E_NOT_OK;
      uint16_least i = 0;
      while (Dem_DIDLookupTable[i].did != DEM_DIDTABLE_END_OF_TABLE)
      { /* find correct function for given DID */
        if (DemCfg_GetSnapshotDID(SsRecIdx) == Dem_DIDLookupTable[i].did)
        { /* call the configured function Xxx_DemGetDataValueByDataIdentifier{DataId}() to fill this DID's data record */
          /* DataID is no argument any more in R3.0 */
          
		  CDD_DemIdSnapshot_Cnt_G_u08 = EventId; /* NEXTEER MANUAL EDIT - Dem snapshot data (DID D40A) */
		  
		  result = (Dem_DIDLookupTable[i].pFunc) ( (P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA)) BufferPtr);             /* PRQA S 0310, 0308, 0850, 3651 *//* MD_DEM_11.4, MD_DEM_3.1_0308, MD_MSR_19.8, MD_DEM_3651 */
          break;
        }
        ++i;
      }
      SsRecBufIdx = SsRecBufIdx + SsRecDataSize;
      if  (result == E_OK)
      {
        BufferPtr = &BufferPtr[SsRecDataSize];                      /*  MISRA improvement for: BufferPtr += SsRecDataSize; */
      }
      else
      {
        /* error getting data record -> we fill the Buffer with a default value: DEM_MISSING_DATA_PADDING_VALUE */
        while (SsRecDataSize != 0)
        {
          *BufferPtr = DEM_MISSING_DATA_PADDING_VALUE;
          BufferPtr = &BufferPtr[1];                                /*  MISRA improvement for: ++BufferPtr; */
          --SsRecDataSize;
        }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        Dem_DetReportError(DEM_XXX_GETDATAVALUEBYDATAIDENTIFIER_APIID, DEM_E_NODATAAVAILABLE);
#endif
      }
      ++SsRecIdx;
    }
    else
    { /* not enough space left? just abort */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
      /* configuration problem with PostBuild data: the sum of single DID records' data is larger than 
      * the total reserved space for the whole Snapshot/FreezeFrame data record buffer */
      Dem_DetReportError(DEM_UPDATESNAPSHOTRECORD_APIID, DEM_E_PARAM_CONFIG);
#endif
      break;
    }
  }

}

/**********************************************************************************************************************
  Dem_UpdateExtendedRecord
**********************************************************************************************************************/
/** (Over-)write extended data record in the PrimaryMemory stack.
 *  Request the update of the extended data record(s) from application.
 *  By the value of argument 'UpdateMode' the caller decides, which extended records shall be updated:
 *-   0: Event is added to PrimaryMemory. 'BufferPtr' is PriMem-record
 *-   1: Event is updated in PrimaryMemory (resp. store additional FreezeFrame/Snapshot). 'BufferPtr' is PriMem-record
 *  .
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function Dem_UpdateUserdataRecord()
 * \param[in]   EventId               event that shall be stored
 * \param[out]  BufferPtr             buffer, where the requested data is copied to. If NULL_PTR, the configured
 *                                    location in the PrimaryMemory buffer will be used.
 * \param[in]   UpdateMode            reason for updating the Ext.Records of the event
 * \pre         Use inside critical section, only. Or assure data consistency by other means.
 * \post        Leave function inside critical section.
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateExtendedRecord(
  Dem_EventIdType                           EventId,
  P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA )  BufferPtr,                                            /* PRQA S 0850 *//* MD_MSR_19.8 */
  uint8                                     UpdateMode
  )
{
  uint16_least numberOfExtDataRecords = (uint16_least) DemCfg_GetCountOfCurrentExtendedRecord(EventId);

  if (numberOfExtDataRecords > 0)
  {
    Std_ReturnType result = E_OK;                                   /* initialization redundant, just to avoid compiler warnings */
    Dem_DataRecordSizeType sizeExtDataRecord;
    uint16_least extRecIdx;
    P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA )  recordBufferPtr;      /* buffer pointer for individual records */  /* PRQA S 0850 *//* MD_MSR_19.8 */

    /* address the Record attributes in Dem_ExtDataRecordTable[] */
    extRecIdx = (uint16_least) DemCfg_GetFirstExtendedRecord(EventId);
    /* set 'numberOfExtDataRecords' to last+1 index */
    numberOfExtDataRecords = numberOfExtDataRecords + extRecIdx;

    for ( ; extRecIdx < numberOfExtDataRecords; ++extRecIdx)
    { /* for all ext. data records, that were defined for this event */
      sizeExtDataRecord = (Dem_DataRecordSizeType) DemCfg_GetExtendedRecordNumberDataSize(extRecIdx);
      recordBufferPtr = BufferPtr;

#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
      /* ignore records that are not stored in the PrimaryMemory, but stored globally */
      if (Dem_OccurrenceCtr_ExtDataRecNum == DemCfg_GetExtendedRecordNumber(extRecIdx))
      {
        continue;                                                                                 /* PRQA S 0770 *//* MD_DEM_14.5 */
      }

#endif
      if ((UpdateMode == 0) || (UpdateMode == 1))                   /* update (testFailed 0->1, ConfirmedDTC x->1) */
      {
        /* call the function to fill in the value(s) for this ExtDataRecord number */
        /* the record number is no argument any more in R3.0: DemCfg_GetExtendedRecordNumber(extRecIdx) */
        result = (Dem_GetExtDataRecordListTable[DemCfg_GetExtendedRecordFuncRef(extRecIdx)]) ( (P2VAR(Dem_MaxExtendedDataRecordType, AUTOMATIC, DEM_APPL_DATA)) recordBufferPtr);     /* PRQA S 0310, 0308, 0850, 3651 *//* MD_DEM_11.4, MD_DEM_3.1_0308, MD_MSR_19.8, MD_DEM_3651 */
        /* advance the BufferPtr for writing the next extended record (later) */
        /* recordBufferPtr keeps the current buffer start, to fill a default value in case of result==E_NOT_OK */ 
        BufferPtr = &BufferPtr[sizeExtDataRecord];
      }

      /* if the callback returned E_NOT_OK, we fill the Buffer with a default value: DEM_MISSING_DATA_PADDING_VALUE */
      if (E_NOT_OK == result)
      { /* error with getting extended data record */
        for ( ; sizeExtDataRecord > 0;  --sizeExtDataRecord)
        { /* fill the missing Data with the padding value 0xFF */
          *recordBufferPtr = DEM_MISSING_DATA_PADDING_VALUE;
          recordBufferPtr = &recordBufferPtr[1];                    /* this is MISRA for ++recordBufferPtr; */
        }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        Dem_DetReportError(DEM_XXX_GETEXTENDEDDATARECORD_APIID, DEM_E_NODATAAVAILABLE);
#endif
      }
    } /* for all ext. data records, that were defined for this event */

  }
  /* else: no extended data record defined for this event */
}

/**********************************************************************************************************************
  Dem_UpdateUserdataRecord
**********************************************************************************************************************/
/** (Over-)write snapshot and extended data record in the PrimaryMemory stack.
 *  The function is called, when an event is either put into the PrimaryMemory for the first time, or when the
 *  data in the freezeframe/snapshot and extended data record shall be updated.
 *  By the value of argument 'UpdateMode' the caller describes, which extended records shall be updated:
 *-  0 - Event is added to PrimaryMemory. 'BufferPtr' is PriMem-record
 *-  1 - Event is updated in PrimaryMemory (resp. store additional FreezeFrame/Snapshot). 'BufferPtr' is PriMem-record
 *  .
 *  \see Dem_UpdateExtendedRecord() for the update of the extended data records.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function
 *                                    Dem_UpdateUserdataRecord_First()
 *                                    Dem_UpdateUserdataRecord_Recent()
 * \param[in]   EventId               event that shall be stored
 * \param[in]   stackElementRef       reference (index) of element in the stack
 * \param[in]   SnapshotRecordNumber  n-th snapshot of the event, range 0...DemCfg_GetCountOfSnapshotsPerDTC()-1
 * \param[in]   UpdateMode            reason for updating the event
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateUserdataRecord(
  Dem_EventIdType       EventId,
  Dem_DtcChronoRefType  stackElementRef,
  uint8                 SnapshotRecordNumber,
  uint8                 UpdateMode
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (SnapshotRecordNumber >= DemCfg_GetCountOfSnapshotsPerDTC())
  {
    Dem_DetReportError(DEM_UPDATEUSERDATARECORD_APIID, DEM_E_INV_SNAPSHOT_NUM);
  }
  else
#endif
  {
    P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA )  bufferPtr;                                          /* PRQA S 0850 *//* MD_MSR_19.8 */

    /* update the snapshot/freezeframe record */
    /* get location of the snapshot record to write */
    bufferPtr = Dem_GetPrimaryStackBufferPtr(stackElementRef);
    bufferPtr = &bufferPtr[Dem_PriMemSnapshotRecordsOffset() + (DemCfg_GetMaxSnapshotRecordSize() * (uint16_least) SnapshotRecordNumber)];
    
    /* if prestored frame exists, use it */
    if (DEM_IS_SET_PRESTORED_EVENT(EventId) != FALSE)
    { /* we have a prestored data record. Use that record, don't collect current data via callbacks (RTE) */
      P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) prestoreBufPtr;                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
      /* get location of prestored freezeframe */
      prestoreBufPtr = &Dem_PreFFBuffer[DemCfg_PrestoreFFBufStartOffset(EventId)];
      /* copy data */
      Dem_MemMove(bufferPtr, prestoreBufPtr, DemCfg_PrestoreFFBufSize(EventId));
      DEM_UNSET_PRESTORED_EVENT(EventId);                                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
    }
    else
    { /* use current data by requesting it via RTE/application */
      Dem_UpdateSnapshotRecord(EventId, bufferPtr);
    }


    /* update the extended data records */
    bufferPtr = Dem_GetPrimaryStackBufferPtr(stackElementRef);
    bufferPtr = &bufferPtr[Dem_PriMemExtendedRecordOffset()];                 /*  MISRA improvement for: BufferPtr += Dem_PriMemExtendedRecordOffset(); */
    Dem_UpdateExtendedRecord(EventId, bufferPtr, UpdateMode);
  }

#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
  /* update the occurrence counter */
  if (Dem_DtcOccurrenceCounterPtr[EventId] < (uint8) 0xFFu)
  {
    ++(Dem_DtcOccurrenceCounterPtr[EventId]);
  }
#endif
}




/**********************************************************************************************************************
  Dem_UpdateDTCinPriM_NotAct2Act
**********************************************************************************************************************/
/** Update DTC stored in the PrimaryMemory for transition Not-Active to Active.
 *  The DTC will be updated in the Primary Memory from the Not-Active to the Active state. DTC status bits must be
 *  modified (updated) by caller of this function.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    No
 * \note        CALLED BY    Internal from function
 *                                    Dem_DoSetEventStatus()
 * \param[in]   EventId      event that shall be updated
 * \pre         The DTC must exist in the Primary Memory.
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_UpdateDTCinPriM_NotAct2Act(
  Dem_EventIdType   EventId
  )
{
  Dem_DtcChronoRefType chronoIndex;
  Dem_ChronoPriMemType chronoPriMemElement;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (EventId > DemCfg_GetMaxCountOfEventId())
  {
    Dem_DetReportError(DEM_UPDATEDTCINPRIM_NOTACT2ACT_APIID, DEM_E_INV_SFN);
  }
  else
#endif
  {
    /* search for the right element */
    chronoIndex = Dem_GetChronoManagerIndex(EventId);

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
    if (chronoIndex >= *Dem_ChronoPriMemUsedPtr)
    {
      Dem_DetReportError(DEM_UPDATEDTCINPRIM_NOTACT2ACT_APIID, DEM_E_DTC_NOT_FOUND);
    }
    else
  #endif
    {
      /* we found the right element, temporary save this reference */
      chronoPriMemElement = Dem_ChronoPriMemPtr[chronoIndex];
      /* go ahead in the chrono stack and move down all entries to set this DTC on the top */
      for (; chronoIndex < (Dem_DtcChronoRefType)(*Dem_ChronoPriMemUsedPtr-1); ++chronoIndex)
      {
        Dem_ChronoPriMemPtr[chronoIndex] = Dem_ChronoPriMemPtr[chronoIndex+1];
      }
      /* restore back the current DTC at end */
      Dem_ChronoPriMemPtr[chronoIndex] = chronoPriMemElement;

      Dem_UpdateUserdataRecord_Recent(EventId, chronoPriMemElement.ref);
    }
  }
}


/**********************************************************************************************************************
  Dem_DeleteDTCinChronoStack
**********************************************************************************************************************/
/** A Chrono-Stack element will be removed from the ChronoStack/PrimaryMemory.
 *  The argument (index) refers the element in the ChronoPriMem array (if DTCs are ordered chronological and such
 *  a structure is available, else it refers the element in the PrimaryMemory directly).
 *  DTC status bits are updated here!
 *  The related InitMonitor(DEM_INIT_MONITOR_CLEAR) is not called in this function.
 * \note        SYNC/ASYNC   Synchronous
 * \note        CALLED BY    Internal from function
 *                                    Dem_AddNewDTCtoChronoStack()
 *                                    Dem_DoSetOperationCycleState()
 *                                    Dem_ClearSingleEvent()
 * \param[in]   chronoIndex  reference (index) to stack element which shall be deleted
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DeleteDTCinChronoStack(
  Dem_DtcChronoRefType  chronoIndex
  )
{
  Dem_DtcChronoRefType i;

  Dem_ChronoPriMemType chronoPriMemElement;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (*Dem_ChronoPriMemUsedPtr == 0)
  { /* at least one entry must exist */
    Dem_DetReportError(DEM_DELETEDTCINCHRONOSTACK_APIID, DEM_E_ERASING_EMPTY_STACK);
  }
  else if (*Dem_ChronoPriMemUsedPtr > DemCfg_GetMaxCountOfPriMemStack())
  {
    Dem_DetReportError(DEM_DELETEDTCINCHRONOSTACK_APIID, DEM_E_INV_CSTACK_REF);
  }
  else
#endif
  {
#if (DEM_CONFIRMEDDTC_MEANS_STOREDDTC == STD_OFF)
    {
      Dem_EventIdType EventId = Dem_GetEventIdOfEntry(chronoIndex);
      DEM_UNSET_STORED_DTC(EventId);                                                              /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
    }
#endif  /* ! DEM_CONFIRMEDDTC_MEANS_STOREDDTC */

    /* Save the information from the given reference */
    chronoPriMemElement = Dem_ChronoPriMemPtr[chronoIndex];
    /* compact the stack and close the hole */
    for (i = chronoIndex; i < (Dem_DtcChronoRefType)(*Dem_ChronoPriMemUsedPtr-1); ++i)    /* Harmless cast since the assertion checks for non zero size */
    {
      Dem_ChronoPriMemPtr[i] = Dem_ChronoPriMemPtr[i+1];
    }
    /* Restore the saved reference - to keep the references into ChronoStack consistent */
    Dem_ChronoPriMemPtr[i] = chronoPriMemElement;
    /* reduce count of used elements in the chrono stack */
    --(*Dem_ChronoPriMemUsedPtr);
  }
}


/**********************************************************************************************************************
  Dem_MapStatusByteTypeToMaskType
**********************************************************************************************************************/
/** Convert the internal used status byte to the external form of Dem_DTCStatusMaskType.
 *  The function considers the optional status bits and sets those bits to zero, that aren't supported by the DEM.
 *  This mapping is needed for the API functions towards the DCM and in xxx_TriggerOnDTCStatus
 * \return      DTC status in the external form as type Dem_DTCStatusMaskType
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from  function
 *                                    Dem_SetDTCFilter()
 *                                    Dem_GetStatusOfDTC()
 *                                    Dem_GetNextFilteredDTC()
 *                                    Dem_GetNextFilteredDTCAndSeverity()
 *                                    Dem_TriggerOnEvent()
 * \param[in]   internalStatus      event status in internal form of type Dem_DtcStatusByteType
 * \note        For the mapping from (Dem_DtcStatusByteType) to (Dem_EventStatusExtendedType) see the macro
 *              Dem_MapStatusByteTypeToExtType()
 *********************************************************************************************************************/
STATIC FUNC(Dem_DTCStatusMaskType, DEM_CODE)                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_MapStatusByteTypeToMaskType(
  const Dem_DtcStatusByteType   internalStatus
  )
{
  return (Dem_DTCStatusMaskType) (internalStatus & Dem_StatusAvailabilityMask
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_OFF)
    /* if the PendingDTC bit is internally not supported, we will set it to zero (0) [~0x04=0xFB]*/
    & 0xFBu
#endif
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_OFF)
    /* if the WarningIndicator bit is internally not supported, we will set it to zero (0) [~0x80=0x7F]*/
    & 0x7Fu
#endif
    );
}



#if (DEM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Dem_GetVersionInfo
**********************************************************************************************************************/
/** Get the version of the Dem (Version numbers are BCD coded!).
 *  This service returns the version information of this module. The version information includes:
 *  - Module Id = 30    (Vector Informatik GmbH)
 *  - Vendor Id = 54    (DEM)
 *  - Vendor specific version numbers (BSW00407)
 *  .
 *  This function shall be pre compile time configurable On/Off by the configuration parameter: DEM_VERSION_INFO_API
 * \return      Version information
 * \note        SERVICE ID   0x00
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    "Other"
 * \note        AUTOSAR R3.0 API
 * \param[out]  versioninfo   Pointer to where to store the version information of this module.
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA)  versioninfo                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
# if ( (STD_TYPES_AR_MAJOR_VERSION < 1) \
   ||((STD_TYPES_AR_MAJOR_VERSION == 1) && (STD_TYPES_AR_MINOR_VERSION < 2)) \
   ||((STD_TYPES_AR_MAJOR_VERSION == 1) && (STD_TYPES_AR_MINOR_VERSION == 2) && (STD_TYPES_AR_PATCH_VERSION < 0)) )
/* For Std_VersionInfoType we require at least the structure defined in document AUTOSAR_SWS_StandardTypes.pdf version 1.2.0
 * that is part of AUTOSAR release 3.0 and contains the element 'instanceID' in front of element 'sw_major_version' */
#error "Dem.c: requires minimum AUTOSAR version of \"Std_Types.h\" v1.2.0 (Part of AUTOSAR R3.0)" 
# endif  /* STD_TYPES VERSION 1.2.0 */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETVERSIONINFO_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
# endif  /* DEM_DEV_ERROR_DETECT */
  {
    versioninfo->vendorID   = DEM_VENDOR_ID;
    versioninfo->moduleID   = DEM_MODULE_ID;
    versioninfo->instanceID = DEM_INSTANCE_ID;
    versioninfo->sw_major_version = DEM_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = DEM_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = DEM_SW_PATCH_VERSION;
  }
}
#endif  /* DEM_VERSION_INFO_API */


/**********************************************************************************************************************
  Dem_ResetEventStatus
**********************************************************************************************************************/
/** Set status bit 'testFailed' to 0.
 *  This service shall be used to reset the Event Status stored in the Event Memory in the DEM, without the usage
 *  of API Dem_SetEventStatus(EventId, Passed), because no new test result is available at this time.
 *  With this API the status bit 'Failed' defined by Dem_EventStatusExtendedType is set to 0. API is called by
 *  Monitor Function.
 *  Refer to ISO14229: DTC Status Bit Definition, Table D.14, Bit0 Test failed.
 *  Dem_ResetEventStatus does not influence the status bit 6 ('testNotCompletedThisOperationCycle'). [ref. to Dem001]
 *  No API parameter checks required.
 * \attention   This API just sets a trigger to store the event, the actual storing is done later in Dem_MainFunction()
 *              by calling Dem_DoResetEventStatus()
 * \note        If the value of the status bit 'testFailed' changes, the configured OnEventChange callback will be
 *              triggered.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x05
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \retval      E_OK      reset of event status was successful
 * \retval      E_NOT_OK  reset of event status failed
 * \retval      DEM_E_QUEUE_OVERFLOW  set of event status failed, no space left in internal queue. Try again later.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ResetEventStatus(
  Dem_EventIdType   EventId
  )
{
  Std_ReturnType returnValue = E_NOT_OK;
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (! (Dem_IsInActiveVariant(EventId)))
      { /* event is not available in current variant */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        Dem_DetReportError(DEM_RESETEVENTSTATUS_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
#endif  /* DEM_DEV_ERROR_DETECT */
      }
      else
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      if ( (((Dem_StatusUpdate & DemCfg_GetDTCGroupKind(EventId)) != 0)            /* check !DisableEventStatusUpdate(DTCGroup) */      /* PRQA S 3415 *//* MD_DEM_12.4 */
        ||  ((DemCfg_GetDTCGroupKind(EventId) == 0) && (Dem_StatusUpdate != 0)))   /* or if internal event: check !DisableEventStatusUpdate(ALL) */
        )
      {
        Dem_AQElementType newElement;
        boolean successfulQueued;

        /* the ResetEventStatus is put to the queue, the queue will be drained later in Dem_MainFunction() */
        Dem_AQSetAction( &newElement, DEM_AQACTION_RESETEVENTSTATUS);                             /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
        Dem_AQSetEventId( &newElement, EventId );
        /* Append the new action to queue */
        /* Enter Critical ========================================================== */
        Dem_EnterCritical();
        successfulQueued = Dem_AQPush( &newElement );
        Dem_LeaveCritical();
        /* Leave Critical ========================================================== */

        if (!successfulQueued)
        {
          returnValue = DEM_E_QUEUE_OVERFLOW;
        }
        else
        {
          returnValue = E_OK;
        }
      }
      else
      {}                                                                                          /* satisfy MISRA-C:2004 Rule 14.10: requires else for if-else-if statements */
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  { /* DEM is not initialized */
    Dem_DetReportError(DEM_RESETEVENTSTATUS_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_DoResetEventStatus
**********************************************************************************************************************/
/** Execute ResetEventStatus tasks inside Dem_MainFunction().
 *  This service shall set status bit 'testFailed' to 0.
 *  No API parameter checks required.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x05
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    Internal from function Dem_MainFunction()
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \retval      E_OK      reset of event status was successful
 * \retval      E_NOT_OK  reset of event status failed
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoResetEventStatus(
  Dem_EventIdType   EventId
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ( ((Dem_StatusUpdate & DemCfg_GetDTCGroupKind(EventId)) != 0)            /* check !DisableEventStatusUpdate(DTCGroup) */      /* PRQA S 3415 *//* MD_DEM_12.4 */
    || ((DemCfg_GetDTCGroupKind(EventId) == 0) && (Dem_StatusUpdate != 0)))   /* or if internal event: check !DisableEventStatusUpdate(ALL) */
  {
    boolean               isStatusUnchanged;
    Dem_DtcStatusByteType lDtcStatusByte;

    /* make a local copy of current status byte to check (later) for status change */
    lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

    DEM_UNSET_BIT_TEST_FAILED(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */

    /* check if DTC status changed due above code */
    isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);

    if (FALSE == isStatusUnchanged)
    { /* there is a change - notify application */
      Dem_TriggerOnEvent(EventId, lDtcStatusByte);
    }
    returnValue = E_OK;
  }

  return returnValue;
}

/**********************************************************************************************************************
  Dem_PrestoreFreezeFrame
**********************************************************************************************************************/
/** Capture the FreezeFrame data for a specific EventId.
 *  This API call is used to capture the FreezeFrame data for a specific EventId before this event shall be stored 
 *  triggered by the Monitor Function reporting the event status DEM_EVENT_STATUS_PREFAILED to the DEM by calling 
 *  Dem_SetEventStatus() (e.g. rapid changing of environmental data during running failure monitoring phase).
 *  If the DEM does not receive any request to pre-store a FreezeFrame, FreezeFrame capture is linked to the API
 *  call Dem_SetEventStatus(). This API call triggers the FreezeFrame storage.
 *  If Dem_SetEventStatus(EventId, Failed) or Dem_SetEventStatus(EventId, Passed) is called the corresponding 
 *  pre-stored FreezeFrame is discarded (same behaviour like Dem_ClearPrestoredFreezeFrame()). The API call 
 *  Dem_ResetEventStatus() does not influence the pre-stored FreezeFrame.
 *  No API parameter checks are required.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x06
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \note        CONFIG       During configuration the DEM the capability of pre-store functionality for the required
 *                           event has to be defined.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \retval      E_OK      PreStoreFreezeFrame was successful
 * \retval      E_NOT_OK  PreStoreFreezeFrame failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_PrestoreFreezeFrame(
  Dem_EventIdType   EventId
  )
{
  Std_ReturnType  returnValue = E_NOT_OK;
  uint16  prestoreBufSize;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                                /* PRQA S 3415 *//* MD_DEM_12.4 */
  {
    Dem_DetReportError(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
  }
  else if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_UNINIT);
  }
  else
#endif
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
  if (! Dem_IsInActiveVariant(EventId))
  { /* event is not available in current variant */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
#endif  /* DEM_DEV_ERROR_DETECT */
  }
  else
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
  {
    prestoreBufSize = DemCfg_PrestoreFFBufSize(EventId);
    /* check if event is configured for prestore */
    if (prestoreBufSize > 0)
    {
      P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) prestoreBufPtr;                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
      prestoreBufPtr = &Dem_PreFFBuffer[DemCfg_PrestoreFFBufStartOffset(EventId)];

      /* fill the prestore buffer with data requested via callbacks (RTE) */
      Dem_UpdateSnapshotRecord(EventId, prestoreBufPtr);

      /* mark the event as prestored */
      DEM_SET_PRESTORED_EVENT(EventId);
      returnValue = E_OK;
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* Dem_PrestoreFreezeFrame was called for EventId, that is not configured for prestored FreezeFrames */
      Dem_DetReportError(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_PARAM_CONFIG);
    }
#endif
  }

  return returnValue;
}


/**********************************************************************************************************************
  Dem_ClearPrestoredFreezeFrame
**********************************************************************************************************************/
/** Delete or release the prestored FreezeFrame for specific EventId.
 *  The API shall be called to delete or release the prestored FreezeFrame for specific EventId. If the API
 *  Dem_SetEventStatus (passed|failed) is called it has the same effect - that means it's not necessary to call
 *  the API Dem_ClearPrestoredFreezeFrame directly after Dem_SetEventStatus.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x07
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \note        CONFIG       During integration in the DEM the capability of pre-store functionality for the
 *                           required event has to be defined.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \retval      E_OK      ClearPreStoreFreezeFrame was successful
 * \retval      E_NOT_OK  ClearPreStoreFreezeFrame failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearPrestoredFreezeFrame(
  Dem_EventIdType   EventId
  )
{
  Std_ReturnType  returnValue = E_NOT_OK;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                                /* PRQA S 3415 *//* MD_DEM_12.4 */
  {
    Dem_DetReportError(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
  }
  else if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_UNINIT);
  }
  else
#endif
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
  if (! Dem_IsInActiveVariant(EventId))
  { /* event is not available in current variant */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
#endif  /* DEM_DEV_ERROR_DETECT */
  }
  else
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
  /* check if event is configured for prestore */
  if (DemCfg_PrestoreFFBufSize(EventId) > 0)
  {
    DEM_UNSET_PRESTORED_EVENT(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
    returnValue = E_OK;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  { /* event is not configured for prestore */
    Dem_DetReportError(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_PARAM_CONFIG);
  }
#endif
  
  return returnValue;
}

/**********************************************************************************************************************
  Dem_SetOperationCycleState
**********************************************************************************************************************/
/** Change the state of an OperationCycle (i.e.\ START, END).
 *  DEM shall be called by the SW-Component as soon as it detects the status change of the CycleState for the
 *  Operation Cycle. This function can be called DEM internal for DEM self calculated operation cycles.
 * \attention   This API just sets a trigger to set the OperationCycle state, the actual changing is done later in 
 *              Dem_MainFunction() by calling Dem_DoSetOperationCycleState()
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x08
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \param[in]   OperationCycleId    Identification of operation cycle, like power cycle, driving cycle, ...
 * \param[in]   CycleState          uint8 (DEM_CYCLE_STATE_START, DEM_CYCLE_STATE_END)
 * \retval      E_OK                  set of operation cycle was successful
 * \retval      E_NOT_OK              set of operation cycle failed
 * \retval      DEM_E_QUEUE_OVERFLOW  set of operation cycle failed, no space left in internal queue. Try again later.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetOperationCycleState(
  Dem_OperationCycleIdType      OperationCycleId,
  Dem_OperationCycleStateType   CycleState
  )
{
  Std_ReturnType returnValue = E_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if (OperationCycleId >= DemCfg_GetMaxCountOfOperationCycle())
    {
      Dem_DetReportError(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_CONFIG);
      returnValue = E_NOT_OK;
    }
    else if ((CycleState != DEM_CYCLE_STATE_START) && (CycleState != DEM_CYCLE_STATE_END))
    {
      Dem_DetReportError(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_DATA);
      returnValue = E_NOT_OK;
    }
    else
#endif
    {
      Dem_AQElementType newElement;
      boolean successfulQueued;

      /* the SetOperationCycleState is put to the queue, the queue will be drained later in Dem_MainFunction() */
      Dem_AQSetAction( &newElement, DEM_AQACTION_SETOPCYCLE);                                     /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetOpCycleState( &newElement, CycleState );                                           /* PRQA S 3198 *//* We modify newElement.arg.opcycle.CycleState only once - Bug in PRQA analysis */
      Dem_AQSetOpCycleId( &newElement, OperationCycleId );
      /* Append the new action to queue */
      /* Enter Critical ========================================================== */
      Dem_EnterCritical();
      successfulQueued = Dem_AQPush( &newElement );
      Dem_LeaveCritical();
      /* Leave Critical ========================================================== */

      if (!successfulQueued)
      {
        returnValue = DEM_E_QUEUE_OVERFLOW;
      }
    }
  }
  else
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_UNINIT);
#endif
    returnValue = E_NOT_OK;
  }
  return returnValue;
}

/**********************************************************************************************************************
  Dem_DoSetOperationCycleState
**********************************************************************************************************************/
/** Execute SetOperationCycleState tasks inside Dem_MainFunction().
 *  This Service changes the Operation Cycle state, updates the counters, checks for ageing and triggers the
 *  callback functions that need to be called due the changes.
 *  API parameter checks (if applicable) already done by Dem_SetOperationCycleState().
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x08
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    Internal from function Dem_MainFunction()
 * \note        AUTOSAR R3.0 API
 * \param[in]   CycleId         Identification of operation cycle, like power cycle, driving cycle, ...
 * \param[in]   CycleState      uint8 (DEM_CYCLE_STATE_START, DEM_CYCLE_STATE_END)
 * \retval      E_OK      set of operation cycle was successful
 * \retval      E_NOT_OK  set of operation cycle failed
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoSetOperationCycleState(
  Dem_OperationCycleIdType      CycleId,
  Dem_OperationCycleStateType   CycleState
  )
{
  Std_ReturnType  returnValue = E_OK;

  Dem_OperationCycleState[CycleId] = CycleState;
  /* DEM_CYCLE_STATE_START or DEM_CYCLE_STATE_END */
  if (CycleState == DEM_CYCLE_STATE_START)
  {
    /* Start new cycle, reset the cycle related status flags */
    Dem_EventIdType  EventId;
    Dem_DtcChronoRefType  chronoIndex, priMemIndex;
    Dem_DtcStatusByteType  lDtcStatusByte;
    boolean  isStatusUnchanged;

    /* iterate over chrono stack and perform the aging */
    for (chronoIndex=0; chronoIndex<*Dem_ChronoPriMemUsedPtr; ++chronoIndex)
    {
      EventId = Dem_GetEventIdOfEntry(chronoIndex);

      if ((DemCfg_GetAgingCycleId(EventId) == CycleId)                                          /* PRQA S 3415 *//* MD_DEM_12.4 */
        && (DemCfg_GetIsAgingAllowed(EventId) != FALSE))
      { /* AgingCycleId is relevant for this CS-entry, and event uses self-healing/aging */
        /** Increment self-healing counter, if
        * - DTC is not in 'failed' but 'passed' state AND
        * - DTC was tested in the current *operation* cycle
        *   Note: if the aging cycle is equal the operation cycle, this event's operation cycle is the currently ending cycle;
        *         else this event's aging cycle is ending now but its operation cycle is ongoing and the 'tested-This-Operation-Cycle' state remains true.
        */
        if ( (DEM_IS_BIT_UNSET_TEST_FAILED(EventId) != FALSE)                                     /* PRQA S 3415 *//* MD_DEM_12.4 */
          && (DEM_IS_BIT_UNSET_TEST_N_COMPL_THIS_OC(EventId) != FALSE) )
        { /* DTC is 'passed' and 'tested this operation(!) cycle' */
          priMemIndex = Dem_GetPriMemIndexFromChronoIndex(chronoIndex);
          if (Dem_DtcAgingCounterPtr[priMemIndex] == DemCfg_GetNumberOfAgingCycles(EventId))
          { /* Selfheal/age this DTC */
            /* make a local copy of current status byte to check (later) for status change */
            lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

            /* Remove it from ChronoStack */
            Dem_DeleteDTCinChronoStack(chronoIndex);
            /* Update the status bits for ageing (part 1) */
            DEM_UNSET_BIT_CONFIRMED_DTC(EventId);                                                 /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
            DEM_UNSET_BIT_WARNING_INDICATOR_REQ(EventId);                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif

            /* check if DTC status changed since last lines of code */
            isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);
            if (FALSE == isStatusUnchanged)
            { /* there is a change - notify application */
              Dem_TriggerOnEvent(EventId, lDtcStatusByte);
            }

            /* call related Xxx_DemInitMonitor{EventId}(CLEAR) function */
            if (!! DemCfg_GetInitMonitorFPtr(EventId))                                            /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
            {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
              if (! (Dem_IsInActiveVariant(EventId)))
              { /* EventId is not defined for current configuration */
                Dem_DetReportError(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
              }
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
#endif  /* DEM_DEV_ERROR_DETECT */
              (void)(*DemCfg_GetInitMonitorFPtr(EventId))(DEM_INIT_MONITOR_CLEAR);
            }
          }
          else if (Dem_DtcAgingCounterPtr[priMemIndex] < 255)
          { /* Increment the Aging Counter */
            ++(Dem_DtcAgingCounterPtr[priMemIndex]);
          }
          else
          {}                                                                                      /* satisfy MISRA-C:2004 Rule 14.10: requires else for if-else-if statements */
        }
      }
    }
    /* iterate over all DTCs and update the status bits and call the Xxx_DemInitMonitor{EventId}() function */
    for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
    {
      if ( (DemCfg_GetOperationCycleId(EventId) == CycleId)                                       /* PRQA S 3415 *//* MD_DEM_12.4 */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
        && (Dem_IsInActiveVariant(EventId))
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
        )
      { /* CycleId is relevant for this 'EventId' */
        Dem_FaultDetectionCounterPtr[EventId] = 0;
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
        Dem_ClearDebounceTimerSlot(EventId);
#endif
        /* make a local copy of current status byte to check (later) for status change */
        lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

        /* Update the status bits for ageing (part 2) */
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_ON)
        /* pendingDTC preserves the last cycle's failed state */
        DEM_COPY_BIT_PENDING_DTC(EventId);                                                        /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
        DEM_UNSET_BIT_TEST_FAILED_THIS_OC(EventId);                                               /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
        DEM_SET_BIT_TEST_N_COMPL_THIS_OC(EventId);

        /* check if DTC status changed by above code */
        isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);

        if (FALSE == isStatusUnchanged)
        { /* there is a change - notify application */
          Dem_TriggerOnEvent(EventId, lDtcStatusByte);
        }

        /* call related Xxx_DemInitMonitor{EventId}(RESTART) function */
        if (!! DemCfg_GetInitMonitorFPtr(EventId))                                                /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
        {
          /* call related Xxx_DemInitMonitor{EventId}() function */
          (void)(*DemCfg_GetInitMonitorFPtr(EventId))(DEM_INIT_MONITOR_RESTART);
        }
      }
    }
  }
  else
  { /* DEM_CYCLE_STATE_END */
    /* End current cycle */
  }

  return returnValue;
}

/**********************************************************************************************************************
  Dem_SetEventStatus
**********************************************************************************************************************/
/** Service for reporting the Event Status to the DEM.
 *  This service shall be used to report an Event Status as soon a new test result is available.
 *  This Service stores the event to the Event Memory.
 *  API is called from the Monitor Function.
 *  No API parameter checks required.
 * \attention   This API just sets a trigger to store the event, the actual storing is done later in Dem_MainFunction()
 *              by calling Dem_DoSetEventStatus()
 * \attention   To store an event, the event's assigned operation cycle must be in State DEM_CYCLE_STATE_START else the
 *              event will be discarded!
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x04
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C (API is called from the Monitor Function)
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \param[in]   EventStatus  uint8 { DEM_EVENT_STATUS_PASSED, DEM_EVENT_STATUS_FAILED, DEM_EVENT_STATUS_PREPASSED,
 *                           DEM_EVENT_STATUS_PREFAILED [, Custom]}
 * \retval      E_OK                  set of event status was successful
 * \retval      E_NOT_OK              set of event status failed
 * \retval      DEM_E_QUEUE_OVERFLOW  set of event status failed, no space left in internal queue. Try again later.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetEventStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()) ||                            /* PRQA S 3415 *//* MD_DEM_12.4 */
      ( (EventStatus != DEM_EVENT_STATUS_PASSED)
      &&(EventStatus != DEM_EVENT_STATUS_FAILED)
      &&(EventStatus != DEM_EVENT_STATUS_PREPASSED)
      &&(EventStatus != DEM_EVENT_STATUS_PREFAILED) )
      )
    {
      Dem_DetReportError(DEM_SETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
#endif
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* this EventId is invalid in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_SETEVENTSTATUS_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
      /* ignore this event, returnValue := E_NOT_OK */
    }
    else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      Dem_AQElementType newElement;
      boolean successfulQueued;

      /* the SetEventStatus is put to the queue, the queue will be drained later in Dem_MainFunction() */
      Dem_AQSetAction( &newElement, DEM_AQACTION_SETEVENT);                                       /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetEventStatus( &newElement, EventStatus );                                           /* PRQA S 3198 *//* We modify newElement.arg.event.Status only once - Bug in PRQA analysis */
      Dem_AQSetEventId( &newElement, EventId );
      /* Append the new action to queue */
      /* Enter Critical ========================================================== */
      Dem_EnterCritical();
      successfulQueued = Dem_AQPush( &newElement );
      Dem_LeaveCritical();
      /* Leave Critical ========================================================== */

      if (!successfulQueued)
      {
        returnValue = DEM_E_QUEUE_OVERFLOW;
      }
      else
      {
        returnValue = E_OK;
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_SETEVENTSTATUS_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}


/**********************************************************************************************************************
  Dem_DoSetEventStatus
**********************************************************************************************************************/
/** Execute SetEventStatus tasks inside Dem_MainFunction().
 *  This Service stores the relevant Event data to the Event Memory.
 *  API parameter checks (if applicable) already done by Dem_SetEventStatus().
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x04
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 *                                    Dem_HandleTimeBasedDebounceEvents()
 * \note        AUTOSAR R3.0 API
 * \attention   DEM configuration during integration of Monitor Functions is system specific.
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \param[in]   EventStatus  uint8 { DEM_EVENT_STATUS_PASSED, DEM_EVENT_STATUS_FAILED, DEM_EVENT_STATUS_PREPASSED,
 *                           DEM_EVENT_STATUS_PREFAILED [, Custom]}
 * \retval      E_OK      trigger for set of event status was accepted
 * \retval      E_NOT_OK  event could not be stored
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoSetEventStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  )
{
  Std_ReturnType returnValue = E_OK;
  boolean        isStatusUnchanged;

  if ( (((Dem_StatusUpdate & DemCfg_GetDTCGroupKind(EventId)) != 0)            /* check !DisableEventStatusUpdate(DTCGroup) */      /* PRQA S 3415 *//* MD_DEM_12.4 */
    ||  ((DemCfg_GetDTCGroupKind(EventId) == 0) && (Dem_StatusUpdate != 0)))   /* or if internal event: check !DisableEventStatusUpdate(ALL) */
    && (Dem_OperationCycleState[DemCfg_GetOperationCycleId(EventId)] == DEM_CYCLE_STATE_START)    /* configured cycle is STARTed */
    )
  {
    Dem_DtcStatusByteType lDtcStatusByte;
    sint8                 newFDC;

    /* make a local copy of current status byte */
    lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

    /* special handling for PREPASSED and PREFAILED: they may trigger FAILED or PASSED afterwards */
    newFDC = Dem_CalcNewFaultDetectionCntr(EventId, &EventStatus);        /* 'EventStatus' may be modified */

    switch (EventStatus)
    {
    /** *** FAILED *** */
    case DEM_EVENT_STATUS_FAILED :
      /* is the DTC already stored ? */
      if (DEM_IS_UNSET_STORED_DTC(EventId) != FALSE)
      { /* not stored - may the DTC be stored in the Chrono-stack? */
        if (DemCfg_GetDtcSuppressFlag(EventId) == FALSE)
        { /* check enable conditions */
          Dem_DTCGroupKindType enable = (Dem_DTCGroupKindType)(Dem_StorageState & DemCfg_GetDTCGroupKind(EventId));
          if (enable != 0)
          { /* enable conditions are OK -> store DTC */
            returnValue = Dem_AddNewDTCtoChronoStack(EventId);
          }
        }
      }
      else
      { /* DTC is already stored - is it still active? */
        if (DEM_IS_BIT_UNSET_TEST_FAILED(EventId) != FALSE)
        { /* stored - not active */
          /* Do the EnableConditions permit the update of DTC in Chrono-Stack? */
          Dem_DTCGroupKindType enable = (Dem_DTCGroupKindType)(Dem_StorageState & DemCfg_GetDTCGroupKind(EventId));
          if ((enable != 0) && (Dem_RecordUpdate != DEM_FORBID_EXISTENT_RECORD_UPDATE))
          { /* enable conditions are OK and update is not blocked by DisableDTCRecordUpdate -> update DTC */
            Dem_UpdateDTCinPriM_NotAct2Act(EventId);
          }
        }
      }
      if (DEM_IS_BIT_SET_CONFIRMED_DTC(EventId) != FALSE)
      { /* Event is stored in PrimaryMemory - reset Aging Counter */
        Dem_DtcChronoRefType stackIndex = Dem_GetPriMemStackIndex(EventId);
      #if (DEM_DEV_ERROR_DETECT == STD_ON)
        if (stackIndex >= DemCfg_GetMaxCountOfPriMemStack())
        {
          Dem_DetReportError(DEM_SETEVENTSTATUS_APIID, DEM_E_DTC_NOT_FOUND);
        }
      #endif
      
        Dem_DtcAgingCounterPtr[stackIndex] = 0;
      }

      if (*Dem_FirstFailedEventIdPtr == 0)
      { /* not set yet */
        *Dem_FirstFailedEventIdPtr = EventId;
      }
      *Dem_MostRecentFailedEventIdPtr = EventId;

      DEM_SET_BIT_TEST_FAILED(EventId);
      DEM_SET_BIT_TEST_FAILED_THIS_OC(EventId);
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_ON)
      DEM_SET_BIT_PENDING_DTC(EventId);
#endif
      DEM_SET_BIT_TEST_FAILED_SINCE_LC(EventId);
      DEM_UNSET_BIT_TEST_N_COMPL_THIS_OC(EventId);                                          /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
      DEM_UNSET_BIT_TEST_N_COMPL_SINCE_LC(EventId);                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
      /* is Warning Indicator associated with DTC */
      if (DemCfg_GetDtcSupportWarningIndicator(EventId) != FALSE)
      { /* set Warning Indicator active */
        DEM_SET_BIT_WARNING_INDICATOR_REQ(EventId);
      }
#endif

      newFDC = 127;
      break;

    /** *** PASSED *** */
    case DEM_EVENT_STATUS_PASSED:
      DEM_UNSET_BIT_TEST_FAILED(EventId);                                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
      DEM_UNSET_BIT_TEST_N_COMPL_SINCE_LC(EventId);                                         /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
      DEM_UNSET_BIT_TEST_N_COMPL_THIS_OC(EventId);                                          /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
      /* is Warning Indicator associated with DTC  and  is not LatchedFailsafe ? */
      if ((DemCfg_GetDtcSupportWarningIndicator(EventId) != FALSE))
      { /* set Warning Indicator in-active */
        DEM_UNSET_BIT_WARNING_INDICATOR_REQ(EventId);                                             /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
      }
#endif

      newFDC = -128;
      break;

    case DEM_EVENT_STATUS_PREPASSED:
    case DEM_EVENT_STATUS_PREFAILED:
      break;

    default:
      break;
    }

    /* write the new Fault Detection Counter */
    Dem_FaultDetectionCounterPtr[EventId] = newFDC;

    /* check if DTC status was changed by above lines of code */
    isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);
    if (FALSE == isStatusUnchanged)
    { /* there is a change - notify application */
      Dem_TriggerOnEvent(EventId, lDtcStatusByte);
    }
  }
  /* else: something prevents the setting of the event, ignore this request */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_CalcNewFaultDetectionCntr
**********************************************************************************************************************/
/** Calculate Fault Detection Counter and map PREFAILED/PREPASSED to FAILED/PASSED when new FDC hits upper/lower limit.
 *  Recalculate the Fault Detection Counter (FDC) according given EventStatus, current FDC value and configured step
 *  size. When the new FDC reaches its upper or lower limit, a given EventStatus PREFAILED or PREPASSED is replaced
 *  by FAILED resp.\ PASSED.
 *  API parameter checks (if applicable) already done by Dem_DoSetEventStatus().
 * \return      sint8 (updated FaultDetectionCounter)
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_DoSetEventStatus()
 * \attention   The EventStatus is modified if PREFAILED or PREPASSED will result in new FDC value +127/-128.
 * \param[in]     EventId      Identification of an event by assigned EventId. The EventId is configured in the DEM.
 * \param[in,out] EventStatus  uint8 { DEM_EVENT_STATUS_PASSED, DEM_EVENT_STATUS_FAILED, DEM_EVENT_STATUS_PREPASSED,
 *                             DEM_EVENT_STATUS_PREFAILED [, Custom]}
 *********************************************************************************************************************/
STATIC FUNC(sint8, DEM_CODE)                                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_CalcNewFaultDetectionCntr(
  Dem_EventIdType EventId,
  P2VAR(Dem_EventStatusType, AUTOMATIC, AUTOMATIC) EventStatus                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  sint16_least fdCounter = Dem_FaultDetectionCounterPtr[EventId];

  /* Special handling for PREPASSED and PREFAILED: they may lead to FAILED or PASSED */
  /* The global Dem_FaultDetectionCounter is never adapted here, but the argument *EventStatus can be changed */
  if (*EventStatus == DEM_EVENT_STATUS_PREFAILED)
  {
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
    /* Check if EventId is handled via time based de-bounce algorithm */
    if (DemCfg_GetIsEventTimeBasedDebounce(EventId) != FALSE)
    {
      if (fdCounter > 0)
      { /* timer is still running in the direction of prefailed (+1) or event is failed (+127) */
      }
      else
      { /* start timer in the direction of prefailed and set faultdetection counter accordingly (+1) */
        Dem_CalcNewDebounceTimerSlotValue(EventId, EventStatus);  
        fdCounter = 1;
      }
    }
    else
#endif
    {
      /* Do we need a jump-up to zero */
      if ((fdCounter < 0) && (DemCfg_GetIsPredebJumpPreFailed(EventId) != FALSE))                 /* PRQA S 3415 *//* MD_DEM_12.4 */
      {
        fdCounter = 0;
      }
      fdCounter = fdCounter + (sint16_least) DemCfg_GetPredebStepsizePreFailed(EventId);

      if (fdCounter >= 127)                                   /* limit the counter to max value */
      {
        fdCounter = 127;
        *EventStatus = DEM_EVENT_STATUS_FAILED;               /* change EventStatus: PREFAILED -> FAILED */
      }
    }
  }
  else if (*EventStatus == DEM_EVENT_STATUS_PREPASSED)
  {
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
    /* Check if EventId is handled via time based de-bounce algorithm */
    if(DemCfg_GetIsEventTimeBasedDebounce(EventId) != FALSE)
    {
      if (fdCounter < 0)
      { /* timer is still running in the direction of prepassed (-1) or event is passed (-128) */
      }
      else
      { /* start timer in the direction of prepassed and set faultdetection counter accordingly (-1) */
        Dem_CalcNewDebounceTimerSlotValue(EventId, EventStatus);
        fdCounter = -1;
      }
    }
    else
#endif
    {
      /* Do we need a jump-down to zero */
      if ((fdCounter > 0) && (DemCfg_GetIsPredebJumpPrePassed(EventId) != FALSE))                 /* PRQA S 3415 *//* MD_DEM_12.4 */
      {
        fdCounter = 0;
      }
      fdCounter = fdCounter - (sint16_least) DemCfg_GetPredebStepsizePrePassed(EventId);

      if (fdCounter <= -128)                                  /* limit the counter to min value */
      {
        fdCounter = -128;
        *EventStatus = DEM_EVENT_STATUS_PASSED;
      }
    }
  }
  else if (*EventStatus == DEM_EVENT_STATUS_PASSED)
  {
    /* discard any prestored FreezeFrame for this event (Dem192) */
    DEM_UNSET_PRESTORED_EVENT(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
    Dem_ClearDebounceTimerSlot(EventId);                      /* stop any running debounce timer */
#endif
    fdCounter = -128;
  }
  else /* (*EventStatus == DEM_EVENT_STATUS_FAILED) */
  {
    /* discard any prestored FreezeFrame for this event (Dem192) */
    DEM_UNSET_PRESTORED_EVENT(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
    Dem_ClearDebounceTimerSlot(EventId);                      /* stop any running debounce timer */
#endif
    fdCounter = 127;
  }

  /* return the new value of the fault detection counter */
  return (sint8) fdCounter;
}

#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
/**********************************************************************************************************************
  Dem_HandleTimeBasedDebounceEvents
**********************************************************************************************************************/
/** Increment internal clock and work all events that are configured for time based debouncing.
 *  Advance the internal timer for time based debouncing (global variable 'Dem_DebounceTimer'). Scan all time based
 *  events that are currently debouncing. Will set event (failed/passed) if timer reached target time for the event.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \attention   When the timer of an event fires, the event is set by calling Dem_DoSetEventStatus()
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_HandleTimeBasedDebounceEvents( 
  void 
  ) 
{
  uint16_least iter;
  Dem_EventIdType EventId;

  /* increment the internal 'clock' */
  if (Dem_DebounceTimer == (Dem_TimeBasedDebounceTimerType)(~(Dem_TimeBasedDebounceTimerType)0u))  /* max value reached, counter wrap around */  /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
  { /* Timer value 0 is not valid */
    Dem_DebounceTimer = 1;
  }
  else
  {
    ++Dem_DebounceTimer;
  }

  /* look for a timer event */
  for (iter = 0; iter < Dem_NumberOfDebounceTimerSlots; ++iter)
  { /* check if timer value matches */
    if (Dem_DebounceTimerSlots[iter] == Dem_DebounceTimer)
    { /* Timer matches */
      EventId = DemCfg_GetEventIdFromTimeBasedDebounceTableIdx(iter);
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (Dem_IsInActiveVariant(EventId) != FALSE)
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      {
        /* Is the alarm a Failed/ Passed event */
        if (Dem_FaultDetectionCounterPtr[EventId] == 1)
        {
          (void) Dem_DoSetEventStatus(EventId, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
          (void) Dem_DoSetEventStatus(EventId, DEM_EVENT_STATUS_PASSED);
        }
        /* Event has been processed, clear timer slot */
        Dem_ClearDebounceTimerSlot(EventId);
      }
    }
  }
}
#endif

#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
/**********************************************************************************************************************
  Dem_CalcNewDebounceTimerSlotValue
**********************************************************************************************************************/
/** Calculate the new timer alarm value for the time based de-bounce algorithm for given event.
 *  Use current time (Dem_DebounceTimer) and configured debounce time to calculate the target time for the event
 *  to terminate its debouncing. Target time is stored in related Dem_DebounceTimerSlots[].
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_CalcNewFaultDetectionCntr()
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \param[in]   EventStatus  uint8 { DEM_EVENT_STATUS_PREPASSED, DEM_EVENT_STATUS_PREFAILED }
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_CalcNewDebounceTimerSlotValue(
  Dem_EventIdType EventId,
  P2CONST(Dem_EventStatusType, AUTOMATIC, AUTOMATIC) EventStatus                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_TimeBasedDebounceTimerType slotVal;

  slotVal = Dem_DebounceTimer;                                /* get current time */

  /* calculate alarm time (which depends on direction of fault detection counter) */
  if(*EventStatus == DEM_EVENT_STATUS_PREFAILED)
  {
    slotVal = slotVal + DemCfg_GetTimeBasedDebValueFailed(EventId);                          /* explicitely permit overflow of range here */
  }
  else  /* DEM_EVENT_STATUS_PREPASSED */
  {
    slotVal = slotVal + DemCfg_GetTimeBasedDebValuePassed(EventId);                          /* explicitely permit overflow of range here */
  }
  
  if (slotVal < Dem_DebounceTimer)                                                                /* detect overflow of range */
  { /* compensate timer wrap around (when the invalid value '0' must be skipped) */
    ++slotVal;
  }

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Timer slot 0 is an invalid value */
  if (slotVal == 0)
  {
    Dem_DetReportError(DEM_CALCNEWDEBOUNCETIMERSLOTVAL_APIID, DEM_E_INV_TIMER_SLOT_VAL);
  }
#endif
  Dem_DebounceTimerSlots[DemCfg_GetTimeBasedDebounceTableIdx(EventId)] = slotVal;                 /* store target (alarm) time */
}
#endif

#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
/**********************************************************************************************************************
  Dem_ClearDebounceTimerSlot
**********************************************************************************************************************/
/** Clear the time based timer slot of given event.
 *  This function stops the timer for time based debouncing of the given EventId.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_InitChronoStack()
 *                                    Dem_DoSetOperationCycleState()
 *                                    Dem_CalcNewFaultDetectionCntr()
 *                                    Dem_HandleTimeBasedDebounceEvents()
 *                                    Dem_ClearSingleEvent()
 * \param[in]   EventId      Clears the timer slot for this event (if configured)
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearDebounceTimerSlot( 
  Dem_EventIdType EventId 
  )
{ /* Is the Event a time based de-bounce one? */
  if (DemCfg_GetIsEventTimeBasedDebounce(EventId) != FALSE)
  { /* Deactivate time based de-bounce timer slot for this event if it is active */
    Dem_DebounceTimerSlots[DemCfg_GetTimeBasedDebounceTableIdx(EventId)] = 0;
  }
}
#endif

/**********************************************************************************************************************
  Dem_ReportErrorStatus
**********************************************************************************************************************/
/** Interface for BSW Components to report Errors during start up and normal operation.
 *  Interface for BSW Components to report Errors during start up (even before DEM initialization) and normal
 *  operation. During start up all incoming Errors are collected in the BSW buffer queue and handled in first call of 
 *  Dem_MainFunction(). At a first step, it is assumed, that all incoming results are considered as debounced. If a 
 *  central pre-debouncing is provided, this API shall be used to support them for the BSW.
 * \attention   This API just sets a trigger to store the event, the actual storing is done later in Dem_MainFunction()
 *              by calling Dem_DoSetEventStatus()
 * \attention   To store an event, the event's assigned operation cycle must be in State DEM_CYCLE_STATE_START else the
 *              event will be discarded!
 * \note        SERVICE ID   0x0f
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    BSW
 * \note        CONFIG       The size of the buffer queue needs to be configured (ref.\ to DEM_BSW_ERROR_BUFFER_SIZE)
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId      Identification of an Event by assigned Event ID. The Event ID is configured in the DEM.
 * \param[in]   EventStatus  uint8 { DEM_EVENT_STATUS_PASSED, DEM_EVENT_STATUS_FAILED, DEM_EVENT_STATUS_PREPASSED,
 *                           DEM_EVENT_STATUS_PREFAILED [, Custom]}
 *********************************************************************************************************************/
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ReportErrorStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  boolean successfulQueued;

  if ( (DEM_EVENT_STATUS_PASSED != EventStatus)
    && (DEM_EVENT_STATUS_FAILED != EventStatus)
    && (DEM_EVENT_STATUS_PREPASSED != EventStatus)
    && (DEM_EVENT_STATUS_PREFAILED != EventStatus) )
  {
    Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif
  if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                                /* PRQA S 3415 *//* MD_DEM_12.4 */
  {
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* event is not available in current variant */
#  if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
#  endif  /* DEM_DEV_ERROR_DETECT */
    }
    else
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      Dem_AQElementType newElement;

      /* the ReportErrorStatus is put to the queue, the queue will be drained later in Dem_MainFunction() */
      /* First, prepare the queue element */
      Dem_AQSetAction( &newElement, DEM_AQACTION_REPORTERROR);                                    /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetEventStatus( &newElement, EventStatus );                                           /* PRQA S 3198 *//* We modify newElement.arg.event.Status only once - Bug in PRQA analysis */
      Dem_AQSetEventId( &newElement, EventId );

      /* Before DEM startup (and optionally) during drive:
      *  Put 'failed' events to buffer;
      *  Ignore 'passed' events to avoid Buffer overflow [Dem107] */
      if (Dem_InitializationStatus == DEM_IsUninitialized)
      { /* OS is probably not running - we need special critical section handling here */
        if (DEM_EVENT_STATUS_FAILED == EventStatus)
        { /* put 'failed' event into queue, if there is space for event + n times StartOperationCycle();
          * (with n = DEM_ADD_ERROR_BUFFER_SIZE)
          * see size of Dem_ActionQueue[], which is n elements larger than the DEM_BSW_ERROR_BUFFER_SIZE */
          if (Dem_AQUsed() < (uint16) Dem_ReportErrorBufferSize)
          {
            /* Append the new action to queue */
            /* Enter Critical ====  OS is probably not running yet  ====================================================== */
            Dem_EnterCritical_PreInit();
            (void) Dem_AQPush( &newElement );
            Dem_LeaveCritical_PreInit();
            /* Leave Critical ====  OS is probably not running yet  ====================================================== */
          }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
          else
          {
            Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_QUEUE_OVERFLOW);
          }
#endif
        }
      }
      else if ((Dem_InitializationStatus == DEM_IsDisabled) || (Dem_InitializationStatus == DEM_IsEnabled))
      { /* OS is running - we use standard critical section handling here */
        /*
        * After Dem_Shutdown  (DEM_IsDisabled) we store only 'failed' BSW reports in the BSW queue.
        * After Dem_Init until first Dem_MainFunction has drained the BSW queue (DEM_IsEnabled), we keep
        * filtering just 'failed' events to add to the BSW queue and discard others.
        */
        if (DEM_EVENT_STATUS_FAILED == EventStatus)
        { /* put 'failed' event into queue, if there is space for event + 1x StartOperationCycle()  */
          if (Dem_AQUsed() < (uint16) Dem_ReportErrorBufferSize)
          {
            /* Enter Critical ========================================================== */
            Dem_EnterCritical();
#if (DEM_DEV_ERROR_DETECT == STD_ON)
            successfulQueued = 
#else
            (void)
#endif
              Dem_AQPush( &newElement );
            Dem_LeaveCritical();
            /* Leave Critical ========================================================== */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
            if (!successfulQueued)
            {
              Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_QUEUE_OVERFLOW);
            }
#endif
          }
        }
      }
      else if (Dem_InitializationStatus == DEM_IsEnabledAndRunning)
      { /* DEM is active, so directly use Dem_SetEventStatus() [which is not different here, as we use the same buffer] */
        /* Enter Critical ========================================================== */
        Dem_EnterCritical();
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        successfulQueued = 
#else
        (void)
#endif
          Dem_AQPush( &newElement );
        Dem_LeaveCritical();
        /* Leave Critical ========================================================== */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        if (!successfulQueued)
        {
          Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_QUEUE_OVERFLOW);
        }
#endif
      }
      else
      {}                                                                                          /* satisfy MISRA-C:2004 Rule 14.10: requires else for if-else-if statements */
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_REPORTERRORSTATUS_APIID, DEM_E_PARAM_DATA);
  }
#endif
  return;
}


/**********************************************************************************************************************
  Dem_GetEventStatus
**********************************************************************************************************************/
/** This API shall be used to read the event status from the DEM.
 *  This API is provided to be used by SW-Components or other basic software modules e.g. FIM.
 *  For the DCM the API Dem_GetStatusOfDTC is used.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x0a
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId               Identification of an Event by assigned EventId. The EventId is configured
 *                                    in the DEM.
 * \param[out]  EventStatusExtended   For explanation \see Dem_EventStatusExtendedType definition chapter. The returned
 *                                    status is NOT limited by the status availability mask!
 * \retval      E_OK      get of event status was successful
 * \retval      E_NOT_OK  get of event status failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventStatus(
  Dem_EventIdType                                               EventId,
  P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA)  EventStatusExtended               /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      Dem_DetReportError(DEM_GETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
#endif
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* event is not available in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_GETEVENTSTATUS_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
    }
    else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      Dem_DtcStatusByteType internalStatus = Dem_DtcStatusBytePtr[EventId];
      *EventStatusExtended = Dem_MapStatusByteTypeToExtType(internalStatus);                      /* no limitation via status availability mask */
      returnValue = E_OK;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETEVENTSTATUS_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetEventFailed
**********************************************************************************************************************/
/** Read 'testFailed' bit of event.
 *  This API shall be used to read Bit 0 of Dem_EventStatusExtendedType from the DEM.
 *  For the DCM the API Dem_GetStatusOfDTC is used.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x0b
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \param[out]  EventFailed  'TRUE' - Last Failed, 'FALSE' - not Last Failed
 * \retval      E_OK      get of 'EventFailed' was successful
 * \retval      E_NOT_OK  get of 'EventFailed' was not successful
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventFailed(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      Dem_DetReportError(DEM_GETEVENTFAILED_APIID, DEM_E_PARAM_DATA);
    }
    else
#endif
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* event is not available in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_GETEVENTFAILED_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
    }
    else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      if (DEM_IS_BIT_SET_TEST_FAILED(EventId) != FALSE)
      {
        *EventFailed = TRUE;
      }
      else
      {
        *EventFailed = FALSE;
      }
      returnValue = E_OK;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETEVENTFAILED_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetEventTested
**********************************************************************************************************************/
/** Read negated 'testNotCompletedThisOperationCycle' bit of event.
 *  This API shall be used to read negated Bit 6 of Dem_EventStatusExtendedType from the DEM.
 *  For the DCM the API Dem_GetStatusOfDTC is used.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x0c
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId      Identification of an Event by assigned EventId. The EventId is configured in the DEM.
 * \param[out]  EventTested  'TRUE' - event tested this cycle, 'FALSE' - event not tested this cycle
 * \retval      E_OK      get of event state 'tested' successful
 * \retval      E_NOT_OK  get of event state 'tested' failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventTested(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      Dem_DetReportError(DEM_GETEVENTTESTED_APIID, DEM_E_PARAM_CONFIG);
    }
    else
#endif
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* event is not available in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_GETEVENTTESTED_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
    }
    else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      if (Dem_OperationCycleState[DemCfg_GetOperationCycleId(EventId)] == DEM_CYCLE_STATE_START )
      {
        if (DEM_IS_BIT_UNSET_TEST_N_COMPL_THIS_OC(EventId) != FALSE)
        {
          *EventTested = TRUE;
        }
        else
        {
          *EventTested = FALSE;
        }
        returnValue = E_OK;
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETEVENTTESTED_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetDTCOfEvent
**********************************************************************************************************************/
/** Gets the DTC which is mapped to EventId by DEM Configuration.
 * \return      Std_ReturnType with extension(!), see Bugzilla #23091
 * \note        SERVICE ID   0x0d
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        CONFIG       Mapping of Events to DTCs is configured in DEM.
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId           Identification of an Event by assigned EventId. The EventId is configured in
 *                                the DEM.
 * \param[in]   DTCKind           This parameter defines the requested DTC, either only OBD relevant DTCs or all DTCs.
 * \param[out]  DTCOfEvent        Receives the DTC value returned by the function. If the status return value of the
 *                                function is other than OK this parameter does not contain valid data.
 * \retval      E_OK                              get of DTC was successful
 * \retval      E_NOT_OK                          get of DTC failed
 * \retval      DEM_GET_DTCOFEVENT_WRONG_DTCKIND  DTC kind wrong
 * \retval      DEM_GET_DTCOFEVENT_WRONG_EVENTID  Wrong EventId
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCOfEvent(
  Dem_EventIdType                                               EventId,
  Dem_DTCKindType                                               DTCKind,
  P2VAR(Dem_DTCType,                 AUTOMATIC, DEM_APPL_DATA)  DTCOfEvent                        /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()) && (DEM_DTCNUMBER_INVALID != DemCfg_GetDTCnumber(EventId)))      /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (! (Dem_IsInActiveVariant(EventId)))
      { /* event is not available in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
        Dem_DetReportError(DEM_GETDTCOFEVENT_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
        /* returnValue = E_NOT_OK; */
      }
      else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      if ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DemCfg_GetDTCKind(EventId)))          /* PRQA S 3415 *//* MD_DEM_12.4 */
      {
        *DTCOfEvent = DemCfg_GetDTCnumber(EventId);
        returnValue = E_OK;
      }
      else
      {
        returnValue = DEM_GET_DTCOFEVENT_WRONG_DTCKIND;
      }
    }
    else
    {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_GETDTCOFEVENT_APIID, DEM_E_PARAM_CONFIG);
#endif
      returnValue = DEM_GET_DTCOFEVENT_WRONG_EVENTID;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETDTCOFEVENT_APIID, DEM_E_UNINIT);
  }
#endif
  return returnValue;
}

/**********************************************************************************************************************
  Dem_SetValueByOemId
**********************************************************************************************************************/
/** This API shall be used to set a data value assigned to a specific data identifier.
 *  The list of data identifiers is OEM specific and has to be fixed at configuration time.
 *  Only simple data types (uint8...uint32; sint8...sint32) are allowed.
 *  Structured data types (struct, array) are not allowed.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x38
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        CONFIG       Required configuration parameters:
 *                            - OemID
 *                            - real Name of the assigned value
 * \note        AUTOSAR R3.0 API
 * \param[in]   OemID         This OEM specific parameter identifies a data value the DEM
 *                            requires for internal processing, e.g. vehicle speed or mileage.
 * \param[in]   BufferLength  Data length of the value to be set
 * \param[out]  DataValue     Pointer to the buffer with the value to be set
 * \retval      E_OK      the data value could be set successfully
 * \retval      E_NOT_OK  the setting of the data value failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetValueByOemId(
  uint16                                  OemID,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DataValue,                                              /* PRQA S 3673 *//* MD_DEM_16.7 */ /* PRQA S 0850 *//* MD_MSR_19.8 */
  uint8                                   BufferLength
  )
{
  /* feature not supported for this OEM */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DataValue == NULL_PTR)
  {
    Dem_DetReportError(DEM_SETVALUEBYOEMID_APIID, DEM_E_PARAM_CONFIG);
  }
  else if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_SETVALUEBYOEMID_APIID, DEM_E_UNINIT);
  }
  else
#else
  DEM_IGNORE_UNUSED_ARG(DataValue);                                                               /* PRQA S 3112 *//* MD_DEM_14.2 */
#endif
  {
    DEM_IGNORE_UNUSED_ARG(OemID);                                                                 /* PRQA S 3112 *//* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_ARG(BufferLength);                                                          /* PRQA S 3112 *//* MD_DEM_14.2 */
  }
  return E_NOT_OK;
}


/**********************************************************************************************************************
  Dem_SetEnableCondition
**********************************************************************************************************************/
/** This API shall be used to set the enable condition.
 *  For each event an enable condition value is assigned to. An enable condition specifies a certain number of
 *  checks (e.g. correct voltage range) for an event before the event can be qualified as confirmed.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x39
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \attention   This API is optional and depends on the automotive manufacturer.
 * \note        CONFIG       Required configuration parameters per event:
 *                           - EnableConditionID
 *                           - EnableConditionStatus
 * \param[in]   EnableConditionID   This parameter identifies the enable condition.
 * \param[in]   ConditionFulfilled  This parameter specifies whether the enable condition assigned to the
 *                                  EnableConditionID is fulfilled (TRUE) or not fulfilled (FALSE).
 * \retval      E_OK      the enable condition could be set successfully
 * \retval      E_NOT_OK  the setting of the enable condition failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetEnableCondition(
  uint8     EnableConditionID,
  boolean   ConditionFulfilled
  )
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
    Dem_DetReportError(DEM_SETENABLECONDITION_APIID, DEM_E_UNINIT);
  }
  else
#endif
  {
    /* feature not supported for this OEM */
    DEM_IGNORE_UNUSED_ARG(EnableConditionID);                                                     /* PRQA S 3112 *//* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_ARG(ConditionFulfilled);                                                    /* PRQA S 3112 *//* MD_DEM_14.2 */
  }
  return E_NOT_OK;
}


/**********************************************************************************************************************
  Dem_GetSeverityOfDTC
**********************************************************************************************************************/
/** Gets Severity of the requested DTC.
 * \return      Status of the operation of type Dem_ReturnGetSeverityOfDTCType
 * \note        SERVICE ID   0x0e
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1908, 0x1909
 * \attention   Dem_DTCKindType not needed, because Severity is only available for ISO14229-1 DTCs
 * \note        CONFIG       Mapping of Events to DTCs is configured in DEM.
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC                 The Severity assigned to this DTC should be returned.
 * \param[out]  DTCSeverity         This parameter contains the DTCSeverityMask according to ISO14229-1.
 * \retval      DEM_GET_SEVERITYOFDTC_OK               Severity successfully returned.
 * \retval      DEM_GET_SEVERITYOFDTC_WRONG_DTC        Wrong DTC
 * \retval      DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN  Wrong DTC origin  (unused)
 * \retval      DEM_GET_SEVERITYOFDTC_NOSEVERITY       Severity information is not available
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSeverityOfDTC(
  Dem_DTCType                                                       DTC,
  P2VAR(Dem_DTCSeverityType,            AUTOMATIC, DEM_APPL_DATA)   DTCSeverity                   /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_ReturnGetSeverityOfDTCType returnValue = DEM_GET_SEVERITYOFDTC_NOSEVERITY;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DTCSeverity == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETSEVERITYOFDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      *DTCSeverity = DemCfg_GetDTCSeverity(EventId);
      returnValue  = DEM_GET_SEVERITYOFDTC_OK;
    }
    else
    { /* invalid DTC - no DetReportError, as the DTC number is from external request */
      returnValue = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETSEVERITYOFDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_DisableDTCStorage
**********************************************************************************************************************/
/** Disable the storage of DTCs in the event memory (Dem035).
 *  DTC status information update is not affected by this function.
 *  This is only for preventing DTCs from being stored in case of an induced failure situations in a system, e.g.
 *  during flash-reprogramming of one ECU in a network. In that case all the ECU's are commanded via diagnostic
 *  request (linked to the above diagnostic request) to suppress storage of a DTC while maintaining correct
 *  fail-safe behavior as the flashed ECU is not participating in the normal communication anymore. If one of the
 *  other networked ECUs needs one of the signals which are now missing, this will lead to a failsafe-reaction of
 *  the ECU as by the AUTOSAR concept the fail-safe reaction of an ECU is triggered by certain event-status
 *  updates or a FIM-command which is itself triggered by an event-status update.
 * \return      Status of the operation of type Dem_ReturnControlDTCStorageType.
 * \note        SERVICE ID   0x24
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x85
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCGroup  Defines the group of DTC that shall be disabled to store in event memory.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \retval      DEM_CONTROL_DTC_STORAGE_OK      DTC storage control successful
 * \retval      DEM_CONTROL_DTC_STORAGE_N_OK    DTC storage control not successful
 * \retval      DEM_CONTROL_DTC_WRONG_DTCGROUP  DTC storage control not successful because group of DTC was wrong.
 *********************************************************************************************************************/
FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)                                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableDTCStorage(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  )
{
  Dem_ReturnControlDTCStorageType returnValue = DEM_CONTROL_DTC_STORAGE_N_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
  {
    Dem_DetReportError(DEM_DISABLEDTCSTORAGE_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_DTCGroupKindType BitcodedDTCGroup;

    returnValue = DEM_CONTROL_DTC_WRONG_DTCGROUP;
    BitcodedDTCGroup = Dem_MapGroupNumberToGroupKind((Dem_DTCType) DTCGroup);

    if ((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && (BitcodedDTCGroup == DEM_DTC_GROUPKIND_ALL_DTCS))
    {
      BitcodedDTCGroup = DEM_DTC_GROUPKIND_EMISSION_REL;
    }

    if (BitcodedDTCGroup != 0)
    {
      Dem_StorageState = (Dem_DTCGroupKindType)(Dem_StorageState & ((Dem_DTCGroupKindType) (~BitcodedDTCGroup)));         /*  MISRA improvement for: Dem_StorageState &= ~BitcodedDTCGroup; */  /* PRQA S 0291 *//* MD_DEM_21.1 */
      returnValue = DEM_CONTROL_DTC_STORAGE_OK;
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* invalid DTCGroup */
      Dem_DetReportError(DEM_DISABLEDTCSTORAGE_APIID, DEM_E_PARAM_DATA);
    }
#endif  /* DEM_DEV_ERROR_DETECT */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_DISABLEDTCSTORAGE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_EnableDTCStorage
**********************************************************************************************************************/
/** Enable the storage of DTCs in the event memory (Dem035).
 *  \see Dem_DisableDTCStorage().
 * \attention   This API just sets a trigger to enable the storage, the actual enabling is done later in Dem_MainFunction()
 *              by calling Dem_DoEnableDTCStorage()
 * \return      Status of the operation of type Dem_ReturnControlDTCStorageType.
 * \note        SERVICE ID   0x25
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x85 and during session change to default session
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCGroup  Defines the group of DTC that shall be enabled to store in event memory.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \retval      DEM_CONTROL_DTC_STORAGE_OK      DTC storage control successful
 * \retval      DEM_CONTROL_DTC_STORAGE_N_OK    DTC storage control not successful
 * \retval      DEM_CONTROL_DTC_WRONG_DTCGROUP  DTC storage control not successful because group of DTC was wrong.
 *********************************************************************************************************************/
FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)                                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableDTCStorage(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  )
{
  Dem_ReturnControlDTCStorageType returnValue = DEM_CONTROL_DTC_STORAGE_N_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
  {
    Dem_DetReportError(DEM_ENABLEDTCSTORAGE_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_DTCGroupKindType BitcodedDTCGroup = Dem_MapGroupNumberToGroupKind((Dem_DTCType) DTCGroup);
    returnValue = DEM_CONTROL_DTC_WRONG_DTCGROUP;

    if ((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && (BitcodedDTCGroup == DEM_DTC_GROUPKIND_ALL_DTCS))
    {
      BitcodedDTCGroup = DEM_DTC_GROUPKIND_EMISSION_REL;
    }

    if (BitcodedDTCGroup != 0)
    { /* work is be shifted to main task to get the correct context when calling xxx_DemInitMonitor() */
      Dem_AQElementType newElement;
      boolean successfulQueued;

      /* the EnableDTCStorage is put to the queue, the queue will be drained later in Dem_MainFunction() */
      Dem_AQSetAction( &newElement, DEM_AQACTION_ENABLESTORAGE);                                  /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetBitcodedDTCGroup( &newElement, BitcodedDTCGroup );                                 /* PRQA S 3198 *//* We modify newElement.arg.dtc.BitcodedDtcGroup only once - Bug in PRQA analysis */
      Dem_AQSetDTCKind( &newElement, DTCKind );
      /* Append the new action to queue */
      /* Enter Critical ========================================================== */
      Dem_EnterCritical();
      successfulQueued = Dem_AQPush( &newElement );
      Dem_LeaveCritical();
      /* Leave Critical ========================================================== */

      if (!successfulQueued)
      {
        returnValue = DEM_CONTROL_DTC_STORAGE_N_OK;
      }
      else
      {
        returnValue = DEM_CONTROL_DTC_STORAGE_OK;
      }
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* invalid DTCGroup */
      Dem_DetReportError(DEM_ENABLEDTCSTORAGE_APIID, DEM_E_PARAM_DATA);
    }
#endif  /* DEM_DEV_ERROR_DETECT */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_ENABLEDTCSTORAGE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_DoEnableDTCStorage
**********************************************************************************************************************/
/** Execute EnableDTCStorage tasks inside Dem_MainFunction().
 *  This function actually enables the storage of DTCs in the event memory (Dem035).
 *  API parameter checks (if applicable) are already done by Dem_EnableDTCStorage().
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x25
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   no
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \note        AUTOSAR R3.0 API
 * \param[in]   BitcodedDTCGroup  Group of DTC that shall be enabled to store in event memory (internal group value).
 * \param[in]   DTCKind           This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \retval      E_OK         DTC storage control successful
 * \retval      E_NOT_OK     DTC storage control not successful
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoEnableDTCStorage(
  Dem_DTCGroupKindType  BitcodedDTCGroup,
  Dem_DTCKindType       DTCKind
  )
{
  Std_ReturnType returnValue = E_OK;
  Dem_EventIdType EventId;
  Dem_DTCGroupKindType EventGroupKind;

  Dem_StorageState |= BitcodedDTCGroup;

  /* restart the init monitors for the requested DTCGroup and DTCKind */
  for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
  { /* iterate over all events */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* EventId is not defined for current configuration */
      continue;                                                                                   /* PRQA S 0770 *//* MD_DEM_14.5 */
    }
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */

    EventGroupKind = DemCfg_GetDTCGroupKind(EventId);
    if ((BitcodedDTCGroup & EventGroupKind) != 0)
    { /* this event is in the requested DTCGroup */
      if (DemCfg_GetDTCKind(EventId) == DTCKind)
      { /* and is of the requested DTCKind */
        /* call related Xxx_DemInitMonitor{EventId}() function to restart the monitor */
        if (!! DemCfg_GetInitMonitorFPtr(EventId))                                                /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
        {
          (void)(*DemCfg_GetInitMonitorFPtr(EventId))(DEM_INIT_MONITOR_RESTART);
        }
      }
    }
  }

  return returnValue;
}
  
/**********************************************************************************************************************
  Dem_DisableEventStatusUpdate
**********************************************************************************************************************/
/** Disable the update of the event status.
 *  The function shall disable the update of the event status of a DTC group.
 *  This API has influence only on the execution of the API's Dem_SetEventStatus and Dem_ResetEventStatus. This is
 *  defined within the configuration (Dem034).
 *  In this case both, the event status update and consequently the storage of DTCs, are suppressed. Thereby any
 *  fail-safe reaction of the ECU which is tight to certain event-status-updates will be suppressed as well,
 *  leaving the system in an unpredictable or even self-destructive condition if failures are not correctly
 *  handled anymore.
 *  This feature / API-call may be used for engineering purposes or during manufacturing in a controlled
 *  environment to suppress failsafe-reaction (e.g. prevent headlamps on, windshield wiper on, etc.).
 * \return      Status of the operation of type Status of the operation of type Dem_ReturnControlDTCStorageType
 * \note        SERVICE ID   0x26
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCGroup  Defines the group of DTC that shall be disabled to store in event memory.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \retval      DEM_CONTROL_EVENT_UPDATE_OK       Event storage control successful.
 * \retval      DEM_CONTROL_EVENT_UPDATE_N_OK     Event storage control not successful.
 * \retval      DEM_CONTROL_EVENT_WRONG_DTCGROUP  Event storage control not successful because group of DTC was wrong.
 *********************************************************************************************************************/
FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableEventStatusUpdate(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  )
{
  Dem_ReturnControlDTCStorageType returnValue = DEM_CONTROL_EVENT_UPDATE_N_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
  {
    Dem_DetReportError(DEM_DISABLEEVENTSTATUSUPDATE_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_DTCGroupKindType BitcodedDTCGroup;

    returnValue = DEM_CONTROL_EVENT_WRONG_DTCGROUP;
    BitcodedDTCGroup = Dem_MapGroupNumberToGroupKind((Dem_DTCType) DTCGroup);

    if ((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && (BitcodedDTCGroup == DEM_DTC_GROUPKIND_ALL_DTCS))
    {
      BitcodedDTCGroup = DEM_DTC_GROUPKIND_EMISSION_REL;
    }

    if (BitcodedDTCGroup != 0)
    {
      Dem_StatusUpdate = (Dem_DTCGroupKindType)(Dem_StatusUpdate & ((Dem_DTCGroupKindType) (~BitcodedDTCGroup)));         /*  MISRA improvement for: Dem_StatusUpdate &= ~BitcodedDTCGroup; */  /* incorrect report of MISRA-C:2004 Rule 21.1 violation from using '~': An integer expression with a value that is apparently negative is being converted to an unsigned type.*/ /* PRQA S 0291 *//* Using '~' on uint8 will always cause MISRA violation. */
      returnValue = DEM_CONTROL_EVENT_UPDATE_OK;
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* invalid DTCGroup */
      Dem_DetReportError(DEM_DISABLEEVENTSTATUSUPDATE_APIID, DEM_E_PARAM_DATA);
    }
#endif  /* DEM_DEV_ERROR_DETECT */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_DISABLEEVENTSTATUSUPDATE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */

  return returnValue;
}

/**********************************************************************************************************************
  Dem_EnableEventStatusUpdate
**********************************************************************************************************************/
/** Enable the update of the event status (Dem034).
 *  \see Dem_DisableEventStatusUpdate().
 * \return      Status of the operation of type Status of the operation of type Dem_ReturnControlDTCStorageType
 * \note        SERVICE ID   0x27
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTCGroup  Defines the group of DTC that shall be enabled to store in event memory.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \retval      DEM_CONTROL_EVENT_UPDATE_OK       Event storage control successful.
 * \retval      DEM_CONTROL_EVENT_UPDATE_N_OK     Event storage control not successful.
 * \retval      DEM_CONTROL_EVENT_WRONG_DTCGROUP  Event storage control not successful because group of DTC was wrong.
 *********************************************************************************************************************/
FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableEventStatusUpdate(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  )
{
  Dem_ReturnControlDTCStorageType returnValue = DEM_CONTROL_EVENT_UPDATE_N_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
  {
    Dem_DetReportError(DEM_ENABLEEVENTSTATUSUPDATE_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_DTCGroupKindType BitcodedDTCGroup = Dem_MapGroupNumberToGroupKind((Dem_DTCType) DTCGroup);
    returnValue = DEM_CONTROL_EVENT_WRONG_DTCGROUP;

    if ((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && (BitcodedDTCGroup == DEM_DTC_GROUPKIND_ALL_DTCS))
    {
      BitcodedDTCGroup = DEM_DTC_GROUPKIND_EMISSION_REL;
    }

    if (BitcodedDTCGroup != 0)
    {
      Dem_StatusUpdate |= BitcodedDTCGroup;
      returnValue = DEM_CONTROL_EVENT_UPDATE_OK;
    }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    else
    { /* invalid DTCGroup */
      Dem_DetReportError(DEM_ENABLEEVENTSTATUSUPDATE_APIID, DEM_E_PARAM_DATA);
    }
#endif  /* DEM_DEV_ERROR_DETECT */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_ENABLEEVENTSTATUSUPDATE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetIndicatorStatus
**********************************************************************************************************************/
/** Get status of an indicator.
 *  This function shall be used to read the indicator-status derived from the event status as a summary of all
 *  assigned events.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x29
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        CONFIG       The assignment for the Dem_IndicatorId to indicator has to be done.
 *                           Examples for indicators: lamps, different text messages, icons,...
 * \note        AUTOSAR R3.0 API
 * \param[in]   Dem_IndicatorId       Number of indicator
 * \param[out]  Dem_IndicatorStatus   Status of the indicator, like on, off, blinking.
 * \retval      E_OK      Operation was successful
 * \retval      E_NOT_OK  Operation failed or is not supported
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetIndicatorStatus(
  Dem_IndicatorIdType                                       Dem_IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA)  Dem_IndicatorStatus                   /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType           returnValue = E_NOT_OK;      /* Operation failed (due invalid IndicatorId) */
  uint16_least             indicatorRef = 0;
  uint8                    indicatorIdCount;            /* configured number of IndicatorIds for the event */
  Dem_IndicatorStatusType  resultIndicatorStatus = 0;
  Dem_EventIdType          EventId;
  boolean                  doActivateIndicator;
  
  if ((Dem_InitializationStatus == DEM_IsUninitialized) || (Dem_InitializationStatus == DEM_IsDisabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    Dem_DetReportError(DEM_GETINDICATORSTATUS_APIID, DEM_E_UNINIT);
#endif
  }
  else
  {
    EventId = 0;
    do
    { /* iterate over all defined events, start with event #1 */
      ++EventId;
      if ((DEM_INDICATOR_OFF | DEM_INDICATOR_CONTINUOUS | DEM_INDICATOR_BLINKING | DEM_INDICATOR_BLINK_CONT) == resultIndicatorStatus)
      { /* abort loop when all possible return values are already set */
        break;
      }

#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (! (Dem_IsInActiveVariant(EventId)))
      { /* event is not available in current variant */
        continue;                                                                                 /* PRQA S 0770 *//* MD_DEM_14.5 */
      }
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */

      /* check, if the indicator has to be activated for this event */
      doActivateIndicator = (boolean) DEM_IS_BIT_SET_TEST_FAILED(EventId);

      for (indicatorIdCount = DemCfg_GetCountOfIndicatorIds(EventId);
        indicatorIdCount > 0;
        --indicatorIdCount)
      { /* iterate over all indicators of this event */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
        if (indicatorRef >= 65535u)
        {
          Dem_DetReportError(DEM_GETINDICATORSTATUS_APIID, DEM_E_TOO_MANY_INDICATOR_IDS);
        }
#endif

        if (DemCfg_GetIndicatorId(indicatorRef) == Dem_IndicatorId)
        { /* detected the requested indicator id */
          returnValue = E_OK;
          /* if conditions to activate the indicator are fulfilled, put the indicator status to already set status */
          if (doActivateIndicator != FALSE)
          {
            resultIndicatorStatus |= DemCfg_GetIndicatorStatusType(indicatorRef);
          }
        }
        ++indicatorRef;
      }
    } while (EventId < DemCfg_GetMaxCountOfEventId());

    if (E_OK == returnValue)
    { /* write *Dem_IndicatorStatus on success only */
      *Dem_IndicatorStatus = resultIndicatorStatus;
    }
  }

  return returnValue;
}


/**********************************************************************************************************************
  Dem_GetFaultDetectionCounter
**********************************************************************************************************************/
/** Read the DEM internal FaultDetectionCounter of an event.
 *  The API shall be used by SW-C to request the current Fault Detection Counter for a given EventId.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x3e
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \note        AUTOSAR R3.0 API
 * \param[in]   EventId                       Provide the EventId value the fault detection counter is requested
 *                                            for. If the return value of the function is other than OK this parameter
 *                                            does not contain valid data.
 * \param[out]  EventIdFaultDetectionCounter  This parameter receives the Fault Detection Counter information of
 *                                            the requested EventId. If the return value of the function call is
 *                                            other than E_OK this parameter does not contain valid data.
 *                                            (-128dec...127dec PASSED...FAILED according to ISO 14229-1)
 * \retval      E_OK      request of FDC was successful
 * \retval      E_NOT_OK  request of FDC failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFaultDetectionCounter(
  Dem_EventIdType                                                 EventId,
  P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)  EventIdFaultDetectionCounter    /* PRQA S 0850 *//* MD_MSR_19.8 */
)
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      Dem_DetReportError(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_PARAM_CONFIG);
    }
    else
#endif
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* event is not available in current variant */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
      Dem_DetReportError(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
# endif  /* DEM_DEV_ERROR_DETECT */
    }
    else
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
    {
      *EventIdFaultDetectionCounter = Dem_FaultDetectionCounterPtr[EventId];
      returnValue = E_OK;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_UNINIT);
  }
#endif

  return returnValue;
}

#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
/**********************************************************************************************************************
  Dem_GetOccurrenceCounter
**********************************************************************************************************************/
/** Read the DEM internal implemented OccurrenceCounter of an event.
 *  The API shall be used by SW-C to request the current Occurrence Counter for a given EventId.
 * \return      Std_ReturnType
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Reentrant
 * \note        CALLED BY    RTE/SW-C
 * \param[in]   EventId                 Provide the EventId value the occurrence counter is requested for.
 *                                      If the return value of the function is other than OK this parameter
 *                                      does not contain valid data.
 * \param[out]  OccurrenceCounterValue  This parameter receives the Occurrence Counter information of
 *                                      the requested EventId. If the return value of the function call is
 *                                      other than E_OK this parameter does not contain valid data.
 * \retval      E_OK      request of occurrence counter was successful
 * \retval      E_NOT_OK  request of occurrence counter failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetOccurrenceCounter(
  Dem_EventIdType                         EventId,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  OccurrenceCounterValue                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
)
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if ((EventId == 0) || (EventId > DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      Dem_DetReportError(DEM_GETOCCURRENCECOUNTER_APIID, DEM_E_PARAM_CONFIG);
    }
    else
#endif
    {
      *OccurrenceCounterValue = Dem_DtcOccurrenceCounterPtr[EventId];
      returnValue = E_OK;
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETOCCURRENCECOUNTER_APIID, DEM_E_UNINIT);
  }
#endif

  return returnValue;
}
#endif /* DEM_SUPPORT_OCCURRENCE_COUNTER */


/**********************************************************************************************************************
  Dem_GetOffsetSnapshotRecordDID
**********************************************************************************************************************/
/** Read ROM table to get size and offset of an event specific DID record in event buffer.
 *  Calculate the 'offset' in the snapshot entry and the 'size' of given 'DID' for 'EventId'.
 *  If found, return them with result E_OK,
 *  else let 'offset' and 'size' unmodified and return E_NOT_OK
 * \return      Std_ReturnType
 * \note        REENTRANT    no
 * \note        SYNC/ASYNC   Synchronous
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetFreezeFrameDataByDTC()
 * \param[in]   EventId       event to read
 * \param[in]   RecordNumber  requested record number to read
 * \param[in]   DID           DataId to read for that event
 * \param[out]  offset        offset of DID record in relation to begin of the snapshot (freezeframe)
 * \param[out]  size          size of the DID record
 * \retval      E_OK      success
 * \retval      E_NOT_OK  failed (invalid DID for given EventId)
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetOffsetSnapshotRecordDID(
  Dem_EventIdType                                       EventId,
  uint8                                                 RecordNumber,
  uint16                                                DID,
  P2VAR(uint16,                 AUTOMATIC, AUTOMATIC)   offset,                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(Dem_DataRecordSizeType, AUTOMATIC, AUTOMATIC)   size                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;
  uint16 SsRecIdx;                        /* index to Dem_SnapshotEntryTable[] */
  uint8  SsRecCount;                      /* number of DIDs for current EventId */
  uint16 SsRecBufIdx = 0;                 /* offset in buffer */

  DEM_IGNORE_UNUSED_ARG(RecordNumber);                                                            /* PRQA S 3112 *//* MD_DEM_14.2 */

  SsRecIdx   = DemCfg_GetFirstSnapshot(EventId);
  SsRecCount = DemCfg_GetCountOfSnapshotDIDs(EventId);

  while (SsRecCount != 0)
  {
    --SsRecCount;
    if (DID != DemCfg_GetSnapshotDID(SsRecIdx))
    {
      SsRecBufIdx = SsRecBufIdx + (uint16) DemCfg_GetSnapshotDIDDataSize(SsRecIdx);
      ++SsRecIdx;
    }
    else
    { /* found the requested DID */
      *offset = SsRecBufIdx;
      *size   = DemCfg_GetSnapshotDIDDataSize(SsRecIdx);
      returnValue = E_OK;
      /* abort the loop */
      break;
    }
  }

  return returnValue;
}


/**********************************************************************************************************************
  Dem_GetOffsetSnapshotRecordNth
**********************************************************************************************************************/
/** Read ROM table to get (next) DID record size and DID number of an event; call multiple times to get all DIDs.
 *  For 'RecordNumber' of 'EventId' iterate over all defined DIDs and return the 'did' and the 'size' of the data value.
 *  Start with '*Iterator' set to 0 to get the first DID, the next call will return the next data set.
 *  If a data set exists return its values in related args with result E_OK,
 *  else (no more data) leave 'did' and 'size' unmodified and return E_NOT_OK.
 * \return      Std_ReturnType
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetFreezeFrameDataByDTC()
 * \param[in]   EventId       event to read
 * \param[in]   RecordNumber  requested record number to read
 * \param[in,out] Iterator    counter to get next DID entry; set to 0 to get the first DID
 * \param[out]  did           DID record number
 * \param[out]  size          size of the DID record
 * \retval      E_OK      success
 * \retval      E_NOT_OK  failed - no more data
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetOffsetSnapshotRecordNth(
  Dem_EventIdType                                       EventId,
  uint8                                                 RecordNumber,
  P2VAR(uint8,                  AUTOMATIC, AUTOMATIC)   Iterator,                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(uint16,                 AUTOMATIC, AUTOMATIC)   did,                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(Dem_DataRecordSizeType, AUTOMATIC, AUTOMATIC)   size                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Std_ReturnType returnValue = E_NOT_OK;
  uint16 SsRecIdx;                        /* index to Dem_SnapshotEntryTable[] */

  DEM_IGNORE_UNUSED_ARG(RecordNumber);                                                            /* PRQA S 3112 *//* MD_DEM_14.2 */

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DemCfg_GetCountOfSnapshotDIDs(EventId) >= 255)
  {
    Dem_DetReportError(DEM_GETOFFSETSNAPSHOTRECORDNTH_APIID, DEM_E_TOO_MANY_DIDS_FOR_EVENT);
  }
#endif

  if (*Iterator < DemCfg_GetCountOfSnapshotDIDs(EventId))
  {
    SsRecIdx = DemCfg_GetFirstSnapshot(EventId) + (*Iterator);

    *did = DemCfg_GetSnapshotDID(SsRecIdx);
    *size = DemCfg_GetSnapshotDIDDataSize(SsRecIdx);
    ++(*Iterator);
    returnValue = E_OK;
  }
  /* else: no more data.  returnValue = E_NOT_OK; */

  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetDTCOfFreezeFrameRecord
**********************************************************************************************************************/
/** Return the DTC associated with the FreezeFrame selected via its absolute record number.
 * \return      Status of the operation of type Dem_ReturnGetDTCOfFreezeFrameRecordType.
 * \note        SERVICE ID   0x1c
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1903, 0x1905
 * \note        AUTOSAR R3.0 API
 * \attention   The record number has to be unique throughout the whole ECU. This function is only required for
 *              OBD-relevant ECUs.
 *              For current implementation the record numbers are relative, so this function will always return the 
 *              first stored DTC. 
 * \param[in]   RecordNumber  This parameter is a unique identifier for a FreezeFrame record as defined in
 *                            ISO15031-5 and ISO14229-1.
 * \param[in]   DTCOrigin     If the DEM supports more than one event memory this parameter is used to select the
 *                            source memory the DTCs shall be read from.
 * \param[in]   DTCKind       This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[out]  DTC           Receives the DTC value returned by the function. If the return value of the function
 *                            is other than OK this parameter does not contain valid data.
 * \retval      DEM_GET_DTCOFFF_OK                  DTC successfully returned
 * \retval      DEM_GET_DTCOFFF_WRONG_RECORD        Wrong record
 * \retval      DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD   No DTC for record available
 * \retval      DEM_GET_DTCOFFF_WRONG_DTCKIND       DTC kind wrong
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE)                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCOfFreezeFrameRecord(
  uint8                                         RecordNumber,
  Dem_DTCOriginType                             DTCOrigin,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC                                               /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetDTCOfFreezeFrameRecordType returnValue = DEM_GET_DTCOFFF_WRONG_RECORD;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (DTC == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETDTCOFFREEZEFRAMERECORD_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((!Dem_IsSupportedDtcOrigin(DTCOrigin)) || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)))
  {
    Dem_DetReportError(DEM_GETDTCOFFREEZEFRAMERECORD_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    /* return the oldest DTC which has the requested record */
    if (FALSE == Dem_IsValidSsRecordNumber(RecordNumber))
    {
      /* Record number is out of valid range */
      returnValue = DEM_GET_DTCOFFF_WRONG_RECORD;
    }
    else
    {
      Dem_EventIdType EventId;
      Dem_DtcChronoRefType chronoIndex;
      Dem_DtcChronoRefType priMemIndex;
    
      returnValue = DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD;
      /* iterate over chrono stack to find first (oldest) DTC with requested record number */
      for (chronoIndex = 0; chronoIndex < *Dem_ChronoPriMemUsedPtr; ++chronoIndex)
      {
        EventId = Dem_GetEventIdOfEntry(chronoIndex);
        /* get the number of snapshots stored with this DTC */
        priMemIndex = Dem_GetPriMemIndexFromChronoIndex(chronoIndex);
    
        if (FALSE == Dem_CheckUsedSsRecordNumber(RecordNumber, priMemIndex))
        { /* RecordNumber not used with this DTC (yet), too few records are stored. Try next DTC */
          continue;                                                                               /* PRQA S 0770 *//* MD_DEM_14.5 */
        }
    
        /* current DTC has set enough records, do further checks */
        if ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DemCfg_GetDTCKind(EventId)))        /* PRQA S 3415 *//* MD_DEM_12.4 */
        {
          if (((1u<<DTCOrigin) & DemCfg_GetDTCOrigin(EventId)) != 0)
          {
            /* found - return current EventId's DTC number */
            *DTC = DemCfg_GetDTCnumber(EventId);
            returnValue = DEM_GET_DTCOFFF_OK;
            /* Abort search */
            break;
          }
        }
        /* DTC has incorrect DTCKind or DTCOrigin, continue the search */
      }
      /* no event found for given RecordNumber/DTCOrigin/DTCKind */
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETDTCOFFREEZEFRAMERECORD_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetFreezeFrameDataIdentifierByDTC
**********************************************************************************************************************/
/** Read count of DIDs and the DID numbers for a given, currently stored DTC.
 *  This function shall be used to return the data identifiers and the number of data identifiers of a FreezeFrame
 *  which belong to a specific DTC.
 * \return      Status of the operation of type Dem_ReturnGetFreezeFrameDataIdentifierByDTCType.
 * \note        SERVICE ID   0x1e
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1904, 0x1905
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC           This is the DTC the FreezeFrame is assigned to.
 * \param[in]   DTCKind       This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin     If the DEM supports more than one event memory this parameter is used to select the
 *                            source memory the DTCs shall be read from.
 * \param[in]   RecordNumber  This parameter is a unique identifier for a FreezeFrame record as defined in
 *                            ISO15031-5 and ISO14229-1.
 * \param[out]  ArraySize     This parameter specifies the number of data identifiers for the selected RecordNumber.
 * \param[out]  DataId        Pointer to an array with the supported data identifiers for the selected RecordNumber
 *                            and DTC.
 * \retval      DEM_GET_ID_OK               FreezeFrame data identifier successfully returned
 * \retval      DEM_GET_ID_WRONG_DTC        Wrong DTC
 * \retval      DEM_GET_ID_WRONG_DTCORIGIN  Wrong DTC origin
 * \retval      DEM_GET_ID_WRONG_DTCKIND    DTC kind wrong
 * \retval      DEM_GET_ID_WRONG_FF_TYPE    FreezeFrame type wrong
 *********************************************************************************************************************/
/** \note
Extension: The function returns the 'DataId' array for _currently_ stored DTCs only!
           If the DID exists but is not in the chrono stack (thus cannot be reported), the
           function returns DEM_GET_ID_OK with ArraySize:=0 while DataId stays unmodified
*/
FUNC(Dem_ReturnGetFreezeFrameDataIdentifierByDTCType, DEM_CODE)                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFreezeFrameDataIdentifierByDTC(
  Dem_DTCType                                             DTC,
  Dem_DTCKindType                                         DTCKind,
  Dem_DTCOriginType                                       DTCOrigin,
  uint8                                                   RecordNumber,
  P2VAR(uint8,                 AUTOMATIC, DEM_APPL_DATA)  ArraySize,              /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  P2VAR(Dem_RecordDIDAddrType, AUTOMATIC, DEM_APPL_DATA)  DataId  /* const uint16 **DataId */  /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetFreezeFrameDataIdentifierByDTCType returnValue = DEM_GET_ID_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((ArraySize == NULL_PTR) || (DataId == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATAIDENTIFIERBYDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((!Dem_IsSupportedDtcOrigin(DTCOrigin)) || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)))
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATAIDENTIFIERBYDTC_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      if (DemCfg_GetCountOfSnapshotRecNumbers(EventId) > 0)
      {
        if (DEM_IS_SET_STORED_DTC(EventId))
        {
          Dem_DtcChronoRefType priMemStackIndex;
          priMemStackIndex = Dem_GetPriMemStackIndex(EventId);

          if (FALSE != Dem_CheckUsedSsRecordNumber(RecordNumber, priMemStackIndex))
          { /* specified RecordNumber is available */
            *ArraySize = DemCfg_GetCountOfSnapshotDIDs(EventId);
            *DataId = DemCfg_GetSnapshotDIDAddr(DemCfg_GetFirstSnapshot(EventId));
            returnValue = DEM_GET_ID_OK;
          }
          else
          { /* specific RecordNumber, but (currently) not available */
            returnValue = DEM_GET_ID_WRONG_FF_TYPE;            /* invalid RecordNumber */
          }
        }
        else if (FALSE != Dem_IsValidSsRecordNumber(RecordNumber))
        { /* valid EventId, valid RecordNumber but currently no such entry in the primary memory stack */
          *ArraySize = 0;
          returnValue = DEM_GET_ID_OK;          /* See ESCAN00042368: for valid record numbers the DEM shall respond with OK to the DCM */
        }
        else /* invalid RecordNumber for this DTC - result DEM_GET_ID_WRONG_DTC already set */
        {}   /* satisfy MISRA-C:2004 Rule 14.10: requires else for if-else-if statements */
      }
      /* else: DTC has no snapshot records - result DEM_GET_ID_WRONG_DTC already set */
    }
    /* else: no such DTC - result DEM_GET_ID_WRONG_DTC already set */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATAIDENTIFIERBYDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetFreezeFrameDataByDTC
**********************************************************************************************************************/
/** Copy Freezeframe/Snapshot record to DestBuffer.
 *  This function shall be used to copy a specific PID/DataId of a FreezeFrame selected via the associated DTC
 *  number and an optional FreezeFrame RecordNumber to the destination buffer. Shall be transmitted as complete
 *  record with format PID followed by data, PID - data, ... The DCM does not know the DEM internal structure so
 *  it asks per Identifier to get special PIDs for instance, not intended to get all FreezeFrame data value by
 *  value. In case of DataId=0xffff all FreezeFrame Data will be transferred at once.
 * \return      Status of the operation of type Dem_ReturnGetFreezeFrameDataByDTCType.
 * \note        SERVICE ID   0x1d
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1904, 0x1905
 * \note        AUTOSAR R3.0 API
 * \attention   Assumptions: The software engineer implementing the DEM shall be an expert in OBD-relevant onboard
 *              diagnostics and familiar with the services as defined in ISO15031-5.
 * \param[in]   DTC           This is the DTC the FreezeFrame is assigned to.
 * \param[in]   DTCKind       This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin     If the DEM supports more than one event memory this parameter is used to select the
 *                            source memory the DTCs shall be read from.
 * \param[in]   RecordNumber  This parameter is a unique identifier for a FreezeFrame record as defined in
 *                            ISO15031-5 and ISO14229-1.
 * \param[in]   DataId        This parameter specifies the PID (ISO15031-5) (Mode2 individual parameter or the
 *                            whole FreezeFrame data set) or data identifier (ISO14229-1) that shall be copied to
 *                            the destination buffer.
 * \param[in,out] BufSize     When the function is called this parameter contains the maximum number of data bytes
 *                            that can be written to the buffer.
 *                            The function returns the actual number of written data bytes in this parameter.
 * \param[out]  DestBuffer    This parameter contains a byte pointer that points to the buffer to which the
 *                            FreezeFrame data shall be written.
 * \retval      DEM_GET_FFDATABYDTC_OK                  FreezeFrame data successfully returned
 * \retval      DEM_GET_FFDATABYDTC_WRONG_DTC           Wrong DTC
 * \retval      DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN     Wrong DTC origin
 * \retval      DEM_GET_FFDATABYDTC_WRONG_DTCKIND       DTC kind wrong
 * \retval      DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER  Wrong Record Number
 * \retval      DEM_GET_FFDATABYDTC_WRONG_DATAID        Wrong DataID
 * \retval      DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE    provided buffer size to small
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)        /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFreezeFrameDataByDTC(
  Dem_DTCType                             DTC,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  uint8                                   RecordNumber,
  uint16                                  DataId,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,        /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  BufSize            /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetFreezeFrameDataByDTCType returnValue = DEM_GET_FFDATABYDTC_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATABYDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((!Dem_IsSupportedDtcOrigin(DTCOrigin)) || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)))
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATABYDTC_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))         /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      if (DemCfg_GetCountOfSnapshotRecNumbers(EventId) > 0)
      { /* by configuration, this event has snapshots */
        if (FALSE == Dem_IsValidSsRecordNumber(RecordNumber))
        { /* invalid RecordNumber */
          returnValue = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        }
        else if (DEM_IS_SET_STORED_DTC(EventId))
        {
          Dem_DtcChronoRefType primaryMemoryIndex = Dem_GetPriMemStackIndex(EventId);
          if (primaryMemoryIndex < DemCfg_GetMaxCountOfPriMemStack())
          {
            /* check if RecordNumber is (currently) available with DTC */
            /* Note: RecordNumber 0xff is no wildcard for 'all records' here! If needed, DCM must explicitly iterate over the valid numbers */
            if (FALSE != Dem_CheckUsedSsRecordNumber(RecordNumber, primaryMemoryIndex))
            {
              P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA ) snapshotBuffer;              /* PRQA S 0850 *//* MD_MSR_19.8 */

              snapshotBuffer = Dem_GetPrimaryStackBufferPtr(primaryMemoryIndex);    /* stack entry for requested event */
              snapshotBuffer = &snapshotBuffer[Dem_PriMemSnapshotNthRecordOffset(RecordNumber - DemCfg_GetFirstOccurredRecordNr())];
              /* add offset for n-th snapshot record */
              if (DataId != DEM_GET_FFDATA_ID_ALL)      /* PRQA S 0715 NONCONFORMING *//* MD_DEM_1.1_0715 */
              { /* single DID is requested */
                uint16                  offset;
                Dem_DataRecordSizeType  size;
                if (E_OK == Dem_GetOffsetSnapshotRecordDID(EventId, RecordNumber, DataId, &offset, &size))
                {
                  if ((size+2) <= *BufSize)
                  {
                    *DestBuffer = Dem_GetHiByte(DataId);
                    DestBuffer = &DestBuffer[1];                                      /*  MISRA improvement for: ++DestBuffer; */
                    *DestBuffer = Dem_GetLoByte(DataId);
                    DestBuffer = &DestBuffer[1];                                      /*  MISRA improvement for: ++DestBuffer; */
                    Dem_MemMove(DestBuffer, &snapshotBuffer[offset], (uint16) size);
                    *BufSize = (uint8)(size+2);
                    returnValue = DEM_GET_FFDATABYDTC_OK;
                  }
                  else
                  { /* result buffer to small */
                    returnValue = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
                  }
                }
              }                                        /* PRQA L:NONCONFORMING */
              else
              { /* all DIDs shall be returned */
                uint8 iter = 0;
                uint16 dId;
                Dem_DataRecordSizeType size;
                uint8 bufferSizeFree = *BufSize;    /* remaining unused bytes in buffer */
                uint16 offset = 0;

                returnValue = DEM_GET_FFDATABYDTC_OK;
                while (E_OK == Dem_GetOffsetSnapshotRecordNth(EventId, RecordNumber, &iter, &dId, &size)) /* PRQA S 0715 NONCONFORMING *//* MD_DEM_1.1_0715 */
                {
                  if ((size+2) <= bufferSizeFree)
                  {
                    *DestBuffer = Dem_GetHiByte(dId);
                    DestBuffer = &DestBuffer[1];                                      /*  MISRA improvement for: ++DestBuffer; */
                    *DestBuffer = Dem_GetLoByte(dId);
                    DestBuffer = &DestBuffer[1];                                      /*  MISRA improvement for: ++DestBuffer; */
                    Dem_MemMove(DestBuffer, &snapshotBuffer[offset], (uint16) size);
                    DestBuffer = &DestBuffer[size];                                   /*  MISRA improvement for: DestBuffer += size */
                    offset = offset + (uint16) size;
                    bufferSizeFree = (uint8)(bufferSizeFree - (size+2));
                  }
                  else
                  { /* result buffer to small */
                    returnValue = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
                    break;
                  }
                }                                                                                           /* PRQA L:NONCONFORMING */
                *BufSize = (uint8)(*BufSize - bufferSizeFree);
              }
            }
            else
            { /* valid EventId but no entry in chrono stack */
              *BufSize = 0;
              returnValue = DEM_GET_FFDATABYDTC_OK;               /* See ESCAN00042368: for valid record numbers the DEM shall respond with OK to the DCM */
            }
          }
          else
          { /* valid EventId but no entry in chrono stack */
            *BufSize = 0;
            returnValue = DEM_GET_FFDATABYDTC_OK;               /* See ESCAN00042368: for valid record numbers the DEM shall respond with OK to the DCM */
          }
        }
        else
        { /* valid EventId but no entry in chrono stack */
          *BufSize = 0;
          returnValue = DEM_GET_FFDATABYDTC_OK;               /* See ESCAN00042368: for valid record numbers the DEM shall respond with OK to the DCM */
        }
      }
      else
      { /* valid EventId but no snapshots configured */
        returnValue = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
      }
    }
    /* else: no such EventId - result _WRONG_DTC already set */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETFREEZEFRAMEDATABYDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetSizeOfFreezeFrame
**********************************************************************************************************************/
/** Get the size of the requested FreezeFrame record.
 *  This size only represents the number of user data bytes (pure FreezeFrame data) and does not contain any
 *  FreezeFrame structure information.
 * \return      Status of the operation of type Dem_ReturnGetSizeOfFreezeFrameType
 * \note        SERVICE ID   0x1f
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1904, 0x1905
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC                 This is the DTC the FreezeFrame is assigned to.
 * \param[in]   DTCKind             This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin           If the DEM supports more than one event memory this parameter is used to select
 *                                  the source memory the DTCs shall be read from.
 * \param[in]   RecordNumber        This parameter is a unique identifier for a FreezeFrame record as defined in
 *                                  ISO15031-5 and ISO14229-1.
 * \param[out]  SizeOfFreezeFrame   Number of bytes in the requested FreezeFrame.
 * \retval      DEM_GET_SIZEOFFF_OK               Size successfully returned.
 * \retval      DEM_GET_SIZEOFFF_WRONG_DTC        Wrong DTC
 * \retval      DEM_GET_SIZEOFFF_WRONG_DTCOR      Wrong DTC origin
 * \retval      DEM_GET_SIZEOFFF_WRONG_DTCKIND    DTC kind wrong
 * \retval      DEM_GET_SIZEOFFF_WRONG_RNUM       Wrong Record Number
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE)                                                /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSizeOfFreezeFrame(
  Dem_DTCType                               DTC,
  Dem_DTCKindType                           DTCKind,
  Dem_DTCOriginType                         DTCOrigin,
  uint8                                     RecordNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfFreezeFrame                                     /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetSizeOfFreezeFrameType returnValue = DEM_GET_SIZEOFFF_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (SizeOfFreezeFrame == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETSIZEOFFREEZEFRAME_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((!Dem_IsSupportedDtcOrigin(DTCOrigin)) || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)))
  {
    Dem_DetReportError(DEM_GETSIZEOFFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;
    
    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
      if ( (FALSE != Dem_IsValidSsRecordNumber(RecordNumber))                                     /* PRQA S 3415 *//* MD_DEM_12.4 */
        && ((DemCfg_GetCountOfSnapshotRecNumbers(EventId) > 0)) )
      {
        Dem_DtcChronoRefType primaryMemoryIndex;
        *SizeOfFreezeFrame = 0;         /* event and record number are defined */
    
        primaryMemoryIndex = Dem_GetPriMemStackIndex(EventId);
        if (primaryMemoryIndex < DemCfg_GetMaxCountOfPriMemStack())
        {
          if (FALSE != Dem_CheckUsedSsRecordNumber(RecordNumber, primaryMemoryIndex))
          {
            uint8  SsRecCount;
            uint16 SsRecIdx;
            uint16 SsRecSize;

            SsRecCount = DemCfg_GetCountOfSnapshotDIDs(EventId);
            SsRecIdx   = DemCfg_GetFirstSnapshot(EventId);
            SsRecSize  = (uint16) (2 * SsRecCount);   /* each DID number has 2 Byte length */
            while (SsRecCount != 0)
            {
              SsRecCount--;
              SsRecSize = SsRecSize + (uint16) DemCfg_GetSnapshotDIDDataSize(SsRecIdx); /* add size of each DID data value */
              SsRecIdx++;
            }
    
            *SizeOfFreezeFrame = SsRecSize;
          }
          /* else: EventId available in primary memory but RecordNumber currently not used: *SizeOfFreezeFrame = 0; */
        }
        /* else: valid EventId and RecordNumber but no such entry in the chrono stack: *SizeOfFreezeFrame = 0; */
    
        returnValue = DEM_GET_SIZEOFFF_OK;
      }
      else
      { /* valid EventId but invalid RecordNumber */
        returnValue = DEM_GET_SIZEOFFF_WRONG_RNUM;
      }
    }
    /* else: no such DTC - result _WRONG_DTC already set */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETSIZEOFFREEZEFRAME_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetExtendedDataRecordByDTC
**********************************************************************************************************************/
/** Get ExtendedData record for requested DTC.
 *  This function shall be used to return the complete Extended Data Record for the requested DTC.
 *  The format of the data is raw hexadecimal values and is not standardized to comply with predefined scaling methods.
 * \return      Status of the operation of type Dem_ReturnGetExtendedDataRecordByDTCType.
 * \note        SERVICE ID   0x20
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1906 1910
 * \note        CONFIG       Values of 'Extended Data Record' have to be defined.
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC                 This is the DTC the 'Extended Data Record' is assigned to.
 * \param[in]   DTCKind             This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin           If the DEM supports more than one event memory this parameter is used to select
 *                                  the source memory the DTCs shall be read from.
 * \param[in]   ExtendedDataNumber  Identification of requested Extended data record. The requested record is
 *                                  copied to the destination buffer.
 * \param[in,out] BufSize           When the function is called this parameter contains the maximum number of data
 *                                  bytes that can be written to the buffer.
 *                                  The function returns the actual number of written data bytes in this parameter.
 * \param[out]  DestBuffer          This parameter contains a byte pointer that points to the buffer to which the
 *                                  Extended Data shall be written.
 * \retval      DEM_RECORD_OK                 Extended data record successfully returned
 * \retval      DEM_RECORD_WRONG_DTC          Wrong DTC
 * \retval      DEM_RECORD_WRONG_DTCORIGIN    Origin wrong
 * \retval      DEM_RECORD_WRONG_DTCKIND      DTC kind wrong
 * \retval      DEM_RECORD_WRONG_NUMBER       Record number wrong
 * \retval      DEM_RECORD_WRONG_BUFFERSIZE   Provided buffer to small
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)                                          /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetExtendedDataRecordByDTC(
  Dem_DTCType                             DTC,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  uint8                                   ExtendedDataNumber,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_ReturnGetExtendedDataRecordByDTCType returnValue = DEM_RECORD_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if ((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
  {
    Dem_DetReportError(DEM_GETEXTENDEDDATARECORDBYDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ( (!Dem_IsSupportedDtcOrigin(DTCOrigin))
    || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
    )
  {
    Dem_DetReportError(DEM_GETEXTENDEDDATARECORDBYDTC_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    { /* valid DTC Number */
      volatile P2VAR( uint8, AUTOMATIC, DEM_APPL_DATA )  storedRecordPtr = NULL_PTR;  /* buffer pointer for individual records */ /* PRQA S 0850 *//* MD_MSR_19.8 */
      uint16 storedRecordSize = 0;

#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
      /* Extended data is event specific, first handle the records that are always available (for all events) */
      if (Dem_OccurrenceCtr_ExtDataRecNum == ExtendedDataNumber)
      {
        storedRecordSize = 1;
        storedRecordPtr = &Dem_DtcOccurrenceCounterPtr[EventId];
      }
      else
#endif
      /* Extended data is event specific, some records are available only if a primary memory entry exists. */
      {
        uint16_least srcOffset;                                   /* Offset inside this event's data record */
        uint16_least recordIndex;
        uint16_least recordIndexLast;

        /* offset of ext. data record's data in event entry */
        srcOffset = Dem_PriMemExtendedRecordOffset();

        /* iterate the records to find the requested number */
        recordIndex = DemCfg_GetFirstExtendedRecord(EventId);     /* first index in ExtDataRecordTable */
        recordIndexLast = recordIndex + (uint16_least) DemCfg_GetCountOfCurrentExtendedRecord(EventId);    /* last + 1 */      /* incorrect: MISRA Rule 44 */
        for (; recordIndex < recordIndexLast; ++recordIndex)
        {
#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
          /* ignore records that are not stored in the PrimaryMemory, but stored globally (they were already handled above) */
          if (Dem_OccurrenceCtr_ExtDataRecNum == DemCfg_GetExtendedRecordNumber(recordIndex))
          {
            continue;                                                                           /* PRQA S 0770 *//* MD_DEM_14.5 */
          }
#endif
          if (ExtendedDataNumber == DemCfg_GetExtendedRecordNumber(recordIndex))
          { /* found the requested extended record number */
            break;
          }
          /* add sizes of skipped records to calculate offset in PrimaryMemory record */
          srcOffset = srcOffset +(uint16_least) DemCfg_GetExtendedRecordNumberDataSize(recordIndex);
        }

        if (recordIndex < recordIndexLast)
        { /* found requested ext. data record number */
          /* now scan, if this record is currently available in the primary memory */
          Dem_DtcChronoRefType primaryMemoryIndex = Dem_GetPriMemStackIndex(EventId);
          if (primaryMemoryIndex < DemCfg_GetMaxCountOfPriMemStack())
          { /* Event is currently stored in primary memory stack */
            storedRecordPtr = Dem_GetPrimaryStackBufferPtr(primaryMemoryIndex);
            storedRecordPtr = &storedRecordPtr[srcOffset];                              /*  MISRA improvement for: storedRecordPtr += srcOffset; */
            storedRecordSize = DemCfg_GetExtendedRecordNumberDataSize(recordIndex);
          }
          else
          { /* event not in primary memory, but valid record number */
            returnValue = DEM_RECORD_OK;          /* See ESCAN00042368: for valid record numbers the DEM shall respond with OK to the DCM */
            *BufSize = 0;
          }
        }
        else
        { /* no such extended record number defined for this event */
          returnValue = DEM_RECORD_WRONG_NUMBER;
          *BufSize = 0;
        }
      }

      /* If the found record fits into the DCM buffer copy it now */
      if (NULL_PTR != storedRecordPtr)
      {
        if ((uint16)(*BufSize) >= storedRecordSize)
        {
          *BufSize = (uint8) storedRecordSize;
          while (storedRecordSize > 0)
          {
            --storedRecordSize;
            DestBuffer[storedRecordSize] = storedRecordPtr[storedRecordSize];
          }
          returnValue = DEM_RECORD_OK;
        }
        else
        { /* Buffer in DCM too small */
          returnValue = DEM_RECORD_WRONG_BUFFERSIZE;
          *BufSize = 0;
        }
      }
      /* else: no record found - 'returnValue' and 'BufSize' are already set */
    }
    /* else: No such DTC - returnValue WRONG_DTC already set */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETEXTENDEDDATARECORDBYDTC_APIID, DEM_E_UNINIT);
  }
#endif /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_GetSizeOfExtendedDataRecordByDTC
**********************************************************************************************************************/
/** Get size of ExtendedData record for requested DTC.
 *  The API shall be used to return the size of the requested 'Extended Data Record' frame. This size only
 *  represents the number of user data bytes stored in the 'Extended Data Record'.
 * \return      Status of the operation of type Dem_ReturnGetSizeOfExtendedDataRecordByDTCType
 * \note        SERVICE ID   0x21
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1906 1910
 * \note        CONFIG       Values of 'Extended Data Record' have to be defined.
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC                         This is the DTC the 'Extended Data Record' is assigned to.
 * \param[in]   DTCKind                     This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin                   If the DEM supports more than one event memory this parameter is used
 *                                          to select the source memory the DTCs shall be read from.
 * \param[in]   ExtendedDataNumber          Identification of requested Extended data record. The requested record
 *                                          is copied to the destination buffer.
 * \param[out]  SizeOfExtendedDataRecord    Pointer to Size of the requested data record
 * \retval      DEM_GET_SIZEOFEDRBYDTC_OK         Size successfully returned.
 * \retval      DEM_GET_SIZEOFEDRBYDTC_W_DTC      Wrong DTC
 * \retval      DEM_GET_SIZEOFEDRBYDTC_W_DTCOR    Wrong DTC origin
 * \retval      DEM_GET_SIZEOFEDRBYDTC_W_DTCKI    DTC kind wrong
 * \retval      DEM_GET_SIZEOFEDRBYDTC_W_RNUM     Wrong Record Number
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE)                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSizeOfExtendedDataRecordByDTC(
  Dem_DTCType                               DTC,
  Dem_DTCKindType                           DTCKind,
  Dem_DTCOriginType                         DTCOrigin,
  uint8                                     ExtendedDataNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfExtendedDataRecord                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  Dem_ReturnGetSizeOfExtendedDataRecordByDTCType returnValue = DEM_GET_SIZEOFEDRBYDTC_W_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (SizeOfExtendedDataRecord == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else if ((!Dem_IsSupportedDtcOrigin(DTCOrigin))
    || ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
    )
  {
    Dem_DetReportError(DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_APIID, DEM_E_PARAM_DATA);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()) )                             /* PRQA S 3415 *//* MD_DEM_12.4 */
    {
#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
      /* Extended data is event specific, first handle the records that are always available */
      if (Dem_OccurrenceCtr_ExtDataRecNum == ExtendedDataNumber)
      {
        returnValue = DEM_GET_SIZEOFEDRBYDTC_OK;
        *SizeOfExtendedDataRecord = 1;
      }
      else
#endif
      {
        /* Extended data is event specific, some records are available only if a primary memory entry exists. */
        uint16_least  i = DemCfg_GetFirstExtendedRecord(EventId);
        uint16_least  lastIdx = i + (uint16_least) DemCfg_GetCountOfCurrentExtendedRecord(EventId); /* set to (last+1)-th index */
        
        /* set default values if record is not found */
        returnValue = DEM_GET_SIZEOFEDRBYDTC_W_RNUM;
        *SizeOfExtendedDataRecord = 0;
        
        /* iterate the records to find the requested number */
        for (; i < lastIdx; ++i)
        {
          if (DemCfg_GetExtendedRecordNumber(i) == ExtendedDataNumber)
          { /* found the requested extended record number */
            returnValue = DEM_GET_SIZEOFEDRBYDTC_OK;
            if (Dem_GetPriMemStackIndex(EventId) != DemCfg_GetMaxCountOfPriMemStack())
            { /* valid extended record number AND record is currently stored in PriMem */
              *SizeOfExtendedDataRecord = DemCfg_GetExtendedRecordNumberDataSize(i);
            }
            /* else: *SizeOfExtendedDataRecord = 0; already set as result for "valid record number, but currently not available" */
            break;
          }
        }
      }
    }
    /* else: returnValue WRONG_DTC already set */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_ClearSingleEvent
**********************************************************************************************************************/
/** Clear the given EventId.
 *  All checks have to be done before calling this func: valid EventId, deletion is permitted, ...
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_DoClearSingleEvent()
 *                                    Dem_DoClearGroupOfEvents()
 *                                    Dem_DoJ1939ClearPassiveDTCs() [if supported]
 * \param[in]   EventId      event that shall be cleared
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearSingleEvent(
  Dem_EventIdType   EventId
  )
{
  boolean               isStatusUnchanged;
  Dem_DtcStatusByteType lDtcStatusByte;

  /* make a local copy of current status byte to check (later) for status change */
  lDtcStatusByte = Dem_DtcStatusBytePtr[EventId];

  if (DEM_IS_SET_STORED_DTC(EventId) != FALSE)
  {
    Dem_DtcChronoRefType chronoIndex = Dem_GetChronoManagerIndex(EventId);
#if (DEM_DEV_ERROR_DETECT == STD_ON)
    if (chronoIndex >= DemCfg_GetMaxCountOfPriMemStack())
    {
      Dem_DetReportError(DEM_CLEARSINGLEEVENT_APIID, DEM_E_DTC_NOT_FOUND);
    }
#endif
    
    Dem_DeleteDTCinChronoStack(chronoIndex);
  }

  /* Group UNSET macros and group SET macros to benefit from compiler optimizations */
  DEM_UNSET_BIT_TEST_FAILED(EventId);                                                             /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
  DEM_UNSET_BIT_TEST_FAILED_THIS_OC(EventId);                                                     /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_PENDINGDTC_STATUS == STD_ON)
  DEM_UNSET_BIT_PENDING_DTC(EventId);                                                             /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
  DEM_UNSET_BIT_CONFIRMED_DTC(EventId);                                                           /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
  DEM_UNSET_BIT_TEST_FAILED_SINCE_LC(EventId);                                                    /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#if (DEM_ENABLE_WARNINGINDICATOR_STATUS == STD_ON)
  DEM_UNSET_BIT_WARNING_INDICATOR_REQ(EventId);                                                   /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
#endif
  DEM_SET_BIT_TEST_N_COMPL_SINCE_LC(EventId);
  DEM_SET_BIT_TEST_N_COMPL_THIS_OC(EventId);

  /* reset fault detection counter */
  Dem_FaultDetectionCounterPtr[EventId] = 0;
#if (DEM_ENABLE_TIME_BASED_DEBOUNCE == STD_ON)
  Dem_ClearDebounceTimerSlot(EventId);
#endif
#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
  /* reset occurrence counter */
  Dem_DtcOccurrenceCounterPtr[EventId] = 0;
#endif

  /* check if DTC status changed by above code */
  isStatusUnchanged = Dem_IsEqualDtcStatusByte(&lDtcStatusByte, &Dem_DtcStatusBytePtr[EventId]);
  if (FALSE == isStatusUnchanged)
  { /* there is a change - notify application */
    Dem_TriggerOnEvent(EventId, lDtcStatusByte);
  }

  /* call related Xxx_DemInitMonitor{EventId}(CLEAR) function */
  if (!! DemCfg_GetInitMonitorFPtr(EventId))                                                      /* if (func_pointer != NULL) {...}   MISRA/PRQA enforces the strange "if (!!func_pointer)" syntax */
  {
#if (DEM_DEV_ERROR_DETECT == STD_ON)
# if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
    if (! (Dem_IsInActiveVariant(EventId)))
    { /* EventId is not defined for current configuration */
      Dem_DetReportError(DEM_CLEARSINGLEEVENT_APIID, DEM_E_NOT_IN_ACTIVE_VARIANT);
    }
# endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
#endif  /* DEM_DEV_ERROR_DETECT */
    (void)(*DemCfg_GetInitMonitorFPtr(EventId))(DEM_INIT_MONITOR_CLEAR);
  }
}

/**********************************************************************************************************************
  Dem_DoClearSingleEvent
**********************************************************************************************************************/
/** Clear the given EventId (after checking, that clearing is permitted).
 * \return      Std_ReturnType.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \param[in]   EventId      event that shall be cleared
 * \retval      E_OK         DTC successfully cleared
 * \retval      E_NOT_OK     Deletion is not permitted
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoClearSingleEvent(
  Dem_EventIdType   EventId
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_RecordUpdate != DEM_FORBID_EXISTENT_RECORD_UPDATE) || (DEM_IS_UNSET_STORED_DTC(EventId) != FALSE))    /* PRQA S 3415 *//* MD_DEM_12.4 */
  { /* deletion of DTCs is permitted, or there is no PriMem entry for the DTC (so we can ignore any 'ForbidRecordUpdate') */
    Dem_ClearSingleEvent(EventId);
    returnValue = E_OK;
  }
  /* else: deletion is not permitted */

  return returnValue;
}


/**********************************************************************************************************************
  Dem_DoClearGroupOfEvents
**********************************************************************************************************************/
/** Clear the given DTCGroup (after checking, that clearing is permitted).
 * \return      Std_ReturnType.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    no
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \param[in]   BitcodedDtcGroup  DTCGroup that shall be cleared
 * \param[in]   DtcKind           DtcKind that shall be cleared
 * \param[in]   DtcOrigin         DtcOrigin that shall be cleared
 * \retval      E_OK         DTC successfully cleared all specified events
 * \retval      E_NOT_OK     Deletion is not permitted, at least one failed
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE)                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DoClearGroupOfEvents(
  Dem_DTCGroupKindType  BitcodedDTCGroup,
  Dem_DTCKindType       DTCKind,
  Dem_DTCOriginType     DTCOrigin
  )
{
  Dem_EventIdType EventId;
  Std_ReturnType  returnValue = E_OK;

  /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8! */
  for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
  {
    if ( ((BitcodedDTCGroup & DemCfg_GetDTCGroupKind(EventId)) != 0)                          /* event is part of that group */      /* PRQA S 3415 *//* MD_DEM_12.4 */
      && (((1u<<DTCOrigin) & DemCfg_GetDTCOrigin(EventId)) != 0)                              /* event will be stored in that origin */
      && ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DemCfg_GetDTCKind(EventId)))      /* event has given DTCKind or all events are addressed */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      && (Dem_IsInActiveVariant(EventId))
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      )
    {
      if ((Dem_RecordUpdate != DEM_FORBID_EXISTENT_RECORD_UPDATE) || (DEM_IS_UNSET_STORED_DTC(EventId) != FALSE))         /* PRQA S 3415 *//* MD_DEM_12.4 */
      { /* deletion of DTCs is permitted, or there is no PriMem entry for the DTC (so we can ignore any 'ForbidRecordUpdate') */
        Dem_ClearSingleEvent(EventId);
      }
      else
      { /* deletion is not permitted */
        returnValue = E_NOT_OK;
        /* continue deleting other events */
      }
    }
  }
  return returnValue;
}

/**********************************************************************************************************************
  Dem_ClearDTC
**********************************************************************************************************************/
/** Clear DTC or group of DTCs.
 *  This API shall be used to clear
 *  - all the event status related the specified DTC
 *  - all associated event memory entries for these events (environmental and/or FreezeFrame data, ...)
 * \return      Status of the operation of type Dem_ReturnClearDTCType.
 * \note        SERVICE ID   0x22
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x14
 * \note        CONFIG       The initialization of the corresponding Monitor Function (DTC -> EventId ->
 *                           Xxx_DemInitMonitor{EventId}) is managed by Xxx_Dem_InitMonitor{EventId}.
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC         Defines the DTC that shall be cleared from the event memory. If the DTC fits to a DTC
 *                          group number, all DTCs of the group shall be cleared.
 * \param[in]   DTCKind     This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[in]   DTCOrigin   If the DEM supports more than one event memory this parameter is used to select the
 *                          source memory the DTCs shall be cleared from.
 * \retval      DEM_CLEAR_OK                DTC successfully cleared
 * \retval      DEM_CLEAR_WRONG_DTC         Wrong DTC
 * \retval      DEM_CLEAR_WRONG_DTCORIGIN   Wrong DTC origin
 * \retval      DEM_CLEAR_WRONG_DTCKIND     DTC kind wrong
 * \retval      DEM_CLEAR_FAILED            DTC not cleared
 * \retval      DEM_DTC_PENDING             Clearing of DTC is pending
 *********************************************************************************************************************/
FUNC(Dem_ReturnClearDTCType, DEM_CODE)                                                            /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearDTC(
  Dem_DTCType         DTC,
  Dem_DTCKindType     DTCKind,
  Dem_DTCOriginType   DTCOrigin
  )
{
  Dem_ReturnClearDTCType returnValue = DEM_CLEAR_FAILED;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (!Dem_IsSupportedDtcOrigin(DTCOrigin))
  {
    Dem_DetReportError(DEM_CLEARDTC_APIID, DEM_E_PARAM_DATA);
    returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
  }
  else if ((DTCKind != DEM_DTC_KIND_ALL_DTCS) && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
  {
    Dem_DetReportError(DEM_CLEARDTC_APIID, DEM_E_PARAM_DATA);
    returnValue = DEM_CLEAR_WRONG_DTCKIND;
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;
    Dem_DTCGroupKindType BitcodedDTCGroup = Dem_MapGroupNumberToGroupKind(DTC);
    Dem_AQElementType newElement;
    boolean successfulClearDtcRequest = TRUE;

    /* extract the success of former request and reset the 'fail' bit there */
    if ((Dem_AQGetAction( &Dem_FinishedClearDtcRequest ) & DEM_AQACTION_FAILED) != 0u)
    { /* unsuccessful execution of action. Store failure and reset the failure bit */
      successfulClearDtcRequest = FALSE;
      Dem_AQSetAction( &Dem_FinishedClearDtcRequest,                                              /* PRQA S 0277 *//* MD_DEM_3.1_0277 */
                       (uint8) (Dem_AQGetAction( &Dem_FinishedClearDtcRequest ) & (uint8)(~(uint8)DEM_AQACTION_FAILED)));
    }

    if (BitcodedDTCGroup == 0)
    { /* no DTCGroup, single DTC */
      EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DTCOrigin);
      if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                            /* PRQA S 3415 *//* MD_DEM_12.4 */
      { /* existing DTC */
        Dem_AQSetAction(  &newElement, DEM_AQACTION_CLEARSINGLEEVENT);                            /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
        Dem_AQSetEventId( &newElement, EventId );

        /* check, if former clear request is finished now (DTC is cleared) */
        if ( (Dem_AQGetAction( &Dem_FinishedClearDtcRequest )  == DEM_AQACTION_CLEARSINGLEEVENT)
          && (Dem_AQGetEventId( &Dem_FinishedClearDtcRequest ) == EventId) )
        { /* DTC has been cleared */
          if (successfulClearDtcRequest == FALSE)
          {
            returnValue = DEM_CLEAR_FAILED;
          }
          else
          {
            returnValue = DEM_CLEAR_OK;
          }
          Dem_AQSetAction(&Dem_FinishedClearDtcRequest, DEM_AQACTION_NONE);        /* invalidate 'finished request' flag */
        }
        else if ( Dem_AQIsQueued( &newElement ) != FALSE)
        { /* The request is still in the queue, awaiting its work */
          returnValue = DEM_DTC_PENDING;
        }
        else if ((Dem_RecordUpdate == DEM_FORBID_EXISTENT_RECORD_UPDATE) && (DEM_IS_SET_STORED_DTC(EventId) != FALSE))      /* PRQA S 3415 *//* MD_DEM_12.4 */
        { /* deletion is not permitted, do not put the request into the queue */
          returnValue = DEM_CLEAR_FAILED;
        }
        else
        {
          /* the ClearDTC request is put to the queue, the queue will be drained later in Dem_MainFunction() */
          /* Append the new action to queue */
          /* Enter Critical ========================================================== */
          Dem_EnterCritical();
          (void) Dem_AQPush( &newElement );
          /* If the queueing fails (due overflow), the PENDING below will signal DCM to repeat again next cycle */
          Dem_LeaveCritical();
          /* Leave Critical ========================================================== */

          returnValue = DEM_DTC_PENDING;
        }
      }
      else
      { /* unknown DTC */
        returnValue = DEM_CLEAR_WRONG_DTC;
      }
    }
    else if (BitcodedDTCGroup == DEM_DTC_GROUPKIND_ALL_DTCS)
    { /* delete all DTCs */
      Dem_AQSetAction(           &newElement, DEM_AQACTION_CLEARALLDTC);                          /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetBitcodedDTCGroup( &newElement, BitcodedDTCGroup );                                 /* PRQA S 3198 *//* We modify newElement.arg.dtc.BitcodedDtcGroup only once - Bug in PRQA analysis */
      Dem_AQSetDTCKind(          &newElement, DTCKind );                                          /* PRQA S 3198 *//* We modify newElement.arg.dtc.DTCKind only once - Bug in PRQA analysis */
      Dem_AQSetDTCOrigin(        &newElement, DTCOrigin );

      /* check, if former clear request is finished now (DTCs are cleared) */
      if ( (Dem_AQGetAction(           &Dem_FinishedClearDtcRequest ) == DEM_AQACTION_CLEARALLDTC)
        && (Dem_AQGetBitcodedDTCGroup( &Dem_FinishedClearDtcRequest ) == BitcodedDTCGroup)
        && (Dem_AQGetDTCKind(          &Dem_FinishedClearDtcRequest ) == DTCKind)
        && (Dem_AQGetDTCOrigin(        &Dem_FinishedClearDtcRequest ) == DTCOrigin) )
      { /* DTCs have been cleared */
        if (successfulClearDtcRequest == FALSE)
        {
          returnValue = DEM_CLEAR_FAILED;
        }
        else
        {
          returnValue = DEM_CLEAR_OK;
        }
        Dem_AQSetAction(&Dem_FinishedClearDtcRequest, DEM_AQACTION_NONE);        /* invalidate 'finished request' flag  */
      }
      else if ( Dem_AQIsQueued( &newElement ) != FALSE )
      { /* The request is still in the queue, awaiting its work */
        returnValue = DEM_DTC_PENDING;
      }
      else if ((Dem_RecordUpdate == DEM_FORBID_EXISTENT_RECORD_UPDATE) && (*Dem_ChronoPriMemUsedPtr != 0))
      { /* deleting DTCs is prohibited and some DTCs have a chrono stack entry (snapshot) */
        returnValue = DEM_CLEAR_FAILED;
      }
      else
      { /* deletion is permitted, or chrono stack is empty (so we can ignore any 'ForbidRecordUpdate')  */
        /* the ClearDTC is put to the queue, the queue will be drained later in Dem_MainFunction() */
        /* Append the new action to queue */
        /* Enter Critical ========================================================== */
        Dem_EnterCritical();
        (void) Dem_AQPush( &newElement );
        /* If the queueing fails (due overflow), the PENDING below will signal DCM to repeat again next cycle */
        Dem_LeaveCritical();
        /* Leave Critical ========================================================== */

        returnValue = DEM_DTC_PENDING;
      }
    }
    else
    { /* delete Group of DTCs */
      Dem_AQSetAction(           &newElement, DEM_AQACTION_CLEARDTCGROUP);                        /* PRQA S 3198 *//* We modify newElement.Action only once - Bug in PRQA analysis */
      Dem_AQSetBitcodedDTCGroup( &newElement, BitcodedDTCGroup );                                 /* PRQA S 3198 *//* We modify newElement.arg.dtc.BitcodedDtcGroup only once - Bug in PRQA analysis */
      Dem_AQSetDTCKind(          &newElement, DTCKind );                                          /* PRQA S 3198 *//* We modify newElement.arg.dtc.DTCKind only once - Bug in PRQA analysis */
      Dem_AQSetDTCOrigin(        &newElement, DTCOrigin );

      /* check, if former clear request is finished now (DTCs are cleared) */
      if ( (Dem_AQGetAction(           &Dem_FinishedClearDtcRequest ) == DEM_AQACTION_CLEARDTCGROUP)
        && (Dem_AQGetBitcodedDTCGroup( &Dem_FinishedClearDtcRequest ) == BitcodedDTCGroup)
        && (Dem_AQGetDTCKind(          &Dem_FinishedClearDtcRequest ) == DTCKind)
        && (Dem_AQGetDTCOrigin(        &Dem_FinishedClearDtcRequest ) == DTCOrigin) )
      { /* DTCs have been cleared */
        if (successfulClearDtcRequest == FALSE)
        {
          returnValue = DEM_CLEAR_FAILED;
        }
        else
        {
          returnValue = DEM_CLEAR_OK;
        }
        Dem_AQSetAction(&Dem_FinishedClearDtcRequest, DEM_AQACTION_NONE);        /* invalidate 'finished request' flag */
      }
      else if ( Dem_AQIsQueued( &newElement ) != FALSE )
      { /* The request is still in the queue, awaiting its work */
        returnValue = DEM_DTC_PENDING;
      }
      else
      {
        boolean forbidToDelete = FALSE;

        /* check, if there are DTCs that must not be deleted */
        /* count down to beware of type overflow: For exact 255 DTCs 'EventId' is of type uint8!! */
        for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
        {
          if (((BitcodedDTCGroup & DemCfg_GetDTCGroupKind(EventId)) != 0)                         /* event is part of that group */      /* PRQA S 3415 *//* MD_DEM_12.4 */
            && (((1u<<DTCOrigin) & DemCfg_GetDTCOrigin(EventId)) != 0)                            /* event will be stored in that origin */
            && ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DemCfg_GetDTCKind(EventId)))    /* event has given DTCKind or all events are addressed */
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
            && (Dem_IsInActiveVariant(EventId))
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
            )
          {
            if ((Dem_RecordUpdate == DEM_FORBID_EXISTENT_RECORD_UPDATE) && (DEM_IS_SET_STORED_DTC(EventId) != FALSE))     /* PRQA S 3415 *//* MD_DEM_12.4 */
            {                                                                                     /* PRQA S 0715 NONCONFORMING *//* MD_DEM_1.1_0715 */
              /* this DTC has a primary memory entry (snapshot) but record update is prohibited, so it cannot be deleted */
              forbidToDelete = TRUE;
              break;                  /* abort 'for'-loop */
            }                                                                                     /* PRQA L:NONCONFORMING */
          }
        }

        if (TRUE == forbidToDelete)
        { /* at least one DTC is prohibited from deletion */
          returnValue = DEM_CLEAR_FAILED;
        }
        else
        {
          /* the ClearDTC is put to the queue, the queue will be drained later in Dem_MainFunction() */
          /* Append the new action to queue */
          /* Enter Critical ========================================================== */
          Dem_EnterCritical();
          (void) Dem_AQPush( &newElement );
          /* If the queueing fails (due overflow), the PENDING below will signal DCM to repeat again next cycle */
          Dem_LeaveCritical();
          /* Leave Critical ========================================================== */

          returnValue = DEM_DTC_PENDING;
        }
      }
    }
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_CLEARDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}


/**********************************************************************************************************************
  Dem_GetViewIDOfDTC
**********************************************************************************************************************/
/** Get ViewId for requested DTC.
 *  The API provides the capability to get the according ViewId (e.g. wiper system, window lifter,...) of a
 *  specific DTC. The parameter ViewId is equivalent to the parameter FunctionalUnit in ISO14229-1 [9].
 * \attention   This function is not the counterpart to Dem_SetViewFilter! This function shall return the FunctionalUnit.
 * \return      Status of the operation of type Dem_ReturnGetViewIDOfDTCType.
 * \note        SERVICE ID   0x36
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1909
 * \note        AUTOSAR R3.0 API
 * \param[in]   DTC       This parameter defines the requested DTC.
 * \param[in]   DTCKind   This parameter defines the requested DTC, either OBD-relevant or all DTCs.
 * \param[out]  ViewId    The ViewId is a parameter used to select a specific view (ref. to Dem_ViewIdType).
 * \retval      DEM_VIEWID_OK             Status of ViewId is OK
 * \retval      DEM_VIEWID_WRONG_DTC      Wrong DTC
 * \retval      DEM_VIEWID_WRONG_DTCKIND  DTC kind wrong
 *********************************************************************************************************************/
FUNC(Dem_ReturnGetViewIDOfDTCType, DEM_CODE)                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetViewIDOfDTC(
  Dem_DTCType                                       DTC,
  Dem_DTCKindType                                   DTCKind,
  P2VAR(Dem_ViewIdType, AUTOMATIC, DEM_APPL_DATA)   ViewId        /* PRQA S 0850, 3673 *//* MD_MSR_19.8, MD_DEM_16.7 */
  )
{
  Dem_ReturnGetViewIDOfDTCType returnValue = DEM_VIEWID_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (ViewId == NULL_PTR)
  {
    Dem_DetReportError(DEM_GETVIEWIDOFDTC_APIID, DEM_E_PARAM_ADDRESS);
  }
  else
#endif  /* DEM_DEV_ERROR_DETECT */
  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_EventIdType EventId;

    EventId = Dem_GetEventIdOfDTC (DTC, DTCKind, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    if ((EventId > 0) && (EventId <= DemCfg_GetMaxCountOfEventId()))                              /* PRQA S 3415 *//* MD_DEM_12.4 */
    { /* existing DTC */
      /* do NOT return the ViewId...        *ViewId = DemCfg_GetViewId(EventId);
         ...but return the FunctionalUnit of the DTC: */
      *ViewId = (Dem_ViewIdType) DemCfg_GetFunctionalUnit(EventId);
      returnValue = DEM_VIEWID_OK;
    }
    /* else: invalid DTC or DTCKind - no DetReportError, as the DTC number is from external request */
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_GETVIEWIDOFDTC_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}


/**********************************************************************************************************************
  Dem_GetEventIdOfDTC
**********************************************************************************************************************/
/** Return the EventId for the given Dtc/DTCKind/DTCOrigin triple.
 *  If no appropriate event is found, the invalid EventId 0 is returned.
 *  The function does not check, if the DTC is currently stored in the given DTCOrigin!
 * \return      EventId for the given Dtc/DTCKind/DTCOrigin triple
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal in task context of DCM from function
 *                                Dem_GetStatusOfDTC() [API]
 *                                Dem_GetSeverityOfDTC() [API]
 *                                Dem_GetFreezeFrameDataIdentifierByDTC() [API]
 *                                Dem_GetFreezeFrameDataByDTC() [API]
 *                                Dem_GetSizeOfFreezeFrame() [API]
 *                                Dem_GetExtendedDataRecordByDTC() [API]
 *                                Dem_GetSizeOfExtendedDataRecordByDTC() [API]
 *                                Dem_ClearDTC() [API]
 *                                Dem_GetViewIDOfDTC() [API]
 * \attention   To avoid reentrancy problems, call this API in (uninterruptable) task context of DCM only!
 * \param[in]   Dtc         DTC number
 * \param[in]   DTCKind     Kind of DTC: ALL_DTCS or EMISSION_REL_DTCS
 * \param[in]   DTCOrigin   DEM_DTC_ORIGIN_PRIMARY_MEMORY/_SECONDARY_MEMORY/_MIRROR_MEMORY
 * \retval      0      no EventId found for given triple
 * \retval      else   found EventId
 *********************************************************************************************************************/
STATIC FUNC(Dem_EventIdType, DEM_CODE)                           /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventIdOfDTC(
  Dem_DTCType         Dtc,
  Dem_DTCKindType     DTCKind,
  Dem_DTCOriginType   DTCOrigin
  )
{
  /* Use cache realized by variables Dem_CvtDtc2EventIdCacheX;  with X=={Dtc,DTCKind,DTCOrigin,EventId} */
  if ( (Dem_CvtDtc2EventIdCacheDtc != Dtc)                /* current request is different from previous request OR this is the 1st request (Dem_CvtDtc2EventIdCacheDtc==DEM_DTCNUMBER_INVALID) */
    || (Dem_CvtDtc2EventIdCacheDTCKind != DTCKind)        /* current request is different from previous request */
    || (Dem_CvtDtc2EventIdCacheDTCOrigin != DTCOrigin)    /* current request is different from previous request */
    )
  {
    Dem_EventIdType EventId;
    uint8           eventDesinationMask;  /* DTCOrigin as bitmask */

    /* cache the current request for later use */
    Dem_CvtDtc2EventIdCacheDtc = Dtc;
    Dem_CvtDtc2EventIdCacheDTCKind = DTCKind;
    Dem_CvtDtc2EventIdCacheDTCOrigin = DTCOrigin;

    eventDesinationMask = (uint8)(1u<<DTCOrigin);
    for (EventId = DemCfg_GetMaxCountOfEventId(); EventId > 0; --EventId)
    {
#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
      if (! (Dem_IsInActiveVariant(EventId)))
      { /* EventId is not defined for current configuration */
        continue;                                                             /* PRQA S 0770 *//* MD_DEM_14.5 */
      }
#endif /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */
      if (Dtc == DemCfg_GetDTCnumber(EventId))
      {
        if ((DTCKind == DEM_DTC_KIND_ALL_DTCS) || (DTCKind == DemCfg_GetDTCKind(EventId)))        /* PRQA S 3415 *//* MD_DEM_12.4 */
        {
          if ((eventDesinationMask & DemCfg_GetDTCOrigin(EventId)) != 0)
          {
            /* right EventId found - return current EventId */
            break;
          }
        }
      }
    }

    /* cache the current result for later use */
    Dem_CvtDtc2EventIdCacheEventId = EventId;
  }
  /* else: this request is equal to the previous one, Dem_CvtDtc2EventIdCacheEventId contains previous result */

  /* return 0 if not found */
  return Dem_CvtDtc2EventIdCacheEventId;
}


#if (DEM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  Dem_IsSupportedDtcOrigin
**********************************************************************************************************************/
/** Check, if the requested DTCOrigin is supported.
 * \return      boolean
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetStatusOfDTC()
 *                                    Dem_GetDTCOfFreezeFrameRecord()
 *                                    Dem_GetFreezeFrameDataIdentifierByDTC()
 *                                    Dem_GetFreezeFrameDataByDTC()
 *                                    Dem_GetSizeOfFreezeFrame()
 *                                    Dem_GetExtendedDataRecordByDTC()
 *                                    Dem_GetSizeOfExtendedDataRecordByDTC()
 *                                    Dem_ClearDTC()
 * \param[in]   DTCOrigin   DEM_DTC_ORIGIN_PRIMARY_MEMORY/_SECONDARY_MEMORY/_MIRROR_MEMORY
 * \retval      TRUE   origin is available in DEM
 * \retval      FALSE  origin is not available in DEM
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_IsSupportedDtcOrigin(
  Dem_DTCOriginType   DTCOrigin
  )
{
  boolean returnValue;
  if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
  {
    returnValue = TRUE;
  }
# if defined (DEM_TYPE_OF_ORIGIN_SUPPORTED)
#  if ((DEM_TYPE_OF_ORIGIN_SUPPORTED & 0x01) != 0)
  else if (DEM_DTC_ORIGIN_MIRROR_MEMORY == DTCOrigin)
  {
    returnValue = TRUE;
  }
#  endif  /* mask 0x01: MirrorMemory is supported */
#  if ((DEM_TYPE_OF_ORIGIN_SUPPORTED & 0x02) != 0)
  else if (DEM_DTC_ORIGIN_PERMANENT == DTCOrigin)
  {
    returnValue = FALSE;
  }
#  endif /* mask 0x02: PermanentMemory is supported */
#  if ((DEM_TYPE_OF_ORIGIN_SUPPORTED & 0x04) != 0)
  else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin)
  {
    returnValue = TRUE;
  }
#  endif /* mask 0x04: SecondaryMemory is supported */
# endif  /* DEM_TYPE_OF_ORIGIN_SUPPORTED */
  else
  {
    returnValue = FALSE;
  }
  return returnValue;
}
#endif  /* DEM_DEV_ERROR_DETECT */


/**********************************************************************************************************************
  Dem_IsValidSsRecordNumber
**********************************************************************************************************************/
/** Check, if SnapShot 'RecordNumber' is valid in system, i.e.\ defined for this OEM for any DTC.
 *  The function doesn't check, if RecordNumber is currently USED in the chrono stack!
 * \return      boolean
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetDTCOfFreezeFrameRecord()
 *                                    Dem_GetFreezeFrameDataIdentifierByDTC()
 *                                    Dem_GetFreezeFrameDataByDTC()
 *                                    Dem_GetSizeOfFreezeFrame()
 * \param[in]   RecordNumber  number to check
 * \retval      TRUE    RecordNumber is defined for this DEM
 * \retval      FALSE   invalid RecordNumber
 * \note        All events (that have configured freezeframes/snapshots) use the same record numbers
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_IsValidSsRecordNumber(
  uint8             RecordNumber
  )
{
  /* check for valid Snapshot RecordNumber */
  boolean result = TRUE;
  if ((RecordNumber < DemCfg_GetFirstOccurredRecordNr())                                          /* PRQA S 3415 *//* MD_DEM_12.4 */
   || (RecordNumber >= (DemCfg_GetFirstOccurredRecordNr() + DemCfg_GetCountOfSnapshotsPerDTC())))
  {
    result = FALSE;
  }
  return result;
}


/**********************************************************************************************************************
  Dem_CheckUsedSsRecordNumber
**********************************************************************************************************************/
/** Check, if SnapShot 'RecordNumber' is readable off the given PrimaryMemory entry, return index to config when found.
 *  Prove that the snapshot record number is defined for this OEM and currently IN USE with this EventId.
 * \return      TRUE, if RecordNumber is valid and in use
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_GetDTCOfFreezeFrameRecord()
 *                                    Dem_GetFreezeFrameDataIdentifierByDTC()
 *                                    Dem_GetFreezeFrameDataByDTC()
 *                                    Dem_GetSizeOfFreezeFrame()
 * \param[in]   RecordNumber  snapshot record number to check
 * \param[in]   priMemIndex   event entry to check
 * \retval      FALSE    invalid RecordNumber or currently not used at given EventId.
 * \retval      TRUE     RecordNumber is defined for this DEM.
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_CheckUsedSsRecordNumber(
  uint8                 RecordNumber,
  Dem_DtcChronoRefType  priMemIndex
  )
{
  boolean result = TRUE;
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  pSnapshotCount;                                         /* PRQA S 0850 *//* MD_MSR_19.8 */

  if ((priMemIndex < DemCfg_GetMaxCountOfPriMemStack())                                           /* PRQA S 3415 *//* MD_DEM_12.4 */
    && (RecordNumber >= DemCfg_GetFirstOccurredRecordNr()) )
  {
    pSnapshotCount = Dem_GetPrimaryStackBufferPtr(priMemIndex);
    pSnapshotCount = &pSnapshotCount[Dem_PriMemSnapshotUsedCntOffset()];    /*  MISRA improvement for: pSnapshotCount += Dem_PriMemSnapshotUsedCntOffset() */

    /* record numbers are 'DemCfg_GetFirstOccurredRecordNr()'...'DemCfg_GetFirstOccurredRecordNr() + DemCfg_GetCountOfSnapshotsPerDTC() - 1', for example '1'...'21'(=1+21-1)
     * snapshots are counted '0 (none available)'...'DemCfg_GetCountOfSnapshotsPerDTC() (all set)'
     * First check, if this DTC has set enough snapshots to satisfy requested number */
    if (*pSnapshotCount <= (RecordNumber - DemCfg_GetFirstOccurredRecordNr()))
    { /* no, too few records are stored. */
      result = FALSE;
    }
  }
  else
  { /* priMemIndex out of range or requested RecordNumber lower than first valid record */
    result = FALSE;
  }
  return result;
}


/**********************************************************************************************************************
  Dem_DisableDTCRecordUpdate
**********************************************************************************************************************/
/** Lock existing DTCs, associated FreezeFrames and/or extended data records against modification.
 *  This function shall be used if the FreezeFrame or extended data record are about to be accessed by subsequent
 *  API-calls. It is done to ensure that the data contained in this record is not changed while the FreezeFrame or
 *  extended data record are accessed by the external application, e.g. DCM.
 *  This function is used to prevent the DEM from manipulating, overwriting or deleting any existing DTC,
 *  associated FreezeFrame and/or extended data records. New DTCs and associated FreezeFrames and extended data
 *  records can still be added to the fault record storage as long as memory is available.
 *  DTC status information update is not affected by this function.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x1a
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1906 1910, 0x1904, 0x1905, 0x1914 (and probably more)
 * \note        AUTOSAR R3.0 API
 * \retval      E_OK      Operation was successful
 * \retval      E_NOT_OK  Operation failed
 *********************************************************************************************************************/
/** \note
AUTOSAR:
This function is used to prevent the DEM from manipulating, overwriting or deleting
any existing DTC, associated FreezeFrame and/or extended data records. New
DTCs and associated FreezeFrames and extended data records can still be added
to the fault record storage as long as memory is available.
DTC status information update is not affected by this function.

DEVIATION: (OEM/configuration dependent)
Some status information related counters (i.e. "extended data") may be updated when
DTC status information is updated!
Reason: Several counters (i.e. "extended data") found their increment and hence resulting
        actions on the change/state of the status bits. Changing the status and keep the
        counters unmodified will cause undefined behaviour e.g. with aging/selfhealing
        (Dem_DtcAgingCounterPtr), PREFAILED/PREPASSED (Dem_FaultDetectionCounterPtr) or
        simply invalidate their counting (ASR: Dem_FirstFailedEventIdPtr, Dem_MostRecent~,
        ~~ConfirmedEventIdPtr, ... or Dem_DTCCycleCounter). Therefore these counters
        are updated.
*/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableDTCRecordUpdate(
  void
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_RecordUpdate = DEM_FORBID_EXISTENT_RECORD_UPDATE;
    returnValue = E_OK;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_DISABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_EnableDTCRecordUpdate
**********************************************************************************************************************/
/** Unlock DTCs, associated FreezeFrames and/or extended data records.
 *  The function Dem_EnableDTCRecordUpdate is the counterpart to the function Dem_DisableDTCRecordUpdate. It shall
 *  be called after the FreezeFrame and extended data record were protected by the function
 *  Dem_DisableDTCRecordUpdate and after the access by subsequent API-calls is finished.
 *  It is called to release the data contained in this record so that the data can be accessed or manipulated by
 *  the external application, e.g. DCM, again.
 * \return      Std_ReturnType
 * \note        SERVICE ID   0x1b
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANCY   Non Reentrant
 * \note        CALLED BY    DCM for service 0x1906 1910, 0x1904, 0x1905, 0x1914 (and probably more)
 * \note        AUTOSAR R3.0 API
 * \retval      E_OK      Operation was successful
 * \retval      E_NOT_OK  Operation failed
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableDTCRecordUpdate(
  void
  )
{
  Std_ReturnType returnValue = E_NOT_OK;

  if ((Dem_InitializationStatus == DEM_IsEnabledAndRunning) || (Dem_InitializationStatus == DEM_IsEnabled))
  {
    Dem_RecordUpdate = DEM_PERMIT_EXISTENT_RECORD_UPDATE;
    returnValue = E_OK;
  }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_ENABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
  }
#endif  /* DEM_DEV_ERROR_DETECT */
  return returnValue;
}

/**********************************************************************************************************************
  Dem_TriggerOnEvent
**********************************************************************************************************************/
/** Call all configured Xxx_DemTriggerOnEventStatus() functions and all Xxx_DemTriggerOnDTCStatus() functions.
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_InitChronoStack()
 *                                    Dem_AddNewDTCtoChronoStack()
 *                                    Dem_DoResetEventStatus()
 *                                    Dem_DoSetOperationCycleState()
 *                                    Dem_DoSetEventStatus()
 *                                    Dem_ClearSingleEvent()
 * \param[in]   EventId       event that has got its status bits updated
 * \param[in]   OldStatusByte status bits before the status update
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_TriggerOnEvent(
  Dem_EventIdType         EventId,
  Dem_DtcStatusByteType   OldStatusByte
  )
{ /* there is a change - notify application */
  uint16 triggerFuncIndex;
  uint16 triggerCount;
  Dem_DtcStatusByteType newStatusByte;

  newStatusByte = Dem_DtcStatusBytePtr[EventId];

  { /* Trigger on DTC status */
    Dem_DTCStatusMaskType oldStatusMask = Dem_MapStatusByteTypeToMaskType(OldStatusByte);
    Dem_DTCStatusMaskType newStatusMask = Dem_MapStatusByteTypeToMaskType(newStatusByte);

    triggerFuncIndex = DemCfg_GetFirstTriggerOnDTC(EventId);
    triggerCount     = DemCfg_GetCountOfTriggerOnDTC(EventId);

    while (triggerCount != 0)
    {
      triggerCount--;
      /* call TriggerOnDTC function */
      /* the first parameter of Dem260 is DTC, the second DTCKind, followed by the status changes. see http://www.autosar.org/bugzilla/show_bug.cgi?id=24330 */
      (void) (Dem_TriggerDTCFunctionTable[triggerFuncIndex])(DemCfg_GetDTCnumber(EventId), DemCfg_GetDTCKind(EventId), oldStatusMask, newStatusMask);
      /* ignore failures, as there is no sensible (re)action */
      ++triggerFuncIndex;
    }
  }

  { /* Trigger on Event status */
    Dem_EventStatusExtendedType oldExtStatus = Dem_MapStatusByteTypeToExtType(OldStatusByte);
    Dem_EventStatusExtendedType newExtStatus = Dem_MapStatusByteTypeToExtType(newStatusByte);

    triggerFuncIndex = DemCfg_GetFirstTriggerOnEvent(EventId);
    triggerCount     = DemCfg_GetCountOfTriggerOnEvent(EventId);

    while (triggerCount != 0)
    {
      triggerCount--;
      /* call TriggerOnEvent function */
      (void) (Dem_TriggerFunctionTable[triggerFuncIndex])(oldExtStatus, newExtStatus);
      /* ignore failures, as there is no sensible (re)action */
      ++triggerFuncIndex;
    }

    /* Trigger status change to FIM */
#if (DEM_USE_FIM_NOTIFICATION_API == STD_ON)
    /* FIM is configured as FIM_CYCLIC_EVENT_EVALUATION, we must notify the event change */
    (void) Fim_DemTriggerOnEventStatus( EventId, oldExtStatus, newExtStatus );
#endif  /* DEM_USE_FIM_NOTIFICATION_API */
  }
}



/**********************************************************************************************************************
  Dem_RingbufIndexRelToAbs
**********************************************************************************************************************/
/** Convert the relative index of a ringbuffer into an absolute index.
 *  Convert the given 'rbRelIndex', that addresses an element in the ringbuffer relative to the 'rbFirst' entry
 *  into an absolute address relative to the ring buffer array. E.g. rbRelIndex==0 addresses the first entry in the
 *  ringbuffer that will be on absolute position 'rbFirst'. The function considers a wrap around, if necessary.
 * \return      absolute index in ringbuffer array (0 <= i < rbSize)
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    yes
 * \note        CALLED BY    Internal from function
 *                                    Dem_AQPush()
 *                                    Dem_AQPeek()
 * \param[in]   rbRelIndex   relative Index into ringbuffer
 * \param[in]   rbFirst      absolute Index of first element (i.e. rbRelIndex == 0)
 * \param[in]   rbSize       total number of entries in ringbuffer
 * \attention   This function is limited to ringbuffers up to 32k elements.
 *********************************************************************************************************************/
STATIC FUNC(uint16_least, DEM_CODE)                                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_RingbufIndexRelToAbs(
  uint16_least rbRelIndex,
  uint16_least rbFirst,
  uint16_least rbSize
  )
{
  uint16_least idx = rbFirst + rbRelIndex;
  if (idx >= rbSize)
  { /* wrap around */
    idx = idx - rbSize;
  }
  return idx;
}


/**********************************************************************************************************************
  Dem_AQPush
**********************************************************************************************************************/
/** Add new element to action queue, discard it on overflow.
 *  Store 'newElement' as last element into Dem_ActionQueue[]. The newElement must already contain the action and
 *  arguments. 
 * \return      boolean
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_ResetEventStatus() [API]
 *                                    Dem_SetOperationCycleState() [API]
 *                                    Dem_SetEventStatus() [API]
 *                                    Dem_ReportErrorStatus() [API]
 *                                    Dem_EnableDTCStorage() [API]
 *                                    Dem_ClearDTC() [API]
 * \param[in]   newElement  pointer to new element
 * \retval      TRUE        Element was appended
 * \retval      FALSE       Element was discarded
 * \pre         Use inside critical section, only!
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AQPush(
  P2CONST(Dem_AQElementType, AUTOMATIC, AUTOMATIC) newElement                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  boolean returnValue = FALSE;
  if (Dem_ActionQueueUsed < Dem_ActionQueueCount)
  {
    uint16_least idx;
    uint16_least used = (uint16_least) Dem_ActionQueueUsed;   /* evaluate volatile variable to avoid in next line compiler warning
                                                              ** "undefined behavior: the order of volatile accesses is undefined" */
    idx = Dem_RingbufIndexRelToAbs(used, (uint16_least) Dem_ActionQueueRbFirst, (uint16_least) Dem_ActionQueueCount);
    /* Dem_AQCopy is a workaround (MACRO), as some compilers cannot assign complex vars. Read as:
    *  Dem_ActionQueue[idx] = *newElement; */
    Dem_AQCopy(Dem_ActionQueue[idx], *newElement);
    ++Dem_ActionQueueUsed;
    returnValue = TRUE;
  }
  return returnValue;
}

/**********************************************************************************************************************
  Dem_AQIsQueued
**********************************************************************************************************************/
/** Check, if element is already in the queue.
 *  Search 'newElement' in Dem_ActionQueue[]. The return value 'TRUE' describes that the element is already there.
 *  As this check is typically used to prevent the enqueueing of the 'newElement', the function will also return 'TRUE'
 *  for unknown actions and the action DEM_AQACTION_NONE.
 * \return      boolean
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_ClearDTC() [API]
 * \param[in]   newElement  pointer to new element
 * \retval      TRUE        Element is already in the queue
 * \retval      FALSE       Element is not in the queue
 *********************************************************************************************************************/
STATIC FUNC(boolean, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AQIsQueued(
  P2CONST(Dem_AQElementType, AUTOMATIC, AUTOMATIC) newElement                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  boolean             returnValue = FALSE;
  uint16              index, count;
  uint8               newAction = Dem_AQGetAction(newElement);
  Dem_AQElementType  *elemPtr;       /* iterates through existing queue */

  /* Enter Critical ========================================================== */
  Dem_EnterCritical();
  index = Dem_ActionQueueRbFirst;
  count = Dem_ActionQueueUsed;
  switch (newAction)
  {
  case DEM_AQACTION_SETEVENT:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if ( (Dem_AQGetEventId( newElement )     == Dem_AQGetEventId( elemPtr ))
          && (Dem_AQGetEventStatus( newElement ) == Dem_AQGetEventStatus( elemPtr ))
          )
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_SETOPCYCLE:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if ( (Dem_AQGetOpCycleId( newElement )    == Dem_AQGetOpCycleId( elemPtr ))
          && (Dem_AQGetOpCycleState( newElement ) == Dem_AQGetOpCycleState( elemPtr ))
          )
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_CLEARALLDTC:
  case DEM_AQACTION_CLEARDTCGROUP:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if ( (Dem_AQGetBitcodedDTCGroup( newElement ) == Dem_AQGetBitcodedDTCGroup( elemPtr ))
          && (Dem_AQGetDTCKind( newElement )          == Dem_AQGetDTCKind( elemPtr ))
          && (Dem_AQGetDTCOrigin( newElement )        == Dem_AQGetDTCOrigin( elemPtr ))
          )
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_CLEARSINGLEEVENT:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if ( (Dem_AQGetEventId( newElement ) == Dem_AQGetEventId( elemPtr )) )
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_ENABLESTORAGE:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if ( (Dem_AQGetBitcodedDTCGroup( newElement ) == Dem_AQGetBitcodedDTCGroup( elemPtr ))
          && (Dem_AQGetDTCKind( newElement )          == Dem_AQGetDTCKind( elemPtr ))
          )
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_RESETEVENTSTATUS:
    for (/* count = Dem_ActionQueueUsed */; count > 0; --count)
    {
      elemPtr = Dem_AQPeekAbs(index);
      /* check for equal action */
      if (newAction == Dem_AQGetAction(elemPtr))
      { /* index'd element has requested action */
        /* check for equal arguments */
        if (Dem_AQGetEventId( newElement )     == Dem_AQGetEventId( elemPtr ))
        { /* found equal entry, abort 'for' loop by setting last index */
          returnValue = TRUE;
          break;            /* abort 'for'-loop */
        }
      }
      ++index;
      if (index == Dem_ActionQueueCount)
      { /* wrap around of ringbuffer */
        index = 0;
      }
    }
    break;
  case DEM_AQACTION_NONE:
  default:
    /* unknown actions and action DEM_AQACTION_NONE are per definition always in the queue */
    returnValue = TRUE;
    break;
  }
  Dem_LeaveCritical();
  /* Leave Critical ========================================================== */

  return returnValue;
}

/**********************************************************************************************************************
  Dem_AQPop
**********************************************************************************************************************/
/** Get oldest element from action queue, shrink queue.
 *  Take the oldest element from Dem_ActionQueue[] and store it into the buffer given by 'oldestElement'.
 *  Remove that element from queue afterwards.
 *  If queue is empty, just write "No Action" DEM
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \param[out]  oldestElement   pointer to buffer to store the oldestElement
 * \pre         Use inside critical section, only!
 *********************************************************************************************************************/
STATIC FUNC(void, DEM_CODE)                                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AQPop(
  P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC) oldestElement                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  )
{
  if  (Dem_ActionQueueUsed == 0)
  {
    Dem_AQSetAction(oldestElement, DEM_AQACTION_NONE);
  }
  else
  {
    /* Dem_AQCopy is a workaround (MACRO), as some compilers cannot assign complex vars. Read as:
    *  *oldestElement = Dem_ActionQueue[Dem_ActionQueueRbFirst]; */
    Dem_AQCopy(*oldestElement, Dem_ActionQueue[Dem_ActionQueueRbFirst]);
    --Dem_ActionQueueUsed;
    ++Dem_ActionQueueRbFirst;
    if (Dem_ActionQueueRbFirst == Dem_ActionQueueCount)
    { /* wrap around of ringbuffer */
      Dem_ActionQueueRbFirst = 0;
    }
  }
}

/**********************************************************************************************************************
  Dem_AQPeek
**********************************************************************************************************************/
/** Get pointer to the n-th element of the action queue, don't modify queue.
 *  Access the Dem_ActionQueue[] as ringbuffer. The returned, referenced element remains in the action queue.
 * \return      pointer to referenced element in the action queue
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_MainFunction()
 * \param[in]   relIndex      relative index in the Dem_ActionQueue[], first (oldest) entry has index 0,
 *                            last (latest) entry has index Dem_AQUsed()-1
 *********************************************************************************************************************/
STATIC FUNC(P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC), DEM_CODE)                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AQPeek(
  uint16 relIndex
  )
{
  /* convert ringbuffer related, relative 'index' into absolute array position */
  uint16_least       idx;
  Dem_AQElementType *elem;

  idx = Dem_RingbufIndexRelToAbs((uint16_least) relIndex, (uint16_least) Dem_ActionQueueRbFirst, (uint16_least) Dem_ActionQueueCount);
  elem = &Dem_ActionQueue[idx];

  return elem;
}

/**********************************************************************************************************************
  Dem_AQPeekAbs
**********************************************************************************************************************/
/** Get pointer to the n-th element of the action queue Array, don't modify Array.
 *  Access the Dem_ActionQueue[] directly. The returned, referenced element remains in the action queue.
 * \return      pointer to referenced element in the action queue
 * \note        SYNC/ASYNC   Synchronous
 * \note        REENTRANT    Non Reentrant
 * \note        CALLED BY    Internal from function
 *                                    Dem_AQIsQueued()
 * \param[in]   absIndex     absolute index in the Dem_ActionQueue[] array.
 *********************************************************************************************************************/
STATIC FUNC(P2VAR(Dem_AQElementType, AUTOMATIC, AUTOMATIC), DEM_CODE)                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_AQPeekAbs(
  uint16 absIndex
  )
{
  Dem_AQElementType *elem = &Dem_ActionQueue[absIndex];
  return elem;
}




#define DEM_STOP_SEC_CODE 
#include "MemMap.h"                                                                                                       /* PRQA S 5087 *//* MD_MSR_19.1 */ 


/* module specific MISRA deviations:
   MD_DEM_1.1_0715:
     Reason:     Performance and reduced stack footprint.
     Risk:       Compiler will not support nesting of more than 15 levels.
     Prevention: Will be tested with actual compiler before delivery.
   MD_DEM_1.1_0857:
     Reason:     AUTOSAR compiler abstraction / MemMap.
     Risk:       Compiler will not support more than 1024 macro definitions.
     Prevention: Will be tested with actual compiler before delivery.
   MD_DEM_3.1_0277:
     Reason:     Avoid compiler warning/error.
                 The SWCDEMSC_UNSET_BIT() macro uses the ~ operator to construct a 1111 bit mask with a single bit set
                 to 0. For correct MISRA implementation (according PRQA) the code must be like
                    (Dem_DtcStatusByteType)(~(1u << 0))
                 Unfortunately most compilers need an additional cast
                    (Dem_DtcStatusByteType)(~(Dem_DtcStatusByteType)(1u << 0))
                 to avoid warnings or error messages like "cast truncates constant value" (VisualC), "truncating 
                 assignment" (Cosmic), "Possible loss of data" (Metrowerks).
                 To get compilable code each use of the SWCDEMSC_UNSET_BIT() macro (and other macros using the 
                 ~ operator) will intentionally cause MISRA-C:2004 Rule 3.1 violation!
     Risk:       None.
     Prevention: None.
   MD_DEM_3.1_0308:
     Reason:     AUTOSAR defined API.
     Risk:       Overwritten memory -> unexpected behaviour.
     Prevention: System integrator must carefully fill array in application (size as configured).
   MD_DEM_8.7:
     Reason:     Needed to enable use of compiler abstractions.
     Risk:       None. 
     Prevention: None.
   MD_DEM_8.8_3408:
     Reason:     This "external" symbol is used for internal purpose only, but must be globally available.
     Risk:       None.
     Prevention: None.
   MD_DEM_8.8_3451:
     Reason:     Cannot prevent RTE from creating this prototype.
     Risk:       None.
     Prevention: None.
   MD_DEM_11.4:
     Reason:     Pointer to uint8 and pointer to uint8[] is formal different, but required to correctly implement AUTOSAR's API.
     Risk:       Conversions of this type may be invalid if the new pointer type requires a stricter alignment. 
     Prevention: Will be tested with actual compiler before delivery.
   MD_DEM_11.5:
     Reason:     Only a snapshot is used, volatile qualifier can be safely ignored.
     Risk:       None.
     Prevention: None.
   MD_DEM_12.4:
     Reason:     No side effect - right hand is read only.
     Risk:       If the right hand operands contain side effects then those side effects may or may not occur, 
                 depending on the values of the left hand expressions. 
     Prevention: By code inspection of the right hand operands.
   MD_DEM_13.7:
     Reason:     Protect against future extensions.
     Risk:       None. 
     Prevention: None.
   MD_DEM_14.2:
     Reason:     This statement is used to avoid warnings caused by unused parameters.
     Risk:       None.
     Prevention: None.
   MD_DEM_14.5:
     Reason:     Continue used for better performance.
     Risk:       Resulting code is more difficult to maintain.
     Prevention: None.
   MD_DEM_14.7:
     Reason:     This is the only exit path with operable ECU. Other exit paths are used in case of fatal error.
     Risk:       Unexpected behaviour or return values after calling this function.
     Prevention: Check all return paths during code inspection. Ensure that all other return paths will not lead to an
                 unexpected behaviour.
   MD_DEM_16.7:
     Reason:     AUTOSAR API definition - argument can not be modified.
     Risk:       Not optimized code.
     Prevention: None.
   MD_DEM_19.15:
     Reason:     Only comments are not protected against repeated inclusion.
     Risk:       None (this code is removed for delivery by ORGANI).
     Prevention: None.
   MD_DEM_21.1:
     Reason:     Using '~' on uint8 will cause QAC violation though casting is correct.
     Risk:       None.
     Prevention: None.
   MD_DEM_3651:
     Reason:     AUTOSAR API.
     Risk:       Using a typedef for an array of unknown size can lead to unexpected results.
     Prevention: Only pointers are used to access data of array.
   MD_DEM_4700:
     Reason:     For performance reason some PRQA metrics are beyond their recommendation: CAL, CYC, MIF, PTH, RET, 
                 ST3. Others are violated by AUTOSAR defined APIs: PAR.
     Risk:       None.
     Prevention: None.
*/
