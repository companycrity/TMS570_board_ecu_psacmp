/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Jan  17 16:48:22 2014
* %version:          EA3#6 %
* %derived_by:       nz2999 %
* %date_modified:    Mon Jan 27 18:16:49 2014 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 2018-02-07 09:58:40 *******************/
/******************************* PSASH - Rev 7 *******************************/



extern CONST(float32, CAL_CONST) k_PsaTA_APAEnableRate_UlspS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaTA_ApaPosServFltMode_Cnt_str;
extern CONST(float32, CAL_CONST) k_PsaTA_ApaPosnServoTran_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_DisableRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_FilterCutOff_Hz_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_LxaDiTranTi_Sec_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaTA_LxaHwTrqFltMode_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaTA_LxaHwTrqRateFltMode_Cnt_str;
extern CONST(float32, CAL_CONST) k_PsaTA_LxaHwTrqRateSftyThd_HwNmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaTA_LxaHwVelFltMode_Cnt_str;
extern CONST(float32, CAL_CONST) k_PsaTA_LxaMaxRate_UlspS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaTA_LxaOpTrqOvFltMode_Cnt_str;
extern CONST(float32, CAL_CONST) k_PsaTA_LxaPosnServoTran_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_LxaSftyMaxHwTorque_HwNm_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_MaxPosServoCmdSafety_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_PsaTA_MaxVehicleSpeedSafety_Kph_f32;
extern CONST(uint16, CAL_CONST) t_PsaTA_DisableRateX_HwNm_u11p5[6];
extern CONST(uint16, CAL_CONST) t_PsaTA_DisableRateY_UlspS_u11p5[6];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaHwVelSftyThdX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaHwVelSftyThdY_HwRadpS_u7p9[15];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaOpTrqOvBndX_Kph_u9p7[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaOpTrqOvBndY_MtrNm_u4p12[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaOpTrqOvSftyBndY_MtrNm_u4p12[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaSmotngFactorX_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaSmotngFactorY_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaSmotngSftyFactorX_Kph_u9p7[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_LxaSmotngSftyFactorY_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_SmoothingX_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_PsaTA_SmoothingY_Uls_u6p10[10];
#endif


