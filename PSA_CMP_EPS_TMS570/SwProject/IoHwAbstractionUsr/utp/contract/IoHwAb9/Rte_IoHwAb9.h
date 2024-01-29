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
 *          File:  Rte_IoHwAb9.h
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  IoHwAb9
 *  Generated at:  Tue Aug 26 16:12:20 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <IoHwAb9> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB9_H
# define _RTE_IOHWAB9_H

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

typedef P2CONST(struct Rte_CDS_IoHwAb9, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_IOHWAB9_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_Adc_ResetAdcEnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetAdcEnable> of PortPrototype <IoHwAb_Adc>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IoHwAb_Adc_ResetAdcEnable(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB9_APPL_CODE) IoHwAb_Adc_ResetAdcEnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_StartAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB9_APPL_CODE) IoHwAb_StartAdc(void);

# define RTE_STOP_SEC_IOHWAB9_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1409085495
#    error "The magic number of the generated file <C:/Users/nzx5jd/Desktop/DVOutput/IoHwAb9/Rte_IoHwAb9.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1409085495
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_IOHWAB9_H */
