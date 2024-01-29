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
 *          File:  Rte_Sa_CDDInterface6.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface6
 *  Generated at:  Fri Dec  8 18:24:12 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface6> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE6_H
# define _RTE_SA_CDDINTERFACE6_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface6, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AVASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_DftAsstTbl_Cnt_lgc (FALSE)
# define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_DwnldAsstGain_Uls_f32 (0.0F)
# define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
# define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_FricLrnSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_LoaMgrDft_Cnt_lgc (FALSE)
# define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
# define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
# define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_MultiModeSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
# define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_WhlImbRejSrlComSvcDft_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface6_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IWrite_CDDInterface6_Init1_AVASelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_AVASelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_AVASelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_AVASelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_CAVHCSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_CAVHCSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_CityParkSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_CityParkSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_CityParkSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Init1_LXASelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_LXASelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_LXASelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_LXASelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_MultiModeSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_MultiModeSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Init1_STTdSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_STTdSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Init1_STTdSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Init1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IWrite_CDDInterface6_Per1_AVASelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_AVASelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_AVASelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_AVASelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_CAVHCSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_CAVHCSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_CityParkSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_CityParkSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_CityParkSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DftAsstTbl_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DftAsstTbl_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DwnldAsstGain_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_DwnldAsstGain_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_DwnldAsstGain_Uls_f32->value)

# define Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_EnergyModeState_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EnergyModeState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_EnergyModeState_Cnt_enum() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EnergyModeState_Cnt_enum->value)

# define Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_LXASelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LXASelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_LXASelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LXASelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LoaMgrDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_LoaMgrDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MultiModeSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_MultiModeSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_STTdSelected_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_STTdSelected_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_STTdSelected_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_STTdSelected_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_SrlComSvcDft_Cnt_b32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_SrlComSvcDft_Cnt_b32->value)

# define Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface6->CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CDDPorts_ApplyMtrElecMechPol Rte_Call_Sa_CDDInterface6_CDDPorts_ApplyMtrElecMechPol




# define RTE_START_SEC_SA_CDDINTERFACE6_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface6_Init1
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
 *   SInt8 Rte_IRead_CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface6_Init1_AVASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_AVASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_LXASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_LXASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_STTdSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_STTdSelected_Cnt_lgc(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface6_Per1
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
 *   SInt8 Rte_IRead_CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface6_Per1_AVASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_AVASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_CDDInterface6_Per1_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LXASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LXASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_STTdSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_STTdSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE6_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1512761566
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/CDDInterface/utp/contract/Sa_CDDInterface6/Rte_Sa_CDDInterface6.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1512761566
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE6_H */
