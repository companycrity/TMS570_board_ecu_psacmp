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
 *          File:  Rte_Ap_SrlComOutput.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Thu May 17 16:18:21 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComOutput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComOutput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_APAState_Cnt_enum (0U)
# define Rte_InitValue_APAStateTransitionCause_Cnt_enum (0U)
# define Rte_InitValue_AVASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_AbsltHwPosn_HwDeg_f32 (0.0F)
# define Rte_InitValue_AbsltHwPosnLvl1_Cnt_lgc (FALSE)
# define Rte_InitValue_AbsltHwPosnLvl2_Cnt_lgc (FALSE)
# define Rte_InitValue_AbsltHwPosnVld_Cnt_lgc (FALSE)
# define Rte_InitValue_AgArbnStToSerlCom_Cnt_enum (0U)
# define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CTCFailed_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_DefaultHwaSCommExportValue_Cnt_lgc (FALSE)
# define Rte_InitValue_DmdDelestDaVld_Cnt_lgc (FALSE)
# define Rte_InitValue_DrvrIntvDetd_Cnt_lgc (FALSE)
# define Rte_InitValue_EPSStateForLxa_Cnt_enum (0U)
# define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
# define Rte_InitValue_ETATDADYN_Cnt_enum (0U)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
# define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_LxaTqLimnActv_Cnt_lgc (FALSE)
# define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
# define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_RelHwPosnToSerlCom_HwDeg_f32 (0.0F)
# define Rte_InitValue_RelHwPosnVldToSerlCom_Cnt_lgc (FALSE)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComHwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
# define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_TxEnabled_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComOutput_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_IndStatusETATDA2_GetIndicatorStatus(P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IndicatorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SrlComDriver_SCom_SendMsgOnChange(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) CurrentTime);

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComOutput_IsDatDiraMsg(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComOutput_IsDatDiraMsg(void);

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComOutput_IsDynDaeMsg(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComOutput_IsDynDaeMsg(void);

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComOutput_IsDynVolMsg(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComOutput_IsDynVolMsg(void);

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComOutput_IsSupvDiraMsg(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComOutput_IsSupvDiraMsg(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_enum() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_APAStateTransitionCause_Cnt_enum->value)

# define Rte_IRead_SrlComOutput_Per1_APAState_Cnt_enum() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_APAState_Cnt_enum->value)

# define Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl1_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AbsltHwPosnLvl1_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl2_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AbsltHwPosnLvl2_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32->value)

# define Rte_IRead_SrlComOutput_Per1_AgArbnStToSerlCom_Cnt_enum() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AgArbnStToSerlCom_Cnt_enum->value)

# define Rte_IRead_SrlComOutput_Per1_CAVHCSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CAVHCSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CTCFailed_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CityParkSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_DmdDelestDaVld_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DmdDelestDaVld_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_DrvrIntvDetd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DrvrIntvDetd_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_EPSStateForLxa_Cnt_enum() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_EPSStateForLxa_Cnt_enum->value)

# define Rte_IRead_SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_ETATDADYN_Cnt_enum() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDADYN_Cnt_enum->value)

# define Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_EtatMT_Cnt_u08->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelTorque_HwNm_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_LxaTqLimnActv_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_LxaTqLimnActv_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_RelHwPosnToSerlCom_HwDeg_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_RelHwPosnToSerlCom_HwDeg_f32->value)

# define Rte_IRead_SrlComOutput_Per1_RelHwPosnVldToSerlCom_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_RelHwPosnVldToSerlCom_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_SrlComHwTrq_HwNm_f32->value)

# define Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VehicleSpeed_Kph_f32->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_TxEnabled_Cnt_lgc Rte_Read_Ap_SrlComOutput_TxEnabled_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComOutput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_SrlComOutput_EpsEn_OP_GET
# define Rte_Call_IndStatusETATDA2_GetIndicatorStatus Rte_Call_Ap_SrlComOutput_IndStatusETATDA2_GetIndicatorStatus
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SrlComDriver_SCom_SendMsgOnChange Rte_Call_Ap_SrlComOutput_SrlComDriver_SCom_SendMsgOnChange
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_IsDatDiraMsg Rte_Enter_Ap_SrlComOutput_IsDatDiraMsg
# define Rte_Exit_IsDatDiraMsg Rte_Exit_Ap_SrlComOutput_IsDatDiraMsg

# define Rte_Enter_IsDynDaeMsg Rte_Enter_Ap_SrlComOutput_IsDynDaeMsg
# define Rte_Exit_IsDynDaeMsg Rte_Exit_Ap_SrlComOutput_IsDynDaeMsg

# define Rte_Enter_IsDynVolMsg Rte_Enter_Ap_SrlComOutput_IsDynVolMsg
# define Rte_Exit_IsDynVolMsg Rte_Exit_Ap_SrlComOutput_IsDynVolMsg

# define Rte_Enter_IsSupvDiraMsg Rte_Enter_Ap_SrlComOutput_IsSupvDiraMsg
# define Rte_Exit_IsSupvDiraMsg Rte_Exit_Ap_SrlComOutput_IsSupvDiraMsg


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PimIsDatDiraMsg() (Rte_Inst_Ap_SrlComOutput->Pim_PimIsDatDiraMsg)

# define Rte_Pim_PimIsDynDaeMsg() (Rte_Inst_Ap_SrlComOutput->Pim_PimIsDynDaeMsg)

# define Rte_Pim_PimIsDynVolAddMsg() (Rte_Inst_Ap_SrlComOutput->Pim_PimIsDynVolAddMsg)

# define Rte_Pim_PimIsDynVolBaseMsg() (Rte_Inst_Ap_SrlComOutput->Pim_PimIsDynVolBaseMsg)

# define Rte_Pim_PimIsSupvDiraMsg() (Rte_Inst_Ap_SrlComOutput->Pim_PimIsSupvDiraMsg)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   IS_DAT_DIRA_Msg *Rte_Pim_PimIsDatDiraMsg(void)
 *   IS_DYN_DAE_Msg *Rte_Pim_PimIsDynDaeMsg(void)
 *   IS_DYN_VOL_MsgAdd *Rte_Pim_PimIsDynVolAddMsg(void)
 *   IS_DYN_VOL_MsgBase *Rte_Pim_PimIsDynVolBaseMsg(void)
 *   IS_SUPV_DIRA_Msg *Rte_Pim_PimIsSupvDiraMsg(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DAT_DIRA_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DAT_DIRA>
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
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsDatDiraMsg(void)
 *   void Rte_Exit_IsDatDiraMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DAT_DIRA_Get(IS_DAT_DIRA_Msg *IsDatDira)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DAT_DIRA_Get(P2VAR(IS_DAT_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDatDira);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DYN_DAE_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DYN_DAE>
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
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsDynDaeMsg(void)
 *   void Rte_Exit_IsDynDaeMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynDae);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_DYN_VOL_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_DYN_VOL>
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
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsDynVolMsg(void)
 *   void Rte_Exit_IsDynVolMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_DYN_VOL_Get(IS_DYN_VOL_MsgBase *IsDynVolBase, IS_DYN_VOL_MsgAdd *IsDynVolAdd)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_VOL_Get(P2VAR(IS_DYN_VOL_MsgBase, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolBase, P2VAR(IS_DYN_VOL_MsgAdd, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolAdd);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_IS_SUPV_DIRA_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <IS_SUPV_DIRA>
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
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsSupvDiraMsg(void)
 *   void Rte_Exit_IsSupvDiraMsg(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComOutput_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsSupvDira);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TxEnabled_Cnt_lgc(Boolean *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   PsaApaTranCause_Cnt_enum Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_enum(void)
 *   PsaApaSt_Cnt_enum Rte_IRead_SrlComOutput_Per1_APAState_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl1_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnLvl2_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AbsltHwPosnVld_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_AbsltHwPosn_HwDeg_f32(void)
 *   PsaAgArbnSt_Enum Rte_IRead_SrlComOutput_Per1_AgArbnStToSerlCom_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DmdDelestDaVld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DrvrIntvDetd_Cnt_lgc(void)
 *   PsaEpsStLxa_Cnt_enum Rte_IRead_SrlComOutput_Per1_EPSStateForLxa_Cnt_enum(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   PsaTunModSt_Cnt_enum Rte_IRead_SrlComOutput_Per1_ETATDADYN_Cnt_enum(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_LxaTqLimnActv_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_RelHwPosnToSerlCom_HwDeg_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_SendMsgOnChange(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_IndStatusETATDA2_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_IsDatDiraMsg(void)
 *   void Rte_Exit_IsDatDiraMsg(void)
 *   void Rte_Enter_IsDynDaeMsg(void)
 *   void Rte_Exit_IsDynDaeMsg(void)
 *   void Rte_Enter_IsDynVolMsg(void)
 *   void Rte_Exit_IsDynVolMsg(void)
 *   void Rte_Enter_IsSupvDiraMsg(void)
 *   void Rte_Exit_IsSupvDiraMsg(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_IndicatorStatus_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1526576304
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/SrlComOutput/utp/contract/Ap_SrlComOutput/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1526576304
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
