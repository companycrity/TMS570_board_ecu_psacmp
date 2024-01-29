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
 * %version:          9 %
 * %derived_by:       kzdyfh %
 * %date_modified:    Tue Jun  4 11:20:23 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/28/2013 3:43:21 PM *******************/
/***************************** HystComp - Rev 23 *****************************/


extern CONST(float32, CAL_CONST) k_HysCmpLPAstLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HysCmpHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HysFinalOutLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HysRevGain_InvHwNm_f32;
extern CONST(uint16, CAL_CONST) k_LpFricIpLim_HwNm_u9p7;
extern CONST(uint16, CAL_CONST) t2_HysHwTrqBlndTblX_HwNm_u4p12[12][8];
extern CONST(uint16, CAL_CONST) t2_HysHwTrqBlndTblY_Uls_u4p12[12][8];
extern CONST(uint16, CAL_CONST) t_HysRiseTblX_HwNm_u2p14[6];
extern CONST(uint16, CAL_CONST) t_HysRiseTblY_Uls_u2p14[6];

/***************************** Cmn_t_VehSpd_Kph ******************************/
extern CONST(uint16, CAL_CONST) t_CmnVehSpd_Kph_u9p7[12];
extern CONST(uint16, CAL_CONST) t_EffLossTblY_Uls_u4p12[12];
extern CONST(uint16, CAL_CONST) t_EffOffTblY_HwNm_u9p7[12];
extern CONST(float32, CAL_CONST) k_CmnSysTrqRatio_HwNmpMtrNm_f32;
extern CONST(float32, CAL_CONST) k_HysOutLIm_HwNm_f32;
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricY_HwNm_u9p7[2][12];
extern CONST(sint16, CAL_CONST) t_HysCompCoulFricTempScaleX_DegC_s14p1[8];
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricTempScaleY_HwNm_u9p7[8];
extern CONST(uint16, CAL_CONST) t_HysCompHysSatY_HwNm_u9p7[12];
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6];
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendY_Uls_u2p14[6];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysCompX_MtrNm_u8p8[8];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysCompY_HwNm_u9p7[8];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysBlendX_HwNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysBlendY_Uls_u2p14[5];
#endif
