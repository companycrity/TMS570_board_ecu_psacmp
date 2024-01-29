/*****************************************************************************
* Copyright 2016 Nexteer Automotive, All Rights Reserved.
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
 * %version:          EA3#9 %
 * %derived_by:       z172399 %
 * %date_modified:    Thu Jul 11 18:00:06 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/16/2018 1:45:28 PM *******************/
/****************************** PSASH - Rev 14 *******************************/




/*********************************** CF13A ***********************************/
extern CONST(float32, CAL_CONST) k_PsaSH_ApaAssiStallLim_MtrNm_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaSH_ApaDynErr_Cnt_str;
extern CONST(uint16, CAL_CONST) k_PsaSH_ApaDynHwThd_HwDeg_u16;
extern CONST(uint16, CAL_CONST) k_PsaSH_ApaExitCtrlProgsTi_mS_u16;
extern CONST(uint16, CAL_CONST) k_PsaSH_ApaStatHwThd_HwDeg_u16;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaHwAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaHwTrqMax_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_PsaSH_ApaHwTrqMaxTi_mS_u32;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaHwTrqMin_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_PsaSH_ApaHwTrqMinTi_mS_u32;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaMaxHwTrqFilt_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PsaSH_ApaStatErr_Cnt_str;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaThemLimPerc_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_ApaVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaCorrnFacReqRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaCorrnFacThd_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaDrvrAbsntDetnTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaDrvrIntvtWarnTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaHwAuthy_Uls_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaMaxHwTrq_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_PsaSH_LxaHwAgDetnCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PsaSH_LxaHwVelDetnCnt_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaHwTrqDetnTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaHwTrqRateThd_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaHwTrqRateDetnTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaHwTrqRateTi_Hz_f32;
extern CONST(float32, CAL_CONST) k_PsaSH_LxaVehSpdMin_Kph_f32;
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7[10];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaDrvrAbsntDetnTiY_Sec_u9p7[10];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrPStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrNStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11[9][8];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaDrvrAbsntHwVelThdY_HwRadpS_u7p9[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgCmdSatnY_HwDeg_u16[15];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwAgDetnCntrNStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwAgDetnCntrPStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5[9][8];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgCmdRateY_HwDegpS_u11p5[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgThdX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwAgThdY_HwDeg_u16[15];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwVelDetnCntrNStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwVelDetnCntrPStepY_Cnt_u16[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11[9][8];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwVelThdX_Kph_u9p7[8][9];
extern CONST(uint16, CAL_CONST) t2_PsaSH_LxaHwVelThdY_HwRadpS_u7p9[8][9];
extern CONST(uint16, CAL_CONST) t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_ApaHwAgCmdRateY_HwDegpS_u11p5[15];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11[8];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaInactvRstTmrX_Kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaInactvRstTmrY_Sec_u7p9[3];
extern CONST(uint16, CAL_CONST) t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7[9];
extern CONST(sint8, CAL_CONST) k_PsaSH_LxaDrvrIntvDetnThd_Uls_s08;
#endif


