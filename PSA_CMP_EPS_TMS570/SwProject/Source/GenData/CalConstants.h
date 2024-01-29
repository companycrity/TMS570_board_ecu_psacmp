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
 * Date Created:      Mon Feb 17 17:00:00 2014
 * %version:          37 %
 * %derived_by:       nz3337 %
 * %date_modified:    Wed Feb 26 16:37:43 2014 %
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_DiagMgr_Types.h"
#include "DiagSvc.h"

#define D_NUMOFTUNSETS_CNT_U16 	5U
#define D_NUMOFPERS_CNT_U16 	3U


#define BC_XCP_MAXPERCOPY_CNT_U8	1U


/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/17/2018 12:14:35 PM ******************/
/***************************** PSA BMPV - Rev 37 *****************************/



/************* Tuning Structure Definition for "Y" Calibrations **************/

typedef struct
{
	float32	k_EnableHwAuthMin_Uls_f32;
	float32	k_EnableHwPosMax_HwDeg_f32;
	float32	k_EnableHwTrqMax_HwNm_f32;
	float32	k_EnableHwVelMax_DegpS_f32;
	float32	k_EnableLatAccMax_MpSecSq_f32;
	uint32	k_EnableTime_mS_u32;
	float32	k_EnableVehSpdMax_Kph_f32;
	float32	k_EnableVehSpdMin_Kph_f32;
	float32	k_EnableVehSpdRateMax_KphpS_f32;
	float32	k_EnableYawRateMax_DegpS_f32;
	float32	k_FiltDeadband_HwNm_f32;
	float32	k_HwNmToMtrNm_MtrNmpHwNm_f32;
	float32	k_HwTrqFilt_Hz_f32;
	float32	k_LTFilt_Hz_f32;
	float32	k_LTIntInputLimit_HwNm_f32;
	float32	k_LTLearnTime_Min_f32;
	float32	k_LTLimit_HwNm_f32;
	float32	k_OutputMaxRate_HwNmpS_f32;
	float32	k_PullCmp_LTIntgtrStCorrnGain_Uls_f32;
	float32	k_PullCmp_STIntgtrStCorrnGain_Uls_f32;
	float32	k_STFilt_Hz_f32;
	float32	k_STIntInputLimit_HwNm_f32;
	float32	k_STLearnTimeDec_Sec_f32;
	float32	k_STLearnTimeInc_Sec_f32;
	float32	k_STLimit_HwNm_f32;
	uint32	k_STOppSignTime_mS_u32;
	float32	k_STRampTime_Sec_f32;
	float32	k_STResetHwPos_HwDeg_f32;
	float32	k_STResetHwTrq_HwNm_f32;
	float32	k_STResetLatAcc_MpSecSq_f32;
	float32	k_STResetYawRate_DegpS_f32;
	float32	k_TotalLimit_HwNm_f32;
	float32	k_YawRateFilt_Hz_f32;
	uint16	t_VehSpdScaleTblX_Kph_u9p7[4];
	uint16	t_VehSpdScaleTblY_Uls_u2p14[4];
	uint16	t_AsstThermSclX_Cnt_u16p0[2];
	uint16	t_AsstThermSclY_Uls_u2p14[2];
	float32	k_AsstFWFiltKn_Hz_f32;
	float32	k_AsstFWFWActiveLPF_Hz_f32;
	float32	k_AsstFWInpLimitBaseAsst_MtrNm_f32;
	float32	k_AsstFWInpLimitHFA_MtrNm_f32;
	float32	k_AsstFWInpLimitHysComp_MtrNm_f32;
	uint16	k_AsstFWNstep_Cnt_u16;
	uint16	k_AsstFWPstep_Cnt_u16;
	float32	k_RestoreThresh_MtrNm_f32;
	uint16	t_AsstFWPstepNstepThresh_Cnt_u16[2];
	float32	k_SumLim_CmdSftyLimr_MtrNm_f32;
	DiagSettings_Str	k_SumLim_LrnPnCtrDebounce_Cnt_str;
	sint16	t_TempScaleX_DegC_s8p7[11];
	uint16	t_TempScaleY_Uls_u4p12[11];
	float32	k_DampFWErrThresh_MtrNm_f32;
	float32	k_DampFWFWActiveLPF_Hz_f32;
	uint16	k_DampFWInCmpNStep_Cnt_u16;
	uint16	k_DampFWInCmpPStep_Cnt_u16;
	float32	k_DampFWInpLimitDamp_MtrNm_f32;
	uint16	k_DampFWNstep_Cnt_u16;
	uint16	k_DampFWPstep_Cnt_u16;
	float32	k_DampFWVBICLPF_Hz_f32;
	uint16	t_DampFWAddDampAFWX_MtrRadpS_u11p5[8];
	uint16	t_DampFWAddDampAFWY_MtrNm_u5p11[8];
	uint16	t_DampFWAddDampDFWX_MtrRadpS_u11p5[8];
	uint16	t_DampFWAddDampDFWY_MtrNm_u5p11[8];
	uint16	t_DampFWDampInrtCmpPNThesh_Cnt_u16[2];
	uint16	t_DampFWPNstepThresh_Cnt_u16[2];
	float32	k_DmpDecelGain_Uls_f32;
	float32	k_DmpDecelGainFSlew_UlspS_f32;
	float32	k_DmpGainOffThresh_KphpS_f32;
	float32	k_DmpGainOnThresh_KphpS_f32;
	uint16	t_DmpDecelGainSlewX_MtrRadpS_u11p5[6];
	uint16	t_DmpDecelGainSlewY_UlspS_u13p3[6];
	uint16	k_EOTDefltPosition_HwDeg_u12p4;
	uint16	k_EOTDeltaTrqThrsh_HwNm_u9p7;
	uint16	k_EOTEnterLPFKn_Cnt_u16;
	uint16	k_EOTExitLPFKn_Cnt_u16;
	uint16	k_EOTImpSpdEn_Kph_u9p7;
	Boolean	k_EOTOriginalImpactandSoftEnd_Cnt_lgc;
	float32	k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32;
	uint16	k_EOTStateHwTrqLPFKn_Cnt_u16;
	uint16	k_MaxRackTrvl_HwDeg_u12p4;
	uint16	k_PosRampStep_HwDeg_u12p4;
	Boolean	k_SoftStopEOTEnable_Cnt_lgc;
	uint16	k_SpdIptScale_MtrNmpRadpS_u4p12;
	uint16	t_EOTDmpVspd_Kph_u9p7[4];
	uint16	t_EOTEnterGainVspd_Kph_u9p7[4];
	uint16	t_SpdIptTblXTbl_HwDeg_u12p4[2];
	uint16	t_SpdIptTblYTbl_MtrRadpS_u12p4[2];
	uint16	t_TrqTableX_HwNm_u8p8[2];
	uint16	t2_EOTEnterGainX_HwDeg_u12p4[4][4];
	uint16	t2_EOTEnterGainY_Uls_u1p15[4][4];
	uint16	t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16[4][2];
	uint16	t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16[4][2];
	uint16	k_EOTDynConf_Uls_u8p8;
	uint16	k_MinRackTrvl_HwDeg_u12p4;
	uint16	t2_EOTPosDepDmpTblX_HwDeg_u12p4[4][2];
	float32	k_EOTDmpFWInactiveLim_MtrNm_f32;
	float32	k_EOTDmpFWInputLim_MtrNm_f32;
	uint16	k_LpFricIpLim_HwNm_u9p7;
	uint16	t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6];
	uint16	t_HysCompCoulFricWIRBlendY_Uls_u2p14[6];
	float32	k_PosSrvo_PidLim_MtrNm_f32;
	float32	k_PrkAstDTermKn_Hz_f32;
	float32	k_PrkAstEnableRate_pSec_f32;
	float32	k_PrkAstHwaLPFKn_Hz_f32;
	float32	k_PrkAstHwTrqLPFKn_Hz_f32;
	uint16	t_HwaRateLimit_HwDegpSec_u12p4[9];
	uint16	t_PosSrvoMaxCmdX_Kph_u9p7[4];
	uint16	t_PosSrvoMaxCmdY_MtrNm_u5p11[4];
	uint16	t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9[9];
	uint16	t_PrkAstDisableRateX_HwNm_u11p5[6];
	uint16	t_PrkAstDisableRateY_pSec_u12p4[6];
	uint16	t_PrkAstDmpTrqX_MtrRadpS_u11p5[13];
	uint16	t_PrkAstIGainY_MtrNmpHwDegS_u2p14[9];
	uint16	t_PrkAstITermAWLmtY_MtrNm_u9p7[9];
	uint16	t_PrkAstSmoothX_Uls_u6p10[10];
	uint16	t_PrkAstSmoothY_Uls_u6p10[10];
	uint16	t_PrkAstVehSpdBS_Kph_u9p7[9];
	uint16	t2_PrkAstDmpTrqY_MtrNm_u4p12[9][13];
	uint16	t2_PrkAstPGainX_HwDeg_u12p4[9][7];
	uint16	t2_PrkAstPGainY_MtrNm_u9p7[9][7];
	float32	k_PsaAgAn_AbsHwPosLvl1_HwDeg_f32;
	float32	k_PsaAgAn_AbsHwPosLvl2_HwDeg_f32;
	float32	k_PsaAgAn_DiagPrec_HwDeg_f32;
	float32	k_PsaAgAn_EpsPrec_HwDeg_f32;
	float32	k_PsaAgAn_HwTrqFilt_Hz_f32;
	float32	k_PsaAgAn_MinPrecFail_HwDeg_f32;
	float32	k_PsaAgAn_MtrVelFilt_Hz_f32;
	float32	k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32;
	uint8	k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08;
	float32	k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32;
	uint8	k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08;
	float32	k_PsaAgAn_OffsetPolarity_HwDeg_f32;
	float32	k_PsaAgAn_PinionTrqFilt_Hz_f32;
	float32	k_PsaAgAn_VehCondMaxHwTrq_HwNm_f32;
	float32	k_PsaAgAn_VehCondMaxMtrVel_MtrRadpS_f32;
	float32	k_PsaAgAn_VehCondMaxPinTrq_HwNm_f32;
	float32	k_PsaAgAn_VehCondMaxVehSpd_Kph_f32;
	uint32	k_PsaAgAn_VehCondMinTi_mS_u32;
	float32	k_PsaSH_ApaAssiStallLim_MtrNm_f32;
	DiagSettings_Str	k_PsaSH_ApaDynErr_Cnt_str;
	uint16	k_PsaSH_ApaDynHwThd_HwDeg_u16;
	uint16	k_PsaSH_ApaExitCtrlProgsTi_mS_u16;
	float32	k_PsaSH_ApaHwAuthority_Uls_f32;
	float32	k_PsaSH_ApaHwTrqMax_HwNm_f32;
	uint32	k_PsaSH_ApaHwTrqMaxTi_mS_u32;
	float32	k_PsaSH_ApaHwTrqMin_HwNm_f32;
	uint32	k_PsaSH_ApaHwTrqMinTi_mS_u32;
	float32	k_PsaSH_ApaMaxHwTrqFilt_Hz_f32;
	DiagSettings_Str	k_PsaSH_ApaStatErr_Cnt_str;
	uint16	k_PsaSH_ApaStatHwThd_HwDeg_u16;
	float32	k_PsaSH_ApaThemLimPerc_Uls_f32;
	float32	k_PsaSH_ApaVehSpd_Kph_f32;
	float32	k_PsaSH_LxaCorrnFacReqRate_UlspS_f32;
	float32	k_PsaSH_LxaCorrnFacThd_Uls_f32;
	float32	k_PsaSH_LxaDrvrAbsntDetnTi_Sec_f32;
	sint8	k_PsaSH_LxaDrvrIntvDetnThd_Uls_s08;
	float32	k_PsaSH_LxaDrvrIntvtWarnTi_Sec_f32;
	uint16	k_PsaSH_LxaHwAgDetnCnt_Cnt_u16;
	float32	k_PsaSH_LxaHwAuthy_Uls_f32;
	float32	k_PsaSH_LxaHwTrqDetnTi_Sec_f32;
	float32	k_PsaSH_LxaHwTrqRateDetnTi_Sec_f32;
	float32	k_PsaSH_LxaHwTrqRateThd_HwNmpS_f32;
	float32	k_PsaSH_LxaHwTrqRateTi_Hz_f32;
	uint16	k_PsaSH_LxaHwVelDetnCnt_Cnt_u16;
	float32	k_PsaSH_LxaMaxHwTrq_HwNm_f32;
	float32	k_PsaSH_LxaVehSpdMin_Kph_f32;
	uint16	t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7[15];
	uint16	t_PsaSH_ApaHwAgCmdRateY_HwDegpS_u11p5[15];
	uint16	t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7[10];
	uint16	t_PsaSH_LxaDrvrAbsntDetnTiY_Sec_u9p7[10];
	uint16	t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7[15];
	uint16	t_PsaSH_LxaDrvrAbsntHwVelThdY_HwRadpS_u7p9[15];
	uint16	t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7[15];
	uint16	t_PsaSH_LxaHwAgCmdRateY_HwDegpS_u11p5[15];
	uint16	t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7[15];
	uint16	t_PsaSH_LxaHwAgCmdSatnY_HwDeg_u16[15];
	uint16	t_PsaSH_LxaHwAgThdX_Kph_u9p7[15];
	uint16	t_PsaSH_LxaHwAgThdY_HwDeg_u16[15];
	uint16	t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11[8];
	uint16	t_PsaSH_LxaInactvRstTmrX_Kph_u9p7[3];
	uint16	t_PsaSH_LxaInactvRstTmrY_Sec_u7p9[3];
	uint16	t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7[9];
	uint16	t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrNStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrPStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11[9][8];
	uint16	t2_PsaSH_LxaHwAgDetnCntrNStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaHwAgDetnCntrPStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5[9][8];
	uint16	t2_PsaSH_LxaHwVelDetnCntrNStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaHwVelDetnCntrPStepY_Cnt_u16[9][8];
	uint16	t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11[9][8];
	uint16	t2_PsaSH_LxaHwVelThdX_Kph_u9p7[8][9];
	uint16	t2_PsaSH_LxaHwVelThdY_HwRadpS_u7p9[8][9];
	float32	k_PsaTA_APAEnableRate_UlspS_f32;
	float32	k_PsaTA_ApaPosnServoTran_Uls_f32;
	DiagSettings_Str	k_PsaTA_ApaPosServFltMode_Cnt_str;
	float32	k_PsaTA_DisableRate_UlspS_f32;
	float32	k_PsaTA_FilterCutOff_Hz_f32;
	float32	k_PsaTA_LxaDiTranTi_Sec_f32;
	DiagSettings_Str	k_PsaTA_LxaHwTrqFltMode_Cnt_str;
	DiagSettings_Str	k_PsaTA_LxaHwTrqRateFltMode_Cnt_str;
	float32	k_PsaTA_LxaHwTrqRateSftyThd_HwNmpS_f32;
	DiagSettings_Str	k_PsaTA_LxaHwVelFltMode_Cnt_str;
	float32	k_PsaTA_LxaMaxRate_UlspS_f32;
	DiagSettings_Str	k_PsaTA_LxaOpTrqOvFltMode_Cnt_str;
	float32	k_PsaTA_LxaPosnServoTran_Uls_f32;
	float32	k_PsaTA_LxaSftyMaxHwTorque_HwNm_f32;
	float32	k_PsaTA_MaxPosServoCmdSafety_MtrNm_f32;
	float32	k_PsaTA_MaxVehicleSpeedSafety_Kph_f32;
	uint16	t_PsaTA_DisableRateX_HwNm_u11p5[6];
	uint16	t_PsaTA_DisableRateY_UlspS_u11p5[6];
	uint16	t_PsaTA_LxaHwVelSftyThdX_Kph_u9p7[15];
	uint16	t_PsaTA_LxaHwVelSftyThdY_HwRadpS_u7p9[15];
	uint16	t_PsaTA_LxaOpTrqOvBndX_Kph_u9p7[10];
	uint16	t_PsaTA_LxaOpTrqOvBndY_MtrNm_u4p12[10];
	uint16	t_PsaTA_LxaOpTrqOvSftyBndY_MtrNm_u4p12[10];
	uint16	t_PsaTA_LxaSmotngFactorX_Uls_u6p10[10];
	uint16	t_PsaTA_LxaSmotngFactorY_Uls_u6p10[10];
	uint16	t_PsaTA_LxaSmotngSftyFactorX_Kph_u9p7[10];
	uint16	t_PsaTA_LxaSmotngSftyFactorY_Uls_u6p10[10];
	uint16	t_PsaTA_SmoothingX_Uls_u6p10[10];
	uint16	t_PsaTA_SmoothingY_Uls_u6p10[10];
	float32	k_RtnOffsetRange_HWDeg_f32;
	float32	k_RtnOffsetSlew_HwDegpS_f32;
	uint16	t_ReturnTempScaleSclYTbl_Uls_u8p8[14];
	sint16	t_ReturnTempScaleXTbl_DegC_s11p4[14];
	uint16	t_ReturnVSpdTblBS_Kph_u9p7[9];
	uint16	t_RtrnFWVehSpd_Kph_u9p7[8];
	float32	k_TunSel_HwVelThresh_HwRadpS_f32;
	float32	k_TunSelHwTrqLPFKn_Hz_f32;
	float32	k_TunSelVehSpdThresh_Kph_f32;
	uint16	t_TunSel_HwTrqThX_Kph_u9p7[5];
	uint16	t_TunSel_HwTrqThY_HwNm_u4p12[5];
	float32	k_AutoCntrHiSpdCntrWindow_HwDeg_f32;
	float32	k_AutoCntrHiSpdFilt1Kn_Hz_f32;
	float32	k_AutoCntrHiSpdFilt2Kn_Hz_f32;
	uint16	k_AutoCntrHiSpdTimer1_mS_u16;
	float32	k_AutoCntrHiSpdTimer1MtrVel_MtrRadpS_f32;
	float32	k_AutoCntrHiSpdTimer1PinTrq_HwNm_f32;
	float32	k_AutoCntrHiSpdTimer1VehSpd_kph_f32;
	uint16	k_AutoCntrHiSpdTimer2_mS_u16;
	uint16	k_AutoCntrHiSpdTimer4_mS_u16;
	float32	k_AutoCntrHiSpdTimer4CntrWindow_HwDeg_f32;
	float32	k_AutoCntrHiSpdTimer4MtrVel_MtrRadpS_f32;
	float32	k_AutoCntrHiSpdTimer4PinTrq_HwNm_f32;
	float32	k_AutoCntrHiSpdTimer4VehSpd_kph_f32;
	float32	k_AutoCntrLoSpdCntrWindow_HwDeg_f32;
	float32	k_AutoCntrLoSpdFilt1Kn_Hz_f32;
	float32	k_AutoCntrLoSpdFilt2Kn_Hz_f32;
	uint16	k_AutoCntrLoSpdTimer1_mS_u16;
	float32	k_AutoCntrLoSpdTimer1MtrVel_MtrRadpS_f32;
	float32	k_AutoCntrLoSpdTimer1PinTrq_HwNm_f32;
	float32	k_AutoCntrLoSpdTimer1VehSpd_kph_f32;
	uint16	k_AutoCntrLoSpdTimer2_mS_u16;
	float32	k_AutoCntrPinTrqLPFCoeffKn_Hz_f32;
	float32	k_HiSpdVDAuthority_Uls_f32;
	float32	k_HwTqMgnThd_HwNm_f32;
	float32	k_LoSpdVDAuthority_Uls_f32;
	boolean	k_SLPEnableBFCheck_Cnt_lgc;
	float32	k_SLPHwAuthority_Uls_f32;
	float32	k_SLPMinHwAuthToStoreHwPos_Uls_f32;
	uint32	k_SrlHwAgVldTiThd_mS_u32;
	float32	k_TravelXCDeadband_Uls_f32;
	float32	k_TravelXCHwAuthority_Uls_f32;
	float32	k_VehDyn_ErrTolr_HwDeg_f32;
	float32	k_VehDyn_SmoothCoeff_Uls_f32;
	float32	k_VehDyn_TravelXCDeadbandTolr_Uls_f32;

} TUNING_Y_Str;

