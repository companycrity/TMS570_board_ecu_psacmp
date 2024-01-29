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
 *          File:  Rte_Ap_FaultLog.h
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_FaultLog
 *  Generated at:  Thu Apr 30 13:58:58 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_FaultLog> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_FAULTLOG_H
# define _RTE_AP_FAULTLOG_H

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

typedef P2CONST(struct Rte_CDS_Ap_FaultLog, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_BatteryVoltage_Volt_f32 (0.0F)
# define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
# define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
# define Rte_InitValue_CtrlTemp_DegC_f32 (0.0F)
# define Rte_InitValue_EngineState_Cnt_u08 (0U)
# define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
# define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
# define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
# define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
# define Rte_InitValue_MotorTorque_MtrNm_f32 (0.0F)
# define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
# define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
# define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_BSIDataMissing_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_BatteryVoltage_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_CMMDataMissing_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_CtrlTemp_DegC_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_EngineState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_EtatPrincipSev_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_EtatReseauElec_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_HandwheelPosition_HwDeg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_HandwheelTorque_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_Kilometrage_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_MotorTorque_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_PowerSupplies_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_ShuntPosition_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_FaultLog_VehicleSpeed_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_FaultLog_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_FaultLog_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_FaultLog_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_FaultLog_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_FAULTLOG_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (Rte_Inst_Ap_FaultLog->FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32->value)

# define Rte_IRead_FaultLog_Per1_ComputerRazGCT_Cnt_u08() \
  (Rte_Inst_Ap_FaultLog->FaultLog_Per1_ComputerRazGCT_Cnt_u08->value)

# define Rte_IRead_FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_FaultLog->FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32->value)

# define Rte_IRead_FaultLog_Per1_TxEnabled_Cnt_lgc() \
  (Rte_Inst_Ap_FaultLog->FaultLog_Per1_TxEnabled_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BSIDataMissing_Cnt_lgc Rte_Read_Ap_FaultLog_BSIDataMissing_Cnt_lgc
# define Rte_Read_BatteryVoltage_Volt_f32 Rte_Read_Ap_FaultLog_BatteryVoltage_Volt_f32
# define Rte_Read_CMMDataMissing_Cnt_lgc Rte_Read_Ap_FaultLog_CMMDataMissing_Cnt_lgc
# define Rte_Read_CtrlTemp_DegC_f32 Rte_Read_Ap_FaultLog_CtrlTemp_DegC_f32
# define Rte_Read_EngineState_Cnt_u08 Rte_Read_Ap_FaultLog_EngineState_Cnt_u08
# define Rte_Read_EtatPrincipSev_Cnt_u08 Rte_Read_Ap_FaultLog_EtatPrincipSev_Cnt_u08
# define Rte_Read_EtatReseauElec_Cnt_u08 Rte_Read_Ap_FaultLog_EtatReseauElec_Cnt_u08
# define Rte_Read_HandwheelPosition_HwDeg_f32 Rte_Read_Ap_FaultLog_HandwheelPosition_HwDeg_f32
# define Rte_Read_HandwheelTorque_HwNm_f32 Rte_Read_Ap_FaultLog_HandwheelTorque_HwNm_f32
# define Rte_Read_Kilometrage_Cnt_u32 Rte_Read_Ap_FaultLog_Kilometrage_Cnt_u32
# define Rte_Read_MotorTorque_MtrNm_f32 Rte_Read_Ap_FaultLog_MotorTorque_MtrNm_f32
# define Rte_Read_PowerSupplies_Cnt_u08 Rte_Read_Ap_FaultLog_PowerSupplies_Cnt_u08
# define Rte_Read_ShuntPosition_Cnt_u08 Rte_Read_Ap_FaultLog_ShuntPosition_Cnt_u08
# define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_FaultLog_VehicleSpeed_Kph_f32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_FaultLog_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_FaultLog_EpsEn_OP_GET
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_FaultLog_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_FaultLog_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_FaultLog() (Rte_Inst_Ap_FaultLog->Pim_FaultLog)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   FaultLogType *Rte_Pim_FaultLog(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_FAULTLOG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_DTCStatusChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <CallbackDTCStatusChange>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BSIDataMissing_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_BatteryVoltage_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_CMMDataMissing_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_CtrlTemp_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_EngineState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatPrincipSev_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatReseauElec_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HandwheelPosition_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_HandwheelTorque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_Kilometrage_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_MotorTorque_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_PowerSupplies_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ShuntPosition_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_VehicleSpeed_Kph_f32(Float *data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_FaultLog_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   UInt8 Rte_IRead_FaultLog_Per1_ComputerRazGCT_Cnt_u08(void)
 *   UInt32 Rte_IRead_FaultLog_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   Boolean Rte_IRead_FaultLog_Per1_TxEnabled_Cnt_lgc(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultLog_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_FAULTLOG_APPL_CODE) FaultLog_Trns1(void);

# define RTE_STOP_SEC_AP_FAULTLOG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1430419865
#    error "The magic number of the generated file <C:/Users/nzx5jd/Desktop/DVOutput/Ap_FaultLog/Rte_Ap_FaultLog.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1430419865
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_FAULTLOG_H */
