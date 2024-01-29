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
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
**********************************************************************************************************************/

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
 *  01.01.02  2008-11-04  Jk                    Component spesific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http,
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
 *********************************************************************************************************************
 * Nexteer Change Log
**********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Feb 17 17:00:00 2014
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/08/16   1       WH        Initial version based off PSA_BMPV v26
 * 06/15/16   2       WH        Integrated CF24                                                                 EA3#9001
 * 06/17/16   3       WH        Integrated ES-57C                                                               EA3#9033
 * 06/20/16   4       WH        Integrated ES-56C                                                               EA3#9067
 * 06/20/16   5       WH        Integrated SF-48A                                                               EA3#9074
 * 06/21/16   6       WH        Integrated SF-49A                                                               EA3#9078
 * 06/21/16   7       WH        Integrated SF-50A                                                               EA3#9079
 * 06/22/16   8       WH        Updated SF-99b                                                                  EA3#9081
 * 06/29/16   9       WH        Integrated SF-44                                                                EA3#9216
 * 07/29/16   10      WH        Updates for integrating the new NHET/epwm and its dependencies					EA3#9275
 * 12/15/17   11      RK        Added new sections for PSADMQ CF24			                                    EA3#18482
 * 12/15/17   12      RK        Added sections for CustBattDiag for change in Volt Diag Window					EA3#18425
 */
/**********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

/* MemMap defeat for faster Polyspace analysis */
#ifndef DEFEAT_MEMMAP

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        (30u)
#define MEM_AR_MAJOR_VERSION (1u)                      /* part of Autosare release 3.0.1 */
#define MEM_AR_MINOR_VERSION (1u)
#define MEM_AR_PATCH_VERSION (0u)

#define MEM_SW_MAJOR_VERSION (1u)
#define MEM_SW_MINOR_VERSION (5u)
#define MEM_SW_PATCH_VERSION (4u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */

/* Include these prior to Rte_MemMap, because that file includes Os_MemMap */

#include "Wdg_MemMap.h"
#include "WdgM_MemMap.h"

/* include Rte MemMap because the Rte sections are configuration dependent*/
#include "Rte_MemMap.h"


/**********************************************************************************************************************
*  AbsHwPos START
**********************************************************************************************************************/

#ifdef ABSHWPOS_START_SEC_VAR_CLEARED_32
	#undef ABSHWPOS_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef ABSHWPOS_STOP_SEC_VAR_CLEARED_32
	#undef ABSHWPOS_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef ABSHWPOS_START_SEC_VAR_CLEARED_16
	#undef ABSHWPOS_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef ABSHWPOS_STOP_SEC_VAR_CLEARED_16
	#undef ABSHWPOS_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef ABSHWPOS_START_SEC_VAR_CLEARED_8
	#undef ABSHWPOS_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef ABSHWPOS_STOP_SEC_VAR_CLEARED_8
	#undef ABSHWPOS_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef ABSHWPOS_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ABSHWPOS_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef ABSHWPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ABSHWPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef ABSHWPOS_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ABSHWPOS_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef ABSHWPOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ABSHWPOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  AbsHwPos END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ActivePull START
**********************************************************************************************************************/

#ifdef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ActivePull")
	#undef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
	#undef MEMMAP_ERROR
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
	#undef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
	#define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_32
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_16
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ActivePull END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Adc START
**********************************************************************************************************************/

#ifdef ADC_START_SEC_CODE
	#undef ADC_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef ADC_STOP_SEC_CODE
	#undef ADC_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef ADC2_START_SEC_CODE
	#undef ADC2_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef ADC2_STOP_SEC_CODE
	#undef ADC2_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONST_32
	#undef ADC_START_SEC_CONST_32
	#define START_SEC_CONST_32BIT
#endif
#ifdef ADC_STOP_SEC_CONST_32
	#undef ADC_STOP_SEC_CONST_32
	#define STOP_SEC_CONST
#endif

#ifdef ADC2_START_SEC_CONST_32
	#undef ADC2_START_SEC_CONST_32
	#define START_SEC_CONST_32BIT
#endif
#ifdef ADC2_STOP_SEC_CONST_32
	#undef ADC2_STOP_SEC_CONST_32
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  Adc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  AppDesc START
**********************************************************************************************************************/

#ifdef APPDESC_START_SEC_VAR_CLEARED_32
	#undef APPDESC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef APPDESC_STOP_SEC_VAR_CLEARED_32
	#undef APPDESC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef APPDESC_START_SEC_VAR_CLEARED_16
	#undef APPDESC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef APPDESC_STOP_SEC_VAR_CLEARED_16
	#undef APPDESC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef APPDESC_START_SEC_VAR_CLEARED_8
	#undef APPDESC_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef APPDESC_STOP_SEC_VAR_CLEARED_8
	#undef APPDESC_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef APPDESC_START_SEC_VAR_CLEARED_BOOLEAN
	#undef APPDESC_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef APPDESC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef APPDESC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  AppDesc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ApXcp START
**********************************************************************************************************************/

#ifdef APXCP_START_SEC_VAR_NOINIT_8
	#undef APXCP_START_SEC_VAR_NOINIT_8
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef APXCP_STOP_SEC_VAR_NOINIT_8
	#undef APXCP_STOP_SEC_VAR_NOINIT_8
	#define STOP_SEC_VAR
#endif

#ifdef APXCP_START_SEC_VAR_NOINIT_32
	#undef APXCP_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32BIT_6
#endif
#ifdef APXCP_STOP_SEC_VAR_NOINIT_32
	#undef APXCP_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

#ifdef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
	#undef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef APXCP_START_SEC_VAR_CLEARED_8
	#undef APXCP_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef APXCP_STOP_SEC_VAR_CLEARED_8
	#undef APXCP_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef APXCP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef APXCP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ApXcp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Assist START
**********************************************************************************************************************/

#ifdef ASSIST_START_SEC_VAR_CLEARED_16
	#undef ASSIST_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef ASSIST_STOP_SEC_VAR_CLEARED_16
	#undef ASSIST_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Assist END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  AssistFirewall START
**********************************************************************************************************************/

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
	#undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
	#undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
	#undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
	#undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  AssistFirewall END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  AstLmt START
*********************************************************************************************************************/

#ifdef ASTLMT_START_SEC_VAR_CLEARED_32
	#undef ASTLMT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef ASTLMT_STOP_SEC_VAR_CLEARED_32
	#undef ASTLMT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef ASTLMT_START_SEC_VAR_CLEARED_16
	#undef ASTLMT_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef ASTLMT_STOP_SEC_VAR_CLEARED_16
	#undef ASTLMT_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  AstLmt END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Atan2_NxtrLib START
**********************************************************************************************************************/

#ifdef ATAN2_START_SEC_VAR_INIT_32
	#undef ATAN2_START_SEC_VAR_INIT_32
	#define START_SEC_VAR_INIT_32BIT_10
#endif
#ifdef ATAN2_STOP_SEC_VAR_INIT_32
	#undef ATAN2_STOP_SEC_VAR_INIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Atan2_NxtrLib END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  AvgFricLrn START
**********************************************************************************************************************/

#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_32
	#undef AVGFRICLRN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
	#undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  AvgFricLrn END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  BatteryVoltage START
*********************************************************************************************************************/

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
	#undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
	#undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
	#undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
	#undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
	#undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  BatteryVoltage END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  BkCpPc START
**********************************************************************************************************************/

#ifdef BKCPPC_START_SEC_VAR_CLEARED_16
	#undef BKCPPC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_16
	#undef BKCPPC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef BKCPPC_START_SEC_VAR_CLEARED_32
	#undef BKCPPC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_32
	#undef BKCPPC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  BkCpPc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  BVDiag START
**********************************************************************************************************************/

#ifdef BVDIAG_START_SEC_VAR_CLEARED_32
	#undef BVDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef BVDIAG_STOP_SEC_VAR_CLEARED_32
	#undef BVDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  BVDiag END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CalConstants START
**********************************************************************************************************************/

#ifdef CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_32BIT_11
#endif
#ifdef CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CalConstants END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CDDData START
**********************************************************************************************************************/

#ifdef CDDDATA0_START_SEC_VAR_CLEARED_16
	#undef CDDDATA0_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_0
#endif
#ifdef CDDDATA0_STOP_SEC_VAR_CLEARED_16
	#undef CDDDATA0_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA0_START_SEC_VAR_CLEARED_32
	#undef CDDDATA0_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_0
#endif
#ifdef CDDDATA0_STOP_SEC_VAR_CLEARED_32
	#undef CDDDATA0_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA0_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA0_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef CDDDATA0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif


#ifdef CDDDATA6_START_SEC_VAR_CLEARED_8
	#undef CDDDATA6_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef CDDDATA6_STOP_SEC_VAR_CLEARED_8
	#undef CDDDATA6_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA6_START_SEC_VAR_CLEARED_32
	#undef CDDDATA6_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef CDDDATA6_STOP_SEC_VAR_CLEARED_32
	#undef CDDDATA6_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA6_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA6_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef CDDDATA6_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA6_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif


#ifdef CDDDATA9_START_SEC_VAR_CLEARED_16
	#undef CDDDATA9_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef CDDDATA9_STOP_SEC_VAR_CLEARED_16
	#undef CDDDATA9_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA9_START_SEC_VAR_CLEARED_32
	#undef CDDDATA9_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef CDDDATA9_STOP_SEC_VAR_CLEARED_32
	#undef CDDDATA9_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif


