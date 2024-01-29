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
 *          File:  Rte_Ap_DiagSvc.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_DiagSvc
 *  Generated at:  Mon Mar 19 08:59:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_DiagSvc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DIAGSVC_H
# define _RTE_AP_DIAGSVC_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_DiagSvc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BatteryVoltage_Volt_f32 (0.0F)
# define Rte_InitValue_ECUTemperature_DegC_f32 (0.0F)
# define Rte_InitValue_EngineState_Cnt_u08 (0U)
# define Rte_InitValue_FinalTorqueCommand_MtrNm_f32 (0.0F)
# define Rte_InitValue_HandwheelAngle_HwDeg_f32 (0.0F)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
# define Rte_InitValue_Mileage_Cnt_u32 (0U)
# define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_BatteryVoltage_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_ECUTemperature_DegC_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_EngineState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_FinalTorqueCommand_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_HandwheelAngle_HwDeg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_HandwheelAuthority_Uls_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_HandwheelTorque_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_HandwheelVelocity_HwRadpS_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_Mileage_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_SrlComVehSpd_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagSvc_VehicleSpeedValid_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_DiagSvc_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagSvc_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagSvc_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) IsDynDae);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagSvc_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) IsSupvDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagSvc_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagSvc_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) NTCFailed_Ptr_T_lgc);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BatteryVoltage_Volt_f32 Rte_Read_Ap_DiagSvc_BatteryVoltage_Volt_f32
# define Rte_Read_ECUTemperature_DegC_f32 Rte_Read_Ap_DiagSvc_ECUTemperature_DegC_f32
# define Rte_Read_EngineState_Cnt_u08 Rte_Read_Ap_DiagSvc_EngineState_Cnt_u08
# define Rte_Read_FinalTorqueCommand_MtrNm_f32 Rte_Read_Ap_DiagSvc_FinalTorqueCommand_MtrNm_f32
# define Rte_Read_HandwheelAngle_HwDeg_f32 Rte_Read_Ap_DiagSvc_HandwheelAngle_HwDeg_f32
# define Rte_Read_HandwheelAuthority_Uls_f32 Rte_Read_Ap_DiagSvc_HandwheelAuthority_Uls_f32
# define Rte_Read_HandwheelTorque_HwNm_f32 Rte_Read_Ap_DiagSvc_HandwheelTorque_HwNm_f32
# define Rte_Read_HandwheelVelocity_HwRadpS_f32 Rte_Read_Ap_DiagSvc_HandwheelVelocity_HwRadpS_f32
# define Rte_Read_Mileage_Cnt_u32 Rte_Read_Ap_DiagSvc_Mileage_Cnt_u32
# define Rte_Read_SrlComVehSpd_Kph_f32 Rte_Read_Ap_DiagSvc_SrlComVehSpd_Kph_f32
# define Rte_Read_VehicleSpeedValid_Cnt_lgc Rte_Read_Ap_DiagSvc_VehicleSpeedValid_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_DiagSvc_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_DiagSvc_EpsEn_OP_GET
# define Rte_Call_IS_DYN_DAE_Get Rte_Call_Ap_DiagSvc_IS_DYN_DAE_Get
# define Rte_Call_IS_SUPV_DIRA_Get Rte_Call_Ap_DiagSvc_IS_SUPV_DIRA_Get
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_DiagSvc_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_DiagSvc_NxtrDiagMgr_GetNTCFailed




# define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd401_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd401>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Mileage_Cnt_u32(UInt32 *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd401_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd401_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd401_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd403_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd403>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComVehSpd_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehicleSpeedValid_Cnt_lgc(Boolean *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd403_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd403_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd403_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd404_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd404>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BatteryVoltage_Volt_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd404_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd404_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd404_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd405_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd405>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ECUTemperature_DegC_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd405_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd405_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd405_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd407_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd407>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EngineState_Cnt_u08(UInt8 *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd407_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd407_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd407_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd408_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd408>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd408_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd408_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd408_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd409_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd409>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd409_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd409_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd409_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40b_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40b>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40b_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd40b_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40c_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40c>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40c_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd40c_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40c_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40d_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40d>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelAngle_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_HandwheelAuthority_Uls_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40d_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd40d_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40d_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd40f_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd40f>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelTorque_HwNm_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd40f_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd40f_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd40f_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd410_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd410>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FinalTorqueCommand_MtrNm_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd410_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd410_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd410_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd412_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd412>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd412_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd412_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd412_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd414_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd414>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd414_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd414_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd414_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd415_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd415>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd415_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd415_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd415_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd418_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd418>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HandwheelVelocity_HwRadpS_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd418_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd418_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd418_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBValByDID_0xd41b_GetDataValueByDataIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataValueByDataIdentifier> of PortPrototype <CBValByDID_0xd41b>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType CBValByDID_0xd41b_GetDataValueByDataIdentifier(UInt8 *Data)
# else
 *   Std_ReturnType CBValByDID_0xd41b_GetDataValueByDataIdentifier(Dem_MaxDataValueType *Data)
# endif
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackGetDataValueByDataId_E_NOT_OK
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) CBValByDID_0xd41b_GetDataValueByDataIdentifier(P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Data);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagSvc_DummyFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DIAGSVC_APPL_CODE) DiagSvc_DummyFunction(void);

# define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_CallbackGetDataValueByDataId_E_NOT_OK (1U)

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1521442787
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/DiagSvc/utp/contract/Ap_DiagSvc/Rte_Ap_DiagSvc.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1521442787
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DIAGSVC_H */
