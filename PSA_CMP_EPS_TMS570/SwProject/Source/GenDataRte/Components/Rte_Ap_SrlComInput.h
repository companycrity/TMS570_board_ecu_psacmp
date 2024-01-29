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
 *          File:  Components/Rte_Ap_SrlComInput.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

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

# include "Rte_Hook.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_DmdDelestDaSts_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DmdDelestDaVld_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VVHType_Cnt_u08;
extern VAR(SInt16, RTE_VAR_INIT) Rte_SrlComDriver_AccelLat_Cnt_s16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_AnneeEcoule_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_ColumnAngleSetpoint_Cnt_u16;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_CompteurTemporelVehicule_Cnt_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ComputerRazGCT_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ConfigVhl_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_DiagIntegraElec_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_DiagMuxOn_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_DmdDelestDA_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ESPDeconnecte_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_EffacDefaultDiag_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_EtatMT_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_EtatPrincipSev_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_EtatReseauElec_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_JourEcoule_Cnt_u16;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_Kilometrage_Cnt_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LKAState_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LKATrqFactReq_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LXAActivation_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ModeDiag_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_PowerSupplies_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_RegulABR_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_RegulESP_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ReqLampeDefEsp_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ReqModeDA_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_SecondeEcoulee_Cnt_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ShuntPosition_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_VitesseVehicleBV_Cnt_u16;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_APAAuthn_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_AbsActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_AccelLat_Cnt_s16 (0)
#  define Rte_InitValue_AngleVolant_HwDeg_f32 (0.0F)
#  define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
#  define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaVehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_Batt_Volt_f32 (0.0F)
#  define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_CONSANGLECPK_Cnt_s16 (0)
#  define Rte_InitValue_CPKOK_Cnt_lgc (FALSE)
#  define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_ColAngleSetpoint_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
#  define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
#  define Rte_InitValue_CompteurTemporelVehiculeRaw_Cnt_u32 (0U)
#  define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
#  define Rte_InitValue_ComputerRazGCTRaw_Cnt_u08 (0U)
#  define Rte_InitValue_ConfigVhl_Cnt_u08 (0U)
#  define Rte_InitValue_DMDFCTCPK_Cnt_u08 (0U)
#  define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
#  define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
#  define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
#  define Rte_InitValue_DmdDelestDaSts_Cnt_u08 (0U)
#  define Rte_InitValue_DmdDelestDaVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESPDeconnecte_Cnt_u08 (1U)
#  define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
#  define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
#  define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
#  define Rte_InitValue_EngOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscAckFromSerlCom_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscDataVldFromSerlCom_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscEna_Cnt_lgc (FALSE)
#  define Rte_InitValue_EscFltPrsnt_Cnt_lgc (TRUE)
#  define Rte_InitValue_EscOffsFromSerlCom_HwDeg_f32 (0.0F)
#  define Rte_InitValue_EscPrecisionFromSerlCom_HwDeg_f32 (0.0F)
#  define Rte_InitValue_EtatMT_Cnt_u08 (0U)
#  define Rte_InitValue_EtatMTRaw_Cnt_u08 (0U)
#  define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
#  define Rte_InitValue_EtatPrincipSevIn_Cnt_u08 (0U)
#  define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
#  define Rte_InitValue_EtatReseauElecIn_Cnt_u08 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32 (0U)
#  define Rte_InitValue_ISDATABR50DMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATABR50DMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI572MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI572MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc (FALSE)
#  define Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYN2FRE3CDMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYN2FRE3CDMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNCDS34DMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNCDS34DMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
#  define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
#  define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
#  define Rte_InitValue_KilometrageIn_Cnt_u32 (0U)
#  define Rte_InitValue_LKAState_Cnt_u08 (0U)
#  define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
#  define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
#  define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaInpVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaSeln_Cnt_lgc (FALSE)
#  define Rte_InitValue_LxaStateFilt_Cnt_enum (0U)
#  define Rte_InitValue_LxaTqFacReq_Uls_f32 (0.0F)
#  define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
#  define Rte_InitValue_MultiModeVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_MultimodeSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
#  define Rte_InitValue_PowerSuppliesIn_Cnt_u08 (0U)
#  define Rte_InitValue_RegulAbr_Cnt_u08 (0U)
#  define Rte_InitValue_RegulEsp_Cnt_u08 (0U)
#  define Rte_InitValue_ReqLampeDefEsp_Cnt_u08 (0U)
#  define Rte_InitValue_ReqModeDA_Cnt_u08 (0U)
#  define Rte_InitValue_ReqModeDAFinal_Cnt_enum (0U)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
#  define Rte_InitValue_SerialComAngleValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
#  define Rte_InitValue_ShuntPositionIn_Cnt_u08 (0U)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_VVHType_Cnt_u08 (0U)
#  define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleLatAccel_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_VehicleLatAccelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;

