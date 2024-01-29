
#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#define NVM_REQ_OK ((NvM_RequestResultType)0u)
#define ManufacturingMode ((ManufModeType)1u)

typedef uint8 NvM_RequestResultType;

typedef uint8 ManufModeType;

typedef uint16 NvM_BlockIdType;

typedef sint16 CurrTempOffsetTblType[16];

typedef struct
{
  CurrTempOffsetTblType CurrTempOffsetX_DegC_s10p5;
  CurrTempOffsetTblType CurrOffsetY1_Volts_s4p11;
  CurrTempOffsetTblType CurrOffsetY2_Volts_s4p11;
} CurrTempOffsetType;

typedef struct
{
  float32 EOLMtrCurrVcalCmd_VoltCnts_f32;
  float32 EOLMtrCurr1OffsetLo_Volts_f32;
  float32 EOLPhscurr1Gain_AmpspVolt_f32;
  float32 EOLPhscurr2Gain_AmpspVolt_f32;
  float32 EOLMtrCurr2OffsetLo_Volts_f32;
  float32 EOLMtrCurr1OffsetDiff_Volts_f32;
  float32 EOLMtrCurr2OffsetDiff_Volts_f32;
} PhaseCurrCal_DataType;

typedef struct
{
  float32 CWEOTPosition_HwDeg_f32;
  float32 CCWEOTPosition_HwDeg_f32;
  boolean CWEOTFound_Cnt_lgc;
  boolean CCWEOTFound_Cnt_lgc;
} EOTLearned_DataType;

typedef uint16 AvgFricLrnRangeCounterSubType[3];
typedef AvgFricLrnRangeCounterSubType AvgFricLrnRangeCounterType[8];
typedef float32 AvgFricLrnThetaSubType[4];
typedef AvgFricLrnThetaSubType AvgFricLrnThetaType[8];
typedef float32 AvgFricLrnVehLearnedFricType[4];

typedef struct
{
  float32 FricOffset_HwNm_f32;
  float32 EOLFric_HwNm_f32;
  boolean EnableFricOffsetOutput_Cnt_lgc;
  boolean EnableFricLearning_Cnt_lgc;
  uint8 OpMode_Cnt_enum;
  AvgFricLrnRangeCounterType RangeCounter_Cnt_u16;
  AvgFricLrnThetaType Theta_HwNm_f32;
  AvgFricLrnVehLearnedFricType VehLearnedFric_HwNm_f32;
} AvgFricLrnType;

typedef struct
{
  float32 EOLVehCntrOffset_HwDeg_f32;
  uint16 EOLHwPosTrimPerformed_Cnt_u16;
} EOLHwPosTrimType;

#endif
