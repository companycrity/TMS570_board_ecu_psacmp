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
 *          File:  Components/Rte_Ap_FaultLog.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_FAULTLOG_H
# define _RTE_AP_FAULTLOG_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_BSIDataMissing_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb10_Batt_Volt_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_CMMDataMissing_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_EtatMTRaw_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_EtatPrincipSev_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_EtatReseauElec_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_PsaAgArbn_HandwheelPosition_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sweep_OutputHwTrq_HwNm_f32;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComInput_Kilometrage_Cnt_u32;
extern VAR(Float, RTE_VAR_INIT) Rte_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_PowerSupplies_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_ShuntPosition_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_BatteryVoltage_Volt_f32 (0.0F)
#  define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
#  define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
#  define Rte_InitValue_CtrlTemp_DegC_f32 (0.0F)
#  define Rte_InitValue_EngineState_Cnt_u08 (0U)
#  define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
#  define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
#  define Rte_InitValue_MotorTorque_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
#  define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
#  define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd6_SystemState6_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_6, RTE_VAR_NOINIT) Rte_Task_10ms_6;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_FaultLog_FaultLog_Per1.Rte_CompteurTemporelVehicule_Cnt_u32.value)

#  define Rte_IRead_FaultLog_Per1_ComputerRazGCT_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_FaultLog_FaultLog_Per1.Rte_ComputerRazGCT_Cnt_u08.value)

#  define Rte_IRead_FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_FaultLog_FaultLog_Per1.Rte_ISDAT4V2BSI552MsgRxTime_MSec_u32.value)

#  define Rte_IRead_FaultLog_Per1_TxEnabled_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Ap_FaultLog_FaultLog_Per1.Rte_TxEnabled_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BSIDataMissing_Cnt_lgc Rte_Read_Ap_FaultLog_BSIDataMissing_Cnt_lgc
#  define Rte_Read_Ap_FaultLog_BSIDataMissing_Cnt_lgc(data) (*(data) = Rte_SrlComInput_BSIDataMissing_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_BatteryVoltage_Volt_f32 Rte_Read_Ap_FaultLog_BatteryVoltage_Volt_f32
#  define Rte_Read_Ap_FaultLog_BatteryVoltage_Volt_f32(data) (*(data) = Rte_IoHwAb10_Batt_Volt_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CMMDataMissing_Cnt_lgc Rte_Read_Ap_FaultLog_CMMDataMissing_Cnt_lgc
#  define Rte_Read_Ap_FaultLog_CMMDataMissing_Cnt_lgc(data) (*(data) = Rte_SrlComInput_CMMDataMissing_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CtrlTemp_DegC_f32 Rte_Read_Ap_FaultLog_CtrlTemp_DegC_f32
#  define Rte_Read_Ap_FaultLog_CtrlTemp_DegC_f32(data) (*(data) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EngineState_Cnt_u08 Rte_Read_Ap_FaultLog_EngineState_Cnt_u08
#  define Rte_Read_Ap_FaultLog_EngineState_Cnt_u08(data) (*(data) = Rte_SrlComInput_EtatMTRaw_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EtatPrincipSev_Cnt_u08 Rte_Read_Ap_FaultLog_EtatPrincipSev_Cnt_u08
#  define Rte_Read_Ap_FaultLog_EtatPrincipSev_Cnt_u08(data) (*(data) = Rte_SrlComInput_EtatPrincipSev_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EtatReseauElec_Cnt_u08 Rte_Read_Ap_FaultLog_EtatReseauElec_Cnt_u08
#  define Rte_Read_Ap_FaultLog_EtatReseauElec_Cnt_u08(data) (*(data) = Rte_SrlComInput_EtatReseauElec_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelPosition_HwDeg_f32 Rte_Read_Ap_FaultLog_HandwheelPosition_HwDeg_f32
#  define Rte_Read_Ap_FaultLog_HandwheelPosition_HwDeg_f32(data) (*(data) = Rte_PsaAgArbn_HandwheelPosition_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelTorque_HwNm_f32 Rte_Read_Ap_FaultLog_HandwheelTorque_HwNm_f32
#  define Rte_Read_Ap_FaultLog_HandwheelTorque_HwNm_f32(data) (*(data) = Rte_Sweep_OutputHwTrq_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Kilometrage_Cnt_u32 Rte_Read_Ap_FaultLog_Kilometrage_Cnt_u32
#  define Rte_Read_Ap_FaultLog_Kilometrage_Cnt_u32(data) (*(data) = Rte_SrlComInput_Kilometrage_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MotorTorque_MtrNm_f32 Rte_Read_Ap_FaultLog_MotorTorque_MtrNm_f32
#  define Rte_Read_Ap_FaultLog_MotorTorque_MtrNm_f32(data) (*(data) = Rte_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PowerSupplies_Cnt_u08 Rte_Read_Ap_FaultLog_PowerSupplies_Cnt_u08
#  define Rte_Read_Ap_FaultLog_PowerSupplies_Cnt_u08(data) (*(data) = Rte_SrlComInput_PowerSupplies_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ShuntPosition_Cnt_u08 Rte_Read_Ap_FaultLog_ShuntPosition_Cnt_u08
#  define Rte_Read_Ap_FaultLog_ShuntPosition_Cnt_u08(data) (*(data) = Rte_SrlComInput_ShuntPosition_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_FaultLog_VehicleSpeed_Kph_f32
#  define Rte_Read_Ap_FaultLog_VehicleSpeed_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComVehSpd_Kph_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd6_SystemState6_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR6_APPL_CODE) NxtrDiagMgr6_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR6_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr6_GetNTCFailed
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(FaultLogType, RTE_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP) Rte_FaultLog_FaultLog;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_FaultLog() \
  (&Rte_FaultLog_FaultLog)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_FAULTLOG_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Init1(void);

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Per1(void);

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Trns1(void);

# define RTE_STOP_SEC_AP_FAULTLOG_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_FAULTLOG_H */
