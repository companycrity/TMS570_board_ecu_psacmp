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
 * Date Created:      Sun Feb 26 18:00:00 2012
 * %version:          3 %
 * %derived_by:       gzkys7 %
 * %date_modified:    Mon Nov 25 14:40:17 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/19/2013 3:46:39 PM *******************/
/************* Absolute Handwheel Position (TC, I2C, VD) - Rev 1 *************/


extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;
extern CONST(boolean, CAL_CONST) k_UseTurnsCntr_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFCoeffFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_I2CHwAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxVehCntrOffDiff_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLimit_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_HWAtoMtrADiffLimit_HwDeg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwAtoMtrAError_str;
extern CONST(float32, CAL_CONST) k_VehCntrOffValidLimit_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinSensorlessAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxSensorlessAuthority_Uls_f32;
#endif
