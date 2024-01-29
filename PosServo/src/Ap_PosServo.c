/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PosServo.c
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PosServo-nz2999/PosServo/autosar
 *     SW-C Type:  Ap_PosServo
 *  Generated at:  Fri Feb 23 10:24:50 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PosServo>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2011-2018 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_PosServo.c
 * Module Description: Implementation of SF020A - "Position Tracking Servo"
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          EA3#14 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/01/11  1        JJW       Initial CBD SWC template                                                      4721
 * 06/06/11  2        VK        Implemented FDD SF20 rev001                                                   4721
 * 01/09/12  3        VK        Changed VehSpd_T_u12p4 to u9p7 and changed the precision for the
 *                              table associated.
 * 02/02/12  4        VK        Updated the memory segments for local functions and module level variables    4271
 * 08/01/12  5        OT        Updated to SF-20 v002                                                         5906
 * 08/08/12  6        OT        Fix UTP issue (typecasting overflow)                                          5906
 * 08/10/12  7        OT        Fixed another UTP issue (signed math overflow)                                5906
 * 08/29/12  8        KJS       Updated to SF-20 v003                                                         6116
 * 09/21/12  9        Selva     Checkpoints added and mempmap macros corrected                                6240
 * 03/15/13  10       SP        Updated to FDD V004                                                           7618
 * 03/15/13  11       SP        Fixed Anomaly 4651                                                            7634
 * 03/20/13  12       KJS       Corrected anomaly 4681                                                        7686
 * 05/09/13  13       Jared     Updated to FDD ver 005                                                        8192
 * 02/22/18  14       KByrski   Updated to Design version 6.0.0                                               EA3#18327
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_PosServo.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Ap_PosServo_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "SystemTime.h"
#include "filters.h"
#include "fixmath.h"
#include "interpolation.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */
/* PRQA S 4395 EOF
   MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */
/* MISRA-C:2004 Rule 11.4: Casting to different object pointer type. */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/********************************************* Embedded Local Constants **********************************************/
#define D_2MS_MS_F32                (2.0F)
#define D_DGAINMAX_MTRNM_F32        (255.0F)
#define D_DGAINMIN_MTRNM_F32        (-255.0F)
#define D_EXECRATE_HZ_F32           (500.0F)
#define D_POSSERVOMAXRAMP_ULS_F32   (1.0F)
#define D_POSSERVOMINRAMP_ULS_F32   (0.0F)
#define D_RAMPCMPL_ULS_U6P10        (0U)
#define D_ZERO_HWDEG_F32            (0.0F)
#define D_ZERO_MTRNMPHWDEGS_U12P4   (0U)
#define D_ZERO_MTRNM_F32            (0.0F)

