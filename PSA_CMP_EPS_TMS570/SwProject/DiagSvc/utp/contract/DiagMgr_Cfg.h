
#ifndef DIAGMGR_CFG_H
#define DIAGMGR_CFG_H

#define DIAGMGR_NUMAPPS                                   4u

typedef struct {
	uint8 Param;
   	uint8 Status;
	uint8 AgingCounter;
} NTCInfo_Str;

typedef struct {
	uint8 AppIdx;	/* Application index, key to DiagMgrNtcInfoMap_Str table */
   	uint8 InfoIdx;  /* NTCInfo index of of table found by using the AppIdx into the DiagMgrNtcInfoMap_Str table */
} DiagMgrNtcAppMap_Str;

typedef struct {
	P2VAR(NTCInfo_Str, AUTOMATIC, AUTOMATIC) NTCInfoPtr;
   	uint8 NumElements;
} DiagMgrNtcInfoMap_Str;

extern CONST(DiagMgrNtcAppMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcAppInfoMap_Cnt_Str[512u];
extern CONST(DiagMgrNtcInfoMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcInfoPtr_Cnt_Str[DIAGMGR_NUMAPPS];


#endif
