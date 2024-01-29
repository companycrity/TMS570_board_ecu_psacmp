
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : DiagMgr_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 17.05.2018 16:26:23
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          15 %
 * %date_modified:    Tue May 10 09:35:24 2016 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 * 02/28/14   4       JWJ       Updated to add new #define for MTO programs to support snapshot data changes   11531
 * 04/14/16   5       JK        Anomaly fix - EA3#6259.Also added some indentation fixes                    EA3#6988
 * 05/10/16   6       SB        Update to capture the Ap ID from DiagMgrDemIfOsAppRef field in configurator	EA3#8268
 */

#ifndef DIAGMGR_CFG_H
#define DIAGMGR_CFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*** Public Part (used by DiagMgr API) *****************************************/

#include "Std_Types.h" /* Standard type definitions */


extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr6_GetNTCFailed( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCFailed_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr6_GetNTCActive( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCActive_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr6_GetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08 );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr6_SetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr6_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );

extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_GetNTCFailed( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCFailed_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_GetNTCActive( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCActive_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_GetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08 );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_SetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );

extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_GetNTCFailed( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCFailed_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_GetNTCActive( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCActive_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_GetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08 );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_SetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );

extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr11_GetNTCFailed( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCFailed_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr11_GetNTCActive( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCActive_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr11_GetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08 );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr11_SetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr11_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );

/*** Private Part (used by DiagMgr.c only) *************************************/
#ifdef DIAGMGR_C

/* Provide access to the direct access S/R port definitions for black box data */
#if defined(DIAGMGR_DEMIF_RTEHEADER)
#include "Rte_Ap_DiagMgr6.h"
#elif defined(DIAGMGR_FAILACTION_RTEHEADER)

/* Provide access to the direct access S/R port definitions for black box data */
#include "Rte_Ap_DiagMgr10.h"
#else
#endif

#define DIAGMGR_DEV_ERROR_DETECT                    STD_ON
#define NxtrDiagMgrDemIf_ReportNTCStatus            NxtrDiagMgr6_ReportNTCStatus
#define DIAGMGR_IS_MTO_PROGRAM                      STD_OFF
#define D_NUMOFDEMEVENTS_CNT_U08                    60U
#define D_NOOFACTIVEINVERTER_CNT_U08                1U

/* DiagMgr Event Block Configuration Definitions */
typedef struct {
	uint8 Param;
	uint8 Status;
	uint8 AgingCounter;
} NTCInfo_Str;

typedef struct {
	NTCNumber NTC;
	uint8 Param;
	NxtrDiagMgrStatus Status;
} NTCInfoQueue_Str;

typedef struct {
	P2VAR(NTCInfo_Str, AUTOMATIC, AUTOMATIC) NTCInfoPtr;
	uint8 NumElements;
} DiagMgrNtcInfoMap_Str;

typedef struct {
	uint8 AppIdx;   /* Application index, key to DiagMgrNtcInfoMap_Str table */
	uint8 InfoIdx;  /* NTCInfo index of of table found by using the AppIdx into the DiagMgrNtcInfoMap_Str table */
} DiagMgrNtcAppMap_Str;


/* Ap_6 Application SWC Internal Defs*/
#define DIAGMGR_EVENTNUM_6                                6U
#define DIAGMGR_APID_6                                    0U

extern VAR(uint8, AP_DIAGMGR_VAR) ActDiagSts6_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag6_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag_Cnt_M_u08;
extern VAR(uint16, AP_DIAGMGR_VAR) DiagSts6_Cnt_M_b16[2u];
extern VAR(float32, AP_DIAGMGR_VAR) ActiveRmpRate6_UlspmS_M_f32[2u];
extern VAR(boolean, AP_DIAGMGR_VAR) DiagMgrInitComp6_Cnt_M_lgc;
extern VAR(NTCInfo_Str, AP_DIAGMGR_VAR) DiagMgr_NTCInfo6_Cnt_M_str[DIAGMGR_EVENTNUM_6];
extern CONST(NTCNumber, AUTOMATIC) T_NTCMapTbl6_Cnt_enum[DIAGMGR_EVENTNUM_6];
extern VAR(uint8, AP_DIAGMGR_VAR) NTCQueueIndex6_Cnt_M_u08;
extern VAR(NTCInfoQueue_Str, AP_DIAGMGR_VAR) NTCInfoQueue6_Cnt_M_str[2];

/* Ap_9 Application SWC Internal Defs*/
#define DIAGMGR_EVENTNUM_9                                28U
#define DIAGMGR_APID_9                                    1U

