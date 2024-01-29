/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PSASH.c
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSAStHdlr-nz2999/PSAStHdlr/autosar
 *     SW-C Type:  Ap_PSASH
 *  Generated at:  Mon Feb 12 15:44:52 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PSASH>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2016-2018 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_PSASH.c
 * Module Description: Implementation of CF13A
 * Project           : CBD
 * Author            : Sankardu Varadapureddi
 **********************************************************************************************************************
 * Version Control:
 * %version:          EA3#17 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 03/04/15  1        SV        Initial Version                                                               EA3#13012
 * 07/30/15  2        SV        Updated for Anomaly EA3#2106                                                  EA3#2200
 * 08/13/15  3        SV        Updated for Anomalies EA3#2415,EA3#2316 and EA3#2318                          EA3#2465,
 *                                                                                                            EA3#2471,
 *                                                                                                            EA3#2476
 * 08/18/15  4        SV        Updated for Anomaly EA3#2526                                                  EA3#2570
 * 06/08/16  5        SV        Updated for FDD version 4.1.0                                                 EA3#4713
 * 08/11/16  6        KK        Updated for FDD version V5.0.0 to V5.2.0(Include City park function)          EA3#9280
 *                              (also fixed anomalies EA3#12055, EA3#11806)                                   EA3#12478
 * 12/15/16  7        KK        Fix for anomaly EA3#13197                                                     EA3#13199
 * 01/26/17  8        KK        Fix for anomalies EA3#13650, EA3#13651 as per FDD v5.4.0                      EA3#13749
 * 02/23/17  9        KK        Updated as per FDD v6.0.0                                                     EA3#14367
 * 03/16/17  10       KK        Corrected D_HWTRQRATEMINLIM_HWDEGPS_F32 definition                            EA3#14688
 * 03/22/17  11       KK        Updated as per FDD v6.2.0                                                     EA3#14762
 * 08/08/17  12       KByrski   Updated as per FDD v7.0.0                                                     EA3#16793
 * 12/07/17  13       MB        Fix anomaly EA3#17685                                                         EA3#18373
 * 01/30/18  14       KByrski   Updated as per FDD v8.0.0                                                     EA3#18808
 * 05/29/18  15       KByrski   Updated as per FDD v8.1.0                                                     EA3#20182
 * 14/06/18  16       BrykczyM  Updated as per FDD v8.2.0                                                     EA3#20372
 * 16/07/18  17       BrykczyM  Updated as per FDD v8.3.0 and the anomaly EA3#20489 fix                       EA3#20536
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
  AbsActv
    CAN signal indicating whether ABS is active or not.

  ApaAuthn
    True: Ignition is running and auto park function is authorized.

  ApaCmdReq
    True: Automatic Parking Assist Command is requested.

  ApaEna
    True: if the coding variant of Automatic Parking Assist is enabled

  ApaHwAgCmd
    Handwheel position set point for Automatic Parking Assist.

  ApaPosSrvoFlt
    True: If an NTC is detected due to fact that Automatic Parking ASsist is still active during a vehicle speed greater than a certain threshold

  ApaRelaxReq
    True: Temporary request to hold the Automatic Parking Assist command.

  ApaStateTransitionCause
    Indicates the transition reason of the Automatic Parking Assist State

  AssistStallLimit
    Motor is stalled when Stall limit is lower or equal than a certain calibrated threshold

  CpkOk
    True: All CAN signal used by Automatic Parking Assist are valid.

  DrvrIntvDetd
    True -> Hands are on the wheel.

  EPSStateForLxa
    EPS State For LXA

  EscActv
    True: Electrical stability control is active

  EscEna
    True: Electronic Stability Control is enabled.

  EscFltPrsnt
    True: Fault present on Electronic Stability Control

  FTermActv
    True: Fault term is active

  HOWState
    Computes if hands are on the wheel or not with a levelof confident goi'ng from -3 to 3

  HandwheelAuthority
    Handwheel Authority signal whichis used in order to determine APA State and LXA State.

  HandwheelPosition
    Handwheel Position Signal. Used in all kinds of computations: LXA State, APA State and LXA Driver Behavior

  HandwheelVelocity
    Handwheel Velocity. Used for calculating handwheel velocity thresholds used in LXA Driver Behavior algorithm to determine its outputs.

  HwTorque
    Standard Handwheel Torque used in LXA Driver Behavior algorithm.

  HwTrqRate
    Computes Handwheel Torque gradient during LXA command

  LpaSeld
    To select between LKA (Lane Keeping Assist) & LPA (Lane Positioning Assist). 0 = LPA Not Selected (LKA Active), 1 - Otherwise

  LxaApaConflictReqNTC
    True means that NTC VLF_20 has been set to FAILED at least one time.

  LxaCorrnFacReqLimd
    If equal to 1, then the trajectory correction is maximal. If equal to 0, then the trajectory correction is minimal.

  LxaDrvrAbsntDetd
    True = Lxa is inactive or driver absent detected

  LxaDrvrAbsntHwVelDetd
    True means Lxa has been deactivated on handwheel velocity.

  LxaDrvrAbsntWarn
    True means a warning that hands are not on the wheel.

  LxaHwAgCmd
    Handwheel position set point for LXA

  LxaHwAgDetd
    True means LXA has been deactivated on handwheel angle.

  LxaInactivOnDrvrBhvr
    LXA Inactive on Driver Behavior

  LxaInpVld
    True: CAN signals used by the LXA function are valid

  LxaSelected
    Variand coding to enable/disbale the Lxa function

  LxaState
    Lane Keeping Assist comand request to change the EPS state for LKA

  LxaTqFacReq
    A scale factor for LXA Command.

  OutputRampMult
    Signal used in computing internal EPS State which is part of EPS State For Lxa computations.

  PosSrvoEnable
    True means Position Servo is enabled.

  PosSrvoHwAngle
    Tracking angle.

  SystemState
    Indicates the system state.

  ThermLimitPerc
    Thermal Limit is reached when thermal Limit is higher than or equal to a certain calibrated threshold.

  VehicleSpeed
    Standard Vehicle Speed signal.

  VehicleSpeedValid
    TRUE: Vehicle Speed signal is valid


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration


 Runnable Entities:
 ==================
  PSASH_Init1
    Function initialization

  PSASH_Per1
    Periodic Runnable execute at every 0.002 sec. Shouble be executed before SF020A PosnTrakgServo

 *********************************************************************************************************************/

#include "Rte_Ap_PSASH.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "SystemTime.h"
#include "interpolation.h"
#include "fixmath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */
/* PRQA S 4395 EOF
   MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */
/* MISRA-C:2004 Rule 11.4: Casting to different object pointer type. */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/********************************************* Embedded Local Constants **********************************************/
/* PSA APA States */
#define D_APA_UNAVAILABLE_CNT_U08                     (0U)
#define D_APA_UNAVAILABLE_THERMALLIMIT_CNT_U08        (1U)
#define D_APA_UNAVAILABLE_NOAUTHORIZATION_CNT_U08     (2U)
#define D_APA_DEFECT_CNT_U08                          (3U)
#define D_APA_AVAILABLE_CNT_U08                       (4U)
#define D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08   (5U)
#define D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08       (6U)
#define D_APA_AVAILABLE_MOTORSTALLED_CNT_U08          (7U)
#define D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08   (8U)
#define D_APA_CONTROLPROGRESS_CNT_U08                 (9U)
#define D_APA_DEFAULT_CNT_U08                         (255U)

/* PSA LXA States */
#define D_LXA_UNAUTHORIZED_CNT_U08                    (0U)
#define D_LXA_AUTHORIZED_CNT_U08                      (1U)
#define D_LXA_AVAILABLE_CNT_U08                       (2U)
#define D_LXA_ACTIVE_CNT_U08                          (3U)
#define D_LXA_DEFECT_CNT_U08                          (4U)
#define D_LXA_DEFAULT_CNT_U08                         (255U)


#define D_FLTEPSILON_ULS_F32            (1.192092896e-07) /* Nearly zero */
#define D_HWTRQBUFSIZE_ULS_U08          (250U)            /* Handwheel Torque Buffer Size */
#define D_HWTRQRATEMAXLIM_HWDEGPS_F32   (2000.0F)         /* Handwheel Torque Rate Maximum Limit */
#define D_HWTRQRATEMINLIM_HWDEGPS_F32   (0.0F)            /* Handwheel Torque Rate Minimum Limit */
#define D_LXATQFACREQAVRG_ULS_F32       (0.04F)           /* Factor to calculate the average of Lxa Torque Factor Request */
#define D_LXATQFACREQBUFSIZE_CNT_U08    (25U)             /* Lxa Torque Factor Request Buffer Size */
#define D_LXATQFACREQBUFSIZE_ULS_F32    (25.0F)           /* Lxa Torque Factor Request Buffer Size */
#define D_ONE_CNT_U08                   (1U)              /* Count one with the data type uint8 */
#define D_POSSERVOHWAGMAXLIM_HWDEG_F32  (1600.0F)         /* Position Servo Handwheel Angle Maximum Limit */
#define D_POSSERVOHWAGMINLIM_HWDEG_F32  (-1600.0F)        /* Position Servo Handwheel Angle Minimum Limit */
#define D_SAMPLETIME_CNT_U16            (2U)              /* Sample Time */
#define D_U16MAX_CNT_U16                (65535U)          /* Maximum Value of Uint16 */
#define D_U16MAX_HWDEG_F32              (65535.0F)        /* Uint16 Maximum Value with the unit of HwDeg */
#define D_ZERO_CNT_U08                  (0U)              /* Count zero with the data type uint8 */
#define D_ZERO_HWDEG_F32                (0.0F)            /* Zero with the unit of HwDeg */
#define D_ZERO_HWNMPS_F32               (0.0F)            /* Constant float value of 0.0 with the unit of HwNmpS */
#define D_ZERO_SEC_F32                  (0.0F)            /* Zero with the unit of Sec */

/*********************************************** Module level variables **********************************************/
#define PSASH_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_PSASH_VAR) PrevApaPosSrvoEna_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaApaConflictReqNTC_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaDrvrAbsntDetd_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaDrvrAbsntWarn_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaHwAgDetd_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc;
STATIC VAR(boolean, AP_PSASH_VAR) LxaApaConflictReqFltTrig_Cnt_M_lgc;                         /* PRQA S 3218 */
STATIC VAR(boolean, AP_PSASH_VAR) LxaTqFacReqBufFull_Cnt_M_lgc;                               /* PRQA S 3218 */
STATIC VAR(boolean, AP_PSASH_VAR) PsaSH_HwTrqBufFilled_Cnt_M_lgc;                             /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaAllw_Cnt_D_lgc;                           /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaFltActv_Cnt_D_lgc;                        /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaHwAgDynErr_Cnt_D_lgc;                     /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaHwAgStatErr_Cnt_D_lgc;                    /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaHwMaxTrqReached_Cnt_D_lgc;                /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ApaHwMinTrqReached_Cnt_D_lgc;                /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_MtrStalled_Cnt_D_lgc;                        /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_ThrmlLmtReached_Cnt_D_lgc;                   /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_PSASH_VAR) PsaSH_VehSpdTooHi_Cnt_D_lgc;                       /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_PSASH_VAR) LxaTqFacReqPtr_Cnt_M_u08;                                     /* PRQA S 3218 */
STATIC VAR(uint8, AP_PSASH_VAR) PsaSH_HwTrqBufPtr_Cnt_M_u08;                                  /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_INIT_8
#include "MemMap.h" /* PRQA S 5087 */
/* Initialize default states */
STATIC VAR(uint8, AP_PSASH_VAR) LxaTqFacReqCntr_Cnt_M_u08;                                    /* PRQA S 3218 */
STATIC VAR(uint8, AP_PSASH_VAR) PsaSH_ApaState_Cnt_M_u08 = D_APA_DEFAULT_CNT_U08;             /* PRQA S 3218 */
STATIC VAR(uint8, AP_PSASH_VAR) PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_DEFAULT_CNT_U08;       /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_INIT_8
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_PSASH_VAR) PrevHwVelDetnCntr_Cnt_M_u16;
STATIC VAR(uint16, AP_PSASH_VAR) PsaSH_DynErrAcc_Cnt_M_u16;                                   /* PRQA S 3218 */
STATIC VAR(uint16, AP_PSASH_VAR) PsaSH_StaErrAcc_Cnt_M_u16;                                   /* PRQA S 3218 */
STATIC VAR(uint16, AP_PSASH_VAR) PsaSH_HwAgDetnCntr_Cnt_M_u16;                                /* PRQA S 3218 */
STATIC VAR(uint16, AP_PSASH_VAR) PsaSH_ApaExitCtrlProgsCntr_Cnt_M_u16;                        /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_D_u16;     /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_D_u16;     /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaHwAgDetnCntrNStep_Cnt_D_u16;               /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaHwAgDetnCntrPStep_Cnt_D_u16;               /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaHwVelDetnCntrNStep_Cnt_D_u16;              /* PRQA S 3218 */
STATIC volatile VAR(uint16, AP_PSASH_VAR) PsaSH_LxaHwVelDetnCntrPStep_Cnt_D_u16;              /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_PSASH_VAR) PrevDeltaApaHwAg_HwDeg_M_f32;                               /* PRQA S 3218 */
STATIC VAR(uint32,  AP_PSASH_VAR) MinTqTimer_mS_M_u32;                                        /* PRQA S 3218 */
STATIC VAR(uint32,  AP_PSASH_VAR) MaxTqTimer_mS_M_u32;                                        /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PrevLxaInactivRstTmr_Sec_M_f32;                             /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) LxaCorrnFacReqLimd_Uls_M_f32;                               /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) LxaTqFacReqBuf_Uls_M_f32[D_LXATQFACREQBUFSIZE_CNT_U08];     /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) LxaTqFacReqSum_Uls_M_f32;                                   /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PrevPosSrvoHwAngle_HwDeg_M_f32;                             /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PrevLxaTqFacReq_Uls_M_f32;                                  /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PsaSH_HwTrqDetnTmr_Sec_M_f32;                               /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PsaSH_HwTrqBuf_HwNm_M_f32[D_HWTRQBUFSIZE_ULS_U08];          /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PsaSH_HwTrqRateDetnTmr_Sec_M_f32;                           /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PSASH_VAR) PsaSH_LxaCorrnFacReq_Uls_D_f32;                    /* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32;                        /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PSASH_VAR) PsaSH_LxaDrvrAbsntHwVelThd_HwRadpS_D_f32;          /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PSASH_VAR) PsaSH_LxaHwAgThd_HwDeg_D_f32;                      /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_PSASH_VAR) PsaSH_LxaHwVelThd_HwRadpS_D_f32;                   /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str,             AP_PSASH_VAR) HwTrqFilterSV_Str_M_Str;
STATIC VAR(PsaEpsStLxa_Cnt_enum,     AP_PSASH_VAR) PsaSH_EPSStateForLxa_Cnt_M_enum;           /* PRQA S 3218 */
STATIC VAR(PsaApaSt_Cnt_enum,        AP_PSASH_VAR) PsaSH_ApaState_Cnt_M_enum;                 /* PRQA S 3218 */
STATIC VAR(PsaApaTranCause_Cnt_enum, AP_PSASH_VAR) PsaSH_ApaStateTransitionCause_Cnt_M_enum;  /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************** Function Prototypes *************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaDrvrBhvr(
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc,
        VAR(sint8,   AUTOMATIC) HOWState_Cnt_T_s08,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaHwAgThd(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaHwVelThd(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32);

STATIC FUNC(float32, RTE_AP_PSASH_APPL_CODE) ComputeLxaHowDetnTime(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaInactivOnDrvrBhvr(
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwAgMon(
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwTrqMon(
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwVelMon(
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaDrvrAbsntDetd(
        VAR(boolean, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) LxaDrvrAbsntDetdTi_Sec_T_f32,
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        VAR(boolean, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC)  LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC)  LxaInactivRstTmrDi_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaInactivRstTmr(
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaInactivRstTmrDi_Cnt_T_lgc,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7);

STATIC FUNC(PsaEpsSt_Cnt_enum, RTE_AP_PSASH_APPL_CODE) ComputeEPSState(
        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_u08,
        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc);

STATIC FUNC(float32, RTE_AP_PSASH_APPL_CODE) ComputeLxaCorrnFacReqLimd(
        VAR(float32, AUTOMATIC) LxaTqFacReq_Uls_T_f32,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc);

STATIC FUNC(PsaEpsStLxa_Cnt_enum, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwTqCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaTqReqFacCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa_ParentTransitions(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaNtcCdn_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa_ChildTransitions(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwTqCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaTqReqFacCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaNtcCdn_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApa(
        VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) ThermLimitPerc_Uls_T_f32,
        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaPosSrvoFlt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32,
        VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaState_Cnt_T_enum,
        P2VAR(PsaApaTranCause_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaStateTransitionCause_Cnt_T_enum);

STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaAllw(
        VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaLimits(
        VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
        VAR(float32, AUTOMATIC) ThermLimPerc_Uls_T_f32,
        VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) MtrStalled_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaDrvrIntv(
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc);

STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaHwAgCtrlErr(
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32);

STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaFltActv(
        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaPosSrvoFlt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState(
        VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaState_Cnt_T_enum,
        P2VAR(PsaApaTranCause_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaStateTransitionCause_Cnt_T_enum);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState_ParentTransitions(
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState_ChildTransitions(
        VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc);

STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputePosSrvoEnable(
        VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC) EPSStateForLxa_Cnt_T_enum,
        VAR(PsaApaSt_Cnt_enum, AUTOMATIC) ApaState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) LxaHwAgCmd_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) OutApaState_Cnt_T_enum,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32,
        P2VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC, AUTOMATIC) OutEPSStateForLxa_Cnt_T_enum);

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
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_PLLSlipNrcvrl (22u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PeripheralStartupFlt (55u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73u)
 *   NTC_Num_IvtrPwrDiscnctFailr (74u)
 *   NTC_Num_PowerRelayInit2Flt (75u)
 *   NTC_Num_GateDrvFltInProcess (76u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90u)
 *   NTC_Num_SysVltgCorrlnFlt (91u)
 *   NTC_Num_Inv2GateDrvFltInProcess (92u)
 *   NTC_Num_Inv2GateDrvFlt (93u)
 *   NTC_Num_Inv2OnStateSingleFET (94u)
 *   NTC_Num_EcuIdnFlt (95u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_IMCLossOfCom (125u)
 *   NTC_Num_ImcArbrFault (127u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_TurnCntr_SpiDataFlt (135u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_EcuCrossChk (150u)
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151u)
 *   NTC_Num_EcuConfigMismatch (152u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
 *   NTC_Num_AgCompDiagc (167u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_LoaRpdShutdn (170u)
 *   NTC_Num_LoaCtrldShutdn (171u)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172u)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173u)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174u)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_DataOtherFlt2Msg_Q (327u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AM (482u)
 *   NTC_Num_InvalidMsg_AM (483u)
 *   NTC_Num_CRCFltMsg_AM (484u)
 *   NTC_Num_PgrsCntFltMsg_AM (485u)
 *   NTC_Num_DataRngFltMsg_AM (486u)
 *   NTC_Num_InvalidMsg_AL (488u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_DataRngFltMsg_AL (492u)
 *   NTC_Num_DataOtherFltMsg_AL (494u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_PHAScratchPadTrf (503u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 * PsaApaSt_Cnt_enum: Enumeration of integer in interval [0...3] with enumerators
 *   PSAAPAST_UNAVL (0u)
 *   PSAAPAST_AVL (1u)
 *   PSAAPAST_CTRLPRGS (2u)
 *   PSAAPAST_DFCT (3u)
 * PsaApaTranCause_Cnt_enum: Enumeration of integer in interval [0...7] with enumerators
 *   PSAAPATRANCAUSE_NOINTRPT (0u)
 *   PSAAPATRANCAUSE_DRVRINTV (1u)
 *   PSAAPATRANCAUSE_VEHSPDHI (2u)
 *   PSAAPATRANCAUSE_AGLERR (3u)
 *   PSAAPATRANCAUSE_MTRSTALL (4u)
 *   PSAAPATRANCAUSE_UNUSED (5u)
 *   PSAAPATRANCAUSE_THERMLIM (6u)
 *   PSAAPATRANCAUSE_OTHERERR (7u)
 * PsaEpsStLxa_Cnt_enum: Enumeration of integer in interval [0...4] with enumerators
 *   PSAEPSSTLXA_UNAUTHD (0u)
 *   PSAEPSSTLXA_AUTHD (1u)
 *   PSAEPSSTLXA_AVL (2u)
 *   PSAEPSSTLXA_ACTV (3u)
 *   PSAEPSSTLXA_DFCT (4u)
 * PsaLxaSt_Cnt_enum: Enumeration of integer in interval [0...6] with enumerators
 *   PSALXAST_UNAVL (0u)
 *   PSALXAST_UNSELD (1u)
 *   PSALXAST_SELD (2u)
 *   PSALXAST_AUTHD (3u)
 *   PSALXAST_ACTV (4u)
 *   PSALXAST_DFCT (5u)
 *   PSALXAST_COLLRISK (6u)
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
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_MSECPERSEC_ULS_F32 = 1000
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * PsaApaSt_Cnt_enum: D_PSAAPASTINIT_CNT_ENUM = 0u
 * PsaApaTranCause_Cnt_enum: D_PSAAPATRANCAUSEINIT_CNT_ENUM = 0u
 * PsaEpsStLxa_Cnt_enum: D_PSAEPSSTLXAINIT_CNT_ENUM = 0u
 * PsaLxaSt_Cnt_enum: D_PSALXASTINIT_CNT_ENUM = 0u
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSASH_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSASH_Init1
 *********************************************************************************************************************/

    /* Hw TrqFilter K init */
    LPF_Init_f32_m(D_ZERO_ULS_F32, k_PsaSH_ApaMaxHwTrqFilt_Hz_f32, D_2MS_SEC_F32, &HwTrqFilterSV_Str_M_Str);  /* REQ: CF013A #25 I */

    /* LxaApaConflictRequestFault_Init */
    (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_20, 0U, NTC_STATUS_PASSED);                          /* REQ: CF013A #322 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Per1
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
 *   Boolean Rte_IRead_PSASH_Per1_AbsActv_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_ApaHwAgCmd_HwDeg_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscActv_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscEna_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_EscFltPrsnt_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc(void)
 *   SInt8 Rte_IRead_PSASH_Per1_HOWState_Cnt_s08(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_LpaSeld_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_LxaHwAgCmd_HwDeg_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_LxaInpVld_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_LxaSelected_Cnt_lgc(void)
 *   PsaLxaSt_Cnt_enum Rte_IRead_PSASH_Per1_LxaState_Cnt_enum(void)
 *   Float Rte_IRead_PSASH_Per1_LxaTqFacReq_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(PsaApaTranCause_Cnt_enum data)
 *   PsaApaTranCause_Cnt_enum *Rte_IWriteRef_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_ApaState_Cnt_enum(PsaApaSt_Cnt_enum data)
 *   PsaApaSt_Cnt_enum *Rte_IWriteRef_PSASH_Per1_ApaState_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_EPSStateForLxa_Cnt_enum(PsaEpsStLxa_Cnt_enum data)
 *   PsaEpsStLxa_Cnt_enum *Rte_IWriteRef_PSASH_Per1_EPSStateForLxa_Cnt_enum(void)
 *   void Rte_IWrite_PSASH_Per1_HwTrqRate_HwNmpS_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_HwTrqRate_HwNmpS_f32(void)
 *   void Rte_IWrite_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   void Rte_IWrite_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSASH_Per1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) ApaPosSrvoFlt_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32;
    VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc;
    VAR(sint8,   AUTOMATIC) HOWState_Cnt_T_s08;
    VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) LxaHwAgCmd_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc;
    VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum;
    VAR(float32, AUTOMATIC) LxaTqFacReq_Uls_T_f32;
    VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
    VAR(float32, AUTOMATIC) ThermLimitPerc_Uls_T_f32;
    VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
    VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

    /* Outputs */
    VAR(boolean, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc;
    VAR(PsaApaSt_Cnt_enum, AUTOMATIC) OutApaState_Cnt_T_enum;
    VAR(PsaApaTranCause_Cnt_enum, AUTOMATIC) ApaStateTransitionCause_Cnt_T_enum;
    VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC) OutEPSStateForLxa_Cnt_T_enum;
    VAR(float32, AUTOMATIC) LxaCorrnFacReqLimd_Uls_T_f32;
    VAR(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTrqRate_HwNmpS_T_f32 = 0.0F;

    /* Temporary variables */
    VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
    VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HwTqCdn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LxaTqReqFacCdn_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32;
    VAR(PsaEpsSt_Cnt_enum,    AUTOMATIC) EPSState_Cnt_T_enum;
    VAR(PsaApaSt_Cnt_enum,    AUTOMATIC) ApaState_Cnt_T_enum;
    VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC) EPSStateForLxa_Cnt_T_enum;

    /* Read inputs */
    AbsActv_Cnt_T_lgc                       = Rte_IRead_PSASH_Per1_AbsActv_Cnt_lgc();                 /* REQ: CF013A #11 I */
    ApaAuthn_Cnt_T_lgc                      = Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc();                /* REQ: CF013A #53 I */
    ApaCmdReq_Cnt_T_lgc                     = Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc();               /* REQ: CF013A #54 I */
    ApaEna_Cnt_T_lgc                        = Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc();                  /* REQ: CF013A #55 I */
    ApaHwAgCmd_HwDeg_T_f32                  = Rte_IRead_PSASH_Per1_ApaHwAgCmd_HwDeg_f32();            /* REQ: CF013A #56 I */
    ApaPosSrvoFlt_Cnt_T_lgc                 = Rte_IRead_PSASH_Per1_ApaPosSrvoFlt_Cnt_lgc();           /* REQ: CF013A #76 I */
    ApaRelaxReq_Cnt_T_lgc                   = Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc();             /* REQ: CF013A #57 I */
    AssistStallLimit_MtrNm_T_f32            = Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32();      /* REQ: CF013A #58 I */
    CpkOk_Cnt_T_lgc                         = Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc();                   /* REQ: CF013A #59 I */
    EscActv_Cnt_T_lgc                       = Rte_IRead_PSASH_Per1_EscActv_Cnt_lgc();                 /* REQ: CF013A #60 I */
    EscEna_Cnt_T_lgc                        = Rte_IRead_PSASH_Per1_EscEna_Cnt_lgc();                  /* REQ: CF013A #61 I */
    EscFltPrsnt_Cnt_T_lgc                   = Rte_IRead_PSASH_Per1_EscFltPrsnt_Cnt_lgc();             /* REQ: CF013A #62 I */
    FTermActv_Cnt_T_lgc                     = Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc();               /* REQ: CF013A #63 I */
    HOWState_Cnt_T_s08                      = Rte_IRead_PSASH_Per1_HOWState_Cnt_s08();                /* REQ: CF013A #64 I */
    HandwheelAuthority_Uls_T_f32            = Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32();      /* REQ: CF013A #65 I */
    HandwheelPosition_HwDeg_T_f32           = Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32();     /* REQ: CF013A #66 I */
    HandwheelVelocity_HwRadpS_T_f32         = Rte_IRead_PSASH_Per1_HandwheelVelocity_HwRadpS_f32();   /* REQ: CF013A #67 I */
    HwTorque_HwNm_T_f32                     = Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32();               /* REQ: CF013A #68 I */
    LpaSeld_Cnt_T_lgc                       = Rte_IRead_PSASH_Per1_LpaSeld_Cnt_lgc();                 /* REQ: CF013A #74 I */
    LxaHwAgCmd_HwDeg_T_f32                  = Rte_IRead_PSASH_Per1_LxaHwAgCmd_HwDeg_f32();            /* REQ: CF013A #72 I */
    LxaInpVld_Cnt_T_lgc                     = Rte_IRead_PSASH_Per1_LxaInpVld_Cnt_lgc();               /* REQ: CF013A #73 I */
    LxaSelected_Cnt_T_lgc                   = Rte_IRead_PSASH_Per1_LxaSelected_Cnt_lgc();             /* REQ: CF013A #70 I */
    LxaState_Cnt_T_enum                     = Rte_IRead_PSASH_Per1_LxaState_Cnt_enum();               /* REQ: CF013A #69 I */
    LxaTqFacReq_Uls_T_f32                   = Rte_IRead_PSASH_Per1_LxaTqFacReq_Uls_f32();             /* REQ: CF013A #71 I*/
    OutputRampMult_Uls_T_f32                = Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32();          /* REQ: CF013A #75 I */
    ThermLimitPerc_Uls_T_f32                = Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32();          /* REQ: CF013A #78 I */
    VehicleSpeedValid_Cnt_T_lgc             = Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc();       /* REQ: CF013A #93 I */
    VehicleSpeed_Kph_T_f32                  = Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32();            /* REQ: CF013A #94 I */
    SystemState_Cnt_T_enum                  = Rte_Mode_SystemState_Mode();                            /* REQ: CF013A #77 I */

    VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);

    /* HwTqFiltering */
    /* REQ: CF013A #226 I */ /* REQ: CF013A #228 I */ /* REQ: CF013A #111 I */ /* REQ: CF013A #139 I */
    HwTqFild_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &HwTrqFilterSV_Str_M_Str);
    /* ENDREQ: CF013A #226 I */ /* ENDREQ: CF013A #228 I */ /* ENDREQ: CF013A #111 I */ /* ENDREQ: CF013A #139 I */

    /* Compute_LxaDrvrBhvr */
    ComputeLxaDrvrBhvr(
            LxaSelected_Cnt_T_lgc,
            HOWState_Cnt_T_s08,
            LxaInpVld_Cnt_T_lgc,
            LxaState_Cnt_T_enum,
            HandwheelVelocity_HwRadpS_T_f32,
            HwTqFild_HwNm_T_f32,
            LpaSeld_Cnt_T_lgc,
            Abs_f32_m(HandwheelPosition_HwDeg_T_f32),       /* REQ: CF013A #106 I */ /* REQ: CF013A #122 I */
            VehicleSpeed_Kph_T_u9p7,
            &DrvrIntvDetd_Cnt_T_lgc,
            &HwTrqRate_HwNmpS_T_f32);

    /* VehSpdCdn */
    VehSpdCdn_Cnt_T_lgc             = (VehicleSpeed_Kph_T_f32 >= k_PsaSH_LxaVehSpdMin_Kph_f32) ? D_TRUE_CNT_LGC : D_FALSE_CNT_LGC;         /* REQ: CF013A #226 I */
    /* Compute_EPSState */
    EPSState_Cnt_T_enum             = ComputeEPSState(SystemState_Cnt_T_enum, OutputRampMult_Uls_T_f32, FTermActv_Cnt_T_lgc);
    /* HwAuthyCdn */
    HwAuthyCdn_Cnt_T_lgc            = (HandwheelAuthority_Uls_T_f32 >= k_PsaSH_LxaHwAuthy_Uls_f32) ? D_TRUE_CNT_LGC : D_FALSE_CNT_LGC;     /* REQ: CF013A #226 I */
    /* HwTqCdn */
    HwTqCdn_Cnt_T_lgc               = (Abs_f32_m(HwTqFild_HwNm_T_f32) < k_PsaSH_LxaMaxHwTrq_HwNm_f32) ? D_TRUE_CNT_LGC : D_FALSE_CNT_LGC;  /* REQ: CF013A #226 I */
    /* Compute_LxaCorrnFacReqLimd */
    LxaCorrnFacReqLimd_Uls_T_f32    = ComputeLxaCorrnFacReqLimd(LxaTqFacReq_Uls_T_f32, LxaInpVld_Cnt_T_lgc);
    /* LxaTqFacReqCdn */
    LxaTqReqFacCdn_Cnt_T_lgc        = (LxaCorrnFacReqLimd_Uls_T_f32 > k_PsaSH_LxaCorrnFacThd_Uls_f32) ? D_TRUE_CNT_LGC : D_FALSE_CNT_LGC;  /* REQ: CF013A #434 I */ /* REQ: CF013A #435 I */ /* REQ: CF013A #437 I */

    /* Compute_EPSStateForLxa */
    EPSStateForLxa_Cnt_T_enum = ComputeEPSStateForLxa(
            EscActv_Cnt_T_lgc,
            AbsActv_Cnt_T_lgc,
            EscFltPrsnt_Cnt_T_lgc,
            EscEna_Cnt_T_lgc,
            VehSpdCdn_Cnt_T_lgc,
            PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc,
            PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc,
            EPSState_Cnt_T_enum,
            LxaState_Cnt_T_enum,
            PrevLxaHwAgDetd_Cnt_M_lgc,
            HwAuthyCdn_Cnt_T_lgc,
            LpaSeld_Cnt_T_lgc,
            HwTqCdn_Cnt_T_lgc,
            LxaInpVld_Cnt_T_lgc,
            PrevLxaDrvrAbsntDetd_Cnt_M_lgc,
            LxaTqReqFacCdn_Cnt_T_lgc,
            LxaSelected_Cnt_T_lgc);

    /* APA */
    ComputeApa(
            AssistStallLimit_MtrNm_T_f32,
            ApaEna_Cnt_T_lgc,
            ThermLimitPerc_Uls_T_f32,
            VehicleSpeedValid_Cnt_T_lgc,
            CpkOk_Cnt_T_lgc,
            ApaPosSrvoFlt_Cnt_T_lgc,
            ApaAuthn_Cnt_T_lgc,
            ApaCmdReq_Cnt_T_lgc,
            ApaRelaxReq_Cnt_T_lgc,
            HandwheelAuthority_Uls_T_f32,
            SystemState_Cnt_T_enum,
            OutputRampMult_Uls_T_f32,
            VehicleSpeed_Kph_T_f32,
            HwTqFild_HwNm_T_f32,
            HandwheelPosition_HwDeg_T_f32,
            ApaHwAgCmd_HwDeg_T_f32,
            FTermActv_Cnt_T_lgc,
            &ApaState_Cnt_T_enum,
            &ApaStateTransitionCause_Cnt_T_enum);

    /* Compute_PosSrvoEnable */
    ComputePosSrvoEnable(
            EPSStateForLxa_Cnt_T_enum,
            ApaState_Cnt_T_enum,
            LxaHwAgCmd_HwDeg_T_f32,
            ApaRelaxReq_Cnt_T_lgc,
            ApaHwAgCmd_HwDeg_T_f32,
            VehicleSpeed_Kph_T_u9p7,
            HandwheelPosition_HwDeg_T_f32,
            &OutApaState_Cnt_T_enum,
            &PosSrvoEnable_Cnt_T_lgc,
            &PosSrvoHwAngle_HwDeg_T_f32,
            &OutEPSStateForLxa_Cnt_T_enum);

    HwTrqRate_HwNmpS_T_f32       = Limit_m(HwTrqRate_HwNmpS_T_f32, D_HWTRQRATEMINLIM_HWDEGPS_F32, D_HWTRQRATEMAXLIM_HWDEGPS_F32);
    LxaCorrnFacReqLimd_Uls_T_f32 = Limit_m(LxaCorrnFacReqLimd_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);

    /* Write outputs */
    Rte_IWrite_PSASH_Per1_ApaStateTransitionCause_Cnt_enum(ApaStateTransitionCause_Cnt_T_enum);       /* REQ: CF013A #79 I */
    Rte_IWrite_PSASH_Per1_ApaState_Cnt_enum(OutApaState_Cnt_T_enum);                                  /* REQ: CF013A #80 I */
    Rte_IWrite_PSASH_Per1_DrvrIntvDetd_Cnt_lgc(DrvrIntvDetd_Cnt_T_lgc);                               /* REQ: CF013A #81 I */
    Rte_IWrite_PSASH_Per1_EPSStateForLxa_Cnt_enum(OutEPSStateForLxa_Cnt_T_enum);                      /* REQ: CF013A #82 I */
    Rte_IWrite_PSASH_Per1_HwTrqRate_HwNmpS_f32(HwTrqRate_HwNmpS_T_f32);                               /* REQ: CF013A #83 I */
    Rte_IWrite_PSASH_Per1_LxaApaConflictReqNTC_Cnt_lgc(PrevLxaApaConflictReqNTC_Cnt_M_lgc);           /* REQ: CF013A #84 I */
    Rte_IWrite_PSASH_Per1_LxaCorrnFacReqLimd_Uls_f32(LxaCorrnFacReqLimd_Uls_T_f32);
    Rte_IWrite_PSASH_Per1_LxaDrvrAbsntDetd_Cnt_lgc(PrevLxaDrvrAbsntDetd_Cnt_M_lgc);                   /* REQ: CF013A #85 I */
    Rte_IWrite_PSASH_Per1_LxaDrvrAbsntHwVelDetd_Cnt_lgc(PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc);         /* REQ: CF013A #95 I */
    Rte_IWrite_PSASH_Per1_LxaDrvrAbsntWarn_Cnt_lgc(PrevLxaDrvrAbsntWarn_Cnt_M_lgc);                   /* REQ: CF013A #86 I */
    Rte_IWrite_PSASH_Per1_LxaHwAgDetd_Cnt_lgc(PrevLxaHwAgDetd_Cnt_M_lgc);                             /* REQ: CF013A #87 I */
    Rte_IWrite_PSASH_Per1_LxaInactivOnDrvrBhvr_Cnt_lgc(PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc);           /* REQ: CF013A #88 I */
    Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(PosSrvoEnable_Cnt_T_lgc);                             /* REQ: CF013A #89 I */
    Rte_IWrite_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(PosSrvoHwAngle_HwDeg_T_f32);                       /* REQ: CF013A #90 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSASH_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define RTE_START_SEC_AP_PSASH_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 * Name:        ComputeLxaDrvrBhvr
 * Description: Implementation of "Compute_LxaDrvrBhvr" block in the FDD.
 * Inputs:      VehicleSpeed_Kph_T_u9p7
 *              LxaSelected_Cnt_T_lgc
 *              HOWState_Cnt_T_s08
 *              LxaInpVld_Cnt_T_lgc
 *              LxaState_Cnt_T_enum
 *              HandwheelVelocity_HwRadpS_T_f32
 *              HwTqFild_HwNm_T_f32
 *              LpaSeld_Cnt_T_lgc
 *              AbsltHwPosn_HwDeg_T_f32
 *              VehicleSpeed_Kph_T_u9p7
 * Outputs:     PrevLxaDrvrAbsntDetd_Cnt_M_lgc
 *              PrevLxaDrvrAbsntWarn_Cnt_M_lgc
 *              DrvrIntvDetd_Cnt_T_lgc
 *              PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc
 *              PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc
 *              PrevLxaHwAgDetd_Cnt_M_lgc
 *              HwTrqRate_HwNmpS_T_f32
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaDrvrBhvr(
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc,
        VAR(sint8,   AUTOMATIC) HOWState_Cnt_T_s08,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32)
{
    VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16;
    VAR(float32, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32;
    VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16;
    VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16;
    VAR(float32, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) LxaDrvrAbsntDetdTi_Sec_T_f32;
    VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32;
    VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc;
    VAR(uint16,  AUTOMATIC) HwVelDetnCntr_Cnt_T_u16;
    VAR(boolean, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) LxaInactivRstTmrDi_Cnt_T_lgc;

    /* Compute_LxaHwAgThd */
    ComputeLxaHwAgThd(
            VehicleSpeed_Kph_T_u9p7,
            AbsltHwPosn_HwDeg_T_f32,
            &LxaHwAgDetnCntrNStep_Cnt_T_u16,
            &LxaHwAgDetnCntrPStep_Cnt_T_u16,
            &LxaHwAgThd_HwDeg_T_f32);

    /* Compute_LxaHwVelThd */
    ComputeLxaHwVelThd(
            VehicleSpeed_Kph_T_u9p7,
            HandwheelVelocity_HwRadpS_T_f32,
            HwTqFild_HwNm_T_f32,
            &LxaHwVelDetnCntrNStep_Cnt_T_u16,
            &LxaHwVelDetnCntrPStep_Cnt_T_u16,
            &LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
            &LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
            &LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
            &LxaHwVelThd_HwRadpS_T_f32);

    /* Compute_LxaHowDetnTime */
    LxaDrvrAbsntDetdTi_Sec_T_f32 = ComputeLxaHowDetnTime(
            VehicleSpeed_Kph_T_u9p7,
            LpaSeld_Cnt_T_lgc);

    /* REQ: CF013A #344 I */ /* REQ: CF013A #345 I */ /* REQ: CF013A #153 I */ /* REQ: CF013A #346 I */ /* REQ: CF013A #347 I */ /* REQ: CF013A #348 I */ /* REQ: CF013A #349 I */
    /* Compute_LxaDrvrBhvr */
    if (LxaSelected_Cnt_T_lgc == D_TRUE_CNT_LGC) /* REQ: CF013A #153 I */ /* REQ: CF013A #344 I */ /* REQ: CF013A #345 I */ /* REQ: CF013A #346 I */ /* REQ: CF013A #348 I */ /* REQ: CF013A #349 I */ /* REQ: CF013A #174 I */ /* REQ: CF013A #162 I */ /* REQ: CF013A #404 I */
    {
        AbsltHandwheelVelocity_HwRadpS_T_f32 = Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32);

        /* KeepCalculating */
        /* REQ: CF013A #154 I */ /* REQ: CF013A #155 I */ /* REQ: CF013A #156 I */
        if ((HOWState_Cnt_T_s08 <= k_PsaSH_LxaDrvrIntvDetnThd_Uls_s08) || (LxaInpVld_Cnt_T_lgc == D_FALSE_CNT_LGC))
        {
            *DrvrIntvDetd_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }
        else
        {
            *DrvrIntvDetd_Cnt_T_lgc = D_TRUE_CNT_LGC;
        }
        /* ENDREQ: CF013A #154 I */ /* ENDREQ: CF013A #155 I */ /* ENDREQ: CF013A #156 I */

        /* Compute_LxaInactivOnDrvrBhvr */
        ComputeLxaInactivOnDrvrBhvr(
                LxaInpVld_Cnt_T_lgc,
                *DrvrIntvDetd_Cnt_T_lgc,
                HwTqFild_HwNm_T_f32,
                AbsltHandwheelVelocity_HwRadpS_T_f32,
                LxaHwVelThd_HwRadpS_T_f32,
                LxaHwVelDetnCntrNStep_Cnt_T_u16,
                LxaHwVelDetnCntrPStep_Cnt_T_u16,
                AbsltHwPosn_HwDeg_T_f32,
                LxaHwAgThd_HwDeg_T_f32,
                LxaHwAgDetnCntrNStep_Cnt_T_u16,
                LxaHwAgDetnCntrPStep_Cnt_T_u16,
                &LxaInactivOnDrvrBhvr_Cnt_T_lgc,
                HwTrqRate_HwNmpS_T_f32,
                &LxaHwAgDetd_Cnt_T_lgc,
                &HwVelDetnCntr_Cnt_T_u16,
                &TempLxaInactivRstTmrDi_Cnt_T_lgc);

        /* Compute_LxaDrvrAbsntDetd */
        ComputeLxaDrvrAbsntDetd(
                *DrvrIntvDetd_Cnt_T_lgc,
                LxaDrvrAbsntDetdTi_Sec_T_f32,
                AbsltHandwheelVelocity_HwRadpS_T_f32,
                LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
                LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
                LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
                HwVelDetnCntr_Cnt_T_u16,
                TempLxaInactivRstTmrDi_Cnt_T_lgc,
                &LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
                &LxaInactivRstTmrDi_Cnt_T_lgc);

        /* Compute_LxaInactivRstTmr */
        ComputeLxaInactivRstTmr(
                LxaInactivOnDrvrBhvr_Cnt_T_lgc,
                LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
                LxaHwAgDetd_Cnt_T_lgc,
                LpaSeld_Cnt_T_lgc,
                LxaState_Cnt_T_enum,
                LxaInactivRstTmrDi_Cnt_T_lgc,
                VehicleSpeed_Kph_T_u9p7);
    }
    else
    {
        /* FixdValues */
        PrevLxaDrvrAbsntDetd_Cnt_M_lgc      = D_FALSE_CNT_LGC;
        PrevLxaDrvrAbsntWarn_Cnt_M_lgc      = D_FALSE_CNT_LGC;
        *DrvrIntvDetd_Cnt_T_lgc             = D_FALSE_CNT_LGC;
        PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc  = D_FALSE_CNT_LGC;
        PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc = D_FALSE_CNT_LGC;
        PrevLxaHwAgDetd_Cnt_M_lgc           = D_FALSE_CNT_LGC;
        *HwTrqRate_HwNmpS_T_f32             = D_ZERO_HWNMPS_F32;
    }
    /* ENDREQ: CF013A #344 I */ /* ENDREQ: CF013A #345 I */ /* ENDREQ: CF013A #153 I */ /* ENDREQ: CF013A #346 I */ /* ENDREQ: CF013A #347 I */ /* ENDREQ: CF013A #348 I */ /* ENDREQ: CF013A #349 I */
}

/**********************************************************************************************************************
 * Name:        ComputeLxaHwAgThd
 * Description: Implementation of "Compute_LxaHwAgThd" block in the FDD.
 * Inputs:      VehicleSpeed_Kph_T_u9p7
 *              AbsltHwPosn_HwDeg_T_f32
 * Outputs:     LxaHwAgDetnCntrNStep_Cnt_T_u16
 *              PsaSH_LxaHwAgDetnCntrNStep_Cnt_D_u16
 *              LxaHwAgDetnCntrPStep_Cnt_T_u16
 *              PsaSH_LxaHwAgDetnCntrPStep_Cnt_D_u16
 *              LxaHwAgThd_HwDeg_T_f32
 *              PsaSH_LxaHwAgThd_HwDeg_D_f32
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaHwAgThd(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32)
{
    VAR(uint16, AUTOMATIC) AbsHwPos_HwDeg_T_u11p5;
    VAR(uint16, AUTOMATIC) LxaHwAgThd_HwDeg_T_u16p0;

    LxaHwAgThd_HwDeg_T_u16p0 = IntplVarXY_u16_u16Xu16Y_Cnt(
            t_PsaSH_LxaHwAgThdX_Kph_u9p7,
            t_PsaSH_LxaHwAgThdY_HwDeg_u16,
            TableSize_m(t_PsaSH_LxaHwAgThdX_Kph_u9p7),
            VehicleSpeed_Kph_T_u9p7);
    *LxaHwAgThd_HwDeg_T_f32 = FPM_FixedToFloat_m(LxaHwAgThd_HwDeg_T_u16p0, u16p0_T);
    PsaSH_LxaHwAgThd_HwDeg_D_f32 = *LxaHwAgThd_HwDeg_T_f32;                     /* REQ: CF013A #105 I */

    AbsHwPos_HwDeg_T_u11p5 = FPM_FloatToFixed_m(AbsltHwPosn_HwDeg_T_f32, u11p5_T);

    /* PRQA S 310 BilnrIntpl */
    *LxaHwAgDetnCntrNStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwPos_HwDeg_T_u11p5,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwAgDetnCntrNStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5[0]));
    PsaSH_LxaHwAgDetnCntrNStep_Cnt_D_u16 = *LxaHwAgDetnCntrNStep_Cnt_T_u16;     /* REQ: CF013A #106 I */

    *LxaHwAgDetnCntrPStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwPos_HwDeg_T_u11p5,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwAgDetnCntrPStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaHwAgDetnCntrStepX_HwDeg_u11p5[0]));
    PsaSH_LxaHwAgDetnCntrPStep_Cnt_D_u16 = *LxaHwAgDetnCntrPStep_Cnt_T_u16;     /* REQ: CF013A #122 I */
    /*PRQA L:BilnrIntpl */
}

/**********************************************************************************************************************
 * Name:        ComputeLxaHwVelThd
 * Description: Implementation of "Compute_LxaHwVelThd" block in the FDD.
 * Inputs:      VehicleSpeed_Kph_T_u9p7
 *              HandwheelVelocity_HwRadpS_T_f32
 *              HwTqFild_HwNm_T_f32
 * Outputs:     LxaHwVelDetnCntrNStep_Cnt_T_u16
 *              PsaSH_LxaHwVelDetnCntrNStep_Cnt_D_u16
 *              LxaHwVelDetnCntrPStep_Cnt_T_u16
 *              PsaSH_LxaHwVelDetnCntrPStep_Cnt_D_u16
 *              LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16
 *              PsaSH_LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_D_u16
 *              LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16
 *              PsaSH_LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_D_u16
 *              LxaDrvrAbsntHwVelThd_HwRadpS_T_f32
 *              PsaSH_LxaDrvrAbsntHwVelThd_HwRadpS_D_f32
 *              LxaHwVelThd_HwRadpS_T_f32
 *              PsaSH_LxaHwVelThd_HwRadpS_D_f32
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaHwVelThd(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32)
{
    VAR(uint16, AUTOMATIC) LxaHwVelThd_HwRadpS_T_u7p9;
    VAR(uint16, AUTOMATIC) AbsHwVel_HwRadpS_T_u5p11;
    VAR(uint16, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_u7p9;

    /*PRQA S 310 BilnrIntpl2 */
    LxaHwVelThd_HwRadpS_T_u7p9 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            FPM_FloatToFixed_m(Abs_f32_m(HwTqFild_HwNm_T_f32), u15p1_T),
            VehicleSpeed_Kph_T_u9p7,
            t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11,
            TableSize_m(t_PsaSH_LxaHwTqBndTbl_HwNm_u5p11),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelThdX_Kph_u9p7,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelThdY_HwRadpS_u7p9,
            TableSize_m(t2_PsaSH_LxaHwVelThdX_Kph_u9p7[0]));
    *LxaHwVelThd_HwRadpS_T_f32 = FPM_FixedToFloat_m(LxaHwVelThd_HwRadpS_T_u7p9, u7p9_T);
    PsaSH_LxaHwVelThd_HwRadpS_D_f32 = *LxaHwVelThd_HwRadpS_T_f32;                                   /* REQ: CF013A #123 I */

    AbsHwVel_HwRadpS_T_u5p11 = FPM_FloatToFixed_m(Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32), u5p11_T);

    *LxaHwVelDetnCntrNStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwVel_HwRadpS_T_u5p11,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelDetnCntrNStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11[0]));
    PsaSH_LxaHwVelDetnCntrNStep_Cnt_D_u16 = *LxaHwVelDetnCntrNStep_Cnt_T_u16;                       /* REQ: CF013A #124 I */

    *LxaHwVelDetnCntrPStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwVel_HwRadpS_T_u5p11,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaHwVelDetnCntrPStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaHwVelDetnCntrStepX_HwRadpS_u5p11[0]));
    PsaSH_LxaHwVelDetnCntrPStep_Cnt_D_u16 = *LxaHwVelDetnCntrPStep_Cnt_T_u16;                       /* REQ: CF013A #125 I */

    LxaDrvrAbsntHwVelThd_HwRadpS_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt(
            t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7,
            t_PsaSH_LxaDrvrAbsntHwVelThdY_HwRadpS_u7p9,
            TableSize_m(t_PsaSH_LxaDrvrAbsntHwVelThdX_Kph_u9p7),
            VehicleSpeed_Kph_T_u9p7);
    *LxaDrvrAbsntHwVelThd_HwRadpS_T_f32 = FPM_FixedToFloat_m(LxaDrvrAbsntHwVelThd_HwRadpS_T_u7p9, u7p9_T);
    PsaSH_LxaDrvrAbsntHwVelThd_HwRadpS_D_f32 = *LxaDrvrAbsntHwVelThd_HwRadpS_T_f32;                 /* REQ: CF013A #126 I */

    *LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwVel_HwRadpS_T_u5p11,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrNStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11[0]));
    PsaSH_LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_D_u16 = *LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16;     /* REQ: CF013A #127 I */

    *LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            AbsHwVel_HwRadpS_T_u5p11,
            t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaSH_LxaVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrPStepY_Cnt_u16,
            TableSize_m(t2_PsaSH_LxaDrvrAbsntHwVelDetnCntrStepX_HwRadpS_u5p11[0]));
    PsaSH_LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_D_u16 = *LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16;     /* REQ: CF013A #128 I */

    /*PRQA L:BilnrIntpl2 */
}

