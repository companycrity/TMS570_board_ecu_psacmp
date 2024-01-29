/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : DiagSvc.h
* Module Description: Header for customer diagnostic services data
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/*******************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       tzyksv %
********************************************************************************
* Change History:
* Date      Rev      Author    Change Description                          CR
* --------  -------  --------  -----------------------------------------  -----
* 08/13/14   1       OT        Initial version                            12250
* 09/11/14   2       OT        Updates for new DSR                        12451
* 09/19/14   3       OT        Size corrections                           12451
* 10/02/14   4       OT        Updates for new customer services          12363
* 05/10/16   5       WH        Updates for DSR 4A                         EA3#7994
*******************************************************************************/

#ifndef DIAGSVC_H
#define DIAGSVC_H


#include "Std_Types.h"


typedef struct
{
	uint8	CPROrder_Cnt_u08;
	uint8	MPROrder_Cnt_u08;
	uint8	BVPROrder_Cnt_u08;
	uint8	PPROrder_Cnt_u08;
	uint8	TuningSet_Cnt_u08;
} TuningSelectTableType_Str;

typedef struct
{
	uint8	IDTLC_Cnt_u08;
	uint8	STTPR_Cnt_u08;
    uint8   MultiModePR_Cnt_u08;
    uint8   LXAPR_Cnt_u08;
	uint8	CPKPR_Cnt_u08;
	uint8	CAVPR_Cnt_u08;
	uint16	CPR_Cnt_u16;
	uint32	MPR_Cnt_u32;
	uint16	BVPR_Cnt_u16;
	uint32	PPR_Cnt_u32;
	uint8	VariantCodingNumber_Cnt_u08;
} TuningSelectType_Str;


typedef struct
{
	uint8	TurnsCounterAvail_Cnt_u08;
	uint8	MotorId_Cnt_u08;
    uint8   CustomerId_Cnt_u08;
} PowerPackConfigType_Str;

typedef struct
{
	uint8	Data_Cnt_u08[24u];
	uint8	Nexteer_Cnt_u08[22u];
	uint16	CRC_Cnt_u16;
	uint16	Count_Cnt_u16;
} FlashLogType_Str;

typedef struct
{
	uint8	FunctionalDrawingNumber_Cnt_u08[5u];
	uint8	FunctionalProdNumber_Cnt_u08[5u];
	uint8	HwVersion_Cnt_u08;
} AuthenticationZoneType_Str;

typedef struct
{
	uint8	Day_Cnt_u08;
	uint8	Month_Cnt_u08;
	uint8	Year_Cnt_u08;
} ECUManufacturingDateType_Str;

typedef struct
{
	uint8	ModuleInitials_Cnt_u08[5u];
	uint8	FreeField_Cnt_u08[16u];
	uint8	EMCIndex_Cnt_u08;
} EMCStandardizationLabelType_Str;


extern CONST(TuningSelectType_Str, DIAGSVC_CONST) D_TUNINGSELECTINIT_CNT_STR;
extern CONST(PowerPackConfigType_Str, DIAGSVC_CONST) D_POWERPACKCONFIGINIT_CNT_STR;
extern CONST(AuthenticationZoneType_Str, DIAGSVC_CONST) D_AUTHENTICATIONZONEINIT_CNT_STR;
extern CONST(EMCStandardizationLabelType_Str, DIAGSVC_CONST) D_STDLABELINIT_CNT_STR;
extern CONST(uint8, DIAGSVC_CONST) D_SECURITYKEYINIT_CNT_U08[3u];
extern CONST(uint8, DIAGSVC_CONST) D_CUSTECUINIT_CNT_U08[13u];

extern VAR(TuningSelectType_Str, DIAGSVC_VAR) TuningSelect_G_str; /* DID 2101 */
extern VAR(PowerPackConfigType_Str, DIAGSVC_VAR) PowerPackConfig_G_str;
extern VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogA_G_str; /* DID F0FE */
extern VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogB_G_str; /* DID F0FE */
extern VAR(AuthenticationZoneType_Str, DIAGSVC_VAR) AuthenticationZone_G_str; /* DID F080 */
extern VAR(ECUManufacturingDateType_Str, DIAGSVC_VAR) ECUManufacturingDate_G_str; /* DID F18B */
extern VAR(EMCStandardizationLabelType_Str, DIAGSVC_VAR) EMCStandardizationLabel_G_str; /* DID F18F */

extern VAR(boolean, DIAGSVC_VAR) Deprecated_PowerLatchFlag_Cnt_G_lgc;

extern VAR(uint8, DIAGSVC_VAR) Deprecated_SecurityKey_Cnt_G_u08[10u];
extern VAR(uint8, DIAGSVC_VAR) SecurityKey_Cnt_G_u08[3u];
extern VAR(uint8, DIAGSVC_VAR) SecurityViolation_Cnt_G_u08;
extern VAR(uint8, DIAGSVC_VAR) CustECUSrlNum_Cnt_G_u08[13u]; /* DID F18C */


#endif