/*********************************************** Module level variables **********************************************/
#define POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_POSSERVO_VAR) FiltHwPosKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_POSSERVO_VAR) FiltHwTrqKSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_POSSERVO_VAR) DTermKSV_M_str;
#define POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(boolean, AP_POSSERVO_VAR) PosSrvoRampComplete_Cnt_D_lgc;                          /* PRQA S 3218 */
#define POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_POSSERVO_VAR) PrkAstRampSV_Uls_M_f32;                                          /* PRQA S 3218 */
STATIC VAR(float32, AP_POSSERVO_VAR) PosSrvo_LimErr_HwDeg_M_f32;                                      /* PRQA S 3218 */
STATIC VAR(float32, AP_POSSERVO_VAR) PrevLimitedHwPos_HwDeg_M_f32;                                    /* PRQA S 3218 */
STATIC VAR(float32, AP_POSSERVO_VAR) PosSrvo_HwAgErr_HwDeg_M_f32;                                     /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_POSSERVO_VAR) PosSrvoHWATargFilt_HwDeg_D_f32;                         /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_POSSERVO_VAR) PosSrvoPIDCmd_MtrNm_D_f32;                              /* PRQA S 3218 */
STATIC volatile VAR(sint32, AP_POSSERVO_VAR) PosServo_PTerm_MtrNm_D_s24p7;                            /* PRQA S 3218 */
#define POSSERVO_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(sint16, AP_POSSERVO_VAR) PosServo_ITerm_MtrNm_D_s8p7;                             /* PRQA S 3218 */
STATIC volatile VAR(sint16, AP_POSSERVO_VAR) PosServo_DTerm_MtrNm_D_s8p7;                             /* PRQA S 3218 */
#define POSSERVO_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************** Function Prototypes *************************************************/
STATIC FUNC(float32, AP_POSSERVO_CODE) FilterDesiredAngle(CONST(boolean, AUTOMATIC) RampCmpl_Cnt_T_lgc,
                                                          CONST(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32,
                                                          CONST(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
                                                          CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                          CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7);

STATIC FUNC(void, AP_POSSERVO_CODE) TransitionControl(CONST(float32, AUTOMATIC) HwTorque_HwNm_T_f32,
                                                      CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                      P2VAR(float32, AUTOMATIC, AUTOMATIC) pPosSrvoReturnSclFct_Uls_T_f32,
                                                      P2VAR(float32, AUTOMATIC, AUTOMATIC) pPosSrvoSmoothEnable_Uls_T_f32,
                                                      P2VAR(boolean, AUTOMATIC, AUTOMATIC) pRampCmpl_Cnt_T_lgc);

STATIC FUNC(float32, AP_POSSERVO_CODE) PIDControl(CONST(float32, AUTOMATIC) FildTarHwAg_HwDeg_T_f32,
                                                  CONST(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
                                                  CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
                                                  CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                  CONST(boolean, AUTOMATIC) RampCmpl_Cnt_T_lgc);

STATIC FUNC(float32, AP_POSSERVO_CODE) OutputTorque(CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
                                                    CONST(float32, AUTOMATIC) PosSrvoSmoothEnable_Uls_T_f32,
                                                    CONST(float32, AUTOMATIC) PidCmd_MtrNm_T_f32,
                                                    CONST(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32);

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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosServo_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosServo_Init1
 *********************************************************************************************************************/

    LPF_KUpdate_f32_m(k_PrkAstHwaLPFKn_Hz_f32,   D_2MS_SEC_F32, &FiltHwPosKSV_M_str);
    LPF_KUpdate_f32_m(k_PrkAstHwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &FiltHwTrqKSV_M_str);
    LPF_KUpdate_f32_m(k_PrkAstDTermKn_Hz_f32,    D_2MS_SEC_F32, &DTermKSV_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosServo_Per1
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
 *   Float Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_PosServo_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PosServo_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_PosServo_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PosServo_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   Float Rte_IRead_PosServo_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PosServo_Per1_PosSrvoCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoCmd_MtrNm_f32(void)
 *   void Rte_IWrite_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(void)
 *   void Rte_IWrite_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosServo_Per1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32;
    VAR(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) PosSrvoCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PosSrvoReturnSclFct_Uls_T_f32;
    VAR(float32, AUTOMATIC) PosSrvoSmoothEnable_Uls_T_f32;

    /* Temporary */
    VAR(float32, AUTOMATIC) FildTarHwAg_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) RampCmpl_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) PidCmd_MtrNm_T_f32;
    VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;

    /* Configurable Start of Runnable Checkpoint */
    Rte_Call_PosServo_Per1_CP0_CheckpointReached();

    /* Read inputs */
    HandwheelPosition_HwDeg_T_f32 = Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32();      /* REQ: SF020A #34 I */
    HwTorque_HwNm_T_f32           = Rte_IRead_PosServo_Per1_HwTorque_HwNm_f32();                /* REQ: SF020A #35 I */
    MotorVelCRF_MtrRadpS_T_f32    = Rte_IRead_PosServo_Per1_MotorVelCRF_MtrRadpS_f32();         /* REQ: SF020A #36 I */
    PosSrvoEnable_Cnt_T_lgc       = Rte_IRead_PosServo_Per1_PosSrvoEnable_Cnt_lgc();            /* REQ: SF020A #9 I */
    PosSrvoHwAngle_HwDeg_T_f32    = Rte_IRead_PosServo_Per1_PosSrvoHwAngle_HwDeg_f32();         /* REQ: SF020A #33 I */
    VehicleSpeed_Kph_T_f32        = Rte_IRead_PosServo_Per1_VehicleSpeed_Kph_f32();             /* REQ: SF020A #32 I */

    VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);

    /* Transition Control */
    TransitionControl(HwTorque_HwNm_T_f32,
                      PosSrvoEnable_Cnt_T_lgc,
                      &PosSrvoReturnSclFct_Uls_T_f32,
                      &PosSrvoSmoothEnable_Uls_T_f32,
                      &RampCmpl_Cnt_T_lgc);

    /* Filter Desired Angle */
    FildTarHwAg_HwDeg_T_f32 = FilterDesiredAngle(RampCmpl_Cnt_T_lgc,
                                                 PosSrvoHwAngle_HwDeg_T_f32,
                                                 HandwheelPosition_HwDeg_T_f32,
                                                 PosSrvoEnable_Cnt_T_lgc,
                                                 VehicleSpeed_Kph_T_u9p7);

    /* PID Control */
    PidCmd_MtrNm_T_f32 = PIDControl(FildTarHwAg_HwDeg_T_f32,
                                    HandwheelPosition_HwDeg_T_f32,
                                    VehicleSpeed_Kph_T_u9p7,
                                    PosSrvoEnable_Cnt_T_lgc,
                                    RampCmpl_Cnt_T_lgc);

    /* CalcOutpTq */
    PosSrvoCmd_MtrNm_T_f32 = OutputTorque(VehicleSpeed_Kph_T_u9p7,
                                          PosSrvoSmoothEnable_Uls_T_f32,
                                          PidCmd_MtrNm_T_f32,
                                          MotorVelCRF_MtrRadpS_T_f32);

    /* Update Display Variables */
    PosSrvoRampComplete_Cnt_D_lgc  = RampCmpl_Cnt_T_lgc;
    PosSrvoHWATargFilt_HwDeg_D_f32 = FildTarHwAg_HwDeg_T_f32;
    PosSrvoPIDCmd_MtrNm_D_f32      = PidCmd_MtrNm_T_f32;

    /* Write outputs */
    Rte_IWrite_PosServo_Per1_PosSrvoCmd_MtrNm_f32(PosSrvoCmd_MtrNm_T_f32);                      /* REQ: SF020A #11 I */
    Rte_IWrite_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(PosSrvoReturnSclFct_Uls_T_f32);        /* REQ: SF020A #37 I */
    Rte_IWrite_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(PosSrvoSmoothEnable_Uls_T_f32);        /* REQ: SF020A #38 I */

    /* Configurable End of Runnable Checkpoint */
    Rte_Call_PosServo_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define RTE_START_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * Name:        FilterDesiredAngle
 * Description: Implementation of "Filter Desired Angle" block in FDD
 * Inputs:      RampCmpl_Cnt_T_lgc
 *              PosSrvoHwAngle_HwDeg_T_f32
 *              HandwheelPosition_HwDeg_T_f32
 *              PosSrvoEnable_Cnt_T_lgc
 *              VehicleSpeed_Kph_T_u9p7
 * Outputs:     FildTarHwAg_HwDeg_T_f32
 * Usage Notes: Called by PosServo_Per1
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_POSSERVO_CODE) FilterDesiredAngle(CONST(boolean, AUTOMATIC) RampCmpl_Cnt_T_lgc,
                                                          CONST(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32,
                                                          CONST(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
                                                          CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                          CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7)
{
    VAR(uint16,  AUTOMATIC) HwPosRateLimit_HwDegpSec_T_u12p4;
    VAR(float32, AUTOMATIC) HwPosLimit_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) TempHwAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) LimitedHwPos_HwDeg_T_f32;

    if(PosSrvoEnable_Cnt_T_lgc != FALSE)
    {
        /* PassPosSrvoHwAngle */
        TempHwAg_HwDeg_T_f32 = PosSrvoHwAngle_HwDeg_T_f32;                                      /* REQ: SF020A #98 I */
    }
    else
    {
        /* PassHandwheelPosition */
        TempHwAg_HwDeg_T_f32 = HandwheelPosition_HwDeg_T_f32;                                   /* REQ: SF020A #99 I */
    }

    /* REQ: SF020A #100 I */
    HwPosRateLimit_HwDegpSec_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstVehSpdBS_Kph_u9p7,
                                                                   t_HwaRateLimit_HwDegpSec_u12p4,
                                                                   TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                                   VehicleSpeed_Kph_T_u9p7);

    HwPosLimit_HwDeg_T_f32 = FPM_FixedToFloat_m(HwPosRateLimit_HwDegpSec_T_u12p4, u12p4_T) * D_2MS_SEC_F32;

    LimitedHwPos_HwDeg_T_f32 = Limit_m(TempHwAg_HwDeg_T_f32,
                                       PrevLimitedHwPos_HwDeg_M_f32 - HwPosLimit_HwDeg_T_f32,
                                       PrevLimitedHwPos_HwDeg_M_f32 + HwPosLimit_HwDeg_T_f32);
    PrevLimitedHwPos_HwDeg_M_f32 = LimitedHwPos_HwDeg_T_f32;
    /* ENDREQ: SF020A #100 I */

    if (FALSE == PosSrvoEnable_Cnt_T_lgc)
    {
        /* KeepChecking */
        if (FALSE == RampCmpl_Cnt_T_lgc)
        {
            /* PrevActvAndRampCmpl */                                                          /* REQ: SF020A #101 I */
        }
        else
        {
            /* ActvAndRampCmpl */
            FiltHwPosKSV_M_str.SV_Uls_f32 = HandwheelPosition_HwDeg_T_f32;                     /* REQ: SF020A #142 I */
        }
    }
    else
    {
        /* ActvAndRampCmpl */
        LPF_OpUpdate_f32_m(LimitedHwPos_HwDeg_T_f32, &FiltHwPosKSV_M_str);                     /* REQ: SF020A #141 I */
    }

    return FiltHwPosKSV_M_str.SV_Uls_f32;
}