extern VAR(Rte_tsTask_10ms_10b, RTE_VAR_NOINIT) Rte_Task_10ms_10b;

extern VAR(Rte_tsTask_Trns_10, RTE_VAR_NOINIT) Rte_Task_Trns_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif



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

#  define Rte_IRead_SrlComInput_Init_CAVHCSelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_CAVHCSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_CityParkSelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_CityParkSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface10_ESCOffsCfgSeld_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_LXASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_MultimodeSelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_MultimodeSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ApaVehicleSpeedValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ApaVehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_CPKOK_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_CPKOK_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_CPKOK_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_CPKOK_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ElectronicIntegration_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_EnergyModeState_Cnt_enum(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_EnergyModeState_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_EnergyModeState_Cnt_enum() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_EnergyModeState_Cnt_enum.value)

#  define Rte_IWrite_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_EscPrecisionFromSerlCom_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_EscPrecisionFromSerlCom_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Init_LxaInpVld_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_LxaInpVld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_LxaInpVld_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_LxaInpVld_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_MultiModeVld_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_MultiModeVld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_MultiModeVld_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_MultiModeVld_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_SrlComVehSpd_Kph_f32(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_SrlComVehSpd_Kph_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_SrlComVehSpd_Kph_f32() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_SrlComVehSpd_Kph_f32.value)

#  define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_CompteurTemporelVehiculeRaw_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_CompteurTemporelVehiculeRaw_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32.value)

#  define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_Kilometrage_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552.Rte_Kilometrage_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2.Rte_LxaSeln_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2.Rte_LxaSeln_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2.Rte_LxaTqFacReq_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2.Rte_LxaTqFacReq_Uls_f32.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_EtatPrincipSev_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_EtatPrincipSev_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_EtatReseauElec_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_EtatReseauElec_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_PowerSupplies_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_PowerSupplies_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_ShuntPosition_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432.Rte_ShuntPosition_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_Batt_Volt_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_Batt_Volt_f32.value)

#  define Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_BusOff_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CTermActive_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ESCOffsCfgSeld_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ComputerRazGCTRaw_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ComputerRazGCTRaw_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Per1_EtatMTRaw_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EtatMTRaw_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_EtatMTRaw_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EtatMTRaw_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per2_DefaultVehSpd_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_DefaultVehSpd_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_APAAuthn_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_APAAuthn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_APAAuthn_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_APAAuthn_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_APARequest_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_APARequest_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_APARequest_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_APARequest_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_AbsActv_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_AbsActv_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_AbsActv_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_AbsActv_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_AngleVolant_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_AngleVolant_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_AngleVolant_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_AngleVolant_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ApaRelaxReq_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ApaRelaxReq_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ApaVehicleSpeedValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ApaVehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_BSIDataMissing_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_BSIDataMissing_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_BSIDataMissing_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CMMDataMissing_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_CMMDataMissing_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CMMDataMissing_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CONSANGLECPK_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_CONSANGLECPK_Cnt_s16() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CONSANGLECPK_Cnt_s16.value)

#  define Rte_IWrite_SrlComInput_Per2_CPKOK_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CPKOK_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_CPKOK_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_CPKOK_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ColAngleSetpoint_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ColAngleSetpoint_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_DMDFCTCPK_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_DMDFCTCPK_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_DMDFCTCPK_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ElectronicIntegration_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EnergyModeState_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EnergyModeState_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EnergyModeState_Cnt_enum() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EnergyModeState_Cnt_enum.value)

