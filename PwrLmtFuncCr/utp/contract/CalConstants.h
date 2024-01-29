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
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          5 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Aug 29 13:19:13 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 8/29/2013 1:15:23 PM *******************/
/**************** Power Limit Function (Current Mode) - Rev 6 ****************/


extern CONST(uint16, CAL_CONST) t_DLVTblX_Volt_u5p11[10];
extern CONST(uint16, CAL_CONST) t_DLVTblY_MtrRadpS_u11p5[10];
extern CONST(sint16, CAL_CONST) t_MtrEnvTblX_MtrRadpS_s11p4[14];
extern CONST(uint16, CAL_CONST) t_MtrEnvTblY_MtrNm_u5p11[14];
extern CONST(float32, CAL_CONST) k_KeStdTemp_VpRadpS_f32;
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblX_MtrRadpS_u11p5[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblY_MtrNm_u4p12[6];
extern CONST(float32, CAL_CONST) k_SpdAdjSlewInc_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_SpdAdjSlewDec_MtrRadpS_f32;
extern CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_PwrLmtMtrVelLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16;
extern CONST(float32, CAL_CONST) k_LowVltAstRecTh_Volt_f32;
extern CONST(float32, CAL_CONST) k_PwrLmtVecuAltFltAdj_Volt_f32;
extern CONST(float32, CAL_CONST) k_PwrLmtVecuAdjSlew_VoltspL_f32;
#endif
