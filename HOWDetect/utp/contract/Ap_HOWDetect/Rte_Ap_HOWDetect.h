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
 *          File:  Rte_Ap_HOWDetect.h
 *     Workspace:  C:/Rijvi_Synergy/Prep/HOWDetect-1/HOWDetect/autosar
 *     SW-C Type:  Ap_HOWDetect
 *  Generated at:  Mon Apr 14 11:47:26 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_HOWDetect> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_HOWDETECT_H
# define _RTE_AP_HOWDETECT_H

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

typedef P2CONST(struct Rte_CDS_Ap_HOWDetect, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HOWEstimate_Uls_f32 ((Float)0)
# define Rte_InitValue_HOWState_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HOWDetect_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_HOWDetect_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_VehSpd_Kph_f32->value)

# define Rte_IWrite_HOWDetect_Per1_HOWEstimate_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_HOWEstimate_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_HOWDetect_Per1_HOWEstimate_Uls_f32() \
  (&Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_HOWEstimate_Uls_f32->value)

# define Rte_IWrite_HOWDetect_Per1_HOWState_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_HOWState_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_HOWDetect_Per1_HOWState_Cnt_s08() \
  (&Rte_Inst_Ap_HOWDetect->HOWDetect_Per1_HOWState_Cnt_s08->value)




# define RTE_START_SEC_AP_HOWDETECT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HOWDetect_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HOWDETECT_APPL_CODE) HOWDetect_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HOWDetect_Per1
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
 *   Float Rte_IRead_HOWDetect_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_HOWDetect_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HOWDetect_Per1_HOWEstimate_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_HOWDetect_Per1_HOWEstimate_Uls_f32(void)
 *   void Rte_IWrite_HOWDetect_Per1_HOWState_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_HOWDetect_Per1_HOWState_Cnt_s08(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HOWDETECT_APPL_CODE) HOWDetect_Per1(void);

# define RTE_STOP_SEC_AP_HOWDETECT_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1397496061
#    error "The magic number of the generated file <C:/Rijvi_Synergy/Prep/HOWDetect-1/HOWDetect/utp/contract/Ap_HOWDetect/Rte_Ap_HOWDetect.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1397496061
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HOWDETECT_H */
