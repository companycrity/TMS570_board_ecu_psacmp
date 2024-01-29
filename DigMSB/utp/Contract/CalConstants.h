/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          3 %
* %derived_by:       nzt9hv %
* %date_modified:    Tue Dec  3 09:39:07 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H



#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 5/1/2014 2:45:14 PM *******************/
/****************************** DigMSB - Rev 11 ******************************/


extern CONST(uint8, CAL_CONST) k_Die1RPMMode_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_Die2RPMMode_Cnt_u08;
extern CONST(DiagSettings_Str, CAL_CONST) k_DigMSBParity_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DigMSBTCRunTimeParity_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_ErrorRegTCAcc_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPos1vsMtrPos2Diag_Cnt_str;
extern CONST(float32, CAL_CONST) k_Die1vsDie2TrnsCntrThresh_Deg_f32;
extern CONST(uint16, CAL_CONST) k_Die2Offset_Rev_u3p13;
extern CONST(uint16, CAL_CONST) k_MtrPos1vsMtrPos2Thresh_Rev_u3p13;
extern CONST(uint8, CAL_CONST) k_DigMSBErrorRegGenMask_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_ErrorRegTCMask_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_ErrorRegVehMask_Cnt_u08;
extern CONST(float32, CAL_CONST) k_TurnsCntrOffset_Rev_f32;
#endif
