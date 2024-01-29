/* -----------------------------------------------------------------------------
  Filename:    fbl_cfg.h
  Description: Toolversion: 04.01.00.01.30.06.65.02.00.00
               
               Serial Number: CBD1300665
               Customer Info: Nexteer Automotive Corporation
                              Package: FBL Psa SLP4 - CANfbl for PSA SLP4
                              Micro: 0812BPGEQQ1
                              Compiler: TexasInstruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyFblCanBase
               
               Configuration   : C:\Users\jzk9cc\Desktop\PSA_BMPV_FBL-Final-working\PSA_BMPV_FBL\SwProject\GENy_files\PSA_BMPV_Fbl.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS0322
               
               Channel "Channel0":
                       Databasefile: C:\Users\jzk9cc\Desktop\PSA_BMPV_FBL-Final-working\PSA_BMPV_FBL\SwProject\GENy_files\PSA_BMPV.dbc
                       Bussystem:    CAN
                       Manufacturer: PSA
                       Node:         PSCM

 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2014 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__FBL_CFG_H__)
#define __FBL_CFG_H__

/* -----------------------------------------------------------------------------
    &&&~ 
 ----------------------------------------------------------------------------- */

#define FBL_DISABLE_FLASHBLOCK_CHECK
#define FBL_WATCHDOG_OFF
#define FBL_WATCHDOG_TIME                    (1 / FBL_REPEAT_CALL_CYCLE)
#define FBL_HEADER_ADDRESS                   0x0100
#define FBL_ENABLE_APPL_TASK
#define FBL_ENABLE_MULTIPLE_MODULES
#define FBL_DIAG_BUFFER_LENGTH               4095
#define FBL_DIAG_TIME_P2MAX                  (10 / FBL_REPEAT_CALL_CYCLE)
#define FBL_DIAG_TIME_P3MAX                  (5000 / FBL_REPEAT_CALL_CYCLE)
#define FBL_DISABLE_SLEEPMODE
#define kFillChar                            0xFF
#define FBL_DISABLE_MULTIPLE_MEM_DEVICES
#define FBL_DISABLE_PRESENCE_PATTERN
#define FBL_ENABLE_FBL_START
/* Project State */
#define FBL_INTEGRATION                      2
#define FBL_PRODUCTION                       1
#define FBL_PROJECT_STATE                    FBL_INTEGRATION
#define FBL_ENABLE_SYSTEM_CHECK
#define FBL_ENABLE_DEBUG_STATUS
#define FBL_ENABLE_ASSERTION

/* Tmsx70Dcan specific ******************************************************* */
#define FBL_TIMER_PRESCALER_VALUE            0x01
#define FBL_TIMER_RELOAD_VALUE               0x9C3F
#define DELAY                                0

#define CAN_BITTIMING                        0x2B89
#define CAN_BRP_REG                          0x00
#define CAN_CTRL_ADDR                        0xFFF7DC00
#define CAN_NUMBER_OF_HW_OBJECTS             32
#define CAN_TP_RXID                          0x6b5
#define CAN_TP_TXID                          0x695
#define CAN_TP_FUNC_RXID                     0x07FF

#define FLASH_SIZE                           0x2000
#define FBL_WD_TRIGGER_SIZE                  1024
#define FBL_WDTRIGGER_EXTRA_WORDS            128
/*  */
/*  */
/* Manufacturer specific part ******************************************************************************** */
#define FBL_ENABLE_FBL_START
#define FBL_DIAG_DATA_LENGTH                 256
#define FBL_ECU_STATUS_ADDR                  0x0BFFF0
#define FBL_APPLI_KEY_ADDR                   0xF0200000
#define FBL_NO_OF_APPLI_KEY_SECTIONS         0x03
#define FBL_MTAB_NO_OF_SECTIONS              2
#define FBL_LOG_ZONE_ADDR                    0xF020FFFF
#define FBL_NO_OF_LOG_ENTRIES                20
#define FBL_DISABLE_UPLOAD
#define FBL_DISABLE_CAN_IS


/* -----------------------------------------------------------------------------
    &&&~ 
 ----------------------------------------------------------------------------- */

/* User Config File ********************************************************** */
/*************************************************/
/* Configuration Area F021 Flash Driver          */
/*************************************************/

/* Tms570 HCLK frequency in MHz */
#define FBL_HCLK      160
/*User Configuration Defines*/
#define FBLCW_ENABLE_TASK_CODE_IN_RAM
#define SEC_SECURITY_CLASS SEC_CLASS_NONE
#define SEC_CLASS_NONE 0
#define SEC_CLASS_C 1
#define SEC_CLASS_CCC 2


#define FBL_DISABLE_USERSUBFUNCTION
#define FBL_DISABLE_DATA_PROCESSING
#define FBL_ENABLE_FLASHDRV_ROM
/* User Section ************************************************************** */
#define FBL_ENABLE_SERVICE_POSTHANDLER
#define FBL_ENABLE_CAN_CONFIRMATION
/* *************************************************************************** */


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 167443655
      #error "The magic number of the generated file <C:\Users\jzk9cc\Desktop\PSA_BMPV_FBL-Final-working\PSA_BMPV_FBL\SwProject\GENy_files\fbl_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 167443655
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __FBL_CFG_H__ */
