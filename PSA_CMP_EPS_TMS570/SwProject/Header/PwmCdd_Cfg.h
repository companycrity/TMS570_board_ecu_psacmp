/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : PwmCdd_Cfg.h
* Module Description: Pwm Complex Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          1 %
* %derived_by:       fzh7xw %
* %date_modified:    Wed Feb 26 16:28:57 2014 %
*---------------------------------------------------------------------------*/


#ifndef PWMCDD_CFG_H
#define PWMCDD_CFG_H

#include "CDD_Data.h"

#define d_PWMClockFreq_Hz_u32           80000000UL
#define d_PwmFreq_Hz_Cnt_u16            80000000UL
#define d_PWMFreqBase_Hz_u16            16000U
#define d_PWMFreqDither_Hz_u16          2000U

#define CDD_Read_PhaseAdvanceFinal_Rev_u0p16( ptr )		*(ptr) = CDD_PhaseAdvFinal_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define CDD_Read_CorrectedMtrPos_Rev_u0p16( ptr )		*(ptr) = CDD_CorrectedElecMtrPos_Rev_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define CDD_Read_CommOffset_Cnt_u16( ptr )				*(ptr) = CDD_CommOffset_Cnt_G_u16

#define CDD_Write_DCPhsBComp_Cnt_u16p0( val ) 	(void)0	 /* Disable optional write, not required */
#define CDD_Write_DCPhsCComp_Cnt_u16p0( val ) 	(void)0  /* Disable optional write, not required */

#endif