/************* Tuning Structure Definition for "P" Calibrations **************/

typedef struct
{
	sint16	t2_AsstAsstY0_MtrNm_s4p11[12][20];
	uint16	t2_AsstHwtX0_HwNm_u8p8[12][20];
	uint16	t_CmnVehSpd_Kph_u9p7[12];
	uint16	t_AsstFWDefltAssistX_HwNm_u8p8[20];
	sint16	t_AsstFWDefltAssistY_MtrNm_s4p11[20];
	uint16	t_AsstFWVehSpd_Kph_u9p7[8];
	sint16	t2_AsstFWUprBoundX_HwNm_s4p11[8][11];
	sint16	t2_AsstFWUprBoundY_MtrNm_s4p11[8][11];
	float32	k_HPSbaseC1_MtrNmpMtrRadpS_f32;
	float32	k_HPSbaseC2_MtrNmpMtrRadpS_f32;
	float32	k_HPSbaseC3_MtrNmpMtrRadpS_f32;
	float32	k_HPSbaseC4_MtrNmpMtrRadpS_f32;
	float32	k_HPSOutLimit_MtrNm_f32;
	float32	k_MtrVelDampLPFKn_Hz_f32;
	float32	k_QDDHwTrqBckLash_HwNm_f32;
	float32	k_QddHwTrqDampKn_Hz_f32;
	float32	k_QDDMtrVelBckLash_MtrRadpS_f32;
	float32	k_QddMtrVelDampKn_Hz_f32;
	float32	k_QddSfLFPKn_Hz_f32;
	float32	k_Quad13DmpMult_Uls_f32;
	float32	k_Quad24DmpMult_Uls_f32;
	uint16	t_HPSAsstLimY_MtrNm_u4p12[12];
	uint16	t_HPSscaleC1Y_Uls_u4p12[12];
	uint16	t_HPSscaleC2Y_Uls_u4p12[12];
	uint16	t_HPSscaleC3Y_Uls_u4p12[12];
	uint16	t_HPSscaleC4Y_Uls_u4p12[12];
	uint16	t_HwTrqDmpTblX_HwNm_u8p8[2];
	uint16	t_HwTrqDmpTblY_Uls_u1p15[2];
	uint16	t2_MtrVelDmpTblX_MtrRadpS_u12p4[12][13];
	uint16	t2_MtrVelDmpTblY_MtrNm_u5p11[12][13];
	float32	k_DmpBoundLPFKn_Hz_f32;
	uint16	t_DampFWDefltDampX_MtrRadpS_u11p5[11];
	uint16	t_DampFWDefltDampY_MtrNm_u5p11[11];
	sint16	t_DampFWUprBoundX_MtrRadpS_s11p4[11];
	uint16	t_DampFWVehSpd_Kph_u9p7[8];
	sint16	t2_DampFWUprBoundY_MtrNm_s7p8[8][11];
	float32	k_InrtCmp_MtrInertia_KgmSq_f32;
	float32	k_InrtCmp_MtrVel_ScaleFactor_Uls_f32;
	float32	k_InrtCmp_TBarVelLPFKn_Hz_f32;
	uint16	t_DmpADDCoefX_MtrNm_u4p12[10];
	uint16	t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17[10];
	uint16	t_FDD_AttenTblX_MtrRadpS_u12p4[2];
	uint16	t_FDD_AttenTblY_Uls_u8p8[2];
	uint16	t_FDD_BlendTblY_Uls_u8p8[12];
	uint16	t_InrtCmp_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17[2][10];
	uint16	t2_FDD_FreqTblYM_Hz_u12p4[2][12];
	sint16	t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4[5];
	uint16	t_EOTDmpFWVehSpd_Kph_u9p7[4];
	sint16	t2_EOTDmpFWActiveBoundY_MtrNm_s7p8[4][5];
	uint16	t_LPFKnY_Hz_u7p9[12];
	uint16	t2_GainY0_MtrNmpHwNm_u3p13[12][13];
	uint16	t2_TorqX0_HwNm_u5p11[12][13];
	float32	k_HysCmpHwTrqLPFKn_Hz_f32;
	float32	k_HysCmpLPAstLPFKn_Hz_f32;
	float32	k_HysFinalOutLPFKn_Hz_f32;
	float32	k_HysOutLIm_HwNm_f32;
	float32	k_HysRevGain_InvHwNm_f32;
	uint16	t_EffLossTblY_Uls_u4p12[12];
	uint16	t_EffOffTblY_HwNm_u9p7[12];
	sint16	t_HysCompCoulFricTempScaleX_DegC_s14p1[8];
	uint16	t_HysCompCoulFricTempScaleY_HwNm_u9p7[8];
	uint16	t_HysCompCoulFricY_HwNm_u9p7[2][12];
	uint16	t_HysCompHysSatY_HwNm_u9p7[12];
	uint16	t_HysCompNegHysBlendX_HwNm_u9p7[5];
	uint16	t_HysCompNegHysBlendY_Uls_u2p14[5];
	uint16	t_HysCompNegHysCompX_MtrNm_u8p8[8];
	uint16	t_HysCompNegHysCompY_HwNm_u9p7[8];
	uint16	t_HysRiseTblX_HwNm_u2p14[6];
	uint16	t_HysRiseTblY_Uls_u2p14[6];
	uint16	t2_HysHwTrqBlndTblX_HwNm_u4p12[12][8];
	uint16	t2_HysHwTrqBlndTblY_Uls_u4p12[12][8];
	uint16	t_PsaDSG_DampgCmdFacVehSpdBndTbl_Kph_u9p7[4];
	uint16	t2_PsaDSG_DampgCmdFacHwTqX_HwNm_u4p12[4][12];
	uint16	t2_PsaDSG_DampgCmdFacY_Uls_u1p15[4][12];
	float32	k_RtnHWAuthSlew_UlspS_f32;
	uint16	t_HWAuthRetScl_X_Uls_u8p8[4];
	uint16	t_HWAuthRetScl_Y_Uls_u9p7[4];
	uint16	t2_ReturnPosTblXM_HwDeg_u12p4[9][16];
	uint16	t2_ReturnPosTblYM_MtrNm_u5p11[9][16];
	uint16	t2_ReturnSclTrqTblXM_HwNm_T_u8p8[9][8];
	uint16	t2_ReturnSclTrqTblYM_Uls_u8p8[9][8];
	uint16	t2_ReturnSclVelTblXM_HwRadpS_T_u7p9[9][4];
	uint16	t2_ReturnSclVelTblYM_Uls_u8p8[9][4];
	sint16	t_RtrnFWUprBoundX_HwDeg_s11p4[11];
	sint16	t2_RtrnFWUprBoundY_MtrNm_s4p11[8][11];
	float32	k_StCmpHwTrqLPFKn_Hz_f32;
	uint16	k_StCmpStabCmpNstep_Cnt_u16;
	uint16	k_StCmpStabCmpPNThresh_Cnt_u16;
	uint16	k_StCmpStabCmpPstep_Cnt_u16;
	float32	k_StCmpSysCorrThresh_MtrNm_f32;
	uint16	t_StCmpADDFBlendX_Uls_u2p14[2];
	uint16	t_StCmpADDFBlendY_Uls_u2p14[2];
	uint16	t_StCmpBlend12Trq_HwNm_u8p8[5];
	uint16	t_StCmpBlend34Trq_HwNm_u8p8[5];
	uint16	t_StCmpBlendSpdBS_Kph_u9p7[6];
	NotchFiltK_Str	t_StCmpNFK_Str[4];
	uint16	t2_StCmpBlend02TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend04TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend12TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend34TblY_Uls_u2p14[6][5];

} TUNING_P_Str;


/***************************** AbsHwPos_TcI2cVd ******************************/
extern CONST(float32, CAL_CONST) k_HWAtoMtrADiffLimit_HwDeg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwAtoMtrAError_str;
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFCoeffFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_I2CHwAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLimit_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MaxSensorlessAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxVehCntrOffDiff_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinSensorlessAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32;
extern CONST(boolean, CAL_CONST) k_UseTurnsCntr_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehCntrOffValidLimit_HwDeg_f32;

