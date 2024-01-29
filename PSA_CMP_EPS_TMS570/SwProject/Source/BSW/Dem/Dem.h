/* Kernbauer Version: 1.15 Konfiguration: Diag_AsrDem_Vector Erzeugungsgangnummer: 1 */


/*********************************************************************************************************************/
/*!
 * \file     Dem.h
 * \brief    Interface of DEM
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
 *         File:  Dem.h
 *      Project:  MICROSAR DEM
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Interface of DEM
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

#if defined (DEM_H)
#else
#define DEM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

#if (defined(STD_OFF) && defined(STD_ON))
#else
# error "Definition of STD_ON and/or STD_OFF is missing in Std_Types.h"
#endif

/* get GENy generated (CompileTime) configuration from file "Dem_Cfg.h" */
#include "Dem_Cfg.h"

/* -----------------------------------------------------------------------------
  Datatype definitions
 ----------------------------------------------------------------------------- */

#include "Dem_Types.h"


/* -----------------------------------------------------------------------------
  EventId definitions
 ----------------------------------------------------------------------------- */

/* PreConfig + PostBuild: #define  EVENT_CONFIG_NAME  DEM-internal-EventId */

/* BSW event Id symbols */
#include "Dem_IntErrId.h"
/* SW_C event Id symbols */
#include "Dem_IntEvtId.h"


/* -----------------------------------------------------------------------------
  Consistency check between generated code and static code/library
 ----------------------------------------------------------------------------- */

/* Check is not required for PRE-COMPILE variant */
#if (DEM_CONFIG_VARIANT != 1)
# define DEM_START_SEC_CONST_8BIT
# include "MemMap.h"                                                                              /* PRQA S 5087 *//* MD_MSR_19.1 */ 
extern CONST(uint8, DEM_CONST)  Dem_NeedDemLibVersion_SW_02_14_xx;                                /* PRQA S 0850 *//* MD_MSR_19.8 */
extern CONST(uint8, DEM_CONST)  Dem_NeedDemLibOem_DEM_Vector;                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
# define DEM_STOP_SEC_CONST_8BIT
# include "MemMap.h"                                                                              /* PRQA S 5087 *//* MD_MSR_19.1 */ 
#endif


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
#define DIAG_ASRDEM_VERSION                     DIAG_ASRDEM_VECTOR_VERSION
#define DIAG_ASRDEM_RELEASE_VERSION             DIAG_ASRDEM_VECTOR_RELEASE_VERSION
/* ##V_CFG_MANAGEMENT ##CQProject : Diag_AsrDem_Vector CQComponent : Implementation */
#define DIAG_ASRDEM_VECTOR_VERSION              0x0214u
#define DIAG_ASRDEM_VECTOR_RELEASE_VERSION      0x00u
/* ##V_CFG_MANAGEMENT ##CQProject : Diag_AsrDem__core CQComponent : Implementation */
#define DIAG_ASRDEM__CORE_VERSION               0x0300u
#define DIAG_ASRDEM__CORE_RELEASE_VERSION       0x01u

/* vendor and module identification */
#define DEM_VENDOR_ID                           30    /* Vector Informatik GmbH */
#define DEM_MODULE_ID                           54    /* DEM */
#define DEM_INSTANCE_ID                         0     /* always 1 instance */

/* AUTOSAR Software Specification Version Information (decimal coded) */
/* Document Version   2.2.1
   Part of Release    3.0
   Revision           0002, dated 2008-01-23 */
#define DEM_AR_MAJOR_VERSION                    (0x02u)
#define DEM_AR_MINOR_VERSION                    (0x02u)
#define DEM_AR_PATCH_VERSION                    (0x01u)
 
/* Component Version Information */
#define DEM_SW_MAJOR_VERSION                    (DIAG_ASRDEM_VERSION >> 8u)
#define DEM_SW_MINOR_VERSION                    (DIAG_ASRDEM_VERSION & 0x00FFu)
#define DEM_SW_PATCH_VERSION                    DIAG_ASRDEM_RELEASE_VERSION


