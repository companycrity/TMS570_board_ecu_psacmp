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
 * %version:          EA3#3 %
 * %derived_by:       gzkys7 %
 * %date_modified:    Fri Jul 27 16:40:23 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/* Test Definitions of tuning sets for UTP testing */
typedef uint16 TUNING_P_Str;
typedef uint16 TUNING_Y_Str;

P2CONST(uint16, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
P2CONST(uint16, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;

CONSTP2CONST(uint16, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[3];
CONSTP2CONST(uint16, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[3][5];

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/19/2016 12:28:08 PM ******************/
/*********************** TuningSelectAuthority - Rev 7 ***********************/



extern CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_TunSel_HwVelThresh_HwRadpS_f32;
extern CONST(uint16, CAL_CONST) t_TunSel_HwTrqThX_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_TunSel_HwTrqThY_HwNm_u4p12[5];
#endif


