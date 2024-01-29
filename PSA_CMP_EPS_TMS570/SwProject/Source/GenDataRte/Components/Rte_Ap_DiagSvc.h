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
 *          File:  Components/Rte_Ap_DiagSvc.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DIAGSVC_H
# define _RTE_AP_DIAGSVC_H

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
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb10_Batt_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_EtatMTRaw_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_PsaAgArbn_HandwheelPosition_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_PsaAgArbn_HandwheelAuthority_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sweep_OutputHwTrq_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrVel_HandwheelVel_HwRadpS_f32;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_Kilometrage_Cnt_u32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BatteryVoltage_Volt_f32 (0.0F)
#  define Rte_InitValue_ECUTemperature_DegC_f32 (0.0F)
#  define Rte_InitValue_EngineState_Cnt_u08 (0U)
#  define Rte_InitValue_FinalTorqueCommand_MtrNm_f32 (0.0F)
#  define Rte_InitValue_HandwheelAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_Mileage_Cnt_u32 (0U)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
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



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BatteryVoltage_Volt_f32 Rte_Read_Ap_DiagSvc_BatteryVoltage_Volt_f32
#  define Rte_Read_Ap_DiagSvc_BatteryVoltage_Volt_f32(data) (*(data) = Rte_IoHwAb10_Batt_Volt_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ECUTemperature_DegC_f32 Rte_Read_Ap_DiagSvc_ECUTemperature_DegC_f32
#  define Rte_Read_Ap_DiagSvc_ECUTemperature_DegC_f32(data) (*(data) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EngineState_Cnt_u08 Rte_Read_Ap_DiagSvc_EngineState_Cnt_u08
#  define Rte_Read_Ap_DiagSvc_EngineState_Cnt_u08(data) (*(data) = Rte_SrlComInput_EtatMTRaw_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_FinalTorqueCommand_MtrNm_f32 Rte_Read_Ap_DiagSvc_FinalTorqueCommand_MtrNm_f32
#  define Rte_Read_Ap_DiagSvc_FinalTorqueCommand_MtrNm_f32(data) (*(data) = Rte_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelAngle_HwDeg_f32 Rte_Read_Ap_DiagSvc_HandwheelAngle_HwDeg_f32
#  define Rte_Read_Ap_DiagSvc_HandwheelAngle_HwDeg_f32(data) (*(data) = Rte_PsaAgArbn_HandwheelPosition_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelAuthority_Uls_f32 Rte_Read_Ap_DiagSvc_HandwheelAuthority_Uls_f32
#  define Rte_Read_Ap_DiagSvc_HandwheelAuthority_Uls_f32(data) (*(data) = Rte_PsaAgArbn_HandwheelAuthority_Uls_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelTorque_HwNm_f32 Rte_Read_Ap_DiagSvc_HandwheelTorque_HwNm_f32
#  define Rte_Read_Ap_DiagSvc_HandwheelTorque_HwNm_f32(data) (*(data) = Rte_Sweep_OutputHwTrq_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelVelocity_HwRadpS_f32 Rte_Read_Ap_DiagSvc_HandwheelVelocity_HwRadpS_f32
#  define Rte_Read_Ap_DiagSvc_HandwheelVelocity_HwRadpS_f32(data) (*(data) = Rte_MtrVel_HandwheelVel_HwRadpS_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Mileage_Cnt_u32 Rte_Read_Ap_DiagSvc_Mileage_Cnt_u32
#  define Rte_Read_Ap_DiagSvc_Mileage_Cnt_u32(data) (*(data) = Rte_SrlComDriver_Kilometrage_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComVehSpd_Kph_f32 Rte_Read_Ap_DiagSvc_SrlComVehSpd_Kph_f32
#  define Rte_Read_Ap_DiagSvc_SrlComVehSpd_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComVehSpd_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VehicleSpeedValid_Cnt_lgc Rte_Read_Ap_DiagSvc_VehicleSpeedValid_Cnt_lgc
#  define Rte_Read_Ap_DiagSvc_VehicleSpeedValid_Cnt_lgc(data) (*(data) = Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynDae);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_DYN_DAE_Get(arg1) (SrlComOutput_IS_DYN_DAE_Get(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsSupvDira);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_SUPV_DIRA_Get(arg1) (SrlComOutput_IS_SUPV_DIRA_Get(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR6_APPL_CODE) NxtrDiagMgr6_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR6_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr6_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR6_APPL_CODE) NxtrDiagMgr6_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR6_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr6_GetNTCFailed


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

FUNC(void, RTE_AP_DIAGSVC_APPL_CODE) DiagSvc_DummyFunction(void);

# define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackGetDataValueByDataId_E_NOT_OK (1U)

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_DIAGSVC_H */
