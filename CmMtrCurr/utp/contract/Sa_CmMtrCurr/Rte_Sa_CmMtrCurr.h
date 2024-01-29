/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Sa_CmMtrCurr.h
 *     Workspace:  C:/_Synergy_Projects/Working/CmMtrCurr-nz63rn - Copy/CmMtrCurr/autosar
 *     SW-C Type:  Sa_CmMtrCurr
 *  Generated at:  Wed Nov 20 14:59:09 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_CmMtrCurr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CMMTRCURR_H
# define _RTE_SA_CMMTRCURR_H

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

typedef P2CONST(struct Rte_CDS_Sa_CmMtrCurr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ADCMtrCurr1_Volts_f32 ((Float)0)
# define Rte_InitValue_ADCMtrCurr2_Volts_f32 ((Float)0)
# define Rte_InitValue_ComOffset_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_CorrMtrCurrPosition_Rev_f32 ((Float)0)
# define Rte_InitValue_CurrentGainSvc_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_FiltCntrlTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_MEC_Cnt_enum ((ManufModeType)0u)
# define Rte_InitValue_MtrCurr1TempOffset_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrCurr2TempOffset_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrCurrAngle_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrCurrK1_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrK2_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_SrlComSvcDft_Cnt_b32 ((UInt32)0u)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)
# define Rte_InitValue_VhSpdValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_CmMtrCurr_MEC_Cnt_enum(P2VAR(ManufModeType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_CmMtrCurr_VehSpd_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc(Boolean data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_CmMtrCurr_SystemState_Mode(void);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_EOLCurrTempOffset_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_EOLCurrTempOffset_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CmMtrCurr_Per1_FiltCntrlTemp_DegC_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per1_FiltCntrlTemp_DegC_f32->value)

# define Rte_IWrite_CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32() \
  (&Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32->value)

# define Rte_IWrite_CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32() \
  (&Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_ADCMtrCurr1_Volts_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_ADCMtrCurr1_Volts_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_ADCMtrCurr2_Volts_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_ADCMtrCurr2_Volts_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_CorrMtrCurrPosition_Rev_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_CorrMtrCurrPosition_Rev_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_MtrCurrAngle_Rev_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_MtrCurrAngle_Rev_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_MtrCurrK1_Amp_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_MtrCurrK1_Amp_f32->value)

# define Rte_IRead_CmMtrCurr_Per2_MtrCurrK2_Amp_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per2_MtrCurrK2_Amp_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_ADCMtrCurr1_Volts_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_ADCMtrCurr1_Volts_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_ADCMtrCurr2_Volts_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_ADCMtrCurr2_Volts_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_MtrVel_MtrRadpS_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_MtrVel_MtrRadpS_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_SrlComSvcDft_Cnt_b32->value)

# define Rte_IRead_CmMtrCurr_Per3_Vecu_Volt_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_Vecu_Volt_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_VehSpd_Kph_f32() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_VehSpd_Kph_f32->value)

# define Rte_IRead_CmMtrCurr_Per3_VhSpdValid_Cnt_lgc() \
  (Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_VhSpdValid_Cnt_lgc->value)

# define Rte_IWrite_CmMtrCurr_Per3_ComOffset_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_ComOffset_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CmMtrCurr_Per3_ComOffset_Cnt_u16() \
  (&Rte_Inst_Sa_CmMtrCurr->CmMtrCurr_Per3_ComOffset_Cnt_u16->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MEC_Cnt_enum Rte_Read_Sa_CmMtrCurr_MEC_Cnt_enum
# define Rte_Read_MtrVel_MtrRadpS_f32 Rte_Read_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32
# define Rte_Read_VehSpd_Kph_f32 Rte_Read_Sa_CmMtrCurr_VehSpd_Kph_f32
# define Rte_Read_VhSpdValid_Cnt_lgc Rte_Read_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_CurrentGainSvc_Cnt_lgc Rte_Write_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_CmMtrCurr_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLCurrTempOffset_WriteBlock Rte_Call_Sa_CmMtrCurr_EOLCurrTempOffset_WriteBlock
# define Rte_Call_EOLShCurrCal_SetRamBlockStatus Rte_Call_Sa_CmMtrCurr_EOLShCurrCal_SetRamBlockStatus
# define Rte_Call_EOLShCurrCal_WriteBlock Rte_Call_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_CurrTempOffset() (Rte_Inst_Sa_CmMtrCurr->Pim_CurrTempOffset)

# define Rte_Pim_ShCurrCal() (Rte_Inst_Sa_CmMtrCurr->Pim_ShCurrCal)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   CurrTempOffsetType *Rte_Pim_CurrTempOffset(void)
 *   PhaseCurrCal_DataType *Rte_Pim_ShCurrCal(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurrTempOffset_Scom_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <CmMtrCurrTempOffset_Scom>
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
 *   void CmMtrCurrTempOffset_Scom_Get(CurrTempOffsetType *CurrTempOffCal)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurrTempOffset_Scom_Get(P2VAR(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrTempOffCal);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurrTempOffset_Scom_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <CmMtrCurrTempOffset_Scom>
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLCurrTempOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLCurrTempOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CmMtrCurrTempOffset_Scom_Set(const CurrTempOffsetType *CurrTempOffCal)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurrTempOffset_Scom_Set(P2CONST(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) CurrTempOffCal);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_Init
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

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_Per1
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
 *   Float Rte_IRead_CmMtrCurr_Per1_FiltCntrlTemp_DegC_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CmMtrCurr_Per1_MtrCurr1TempOffset_Volt_f32(void)
 *   void Rte_IWrite_CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CmMtrCurr_Per1_MtrCurr2TempOffset_Volt_f32(void)
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

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OFF, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CmMtrCurr_Per2_ADCMtrCurr1_Volts_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per2_ADCMtrCurr2_Volts_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per2_CorrMtrCurrPosition_Rev_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per2_MtrCurrAngle_Rev_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per2_MtrCurrK1_Amp_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per2_MtrCurrK2_Amp_f32(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CmMtrCurr_Per3_ADCMtrCurr1_Volts_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per3_ADCMtrCurr2_Volts_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per3_MtrVel_MtrRadpS_f32(void)
 *   UInt32 Rte_IRead_CmMtrCurr_Per3_SrlComSvcDft_Cnt_b32(void)
 *   Float Rte_IRead_CmMtrCurr_Per3_Vecu_Volt_f32(void)
 *   Float Rte_IRead_CmMtrCurr_Per3_VehSpd_Kph_f32(void)
 *   Boolean Rte_IRead_CmMtrCurr_Per3_VhSpdValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CmMtrCurr_Per3_ComOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CmMtrCurr_Per3_ComOffset_Cnt_u16(void)
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MEC_Cnt_enum(ManufModeType *data)
 *   Std_ReturnType Rte_Read_MtrVel_MtrRadpS_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehSpd_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_VhSpdValid_Cnt_lgc(Boolean *data)
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
 *   Std_ReturnType Rte_Call_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CmMtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalGain(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MEC_Cnt_enum(ManufModeType *data)
 *   Std_ReturnType Rte_Read_MtrVel_MtrRadpS_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehSpd_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_VhSpdValid_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CurrentGainSvc_Cnt_lgc(Boolean data)
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
 *   Std_ReturnType CmMtrCurr_SCom_CalOffset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_SCom_MtrCurrOffReadStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MtrCurrOffReadStatus> of PortPrototype <CmMtrCurr_SCom>
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
 *   void CmMtrCurr_SCom_MtrCurrOffReadStatus(MtrCurrOffProcessFlag *CurrOffStatus)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrOffStatus);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_SCom_ReadMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadMtrCurrCals> of PortPrototype <CmMtrCurr_SCom>
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
 *   void CmMtrCurr_SCom_ReadMtrCurrCals(PhaseCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_ReadMtrCurrCals(P2VAR(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) ShCurrCalPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <CmMtrCurr_SCom>
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLShCurrCal_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);

# define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_CmMtrCurr_SCom_ConditionNotCorrect (34u)

# define RTE_E_CmMtrCurr_SCom_CurrentOutOfRange (20u)

# define RTE_E_CmMtrCurr_SCom_VehSpdOutofRange (21u)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1384973440
#    error "The magic number of the generated file <C:/_Synergy_Projects/Working/CmMtrCurr-nz63rn - Copy/CmMtrCurr/utp/contract/Sa_CmMtrCurr/Rte_Sa_CmMtrCurr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1384973440
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CMMTRCURR_H */
