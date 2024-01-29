/*****************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : ePWM_Cfg_Template.h
* Module Description: This is a template for the manual configuration file needed for the ePWM component
* Product           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* %version:          1 %
* %derived_by:       jzk9cc %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 08/20/15    1		 Rijvi		Changed macros needed for ES34E rev.001								            EA3#1300
******************************************************************************/

#ifndef EPWM_CFG_H
#define EPWM_CFG_H

#include "Std_Types.h"


#define ePWM_Read_PWMPeriod_u16(ptr)  (*ptr) =    	/* fill in variable to read for PWM period Pwm time period   */

#define  ePWM_Read_DCPhsAComp_u16(ptr) (*ptr) =   	/* fill in variable to read for Phase A Duty Cycle counts  */
#define  ePWM_Read_DCPhsBComp_u16(ptr) (*ptr) =   	/* fill in variable to read for Phase B Duty Cycle counts  */
#define  ePWM_Read_DCPhsCComp_u16(ptr)  (*ptr) =  	/* fill in variable to read for Phase C Duty Cycle counts  */ 
#define  ePWM_Read_ePWM4CMPB_Cnt_u16(ptr)     (*ptr) =      /* fill in variable to read for ePWM4 CMPB counts */

/*  the following macros need to be defined for where the ePWM CMPA and CMPB counts should be written
	for example, if DMA is used for the data for all four ePWMs, all eight macros should be defined to 
	copy the value to the appropriate DMA data structure(s)   */
#define  ePWM_Write_ePWM1CMPA_Cnt_u16(val)	   
#define  ePWM_Write_ePWM1CMPB_Cnt_u16(val)
#define  ePWM_Write_ePWM2CMPA_Cnt_u16(val)
#define  ePWM_Write_ePWM2CMPB_Cnt_u16(val)
#define  ePWM_Write_ePWM3CMPA_Cnt_u16(val)
#define  ePWM_Write_ePWM3CMPB_Cnt_u16(val)
#define  ePWM_Write_ePWM4CMPA_Cnt_u16(val)
#define  ePWM_Write_ePWM4CMPB_Cnt_u16(val)
 

#endif

