/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupts external definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * %version:          2 %
 * %derived_by:       nzx5jd %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 02/14/14   1       OT        Initial version
 * 10/31/14   2       OT        Added disable systick interrupt for F0FF service                                 12655
 */


#ifndef INTERRUPTS_H
#define INTERRUPTS_H


#include "tcb.h"


FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void);
FUNC(void, INTERRUPT_CODE) EnableCanInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableOverVoltThreshInterrupt(void);
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void);
FUNC(void, INTERRUPT_CODE) ClearSysTickInterruptFlg(void);
FUNC(void, INTERRUPT_CODE) DisableCan1Interrupt(void);
FUNC(void, INTERRUPT_CODE) EnableCan1Interrupt(void);


#endif