#  define Rte_IWrite_SrlComInput_Per2_EngOn_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EngOn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EngOn_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EngOn_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscAckFromSerlCom_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscAckFromSerlCom_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscActv_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscActv_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscActv_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscActv_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscDataVldFromSerlCom_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscDataVldFromSerlCom_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscEna_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscEna_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscEna_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscEna_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscFltPrsnt_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscFltPrsnt_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscOffsFromSerlCom_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscOffsFromSerlCom_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscPrecisionFromSerlCom_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_EscPrecisionFromSerlCom_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_IgnTimeOff_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_IgnTimeOff_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_IgnTimeOff_Cnt_u32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_IgnTimeOff_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_Per2_LxaInpVld_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_LxaInpVld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_LxaInpVld_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_LxaInpVld_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_LxaStateFilt_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_LxaStateFilt_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_LxaStateFilt_Cnt_enum() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_LxaStateFilt_Cnt_enum.value)

#  define Rte_IWrite_SrlComInput_Per2_MultiModeVld_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_MultiModeVld_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_MultiModeVld_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_MultiModeVld_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_PosSrvoHwAngle_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_PosSrvoHwAngle_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ReqModeDAFinal_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ReqModeDAFinal_Cnt_enum.value)

#  define Rte_IWrite_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_SerialComAngleValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_SerialComAngleValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_SrlComVehSpd_Kph_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_SrlComVehSpd_Kph_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_SrlComVehSpd_Kph_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_SrlComVehSpd_Kph_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ValidEngineStatus_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_ValidEngineStatus_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_VehTimeValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehTimeValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_VehTimeValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehTimeValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleLatAccelValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleLatAccelValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleLatAccel_MpSecSq_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleLatAccel_MpSecSq_f32.value)

#  define Rte_IWrite_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleSpeedValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per2.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_CompteurTemporelVehiculeRaw_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_CompteurTemporelVehiculeRaw_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_EtatPrincipSev_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_EtatPrincipSev_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_EtatReseauElec_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_EtatReseauElec_Cnt_u08() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_EtatReseauElec_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32.value)

#  define Rte_IWrite_SrlComInput_Trns2_Kilometrage_Cnt_u32(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_Kilometrage_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_Kilometrage_Cnt_u32() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_Kilometrage_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_Trns2_LxaSeln_Cnt_lgc(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_LxaSeln_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_LxaSeln_Cnt_lgc() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_LxaSeln_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_LxaTqFacReq_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_LxaTqFacReq_Uls_f32() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_LxaTqFacReq_Uls_f32.value)

