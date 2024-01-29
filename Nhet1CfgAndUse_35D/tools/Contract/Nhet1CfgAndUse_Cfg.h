/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: ES-35B (Nhet1 configuration and use)
* Product           : CBD
* Author            : Yue Zhao
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Wed Jun 10 09:35:16 2015
* %version:          1 %
* %derived_by:       rzk04c %
* %date_modified:    Wed Jun 10 15:29:28 2015 %
*---------------------------------------------------------------------------*/
#ifndef NHET1CFGANDUSE_CFG_H
#define NHET1CFGANDUSE_CFG_H


#include "Std_Types.h"

extern uint16 A;
extern volatile uint16 B;

#define Nhet1CfgAndUse_Read_PWMPeriod_u16(ptr)  (*ptr)= A  /* Pwm time period  and must be equal to Read_EPWM_PWMPeriod_u16 */



#define Nhet1CfgAndUse_Write_PWMPeriod_Cnt_u16(val)	 B = val


#endif