/**********************************************************************************************************************
 * Name:        ComputeLxaHowDetnTime
 * Description: Implementation of "Compute_LxaHowDetnTime" block in the FDD.
 * Inputs:      VehicleSpeed_Kph_T_u9p7
 *              LpaSeld_Cnt_T_lgc
 * Outputs:     LxaDrvrAbsntDetdTi_Sec_T_f32
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(float32, RTE_AP_PSASH_APPL_CODE) ComputeLxaHowDetnTime(
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc)
{
    VAR(uint16,  AUTOMATIC) LxaDrvrAbsntDetdTi_Sec_T_u9p7;
    VAR(float32, AUTOMATIC) LxaDrvrAbsntDetdTi_Sec_T_f32;

    if (LpaSeld_Cnt_T_lgc != D_FALSE_CNT_LGC)
    {
        LxaDrvrAbsntDetdTi_Sec_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(
                t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7,
                t_PsaSH_LxaDrvrAbsntDetnTiY_Sec_u9p7,
                TableSize_m(t_PsaSH_LxaDrvrAbsntDetnTiX_Kph_u9p7),
                VehicleSpeed_Kph_T_u9p7);

        LxaDrvrAbsntDetdTi_Sec_T_f32 = FPM_FixedToFloat_m(LxaDrvrAbsntDetdTi_Sec_T_u9p7, u9p7_T);   /* REQ: CF013A #140 I */
    }
    else
    {
        LxaDrvrAbsntDetdTi_Sec_T_f32 = k_PsaSH_LxaDrvrAbsntDetnTi_Sec_f32;                          /* REQ: CF013A #118 I */
    }

    return LxaDrvrAbsntDetdTi_Sec_T_f32;
}

