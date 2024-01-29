/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ePWM.h
* Module Description: implement of FDD ePWM-34E
* Product           : Gen II Plus - EA3.0
* Author            : Yue Zhao
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thr Jun 18 16:19:40 2015
* %version:          1 %
* %derived_by:       jzk9cc %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                               SCR #
* -------   -------  --------  -------------------------------------------------------------------------------  ------
* 06/18/15  1        Yue Zhao        Initial Version (ePWM - FDD 34E v001)										EA3#1300
******************************************************************************/


#ifndef EPWM_H
#define EPWM_H

#include "epwm_regs.h"

FUNC(void, EPWM_CODE) ePWM_Init1(void);
FUNC(void, EPWM_CODE) ePWM_Per1(void);


/* Disable PWM Outputs */
#define ePWM_DisableOutputs()        \
{                                    \
	ePWM1->AQCSFRC = 5U;         \
	ePWM1->DBCTL &= 0xFFFCU; \
	ePWM2->AQCSFRC = 5U;         \
	ePWM2->DBCTL &= 0xFFFCU; \
	ePWM3->AQCSFRC = 5U;         \
	ePWM3->DBCTL &= 0xFFFCU; \
}


/* Enable PWM Outputs */
#define ePWM_EnableOutputs() \
{                            \
	ePWM1->AQCSFRC = 0U; \
	ePWM1->DBCTL |= 3U;  \
	ePWM2->AQCSFRC = 0U; \
	ePWM2->DBCTL |= 3U;  \
	ePWM3->AQCSFRC = 0U; \
	ePWM3->DBCTL |= 3U;  \
}


#endif  /* end of EPWM_H definition */
