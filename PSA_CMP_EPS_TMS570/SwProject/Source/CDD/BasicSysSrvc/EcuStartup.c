/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.c
* Module Description: AUTOSAR Startup Sequence
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*******************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.c
* Module Description: AUTOSAR Startup Sequence
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*******************************************************************************/
/*******************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       fzh7xw %
*******************************************************************************/
/*******************************************************************************
* Change History:
* Date      Rev      Author    Change Description
* --------  -------  --------  ------------------------------------------------
* 02/14/14   1       OT        Initial version
* 06/03/14   2       OT        Removed references to CanXcp for updated SIP
* 07/14/14   3       OT        Integrated GliwaT1
* 07/15/14   4       OT        Integrated Dma
* 09/25/14   5       OT        Updates for electronic integration
* 10/20/14   6       OT        Updates for split appdesc init function
* 04/15/15   7       OT        Added suspend/resume functionality
* 09/15/15   8       OT        Added uDiagPeriphMPU_Init call
* 07/28/16   9       WH        Updated for the new NHET component              EA3#9275
*******************************************************************************/


/*******************************************************************************
* Include files
*******************************************************************************/

#include "Metrics.h"
#include "Os.h"
#include "EcuM.h"

#include "Nhet.h"
#include "Ap_DfltConfigData.h"
#include "Interrupts.h"
#include "SystemTime.h"
#include "Dma.h"
#include "FlsTst.h"
#include "Lnk_Symbols.h"
#include "CDD_Func.h"
#include "Dem.h"
#include "ePWM.h"
#include "Gpt.h"
#include "Port.h"
#include "Fee.h"
#include "ApplCallbacks.h"
#include "Cd_FeeIf.h"
#include "SpiNxt.h"
#include "Ap_ApXcp.h"
#include "NtWrap.h"
#include "uDiag.h"
#include "il_inc.h"
#include "tpmc.h"
#include "XcpProf.h"
#include "desc.h"
#include "appdesc.h"
#include "ti_fee.h" /* Required for suspend/resume erase API */
#include "Cd_PhaseAbcFdbkMeas.h"

extern boolean Rte_SrlComInput_ElecIntData;
extern VAR(ManufModeType, EPSDIAGSRVC_VAR) NxtrMEC_Uls_G_enum;

/*******************************************************************************
  * Name:        main
  * Description: 
  * Inputs:      None 
  * Outputs:     None
  *
*******************************************************************************/
int main(void)
{
	T1_AppInit();
	osInitialize();
	EcuM_Init();
}


/*******************************************************************************
  * Name:        EcuStartup_Init1
  * Description: Initialization executed prior to OS start  
  * Inputs:      None 
  * Outputs:     None
  *
*******************************************************************************/
void EcuStartup_Init1(void) 
{
	Dem_PreInit();
	Dma_Init();
	FlsTst_Init(&FlsTst_Runtime);
	uDiagCCRM_Init();
	uDiagClockMonitor_Init();
	uDiagECC_Init();
	uDiagESM_Init();
	uDiagIOMM_Init();
	uDiagParity_Init();
	uDiagPeriphMPU_Init();
	uDiagStaticRegs_Init();
	uDiagVIM_Init();
	Nhet1CfgAndUse_Init();
	Cd_PhaseAbcFdbkMeas_Init1();
	ePWM_Init1();
	SpiNxt_Init();
	Dma_SetupMtrCtrlGroups();
}


/*******************************************************************************
  * Name:        EcuStartup_Init2
  * Description: Initialization executed after OS start, prior to RTE start
  * Inputs:      None 
  * Outputs:     None
  *
*******************************************************************************/
void EcuStartup_Init2(void)
{
	ApXcp_Init();
	Gpt_Init(&Gpt_Runtime);
	SystemTime_Init();
	TWrapC_Adc_Init(NULL_PTR);
	TWrapC_Adc2_Init1();
	TWrapC_PwmCdd_Init();
	Gpt_EnableNotification(SystemTime_uS);
	EnableCRCInterrupt();
	TWrapC_FeeIf_Init();
	Port_Init(&Port_Runtime);
	NvM_Init();
	TWrapC_TI_Fee_SuspendResumeErase(Suspend_Erase);
	NvM_ReadAll();
	Appl_WaitNvMReady(0, TRUE);
	TWrapC_TI_Fee_SuspendResumeErase(Resume_Erase);
	TWrapC_StaMd_Init0();
	DfltConfigData_Init1();
	TWrapC_NvMProxy_Init();
    EnableOverVoltThreshInterrupt();
	Dem_Init();
	if( Rte_SrlComInput_ElecIntData == TRUE )
	{
		Dem_DisableEventStatusUpdate(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
	}
	CanInitPowerOn();
	IlInitPowerOn();
	TpInitPowerOn();
	XcpInit();
	if (ProductionMode == NxtrMEC_Uls_G_enum)
	{
		XcpControl(kXcpControl_Disable);
	}
	DescInitPowerOn(kDescPowerOnInitParam);
	AppDesc_Init1();
	EnableCanInterrupt();
}