/************************************ Adc ************************************/
extern CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16;
extern CONST(uint32, CAL_CONST) k_VbattOVTransIntConfig_Cnt_u32;

/********************************** Assist ***********************************/
extern CONST(sint16, CAL_CONST) t2_AsstAsstY1_MtrNm_s4p11[12][20];
extern CONST(uint16, CAL_CONST) t2_AsstHwtX1_HwNm_u8p8[12][20];
extern CONST(uint16, CAL_CONST) t2_AsstWIRBlendY_Uls_u2p14[12][5];
extern CONST(uint16, CAL_CONST) t2_AsstWIRBlndX_MtrNm_u5p11[12][5];

/******************************** AvgFricLrn *********************************/
extern CONST(float32, CAL_CONST) k_AvgFricLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_BaselineEOLFric_HwNm_f32;
extern CONST(float32, CAL_CONST) k_DataPrepLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffLimitHigh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffLimitLow_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffScalingFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLimitHigh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLimitLow_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FrictionDiagThreshold_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_FrictionDiagTimer_mS_u32;
extern CONST(float32, CAL_CONST) k_HwPosAuthMin_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwVelConstLimit_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelMax_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelMin_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_IgnCycleFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_LatAccMax_MpSecSqrd_f32;
extern CONST(float32, CAL_CONST) k_LatAccMin_MpSecSqrd_f32;
extern CONST(float32, CAL_CONST) k_LearningGain_Uls_f32;
extern CONST(uint32, CAL_CONST) k_LearningThreshold_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_RangeCounterLimit_Cnt_u16;
extern CONST(float32, CAL_CONST) k_SatFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TempMax_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempMin_DegC_f32;
extern CONST(float32, CAL_CONST) t_BaselineFric_HwNm_f32[4];
extern CONST(float32, CAL_CONST) t_FrHystHwAPts_HwDeg_f32[4];
extern CONST(float32, CAL_CONST) t_FricChgWeight_Uls_f32[4];
extern CONST(uint16, CAL_CONST) t_InvRatioX_HwDeg_u11p5[10];
extern CONST(uint16, CAL_CONST) t_InvRatioY_HwNmpMtrNm_u6p10[10];
extern CONST(boolean, CAL_CONST) t_MskVehSpd_Cnt_lgc[4];
extern CONST(uint16, CAL_CONST) t2_BaselineRangeCounter_Cnt_u16[8][3];
extern CONST(float32, CAL_CONST) t2_BaselineTheta_HwNm_f32[8][4];
extern CONST(float32, CAL_CONST) t2_VehSpd_Kph_f32[4][2];

/****************************** BatteryVoltage *******************************/
extern CONST(float32, CAL_CONST) k_MaxBattVoltDiff_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VecuCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_VecuVbatCorrLim_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VswitchCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_VswitchCorrLim_Volts_f32;

/************************** BatteryVoltage, BkCpPc ***************************/
extern CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32;

/********************************** BkCpPc ***********************************/
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaExtOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNonOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNormlOp_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChargePumpDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_MaxDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_MinDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrMotionThresh_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_OVERRIDESIGDIAGOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_PMOSDIAGOpenThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PMOSTError_mS_u16;
extern CONST(float32, CAL_CONST) k_PMOSVError_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PrechargeThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_PwrDiscCloseThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_PwrDiscOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshExNorm_Volt_f32;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshNonExt_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VerifyPwrDiscCloseDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscCloseThresh_mS_u16;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscOpenThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_VswitchDeltaThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_WaitForSqrWaveThresh_mS_u16;

/********************************** BVDiag ***********************************/
extern CONST(uint16, CAL_CONST) k_BattDiagUvMax_Volt_u10p6;
extern CONST(uint16, CAL_CONST) k_BattDiagUvMin_Volt_u10p6;
extern CONST(uint16, CAL_CONST) k_BattUvRecMax_Volt_u10p6;
extern CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_MSALowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_MSALowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_MSALowNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_MSALowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_UvDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_UvNotDetect_ms_u16p0;

/********************************* CmMtrCurr *********************************/
extern CONST(float32, CAL_CONST) k_CurrCorrErrFiltFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_CurrCorrErrThresh_Amps_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Amps_f32;
extern CONST(uint16, CAL_CONST) k_CurrOffGainKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CurrOffNoofAvg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MaxCurrOffMtrVel_RadpS_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinOffset_Volts_f32;
extern CONST(uint16, CAL_CONST) k_MtrCurrOffLoComOff_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MtrPosComputDelay_Sec_f32;

/******************************** CMS_Common *********************************/
extern CONST(sint8, CAL_CONST) k_CMSGotoPosPol_Cnt_s08;
extern CONST(boolean, CAL_CONST) k_CyberSecNexteerCheckEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_F00FHandsOnThres_HwNm_f32;
extern CONST(boolean, CAL_CONST) k_FreezeMECFD1BEnable_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcHandsOnTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcPosTrajHoldTime_mS_u16;
extern CONST(float32, CAL_CONST) k_NxtrSrvcPosTrajThres_HwDeg_f32;
extern CONST(boolean, CAL_CONST) k_VehSpdZeroCheckEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehSpdZeroThreshold_Kph_f32;

/********************************** CMS_PSA **********************************/
extern CONST(uint8, CAL_CONST) k_CalRelNum_Cnt_u8[12];
extern CONST(float32, CAL_CONST) k_SrvcHwTrqLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SrvcVehSpdLimit_Kph_f32;

/********************************* ComplErr **********************************/
extern CONST(uint16, CAL_CONST) t_CompErrMtrPosNonLinComplDepTbl_HwDegpMtrNm_u8p8[6];
extern CONST(uint16, CAL_CONST) t_ComplErrMtrPosNonLinComplIndTbl_MtrNm_u5p11[6];

/********************************* CtrlTemp **********************************/
extern CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32;
extern CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32;

/******************************* CustBattDiag ********************************/
extern CONST(uint16, CAL_CONST) k_CBDiagc_OverVltgDetd_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CBDiagc_OverVltgDetd_Volt_u10p6;
extern CONST(uint16, CAL_CONST) k_CBDiagc_OverVltgNotDetd_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CBDiagc_OverVltgNotDetd_Volt_u10p6;
extern CONST(uint16, CAL_CONST) k_CBDiagc_UnderVltgDetd_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CBDiagc_UnderVltgNotDetd_mS_u16p0;
extern CONST(float32, CAL_CONST) k_CustBattDiaghispd_kph_f32;
extern CONST(float32, CAL_CONST) k_CustBattDiagLOIspd_kph_f32;
extern CONST(float32, CAL_CONST) k_CustBattDiaglospd_kph_f32;
extern CONST(uint16, CAL_CONST) k_LOIDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LOINotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVCDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVCDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVCNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVCNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVHSDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVHSDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVHSNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVHSNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVLSDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVLSDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVLSNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVLSNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVNDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVNDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVNNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVNNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVSMDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVSMDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LVSMNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LVSMNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_UVDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_UVNotDetect_Volts_u10p6;

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
extern CONST(float32, CAL_CONST) k_CmnSysKinRatio_MtrDegpHwDeg_f32;
extern CONST(float32, CAL_CONST) k_CmnTbarStiff_NmpDeg_f32;
extern CONST(uint16, CAL_CONST) t_DmpFiltKpWIRBlndY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t_RIAstWIRBlndTblY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t_WIRBlndTblX_MtrNm_u8p8[5];

/*********************************** DemIf ***********************************/
extern CONST(uint16, CAL_CONST) k_AasActvTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_AasActvVBattMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_AasActvVBattMin_Volt_f32;
extern CONST(uint16, CAL_CONST) k_BsiActvTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_BsiActvVBattMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_BsiActvVBattMin_Volt_f32;
extern CONST(uint16, CAL_CONST) k_CavActvTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_CavActvVBattMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_CavActvVBattMin_Volt_f32;
extern CONST(uint16, CAL_CONST) k_CmmActvTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_CmmActvVBattMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_CmmActvVBattMin_Volt_f32;
extern CONST(uint16, CAL_CONST) k_EscActvTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_EscActvVBattMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_EscActvVBattMin_Volt_f32;

/********************************** DiagMgr **********************************/
extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCLatch_Str, CAL_CONST) t_LatchFaults_Cnt_str[8];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];

/********************************** DiagSvc **********************************/
extern CONST(uint8, CAL_CONST) k_CalibrationEdition_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_CalibrationVersion_Cnt_u08;
extern CONST(float32, CAL_CONST) k_DiagHandwheelAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwTrqResetThresh_Kph_f32;
extern CONST(uint8, CAL_CONST) k_NBRPARAMFLT_Cnt_u08;
extern CONST(boolean, CAL_CONST) k_NonDefaultCalset_Cnt_lgc;
extern CONST(uint8, CAL_CONST) k_SoftwareEdition_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_SoftwareVersion_Cnt_u08;
extern CONST(uint16, CAL_CONST) k_SupplierCode_Cnt_u16;
extern CONST(TuningSelectTableType_Str, CAL_CONST) k_TuningSelectTable_Cnt_str[128];
extern CONST(uint16, CAL_CONST) k_VariantCodingBVPO_Cnt_u16;
extern CONST(uint8, CAL_CONST) k_VariantCodingCAVPO_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_VariantCodingCPKPO_Cnt_u08;
extern CONST(uint16, CAL_CONST) k_VariantCodingCPO_Cnt_u16;
extern CONST(uint8, CAL_CONST) k_VariantCodingIDTLC_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_VariantCodingLXAPO_Cnt_u08;
extern CONST(uint32, CAL_CONST) k_VariantCodingMPO_Cnt_u32;
extern CONST(uint8, CAL_CONST) k_VariantCodingMultiModePO_Cnt_u08;
extern CONST(uint32, CAL_CONST) k_VariantCodingPPO_Cnt_u32;
extern CONST(uint8, CAL_CONST) k_VariantCodingSTTPO_Cnt_u08;
extern CONST(float32, CAL_CONST) k_VehSpdResetThresh_Kph_f32;
extern CONST(uint8, CAL_CONST) t_F080Reseved_Cnt_u08[4];

/******** DiagSvc, FaultLog, SrlComDriver, SrlComInput, SrlComOutput *********/
extern CONST(boolean, CAL_CONST) k_JDD2010Selected_Cnt_lgc;

/********************************** DigMSB ***********************************/
extern CONST(uint8, CAL_CONST) k_Die1RPMMode_Cnt_u08;
extern CONST(float32, CAL_CONST) k_Die1vsDie2TrnsCntrThresh_Deg_f32;
extern CONST(uint16, CAL_CONST) k_Die2Offset_Rev_u3p13;
extern CONST(uint8, CAL_CONST) k_Die2RPMMode_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_DigMSBErrorRegGenMask_Cnt_u08;
extern CONST(DiagSettings_Str, CAL_CONST) k_DigMSBParity_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DigMSBTCRunTimeParity_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_ErrorRegTCAcc_Cnt_str;
extern CONST(uint8, CAL_CONST) k_ErrorRegTCMask_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_ErrorRegVehMask_Cnt_u08;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPos1vsMtrPos2Diag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MtrPos1vsMtrPos2Thresh_Rev_u3p13;
extern CONST(float32, CAL_CONST) k_TurnsCntrOffset_Rev_f32;

/********************************** ElePwr ***********************************/
extern CONST(float32, CAL_CONST) k_CntlrInResist_Ohm_f32;
extern CONST(float32, CAL_CONST) k_PstcPowerLoss_Watt_f32;

/******************************* ePWM, ePWM_Up *******************************/
extern CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PwmRelay_Cnt_u16;

/***************** ePWM, Nhet1CfgAndUse, Nhet1CfgAndUse_35D ******************/
extern CONST(uint32, CAL_CONST) k_SENTSyncTrgMin_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_SPI1mOff_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_SPI50UOff_Cnt_u16;

/****************************** HighFreqAssist *******************************/
extern CONST(uint16, CAL_CONST) t2_GainY1_MtrNmpHwNm_u3p13[12][13];
extern CONST(uint16, CAL_CONST) t2_TorqX1_HwNm_u5p11[12][13];
extern CONST(uint16, CAL_CONST) t2_WIRBlendX_MtrNm_u4p12[12][5];
extern CONST(uint16, CAL_CONST) t2_WIRBlendY_Uls_u1p15[12][5];

/******************************** HiLoadStall ********************************/
extern CONST(uint16, CAL_CONST) k_EOTThrmPrtLPFKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_EOTThrmSlwLmtStp_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_EOTThrmDpntTbl_MtrNm_u8p8[4];
extern CONST(uint16, CAL_CONST) t_EOTThrmIndptTbl_MtrNm_u8p8[4];

/************************ HiLoadStall, ThrmDutyCycle *************************/
extern CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32;

/********************************* HOWDetect *********************************/
extern CONST(float32, CAL_CONST) k_HOWDecaySF_Uls_f32;
extern CONST(float32, CAL_CONST) k_HOWEstLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HOWSlewRate_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_HOWStateLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqFinalLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqHPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqInitLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_HOWHighFreqGainY_Uls_u9p7[3];
extern CONST(uint16, CAL_CONST) t_HOWStateThresholds_Uls_u8p8[7];
extern CONST(uint16, CAL_CONST) t_HOWVehSpd_Kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t2_HOWHFRateX_HwNm_u8p8[3][6];
extern CONST(sint16, CAL_CONST) t2_HOWHFRateY_UlspS_s7p8[3][6];
extern CONST(uint16, CAL_CONST) t2_HOWLFRateX_HwNm_u8p8[3][5];
extern CONST(sint16, CAL_CONST) t2_HOWLFRateY_UlspS_s7p8[3][5];

/***************************** HwTqArbn_2TqADAS ******************************/
extern CONST(float32, CAL_CONST) k_HwTqArb_HwTqCh1MaxOfstTrm_HwNm_f32;