#ifdef CDDDATA10_START_SEC_VAR_CLEARED_8
	#undef CDDDATA10_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef CDDDATA10_STOP_SEC_VAR_CLEARED_8
	#undef CDDDATA10_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA10_START_SEC_VAR_CLEARED_BOOLEAN
	#undef CDDDATA10_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef CDDDATA10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef CDDDATA10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA10_START_SEC_VAR_CLEARED_16
	#undef CDDDATA10_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef CDDDATA10_STOP_SEC_VAR_CLEARED_16
	#undef CDDDATA10_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA10_START_SEC_VAR_CLEARED_32
	#undef CDDDATA10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef CDDDATA10_STOP_SEC_VAR_CLEARED_32
	#undef CDDDATA10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CDDDATA10_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA10_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef CDDDATA10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CDDDATA10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CDDData END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CDDInterface6 START
**********************************************************************************************************************/

#ifdef CDDINTERFACE6_START_SEC_VAR_CLEARED_8
	#undef CDDINTERFACE6_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef CDDINTERFACE6_STOP_SEC_VAR_CLEARED_8
	#undef CDDINTERFACE6_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CDDInterface6 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CDDInterface9 START
**********************************************************************************************************************/

#ifdef CDDINTERFACE9_STOP_SEC_VAR_NOINIT_32
	#undef CDDINTERFACE9_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CDDInterface9 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CmMtrCurr START
**********************************************************************************************************************/

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_16
	#undef CMMTRCURR_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_11
#endif
#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_16
	#undef CMMTRCURR_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_32
	#undef CMMTRCURR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_32
	#undef CMMTRCURR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
	#undef CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_11
#endif
#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CmMtrCurr END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CMS_Common START
**********************************************************************************************************************/

#ifdef EPSDIAGSRVC_START_SEC_CONST_8
	#undef EPSDIAGSRVC_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_CONST_8
	#undef EPSDIAGSRVC_STOP_SEC_CONST_8
	#define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
	#undef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
	#undef EPSXCPSRVC_STOP_SEC_VAR_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CMS_Common END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CtrlTemp START
**********************************************************************************************************************/

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_32
	#undef CTRLTEMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
	#undef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_16
	#undef CTRLTEMP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_11
#endif
#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
	#undef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CtrlTemp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CurrCmd START
**********************************************************************************************************************/

#ifdef CURRCMD_START_SEC_VAR_CLEARED_32
	#undef CURRCMD_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef CURRCMD_STOP_SEC_VAR_CLEARED_32
	#undef CURRCMD_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CURRCMD_START_SEC_VAR_CLEARED_16
	#undef CURRCMD_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef CURRCMD_STOP_SEC_VAR_CLEARED_16
	#undef CURRCMD_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef CURRCMD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CURRCMD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef CURRCMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CURRCMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CurrCmd END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CurrParamComp START
**********************************************************************************************************************/

#ifdef CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
	#undef CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
	#undef CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CurrParamComp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CustBattDiag START
**********************************************************************************************************************/

#ifdef CUSTBATTDIAG_START_SEC_VAR_CLEARED_32
	#undef CUSTBATTDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef CUSTBATTDIAG_STOP_SEC_VAR_CLEARED_32
	#undef CUSTBATTDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef CUSTBATTDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CUSTBATTDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef CUSTBATTDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef CUSTBATTDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef CUSTBATTDIAG_START_SEC_CONST_16
	#undef CUSTBATTDIAG_START_SEC_CONST_16
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CUSTBATTDIAG_STOP_SEC_CONST_16
	#undef CUSTBATTDIAG_STOP_SEC_CONST_16
	#define STOP_SEC_CONST
#endif

#ifdef CUSTBATTDIAG_START_SEC_CONST_UNSPECIFIED
	#undef CUSTBATTDIAG_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CUSTBATTDIAG_STOP_SEC_CONST_UNSPECIFIED
	#undef CUSTBATTDIAG_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  CustBattDiag END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Damping START
**********************************************************************************************************************/

#ifdef DAMPING_START_SEC_VAR_CLEARED_16
	#undef DAMPING_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef DAMPING_STOP_SEC_VAR_CLEARED_16
	#undef DAMPING_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DAMPING_START_SEC_VAR_CLEARED_32
	#undef DAMPING_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef DAMPING_STOP_SEC_VAR_CLEARED_32
	#undef DAMPING_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Damping END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DampingFirewall START
**********************************************************************************************************************/

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
	#undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
	#undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
	#undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
	#undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
*  DampingFirewall END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Dem START
**********************************************************************************************************************/

#ifdef DEM_START_SEC_CODE
	#undef DEM_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef DEM_STOP_SEC_CODE
	#undef DEM_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef DEM_START_SEC_VAR_8BIT
	#undef DEM_START_SEC_VAR_8BIT
	#define START_SEC_VAR_INIT_8BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_8BIT
	#undef DEM_STOP_SEC_VAR_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_32BIT
	#undef DEM_START_SEC_VAR_32BIT
	#define START_SEC_VAR_INIT_32BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_32BIT
	#undef DEM_STOP_SEC_VAR_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_FAST_8BIT
	#undef DEM_START_SEC_VAR_FAST_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_8BIT
	#undef DEM_STOP_SEC_VAR_FAST_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_FAST_16BIT
	#undef DEM_START_SEC_VAR_FAST_16BIT
	#define START_SEC_VAR_NOINIT_16BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_16BIT
	#undef DEM_STOP_SEC_VAR_FAST_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_FAST_32BIT
	#undef DEM_START_SEC_VAR_FAST_32BIT
	#define START_SEC_VAR_NOINIT_32BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_32BIT
	#undef DEM_STOP_SEC_VAR_FAST_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_8BIT
	#undef DEM_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_8BIT
	#undef DEM_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_16BIT
	#undef DEM_START_SEC_VAR_NOINIT_16BIT
	#define START_SEC_VAR_NOINIT_16BIT_6
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_16BIT
	#undef DEM_STOP_SEC_VAR_NOINIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
	#undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
	#undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_CONST_8BIT
	#undef DEM_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef DEM_STOP_SEC_CONST_8BIT
	#undef DEM_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_CONST_32BIT
	#undef DEM_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef DEM_STOP_SEC_CONST_32BIT
	#undef DEM_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_CONST_UNSPECIFIED
	#undef DEM_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DEM_STOP_SEC_CONST_UNSPECIFIED
	#undef DEM_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_CONST_LCFG
	#undef DEM_START_SEC_CONST_LCFG
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DEM_STOP_SEC_CONST_LCFG
	#undef DEM_STOP_SEC_CONST_LCFG
	#define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_PBCONST_ROOT
	#undef DEM_START_SEC_PBCONST_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef DEM_STOP_SEC_PBCONST_ROOT
	#undef DEM_STOP_SEC_PBCONST_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_PBCONST
	#undef DEM_START_SEC_PBCONST
	#define START_SEC_CONST_PBCFG
#endif
#ifdef DEM_STOP_SEC_PBCONST
	#undef DEM_STOP_SEC_PBCONST
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  Dem END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DemIf START
**********************************************************************************************************************/

#ifdef DEMIF_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DEMIF_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef DEMIF_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DEMIF_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef DEMIF_START_SEC_VAR_CLEARED_8
	#undef DEMIF_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef DEMIF_STOP_SEC_VAR_CLEARED_8
	#undef DEMIF_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DEMIF_START_SEC_VAR_CLEARED_32
    #undef DEMIF_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef DEMIF_STOP_SEC_VAR_CLEARED_32
    #undef DEMIF_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
#endif

#ifdef DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DEMIF_START_SEC_CONST_UNSPECIFIED
	#undef DEMIF_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DEMIF_STOP_SEC_CONST_UNSPECIFIED
	#undef DEMIF_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  DemIf END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DfltConfigData START
**********************************************************************************************************************/

#ifdef DFLTCONFIGDATA_START_SEC_VAR_NOINIT_8
	#undef DFLTCONFIGDATA_START_SEC_VAR_NOINIT_8
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef DFLTCONFIGDATA_STOP_SEC_VAR_NOINIT_8
	#undef DFLTCONFIGDATA_STOP_SEC_VAR_NOINIT_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DfltConfigData END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgr START
**********************************************************************************************************************/

#ifdef DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
	#undef DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
	#undef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_GLOBALSHARED
#endif
#ifdef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif
#ifdef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

/**********************************************************************************************************************
*  DiagMgr END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgr6 START
**********************************************************************************************************************/

#ifdef DIAGMGR6_START_SEC_VAR_CLEARED_8
	#undef DIAGMGR6_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef DIAGMGR6_STOP_SEC_VAR_CLEARED_8
	#undef DIAGMGR6_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR6_START_SEC_VAR_CLEARED_16
	#undef DIAGMGR6_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef DIAGMGR6_STOP_SEC_VAR_CLEARED_16
	#undef DIAGMGR6_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR6_START_SEC_VAR_CLEARED_32
	#undef DIAGMGR6_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef DIAGMGR6_STOP_SEC_VAR_CLEARED_32
	#undef DIAGMGR6_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR6_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR6_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef DIAGMGR6_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR6_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagMgr8 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgr9 START
**********************************************************************************************************************/

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_8
	#undef DIAGMGR9_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
	#undef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_16
	#undef DIAGMGR9_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
	#undef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_32
	#undef DIAGMGR9_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
	#undef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagMgr9 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgr10 START
**********************************************************************************************************************/

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_8
	#undef DIAGMGR10_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
	#undef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_16
	#undef DIAGMGR10_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
	#undef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_32
	#undef DIAGMGR10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
	#undef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagMgr10 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgr11 START
**********************************************************************************************************************/

#ifdef DIAGMGR11_START_SEC_VAR_CLEARED_8
	#undef DIAGMGR11_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_11
#endif
#ifdef DIAGMGR11_STOP_SEC_VAR_CLEARED_8
	#undef DIAGMGR11_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR11_START_SEC_VAR_CLEARED_16
	#undef DIAGMGR11_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_11
#endif
#ifdef DIAGMGR11_STOP_SEC_VAR_CLEARED_16
	#undef DIAGMGR11_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR11_START_SEC_VAR_CLEARED_32
	#undef DIAGMGR11_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef DIAGMGR11_STOP_SEC_VAR_CLEARED_32
	#undef DIAGMGR11_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIAGMGR11_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR11_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef DIAGMGR11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGMGR11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagMgr8 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagMgrDemIf START
