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
 *          File:  Rte_Ap_PSATA.h
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSATA-nz2999/PSATA/autosar
 *     SW-C Type:  Ap_PSATA
 *  Generated at:  Wed Feb  7 11:47:19 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PSATA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSATA_H
# define _RTE_AP_PSATA_H

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

typedef P2CONST(struct Rte_CDS_Ap_PSATA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ApaOpTrqOv_MtrNm_f32 ((Float)0)
# define Rte_InitValue_ApaPosSrvoFlt_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ApaState_Cnt_enum ((PsaApaSt_Cnt_enum)0u)
# define Rte_InitValue_EPSStateForLxa_Cnt_enum ((PsaEpsStLxa_Cnt_enum)0u)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTrqRate_HwNmpS_f32 ((Float)0)
# define Rte_InitValue_LxaCorrnFacReqLimd_Uls_f32 ((Float)0)
# define Rte_InitValue_LxaDrvrAbsntHwVelDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaHwAgDetd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LxaOpTrqOv_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LxaTqLimnActv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_OpTrqOv_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PosSrvoCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PosSrvoEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PSATA_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PSATA_Per1_ApaState_Cnt_enum() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_ApaState_Cnt_enum->value)

# define Rte_IRead_PSATA_Per1_EPSStateForLxa_Cnt_enum() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_EPSStateForLxa_Cnt_enum->value)

# define Rte_IRead_PSATA_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_PSATA_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_PSATA_Per1_HwTrqRate_HwNmpS_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_HwTrqRate_HwNmpS_f32->value)

# define Rte_IRead_PSATA_Per1_LxaCorrnFacReqLimd_Uls_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_LxaCorrnFacReqLimd_Uls_f32->value)

# define Rte_IRead_PSATA_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc->value)

# define Rte_IRead_PSATA_Per1_LxaHwAgDetd_Cnt_lgc() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_LxaHwAgDetd_Cnt_lgc->value)

# define Rte_IRead_PSATA_Per1_PosSrvoCmd_MtrNm_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_PosSrvoCmd_MtrNm_f32->value)

# define Rte_IRead_PSATA_Per1_PosSrvoEnable_Cnt_lgc() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_PosSrvoEnable_Cnt_lgc->value)

# define Rte_IRead_PSATA_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_PSATA->PSATA_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_PSATA_Per1_ApaOpTrqOv_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_PSATA->PSATA_Per1_ApaOpTrqOv_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_PSATA_Per1_ApaOpTrqOv_MtrNm_f32() \
  (&Rte_Inst_Ap_PSATA->PSATA_Per1_ApaOpTrqOv_MtrNm_f32->value)

# define Rte_IWrite_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSATA->PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc() \
  (&Rte_Inst_Ap_PSATA->PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc->value)

# define Rte_IWrite_PSATA_Per1_LxaOpTrqOv_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_PSATA->PSATA_Per1_LxaOpTrqOv_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_PSATA_Per1_LxaOpTrqOv_MtrNm_f32() \
  (&Rte_Inst_Ap_PSATA->PSATA_Per1_LxaOpTrqOv_MtrNm_f32->value)

# define Rte_IWrite_PSATA_Per1_LxaTqLimnActv_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PSATA->PSATA_Per1_LxaTqLimnActv_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PSATA_Per1_LxaTqLimnActv_Cnt_lgc() \
  (&Rte_Inst_Ap_PSATA->PSATA_Per1_LxaTqLimnActv_Cnt_lgc->value)

# define Rte_IWrite_PSATA_Per1_OpTrqOv_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_PSATA->PSATA_Per1_OpTrqOv_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_PSATA_Per1_OpTrqOv_MtrNm_f32() \
  (&Rte_Inst_Ap_PSATA->PSATA_Per1_OpTrqOv_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PSATA_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_PSATA_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSATA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSATA_Per1
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
 *   PsaApaSt_Cnt_enum Rte_IRead_PSATA_Per1_ApaState_Cnt_enum(void)
 *   PsaEpsStLxa_Cnt_enum Rte_IRead_PSATA_Per1_EPSStateForLxa_Cnt_enum(void)
 *   Float Rte_IRead_PSATA_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_PSATA_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PSATA_Per1_HwTrqRate_HwNmpS_f32(void)
 *   Float Rte_IRead_PSATA_Per1_LxaCorrnFacReqLimd_Uls_f32(void)
 *   Boolean Rte_IRead_PSATA_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSATA_Per1_LxaHwAgDetd_Cnt_lgc(void)
 *   Float Rte_IRead_PSATA_Per1_PosSrvoCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_PSATA_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PSATA_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSATA_Per1_ApaOpTrqOv_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PSATA_Per1_ApaOpTrqOv_MtrNm_f32(void)
 *   void Rte_IWrite_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSATA_Per1_ApaPosSrvoFlt_Cnt_lgc(void)
 *   void Rte_IWrite_PSATA_Per1_LxaOpTrqOv_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PSATA_Per1_LxaOpTrqOv_MtrNm_f32(void)
 *   void Rte_IWrite_PSATA_Per1_LxaTqLimnActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSATA_Per1_LxaTqLimnActv_Cnt_lgc(void)
 *   void Rte_IWrite_PSATA_Per1_OpTrqOv_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PSATA_Per1_OpTrqOv_MtrNm_f32(void)
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

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Per1(void);

# define RTE_STOP_SEC_AP_PSATA_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1517995610
#    error "The magic number of the generated file <C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSATA-nz2999/PSATA/tools/contract/Ap_PSATA/Rte_Ap_PSATA.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1517995610
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PSATA_H */