/**************************** HwTqCorrln_2TqADAS *****************************/
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFActvnThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFOpLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1ImdtCorrlnChkFailThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1ImdtCorrlnChkPassThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSOpSetFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1TqSumLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1TraSumOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1TraSumOpSetFltThd_HwNm_f32;
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch1TraLPFDepAxis_Hz_u7p9[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch1TraLPFIndAxis_HwNm_u6p10[17];

/**************************** HystComp, PsaAgArbn ****************************/
extern CONST(float32, CAL_CONST) k_CmnSysTrqRatio_HwNmpMtrNm_f32;

/**************************** IoHwAbstractionUsr *****************************/
extern CONST(float32, CAL_CONST) k_TempSensorOffset_Volt_f32;
extern CONST(float32, CAL_CONST) k_TempSensorScale_Uls_f32;
extern CONST(float32, CAL_CONST) k_VbattScale_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VrefDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_VrefMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_VrefMin_Volt_f32;
extern CONST(float32, CAL_CONST) k_VrefScale_Uls_f32;
extern CONST(float32, CAL_CONST) k_VswitchScale_Uls_f32;

/********************************** LmtCod ***********************************/
extern CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32;
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2];

/********************************** LoaMgr ***********************************/
extern CONST(float32, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_LoaMgr_FadeOutStRate_UlspS_f32;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig0TloaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig1NoTloaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig1TloaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig2TloaDiResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig2TloaEnaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig4Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_HwTqMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_HwTqMtgtnSca_Uls_f32;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSig1Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_IvtrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_IvtrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_IvtrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig1NoSmaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig3Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotAgMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotAgMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_MotAgMtgtnScaZeroEn_Cnt_lgc;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgSmaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig0Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig1Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotCurrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotCurrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_MotCurrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_LoaMgr_RedcdStRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_RedcdStSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_SnsrlsMotAgAvail_Cnt_lgc;

/********************************** LrnEOT ***********************************/
extern CONST(float32, CAL_CONST) k_AuthorityStartLrn_Uls_f32;
extern CONST(uint16, CAL_CONST) k_EOTLrnTimer_mS_u16;
extern CONST(float32, CAL_CONST) k_HwTrqEOTLrn_HwNm_f32;
extern CONST(float32, CAL_CONST) k_MaxRackTrvl_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinRackTrvl_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinResetAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrVelEOTLrn_MtrRadpS_f32;

/******************************** MtrCtrl_CM *********************************/
extern CONST(float32, CAL_CONST) k_DualEcuSignalSclFacSlew_UlspS_f32;

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_AMAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AMAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_AmbPwrMult_WtspAmpSq_f32;
extern CONST(float32, CAL_CONST) k_AmbTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMDampScl_NmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_AMDefaultTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltPoleA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AssistMechSlew_DegCpS_f32;
extern CONST(float32, CAL_CONST) k_CuAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_CuAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_EngTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_SiAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_SiAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_SiLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_SiLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_SiLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrimTempAM_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempCu_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempMag_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempSi_DegC_f32;
extern CONST(Boolean, CAL_CONST) k_WtAvgTempDFt_Cnt_lgc;

/******************* MtrVel, AbsHwPos_TcI2cVd, MtrVel_Digi *******************/
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;

/**************************** MtrVel, MtrVel_Digi ****************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];

/******************** Nhet1CfgAndUse, Nhet1CfgAndUse_35D *********************/
extern CONST(uint8, CAL_CONST) k_TSNstep_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TSPstep_Cnt_u08;

/************************* NonComponent, MtrCtrl_CM **************************/
extern CONST(float32, CAL_CONST) k_CLOAFdbackSignalSclFacSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_deadtimeVScale_Uls_f32;
extern CONST(uint16, CAL_CONST) k_EstPkCurr2msLPFKn_Uls_u16;
extern CONST(uint16, CAL_CONST) k_EstPkCurrSlowLoopLPFKn_Uls_u16;
extern CONST(float32, CAL_CONST) k_Harmonic12thElec_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic18thElec_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic6thElec_Uls_f32;
extern CONST(float32, CAL_CONST) k_IdBoostGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_IdBoostVRThreshScl_Uls_f32;
extern CONST(uint16, CAL_CONST) k_IdqRefIminNIter_Cnt_u16;
extern CONST(float32, CAL_CONST) k_IdqRefIminTol_Amp_f32;
extern CONST(uint16, CAL_CONST) k_IdqRefLocateRefNIter_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_IdqRefTrqNIter_Cnt_u16;
extern CONST(float32, CAL_CONST) k_IdqRefTrqTol_Rad_f32;
extern CONST(float32, CAL_CONST) k_ILOAFdbackSignalSclFacSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32;
extern CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32;
extern CONST(float32, CAL_CONST) k_MaxKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MinKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MinLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32;
extern CONST(boolean, CAL_CONST) k_MtrCtrlCurrLoopSecOrTranFcEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrCtrlFeedbackControlDisable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrCtrlVirualResDax_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MtrCtrlVirualResQax_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrDaxMaxValScl_Per_f32;
extern CONST(boolean, CAL_CONST) k_MtrCurrQaxRefModifDsb_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrCurrQaxRefModifRplEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrDampingRatioDax_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrDampingRatioQax_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelayRpl_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrVelFiltFFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVelFiltPIKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegLoLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDervFiltCoeffTimeCons_Sec_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltQaxFiltFFEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxFiltFFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegLoLim_Volt_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltVecuFiltEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltVecuFiltKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_NomLd_Henry_f32;
extern CONST(float32, CAL_CONST) k_NomLq_Henry_f32;
extern CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32;
extern CONST(float32, CAL_CONST) k_NomTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_NoofPoles_Uls_f32;
extern CONST(float32, CAL_CONST) k_PIGainVspdCutoff_kph_f32;
extern CONST(float32, CAL_CONST) k_PiSamplingTs_Sec_f32;
extern CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32;
extern CONST(boolean, CAL_CONST) k_VoltModeDynCompEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VoltSatDaxPolyCoeff_Uls_f32;
extern CONST(float32, CAL_CONST) k_VoltSatQaxPolyCoeff_Uls_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_CurrParamCompDaxRef_Amp_u9p7[6];
extern CONST(uint16, CAL_CONST) t_CurrParamCompQaxRef_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCharSclY_Uls_u1p15[11];
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCmdX_MtrNm_u4p12[11];
extern CONST(uint16, CAL_CONST) t_KeSatTblX_Amp_u9p7[16];
extern CONST(uint16, CAL_CONST) t_KeSatTblY_Uls_u2p14[16];
extern CONST(uint16, CAL_CONST) t_MtrBandwidthDaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrBandwidthQaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrCurrDaxRpl_Amp_u9p7[10];
extern CONST(uint16, CAL_CONST) t_MtrCurrQaxRpl_Amp_u9p7[12];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqDaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqQaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrTrqCmdPIY_MtrNm_u5p11[8];
extern CONST(uint16, CAL_CONST) t_MtrVelCtrlGainX_MtrRadpSec_u12p4[4];
extern CONST(uint16, CAL_CONST) t_MtrVelX_MtrRadpS_T_u16[20];
extern CONST(uint16, CAL_CONST) t_Q13VltgSchedXTbl_MtrRadpS_u12p4[10];
extern CONST(uint16, CAL_CONST) t_Q13VltgSchedYTbl_Volt_u5p11[10];
extern CONST(uint16, CAL_CONST) t_Q24VltgSchedXTbl_MtrRadpS_u12p4[10];
extern CONST(uint16, CAL_CONST) t_Q24VltgSchedYTbl_Volt_u5p11[10];
extern CONST(float32, CAL_CONST) t_RefDeltaPoints_Rad_f32[8];
extern CONST(uint16, CAL_CONST) t2_CurrParamLdSatSclFac_Uls_u2p14[6][7];
extern CONST(uint16, CAL_CONST) t2_CurrParamLqSatSclFac_Uls_u2p14[6][7];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIMagRP_Uls_u6p10[20][8];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIPhRP_Rev_u0p16[20][8];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl12X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl12Y_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl18X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl18Y_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl6X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl6Y_MtrNm_s2p13[10][12];

/********************* NonComponent, MtrCtrl_CM, SVDiag **********************/
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];

/******************************** OvrVoltMon *********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_CPUSupplyOV_Cnt_Str;

/********************************* PsaAgArbn *********************************/
extern CONST(uint16, CAL_CONST) t_PsaAgAn_AbsltHwAuthyY_Uls_u1p15[4];
extern CONST(uint16, CAL_CONST) t_PsaAgAn_AbsltHwPosnPrecX_HwDeg_u16p0[4];

/******************************* PwrLmtFuncCr ********************************/
extern CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32;
extern CONST(float32, CAL_CONST) k_KeStdTemp_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_LowVltAstRecTh_Volt_f32;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PwrLmtMtrVelLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_PwrLmtVecuAdjSlew_VoltspL_f32;
extern CONST(float32, CAL_CONST) k_PwrLmtVecuAltFltAdj_Volt_f32;
extern CONST(float32, CAL_CONST) k_SpdAdjSlewDec_MtrRadpS_f32;
extern CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SpdAdjSlewInc_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) t_DLVTblX_Volt_u5p11[10];
extern CONST(uint16, CAL_CONST) t_DLVTblY_MtrRadpS_u11p5[10];
extern CONST(sint16, CAL_CONST) t_MtrEnvTblX_MtrRadpS_s11p4[14];
extern CONST(uint16, CAL_CONST) t_MtrEnvTblY_MtrNm_u5p11[14];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblX_MtrRadpS_u11p5[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblY_MtrNm_u4p12[6];

/********************************** Return ***********************************/
extern CONST(float32, CAL_CONST) k_RtnLimit_MtrNm_f32;

/********************************* SgnlCond **********************************/
extern CONST(float32, CAL_CONST) k_VehAccelSlewRate_KphpSecSq_f32;
extern CONST(float32, CAL_CONST) k_VehSpdSlewRate_KphpSec_f32;

/******************************* SrlComDriver ********************************/
extern CONST(uint16, CAL_CONST) k_BusOffTimeout_mS_u16;

/******************************** SrlComInput ********************************/
extern CONST(uint16, CAL_CONST) k_Aas2EBMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_AccelLatInvalidityThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AccelLatInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AccelLatValidityThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AccelLatValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ANGLEVOLANTSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ANGLEVOLANTSigValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_BattOvHi_Volt_f32;
extern CONST(float32, CAL_CONST) k_BattOvLo_Volt_f32;
extern CONST(float32, CAL_CONST) k_BattUvHi_Volt_f32;
extern CONST(float32, CAL_CONST) k_BattUvLo_Volt_f32;
extern CONST(uint16, CAL_CONST) k_Bsi3F2MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Bsi412MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Bsi432MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Bsi552MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Bsi572MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Cav305MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CDS34DMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CDS50DMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CMM388MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_ColumnAngleSetpointInvalidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_ColumnAngleSetpointLimit_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_ColumnAngleSetpointValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ComputerRazGCTSigInvalidTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_ComputerRazGCTSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ConfigVhlSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ConfigVhlSigValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_CONSANGLECPKMax_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_CONSANGLECPKMin_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_CONSANGLECPKSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CONSANGLECPKSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CptTemporelSigInvalidTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CptTemporelSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DateValidSigInvalidTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_DateValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_DefaultVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_DiagMuxOnAbsentTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_DmdDelestDaValidThresh_Uls_u16;
extern CONST(uint16, CAL_CONST) k_DmdDelestVldTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_DMDFCTCPKSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DMDFCTCPKSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DMDFCTCPKValidCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DMDRelaxeConsistentThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DMDRELAXECPKSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DMDRELAXECPKSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_Emn208MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Emn348MsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Esc38DMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Esc3CDMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_Esc5CDMsgTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_EtatMTSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_EtatMTSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_IgnOnTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_ISDAT4V2BSI552MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDAT4V2BSI552MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDAT4V2BSI552MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATABR50DMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATABR50DMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATABR50DMsgTimeValidCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI3F2MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI3F2MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI3F2MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI412MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI412MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI412MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI432MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI432MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI432MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI572MsgCntrThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI572MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI572MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDATBSI572MsgTimeValidThresh_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_ISDATDIRASentDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ISDATDIRASentTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2CMMMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2CMMMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2CMMMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2FRE3CDMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2FRE3CDMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYN2FRE3CDMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASChkSumInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASChkSumValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASMsgCountInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASMsgCountValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNAASMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRChkSumInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRChkSumValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRMsgCountInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRMsgCountValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNABRMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCDS34DMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCDS34DMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCDS34DMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM208MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM208MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM208MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM388MsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM388MsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNCMM388MsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLChkSumInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLChkSumValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLMsgCountInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLMsgCountValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ISDYNVOLMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_LKAStateInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_LKAStateValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_LKATrqFactReqInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_LKATrqFactReqValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MultimodeInvalidCountThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MultimodeValidCountThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OffsetDataConsistentThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OffsetDataInconsistentThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OffsetInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OffsetValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PowerCutVehSpdHighThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_PowerCutVehSpdLowThresh_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PowerCutVehSpdLowTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_PrecisionOffsetInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PrecisionOffsetValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgChkSumInvalid_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgChkSumValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgCountInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgLenInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgLenValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDMsgTimeValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PROTOHS1DYNUCF5CDOffsetSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ROTOHS1DYNUCF5CDMsgCountValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ROTOHS1DYNUCF5CDOffsetSigValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_VehSpdInit_Kph_f32;
extern CONST(uint16, CAL_CONST) k_VITESSEROTVOLANTSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VITESSEROTVOLANTSigValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VitesseVehicleBVRampValidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VitesseVehicleBVSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VitesseVehicleBVSigValidThresh_Cnt_u16;
extern CONST(float32, CAL_CONST) k_VitesseVehicleBVSpeedPassThresh_kph_f32;
extern CONST(uint16, CAL_CONST) k_VitesseVehiculeRouesSigInvalidThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VitesseVehiculeRouesSigValidThresh_Cnt_u16;

/******************************* SrlComOutput ********************************/
extern CONST(float32, CAL_CONST) k_AUTORARRETMOTDAHwPosThresh_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_AUTORARRETMOTDAHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_AUTORARRETMOTDAHwVelThresh_HwRadpS_f32;
extern CONST(uint16, CAL_CONST) k_AUTORARRETMOTDAValidThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_DDEREDEMDAHwPosThresh_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_DDEREDEMDAHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_DDEREDEMDAHwVelThresh_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_DDEREDEMDAVehSpdThresh_Kph_f32;
extern CONST(uint16, CAL_CONST) k_ETATSECUANGLECOLSigTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_STTdMinHwAuthority_Uls_f32;

/******************************* StabilityComp *******************************/
extern CONST(boolean, CAL_CONST) k_StCmpCrosChkEnbl_Uls_lgc;

/*********************************** StaMd ***********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str;

/********************************** SVDiag ***********************************/
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_LowResPhsReas_Cnt_str;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMaxTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMinTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LRPRCommOffsetMargin_Uls_f32;
extern CONST(float32, CAL_CONST) k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str;
extern CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32;
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;

/********************************* SVDrvr_CM *********************************/
extern CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PWMBaseFrequency_Hz_u16;

/******************************* ThrmDutyCycle *******************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32;
extern CONST(boolean, CAL_CONST) k_CtrlTempSlc_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_DefaultIgnOffTime_Sec_f32;
extern CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0;
extern CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32;
extern CONST(boolean, CAL_CONST) k_IgnOffCntrEnb_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_IgnOffMsgWaitTime_Sec_f32;
extern CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewDown_MtrNm_u9p7;
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewUp_MtrNm_u9p7;
extern CONST(sint16, CAL_CONST) t_AbsCtrlTmpTblX_DegC_s15p0[4];
extern CONST(uint16, CAL_CONST) t_AbsCtrlTmpTblY_MtrNm_u9p7[4];
extern CONST(sint16, CAL_CONST) t_AbsCuTmpTblX_DegC_s15p0[4];
extern CONST(uint16, CAL_CONST) t_AbsCuTmpTblY_MtrNm_u9p7[4];
extern CONST(uint16, CAL_CONST) t_LastTblValNS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_LastTblValS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_Mult1NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult1STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6STblY_Uls_u3p13[5];
extern CONST(sint16, CAL_CONST) t_MultTblX_DegC_s15p0[5];
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblX_Uls_u16p0[8];
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblY_MtrNm_u9p7[8];

/********************************* TmprlMon **********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_TmprlMonPstepNstep_Cnt_str;

/******************************* TMS570_uDiag ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16;

/********************************** TqRsDg ***********************************/
extern CONST(float32, CAL_CONST) k_CurrDiagLambdaMinMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagMtrEnvTblMax_MtrNm_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagPrim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_CurrDiagPrimErrorThresh_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagPrimLPFKn_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagSec_Cnt_Str;
extern CONST(float32, CAL_CONST) k_CurrDiagSecErrorThresh_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagSecLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagSecTrqLmtThresh_Uls_f32;

/******************************** TranlDampg *********************************/
extern CONST(float32, CAL_CONST) k_TrnDmp_BkptTwo_mS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_DampCoeff_MtrNmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_DmpLimit_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_RampEnd_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_TmrBkptOne_mS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_VelThr_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) t_TrnDmp_VehSpdBlndX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_TrnDmp_VehSpdBlndY_Uls_u9p7[4];