/**********************************************************************************************************************
 * Name:        TransitionControl
 * Description: Implementation of "Transition Control" block in FDD
 * Inputs:      HwTorque_HwNm_T_f32
 *              PosSrvoEnable_Cnt_T_lgc
 * Outputs:     PosSrvoReturnSclFct_Uls_T_f32
 *              PosSrvoSmoothEnable_Uls_T_f32
 *              RampCmpl_Cnt_T_lgc
 * Usage Notes: Called by PosServo_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, AP_POSSERVO_CODE) TransitionControl(CONST(float32, AUTOMATIC) HwTorque_HwNm_T_f32,
                                                      CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                      P2VAR(float32, AUTOMATIC, AUTOMATIC) pPosSrvoReturnSclFct_Uls_T_f32,
                                                      P2VAR(float32, AUTOMATIC, AUTOMATIC) pPosSrvoSmoothEnable_Uls_T_f32,
                                                      P2VAR(boolean, AUTOMATIC, AUTOMATIC) pRampCmpl_Cnt_T_lgc)
{
    VAR(float32, AUTOMATIC) HwTrqFilt_HwNm_T_f32;
    VAR(uint16,  AUTOMATIC) AbsHwTrqFilt_HwNm_T_u11p5;
    VAR(uint16,  AUTOMATIC) Rate_UlspS_T_u12p4;
    VAR(uint16,  AUTOMATIC) Slew_Uls_T_u6p10;
    VAR(uint16,  AUTOMATIC) SmoothEnable_Uls_T_u6p10;

    HwTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &FiltHwTrqKSV_M_str);       /* REQ: SF020A #136 I */

    if (FALSE != PosSrvoEnable_Cnt_T_lgc)
    {
        /* True */
        PrkAstRampSV_Uls_M_f32 += k_PrkAstEnableRate_pSec_f32 * D_2MS_SEC_F32;                 /* REQ: SF020A #137 I */ /* REQ: SF020A #138 I */
    }
    else
    {
        /* False */
        /* REQ: SF020A #139 I */
        AbsHwTrqFilt_HwNm_T_u11p5 = FPM_FloatToFixed_m(Abs_f32_m(HwTrqFilt_HwNm_T_f32), u11p5_T); /* REQ: SF020A #136 I */
        Rate_UlspS_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstDisableRateX_HwNm_u11p5,
                                                         t_PrkAstDisableRateY_pSec_u12p4,
                                                         TableSize_m(t_PrkAstDisableRateX_HwNm_u11p5),
                                                         AbsHwTrqFilt_HwNm_T_u11p5 );

        PrkAstRampSV_Uls_M_f32 -= FPM_FixedToFloat_m(Rate_UlspS_T_u12p4, u12p4_T) * D_2MS_SEC_F32; /* REQ: SF020A #137 I */
        /* ENDREQ: SF020A #139 I */
    }

    /* REQ: SF020A #70 I */
    PrkAstRampSV_Uls_M_f32 = Limit_m(PrkAstRampSV_Uls_M_f32, D_POSSERVOMINRAMP_ULS_F32, D_POSSERVOMAXRAMP_ULS_F32);
    Slew_Uls_T_u6p10 = FPM_FloatToFixed_m(PrkAstRampSV_Uls_M_f32, u6p10_T);

    SmoothEnable_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstSmoothX_Uls_u6p10,
                                                           t_PrkAstSmoothY_Uls_u6p10,
                                                           TableSize_m(t_PrkAstSmoothX_Uls_u6p10),
                                                           Slew_Uls_T_u6p10);
    (*pPosSrvoSmoothEnable_Uls_T_f32) = FPM_FixedToFloat_m(SmoothEnable_Uls_T_u6p10, u6p10_T);
    /* ENDREQ: SF020A #70 I */

    (*pRampCmpl_Cnt_T_lgc) = (D_RAMPCMPL_ULS_U6P10 == SmoothEnable_Uls_T_u6p10) ? TRUE : FALSE;         /* REQ: SF020A #71 I *//* REQ: SF020A #96 I */
    (*pPosSrvoReturnSclFct_Uls_T_f32) = D_POSSERVOMAXRAMP_ULS_F32 - (*pPosSrvoSmoothEnable_Uls_T_f32);  /* REQ: SF020A #140 I */
}

