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
 *          File:  Components/Rte_Cd_SrlComDriver.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_SRLCOMDRIVER_H
# define _RTE_CD_SRLCOMDRIVER_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_JourEcoule_Cnt_u16;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_Kilometrage_Cnt_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LKAState_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LKATrqFactReq_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_LXAActivation_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ModeDiag_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_PowerSupplies_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_RegulABR_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_RegulESP_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ReqLampeDefEsp_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ReqModeDA_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_SecondeEcoulee_Cnt_u32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_ShuntPosition_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_VitesseVehicleBV_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VVHType_Cnt_u08;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AccelLat_Cnt_s16 (0)
#  define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
#  define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
#  define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
#  define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
#  define Rte_InitValue_ConfigVhl_Cnt_u08 (0U)
#  define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
#  define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
#  define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
#  define Rte_InitValue_ESCOffsCfgSeld_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESPDeconnecte_Cnt_u08 (1U)
#  define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
#  define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
#  define Rte_InitValue_EtatMT_Cnt_u08 (0U)
#  define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
#  define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
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
#  define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
#  define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
#  define Rte_InitValue_LKAState_Cnt_u08 (0U)
#  define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
#  define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
#  define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
#  define Rte_InitValue_MultimodeSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
#  define Rte_InitValue_RegulABR_Cnt_u08 (0U)
#  define Rte_InitValue_RegulESP_Cnt_u08 (0U)
#  define Rte_InitValue_ReqLampeDefEsp_Cnt_u08 (0U)
#  define Rte_InitValue_ReqModeDA_Cnt_u08 (0U)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
#  define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
#  define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
#  define Rte_InitValue_VVHType_Cnt_u08 (0U)
#  define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd6_SystemState6_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2CONST(UInt8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08(P2CONST(CanMsgType, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) data);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 data);


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