/********************************** TrqLOA ***********************************/
extern CONST(float32, CAL_CONST) k_Cmn_VehWhlBas_mm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_AbsAssistThreshold_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_AbsVelThreshold_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterFalling_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterRising_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_FallingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LatAccConversionFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LimOutput_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LPF_Hz_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MaxScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MinScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_NomDrvTrq_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_RisingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_SteerRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_UndersteerGrad_RadpG_f32;
extern CONST(boolean, CAL_CONST) k_TrqLOA_UseVehWhlBasCal_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_TrqLOA_DiffGainX_G_u2p14[4];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_X_Kph_u10p6[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_Y_Uls_u1p15[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_LatAccGain_Y_MtrNmpG_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_TempTrqCmdSatYTbl_MtrNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_X_Kph_u10p6[8];
extern CONST(uint16, CAL_CONST) t2_TrqLOA_DiffGainY_Uls_u1p15[8][4];

/********************************** VehDyn ***********************************/
extern CONST(float32, CAL_CONST) k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;
extern CONST(float32, CAL_CONST) k_VehDyn_NVMTestValHwPos_HwDeg_f32;
extern CONST(boolean, CAL_CONST) k_VehDyn_NVMTestValHwPosValid_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehDyn_SerlCommSyncnHwAgLpFil_Hz_f32;
extern CONST(boolean, CAL_CONST) k_VehDyn_SerlCommSyncnKeepRecOffs_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehDyn_SerlCommSyncnMaxMotHwTqThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_VehDyn_SerlCommSyncnMaxMotVelThd_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_VehDyn_SerlCommSyncnMaxOffsRng_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_VehDyn_SerlCommSyncnMaxPinionTqThd_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_VehDyn_SerlCommSyncnTmrThd_mS_u16;
extern CONST(boolean, CAL_CONST) k_VehDyn_SerlCommSyncnUseSyncnMethod_Cnt_lgc;

/********************************* VehPwrMd **********************************/
extern CONST(uint16, CAL_CONST) k_ATermTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CTermIgnOffTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CTermIgnOnTimeout_mS_u16;
extern CONST(uint16, CAL_CONST) k_CTermVehSpdInvalidTimeout_mS_u16;
extern CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_STTdEntryThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_STTdExitThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_STTdRampDownRate_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_STTdRampUpRate_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_VehSpdThresh_Kph_f32;

/********************************* VehSpdLmt *********************************/
extern CONST(uint16, CAL_CONST) k_PosMaxOfstOne_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) k_PosMaxOfstTwo_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) t_MaxAsstTblX_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_MaxAsstTblY_MtrNm_u5p11[5];

/******************************** ActivePull *********************************/
#define k_EnableHwAuthMin_Uls_f32	TunSet_Ptr_Str->k_EnableHwAuthMin_Uls_f32
#define k_EnableHwPosMax_HwDeg_f32	TunSet_Ptr_Str->k_EnableHwPosMax_HwDeg_f32
#define k_EnableHwTrqMax_HwNm_f32	TunSet_Ptr_Str->k_EnableHwTrqMax_HwNm_f32
#define k_EnableHwVelMax_DegpS_f32	TunSet_Ptr_Str->k_EnableHwVelMax_DegpS_f32
#define k_EnableLatAccMax_MpSecSq_f32	TunSet_Ptr_Str->k_EnableLatAccMax_MpSecSq_f32
#define k_EnableTime_mS_u32	TunSet_Ptr_Str->k_EnableTime_mS_u32
#define k_EnableVehSpdMax_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMax_Kph_f32
#define k_EnableVehSpdMin_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMin_Kph_f32
#define k_EnableVehSpdRateMax_KphpS_f32	TunSet_Ptr_Str->k_EnableVehSpdRateMax_KphpS_f32
#define k_EnableYawRateMax_DegpS_f32	TunSet_Ptr_Str->k_EnableYawRateMax_DegpS_f32
#define k_FiltDeadband_HwNm_f32	TunSet_Ptr_Str->k_FiltDeadband_HwNm_f32
#define k_HwNmToMtrNm_MtrNmpHwNm_f32	TunSet_Ptr_Str->k_HwNmToMtrNm_MtrNmpHwNm_f32
#define k_HwTrqFilt_Hz_f32	TunSet_Ptr_Str->k_HwTrqFilt_Hz_f32
#define k_LTFilt_Hz_f32	TunSet_Ptr_Str->k_LTFilt_Hz_f32
#define k_LTIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_LTIntInputLimit_HwNm_f32
#define k_LTLearnTime_Min_f32	TunSet_Ptr_Str->k_LTLearnTime_Min_f32
#define k_LTLimit_HwNm_f32	TunSet_Ptr_Str->k_LTLimit_HwNm_f32
#define k_OutputMaxRate_HwNmpS_f32	TunSet_Ptr_Str->k_OutputMaxRate_HwNmpS_f32
#define k_PullCmp_LTIntgtrStCorrnGain_Uls_f32	TunSet_Ptr_Str->k_PullCmp_LTIntgtrStCorrnGain_Uls_f32
#define k_PullCmp_STIntgtrStCorrnGain_Uls_f32	TunSet_Ptr_Str->k_PullCmp_STIntgtrStCorrnGain_Uls_f32
#define k_STFilt_Hz_f32	TunSet_Ptr_Str->k_STFilt_Hz_f32
#define k_STIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_STIntInputLimit_HwNm_f32
#define k_STLearnTimeDec_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeDec_Sec_f32
#define k_STLearnTimeInc_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeInc_Sec_f32
#define k_STLimit_HwNm_f32	TunSet_Ptr_Str->k_STLimit_HwNm_f32
#define k_STOppSignTime_mS_u32	TunSet_Ptr_Str->k_STOppSignTime_mS_u32
#define k_STRampTime_Sec_f32	TunSet_Ptr_Str->k_STRampTime_Sec_f32
#define k_STResetHwPos_HwDeg_f32	TunSet_Ptr_Str->k_STResetHwPos_HwDeg_f32
#define k_STResetHwTrq_HwNm_f32	TunSet_Ptr_Str->k_STResetHwTrq_HwNm_f32
#define k_STResetLatAcc_MpSecSq_f32	TunSet_Ptr_Str->k_STResetLatAcc_MpSecSq_f32
#define k_STResetYawRate_DegpS_f32	TunSet_Ptr_Str->k_STResetYawRate_DegpS_f32
#define k_TotalLimit_HwNm_f32	TunSet_Ptr_Str->k_TotalLimit_HwNm_f32
#define k_YawRateFilt_Hz_f32	TunSet_Ptr_Str->k_YawRateFilt_Hz_f32
#define t_VehSpdScaleTblX_Kph_u9p7	TunSet_Ptr_Str->t_VehSpdScaleTblX_Kph_u9p7
#define t_VehSpdScaleTblY_Uls_u2p14	TunSet_Ptr_Str->t_VehSpdScaleTblY_Uls_u2p14

/********************************** Assist ***********************************/
#define t_AsstThermSclX_Cnt_u16p0	TunSet_Ptr_Str->t_AsstThermSclX_Cnt_u16p0
#define t_AsstThermSclY_Uls_u2p14	TunSet_Ptr_Str->t_AsstThermSclY_Uls_u2p14

/****************************** AssistFirewall *******************************/
#define k_AsstFWFiltKn_Hz_f32	TunSet_Ptr_Str->k_AsstFWFiltKn_Hz_f32
#define k_AsstFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_AsstFWFWActiveLPF_Hz_f32
#define k_AsstFWInpLimitBaseAsst_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitBaseAsst_MtrNm_f32
#define k_AsstFWInpLimitHFA_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitHFA_MtrNm_f32
#define k_AsstFWInpLimitHysComp_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitHysComp_MtrNm_f32
#define k_AsstFWNstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWNstep_Cnt_u16
#define k_AsstFWPstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWPstep_Cnt_u16
#define k_RestoreThresh_MtrNm_f32	TunSet_Ptr_Str->k_RestoreThresh_MtrNm_f32
#define t_AsstFWPstepNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_AsstFWPstepNstepThresh_Cnt_u16

/********************************* AstLmt_CM *********************************/
#define k_SumLim_CmdSftyLimr_MtrNm_f32	TunSet_Ptr_Str->k_SumLim_CmdSftyLimr_MtrNm_f32
#define k_SumLim_LrnPnCtrDebounce_Cnt_str	TunSet_Ptr_Str->k_SumLim_LrnPnCtrDebounce_Cnt_str

/********************************** Damping **********************************/
#define t_TempScaleX_DegC_s8p7	TunSet_Ptr_Str->t_TempScaleX_DegC_s8p7
#define t_TempScaleY_Uls_u4p12	TunSet_Ptr_Str->t_TempScaleY_Uls_u4p12

/****************************** DampingFirewall ******************************/
#define k_DampFWErrThresh_MtrNm_f32	TunSet_Ptr_Str->k_DampFWErrThresh_MtrNm_f32
#define k_DampFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_DampFWFWActiveLPF_Hz_f32
#define k_DampFWInCmpNStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpNStep_Cnt_u16
#define k_DampFWInCmpPStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpPStep_Cnt_u16
#define k_DampFWInpLimitDamp_MtrNm_f32	TunSet_Ptr_Str->k_DampFWInpLimitDamp_MtrNm_f32
#define k_DampFWNstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWNstep_Cnt_u16
#define k_DampFWPstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWPstep_Cnt_u16
#define k_DampFWVBICLPF_Hz_f32	TunSet_Ptr_Str->k_DampFWVBICLPF_Hz_f32
#define t_DampFWAddDampAFWX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DampFWAddDampAFWX_MtrRadpS_u11p5
#define t_DampFWAddDampAFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampAFWY_MtrNm_u5p11
#define t_DampFWAddDampDFWX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DampFWAddDampDFWX_MtrRadpS_u11p5
#define t_DampFWAddDampDFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampDFWY_MtrNm_u5p11
#define t_DampFWDampInrtCmpPNThesh_Cnt_u16	TunSet_Ptr_Str->t_DampFWDampInrtCmpPNThesh_Cnt_u16
#define t_DampFWPNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_DampFWPNstepThresh_Cnt_u16

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#define k_DmpDecelGain_Uls_f32	TunSet_Ptr_Str->k_DmpDecelGain_Uls_f32
#define k_DmpDecelGainFSlew_UlspS_f32	TunSet_Ptr_Str->k_DmpDecelGainFSlew_UlspS_f32
#define k_DmpGainOffThresh_KphpS_f32	TunSet_Ptr_Str->k_DmpGainOffThresh_KphpS_f32
#define k_DmpGainOnThresh_KphpS_f32	TunSet_Ptr_Str->k_DmpGainOnThresh_KphpS_f32
#define t_DmpDecelGainSlewX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DmpDecelGainSlewX_MtrRadpS_u11p5
#define t_DmpDecelGainSlewY_UlspS_u13p3	TunSet_Ptr_Str->t_DmpDecelGainSlewY_UlspS_u13p3

