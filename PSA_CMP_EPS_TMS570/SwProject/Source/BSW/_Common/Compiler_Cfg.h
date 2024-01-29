/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vector Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component spesific defines filtering added
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all oems
 *                                              rename internal variables and filtermethods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */





/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE

/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */

#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#define V_USE_DUMMY_STATEMENT  STD_ON

/* include Rte Compiler_Cfg because the Rte sections are configuration dependent*/
#include "Rte_Compiler_Cfg.h"



















































/**********************************************************************************************************************
 *  Adc START
 *********************************************************************************************************************/
#define ADC_CODE
#define ADC_CONST
#define ADC_PBCFG
#define ADC_APPL_DATA
#define ADC_VAR
/**********************************************************************************************************************
 *  Adc END
 *********************************************************************************************************************/



#define DIO_CONST
#define DIO_CODE
#define DIO_APPL_DATA
#define DIO_VAR




#define EEP_30_AT25128_CODE
#define EEP_30_AT25128_APPL_CODE
#define EEP_30_AT25128_PBCFG
#define EEP_30_AT25128_CONST
#define EEP_30_AT25128_VAR
#define EEP_30_AT25128_VAR_NOINIT
#define EEP_30_AT25128_APPL_DATA








#define GPT_CODE
#define GPT_DATA
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CODE
#define GPT_PBCFG



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr START
 *********************************************************************************************************************/

#define ICU_CODE
#define ICU_APPL_CODE
#define ICU_APPL_CONST
#define ICU_APPL_DATA
#define ICU_VAR
#define ICU_VAR_FAST
#define ICU_CONST
#define ICU_PBCFG

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 * MCU START
 *********************************************************************************************************************/

#define MCU_APPL_DATA
#define MCU_CODE
#define MCU_DATA
#define MCU_PBCFG
#define MCU_RAM_COPY
#define MCU_ROM_COPY
#define MICROSAR_NEAR

/**********************************************************************************************************************
 *  MCU END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  PORT START 
 *********************************************************************************************************************/
 
#define PORT_CODE
#define PORT_PBCODE
#define PORT_VAR
#define PORT_APPL_DATA
#define PORT_PBCFG

/**********************************************************************************************************************
 *  PORT END 
 *********************************************************************************************************************/


#define PWM_CODE
#define PWM_VAR
#define PWM_APPL_DATA
#define PWM_PBCFG



/**********************************************************************************************************************
 *  Spi START 
 **********************************************************************************************************************/

#define SPI_CODE
#define SPI_VAR
#define SPI_VAR_NOINIT
#define SPI_VAR_ZERO_INIT
#define SPI_CONST
#define SPI_PBCFG
#define SPI_APPL_CODE
#define SPI_APPL_DATA
#define SPI_SEC_REGISTER    MSR_REGSPACE

/**********************************************************************************************************************
 *  Spi END
 **********************************************************************************************************************/





/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

#define IOHWAB_CODE

#define IOHWAB_VAR

#define IOHWAB_APPL_DATA
#define IOHWAB_APPL_CODE

#define IOHWAB_CONST

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  If_AsrIfEa START 
 *********************************************************************************************************************/

#define EA_PUBLIC_CODE
#define EA_PRIVATE_CODE

#define EA_APPL_DATA
#define EA_FAST_DATA

#define EA_PRIVATE_CONST
#define EA_PUBLIC_CONST

#define EA_NVM_CODE

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


















#define MEMIF_CODE
#define MEMIF_CONST
#define MEMIF_APPL_DATA





/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

#define WDGIF_CODE
#define WDGIF_VAR
#define WDGIF_CONST
#define WDGIF_APPL_DATA

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/


















/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

#define NVM_APPL_DATA
#define NVM_APPL_CODE
#define NVM_APPL_CONST

#define NVM_CRC_APPL_DATA

#define NVM_CONFIG_DATA
#define NVM_CONFIG_CONST

#define NVM_FAST_DATA

#define NVM_PRIVATE_CODE
#define NVM_PRIVATE_CONST
#define NVM_PRIVATE_DATA

#define NVM_PUBLIC_CODE
#define NVM_PUBLIC_CONST

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/












#define CRC_APPL_DATA
#define CRC_CODE
#define CRC_CONST



# define DET_CODE
# define DET_VAR
# define DET_APPL_DATA
# define DET_APPL_CODE



/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

#define ECUM_API_CODE 
#define ECUM_APPL_CONFIG 
#define ECUM_APPL_DATA 
#define ECUM_VAR_BOOT
#define ECUM_CODE
#define ECUM_CODE_BOOT_TARGET 
#define ECUM_CONST 
#define ECUM_PBCFG
#define ECUM_VAR 
#define ECUM_VAR_NOINIT 

/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/








/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM START 
 *********************************************************************************************************************/

#define WDGM_CODE

#define WDGM_VAR
#define WDGM_VAR_NOINIT
#define WDGM_DATA

#define WDGM_APPL_DATA
#define WDGM_APPL_CODE

#define WDGM_GPT_CODE
#define WDGM_CONST
#define WDGM_PBCFG

/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx START
 *********************************************************************************************************************/

#define HET_CODE
#define HET_RAM
#define HET_VAR
#define HET_CONST

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

