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
 *          File:  Rte_Ap_TqRsDg.h
 *     Workspace:  C:/SynergyEA3/Working/TqRsDg/autosar
 *     SW-C Type:  Ap_TqRsDg
 *  Generated at:  Fri Aug  5 15:32:00 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TqRsDg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TQRSDG_H
# define _RTE_AP_TQRSDG_H

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

typedef P2CONST(struct Rte_CDS_Ap_TqRsDg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CorrMtrPosElec_Rev_f32 ((Float)0)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrIdptSig_Cnt_u08 ((UInt8)2u)
# define Rte_InitValue_MtrCurrQaxFinalRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrVoltDax_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltQax_Volt_f32 ((Float)0)
# define Rte_InitValue_OutputRampMult_Uls_f32 ((Float)0)
# define Rte_InitValue_TrqLimitMin_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_TqRsDg_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_TqRsDg_Per1_CorrMtrPosElec_Rev_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_CorrMtrPosElec_Rev_f32->value)

# define Rte_IRead_TqRsDg_Per1_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IRead_TqRsDg_Per1_EstR_Ohm_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_TqRsDg_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_TqRsDg_Per1_MtrCurrDaxRef_Amp_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrCurrDaxRef_Amp_f32->value)

# define Rte_IRead_TqRsDg_Per1_MtrCurrQaxFinalRef_Amp_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrCurrQaxFinalRef_Amp_f32->value)

# define Rte_IRead_TqRsDg_Per1_MtrVoltDax_Volt_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrVoltDax_Volt_f32->value)

# define Rte_IRead_TqRsDg_Per1_MtrVoltQax_Volt_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrVoltQax_Volt_f32->value)

# define Rte_IRead_TqRsDg_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_TqRsDg_Per1_TrqLimitMin_MtrNm_f32() \
  (Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_TrqLimitMin_MtrNm_f32->value)

# define Rte_IWrite_TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08() \
  (&Rte_Inst_Ap_TqRsDg->TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_TqRsDg_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_TQRSDG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqRsDg_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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

FUNC(void, RTE_AP_TQRSDG_APPL_CODE) TqRsDg_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqRsDg_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OFF, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_TqRsDg_Per1_CorrMtrPosElec_Rev_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_MtrVoltDax_Volt_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_MtrVoltQax_Volt_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_TqRsDg_Per1_TrqLimitMin_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_TqRsDg_Per1_MtrCurrIdptSig_Cnt_u08(void)
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

FUNC(void, RTE_AP_TQRSDG_APPL_CODE) TqRsDg_Per1(void);

# define RTE_STOP_SEC_AP_TQRSDG_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1470426943
#    error "The magic number of the generated file <C:/SynergyEA3/Working/TqRsDg/tools/contract/Ap_TqRsDg/Rte_Ap_TqRsDg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1470426943
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TQRSDG_H */
