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
 *          File:  Rte_Sa_CDDInterface9.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface9
 *  Generated at:  Mon May 14 15:06:04 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface9> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE9_H
# define _RTE_SA_CDDINTERFACE9_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface9, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ADCMtrCurr1_Volts_f32 (0.0F)
# define Rte_InitValue_ADCMtrCurr2_Volts_f32 (0.0F)
# define Rte_InitValue_CorrMtrCurrPosition_Rev_f32 (0.0F)
# define Rte_InitValue_CorrMtrPosElec_Rev_f32 (0.0F)
# define Rte_InitValue_CorrectedElecMtrPos_Rev_u0p16 (0U)
# define Rte_InitValue_CumMechMtrPos_Rev_f32 (0.0F)
# define Rte_InitValue_Die1RxError_Cnt_u16 (0U)
# define Rte_InitValue_Die1RxMtrPos_Cnt_u16 (0U)
# define Rte_InitValue_Die1RxRevCtr_Cnt_u16 (0U)
# define Rte_InitValue_Die1UnderVoltgFltAccum_Cnt_u16 (0U)
# define Rte_InitValue_Die2RxError_Cnt_u16 (0U)
# define Rte_InitValue_Die2RxMtrPos_Cnt_u16 (0U)
# define Rte_InitValue_Die2RxRevCtr_Cnt_u16 (0U)
# define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
# define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
# define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
# define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
# define Rte_InitValue_LRPRPhaseadvanceCaptured_Cnt_s16 (0)
# define Rte_InitValue_MEC_Cnt_enum (0U)
# define Rte_InitValue_MECTemp_Cnt_u08 (0U)
# define Rte_InitValue_MechMtrPos1_Rev_f32 (0.0F)
# define Rte_InitValue_MechMtrPos1Timestamp_USec_u32 (0U)
# define Rte_InitValue_MechMtrPos2Timestamp_USec_u32 (0U)
# define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
# define Rte_InitValue_MtrCurrDax_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrK1_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrK2_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrQaxFinalRef_Amp_f32 (0.0F)
# define Rte_InitValue_MtrVoltDax_Volt_f32 (0.0F)
# define Rte_InitValue_MtrVoltQax_Volt_f32 (0.0F)
# define Rte_InitValue_RxMtrPosParityAccum_Cnt_u16 (0U)
# define Rte_InitValue_SysCCorrMtrPosElec_Rev_f32 (0.0F)
# define Rte_InitValue_SysCVSwitchADC_Cnt_u16 (0U)
# define Rte_InitValue_UncorrMechMtrPos1_Rev_u0p16 (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface9_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface9_Get_PhaseFdbk_PhaseFdbk(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_CDDInterface9_Init1_IgnCnt_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_IgnCnt_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Init1_IgnCnt_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_IgnCnt_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Init1_MECTemp_Cnt_u08(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_MECTemp_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Init1_MECTemp_Cnt_u08() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_MECTemp_Cnt_u08->value)

# define Rte_IWrite_CDDInterface9_Init1_MEC_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_MEC_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Init1_MEC_Cnt_enum() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Init1_MEC_Cnt_enum->value)

# define Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ADCMtrCurr1_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ADCMtrCurr1_Volts_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ADCMtrCurr2_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ADCMtrCurr2_Volts_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrMtrPosElec_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrMtrPosElec_Rev_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16->value)

# define Rte_IWrite_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CumMechMtrPos_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_CumMechMtrPos_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_CumMechMtrPos_Rev_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_Die1RxError_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxError_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die1RxError_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxError_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die2RxError_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxError_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die2RxError_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxError_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32->value)

# define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32->value)

# define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32->value)

# define Rte_IWrite_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16->value)

# define Rte_IWrite_CDDInterface9_Per1_MEC_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MEC_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MEC_Cnt_enum() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MEC_Cnt_enum->value)

# define Rte_IWrite_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32->value)

# define Rte_IWrite_CDDInterface9_Per1_MechMtrPos1_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos1_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos1_Rev_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32->value)

# define Rte_IWrite_CDDInterface9_Per1_ModIdxFinal_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ModIdxFinal_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_ModIdxFinal_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_ModIdxFinal_Uls_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrDax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrDax_Amp_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrCurrK1_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrK1_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK1_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrK1_Amp_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrCurrK2_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrK2_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK2_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrK2_Amp_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrQax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrVoltDax_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrVoltDax_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrVoltDax_Volt_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrVoltDax_Volt_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_MtrVoltQax_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrVoltQax_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_MtrVoltQax_Volt_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_MtrVoltQax_Volt_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32->value)

# define Rte_IWrite_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16->value)

# define Rte_IWrite_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16() \
  (&Rte_Inst_Sa_CDDInterface9->CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CDDPorts_ClearPhsReasSum Rte_Call_Sa_CDDInterface9_CDDPorts_ClearPhsReasSum
# define Rte_Call_Get_PhaseFdbk_PhaseFdbk Rte_Call_Sa_CDDInterface9_Get_PhaseFdbk_PhaseFdbk




# define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface9_Init1_IgnCnt_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Init1_IgnCnt_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Init1_MECTemp_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_CDDInterface9_Init1_MECTemp_Cnt_u08(void)
 *   void Rte_IWrite_CDDInterface9_Init1_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface9_Init1_MEC_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxError_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxError_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxError_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxError_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface9_Per1_MEC_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos1_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ModIdxFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ModIdxFinal_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrK1_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK1_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrK2_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK2_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrVoltDax_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrVoltDax_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrVoltQax_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrVoltQax_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Get_PhaseFdbk_PhaseFdbk(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1526309527
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/CDDInterface/utp/contract/Sa_CDDInterface9/Rte_Sa_CDDInterface9.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1526309527
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE9_H */
