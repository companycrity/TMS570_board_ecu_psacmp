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
 *          File:  Rte_Cd_SrlComDriver.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Cd_SrlComDriver
 *  Generated at:  Mon Apr 30 20:03:43 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Cd_SrlComDriver> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_SRLCOMDRIVER_H
# define _RTE_CD_SRLCOMDRIVER_H

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

typedef P2CONST(struct Rte_CDS_Cd_SrlComDriver, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AccelLat_Cnt_s16 (0)
# define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
# define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
# define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
# define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
# define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
# define Rte_InitValue_ConfigVhl_Cnt_u08 (0U)
# define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
# define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
# define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
# define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
# define Rte_InitValue_ESPDeconnecte_Cnt_u08 (1U)
# define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
# define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
# define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
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
# define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
# define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
# define Rte_InitValue_LKAState_Cnt_u08 (0U)
# define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
# define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
# define Rte_InitValue_MultimodeSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
# define Rte_InitValue_RegulABR_Cnt_u08 (0U)
# define Rte_InitValue_RegulESP_Cnt_u08 (0U)
# define Rte_InitValue_ReqLampeDefEsp_Cnt_u08 (0U)
# define Rte_InitValue_ReqModeDA_Cnt_u08 (0U)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
# define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
# define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
# define Rte_InitValue_VVHType_Cnt_u08 (0U)
# define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Cd_SrlComDriver_VVHType_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_AccelLat_Cnt_s16(SInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_AnneeEcoule_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ColumnAngleSetpoint_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_CompteurTemporelVehicule_Cnt_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ComputerRazGCT_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ConfigVhl_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_DiagIntegraElec_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_DiagMuxOn_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_DmdDelestDA_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ESPDeconnecte_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_EffacDefaultDiag_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_EtatMT_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_EtatPrincipSev_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_EtatReseauElec_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_JourEcoule_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_Kilometrage_Cnt_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_LKAState_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_LKATrqFactReq_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_LXAActivation_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ModeDiag_Cnt_u08(UInt8 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PowerSupplies_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_RegulABR_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_RegulESP_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ReqLampeDefEsp_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ReqModeDA_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_SecondeEcoulee_Cnt_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ShuntPosition_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_VitesseVehicleBV_Cnt_u16(UInt16 data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Cd_SrlComDriver_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_AvgFricLrnData_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_IS_DAT_DIRA_Get(P2VAR(IS_DAT_DIRA_Msg, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) IsDatDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) IsDynDae);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_IS_DYN_VOL_Get(P2VAR(IS_DYN_VOL_MsgBase, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) IsDynVolBase, P2VAR(IS_DYN_VOL_MsgAdd, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) IsDynVolAdd);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) IsSupvDira);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_LearnedEOT_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_MotPosReset_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_PsaAgArbnLrndOffsBlk_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) CurrentTime);

FUNC(void, RTE_CODE) Rte_Enter_Cd_SrlComDriver_BusOff(void);
FUNC(void, RTE_CODE) Rte_Exit_Cd_SrlComDriver_BusOff(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComDriver_Init1_CAVHCSelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_CAVHCSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Init1_CityParkSelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_CityParkSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Init1_LXASelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Init1_MultimodeSelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_MultimodeSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Init1_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Init1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TMFTestComplete_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_BusOff_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_BusOff_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TxEnabled_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TxEnabled_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_VVHType_Cnt_u08 Rte_Read_Cd_SrlComDriver_VVHType_Cnt_u08


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AccelLat_Cnt_s16 Rte_Write_Cd_SrlComDriver_AccelLat_Cnt_s16
# define Rte_Write_AnneeEcoule_Cnt_u08 Rte_Write_Cd_SrlComDriver_AnneeEcoule_Cnt_u08
# define Rte_Write_ColumnAngleSetpoint_Cnt_u16 Rte_Write_Cd_SrlComDriver_ColumnAngleSetpoint_Cnt_u16
# define Rte_Write_CompteurTemporelVehicule_Cnt_u32 Rte_Write_Cd_SrlComDriver_CompteurTemporelVehicule_Cnt_u32
# define Rte_Write_ComputerRazGCT_Cnt_u08 Rte_Write_Cd_SrlComDriver_ComputerRazGCT_Cnt_u08
# define Rte_Write_ConfigVhl_Cnt_u08 Rte_Write_Cd_SrlComDriver_ConfigVhl_Cnt_u08
# define Rte_Write_DiagIntegraElec_Cnt_u08 Rte_Write_Cd_SrlComDriver_DiagIntegraElec_Cnt_u08
# define Rte_Write_DiagMuxOn_Cnt_u08 Rte_Write_Cd_SrlComDriver_DiagMuxOn_Cnt_u08
# define Rte_Write_DmdDelestDA_Cnt_u08 Rte_Write_Cd_SrlComDriver_DmdDelestDA_Cnt_u08
# define Rte_Write_ESPDeconnecte_Cnt_u08 Rte_Write_Cd_SrlComDriver_ESPDeconnecte_Cnt_u08
# define Rte_Write_EffacDefaultDiag_Cnt_u08 Rte_Write_Cd_SrlComDriver_EffacDefaultDiag_Cnt_u08
# define Rte_Write_EtatMT_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatMT_Cnt_u08
# define Rte_Write_EtatPrincipSev_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatPrincipSev_Cnt_u08
# define Rte_Write_EtatReseauElec_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatReseauElec_Cnt_u08
# define Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08
# define Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32
# define Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08
# define Rte_Write_ISDATABR50DMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32
# define Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08
# define Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32
# define Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08
# define Rte_Write_ISDATBSI412MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32
# define Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08
# define Rte_Write_ISDATBSI432MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32
# define Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08
# define Rte_Write_ISDATBSI572MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32
# define Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc
# define Rte_Write_ISDATDIRAMsgTxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32
# define Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08
# define Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32
# define Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08
# define Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32
# define Rte_Write_ISDYNAASMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08
# define Rte_Write_ISDYNAASMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08
# define Rte_Write_ISDYNAASMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32
# define Rte_Write_ISDYNABRMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08
# define Rte_Write_ISDYNABRMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08
# define Rte_Write_ISDYNABRMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32
# define Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08
# define Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32
# define Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08
# define Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32
# define Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08
# define Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32
# define Rte_Write_ISDYNVOLMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08
# define Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08
# define Rte_Write_ISDYNVOLMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32
# define Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISINTEELECTRONBSIMsgRxTime_MSec_u32
# define Rte_Write_JourEcoule_Cnt_u16 Rte_Write_Cd_SrlComDriver_JourEcoule_Cnt_u16
# define Rte_Write_Kilometrage_Cnt_u32 Rte_Write_Cd_SrlComDriver_Kilometrage_Cnt_u32
# define Rte_Write_LKAState_Cnt_u08 Rte_Write_Cd_SrlComDriver_LKAState_Cnt_u08
# define Rte_Write_LKATrqFactReq_Cnt_u08 Rte_Write_Cd_SrlComDriver_LKATrqFactReq_Cnt_u08
# define Rte_Write_LXAActivation_Cnt_u08 Rte_Write_Cd_SrlComDriver_LXAActivation_Cnt_u08
# define Rte_Write_ModeDiag_Cnt_u08 Rte_Write_Cd_SrlComDriver_ModeDiag_Cnt_u08
# define Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08
# define Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08
# define Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32
# define Rte_Write_PowerSupplies_Cnt_u08 Rte_Write_Cd_SrlComDriver_PowerSupplies_Cnt_u08
# define Rte_Write_RegulABR_Cnt_u08 Rte_Write_Cd_SrlComDriver_RegulABR_Cnt_u08
# define Rte_Write_RegulESP_Cnt_u08 Rte_Write_Cd_SrlComDriver_RegulESP_Cnt_u08
# define Rte_Write_ReqLampeDefEsp_Cnt_u08 Rte_Write_Cd_SrlComDriver_ReqLampeDefEsp_Cnt_u08
# define Rte_Write_ReqModeDA_Cnt_u08 Rte_Write_Cd_SrlComDriver_ReqModeDA_Cnt_u08
# define Rte_Write_SecondeEcoulee_Cnt_u32 Rte_Write_Cd_SrlComDriver_SecondeEcoulee_Cnt_u32
# define Rte_Write_ShuntPosition_Cnt_u08 Rte_Write_Cd_SrlComDriver_ShuntPosition_Cnt_u08
# define Rte_Write_VitesseVehicleBV_Cnt_u16 Rte_Write_Cd_SrlComDriver_VitesseVehicleBV_Cnt_u16


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Cd_SrlComDriver_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_AvgFricLrnData_GetErrorStatus Rte_Call_Cd_SrlComDriver_AvgFricLrnData_GetErrorStatus
# define Rte_Call_DemIf_VehSpdControl Rte_Call_Cd_SrlComDriver_DemIf_VehSpdControl
# define Rte_Call_IS_DAT_DIRA_Get Rte_Call_Cd_SrlComDriver_IS_DAT_DIRA_Get
# define Rte_Call_IS_DYN_DAE_Get Rte_Call_Cd_SrlComDriver_IS_DYN_DAE_Get
# define Rte_Call_IS_DYN_VOL_Get Rte_Call_Cd_SrlComDriver_IS_DYN_VOL_Get
# define Rte_Call_IS_SUPV_DIRA_Get Rte_Call_Cd_SrlComDriver_IS_SUPV_DIRA_Get
# define Rte_Call_LearnedEOT_GetErrorStatus Rte_Call_Cd_SrlComDriver_LearnedEOT_GetErrorStatus
# define Rte_Call_MotPosReset_GetErrorStatus Rte_Call_Cd_SrlComDriver_MotPosReset_GetErrorStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Cd_SrlComDriver_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus Rte_Call_Cd_SrlComDriver_PsaAgArbnLrndOffsBlk_GetErrorStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Cd_SrlComDriver_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Cd_SrlComDriver_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_BusOff Rte_Enter_Cd_SrlComDriver_BusOff
# define Rte_Exit_BusOff Rte_Exit_Cd_SrlComDriver_BusOff




# define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Init1
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
 *   Boolean Rte_IRead_SrlComDriver_Init1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_MultimodeSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Init1_STTdSelected_Cnt_lgc(void)
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Per1
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
 *   Std_ReturnType Rte_Read_VVHType_Cnt_u08(UInt8 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AccelLat_Cnt_s16(SInt16 data)
 *   Std_ReturnType Rte_Write_AnneeEcoule_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ColumnAngleSetpoint_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_CompteurTemporelVehicule_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ComputerRazGCT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ConfigVhl_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DiagIntegraElec_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DiagMuxOn_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DmdDelestDA_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ESPDeconnecte_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EffacDefaultDiag_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatMT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EtatReseauElec_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATABR50DMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDATBSI572MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_ISDATDIRAMsgTxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 data)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNAASMsg_Cnt_u08(const UInt8 *data)
# else
 *   Std_ReturnType Rte_Write_ISDYNAASMsg_Cnt_u08(const CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Write_ISDYNAASMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNAASMsgRxTime_MSec_u32(UInt32 data)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNABRMsg_Cnt_u08(const UInt8 *data)
# else
 *   Std_ReturnType Rte_Write_ISDYNABRMsg_Cnt_u08(const CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Write_ISDYNABRMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNABRMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_ISDYNVOLMsg_Cnt_u08(const UInt8 *data)
# else
 *   Std_ReturnType Rte_Write_ISDYNVOLMsg_Cnt_u08(const CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_JourEcoule_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_Kilometrage_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_LKAState_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_LKATrqFactReq_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_LXAActivation_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ModeDiag_Cnt_u08(UInt8 data)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const UInt8 *data)
# else
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08(const CanMsgType *data)
# endif
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_PowerSupplies_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_RegulABR_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_RegulESP_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ReqLampeDefEsp_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_ReqModeDA_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_SecondeEcoulee_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_ShuntPosition_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VitesseVehicleBV_Cnt_u16(UInt16 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DAT_DIRA_Get(IS_DAT_DIRA_Msg *IsDatDira)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DYN_DAE_Get(IS_DYN_DAE_Msg *IsDynDae)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_DYN_VOL_Get(IS_DYN_VOL_MsgBase *IsDynVolBase, IS_DYN_VOL_MsgAdd *IsDynVolAdd)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_AvgFricLrnData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LearnedEOT_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_MotPosReset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_BusOff(void)
 *   void Rte_Exit_BusOff(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStart> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStart(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStop> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStop(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_GetBusOffCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetBusOffCounter> of PortPrototype <SrlComDriver_SCom>
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
 *   void Rte_Enter_BusOff(void)
 *   void Rte_Exit_BusOff(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_SendMsgOnChange
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendMsgOnChange> of PortPrototype <SrlComDriver_SCom>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IS_SUPV_DIRA_Get(IS_SUPV_DIRA_Msg *IsSupvDira)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComDriver_SCom_SendMsgOnChange(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_SendMsgOnChange(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns1
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns2(void);

# define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1525107626
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/SrlComDriver/utp/contract/Cd_SrlComDriver/Rte_Cd_SrlComDriver.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1525107626
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_SRLCOMDRIVER_H */
