/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ePWM.h
* Module Description: implement of FDD ePWM-34E
* Product           : Gen II Plus - EA3.0
* Author            : Yue Zhao
*****************************************************************************/


/* Version Control:
* Date Created:      Thr Jun 18 16:19:40 2015
* %version:          2 %
* %derived_by:       czmgrw %
*-----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                               SCR #
* -------   -------  --------  -------------------------------------------------------------------------------  --------
* 06/18/15  1        Yue Zhao        Initial Version (ePWM - FDD 34E v001)										EA3#1300
* 09/22/15  2        JK              Anomaly fix EA3#3088 - incorrectly computes CmpBPhaseX(ePWM FDD34E v002)   EA3#3250
*/

#include "ePwm.h"
#include "ePWM_Cfg.h" 
#include "CalConstants.h"



/* MISRA-C:2004 Rule 10.3: This deviation is required for Library Exception.  The rule is suppressed by line at each occurrence */

/* PRQA S 303 EOF 
 * MISRA-C:2004 Rule 11.3: This deviation is required for register access.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */

#define D_PHSAIDX_CNT_U16  0U
#define D_PHSBIDX_CNT_U16  1U
#define D_PHSCIDX_CNT_U16  2U



 
#define EPWM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

/******************************************************************************
  * Name:        ePWM_Init1
  * Description: Implements ePWM: Core Configuration subfunction
  * Inputs:      None 
  * Outputs:     None 
  * Usage Notes:  Called from ECU Startup; register access must be performed in privilege mode
  ****************************************************************************/
