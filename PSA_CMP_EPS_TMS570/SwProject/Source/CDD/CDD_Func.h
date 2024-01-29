/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Func.h
* Module Description: Header file for functions communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Jul 17 10:00:00 2013
 * %version:          2 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Wed Feb 26 16:30:41 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 02/14/14   1       OT        Initial version
 * 06/10/14   2       OT        Updates for QAC errors
 */

#ifndef CDD_FUNC_H
#define CDD_FUNC_H

#include "Std_Types.h"

extern FUNC(void, RTE_AP_MICRODIAG_APPL_CODE) MicroDiag_Per1(void);
extern FUNC(void, PWMCDD_CODE) CDD_ApplyPWMMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8);
extern FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ApplyMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8);

/* TODO: Determine if the  CalRamInit really needs to execute as a CDD early in init */
/*        if it is determined that RAM cals are only used after RTE Start, then this */
/*        function can be removed from here and scheduled in Developer               */
extern FUNC(void, XCP_CODE) Xcp_CalRamInit(void);

#endif