#  define Rte_IWrite_SrlComInput_Trns2_PowerSupplies_Cnt_u08(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_PowerSupplies_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_PowerSupplies_Cnt_u08() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_PowerSupplies_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Trns2_ShuntPosition_Cnt_u08(data) \
  ( \
    Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_ShuntPosition_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Trns2_ShuntPosition_Cnt_u08() \
  (&Rte_Task_Trns_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Trns2.Rte_ShuntPosition_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AccelLat_Cnt_s16 Rte_Read_Ap_SrlComInput_AccelLat_Cnt_s16
#  define Rte_Read_Ap_SrlComInput_AccelLat_Cnt_s16(data) (*(data) = Rte_SrlComDriver_AccelLat_Cnt_s16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_AnneeEcoule_Cnt_u08 Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08(data) (*(data) = Rte_SrlComDriver_AnneeEcoule_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ColumnAngleSetpoint_Cnt_u16 Rte_Read_Ap_SrlComInput_ColumnAngleSetpoint_Cnt_u16
#  define Rte_Read_Ap_SrlComInput_ColumnAngleSetpoint_Cnt_u16(data) (*(data) = Rte_SrlComDriver_ColumnAngleSetpoint_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CompteurTemporelVehicule_Cnt_u32 Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32
#  define Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32(data) (*(data) = Rte_SrlComDriver_CompteurTemporelVehicule_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ComputerRazGCT_Cnt_u08 Rte_Read_Ap_SrlComInput_ComputerRazGCT_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ComputerRazGCT_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ComputerRazGCT_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ConfigVhl_Cnt_u08 Rte_Read_Ap_SrlComInput_ConfigVhl_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ConfigVhl_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ConfigVhl_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagIntegraElec_Cnt_u08 Rte_Read_Ap_SrlComInput_DiagIntegraElec_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_DiagIntegraElec_Cnt_u08(data) (*(data) = Rte_SrlComDriver_DiagIntegraElec_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagMuxOn_Cnt_u08 Rte_Read_Ap_SrlComInput_DiagMuxOn_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_DiagMuxOn_Cnt_u08(data) (*(data) = Rte_SrlComDriver_DiagMuxOn_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DmdDelestDA_Cnt_u08 Rte_Read_Ap_SrlComInput_DmdDelestDA_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_DmdDelestDA_Cnt_u08(data) (*(data) = Rte_SrlComDriver_DmdDelestDA_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ESPDeconnecte_Cnt_u08 Rte_Read_Ap_SrlComInput_ESPDeconnecte_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ESPDeconnecte_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ESPDeconnecte_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EffacDefaultDiag_Cnt_u08 Rte_Read_Ap_SrlComInput_EffacDefaultDiag_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_EffacDefaultDiag_Cnt_u08(data) (*(data) = Rte_SrlComDriver_EffacDefaultDiag_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EtatMT_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatMT_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_EtatMT_Cnt_u08(data) (*(data) = Rte_SrlComDriver_EtatMT_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EtatPrincipSevIn_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatPrincipSevIn_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_EtatPrincipSevIn_Cnt_u08(data) (*(data) = Rte_SrlComDriver_EtatPrincipSev_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EtatReseauElecIn_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatReseauElecIn_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_EtatReseauElecIn_Cnt_u08(data) (*(data) = Rte_SrlComDriver_EtatReseauElec_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDAT4V2BSI552MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATABR50DMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATABR50DMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDATABR50DMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATABR50DMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATABR50DMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATABR50DMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI3F2MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI412MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI412MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDATBSI412MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI412MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI412MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATBSI412MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI432MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI432MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDATBSI432MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI432MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI432MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATBSI432MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI572MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI572MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDATBSI572MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATBSI572MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI572MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATBSI572MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATDIRAMsgTxInProgress_Cnt_lgc Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxInProgress_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxInProgress_Cnt_lgc(data) (*(data) = Rte_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDATDIRAMsgTxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYN2CMMMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYN2FRE3CDMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNAASMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08
#  define Rte_Read_ISDYNAASMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNAASMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNAASMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNAASMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNAASMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNAASMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNABRMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08
#  define Rte_Read_ISDYNABRMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNABRMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNABRMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNABRMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNABRMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNABRMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCDS34DMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCMM208MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCMM388MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNVOLMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08
#  define Rte_Read_ISDYNVOLMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNVOLMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ISDYNVOLMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDYNVOLMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNVOLMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDYNVOLMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_JourEcoule_Cnt_u16 Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16
#  define Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16(data) (*(data) = Rte_SrlComDriver_JourEcoule_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_KilometrageIn_Cnt_u32 Rte_Read_Ap_SrlComInput_KilometrageIn_Cnt_u32
#  define Rte_Read_Ap_SrlComInput_KilometrageIn_Cnt_u32(data) (*(data) = Rte_SrlComDriver_Kilometrage_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LKAState_Cnt_u08 Rte_Read_Ap_SrlComInput_LKAState_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_LKAState_Cnt_u08(data) (*(data) = Rte_SrlComDriver_LKAState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LKATrqFactReq_Cnt_u08 Rte_Read_Ap_SrlComInput_LKATrqFactReq_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_LKATrqFactReq_Cnt_u08(data) (*(data) = Rte_SrlComDriver_LKATrqFactReq_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LXAActivation_Cnt_u08 Rte_Read_Ap_SrlComInput_LXAActivation_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_LXAActivation_Cnt_u08(data) (*(data) = Rte_SrlComDriver_LXAActivation_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ModeDiag_Cnt_u08 Rte_Read_Ap_SrlComInput_ModeDiag_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ModeDiag_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ModeDiag_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08
#  define Rte_Read_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(data) (*(data) = Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PowerSuppliesIn_Cnt_u08 Rte_Read_Ap_SrlComInput_PowerSuppliesIn_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_PowerSuppliesIn_Cnt_u08(data) (*(data) = Rte_SrlComDriver_PowerSupplies_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RegulAbr_Cnt_u08 Rte_Read_Ap_SrlComInput_RegulAbr_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_RegulAbr_Cnt_u08(data) (*(data) = Rte_SrlComDriver_RegulABR_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RegulEsp_Cnt_u08 Rte_Read_Ap_SrlComInput_RegulEsp_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_RegulEsp_Cnt_u08(data) (*(data) = Rte_SrlComDriver_RegulESP_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ReqLampeDefEsp_Cnt_u08 Rte_Read_Ap_SrlComInput_ReqLampeDefEsp_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ReqLampeDefEsp_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ReqLampeDefEsp_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ReqModeDA_Cnt_u08 Rte_Read_Ap_SrlComInput_ReqModeDA_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ReqModeDA_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ReqModeDA_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SecondeEcoulee_Cnt_u32 Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32
#  define Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32(data) (*(data) = Rte_SrlComDriver_SecondeEcoulee_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ShuntPositionIn_Cnt_u08 Rte_Read_Ap_SrlComInput_ShuntPositionIn_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_ShuntPositionIn_Cnt_u08(data) (*(data) = Rte_SrlComDriver_ShuntPosition_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VitesseVehicleBV_Cnt_u16 Rte_Read_Ap_SrlComInput_VitesseVehicleBV_Cnt_u16
#  define Rte_Read_Ap_SrlComInput_VitesseVehicleBV_Cnt_u16(data) (*(data) = Rte_SrlComDriver_VitesseVehicleBV_Cnt_u16, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_DmdDelestDaSts_Cnt_u08 Rte_Write_Ap_SrlComInput_DmdDelestDaSts_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_DmdDelestDaSts_Cnt_u08(data) (Rte_SrlComInput_DmdDelestDaSts_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DmdDelestDaVld_Cnt_lgc Rte_Write_Ap_SrlComInput_DmdDelestDaVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DmdDelestDaVld_Cnt_lgc(data) (Rte_SrlComInput_DmdDelestDaVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VVHType_Cnt_u08 Rte_Write_Ap_SrlComInput_VVHType_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_VVHType_Cnt_u08(data) (Rte_SrlComInput_VVHType_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ElecInt_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)18, arg1))
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr10_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define Rte_Call_ShutdownTime_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)19, arg1))
#  define RTE_START_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void);
#  define RTE_STOP_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SrlComDriver_SCom_ElecIntStart() (NtWrapC_SrlComDriver_SCom_ElecIntStart(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void);
#  define RTE_STOP_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SrlComDriver_SCom_ElecIntStop() (NtWrapC_SrlComDriver_SCom_ElecIntStop(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_VHHTYPE_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)17, arg1))


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_DmdDelestDa() \
  { \
    Rte_EnterHook_Ap_SrlComInput_DmdDelestDa_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Ap_SrlComInput_DmdDelestDa_Return(); \
  }

