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
* %version:          EA3#6 %
* %date_modified:    Fri May 10 10:19:58 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 2018-02-23 12:29:28 *******************/
/***************************** PosServo - Rev 9 ******************************/



extern CONST(float32, CAL_CONST) k_PrkAstDTermKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_PrkAstEnableRate_pSec_f32;
extern CONST(float32, CAL_CONST) k_PrkAstHwaLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_PosSrvo_PidLim_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_PrkAstHwTrqLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_PrkAstITermAWLmtY_MtrNm_u9p7[9];
extern CONST(uint16, CAL_CONST) t_PrkAstDmpTrqX_MtrRadpS_u11p5[13];
extern CONST(uint16, CAL_CONST) t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9[9];
extern CONST(uint16, CAL_CONST) t_PrkAstDisableRateX_HwNm_u11p5[6];
extern CONST(uint16, CAL_CONST) t_PrkAstDisableRateY_pSec_u12p4[6];
extern CONST(uint16, CAL_CONST) t_HwaRateLimit_HwDegpSec_u12p4[9];
extern CONST(uint16, CAL_CONST) t_PrkAstIGainY_MtrNmpHwDegS_u2p14[9];
extern CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdY_MtrNm_u5p11[4];
extern CONST(uint16, CAL_CONST) t_PrkAstSmoothX_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PrkAstSmoothY_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PrkAstVehSpdBS_Kph_u9p7[9];
extern CONST(uint16, CAL_CONST) t2_PrkAstDmpTrqY_MtrNm_u4p12[9][13];
extern CONST(uint16, CAL_CONST) t2_PrkAstPGainX_HwDeg_u12p4[9][7];
extern CONST(uint16, CAL_CONST) t2_PrkAstPGainY_MtrNm_u9p7[9][7];
#endif