FUNC(void, EPWM_CODE) ePWM_Init1(void)
{
	
	/* Initialize ePWM1 */
	
	ePWM1->TBCTL = (0U)         /* Counter Mode:                               Up */
				 |  ((uint16)1U << 2U)   /* Counter Register Load from phase register:  Enabled */
				 | ((uint16)0U << 3U)   /* Use shadow period register:                 Enabled */
				 | ((uint16)0U << 4U)   /* Sync Output Select:                         Sync In */
				 | ((uint16)0U << 7U)   /* High Speed Clock Prescale:                  1:1 */
				 | ((uint16)0U << 10U)  /* Clock Prescale:                             1:1 */
				 | ((uint16)1U << 13U); /* Phase Direction Bit:                        Count Up */
	
	ePWM1->TBPRD = 0xFFFFU; /* Set to Max period as period is set by NHET*/
	
	ePWM1->TBPHS = 0U; /* Reset to zero on sync */
	
	ePWM1->CMPA = 2499U; /* Init duty cycle of 0% */
	ePWM1->CMPB = 2499U; /* Init duty cycle of 0% */
	
	ePWM1->CMPCTL = (0U)        /* Counter A Shadow Load Mode:  CTR = zero */
				  | ((uint16)0U << 2U)	/* Counter B Shadow Load Mode:  CTR = zero */ 
				  | ((uint16)0U << 4U)  /* Counter A Shadow Mode:       Enabled */
				  | ((uint16)0U << 6U); /* Counter B Shadow Mode:       Enabled */
	
	ePWM1->AQCTLA = (1U)         /* CTR = zero:                Clear */
				  | ((uint16)0U << 2U)   /* CTR = PRD:                 Do Nothing */
				  | ((uint16)2U << 4U)   /* CTR = CMPA, incrementing:  Set */
				  | ((uint16)0U << 6U)   /* CTR = CMPA,   :Do Nothing */
				  | ((uint16)1U << 8U)   /* CTR = CMPB,   :  Clear */
				  | ((uint16)0U << 10U); /* CTR = CMPB,   :Do Nothing */
	
	ePWM1->DBCTL = (3U)         /* Out Mode:         Enable both RED and FED */
				 | ((uint16)2U << 2U)   /* Polarity Select:  Invert B */
				 | ((uint16)0U << 4U)   /* In Mode:          Use A for both RED and FED outputs*/
				 | ((uint16)0U << 15U); /* Half Cycle:       Use TBCLK rate for DB */
	
	ePWM1->DBRED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM1->DBFED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM1->PCCTL = 0U; /* Disable chopper */
	
	ePWM1->TZCTL = 0x0FFFU; /* Do nothing on all trip-zone conditions */
	
	ePWM1->ETSEL= 0U; /* Disable all events */
	
	
	/* Initialize ePWM2 */
	
	ePWM2->TBCTL = (0U)         /* Counter Mode:                               Up*/
				 | ((uint16)1U << 2U)   /* Counter Register Load from phase register:  Enabled */
				 | ((uint16)0U << 3U)   /* Use shadow period register:                 Enabled */
				 | ((uint16)0U << 4U)   /* Sync Output Select:                         Sync In */
				 | ((uint16)0U << 7U)   /* High Speed Clock Prescale:                  1:1 */
				 | ((uint16)0U << 10U)  /* Clock Prescale:                             1:1 */
				 | ((uint16)1U << 13U); /* Phase Direction Bit:                        Count Up */
	
	ePWM2->TBPRD = 0xFFFFU; /*Set to Max period as period is set by NHET */
	
	ePWM2->TBPHS = 0U; /* Reset to zero on sync */
	
	ePWM2->CMPA = 2499U; /* Init duty cycle of 0% */
	ePWM2->CMPB = 2499U; /* Init duty cycle of 0% */
	
	ePWM2->CMPCTL = (0U)        /* Counter A Shadow Load Mode:  CTR = zero */
				  | ((uint16)0U << 2U)	/* Counter B Shadow Load Mode:  CTR = zero */ 
				  | ((uint16)0U<< 4U)  /* Counter A Shadow Mode:       Enabled */
				  | ((uint16)0U << 6U); /* Counter B Shadow Mode:       Enabled */
	
	ePWM2->AQCTLA = (0U)         /* CTR = zero:                Do Nothing */
				  | ((uint16)0U << 2U)   /* CTR = PRD:                 Do Nothing */
				  | ((uint16)2U << 4U)   /* CTR = CMPA, incrementing:  Set */
				  | ((uint16)0U << 6U)   /* CTR = CMPA, 			:  Do nothing*/
				  | ((uint16)1U << 8U)   /* CTR = CMPB, 			:  Clear*/
				  | ((uint16)0U << 10U); /* CTR = CMPB, 			:  Do Nothing */
	
	ePWM2->DBCTL = (3U)         /* Out Mode:         Enable both RED and FED */
				 | ((uint16)2U << 2U)   /* Polarity Select:  Invert B */
				 | ((uint16)0U << 4U)   /* In Mode:          Use A for both RED and FED outputs */
				 | ((uint16)0U << 15U); /* Half Cycle:       Use TBCLK rate for DB */
	
	ePWM2->DBRED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM2->DBFED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM2->PCCTL = 0U; /* Disable chopper */
	
	ePWM2->TZCTL = 0x0FFFU; /* Do nothing on all trip-zone conditions */
	
	ePWM2->ETSEL= 0U; /* Disable all events */
	
	
	/* Initialize ePWM3 */
	
	ePWM3->TBCTL = (0U)         /* Counter Mode:                               Up */
				 | ((uint16)1U << 2U)   /* Counter Register Load from phase register:  Enabled */
				 | ((uint16)0U << 3U)   /* Use shadow period register:                 Enabled */
				 | ((uint16)0U << 4U)   /* Sync Output Select:                         Sync In */
				 | ((uint16)0U << 7U)   /* High Speed Clock Prescale:                  1:1 */
				 | ((uint16)0U << 10U)  /* Clock Prescale:                             1:1 */
				 | ((uint16)1U << 13U); /* Phase Direction Bit:                        Count Up */
	
	ePWM3->TBPRD = 0xFFFFU; /* Set to Max period as period is set by NHET*/
	
	ePWM3->TBPHS = 0U; /* Reset to zero on sync */
	
	ePWM3->CMPA = 2499U; /* Init duty cycle of 0% */
	ePWM3->CMPB = 2499U; /* Init duty cycle of 0% */
	
	ePWM3->CMPCTL = (0U)        /* Counter A Shadow Load Mode:  CTR = zero */
				  | ((uint16)0U << 2U)	/* Counter B Shadow Load Mode:  CTR = zero */ 
				  | ((uint16)0U << 4U)  /* Counter A Shadow Mode:       Enabled */
				  | ((uint16)0U << 6U); /* Counter B Shadow Mode:       Enabled */
	
	ePWM3->AQCTLA = (0U)         /* CTR = zero:                Do Nothing */
				  | ((uint16)0U << 2U)   /* CTR = PRD:                 Do Nothing */
				  | ((uint16)2U << 4U)   /* CTR = CMPA, incrementing:  Set */
				  | ((uint16)0U << 6U)   /* CTR = CMPA,               Do Nothing */
				  | ((uint16)1U << 8U)   /* CTR = CMPB, 			  Clear */
				  | ((uint16)0U << 10U); /* CTR = CMPB, 			  Do Nothing */
	 
	ePWM3->DBCTL = (3U)         /* Out Mode:         Enable both RED and FED */
				 | ((uint16)2U << 2U)   /* Polarity Select:  Invert B */
				 | ((uint16)0U << 4U)   /* In Mode:          Use A for both RED and FED outputs */
				 | ((uint16)0U << 15U); /* Half Cycle:       Use TBCLK rate for DB */
	
	ePWM3->DBRED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM3->DBFED = k_PwmDeadBand_Cnt_u16; /* Initialized with a cal */
	
	ePWM3->PCCTL = 0U; /* Disable chopper */
	
	ePWM3->TZCTL = 0x0FFFU; /* Do nothing on all trip-zone conditions */
	
	ePWM3->ETSEL = 0U; /* Disable all events */
	
	
	/* Initialize ePWM4 */
	
	ePWM4->TBCTL = (0U)         /* Counter Mode:                               Up */
				 | ((uint16)1U << 2U)   /* Counter Register Load from phase register:  Enabled */
				 | ((uint16)0U << 3U)   /* Use shadow period register:                 Enabled */
				 | ((uint16)0U << 4U)   /* Sync Output Select:                         Sync In */
				 | ((uint16)0U << 7U)   /* High Speed Clock Prescale:                  1:1 */
				 | ((uint16)0U << 10U); /* Clock Prescale:                             1:1 */
	
	ePWM4->TBPRD = 65535U; /* Init with max possible period */
	
	ePWM4->TBPHS = 0U; /* Reset to zero on sync */
	
	ePWM4->CMPA = 2499U; /* Init with trigger offset of zero */
	ePWM4->CMPB = 65535U; /* Trigger Disable at init */
	
	ePWM4->CMPCTL = (0U)        /* Counter A Shadow Load Mode:  CTR = zero */
				  | ((uint16)0U<< 4U); /* Counter A Shadow Mode:       Enabled */
	
	ePWM4->AQCTLA = (0U)         /* CTR = zero:                Do Nothing */
				  | ((uint16)0U << 2U)   /* CTR = PRD:                 Do Nothing */
				  | ((uint16)0U << 4U)   /* CTR = CMPA, incrementing:  Do Nothing */
				  | ((uint16)0U << 6U)   /* CTR = CMPA, decrementing:  Do Nothing */
				  | ((uint16)0U << 8U)   /* CTR = CMPB, incrementing:  Do Nothing */
				  | ((uint16)0U << 10U); /* CTR = CMPB, decrementing:  Do Nothing */
	
	ePWM4->DBCTL = 0U; /* Disable deadband generator */
	
	ePWM4->PCCTL = 0U; /* Disable chopper */
	
	ePWM4->TZCTL = 0x0FFFU; /* Do nothing on all trip-zone conditions */
	
	ePWM4->ETSEL = ((uint16)0U << 3U)   /* Interrupt Enable:  Disabled */
				 | ((uint16)4U << 8U)   /* SOCA Select:       CTR = CMPA, incrementing */
				 | ((uint16)1U << 11U)  /* SOCA Enable:       Enabled */
				 | ((uint16)6U << 12U)  /* SOCB Select:       CTR = CMPB, incrementing */
				 | ((uint16)1U << 15U); /* SOCB Enable:       Enabled */
	
	ePWM4->ETPS = ((uint16)1U << 8U)   /* SOCA Period:  Generate SOCA on every SOCA event */
				| ((uint16)1U << 12U); /* SOCB Period:  Generate SOCB on every SOCB event */
	
	
	/* Initialize ePWM7 */
	
	ePWM7->TBCTL = (0U)         /* Counter Mode:                               Up */
				 | ((uint16)1U << 2U)   /* Counter Register Load from phase register:  Enabled */
				 | ((uint16)0U << 3U)   /* Use shadow period register:                 Enabled */
				 | ((uint16)0U << 4U)   /* Sync Output Select:                         Sync In */
				 | ((uint16)0U << 7U)   /* High Speed Clock Prescale:                  1:1 */
				 | ((uint16)0U << 10U); /* Clock Prescale:                             1:1 */
	
	ePWM7->TBPRD = 65535U; /* Init with max possible period */
	
	ePWM7->TBPHS = 0U; /* Reset to zero on sync */
	
	ePWM7->CMPA = k_PwmRelay_Cnt_u16; /* Initialized with a cal */
	
	ePWM7->CMPCTL = (0U)        /* Counter A Shadow Load Mode:  CTR = zero */
				  | ((uint16)0U << 4U); /* Counter A Shadow Mode:       Enabled */
	
	ePWM7->AQCTLB = (1U)         /* CTR = zero:                Clear */
				  | ((uint16)0U << 2U)   /* CTR = PRD:                 Do Nothing */
				  | ((uint16)2U << 4U)   /* CTR = CMPA, incrementing:  Set */
				  | ((uint16)0U << 6U)   /* CTR = CMPA, decrementing:  Do Nothing */
				  | ((uint16)0U << 8U)   /* CTR = CMPB, incrementing:  Do Nothing */
				  | ((uint16)0U << 10U); /* CTR = CMPB, decrementing:  Do Nothing */
	
	ePWM7->DBCTL = 0U; /* Disable deadband generator */
	
	ePWM7->PCCTL = 0U; /* Disable chopper */
	
	ePWM7->TZCTL = 0x0FFFU; /* Do nothing on all trip-zone conditions */
	
	ePWM7->ETSEL = 0U; /* Disable all events */
	
	
	/* Disable PWM modules 1-3 initially */
	ePWM_DisableOutputs() 
	
}

