
#ifndef APPDESC_H
#define APPDESC_H

#include "Nvm.h"

typedef struct
{
	uint8	Data_Cnt_u08[24u];
	uint8	Nexteer_Cnt_u08[22u];
	uint16	CRC_Cnt_u16;
	uint16	Count_Cnt_u16;
} FlashLogType_Str;

extern void AppDesc_Init2(void);
extern void AppDesc_Per1(void);
boolean TestFlashLogValidity(NvM_BlockIdType NvmBlock_Cnt_T_enum, FlashLogType_Str * FlashLogData_Cnt_T_str);

#endif