#  define Rte_IRead_SrlComDriver_Init1_CAVHCSelected_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CAVHCSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Init1_CityParkSelected_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_CityParkSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Init1_ESCOffsCfgSeld_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Init1.Rte_ESCOffsCfgSeld_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Init1_LXASelected_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_LXASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Init1_MultimodeSelected_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_MultiModeSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Init1_STTdSelected_Cnt_lgc() \
  (Rte_Task_Init_6.Rte_TB.Rte_I_CDDInterface6_STTdSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TMFTestComplete_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_BusOff_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_BusOff_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TxEnabled_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TxEnabled_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_VVHType_Cnt_u08 Rte_Read_Cd_SrlComDriver_VVHType_Cnt_u08
#  define Rte_Read_Cd_SrlComDriver_VVHType_Cnt_u08(data) (*(data) = Rte_SrlComInput_VVHType_Cnt_u08, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AccelLat_Cnt_s16 Rte_Write_Cd_SrlComDriver_AccelLat_Cnt_s16
#  define Rte_Write_Cd_SrlComDriver_AccelLat_Cnt_s16(data) (Rte_SrlComDriver_AccelLat_Cnt_s16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_AnneeEcoule_Cnt_u08 Rte_Write_Cd_SrlComDriver_AnneeEcoule_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_AnneeEcoule_Cnt_u08(data) (Rte_SrlComDriver_AnneeEcoule_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ColumnAngleSetpoint_Cnt_u16 Rte_Write_Cd_SrlComDriver_ColumnAngleSetpoint_Cnt_u16
#  define Rte_Write_Cd_SrlComDriver_ColumnAngleSetpoint_Cnt_u16(data) (Rte_SrlComDriver_ColumnAngleSetpoint_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CompteurTemporelVehicule_Cnt_u32 Rte_Write_Cd_SrlComDriver_CompteurTemporelVehicule_Cnt_u32
#  define Rte_Write_Cd_SrlComDriver_CompteurTemporelVehicule_Cnt_u32(data) (Rte_SrlComDriver_CompteurTemporelVehicule_Cnt_u32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ComputerRazGCT_Cnt_u08 Rte_Write_Cd_SrlComDriver_ComputerRazGCT_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ComputerRazGCT_Cnt_u08(data) (Rte_SrlComDriver_ComputerRazGCT_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ConfigVhl_Cnt_u08 Rte_Write_Cd_SrlComDriver_ConfigVhl_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ConfigVhl_Cnt_u08(data) (Rte_SrlComDriver_ConfigVhl_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DiagIntegraElec_Cnt_u08 Rte_Write_Cd_SrlComDriver_DiagIntegraElec_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_DiagIntegraElec_Cnt_u08(data) (Rte_SrlComDriver_DiagIntegraElec_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DiagMuxOn_Cnt_u08 Rte_Write_Cd_SrlComDriver_DiagMuxOn_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_DiagMuxOn_Cnt_u08(data) (Rte_SrlComDriver_DiagMuxOn_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DmdDelestDA_Cnt_u08 Rte_Write_Cd_SrlComDriver_DmdDelestDA_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_DmdDelestDA_Cnt_u08(data) (Rte_SrlComDriver_DmdDelestDA_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ESPDeconnecte_Cnt_u08 Rte_Write_Cd_SrlComDriver_ESPDeconnecte_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ESPDeconnecte_Cnt_u08(data) (Rte_SrlComDriver_ESPDeconnecte_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EffacDefaultDiag_Cnt_u08 Rte_Write_Cd_SrlComDriver_EffacDefaultDiag_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_EffacDefaultDiag_Cnt_u08(data) (Rte_SrlComDriver_EffacDefaultDiag_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EtatMT_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatMT_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_EtatMT_Cnt_u08(data) (Rte_SrlComDriver_EtatMT_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EtatPrincipSev_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatPrincipSev_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_EtatPrincipSev_Cnt_u08(data) (Rte_SrlComDriver_EtatPrincipSev_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EtatReseauElec_Cnt_u08 Rte_Write_Cd_SrlComDriver_EtatReseauElec_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_EtatReseauElec_Cnt_u08(data) (Rte_SrlComDriver_EtatReseauElec_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDAT4V2BSI552MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDAT4V2BSI552MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32
#  define Rte_Write_ISDATABR50DMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDATABR50DMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATABR50DMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATABR50DMsgRxTime_MSec_u32
#  define Rte_Write_ISDATBSI3F2MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDATBSI3F2MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATBSI3F2MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI3F2MsgRxTime_MSec_u32
#  define Rte_Write_ISDATBSI412MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDATBSI412MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATBSI412MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI412MsgRxTime_MSec_u32
#  define Rte_Write_ISDATBSI432MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDATBSI432MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATBSI432MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI432MsgRxTime_MSec_u32
#  define Rte_Write_ISDATBSI572MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDATBSI572MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATBSI572MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATBSI572MsgRxTime_MSec_u32
#  define Rte_Write_ISDATDIRAMsgTxInProgress_Cnt_lgc Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc
#  define Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc(data) (Rte_SrlComDriver_ISDATDIRAMsgTxInProgress_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDATDIRAMsgTxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32
#  define Rte_Write_Cd_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32(data) (Rte_SrlComDriver_ISDATDIRAMsgTxTime_MSec_u32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYN2CMMMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYN2CMMMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYN2CMMMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYN2CMMMsgRxTime_MSec_u32
#  define Rte_Write_ISDYN2FRE3CDMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYN2FRE3CDMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYN2FRE3CDMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYN2FRE3CDMsgRxTime_MSec_u32
#  define Rte_Write_ISDYNAASMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNAASMsg_Cnt_u08
#  define Rte_Write_ISDYNAASMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNAASMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNAASMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNAASMsgRxTime_MSec_u32
#  define Rte_Write_ISDYNABRMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNABRMsg_Cnt_u08
#  define Rte_Write_ISDYNABRMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNABRMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNABRMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNABRMsgRxTime_MSec_u32
#  define Rte_Write_ISDYNCDS34DMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNCDS34DMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNCDS34DMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCDS34DMsgRxTime_MSec_u32
#  define Rte_Write_ISDYNCMM208MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNCMM208MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNCMM208MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCMM208MsgRxTime_MSec_u32
#  define Rte_Write_ISDYNCMM388MsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNCMM388MsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNCMM388MsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNCMM388MsgRxTime_MSec_u32
#  define Rte_Write_ISDYNVOLMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsg_Cnt_u08
#  define Rte_Write_ISDYNVOLMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_ISDYNVOLMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ISDYNVOLMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISDYNVOLMsgRxTime_MSec_u32
#  define Rte_Write_ISINTEELECTRONBSIMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_ISINTEELECTRONBSIMsgRxTime_MSec_u32
#  define Rte_Write_JourEcoule_Cnt_u16 Rte_Write_Cd_SrlComDriver_JourEcoule_Cnt_u16
#  define Rte_Write_Cd_SrlComDriver_JourEcoule_Cnt_u16(data) (Rte_SrlComDriver_JourEcoule_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Kilometrage_Cnt_u32 Rte_Write_Cd_SrlComDriver_Kilometrage_Cnt_u32
#  define Rte_Write_Cd_SrlComDriver_Kilometrage_Cnt_u32(data) (Rte_SrlComDriver_Kilometrage_Cnt_u32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKAState_Cnt_u08 Rte_Write_Cd_SrlComDriver_LKAState_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_LKAState_Cnt_u08(data) (Rte_SrlComDriver_LKAState_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKATrqFactReq_Cnt_u08 Rte_Write_Cd_SrlComDriver_LKATrqFactReq_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_LKATrqFactReq_Cnt_u08(data) (Rte_SrlComDriver_LKATrqFactReq_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LXAActivation_Cnt_u08 Rte_Write_Cd_SrlComDriver_LXAActivation_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_LXAActivation_Cnt_u08(data) (Rte_SrlComDriver_LXAActivation_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ModeDiag_Cnt_u08 Rte_Write_Cd_SrlComDriver_ModeDiag_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ModeDiag_Cnt_u08(data) (Rte_SrlComDriver_ModeDiag_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PROTOHS1DYNUCF5CDMsg_Cnt_u08 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsg_Cnt_u08
#  define Rte_Write_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(data) (Rte_SrlComDriver_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32 Rte_Write_Cd_SrlComDriver_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32
#  define Rte_Write_PowerSupplies_Cnt_u08 Rte_Write_Cd_SrlComDriver_PowerSupplies_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_PowerSupplies_Cnt_u08(data) (Rte_SrlComDriver_PowerSupplies_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_RegulABR_Cnt_u08 Rte_Write_Cd_SrlComDriver_RegulABR_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_RegulABR_Cnt_u08(data) (Rte_SrlComDriver_RegulABR_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_RegulESP_Cnt_u08 Rte_Write_Cd_SrlComDriver_RegulESP_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_RegulESP_Cnt_u08(data) (Rte_SrlComDriver_RegulESP_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ReqLampeDefEsp_Cnt_u08 Rte_Write_Cd_SrlComDriver_ReqLampeDefEsp_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ReqLampeDefEsp_Cnt_u08(data) (Rte_SrlComDriver_ReqLampeDefEsp_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ReqModeDA_Cnt_u08 Rte_Write_Cd_SrlComDriver_ReqModeDA_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ReqModeDA_Cnt_u08(data) (Rte_SrlComDriver_ReqModeDA_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SecondeEcoulee_Cnt_u32 Rte_Write_Cd_SrlComDriver_SecondeEcoulee_Cnt_u32
#  define Rte_Write_Cd_SrlComDriver_SecondeEcoulee_Cnt_u32(data) (Rte_SrlComDriver_SecondeEcoulee_Cnt_u32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ShuntPosition_Cnt_u08 Rte_Write_Cd_SrlComDriver_ShuntPosition_Cnt_u08
#  define Rte_Write_Cd_SrlComDriver_ShuntPosition_Cnt_u08(data) (Rte_SrlComDriver_ShuntPosition_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VitesseVehicleBV_Cnt_u16 Rte_Write_Cd_SrlComDriver_VitesseVehicleBV_Cnt_u16
#  define Rte_Write_Cd_SrlComDriver_VitesseVehicleBV_Cnt_u16(data) (Rte_SrlComDriver_VitesseVehicleBV_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd6_SystemState6_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AvgFricLrnData_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)13, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DEMIF_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc);
#  define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DemIf_VehSpdControl(arg1) (DemIf_VehSpdControl(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DAT_DIRA_Get(P2VAR(IS_DAT_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDatDira);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_DAT_DIRA_Get(arg1) (SrlComOutput_IS_DAT_DIRA_Get(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_DAE_Get(P2VAR(IS_DYN_DAE_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynDae);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_DYN_DAE_Get(arg1) (SrlComOutput_IS_DYN_DAE_Get(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_DYN_VOL_Get(P2VAR(IS_DYN_VOL_MsgBase, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolBase, P2VAR(IS_DYN_VOL_MsgAdd, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsDynVolAdd);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_DYN_VOL_Get(arg1, arg2) (SrlComOutput_IS_DYN_VOL_Get(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_IS_SUPV_DIRA_Get(P2VAR(IS_SUPV_DIRA_Msg, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IsSupvDira);
#  define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IS_SUPV_DIRA_Get(arg1) (SrlComOutput_IS_SUPV_DIRA_Get(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_LearnedEOT_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)12, arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_MotPosReset_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)16, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR6_APPL_CODE) NxtrDiagMgr6_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr6_SetNTCStatus
#  define Rte_Call_PsaAgArbnLrndOffsBlk_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)22, arg1), ((Std_ReturnType)RTE_E_OK))
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


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_BusOff() \
  { \
    Rte_EnterHook_Cd_SrlComDriver_BusOff_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Cd_SrlComDriver_BusOff_Return(); \
  }

#  define Rte_Exit_BusOff() \
  { \
    Rte_ExitHook_Cd_SrlComDriver_BusOff_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Cd_SrlComDriver_BusOff_Return(); \
  }


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Init1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_SendMsgOnChange(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns2(void);

# define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_CD_SRLCOMDRIVER_H */
