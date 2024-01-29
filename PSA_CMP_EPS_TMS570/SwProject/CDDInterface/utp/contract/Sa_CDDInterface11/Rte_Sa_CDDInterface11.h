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
 *          File:  Rte_Sa_CDDInterface11.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface11
 *  Generated at:  Fri Dec  8 18:25:26 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface11> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE11_H
# define _RTE_SA_CDDINTERFACE11_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface11, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_CDDInterface11_Init1_DesiredTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface11->CDDInterface11_Init1_DesiredTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface11_Init1_DesiredTunSet_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface11->CDDInterface11_Init1_DesiredTunSet_Cnt_u16->value)

# define Rte_IWrite_CDDInterface11_Per1_DesiredTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface11->CDDInterface11_Per1_DesiredTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface11_Per1_DesiredTunSet_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface11->CDDInterface11_Per1_DesiredTunSet_Cnt_u16->value)




# define RTE_START_SEC_SA_CDDINTERFACE11_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface11_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface11_Init1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface11_Init1_DesiredTunSet_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE11_APPL_CODE) CDDInterface11_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface11_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface11_Per1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface11_Per1_DesiredTunSet_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE11_APPL_CODE) CDDInterface11_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE11_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1512761200
#    error "The magic number of the generated file <C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/SwProject/CDDInterface/utp/contract/Sa_CDDInterface11/Rte_Sa_CDDInterface11.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1512761200
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE11_H */