/****************************** EOTActuatorMng *******************************/
#define k_EOTDefltPosition_HwDeg_u12p4	TunSet_Ptr_Str->k_EOTDefltPosition_HwDeg_u12p4
#define k_EOTDeltaTrqThrsh_HwNm_u9p7	TunSet_Ptr_Str->k_EOTDeltaTrqThrsh_HwNm_u9p7
#define k_EOTEnterLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTEnterLPFKn_Cnt_u16
#define k_EOTExitLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTExitLPFKn_Cnt_u16
#define k_EOTImpSpdEn_Kph_u9p7	TunSet_Ptr_Str->k_EOTImpSpdEn_Kph_u9p7
#define k_EOTOriginalImpactandSoftEnd_Cnt_lgc	TunSet_Ptr_Str->k_EOTOriginalImpactandSoftEnd_Cnt_lgc
#define k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32	TunSet_Ptr_Str->k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32
#define k_EOTStateHwTrqLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTStateHwTrqLPFKn_Cnt_u16
#define k_MaxRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MaxRackTrvl_HwDeg_u12p4
#define k_PosRampStep_HwDeg_u12p4	TunSet_Ptr_Str->k_PosRampStep_HwDeg_u12p4
#define k_SoftStopEOTEnable_Cnt_lgc	TunSet_Ptr_Str->k_SoftStopEOTEnable_Cnt_lgc
#define k_SpdIptScale_MtrNmpRadpS_u4p12	TunSet_Ptr_Str->k_SpdIptScale_MtrNmpRadpS_u4p12
#define t_EOTDmpVspd_Kph_u9p7	TunSet_Ptr_Str->t_EOTDmpVspd_Kph_u9p7
#define t_EOTEnterGainVspd_Kph_u9p7	TunSet_Ptr_Str->t_EOTEnterGainVspd_Kph_u9p7
#define t_SpdIptTblXTbl_HwDeg_u12p4	TunSet_Ptr_Str->t_SpdIptTblXTbl_HwDeg_u12p4
#define t_SpdIptTblYTbl_MtrRadpS_u12p4	TunSet_Ptr_Str->t_SpdIptTblYTbl_MtrRadpS_u12p4
#define t_TrqTableX_HwNm_u8p8	TunSet_Ptr_Str->t_TrqTableX_HwNm_u8p8
#define t2_EOTEnterGainX_HwDeg_u12p4	TunSet_Ptr_Str->t2_EOTEnterGainX_HwDeg_u12p4
#define t2_EOTEnterGainY_Uls_u1p15	TunSet_Ptr_Str->t2_EOTEnterGainY_Uls_u1p15
#define t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16	TunSet_Ptr_Str->t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16
#define t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16	TunSet_Ptr_Str->t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16

/************************** EOTActuatorMng, EtDmpFw **************************/
#define k_EOTDynConf_Uls_u8p8	TunSet_Ptr_Str->k_EOTDynConf_Uls_u8p8
#define k_MinRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MinRackTrvl_HwDeg_u12p4
#define t2_EOTPosDepDmpTblX_HwDeg_u12p4	TunSet_Ptr_Str->t2_EOTPosDepDmpTblX_HwDeg_u12p4

/********************************** EtDmpFw **********************************/
#define k_EOTDmpFWInactiveLim_MtrNm_f32	TunSet_Ptr_Str->k_EOTDmpFWInactiveLim_MtrNm_f32
#define k_EOTDmpFWInputLim_MtrNm_f32	TunSet_Ptr_Str->k_EOTDmpFWInputLim_MtrNm_f32

/********************************* HystComp **********************************/
#define k_LpFricIpLim_HwNm_u9p7	TunSet_Ptr_Str->k_LpFricIpLim_HwNm_u9p7
#define t_HysCompCoulFricWIRBlendX_MtrNm_u8p8	TunSet_Ptr_Str->t_HysCompCoulFricWIRBlendX_MtrNm_u8p8
#define t_HysCompCoulFricWIRBlendY_Uls_u2p14	TunSet_Ptr_Str->t_HysCompCoulFricWIRBlendY_Uls_u2p14

/********************************* PosServo **********************************/
#define k_PosSrvo_PidLim_MtrNm_f32	TunSet_Ptr_Str->k_PosSrvo_PidLim_MtrNm_f32
#define k_PrkAstDTermKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstDTermKn_Hz_f32
#define k_PrkAstEnableRate_pSec_f32	TunSet_Ptr_Str->k_PrkAstEnableRate_pSec_f32
#define k_PrkAstHwaLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwaLPFKn_Hz_f32
#define k_PrkAstHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwTrqLPFKn_Hz_f32
#define t_HwaRateLimit_HwDegpSec_u12p4	TunSet_Ptr_Str->t_HwaRateLimit_HwDegpSec_u12p4
#define t_PosSrvoMaxCmdX_Kph_u9p7	TunSet_Ptr_Str->t_PosSrvoMaxCmdX_Kph_u9p7
#define t_PosSrvoMaxCmdY_MtrNm_u5p11	TunSet_Ptr_Str->t_PosSrvoMaxCmdY_MtrNm_u5p11
#define t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9	TunSet_Ptr_Str->t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9
#define t_PrkAstDisableRateX_HwNm_u11p5	TunSet_Ptr_Str->t_PrkAstDisableRateX_HwNm_u11p5
#define t_PrkAstDisableRateY_pSec_u12p4	TunSet_Ptr_Str->t_PrkAstDisableRateY_pSec_u12p4
#define t_PrkAstDmpTrqX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_PrkAstDmpTrqX_MtrRadpS_u11p5
#define t_PrkAstIGainY_MtrNmpHwDegS_u2p14	TunSet_Ptr_Str->t_PrkAstIGainY_MtrNmpHwDegS_u2p14
#define t_PrkAstITermAWLmtY_MtrNm_u9p7	TunSet_Ptr_Str->t_PrkAstITermAWLmtY_MtrNm_u9p7
#define t_PrkAstSmoothX_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothX_Uls_u6p10
#define t_PrkAstSmoothY_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothY_Uls_u6p10
#define t_PrkAstVehSpdBS_Kph_u9p7	TunSet_Ptr_Str->t_PrkAstVehSpdBS_Kph_u9p7
#define t2_PrkAstDmpTrqY_MtrNm_u4p12	TunSet_Ptr_Str->t2_PrkAstDmpTrqY_MtrNm_u4p12
#define t2_PrkAstPGainX_HwDeg_u12p4	TunSet_Ptr_Str->t2_PrkAstPGainX_HwDeg_u12p4
#define t2_PrkAstPGainY_MtrNm_u9p7	TunSet_Ptr_Str->t2_PrkAstPGainY_MtrNm_u9p7

/********************************* PsaAgArbn *********************************/
#define k_PsaAgAn_AbsHwPosLvl1_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_AbsHwPosLvl1_HwDeg_f32
#define k_PsaAgAn_AbsHwPosLvl2_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_AbsHwPosLvl2_HwDeg_f32
#define k_PsaAgAn_DiagPrec_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_DiagPrec_HwDeg_f32
#define k_PsaAgAn_EpsPrec_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_EpsPrec_HwDeg_f32
#define k_PsaAgAn_HwTrqFilt_Hz_f32	TunSet_Ptr_Str->k_PsaAgAn_HwTrqFilt_Hz_f32
#define k_PsaAgAn_MinPrecFail_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_MinPrecFail_HwDeg_f32
#define k_PsaAgAn_MtrVelFilt_Hz_f32	TunSet_Ptr_Str->k_PsaAgAn_MtrVelFilt_Hz_f32
#define k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_OffsDataInitMaxOffs_HwDeg_f32
#define k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08	TunSet_Ptr_Str->k_PsaAgAn_OffsDataInitMaxSrc_Cnt_u08
#define k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_OffsDataInitMinOffs_HwDeg_f32
#define k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08	TunSet_Ptr_Str->k_PsaAgAn_OffsDataInitMinSrc_Cnt_u08
#define k_PsaAgAn_OffsetPolarity_HwDeg_f32	TunSet_Ptr_Str->k_PsaAgAn_OffsetPolarity_HwDeg_f32
#define k_PsaAgAn_PinionTrqFilt_Hz_f32	TunSet_Ptr_Str->k_PsaAgAn_PinionTrqFilt_Hz_f32
#define k_PsaAgAn_VehCondMaxHwTrq_HwNm_f32	TunSet_Ptr_Str->k_PsaAgAn_VehCondMaxHwTrq_HwNm_f32
#define k_PsaAgAn_VehCondMaxMtrVel_MtrRadpS_f32	TunSet_Ptr_Str->k_PsaAgAn_VehCondMaxMtrVel_MtrRadpS_f32
#define k_PsaAgAn_VehCondMaxPinTrq_HwNm_f32	TunSet_Ptr_Str->k_PsaAgAn_VehCondMaxPinTrq_HwNm_f32
#define k_PsaAgAn_VehCondMaxVehSpd_Kph_f32	TunSet_Ptr_Str->k_PsaAgAn_VehCondMaxVehSpd_Kph_f32
#define k_PsaAgAn_VehCondMinTi_mS_u32	TunSet_Ptr_Str->k_PsaAgAn_VehCondMinTi_mS_u32

/********************************* PSAStHdlr *********************************/
#define k_PsaSH_ApaAssiStallLim_MtrNm_f32	TunSet_Ptr_Str->k_PsaSH_ApaAssiStallLim_MtrNm_f32
#define k_PsaSH_ApaDynErr_Cnt_str	TunSet_Ptr_Str->k_PsaSH_ApaDynErr_Cnt_str
#define k_PsaSH_ApaDynHwThd_HwDeg_u16	TunSet_Ptr_Str->k_PsaSH_ApaDynHwThd_HwDeg_u16
#define k_PsaSH_ApaExitCtrlProgsTi_mS_u16	TunSet_Ptr_Str->k_PsaSH_ApaExitCtrlProgsTi_mS_u16
#define k_PsaSH_ApaHwAuthority_Uls_f32	TunSet_Ptr_Str->k_PsaSH_ApaHwAuthority_Uls_f32
#define k_PsaSH_ApaHwTrqMax_HwNm_f32	TunSet_Ptr_Str->k_PsaSH_ApaHwTrqMax_HwNm_f32
#define k_PsaSH_ApaHwTrqMaxTi_mS_u32	TunSet_Ptr_Str->k_PsaSH_ApaHwTrqMaxTi_mS_u32
#define k_PsaSH_ApaHwTrqMin_HwNm_f32	TunSet_Ptr_Str->k_PsaSH_ApaHwTrqMin_HwNm_f32
#define k_PsaSH_ApaHwTrqMinTi_mS_u32	TunSet_Ptr_Str->k_PsaSH_ApaHwTrqMinTi_mS_u32
#define k_PsaSH_ApaMaxHwTrqFilt_Hz_f32	TunSet_Ptr_Str->k_PsaSH_ApaMaxHwTrqFilt_Hz_f32
#define k_PsaSH_ApaStatErr_Cnt_str	TunSet_Ptr_Str->k_PsaSH_ApaStatErr_Cnt_str
#define k_PsaSH_ApaStatHwThd_HwDeg_u16	TunSet_Ptr_Str->k_PsaSH_ApaStatHwThd_HwDeg_u16
#define k_PsaSH_ApaThemLimPerc_Uls_f32	TunSet_Ptr_Str->k_PsaSH_ApaThemLimPerc_Uls_f32
#define k_PsaSH_ApaVehSpd_Kph_f32	TunSet_Ptr_Str->k_PsaSH_ApaVehSpd_Kph_f32
#define k_PsaSH_LxaCorrnFacReqRate_UlspS_f32	TunSet_Ptr_Str->k_PsaSH_LxaCorrnFacReqRate_UlspS_f32
#define k_PsaSH_LxaCorrnFacThd_Uls_f32	TunSet_Ptr_Str->k_PsaSH_LxaCorrnFacThd_Uls_f32
#define k_PsaSH_LxaDrvrAbsntDetnTi_Sec_f32	TunSet_Ptr_Str->k_PsaSH_LxaDrvrAbsntDetnTi_Sec_f32
#define k_PsaSH_LxaDrvrIntvDetnThd_Uls_s08	TunSet_Ptr_Str->k_PsaSH_LxaDrvrIntvDetnThd_Uls_s08
#define k_PsaSH_LxaDrvrIntvtWarnTi_Sec_f32	TunSet_Ptr_Str->k_PsaSH_LxaDrvrIntvtWarnTi_Sec_f32
#define k_PsaSH_LxaHwAgDetnCnt_Cnt_u16	TunSet_Ptr_Str->k_PsaSH_LxaHwAgDetnCnt_Cnt_u16
#define k_PsaSH_LxaHwAuthy_Uls_f32	TunSet_Ptr_Str->k_PsaSH_LxaHwAuthy_Uls_f32
#define k_PsaSH_LxaHwTrqDetnTi_Sec_f32	TunSet_Ptr_Str->k_PsaSH_LxaHwTrqDetnTi_Sec_f32
#define k_PsaSH_LxaHwTrqRateDetnTi_Sec_f32	TunSet_Ptr_Str->k_PsaSH_LxaHwTrqRateDetnTi_Sec_f32
#define k_PsaSH_LxaHwTrqRateThd_HwNmpS_f32	TunSet_Ptr_Str->k_PsaSH_LxaHwTrqRateThd_HwNmpS_f32
#define k_PsaSH_LxaHwTrqRateTi_Hz_f32	TunSet_Ptr_Str->k_PsaSH_LxaHwTrqRateTi_Hz_f32
#define k_PsaSH_LxaHwVelDetnCnt_Cnt_u16	TunSet_Ptr_Str->k_PsaSH_LxaHwVelDetnCnt_Cnt_u16
#define k_PsaSH_LxaMaxHwTrq_HwNm_f32	TunSet_Ptr_Str->k_PsaSH_LxaMaxHwTrq_HwNm_f32
#define k_PsaSH_LxaVehSpdMin_Kph_f32	TunSet_Ptr_Str->k_PsaSH_LxaVehSpdMin_Kph_f32
#define t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7
#define t_PsaSH_ApaHwAgCmdRateY_HwDegpS_u11p5	TunSet_Ptr_Str->t_PsaSH_ApaHwAgCmdRateY_HwDegpS_u11p5
#define t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7
#define t_PsaSH_LxaDrvrAbsntDetnTiY_Sec_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaDrvrAbsntDetnTiY_Sec_u9p7
#define t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7
#define t_PsaSH_LxaDrvrAbsntHwVelThdY_HwRadpS_u7p9	TunSet_Ptr_Str->t_PsaSH_LxaDrvrAbsntHwVelThdY_HwRadpS_u7p9
#define t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7
#define t_PsaSH_LxaHwAgCmdRateY_HwDegpS_u11p5	TunSet_Ptr_Str->t_PsaSH_LxaHwAgCmdRateY_HwDegpS_u11p5
#define t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7
#define t_PsaSH_LxaHwAgCmdSatnY_HwDeg_u16	TunSet_Ptr_Str->t_PsaSH_LxaHwAgCmdSatnY_HwDeg_u16
#define t_PsaSH_LxaHwAgThdX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaHwAgThdX_Kph_u9p7
#define t_PsaSH_LxaHwAgThdY_HwDeg_u16	TunSet_Ptr_Str->t_PsaSH_LxaHwAgThdY_HwDeg_u16
#define t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11	TunSet_Ptr_Str->t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11
#define t_PsaSH_LxaInactvRstTmrX_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaInactvRstTmrX_Kph_u9p7
#define t_PsaSH_LxaInactvRstTmrY_Sec_u7p9	TunSet_Ptr_Str->t_PsaSH_LxaInactvRstTmrY_Sec_u7p9
#define t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7	TunSet_Ptr_Str->t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7
#define t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrNStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrNStepY_Cnt_u16
#define t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrPStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrPStepY_Cnt_u16
#define t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11	TunSet_Ptr_Str->t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11
#define t2_PsaSH_LxaHwAgDetnCntrNStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaHwAgDetnCntrNStepY_Cnt_u16
#define t2_PsaSH_LxaHwAgDetnCntrPStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaHwAgDetnCntrPStepY_Cnt_u16
#define t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5	TunSet_Ptr_Str->t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5
#define t2_PsaSH_LxaHwVelDetnCntrNStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaHwVelDetnCntrNStepY_Cnt_u16
#define t2_PsaSH_LxaHwVelDetnCntrPStepY_Cnt_u16	TunSet_Ptr_Str->t2_PsaSH_LxaHwVelDetnCntrPStepY_Cnt_u16
#define t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11	TunSet_Ptr_Str->t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11
#define t2_PsaSH_LxaHwVelThdX_Kph_u9p7	TunSet_Ptr_Str->t2_PsaSH_LxaHwVelThdX_Kph_u9p7
#define t2_PsaSH_LxaHwVelThdY_HwRadpS_u7p9	TunSet_Ptr_Str->t2_PsaSH_LxaHwVelThdY_HwRadpS_u7p9