/******************************************************************************
  * Name:        ePWM_Per1
  * Description: Implements the Motor Control Configuration and ADC SOCA/B subfunctions
  * Inputs:      inputs read by the following macros:
  *					ePWM_Read_PWMPeriod_u16
  *					ePWM_Read_DCPhsAComp_u16
  *					ePWM_Read_DCPhsBComp_u16
  *					ePWM_Read_DCPhsCComp_u16
  *					ePWM_Read_ePWM4CMPB_Cnt_u16
  *              outputs written by the ePWM_Write_ePWMxCMPy_Cnt_u16 macros
  * Usage Notes:  Called by the motor control task list
  ****************************************************************************/
FUNC(void, EPWM_CODE) ePWM_Per1(void)
{
	
	VAR(uint16, AUTOMATIC) halfPWMPeriod_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) PWMPeriod_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	DCPhsAComp_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	DCPhsBComp_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	DCPhsCComp_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	ePWM4CMPB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM1CMPA_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM1CMPB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM2CMPA_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM2CMPB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM3CMPA_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ePWM3CMPB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpAPhaseA_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpAPhaseB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpAPhaseC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpBPhaseA_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpBPhaseB_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CmpBPhaseC_Cnt_T_u16;
	
	/* Update ePWM duty cycles and periods */
	ePWM_Read_PWMPeriod_u16(&PWMPeriod_Cnt_T_u16);
	ePWM_Read_DCPhsAComp_u16(&DCPhsAComp_Cnt_T_u16);
	ePWM_Read_DCPhsBComp_u16(&DCPhsBComp_Cnt_T_u16);
	ePWM_Read_DCPhsCComp_u16(&DCPhsCComp_Cnt_T_u16);
	ePWM_Read_ePWM4CMPB_Cnt_u16(&ePWM4CMPB_Cnt_T_u16);
	
	halfPWMPeriod_Cnt_T_u16 = (uint16)(PWMPeriod_Cnt_T_u16 >> 1U);

	/* Update CompA and CompB Registers */

	CmpAPhaseA_Cnt_T_u16 =  (PWMPeriod_Cnt_T_u16 - DCPhsAComp_Cnt_T_u16)>>1U;

	if (CmpAPhaseA_Cnt_T_u16 > 535U)
	   { ePWM1CMPA_Cnt_T_u16 = CmpAPhaseA_Cnt_T_u16 - 535U; }
	else
	  { ePWM1CMPA_Cnt_T_u16 = 1U; }

	CmpBPhaseA_Cnt_T_u16 = ePWM1CMPA_Cnt_T_u16 + DCPhsAComp_Cnt_T_u16;
	if (CmpBPhaseA_Cnt_T_u16 > ( PWMPeriod_Cnt_T_u16 - 1U))
	   { ePWM1CMPB_Cnt_T_u16 = PWMPeriod_Cnt_T_u16 - 1U; }
	else
	  {	ePWM1CMPB_Cnt_T_u16 = CmpBPhaseA_Cnt_T_u16; }




	CmpAPhaseB_Cnt_T_u16 = (PWMPeriod_Cnt_T_u16 - DCPhsBComp_Cnt_T_u16)>>1U;

	if (CmpAPhaseB_Cnt_T_u16 > 535U)
	   { ePWM2CMPA_Cnt_T_u16 = CmpAPhaseB_Cnt_T_u16 - 535U; }
	else
	   { ePWM2CMPA_Cnt_T_u16 = 1U; }

	CmpBPhaseB_Cnt_T_u16 = ePWM2CMPA_Cnt_T_u16 + DCPhsBComp_Cnt_T_u16;
	if (CmpBPhaseB_Cnt_T_u16 > ( PWMPeriod_Cnt_T_u16 - 1U))
	   { ePWM2CMPB_Cnt_T_u16 = PWMPeriod_Cnt_T_u16 - 1U; }
	else
	   { ePWM2CMPB_Cnt_T_u16 = CmpBPhaseB_Cnt_T_u16; }




	CmpAPhaseC_Cnt_T_u16 = (PWMPeriod_Cnt_T_u16 - DCPhsCComp_Cnt_T_u16)>>1U;

	if (CmpAPhaseC_Cnt_T_u16 > 535U)
	   { ePWM3CMPA_Cnt_T_u16 = CmpAPhaseC_Cnt_T_u16 - 535U; }
	else
	   { ePWM3CMPA_Cnt_T_u16 = 1U; }

	CmpBPhaseC_Cnt_T_u16 = ePWM3CMPA_Cnt_T_u16 + DCPhsCComp_Cnt_T_u16;
	if (CmpBPhaseC_Cnt_T_u16 > ( PWMPeriod_Cnt_T_u16 - 1U))
	   { ePWM3CMPB_Cnt_T_u16 = PWMPeriod_Cnt_T_u16 - 1U; }
	else
	   { ePWM3CMPB_Cnt_T_u16 = CmpBPhaseC_Cnt_T_u16; }

	ePWM_Write_ePWM1CMPA_Cnt_u16(ePWM1CMPA_Cnt_T_u16);
	ePWM_Write_ePWM1CMPB_Cnt_u16(ePWM1CMPB_Cnt_T_u16);
	ePWM_Write_ePWM2CMPA_Cnt_u16(ePWM2CMPA_Cnt_T_u16);
	ePWM_Write_ePWM2CMPB_Cnt_u16(ePWM2CMPB_Cnt_T_u16);
	ePWM_Write_ePWM3CMPA_Cnt_u16(ePWM3CMPA_Cnt_T_u16);
	ePWM_Write_ePWM3CMPB_Cnt_u16(ePWM3CMPB_Cnt_T_u16);

	ePWM_Write_ePWM4CMPA_Cnt_u16((uint16)((((sint16)halfPWMPeriod_Cnt_T_u16) - k_ADCTrig1Offset_Cnt_s16) - 535 ))  ; /* PRQA S 4393 */
	ePWM_Write_ePWM4CMPB_Cnt_u16(ePWM4CMPB_Cnt_T_u16);


}

#define EPWM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

