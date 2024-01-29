/*****************************************************************************
* Copyright 2016 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_PhaseAbcFdbkMeas.h
* Module Description: Nhet1 Configuration and Use global header file
* Product           : Gen II Plus - EA3.0
* Author            : Avinash James 
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue May 17 10:56:00 2016 %
 * %version:          1 %
 * %derived_by:       rzk04c %
 * %date_modified:    Tue May 17 10:56:00 2016 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/17/16  1        AJM       Nhet1 Configuration and Use, implementation of FDD_36B						 EA3#8295
 */



#ifndef CD_PHASEFDBKMEAS_H
#define CD_PHASEFDBKMEAS_H


#include "PhaseAbcFdbkMeas.h"
#include "Std_Types.h"
#include "n2het_regs.h"
#include "std_nhet.h"


/* Global PhaseFdbkMeas Functions for Nhet1 initialization */
FUNC(void, CD_PHASEABCFDBKMEAS_CODE) Cd_PhaseAbcFdbkMeas_Init1(void);


#endif
