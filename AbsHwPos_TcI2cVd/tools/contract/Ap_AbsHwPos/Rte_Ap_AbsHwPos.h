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
 *          File:  Rte_Ap_AbsHwPos.h
 *     Workspace:  C:/Synergy_EA3/working/AbsHwPos_TcI2cVd/autosar
 *     SW-C Type:  Ap_AbsHwPos
 *  Generated at:  Thu Jan 26 14:30:22 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_AbsHwPos> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ABSHWPOS_H
# define _RTE_AP_ABSHWPOS_H

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

typedef P2CONST(struct Rte_CDS_Ap_AbsHwPos, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedCumMechMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_AlignedRelHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_ComplError_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CumMechMtrPosCRF_Deg_f32 ((Float)0)
# define Rte_InitValue_DiagStatusHwPosReducedPerf_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwPosSource_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_I2CHwAbsPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_I2CHwAbsPosValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ManufMode_Cnt_enum ((ManufModeType)0u)
# define Rte_InitValue_RelHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_SensorlessAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_SensorlessHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_SrlComHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_SrlComHwPosStatus_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_TurnsCntrValidity_Cnt_u08 ((UInt8)0u)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AbsHwPos_ManufMode_Cnt_enum(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AbsHwPos_TurnsCntrValidity_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_EOLVehCntrOffset_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) ErrorStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_EOLVehCntrOffset_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_EOLVehCntrOffset_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_AbsHwPos_Init1_ManufMode_Cnt_enum() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_ManufMode_Cnt_enum->value)

# define Rte_IWrite_AbsHwPos_Init1_HwPosSource_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_HwPosSource_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Init1_HwPosSource_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_HwPosSource_Cnt_u16->value)

# define Rte_IWrite_AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16->value)

# define Rte_IRead_AbsHwPos_Per1_AlignedCumMechMtrPosCRF_Deg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedCumMechMtrPosCRF_Deg_f32->value)

# define Rte_IRead_AbsHwPos_Per1_ComplError_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_ComplError_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per1_CumMechMtrPosCRF_Deg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_CumMechMtrPosCRF_Deg_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_RelHwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RelHwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_RelHwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RelHwPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per2_DiagStatusHwPosReducedPerf_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_DiagStatusHwPosReducedPerf_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per2_I2CHwAbsPosValid_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_I2CHwAbsPosValid_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per2_I2CHwAbsPos_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_I2CHwAbsPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per2_ManufMode_Cnt_enum() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_ManufMode_Cnt_enum->value)

# define Rte_IRead_AbsHwPos_Per2_SensorlessAuthority_Uls_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SensorlessAuthority_Uls_f32->value)

# define Rte_IRead_AbsHwPos_Per2_SensorlessHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SensorlessHwPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per2_TurnsCntrValidity_Cnt_u08() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_TurnsCntrValidity_Cnt_u08->value)

# define Rte_IWrite_AbsHwPos_Per2_HandwheelAuthority_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HandwheelAuthority_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per2_HandwheelAuthority_Uls_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HandwheelAuthority_Uls_f32->value)

# define Rte_IWrite_AbsHwPos_Per2_HandwheelPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HandwheelPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per2_HandwheelPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HandwheelPosition_HwDeg_f32->value)

# define Rte_IWrite_AbsHwPos_Per2_HwPosSource_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HwPosSource_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per2_HwPosSource_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_HwPosSource_Cnt_u16->value)

# define Rte_IWrite_AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16->value)

# define Rte_IWrite_AbsHwPos_Per2_SrlComHwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SrlComHwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per2_SrlComHwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_SrlComHwPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per3_I2CHwAbsPosValid_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per3_I2CHwAbsPosValid_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per3_I2CHwAbsPos_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per3_I2CHwAbsPos_HwDeg_f32->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ManufMode_Cnt_enum Rte_Read_Ap_AbsHwPos_ManufMode_Cnt_enum
# define Rte_Read_TurnsCntrValidity_Cnt_u08 Rte_Read_Ap_AbsHwPos_TurnsCntrValidity_Cnt_u08


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLVehCntrOffset_GetErrorStatus Rte_Call_Ap_AbsHwPos_EOLVehCntrOffset_GetErrorStatus
# define Rte_Call_EOLVehCntrOffset_WriteBlock Rte_Call_Ap_AbsHwPos_EOLVehCntrOffset_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_EOLVehCntrOffset() (Rte_Inst_Ap_AbsHwPos->Pim_EOLVehCntrOffset)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLHwPosTrimType *Rte_Pim_EOLVehCntrOffset(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_AbsHwPos_Init1_ManufMode_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Init1_HwPosSource_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Init1_HwPosSource_Cnt_u16(void)
 *   void Rte_IWrite_AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Init1_SrlComHwPosStatus_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPos_Per1_AlignedCumMechMtrPosCRF_Deg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_ComplError_HwDeg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_CumMechMtrPosCRF_Deg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_AlignedRelHwPos_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_RelHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_RelHwPos_HwDeg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_AbsHwPos_Per2_DiagStatusHwPosReducedPerf_Cnt_lgc(void)
 *   Boolean Rte_IRead_AbsHwPos_Per2_I2CHwAbsPosValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPos_Per2_I2CHwAbsPos_HwDeg_f32(void)
 *   ManufModeType Rte_IRead_AbsHwPos_Per2_ManufMode_Cnt_enum(void)
 *   Float Rte_IRead_AbsHwPos_Per2_SensorlessAuthority_Uls_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per2_SensorlessHwPos_HwDeg_f32(void)
 *   UInt8 Rte_IRead_AbsHwPos_Per2_TurnsCntrValidity_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Per2_HandwheelAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per2_HandwheelAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per2_HandwheelPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per2_HandwheelPosition_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per2_HwPosSource_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Per2_HwPosSource_Cnt_u16(void)
 *   void Rte_IWrite_AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Per2_SrlComHwPosStatus_Cnt_u16(void)
 *   void Rte_IWrite_AbsHwPos_Per2_SrlComHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per2_SrlComHwPos_HwDeg_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_AbsHwPos_Per3_I2CHwAbsPosValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPos_Per3_I2CHwAbsPos_HwDeg_f32(void)
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

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
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

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per4(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_CustClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustClrTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ManufMode_Cnt_enum(ManufModeType *data)
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SCom_CustClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_CustClrTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_CustSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ManufMode_Cnt_enum(ManufModeType *data)
 *   Std_ReturnType Rte_Read_TurnsCntrValidity_Cnt_u08(UInt8 *data)
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AbsHwPos_SCom_CustSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_CustSetTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_NxtClearTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtClearTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SCom_NxtClearTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_NxtClearTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_NxtSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TurnsCntrValidity_Cnt_u08(UInt8 *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLVehCntrOffset_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *   RTE_E_AbsHwPos_SCom_ValueNotAccepted
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32);

# define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_AbsHwPos_SCom_TrimNotPerformed (34u)

# define RTE_E_AbsHwPos_SCom_ValueNotAccepted (49u)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1485462317
#    error "The magic number of the generated file <C:/Synergy_EA3/working/AbsHwPos_TcI2cVd/tools/contract/Ap_AbsHwPos/Rte_Ap_AbsHwPos.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1485462317
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ABSHWPOS_H */
