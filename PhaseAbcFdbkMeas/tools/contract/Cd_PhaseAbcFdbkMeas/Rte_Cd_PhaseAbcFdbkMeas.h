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
 *          File:  Rte_Cd_PhaseAbcFdbkMeas.h
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/PhaseAbcFdbkMeas/autosar
 *     SW-C Type:  Cd_PhaseAbcFdbkMeas
 *  Generated at:  Tue May 17 14:46:54 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Cd_PhaseAbcFdbkMeas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_PHASEABCFDBKMEAS_H
# define _RTE_CD_PHASEABCFDBKMEAS_H

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

typedef P2CONST(struct Rte_CDS_Cd_PhaseAbcFdbkMeas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 ((UInt32)0u)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32->value)

# define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32->value)

# define Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Inst_Cd_PhaseAbcFdbkMeas->Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32->value)




# define RTE_START_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cd_PhaseAbcFdbkMeas_Init2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Init2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cd_PhaseAbcFdbkMeas_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_Cd_PhaseAbcFdbkMeas_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Cd_PhaseAbcFdbkMeas_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Get_PhaseAbcFdbkMeas_PhaseFdbk
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PhaseFdbk> of PortPrototype <Get_PhaseFdbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Get_PhaseAbcFdbkMeas_PhaseFdbk(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_PHASEABCFDBKMEAS_APPL_CODE) Get_PhaseAbcFdbkMeas_PhaseFdbk(void);

# define RTE_STOP_SEC_CD_PHASEABCFDBKMEAS_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1463515413
#    error "The magic number of the generated file <C:/Users/rzk04c/Documents/Synergy/EA3/PhaseAbcFdbkMeas/tools/contract/Cd_PhaseAbcFdbkMeas/Rte_Cd_PhaseAbcFdbkMeas.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1463515413
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_PHASEABCFDBKMEAS_H */
