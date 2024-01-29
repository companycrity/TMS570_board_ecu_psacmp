
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_ DIGMSB_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 30.11.2012 08:09:43
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          5 %
 * %date_modified:    Tue Dec  3 09:39:04 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/13   1       Selva      Initial template creation
 * 08/08/13   2       Selva      Template Updated
 * 12/02/13   3       OT         Updates for FDD 50A v4
 * 04/07/14   4       Selva      Updates for FDD 50A v5 prerelease
 * 02/06/15   5       Rijvi      Updated per FDD rev.008                							           12997
 */

#ifndef  DIGMSB_CFG_H
#define  DIGMSB_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

FUNC(void, RTE_CODE) DigMSB_Read_MtrPosPolarity_Cnt_s08(sint8* ptr);

/* Map the outputs back to 2ms RTE using buffering. */

FUNC(void, RTE_CODE) 	DigMSB_Write_MechMtrPos1_Rev_u0p16(uint16 Var)				;                                     /***Also Used in 62.5uS  of Motor Velocity***/
FUNC(void, RTE_CODE) 	DigMSB_Write_SysCMechMtrPos1_Rev_u0p16(uint16 Var)				;
FUNC(void, RTE_CODE) 	DigMSB_Write_SysCorrectedElecMtrPos_Rev_u0p16(uint16 Var)				;
FUNC(void, RTE_CODE) 	DigMSB_Write_MechMtrPos1TimeStamp_uSec_u32(uint32 Var)				;                                      /***Also Used in 62.5uS of Motor Velocity ***/
FUNC(void, RTE_CODE) 	DigMSB_Write_MechMtrPos2TimeStamp_uSec_u32(uint32 Var)				;
/*------------------------------------------------*/
FUNC(void, RTE_CODE) 	DigMSB_Write_CorrectedElecMtrPos_Rev_u0p16(uint16 Var)				;                                      /***Used in 62.5uS  of Motor Current  Measurement ***/

/************* DO NOT COPY THIS IN INTEGRATION PROJECT. REFER TEMPALTE  IN TOOL FOLDER **********************/
/****Used in 2ms of DigMSB***/
FUNC(void, RTE_CODE) DigMSB_Write_UncorrMechMtrPos1_Rev_u0p16(uint16 Var)				;
FUNC(void, RTE_CODE) DigMSB_Write_CumMechMtrPos_Rev_s15p16(sint32 Var)					;
FUNC(void, RTE_CODE) DigMSB_Write_Die1RxError_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_Die2RxError_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_Die1RxRevCtr_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_Die2RxRevCtr_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_Die1RxMtrPos_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_Die2RxMtrPos_Cnt_u16(uint16 Var)						;
FUNC(void, RTE_CODE) DigMSB_Write_RxMtrPos1ParityAccum_Cnt_u16(uint16 Var)   			;
FUNC(void, RTE_CODE) DigMSB_Write_RxMtrPos1UnderVoltgFltAccum_Cnt_u16(uint16 Var)        ;

/* macro definitions for SPI functions using SpiNxt */

FUNC(void, RTE_CODE) MSB1GetData(uint16* ptr);
 FUNC(void, RTE_CODE) MSB1SetData(uint16* ptr)             ;
 FUNC(void, RTE_CODE) MSB2GetData(uint16* ptr)             ;
 FUNC(void, RTE_CODE) MSB2SetData(uint16* ptr)              ;
 FUNC(void, RTE_CODE) MSB1EnableDataTransfer()   ;
 FUNC(void, RTE_CODE) MSB2EnableDataTransfer()   ;
 FUNC(void, RTE_CODE) MSB1GetConfig(uint16* ptr)            ;
 FUNC(void, RTE_CODE) MSB1SetConfig(uint16* ptr)            ;
 FUNC(void, RTE_CODE) MSB2GetConfig(uint16* ptr)           ;
 FUNC(void, RTE_CODE) MSB2SetConfig(uint16* ptr)            ;
 FUNC(void, RTE_CODE) MSB1EnableConfigTransfer() ;
 FUNC(void, RTE_CODE) MSB2EnableConfigTransfer() ;
/*** End of file **************************************************************/

#endif /* DIGMSBSIGCORR_CFG_H */

