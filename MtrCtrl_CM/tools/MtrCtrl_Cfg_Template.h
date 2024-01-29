/*****************************************************************************
/*****************************************************************************
* Copyright 2015, 2016 Nexteer Automotive
* Nexteer Confidential
*
* Module File Name  : MtrCtrl_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Mar 23 13:00:00 2013
* %version:          EA3#4 %
* %derived_by:       jzk9cc %
* %date_modified:    Wed Jun  5 11:31:23 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/11/15   2       Selva      Initial template creation                                                    CR12888
 * 07/21/16	  4       Rijvi      Updated for V19 of FDD SF99                                                  EA3#9293
 */


#ifndef MTRCTRL_CFG_H
#define MTRCTRL_CFG_H


#include "CDD_Data.h"



#define 	MtrCntrl_Read_MtrCurrQax_Amp_f32(ptr)    			*(ptr) =  
#define 	MtrCntrl_Read_MtrCurrDax_Amp_f32(ptr)    			*(ptr) =  
#define 	MtrCntrl_Read_ModIdxSrlComSvcDft_Cnt_lgc(ptr)    	*(ptr) =  
#define 	MtrCntrl_Read_SysState_Cnt_Enum(ptr)    			*(ptr) =  
#define 	MtrCntrl_Read_MtrCurrOffComOffset_Cnt_u16(ptr)   	*(ptr) =  
#define 	MtrCntrl_Read_MtrElecPol_Cnt_s8(ptr)    			*(ptr) =  
#define 	MtrCntrl_Read_MtrPosElec_Rev_u0p16(ptr)   			*(ptr) =   
#define 	MtrCntrl_Read_IvtrLoaMtgtnEn_Cnt_lgc(ptr)   		*(ptr) =            /********* from LOA manager through CDD interface**********/       
#define 	MtrCntrl_Read_MotCurrLoaMtgtnEn_Cnt_lgc(ptr)   		*(ptr) =            /********* from LOA manager through CDD interface**********/ 
#define     MtrCntrl_Read_DualEcuMotCtrlMtgnEna_Cnt_lgc(ptr)    *(ptr) =			/********* from LOA manager through CDD interface**********/ 


#define MtrCntrl_Write_MtrCurrQaxFinalRef_Amp_f32(val)           = (val)
#define MtrCntrl_Write_MtrDaxVoltage_Volt_f32(val)               = (val)
#define MtrCntrl_Write_MtrQaxVoltage_Volt_f32(val)               = (val)
#define MtrCntrl_Write_ModIdx_Uls_u16p16(val)                    = (val)
#define MtrCntrl_Write_PhaseAdvanceFinal_Rev_u0p16(val)   		 = (val)
															
#define MtrCntrl_Write_CommOffset_Cnt_u16(val)	                 = (val)

#endif