**********************************************************************************************************************/

#ifdef DIAGMGRDEMIF_START_SEC_VAR_16
	#undef DIAGMGRDEMIF_START_SEC_VAR_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef DIAGMGRDEMIF_STOP_SEC_VAR_16
	#undef DIAGMGRDEMIF_STOP_SEC_VAR_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagMgrDemIf END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DiagSvc START
**********************************************************************************************************************/

#ifdef DIAGSVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGSVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef DIAGSVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIAGSVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DIAGSVC_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIAGSVC_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef DIAGSVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIAGSVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef DIAGSVC_START_SEC_VAR_CLEARED_8
	#undef DIAGSVC_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef DIAGSVC_STOP_SEC_VAR_CLEARED_8
	#undef DIAGSVC_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DiagSvc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DigMSB START
**********************************************************************************************************************/

#ifdef DIGMSB_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSB_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef DIGMSB_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef DIGMSB_START_SEC_VAR_CLEARED_8
	#undef DIGMSB_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef DIGMSB_STOP_SEC_VAR_CLEARED_8
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIGMSB_START_SEC_VAR_CLEARED_16
	#undef DIGMSB_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef DIGMSB_STOP_SEC_VAR_CLEARED_16
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIGMSB_START_SEC_VAR_CLEARED_32
	#undef DIGMSB_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef DIGMSB_STOP_SEC_VAR_CLEARED_32
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIGMSB_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSB_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DIGMSB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DIGMSB_START_SEC_CONST_8
	#undef DIGMSB_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT
#endif
#ifdef DIGMSB_STOP_SEC_CONST_8
	#undef DIGMSB_STOP_SEC_CONST_8
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  DigMSB END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  DigPhsReasDiag START
**********************************************************************************************************************/

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  DigPhsReasDiag END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Dma START
**********************************************************************************************************************/

#ifdef DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Dma END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ElePwr START
**********************************************************************************************************************/

#ifdef ELEPWR_START_SEC_VAR_CLEARED_32
	#undef ELEPWR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef ELEPWR_STOP_SEC_VAR_CLEARED_32
	#undef ELEPWR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ElePwr END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ePWM START
**********************************************************************************************************************/

#ifdef EPWM_START_SEC_CODE
	#undef EPWM_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef EPWM_STOP_SEC_CODE
	#undef EPWM_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  ePWM END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EOTActuatorMng START
**********************************************************************************************************************/

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  EOTActuatorMng END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  EtDmpFw START
**********************************************************************************************************************/

#ifdef ETDMPFW_START_SEC_VAR_CLEARED_08
	#undef ETDMPFW_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef ETDMPFW_STOP_SEC_VAR_CLEARED_08
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR
#endif

#ifdef ETDMPFW_START_SEC_VAR_CLEARED_32
	#undef ETDMPFW_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef ETDMPFW_STOP_SEC_VAR_CLEARED_32
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  EtDmpFw END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  FaultLog START
**********************************************************************************************************************/

#ifdef FAULTLOG_START_SEC_VAR_CLEARED_32
	#undef FAULTLOG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef FAULTLOG_STOP_SEC_VAR_CLEARED_32
	#undef FAULTLOG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef FAULTLOG_START_SEC_VAR_CLEARED_16
	#undef FAULTLOG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef FAULTLOG_STOP_SEC_VAR_CLEARED_16
	#undef FAULTLOG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef FAULTLOG_START_SEC_VAR_CLEARED_8
	#undef FAULTLOG_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef FAULTLOG_STOP_SEC_VAR_CLEARED_8
	#undef FAULTLOG_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef FAULTLOG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef FAULTLOG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef FAULTLOG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef FAULTLOG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  FaultLog END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  Fbl START
**********************************************************************************************************************/

#ifdef FBLHEADER_START_SEC_CONST_EXPORT
	#undef FBLHEADER_START_SEC_CONST_EXPORT
	#define CONST_SEC_OPEN
	#pragma SET_DATA_SECTION(".FblHeader")
	#undef MEMMAP_ERROR
#endif
#ifdef FBLHEADER_STOP_SEC_CONST_EXPORT
	#undef FBLHEADER_STOP_SEC_CONST_EXPORT
	#define STOP_SEC_CONST
#endif

#ifdef MAGICFLAG_START_SEC_DATA_EXPORT
	#undef MAGICFLAG_START_SEC_DATA_EXPORT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".MagicFlag")
	#undef MEMMAP_ERROR
#endif
#ifdef MAGICFLAG_STOP_SEC_DATA_EXPORT
	#undef MAGICFLAG_STOP_SEC_DATA_EXPORT
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Fbl END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  FlsTst START
**********************************************************************************************************************/

#ifdef FLSTST_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef FLSTST_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FLSTST_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef FLSTST_STOP_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLSTST_START_SEC_VAR_UNSPECIFIED
	#undef FLSTST_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#endif
#ifdef FLSTST_STOP_SEC_VAR_UNSPECIFIED
	#undef FLSTST_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_16
	#undef FLSTST_START_SEC_VAR_16
	#define START_SEC_VAR_NOINIT_16BIT_0
#endif
#ifdef FLSTST_STOP_SEC_VAR_16
	#undef FLSTST_STOP_SEC_VAR_16
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_CLEARED_8
	#undef FLSTST_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_0
#endif
#ifdef FLSTST_STOP_SEC_VAR_CLEARED_8
	#undef FLSTST_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_CODE
	#undef MEMMAP_ERROR
	#undef FLSTST_START_SEC_CODE
#endif
#ifdef FLSTST_STOP_SEC_CODE
	#undef MEMMAP_ERROR
	#undef FLSTST_STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  FlsTst END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  FltInjection START
**********************************************************************************************************************/

#ifdef FLTINJECTION_START_SEC_VAR_CLEARED_32
	#undef FLTINJECTION_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED
#endif
#ifdef FLTINJECTION_STOP_SEC_VAR_CLEARED_32
	#undef FLTINJECTION_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  FltInjection END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  FrqDepDmpnInrtCmp START
**********************************************************************************************************************/

#ifdef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  FrqDepDmpnInrtCmp END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  HighFreqAssist START
**********************************************************************************************************************/

#ifdef HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
	#undef HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
	#undef HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  HighFreqAssist END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  HiLoadStall START
**********************************************************************************************************************/

#ifdef HILOADSTALL_START_SEC_VAR_CLEARED_16
	#undef HILOADSTALL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
	#undef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef HILOADSTALL_START_SEC_VAR_CLEARED_32
	#undef HILOADSTALL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
	#undef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  HiLoadStall END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  HOWDETECT START
**********************************************************************************************************************/

#ifdef HOWDETECT_START_SEC_CONST_16
	#undef HOWDETECT_START_SEC_CONST_16
	#define START_SEC_CONST_16BIT
#endif
#ifdef HOWDETECT_STOP_SEC_CONST_16
	#undef HOWDETECT_STOP_SEC_CONST_16
	#define STOP_SEC_VAR
#endif

#ifdef HOWDETECT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HOWDETECT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef HOWDETECT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HOWDETECT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef HOWDETECT_START_SEC_VAR_CLEARED_32
	#undef HOWDETECT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef HOWDETECT_STOP_SEC_VAR_CLEARED_32
	#undef HOWDETECT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  HOWDETECT END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  HwPwUp START
**********************************************************************************************************************/

#ifdef HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef HWPWUP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWPWUP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HWPWUP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWPWUP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  HwPwUp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  HWTQCORRLN START
**********************************************************************************************************************/

#ifdef HWTQCORRLN_START_SEC_VAR_CLEARED_8
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef HWTQCORRLN_STOP_SEC_VAR_CLEARED_8
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef HWTQCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_BOOLEAN 
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HWTQCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef HWTQCORRLN_START_SEC_VAR_CLEARED_32
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef HWTQCORRLN_STOP_SEC_VAR_CLEARED_32
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef HWTQCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HWTQCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef HWTQCORRLN_START_SEC_CODE
	#undef HWTQCORRLN_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef HWTQCORRLN_STOP_SEC_CODE
	#undef HWTQCORRLN_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  HWTQCORRLN END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  HWTQARBN START
**********************************************************************************************************************/

#ifdef HWTQARBN_START_SEC_VAR_CLEARED_8
	#undef HWTQARBN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef HWTQARBN_STOP_SEC_VAR_CLEARED_8
	#undef HWTQARBN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef HWTQARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQARBN_START_SEC_VAR_CLEARED_BOOLEAN 
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HWTQARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef HWTRQARBN_START_SEC_VAR_CLEARED_32
	#undef HWTRQARBN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef HWTRQARBN_STOP_SEC_VAR_CLEARED_32
	#undef HWTRQARBN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef HWTQARBN_START_SEC_CODE
	#undef HWTQARBN_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef HWTQARBN_STOP_SEC_CODE
	#undef HWTQARBN_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  HWTQARBN END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  HystComp START
**********************************************************************************************************************/

#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_16
	#undef HYSTCOMP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
	#undef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_32
	#undef HYSTCOMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
	#undef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  HystComp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  IoHwAbstractionUsr10 START
**********************************************************************************************************************/

#ifdef IOHWABSTRACTIONUSR10_START_SEC_VAR_CLEARED_16
	#undef IOHWABSTRACTIONUSR10_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef IOHWABSTRACTIONUSR10_STOP_SEC_VAR_CLEARED_16
	#undef IOHWABSTRACTIONUSR10_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef IOHWABSTRACTIONUSR10_START_SEC_VAR_CLEARED_32
	#undef IOHWABSTRACTIONUSR10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef IOHWABSTRACTIONUSR10_STOP_SEC_VAR_CLEARED_32
	#undef IOHWABSTRACTIONUSR10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  LmtCod END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  LmtCod START
