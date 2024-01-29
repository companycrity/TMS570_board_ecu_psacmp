/*****************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : ePWM_Cfg.h
* Module Description: This is a stub header file used for QAC checking
* Product           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* %version:          1 %
* %derived_by:       jzk9cc %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 08/20/15    1		 Rijvi		Changed macros needed for ES34E rev.001								            EA3#1300
******************************************************************************/

#ifndef EPWM_CFG_H
#define EPWM_CFG_H

#include "Std_Types.h"

/* extern declarations for dummy variables to be used in macro definitions below */
/* ok because this file is used for MISARA checking only; no unit test for this component */
/* use of these dummy variables avoids extraneous MISRA violations flagged by QAC when
   macros are defined using literals  */
extern uint16 DummyVarPeriodIn;
extern uint16 DummyVarDCA;
extern uint16 DummyVarDCB;
extern uint16 DummyVarDCC;
extern uint16 DummyVar1A;
extern uint16 DummyVar1B;
extern uint16 DummyVar2A;
extern uint16 DummyVar2B;
extern uint16 DummyVar3A;
extern uint16 DummyVar3B;
extern uint16 DummyVar4A;
extern uint16 DummyVar4B;
extern uint16 DummyVar4BIn;



#define ePWM_Read_PWMPeriod_u16(ptr)  (*ptr) = DummyVarPeriodIn    /* Pwm time period   */

#define  ePWM_Read_DCPhsAComp_u16(ptr) (*ptr) = DummyVarDCA  /* Phase A  */
#define  ePWM_Read_DCPhsBComp_u16(ptr) (*ptr) = DummyVarDCB  /* Phase B  */
#define  ePWM_Read_DCPhsCComp_u16(ptr)  (*ptr) = DummyVarDCC  /* Phase C    */ 
#define  ePWM_Read_ePWM4CMPB_Cnt_u16(ptr)     (*ptr) = DummyVar4BIn

#define  ePWM_Write_ePWM1CMPA_Cnt_u16(val)   DummyVar1A = val
#define  ePWM_Write_ePWM1CMPB_Cnt_u16(val)   DummyVar1B = val
#define  ePWM_Write_ePWM2CMPA_Cnt_u16(val)   DummyVar2A = val
#define  ePWM_Write_ePWM2CMPB_Cnt_u16(val)   DummyVar2B = val
#define  ePWM_Write_ePWM3CMPA_Cnt_u16(val)   DummyVar3A = val
#define  ePWM_Write_ePWM3CMPB_Cnt_u16(val)   DummyVar3B = val
#define  ePWM_Write_ePWM4CMPA_Cnt_u16(val)   DummyVar4A = val
#define  ePWM_Write_ePWM4CMPB_Cnt_u16(val)   DummyVar4B = val



#endif

