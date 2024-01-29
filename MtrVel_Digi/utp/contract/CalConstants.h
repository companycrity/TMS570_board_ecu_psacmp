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
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Wed May  8 15:40:32 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H



#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/11/2013 2:08:45 PM *******************/
/*************************** MotorVelocity - Rev 6 ***************************/


extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];
extern CONST(Boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32;
extern CONST(float32, CAL_CONST) k_DiagMtrVelFiltKn_Hz_f32;



#endif