#  define Rte_Exit_DmdDelestDa() \
  { \
    Rte_ExitHook_Ap_SrlComInput_DmdDelestDa_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Ap_SrlComInput_DmdDelestDa_Return(); \
  }

#  define Rte_Enter_EaShutdownTimeData() \
  { \
    Rte_EnterHook_Ap_SrlComInput_EaShutdownTimeData_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Ap_SrlComInput_EaShutdownTimeData_Return(); \
  }

#  define Rte_Exit_EaShutdownTimeData() \
  { \
    Rte_ExitHook_Ap_SrlComInput_EaShutdownTimeData_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Ap_SrlComInput_EaShutdownTimeData_Return(); \
  }


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_VVHTYPEData;
extern VAR(Boolean, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ElecIntData;
extern VAR(ShutdownTimeType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ShutdownTimeData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_VVHTYPEData() \
  (&Rte_SrlComInput_VVHTYPEData)

#  define Rte_Pim_ElecIntData() \
  (&Rte_SrlComInput_ElecIntData)

#  define Rte_Pim_ShutdownTimeData() \
  (&Rte_SrlComInput_ShutdownTimeData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDat4V2Bsi_552(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatAbr_50D(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_3F2(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_412(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_432(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_572(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Cmm_348(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Fre_3CD(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAas_2EB(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAbr_38D(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCds_34D(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_208(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_388(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynVol_305(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsInteElectronBsi_092(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProtoHs1DynUcf_5CD(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per2(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns2(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_SRLCOMINPUT_H */
