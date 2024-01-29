
#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Rte_Type.h"

/* Buffer Switch */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;


/* Data Native to MtrCtrl Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosMech_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosElec_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];


extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrPosElec_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK1_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK2_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_DaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_DaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_QaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_QaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltDaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltQaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,CDD_VAR_NOINIT)	CDD_ModIdxSrlComSvcDft_Cnt_G_u16;
extern VAR(float32, CDD_VAR_NOINIT)  CDD_ElecPosDelayComp_Rad_G_f32;
extern VAR(sint8,CDD_VAR_NOINIT)	CDD_MtrElecPol_Cnt_G_s8;
extern VAR(Rte_ModeType_StaMd_Mode, CDD_VAR_NOINIT) CDD_SysState_Cnt_G_Enum;
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsBComp_Cnt_G_u16p0;
extern VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsCComp_Cnt_G_u16p0;

extern VAR(uint16,CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;
extern VAR(uint16,CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;

extern VAR(uint16, CDD_VAR_NOINIT) CDD_ADC2OffsetComp_Cnt_G_u8p8;
#endif