/*********************************** PSATA ***********************************/
#define k_PsaTA_APAEnableRate_UlspS_f32	TunSet_Ptr_Str->k_PsaTA_APAEnableRate_UlspS_f32
#define k_PsaTA_ApaPosnServoTran_Uls_f32	TunSet_Ptr_Str->k_PsaTA_ApaPosnServoTran_Uls_f32
#define k_PsaTA_ApaPosServFltMode_Cnt_str	TunSet_Ptr_Str->k_PsaTA_ApaPosServFltMode_Cnt_str
#define k_PsaTA_DisableRate_UlspS_f32	TunSet_Ptr_Str->k_PsaTA_DisableRate_UlspS_f32
#define k_PsaTA_FilterCutOff_Hz_f32	TunSet_Ptr_Str->k_PsaTA_FilterCutOff_Hz_f32
#define k_PsaTA_LxaDiTranTi_Sec_f32	TunSet_Ptr_Str->k_PsaTA_LxaDiTranTi_Sec_f32
#define k_PsaTA_LxaHwTrqFltMode_Cnt_str	TunSet_Ptr_Str->k_PsaTA_LxaHwTrqFltMode_Cnt_str
#define k_PsaTA_LxaHwTrqRateFltMode_Cnt_str	TunSet_Ptr_Str->k_PsaTA_LxaHwTrqRateFltMode_Cnt_str
#define k_PsaTA_LxaHwTrqRateSftyThd_HwNmpS_f32	TunSet_Ptr_Str->k_PsaTA_LxaHwTrqRateSftyThd_HwNmpS_f32
#define k_PsaTA_LxaHwVelFltMode_Cnt_str	TunSet_Ptr_Str->k_PsaTA_LxaHwVelFltMode_Cnt_str
#define k_PsaTA_LxaMaxRate_UlspS_f32	TunSet_Ptr_Str->k_PsaTA_LxaMaxRate_UlspS_f32
#define k_PsaTA_LxaOpTrqOvFltMode_Cnt_str	TunSet_Ptr_Str->k_PsaTA_LxaOpTrqOvFltMode_Cnt_str
#define k_PsaTA_LxaPosnServoTran_Uls_f32	TunSet_Ptr_Str->k_PsaTA_LxaPosnServoTran_Uls_f32
#define k_PsaTA_LxaSftyMaxHwTorque_HwNm_f32	TunSet_Ptr_Str->k_PsaTA_LxaSftyMaxHwTorque_HwNm_f32
#define k_PsaTA_MaxPosServoCmdSafety_MtrNm_f32	TunSet_Ptr_Str->k_PsaTA_MaxPosServoCmdSafety_MtrNm_f32
#define k_PsaTA_MaxVehicleSpeedSafety_Kph_f32	TunSet_Ptr_Str->k_PsaTA_MaxVehicleSpeedSafety_Kph_f32
#define t_PsaTA_DisableRateX_HwNm_u11p5	TunSet_Ptr_Str->t_PsaTA_DisableRateX_HwNm_u11p5
#define t_PsaTA_DisableRateY_UlspS_u11p5	TunSet_Ptr_Str->t_PsaTA_DisableRateY_UlspS_u11p5
#define t_PsaTA_LxaHwVelSftyThdX_Kph_u9p7	TunSet_Ptr_Str->t_PsaTA_LxaHwVelSftyThdX_Kph_u9p7
#define t_PsaTA_LxaHwVelSftyThdY_HwRadpS_u7p9	TunSet_Ptr_Str->t_PsaTA_LxaHwVelSftyThdY_HwRadpS_u7p9
#define t_PsaTA_LxaOpTrqOvBndX_Kph_u9p7	TunSet_Ptr_Str->t_PsaTA_LxaOpTrqOvBndX_Kph_u9p7
#define t_PsaTA_LxaOpTrqOvBndY_MtrNm_u4p12	TunSet_Ptr_Str->t_PsaTA_LxaOpTrqOvBndY_MtrNm_u4p12
#define t_PsaTA_LxaOpTrqOvSftyBndY_MtrNm_u4p12	TunSet_Ptr_Str->t_PsaTA_LxaOpTrqOvSftyBndY_MtrNm_u4p12
#define t_PsaTA_LxaSmotngFactorX_Uls_u6p10	TunSet_Ptr_Str->t_PsaTA_LxaSmotngFactorX_Uls_u6p10
#define t_PsaTA_LxaSmotngFactorY_Uls_u6p10	TunSet_Ptr_Str->t_PsaTA_LxaSmotngFactorY_Uls_u6p10
#define t_PsaTA_LxaSmotngSftyFactorX_Kph_u9p7	TunSet_Ptr_Str->t_PsaTA_LxaSmotngSftyFactorX_Kph_u9p7
#define t_PsaTA_LxaSmotngSftyFactorY_Uls_u6p10	TunSet_Ptr_Str->t_PsaTA_LxaSmotngSftyFactorY_Uls_u6p10
#define t_PsaTA_SmoothingX_Uls_u6p10	TunSet_Ptr_Str->t_PsaTA_SmoothingX_Uls_u6p10
#define t_PsaTA_SmoothingY_Uls_u6p10	TunSet_Ptr_Str->t_PsaTA_SmoothingY_Uls_u6p10

/********************************** Return ***********************************/
#define k_RtnOffsetRange_HWDeg_f32	TunSet_Ptr_Str->k_RtnOffsetRange_HWDeg_f32
#define k_RtnOffsetSlew_HwDegpS_f32	TunSet_Ptr_Str->k_RtnOffsetSlew_HwDegpS_f32
#define t_ReturnTempScaleSclYTbl_Uls_u8p8	TunSet_Ptr_Str->t_ReturnTempScaleSclYTbl_Uls_u8p8
#define t_ReturnTempScaleXTbl_DegC_s11p4	TunSet_Ptr_Str->t_ReturnTempScaleXTbl_DegC_s11p4
#define t_ReturnVSpdTblBS_Kph_u9p7	TunSet_Ptr_Str->t_ReturnVSpdTblBS_Kph_u9p7

/****************************** ReturnFirewall *******************************/
#define t_RtrnFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_RtrnFWVehSpd_Kph_u9p7

/******************************* TuningSelAuth *******************************/
#define k_TunSel_HwVelThresh_HwRadpS_f32	TunSet_Ptr_Str->k_TunSel_HwVelThresh_HwRadpS_f32
#define k_TunSelHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_TunSelHwTrqLPFKn_Hz_f32
#define k_TunSelVehSpdThresh_Kph_f32	TunSet_Ptr_Str->k_TunSelVehSpdThresh_Kph_f32
#define t_TunSel_HwTrqThX_Kph_u9p7	TunSet_Ptr_Str->t_TunSel_HwTrqThX_Kph_u9p7
#define t_TunSel_HwTrqThY_HwNm_u4p12	TunSet_Ptr_Str->t_TunSel_HwTrqThY_HwNm_u4p12

/********************************** VehDyn ***********************************/
#define k_AutoCntrHiSpdCntrWindow_HwDeg_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdCntrWindow_HwDeg_f32
#define k_AutoCntrHiSpdFilt1Kn_Hz_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdFilt1Kn_Hz_f32
#define k_AutoCntrHiSpdFilt2Kn_Hz_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdFilt2Kn_Hz_f32
#define k_AutoCntrHiSpdTimer1_mS_u16	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer1_mS_u16
#define k_AutoCntrHiSpdTimer1MtrVel_MtrRadpS_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer1MtrVel_MtrRadpS_f32
#define k_AutoCntrHiSpdTimer1PinTrq_HwNm_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer1PinTrq_HwNm_f32
#define k_AutoCntrHiSpdTimer1VehSpd_kph_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer1VehSpd_kph_f32
#define k_AutoCntrHiSpdTimer2_mS_u16	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer2_mS_u16
#define k_AutoCntrHiSpdTimer4_mS_u16	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer4_mS_u16
#define k_AutoCntrHiSpdTimer4CntrWindow_HwDeg_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer4CntrWindow_HwDeg_f32
#define k_AutoCntrHiSpdTimer4MtrVel_MtrRadpS_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer4MtrVel_MtrRadpS_f32
#define k_AutoCntrHiSpdTimer4PinTrq_HwNm_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer4PinTrq_HwNm_f32
#define k_AutoCntrHiSpdTimer4VehSpd_kph_f32	TunSet_Ptr_Str->k_AutoCntrHiSpdTimer4VehSpd_kph_f32
#define k_AutoCntrLoSpdCntrWindow_HwDeg_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdCntrWindow_HwDeg_f32
#define k_AutoCntrLoSpdFilt1Kn_Hz_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdFilt1Kn_Hz_f32
#define k_AutoCntrLoSpdFilt2Kn_Hz_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdFilt2Kn_Hz_f32
#define k_AutoCntrLoSpdTimer1_mS_u16	TunSet_Ptr_Str->k_AutoCntrLoSpdTimer1_mS_u16
#define k_AutoCntrLoSpdTimer1MtrVel_MtrRadpS_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdTimer1MtrVel_MtrRadpS_f32
#define k_AutoCntrLoSpdTimer1PinTrq_HwNm_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdTimer1PinTrq_HwNm_f32
#define k_AutoCntrLoSpdTimer1VehSpd_kph_f32	TunSet_Ptr_Str->k_AutoCntrLoSpdTimer1VehSpd_kph_f32
#define k_AutoCntrLoSpdTimer2_mS_u16	TunSet_Ptr_Str->k_AutoCntrLoSpdTimer2_mS_u16
#define k_AutoCntrPinTrqLPFCoeffKn_Hz_f32	TunSet_Ptr_Str->k_AutoCntrPinTrqLPFCoeffKn_Hz_f32
#define k_HiSpdVDAuthority_Uls_f32	TunSet_Ptr_Str->k_HiSpdVDAuthority_Uls_f32
#define k_HwTqMgnThd_HwNm_f32	TunSet_Ptr_Str->k_HwTqMgnThd_HwNm_f32
#define k_LoSpdVDAuthority_Uls_f32	TunSet_Ptr_Str->k_LoSpdVDAuthority_Uls_f32
#define k_SLPEnableBFCheck_Cnt_lgc	TunSet_Ptr_Str->k_SLPEnableBFCheck_Cnt_lgc
#define k_SLPHwAuthority_Uls_f32	TunSet_Ptr_Str->k_SLPHwAuthority_Uls_f32
#define k_SLPMinHwAuthToStoreHwPos_Uls_f32	TunSet_Ptr_Str->k_SLPMinHwAuthToStoreHwPos_Uls_f32
#define k_SrlHwAgVldTiThd_mS_u32	TunSet_Ptr_Str->k_SrlHwAgVldTiThd_mS_u32
#define k_TravelXCDeadband_Uls_f32	TunSet_Ptr_Str->k_TravelXCDeadband_Uls_f32
#define k_TravelXCHwAuthority_Uls_f32	TunSet_Ptr_Str->k_TravelXCHwAuthority_Uls_f32
#define k_VehDyn_ErrTolr_HwDeg_f32	TunSet_Ptr_Str->k_VehDyn_ErrTolr_HwDeg_f32
#define k_VehDyn_SmoothCoeff_Uls_f32	TunSet_Ptr_Str->k_VehDyn_SmoothCoeff_Uls_f32
#define k_VehDyn_TravelXCDeadbandTolr_Uls_f32	TunSet_Ptr_Str->k_VehDyn_TravelXCDeadbandTolr_Uls_f32

/********************************** Assist ***********************************/
#define t2_AsstAsstY0_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY0_MtrNm_s4p11
#define t2_AsstHwtX0_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX0_HwNm_u8p8

