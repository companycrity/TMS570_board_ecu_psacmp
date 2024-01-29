
#ifndef ADC_H
#define ADC_H

#define D_GROUP2_CNT_U8				2U
#define AdcFdbkPath					D_GROUP2_CNT_U8
#define D_ADC1NUMG2CH_CNT_U08		4u
#define D_TEMPSNSRCHN_CNT_U16		0u
#define D_BATTCHN_CNT_U16			1u
#define D_VREF_CNT_U16				2u
#define D_BATTSWITCHEDCHN_CNT_U16	3u

typedef uint8  Adc_GroupType;
typedef uint16 Adc_ValueGroupType;
typedef P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) Adc_ValueGroupRefType;

typedef enum
{
  ADC_IDLE,
  ADC_BUSY,
  ADC_COMPLETED,
  ADC_STREAM_COMPLETED
} Adc_StatusType;

FUNC(void, ADC_CODE) Adc_StartGroupConversion(Adc_GroupType Group);
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupRefType DataBufferPtr);
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(Adc_GroupType Group);

#endif
