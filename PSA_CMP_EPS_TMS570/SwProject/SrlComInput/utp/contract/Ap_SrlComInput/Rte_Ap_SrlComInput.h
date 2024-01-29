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
 *          File:  Rte_Ap_SrlComInput.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Thu May 17 19:49:01 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComInput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComInput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_APAAuthn_Cnt_lgc (FALSE)
# define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
# define Rte_InitValue_AbsActv_Cnt_lgc (FALSE)
# define Rte_InitValue_AccelLat_Cnt_s16 (0)
# define Rte_InitValue_AngleVolant_HwDeg_f32 (0.0F)
# define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
# define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
# define Rte_InitValue_ApaVehicleSpeedValid_Cnt_lgc (FALSE)
# define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_Batt_Volt_f32 (0.0F)
# define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
# define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_CONSANGLECPK_Cnt_s16 (0)
# define Rte_InitValue_CPKOK_Cnt_lgc (FALSE)
# define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_ColAngleSetpoint_HwDeg_f32 (0.0F)
# define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
# define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
# define Rte_InitValue_CompteurTemporelVehiculeRaw_Cnt_u32 (0U)
# define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
# define Rte_InitValue_ComputerRazGCTRaw_Cnt_u08 (0U)
# define Rte_InitValue_ConfigVhl_Cnt_u08 (0U)
# define Rte_InitValue_DMDFCTCPK_Cnt_u08 (0U)
# define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
# define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
# define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
# define Rte_InitValue_DmdDelestDaSts_Cnt_u08 (0U)
# define Rte_InitValue_DmdDelestDaVld_Cnt_lgc (FALSE)
# define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
# define Rte_InitValue_ESPDeconnecte_Cnt_u08 (1U)
# define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
# define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
# define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
# define Rte_InitValue_EngOn_Cnt_lgc (FALSE)
# define Rte_InitValue_EscAckFromSerlCom_Cnt_lgc (FALSE)
# define Rte_InitValue_EscActv_Cnt_lgc (FALSE)
# define Rte_InitValue_EscDataVldFromSerlCom_Cnt_lgc (FALSE)
# define Rte_InitValue_EscEna_Cnt_lgc (FALSE)
# define Rte_InitValue_EscFltPrsnt_Cnt_lgc (TRUE)
# define Rte_InitValue_EscOffsFromSerlCom_HwDeg_f32 (0.0F)
# define Rte_InitValue_EscPrecisionFromSerlCom_HwDeg_f32 (0.0F)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_EtatMTRaw_Cnt_u08 (0U)
# define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
# define Rte_InitValue_EtatPrincipSevIn_Cnt_u08 (0U)
# define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
# define Rte_InitValue_EtatReseauElecIn_Cnt_u08 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32 (0U)
# define Rte_InitValue_ISDATABR50DMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATABR50DMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI572MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI572MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc (FALSE)
# define Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYN2FRE3CDMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYN2FRE3CDMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNCDS34DMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNCDS34DMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
# define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
# define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
# define Rte_InitValue_KilometrageIn_Cnt_u32 (0U)
# define Rte_InitValue_LKAState_Cnt_u08 (0U)
# define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
# define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_LxaInpVld_Cnt_lgc (FALSE)
# define Rte_InitValue_LxaSeln_Cnt_lgc (FALSE)
# define Rte_InitValue_LxaStateFilt_Cnt_enum (0U)
# define Rte_InitValue_LxaTqFacReq_Uls_f32 (0.0F)
# define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
# define Rte_InitValue_MultiModeVld_Cnt_lgc (FALSE)
# define Rte_InitValue_MultimodeSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
# define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
# define Rte_InitValue_PowerSuppliesIn_Cnt_u08 (0U)
# define Rte_InitValue_RegulAbr_Cnt_u08 (0U)
# define Rte_InitValue_RegulEsp_Cnt_u08 (0U)
# define Rte_InitValue_ReqLampeDefEsp_Cnt_u08 (0U)
# define Rte_InitValue_ReqModeDA_Cnt_u08 (0U)
# define Rte_InitValue_ReqModeDAFinal_Cnt_enum (0U)
# define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
# define Rte_InitValue_SerialComAngleValid_Cnt_lgc (FALSE)
# define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
# define Rte_InitValue_ShuntPositionIn_Cnt_u08 (0U)
# define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_VVHType_Cnt_u08 (0U)
# define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
# define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleLatAccel_MpSecSq_f32 (0.0F)
# define Rte_InitValue_VehicleLatAccelValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AccelLat_Cnt_s16(P2VAR(SInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ColumnAngleSetpoint_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ComputerRazGCT_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ConfigVhl_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DiagIntegraElec_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DiagMuxOn_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DmdDelestDA_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ESPDeconnecte_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_EffacDefaultDiag_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_EtatMT_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_EtatPrincipSevIn_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_EtatReseauElecIn_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATABR50DMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATABR50DMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI412MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI412MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI432MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI432MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI572MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATBSI572MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxInProgress_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNAASMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNABRMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDYNVOLMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_KilometrageIn_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_LKAState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_LKATrqFactReq_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_LXAActivation_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ModeDiag_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2VAR(CanMsgType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PowerSuppliesIn_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_RegulAbr_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_RegulEsp_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ReqLampeDefEsp_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ReqModeDA_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ShuntPositionIn_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_VitesseVehicleBV_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DmdDelestDaSts_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DmdDelestDaVld_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VVHType_Cnt_u08(UInt8 data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComInput_SystemState_Mode(void);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStart(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStop(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CurrentTime);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComInput_DmdDelestDa(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComInput_DmdDelestDa(void);

