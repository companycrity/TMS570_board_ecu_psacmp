/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Rijvi Ahmed
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       jzk9cc %
 * %date_modified:    Tue Feb 12 10:22:28 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 4/10/2014 3:04:30 PM *******************/
/***************************** HOWDetect - Rev 1 *****************************/



extern CONST(uint16, CAL_CONST) t_HOWVehSpd_Kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t_HOWHighFreqGainY_Uls_u9p7[3];
extern CONST(uint16, CAL_CONST) t2_HOWHFRateX_HwNm_u8p8[3][6];
extern CONST(sint16, CAL_CONST) t2_HOWHFRateY_UlspS_s7p8[3][6];
extern CONST(uint16, CAL_CONST) t2_HOWLFRateX_HwNm_u8p8[3][5];
extern CONST(sint16, CAL_CONST) t2_HOWLFRateY_UlspS_s7p8[3][5];
extern CONST(uint16, CAL_CONST) t_HOWStateThresholds_Uls_u8p8[7];
extern CONST(float32, CAL_CONST) k_HOWTrqInitLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqHPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqFinalLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWSlewRate_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_HOWDecaySF_Uls_f32;
extern CONST(float32, CAL_CONST) k_HOWEstLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HOWStateLPFKn_Hz_f32;
#endif