**********************************************************************************************************************/

#ifdef LMTCOD_START_SEC_VAR_CLEARED_32
	#undef LMTCOD_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef LMTCOD_STOP_SEC_VAR_CLEARED_32
	#undef LMTCOD_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  LmtCod END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  LrnEOT START
**********************************************************************************************************************/

#ifdef LRNEOT_START_SEC_VAR_CLEARED_32
	#undef LRNEOT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef LRNEOT_STOP_SEC_VAR_CLEARED_32
	#undef LRNEOT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
	#undef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  LrnEOT END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  LOAMGR START
**********************************************************************************************************************/

#ifdef LOAMGR_START_SEC_VAR_CLEARED_08
	#undef LOAMGR_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef LOAMGR_STOP_SEC_VAR_CLEARED_08
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR
#endif

#ifdef LOAMGR_START_SEC_VAR_CLEARED_32
	#undef LOAMGR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef LOAMGR_STOP_SEC_VAR_CLEARED_32
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef LOAMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#undef LOAMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef LOAMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef LOAMGR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef LOAMGR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef LOAMGR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  LOAMGR END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrCtrlISR START
**********************************************************************************************************************/

#ifdef MTRCTRLIRQ_START_SEC_VAR_CLEARED_16
	#undef MTRCTRLIRQ_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_0
#endif
#ifdef MTRCTRLIRQ_STOP_SEC_VAR_CLEARED_16
	#undef MTRCTRLIRQ_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrCtrlISR END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrDrvDiag START
**********************************************************************************************************************/

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrDrvDiag END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrTempEst START
**********************************************************************************************************************/

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_32
	#undef MTRTEMPEST_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
	#undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrTempEst END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrVel START
**********************************************************************************************************************/

#ifdef MTRVEL_START_SEC_VAR_CLEARED_32
	#undef MTRVEL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRVEL_START_SEC_VAR_CLEARED_16
	#undef MTRVEL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef MTRVEL_START_SEC_VAR_CLEARED_8
	#undef MTRVEL_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef MTRVEL_STOP_SEC_VAR_CLEARED_8
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrVel END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrVel2 START
**********************************************************************************************************************/

#ifdef MTRVEL2_START_SEC_VAR_CLEARED_32
	#undef MTRVEL2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef MTRVEL2_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef MTRVEL2_START_SEC_VAR_CLEARED_16
	#undef MTRVEL2_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef MTRVEL2_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL2_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrVel2 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MtrVel3 START
**********************************************************************************************************************/

#ifdef MTRVEL3_START_SEC_VAR_CLEARED_8
	#undef MTRVEL3_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef MTRVEL3_STOP_SEC_VAR_CLEARED_8
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef MTRVEL3_START_SEC_VAR_CLEARED_16
	#undef MTRVEL3_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef MTRVEL3_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef MTRVEL3_START_SEC_VAR_CLEARED_32
	#undef MTRVEL3_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef MTRVEL3_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  MtrVel3 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  NHET1CFGANDUSE START
**********************************************************************************************************************/

#ifdef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_BOOLEAN
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_32
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_32
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_8
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_8
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef NHET1CFGANDUSE_START_SEC_CONST_8
	#undef NHET1CFGANDUSE_START_SEC_CONST_8
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NHET1CFGANDUSE_STOP_SEC_CONST_8
	#undef NHET1CFGANDUSE_STOP_SEC_CONST_8
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  NHET1CFGANDUSE END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  NtWrap START
**********************************************************************************************************************/

#ifdef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  NtWrap END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  NvMProxy START
**********************************************************************************************************************/

#ifdef NVMPROXY_START_SEC_CODE
	#undef NVMPROXY_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef NVMPROXY_STOP_SEC_CODE
	#undef NVMPROXY_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef NVMPROXY_START_SEC_VAR_NOINIT_8
	#undef NVMPROXY_START_SEC_VAR_NOINIT_8
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef NVMPROXY_STOP_SEC_VAR_NOINIT_8
	#undef NVMPROXY_STOP_SEC_VAR_NOINIT_8
	#define STOP_SEC_VAR
#endif

#ifdef NVMPROXY_START_SEC_CONST_UNSPECIFIED
	#undef NVMPROXY_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
	#undef NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  NvMProxy END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  OvrVoltMon START
**********************************************************************************************************************/

#ifdef OVRVOLTMON_START_SEC_VAR_CLEARED_16
	#undef OVRVOLTMON_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
	#undef OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  OvrVoltMon END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PeakCurrEst START
**********************************************************************************************************************/

#ifdef PEAKCURREST_START_SEC_VAR_CLEARED_32
	#undef PEAKCURREST_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef PEAKCURREST_STOP_SEC_VAR_CLEARED_32
	#undef PEAKCURREST_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PeakCurrEst END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PHASEABCFDBKMEAS START
**********************************************************************************************************************/

#ifdef PHASEABCFDBKMEAS_START_SEC_VAR_CLEARED_32
	#undef PHASEABCFDBKMEAS_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif

#ifdef PHASEABCFDBKMEAS_STOP_SEC_VAR_CLEARED_32
	#undef PHASEABCFDBKMEAS_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PHASEABCFDBKMEAS END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PICurrContrl START
**********************************************************************************************************************/

#ifdef PICURRCNTRL_START_SEC_VAR_CLEARED_32
	#undef PICURRCNTRL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif

#ifdef PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
	#undef PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef PICURRCNTRL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PICURRCNTRL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif

#ifdef PICURRCNTRL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PICURRCNTRL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PICurrContrl END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PosServo START
**********************************************************************************************************************/

#ifdef POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
	#undef POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef POSSERVO_START_SEC_VAR_CLEARED_32
	#undef POSSERVO_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef POSSERVO_STOP_SEC_VAR_CLEARED_32
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef POSSERVO_START_SEC_VAR_CLEARED_16
	#undef POSSERVO_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef POSSERVO_STOP_SEC_VAR_CLEARED_16
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PosServo END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PSASH START
**********************************************************************************************************************/

#ifdef PSASH_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PSASH_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef PSASH_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PSASH_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_INIT_8
	#undef PSASH_START_SEC_VAR_INIT_8
    #define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef PSASH_STOP_SEC_VAR_INIT_8
	#undef PSASH_STOP_SEC_VAR_INIT_8
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_CLEARED_8
	#undef PSASH_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef PSASH_STOP_SEC_VAR_CLEARED_8
	#undef PSASH_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_CLEARED_32
	#undef PSASH_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef PSASH_STOP_SEC_VAR_CLEARED_32
	#undef PSASH_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_INIT_16
	#undef PSASH_START_SEC_VAR_INIT_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef PSASH_STOP_SEC_VAR_INIT_16
	#undef PSASH_STOP_SEC_VAR_INIT_16
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_CLEARED_16
	#undef PSASH_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef PSASH_STOP_SEC_VAR_CLEARED_16
	#undef PSASH_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef PSASH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSASH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef PSASH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSASH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PSASH END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PSADMQ START
**********************************************************************************************************************/

#ifdef PSADMQ_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PSADMQ_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PSADMQ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef PSADMQ_START_SEC_VAR_INIT_8
	#undef PSADMQ_START_SEC_VAR_INIT_8
    #define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_INIT_8
	#undef PSADMQ_STOP_SEC_VAR_INIT_8
	#define STOP_SEC_VAR
#endif

#ifdef PSADMQ_START_SEC_VAR_CLEARED_8
	#undef PSADMQ_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_CLEARED_8
	#undef PSADMQ_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef PSADMQ_START_SEC_VAR_INIT_16
	#undef PSADMQ_START_SEC_VAR_INIT_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_INIT_16
	#undef PSADMQ_STOP_SEC_VAR_INIT_16
	#define STOP_SEC_VAR
#endif

#ifdef PSADMQ_START_SEC_VAR_CLEARED_16
	#undef PSADMQ_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_CLEARED_16
	#undef PSADMQ_STOP_SEC_VAR_INIT_16
	#define STOP_SEC_VAR
#endif

#ifdef PSADMQ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSADMQ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef PSADMQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSADMQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
*  PSADMQ END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PSADSG START
**********************************************************************************************************************/

#ifdef PSADSG_START_SEC_VAR_CLEARED_32
	#undef PSADSG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef PSADSG_STOP_SEC_VAR_CLEARED_32
	#undef PSADSG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
*  PSADSG END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PSATA START
**********************************************************************************************************************/

#ifdef PSATA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PSATA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef PSATA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PSATA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef PSATA_START_SEC_VAR_CLEARED_16
	#undef PSATA_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef PSATA_STOP_SEC_VAR_CLEARED_16
	#undef PSATA_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef PSATA_START_SEC_VAR_CLEARED_32
	#undef PSATA_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef PSATA_STOP_SEC_VAR_CLEARED_32
	#undef PSATA_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef PSATA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSATA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef PSATA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSATA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PSATA END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PSAAGARBN START
**********************************************************************************************************************/

#ifdef PSAAGARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PSAAGARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef PSAAGARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PSAAGARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef PSAAGARBN_START_SEC_VAR_CLEARED_32
	#undef PSAAGARBN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef PSAAGARBN_STOP_SEC_VAR_CLEARED_32
	#undef PSAAGARBN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef PSAAGARBN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSAAGARBN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef PSAAGARBN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PSAAGARBN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PSATA END
**********************************************************************************************************************/


/**********************************************************************************************************************
*  PwmCdd START
**********************************************************************************************************************/

#ifdef PWMCDD_START_SEC_VAR_CLEARED_16
	#undef PWMCDD_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef PWMCDD_STOP_SEC_VAR_CLEARED_16
	#undef PWMCDD_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PwmCdd END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  PwrLmtFuncCr START