#define XCP_CONST
#define XCP_VAR
#define XCP_CODE
#define XCP_APPL_DATA
#define XCP_MTA_DATA
#define XCP_DAQ_DATA
#define XCP_VAR_NOINIT


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANXCP START 
 *********************************************************************************************************************/

#define CANXCP_VAR_NOINIT
#define CANXCP_CONST
#define CANXCP_PBCFG
#define CANXCP_CODE
#define CANXCP_APPL_VAR

/*-------------------------------------------------------------------------------------------------------------------*/
/* CANXCP END                                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/




/*==== DEM =================================================================*/
#define DEM_CODE                /* code */
#define DEM_VAR                 /* global/static vars; init after every reset */
#define DEM_VAR_NOINIT_FAST     /* global/static vars; using: bitaccess or frequently used or many accesses in code */
#define DEM_VAR_NOINIT          /* global/static vars; not initialized after reset */
#define DEM_CONST               /* global/static constants */
#define DEM_PBCFG               /* global/static constants for PostBuild */
#define DEM_APPL_CODE           /* callback functions used by DEM, implemented outside DEM */
#define DEM_APPL_DATA           /* vars (buffers) outside DEM, passed via API */
#define DEM_APPL_CONST          /* constants outside DEM, passed via API */
/*==========================================================================*/



/* Kernbauer Version: 1.16 Konfiguration: DrvCAN Erzeugungsgangnummer: 486 */

/*-------------------------------------------------------------------------------------------------------------------*/
/* CAN driver start compiler_cfg                                                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/

#define CAN_CODE                                   /* CAN modules code qualifier               */
#define CAN_CONST                                  /* constant memory                          */
#define CAN_CONST_PBCFG                            /* postbuild generated constant/flash       */
#define CAN_VAR_NOINIT                             /* none initialized variables               */
#define CAN_VAR_INIT                               /* initialized variables                    */
#define CAN_INT_CTRL                               /* access to Interrupt controller registers */
#define CAN_REG_CANCELL                            /* CAN cell register qualifier              */
#define CAN_RX_TX_DATA        CAN_REG_CANCELL      /* pointer width >= CAN_REG_CANCELL  / CAN rx/tx data / RAM or SFR    (rx data pointer for Indication and PreCopy functions to higher layers / tx data pointers / sdu  from application)   */
#define CAN_APPL_CODE                              /* Application code qualifier               */
#define CAN_APPL_CONST                             /* Application constant memory              */
#define CAN_APPL_VAR                               /* Application variables                    */

/*-------------------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------------------------*/
/* CAN driver end compiler_cfg                                                                                       */
/*-------------------------------------------------------------------------------------------------------------------*/



/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

# define PDUR_CODE
# define PDUR_VAR_NOINIT
# define PDUR_VAR_ZERO_INIT
# define PDUR_VAR
# define PDUR_CONST
# define PDUR_PBCFG
# define PDUR_APPL_DATA
# define PDUR_APPL_CODE
# define PDUR_IPDUM_DATA
# define PDUR_MOST_DATA
# define PDUR_PBCFG_ROOT		PDUR_PBCFG

/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/


/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/


#define CANIF_VAR_NOINIT
#define CANIF_VAR_ZERO_INIT
#define CANIF_VAR_INIT


#define CANIF_CONST
#define CANIF_PBCFG
#define CANIF_PBCFG_ROOT

#define CANIF_CODE


#define CANIF_APPL_CODE
#define CANIF_APPL_VAR
#define CANIF_APPL_PBCFG


/*-------------------------------------------------------------------------------------------------------------------*/

/* Has to be kept in default section -> Default access */
#define CANIF_VAR_STACK


/* VAR section of higher layers (TP / NM / PduR / CanSM / EcuM) automatically mapped to APPL_VAR */
#define CANIF_APPL_STATE_VAR   CANIF_APPL_VAR
#define CANIF_APPL_MSG_VAR     CANIF_APPL_VAR

/* VAR section of lower layers (CAN Driver / Transceiver Driver) automatically mapped to APPL_VAR */
#define CANIF_CBK_VAR          CANIF_APPL_VAR

/* #define CANIF_CBK_TRCV_VAR     CANIF_CBK_VAR    not used yet */
#define CANIF_CBK_DRV_VAR      CANIF_CBK_VAR

/* Code sections - DO NOT MODIFY */
#define CANIF_CBK_TRCV_CODE     CANIF_APPL_CODE
#define CANIF_APPL_STATE_CODE   CANIF_APPL_CODE
#define CANIF_APPL_MSG_CODE     CANIF_APPL_CODE


/* Upper layer data pointer */
#define CANIF_UL_STANDARD_VAR    CANIF_APPL_VAR
#define CANIF_UL_ADVANCED_VAR    CANIF_APPL_VAR
#define CANIF_UL_OSEKNM_VAR      CANIF_APPL_VAR

/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/



/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define COM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define COM_PBCFG
/* Module Root Constant of the Postbuild Configuration */
#define COM_PBCFG_ROOT 		COM_PBCFG


/* Module Implementation */
#define COM_CODE

/* Module Variables which are initialized by the startup code or by the call of Com_InitMemory() */
#define COM_VAR_NOINIT
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define COM_APPL_CODE
/* Application Buffer which is located in RAM */
#define COM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define COM_APPL_DATA

/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/











































































/* Package Merger: Stop Section CompilerCfgModuleList */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
