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
 *          File:  Rte_Ap_CustBattDiag.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_CustBattDiag
 *  Generated at:  Sun Dec 10 00:58:23 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_CustBattDiag> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CUSTBATTDIAG_H
# define _RTE_AP_CUSTBATTDIAG_H

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

typedef P2CONST(struct Rte_CDS_Ap_CustBattDiag, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Batt_Volt_f32 (0.0F)
# define Rte_InitValue_CTerm_Cnt_lgc (FALSE)
# define Rte_InitValue_DmdDelestDa_Cnt_u08 (0U)
# define Rte_InitValue_EngOn_Cnt_lgc (FALSE)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_SttdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_CustBattDiag_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_CUSTBATTDIAG_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_CUSTBATTDIAG_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_CUSTBATTDIAG_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_CUSTBATTDIAG_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CustBattDiag_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_CUSTBATTDIAG_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CustBattDiag_Per1_Batt_Volt_f32() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per1_Batt_Volt_f32->value)

# define Rte_IRead_CustBattDiag_Per2_Batt_Volt_f32() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_Batt_Volt_f32->value)

# define Rte_IRead_CustBattDiag_Per2_CTerm_Cnt_lgc() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_CTerm_Cnt_lgc->value)

# define Rte_IRead_CustBattDiag_Per2_DmdDelestDa_Cnt_u08() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_DmdDelestDa_Cnt_u08->value)

# define Rte_IRead_CustBattDiag_Per2_EngOn_Cnt_lgc() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_EngOn_Cnt_lgc->value)

# define Rte_IRead_CustBattDiag_Per2_EtatMT_Cnt_u08() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_EtatMT_Cnt_u08->value)

# define Rte_IRead_CustBattDiag_Per2_SttdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_SttdSelected_Cnt_lgc->value)

# define Rte_IRead_CustBattDiag_Per2_ValidEngineStatus_Cnt_lgc() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_ValidEngineStatus_Cnt_lgc->value)

# define Rte_IRead_CustBattDiag_Per2_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_CustBattDiag_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_CustBattDiag->CustBattDiag_Per2_VehicleSpeed_Kph_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_CustBattDiag_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_CustBattDiag_EpsEn_OP_GET
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_CustBattDiag_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_CustBattDiag_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_CustBattDiag_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_CustBattDiag_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_CUSTBATTDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustBattDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CustBattDiag_Per1_Batt_Volt_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTBATTDIAG_APPL_CODE) CustBattDiag_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustBattDiag_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CustBattDiag_Per2_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_CTerm_Cnt_lgc(void)
 *   UInt8 Rte_IRead_CustBattDiag_Per2_DmdDelestDa_Cnt_u08(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_EngOn_Cnt_lgc(void)
 *   UInt8 Rte_IRead_CustBattDiag_Per2_EtatMT_Cnt_u08(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_SttdSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_CustBattDiag_Per2_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_CustBattDiag_Per2_VehicleSpeed_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTBATTDIAG_APPL_CODE) CustBattDiag_Per2(void);

# define RTE_STOP_SEC_AP_CUSTBATTDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1512853853
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/CustBattDiag/utp/contract/Ap_CustBattDiag/Rte_Ap_CustBattDiag.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1512853853
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CUSTBATTDIAG_H */
