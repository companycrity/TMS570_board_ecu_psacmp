/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : appinit_cfg.h
* Module Description: This file contains the configuration of the applicaiton init sequence
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*******************************************************************************
* Version Control:
* %version:          EA3#4 %
* %derived_by:       nzx5jd %
********************************************************************************
* Change History:
* Date      Rev      Author    Change Description
* --------  -------  --------  ------------------------------------------------
* 03/07/14   1       OT        Initial version
* 07/18/14   2       OT        Updates for DMA
* 08/13/14   3       OT        Enabled DMA parity for new bootloader
* 10/20/15   4       OT        Updates for DMA/HTU MPU
*******************************************************************************/

#ifndef APPINIT_CFG_H_
#define APPINIT_CFG_H_

#include "Std_Types.h"

/* Peripheral Enables */
#define MIBSPI1_ENABLE  			STD_OFF
#define MIBSPI3_ENABLE  			STD_ON
#define MIBSPI5_ENABLE  			STD_ON
#define GIO_ENABLE  				STD_ON

/* Peripheral RAM Parity Test Enables */
#define MIBSPI1_PARITY_ENABLE  		STD_OFF
#define MIBSPI3_PARITY_ENABLE  		STD_OFF
#define MIBSPI5_PARITY_ENABLE  		STD_OFF
#define N2HET1_PARITY_ENABLE  		STD_ON
#define N2HET2_PARITY_ENABLE  		STD_ON
#define N2HET1TU_PARITY_ENABLE  	STD_ON
#define N2HET2TU_PARITY_ENABLE  	STD_ON
#define MIBADC1_PARITY_ENABLE  		STD_ON
#define MIBADC2_PARITY_ENABLE  		STD_ON
#define DCAN1_PARITY_ENABLE  		STD_ON
#define DCAN2_PARITY_ENABLE  		STD_OFF
#define DCAN3_PARITY_ENABLE  		STD_OFF
#define VIM_PARITY_ENABLE  			STD_ON
#define DMA_PARITY_ENABLE  			STD_ON
#define DMA_MPU_ENABLE 				STD_ON
#define N2HET1TU_MPU_ENABLE  		STD_ON
#define N2HET2TU_MPU_ENABLE  		STD_OFF

#endif /* APPINIT_CFG_H_ */
