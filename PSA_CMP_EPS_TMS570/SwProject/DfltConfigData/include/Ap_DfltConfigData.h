/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.h
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/* Version Control:
* %version:          5 %
* %derived_by:       nzx5jd %
*---------------------------------------------------------------------------------------------------------------------
* Date       Rev     Author   Change Description                                                                SCR #
* --------   ------  -------  -------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version 5
 */


#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H


#include "Std_Types.h"
#include "Rte_Type.h"
#include "DiagSvc.h"


extern CONST(PhaseCurrCal_DataType, AP_DFLTCONFIGDATA_CONST) T_ShCurrCalInit_Cnt_str;
extern CONST(uint16,                AP_DFLTCONFIGDATA_CONST) T_CogTrqCalInit_Cnt_u16[512];
extern CONST(uint16,                AP_DFLTCONFIGDATA_CONST) T_CogTrqRplCompInit_Cnt_u16[9];
extern CONST(float32,               AP_DFLTCONFIGDATA_CONST) T_TorqueCmdSFInit_Uls_f32;
extern CONST(EOTLearned_DataType,   AP_DFLTCONFIGDATA_CONST) T_LearnedEOTInit_Cnt_str;
extern CONST(AvgFricLrnType,        AP_DFLTCONFIGDATA_CONST) T_AvgFricLrnDataInit_Cnt_str;


extern CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[50];

extern CONST(ECUManufacturingDateType_Str, DIAGSVC_CONST) D_MANUFDATEINIT_CNT_STR;


extern VAR(uint8, NVM_APPL_DATA) Deprecated_CmMtrCurr_CurrTempOffset[98u];
extern VAR(uint8, NVM_APPL_DATA) Deprecated_AbsHwPos_EOLVehCntrOffset[10u];
extern VAR(uint8, NVM_APPL_DATA) Deprecated_Dem_NvData[60u];


extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void);


#endif /* RTE_AP_DFLTCONFIGDATA_H */
