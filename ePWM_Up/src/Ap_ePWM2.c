/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ePWM2.c
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/ePWM_Up/autosar
 *     SW-C Type:  Ap_ePWM2
 *  Generated at:  Tue May  3 15:07:31 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ePWM2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2015, 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name: Ap_ePWM2.c
* Module Description: Implements the "Motor Control Configuration Override" subfunction of ES-34E
* Project           : CBD   
* Author            : Yue Zhao
*****************************************************************************
* Version Control:
* Date Created:      Thr Jun 18 16:19:40 2015
* %version:          2 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                               SCR #
* -------   -------  --------  -------------------------------------------------------------------------------  ------
* 06/18/15  1        Yue Zhao        Initial Version (ePWM - FDD 34E v001)										EA3#1300
* 04/29/16  2        AJM			 Updated the input variables to match the m file							EA3#8022
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_ePWM2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "ePwm.h"
#include "GlobalMacro.h"

/* PRQA S 303 EOF 
 * MISRA-C:2004 Rule 11.3: This deviation is required for register access.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_EPWM2_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_ePWM2_Per1_CtrldDmpStsCmp_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_DiagStsCtrldDisRmpPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ePWM2_Per1
 *********************************************************************************************************************/

    VAR(boolean, AUTOMATIC) CtrldDmpStsCmp_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DiagStsCtrldDisRmpPres_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) RampDwnStatusComplete_Cnt_T_lgc;

	/* implements the "ePWM Control Shutdown" portion of   "Motor Control Configuration Override" Subfunction */
	DiagStsCtrldDisRmpPres_Cnt_T_lgc = Rte_IRead_ePWM2_Per1_DiagStsCtrldDisRmpPres_Cnt_lgc();
	DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc = Rte_IRead_ePWM2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc();
	RampDwnStatusComplete_Cnt_T_lgc = Rte_IRead_ePWM2_Per1_RampDwnStatusComplete_Cnt_lgc();
	CtrldDmpStsCmp_Cnt_T_lgc = Rte_IRead_ePWM2_Per1_CtrldDmpStsCmp_Cnt_lgc();
	
	/* condition to disable ePWM output */
	/* disable when "OR" condition is true; equivalent to FDD's "Logic output is 0" from NOR gate */
	if (((RampDwnStatusComplete_Cnt_T_lgc == TRUE) && (DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc == TRUE))
		|| ((CtrldDmpStsCmp_Cnt_T_lgc == TRUE) && (DiagStsCtrldDisRmpPres_Cnt_T_lgc == TRUE)))
	{
		ePWM_DisableOutputs()
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ePWM2_Trns1
 *********************************************************************************************************************/
/* implements the "ePWM gate outputs are enable ON entering to operate state" portion of   "Motor Control
   Configuration Override" subfunction */
 
 ePWM_EnableOutputs() 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ePWM2_Trns2
 *********************************************************************************************************************/

/* implements the "ePWM gate outputs are disable if function leaves operate state" portion of   "Motor Control
   Configuration Override" subfunction */
   
 ePWM_DisableOutputs()

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_EPWM2_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
