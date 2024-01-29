/*****************************************************************************
* Copyright 2011 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: This file contains a stub header for UTP and QAC 
*                     projects
* Product           : Gen II Plus EA3.0
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          3 %
* %derived_by:       nzt9hv %
* %date_modified:    Fri Nov  1 16:48:28 2013 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"

#define D_APPCDDBFRSIZE_CNT_U16   2U


extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosElec_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasA_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasB_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];

/* Data Consistancy Buffer Access Variables */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;
extern VAR(uint16, AUTOMATIC)  CDD_PWMPeriod_Cnt_G_u16;
extern VAR(uint16, AUTOMATIC)  CDD_DCPhsComp_Cnt_G_u16[3];

#endif

