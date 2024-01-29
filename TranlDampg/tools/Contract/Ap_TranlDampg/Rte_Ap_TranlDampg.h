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
 *          File:  Rte_Ap_TranlDampg.h
 *     Workspace:  C:/Synergy_KK/working/TranlDampg-nz4qtt/TranlDampg/autosar
 *     SW-C Type:  Ap_TranlDampg
 *  Generated at:  Tue Mar 31 11:37:46 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TranlDampg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TRANLDAMPG_H
# define _RTE_AP_TRANLDAMPG_H

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

typedef P2CONST(struct Rte_CDS_Ap_TranlDampg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistAssyPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_CRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_CntrlDampComp_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsF2Active_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LoaSt_State_enum ((LOA_State_enum)0u)
# define Rte_InitValue_MRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SumLimTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SysC_CRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SysC_MRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_TranlDampg_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TranlDampg_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_TRANLDAMPG_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_TranlDampg_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_TRANLDAMPG_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_Ap_TranlDampg_Per1_AssistAssyPolarity_Cnt_s08() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_AssistAssyPolarity_Cnt_s08->value)

# define Rte_IRead_Ap_TranlDampg_Per1_CRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_CRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_Ap_TranlDampg_Per1_DiagStsF2Active_Cnt_lgc() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_DiagStsF2Active_Cnt_lgc->value)

# define Rte_IRead_Ap_TranlDampg_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_Ap_TranlDampg_Per1_LoaSt_State_enum() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_LoaSt_State_enum->value)

# define Rte_IRead_Ap_TranlDampg_Per1_SumLimTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_SumLimTrqCmd_MtrNm_f32->value)

# define Rte_IRead_Ap_TranlDampg_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_VehSpd_Kph_f32->value)

# define Rte_IWrite_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc() \
  (&Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc->value)

# define Rte_IWrite_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_TranlDampg->Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_TranlDampg_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_TranlDampg_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_TranlDampg_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_TRANLDAMPG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_TranlDampg_Init
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

FUNC(void, RTE_AP_TRANLDAMPG_APPL_CODE) Ap_TranlDampg_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_TranlDampg_Per1
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
 *   SInt8 Rte_IRead_Ap_TranlDampg_Per1_AssistAssyPolarity_Cnt_s08(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_Ap_TranlDampg_Per1_DiagStsF2Active_Cnt_lgc(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_HandwheelPosition_HwDeg_f32(void)
 *   LOA_State_enum Rte_IRead_Ap_TranlDampg_Per1_LoaSt_State_enum(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_SumLimTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_Ap_TranlDampg_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_Ap_TranlDampg_Per1_CntrlDampComp_Cnt_lgc(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_MRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Ap_TranlDampg_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRANLDAMPG_APPL_CODE) Ap_TranlDampg_Per1(void);

# define RTE_STOP_SEC_AP_TRANLDAMPG_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1427812129
#    error "The magic number of the generated file <C:/Synergy_KK/working/TranlDampg-nz4qtt/TranlDampg/tools/contract/Ap_TranlDampg/Rte_Ap_TranlDampg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1427812129
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TRANLDAMPG_H */
