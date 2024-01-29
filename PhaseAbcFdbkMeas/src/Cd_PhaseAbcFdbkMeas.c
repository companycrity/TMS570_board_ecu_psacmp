/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Cd_PhaseAbcFdbkMeas.c
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/PhaseAbcFdbkMeas/autosar
 *     SW-C Type:  Cd_PhaseAbcFdbkMeas
 *  Generated at:  Tue May 17 14:46:49 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Cd_PhaseAbcFdbkMeas>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2016 Nexteer
* Nexteer Confidential
*
* Module File Name  : Cd_PhaseAbcFdbkMeas.c
* Module Description: Phase ABC Feedback Measurement, implementation of ES36B-FDD
* Project           : CBD
* Author            : Avinash James
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue May 17 10:56:00 2016 %
 * %version:          1 %
 * %derived_by:       rzk04c %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/17/16  1        AJM       Nhet1 Configuration and Use, implementation of FDD_36B						 EA3#8295
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Cd_PhaseAbcFdbkMeas.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Cd_PhaseAbcFdbkMeas.h"
#include <string.h>  /* provide memset() and memcpy() definitions */

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

/* PRQA S 303 EOF 
 * MISRA-C:2004 Rule 11.3: This deviation is required for register access.  The rule is suppressed for the entire file */

/* PRQA S 312 EOF 
 * MISRA-C:2004 Rule 11.5: This deviation is required for memcpy of the NHET code into the NHETs.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */



#define D_PHASEA_CNT_U8  				0U 
#define D_PHASEB_CNT_U8 				1U
#define D_PHASEC_CNT_U8 				2U

#define D_PXACCUMMAX_CNT_U32			536870911UL


#define PHASEABCFDBKMEAS_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, CD_PHASEABCFDBKMEAS_VAR)  PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[3];
STATIC VAR(uint32, CD_PHASEABCFDBKMEAS_VAR)  PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[3]; 
#define PHASEABCFDBKMEAS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */




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
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cd_PhaseAbcFdbkMeas_Init2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Init2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cd_PhaseAbcFdbkMeas_Init2
 *********************************************************************************************************************/
	PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[D_PHASEA_CNT_U8] = HET_P1ACC_1.memory.data_word >>3U;
	PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[D_PHASEB_CNT_U8] = HET_P2ACC_1.memory.data_word >>3U;
	PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[D_PHASEC_CNT_U8] = HET_P3ACC_1.memory.data_word >>3U;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cd_PhaseAbcFdbkMeas_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cd_PhaseAbcFdbkMeas_Per1
 *********************************************************************************************************************/

	VAR(uint8, AUTOMATIC) i;
	VAR(uint32, AUTOMATIC) MeasuredOnTime_Cnt_T_u32[6];

	for(i = D_PHASEA_CNT_U8; i <= D_PHASEC_CNT_U8; i++)
	{
		if(PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[i] < PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[i])
		{
			MeasuredOnTime_Cnt_T_u32[i] = (uint32)((D_PXACCUMMAX_CNT_U32 - PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[i]) + PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[i] + 1U);
		}
		else
		{
			MeasuredOnTime_Cnt_T_u32[i] = PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[i] - PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[i];
		}

		PhaseAbcFdbkMeas_PhaseXPrevFdbk_Cnt_M_u32[i] = PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[i];
	}


    Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEA_CNT_U8]);
    Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEB_CNT_U8]);
    Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U8]);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Get_PhaseAbcFdbkMeas_PhaseFdbk
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PhaseFdbk> of PortPrototype <Get_PhaseFdbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Get_PhaseAbcFdbkMeas_PhaseFdbk(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Get_PhaseAbcFdbkMeas_PhaseFdbk(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Get_PhaseAbcFdbkMeas_PhaseFdbk
 *********************************************************************************************************************/
	PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[D_PHASEA_CNT_U8] = HET_P1ACC_1.memory.data_word >>3U;
	PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[D_PHASEB_CNT_U8] = HET_P2ACC_1.memory.data_word >>3U;
	PhaseAbcFdbkMeas_PhaseXFdbk_Cnt_M_u32[D_PHASEC_CNT_U8] = HET_P3ACC_1.memory.data_word >>3U;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*****************************************************************************
  * Name:        Cd_PhaseAbcFdbkMeas_Init1
  * Description: NHET 1 primary initialization 
  * Inputs:      None
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, PHASEABCFDBKMEAS_CODE) Cd_PhaseAbcFdbkMeas_Init1(void)      /*Non-RTE init function*/
{


	/* Start initialization of NHET 1 Peripheral */
	NHET1->NHETGCR =
			(uint32)	(0UL << 24U) | /* L added to remove error */     /* 0: Disable channel disable feature */
			(uint32)	(0UL << 18U) | /* 0: All masters can read and write the program fields.. */
			(uint32)	(1UL << 17U) | /* 1: NHET doesn't stop when a software breakpoint is encountered.*/
			(uint32)	(1UL << 16U) | /* 1: NHET is master */
			(uint32)	(0UL << 0U);   /* 0: Stop NHET */


	if ((NHET1->NHETGCR & 0x1U) == 0U)
	{

		/* copy the HET1 program */
		(void)	memcpy((void *) &e_HETPROGRAM1_UN, (const void *) HET_INIT1_PST, sizeof(HET_INIT1_PST)); /* PRQA S 312 */


		NHET1->NHETPFR =			/* Timer Prescale */
			(uint32) (4UL << 8U) | 	/* 7 -> lr=16 */
			(uint32) (0UL << 0U);   /* 0 -> hr=1 */
						            /* ts = 16*1 = 16 */

		NHET1->NHETINTENAC 	= (uint32)(0xFFFFFFFFUL);  /* NHETINTENAC is a 32 bit register */	/* Disable all interrupts */
		NHET1->NHETEXC1 	= 0U;					   /* Disable exceptions */
		NHET1->NHETPRY  	= 0U;					   /* Interrupt priority level 2 */
		NHET1->NHETAND  	= 0U;					   /* No channels are AND shared */
		NHET1->NHETXOR  	= 0U;					   /* No channels are XOR shared */		
		NHET1->NHETDIR   	= 0U;					   /* All channels are inputs */
		NHET1->NHETPULDIS 	= 0U;					   /* Pull functionality enabled on all channels */
		NHET1->NHETPCR 		= 0xAU;					   /* Disable parity bit mapping, enable parity checking */
		NHET1->NHETPPR 		= 0U;					   /* No channels are affected by a parity error */

		NHET1->NHETSFPRLD =					/* Set suppression filter to 1.7us */
			(uint32) (0x0UL  << 16U) | 		/* L added to remove qac error  */ /* Scaling factor of 1 */
			(uint32) (0x6UL << 0U);   		/* Counter preload value */
											/* 0x6 * 1 * 12.5ns = 0.075us */


		NHET1->NHETSFENA  = (uint32)(0x000FCF03UL);   /* Enable suppression Filter */
		NHET1->NHETPINDIS = 0U;				          /* Output buffer enable is controlled by HETDIR */
   
		(NHET1->NHETGCR  |= 0x01U);                   /* Enable NHET */
		
	}
	/* End initialization of NHET 1 Peripheral */

}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
