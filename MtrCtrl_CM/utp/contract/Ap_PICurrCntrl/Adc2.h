/*****************************************************************************
* Copyright 2011 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Adc2.h
* Module Description: This file contains a stub header for UTP and QAC 
*                     projects
* Product           : Gen II Plus EA3.0
* Author            : Jared Julien
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Wed May  23 16:48:22 2003
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Mon Nov 19 17:58:33 2012 %
*---------------------------------------------------------------------------*/
#ifndef ADC2_H
#define ADC2_H

/* The following defines allow access directly to the ADC2 Result */
/*  RAM (i.e. non-fifo mode.                                      */
#define D_ADC2RSLTBASEADR_CNT_U32      (0xFF3A0000U)

#define  D_PHSREASACHN_CNT_U16         5U
#define  D_PHSREASBCHN_CNT_U16         6U
#define  D_PHSREASCCHN_CNT_U16         7U

/* The following macros are designed to grant access to the motro cos and sin adc results  */
/*  At the moment, for efficiency, they allow direct access to the ADC results.            */
/*  The 12bit mask is used to mask out the Channel ID appended to the conversion result.   */
/*  Function access is used instead of direct memory access to facilitate UTP.  Inline is  */
/*  is specified to reduce the execution time for the Mtr Ctrl Isr accesses                */

#define Adc2_GetPhsReasA_Cnt_u16_m   Adc2_ReadConversion(D_PHSREASACHN_CNT_U16)
#define Adc2_GetPhsReasB_Cnt_u16_m   Adc2_ReadConversion(D_PHSREASBCHN_CNT_U16)
#define Adc2_GetPhsReasC_Cnt_u16_m   Adc2_ReadConversion(D_PHSREASCCHN_CNT_U16)

/* User function prototypes */
inline uint16 Adc2_ReadConversion(uint16);

/* User function definitions */
inline uint16 Adc2_ReadConversion(uint16 ConvId)
{
	return((uint16)(0x00000FFFUL & ((uint32*)D_ADC2RSLTBASEADR_CNT_U32)[ConvId]));
}


#endif  /* ADC2_H */