**********************************************************************************************************************/

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	#undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	#undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  PwrLmtFuncCr END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  QuadDet START
**********************************************************************************************************************/

#ifdef QUADDET_START_SEC_VAR_INIT_8
	#undef QUADDET_START_SEC_VAR_INIT_8
	#define START_SEC_VAR_INIT_8BIT_10
#endif
#ifdef QUADDET_STOP_SEC_VAR_INIT_8
	#undef QUADDET_STOP_SEC_VAR_INIT_8
	#define STOP_SEC_VAR
#endif

#ifdef QUADDET_START_SEC_VAR_INIT_32
	#undef QUADDET_START_SEC_VAR_INIT_32
	#define START_SEC_VAR_INIT_32BIT_10
#endif
#ifdef QUADDET_STOP_SEC_VAR_INIT_32
	#undef QUADDET_STOP_SEC_VAR_INIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  QuadDet END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ResetCause START
**********************************************************************************************************************/

#ifdef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#undef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".resetcause")
	#undef MEMMAP_ERROR
#endif
#ifdef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#undef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ResetCause END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Return START
**********************************************************************************************************************/

#ifdef RETURN_START_SEC_VAR_CLEARED_32
	#undef RETURN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef RETURN_STOP_SEC_VAR_CLEARED_32
	#undef RETURN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef RETURN_START_SEC_VAR_CLEARED_16
	#undef RETURN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef RETURN_STOP_SEC_VAR_CLEARED_16
	#undef RETURN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Return END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ReturnFirewall START
**********************************************************************************************************************/

#ifdef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
	#undef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
	#undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ReturnFirewall END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ShtdnMech START
**********************************************************************************************************************/

#ifdef SHTDNMECH_START_SEC_VAR_CLEARED_32
	#undef SHTDNMECH_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
	#undef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SHTDNMECH_START_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ShtdnMech END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SignlCondn START
**********************************************************************************************************************/

#ifdef SIGNLCONDN_START_SEC_VAR_NOINIT_32
	#undef SIGNLCONDN_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32BIT_11
#endif
#ifdef SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
	#undef SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  SignlCondn END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SpiNxt START
**********************************************************************************************************************/

#ifdef SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef SPINXT_START_SEC_CODE
	#undef SPINXT_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef SPINXT_STOP_SEC_CODE
	#undef SPINXT_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  SpiNxt END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SrlComDriver START
**********************************************************************************************************************/

#ifdef SRLCOMDRIVER_START_SEC_VAR_CLEARED_32
	#undef SRLCOMDRIVER_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_32
	#undef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMDRIVER_START_SEC_VAR_CLEARED_16
	#undef SRLCOMDRIVER_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_16
	#undef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMDRIVER_START_SEC_VAR_CLEARED_8
	#undef SRLCOMDRIVER_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_8
	#undef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMDRIVER_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMDRIVER_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMDRIVER_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SRLCOMDRIVER_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SRLCOMDRIVER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  SrlComDriver END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SrlComInput START
**********************************************************************************************************************/

#ifdef SRLCOMINPUT_START_SEC_VAR_CLEARED_32
	#undef SRLCOMINPUT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
	#undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMINPUT_START_SEC_VAR_CLEARED_16
	#undef SRLCOMINPUT_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
	#undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMINPUT_START_SEC_VAR_CLEARED_8
	#undef SRLCOMINPUT_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
	#undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  SrlComInput END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SrlComOutput START
**********************************************************************************************************************/

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNDEFINED
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNDEFINED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNDEFINED
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNDEFINED
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  SrlComOutput END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StabilityComp START
**********************************************************************************************************************/

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_32
	#undef STABILITYCOMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
	#undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_16
	#undef STABILITYCOMP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
	#undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StabilityComp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StabilityComp2 START
**********************************************************************************************************************/

#ifdef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
	#undef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
	#undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StabilityComp2 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StaMd START
**********************************************************************************************************************/

#ifdef STAMD_START_SEC_CONST_UNSPECIFIED
	#undef STAMD_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif
#ifdef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_GLOBALSHARED
#endif
#ifdef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
	#undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
	#define STOP_SEC_VAR
#endif

#ifdef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED
#endif
#ifdef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
	#undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StaMd END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StaMd6 START
**********************************************************************************************************************/

#ifdef STAMD6_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD6_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_6
#endif
#ifdef STAMD6_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD6_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD6_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD6_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_INIT_UNSPECIFIED_6
#endif
#ifdef STAMD6_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD6_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef STAMD6_START_SEC_VAR_CLEARED_32
	#undef STAMD6_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef STAMD6_STOP_SEC_VAR_CLEARED_32
	#undef STAMD6_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD6_START_SEC_VAR_CLEARED_16
	#undef STAMD6_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef STAMD6_STOP_SEC_VAR_CLEARED_16
	#undef STAMD6_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StaMd6 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StaMd9 START
**********************************************************************************************************************/

#ifdef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD9_START_SEC_VAR_CLEARED_32
	#undef STAMD9_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef STAMD9_STOP_SEC_VAR_CLEARED_32
	#undef STAMD9_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StaMd9 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StaMd10 START
**********************************************************************************************************************/

#ifdef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_10
#endif
#ifdef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_32
	#undef STAMD10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef STAMD10_STOP_SEC_VAR_CLEARED_32
	#undef STAMD10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_8
	#undef STAMD10_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef STAMD10_STOP_SEC_VAR_CLEARED_8
	#undef STAMD10_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StaMd10 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StaMd11 START
**********************************************************************************************************************/

#ifdef STAMD11_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD11_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_11
#endif
#ifdef STAMD11_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD11_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef STAMD11_START_SEC_VAR_CLEARED_32
	#undef STAMD11_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_11
#endif
#ifdef STAMD11_STOP_SEC_VAR_CLEARED_32
	#undef STAMD11_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STAMD11_START_SEC_VAR_CLEARED_16
	#undef STAMD11_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_11
#endif
#ifdef STAMD11_STOP_SEC_VAR_CLEARED_16
	#undef STAMD11_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StaMd8 END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  StOpCtrl START
**********************************************************************************************************************/

#ifdef STOPCTRL_START_SEC_VAR_CLEARED_32
	#undef STOPCTRL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef STOPCTRL_STOP_SEC_VAR_CLEARED_32
	#undef STOPCTRL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef STOPCTRL_START_SEC_VAR_INIT_08
	#undef STOPCTRL_START_SEC_VAR_INIT_08
	#define START_SEC_VAR_INIT_8BIT_10
#endif
#ifdef STOPCTRL_STOP_SEC_VAR_INIT_08
	#undef STOPCTRL_STOP_SEC_VAR_INIT_08
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  StOpCtrl END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Sweep START
**********************************************************************************************************************/

#ifdef SWEEP_START_SEC_VAR_CLEARED_32
	#undef SWEEP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED
#endif
#ifdef SWEEP_STOP_SEC_VAR_CLEARED_32
	#undef SWEEP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef SWEEP_START_SEC_VAR_CLEARED_16
	#undef SWEEP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_GLOBALSHARED
#endif
#ifdef SWEEP_STOP_SEC_VAR_CLEARED_16
	#undef SWEEP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED
#endif
#ifdef SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Sweep END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ThrmlDutyCycle START
**********************************************************************************************************************/

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
	#undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
	#undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
	#undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
	#undef THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  ThrmlDutyCycle END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TmprlMon START
**********************************************************************************************************************/

#ifdef TMPRLMON_START_SEC_CONST_UNSPECIFIED
	#undef TMPRLMON_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
	#undef TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_8
	#undef TMPRLMON_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_8
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_32
	#undef TMPRLMON_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_32
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_16
	#undef TMPRLMON_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_16
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif
#ifdef TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  TmprlMon END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TRANLDAMPG START
**********************************************************************************************************************/

#ifdef TRANLDAMPG_START_SEC_VAR_CLEARED_08
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef TRANLDAMPG_STOP_SEC_VAR_CLEARED_08
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR
#endif

#ifdef TRANLDAMPG_START_SEC_VAR_CLEARED_32
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef TRANLDAMPG_STOP_SEC_VAR_CLEARED_32
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TRANLDAMPG_START_SEC_VAR_CLEARED_16
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef TRANLDAMPG_STOP_SEC_VAR_CLEARED_16
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TRANLDAMPG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_8BIT_10
#endif
#ifdef TRANLDAMPG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef TRANLDAMPG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef TRANLDAMPG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  TRANLDAMPG END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TrqCanc START
**********************************************************************************************************************/

#ifdef TRQCANC_START_SEC_VAR_CLEARED_16
	#undef TRQCANC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef TRQCANC_STOP_SEC_VAR_CLEARED_16
	#undef TRQCANC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TRQCANC_START_SEC_VAR_CLEARED_32
	#undef TRQCANC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef TRQCANC_STOP_SEC_VAR_CLEARED_32
	#undef TRQCANC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TRQCANC_START_SEC_CONST_16
	#undef TRQCANC_START_SEC_CONST_16
	#define START_SEC_CONST_16BIT
#endif
#ifdef TRQCANC_STOP_SEC_CONST_16
	#undef TRQCANC_STOP_SEC_CONST_16
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  TrqCanc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TrqLOA START
**********************************************************************************************************************/

#ifdef TRQLOA_START_SEC_VAR_CLEARED_32
	#undef TRQLOA_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef TRQLOA_STOP_SEC_VAR_CLEARED_32
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TRQLOA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQLOA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef TRQLOA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef TRQLOA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQLOA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef TRQLOA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  TrqLOA END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TqRsDg START
**********************************************************************************************************************/

#ifdef TQRSDG_START_SEC_VAR_CLEARED_32
	#undef TQRSDG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef TQRSDG_STOP_SEC_VAR_CLEARED_32
	#undef TQRSDG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef TQRSDG_START_SEC_VAR_CLEARED_16
	#undef TQRSDG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef TQRSDG_STOP_SEC_VAR_CLEARED_16
	#undef TQRSDG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif
