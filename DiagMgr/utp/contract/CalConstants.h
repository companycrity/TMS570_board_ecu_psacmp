/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          2.1.1 %
* %derived_by:       kzdyfh %
* %date_modified:    Mon Oct  7 14:45:20 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"
#include "Ap_DiagMgr_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 10/3/2013 3:55:04 PM *******************/
/****************************** DiagMgr - Rev 9 ******************************/


extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];
extern CONST(NTCLatch_Str, CAL_CONST) t_LatchFaults_Cnt_str[8];
#endif
