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
 *          File:  Components/Rte_Ap_TrqLOA.h
 *     Workspace:  C:/synergy_projects_working/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TRQLOA_H
# define _RTE_AP_TRQLOA_H

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

#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_MotAgLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_TrqLOAAvail_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqLOACmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TrqLoaDi_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehWhlBas_mm_f32 (3000.0F)
#  define Rte_InitValue_VehWhlBasVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleLatAccel_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_VehicleLatAccelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
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

#  define Rte_IRead_TrqLOA_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_TrqLOA_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_MotAgLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IRead_TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value)

#  define Rte_IRead_TrqLOA_Per1_TrqLoaDi_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLoaDi_Cnt_lgc.value)

#  define Rte_IRead_TrqLOA_Per1_VehWhlBasVld_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehWhlBasVld_Cnt_lgc.value)

#  define Rte_IRead_TrqLOA_Per1_VehWhlBas_mm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehWhlBas_mm_f32.value)

#  define Rte_IRead_TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleLatAccelValid_Cnt_lgc.value)

#  define Rte_IRead_TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleLatAccel_MpSecSq_f32.value)

#  define Rte_IRead_TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_TrqLOA_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLOAAvail_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLOAAvail_Cnt_lgc.value)

#  define Rte_IWrite_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLOACmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqLOA_Per1_TrqLOACmd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLOACmd_MtrNm_f32.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_TRQLOA_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Init1(void);

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Per1(void);

# define RTE_STOP_SEC_AP_TRQLOA_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_TRQLOA_H */
