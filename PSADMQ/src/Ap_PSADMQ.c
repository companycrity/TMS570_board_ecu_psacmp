/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PSADMQ.c
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSADMQ/PSADMQ/autosar
 *     SW-C Type:  Ap_PSADMQ
 *  Generated at:  Wed Sep  6 13:48:10 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PSADMQ>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2016-2017 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_PSADMQ.c
 * Module Description: Implementation of CF024A - PSA Driving Mode Qualifier
 * Project           : CBD
 * Author            : Jayakrishnan T
 **********************************************************************************************************************
 * Version Control:
 * %version:          6 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 05/24/16  1        JK        Initial Version of CF024A                                                     EA3#8100
 * 10/26/16  2        KK        Updates as per FDD v2.0.0                                                     EA3#12456
 * 11/23/16  3        KK        Fix for anomaly EA3#12751                                                     EA3#12784
 * 03/22/17  4        KK        Updates as per FDD v2.2.0                                                     EA3#14764
 * 07/10/17  5        KK        All uint8 I/O ports switched to enumerations (as per FDD v2.3.0)              EA3#16545
 * 09/05/17  6        KByrski   Updates as per FDD v2.3.0 and v2.4.0                                          EA3#16545
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Port Prototypes:
 ================
  DesiredTunPers
    Desired Tuning Personality

  MultiModSwt
    CAN signal to switch between the tuning mode

  MultiModeSelected
    Variant coding signal to enable/disable multimode function

  PersSelnInpVld
    Check if the CAN signal used by multimode is valid

  TunModSt
    Tuning Mode State Output

  TunReqGranted
    Indicates whether request is granted for tuning set or personality change. TRUE = Request granted, FALSE = Request denied

 *********************************************************************************************************************/

#include "Rte_Ap_PSADMQ.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/********************************************* Embedded Local Constants **********************************************/
#define D_DESIREDTUNPERSONE_CNT_U16  (1U)   /* Desired Tuning Personality One */
#define D_DESIREDTUNPERSTWO_CNT_U16  (2U)   /* Desired Tuning Personality Two */
#define D_DESIREDTUNPERSZERO_CNT_U16 (0U)   /* Desired Tuning Personality Zero */

/*********************************************** Module level variables **********************************************/
#define PSADMQ_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_PSADMQ_VAR) PsaDMQ_FirstLoop_Cnt_M_lgc; /* PRQA S 3218 */
#define PSADMQ_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define PSADMQ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(PsaTunModSt_Cnt_enum, AP_PSADMQ_VAR) PsaDMQ_TunModSt_Cnt_M_enum;
STATIC VAR(PsaTunModSt_Cnt_enum, AP_PSADMQ_VAR) PsaDMQ_PrevTunModSt_Cnt_M_enum;
#define PSADMQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define PSADMQ_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_PSADMQ_VAR) PsaDMQ_DesiredTunPers_Cnt_M_u16;
#define PSADMQ_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************** Function Prototypes *************************************************/
STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModNorm(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum);

STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModSport(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum);

STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModTun(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum);

STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModFaild(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MultiModeSelected_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 *
 * Enumeration Types:
 * ==================
 * PsaTunModSt_Cnt_enum: Enumeration of integer in interval [0...3] with enumerators
 *   PSATUNMODST_NORM (0u)
 *   PSATUNMODST_SPORT (1u)
 *   PSATUNMODST_TUN (2u)
 *   PSATUNMODST_FAILD (3u)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * PsaTunModSt_Cnt_enum: D_PSATUNMODSTINIT_CNT_ENUM = 0u
 * UInt16: D_ZERO_CNT_U16 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSADMQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

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

FUNC(void, RTE_AP_PSADMQ_APPL_CODE) PSADMQ_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSADMQ_Per1
 *********************************************************************************************************************/

    VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) MultiModeSelected_Cnt_T_lgc;

    /* Read inputs */
    MultiModSwt_Cnt_T_enum = Rte_IRead_PSADMQ_Per1_MultiModSwt_Cnt_enum();
    PersSelnInpVld_Cnt_T_lgc = Rte_IRead_PSADMQ_Per1_PersSelnInpVld_Cnt_lgc();
    TunReqGranted_Cnt_T_lgc = Rte_IRead_PSADMQ_Per1_TunReqGranted_Cnt_lgc();
    MultiModeSelected_Cnt_T_lgc = Rte_IRead_PSADMQ_Per1_MultiModeSelected_Cnt_lgc();

    if (PsaDMQ_FirstLoop_Cnt_M_lgc != TRUE)
    {
        PsaDMQ_FirstLoop_Cnt_M_lgc = TRUE;

        if ((PersSelnInpVld_Cnt_T_lgc == FALSE) ||
            (MultiModeSelected_Cnt_T_lgc == FALSE))
        {
            PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_FAILD;
        }
        else
        {
            PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_NORM;
        }
    }
    else
    {
        switch (PsaDMQ_TunModSt_Cnt_M_enum)
        {
            case PSATUNMODST_SPORT:
                ComputeTunModSport(PersSelnInpVld_Cnt_T_lgc, TunReqGranted_Cnt_T_lgc, MultiModSwt_Cnt_T_enum);
            break;

            case PSATUNMODST_TUN:
                ComputeTunModTun(PersSelnInpVld_Cnt_T_lgc, TunReqGranted_Cnt_T_lgc, MultiModSwt_Cnt_T_enum);
            break;

            case PSATUNMODST_FAILD:
                ComputeTunModFaild(PersSelnInpVld_Cnt_T_lgc, MultiModeSelected_Cnt_T_lgc);
            break;

            case PSATUNMODST_NORM:
            default:
                ComputeTunModNorm(PersSelnInpVld_Cnt_T_lgc, TunReqGranted_Cnt_T_lgc, MultiModSwt_Cnt_T_enum);
            break;
        }
    }

    /* Write outputs */
    (void) Rte_IWrite_PSADMQ_Per1_DesiredTunPers_Cnt_u16(PsaDMQ_DesiredTunPers_Cnt_M_u16);
    (void) Rte_IWrite_PSADMQ_Per1_TunModSt_Cnt_enum(PsaDMQ_TunModSt_Cnt_M_enum);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSADMQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define RTE_START_SEC_AP_PSADMQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * Name:        ComputeTunModNorm
 * Description: Implementation of logic in below mentioned path to reduce cyclomatic complexity.
 * Inputs:      PersSelnInpVld_Cnt_T_lgc
 *              TunReqGranted_Cnt_T_lgc
 *              MultiModSwt_Cnt_T_enum
 * Outputs:     PsaDMQ_TunModSt_Cnt_M_enum
 *              PsaDMQ_DesiredTunPers_Cnt_M_u16
 *              PsaDMQ_PrevTunModSt_Cnt_M_enum
 * Usage Notes: Path in FDD : CF024A_PSADMQ/PSADMQ/PSADMQ_Per1/ComputeTunModSt/NORMAL
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModNorm(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum)
{
    if (PersSelnInpVld_Cnt_T_lgc == FALSE)
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_FAILD;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_NORM;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_TUN))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_TUN;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSTWO_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_NORM;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_SPORT))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSONE_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_NORM;
    }
    else
    {
        /* Remain in Normal State */
    }
}
/**********************************************************************************************************************
 * Name:        ComputeTunModSport
 * Description: Implementation of logic in below mentioned path to reduce cyclomatic complexity.
 * Inputs:      PersSelnInpVld_Cnt_T_lgc
 *              TunReqGranted_Cnt_T_lgc
 *              MultiModSwt_Cnt_T_enum
 * Outputs:     PsaDMQ_TunModSt_Cnt_M_enum
 *              PsaDMQ_DesiredTunPers_Cnt_M_u16
 *              PsaDMQ_PrevTunModSt_Cnt_M_enum
 * Usage Notes: Path in FDD : CF024A_PSADMQ/PSADMQ/PSADMQ_Per1/ComputeTunModSt/SPORT
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModSport(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum)
{
    if (PersSelnInpVld_Cnt_T_lgc == FALSE)
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_FAILD;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_TUN))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_TUN;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSTWO_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_NORM))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_NORM;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSZERO_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
    }
    else
    {
        /* Remain in Sport State */
    }
}

