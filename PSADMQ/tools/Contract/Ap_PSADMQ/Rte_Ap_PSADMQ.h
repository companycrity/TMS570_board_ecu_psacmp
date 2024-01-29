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
 *          File:  Rte_Ap_PSADMQ.h
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSADMQ/PSADMQ/autosar
 *     SW-C Type:  Ap_PSADMQ
 *  Generated at:  Wed Sep  6 13:48:14 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PSADMQ> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSADMQ_H
# define _RTE_AP_PSADMQ_H

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

typedef P2CONST(struct Rte_CDS_Ap_PSADMQ, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DesiredTunPers_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_MultiModSwt_Cnt_enum ((PsaTunModSt_Cnt_enum)0u)
# define Rte_InitValue_MultiModeSelected_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PersSelnInpVld_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TunModSt_Cnt_enum ((PsaTunModSt_Cnt_enum)0u)
# define Rte_InitValue_TunReqGranted_Cnt_lgc ((Boolean)FALSE)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PSADMQ_Per1_MultiModSwt_Cnt_enum() \
  (Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_MultiModSwt_Cnt_enum->value)

# define Rte_IRead_PSADMQ_Per1_MultiModeSelected_Cnt_lgc() \
  (Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_MultiModeSelected_Cnt_lgc->value)

# define Rte_IRead_PSADMQ_Per1_PersSelnInpVld_Cnt_lgc() \
  (Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_PersSelnInpVld_Cnt_lgc->value)

# define Rte_IRead_PSADMQ_Per1_TunReqGranted_Cnt_lgc() \
  (Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_TunReqGranted_Cnt_lgc->value)

# define Rte_IWrite_PSADMQ_Per1_DesiredTunPers_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_DesiredTunPers_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_PSADMQ_Per1_DesiredTunPers_Cnt_u16() \
  (&Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_DesiredTunPers_Cnt_u16->value)

# define Rte_IWrite_PSADMQ_Per1_TunModSt_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_TunModSt_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_PSADMQ_Per1_TunModSt_Cnt_enum() \
  (&Rte_Inst_Ap_PSADMQ->PSADMQ_Per1_TunModSt_Cnt_enum->value)




# define RTE_START_SEC_AP_PSADMQ_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSADMQ_Per1
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
 *   PsaTunModSt_Cnt_enum Rte_IRead_PSADMQ_Per1_MultiModSwt_Cnt_enum(void)
 *   Boolean Rte_IRead_PSADMQ_Per1_MultiModeSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSADMQ_Per1_PersSelnInpVld_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSADMQ_Per1_TunReqGranted_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSADMQ_Per1_DesiredTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_PSADMQ_Per1_DesiredTunPers_Cnt_u16(void)
 *   void Rte_IWrite_PSADMQ_Per1_TunModSt_Cnt_enum(PsaTunModSt_Cnt_enum data)
 *   PsaTunModSt_Cnt_enum *Rte_IWriteRef_PSADMQ_Per1_TunModSt_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSADMQ_APPL_CODE) PSADMQ_Per1(void);

# define RTE_STOP_SEC_AP_PSADMQ_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1504706710
#    error "The magic number of the generated file <C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSADMQ/PSADMQ/tools/contract/Ap_PSADMQ/Rte_Ap_PSADMQ.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1504706710
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PSADMQ_H */