/* error reporting with Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, ErrorId): */
/* API Service IDs for reporting errors to the DET */
#define DEM_GETVERSIONINFO_APIID                    0x00
#define DEM_PREINIT_APIID                           0x01
#define DEM_INIT_APIID                              0x02
#define DEM_SHUTDOWN_APIID                          0x03
#define DEM_SETEVENTSTATUS_APIID                    0x04
#define DEM_RESETEVENTSTATUS_APIID                  0x05
#define DEM_PRESTOREFREEZEFRAME_APIID               0x06
#define DEM_CLEARPRESTOREDFREEZEFRAME_APIID         0x07
#define DEM_SETOPERATIONCYCLESTATE_APIID            0x08
#define DEM_GETEVENTSTATUS_APIID                    0x0a
#define DEM_GETEVENTFAILED_APIID                    0x0b
#define DEM_GETEVENTTESTED_APIID                    0x0c
#define DEM_GETDTCOFEVENT_APIID                     0x0d
#define DEM_GETSEVERITYOFDTC_APIID                  0x0e
#define DEM_REPORTERRORSTATUS_APIID                 0x0f
#define DEM_SETDTCFILTER_APIID                      0x13
#define DEM_SETVIEWFILTER_APIID                     0x14
#define DEM_GETSTATUSOFDTC_APIID                    0x15
#define DEM_GETDTCSTATUSAVAILABILITYMASK_APIID      0x16
#define DEM_GETNUMBEROFFILTEREDDTC_APIID            0x17
#define DEM_GETNEXTFILTEREDDTC_APIID                0x18
#define DEM_GETDTCBYOCCURRENCETIME_APIID            0x19
#define DEM_DISABLEDTCRECORDUPDATE_APIID            0x1a
#define DEM_ENABLEDTCRECORDUPDATE_APIID             0x1b
#define DEM_GETDTCOFFREEZEFRAMERECORD_APIID         0x1c
#define DEM_GETFREEZEFRAMEDATABYDTC_APIID           0x1d
#define DEM_GETFREEZEFRAMEDATAIDENTIFIERBYDTC_APIID 0x1e
#define DEM_GETSIZEOFFREEZEFRAME_APIID              0x1f
#define DEM_GETEXTENDEDDATARECORDBYDTC_APIID        0x20
#define DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_APIID  0x21
#define DEM_CLEARDTC_APIID                          0x22
#define DEM_DISABLEDTCSTORAGE_APIID                 0x24
#define DEM_ENABLEDTCSTORAGE_APIID                  0x25
#define DEM_DISABLEEVENTSTATUSUPDATE_APIID          0x26
#define DEM_ENABLEEVENTSTATUSUPDATE_APIID           0x27
/* #define DEM_GETMILSTATUS_APIID                   0x28 (=40) no ServiceId in ASR 3.0 any more */
#define DEM_GETINDICATORSTATUS_APIID                0x29
/* #define DEM_GETOBDREADINESS_APIID                0x2a (=42) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETDISTANCEMIL_APIID                 0x2b (=43) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETWARMUPCYCLEDTCCLEAR_APIID         0x2c (=44) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETDISTANCEDTCCLEAR_APIID            0x2d (=45) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETMONITORSTATUS_APIID               0x2e (=46) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETTIMEMIL_APIID                     0x2f (=47) no ServiceId in ASR 3.0 any more */
/* #define DEM_GETTIMEDTCCLEAR_APIID                0x30 (=48) no ServiceId in ASR 3.0 any more */
/* #define XXX_DEMINITFUNCTION_APIID                0x32 (=50) no ServiceId in ASR 3.0 any more */
/* #define XXX_DEMTRIGGERONEVENTSTATUS_APIID        0x33 (=51) no ServiceId in ASR 3.0 any more */
/* #define XXX_DEMTRIGGERONDTCSTATUS_APIID          0x34 (=52) no ServiceId in ASR 3.0 any more */
#define DEM_XXX_GETDATAVALUEBYDATAIDENTIFIER_APIID  0x35    /* no ServiceId in ASR 3.0, number 53 (=0x35) is from ASR 2.1 */
#define DEM_GETVIEWIDOFDTC_APIID                    0x36
#define DEM_XXX_GETEXTENDEDDATARECORD_APIID         0x37    /* no ServiceId in ASR 3.0, number 61 (=0x3D) from ASR 2.1 was reused in 3.0 otherwise */
#define DEM_SETVALUEBYOEMID_APIID                   0x38
#define DEM_SETENABLECONDITION_APIID                0x39
#define DEM_GETNEXTFILTEREDRECORD_APIID             0x3a
#define DEM_GETNEXTFILTEREDDTCANDFDC_APIID          0x3b
#define DEM_GETTRANSLATIONTYPE_APIID                0x3c
#define DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID     0x3d
#define DEM_GETFAULTDETECTIONCOUNTER_APIID          0x3e
#define DEM_SETDTCFILTERFORRECORDS_APIID            0x3f
#define DEM_MAINFUNCTION_APIID                      0x55
/* Additional ApiId for functions beyond AUTOSAR standard */
#define DEM_APIID_ADDON                             0xE0    /* 224 */
#define DEM_GETOCCURRENCECOUNTER_APIID              (DEM_APIID_ADDON+1)     /* 0xE1 */
/* Additional ApiId for internal functions */
#define DEM_APIID_INTERNAL                          0xF0     /* 240 */
#define DEM_UPDATEEXTENDEDRECORD_APIID              (DEM_APIID_INTERNAL+0)  /* 0xF0 */
#define DEM_UPDATESNAPSHOTRECORD_APIID              (DEM_APIID_INTERNAL+1)  /* 0xF1 */
#define DEM_MEMMOVE_APIID                           (DEM_APIID_INTERNAL+2)  /* 0xF2 */
#define DEM_UPDATEDTCINPRIM_NOTACT2ACT_APIID        (DEM_APIID_INTERNAL+3)  /* 0xF3 */
#define DEM_DELETEDTCINCHRONOSTACK_APIID            (DEM_APIID_INTERNAL+4)  /* 0xF4 */
#define DEM_GETOFFSETSNAPSHOTRECORDNTH_APIID        (DEM_APIID_INTERNAL+5)  /* 0xF5 */
#define DEM_GETMOSTRECENTSNAPSHOTINDEX_APIID        (DEM_APIID_INTERNAL+6)  /* 0xF6 */
#define DEM_CLEARSINGLEEVENT_APIID                  (DEM_APIID_INTERNAL+7)  /* 0xF7 */
#define DEM_UPDATEDTCINPRIM_ACT2NOTACT_APIID        (DEM_APIID_INTERNAL+8)  /* 0xF8 */
#define DEM_UPDATEUSERDATARECORD_APIID              (DEM_APIID_INTERNAL+9)  /* 0xF9 */
#define DEM_CALCNEWDEBOUNCETIMERSLOTVAL_APIID       (DEM_APIID_INTERNAL+13) /* 0xFD */
#define DEM_INITDIAGNOSTICVARIANT_APIID             (DEM_APIID_INTERNAL+14) /* 0xFE */