/**********************************************************************************************************************
 * Name:        ComputeTunModTun
 * Description: Implementation of logic in below mentioned path to reduce cyclomatic complexity.
 * Inputs:      PersSelnInpVld_Cnt_T_lgc
 *              TunReqGranted_Cnt_T_lgc
 *              MultiModSwt_Cnt_T_enum
 * Outputs:     PsaDMQ_TunModSt_Cnt_M_enum
 *              PsaDMQ_DesiredTunPers_Cnt_M_u16
 *              PsaDMQ_PrevTunModSt_Cnt_M_enum
 * Usage Notes: Path in FDD : CF024A_PSADMQ/PSADMQ/PSADMQ_Per1/ComputeTunModSt/TUNABLE
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModTun(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) TunReqGranted_Cnt_T_lgc,
        VAR(PsaTunModSt_Cnt_enum, AUTOMATIC) MultiModSwt_Cnt_T_enum)
{
    if (PersSelnInpVld_Cnt_T_lgc == FALSE)
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_FAILD;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_TUN;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_NORM))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_NORM;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSZERO_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_TUN;
    }
    else if ((TunReqGranted_Cnt_T_lgc == TRUE) &&
             (MultiModSwt_Cnt_T_enum == PSATUNMODST_SPORT))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
        PsaDMQ_DesiredTunPers_Cnt_M_u16 = D_DESIREDTUNPERSONE_CNT_U16;
        PsaDMQ_PrevTunModSt_Cnt_M_enum = PSATUNMODST_TUN;
    }
    else
    {
        /* Remain in Tunable State */
    }
}

/**********************************************************************************************************************
 * Name:        ComputeTunModFaild
 * Description: Implementation of logic in below mentioned path to reduce cyclomatic complexity.
 * Inputs:      PersSelnInpVld_Cnt_T_lgc
 *              MultiModeSelected_Cnt_T_lgc
 * Outputs:     PsaDMQ_TunModSt_Cnt_M_enum
 * Usage Notes: Path in FDD : CF024A_PSADMQ/PSADMQ/PSADMQ_Per1/ComputeTunModSt/FAILLURE
 *********************************************************************************************************************/
STATIC FUNC(void, AP_PSADMQ_APPL_CODE) ComputeTunModFaild(
        VAR(boolean, AUTOMATIC) PersSelnInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MultiModeSelected_Cnt_T_lgc)
{
    if ((PersSelnInpVld_Cnt_T_lgc == TRUE) &&
        (PsaDMQ_PrevTunModSt_Cnt_M_enum == PSATUNMODST_NORM) &&
        (MultiModeSelected_Cnt_T_lgc == TRUE))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_NORM;
    }
    else if ((PersSelnInpVld_Cnt_T_lgc == TRUE) &&
             (PsaDMQ_PrevTunModSt_Cnt_M_enum == PSATUNMODST_SPORT) &&
             (MultiModeSelected_Cnt_T_lgc == TRUE))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_SPORT;
    }
    else if ((PersSelnInpVld_Cnt_T_lgc == TRUE) &&
             (PsaDMQ_PrevTunModSt_Cnt_M_enum == PSATUNMODST_TUN) &&
             (MultiModeSelected_Cnt_T_lgc == TRUE))
    {
        PsaDMQ_TunModSt_Cnt_M_enum = PSATUNMODST_TUN;
    }
    else
    {
        /* Remain in Failure State */
    }
}

#define RTE_STOP_SEC_AP_PSADMQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
