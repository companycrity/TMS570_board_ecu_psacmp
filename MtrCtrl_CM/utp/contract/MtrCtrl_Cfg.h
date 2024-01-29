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
* %version:          EA3#5 %
* %derived_by:       jzk9cc %
* %date_modified:    Wed Jun  5 11:31:23 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/11/15   1       Selva      Initial template creation                                                    CR12888
 * 07/21/16	  5       Rijvi      Updated for V19 of FDD SF99                                                  EA3#9293
 */


#ifndef MTRCNTRL_CFG_H
#define MTRCNTRL_CFG_H

#include "Std_Types.h"

/******************** To remove QAC issues and to help UTP these are defined as fuctions rather than #define******/
/****** Refer the Tools folder to see how the actual template looks like***************/
extern void MtrCntrl_Read_MtrCurrQax_Amp_f32(float32 *Val)   ; 			
extern void MtrCntrl_Read_MtrCurrDax_Amp_f32(float32 *Val)    ;						 
extern void MtrCntrl_Read_ModIdxSrlComSvcDft_Cnt_lgc(boolean *Val)    	;
extern void MtrCntrl_Read_SysState_Cnt_Enum(uint8 *Val)    ;
extern void MtrCntrl_Read_MtrCurrOffComOffset_Cnt_u16(uint16 *ptr)   	;
extern void MtrCntrl_Read_MtrElecPol_Cnt_s8(sint8  *ptr)    		;	
extern void MtrCntrl_Read_MtrPosElec_Rev_u0p16(uint16 *ptr)   		;	
extern void MtrCntrl_Read_IvtrLoaMtgtnEn_Cnt_lgc(boolean *ptr)    ;       
extern void MtrCntrl_Read_MotCurrLoaMtgtnEn_Cnt_lgc(boolean *ptr)    ;   
extern void MtrCntrl_Read_DualEcuMotCtrlMtgnEna_Cnt_lgc(boolean *ptr);  


extern void  MtrCntrl_Write_MtrCurrQaxFinalRef_Amp_f32(float32 val);          
extern void  MtrCntrl_Write_MtrDaxVoltage_Volt_f32(float32 val)   ;            
extern void  MtrCntrl_Write_MtrQaxVoltage_Volt_f32(float32 val)   ;           
extern void  MtrCntrl_Write_ModIdx_Uls_u16p16(uint32 val)          ;           
extern void  MtrCntrl_Write_PhaseAdvanceFinal_Rev_u0p16(uint16 val);   		 	
extern void  MtrCntrl_Write_CommOffset_Cnt_u16(uint16 val)	      ;   
       

#endif