FUNC(void, RTE_CODE) Rte_Enter_Ap_SrlComInput_EaShutdownTimeData(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_SrlComInput_EaShutdownTimeData(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComInput_Init_CAVHCSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_CAVHCSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_CityParkSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_CityParkSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_MultimodeSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_MultimodeSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_STTdSelected_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_CPKOK_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_CPKOK_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_CPKOK_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_CPKOK_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ElectronicIntegration_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_EnergyModeState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_EnergyModeState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_EnergyModeState_Cnt_enum() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_EnergyModeState_Cnt_enum->value)

# define Rte_IWrite_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Init_LxaInpVld_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_LxaInpVld_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_LxaInpVld_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_LxaInpVld_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_MultiModeVld_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_MultiModeVld_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_MultiModeVld_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_MultiModeVld_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_SrlComVehSpd_Kph_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_SrlComVehSpd_Kph_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_SrlComVehSpd_Kph_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_SrlComVehSpd_Kph_f32->value)

# define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32->value)

# define Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_Batt_Volt_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_Batt_Volt_f32->value)

# define Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_BusOff_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CTermActive_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ESCOffsCfgSeld_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Per1_EtatMTRaw_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EtatMTRaw_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_EtatMTRaw_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EtatMTRaw_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per2_DefaultVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_DefaultVehSpd_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_APAAuthn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_APAAuthn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_APAAuthn_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_APAAuthn_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_APARequest_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_APARequest_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_APARequest_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_APARequest_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_AbsActv_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_AbsActv_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_AbsActv_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_AbsActv_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_AngleVolant_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_AngleVolant_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_AngleVolant_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_AngleVolant_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ApaRelaxReq_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ApaRelaxReq_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_BSIDataMissing_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_BSIDataMissing_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_BSIDataMissing_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CMMDataMissing_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_CMMDataMissing_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CMMDataMissing_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CONSANGLECPK_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_CONSANGLECPK_Cnt_s16() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CONSANGLECPK_Cnt_s16->value)

# define Rte_IWrite_SrlComInput_Per2_CPKOK_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CPKOK_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_CPKOK_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_CPKOK_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_DMDFCTCPK_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_DMDFCTCPK_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_DMDFCTCPK_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ElectronicIntegration_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EnergyModeState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EnergyModeState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EnergyModeState_Cnt_enum() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EnergyModeState_Cnt_enum->value)

# define Rte_IWrite_SrlComInput_Per2_EngOn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EngOn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EngOn_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EngOn_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscActv_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscActv_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscActv_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscActv_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscEna_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscEna_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscEna_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscEna_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscFltPrsnt_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscFltPrsnt_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per2_IgnTimeOff_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_IgnTimeOff_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_IgnTimeOff_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_IgnTimeOff_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_Per2_LxaInpVld_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_LxaInpVld_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_LxaInpVld_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_LxaInpVld_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_LxaStateFilt_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_LxaStateFilt_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_LxaStateFilt_Cnt_enum() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_LxaStateFilt_Cnt_enum->value)

# define Rte_IWrite_SrlComInput_Per2_MultiModeVld_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_MultiModeVld_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_MultiModeVld_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_MultiModeVld_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ReqModeDAFinal_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ReqModeDAFinal_Cnt_enum->value)

# define Rte_IWrite_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_SerialComAngleValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_SerialComAngleValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_SrlComVehSpd_Kph_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_SrlComVehSpd_Kph_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_SrlComVehSpd_Kph_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_SrlComVehSpd_Kph_f32->value)

# define Rte_IWrite_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ValidEngineStatus_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_ValidEngineStatus_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_VehTimeValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehTimeValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_VehTimeValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehTimeValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32->value)

# define Rte_IWrite_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_EtatPrincipSev_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_EtatPrincipSev_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_EtatReseauElec_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_EtatReseauElec_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_EtatReseauElec_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32->value)

# define Rte_IWrite_SrlComInput_Trns2_Kilometrage_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_Kilometrage_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_Kilometrage_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_Kilometrage_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_Trns2_LxaSeln_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_LxaSeln_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_LxaSeln_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_LxaSeln_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_LxaTqFacReq_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_LxaTqFacReq_Uls_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_LxaTqFacReq_Uls_f32->value)

# define Rte_IWrite_SrlComInput_Trns2_PowerSupplies_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_PowerSupplies_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_PowerSupplies_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_PowerSupplies_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Trns2_ShuntPosition_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_ShuntPosition_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Trns2_ShuntPosition_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Trns2_ShuntPosition_Cnt_u08->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AccelLat_Cnt_s16 Rte_Read_Ap_SrlComInput_AccelLat_Cnt_s16
# define Rte_Read_AnneeEcoule_Cnt_u08 Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08
# define Rte_Read_ColumnAngleSetpoint_Cnt_u16 Rte_Read_Ap_SrlComInput_ColumnAngleSetpoint_Cnt_u16
# define Rte_Read_CompteurTemporelVehicule_Cnt_u32 Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32
# define Rte_Read_ComputerRazGCT_Cnt_u08 Rte_Read_Ap_SrlComInput_ComputerRazGCT_Cnt_u08
# define Rte_Read_ConfigVhl_Cnt_u08 Rte_Read_Ap_SrlComInput_ConfigVhl_Cnt_u08
# define Rte_Read_DiagIntegraElec_Cnt_u08 Rte_Read_Ap_SrlComInput_DiagIntegraElec_Cnt_u08
# define Rte_Read_DiagMuxOn_Cnt_u08 Rte_Read_Ap_SrlComInput_DiagMuxOn_Cnt_u08
# define Rte_Read_DmdDelestDA_Cnt_u08 Rte_Read_Ap_SrlComInput_DmdDelestDA_Cnt_u08
# define Rte_Read_ESPDeconnecte_Cnt_u08 Rte_Read_Ap_SrlComInput_ESPDeconnecte_Cnt_u08
# define Rte_Read_EffacDefaultDiag_Cnt_u08 Rte_Read_Ap_SrlComInput_EffacDefaultDiag_Cnt_u08
# define Rte_Read_EtatMT_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatMT_Cnt_u08
# define Rte_Read_EtatPrincipSevIn_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatPrincipSevIn_Cnt_u08
# define Rte_Read_EtatReseauElecIn_Cnt_u08 Rte_Read_Ap_SrlComInput_EtatReseauElecIn_Cnt_u08
# define Rte_Read_ISDAT4V2BSI552MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgDLCError_Cnt_u08
# define Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32
# define Rte_Read_ISDATABR50DMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATABR50DMsgDLCError_Cnt_u08
# define Rte_Read_ISDATABR50DMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATABR50DMsgRxTime_MSec_u32
# define Rte_Read_ISDATBSI3F2MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgDLCError_Cnt_u08
# define Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI3F2MsgRxTime_MSec_u32
# define Rte_Read_ISDATBSI412MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI412MsgDLCError_Cnt_u08
# define Rte_Read_ISDATBSI412MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI412MsgRxTime_MSec_u32
# define Rte_Read_ISDATBSI432MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI432MsgDLCError_Cnt_u08
# define Rte_Read_ISDATBSI432MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI432MsgRxTime_MSec_u32
# define Rte_Read_ISDATBSI572MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDATBSI572MsgDLCError_Cnt_u08
# define Rte_Read_ISDATBSI572MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATBSI572MsgRxTime_MSec_u32
# define Rte_Read_ISDATDIRAMsgTxInProgress_Cnt_lgc Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxInProgress_Cnt_lgc
# define Rte_Read_ISDATDIRAMsgTxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDATDIRAMsgTxTime_MSec_u32
# define Rte_Read_ISDYN2CMMMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgDLCError_Cnt_u08
# define Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYN2CMMMsgRxTime_MSec_u32
# define Rte_Read_ISDYN2FRE3CDMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgDLCError_Cnt_u08
# define Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYN2FRE3CDMsgRxTime_MSec_u32
# define Rte_Read_ISDYNAASMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNAASMsg_Cnt_u08
# define Rte_Read_ISDYNAASMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNAASMsgDLCError_Cnt_u08
# define Rte_Read_ISDYNAASMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNAASMsgRxTime_MSec_u32
# define Rte_Read_ISDYNABRMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNABRMsg_Cnt_u08
# define Rte_Read_ISDYNABRMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNABRMsgDLCError_Cnt_u08
# define Rte_Read_ISDYNABRMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNABRMsgRxTime_MSec_u32
# define Rte_Read_ISDYNCDS34DMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgDLCError_Cnt_u08
# define Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCDS34DMsgRxTime_MSec_u32
# define Rte_Read_ISDYNCMM208MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgDLCError_Cnt_u08
# define Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCMM208MsgRxTime_MSec_u32
# define Rte_Read_ISDYNCMM388MsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgDLCError_Cnt_u08
# define Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNCMM388MsgRxTime_MSec_u32
# define Rte_Read_ISDYNVOLMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNVOLMsg_Cnt_u08
# define Rte_Read_ISDYNVOLMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_ISDYNVOLMsgDLCError_Cnt_u08
# define Rte_Read_ISDYNVOLMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDYNVOLMsgRxTime_MSec_u32
# define Rte_Read_JourEcoule_Cnt_u16 Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16
# define Rte_Read_KilometrageIn_Cnt_u32 Rte_Read_Ap_SrlComInput_KilometrageIn_Cnt_u32
# define Rte_Read_LKAState_Cnt_u08 Rte_Read_Ap_SrlComInput_LKAState_Cnt_u08
# define Rte_Read_LKATrqFactReq_Cnt_u08 Rte_Read_Ap_SrlComInput_LKATrqFactReq_Cnt_u08
# define Rte_Read_LXAActivation_Cnt_u08 Rte_Read_Ap_SrlComInput_LXAActivation_Cnt_u08
# define Rte_Read_ModeDiag_Cnt_u08 Rte_Read_Ap_SrlComInput_ModeDiag_Cnt_u08
# define Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsg_Cnt_u08
# define Rte_Read_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08
# define Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32
# define Rte_Read_PowerSuppliesIn_Cnt_u08 Rte_Read_Ap_SrlComInput_PowerSuppliesIn_Cnt_u08
# define Rte_Read_RegulAbr_Cnt_u08 Rte_Read_Ap_SrlComInput_RegulAbr_Cnt_u08
# define Rte_Read_RegulEsp_Cnt_u08 Rte_Read_Ap_SrlComInput_RegulEsp_Cnt_u08
# define Rte_Read_ReqLampeDefEsp_Cnt_u08 Rte_Read_Ap_SrlComInput_ReqLampeDefEsp_Cnt_u08
# define Rte_Read_ReqModeDA_Cnt_u08 Rte_Read_Ap_SrlComInput_ReqModeDA_Cnt_u08
# define Rte_Read_SecondeEcoulee_Cnt_u32 Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32
# define Rte_Read_ShuntPositionIn_Cnt_u08 Rte_Read_Ap_SrlComInput_ShuntPositionIn_Cnt_u08
# define Rte_Read_VitesseVehicleBV_Cnt_u16 Rte_Read_Ap_SrlComInput_VitesseVehicleBV_Cnt_u16


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DmdDelestDaSts_Cnt_u08 Rte_Write_Ap_SrlComInput_DmdDelestDaSts_Cnt_u08
# define Rte_Write_DmdDelestDaVld_Cnt_lgc Rte_Write_Ap_SrlComInput_DmdDelestDaVld_Cnt_lgc
# define Rte_Write_VVHType_Cnt_u08 Rte_Write_Ap_SrlComInput_VVHType_Cnt_u08


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComInput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ElecInt_WriteBlock Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_SrlComInput_EpsEn_OP_GET
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_ShutdownTime_WriteBlock Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock
# define Rte_Call_SrlComDriver_SCom_ElecIntStart Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStart
# define Rte_Call_SrlComDriver_SCom_ElecIntStop Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStop
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32
# define Rte_Call_VHHTYPE_WriteBlock Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_DmdDelestDa Rte_Enter_Ap_SrlComInput_DmdDelestDa
# define Rte_Exit_DmdDelestDa Rte_Exit_Ap_SrlComInput_DmdDelestDa

# define Rte_Enter_EaShutdownTimeData Rte_Enter_Ap_SrlComInput_EaShutdownTimeData
# define Rte_Exit_EaShutdownTimeData Rte_Exit_Ap_SrlComInput_EaShutdownTimeData


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_VVHTYPEData() (Rte_Inst_Ap_SrlComInput->Pim_VVHTYPEData)

# define Rte_Pim_ElecIntData() (Rte_Inst_Ap_SrlComInput->Pim_ElecIntData)

# define Rte_Pim_ShutdownTimeData() (Rte_Inst_Ap_SrlComInput->Pim_ShutdownTimeData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt8 *Rte_Pim_VVHTYPEData(void)
 *   Boolean *Rte_Pim_ElecIntData(void)
 *   ShutdownTimeType *Rte_Pim_ShutdownTimeData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
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
 *   Boolean Rte_IRead_SrlComInput_Init_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_MultimodeSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_SrlComInput_Init_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Init_LxaInpVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_LxaInpVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_MultiModeVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_MultiModeVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Init_SrlComVehSpd_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDat4V2Bsi_552
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDAT4V2BSI552MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_KilometrageIn_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaShutdownTimeData(void)
 *   void Rte_Exit_EaShutdownTimeData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDat4V2Bsi_552(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatAbr_50D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATABR50DMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatAbr_50D(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_3F2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI3F2MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ColumnAngleSetpoint_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_LKAState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_LKATrqFactReq_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_LXAActivation_Cnt_u08(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_3F2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_412
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI412MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ReqModeDA_Cnt_u08(UInt8 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_412(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_432
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI432MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EtatPrincipSevIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatReseauElecIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_PowerSuppliesIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ShuntPositionIn_Cnt_u08(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_432(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_572
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI572MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ConfigVhl_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_572(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDyn2Cmm_348
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYN2CMMMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Cmm_348(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDyn2Fre_3CD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYN2FRE3CDMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AccelLat_Cnt_s16(SInt16 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Fre_3CD(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynAas_2EB
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNAASMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNAASMsg_Cnt_u08(UInt8 *data)
# else
 *   Std_ReturnType Rte_Read_ISDYNAASMsg_Cnt_u08(CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Read_ISDYNAASMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNAASMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAas_2EB(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynAbr_38D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNABRMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNABRMsg_Cnt_u08(UInt8 *data)
# else
 *   Std_ReturnType Rte_Read_ISDYNABRMsg_Cnt_u08(CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Read_ISDYNABRMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNABRMsgRxTime_MSec_u32(UInt32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAbr_38D(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCds_34D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCDS34DMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCds_34D(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCmm_208
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCMM208MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_208(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCmm_388
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCMM388MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_VitesseVehicleBV_Cnt_u16(UInt16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_388(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynVol_305
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNVOLMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNVOLMsg_Cnt_u08(UInt8 *data)
# else
 *   Std_ReturnType Rte_Read_ISDYNVOLMsg_Cnt_u08(CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynVol_305(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsInteElectronBsi_092
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISINTEELECTRONBSIMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagIntegraElec_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EffacDefaultDiag_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ModeDiag_Cnt_u08(UInt8 *data)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsInteElectronBsi_092(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgProtoHs1DynUcf_5CD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <PROTOHS1DYNUCF5CDMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08(UInt8 *data)
# else
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08(CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProtoHs1DynUcf_5CD(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ComputerRazGCT_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DiagMuxOn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DmdDelestDA_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatMT_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_ISDATDIRAMsgTxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNAASMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNABRMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_SrlComInput_Per1_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per1_EtatMTRaw_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_EtatMTRaw_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ESPDeconnecte_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_RegulAbr_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_RegulEsp_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ReqLampeDefEsp_Cnt_u08(UInt8 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_Per2_DefaultVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DmdDelestDaSts_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DmdDelestDaVld_Cnt_lgc(Boolean data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per2_APAAuthn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_APAAuthn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_APARequest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_APARequest_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_AbsActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_AbsActv_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_AngleVolant_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_AngleVolant_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(void)
 *   void Rte_IWrite_SrlComInput_Per2_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_SrlComInput_Per2_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_EngOn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EngOn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscActv_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscEna_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscEna_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Per2_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Per2_LxaInpVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_LxaInpVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_LxaStateFilt_Cnt_enum(PsaLxaSt_Cnt_enum data)
 *   PsaLxaSt_Cnt_enum *Rte_IWriteRef_SrlComInput_Per2_LxaStateFilt_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_MultiModeVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_MultiModeVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(PsaTunModSt_Cnt_enum data)
 *   PsaTunModSt_Cnt_enum *Rte_IWriteRef_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_SrlComVehSpd_Kph_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehTimeValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DmdDelestDa(void)
 *   void Rte_Exit_DmdDelestDa(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_GetNetworkDiagFltAcc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNetworkDiagFltAcc> of PortPrototype <SrlComInput_SCom>
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
 *   void SrlComInput_SCom_GetNetworkDiagFltAcc(UInt16 *MuteFltAcc_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
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
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
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
 *   void SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
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
 *   void SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaShutdownTimeData(void)
 *   void Rte_Exit_EaShutdownTimeData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_Kilometrage_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_LxaSeln_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Trns2_LxaSeln_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_ShuntPosition_Cnt_u08(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns2(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1526563491
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/SrlComInput/utp/contract/Ap_SrlComInput/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1526563491
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
