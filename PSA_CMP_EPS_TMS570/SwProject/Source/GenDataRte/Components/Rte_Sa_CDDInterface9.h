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
 *          File:  Components/Rte_Sa_CDDInterface9.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE9_H
# define _RTE_SA_CDDINTERFACE9_H

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
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ADCMtrCurr1_Volts_f32 (0.0F)
#  define Rte_InitValue_ADCMtrCurr2_Volts_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrPosition_Rev_f32 (0.0F)
#  define Rte_InitValue_CorrMtrPosElec_Rev_f32 (0.0F)
#  define Rte_InitValue_CorrectedElecMtrPos_Rev_u0p16 (0U)
#  define Rte_InitValue_CumMechMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_Die1RxError_Cnt_u16 (0U)
#  define Rte_InitValue_Die1RxMtrPos_Cnt_u16 (0U)
#  define Rte_InitValue_Die1RxRevCtr_Cnt_u16 (0U)
#  define Rte_InitValue_Die1UnderVoltgFltAccum_Cnt_u16 (0U)
#  define Rte_InitValue_Die2RxError_Cnt_u16 (0U)
#  define Rte_InitValue_Die2RxMtrPos_Cnt_u16 (0U)
#  define Rte_InitValue_Die2RxRevCtr_Cnt_u16 (0U)
#  define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
#  define Rte_InitValue_LRPRPhaseadvanceCaptured_Cnt_s16 (0)
#  define Rte_InitValue_MEC_Cnt_enum (0U)
#  define Rte_InitValue_MECTemp_Cnt_u08 (0U)
#  define Rte_InitValue_MechMtrPos1_Rev_f32 (0.0F)
#  define Rte_InitValue_MechMtrPos1Timestamp_USec_u32 (0U)
#  define Rte_InitValue_MechMtrPos2Timestamp_USec_u32 (0U)
#  define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrK1_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrK2_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQaxFinalRef_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrVoltDax_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltQax_Volt_f32 (0.0F)
#  define Rte_InitValue_RxMtrPosParityAccum_Cnt_u16 (0U)
#  define Rte_InitValue_SysCCorrMtrPosElec_Rev_f32 (0.0F)
#  define Rte_InitValue_SysCVSwitchADC_Cnt_u16 (0U)
#  define Rte_InitValue_UncorrMechMtrPos1_Rev_u0p16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_9, RTE_VAR_NOINIT) Rte_Task_Init_9;

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

#  define RTE_STOP_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
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

#  define Rte_IWrite_CDDInterface9_Init1_IgnCnt_Cnt_u16(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_IgnCnt_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init1_IgnCnt_Cnt_u16() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_IgnCnt_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Init1_MECTemp_Cnt_u08(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_MECTemp_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init1_MECTemp_Cnt_u08() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_MECTemp_Cnt_u08.value)

#  define Rte_IWrite_CDDInterface9_Init1_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init1_MEC_Cnt_enum() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init1.Rte_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ADCMtrCurr1_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ADCMtrCurr1_Volts_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ADCMtrCurr2_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ADCMtrCurr2_Volts_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrMtrPosElec_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrMtrPosElec_Rev_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrectedElecMtrPos_Rev_u0p16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CorrectedElecMtrPos_Rev_u0p16.value)

#  define Rte_IWrite_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CumMechMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_CumMechMtrPos_Rev_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_CumMechMtrPos_Rev_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die1RxError_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxError_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die1RxError_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxError_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxMtrPos_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxMtrPos_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxRevCtr_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1RxRevCtr_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1UnderVoltgFltAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die1UnderVoltgFltAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die2RxError_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxError_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die2RxError_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxError_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxMtrPos_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxMtrPos_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxRevCtr_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_Die2RxRevCtr_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value)

#  define Rte_IWrite_CDDInterface9_Per1_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MEC_Cnt_enum() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos1Timestamp_USec_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos1Timestamp_USec_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MechMtrPos1_Rev_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos1_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1_Rev_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos1_Rev_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos2Timestamp_USec_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MechMtrPos2Timestamp_USec_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_ModIdxFinal_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ModIdxFinal_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ModIdxFinal_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ModIdxFinal_Uls_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrDax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrDax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrCurrK1_Amp_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrK1_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK1_Amp_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrK1_Amp_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrCurrK2_Amp_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrK2_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK2_Amp_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrK2_Amp_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrQax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrCurrQax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrVoltDax_Volt_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVoltDax_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrVoltDax_Volt_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVoltDax_Volt_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrVoltQax_Volt_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVoltQax_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrVoltQax_Volt_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVoltQax_Volt_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_RxMtrPosParityAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_RxMtrPosParityAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SysCCorrMtrPosElec_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SysCCorrMtrPosElec_Rev_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SysCVSwitchADC_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SysCVSwitchADC_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_UncorrMechMtrPos1_Rev_u0p16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_UncorrMechMtrPos1_Rev_u0p16.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ClearPhsReasSum(arg1) (CDDPorts_ClearPhsReasSum(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Get_PhaseAbcFdbkMeas_PhaseFdbk(void);
#  define RTE_STOP_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Get_PhaseFdbk_PhaseFdbk() (Get_PhaseAbcFdbkMeas_PhaseFdbk(), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_SA_CDDINTERFACE9_H */
