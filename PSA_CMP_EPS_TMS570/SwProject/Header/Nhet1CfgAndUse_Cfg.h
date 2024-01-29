/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Nhet1CfgAndUse_Cfg.h
* Module Description: FDD ES-35B (Nhet1 configuration and use)
* Product           : CBD
* Author            : Yue Zhao
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* %version:          1 %
* %derived_by:       fzh7xw %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 07/01/16  1        WH         Initial Implementation												        EA3#9275
*
*---------------------------------------------------------------------------*/

#ifndef NHET1CFGANDUSE_CFG_H
#define NHET1CFGANDUSE_CFG_H

#include "CDD_Data.h"
#include "Dma.h"


#include "Std_Types.h"



#define Nhet1CfgAndUse_Read_PWMPeriod_u16(ptr)  (*ptr)= CDD_PWMPeriod_Cnt_G_u16

#define Nhet1CfgAndUse_Write_PWMPeriod_Cnt_u16(val)	DMAData_G_str.PWMPeriod_Cnt_u32 = (uint32)(val) 

#endif