/**********************************************************************************************************************
 * Name:        PIDControl
 * Description: Implementation of "PID Control" block in FDD
 * Inputs:      FildTarHwAg_HwDeg_T_f32
 *              HandwheelPosition_HwDeg_T_f32
 *              VehicleSpeed_Kph_T_u9p7
 *              PosSrvoEnable_Cnt_T_lgc
 *              RampCmpl_Cnt_T_lgc
 * Outputs:     PidCmd_MtrNm_T_f32
 * Usage Notes: Called by PosServo_Per1
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_POSSERVO_CODE) PIDControl(CONST(float32, AUTOMATIC) FildTarHwAg_HwDeg_T_f32,
                                                  CONST(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
                                                  CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
                                                  CONST(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
                                                  CONST(boolean, AUTOMATIC) RampCmpl_Cnt_T_lgc)
{
    VAR(uint16,  AUTOMATIC) PTerm_MtrNm_T_u9p7;
    VAR(float32, AUTOMATIC) PTerm_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) ITerm_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) DTerm_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) HwAgErr_HwDeg_T_f32;
    VAR(uint16,  AUTOMATIC) Ki_MtrNmpHwDegS_u2p14;
    VAR(float32, AUTOMATIC) Ki_MtrNmpHwDegS_f32;
    VAR(uint16,  AUTOMATIC) KiAntiWdup_MtrNm_T_u9p7;
    VAR(float32, AUTOMATIC) AntiWdup_MtrNmpHwDegS_T_f32;
    VAR(float32, AUTOMATIC) DTermRate_HwDegpLoop_T_f32;
    VAR(uint16,  AUTOMATIC) DTermGain_MtrNmmSpHwDeg_T_u7p9;
    VAR(float32, AUTOMATIC) PidCmd_MtrNm_T_f32;

    if ((FALSE == PosSrvoEnable_Cnt_T_lgc) && (FALSE != RampCmpl_Cnt_T_lgc))                   /* REQ: SF020A #103 I */ /* REQ: SF020A #104 I */ /* REQ: SF020A #143 I */
    {
        /* RstPid */
        /* REQ: SF020A #125 I */
        PidCmd_MtrNm_T_f32          = D_ZERO_MTRNM_F32;
        PosSrvo_HwAgErr_HwDeg_M_f32 = D_ZERO_HWDEG_F32;
        PosSrvo_LimErr_HwDeg_M_f32  = D_ZERO_HWDEG_F32;
        DTermKSV_M_str.SV_Uls_f32   = D_ZERO_MTRNM_F32;
        /* ENDREQ: SF020A #125 I */
    }
    else
    {
        /* CalcPid */
        HwAgErr_HwDeg_T_f32 = FildTarHwAg_HwDeg_T_f32 - HandwheelPosition_HwDeg_T_f32;         /* REQ: SF020A #102 I */

        /* PTerm */
        /* REQ: SF020A #112 I */
        /* REQ: SF020A #127 I */
        /* PRQA S 310 BilnrIntpl */
        PTerm_MtrNm_T_u9p7 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
                                                             FPM_FloatToFixed_m(Abs_f32_m(HwAgErr_HwDeg_T_f32), u12p4_T),
                                                             t_PrkAstVehSpdBS_Kph_u9p7,
                                                             TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                             (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PrkAstPGainX_HwDeg_u12p4,
                                                             (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PrkAstPGainY_MtrNm_u9p7,
                                                             TableSize_m(t2_PrkAstPGainX_HwDeg_u12p4[0]));
        /*PRQA L:BilnrIntpl */
        /* ENDREQ: SF020A #127 I */
        PTerm_MtrNm_T_f32 = FPM_FixedToFloat_m(PTerm_MtrNm_T_u9p7, u9p7_T) * (float32) Sign_f32_m(HwAgErr_HwDeg_T_f32);
        /* ENDREQ: SF020A #112 I */

        /* ITerm */
        /* REQ: SF020A #116 I */ /* REQ: SF020A #117 I */
        Ki_MtrNmpHwDegS_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstVehSpdBS_Kph_u9p7,
                                                            t_PrkAstIGainY_MtrNmpHwDegS_u2p14,
                                                            TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                            VehicleSpeed_Kph_T_u9p7);
        Ki_MtrNmpHwDegS_f32 = FPM_FixedToFloat_m(Ki_MtrNmpHwDegS_u2p14, u2p14_T);

        /* AntiWdup */
        if (Ki_MtrNmpHwDegS_u2p14 == D_ZERO_MTRNMPHWDEGS_U12P4)
        {
            /* KiZero */
            AntiWdup_MtrNmpHwDegS_T_f32 = FPM_FixedToFloat_m(D_ZERO_MTRNMPHWDEGS_U12P4, u12p4_T);
        }
        else
        {
            /* KiNotZero */
            KiAntiWdup_MtrNm_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstVehSpdBS_Kph_u9p7,
                                                                  t_PrkAstITermAWLmtY_MtrNm_u9p7,
                                                                  TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                                  VehicleSpeed_Kph_T_u9p7);

            AntiWdup_MtrNmpHwDegS_T_f32 = (D_EXECRATE_HZ_F32 * FPM_FixedToFloat_m(KiAntiWdup_MtrNm_T_u9p7, u9p7_T))
                    / Ki_MtrNmpHwDegS_f32;
        }

        PosSrvo_LimErr_HwDeg_M_f32 += HwAgErr_HwDeg_T_f32;

        PosSrvo_LimErr_HwDeg_M_f32 = Limit_m(PosSrvo_LimErr_HwDeg_M_f32, -AntiWdup_MtrNmpHwDegS_T_f32, AntiWdup_MtrNmpHwDegS_T_f32);

        ITerm_MtrNm_T_f32 = PosSrvo_LimErr_HwDeg_M_f32 * Ki_MtrNmpHwDegS_f32 * D_2MS_SEC_F32;
        /* ENDREQ: SF020A #116 I */ /* ENDREQ: SF020A #117 I */

        /* DTerm */
        /* REQ: SF020A #120 I */
        DTermRate_HwDegpLoop_T_f32 = HwAgErr_HwDeg_T_f32 - PosSrvo_HwAgErr_HwDeg_M_f32;
        PosSrvo_HwAgErr_HwDeg_M_f32 = HwAgErr_HwDeg_T_f32;

        DTermGain_MtrNmmSpHwDeg_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstVehSpdBS_Kph_u9p7,
                                                                     t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9,
                                                                     TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                                     VehicleSpeed_Kph_T_u9p7);

        DTerm_MtrNm_T_f32 = (DTermRate_HwDegpLoop_T_f32 * FPM_FixedToFloat_m(DTermGain_MtrNmmSpHwDeg_T_u7p9, u7p9_T)) / D_2MS_MS_F32;
        DTerm_MtrNm_T_f32 = Limit_m(DTerm_MtrNm_T_f32, D_DGAINMIN_MTRNM_F32, D_DGAINMAX_MTRNM_F32);
        /* ENDREQ: SF020A #120 I */

        DTerm_MtrNm_T_f32 = LPF_OpUpdate_f32_m(DTerm_MtrNm_T_f32, &DTermKSV_M_str);            /* REQ: SF020A #121 I */

        /* Update Display Variables */
        PosServo_PTerm_MtrNm_D_s24p7 = FPM_FloatToFixed_m(PTerm_MtrNm_T_f32, s24p7_T);         /* REQ: SF020A #117 I */
        PosServo_ITerm_MtrNm_D_s8p7  = FPM_FloatToFixed_m(ITerm_MtrNm_T_f32, s8p7_T);
        PosServo_DTerm_MtrNm_D_s8p7  = FPM_FloatToFixed_m(DTerm_MtrNm_T_f32, s8p7_T);

        /* Compute and limit the sum */
        PidCmd_MtrNm_T_f32 = PTerm_MtrNm_T_f32 + ITerm_MtrNm_T_f32 + DTerm_MtrNm_T_f32;        /* REQ: SF020A #123 I */
        PidCmd_MtrNm_T_f32 = Limit_m(PidCmd_MtrNm_T_f32, -k_PosSrvo_PidLim_MtrNm_f32, k_PosSrvo_PidLim_MtrNm_f32);
    }

    return PidCmd_MtrNm_T_f32;
}

