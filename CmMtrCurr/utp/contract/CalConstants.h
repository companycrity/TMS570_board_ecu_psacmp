/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          6 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Thu Nov 21 09:29:59 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/26/2014 4:03:05 PM *******************/
/****************************** MtrCurr - Rev9 *******************************/


extern CONST(float32, CAL_CONST) k_CurrCorrErrFiltFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_CurrCorrErrThresh_Amps_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Amps_f32;
extern CONST(float32, CAL_CONST) k_MaxCurrOffMtrVel_RadpS_f32;
extern CONST(uint16, CAL_CONST) k_CurrOffGainKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrCurrOffLoComOff_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CurrOffNoofAvg_Cnt_u16;
#endif