/**********************************************************************************************************************
 * Name:        ComputeLxaInactivOnDrvrBhvr
 * Description: Implementation of "Compute_LxaInactivOnDrvrBhvr" state flow in the FDD.
 * Inputs:      LxaInpVld_Cnt_T_lgc
 *              DrvrIntvDetd_Cnt_T_lgc
 *              HwTqFild_HwNm_T_f32
 *              AbsltHandwheelVelocity_HwRadpS_T_f32
 *              LxaHwVelThd_HwRadpS_T_f32
 *              LxaHwVelDetnCntrNStep_Cnt_T_u16
 *              LxaHwVelDetnCntrPStep_Cnt_T_u16
 *              AbsltHwPosn_HwDeg_T_f32
 *              LxaHwAgThd_HwDeg_T_f32
 *              LxaHwAgDetnCntrNStep_Cnt_T_u16
 *              LxaHwAgDetnCntrPStep_Cnt_T_u16
 *              PrevHwVelDetnCntr_Cnt_M_u16
 *              PrevLxaHwAgDetd_Cnt_M_lgc
 *              PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc
 * Outputs:     LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              HwTrqRate_HwNmpS_T_f32
 *              LxaHwAgDetd_Cnt_T_lgc
 *              HwVelDetnCntr_Cnt_T_u16
 *              TempLxaInactivRstTmrDi_Cnt_T_lgc
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaInactivOnDrvrBhvr(
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc)
{
    /* REQ: CF013A #157 I */
    *TempLxaInactivRstTmrDi_Cnt_T_lgc = D_FALSE_CNT_LGC;
    *HwVelDetnCntr_Cnt_T_u16          = PrevHwVelDetnCntr_Cnt_M_u16;
    *LxaHwAgDetd_Cnt_T_lgc            = PrevLxaHwAgDetd_Cnt_M_lgc;
    *LxaInactivOnDrvrBhvr_Cnt_T_lgc   = PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc;
    /* ENDREQ: CF013A #157 I */

    if (D_FALSE_CNT_LGC == LxaInpVld_Cnt_T_lgc)
    {
        *LxaInactivOnDrvrBhvr_Cnt_T_lgc = D_FALSE_CNT_LGC;  /* REQ: CF013A #356 I */ /* REQ: CF013A #175 I */ /* REQ: CF013A #357 I */
    }
    else
    {
        /* REQ: CF013A #358 I */
        /* LxaHwAgMon */
        LxaHwAgMon(
                AbsltHwPosn_HwDeg_T_f32,
                LxaHwAgThd_HwDeg_T_f32,
                LxaHwAgDetnCntrNStep_Cnt_T_u16,
                LxaHwAgDetnCntrPStep_Cnt_T_u16,
                LxaHwAgDetd_Cnt_T_lgc,
                TempLxaInactivRstTmrDi_Cnt_T_lgc);

        if (D_TRUE_CNT_LGC == DrvrIntvDetd_Cnt_T_lgc)
        {
            /* LxaHwTrqMon */
            LxaHwTrqMon(
                    HwTqFild_HwNm_T_f32,
                    LxaInactivOnDrvrBhvr_Cnt_T_lgc,
                    HwTrqRate_HwNmpS_T_f32,
                    TempLxaInactivRstTmrDi_Cnt_T_lgc);

            /* LxaHwVelMon */
            LxaHwVelMon(
                    AbsltHandwheelVelocity_HwRadpS_T_f32,
                    LxaHwVelThd_HwRadpS_T_f32,
                    LxaHwVelDetnCntrNStep_Cnt_T_u16,
                    LxaHwVelDetnCntrPStep_Cnt_T_u16,
                    LxaInactivOnDrvrBhvr_Cnt_T_lgc,
                    HwVelDetnCntr_Cnt_T_u16,
                    TempLxaInactivRstTmrDi_Cnt_T_lgc);
        }
        /* ENDREQ: CF013A #358 I */
    }
}