/* Application ErrorIDs for RTE/API Application Errors in addition to E_OK and E_NOT_OK */
#define DEM_E_QUEUE_OVERFLOW                            0x0F

/* ErrorIDs for reporting errors to the DET */
/*      API service called with wrong parameter: */
#define DEM_E_PARAM_CONFIG                              0x10    /* using un-configured parameter */
#define DEM_E_PARAM_ADDRESS                             0x11    /* invalid address (NULL_PTR) */
#define DEM_E_PARAM_DATA                                0x12    /* data value out of range, incorrect data */
#define DEM_E_PARAM_LENGTH                              0x13    /* incorrect length of parameter */
/*      API service called before the DEM module has been initialized */
#define DEM_E_UNINIT                                    0x20
/*      No valid data available by the SW-C */
#define DEM_E_NODATAAVAILABLE                           0x30
/* range 0x80..0x9f is reserved for internal Debug codes that denote fatal errors */
#define DEM_E_DTC_NOT_FOUND                             0x82
#define DEM_E_ERASING_EMPTY_STACK                       0x83
#define DEM_E_INV_CSTACK_REF                            0x86
#define DEM_E_INV_SFN                                   0x89
#define DEM_E_INV_SNAPSHOT_NUM                          0x8f
#define DEM_E_ZEROPTR_SOURCE                            0x90
#define DEM_E_ZEROPTR_TARGET                            0x91
#define DEM_E_TOO_MANY_DIDS_FOR_EVENT                   0x92
#define DEM_E_TOO_MANY_INDICATOR_IDS                    0x93
#define DEM_E_INVALIDSTATE                              0x94
#define DEM_E_INV_TIMER_SLOT_VAL                        0x95
#define DEM_E_NOT_IN_ACTIVE_VARIANT                     0x96


