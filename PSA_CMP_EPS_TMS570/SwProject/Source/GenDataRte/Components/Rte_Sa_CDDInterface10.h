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
 *          File:  Components/Rte_Sa_CDDInterface10.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE10_H
# define _RTE_SA_CDDINTERFACE10_H

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

#  define Rte_InitValue_CommOffset_Cnt_u16 (0U)
#  define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
#  define Rte_InitValue_IvtrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MotCurrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrCurr1TempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurr2TempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrPosPolarity_Cnt_s08 (0)
#  define Rte_InitValue_TurnsCounterSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_CDDInterface10_Init1_MtrPosPolarity_Cnt_s08() \
  (Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Init1.Rte_MtrPosPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface10_Init1_ESCOffsCfgSeld_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface10_ESCOffsCfgSeld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Init1_ESCOffsCfgSeld_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface10_ESCOffsCfgSeld_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface10_Init1_TurnsCounterSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface10_TurnsCounterSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Init1_TurnsCounterSelected_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface10_TurnsCounterSelected_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface10_Per1_CommOffset_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_CommOffset_Cnt_u16.value)

#  define Rte_IRead_CDDInterface10_Per1_IvtrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface10_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MRFMtrVel_MtrRadpS_f32.value)

#  define Rte_IRead_CDDInterface10_Per1_MotCurrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface10_Per1_MtrCurr1TempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MtrCurr1TempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface10_Per1_MtrCurr2TempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MtrCurr2TempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface10_Per1_MtrPosPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MtrPosPolarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface10_Per1_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_Vecu_Volt_f32.value)

#  define Rte_IWrite_CDDInterface10_Per1_ESCOffsCfgSeld_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ESCOffsCfgSeld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface10_Per1_ESCOffsCfgSeld_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ESCOffsCfgSeld_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_SA_CDDINTERFACE10_H */
