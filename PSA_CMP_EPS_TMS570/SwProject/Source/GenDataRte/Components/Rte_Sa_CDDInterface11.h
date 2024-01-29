/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Sa_CDDInterface11.h
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE11_H
# define _RTE_SA_CDDINTERFACE11_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_11a, RTE_VAR_NOINIT) Rte_Task_Init_11a;

extern VAR(Rte_tsTask_10ms_11, RTE_VAR_NOINIT) Rte_Task_10ms_11;

#  define RTE_STOP_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IWrite_CDDInterface11_Init1_DesiredTunSet_Cnt_u16(data) \
  ( \
    Rte_Task_Init_11a.Rte_TB.Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface11_Init1_DesiredTunSet_Cnt_u16() \
  (&Rte_Task_Init_11a.Rte_TB.Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface11_Per1_DesiredTunSet_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_11.Rte_TB.Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface11_Per1_DesiredTunSet_Cnt_u16() \
  (&Rte_Task_10ms_11.Rte_TB.Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE11_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE11_APPL_CODE) CDDInterface11_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE11_APPL_CODE) CDDInterface11_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE11_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_SA_CDDINTERFACE11_H */