/**********************************************************************************************************************
 * Name:        LxaHwAgMon
 * Description: Implementation of "LxaHwAgMon" state flow in the FDD.
 * Inputs:      AbsltHwPosn_HwDeg_T_f32
 *              LxaHwAgThd_HwDeg_T_f32
 *              LxaHwAgDetnCntrNStep_Cnt_T_u16
 *              LxaHwAgDetnCntrPStep_Cnt_T_u16
 * Outputs:     LxaHwAgDetd_Cnt_T_lgc
 *              TempLxaInactivRstTmrDi_Cnt_T_lgc
 * Usage Notes: Called by ComputeLxaInactivOnDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwAgMon(
        VAR(float32, AUTOMATIC) AbsltHwPosn_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) LxaHwAgThd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwAgDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc)
{
    /* Lxa will be disabled if handwheel angle exceeds a certain threshold for a certain time */
    if (AbsltHwPosn_HwDeg_T_f32 >= LxaHwAgThd_HwDeg_T_f32)
    {
        if ((k_PsaSH_LxaHwAgDetnCnt_Cnt_u16 <= PsaSH_HwAgDetnCntr_Cnt_M_u16) ||
            (D_TRUE_CNT_LGC == PrevLxaHwAgDetd_Cnt_M_lgc))
        {
            /* REQ: CF013A #195 I */ /* REQ: CF013A #371 I */ /* REQ: CF013A #370 I */ /* REQ: CF013A #372 I */ /* REQ: CF013A #196 I */ /* REQ: CF013A #197 I */
            *LxaHwAgDetd_Cnt_T_lgc            = D_TRUE_CNT_LGC;
            PsaSH_HwAgDetnCntr_Cnt_M_u16      = D_ZERO_CNT_U16;
            *TempLxaInactivRstTmrDi_Cnt_T_lgc = D_TRUE_CNT_LGC;
            /* ENDREQ: CF013A #195 I */ /* ENDREQ: CF013A #371 I */ /* ENDREQ: CF013A #370 I */ /* ENDREQ: CF013A #372 I */ /* ENDREQ: CF013A #196 I */ /* ENDREQ: CF013A #197 I */
        }
        else
        {
            /* REQ: CF013A #365 I */ /* REQ: CF013A #389 I */
            if (LxaHwAgDetnCntrPStep_Cnt_T_u16 <= (D_U16MAX_CNT_U16 - PsaSH_HwAgDetnCntr_Cnt_M_u16))
            {
                PsaSH_HwAgDetnCntr_Cnt_M_u16 += LxaHwAgDetnCntrPStep_Cnt_T_u16;
            }
            else
            {
                PsaSH_HwAgDetnCntr_Cnt_M_u16 = k_PsaSH_LxaHwAgDetnCnt_Cnt_u16;
            }
            /* ENDREQ: CF013A #365 I */ /* ENDREQ: CF013A #389 I */
        }
    }
    else
    {
        /* REQ: CF013A #366 I */ /* REQ: CF013A #390 I */
        if (LxaHwAgDetnCntrNStep_Cnt_T_u16 < PsaSH_HwAgDetnCntr_Cnt_M_u16)
        {
            PsaSH_HwAgDetnCntr_Cnt_M_u16 -= LxaHwAgDetnCntrNStep_Cnt_T_u16;
        }
        else
        {
            PsaSH_HwAgDetnCntr_Cnt_M_u16 = D_ZERO_CNT_U16;
        }
        /* ENDREQ: CF013A #366 I */ /* ENDREQ: CF013A #390 I */
    }
}

/**********************************************************************************************************************
 * Name:        LxaHwTrqMon
 * Description: Implementation of "LxaHwTrqMon" state flow in the FDD.
 * Inputs:      HwTqFild_HwNm_T_f32
 *              LxaInactivOnDrvrBhvr_Cnt_T_lgc
 * Outputs:     LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              HwTrqRate_HwNmpS_T_f32
 *              TempLxaInactivRstTmrDi_Cnt_T_lgc
 * Usage Notes: Called by ComputeLxaInactivOnDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwTrqMon(
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqRate_HwNmpS_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc)
{
    /* Lxa will be disabled if hand wheel torque exceeds a certain threshold for a certain time */
    if (Abs_f32_m(HwTqFild_HwNm_T_f32) >= k_PsaSH_LxaMaxHwTrq_HwNm_f32)
    {
        if ((k_PsaSH_LxaHwTrqDetnTi_Sec_f32 <= PsaSH_HwTrqDetnTmr_Sec_M_f32) ||
            (D_TRUE_CNT_LGC == *LxaInactivOnDrvrBhvr_Cnt_T_lgc))
        {
            /* REQ: CF013A #375 I */ /* REQ: CF013A #376 I */ /* REQ: CF013A #377 I */
            *LxaInactivOnDrvrBhvr_Cnt_T_lgc   = D_TRUE_CNT_LGC;
            PsaSH_HwTrqDetnTmr_Sec_M_f32      = D_ZERO_ULS_F32;
            *TempLxaInactivRstTmrDi_Cnt_T_lgc = D_TRUE_CNT_LGC;
            /* ENDREQ: CF013A #375 I */ /* ENDREQ: CF013A #376 I */ /* ENDREQ: CF013A #377 I */
        }
        else
        {
            PsaSH_HwTrqDetnTmr_Sec_M_f32 += D_2MS_SEC_F32;  /* REQ: CF013A #184 I */ /* REQ: CF013A #374 I */ /* REQ: CF013A #373 I */
        }
    }
    else
    {
        PsaSH_HwTrqDetnTmr_Sec_M_f32 = D_ZERO_ULS_F32;      /* REQ: CF013A #378 I */
    }
    /* REQ: CF013A #416 I */
    PsaSH_HwTrqBuf_HwNm_M_f32[PsaSH_HwTrqBufPtr_Cnt_M_u08] = HwTqFild_HwNm_T_f32;
    PsaSH_HwTrqBufPtr_Cnt_M_u08 += D_ONE_CNT_U8;
    /* ENDREQ: CF013A #416 I */

    /* REQ: CF013A #379 I */ /* REQ: CF013A #380 I */
    if (D_HWTRQBUFSIZE_ULS_U08 <= PsaSH_HwTrqBufPtr_Cnt_M_u08)
    {
        PsaSH_HwTrqBufPtr_Cnt_M_u08 = D_ZERO_CNT_U8;
        PsaSH_HwTrqBufFilled_Cnt_M_lgc = D_TRUE_CNT_LGC;
    }
    /* ENDREQ: CF013A #379 I */ /* ENDREQ: CF013A #380 I */


    if (D_TRUE_CNT_LGC == PsaSH_HwTrqBufFilled_Cnt_M_lgc)
    {
        *HwTrqRate_HwNmpS_T_f32 = Abs_f32_m((HwTqFild_HwNm_T_f32 - PsaSH_HwTrqBuf_HwNm_M_f32[PsaSH_HwTrqBufPtr_Cnt_M_u08]) * k_PsaSH_LxaHwTrqRateTi_Hz_f32);  /* REQ: CF013A #381 I */ /* PRQA S 2842 */

        if (k_PsaSH_LxaHwTrqRateThd_HwNmpS_f32 < *HwTrqRate_HwNmpS_T_f32)
        {
            /* REQ: CF013A #187 I */ /* REQ: CF013A #383 I */ /* REQ: CF013A #382 I */ /* REQ: CF013A #191 I */ /* REQ: CF013A #192 I */ /* REQ: CF013A #384 I */
            if ((k_PsaSH_LxaHwTrqRateDetnTi_Sec_f32 <= PsaSH_HwTrqRateDetnTmr_Sec_M_f32) ||
                (D_TRUE_CNT_LGC == *LxaInactivOnDrvrBhvr_Cnt_T_lgc))
            {
                *LxaInactivOnDrvrBhvr_Cnt_T_lgc   = D_TRUE_CNT_LGC;
                PsaSH_HwTrqRateDetnTmr_Sec_M_f32  = D_ZERO_ULS_F32;
                *TempLxaInactivRstTmrDi_Cnt_T_lgc = D_TRUE_CNT_LGC;
            }
            else
            {
                PsaSH_HwTrqRateDetnTmr_Sec_M_f32 += D_2MS_SEC_F32;
            }
            /* ENDREQ: CF013A #187 I */ /* ENDREQ: CF013A #383 I */ /* ENDREQ: CF013A #382 I */ /* ENDREQ: CF013A #191 I */ /* ENDREQ: CF013A #192 I */ /* ENDREQ: CF013A #384 I */
        }
        else
        {
            /* REQ: CF013A #385 I */ /* REQ: CF013A #386 I */
            if (D_2MS_SEC_F32 < PsaSH_HwTrqRateDetnTmr_Sec_M_f32)
            {
                PsaSH_HwTrqRateDetnTmr_Sec_M_f32 -= D_2MS_SEC_F32;
            }
            else
            {
                PsaSH_HwTrqRateDetnTmr_Sec_M_f32 = D_ZERO_SEC_F32;
            }
            /* ENDREQ: CF013A #385 I */ /* ENDREQ: CF013A #386 I */
        }
    }
}

/**********************************************************************************************************************
 * Name:        LxaHwVelMon
 * Description: Implementation of "LxaHwVelMon" state flow in the FDD.
 * Inputs:      LxaHwVelThd_HwRadpS_T_f32
 *              LxaHwVelDetnCntrNStep_Cnt_T_u16
 *              LxaHwVelDetnCntrPStep_Cnt_T_u16
 *              LxaInactivOnDrvrBhvr_Cnt_T_lgc
 * Outputs:     LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              HwVelDetnCntr_Cnt_T_u16
 *              TempLxaInactivRstTmrDi_Cnt_T_lgc
 * Usage Notes: Called by ComputeLxaInactivOnDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) LxaHwVelMon(
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaHwVelDetnCntrPStep_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        P2VAR(uint16,  AUTOMATIC, AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc)
{
    /* Lxa will be disabled if hand wheel velocity exceeds a certain threshold for a certain time  */
    if (LxaHwVelThd_HwRadpS_T_f32 <= AbsltHandwheelVelocity_HwRadpS_T_f32)
    {
        if ((k_PsaSH_LxaHwVelDetnCnt_Cnt_u16 <= PrevHwVelDetnCntr_Cnt_M_u16) ||
            (D_TRUE_CNT_LGC == *LxaInactivOnDrvrBhvr_Cnt_T_lgc))
        {
            /* REQ: CF013A #181 I */ /* REQ: CF013A #369 I */ /* REQ: CF013A #368 I */ /* REQ: CF013A #367 I */ /* REQ: CF013A #193 I */ /* REQ: CF013A #194 I */
            *LxaInactivOnDrvrBhvr_Cnt_T_lgc   = D_TRUE_CNT_LGC;
            *HwVelDetnCntr_Cnt_T_u16          = D_ZERO_CNT_U16;
            *TempLxaInactivRstTmrDi_Cnt_T_lgc = D_TRUE_CNT_LGC;
            /* ENDREQ: CF013A #181 I */ /* ENDREQ: CF013A #369 I */ /* ENDREQ: CF013A #368 I */ /* ENDREQ: CF013A #367 I */ /* ENDREQ: CF013A #193 I */ /* ENDREQ: CF013A #194 I */
        }
        else
        {
            /* REQ: CF013A #363 I */ /* REQ: CF013A #387 I */
            if (LxaHwVelDetnCntrPStep_Cnt_T_u16 <= (D_U16MAX_CNT_U16 - PrevHwVelDetnCntr_Cnt_M_u16))
            {
                *HwVelDetnCntr_Cnt_T_u16 = PrevHwVelDetnCntr_Cnt_M_u16 + LxaHwVelDetnCntrPStep_Cnt_T_u16;
            }
            else
            {
                *HwVelDetnCntr_Cnt_T_u16 = k_PsaSH_LxaHwVelDetnCnt_Cnt_u16;
            }
            /* ENDREQ: CF013A #363 I */ /* ENDREQ: CF013A #387 I */
        }
    }
    else
    {
        /* REQ: CF013A #364 I */ /* REQ: CF013A #388 I */
        if (LxaHwVelDetnCntrNStep_Cnt_T_u16 < PrevHwVelDetnCntr_Cnt_M_u16)
        {
            *HwVelDetnCntr_Cnt_T_u16 = PrevHwVelDetnCntr_Cnt_M_u16 - LxaHwVelDetnCntrNStep_Cnt_T_u16;
        }
        else
        {
            *HwVelDetnCntr_Cnt_T_u16 = D_ZERO_CNT_U16;
        }
        /* ENDREQ: CF013A #364 I */ /* ENDREQ: CF013A #388 I */
    }
}

