/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SchM.c
* Module Description: AUTOSAR BSW Scheduler
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*******************************************************************************
* Version Control:
* Date Created:      Wed Jul 17 12:00:00 2013
* %version:          3 %
* %derived_by:       nzx5jd %
* %date_modified:    Wed Feb 26 16:42:47 2014 %
*******************************************************************************/
/*******************************************************************************
* Change History:
* Date      Rev      Author    Change Description                          CR#
* --------  -------  --------  -----------------------------------------  -----
* 02/14/14   1       OT        Initial version
* 07/14/14   2       OT        Integrated GliwaT1
* 08/21/14   3       OT        Updates for new MPU configuration          12249
*******************************************************************************/


#include "Std_Types.h"
#include "Os.h"
#include "Interrupts.h"

#include "Cd_NvMProxy.h"
#include "Dem.h"
#include "EcuM.h"
#include "fee.h"
#include "FlsTst.h"
#include "Metrics.h"
#include "NtWrap.h"
#include "NvM.h"
#include "Rte_Ap_StaMd6.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"


TASK(Task_SchM_100ms_0)
{
	Fee_MainFunction();
	TerminateTask();
}


TASK(Task_SchM_100ms_6)
{
	NvMProxy_MainFunction();
	NvM_MainFunction();
	TerminateTask();
}


TASK(Task_SchM_10ms_6)
{
	T1_AppHandler();
	EcuM_MainFunction();
	Dem_MainFunction();
	TerminateTask();
}


TASK(Task_SchM_4ms_0)
{
	WdgM_MainFunction();
	FlsTst_MainFunction();
	TerminateTask();
}


TASK(Task_SchM_Trns_6)
{
	StaMd6_Trns_DemShutdown();
	TerminateTask();
}


TASK(Task_SchM_Init_6)
{
	GetResource(RES_SCHEDULER);
	EcuM_StartupTwo();
	TWrapC_Wdg_TMS570LS3x_Init(&wdg_tms570ls3x_config);
	TWrapC_WdgM_Init(&WdgMConfig_Mode0);
	ReleaseResource(RES_SCHEDULER);
	ClearSysTickInterruptFlg();
	EnableSysTickInterrupt();
	TerminateTask();
}


TASK(Task_Bkgnd)
{
	while( TRUE )
	{
		T1_AppBgHandler();
	}
}