/* Assist, Damping, DampingFirewall, FrqDepDmpnInrtCmp, HighFreqAssist, HystComp ********************************************************************************/
#define t_CmnVehSpd_Kph_u9p7	TunPer_Ptr_Str->t_CmnVehSpd_Kph_u9p7

/****************************** AssistFirewall *******************************/
#define t_AsstFWDefltAssistX_HwNm_u8p8	TunPer_Ptr_Str->t_AsstFWDefltAssistX_HwNm_u8p8
#define t_AsstFWDefltAssistY_MtrNm_s4p11	TunPer_Ptr_Str->t_AsstFWDefltAssistY_MtrNm_s4p11
#define t_AsstFWVehSpd_Kph_u9p7	TunPer_Ptr_Str->t_AsstFWVehSpd_Kph_u9p7
#define t2_AsstFWUprBoundX_HwNm_s4p11	TunPer_Ptr_Str->t2_AsstFWUprBoundX_HwNm_s4p11
#define t2_AsstFWUprBoundY_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstFWUprBoundY_MtrNm_s4p11

/********************************** Damping **********************************/
#define k_HPSbaseC1_MtrNmpMtrRadpS_f32	TunPer_Ptr_Str->k_HPSbaseC1_MtrNmpMtrRadpS_f32
#define k_HPSbaseC2_MtrNmpMtrRadpS_f32	TunPer_Ptr_Str->k_HPSbaseC2_MtrNmpMtrRadpS_f32
#define k_HPSbaseC3_MtrNmpMtrRadpS_f32	TunPer_Ptr_Str->k_HPSbaseC3_MtrNmpMtrRadpS_f32
#define k_HPSbaseC4_MtrNmpMtrRadpS_f32	TunPer_Ptr_Str->k_HPSbaseC4_MtrNmpMtrRadpS_f32
#define k_HPSOutLimit_MtrNm_f32	TunPer_Ptr_Str->k_HPSOutLimit_MtrNm_f32
#define k_MtrVelDampLPFKn_Hz_f32	TunPer_Ptr_Str->k_MtrVelDampLPFKn_Hz_f32
#define k_QDDHwTrqBckLash_HwNm_f32	TunPer_Ptr_Str->k_QDDHwTrqBckLash_HwNm_f32
#define k_QddHwTrqDampKn_Hz_f32	TunPer_Ptr_Str->k_QddHwTrqDampKn_Hz_f32
#define k_QDDMtrVelBckLash_MtrRadpS_f32	TunPer_Ptr_Str->k_QDDMtrVelBckLash_MtrRadpS_f32
#define k_QddMtrVelDampKn_Hz_f32	TunPer_Ptr_Str->k_QddMtrVelDampKn_Hz_f32
#define k_QddSfLFPKn_Hz_f32	TunPer_Ptr_Str->k_QddSfLFPKn_Hz_f32
#define k_Quad13DmpMult_Uls_f32	TunPer_Ptr_Str->k_Quad13DmpMult_Uls_f32
#define k_Quad24DmpMult_Uls_f32	TunPer_Ptr_Str->k_Quad24DmpMult_Uls_f32
#define t_HPSAsstLimY_MtrNm_u4p12	TunPer_Ptr_Str->t_HPSAsstLimY_MtrNm_u4p12
#define t_HPSscaleC1Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC1Y_Uls_u4p12
#define t_HPSscaleC2Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC2Y_Uls_u4p12
#define t_HPSscaleC3Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC3Y_Uls_u4p12
#define t_HPSscaleC4Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC4Y_Uls_u4p12
#define t_HwTrqDmpTblX_HwNm_u8p8	TunPer_Ptr_Str->t_HwTrqDmpTblX_HwNm_u8p8
#define t_HwTrqDmpTblY_Uls_u1p15	TunPer_Ptr_Str->t_HwTrqDmpTblY_Uls_u1p15
#define t2_MtrVelDmpTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t2_MtrVelDmpTblX_MtrRadpS_u12p4
#define t2_MtrVelDmpTblY_MtrNm_u5p11	TunPer_Ptr_Str->t2_MtrVelDmpTblY_MtrNm_u5p11

/****************************** DampingFirewall ******************************/
#define k_DmpBoundLPFKn_Hz_f32	TunPer_Ptr_Str->k_DmpBoundLPFKn_Hz_f32
#define t_DampFWDefltDampX_MtrRadpS_u11p5	TunPer_Ptr_Str->t_DampFWDefltDampX_MtrRadpS_u11p5
#define t_DampFWDefltDampY_MtrNm_u5p11	TunPer_Ptr_Str->t_DampFWDefltDampY_MtrNm_u5p11
#define t_DampFWUprBoundX_MtrRadpS_s11p4	TunPer_Ptr_Str->t_DampFWUprBoundX_MtrRadpS_s11p4
#define t_DampFWVehSpd_Kph_u9p7	TunPer_Ptr_Str->t_DampFWVehSpd_Kph_u9p7
#define t2_DampFWUprBoundY_MtrNm_s7p8	TunPer_Ptr_Str->t2_DampFWUprBoundY_MtrNm_s7p8

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#define k_InrtCmp_MtrInertia_KgmSq_f32	TunPer_Ptr_Str->k_InrtCmp_MtrInertia_KgmSq_f32
#define k_InrtCmp_MtrVel_ScaleFactor_Uls_f32	TunPer_Ptr_Str->k_InrtCmp_MtrVel_ScaleFactor_Uls_f32
#define k_InrtCmp_TBarVelLPFKn_Hz_f32	TunPer_Ptr_Str->k_InrtCmp_TBarVelLPFKn_Hz_f32
#define t_DmpADDCoefX_MtrNm_u4p12	TunPer_Ptr_Str->t_DmpADDCoefX_MtrNm_u4p12
#define t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17	TunPer_Ptr_Str->t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17
#define t_FDD_AttenTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t_FDD_AttenTblX_MtrRadpS_u12p4
#define t_FDD_AttenTblY_Uls_u8p8	TunPer_Ptr_Str->t_FDD_AttenTblY_Uls_u8p8
#define t_FDD_BlendTblY_Uls_u8p8	TunPer_Ptr_Str->t_FDD_BlendTblY_Uls_u8p8
#define t_InrtCmp_ScaleFactorTblY_Uls_u9p7	TunPer_Ptr_Str->t_InrtCmp_ScaleFactorTblY_Uls_u9p7
#define t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7	TunPer_Ptr_Str->t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7
#define t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17	TunPer_Ptr_Str->t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17
#define t2_FDD_FreqTblYM_Hz_u12p4	TunPer_Ptr_Str->t2_FDD_FreqTblYM_Hz_u12p4

/********************************** EtDmpFw **********************************/
#define t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4	TunPer_Ptr_Str->t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4
#define t_EOTDmpFWVehSpd_Kph_u9p7	TunPer_Ptr_Str->t_EOTDmpFWVehSpd_Kph_u9p7
#define t2_EOTDmpFWActiveBoundY_MtrNm_s7p8	TunPer_Ptr_Str->t2_EOTDmpFWActiveBoundY_MtrNm_s7p8

/****************************** HighFreqAssist *******************************/
#define t_LPFKnY_Hz_u7p9	TunPer_Ptr_Str->t_LPFKnY_Hz_u7p9
#define t2_GainY0_MtrNmpHwNm_u3p13	TunPer_Ptr_Str->t2_GainY0_MtrNmpHwNm_u3p13
#define t2_TorqX0_HwNm_u5p11	TunPer_Ptr_Str->t2_TorqX0_HwNm_u5p11

/********************************* HystComp **********************************/
#define k_HysCmpHwTrqLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysCmpHwTrqLPFKn_Hz_f32
#define k_HysCmpLPAstLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysCmpLPAstLPFKn_Hz_f32
#define k_HysFinalOutLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysFinalOutLPFKn_Hz_f32
#define k_HysOutLIm_HwNm_f32	TunPer_Ptr_Str->k_HysOutLIm_HwNm_f32
#define k_HysRevGain_InvHwNm_f32	TunPer_Ptr_Str->k_HysRevGain_InvHwNm_f32
#define t_EffLossTblY_Uls_u4p12	TunPer_Ptr_Str->t_EffLossTblY_Uls_u4p12
#define t_EffOffTblY_HwNm_u9p7	TunPer_Ptr_Str->t_EffOffTblY_HwNm_u9p7
#define t_HysCompCoulFricTempScaleX_DegC_s14p1	TunPer_Ptr_Str->t_HysCompCoulFricTempScaleX_DegC_s14p1
#define t_HysCompCoulFricTempScaleY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompCoulFricTempScaleY_HwNm_u9p7
#define t_HysCompCoulFricY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompCoulFricY_HwNm_u9p7
#define t_HysCompHysSatY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompHysSatY_HwNm_u9p7
#define t_HysCompNegHysBlendX_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompNegHysBlendX_HwNm_u9p7
#define t_HysCompNegHysBlendY_Uls_u2p14	TunPer_Ptr_Str->t_HysCompNegHysBlendY_Uls_u2p14
#define t_HysCompNegHysCompX_MtrNm_u8p8	TunPer_Ptr_Str->t_HysCompNegHysCompX_MtrNm_u8p8
#define t_HysCompNegHysCompY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompNegHysCompY_HwNm_u9p7
#define t_HysRiseTblX_HwNm_u2p14	TunPer_Ptr_Str->t_HysRiseTblX_HwNm_u2p14
#define t_HysRiseTblY_Uls_u2p14	TunPer_Ptr_Str->t_HysRiseTblY_Uls_u2p14
#define t2_HysHwTrqBlndTblX_HwNm_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblX_HwNm_u4p12
#define t2_HysHwTrqBlndTblY_Uls_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblY_Uls_u4p12

/********************************** PSADSG ***********************************/
#define t_PsaDSG_DampgCmdFacVehSpdBndTbl_Kph_u9p7	TunPer_Ptr_Str->t_PsaDSG_DampgCmdFacVehSpdBndTbl_Kph_u9p7
#define t2_PsaDSG_DampgCmdFacHwTqX_HwNm_u4p12	TunPer_Ptr_Str->t2_PsaDSG_DampgCmdFacHwTqX_HwNm_u4p12
#define t2_PsaDSG_DampgCmdFacY_Uls_u1p15	TunPer_Ptr_Str->t2_PsaDSG_DampgCmdFacY_Uls_u1p15

/********************************** Return ***********************************/
#define k_RtnHWAuthSlew_UlspS_f32	TunPer_Ptr_Str->k_RtnHWAuthSlew_UlspS_f32
#define t_HWAuthRetScl_X_Uls_u8p8	TunPer_Ptr_Str->t_HWAuthRetScl_X_Uls_u8p8
#define t_HWAuthRetScl_Y_Uls_u9p7	TunPer_Ptr_Str->t_HWAuthRetScl_Y_Uls_u9p7
#define t2_ReturnPosTblXM_HwDeg_u12p4	TunPer_Ptr_Str->t2_ReturnPosTblXM_HwDeg_u12p4
#define t2_ReturnPosTblYM_MtrNm_u5p11	TunPer_Ptr_Str->t2_ReturnPosTblYM_MtrNm_u5p11
#define t2_ReturnSclTrqTblXM_HwNm_T_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblXM_HwNm_T_u8p8
#define t2_ReturnSclTrqTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblYM_Uls_u8p8
#define t2_ReturnSclVelTblXM_HwRadpS_T_u7p9	TunPer_Ptr_Str->t2_ReturnSclVelTblXM_HwRadpS_T_u7p9
#define t2_ReturnSclVelTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclVelTblYM_Uls_u8p8

/****************************** ReturnFirewall *******************************/
#define t_RtrnFWUprBoundX_HwDeg_s11p4	TunPer_Ptr_Str->t_RtrnFWUprBoundX_HwDeg_s11p4
#define t2_RtrnFWUprBoundY_MtrNm_s4p11	TunPer_Ptr_Str->t2_RtrnFWUprBoundY_MtrNm_s4p11

/******************************* StabilityComp *******************************/
#define k_StCmpHwTrqLPFKn_Hz_f32	TunPer_Ptr_Str->k_StCmpHwTrqLPFKn_Hz_f32
#define k_StCmpStabCmpNstep_Cnt_u16	TunPer_Ptr_Str->k_StCmpStabCmpNstep_Cnt_u16
#define k_StCmpStabCmpPNThresh_Cnt_u16	TunPer_Ptr_Str->k_StCmpStabCmpPNThresh_Cnt_u16
#define k_StCmpStabCmpPstep_Cnt_u16	TunPer_Ptr_Str->k_StCmpStabCmpPstep_Cnt_u16
#define k_StCmpSysCorrThresh_MtrNm_f32	TunPer_Ptr_Str->k_StCmpSysCorrThresh_MtrNm_f32
#define t_StCmpADDFBlendX_Uls_u2p14	TunPer_Ptr_Str->t_StCmpADDFBlendX_Uls_u2p14
#define t_StCmpADDFBlendY_Uls_u2p14	TunPer_Ptr_Str->t_StCmpADDFBlendY_Uls_u2p14
#define t_StCmpBlend12Trq_HwNm_u8p8	TunPer_Ptr_Str->t_StCmpBlend12Trq_HwNm_u8p8
#define t_StCmpBlend34Trq_HwNm_u8p8	TunPer_Ptr_Str->t_StCmpBlend34Trq_HwNm_u8p8
#define t_StCmpBlendSpdBS_Kph_u9p7	TunPer_Ptr_Str->t_StCmpBlendSpdBS_Kph_u9p7
#define t_StCmpNFK_Str	TunPer_Ptr_Str->t_StCmpNFK_Str
#define t2_StCmpBlend02TblY_Uls_u2p14	TunPer_Ptr_Str->t2_StCmpBlend02TblY_Uls_u2p14
#define t2_StCmpBlend04TblY_Uls_u2p14	TunPer_Ptr_Str->t2_StCmpBlend04TblY_Uls_u2p14
#define t2_StCmpBlend12TblY_Uls_u2p14	TunPer_Ptr_Str->t2_StCmpBlend12TblY_Uls_u2p14
#define t2_StCmpBlend34TblY_Uls_u2p14	TunPer_Ptr_Str->t2_StCmpBlend34TblY_Uls_u2p14
#endif

/*********************** Start of Code Footer ************************/

extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];


