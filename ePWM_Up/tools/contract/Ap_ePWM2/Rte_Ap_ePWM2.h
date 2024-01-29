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
 *          File:  Rte_Ap_ePWM2.h
 *     Workspace:  C:/Users/rzk04c/Documents/Synergy/EA3/ePWM_Up/autosar
 *     SW-C Type:  Ap_ePWM2
 *  Generated at:  Tue May  3 15:07:35 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ePWM2> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_EPWM2_H
# define _RTE_AP_EPWM2_H

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

typedef P2CONST(struct Rte_CDS_Ap_ePWM2, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CtrldDmpStsCmp_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsCtrldDisRmpPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_ePWM2_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ePWM2_Per1_CtrldDmpStsCmp_Cnt_lgc() \
  (Rte_Inst_Ap_ePWM2->ePWM2_Per1_CtrldDmpStsCmp_Cnt_lgc->value)

# define Rte_IRead_ePWM2_Per1_DiagStsCtrldDisRmpPres_Cnt_lgc() \
  (Rte_Inst_Ap_ePWM2->ePWM2_Per1_DiagStsCtrldDisRmpPres_Cnt_lgc->value)

# define Rte_IRead_ePWM2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_ePWM2->ePWM2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_ePWM2_Per1_RampDwnStatusComplete_Cnt_lgc() \
  (Rte_Inst_Ap_ePWM2->ePWM2_Per1_RampDwnStatusComplete_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_ePWM2_SystemState_Mode




# define RTE_START_SEC_AP_EPWM2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Per1
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
 *   Boolean Rte_IRead_ePWM2_Per1_CtrldDmpStsCmp_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_DiagStsCtrldDisRmpPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_ePWM2_Per1_RampDwnStatusComplete_Cnt_lgc(void)
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

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ePWM2_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_EPWM2_APPL_CODE) ePWM2_Trns2(void);

# define RTE_STOP_SEC_AP_EPWM2_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1462299363
#    error "The magic number of the generated file <C:/Users/rzk04c/Documents/Synergy/EA3/ePWM_Up/tools/contract/Ap_ePWM2/Rte_Ap_ePWM2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1462299363
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_EPWM2_H */