/**********************************************************************************************************************
 * Name:        OutputTorque
 * Description: Implementation of "CalcOutpTq" block in FDD
 * Inputs:      VehicleSpeed_Kph_T_u9p7
 *              PosSrvoSmoothEnable_Uls_T_f32
 *              PidCmd_MtrNm_T_f32
 *              MotorVelCRF_MtrRadpS_T_f32
 * Outputs:     PosSrvoCmd_MtrNm_T_f32
 * Usage Notes: Called by PosServo_Per1
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_POSSERVO_CODE) OutputTorque(CONST(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
                                                    CONST(float32, AUTOMATIC) PosSrvoSmoothEnable_Uls_T_f32,
                                                    CONST(float32, AUTOMATIC) PidCmd_MtrNm_T_f32,
                                                    CONST(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32)
{
    VAR(uint16,  AUTOMATIC) AbsMotorVelCRF_MtrRadpS_T_u11p5;
    VAR(uint16,  AUTOMATIC) DampingTrq_MtrNm_T_u4p12;
    VAR(uint16,  AUTOMATIC) OutputLimit_MtrNm_T_u5p11;
    VAR(float32, AUTOMATIC) OutpLim_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) DmpTerm_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PosSrvoCmd_MtrNm_T_f32;

    /* REQ: SF020A #127 I */
    AbsMotorVelCRF_MtrRadpS_T_u11p5 = FPM_FloatToFixed_m(Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32), u11p5_T);

    /* PRQA S 310 BilnrIntpl */
    DampingTrq_MtrNm_T_u4p12 = BilinearXYM_u16_u16Xu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
                                                             AbsMotorVelCRF_MtrRadpS_T_u11p5,
                                                             t_PrkAstVehSpdBS_Kph_u9p7,
                                                             TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
                                                             t_PrkAstDmpTrqX_MtrRadpS_u11p5,
                                                             (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PrkAstDmpTrqY_MtrNm_u4p12,
                                                             TableSize_m(t_PrkAstDmpTrqX_MtrRadpS_u11p5));
    /*PRQA L:BilnrIntpl */
    DmpTerm_MtrNm_T_f32 = FPM_FixedToFloat_m(DampingTrq_MtrNm_T_u4p12, u4p12_T) * (float32) Sign_f32_m(MotorVelCRF_MtrRadpS_T_f32);
    PosSrvoCmd_MtrNm_T_f32 = (PidCmd_MtrNm_T_f32 - DmpTerm_MtrNm_T_f32) * PosSrvoSmoothEnable_Uls_T_f32;
    /* ENDREQ: SF020A #127 I */

    /* REQ: SF020A #128 I */
    OutputLimit_MtrNm_T_u5p11 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PosSrvoMaxCmdX_Kph_u9p7,
                                                            t_PosSrvoMaxCmdY_MtrNm_u5p11,
                                                            TableSize_m(t_PosSrvoMaxCmdX_Kph_u9p7),
                                                            VehicleSpeed_Kph_T_u9p7);

    OutpLim_MtrNm_T_f32 = FPM_FixedToFloat_m(OutputLimit_MtrNm_T_u5p11, u5p11_T);
    /* ENDREQ: SF020A #128 I */

    PosSrvoCmd_MtrNm_T_f32 = Limit_m(PosSrvoCmd_MtrNm_T_f32, -OutpLim_MtrNm_T_f32, OutpLim_MtrNm_T_f32);    /* REQ: SF020A #129 I */ /* REQ: SF020A #130 I */

    return PosSrvoCmd_MtrNm_T_f32;
}

#define RTE_STOP_SEC_AP_POSSERVO_APPL_CODE
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