#ifdef TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  TqRsDg END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TuningSelAuth START
**********************************************************************************************************************/

#ifdef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
	#undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_11
#endif
#ifdef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
	#undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
#endif
#ifdef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  TuningSelAuth END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  uDiag START
**********************************************************************************************************************/

#ifdef STARTUP_START_SEC_VAR_NOINIT_32
	#undef STARTUP_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_0
#endif
#ifdef STARTUP_STOP_SEC_VAR_NOINIT_32
	#undef STARTUP_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR
#endif

#ifdef STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
	#undef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
	#define START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#endif
#ifdef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#undef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef UDIAG_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef UDIAG_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef UDIAG_STOP_SEC_CONST_UNSPECIFIED
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_16
	#undef UDIAG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_10
#endif
#ifdef UDIAG_STOP_SEC_VAR_CLEARED_16
	#undef UDIAG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
#endif
#ifdef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_CLEARED_32
	#undef UDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_10
#endif
#ifdef UDIAG_STOP_SEC_VAR_CLEARED_32
	#undef UDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
	#undef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
	#define START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#endif
#ifdef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
	#undef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  uDiag END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  VehDyn START
**********************************************************************************************************************/

#ifdef VEHDYN_START_SEC_VAR_CLEARED_32
	#undef VEHDYN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef VEHDYN_STOP_SEC_VAR_CLEARED_32
	#undef VEHDYN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef VEHDYN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef VEHDYN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef VEHDYN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef VEHDYN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef VEHDYN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef VEHDYN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef VEHDYN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef VEHDYN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

#ifdef VEHDYN_START_SEC_VAR_CLEARED_8
	#undef VEHDYN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_8BIT_9
#endif

#ifdef VEHDYN_STOP_SEC_VAR_CLEARED_8
	#undef VEHDYN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif




/**********************************************************************************************************************
*  VehDyn END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  VehPwrMd START
**********************************************************************************************************************/

#ifdef VEHPWRMD_START_SEC_VAR_CLEARED_32
	#undef VEHPWRMD_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef VEHPWRMD_STOP_SEC_VAR_CLEARED_32
	#undef VEHPWRMD_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
#endif

#ifdef VEHPWRMD_START_SEC_VAR_CLEARED_8
	#undef VEHPWRMD_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_ZERO_INIT_32BIT_9
#endif
#ifdef VEHPWRMD_STOP_SEC_VAR_CLEARED_8
	#undef VEHPWRMD_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
#endif

#ifdef VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
	#undef VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
#endif
#ifdef VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  VehPwrMd END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  VehSpdLmt START
**********************************************************************************************************************/

#ifdef VEHSPDLMT_START_SEC_VAR_CLEARED_16
	#undef VEHSPDLMT_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_ZERO_INIT_16BIT_9
#endif
#ifdef VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
	#undef VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  VehSpdLmt END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Xcp START
**********************************************************************************************************************/

#ifdef XCP_START_SEC_CODE
	#undef XCP_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef XCP_STOP_SEC_CODE
	#undef XCP_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef XCP_START_SEC_CONST_UNSPECIFIED
	#undef XCP_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef XCP_STOP_SEC_CONST_UNSPECIFIED
	#undef XCP_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_16BIT
	#undef XCP_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef XCP_STOP_SEC_CONST_16BIT
	#undef XCP_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_8BIT
	#undef XCP_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef XCP_STOP_SEC_CONST_8BIT
	#undef XCP_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef XCP_START_SEC_VAR_NOINIT_8BIT
	#undef XCP_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef XCP_STOP_SEC_VAR_NOINIT_8BIT
	#undef XCP_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Xcp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  CanXcp START
**********************************************************************************************************************/

#ifdef CANXCP_START_SEC_CODE
	#undef CANXCP_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef CANXCP_STOP_SEC_CODE
	#undef CANXCP_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef CANXCP_START_SEC_CONST_8BIT
	#undef CANXCP_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef CANXCP_STOP_SEC_CONST_8BIT
	#undef CANXCP_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef CANXCP_START_SEC_PBCFG_ROOT
	#undef CANXCP_START_SEC_PBCFG_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef CANXCP_STOP_SEC_PBCFG_ROOT
	#undef CANXCP_STOP_SEC_PBCFG_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef CANXCP_START_SEC_PBCFG
	#undef CANXCP_START_SEC_PBCFG
	#define START_SEC_CONST_PBCFG
#endif
#ifdef CANXCP_STOP_SEC_PBCFG
	#undef CANXCP_STOP_SEC_PBCFG
	#define STOP_SEC_CONST
#endif

#ifdef CANXCP_START_SEC_VAR_NOINIT_8BIT
	#undef CANXCP_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
	#undef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  CanXcp END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Dio START
**********************************************************************************************************************/

#ifdef DIO_START_SEC_CODE
	#undef DIO_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef DIO_STOP_SEC_CODE
	#undef DIO_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
	#undef DIO_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_32BIT
#endif
#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
	#undef DIO_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  Dio END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Fee START
**********************************************************************************************************************/

#ifdef FEE_START_SEC_CODE
	#undef FEE_START_SEC_CODE
	#define START_SEC_CODE
	/* open var section for function-level static variables */
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef FEE_STOP_SEC_CODE
	#undef FEE_STOP_SEC_CODE
	#define STOP_SEC_CODE
	#define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
	#undef FEE_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
	#undef FEE_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
	#undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_6
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Fee END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Gpt START
**********************************************************************************************************************/

#ifdef GPT_START_SEC_CODE
	#undef GPT_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef GPT_STOP_SEC_CODE
	#undef GPT_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_ISR
	#undef GPT_START_SEC_CODE_ISR
	#define START_SEC_CODE_ISR
#endif
#ifdef GPT_STOP_SEC_CODE_ISR
	#undef GPT_STOP_SEC_CODE_ISR
	#define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PBCFG_ROOT
	#undef GPT_START_SEC_PBCFG_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef GPT_STOP_SEC_PBCFG_ROOT
	#undef GPT_STOP_SEC_PBCFG_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PBCFG
	#undef GPT_START_SEC_PBCFG
	#define START_SEC_CONST_PBCFG
#endif
#ifdef GPT_STOP_SEC_PBCFG
	#undef GPT_STOP_SEC_PBCFG
	#define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_32BIT
	#undef GPT_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef GPT_STOP_SEC_CONST_32BIT
	#undef GPT_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_32BIT
	#undef GPT_START_SEC_VAR_32BIT
	#define START_SEC_VAR_NOINIT_32BIT_6
#endif
#ifdef GPT_STOP_SEC_VAR_32BIT
	#undef GPT_STOP_SEC_VAR_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
	#undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_UNSPECIFIED
	#undef GPT_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef GPT_STOP_SEC_VAR_UNSPECIFIED
	#undef GPT_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Gpt END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Mcu START
**********************************************************************************************************************/

#ifdef MCU_START_SEC_CODE
	#undef MCU_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef MCU_STOP_SEC_CODE
	#undef MCU_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_PBCFG
	#undef MCU_START_SEC_PBCFG
	#define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG
	#undef MCU_STOP_SEC_PBCFG
	#define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PBCFG_ROOT
	#undef MCU_START_SEC_PBCFG_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG_ROOT
	#undef MCU_STOP_SEC_PBCFG_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Mcu END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Port START
**********************************************************************************************************************/

#ifdef PORT_START_SEC_CODE
	#undef PORT_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef PORT_STOP_SEC_CODE
	#undef PORT_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PBCODE
	#undef PORT_START_SEC_PBCODE
	#define START_SEC_CODE
#endif
#ifdef PORT_STOP_SEC_PBCODE
	#undef PORT_STOP_SEC_PBCODE
	#define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PBCFG
	#undef PORT_START_SEC_PBCFG
	#define START_SEC_CONST_PBCFG
#endif
#ifdef PORT_STOP_SEC_PBCFG
	#undef PORT_STOP_SEC_PBCFG
	#define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PBCFG_ROOT
	#undef PORT_START_SEC_PBCFG_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef PORT_STOP_SEC_PBCFG_ROOT
	#undef PORT_STOP_SEC_PBCFG_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_VAR_UNSPECIFIED
	#undef PORT_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_6
#endif
#ifdef PORT_STOP_SEC_VAR_UNSPECIFIED
	#undef PORT_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Port END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Wdg START
**********************************************************************************************************************/

#ifdef WDG_START_SEC_CODE
	#undef WDG_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef WDG_STOP_SEC_CODE
	#undef WDG_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef WDG_START_SEC_CONST_8BIT
	#undef WDG_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef WDG_STOP_SEC_CONST_8BIT
	#undef WDG_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_CONST_16BIT
	#undef WDG_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef WDG_STOP_SEC_CONST_16BIT
	#undef WDG_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_CONST_32BIT
	#undef WDG_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef WDG_STOP_SEC_CONST_32BIT
	#undef WDG_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_CONST_UNSPECIFIED
	#undef WDG_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDG_STOP_SEC_CONST_UNSPECIFIED
	#undef WDG_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_VAR_8BIT
	#undef WDG_START_SEC_VAR_8BIT
	#define START_SEC_VAR_INIT_8BIT_0
#endif
#ifdef WDG_STOP_SEC_VAR_8BIT
	#undef WDG_STOP_SEC_VAR_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDG_START_SEC_VAR_16BIT
	#undef WDG_START_SEC_VAR_16BIT
	#define START_SEC_VAR_INIT_16BIT_0
#endif
#ifdef WDG_STOP_SEC_VAR_16BIT
	#undef WDG_STOP_SEC_VAR_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDG_START_SEC_VAR_32BIT
	#undef WDG_START_SEC_VAR_32BIT
	#define START_SEC_VAR_INIT_32BIT_0
