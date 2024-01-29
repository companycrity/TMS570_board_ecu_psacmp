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
 *          File:  Rte_Ap_TrqLOA.h
 *     Workspace:  C:/SynergyEA3/Working/TrqLOA/autosar
 *     SW-C Type:  Ap_TrqLOA
 *  Generated at:  Tue Nov 24 17:00:54 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TrqLOA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TRQLOA_H
# define _RTE_AP_TRQLOA_H

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

typedef P2CONST(struct Rte_CDS_Ap_TrqLOA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_MotAgLoaMtgtnEn_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_TrqLOAAvail_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TrqLOACmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_TrqLoaDi_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehWhlBas_mm_f32 ((Float)3000)
# define Rte_InitValue_VehWhlBasVld_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleLatAccel_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_VehicleLatAccelValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_TrqLOA_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_TrqLOA_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc->value)

# define Rte_IRead_TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_TrqLOA_Per1_TrqLoaDi_Cnt_lgc() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_TrqLoaDi_Cnt_lgc->value)

# define Rte_IRead_TrqLOA_Per1_VehWhlBasVld_Cnt_lgc() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehWhlBasVld_Cnt_lgc->value)

# define Rte_IRead_TrqLOA_Per1_VehWhlBas_mm_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehWhlBas_mm_f32->value)

# define Rte_IRead_TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc->value)

# define Rte_IRead_TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32->value)

# define Rte_IRead_TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_TrqLOA_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_TrqLOAAvail_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc() \
  (&Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_TrqLOAAvail_Cnt_lgc->value)

# define Rte_IWrite_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_TrqLOACmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_TrqLOA_Per1_TrqLOACmd_MtrNm_f32() \
  (&Rte_Inst_Ap_TrqLOA->TrqLOA_Per1_TrqLOACmd_MtrNm_f32->value)




# define RTE_START_SEC_AP_TRQLOA_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqLOA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqLOA_Per1
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
 *   Float Rte_IRead_TrqLOA_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_TrqLOA_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_TrqLoaDi_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehWhlBasVld_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehWhlBas_mm_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(void)
 *   void Rte_IWrite_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Per1(void);

# define RTE_STOP_SEC_AP_TRQLOA_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1448406738
#    error "The magic number of the generated file <C:/SynergyEA3/Working/TrqLOA/tools/contract/Ap_TrqLOA/Rte_Ap_TrqLOA.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1448406738
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TRQLOA_H */
