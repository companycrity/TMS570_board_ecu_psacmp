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
 *          File:  Components/Rte_Cd_PhaseAbcFdbkMeas.h
 *     Workspace:  C:/synergy_projects_working/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_PHASEABCFDBKMEAS_H
# define _RTE_CD_PHASEABCFDBKMEAS_H

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

#  define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

#  define RTE_STOP_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
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

#  define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Init2(void);

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Per1(void);

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Get_PhaseAbcFdbkMeas_PhaseFdbk(void);

# define RTE_STOP_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_CD_PHASEABCFDBKMEAS_H */
