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
 *          File:  Components/Rte_Ap_PosServo.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_POSSERVO_H
# define _RTE_AP_POSSERVO_H

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

#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_MotorVelCRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_PosSrvoCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PosSrvoEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PosSrvoReturnSclFct_Uls_f32 (1.0F)
#  define Rte_InitValue_PosSrvoSmoothEnable_Uls_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
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

#  define Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_PsaAgArbn_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_PosServo_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value)

#  define Rte_IRead_PosServo_Per1_MotorVelCRF_MtrRadpS_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_MtrVel_MotorVelCRF_MtrRadpS_f32.value)

#  define Rte_IRead_PosServo_Per1_PosSrvoEnable_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoEnable_Cnt_lgc.value)

#  define Rte_IRead_PosServo_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_PSASH_PosSrvoHwAngle_HwDeg_f32.value)

#  define Rte_IRead_PosServo_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_PosServo_Per1_PosSrvoCmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoCmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_PosServo_Per1_PosSrvoCmd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoCmd_MtrNm_f32.value)

#  define Rte_IWrite_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoReturnSclFct_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoReturnSclFct_Uls_f32.value)

#  define Rte_IWrite_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_POSSERVO_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Init1(void);

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Per1(void);

# define RTE_STOP_SEC_AP_POSSERVO_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_POSSERVO_H */
