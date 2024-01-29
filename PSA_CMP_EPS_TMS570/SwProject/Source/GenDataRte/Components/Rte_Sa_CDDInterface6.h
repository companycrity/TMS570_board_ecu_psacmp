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
 *          File:  Components/Rte_Sa_CDDInterface6.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE6_H
# define _RTE_SA_CDDINTERFACE6_H

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

#  define Rte_InitValue_AVASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DftAsstTbl_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DwnldAsstGain_Uls_f32 (0.0F)
#  define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
#  define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FricLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LoaMgrDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MultiModeSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_WhlImbRejSrlComSvcDft_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_6, RTE_VAR_NOINIT) Rte_Task_Init_6;

extern VAR(Rte_tsTask_10ms_6, RTE_VAR_NOINIT) Rte_Task_10ms_6;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_Init_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface6_Init1_AVASelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Init1.Rte_AVASelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_AVASelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Init1.Rte_AVASelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CAVHCSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CAVHCSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CityParkSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_CityParkSelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CityParkSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Init1_LXASelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_LXASelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_LXASelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_LXASelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_MultiModeSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_MultiModeSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Init1_STTdSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_STTdSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Init1_STTdSelected_Cnt_lgc() \
  (&Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_STTdSelected_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface6_Per1_AVASelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_AVASelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_AVASelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_AVASelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_CAVHCSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_CAVHCSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_CityParkSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_CityParkSelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_CityParkSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DampingSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DampingSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DftAsstTbl_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DftAsstTbl_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DwnldAsstGain_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_DwnldAsstGain_Uls_f32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_DwnldAsstGain_Uls_f32.value)

#  define Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_EnergyModeState_Cnt_enum(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface6_Per1_EnergyModeState_Cnt_enum() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EnergyModeState_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_HystCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_HystCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_LXASelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LXASelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_LXASelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LXASelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LimitSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LimitSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LoaMgrDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_LoaMgrDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MfgDiagInhibit_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MfgDiagInhibit_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MultiModeSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_MultiModeSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_PullCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_PullCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ReturnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ReturnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_STTdSelected_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_STTdSelected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_STTdSelected_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_SrlComSvcDft_Cnt_b32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Sa_CDDInterface6_CDDInterface6_Per1.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ApplyMtrElecMechPol(arg1) (CDDPorts_ApplyMtrElecMechPol(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE6_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE6_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_SA_CDDINTERFACE6_H */
