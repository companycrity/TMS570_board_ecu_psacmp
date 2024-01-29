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
 *          File:  Rte_Ap_PsaAgArbn.h
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PsaAgArbn-nz2999/PsaAgArbn/autosar
 *     SW-C Type:  Ap_PsaAgArbn
 *  Generated at:  Tue Apr 24 13:32:44 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PsaAgArbn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSAAGARBN_H
# define _RTE_AP_PSAAGARBN_H

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

typedef P2CONST(struct Rte_CDS_Ap_PsaAgArbn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AbsltHwPosn_HwDeg_f32 ((Float)0)
# define Rte_InitValue_AbsltHwPosnLvl1_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_AbsltHwPosnLvl2_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_AbsltHwPosnPrecision_HwDeg_f32 ((Float)0)
# define Rte_InitValue_AbsltHwPosnVld_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_AgArbnStToSerlCom_Cnt_enum ((PsaAgArbnSt_Enum)0u)
# define Rte_InitValue_AlignedCumMechMtrPosStatus_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_AlignedRelHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CumMechMtrPosStatus_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_EscAckFromSerlCom_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EscDataVldFromSerlCom_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EscOffsEna_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EscOffsFromSerlCom_HwDeg_f32 ((Float)0)
# define Rte_InitValue_EscPrecisionFromSerlCom_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_RelHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_RelHwPosnToSerlCom_HwDeg_f32 ((Float)0)
# define Rte_InitValue_RelHwPosnVldToSerlCom_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SensorlessAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_SensorlessHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_TorqueCmdCRF_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_SystemTime_DtrmnElapsedTime_uS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PsaAgArbn_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_PSAAGARBN_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PsaAgArbn_Init1_EscOffsEna_Cnt_lgc() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Init1_EscOffsEna_Cnt_lgc->value)

# define Rte_IRead_PsaAgArbn_Per1_AlignedCumMechMtrPosStatus_Cnt_u08() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AlignedCumMechMtrPosStatus_Cnt_u08->value)

# define Rte_IRead_PsaAgArbn_Per1_AlignedRelHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AlignedRelHwPos_HwDeg_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_CumMechMtrPosStatus_Cnt_u08() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_CumMechMtrPosStatus_Cnt_u08->value)

# define Rte_IRead_PsaAgArbn_Per1_EscAckFromSerlCom_Cnt_lgc() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_EscAckFromSerlCom_Cnt_lgc->value)

# define Rte_IRead_PsaAgArbn_Per1_EscDataVldFromSerlCom_Cnt_lgc() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_EscDataVldFromSerlCom_Cnt_lgc->value)

# define Rte_IRead_PsaAgArbn_Per1_EscOffsEna_Cnt_lgc() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_EscOffsEna_Cnt_lgc->value)

# define Rte_IRead_PsaAgArbn_Per1_EscOffsFromSerlCom_HwDeg_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_EscOffsFromSerlCom_HwDeg_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_EscPrecisionFromSerlCom_HwDeg_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_EscPrecisionFromSerlCom_HwDeg_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_RelHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_RelHwPos_HwDeg_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_SensorlessAuthority_Uls_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_SensorlessAuthority_Uls_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_SensorlessHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_SensorlessHwPos_HwDeg_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_TorqueCmdCRF_MtrNm_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_TorqueCmdCRF_MtrNm_f32->value)

# define Rte_IRead_PsaAgArbn_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_PsaAgArbn_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc->value)

# define Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc->value)

# define Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc->value)

# define Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum->value)

# define Rte_IWrite_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_HandwheelAuthority_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32->value)

# define Rte_IWrite_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc() \
  (&Rte_Inst_Ap_PsaAgArbn->PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_PsaAgArbn_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PsaAgArbn_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_GetErrorStatus
# define Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_SetRamBlockStatus
# define Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock Rte_Call_Ap_PsaAgArbn_PsaAgArbnLrndOffsBlk_WriteBlock
# define Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32 Rte_Call_Ap_PsaAgArbn_SystemTime_DtrmnElapsedTime_uS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_PsaAgArbn_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PsaAgArbnLrndOffsData() (Rte_Inst_Ap_PsaAgArbn->Pim_PsaAgArbnLrndOffsData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   PsaAgAnLrndOffs_Str *Rte_Pim_PsaAgArbnLrndOffsData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_PSAAGARBN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_Init1
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
 *   Boolean Rte_IRead_PsaAgArbn_Init1_EscOffsEna_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
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
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_Per1
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
 *   UInt8 Rte_IRead_PsaAgArbn_Per1_AlignedCumMechMtrPosStatus_Cnt_u08(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_AlignedRelHwPos_HwDeg_f32(void)
 *   UInt8 Rte_IRead_PsaAgArbn_Per1_CumMechMtrPosStatus_Cnt_u08(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscAckFromSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscDataVldFromSerlCom_Cnt_lgc(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_EscOffsEna_Cnt_lgc(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_EscOffsFromSerlCom_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_RelHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_SensorlessAuthority_Uls_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_SensorlessHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_TorqueCmdCRF_MtrNm_f32(void)
 *   Boolean Rte_IRead_PsaAgArbn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_PsaAgArbn_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl1_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnLvl2_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnPrecision_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosnVld_Cnt_lgc(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_AbsltHwPosn_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(PsaAgArbnSt_Enum data)
 *   PsaAgArbnSt_Enum *Rte_IWriteRef_PsaAgArbn_Per1_AgArbnStToSerlCom_Cnt_enum(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_HandwheelAuthority_Uls_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_HandwheelPosition_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnToSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PsaAgArbn_Per1_RelHwPosnVldToSerlCom_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PsaAgArbn_SCom_PsaAaCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PsaAaCmd> of PortPrototype <PsaAgArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSAAGARBN_APPL_CODE) PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum);

# define RTE_STOP_SEC_AP_PSAAGARBN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1524579463
#    error "The magic number of the generated file <C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PsaAgArbn-nz2999/PsaAgArbn/tools/contract/Ap_PsaAgArbn/Rte_Ap_PsaAgArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1524579463
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PSAAGARBN_H */
