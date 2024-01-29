/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Adc_Cfg.h
* Module Description: Adc Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          4 %
* %derived_by:       nzt9hv %
* %date_modified:    Fri May 31 19:21:37 2013 %
*---------------------------------------------------------------------------*/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Adc.h"

#define D_ADC1CURRENTMODE_ULS_LGC

/* Map user defined group conversion names to appropriate group indexer */
#define AdcFwdPath     		D_GROUP1_CNT_U8
#define AdcFdbkPath     	D_GROUP2_CNT_U8
#define adcGROUP0			D_GROUPEV_CNT_U8


#define D_ADC1NUMEVTCH_CNT_U08	0U				/* Number of channels sampled (e.g. number of bits set in D_ADC1EVTCH_CNT_U32) */
#define D_ADC1EVTCH_CNT_U32		0x0000U
#define D_ADC1EVTBUFSZ_CNT_U08	52U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG1CH_CNT_U08	2U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G1CH_CNT_U32) */
#define D_ADC1G1CH_CNT_U32		0xC000U
#define D_ADC1G1BUFSZ_CNT_U08	2U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG2CH_CNT_U08	10U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G2CH_CNT_U32) */
#define D_ADC1G2CH_CNT_U32		0x3F65U
#define D_ADC1G2BUFSZ_CNT_U08	10U				/* Number of results allocated in ADC RAM, must be even */

extern void ADC1_REPORTERRORSTATUS(uint8 event, uint8 param, uint8 status);

#define ADC_EVENT_PASSED				TRUE
#define ADC_EVENT_FAILED				FALSE
#define  D_TRUE_CNT_LGC                 TRUE
#define  D_FALSE_CNT_LGC                FALSE

typedef uint8	Adc_ConfigType;

/* Event Group Register Configuration (Currently Not Used) */
#define D_ADC1GEVTSRC_CNT_U32		0U
#define D_ADC1GEVTDMACR_CNT_U32		0U

/* Group 1 Register Configuration */
#define D_ADC1G1SRC_CNT_U32			0U
#define D_ADC1G1DMACR_CNT_U32		0U

/* Group 2 Register Configuration */
#define D_ADC1G2SRC_CNT_U32			0U
#define D_ADC1G2DMACR_CNT_U32		0U

/* define D_ADC1USEDMA_CNT_LGC to STD_ON if using DMA to transfer ADC data; STD_OFF if not using DMA */
#define D_ADC1USEDMA_CNT_LGC     STD_OFF

/* define D_HWTRGADC1Gx_CNT_LGC to STD_ON to use hardware triggering; STD_OFF to use software triggering */
/* only used when D_ADC1USEDMA_CNT_LGC == STD_ON */
#define D_HWTRGADC1GEVT_CNT_LGC     STD_OFF
#define D_HWTRGADC1G1_CNT_LGC       STD_OFF
#define D_HWTRGADC1G2_CNT_LGC       STD_OFF

#define  Adc1_Write_ADC1OffsetComp_Cnt_u8p8(val)   (val)= (val)
#endif
