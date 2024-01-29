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
 *          File:  Components/Rte_Ap_PSATA.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSATA_H
# define _RTE_AP_PSATA_H

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

#  define Rte_InitValue_ApaOpTrqOv_MtrNm_f32 (0.0F)
#  define Rte_InitValue_ApaPosSrvoFlt_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaState_Cnt_enum (0U)
#  define Rte_InitValue_EPSStateForLxa_Cnt_enum (0U)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTrqRate_HwNmpS_f32 (0.0F)
#  define Rte_InitValue_LxaCorrnFacReqLimd_Uls_f32 (0.0F)
#  define Rte_InitValue_LxaDrvrAbsntHwVelDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaHwAgDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaOpTrqOv_MtrNm_f32 (0.0F)
#  define Rte_InitValue_LxaTqLimnActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_OpTrqOv_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PosSrvoCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PosSrvoEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

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

#  define Rte_IRead_PSATA_Per1_ApaState_Cnt_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_ApaState_Cnt_enum.value)

#  define Rte_IRead_PSATA_Per1_EPSStateForLxa_Cnt_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_EPSStateForLxa_Cnt_enum.value)

#  define Rte_IRead_PSATA_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_PSATA_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_PSATA_Per1_HwTrqRate_HwNmpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_HwTrqRate_HwNmpS_f32.value)

#  define Rte_IRead_PSATA_Per1_LxaCorrnFacReqLimd_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaCorrnFacReqLimd_Uls_f32.value)

#  define Rte_IRead_PSATA_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaDrvrAbsntHwVelDetd_Cnt_lgc.value)

#  define Rte_IRead_PSATA_Per1_LxaHwAgDetd_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaHwAgDetd_Cnt_lgc.value)

#  define Rte_IRead_PSATA_Per1_PosSrvoCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_PosSrvoCmd_MtrNm_f32.value)

#  define Rte_IRead_PSATA_Per1_PosSrvoEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_PosSrvoEnable_Cnt_lgc.value)

#  define Rte_IRead_PSATA_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_PSATA_Per1_ApaOpTrqOv_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_ApaOpTrqOv_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSATA_Per1_ApaOpTrqOv_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_ApaOpTrqOv_MtrNm_f32.value)

#  define Rte_IWrite_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_ApaPosSrvoFlt_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_ApaPosSrvoFlt_Cnt_lgc.value)

#  define Rte_IWrite_PSATA_Per1_LxaOpTrqOv_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaOpTrqOv_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSATA_Per1_LxaOpTrqOv_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaOpTrqOv_MtrNm_f32.value)

#  define Rte_IWrite_PSATA_Per1_LxaTqLimnActv_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaTqLimnActv_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSATA_Per1_LxaTqLimnActv_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PSATA_PSATA_Per1.Rte_LxaTqLimnActv_Cnt_lgc.value)

#  define Rte_IWrite_PSATA_Per1_OpTrqOv_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_PSATA_OpTrqOv_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_PSATA_Per1_OpTrqOv_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_PSATA_OpTrqOv_MtrNm_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PSATA_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Init1(void);

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Per1(void);

# define RTE_STOP_SEC_AP_PSATA_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_PSATA_H */
