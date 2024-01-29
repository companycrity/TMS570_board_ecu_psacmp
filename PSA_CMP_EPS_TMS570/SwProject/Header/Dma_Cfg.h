
#ifndef DMA_CFG_H
#define DMA_CFG_H


#include "Ap_DiagMgr.h"


#define D_DMAFLSTSTENABLED_CNT_ENUM			STD_ON	/* FlsTst Init Groups */
#define D_FASTSPIGROUPENABLED_CNT_ENUM		STD_ON	/* 50us SPI Group */
#define D_FASTADCGROUPENABLED_CNT_ENUM		STD_ON	/* 50us ADC Group */
#define D_FASTPWMGROUPENABLED_CNT_ENUM		STD_ON	/* 50us PWM Group */
#define D_SLOWADCGROUPENABLED_CNT_ENUM		STD_ON	/* 2ms ADC Group */

#define DMA_REPORTERRORSTATUS				NxtrDiagMgr10_ReportNTCStatus

#define DMA_NHET1PROGHFILE "Nhet1CfgAndUse_Prog.h"      /* Header file containing the definition of HET_PRD_BUF1_0 should be used */

#endif