extern VAR(uint8, AP_DIAGMGR_VAR) ActDiagSts9_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag9_Cnt_M_u08;
extern VAR(uint16, AP_DIAGMGR_VAR) DiagSts9_Cnt_M_b16[2u];
extern VAR(float32, AP_DIAGMGR_VAR) ActiveRmpRate9_UlspmS_M_f32[2u];
extern VAR(boolean, AP_DIAGMGR_VAR) DiagMgrInitComp9_Cnt_M_lgc;
extern VAR(NTCInfo_Str, AP_DIAGMGR_VAR) DiagMgr_NTCInfo9_Cnt_M_str[DIAGMGR_EVENTNUM_9];
extern CONST(NTCNumber, AUTOMATIC) T_NTCMapTbl9_Cnt_enum[DIAGMGR_EVENTNUM_9];
extern VAR(uint8, AP_DIAGMGR_VAR) NTCQueueIndex9_Cnt_M_u08;
extern VAR(NTCInfoQueue_Str, AP_DIAGMGR_VAR) NTCInfoQueue9_Cnt_M_str[1];

/* Ap_10 Application SWC Internal Defs*/
#define DIAGMGR_EVENTNUM_10                               147U
#define DIAGMGR_APID_10                                   2U

extern VAR(uint8, AP_DIAGMGR_VAR) ActDiagSts10_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag10_Cnt_M_u08;
extern VAR(uint16, AP_DIAGMGR_VAR) DiagSts10_Cnt_M_b16[2u];
extern VAR(float32, AP_DIAGMGR_VAR) ActiveRmpRate10_UlspmS_M_f32[2u];
extern VAR(boolean, AP_DIAGMGR_VAR) DiagMgrInitComp10_Cnt_M_lgc;
extern VAR(NTCInfo_Str, AP_DIAGMGR_VAR) DiagMgr_NTCInfo10_Cnt_M_str[DIAGMGR_EVENTNUM_10];
extern CONST(NTCNumber, AUTOMATIC) T_NTCMapTbl10_Cnt_enum[DIAGMGR_EVENTNUM_10];
extern VAR(uint8, AP_DIAGMGR_VAR) NTCQueueIndex10_Cnt_M_u08;
extern VAR(NTCInfoQueue_Str, AP_DIAGMGR_VAR) NTCInfoQueue10_Cnt_M_str[9];

/* Ap_11 Application SWC Internal Defs*/
#define DIAGMGR_EVENTNUM_11                               4U
#define DIAGMGR_APID_11                                   3U

extern VAR(uint8, AP_DIAGMGR_VAR) ActDiagSts11_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag11_Cnt_M_u08;
extern VAR(uint16, AP_DIAGMGR_VAR) DiagSts11_Cnt_M_b16[2u];
extern VAR(float32, AP_DIAGMGR_VAR) ActiveRmpRate11_UlspmS_M_f32[2u];
extern VAR(boolean, AP_DIAGMGR_VAR) DiagMgrInitComp11_Cnt_M_lgc;
extern VAR(NTCInfo_Str, AP_DIAGMGR_VAR) DiagMgr_NTCInfo11_Cnt_M_str[DIAGMGR_EVENTNUM_11];
extern CONST(NTCNumber, AUTOMATIC) T_NTCMapTbl11_Cnt_enum[DIAGMGR_EVENTNUM_11];
extern VAR(uint8, AP_DIAGMGR_VAR) NTCQueueIndex11_Cnt_M_u08;
extern VAR(NTCInfoQueue_Str, AP_DIAGMGR_VAR) NTCInfoQueue11_Cnt_M_str[1];

#define DIAGMGR_NUMAPPS                                   4U
extern CONST(DiagMgrNtcAppMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcAppInfoMap_Cnt_Str[512u];
extern CONST(DiagMgrNtcInfoMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcInfoPtr_Cnt_Str[DIAGMGR_NUMAPPS];
extern CONSTP2VAR(uint16, AUTOMATIC, AP_DIAGMGR_CONST) T_DiagMgrDiagSts_Ptr_b16[DIAGMGR_NUMAPPS];
extern CONSTP2VAR(float32, AUTOMATIC, AP_DIAGMGR_CONST) T_DiagMgrRmpRate_Ptr_f32[DIAGMGR_NUMAPPS];


/* Disable all checkpoints that are not enabled */
#define Rte_Call_DiagMgr_Per2_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr_Per2_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr6_Per_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr6_Per_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr9_Per_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr9_Per_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr_Per1_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr_Per1_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr10_Per_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr10_Per_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr11_Per_CP0_CheckpointReached() (void)0 /* Checkpoint disabled */
#define Rte_Call_DiagMgr11_Per_CP1_CheckpointReached() (void)0 /* Checkpoint disabled */

#endif /* DIAGMGR_C */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*** Public Part (DiagMgr API) *****************************************/

/*
 * File version information
 */
#define DIAGMGR_CFG_H_MAJOR_VERSION   1U
#define DIAGMGR_CFG_H_MINOR_VERSION   0U
#define DIAGMGR_CFG_H_PATCH_VERSION   0U

/*
 * API enable settings
 */

#endif /* DIAGMGR_CFG_H */

/*** End of file **************************************************************/