/**********************************************************************************************************************
 * Name:        ComputeLxaDrvrAbsntDetd
 * Description: Implementation of "Compute_LxaDrvrAbsntDetd" state flow in the FDD.
 * Inputs:      DrvrIntvDetd_Cnt_T_lgc
 *              LxaDrvrAbsntDetdTi_Sec_T_f32
 *              PrevLxaDrvrAbsntWarn_Cnt_M_lgc
 *              AbsltHandwheelVelocity_HwRadpS_T_f32
 *              LxaDrvrAbsntHwVelThd_HwRadpS_T_f32
 *              PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc
 *              LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16
 *              LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16
 *              PrevLxaDrvrAbsntDetd_Cnt_M_lgc
 *              HwVelDetnCntr_Cnt_T_u16
 *              TempLxaInactivRstTmrDi_Cnt_T_lgc
 * Outputs:     PrevLxaDrvrAbsntWarn_Cnt_M_lgc
 *              PrevLxaDrvrAbsntDetd_Cnt_M_lgc
 *              LxaDrvrAbsntHwVelDetd_Cnt_T_lgc
 *              PrevHwVelDetnCntr_Cnt_M_u16
 *              LxaInactivRstTmrDi_Cnt_T_lgc
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaDrvrAbsntDetd(
        VAR(boolean, AUTOMATIC) DrvrIntvDetd_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) LxaDrvrAbsntDetdTi_Sec_T_f32,
        VAR(float32, AUTOMATIC) AbsltHandwheelVelocity_HwRadpS_T_f32,
        VAR(float32, AUTOMATIC) LxaDrvrAbsntHwVelThd_HwRadpS_T_f32,
        VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16,
        VAR(uint16,  AUTOMATIC) HwVelDetnCntr_Cnt_T_u16,
        VAR(boolean, AUTOMATIC) TempLxaInactivRstTmrDi_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) LxaInactivRstTmrDi_Cnt_T_lgc)
{
    *LxaDrvrAbsntHwVelDetd_Cnt_T_lgc = PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc;
    *LxaInactivRstTmrDi_Cnt_T_lgc    = TempLxaInactivRstTmrDi_Cnt_T_lgc;

    if (D_FALSE_CNT_LGC == DrvrIntvDetd_Cnt_T_lgc)
    {
        /* REQ: CF013A #202 I */ /* REQ: CF013A #203 I */ /* REQ: CF013A #204 I */
        if (D_2MS_SEC_F32 < PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32)
        {
            PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32 -= D_2MS_SEC_F32;
        }
        else
        {
            PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32 = D_ZERO_ULS_F32;
        }

        if (D_ZERO_ULS_F32 >= PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32)
        {
            if (D_FALSE_CNT_LGC == PrevLxaDrvrAbsntWarn_Cnt_M_lgc)
            {
                PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32 = k_PsaSH_LxaDrvrIntvtWarnTi_Sec_f32;
                PrevLxaDrvrAbsntWarn_Cnt_M_lgc = D_TRUE_CNT_LGC;
            }
            else
            {
                PrevLxaDrvrAbsntDetd_Cnt_M_lgc = D_TRUE_CNT_LGC;
            }
        }
        /* ENDREQ: CF013A #202 I */ /* ENDREQ: CF013A #203 I */ /* ENDREQ: CF013A #204 I */

        /* REQ: CF013A #393 I */
        /* LxaDrvrAbsntHwVelMon */
        /* Lxa will be disabled if hand wheel velocity exceeds a certain threshold for a certain time */
        if (LxaDrvrAbsntHwVelThd_HwRadpS_T_f32 <= AbsltHandwheelVelocity_HwRadpS_T_f32)
        {
            if ((k_PsaSH_LxaHwVelDetnCnt_Cnt_u16 <= HwVelDetnCntr_Cnt_T_u16) ||
                (D_TRUE_CNT_LGC == *LxaDrvrAbsntHwVelDetd_Cnt_T_lgc))
            {
                /* REQ: CF013A #394 I */ /* REQ: CF013A #395 I */ /* REQ: CF013A #396 I */ /* REQ: CF013A #401 I */ /* REQ: CF013A #402 I */ /* REQ: CF013A #403 I */
                *LxaDrvrAbsntHwVelDetd_Cnt_T_lgc = D_TRUE_CNT_LGC;
                PrevHwVelDetnCntr_Cnt_M_u16      = D_ZERO_CNT_U16;
                *LxaInactivRstTmrDi_Cnt_T_lgc    = D_TRUE_CNT_LGC;
                /* ENDREQ: CF013A #394 I */ /* ENDREQ: CF013A #395 I */ /* ENDREQ: CF013A #396 I */ /* ENDREQ: CF013A #401 I */ /* ENDREQ: CF013A #402 I */ /* ENDREQ: CF013A #403 I */
            }
            else
            {
                /* REQ: CF013A #397 I */ /* REQ: CF013A #398 I */
                if (LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16 <= (D_U16MAX_CNT_U16 - HwVelDetnCntr_Cnt_T_u16))
                {
                    PrevHwVelDetnCntr_Cnt_M_u16 += LxaDrvrAbsntHwVelDetnCntrPStep_Cnt_T_u16;
                }
                else
                {
                    PrevHwVelDetnCntr_Cnt_M_u16 = k_PsaSH_LxaHwVelDetnCnt_Cnt_u16;
                }
                /* ENDREQ: CF013A #397 I */ /* ENDREQ: CF013A #398 I */
            }
        }
        else
        {
            /* REQ: CF013A #399 I */ /* REQ: CF013A #400 I */
            if (LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16 < HwVelDetnCntr_Cnt_T_u16)
            {
                PrevHwVelDetnCntr_Cnt_M_u16 -= LxaDrvrAbsntHwVelDetnCntrNStep_Cnt_T_u16;
            }
            else
            {
                PrevHwVelDetnCntr_Cnt_M_u16 = D_ZERO_CNT_U16;
            }
            /* ENDREQ: CF013A #399 I */ /* ENDREQ: CF013A #400 I */
        }
        /* ENDREQ: CF013A #393 I */
    }
    else
    {
        /* REQ: CF013A #198 I */ /* REQ: CF013A #200 I */
        PsaSH_LxaDrvrAbsntDetdTmr_Sec_M_f32 = LxaDrvrAbsntDetdTi_Sec_T_f32;
        PrevHwVelDetnCntr_Cnt_M_u16         = HwVelDetnCntr_Cnt_T_u16;
        PrevLxaDrvrAbsntWarn_Cnt_M_lgc      = D_FALSE_CNT_LGC;
        /* ENDREQ: CF013A #198 I */ /* ENDREQ: CF013A #200 I */

        if (D_TRUE_CNT_LGC == PrevLxaDrvrAbsntDetd_Cnt_M_lgc)
        {
            PrevLxaDrvrAbsntDetd_Cnt_M_lgc = D_FALSE_CNT_LGC; /* REQ: CF013A #391 I */
        }
    }
}

/**********************************************************************************************************************
 * Name:        ComputeLxaInactivRstTmr
 * Description: Implementation of "Compute_LxaInactivRstTmr" block in the FDD.
 * Inputs:      LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              LxaDrvrAbsntHwVelDetd_Cnt_T_lgc
 *              LxaHwAgDetd_Cnt_T_lgc
 *              LpaSeld_Cnt_T_lgc
 *              LxaState_Cnt_T_enum
 *              LxaInactivRstTmrDi_Cnt_T_lgc
 *              PrevLxaInactivRstTmr_Sec_M_f32
 *              VehicleSpeed_Kph_T_u9p7
 * Outputs:     PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc
 *              PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc
 *              PrevLxaHwAgDetd_Cnt_M_lgc
 *              PrevLxaInactivRstTmr_Sec_M_f32
 * Usage Notes: Called by ComputeLxaDrvrBhvr
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeLxaInactivRstTmr(
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaInactivRstTmrDi_Cnt_T_lgc,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7)
{
    VAR(uint16,  AUTOMATIC) LxaInactvRstTmr_Sec_T_u7p9;
    VAR(float32, AUTOMATIC) LxaInactvRstTmr_Sec_T_f32;

    /* REQ: CF013A #169 I */ /* REQ: CF013A #406 I */ /* REQ: CF013A #211 I */ /* REQ: CF013A #407 I */
    /* Time is needed before resetting 'PSASH_LxaInactivOnDrvrBhvr_Cnt_M_lgc' */
    if (((D_TRUE_CNT_LGC == LxaInactivOnDrvrBhvr_Cnt_T_lgc) ||
         (D_TRUE_CNT_LGC == LxaDrvrAbsntHwVelDetd_Cnt_T_lgc) ||
         (D_TRUE_CNT_LGC == LxaHwAgDetd_Cnt_T_lgc)) &&
        (LxaInactivRstTmrDi_Cnt_T_lgc == D_FALSE_CNT_LGC))
    {
        /* KeepChecking */
        LxaInactvRstTmr_Sec_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt(
                       t_PsaSH_LxaInactvRstTmrX_Kph_u9p7,
                       t_PsaSH_LxaInactvRstTmrY_Sec_u7p9,
                       TableSize_m(t_PsaSH_LxaInactvRstTmrX_Kph_u9p7),
                       VehicleSpeed_Kph_T_u9p7);
        LxaInactvRstTmr_Sec_T_f32 = FPM_FixedToFloat_m(LxaInactvRstTmr_Sec_T_u7p9, u7p9_T);

        if ((PrevLxaInactivRstTmr_Sec_M_f32 >= LxaInactvRstTmr_Sec_T_f32) ||
            ((LxaState_Cnt_T_enum == PSALXAST_COLLRISK) && (LpaSeld_Cnt_T_lgc == D_FALSE_CNT_LGC)))
        {
            /* REQ: CF013A #408 I */ /* REQ: CF013A #409 I */ /* REQ: CF013A #410 I */ /* REQ: CF013A #411 I */ /* REQ: CF013A #412 I */ /* REQ: CF013A #413 I */
            /* SetFalseAndZero */
            PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc  = D_FALSE_CNT_LGC;
            PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc = D_FALSE_CNT_LGC;
            PrevLxaHwAgDetd_Cnt_M_lgc           = D_FALSE_CNT_LGC;
            PrevLxaInactivRstTmr_Sec_M_f32      = D_ZERO_SEC_F32;
            /* ENDREQ: CF013A #408 I */ /* ENDREQ: CF013A #409 I */ /* ENDREQ: CF013A #410 I */ /* ENDREQ: CF013A #411 I */ /* ENDREQ: CF013A #412 I */ /* ENDREQ: CF013A #413 I */
        }
        else
        {
            /* IncrTimer */
            PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc  = LxaInactivOnDrvrBhvr_Cnt_T_lgc;
            PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc = LxaDrvrAbsntHwVelDetd_Cnt_T_lgc;
            PrevLxaHwAgDetd_Cnt_M_lgc           = LxaHwAgDetd_Cnt_T_lgc;
            PrevLxaInactivRstTmr_Sec_M_f32     += D_2MS_SEC_F32;
        }
    }
    else
    {
        /* SetZeroAndPassThrough */
        PrevLxaInactivOnDrvrBhvr_Cnt_M_lgc  = LxaInactivOnDrvrBhvr_Cnt_T_lgc;
        PrevLxaDrvrAbsntHwVelDetd_Cnt_M_lgc = LxaDrvrAbsntHwVelDetd_Cnt_T_lgc;
        PrevLxaHwAgDetd_Cnt_M_lgc           = LxaHwAgDetd_Cnt_T_lgc;
        PrevLxaInactivRstTmr_Sec_M_f32      = D_ZERO_SEC_F32;
    }
    /* ENDREQ: CF013A #169 I */ /* ENDREQ: CF013A #406 I */ /* ENDREQ: CF013A #211 I */ /* ENDREQ: CF013A #407 I */
}

/**********************************************************************************************************************
 * Name:        ComputeEPSState
 * Description: Implementation of "Compute_EPSState" block in the FDD.
 * Inputs:      SystemState_Cnt_T_u08
 *              OutputRampMult_Uls_T_f32
 *              FTermActv_Cnt_T_lgc
 * Outputs:     EPSState_Cnt_T_enum
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(PsaEpsSt_Cnt_enum, RTE_AP_PSASH_APPL_CODE) ComputeEPSState(
        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_u08,
        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc)
{
    VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum;

    /* REQ: CF013A #141 I */ /* REQ: CF013A #142 I */ /* REQ: CF013A #143 I */
    if (FTermActv_Cnt_T_lgc == D_TRUE_CNT_LGC)
    {
        /* EPSSTDFCT */
        EPSState_Cnt_T_enum = PSAEPSST_DFCT;
    }
    else
    {
        /* KeepChecking */
        if ((Abs_f32_m(OutputRampMult_Uls_T_f32 - D_ONE_ULS_F32) <= D_FLTEPSILON_ULS_F32) &&
            (SystemState_Cnt_T_u08 == RTE_MODE_StaMd_Mode_OPERATE))
        {
            /* EPSSTAVL */
            EPSState_Cnt_T_enum = PSAEPSST_AVL;
        }
        else
        {
            /* EPSSTUNAVL */
            EPSState_Cnt_T_enum = PSAEPSST_UNAVL;
        }
    }
    /* ENDREQ: CF013A #141 I */ /* ENDREQ: CF013A #142 I */ /* ENDREQ: CF013A #143 I */

    return EPSState_Cnt_T_enum;
}

/**********************************************************************************************************************
 * Name:        ComputeLxaCorrnFacReqLimd
 * Description: Implementation of "Compute_LxaCorrnFacReqLimd" block in the FDD.
 * Inputs:      LxaTqFacReq_Uls_T_f32
 *              LxaInpVld_Cnt_T_lgc
 * Outputs:     LxaCorrnFacReqLimd_Uls_T_f32
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(float32, RTE_AP_PSASH_APPL_CODE) ComputeLxaCorrnFacReqLimd(
        VAR(float32, AUTOMATIC) LxaTqFacReq_Uls_T_f32,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc)
{
    VAR(float32, AUTOMATIC) LxaCorrnFacReqLimd_Uls_T_f32;
    VAR(float32, AUTOMATIC) LxaCorrnFacReq_Uls_T_f32;

    /* Compute_LxaCorrnFacReq */
    if (LxaInpVld_Cnt_T_lgc == D_FALSE_CNT_LGC)
    {
        /* REQ: CF013A #454 I */ /* REQ: CF013A #455 I */ /* REQ: CF013A #456 I */ /* REQ: CF013A #457 I */
        LxaTqFacReqSum_Uls_M_f32     = D_ZERO_ULS_F32;
        LxaTqFacReqPtr_Cnt_M_u08     = D_ZERO_CNT_U08;
        LxaTqFacReqBufFull_Cnt_M_lgc = D_FALSE_CNT_LGC;
        LxaCorrnFacReq_Uls_T_f32     = D_ZERO_ULS_F32;
        /* ENDREQ: CF013A #454 I */ /* ENDREQ: CF013A #455 I */ /* ENDREQ: CF013A #456 I */ /* ENDREQ: CF013A #457 I */
    }
    else
    {
        /* REQ: CF013A #458 I */ /* REQ: CF013A #459 I */
        if (LxaTqFacReqPtr_Cnt_M_u08 >= D_LXATQFACREQBUFSIZE_CNT_U08)
        {
            LxaTqFacReqPtr_Cnt_M_u08     = D_ZERO_CNT_U08;
            LxaTqFacReqBufFull_Cnt_M_lgc = D_TRUE_CNT_LGC;
        }
        /* ENDREQ: CF013A #458 I */ /* ENDREQ: CF013A #459 I */

        if (Abs_f32_m(PrevLxaTqFacReq_Uls_M_f32 - LxaTqFacReq_Uls_T_f32) > D_FLTEPSILON_ULS_F32)
        {
            LxaTqFacReqCntr_Cnt_M_u08 = D_ZERO_CNT_U08;
        }

        /* REQ: CF013A #460 I */  /* REQ: CF013A #462 I */ /* REQ: CF013A #463 I */ /* REQ: CF013A #464 I */
        if (LxaTqFacReqBufFull_Cnt_M_lgc == D_TRUE_CNT_LGC)
        {

            /* REQ: CF013A #488 I */
            if (LxaTqFacReqCntr_Cnt_M_u08 >= D_LXATQFACREQBUFSIZE_CNT_U08)
            {
                LxaCorrnFacReq_Uls_T_f32 = LxaTqFacReq_Uls_T_f32;
                LxaTqFacReqSum_Uls_M_f32 = LxaCorrnFacReq_Uls_T_f32 * D_LXATQFACREQBUFSIZE_ULS_F32;
            }
            else
            {
                LxaTqFacReqSum_Uls_M_f32 += LxaTqFacReq_Uls_T_f32 - LxaTqFacReqBuf_Uls_M_f32[LxaTqFacReqPtr_Cnt_M_u08];
                LxaCorrnFacReq_Uls_T_f32 = LxaTqFacReqSum_Uls_M_f32 * D_LXATQFACREQAVRG_ULS_F32;
            }
            /* ENDREQ: CF013A #488 I */
        }
        else
        {
            LxaCorrnFacReq_Uls_T_f32 = LxaTqFacReq_Uls_T_f32;
            LxaTqFacReqSum_Uls_M_f32 += LxaTqFacReq_Uls_T_f32;
        }
        /* ENDREQ: CF013A #460 I */  /* ENDREQ: CF013A #462 I */ /* ENDREQ: CF013A #463 I */ /* ENDREQ: CF013A #464 I */

        /* REQ: CF013A #465 I */ /* REQ: CF013A #466 I */
        LxaTqFacReqBuf_Uls_M_f32[LxaTqFacReqPtr_Cnt_M_u08] = LxaTqFacReq_Uls_T_f32;
        LxaTqFacReqPtr_Cnt_M_u08                           += D_ONE_CNT_U08;
        /* ENDREQ: CF013A #465 I */ /* ENDREQ: CF013A #466 I */

        /* REQ: CF013A #489 I */
        if ((Abs_f32_m(PrevLxaTqFacReq_Uls_M_f32 - LxaTqFacReq_Uls_T_f32) <= D_FLTEPSILON_ULS_F32)
            && (LxaTqFacReqCntr_Cnt_M_u08 < D_LXATQFACREQBUFSIZE_CNT_U08))
        {
            LxaTqFacReqCntr_Cnt_M_u08 += D_ONE_CNT_U08;
        }
        /* ENDREQ: CF013A #489 I */
    }

    PrevLxaTqFacReq_Uls_M_f32 = LxaTqFacReq_Uls_T_f32;

    PsaSH_LxaCorrnFacReq_Uls_D_f32 = LxaCorrnFacReq_Uls_T_f32;

    /* REQ: CF013A #467 I */
    LxaCorrnFacReqLimd_Uls_M_f32 = Limit_m(LxaCorrnFacReq_Uls_T_f32,
            LxaCorrnFacReqLimd_Uls_M_f32 - (k_PsaSH_LxaCorrnFacReqRate_UlspS_f32 * D_2MS_SEC_F32),
            LxaCorrnFacReqLimd_Uls_M_f32 + (k_PsaSH_LxaCorrnFacReqRate_UlspS_f32 * D_2MS_SEC_F32));
    LxaCorrnFacReqLimd_Uls_T_f32 = LxaCorrnFacReqLimd_Uls_M_f32;
    /* ENDREQ: CF013A #467 I */

    return LxaCorrnFacReqLimd_Uls_T_f32;
}

