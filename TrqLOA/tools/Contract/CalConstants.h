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
* %version:          2 %
* %derived_by:       gzkys7 %
* %date_modified:    Thu May 23 11:37:52 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"
#include "fixmath.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 11/16/2015 6:18:43 PM ******************/
/****************************** TrqLOA  - Rev 2 ******************************/



extern CONST(float32, CAL_CONST) k_TrqLOA_AbsAssistThreshold_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_AbsVelThreshold_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterFalling_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterRising_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_FallingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LPF_Hz_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LatAccConversionFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LimOutput_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MaxScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MinScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_NomDrvTrq_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_RisingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_SteerRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_UndersteerGrad_RadpG_f32;
extern CONST(boolean, CAL_CONST) k_TrqLOA_UseVehWhlBasCal_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_TrqLOA_DiffGainX_G_u2p14[4];
extern CONST(uint16, CAL_CONST) t2_TrqLOA_DiffGainY_Uls_u1p15[8][4];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_X_Kph_u10p6[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_Y_Uls_u1p15[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_LatAccGain_Y_MtrNmpG_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_TempTrqCmdSatYTbl_MtrNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_X_Kph_u10p6[8];
extern CONST(float32, CAL_CONST) k_Cmn_VehWhlBas_mm_f32;
#endif