#endif
#ifdef WDG_STOP_SEC_VAR_32BIT
	#undef WDG_STOP_SEC_VAR_32BIT
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Wdg END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  IoHwAb START
**********************************************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
	#undef IOHWAB_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
	#undef IOHWAB_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef IOHWAB_START_SEC_CONST_32BIT
	#undef IOHWAB_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32BIT
	#undef IOHWAB_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  IoHwAb END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  MemIf START
**********************************************************************************************************************/

#ifdef MEMIF_START_SEC_CONST_8BIT
	#undef MEMIF_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef MEMIF_STOP_SEC_CONST_8BIT
	#undef MEMIF_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef MEMIF_START_SEC_CONST_32BIT
	#undef MEMIF_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef MEMIF_STOP_SEC_CONST_32BIT
	#undef MEMIF_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef MEMIF_START_SEC_CODE
	#undef MEMIF_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef MEMIF_STOP_SEC_CODE
	#undef MEMIF_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
*  MemIf END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  WdgIf START
**********************************************************************************************************************/

#ifdef WDGIF_START_SEC_CODE
	#undef WDGIF_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef WDGIF_STOP_SEC_CODE
	#undef WDGIF_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#if defined WDGIF_START_SEC_VAR_INIT_8BIT
	#undef WDGIF_START_SEC_VAR_INIT_8BIT
	#define START_SEC_VAR_INIT_8BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_INIT_8BIT
	#undef WDGIF_STOP_SEC_VAR_INIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_INIT_16BIT
	#undef WDGIF_START_SEC_VAR_INIT_16BIT
	#define START_SEC_VAR_INIT_16BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_INIT_16BIT
	#undef WDGIF_STOP_SEC_VAR_INIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_INIT_32BIT
	#undef WDGIF_START_SEC_VAR_INIT_32BIT
	#define START_SEC_VAR_INIT_32BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_INIT_32BIT
	#undef WDGIF_STOP_SEC_VAR_INIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
	#undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_NOINIT_8BIT
	#undef WDGIF_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_NOINIT_8BIT
	#undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_NOINIT_16BIT
	#undef WDGIF_START_SEC_VAR_NOINIT_16BIT
	#define START_SEC_VAR_NOINIT_16BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_NOINIT_16BIT
	#undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_NOINIT_32BIT
	#undef WDGIF_START_SEC_VAR_NOINIT_32BIT
	#define START_SEC_VAR_NOINIT_32BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_NOINIT_32BIT
	#undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
	#undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
	#define START_SEC_VAR_ZERO_INIT_8BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
	#undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
	#undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
	#define START_SEC_VAR_ZERO_INIT_16BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
	#undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
	#define START_SEC_VAR_ZERO_INIT_32BIT_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGIF_START_SEC_CONST_8BIT
	#undef WDGIF_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef WDGIF_STOP_SEC_CONST_8BIT
	#undef WDGIF_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGIF_START_SEC_CONST_16BIT
	#undef WDGIF_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef WDGIF_STOP_SEC_CONST_16BIT
	#undef WDGIF_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGIF_START_SEC_CONST_32BIT
	#undef WDGIF_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef WDGIF_STOP_SEC_CONST_32BIT
	#undef WDGIF_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGIF_START_SEC_CONST_UNSPECIFIED
	#undef WDGIF_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDGIF_STOP_SEC_CONST_UNSPECIFIED
	#undef WDGIF_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  WdgIf END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  NvM START
**********************************************************************************************************************/

#ifdef NVM_START_SEC_CODE
	#undef NVM_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef NVM_STOP_SEC_CODE
	#undef NVM_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef NVM_START_SEC_CONST_8BIT
	#undef NVM_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8BIT
	#undef NVM_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16BIT
	#undef NVM_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16BIT
	#undef NVM_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
	#undef NVM_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
	#undef NVM_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
	#undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
	#undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
	#define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_8BIT
	#undef NVM_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8BIT
	#undef NVM_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_UNSPECIFIED
	#undef NVM_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
	#undef NVM_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_FAST_8BIT
	#undef NVM_START_SEC_VAR_FAST_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8BIT
	#undef NVM_STOP_SEC_VAR_FAST_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
	#undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
	#undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  NvM END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Crc START
**********************************************************************************************************************/

#ifdef CRC_START_SEC_CODE
	#undef CRC_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CODE
	#undef CRC_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef CRC_START_SEC_CONST_8BIT
	#undef CRC_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef CRC_STOP_SEC_CONST_8BIT
	#undef CRC_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_16BIT
	#undef CRC_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef CRC_STOP_SEC_CONST_16BIT
	#undef CRC_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_32BIT
	#undef CRC_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef CRC_STOP_SEC_CONST_32BIT
	#undef CRC_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  Crc END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Det START
**********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
	#undef DET_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
	#undef DET_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_UNSPECIFIED
	#undef DET_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef DET_STOP_SEC_VAR_UNSPECIFIED
	#undef DET_STOP_SEC_VAR_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  Det START
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EcuM START
**********************************************************************************************************************/

#ifdef ECUM_START_SEC_CODE
	#undef ECUM_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef ECUM_STOP_SEC_CODE
	#undef ECUM_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#ifdef ECUM_START_SEC_CODE_SET_BOOT_TARGET
	#undef ECUM_START_SEC_CODE_SET_BOOT_TARGET
	#define START_SEC_CODE
#endif
#ifdef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
	#undef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
	#define STOP_SEC_CODE
#endif

#ifdef ECUM_START_SEC_CODE_GET_BOOT_TARGET
	#undef ECUM_START_SEC_CODE_GET_BOOT_TARGET
	#define START_SEC_CODE
#endif
#ifdef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
	#undef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
	#define STOP_SEC_CODE
#endif

#ifdef ECUM_START_SEC_CONST_8BIT
	#undef ECUM_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
	#undef ECUM_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
	#undef ECUM_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
	#undef ECUM_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG_ROOT
	#undef ECUM_START_SEC_CONST_PBCFG_ROOT
	#define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG_ROOT
	#undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
	#define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG
	#undef ECUM_START_SEC_CONST_PBCFG
	#define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG
	#undef ECUM_STOP_SEC_CONST_PBCFG
	#define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
	#undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
	/* Intentional mapping to NOINIT section due to conflicting mapping in header */
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
	#undef ECUM_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_6
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
	#undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
	#undef ECUM_START_SEC_VAR_NOINIT_16BIT
	#define START_SEC_VAR_NOINIT_16BIT_6
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
	#undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_6
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
*  EcuM END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  WdgM START
**********************************************************************************************************************/

#if defined WDGM_START_SEC_CODE
	#undef WDGM_START_SEC_CODE
	#define START_SEC_CODE
#endif
#ifdef WDGM_STOP_SEC_CODE
	#undef WDGM_STOP_SEC_CODE
	#define STOP_SEC_CODE
#endif

#if defined WDGM_START_SEC_VAR_INIT_8BIT
	#undef WDGM_START_SEC_VAR_INIT_8BIT
	#define START_SEC_VAR_INIT_8BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_INIT_8BIT
	#undef WDGM_STOP_SEC_VAR_INIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_INIT_16BIT
	#undef WDGM_START_SEC_VAR_INIT_16BIT
	#define START_SEC_VAR_INIT_16BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_INIT_16BIT
	#undef WDGM_STOP_SEC_VAR_INIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_INIT_32BIT
	#undef WDGM_START_SEC_VAR_INIT_32BIT
	#define START_SEC_VAR_INIT_32BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_INIT_32BIT
	#undef WDGM_STOP_SEC_VAR_INIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_INIT_UNSPECIFIED
	#undef WDGM_START_SEC_VAR_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_INIT_32BIT
	#undef WDGM_GLOBAL_START_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_INIT_32BIT
	#undef WDGM_GLOBAL_STOP_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_INIT_32BIT
	#undef WDGM_GLOBAL_SHARED_START_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_INIT_32BIT
	#undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_START_SEC_VAR_NOINIT_8BIT
	#undef WDGM_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_NOINIT_8BIT
	#undef WDGM_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_NOINIT_16BIT
	#undef WDGM_START_SEC_VAR_NOINIT_16BIT
	#define START_SEC_VAR_NOINIT_16BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_NOINIT_16BIT
	#undef WDGM_STOP_SEC_VAR_NOINIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_NOINIT_32BIT
	#undef WDGM_START_SEC_VAR_NOINIT_32BIT
	#define START_SEC_VAR_NOINIT_32BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_NOINIT_32BIT
	#undef WDGM_STOP_SEC_VAR_NOINIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#endif
#ifdef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_NOINIT_32BIT
	#undef WDGM_GLOBAL_START_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_32BIT
	#undef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_32BIT
	#undef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_32BIT
	#undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_START_SEC_VAR_ZERO_INIT_8BIT
	#undef WDGM_START_SEC_VAR_ZERO_INIT_8BIT
	#define START_SEC_VAR_ZERO_INIT_8BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_ZERO_INIT_8BIT
	#undef WDGM_STOP_SEC_VAR_ZERO_INIT_8BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_ZERO_INIT_16BIT
	#undef WDGM_START_SEC_VAR_ZERO_INIT_16BIT
	#define START_SEC_VAR_ZERO_INIT_16BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_ZERO_INIT_16BIT
	#undef WDGM_STOP_SEC_VAR_ZERO_INIT_16BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_START_SEC_VAR_ZERO_INIT_32BIT
	#define START_SEC_VAR_ZERO_INIT_32BIT_0
#endif
#ifdef WDGM_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_STOP_SEC_VAR_ZERO_INIT_32BIT
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef WDGM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
#endif
#ifdef WDGM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef WDGM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define STOP_SEC_VAR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_GLOBAL_START_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_GLOBAL_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_32BIT
	#undef WDGM_GLOBAL_START_SEC_VAR_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_32BIT
	#undef WDGM_GLOBAL_STOP_SEC_VAR_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_BOOLEAN
	#undef WDGM_GLOBAL_START_SEC_VAR_BOOLEAN
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_BOOLEAN
	#undef WDGM_GLOBAL_STOP_SEC_VAR_BOOLEAN
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_GLOBAL_SHARED_START_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif
#ifdef WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