/**********************************************************************************************************************
 * Name:        ComputeEPSStateForLxa
 * Description: Implementation of "Compute_EPSStateForLxa" state flow in the FDD.
 * Inputs:      EscActv_Cnt_T_lgc
 *              AbsActv_Cnt_T_lgc
 *              EscFltPrsnt_Cnt_T_lgc
 *              EscEna_Cnt_T_lgc
 *              VehSpdCdn_Cnt_T_lgc
 *              LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              LxaDrvrAbsntHwVelDetd_Cnt_T_lgc
 *              EPSState_Cnt_T_enum
 *              LxaState_Cnt_T_enum
 *              PrevLxaApaConflictReqNTC_Cnt_M_lgc
 *              LxaHwAgDetd_Cnt_T_lgc
 *              HwAuthyCdn_Cnt_T_lgc
 *              LxaInpVld_Cnt_T_lgc
 *              LxaDrvrAbsntDetd_Cnt_T_lgc
 *              LxaTqReqFacCdn_Cnt_T_lgc
 *              LxaSelected_Cnt_T_lgc
 * Outputs:     EPSStateForLxa_Cnt_T_enum
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(PsaEpsStLxa_Cnt_enum, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwTqCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaTqReqFacCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) LxaNtcCdn_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NtcQlfr11_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NtcQlfr12_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NtcQlfr13_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NtcQlfr14_Cnt_T_lgc;
    VAR(uint8, AUTOMATIC) PrevEPSStateForLxa_Cnt_T_u08 = PsaSH_EPSStateForLxa_Cnt_M_u08;

    /* REQ: CF013A #468 I */ /* REQ: CF013A #469 I */ /* REQ: CF013A #470 I */ /* REQ: CF013A #471 I */ /* REQ: CF013A #227 I */ /* REQ: CF013A #473 I */ /* REQ: CF013A #472 I */ /* REQ: CF013A #474 I */ /* REQ: CF013A #475 I */
    /* LxaNTCCdn */
    (void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_11, &NtcQlfr11_Cnt_T_lgc);
    (void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_12, &NtcQlfr12_Cnt_T_lgc);
    (void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_13, &NtcQlfr13_Cnt_T_lgc);
    (void) Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_14, &NtcQlfr14_Cnt_T_lgc);

    if ((NtcQlfr11_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
        (NtcQlfr12_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
        (NtcQlfr13_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
        (NtcQlfr14_Cnt_T_lgc == D_FALSE_CNT_LGC))
    {
        LxaNtcCdn_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        LxaNtcCdn_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }
    /* ENDREQ: CF013A #468 I */ /* ENDREQ: CF013A #469 I */ /* ENDREQ: CF013A #470 I */ /* ENDREQ: CF013A #471 I */ /* ENDREQ: CF013A #227 I */ /* ENDREQ: CF013A #473 I */ /* ENDREQ: CF013A #472 I */ /* ENDREQ: CF013A #474 I */ /* ENDREQ: CF013A #475 I */

    /* Parent transitions */
    ComputeEPSStateForLxa_ParentTransitions(
            EscActv_Cnt_T_lgc,
            AbsActv_Cnt_T_lgc,
            EscFltPrsnt_Cnt_T_lgc,
            EscEna_Cnt_T_lgc,
            VehSpdCdn_Cnt_T_lgc,
            LxaInactivOnDrvrBhvr_Cnt_T_lgc,
            LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
            EPSState_Cnt_T_enum,
            LxaState_Cnt_T_enum,
            LxaHwAgDetd_Cnt_T_lgc,
            HwAuthyCdn_Cnt_T_lgc,
            LxaInpVld_Cnt_T_lgc,
            LxaNtcCdn_Cnt_T_lgc);

    /* Child transitions */
    if (PsaSH_EPSStateForLxa_Cnt_M_u08 == PrevEPSStateForLxa_Cnt_T_u08)
    {
        ComputeEPSStateForLxa_ChildTransitions(
                EscActv_Cnt_T_lgc,
                AbsActv_Cnt_T_lgc,
                EscFltPrsnt_Cnt_T_lgc,
                EscEna_Cnt_T_lgc,
                VehSpdCdn_Cnt_T_lgc,
                LxaInactivOnDrvrBhvr_Cnt_T_lgc,
                LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
                EPSState_Cnt_T_enum,
                LxaState_Cnt_T_enum,
                LxaHwAgDetd_Cnt_T_lgc,
                HwAuthyCdn_Cnt_T_lgc,
                LpaSeld_Cnt_T_lgc,
                HwTqCdn_Cnt_T_lgc,
                LxaInpVld_Cnt_T_lgc,
                LxaDrvrAbsntDetd_Cnt_T_lgc,
                LxaTqReqFacCdn_Cnt_T_lgc,
                LxaSelected_Cnt_T_lgc,
                LxaNtcCdn_Cnt_T_lgc);
    }

    /* Entry */
    if (PsaSH_EPSStateForLxa_Cnt_M_u08 != PrevEPSStateForLxa_Cnt_T_u08)
    {
        switch (PsaSH_EPSStateForLxa_Cnt_M_u08)
        {
            case D_LXA_UNAUTHORIZED_CNT_U08: /* REQ: CF013A #221 I */
                PsaSH_EPSStateForLxa_Cnt_M_enum = PSAEPSSTLXA_UNAUTHD;
            break;

            case D_LXA_AVAILABLE_CNT_U08: /* REQ: CF013A #433 I */
                PsaSH_EPSStateForLxa_Cnt_M_enum = PSAEPSSTLXA_AVL;
            break;

            case D_LXA_AUTHORIZED_CNT_U08: /* REQ: CF013A #432 I */
                PsaSH_EPSStateForLxa_Cnt_M_enum = PSAEPSSTLXA_AUTHD;
            break;

            case D_LXA_ACTIVE_CNT_U08: /* REQ: CF013A #431 I */
                PsaSH_EPSStateForLxa_Cnt_M_enum = PSAEPSSTLXA_ACTV;
            break;

            default: /* REQ: CF013A #222 I */
                PsaSH_EPSStateForLxa_Cnt_M_enum = PSAEPSSTLXA_DFCT;
            break;
        }
    }

    return PsaSH_EPSStateForLxa_Cnt_M_enum;
}

/**********************************************************************************************************************
 * Name:        ComputeEPSStateForLxa_ParentTransitions
 * Description: Fragment of implementation of "Compute_EPSStateForLxa" state flow.
 * Inputs:      EscActv_Cnt_T_lgc
                AbsActv_Cnt_T_lgc
                EscFltPrsnt_Cnt_T_lgc
                EscEna_Cnt_T_lgc
                VehSpdCdn_Cnt_T_lgc
                LxaInactivOnDrvrBhvr_Cnt_T_lgc
                LxaDrvrAbsntHwVelDetd_Cnt_T_lgc
                EPSState_Cnt_T_enum
                LxaState_Cnt_T_enum
                PrevLxaApaConflictReqNTC_Cnt_M_lgc
                LxaHwAgDetd_Cnt_T_lgc
                HwAuthyCdn_Cnt_T_lgc
                LxaInpVld_Cnt_T_lgc
                LxaNtcCdn_Cnt_T_lgc
 * Outputs:     None
 * Usage Notes: Called by ComputeEPSStateForLxa
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa_ParentTransitions(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaNtcCdn_Cnt_T_lgc)
{
    switch (PsaSH_EPSStateForLxa_Cnt_M_u08)
    {
        case D_LXA_AVAILABLE_CNT_U08:
        case D_LXA_AUTHORIZED_CNT_U08:
        case D_LXA_ACTIVE_CNT_U08:
            if ((EPSState_Cnt_T_enum == PSAEPSST_DFCT) ||
                (LxaInpVld_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
                (LxaNtcCdn_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_DEFECT_CNT_U08;              /* REQ: CF013A #419 I */ /* REQ: CF013A #235 I */ /* REQ: CF013A #472 I */ /* REQ: CF013A #473 I */ /* REQ: CF013A #474 I */ /* REQ: CF013A #475 I */
            }
            else
            {
                if ((VehSpdCdn_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
                    (EscActv_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (AbsActv_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (EscFltPrsnt_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (EscEna_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
                    (LxaInactivOnDrvrBhvr_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (LxaDrvrAbsntHwVelDetd_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (EPSState_Cnt_T_enum == PSAEPSST_UNAVL) ||
                    (LxaState_Cnt_T_enum == PSALXAST_UNSELD) ||
                    (LxaState_Cnt_T_enum == PSALXAST_DFCT) ||
                    (LxaState_Cnt_T_enum == PSALXAST_UNAVL) ||
                    (PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_TRUE_CNT_LGC) ||
                    (LxaHwAgDetd_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
                    (HwAuthyCdn_Cnt_T_lgc == D_FALSE_CNT_LGC))
                {
                    PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_UNAUTHORIZED_CNT_U08;    /* REQ: CF013A #342 I */ /* REQ: CF013A #219 I */ /* REQ: CF013A #426 I */ /* REQ: CF013A #425 I */ /* REQ: CF013A #424 I */ /* REQ: CF013A #423 I */ /* REQ: CF013A #422 I */ /* REQ: CF013A #421 I */ /* REQ: CF013A #430 I */ /* REQ: CF013A #429 I */ /* REQ: CF013A #428 I */ /* REQ: CF013A #427 I */ /* REQ: CF013A #441 I */ /* REQ: CF013A #440 I */
                }
            }
        break;

        default:
        break;
    }
}

/**********************************************************************************************************************
 * Name:        ComputeEPSStateForLxa_ChildTransitions
 * Description: Fragment of implementation of "Compute_EPSStateForLxa" state flow.
 * Inputs:      EscActv_Cnt_T_lgc
 *              AbsActv_Cnt_T_lgc
 *              EscFltPrsnt_Cnt_T_lgc
 *              EscEna_Cnt_T_lgc
 *              VehSpdCdn_Cnt_T_lgc
 *              LxaInactivOnDrvrBhvr_Cnt_T_lgc
 *              LxaDrvrAbsntHwVelDetd_Cnt_T_lgc
 *              EPSState_Cnt_T_enum
 *              LxaState_Cnt_T_enum
 *              PrevLxaApaConflictReqNTC_Cnt_M_lgc
 *              LxaHwAgDetd_Cnt_T_lgc
 *              HwAuthyCdn_Cnt_T_lgc
 *              LpaSeld_Cnt_T_lgc
 *              HwTqCdn_Cnt_T_lgc
 *              LxaInpVld_Cnt_T_lgc
 *              LxaDrvrAbsntDetd_Cnt_T_lgc
 *              LxaTqReqFacCdn_Cnt_T_lgc
 *              LxaSelected_Cnt_T_lgc
 *              LxaNtcCdn_Cnt_T_lgc
 * Outputs:     None
 * Usage Notes: Called by ComputeEPSStateForLxa
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeEPSStateForLxa_ChildTransitions(
        VAR(boolean, AUTOMATIC) EscActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) AbsActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscFltPrsnt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) EscEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInactivOnDrvrBhvr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntHwVelDetd_Cnt_T_lgc,
        VAR(PsaEpsSt_Cnt_enum, AUTOMATIC) EPSState_Cnt_T_enum,
        VAR(PsaLxaSt_Cnt_enum, AUTOMATIC) LxaState_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) LxaHwAgDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwAuthyCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LpaSeld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HwTqCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaInpVld_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaDrvrAbsntDetd_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaTqReqFacCdn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaSelected_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) LxaNtcCdn_Cnt_T_lgc)
{
    switch (PsaSH_EPSStateForLxa_Cnt_M_u08)
    {
        case D_LXA_UNAUTHORIZED_CNT_U08:
            if ((LxaSelected_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_FALSE_CNT_LGC) &&
                (VehSpdCdn_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (EscActv_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (AbsActv_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (EscFltPrsnt_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (EscEna_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (LxaInactivOnDrvrBhvr_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (LxaDrvrAbsntHwVelDetd_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (EPSState_Cnt_T_enum == PSAEPSST_AVL)&&
                ((LxaState_Cnt_T_enum == PSALXAST_SELD) ||
                 ((LpaSeld_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                  (LxaState_Cnt_T_enum == PSALXAST_COLLRISK))) &&
                (LxaDrvrAbsntDetd_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (LxaInpVld_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (HwTqCdn_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (LxaHwAgDetd_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                (HwAuthyCdn_Cnt_T_lgc == D_TRUE_CNT_LGC))
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_AVAILABLE_CNT_U08;           /* REQ: CF013A #226 I */ /* REQ: CF013A #228 I */
            }
            else
            {
                if ((LxaSelected_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                    ((EPSState_Cnt_T_enum == PSAEPSST_DFCT) ||
                     (LxaInpVld_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
                     (LxaNtcCdn_Cnt_T_lgc == D_FALSE_CNT_LGC)))
                {
                    PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_DEFECT_CNT_U08;          /* REQ: CF013A #229 I */ /* REQ: CF013A #417 I */ /* REQ: CF013A #468 I */ /* REQ: CF013A #469 I */ /* REQ: CF013A #470 I */ /* REQ: CF013A #471 I */
                }
            }
        break;

        case D_LXA_AVAILABLE_CNT_U08:
            if (LxaState_Cnt_T_enum == PSALXAST_AUTHD)
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_AUTHORIZED_CNT_U08;          /* REQ: CF013A #439 I */
            }
        break;

        case D_LXA_AUTHORIZED_CNT_U08:
            if (LxaState_Cnt_T_enum == PSALXAST_SELD)
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_AVAILABLE_CNT_U08;           /* REQ: CF013A #438 I */
            }
            else
            {
                if ((LxaState_Cnt_T_enum == PSALXAST_ACTV) && (LxaTqReqFacCdn_Cnt_T_lgc == D_TRUE_CNT_LGC))
                {
                    PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_ACTIVE_CNT_U08;          /* REQ: CF013A #437 I */ /* REQ: CF013A #436 I */
                }
            }
        break;

        case D_LXA_ACTIVE_CNT_U08:
            if (LxaDrvrAbsntDetd_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_UNAUTHORIZED_CNT_U08;        /* REQ: CF013A #436 I */
            }
            else if ((LxaState_Cnt_T_enum == PSALXAST_AUTHD) && (LxaTqReqFacCdn_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_AUTHORIZED_CNT_U08;          /* REQ: CF013A #435 I */
            }
            else if ((LxaState_Cnt_T_enum == PSALXAST_SELD) && (LxaTqReqFacCdn_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_AVAILABLE_CNT_U08;           /* REQ: CF013A #434 I */
            }
            else
            {
                /* Do nothing */
            }
        break;

        case D_LXA_DEFECT_CNT_U08:
            if ((EPSState_Cnt_T_enum != PSAEPSST_DFCT) &&
                (LxaInpVld_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (LxaNtcCdn_Cnt_T_lgc == D_TRUE_CNT_LGC))
            {
                PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_UNAUTHORIZED_CNT_U08;        /* REQ: CF013A #227 I */
            }
        break;

        default:
            PsaSH_EPSStateForLxa_Cnt_M_u08 = D_LXA_UNAUTHORIZED_CNT_U08;            /* REQ: CF013A #225 I */
        break;
    }
}

/**********************************************************************************************************************
 * Name:        ComputeApa
 * Description: Implementation of "APA" block in the FDD.
 * Inputs:      AssistStallLimit_MtrNm_T_f32
 *              ApaEna_Cnt_T_lgc
 *              ThermLimitPerc_Uls_T_f32
 *              VehicleSpeedValid_Cnt_T_lgc
 *              CpkOk_Cnt_T_lgc
 *              ApaPosSrvoFlt_Cnt_T_lgc
 *              ApaAuthn_Cnt_T_lgc
 *              ApaCmdReq_Cnt_T_lgc
 *              ApaRelaxReq_Cnt_T_lgc
 *              HandwheelAuthority_Uls_T_f32
 *              SystemState_Cnt_T_enum
 *              OutputRampMult_Uls_T_f32
 *              VehicleSpeed_Kph_T_f32
 *              HwTqFild_HwNm_T_f32
 *              HandwheelPosition_HwDeg_T_f32
 *              ApaHwAgCmd_HwDeg_T_f32
 *              PrevApaPosSrvoEna_Cnt_M_lgc
 *              FTermActv_Cnt_T_lgc
 *              PrevLxaApaConflictReqNTC_Cnt_M_lgc
 * Outputs:     ApaState_Cnt_T_enum
 *              ApaStateTransitionCause_Cnt_T_enum
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApa(
        VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) ThermLimitPerc_Uls_T_f32,
        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaPosSrvoFlt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32,
        VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaState_Cnt_T_enum,
        P2VAR(PsaApaTranCause_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaStateTransitionCause_Cnt_T_enum)
{
    VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc;

    /* Compute_ApaAllw */
    ApaAllw_Cnt_T_lgc = ComputeApaAllw(
            ApaAuthn_Cnt_T_lgc,
            HandwheelAuthority_Uls_T_f32,
            SystemState_Cnt_T_enum,
            OutputRampMult_Uls_T_f32 );

    /* Compute_ApaLimits */
    ComputeApaLimits(
            VehicleSpeed_Kph_T_f32,
            ThermLimitPerc_Uls_T_f32,
            AssistStallLimit_MtrNm_T_f32,
            &VehSpdTooHi_Cnt_T_lgc,
            &ThrmlLmtReached_Cnt_T_lgc,
            &MtrStalled_Cnt_T_lgc);

    /* Compute_ApaDrvrIntv */
    ComputeApaDrvrIntv(HwTqFild_HwNm_T_f32, &ApaHwMinTrqReached_Cnt_T_lgc, &ApaHwMaxTrqReached_Cnt_T_lgc);

    /* Compute_ApaHwAgCtrlErr */
    ApaHwAgCtrlErr_Cnt_T_lgc = ComputeApaHwAgCtrlErr(HandwheelPosition_HwDeg_T_f32, ApaHwAgCmd_HwDeg_T_f32);

    /* Compute_ApaFltActv */
    ApaFltActv_Cnt_T_lgc = ComputeApaFltActv(
            VehicleSpeedValid_Cnt_T_lgc,
            CpkOk_Cnt_T_lgc,
            ApaPosSrvoFlt_Cnt_T_lgc,
            FTermActv_Cnt_T_lgc);

    /* Compute_ApaState */
    ComputeApaState(
            ApaAllw_Cnt_T_lgc,
            ApaEna_Cnt_T_lgc,
            VehSpdTooHi_Cnt_T_lgc,
            ThrmlLmtReached_Cnt_T_lgc,
            MtrStalled_Cnt_T_lgc,
            ApaCmdReq_Cnt_T_lgc,
            ApaHwMinTrqReached_Cnt_T_lgc,
            ApaHwMaxTrqReached_Cnt_T_lgc,
            ApaHwAgCtrlErr_Cnt_T_lgc,
            ApaFltActv_Cnt_T_lgc,
            ApaRelaxReq_Cnt_T_lgc,
            ApaState_Cnt_T_enum,
            ApaStateTransitionCause_Cnt_T_enum);
}

/**********************************************************************************************************************
 * Name:        ComputeApaAllw
 * Description: Implementation of "Compute_ApaAllw" block in the FDD.
 * Inputs:      ApaAuthn_Cnt_T_lgc
 *              HandwheelAuthority_Uls_T_f32
 *              OutputRampMult_Uls_T_f32
 * Outputs:     ApaAllw_Cnt_T_lgc
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaAllw(VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
                                                        VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
                                                        VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum,
                                                        VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32)
{
    VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc = D_FALSE_CNT_LGC;

    /* REQ: CF013A #121 I */
    if ((Abs_f32_m(OutputRampMult_Uls_T_f32 - D_ONE_ULS_F32) <= D_FLTEPSILON_ULS_F32) &&
        (ApaAuthn_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
        (HandwheelAuthority_Uls_T_f32 >= k_PsaSH_ApaHwAuthority_Uls_f32) &&
        (SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE))
    {
        ApaAllw_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }

    PsaSH_ApaAllw_Cnt_D_lgc = ApaAllw_Cnt_T_lgc;
    /* ENDREQ: CF013A #121 I */

    return ApaAllw_Cnt_T_lgc;
}

/**********************************************************************************************************************
 * Name:        ComputeApaLimits
 * Description: Implementation of "Compute_ApaLimits" block in the FDD.
 * Inputs:      VehicleSpeed_Kph_T_f32
 *              ThermLimPerc_Uls_T_f32
 *              AssistStallLimit_MtrNm_T_f32
 * Outputs:     VehSpdTooHi_Cnt_T_lgc
 *              PsaSH_VehSpdTooHi_Cnt_D_lgc
 *              ThrmlLmtReached_Cnt_T_lgc
 *              PsaSH_ThrmlLmtReached_Cnt_D_lgc
 *              MtrStalled_Cnt_T_lgc
 *              PsaSH_MtrStalled_Cnt_D_lgc
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaLimits(VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32,
                                                       VAR(float32, AUTOMATIC) ThermLimPerc_Uls_T_f32,
                                                       VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32,
                                                       P2VAR(boolean, AUTOMATIC, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
                                                       P2VAR(boolean, AUTOMATIC, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
                                                       P2VAR(boolean, AUTOMATIC, AUTOMATIC) MtrStalled_Cnt_T_lgc)
{
    /* REQ: CF013A #166 I */
    if (VehicleSpeed_Kph_T_f32 > k_PsaSH_ApaVehSpd_Kph_f32)
    {
        *VehSpdTooHi_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        *VehSpdTooHi_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }
    PsaSH_VehSpdTooHi_Cnt_D_lgc = *VehSpdTooHi_Cnt_T_lgc;
    /* ENDREQ: CF013A #166 I */

    /* REQ: CF013A #242 I */
    if (ThermLimPerc_Uls_T_f32 >= k_PsaSH_ApaThemLimPerc_Uls_f32)
    {
        *ThrmlLmtReached_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        *ThrmlLmtReached_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }
    PsaSH_ThrmlLmtReached_Cnt_D_lgc = *ThrmlLmtReached_Cnt_T_lgc;
    /* ENDREQ: CF013A #242 I */

    /* REQ: CF013A #243 I */
    if (AssistStallLimit_MtrNm_T_f32 <= k_PsaSH_ApaAssiStallLim_MtrNm_f32)
    {
        *MtrStalled_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        *MtrStalled_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }
    PsaSH_MtrStalled_Cnt_D_lgc = *MtrStalled_Cnt_T_lgc;
    /* ENDREQ: CF013A #243 I */
}

/**********************************************************************************************************************
 * Name:        ComputeApaDrvrIntv
 * Description: Implementation of "Compute_ApaDrvrIntv" block in the FDD.
 * Inputs:      HwTqFild_HwNm_T_f32
 * Outputs:     ApaHwMinTrqReached_Cnt_T_lgc
 *              ApaHwMaxTrqReached_Cnt_T_lgc
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaDrvrIntv(
        VAR(float32, AUTOMATIC) HwTqFild_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc)
{
    VAR(uint32, AUTOMATIC) HwTrqFiltTimer1Elapsed_mS_T_u32 = 0U;
    VAR(uint32, AUTOMATIC) HwTrqFiltTimer2Elapsed_mS_T_u32 = 0U;

    /* REQ: CF013A #111 I */
    if (Abs_f32_m(HwTqFild_HwNm_T_f32) > k_PsaSH_ApaHwTrqMin_HwNm_f32)                                                  /* If filtered HWTrq > k_PsaSH_ApaHwTrqMin_HwNm_f32, start measuring time */
    {
        /* ElapsedTime1 */
        (void) Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(MinTqTimer_mS_M_u32, &HwTrqFiltTimer1Elapsed_mS_T_u32);      /* Get elapsed time from 'StartTime1' */
        if (HwTrqFiltTimer1Elapsed_mS_T_u32 > (uint32)k_PsaSH_ApaHwTrqMinTi_mS_u32)
        {
            *ApaHwMinTrqReached_Cnt_T_lgc = D_TRUE_CNT_LGC;                                                             /* Set intermediate APA Intervention Flag to TRUE */
        }
        else
        {
            *ApaHwMinTrqReached_Cnt_T_lgc = D_FALSE_CNT_LGC;
        }
    }
    else
    {
        /* ResetTimer1 */
        (void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&MinTqTimer_mS_M_u32);
        *ApaHwMinTrqReached_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    PsaSH_ApaHwMinTrqReached_Cnt_D_lgc = *ApaHwMinTrqReached_Cnt_T_lgc;
    /* REQ: CF013A #111 I */

    /* REQ: CF013A #139 I */
    if (Abs_f32_m(HwTqFild_HwNm_T_f32) > k_PsaSH_ApaHwTrqMax_HwNm_f32)                                                  /* If filtered HWTrq > k_PsaSH_ApaHwTrqMax_HwNm_f32, start measuring time */
    {
        /* ElapsedTime2 */
        (void) Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(MaxTqTimer_mS_M_u32, &HwTrqFiltTimer2Elapsed_mS_T_u32);      /* Get elapsed time from 'StartTime2' */
        if (HwTrqFiltTimer2Elapsed_mS_T_u32 > (uint32)k_PsaSH_ApaHwTrqMaxTi_mS_u32)
        {
            *ApaHwMaxTrqReached_Cnt_T_lgc = D_TRUE_CNT_LGC;                                                             /* APA_InterventionOut */ /* Set APA Intervention Out Flag to TRUE */
        }
        else
        {
            *ApaHwMaxTrqReached_Cnt_T_lgc = D_FALSE_CNT_LGC;                                                            /*APA_InterventionOut*/
        }
    }
    else
    {
        /* ResetTimer2 */
        (void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&MaxTqTimer_mS_M_u32);                                          /*If filtered HWTrq < k_PsaSH_APAMaxHwTrq1_HwNm_f32, update StartTime2 with current time stamp */
        *ApaHwMaxTrqReached_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    PsaSH_ApaHwMaxTrqReached_Cnt_D_lgc = *ApaHwMaxTrqReached_Cnt_T_lgc;
    /* REQ: CF013A #139 I */
}

/**********************************************************************************************************************
 * Name:        ComputeApaHwAgCtrlErr
 * Description: Implementation of "Compute_ApaHwAgCtrlErr" block in the FDD.
 * Inputs:      HandwheelPosition_HwDeg_T_f32
 *              ApaHwAgCmd_HwDeg_T_f32
 * Outputs:     ApaHwAgCtrlErr_Cnt_T_lgc
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaHwAgCtrlErr(
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) DeltaApaHwAg_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) DecDynErr_Cnt_T_lgc = D_FALSE_CNT_LGC;
    VAR(boolean, AUTOMATIC) DecStatErr_Cnt_T_lgc = D_FALSE_CNT_LGC;
    VAR(boolean, AUTOMATIC) DynErr_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) StatErr_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc;

    DeltaApaHwAg_HwDeg_T_f32 = Abs_f32_m(HandwheelPosition_HwDeg_T_f32 - ApaHwAgCmd_HwDeg_T_f32); /* REQ: CF013A #343 I */

    /* REQ: CF013A #134 I */ /* REQ: CF013A #135 I */
    /* Compute_DynErr */
    if (Limit_m(DeltaApaHwAg_HwDeg_T_f32 - PrevDeltaApaHwAg_HwDeg_M_f32, D_ZERO_HWDEG_F32, D_U16MAX_HWDEG_F32) >= (float32) k_PsaSH_ApaDynHwThd_HwDeg_u16)
    {
        DecDynErr_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    PrevDeltaApaHwAg_HwDeg_M_f32 = DeltaApaHwAg_HwDeg_T_f32;

    if ((PrevApaPosSrvoEna_Cnt_M_lgc == D_TRUE_CNT_LGC) && (DecDynErr_Cnt_T_lgc == D_TRUE_CNT_LGC))
    {
        /* PassDec */
        PsaSH_DynErrAcc_Cnt_M_u16 = DiagPStep_m(PsaSH_DynErrAcc_Cnt_M_u16, k_PsaSH_ApaDynErr_Cnt_str);
    }
    else
    {
        /* PassFalse */
        PsaSH_DynErrAcc_Cnt_M_u16 = DiagNStep_m(PsaSH_DynErrAcc_Cnt_M_u16, k_PsaSH_ApaDynErr_Cnt_str);
    }
    DynErr_Cnt_T_lgc              = DiagFailed_m(PsaSH_DynErrAcc_Cnt_M_u16, k_PsaSH_ApaDynErr_Cnt_str);
    PsaSH_ApaHwAgDynErr_Cnt_D_lgc = DynErr_Cnt_T_lgc;
    /* ENDREQ: CF013A #134 I */ /* ENDREQ: CF013A #135 I */

    /* REQ: CF013A #137 I */ /* REQ: CF013A #138 I */
    /* Compute_StatErr */
    if (Limit_m(DeltaApaHwAg_HwDeg_T_f32, D_ZERO_HWDEG_F32, D_U16MAX_HWDEG_F32) >= (float32) k_PsaSH_ApaStatHwThd_HwDeg_u16)
    {
        DecStatErr_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }

    if ((PrevApaPosSrvoEna_Cnt_M_lgc == D_TRUE_CNT_LGC) && (DecStatErr_Cnt_T_lgc == D_TRUE_CNT_LGC))
    {
        /* PassDec */
        PsaSH_StaErrAcc_Cnt_M_u16 = DiagPStep_m(PsaSH_StaErrAcc_Cnt_M_u16, k_PsaSH_ApaStatErr_Cnt_str);
    }
    else
    {
        /* PassFalse */
        PsaSH_StaErrAcc_Cnt_M_u16 = DiagNStep_m(PsaSH_StaErrAcc_Cnt_M_u16, k_PsaSH_ApaStatErr_Cnt_str);
    }
    StatErr_Cnt_T_lgc              = DiagFailed_m(PsaSH_StaErrAcc_Cnt_M_u16, k_PsaSH_ApaStatErr_Cnt_str);
    PsaSH_ApaHwAgStatErr_Cnt_D_lgc = StatErr_Cnt_T_lgc;
    /* ENDREQ: CF013A #137 I */ /* ENDREQ: CF013A #138 I */

    if ((DynErr_Cnt_T_lgc == D_TRUE_CNT_LGC) || (StatErr_Cnt_T_lgc == D_TRUE_CNT_LGC)) /* REQ: CF013A #132 I */ /* REQ: CF013A #133 I */
    {
        ApaHwAgCtrlErr_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        ApaHwAgCtrlErr_Cnt_T_lgc = D_FALSE_CNT_LGC;
    }

    return ApaHwAgCtrlErr_Cnt_T_lgc;
}

/**********************************************************************************************************************
 * Name:        ComputeApaFltActv
 * Description: Implementation of "Compute_ApaFltActv" block in the FDD.
 * Inputs:      VehicleSpeedValid_Cnt_T_lgc
 *              CpkOk_Cnt_T_lgc
 *              PosSrvoNTC_Cnt_T_lgc
 *              FTermActv_Cnt_T_lgc
 * Outputs:     ApaFltActv_Cnt_T_lgc
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(boolean, RTE_AP_PSASH_APPL_CODE) ComputeApaFltActv(
        VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaPosSrvoFlt_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc = D_FALSE_CNT_LGC;

    /* REQ: CF013A #165 I */ /* REQ: CF013A #239 I */ /* REQ: CF013A #240 I */ /* REQ: CF013A #241 I */
    if ((VehicleSpeedValid_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
        (CpkOk_Cnt_T_lgc == D_FALSE_CNT_LGC) ||
        (ApaPosSrvoFlt_Cnt_T_lgc == D_TRUE_CNT_LGC) ||
        (FTermActv_Cnt_T_lgc == D_TRUE_CNT_LGC))
    {
        ApaFltActv_Cnt_T_lgc = D_TRUE_CNT_LGC;
    }

    PsaSH_ApaFltActv_Cnt_D_lgc = ApaFltActv_Cnt_T_lgc;
    /* ENDREQ: CF013A #165 I */ /* ENDREQ: CF013A #239 I */ /* ENDREQ: CF013A #240 I */ /* ENDREQ: CF013A #241 I */

    return ApaFltActv_Cnt_T_lgc;
}

/**********************************************************************************************************************
 * Name:        ComputeApaState
 * Description: Implementation of "Compute_ApaState" state flow in the FDD.
 * Inputs:      ApaAllw_Cnt_T_lgc
 *              ApaEna_Cnt_T_lgc
 *              PrevLxaApaConflictReqNTC_Cnt_M_lgc
 *              VehSpdTooHi_Cnt_T_lgc
 *              ThrmlLmtReached_Cnt_T_lgc
 *              MtrStalled_Cnt_T_lgc
 *              ApaCmdReq_Cnt_T_lgc
 *              ApaHwMinTrqReached_Cnt_T_lgc
 *              ApaHwMaxTrqReached_Cnt_T_lgc
 *              ApaHwAgCtrlErr_Cnt_T_lgc
 *              ApaFltActv_Cnt_T_lgc
 *              ApaRelaxReq_Cnt_T_lgc
 * Outputs:     ApaState_Cnt_T_enum
 *              ApaStateTransitionCause_Cnt_T_enum
 * Usage Notes: Called by ComputeApa
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState(
        VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaState_Cnt_T_enum,
        P2VAR(PsaApaTranCause_Cnt_enum, AUTOMATIC, AUTOMATIC) ApaStateTransitionCause_Cnt_T_enum)
{
    VAR(uint8, AUTOMATIC) PrevApaState_Cnt_T_u08 = PsaSH_ApaState_Cnt_M_u08;

    /* Parent transitions */
    ComputeApaState_ParentTransitions(ApaFltActv_Cnt_T_lgc, ThrmlLmtReached_Cnt_T_lgc);

    /* Child transitions */
    if (PsaSH_ApaState_Cnt_M_u08 == PrevApaState_Cnt_T_u08)
    {
        ComputeApaState_ChildTransitions(
                ApaAllw_Cnt_T_lgc,ApaEna_Cnt_T_lgc,
                VehSpdTooHi_Cnt_T_lgc,
                ThrmlLmtReached_Cnt_T_lgc,
                MtrStalled_Cnt_T_lgc,
                ApaCmdReq_Cnt_T_lgc,
                ApaHwMinTrqReached_Cnt_T_lgc,
                ApaHwMaxTrqReached_Cnt_T_lgc,
                ApaHwAgCtrlErr_Cnt_T_lgc,
                ApaFltActv_Cnt_T_lgc,
                ApaRelaxReq_Cnt_T_lgc);
    }

    /* Entry */
    if (PsaSH_ApaState_Cnt_M_u08 != PrevApaState_Cnt_T_u08)
    {
        switch (PsaSH_ApaState_Cnt_M_u08)
        {
            case D_APA_DEFECT_CNT_U08:
                /* REQ: CF013A #293 I */ /* REQ: CF013A #294 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_DFCT;
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_OTHERERR;
                /* ENDREQ: CF013A #293 I */ /* ENDREQ: CF013A #294 I */
            break;

            case D_APA_UNAVAILABLE_THERMALLIMIT_CNT_U08:
                /* REQ: CF013A #287 I */ /* REQ: CF013A #288 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_UNAVL;
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_THERMLIM;
                /* ENDREQ: CF013A #287 I */ /* ENDREQ: CF013A #288 I */
            break;

            case D_APA_UNAVAILABLE_NOAUTHORIZATION_CNT_U08:
                /* REQ: CF013A #290 I */ /* REQ: CF013A #291 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_UNAVL;
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_OTHERERR;
                /* ENDREQ: CF013A #290 I */ /* ENDREQ: CF013A #291 I */
            break;

            case D_APA_AVAILABLE_CNT_U08:
                /* REQ: CF013A #442 I */ /* REQ: CF013A #443 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_AVL;
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_NOINTRPT;
                /* ENDREQ: CF013A #442 I */ /* ENDREQ: CF013A #443 I */
            break;

            case D_APA_CONTROLPROGRESS_CNT_U08:
                /* REQ: CF013A #272 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_CTRLPRGS;
                PsaSH_ApaExitCtrlProgsCntr_Cnt_M_u16 = D_ZERO_CNT_U16;
                /* ENDREQ: CF013A #272 I */
            break;

            case D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08:
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_VEHSPDHI;  /* REQ: CF013A #276 I */
            break;

            case D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08:
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_DRVRINTV;  /* REQ: CF013A #279 I */
            break;

            case D_APA_AVAILABLE_MOTORSTALLED_CNT_U08:
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_MTRSTALL;  /* REQ: CF013A #282 I */
            break;

            case D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08:
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_AGLERR;    /* REQ: CF013A #285 I */
            break;

            default:
                /* REQ: CF013A #245 I */ /* REQ: CF013A #247 I */
                PsaSH_ApaState_Cnt_M_enum = PSAAPAST_UNAVL;
                PsaSH_ApaStateTransitionCause_Cnt_M_enum = PSAAPATRANCAUSE_NOINTRPT;
                /* ENDREQ: CF013A #245 I */ /* ENDREQ: CF013A #247 I */
            break;
        }
    }

    /* During */
    switch (PsaSH_ApaState_Cnt_M_u08)
    {
        case D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_MOTORSTALLED_CNT_U08:
        case D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08:
            /* REQ: CF013A #275 I */ /* REQ: CF013A #278 I */ /* REQ: CF013A #281 I */ /* REQ: CF013A #284 I */
            PsaSH_ApaState_Cnt_M_enum = PSAAPAST_AVL;
            PsaSH_ApaExitCtrlProgsCntr_Cnt_M_u16 += D_SAMPLETIME_CNT_U16;
            /* ENDREQ: CF013A #275 I */ /* ENDREQ: CF013A #278 I */ /* ENDREQ: CF013A #281 I */ /* ENDREQ: CF013A #284 I */
        break;

        default:
        break;
    }

    /* Write outputs */
    *ApaState_Cnt_T_enum = PsaSH_ApaState_Cnt_M_enum;
    *ApaStateTransitionCause_Cnt_T_enum = PsaSH_ApaStateTransitionCause_Cnt_M_enum;
}

/**********************************************************************************************************************
 * Name:        ComputeApaState_ParentTransitions
 * Description: Fragment of implementation of "Compute_ApaState" state flow.
 * Inputs:      ApaFltActv_Cnt_T_lgc
                ThrmlLmtReached_Cnt_T_lgc
 * Outputs:     PsaSH_ApaState_Cnt_M_u08
 * Usage Notes: Called by ComputeApaState
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState_ParentTransitions(
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc)
{
    switch (PsaSH_ApaState_Cnt_M_u08)
    {
        case D_APA_AVAILABLE_CNT_U08:
        case D_APA_CONTROLPROGRESS_CNT_U08:
        case D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_MOTORSTALLED_CNT_U08:
        case D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08:
            if (ApaFltActv_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_DEFECT_CNT_U08;                    /* REQ: CF013A #271 I */
            }
            else if (ThrmlLmtReached_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_THERMALLIMIT_CNT_U08;  /* REQ: CF013A #306 I */
            }
            else if (PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08;               /* REQ: CF013A #307 I */
            }
            else
            {
                /* Do nothing */
            }
        break;

        default:
        break;
    }
}

/**********************************************************************************************************************
 * Name:        ComputeApaState_ChildTransitions
 * Description: Fragment of implementation of "Compute_ApaState" state flow.
 * Inputs:      ApaAllw_Cnt_T_lgc
                ApaEna_Cnt_T_lgc
                VehSpdTooHi_Cnt_T_lgc
                ThrmlLmtReached_Cnt_T_lgc
                MtrStalled_Cnt_T_lgc
                ApaCmdReq_Cnt_T_lgc
                ApaHwMinTrqReached_Cnt_T_lgc
                ApaHwMaxTrqReached_Cnt_T_lgc
                ApaHwAgCtrlErr_Cnt_T_lgc
                ApaFltActv_Cnt_T_lgc
                ApaRelaxReq_Cnt_T_lgc
 * Outputs:     PsaSH_ApaState_Cnt_M_u08
 * Usage Notes: Called by ComputeApaState
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputeApaState_ChildTransitions(
        VAR(boolean, AUTOMATIC) ApaAllw_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) VehSpdTooHi_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMinTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwMaxTrqReached_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaHwAgCtrlErr_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaFltActv_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc)
{
    switch (PsaSH_ApaState_Cnt_M_u08)
    {
        case D_APA_DEFECT_CNT_U08:
            if (ApaFltActv_Cnt_T_lgc == D_FALSE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08; /* REQ: CF013A #295 I */
            }
        break;

        case D_APA_UNAVAILABLE_THERMALLIMIT_CNT_U08:
            if (ThrmlLmtReached_Cnt_T_lgc == D_FALSE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08; /* REQ: CF013A #289 I */
            }
        break;

        case D_APA_UNAVAILABLE_NOAUTHORIZATION_CNT_U08:
            if (ApaAllw_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08; /* REQ: CF013A #292 I */
            }
        break;

        case D_APA_AVAILABLE_CNT_U08:
            if (ApaAllw_Cnt_T_lgc == D_FALSE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08; /* REQ: CF013A #296 I */
            }
            else
            {
                if ((ApaCmdReq_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                    (VehSpdTooHi_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                    (MtrStalled_Cnt_T_lgc == D_FALSE_CNT_LGC) &&
                    (ApaHwMinTrqReached_Cnt_T_lgc == D_FALSE_CNT_LGC))
                {
                    PsaSH_ApaState_Cnt_M_u08 = D_APA_CONTROLPROGRESS_CNT_U08; /* REQ: CF013A #297 I */
                }
            }
        break;

        case D_APA_CONTROLPROGRESS_CNT_U08:
            if (VehSpdTooHi_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08; /* REQ: CF013A #262 I */
            }
            else if ((ApaHwAgCtrlErr_Cnt_T_lgc == D_TRUE_CNT_LGC) && (ApaRelaxReq_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08; /* REQ: CF013A #305 I */
            }
            else if (ApaHwMaxTrqReached_Cnt_T_lgc == D_TRUE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08;     /* REQ: CF013A #304 I */
            }
            else if ((MtrStalled_Cnt_T_lgc == D_TRUE_CNT_LGC) && (ApaRelaxReq_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_MOTORSTALLED_CNT_U08;        /* REQ: CF013A #303 I */
            }
            else if (ApaCmdReq_Cnt_T_lgc == D_FALSE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_CNT_U08;                     /* REQ: CF013A #302 I */ /* REQ: CF013A #310 I */
            }
            else if (ApaAllw_Cnt_T_lgc == D_FALSE_CNT_LGC)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_NOAUTHORIZATION_CNT_U08;   /* REQ: CF013A #310 I */
            }
            else
            {
                /* Do nothing */
            }
        break;

        case D_APA_AVAILABLE_VEHICLESPEEDTOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_HWTORQUETOOHIGH_CNT_U08:
        case D_APA_AVAILABLE_MOTORSTALLED_CNT_U08:
        case D_APA_AVAILABLE_HWANGLECONTROLERROR_CNT_U08:
            if (PsaSH_ApaExitCtrlProgsCntr_Cnt_M_u16 >= k_PsaSH_ApaExitCtrlProgsTi_mS_u16)
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_CNT_U08;       /* REQ: CF013A #263 I */ /* REQ: CF013A #315 I */ /* REQ: CF013A #318 I */ /* REQ: CF013A #321 I */
            }
        break;

        case D_APA_UNAVAILABLE_CNT_U08:
            if ((ApaFltActv_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                (ApaEna_Cnt_T_lgc == D_TRUE_CNT_LGC))
            {
                PsaSH_ApaState_Cnt_M_u08 = D_APA_DEFECT_CNT_U08;          /* REQ: CF013A #251 I */
            }
            else
            {
                if ((PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_FALSE_CNT_LGC) &&
                    (ApaAllw_Cnt_T_lgc == D_TRUE_CNT_LGC) &&
                    (ApaEna_Cnt_T_lgc == D_TRUE_CNT_LGC))
                {
                    PsaSH_ApaState_Cnt_M_u08 = D_APA_AVAILABLE_CNT_U08;   /* REQ: CF013A #250 I */ /* REQ: CF013A #270 I */
                }
            }
        break;

        default:
            PsaSH_ApaState_Cnt_M_u08 = D_APA_UNAVAILABLE_CNT_U08;         /* REQ: CF013A #248 I */ /* REQ: CF013A #249 I */
        break;
    }
}

/**********************************************************************************************************************
 * Name:        ComputePosSrvoEnable
 * Description: Implementation of "Compute_PosSrvoEnable" block in the FDD.
 * Inputs:      EPSStateForLxa_Cnt_T_enum
 *              ApaState_Cnt_T_enum
 *              LxaHwAgCmd_HwDeg_T_f32
 *              ApaRelaxReq_Cnt_T_lgc
 *              ApaHwAgCmd_HwDeg_T_f32
 *              VehicleSpeed_Kph_T_u9p7
 *              HandwheelPosition_HwDeg_T_f32
 * Outputs:     PrevLxaApaConflictReqNTC_Cnt_M_lgc
 *              OutApaState_Cnt_T_enum
 *              PrevApaPosSrvoEna_Cnt_M_lgc
 *              PosSrvoEnable_Cnt_T_lgc
 *              PosSrvoHwAngle_HwDeg_T_f32
 *              OutEPSStateForLxa_Cnt_T_enum
 * Usage Notes: Called by PSASH_Per1
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_PSASH_APPL_CODE) ComputePosSrvoEnable(
        VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC) EPSStateForLxa_Cnt_T_enum,
        VAR(PsaApaSt_Cnt_enum, AUTOMATIC) ApaState_Cnt_T_enum,
        VAR(float32, AUTOMATIC) LxaHwAgCmd_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) ApaHwAgCmd_HwDeg_T_f32,
        VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
        P2VAR(PsaApaSt_Cnt_enum, AUTOMATIC, AUTOMATIC) OutApaState_Cnt_T_enum,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32,
        P2VAR(PsaEpsStLxa_Cnt_enum, AUTOMATIC, AUTOMATIC) OutEPSStateForLxa_Cnt_T_enum)
{
    VAR(uint16,  AUTOMATIC) LxaHwAgCmdSatn_HwDeg_T_u16;
    VAR(float32, AUTOMATIC) LxaHwAgCmdSatn_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) LxaHwAgCmdLim_HwDeg_T_f32;
    VAR(uint16,  AUTOMATIC) LxaHwAgCmdRate_HwDegpS_T_u11p5;
    VAR(float32, AUTOMATIC) LxaHwAgCmdRate_HwDegpS_T_f32;
    VAR(uint16, AUTOMATIC)  ApaHwAgCmdRateY_HwDegpS_T_u11p5;
    VAR(float32, AUTOMATIC) ApaHwAgCmdRateY_HwDegpS_T_f32;

    /* REQ: CF013A #168 I */ /* REQ: CF013A #323 I */ /* REQ: CF013A #350 I */ /* REQ: CF013A #351 I */ /* REQ: CF013A #352 I */ /* REQ: CF013A #353 I */
    /* First Stage */
    if (((PSAEPSSTLXA_ACTV == EPSStateForLxa_Cnt_T_enum) ||
         (PSAEPSSTLXA_AUTHD == EPSStateForLxa_Cnt_T_enum)) &&
        (PSAAPAST_CTRLPRGS == ApaState_Cnt_T_enum))
    {
        /* SwitchStates */
        LxaApaConflictReqFltTrig_Cnt_M_lgc = D_TRUE_CNT_LGC;
        *OutEPSStateForLxa_Cnt_T_enum      = PSAEPSSTLXA_UNAUTHD;
        *OutApaState_Cnt_T_enum            = PSAAPAST_UNAVL;
    }
    else
    {
        /* PassThrough */
        *OutEPSStateForLxa_Cnt_T_enum      = EPSStateForLxa_Cnt_T_enum;
        *OutApaState_Cnt_T_enum            = ApaState_Cnt_T_enum;
    }
    /* ENDREQ: CF013A #168 I */ /* ENDREQ: CF013A #323 I */ /* ENDREQ: CF013A #350 I */ /* ENDREQ: CF013A #351 I */ /* ENDREQ: CF013A #352 I */ /* ENDREQ: CF013A #353 I */

    /* REQ: CF013A #354 I */
    if(LxaApaConflictReqFltTrig_Cnt_M_lgc == D_TRUE_CNT_LGC)
    {
        /* SetNTC */
        PrevLxaApaConflictReqNTC_Cnt_M_lgc = D_TRUE_CNT_LGC;
    }
    else
    {
        /* DoNotSetNTC */
        PrevLxaApaConflictReqNTC_Cnt_M_lgc = D_FALSE_CNT_LGC;
    }
    /* ENDREQ: CF013A #354 I */

    /* NTC Handling Logic */
    if(PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_TRUE_CNT_LGC)
    {
        /* NTC_FAILED */
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_20, 0U, NTC_STATUS_FAILED); /* REQ: CF013A #44 I */
    }
    else
    {
        /* NTC_PASSED */
        (void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_20, 0U, NTC_STATUS_PASSED); /* REQ: CF013A #50 I */
    }

    /* REQ: CF013A #327 I */ /* REQ: CF013A #326 I */ /* REQ: CF013A #325 I */ /* REQ: CF013A #329 I */ /* REQ: CF013A #330 I */ /* REQ: CF013A #331 I */ /* REQ: CF013A #333 I */ /* REQ: CF013A #334 I */ /* REQ: CF013A #335 I */
    /* Second Stage */
    if(PrevLxaApaConflictReqNTC_Cnt_M_lgc == D_FALSE_CNT_LGC)
    {
        /* KeepChecking */
        if(EPSStateForLxa_Cnt_T_enum == PSAEPSSTLXA_ACTV)
        {
            /* FinalOutp */
            PrevApaPosSrvoEna_Cnt_M_lgc = D_FALSE_CNT_LGC;
            *PosSrvoEnable_Cnt_T_lgc    = D_TRUE_CNT_LGC;
           
		    /* REQ: CF013A #103 I */
            LxaHwAgCmdSatn_HwDeg_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(
                    t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7,
                    t_PsaSH_LxaHwAgCmdSatnY_HwDeg_u16,
                    TableSize_m(t_PsaSH_LxaHwAgCmdSatnX_Kph_u9p7),
                    VehicleSpeed_Kph_T_u9p7);
            LxaHwAgCmdSatn_HwDeg_T_f32 = FPM_FixedToFloat_m(LxaHwAgCmdSatn_HwDeg_T_u16, u16p0_T);
            LxaHwAgCmdLim_HwDeg_T_f32 = Limit_m(LxaHwAgCmd_HwDeg_T_f32, -LxaHwAgCmdSatn_HwDeg_T_f32, LxaHwAgCmdSatn_HwDeg_T_f32);

            LxaHwAgCmdRate_HwDegpS_T_u11p5 = IntplVarXY_u16_u16Xu16Y_Cnt(
                    t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7,
                    t_PsaSH_LxaHwAgCmdRateY_HwDegpS_u11p5,
                    TableSize_m(t_PsaSH_LxaHwAgCmdRateX_Kph_u9p7),
                    VehicleSpeed_Kph_T_u9p7);
            LxaHwAgCmdRate_HwDegpS_T_f32 = FPM_FixedToFloat_m(LxaHwAgCmdRate_HwDegpS_T_u11p5, u11p5_T);
            /* ENDREQ: CF013A #103 I */

            /* REQ: CF013A #104 I */
            *PosSrvoHwAngle_HwDeg_T_f32 = Limit_m(
                    LxaHwAgCmdLim_HwDeg_T_f32,
                    PrevPosSrvoHwAngle_HwDeg_M_f32 - (LxaHwAgCmdRate_HwDegpS_T_f32 * D_2MS_SEC_F32),
                    PrevPosSrvoHwAngle_HwDeg_M_f32 + (LxaHwAgCmdRate_HwDegpS_T_f32 * D_2MS_SEC_F32));
            /* ENDREQ: CF013A #104 I */
        }
        else
        {
            /* KeepChecking */
            if((ApaState_Cnt_T_enum == PSAAPAST_CTRLPRGS) && (ApaRelaxReq_Cnt_T_lgc == D_FALSE_CNT_LGC))
            {
                /* SetTrue */
                PrevApaPosSrvoEna_Cnt_M_lgc = D_TRUE_CNT_LGC;
                *PosSrvoEnable_Cnt_T_lgc    = D_TRUE_CNT_LGC;

                ApaHwAgCmdRateY_HwDegpS_T_u11p5 = IntplVarXY_u16_u16Xu16Y_Cnt(
                        t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7,
                        t_PsaSH_ApaHwAgCmdRateY_HwDegpS_u11p5,
                        TableSize_m(t_PsaSH_ApaHwAgCmdRateX_Kph_u9p7),
                        VehicleSpeed_Kph_T_u9p7);

                ApaHwAgCmdRateY_HwDegpS_T_f32 = FPM_FixedToFloat_m(ApaHwAgCmdRateY_HwDegpS_T_u11p5, u11p5_T);

                *PosSrvoHwAngle_HwDeg_T_f32 = Limit_m(
                        ApaHwAgCmd_HwDeg_T_f32,
                        PrevPosSrvoHwAngle_HwDeg_M_f32 - (ApaHwAgCmdRateY_HwDegpS_T_f32 * D_2MS_SEC_F32),
                        PrevPosSrvoHwAngle_HwDeg_M_f32 + (ApaHwAgCmdRateY_HwDegpS_T_f32 * D_2MS_SEC_F32));
            }
            else
            {
                /* SetFalseAndZero */
                PrevApaPosSrvoEna_Cnt_M_lgc = D_FALSE_CNT_LGC;
                *PosSrvoEnable_Cnt_T_lgc    = D_FALSE_CNT_LGC;
                *PosSrvoHwAngle_HwDeg_T_f32 = HandwheelPosition_HwDeg_T_f32;
            }
        }
    }
    else
    {
        /* SetFalseAndHwPosn */
        PrevApaPosSrvoEna_Cnt_M_lgc = D_FALSE_CNT_LGC;
        *PosSrvoEnable_Cnt_T_lgc    = D_FALSE_CNT_LGC;
        *PosSrvoHwAngle_HwDeg_T_f32 = HandwheelPosition_HwDeg_T_f32;
    }

    *PosSrvoHwAngle_HwDeg_T_f32    = Limit_m(*PosSrvoHwAngle_HwDeg_T_f32, D_POSSERVOHWAGMINLIM_HWDEG_F32, D_POSSERVOHWAGMAXLIM_HWDEG_F32);
    PrevPosSrvoHwAngle_HwDeg_M_f32 = *PosSrvoHwAngle_HwDeg_T_f32;
    /* ENDREQ: CF013A #327 I */ /* ENDREQ: CF013A #326 I */ /* ENDREQ: CF013A #325 I */ /* ENDREQ: CF013A #329 I */ /* ENDREQ: CF013A #330 I */ /* ENDREQ: CF013A #331 I */ /* ENDREQ: CF013A #333 I */ /* ENDREQ: CF013A #334 I */ /* ENDREQ: CF013A #335 I */
}

#define RTE_STOP_SEC_AP_PSASH_APPL_CODE
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
