
#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H

#include "Std_Types.h"

typedef struct
{
	uint8	Day_Cnt_u08;
	uint8	Month_Cnt_u08;
	uint8	Year_Cnt_u08;
} ECUManufacturingDateType_Str;

extern CONST(ECUManufacturingDateType_Str, DIAGSVC_CONST) D_MANUFDATEINIT_CNT_STR;

extern VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogA_G_str;
extern VAR(FlashLogType_Str, DIAGSVC_VAR) FlashLogB_G_str;

#endif