/* internal check for empty or uninitialized NVRAM (if NvM doesn't use the init-callback Dem_NvDataInit()) */
#define DEM_ENABLE_PATTERN_CHECK                        STD_ON

/* initial value used in Dem_NvDataInit() to initialize Dem_NvData buffer */ 
#define DEM_NVDATA_INIT_VALUE                           0xFFu

/* support for internal occurrence counter */
#if defined (DEM_SUPPORT_OCCURRENCE_COUNTER)
#else
# define DEM_SUPPORT_OCCURRENCE_COUNTER                 STD_OFF
#endif


/* value for invalid DTC number */
#define DEM_DTCNUMBER_INVALID                           0xFFFFFFFFuL


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* Support of DET to handle assertions */
/* extern void Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ); */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
# define Dem_DetReportError(ApiId, ErrorId)   Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, (ApiId), (ErrorId))         /* PRQA S 3453 *//* MD_MSR_19.7 */
#else
# define Dem_DetReportError(ApiId, ErrorId)   do {/* no DET error reporting */} while(0)
#endif

/** Protection for critical areas against concurrent access */
# define Dem_EnterCritical() SchM_Enter_Dem(DEM_EXCLUSIVE_AREA_0)
# define Dem_LeaveCritical() SchM_Exit_Dem(DEM_EXCLUSIVE_AREA_0)
# define Dem_EnterCritical_PreInit() SchM_Enter_Dem(DEM_EXCLUSIVE_AREA_1)
# define Dem_LeaveCritical_PreInit() SchM_Exit_Dem(DEM_EXCLUSIVE_AREA_1)


 /**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON)
#define DEM_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"                                                                               /* PRQA S 5087 *//* MD_MSR_19.1 */ 
extern VAR(uint32, DEM_VAR_NOINIT_FAST)  Dem_ActiveVariant;                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
#define DEM_STOP_SEC_VAR_FAST_32BIT 
#include "MemMap.h"                                                                               /* PRQA S 5087 *//* MD_MSR_19.1 */ 
#endif  /* DEM_SUPPORT_VARIANT_HANDLING || DEM_SUPPORT_MULTIPLE_CONFIG */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define DEM_START_SEC_CODE 
#include "MemMap.h"                                                                               /* PRQA S 5087 *//* MD_MSR_19.1 */ 

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClientRunnable(                                                                               /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  void
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE)                                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetDTCFilter(
  Dem_DTCStatusMaskType                   DTCStatusMask,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  Dem_FilterWithSeverityType              FilterWithSeverity,
  Dem_DTCSeverityType                     DTCSeverity,
  Dem_FilterForFaultDetectionCounterType  FilterForFaultDetectionCounter
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE)                                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetDTCFilterForRecords(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredRecords                                /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnSetViewFilterType, DEM_CODE)                                                       /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetViewFilter(
  Dem_ViewIdType ViewId
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE)                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetStatusOfDTC(
  Dem_DTCType                                             DTC,
  Dem_DTCKindType                                         DTCKind,
  Dem_DTCOriginType                                       DTCOrigin,
  P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCStatusAvailabilityMask(
  P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatusMask                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredDTC                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTC(
 P2VAR(Dem_DTCType,           AUTOMATIC, DEM_APPL_DATA)  DTC,                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus                                /* PRQA S 0850 *//* MD_MSR_19.8 */
 );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredRecord(
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(uint8,       AUTOMATIC, DEM_APPL_DATA)  SnapshotRecord                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTCAndFDC(
 P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(sint8,       AUTOMATIC, DEM_APPL_DATA)  DTCFaultDetectionCounter                           /* PRQA S 0850 *//* MD_MSR_19.8 */
 );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetNextFilteredDTCAndSeverity(
 P2VAR(Dem_DTCType,           AUTOMATIC, DEM_APPL_DATA)  DTC,                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)  DTCStatus,                               /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(Dem_DTCSeverityType,   AUTOMATIC, DEM_APPL_DATA)  DTCSeverity,                             /* PRQA S 0850 *//* MD_MSR_19.8 */
 P2VAR(uint8,                 AUTOMATIC, DEM_APPL_DATA)  DTCFunctionalUnit                        /* PRQA S 0850 *//* MD_MSR_19.8 */
 );  /* PRQA S 1503 */

FUNC(uint8, DEM_CODE)                                                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetTranslationType(
  void
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCByOccurrenceTime(
  Dem_DTCRequestType                            DTCRequest,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_NvDataInit( 
  void
  );  /* PRQA S 1503 */

FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_MainFunction(
  void
  );  /* PRQA S 1503 */

FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_InitMemory(
  void
  );  /* PRQA S 1503 */

#if (DEM_SUPPORT_VARIANT_HANDLING == STD_ON)
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_InitDiagnosticVariant(
  uint32 activeCfg
  );  /* PRQA S 1503 */
#endif  /* DEM_SUPPORT_VARIANT_HANDLING */

#if (DEM_SUPPORT_MULTIPLE_CONFIG == STD_ON) || (DEM_SUPPORT_VARIANT_HANDLING == STD_ON) || (DEM_PREINIT_HAS_CONFIG_PARAM == STD_ON)
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_PreInit(
  P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST) activeCfg                                         /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */
#else
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_PreInit(
  void
  );  /* PRQA S 1503 */
#endif

FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_Init(
  void
  );  /* PRQA S 1503 */

FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_Shutdown(
  void
  );  /* PRQA S 1503 */

#if (DEM_VERSION_INFO_API == STD_ON)
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA)  versioninfo                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */
#endif

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ResetEventStatus(                                                                             /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType   EventId
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_PrestoreFreezeFrame(
  Dem_EventIdType   EventId
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearPrestoredFreezeFrame(
  Dem_EventIdType   EventId
  );  /* PRQA S 1503 */


/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetOperationCycleState(                                                                       /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_OperationCycleIdType      OperationCycleId,
  Dem_OperationCycleStateType   CycleState
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetEventStatus(                                                                               /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(void, DEM_CODE)                                                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ReportErrorStatus(                                                                            /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventStatus(                                                                               /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType                                               EventId,
  P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA)  EventStatusExtended               /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventFailed(                                                                               /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetEventTested(                                                                               /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCOfEvent(                                                                                /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType                                               EventId,
  Dem_DTCKindType                                               DTCKind,
  P2VAR(Dem_DTCType,                 AUTOMATIC, DEM_APPL_DATA)  DTCOfEvent                        /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */


FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetValueByOemId(
  uint16                                  OemID,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DataValue,                                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  uint8                                   BufferLength
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_SetEnableCondition(
  uint8     EnableConditionID,
  boolean   ConditionFulfilled
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSeverityOfDTC(
  Dem_DTCType                                                       DTC,
  P2VAR(Dem_DTCSeverityType,            AUTOMATIC, DEM_APPL_DATA)   DTCSeverity                   /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)                                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableDTCStorage(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)                                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableDTCStorage(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableEventStatusUpdate(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)                                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableEventStatusUpdate(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType   DTCKind
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetIndicatorStatus(
  Dem_IndicatorIdType                                       Dem_IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA)  Dem_IndicatorStatus                   /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFaultDetectionCounter(
  Dem_EventIdType                                                 EventId,
  P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)  EventIdFaultDetectionCounter    /* PRQA S 0850 *//* MD_MSR_19.8 */
);  /* PRQA S 1503 */

FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE)                                           /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetDTCOfFreezeFrameRecord(
  uint8                                         RecordNumber,
  Dem_DTCOriginType                             DTCOrigin,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC                                               /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetFreezeFrameDataIdentifierByDTCType, DEM_CODE)                                   /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFreezeFrameDataIdentifierByDTC(
  Dem_DTCType                                             DTC,
  Dem_DTCKindType                                         DTCKind,
  Dem_DTCOriginType                                       DTCOrigin,
  uint8                                                   RecordNumber,
  P2VAR(uint8,                 AUTOMATIC, DEM_APPL_DATA)  ArraySize,                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(Dem_RecordDIDAddrType, AUTOMATIC, DEM_APPL_DATA)  DataId  /* const uint16 **DataId */     /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetFreezeFrameDataByDTC(
  Dem_DTCType                             DTC,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  uint8                                   RecordNumber,
  uint16                                  DataId,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE)                                                /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSizeOfFreezeFrame(
  Dem_DTCType                               DTC,
  Dem_DTCKindType                           DTCKind,
  Dem_DTCOriginType                         DTCOrigin,
  uint8                                     RecordNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfFreezeFrame                                     /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)                                          /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetExtendedDataRecordByDTC(
  Dem_DTCType                             DTC,
  Dem_DTCKindType                         DTCKind,
  Dem_DTCOriginType                       DTCOrigin,
  uint8                                   ExtendedDataNumber,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                             /* PRQA S 0850 *//* MD_MSR_19.8 */
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                 /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE)                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetSizeOfExtendedDataRecordByDTC(
  Dem_DTCType                               DTC,
  Dem_DTCKindType                           DTCKind,
  Dem_DTCOriginType                         DTCOrigin,
  uint8                                     ExtendedDataNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfExtendedDataRecord                              /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnClearDTCType, DEM_CODE)                                                            /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_ClearDTC(
  Dem_DTCType         DTC,
  Dem_DTCKindType     DTCKind,
  Dem_DTCOriginType   DTCOrigin
  );  /* PRQA S 1503 */

FUNC(Dem_ReturnGetViewIDOfDTCType, DEM_CODE)                                                      /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetViewIDOfDTC(
  Dem_DTCType                                       DTC,
  Dem_DTCKindType                                   DTCKind,
  P2VAR(Dem_ViewIdType, AUTOMATIC, DEM_APPL_DATA)   ViewId                                        /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_DisableDTCRecordUpdate(
  void
  );  /* PRQA S 1503 */

FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_EnableDTCRecordUpdate(
  void
  );  /* PRQA S 1503 */


/* support for internal occurrence counter */
#if (DEM_SUPPORT_OCCURRENCE_COUNTER == STD_ON)
/* Server PortInterface of the DEM (maybe defined in Rte_Dem.h too - depends on RTE/Application config) */
FUNC(Std_ReturnType, DEM_CODE)                                                                    /* PRQA S 0850 *//* MD_MSR_19.8 */
Dem_GetOccurrenceCounter(                                                                         /* PRQA S 3451 *//* MD_DEM_8.8_3451 */
  Dem_EventIdType                         EventId,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  OccurrenceCounterValue                                  /* PRQA S 0850 *//* MD_MSR_19.8 */
  );  /* PRQA S 1503 */
#endif /* DEM_SUPPORT_OCCURRENCE_COUNTER */



#define DEM_STOP_SEC_CODE 
#include "MemMap.h"                                                                               /* PRQA S 5087 *//* MD_MSR_19.1 */ 


#endif /* DEM_H */

