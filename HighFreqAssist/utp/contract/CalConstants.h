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
 * Date Created:      Thu Apr  5 16:00:00 2012
 * %version:          2 %
 * %derived_by:       kzdyfh %
 * %date_modified:    Thu May  2 12:09:12 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/2/2013 11:15:50 AM *******************/
/*********************** High Frequency Assist - Rev 2 ***********************/


extern CONST(uint16, CAL_CONST) t_LPFKnY_Hz_u7p9[12];

/***************************** Cmn_t_VehSpd_Kph ******************************/
extern CONST(uint16, CAL_CONST) t_CmnVehSpd_Kph_u9p7[12];
extern CONST(uint16, CAL_CONST) t2_TorqX0_HwNm_u5p11[12][13];
extern CONST(uint16, CAL_CONST) t2_TorqX1_HwNm_u5p11[12][13];
extern CONST(uint16, CAL_CONST) t2_GainY0_MtrNmpHwNm_u3p13[12][13];
extern CONST(uint16, CAL_CONST) t2_GainY1_MtrNmpHwNm_u3p13[12][13];
extern CONST(uint16, CAL_CONST) t2_WIRBlendX_MtrNm_u4p12[12][5];
extern CONST(uint16, CAL_CONST) t2_WIRBlendY_Uls_u1p15[12][5];
#endif
