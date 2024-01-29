/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Interrupts.c
* Module Description: Interrupt Enable/Disable Interface
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
 * 12/19/16   3       RA        Added CAN interrupt disable/enable functions                                     13252
 */

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "CDD_Const.h"
#include "rti_regs.h"
#include "vim_regs.h"
#include "Os.h"

/* TODO: Generate the ISR priority defines based on the Os Config in the ECUC file.
 *			The priorities must be manually entered in the following set of defines
 *			to match the configuration in the Os.
 */
#define DCAN1_LEVEL0_INT	16u
#define ISR_MTRCTRL_INT		2u
#define RTI_COMP0_INT		4u
#define ESML_INT			20u
#define CRC_INT				19u
#define OVERVOLTTHRESH_INT	31u

/*****************************************************************************
* Local Functions
*****************************************************************************/
STATIC FUNC(void, INTERRUPT_CODE) EnableIrq(uint8 irqRequest);
STATIC FUNC(void, INTERRUPT_CODE) DisableIrq(uint8 irqRequest);

FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void)
{
	_enable_FIQ();
}
/*****************************************************************************
* Global Interrupt Enable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) EnableCanInterrupt(void)
{
	EnableIrq(DCAN1_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void)
{
	EnableIrq(ISR_MTRCTRL_INT);
}

FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void)
{  
	EnableIrq(RTI_COMP0_INT);  
}

FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void)
{
	EnableIrq(ESML_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void)
{
	EnableIrq(CRC_INT);
}

FUNC(void, INTERRUPT_CODE) EnableOverVoltThreshInterrupt(void)
{
	EnableIrq(OVERVOLTTHRESH_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCan1Interrupt(void)
{
	EnableIrq(DCAN1_LEVEL0_INT);
}
/*****************************************************************************
* Global Interrupt Disable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void)
{
	DisableIrq(ISR_MTRCTRL_INT);
}

FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void)
{
	DisableIrq(RTI_COMP0_INT);
}
FUNC(void, INTERRUPT_CODE) DisableCan1Interrupt(void)
{
	DisableIrq(DCAN1_LEVEL0_INT);
}

/*****************************************************************************
* Global Interrupt Clear Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) ClearSysTickInterruptFlg(void)
{
	osWritePeripheral32(OS_MEM_AREA_RTI, (osuint32)&(rtiREG1->INTFLAG), 0xFFFFFFFFU);
	osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->INTREQ0), 0x00000010U);
}


/*****************************************************************************
* Local Functions
*****************************************************************************/

/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
STATIC FUNC(void, INTERRUPT_CODE) EnableIrq(uint8 irqRequest)
{
  if (irqRequest < 32) {  	
	  osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET0), ( ((osuint32)1) << (irqRequest)));
  } else {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET1), ( ((osuint32)1) << (irqRequest)));
  }
}

/*****************************************************************************
  * Name:        DisableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
STATIC FUNC(void, INTERRUPT_CODE) DisableIrq(uint8 irqRequest)
{
  if (irqRequest < 32) {
	  osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR0), ( ((osuint32)1) << (irqRequest)));
  } else {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR1), ( ((osuint32)1) << (irqRequest)));
  }
}

