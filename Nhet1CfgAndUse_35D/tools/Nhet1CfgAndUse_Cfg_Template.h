/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Cd_Nhet1CfgAndUse.c
* Module Description: ES-35D (Nhet1 configuration and use) branched out from ES-35C
* Project           : CBD   
* Author            : Avinash James 
*****************************************************************************/
/* Version Control:
 * Date Created:      Thr Jun 16 08:50:22 2016 %
 * %version:          1 %
 * %derived_by:       rzk04c %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/19/16  1        AJM       Nhet1 Configuration and Use, implementation of FDD_35D						 EA3#9625
 *********************************************************************************************************************/

#ifndef NHET1CFGANDUSE_CFG_H
#define NHET1CFGANDUSE_CFG_H



#include "Std_Types.h"



#define Nhet1CfgAndUse_Read_PWMPeriod_u16(ptr)  (*ptr)=   /* Pwm time period  Global variable */


/*  the following macro needs to be defined for where the PWM Period counts for the NHET should be written
	for example, if DMA is used to write PWM period to the NHET, the macro should be defined to 
	copy the value to the appropriate DMA data structure   */

	
#define Nhet1CfgAndUse_Write_PWMPeriod_Cnt_u16(val)	 

#endif

