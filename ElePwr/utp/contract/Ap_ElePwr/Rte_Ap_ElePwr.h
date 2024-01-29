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
 *          File:  Rte_Ap_ElePwr.h
 *     Workspace:  C:/SynergyWorkspace/WorkingProjects/ElePwr-SF08B_1.1/ElePwr/autosar
 *     SW-C Type:  Ap_ElePwr
 *  Generated at:  Thu May  8 10:51:57 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ElePwr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ELEPWR_H
# define _RTE_AP_ELEPWR_H

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

typedef P2CONST(struct Rte_CDS_Ap_ElePwr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ElectricPower_Watt_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrVoltDax_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltQax_Volt_f32 ((Float)0)
# define Rte_InitValue_SupplyCurrent_Amp_f32 ((Float)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ElePwr_Per1_MtrCurrDax_Amp_f32() \
  (Rte_Inst_Ap_ElePwr->ElePwr_Per1_MtrCurrDax_Amp_f32->value)

# define Rte_IRead_ElePwr_Per1_MtrCurrQax_Amp_f32() \
  (Rte_Inst_Ap_ElePwr->ElePwr_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IRead_ElePwr_Per1_MtrVoltDax_Volt_f32() \
  (Rte_Inst_Ap_ElePwr->ElePwr_Per1_MtrVoltDax_Volt_f32->value)

# define Rte_IRead_ElePwr_Per1_MtrVoltQax_Volt_f32() \
  (Rte_Inst_Ap_ElePwr->ElePwr_Per1_MtrVoltQax_Volt_f32->value)

# define Rte_IRead_ElePwr_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_ElePwr->ElePwr_Per1_Vecu_Volt_f32->value)

# define Rte_IWrite_ElePwr_Per1_ElectricPower_Watt_f32(data) \
  ( \
  Rte_Inst_Ap_ElePwr->ElePwr_Per1_ElectricPower_Watt_f32->value = (data) \
  )

# define Rte_IWriteRef_ElePwr_Per1_ElectricPower_Watt_f32() \
  (&Rte_Inst_Ap_ElePwr->ElePwr_Per1_ElectricPower_Watt_f32->value)

# define Rte_IWrite_ElePwr_Per1_SupplyCurrent_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_ElePwr->ElePwr_Per1_SupplyCurrent_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_ElePwr_Per1_SupplyCurrent_Amp_f32() \
  (&Rte_Inst_Ap_ElePwr->ElePwr_Per1_SupplyCurrent_Amp_f32->value)




# define RTE_START_SEC_AP_ELEPWR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ElePwr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrDax_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrQax_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrVoltDax_Volt_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrVoltQax_Volt_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ElePwr_Per1_ElectricPower_Watt_f32(Float data)
 *   Float *Rte_IWriteRef_ElePwr_Per1_ElectricPower_Watt_f32(void)
 *   void Rte_IWrite_ElePwr_Per1_SupplyCurrent_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ElePwr_Per1_SupplyCurrent_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ELEPWR_APPL_CODE) ElePwr_Per1(void);

# define RTE_STOP_SEC_AP_ELEPWR_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1399569649
#    error "The magic number of the generated file <C:/SynergyWorkspace/WorkingProjects/ElePwr-SF08B_1.1/ElePwr/utp/contract/Ap_ElePwr/Rte_Ap_ElePwr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1399569649
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ELEPWR_H */
