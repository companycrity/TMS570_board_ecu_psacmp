/*****************************************************************************
* Copyright 2010, 2016 Nexteer Automotive, All Rights Reserved.
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
* %version:          EA3#10 %
* %derived_by:       jzk9cc %
* %date_modified:    Thu Feb 13 10:30:44 2014 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H



#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/21/2016 2:36:38 PM *******************/
/************************* MotorControl_CM - Rev  15 *************************/



extern CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_NoofPoles_Uls_f32;
extern CONST(float32, CAL_CONST) k_PIGainVspdCutoff_kph_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_MinKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MinRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MaxRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MinLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_NomTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32;
extern CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32;
extern CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32;
extern CONST(uint16, CAL_CONST) t_KeSatTblX_Amp_u9p7[16];
extern CONST(uint16, CAL_CONST) t_KeSatTblY_Uls_u2p14[16];
extern CONST(uint16, CAL_CONST) t_CurrParamCompDaxRef_Amp_u9p7[6];
extern CONST(uint16, CAL_CONST) t_CurrParamCompQaxRef_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t2_CurrParamLdSatSclFac_Uls_u2p14[6][7];
extern CONST(uint16, CAL_CONST) t2_CurrParamLqSatSclFac_Uls_u2p14[6][7];
extern CONST(float32, CAL_CONST) k_PiSamplingTs_Sec_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) k_EstPkCurr2msLPFKn_Uls_u16;
extern CONST(uint16, CAL_CONST) k_EstPkCurrSlowLoopLPFKn_Uls_u16;
extern CONST(float32, CAL_CONST) k_MtrVelFiltFFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVelFiltPIKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_NoofPoles_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic6thElec_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic12thElec_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic18thElec_Uls_f32;
extern CONST(uint16, CAL_CONST) t_MtrCurrQaxRpl_Amp_u9p7[12];
extern CONST(uint16, CAL_CONST) t_MtrCurrDaxRpl_Amp_u9p7[10];
extern CONST(uint16, CAL_CONST) t_MtrVelX_MtrRadpS_T_u16[20];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIMagRP_Uls_u6p10[20][8];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIPhRP_Rev_u0p16[20][8];
extern CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32;
extern CONST(float32, CAL_CONST) k_NomLq_Henry_f32;
extern CONST(float32, CAL_CONST) k_NomLd_Henry_f32;
extern CONST(float32, CAL_CONST) t_RefDeltaPoints_Rad_f32[8];
extern CONST(uint16, CAL_CONST) t_Q13VltgSchedXTbl_MtrRadpS_u12p4[10];
extern CONST(uint16, CAL_CONST) t_Q13VltgSchedYTbl_Volt_u5p11[10];
extern CONST(uint16, CAL_CONST) t_Q24VltgSchedXTbl_MtrRadpS_u12p4[10];
extern CONST(uint16, CAL_CONST) t_Q24VltgSchedYTbl_Volt_u5p11[10];
extern CONST(float32, CAL_CONST) k_IdqRefTrqTol_Rad_f32;
extern CONST(uint16, CAL_CONST) k_IdqRefTrqNIter_Cnt_u16;
extern CONST(float32, CAL_CONST) k_IdqRefIminTol_Amp_f32;
extern CONST(uint16, CAL_CONST) k_IdqRefIminNIter_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_IdqRefLocateRefNIter_Cnt_u16;
extern CONST(float32, CAL_CONST) k_deadtimeVScale_Uls_f32;
extern CONST(float32, CAL_CONST) k_IdBoostGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_IdBoostVRThreshScl_Uls_f32;
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCmdX_MtrNm_u4p12[11];
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCharSclY_Uls_u1p15[11];
extern CONST(boolean, CAL_CONST) k_MtrCtrlCurrLoopSecOrTranFcEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrCtrlFeedbackControlDisable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_VoltModeDynCompEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltDervFiltCoeffTimeCons_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrCtrlVirualResQax_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MtrCtrlVirualResDax_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrDaxMaxValScl_Per_f32;
extern CONST(float32, CAL_CONST) k_MtrDampingRatioDax_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrDampingRatioQax_Uls_f32;
extern CONST(uint16, CAL_CONST) t_MtrBandwidthDaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrBandwidthQaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrVelCtrlGainX_MtrRadpSec_u12p4[4];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqQaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqDaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrTrqCmdPIY_MtrNm_u5p11[8];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl18Y_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl18X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl12Y_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl12X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl6X_MtrNm_s2p13[10][12];
extern CONST(sint16, CAL_CONST) t2_MtrTrqRpl6Y_MtrNm_s2p13[10][12];
extern CONST(float32, CAL_CONST) k_VoltSatDaxPolyCoeff_Uls_f32;
extern CONST(float32, CAL_CONST) k_VoltSatQaxPolyCoeff_Uls_f32;
extern CONST(boolean, CAL_CONST) k_MtrCurrQaxRefModifDsb_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_CLOAFdbackSignalSclFacSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_ILOAFdbackSignalSclFacSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelayRpl_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxFiltFFKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltQaxFiltFFEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltVecuFiltKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltVecuFiltEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrCurrQaxRefModifRplEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegLoLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegLoLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_DualEcuSignalSclFacSlew_UlspS_f32;
#endif


