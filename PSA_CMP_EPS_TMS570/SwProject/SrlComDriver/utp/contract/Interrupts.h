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
 * %version:          1 %
 * %derived_by:       tzyksv %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 12/19/16   1       RA        Added CAN interrupt disable/enable functions                                     13252

 */


#ifndef INTERRUPTS_H
#define INTERRUPTS_H


FUNC(void, INTERRUPT_CODE) DisableCan1Interrupt(void);
FUNC(void, INTERRUPT_CODE) EnableCan1Interrupt(void);


#endif
