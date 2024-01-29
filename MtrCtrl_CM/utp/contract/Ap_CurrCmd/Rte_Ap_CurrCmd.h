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
 *          File:  Rte_Ap_CurrCmd.h
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/autosar
 *     SW-C Type:  Ap_CurrCmd
 *  Generated at:  Thu Jul 21 16:41:41 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_CurrCmd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CURRCMD_H
# define _RTE_AP_CURRCMD_H

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

typedef P2CONST(struct Rte_CDS_Ap_CurrCmd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CurrentGainSvc_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DualEcuMotCtrlMtgnEna_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstLd_Henry_f32 ((Float)0)
# define Rte_InitValue_EstLq_Henry_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_IvtrLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MRFTrqCmdScl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_MotCurrLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrCurrAngle_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQaxRef_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrQuad_Cnt_u08 ((UInt8)1u)
# define Rte_InitValue_MtrVoltDaxFFStatic_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltQaxFFStatic_Volt_f32 ((Float)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CurrCmd_Per1_CurrentGainSvc_Cnt_lgc() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_CurrentGainSvc_Cnt_lgc->value)

# define Rte_IRead_CurrCmd_Per1_DualEcuMotCtrlMtgnEna_Cnt_lgc() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_DualEcuMotCtrlMtgnEna_Cnt_lgc->value)

# define Rte_IRead_CurrCmd_Per1_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IRead_CurrCmd_Per1_EstLd_Henry_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_EstLd_Henry_f32->value)

# define Rte_IRead_CurrCmd_Per1_EstLq_Henry_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_EstLq_Henry_f32->value)

# define Rte_IRead_CurrCmd_Per1_EstR_Ohm_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_CurrCmd_Per1_IvtrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_IvtrLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IRead_CurrCmd_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_CurrCmd_Per1_MRFTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MRFTrqCmdScl_MtrNm_f32->value)

# define Rte_IRead_CurrCmd_Per1_MotCurrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MotCurrLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IRead_CurrCmd_Per1_MtrQuad_Cnt_u08() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrQuad_Cnt_u08->value)

# define Rte_IRead_CurrCmd_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_Vecu_Volt_f32->value)

# define Rte_IRead_CurrCmd_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_VehSpd_Kph_f32->value)

# define Rte_IWrite_CurrCmd_Per1_MtrCurrAngle_Rev_f32(data) \
  ( \
  Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrAngle_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrCmd_Per1_MtrCurrAngle_Rev_f32() \
  (&Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrAngle_Rev_f32->value)

# define Rte_IWrite_CurrCmd_Per1_MtrCurrDaxRef_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrDaxRef_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrCmd_Per1_MtrCurrDaxRef_Amp_f32() \
  (&Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrDaxRef_Amp_f32->value)

# define Rte_IWrite_CurrCmd_Per1_MtrCurrQaxRef_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrQaxRef_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrCmd_Per1_MtrCurrQaxRef_Amp_f32() \
  (&Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrCurrQaxRef_Amp_f32->value)

# define Rte_IWrite_CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32() \
  (&Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32->value)

# define Rte_IWrite_CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32() \
  (&Rte_Inst_Ap_CurrCmd->CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32->value)




# define RTE_START_SEC_AP_CURRCMD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrCmd_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRCMD_APPL_CODE) CurrCmd_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrCmd_Per1
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
 *   Boolean Rte_IRead_CurrCmd_Per1_CurrentGainSvc_Cnt_lgc(void)
 *   Boolean Rte_IRead_CurrCmd_Per1_DualEcuMotCtrlMtgnEna_Cnt_lgc(void)
 *   Float Rte_IRead_CurrCmd_Per1_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_CurrCmd_Per1_EstLd_Henry_f32(void)
 *   Float Rte_IRead_CurrCmd_Per1_EstLq_Henry_f32(void)
 *   Float Rte_IRead_CurrCmd_Per1_EstR_Ohm_f32(void)
 *   Boolean Rte_IRead_CurrCmd_Per1_IvtrLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_CurrCmd_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_CurrCmd_Per1_MRFTrqCmdScl_MtrNm_f32(void)
 *   Boolean Rte_IRead_CurrCmd_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(void)
 *   UInt8 Rte_IRead_CurrCmd_Per1_MtrQuad_Cnt_u08(void)
 *   Float Rte_IRead_CurrCmd_Per1_Vecu_Volt_f32(void)
 *   Float Rte_IRead_CurrCmd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrCmd_Per1_MtrCurrAngle_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CurrCmd_Per1_MtrCurrAngle_Rev_f32(void)
 *   void Rte_IWrite_CurrCmd_Per1_MtrCurrDaxRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CurrCmd_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   void Rte_IWrite_CurrCmd_Per1_MtrCurrQaxRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CurrCmd_Per1_MtrCurrQaxRef_Amp_f32(void)
 *   void Rte_IWrite_CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CurrCmd_Per1_MtrVoltDaxFFStatic_Volt_f32(void)
 *   void Rte_IWrite_CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CurrCmd_Per1_MtrVoltQaxFFStatic_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRCMD_APPL_CODE) CurrCmd_Per1(void);

# define RTE_STOP_SEC_AP_CURRCMD_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1469131060
#    error "The magic number of the generated file <C:/Rijvi_Synergy_EA3/Core_Component/Working/MtrCtrl_CM/utp/contract/Ap_CurrCmd/Rte_Ap_CurrCmd.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1469131060
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CURRCMD_H */