#ifdef WDGM_START_SEC_CONST_8BIT
	#undef WDGM_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#endif
#ifdef WDGM_STOP_SEC_CONST_8BIT
	#undef WDGM_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGM_START_SEC_CONST_16BIT
	#undef WDGM_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#endif
#ifdef WDGM_STOP_SEC_CONST_16BIT
	#undef WDGM_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGM_START_SEC_CONST_32BIT
	#undef WDGM_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#endif
#ifdef WDGM_STOP_SEC_CONST_32BIT
	#undef WDGM_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
#endif

#ifdef WDGM_START_SEC_CONST_UNSPECIFIED
	#undef WDGM_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDGM_STOP_SEC_CONST_UNSPECIFIED
	#undef WDGM_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
*  WdgM END
**********************************************************************************************************************/



/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
	 ((defined START_SEC_CODE                          ) || \
	  (defined START_SEC_CODE_FAST                     ) || \
	  (defined START_SEC_CODE_ISR                      )    \
	  ))
	#error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
	 ((defined START_SEC_CONST_8BIT                    ) || \
	  (defined START_SEC_CONST_16BIT                   ) || \
	  (defined START_SEC_CONST_32BIT                   ) || \
	  (defined START_SEC_CONST_UNSPECIFIED             ) || \
	  (defined START_SEC_CONST_FAST_8BIT               ) || \
	  (defined START_SEC_CONST_FAST_16BIT              ) || \
	  (defined START_SEC_CONST_FAST_32BIT              ) || \
	  (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
	  (defined START_SEC_CONST_PBCFG                   )    \
	  ))
	#error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)	&& \
	  ( (defined START_SEC_VAR_INIT_8BIT							) || \
		(defined START_SEC_VAR_INIT_16BIT							) || \
		(defined START_SEC_VAR_INIT_32BIT							) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED						) || \
		(defined START_SEC_VAR_NOINIT_8BIT							) || \
		(defined START_SEC_VAR_NOINIT_16BIT							) || \
		(defined START_SEC_VAR_NOINIT_32BIT							) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED					) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT						) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT						) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT						) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED				) || \
		(defined START_SEC_VAR_FAST_INIT_8BIT						) || \
		(defined START_SEC_VAR_FAST_INIT_16BIT						) || \
		(defined START_SEC_VAR_FAST_INIT_32BIT						) || \
		(defined START_SEC_VAR_FAST_INIT_UNSPECIFIED				) || \
		(defined START_SEC_VAR_FAST_NOINIT_8BIT						) || \
		(defined START_SEC_VAR_FAST_NOINIT_16BIT					) || \
		(defined START_SEC_VAR_FAST_NOINIT_32BIT					) || \
		(defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED				) || \
		(defined START_SEC_VAR_FAST_ZERO_INIT_8BIT					) || \
		(defined START_SEC_VAR_FAST_ZERO_INIT_16BIT					) || \
		(defined START_SEC_VAR_FAST_ZERO_INIT_32BIT					) || \
		(defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED			) || \
		(defined START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED			) || \
		(defined START_SEC_VAR_INIT_8BIT_0							) || \
		(defined START_SEC_VAR_INIT_16BIT_0							) || \
		(defined START_SEC_VAR_INIT_32BIT_0							) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_0					) || \
		(defined START_SEC_VAR_NOINIT_8BIT_0						) || \
		(defined START_SEC_VAR_NOINIT_16BIT_0						) || \
		(defined START_SEC_VAR_NOINIT_32BIT_0						) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_0					) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_0						) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_0					) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_0					) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0				) || \
		(defined START_SEC_VAR_INIT_8BIT_6							) || \
		(defined START_SEC_VAR_INIT_16BIT_6							) || \
		(defined START_SEC_VAR_INIT_32BIT_6							) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_6					) || \
		(defined START_SEC_VAR_NOINIT_8BIT_6						) || \
		(defined START_SEC_VAR_NOINIT_16BIT_6						) || \
		(defined START_SEC_VAR_NOINIT_32BIT_6						) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_6					) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_6						) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_6					) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_6					) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6				) || \
		(defined START_SEC_VAR_INIT_8BIT_9							) || \
		(defined START_SEC_VAR_INIT_16BIT_9							) || \
		(defined START_SEC_VAR_INIT_32BIT_9							) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_9					) || \
		(defined START_SEC_VAR_NOINIT_8BIT_9						) || \
		(defined START_SEC_VAR_NOINIT_16BIT_9						) || \
		(defined START_SEC_VAR_NOINIT_32BIT_9						) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_9					) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_9						) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_9					) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_9					) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9				) || \
		(defined START_SEC_VAR_INIT_8BIT_10							) || \
		(defined START_SEC_VAR_INIT_16BIT_10						) || \
		(defined START_SEC_VAR_INIT_32BIT_10						) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_10					) || \
		(defined START_SEC_VAR_NOINIT_8BIT_10						) || \
		(defined START_SEC_VAR_NOINIT_16BIT_10						) || \
		(defined START_SEC_VAR_NOINIT_32BIT_10						) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_10				) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_10					) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_10					) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_10					) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10				) || \
		(defined START_SEC_VAR_INIT_8BIT_11							) || \
		(defined START_SEC_VAR_INIT_16BIT_11						) || \
		(defined START_SEC_VAR_INIT_32BIT_11						) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_11					) || \
		(defined START_SEC_VAR_NOINIT_8BIT_11						) || \
		(defined START_SEC_VAR_NOINIT_16BIT_11						) || \
		(defined START_SEC_VAR_NOINIT_32BIT_11						) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_11				) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_11					) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_11					) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_11					) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11				) || \
		(defined START_SEC_VAR_INIT_8BIT_GLOBALSHARED				) || \
		(defined START_SEC_VAR_INIT_16BIT_GLOBALSHARED				) || \
		(defined START_SEC_VAR_INIT_32BIT_GLOBALSHARED				) || \
		(defined START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED		) || \
		(defined START_SEC_VAR_NOINIT_8BIT_GLOBALSHARED				) || \
		(defined START_SEC_VAR_NOINIT_16BIT_GLOBALSHARED			) || \
		(defined START_SEC_VAR_NOINIT_32BIT_GLOBALSHARED			) || \
		(defined START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED		) || \
		(defined START_SEC_VAR_ZERO_INIT_8BIT_GLOBALSHARED			) || \
		(defined START_SEC_VAR_ZERO_INIT_16BIT_GLOBALSHARED			) || \
		(defined START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED			) || \
		(defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED	) ) )
	#error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE
	#define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CODE
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CODE_FAST
	#define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CODE_FAST
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CODE_ISR
	#define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CODE_ISR
	#undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_FAST_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_16BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_FAST_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_32BIT
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_FAST_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_FAST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG
	#define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
	#undef START_SEC_CONST_PBCFG
	#undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_INIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_INIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_INIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_INIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_FAST_NOINIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_NOINIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_FAST_NOINIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_NOINIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_FAST_NOINIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_ZERO_INIT_8BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_ZERO_INIT_16BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_ZERO_INIT_32BIT
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".noclear")
	#undef START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif



/**************** Application 0 ****************/

#ifdef START_SEC_VAR_INIT_8BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_8BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_16BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_32BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_0
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_0
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_0
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_0:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_0
	#undef MEMMAP_ERROR
#endif



/**************** Application 6 ****************/

#ifdef START_SEC_VAR_INIT_8BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_INIT_8BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_INIT_16BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_INIT_32BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_6
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_6
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_6
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_6:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_6
	#undef MEMMAP_ERROR
#endif



/**************** Application 9 ****************/

#ifdef START_SEC_VAR_INIT_8BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_INIT_8BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_INIT_16BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_INIT_32BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_9
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_9
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_9
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_9
	#undef MEMMAP_ERROR
#endif



/**************** Application 10 ****************/

#ifdef START_SEC_VAR_INIT_8BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_INIT_8BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_INIT_16BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_INIT_32BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_10
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_10
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_10
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_10
	#undef MEMMAP_ERROR
#endif



/**************** Application 11 ****************/

#ifdef START_SEC_VAR_INIT_8BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_INIT_8BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_INIT_16BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_INIT_32BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_11
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")
	#undef START_SEC_VAR_NOINIT_8BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")
	#undef START_SEC_VAR_NOINIT_16BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")
	#undef START_SEC_VAR_NOINIT_32BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_11
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_11
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_11:init")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_11
	#undef MEMMAP_ERROR
#endif



/**************** Global Shared ****************/

#ifdef START_SEC_VAR_INIT_8BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_INIT_8BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_INIT_16BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_INIT_32BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_NOINIT_8BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_NOINIT_16BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_NOINIT_32BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_ZERO_INIT_8BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_16BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_ZERO_INIT_16BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_ZERO_INIT_32BIT_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossGlobalShared")
	#undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED_GLOBALSHARED
	#undef MEMMAP_ERROR
#endif



/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
	#undef CODE_SEC_OPEN
	#pragma SET_CODE_SECTION()
	#undef STOP_SEC_CODE
	#undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST_UNSPECIFIED
	#undef CONST_SEC_OPEN
	#pragma SET_DATA_SECTION()
	#undef STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
	#undef CONST_SEC_OPEN
	#pragma SET_DATA_SECTION()
	#undef STOP_SEC_CONST
	#undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
	#undef VAR_SEC_OPEN
	#pragma SET_DATA_SECTION()
	#undef STOP_SEC_VAR
	#undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
	#error "MemMap.h, wrong pragma command"
#endif




#endif /* DEFEAT_MEMMAP */


/**********************************************************************************************************************
*  END
**********************************************************************************************************************/
