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
 *          File:  Rte_Type.h
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_ANGLE_COLONNE
typedef sint16 ANGLE_COLONNE;
# define ANGLE_COLONNE_LowerLimit (-16300)
# define ANGLE_COLONNE_UpperLimit (16300)

# define Rte_TypeDef_ANGLE_VOLANT
typedef sint16 ANGLE_VOLANT;
# define ANGLE_VOLANT_LowerLimit (-7800)
# define ANGLE_VOLANT_UpperLimit (7800)

# define Rte_TypeDef_ANGLE_VOLANT_ORIGINE
typedef uint8 ANGLE_VOLANT_ORIGINE;
# define ANGLE_VOLANT_ORIGINE_LowerLimit (0U)
# define ANGLE_VOLANT_ORIGINE_UpperLimit (3U)
# define Rte_InvalidValue_ANGLE_VOLANT_ORIGINE (3U)
# define InvalidValue_ANGLE_VOLANT_ORIGINE (3U)

# define Rte_TypeDef_AUTOR_ARRET_MOT_DA
typedef boolean AUTOR_ARRET_MOT_DA;

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_CALIBRATION_VOL
typedef boolean CALIBRATION_VOL;
# define Rte_InvalidValue_CALIBRATION_VOL (1)
# define InvalidValue_CALIBRATION_VOL (1)

# define Rte_TypeDef_CAUSE_DESACTIV_CPK
typedef uint8 CAUSE_DESACTIV_CPK;
# define CAUSE_DESACTIV_CPK_LowerLimit (0U)
# define CAUSE_DESACTIV_CPK_UpperLimit (7U)
# define Rte_InvalidValue_CAUSE_DESACTIV_CPK (0U)
# define InvalidValue_CAUSE_DESACTIV_CPK (0U)

# define Rte_TypeDef_CHKSUM_TRME_DYN_DAE
typedef uint8 CHKSUM_TRME_DYN_DAE;
# define CHKSUM_TRME_DYN_DAE_LowerLimit (0U)
# define CHKSUM_TRME_DYN_DAE_UpperLimit (15U)
# define Rte_InvalidValue_CHKSUM_TRME_DYN_DAE (4U)
# define InvalidValue_CHKSUM_TRME_DYN_DAE (4U)

# define Rte_TypeDef_CHKSUM_VOL
typedef uint8 CHKSUM_VOL;
# define CHKSUM_VOL_LowerLimit (0U)
# define CHKSUM_VOL_UpperLimit (15U)

# define Rte_TypeDef_CODE_DEFAUT
typedef uint8 CODE_DEFAUT;
# define CODE_DEFAUT_LowerLimit (0U)
# define CODE_DEFAUT_UpperLimit (255U)
# define Rte_InvalidValue_CODE_DEFAUT (0U)
# define InvalidValue_CODE_DEFAUT (0U)

# define Rte_TypeDef_CODE_DEFAUT_VOL
typedef uint8 CODE_DEFAUT_VOL;
# define CODE_DEFAUT_VOL_LowerLimit (0U)
# define CODE_DEFAUT_VOL_UpperLimit (15U)

# define Rte_TypeDef_CPLE_VOLANT
typedef sint8 CPLE_VOLANT;
# define CPLE_VOLANT_LowerLimit (-128)
# define CPLE_VOLANT_UpperLimit (127)
# define Rte_InvalidValue_CPLE_VOLANT (127)
# define InvalidValue_CPLE_VOLANT (127)

# define Rte_TypeDef_CPLE_VOLANT_OPTMSE
typedef sint8 CPLE_VOLANT_OPTMSE;
# define CPLE_VOLANT_OPTMSE_LowerLimit (-100)
# define CPLE_VOLANT_OPTMSE_UpperLimit (100)

# define Rte_TypeDef_CPT_PROCESS_4B_A_VOL
typedef uint8 CPT_PROCESS_4B_A_VOL;
# define CPT_PROCESS_4B_A_VOL_LowerLimit (0U)
# define CPT_PROCESS_4B_A_VOL_UpperLimit (15U)

# define Rte_TypeDef_CPT_PROCESS_4B_DAE
typedef uint8 CPT_PROCESS_4B_DAE;
# define CPT_PROCESS_4B_DAE_LowerLimit (0U)
# define CPT_PROCESS_4B_DAE_UpperLimit (15U)
# define Rte_InvalidValue_CPT_PROCESS_4B_DAE (0U)
# define InvalidValue_CPT_PROCESS_4B_DAE (0U)

# define Rte_TypeDef_DDE_REDEM_DA
typedef boolean DDE_REDEM_DA;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;
# define Dem_DTCStatusMaskType_LowerLimit (0U)
# define Dem_DTCStatusMaskType_UpperLimit (255U)

# define Rte_TypeDef_Dem_DTCType
typedef uint32 Dem_DTCType;
# define Dem_DTCType_LowerLimit (0U)
# define Dem_DTCType_UpperLimit (4294967295U)

# define Rte_TypeDef_Dem_EventIdType
typedef uint8 Dem_EventIdType;
# define Dem_EventIdType_LowerLimit (0U)
# define Dem_EventIdType_UpperLimit (255U)

# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;
# define Dem_EventStatusExtendedType_LowerLimit (0U)
# define Dem_EventStatusExtendedType_UpperLimit (255U)

# define Rte_TypeDef_Dem_FaultDetectionCounterType
typedef sint8 Dem_FaultDetectionCounterType;
# define Dem_FaultDetectionCounterType_LowerLimit (-128)
# define Dem_FaultDetectionCounterType_UpperLimit (127)

# define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;
# define Dem_OperationCycleIdType_LowerLimit (0U)
# define Dem_OperationCycleIdType_UpperLimit (255U)

# define Rte_TypeDef_Double
typedef float64 Double;
# define Double_LowerLimit (-DBL_MAX)
# define Double_UpperLimit (DBL_MAX)

# define Rte_TypeDef_EPS_STATE_LKA
typedef uint8 EPS_STATE_LKA;
# define EPS_STATE_LKA_LowerLimit (0U)
# define EPS_STATE_LKA_UpperLimit (15U)

# define Rte_TypeDef_ETAT_ASSIST_DA
typedef uint8 ETAT_ASSIST_DA;
# define ETAT_ASSIST_DA_LowerLimit (0U)
# define ETAT_ASSIST_DA_UpperLimit (7U)
# define Rte_InvalidValue_ETAT_ASSIST_DA (0U)
# define InvalidValue_ETAT_ASSIST_DA (0U)

# define Rte_TypeDef_ETAT_CAPT_VOL
typedef boolean ETAT_CAPT_VOL;
# define Rte_InvalidValue_ETAT_CAPT_VOL (1)
# define InvalidValue_ETAT_CAPT_VOL (1)

# define Rte_TypeDef_ETAT_DAE_CAV3_VIRTUEL
typedef uint8 ETAT_DAE_CAV3_VIRTUEL;
# define ETAT_DAE_CAV3_VIRTUEL_LowerLimit (0U)
# define ETAT_DAE_CAV3_VIRTUEL_UpperLimit (7U)
# define Rte_InvalidValue_ETAT_DAE_CAV3_VIRTUEL (0U)
# define InvalidValue_ETAT_DAE_CAV3_VIRTUEL (0U)

# define Rte_TypeDef_ETAT_DAE_CPK
typedef uint8 ETAT_DAE_CPK;
# define ETAT_DAE_CPK_LowerLimit (0U)
# define ETAT_DAE_CPK_UpperLimit (3U)
# define Rte_InvalidValue_ETAT_DAE_CPK (0U)
# define InvalidValue_ETAT_DAE_CPK (0U)

# define Rte_TypeDef_ETAT_DA_2004
typedef uint8 ETAT_DA_2004;
# define ETAT_DA_2004_LowerLimit (0U)
# define ETAT_DA_2004_UpperLimit (3U)
# define Rte_InvalidValue_ETAT_DA_2004 (0U)
# define InvalidValue_ETAT_DA_2004 (0U)

# define Rte_TypeDef_ETAT_DA_2010
typedef uint8 ETAT_DA_2010;
# define ETAT_DA_2010_LowerLimit (0U)
# define ETAT_DA_2010_UpperLimit (3U)
# define Rte_InvalidValue_ETAT_DA_2010 (0U)
# define InvalidValue_ETAT_DA_2010 (0U)

# define Rte_TypeDef_ETAT_DA_DYN
typedef uint8 ETAT_DA_DYN;
# define ETAT_DA_DYN_LowerLimit (0U)
# define ETAT_DA_DYN_UpperLimit (3U)
# define Rte_InvalidValue_ETAT_DA_DYN (0U)
# define InvalidValue_ETAT_DA_DYN (0U)

# define Rte_TypeDef_ETAT_LIGNE_APC
typedef boolean ETAT_LIGNE_APC;

# define Rte_TypeDef_ETAT_SECU_ANGLE_COL
typedef boolean ETAT_SECU_ANGLE_COL;

# define Rte_TypeDef_FLG_AVOL_ICN
typedef boolean FLG_AVOL_ICN;

# define Rte_TypeDef_FLG_INIT_AVOL
typedef boolean FLG_INIT_AVOL;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_IoHwAb_BoolType
typedef uint8 IoHwAb_BoolType;
# define IoHwAb_BoolType_LowerLimit (0U)
# define IoHwAb_BoolType_UpperLimit (1U)

# define Rte_TypeDef_SENS_ROT_VOL
typedef boolean SENS_ROT_VOL;

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit (-32768)
# define SInt16_UpperLimit (32767)

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define SInt32_LowerLimit (-2147483648)
# define SInt32_UpperLimit (2147483647)

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define SInt8_LowerLimit (-128)
# define SInt8_UpperLimit (127)

# define Rte_TypeDef_STATUS_CONFABSENT
typedef uint32 STATUS_CONFABSENT;
# define STATUS_CONFABSENT_LowerLimit (0U)
# define STATUS_CONFABSENT_UpperLimit (4294967295U)
# define Rte_InvalidValue_STATUS_CONFABSENT (0U)
# define InvalidValue_STATUS_CONFABSENT (0U)

# define Rte_TypeDef_STEERWHL_HOLD_BY_DRV
typedef boolean STEERWHL_HOLD_BY_DRV;

# define Rte_TypeDef_TRIM_VOL
typedef boolean TRIM_VOL;
# define Rte_InvalidValue_TRIM_VOL (1)
# define InvalidValue_TRIM_VOL (1)

# define Rte_TypeDef_TRQ_LIMIT_STATE
typedef boolean TRQ_LIMIT_STATE;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit (0U)
# define UInt8_UpperLimit (255U)

# define Rte_TypeDef_VITESSE_COLONNE
typedef sint16 VITESSE_COLONNE;
# define VITESSE_COLONNE_LowerLimit (-2000)
# define VITESSE_COLONNE_UpperLimit (2000)

# define Rte_TypeDef_VITESSE_ROT_VOL
typedef uint8 VITESSE_ROT_VOL;
# define VITESSE_ROT_VOL_LowerLimit (0U)
# define VITESSE_ROT_VOL_UpperLimit (254U)
# define Rte_InvalidValue_VITESSE_ROT_VOL (0U)
# define InvalidValue_VITESSE_ROT_VOL (0U)

# define Rte_TypeDef_VITESSE_ROT_VOL_OPTIMISE
typedef uint8 VITESSE_ROT_VOL_OPTIMISE;
# define VITESSE_ROT_VOL_OPTIMISE_LowerLimit (0U)
# define VITESSE_ROT_VOL_OPTIMISE_UpperLimit (255U)
# define Rte_InvalidValue_VITESSE_ROT_VOL_OPTIMISE (0U)
# define InvalidValue_VITESSE_ROT_VOL_OPTIMISE (0U)

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;
# define WdgM_CheckpointIdType_LowerLimit (0U)
# define WdgM_CheckpointIdType_UpperLimit (65535U)

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
# define WdgM_ModeType_LowerLimit (0U)
# define WdgM_ModeType_UpperLimit (255U)

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;
# define WdgM_SupervisedEntityIdType_LowerLimit (0U)
# define WdgM_SupervisedEntityIdType_UpperLimit (65535U)

# define Rte_TypeDef_APA_State_enum
typedef uint8 APA_State_enum;
# define APA_State_enum_LowerLimit (0U)
# define APA_State_enum_UpperLimit (4U)
# if (defined RTE_CONST_APA_TempInhibit) || (defined APA_TempInhibit)
#  if (!defined RTE_CONST_APA_TempInhibit) || (RTE_CONST_APA_TempInhibit != 0U)
#   error "Enumeration constant <APA_TempInhibit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_APA_TempInhibit (0U)
#  define APA_TempInhibit (0U)
# endif
# if (defined RTE_CONST_APA_AvailCntrl) || (defined APA_AvailCntrl)
#  if (!defined RTE_CONST_APA_AvailCntrl) || (RTE_CONST_APA_AvailCntrl != 1U)
#   error "Enumeration constant <APA_AvailCntrl> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_APA_AvailCntrl (1U)
#  define APA_AvailCntrl (1U)
# endif
# if (defined RTE_CONST_APA_Active) || (defined APA_Active)
#  if (!defined RTE_CONST_APA_Active) || (RTE_CONST_APA_Active != 2U)
#   error "Enumeration constant <APA_Active> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_APA_Active (2U)
#  define APA_Active (2U)
# endif
# if (defined RTE_CONST_APA_PermanentlyFailed) || (defined APA_PermanentlyFailed)
#  if (!defined RTE_CONST_APA_PermanentlyFailed) || (RTE_CONST_APA_PermanentlyFailed != 3U)
#   error "Enumeration constant <APA_PermanentlyFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_APA_PermanentlyFailed (3U)
#  define APA_PermanentlyFailed (3U)
# endif
# if (defined RTE_CONST_APA_ManufacturingDisable) || (defined APA_ManufacturingDisable)
#  if (!defined RTE_CONST_APA_ManufacturingDisable) || (RTE_CONST_APA_ManufacturingDisable != 4U)
#   error "Enumeration constant <APA_ManufacturingDisable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_APA_ManufacturingDisable (4U)
#  define APA_ManufacturingDisable (4U)
# endif

# define Rte_TypeDef_ApaAbortSt_State_enum
typedef uint8 ApaAbortSt_State_enum;
# define ApaAbortSt_State_enum_LowerLimit (0U)
# define ApaAbortSt_State_enum_UpperLimit (7U)
# if (defined RTE_CONST_CAAPAABORTST_NODRVGINTRPT) || (defined CAAPAABORTST_NODRVGINTRPT)
#  if (!defined RTE_CONST_CAAPAABORTST_NODRVGINTRPT) || (RTE_CONST_CAAPAABORTST_NODRVGINTRPT != 0U)
#   error "Enumeration constant <CAAPAABORTST_NODRVGINTRPT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_NODRVGINTRPT (0U)
#  define CAAPAABORTST_NODRVGINTRPT (0U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_DRVRRCVRY) || (defined CAAPAABORTST_DRVRRCVRY)
#  if (!defined RTE_CONST_CAAPAABORTST_DRVRRCVRY) || (RTE_CONST_CAAPAABORTST_DRVRRCVRY != 1U)
#   error "Enumeration constant <CAAPAABORTST_DRVRRCVRY> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_DRVRRCVRY (1U)
#  define CAAPAABORTST_DRVRRCVRY (1U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_HIVEHSPDERR) || (defined CAAPAABORTST_HIVEHSPDERR)
#  if (!defined RTE_CONST_CAAPAABORTST_HIVEHSPDERR) || (RTE_CONST_CAAPAABORTST_HIVEHSPDERR != 2U)
#   error "Enumeration constant <CAAPAABORTST_HIVEHSPDERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_HIVEHSPDERR (2U)
#  define CAAPAABORTST_HIVEHSPDERR (2U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_AGRDELTAERR) || (defined CAAPAABORTST_AGRDELTAERR)
#  if (!defined RTE_CONST_CAAPAABORTST_AGRDELTAERR) || (RTE_CONST_CAAPAABORTST_AGRDELTAERR != 3U)
#   error "Enumeration constant <CAAPAABORTST_AGRDELTAERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_AGRDELTAERR (3U)
#  define CAAPAABORTST_AGRDELTAERR (3U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_AGRSPDERR) || (defined CAAPAABORTST_AGRSPDERR)
#  if (!defined RTE_CONST_CAAPAABORTST_AGRSPDERR) || (RTE_CONST_CAAPAABORTST_AGRSPDERR != 4U)
#   error "Enumeration constant <CAAPAABORTST_AGRSPDERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_AGRSPDERR (4U)
#  define CAAPAABORTST_AGRSPDERR (4U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_THERMLIM) || (defined CAAPAABORTST_THERMLIM)
#  if (!defined RTE_CONST_CAAPAABORTST_THERMLIM) || (RTE_CONST_CAAPAABORTST_THERMLIM != 5U)
#   error "Enumeration constant <CAAPAABORTST_THERMLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_THERMLIM (5U)
#  define CAAPAABORTST_THERMLIM (5U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_ASSISTALLLIM) || (defined CAAPAABORTST_ASSISTALLLIM)
#  if (!defined RTE_CONST_CAAPAABORTST_ASSISTALLLIM) || (RTE_CONST_CAAPAABORTST_ASSISTALLLIM != 6U)
#   error "Enumeration constant <CAAPAABORTST_ASSISTALLLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_ASSISTALLLIM (6U)
#  define CAAPAABORTST_ASSISTALLLIM (6U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_RESD) || (defined CAAPAABORTST_RESD)
#  if (!defined RTE_CONST_CAAPAABORTST_RESD) || (RTE_CONST_CAAPAABORTST_RESD != 7U)
#   error "Enumeration constant <CAAPAABORTST_RESD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_RESD (7U)
#  define CAAPAABORTST_RESD (7U)
# endif

# define Rte_TypeDef_ApaReqSt_State_enum
typedef uint8 ApaReqSt_State_enum;
# define ApaReqSt_State_enum_LowerLimit (0U)
# define ApaReqSt_State_enum_UpperLimit (2U)
# if (defined RTE_CONST_CAAPAREQST_NOREQ) || (defined CAAPAREQST_NOREQ)
#  if (!defined RTE_CONST_CAAPAREQST_NOREQ) || (RTE_CONST_CAAPAREQST_NOREQ != 0U)
#   error "Enumeration constant <CAAPAREQST_NOREQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_NOREQ (0U)
#  define CAAPAREQST_NOREQ (0U)
# endif
# if (defined RTE_CONST_CAAPAREQST_REQCTRL) || (defined CAAPAREQST_REQCTRL)
#  if (!defined RTE_CONST_CAAPAREQST_REQCTRL) || (RTE_CONST_CAAPAREQST_REQCTRL != 1U)
#   error "Enumeration constant <CAAPAREQST_REQCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_REQCTRL (1U)
#  define CAAPAREQST_REQCTRL (1U)
# endif
# if (defined RTE_CONST_CAAPAREQST_CTRLACTV) || (defined CAAPAREQST_CTRLACTV)
#  if (!defined RTE_CONST_CAAPAREQST_CTRLACTV) || (RTE_CONST_CAAPAREQST_CTRLACTV != 2U)
#   error "Enumeration constant <CAAPAREQST_CTRLACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_CTRLACTV (2U)
#  define CAAPAREQST_CTRLACTV (2U)
# endif

# define Rte_TypeDef_BattSwdVltgCorrSts_Cnt_enum
typedef uint8 BattSwdVltgCorrSts_Cnt_enum;
# define BattSwdVltgCorrSts_Cnt_enum_LowerLimit (0U)
# define BattSwdVltgCorrSts_Cnt_enum_UpperLimit (4U)
# if (defined RTE_CONST_BSVCS_NOFLT) || (defined BSVCS_NOFLT)
#  if (!defined RTE_CONST_BSVCS_NOFLT) || (RTE_CONST_BSVCS_NOFLT != 0U)
#   error "Enumeration constant <BSVCS_NOFLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_NOFLT (0U)
#  define BSVCS_NOFLT (0U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGSWD2FLT) || (defined BSVCS_BATTVLTGSWD2FLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGSWD2FLT) || (RTE_CONST_BSVCS_BATTVLTGSWD2FLT != 1U)
#   error "Enumeration constant <BSVCS_BATTVLTGSWD2FLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGSWD2FLT (1U)
#  define BSVCS_BATTVLTGSWD2FLT (1U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGSWD1FLT) || (defined BSVCS_BATTVLTGSWD1FLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGSWD1FLT) || (RTE_CONST_BSVCS_BATTVLTGSWD1FLT != 2U)
#   error "Enumeration constant <BSVCS_BATTVLTGSWD1FLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGSWD1FLT (2U)
#  define BSVCS_BATTVLTGSWD1FLT (2U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGFLT) || (defined BSVCS_BATTVLTGFLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGFLT) || (RTE_CONST_BSVCS_BATTVLTGFLT != 3U)
#   error "Enumeration constant <BSVCS_BATTVLTGFLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGFLT (3U)
#  define BSVCS_BATTVLTGFLT (3U)
# endif
# if (defined RTE_CONST_BSVCS_NOCORRLN) || (defined BSVCS_NOCORRLN)
#  if (!defined RTE_CONST_BSVCS_NOCORRLN) || (RTE_CONST_BSVCS_NOCORRLN != 4U)
#   error "Enumeration constant <BSVCS_NOCORRLN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_NOCORRLN (4U)
#  define BSVCS_NOCORRLN (4U)
# endif

# define Rte_TypeDef_BattVltgSt_Cnt_enum
typedef uint8 BattVltgSt_Cnt_enum;
# define BattVltgSt_Cnt_enum_LowerLimit (0U)
# define BattVltgSt_Cnt_enum_UpperLimit (6U)
# if (defined RTE_CONST_SYSPRFMNCST_NORMOPER) || (defined SYSPRFMNCST_NORMOPER)
#  if (!defined RTE_CONST_SYSPRFMNCST_NORMOPER) || (RTE_CONST_SYSPRFMNCST_NORMOPER != 0U)
#   error "Enumeration constant <SYSPRFMNCST_NORMOPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_NORMOPER (0U)
#  define SYSPRFMNCST_NORMOPER (0U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGWARN) || (defined SYSPRFMNCST_HIVLTGWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGWARN) || (RTE_CONST_SYSPRFMNCST_HIVLTGWARN != 1U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGWARN (1U)
#  define SYSPRFMNCST_HIVLTGWARN (1U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGCRIT) || (defined SYSPRFMNCST_HIVLTGCRIT)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGCRIT) || (RTE_CONST_SYSPRFMNCST_HIVLTGCRIT != 2U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGCRIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGCRIT (2U)
#  define SYSPRFMNCST_HIVLTGCRIT (2U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGOFF) || (defined SYSPRFMNCST_HIVLTGOFF)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGOFF) || (RTE_CONST_SYSPRFMNCST_HIVLTGOFF != 3U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGOFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGOFF (3U)
#  define SYSPRFMNCST_HIVLTGOFF (3U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGWARN) || (defined SYSPRFMNCST_LOVLTGWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGWARN) || (RTE_CONST_SYSPRFMNCST_LOVLTGWARN != 4U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGWARN (4U)
#  define SYSPRFMNCST_LOVLTGWARN (4U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGCRIT) || (defined SYSPRFMNCST_LOVLTGCRIT)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGCRIT) || (RTE_CONST_SYSPRFMNCST_LOVLTGCRIT != 5U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGCRIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGCRIT (5U)
#  define SYSPRFMNCST_LOVLTGCRIT (5U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGOFF) || (defined SYSPRFMNCST_LOVLTGOFF)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGOFF) || (RTE_CONST_SYSPRFMNCST_LOVLTGOFF != 6U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGOFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGOFF (6U)
#  define SYSPRFMNCST_LOVLTGOFF (6U)
# endif

# define Rte_TypeDef_BmwDrvgDynIfSt_State_enum
typedef uint8 BmwDrvgDynIfSt_State_enum;
# define BmwDrvgDynIfSt_State_enum_LowerLimit (32U)
# define BmwDrvgDynIfSt_State_enum_UpperLimit (255U)
# if (defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (defined Cx20_Schnittstelle_verfuegbar___funktionsbereit)
#  if (!defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit != 32U)
#   error "Enumeration constant <Cx20_Schnittstelle_verfuegbar___funktionsbereit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit (32U)
#  define Cx20_Schnittstelle_verfuegbar___funktionsbereit (32U)
# endif
# if (defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (defined Cx21_Schnittstelle_aktiv)
#  if (!defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (RTE_CONST_Cx21_Schnittstelle_aktiv != 33U)
#   error "Enumeration constant <Cx21_Schnittstelle_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Schnittstelle_aktiv (33U)
#  define Cx21_Schnittstelle_aktiv (33U)
# endif
# if (defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (defined Cx60_Service_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler != 96U)
#   error "Enumeration constant <Cx60_Service_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler (96U)
#  define Cx60_Service_nicht_verfuegbar___Fehler (96U)
# endif
# if (defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (defined Cx80_Schnittstelle_wird_initialisiert)
#  if (!defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (RTE_CONST_Cx80_Schnittstelle_wird_initialisiert != 128U)
#   error "Enumeration constant <Cx80_Schnittstelle_wird_initialisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Schnittstelle_wird_initialisiert (128U)
#  define Cx80_Schnittstelle_wird_initialisiert (128U)
# endif
# if (defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (defined CxE0_Service_nicht_verfuegbar___Standby___PMA)
#  if (!defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA != 224U)
#   error "Enumeration constant <CxE0_Service_nicht_verfuegbar___Standby___PMA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA (224U)
#  define CxE0_Service_nicht_verfuegbar___Standby___PMA (224U)
# endif
# if (defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (defined CxE1_Service_nicht_verfuegbar___Standby___EPS_Status)
#  if (!defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status != 225U)
#   error "Enumeration constant <CxE1_Service_nicht_verfuegbar___Standby___EPS_Status> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225U)
#  define CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225U)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255U)
#  define CxFF_Signal_ungueltig (255U)
# endif

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;
# define Dem_DTCKindType_LowerLimit (1U)
# define Dem_DTCKindType_UpperLimit (2U)
# if (defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (defined DEM_DTC_KIND_ALL_DTCS)
#  if (!defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (RTE_CONST_DEM_DTC_KIND_ALL_DTCS != 1U)
#   error "Enumeration constant <DEM_DTC_KIND_ALL_DTCS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_DTC_KIND_ALL_DTCS (1U)
#  define DEM_DTC_KIND_ALL_DTCS (1U)
# endif
# if (defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (defined DEM_DTC_KIND_EMISSION_REL_DTCS)
#  if (!defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS != 2U)
#   error "Enumeration constant <DEM_DTC_KIND_EMISSION_REL_DTCS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
#  define DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
# endif

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;
# define Dem_EventStatusType_LowerLimit (0U)
# define Dem_EventStatusType_UpperLimit (255U)
# if (defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (defined DEM_EVENT_STATUS_PASSED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (RTE_CONST_DEM_EVENT_STATUS_PASSED != 0U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PASSED (0U)
#  define DEM_EVENT_STATUS_PASSED (0U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (defined DEM_EVENT_STATUS_FAILED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (RTE_CONST_DEM_EVENT_STATUS_FAILED != 1U)
#   error "Enumeration constant <DEM_EVENT_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_FAILED (1U)
#  define DEM_EVENT_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (defined DEM_EVENT_STATUS_PREPASSED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (RTE_CONST_DEM_EVENT_STATUS_PREPASSED != 2U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PREPASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PREPASSED (2U)
#  define DEM_EVENT_STATUS_PREPASSED (2U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (defined DEM_EVENT_STATUS_PREFAILED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (RTE_CONST_DEM_EVENT_STATUS_PREFAILED != 3U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PREFAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PREFAILED (3U)
#  define DEM_EVENT_STATUS_PREFAILED (3U)
# endif

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
# define Dem_IndicatorStatusType_LowerLimit (0U)
# define Dem_IndicatorStatusType_UpperLimit (3U)
# if (defined RTE_CONST_DEM_INDICATOR_OFF) || (defined DEM_INDICATOR_OFF)
#  if (!defined RTE_CONST_DEM_INDICATOR_OFF) || (RTE_CONST_DEM_INDICATOR_OFF != 0U)
#   error "Enumeration constant <DEM_INDICATOR_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_OFF (0U)
#  define DEM_INDICATOR_OFF (0U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (defined DEM_INDICATOR_CONTINUOUS)
#  if (!defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (RTE_CONST_DEM_INDICATOR_CONTINUOUS != 1U)
#   error "Enumeration constant <DEM_INDICATOR_CONTINUOUS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_CONTINUOUS (1U)
#  define DEM_INDICATOR_CONTINUOUS (1U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_BLINKING) || (defined DEM_INDICATOR_BLINKING)
#  if (!defined RTE_CONST_DEM_INDICATOR_BLINKING) || (RTE_CONST_DEM_INDICATOR_BLINKING != 2U)
#   error "Enumeration constant <DEM_INDICATOR_BLINKING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_BLINKING (2U)
#  define DEM_INDICATOR_BLINKING (2U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (defined DEM_INDICATOR_BLINK_CONT)
#  if (!defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (RTE_CONST_DEM_INDICATOR_BLINK_CONT != 3U)
#   error "Enumeration constant <DEM_INDICATOR_BLINK_CONT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_BLINK_CONT (3U)
#  define DEM_INDICATOR_BLINK_CONT (3U)
# endif

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;
# define Dem_OperationCycleStateType_LowerLimit (1U)
# define Dem_OperationCycleStateType_UpperLimit (2U)
# if (defined RTE_CONST_DEM_CYCLE_STATE_START) || (defined DEM_CYCLE_STATE_START)
#  if (!defined RTE_CONST_DEM_CYCLE_STATE_START) || (RTE_CONST_DEM_CYCLE_STATE_START != 1U)
#   error "Enumeration constant <DEM_CYCLE_STATE_START> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_CYCLE_STATE_START (1U)
#  define DEM_CYCLE_STATE_START (1U)
# endif
# if (defined RTE_CONST_DEM_CYCLE_STATE_END) || (defined DEM_CYCLE_STATE_END)
#  if (!defined RTE_CONST_DEM_CYCLE_STATE_END) || (RTE_CONST_DEM_CYCLE_STATE_END != 2U)
#   error "Enumeration constant <DEM_CYCLE_STATE_END> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_CYCLE_STATE_END (2U)
#  define DEM_CYCLE_STATE_END (2U)
# endif

# define Rte_TypeDef_DrvrModCtrl_enum
typedef uint8 DrvrModCtrl_enum;
# define DrvrModCtrl_enum_LowerLimit (1U)
# define DrvrModCtrl_enum_UpperLimit (4U)
# if (defined RTE_CONST_DMC_NORMAL) || (defined DMC_NORMAL)
#  if (!defined RTE_CONST_DMC_NORMAL) || (RTE_CONST_DMC_NORMAL != 1U)
#   error "Enumeration constant <DMC_NORMAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_NORMAL (1U)
#  define DMC_NORMAL (1U)
# endif
# if (defined RTE_CONST_DMC_SPORT) || (defined DMC_SPORT)
#  if (!defined RTE_CONST_DMC_SPORT) || (RTE_CONST_DMC_SPORT != 2U)
#   error "Enumeration constant <DMC_SPORT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_SPORT (2U)
#  define DMC_SPORT (2U)
# endif
# if (defined RTE_CONST_DMC_SNOW) || (defined DMC_SNOW)
#  if (!defined RTE_CONST_DMC_SNOW) || (RTE_CONST_DMC_SNOW != 3U)
#   error "Enumeration constant <DMC_SNOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_SNOW (3U)
#  define DMC_SNOW (3U)
# endif
# if (defined RTE_CONST_DMC_TOUR) || (defined DMC_TOUR)
#  if (!defined RTE_CONST_DMC_TOUR) || (RTE_CONST_DMC_TOUR != 4U)
#   error "Enumeration constant <DMC_TOUR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_TOUR (4U)
#  define DMC_TOUR (4U)
# endif

# define Rte_TypeDef_ESC_State_enum
typedef uint8 ESC_State_enum;
# define ESC_State_enum_LowerLimit (0U)
# define ESC_State_enum_UpperLimit (4U)
# if (defined RTE_CONST_ESC_Inactive) || (defined ESC_Inactive)
#  if (!defined RTE_CONST_ESC_Inactive) || (RTE_CONST_ESC_Inactive != 0U)
#   error "Enumeration constant <ESC_Inactive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ESC_Inactive (0U)
#  define ESC_Inactive (0U)
# endif
# if (defined RTE_CONST_ESC_Active) || (defined ESC_Active)
#  if (!defined RTE_CONST_ESC_Active) || (RTE_CONST_ESC_Active != 1U)
#   error "Enumeration constant <ESC_Active> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ESC_Active (1U)
#  define ESC_Active (1U)
# endif
# if (defined RTE_CONST_ESC_TemporarilyLimited) || (defined ESC_TemporarilyLimited)
#  if (!defined RTE_CONST_ESC_TemporarilyLimited) || (RTE_CONST_ESC_TemporarilyLimited != 2U)
#   error "Enumeration constant <ESC_TemporarilyLimited> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ESC_TemporarilyLimited (2U)
#  define ESC_TemporarilyLimited (2U)
# endif
# if (defined RTE_CONST_ESC_PermanentlyFailed) || (defined ESC_PermanentlyFailed)
#  if (!defined RTE_CONST_ESC_PermanentlyFailed) || (RTE_CONST_ESC_PermanentlyFailed != 3U)
#   error "Enumeration constant <ESC_PermanentlyFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ESC_PermanentlyFailed (3U)
#  define ESC_PermanentlyFailed (3U)
# endif
# if (defined RTE_CONST_ESC_ManufacturingDisable) || (defined ESC_ManufacturingDisable)
#  if (!defined RTE_CONST_ESC_ManufacturingDisable) || (RTE_CONST_ESC_ManufacturingDisable != 4U)
#   error "Enumeration constant <ESC_ManufacturingDisable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ESC_ManufacturingDisable (4U)
#  define ESC_ManufacturingDisable (4U)
# endif

# define Rte_TypeDef_EnergyModeStateType
typedef uint8 EnergyModeStateType;
# define EnergyModeStateType_LowerLimit (0U)
# define EnergyModeStateType_UpperLimit (3U)
# if (defined RTE_CONST_NORMAL) || (defined NORMAL)
#  if (!defined RTE_CONST_NORMAL) || (RTE_CONST_NORMAL != 0U)
#   error "Enumeration constant <NORMAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NORMAL (0U)
#  define NORMAL (0U)
# endif
# if (defined RTE_CONST_PRODUCTION) || (defined PRODUCTION)
#  if (!defined RTE_CONST_PRODUCTION) || (RTE_CONST_PRODUCTION != 1U)
#   error "Enumeration constant <PRODUCTION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PRODUCTION (1U)
#  define PRODUCTION (1U)
# endif
# if (defined RTE_CONST_TRANSPORTATION) || (defined TRANSPORTATION)
#  if (!defined RTE_CONST_TRANSPORTATION) || (RTE_CONST_TRANSPORTATION != 2U)
#   error "Enumeration constant <TRANSPORTATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TRANSPORTATION (2U)
#  define TRANSPORTATION (2U)
# endif
# if (defined RTE_CONST_FLASH) || (defined FLASH)
#  if (!defined RTE_CONST_FLASH) || (RTE_CONST_FLASH != 3U)
#   error "Enumeration constant <FLASH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLASH (3U)
#  define FLASH (3U)
# endif

# define Rte_TypeDef_FETFAULTTYPE_ENUM
typedef uint8 FETFAULTTYPE_ENUM;
# define FETFAULTTYPE_ENUM_LowerLimit (0U)
# define FETFAULTTYPE_ENUM_UpperLimit (255U)
# if (defined RTE_CONST_NOFAULT) || (defined NOFAULT)
#  if (!defined RTE_CONST_NOFAULT) || (RTE_CONST_NOFAULT != 0U)
#   error "Enumeration constant <NOFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NOFAULT (0U)
#  define NOFAULT (0U)
# endif
# if (defined RTE_CONST_LOWER) || (defined LOWER)
#  if (!defined RTE_CONST_LOWER) || (RTE_CONST_LOWER != 1U)
#   error "Enumeration constant <LOWER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOWER (1U)
#  define LOWER (1U)
# endif
# if (defined RTE_CONST_UPPER) || (defined UPPER)
#  if (!defined RTE_CONST_UPPER) || (RTE_CONST_UPPER != 2U)
#   error "Enumeration constant <UPPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_UPPER (2U)
#  define UPPER (2U)
# endif

# define Rte_TypeDef_FETPHASETYPE_ENUM
typedef uint8 FETPHASETYPE_ENUM;
# define FETPHASETYPE_ENUM_LowerLimit (0U)
# define FETPHASETYPE_ENUM_UpperLimit (255U)
# if (defined RTE_CONST_NOPHASE) || (defined NOPHASE)
#  if (!defined RTE_CONST_NOPHASE) || (RTE_CONST_NOPHASE != 0U)
#   error "Enumeration constant <NOPHASE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NOPHASE (0U)
#  define NOPHASE (0U)
# endif
# if (defined RTE_CONST_PHASEA) || (defined PHASEA)
#  if (!defined RTE_CONST_PHASEA) || (RTE_CONST_PHASEA != 1U)
#   error "Enumeration constant <PHASEA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEA (1U)
#  define PHASEA (1U)
# endif
# if (defined RTE_CONST_PHASEB) || (defined PHASEB)
#  if (!defined RTE_CONST_PHASEB) || (RTE_CONST_PHASEB != 2U)
#   error "Enumeration constant <PHASEB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEB (2U)
#  define PHASEB (2U)
# endif
# if (defined RTE_CONST_PHASEC) || (defined PHASEC)
#  if (!defined RTE_CONST_PHASEC) || (RTE_CONST_PHASEC != 3U)
#   error "Enumeration constant <PHASEC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEC (3U)
#  define PHASEC (3U)
# endif

# define Rte_TypeDef_FltInjectionLocType
typedef uint8 FltInjectionLocType;
# define FltInjectionLocType_LowerLimit (0U)
# define FltInjectionLocType_UpperLimit (255U)
# if (defined RTE_CONST_FLTINJ_ASSIST) || (defined FLTINJ_ASSIST)
#  if (!defined RTE_CONST_FLTINJ_ASSIST) || (RTE_CONST_FLTINJ_ASSIST != 1U)
#   error "Enumeration constant <FLTINJ_ASSIST> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSIST (1U)
#  define FLTINJ_ASSIST (1U)
# endif
# if (defined RTE_CONST_FLTINJ_RETURN) || (defined FLTINJ_RETURN)
#  if (!defined RTE_CONST_FLTINJ_RETURN) || (RTE_CONST_FLTINJ_RETURN != 2U)
#   error "Enumeration constant <FLTINJ_RETURN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_RETURN (2U)
#  define FLTINJ_RETURN (2U)
# endif
# if (defined RTE_CONST_FLTINJ_DAMPING) || (defined FLTINJ_DAMPING)
#  if (!defined RTE_CONST_FLTINJ_DAMPING) || (RTE_CONST_FLTINJ_DAMPING != 3U)
#   error "Enumeration constant <FLTINJ_DAMPING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DAMPING (3U)
#  define FLTINJ_DAMPING (3U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (defined FLTINJ_ASSTSUMNLMT)
#  if (!defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (RTE_CONST_FLTINJ_ASSTSUMNLMT != 4U)
#   error "Enumeration constant <FLTINJ_ASSTSUMNLMT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTSUMNLMT (4U)
#  define FLTINJ_ASSTSUMNLMT (4U)
# endif
# if (defined RTE_CONST_FLTINJ_AVGFRICLRN) || (defined FLTINJ_AVGFRICLRN)
#  if (!defined RTE_CONST_FLTINJ_AVGFRICLRN) || (RTE_CONST_FLTINJ_AVGFRICLRN != 7U)
#   error "Enumeration constant <FLTINJ_AVGFRICLRN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_AVGFRICLRN (7U)
#  define FLTINJ_AVGFRICLRN (7U)
# endif
# if (defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (defined FLTINJ_VECU_BATTERYVOLTAGE)
#  if (!defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE != 8U)
#   error "Enumeration constant <FLTINJ_VECU_BATTERYVOLTAGE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE (8U)
#  define FLTINJ_VECU_BATTERYVOLTAGE (8U)
# endif
# if (defined RTE_CONST_FLTINJ_HYSTCOMP) || (defined FLTINJ_HYSTCOMP)
#  if (!defined RTE_CONST_FLTINJ_HYSTCOMP) || (RTE_CONST_FLTINJ_HYSTCOMP != 12U)
#   error "Enumeration constant <FLTINJ_HYSTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_HYSTCOMP (12U)
#  define FLTINJ_HYSTCOMP (12U)
# endif
# if (defined RTE_CONST_FLTINJ_INERTIACOMP) || (defined FLTINJ_INERTIACOMP)
#  if (!defined RTE_CONST_FLTINJ_INERTIACOMP) || (RTE_CONST_FLTINJ_INERTIACOMP != 14U)
#   error "Enumeration constant <FLTINJ_INERTIACOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_INERTIACOMP (14U)
#  define FLTINJ_INERTIACOMP (14U)
# endif
# if (defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (defined FLTINJ_SUPPPWRLMT_CUSTPL)
#  if (!defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL != 25U)
#   error "Enumeration constant <FLTINJ_SUPPPWRLMT_CUSTPL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL (25U)
#  define FLTINJ_SUPPPWRLMT_CUSTPL (25U)
# endif
# if (defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (defined FLTINJ_EOTDAMPING_ETDMPFW)
#  if (!defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW != 27U)
#   error "Enumeration constant <FLTINJ_EOTDAMPING_ETDMPFW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW (27U)
#  define FLTINJ_EOTDAMPING_ETDMPFW (27U)
# endif
# if (defined RTE_CONST_FLTINJ_STABILITYCOMP) || (defined FLTINJ_STABILITYCOMP)
#  if (!defined RTE_CONST_FLTINJ_STABILITYCOMP) || (RTE_CONST_FLTINJ_STABILITYCOMP != 29U)
#   error "Enumeration constant <FLTINJ_STABILITYCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_STABILITYCOMP (29U)
#  define FLTINJ_STABILITYCOMP (29U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (defined FLTINJ_TRQBASEDINRTCOMP)
#  if (!defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (RTE_CONST_FLTINJ_TRQBASEDINRTCOMP != 30U)
#   error "Enumeration constant <FLTINJ_TRQBASEDINRTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQBASEDINRTCOMP (30U)
#  define FLTINJ_TRQBASEDINRTCOMP (30U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (defined FLTINJ_SRLCOMVEHSPD_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND != 33U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHSPD_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
#  define FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (defined FLTINJ_ASSTFIREWALL)
#  if (!defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (RTE_CONST_FLTINJ_ASSTFIREWALL != 34U)
#   error "Enumeration constant <FLTINJ_ASSTFIREWALL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTFIREWALL (34U)
#  define FLTINJ_ASSTFIREWALL (34U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (defined FLTINJ_ASSTEOTGAIN_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD != 38U)
#   error "Enumeration constant <FLTINJ_ASSTEOTGAIN_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
#  define FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (defined FLTINJ_ANAHWTRQT1)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (RTE_CONST_FLTINJ_ANAHWTRQT1 != 39U)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT1 (39U)
#  define FLTINJ_ANAHWTRQT1 (39U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (defined FLTINJ_ANAHWTRQT2)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (RTE_CONST_FLTINJ_ANAHWTRQT2 != 40U)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT2 (40U)
#  define FLTINJ_ANAHWTRQT2 (40U)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (defined FLTINJ_DIGHWTRQSENT_T1FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT != 41U)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T1FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT (41U)
#  define FLTINJ_DIGHWTRQSENT_T1FAULT (41U)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (defined FLTINJ_DIGHWTRQSENT_T2FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT != 42U)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T2FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT (42U)
#  define FLTINJ_DIGHWTRQSENT_T2FAULT (42U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (defined FLTINJ_TRQOSC_PREFINALCOMMAND)
#  if (!defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND != 43U)
#   error "Enumeration constant <FLTINJ_TRQOSC_PREFINALCOMMAND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND (43U)
#  define FLTINJ_TRQOSC_PREFINALCOMMAND (43U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (defined FLTINJ_IMCARBCROLLGCNTR)
#  if (!defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (RTE_CONST_FLTINJ_IMCARBCROLLGCNTR != 44U)
#   error "Enumeration constant <FLTINJ_IMCARBCROLLGCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBCROLLGCNTR (44U)
#  define FLTINJ_IMCARBCROLLGCNTR (44U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRCRC) || (defined FLTINJ_IMCARBRCRC)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRCRC) || (RTE_CONST_FLTINJ_IMCARBRCRC != 45U)
#   error "Enumeration constant <FLTINJ_IMCARBRCRC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRCRC (45U)
#  define FLTINJ_IMCARBRCRC (45U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRDATA) || (defined FLTINJ_IMCARBRDATA)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRDATA) || (RTE_CONST_FLTINJ_IMCARBRDATA != 46U)
#   error "Enumeration constant <FLTINJ_IMCARBRDATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRDATA (46U)
#  define FLTINJ_IMCARBRDATA (46U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (defined FLTINJ_GCCDIAG_HWTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_HWTRQ != 46U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_HWTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_HWTRQ (46U)
#  define FLTINJ_GCCDIAG_HWTRQ (46U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (defined FLTINJ_IMCARBRPATIDN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (RTE_CONST_FLTINJ_IMCARBRPATIDN != 47U)
#   error "Enumeration constant <FLTINJ_IMCARBRPATIDN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRPATIDN (47U)
#  define FLTINJ_IMCARBRPATIDN (47U)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR1) || (defined FLTINJ_CMMTRCURR1)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR1) || (RTE_CONST_FLTINJ_CMMTRCURR1 != 48U)
#   error "Enumeration constant <FLTINJ_CMMTRCURR1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR1 (48U)
#  define FLTINJ_CMMTRCURR1 (48U)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR2) || (defined FLTINJ_CMMTRCURR2)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR2) || (RTE_CONST_FLTINJ_CMMTRCURR2 != 49U)
#   error "Enumeration constant <FLTINJ_CMMTRCURR2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR2 (49U)
#  define FLTINJ_CMMTRCURR2 (49U)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (defined FLTINJ_NHET1CFGANDUSE1)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE1 != 50U)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE1 (50U)
#  define FLTINJ_NHET1CFGANDUSE1 (50U)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (defined FLTINJ_NHET1CFGANDUSE2)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE2 != 51U)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE2 (51U)
#  define FLTINJ_NHET1CFGANDUSE2 (51U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP1) || (defined FLTINJ_EPWM_UP1)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP1) || (RTE_CONST_FLTINJ_EPWM_UP1 != 52U)
#   error "Enumeration constant <FLTINJ_EPWM_UP1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP1 (52U)
#  define FLTINJ_EPWM_UP1 (52U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP2) || (defined FLTINJ_EPWM_UP2)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP2) || (RTE_CONST_FLTINJ_EPWM_UP2 != 53U)
#   error "Enumeration constant <FLTINJ_EPWM_UP2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP2 (53U)
#  define FLTINJ_EPWM_UP2 (53U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP3) || (defined FLTINJ_EPWM_UP3)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP3) || (RTE_CONST_FLTINJ_EPWM_UP3 != 54U)
#   error "Enumeration constant <FLTINJ_EPWM_UP3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP3 (54U)
#  define FLTINJ_EPWM_UP3 (54U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (defined FLTINJ_IMCARBROPENCAN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (RTE_CONST_FLTINJ_IMCARBROPENCAN != 65U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCAN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCAN (65U)
#  define FLTINJ_IMCARBROPENCAN (65U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (defined FLTINJ_IMCARBROPENCANSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (RTE_CONST_FLTINJ_IMCARBROPENCANSCI != 66U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCANSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCANSCI (66U)
#  define FLTINJ_IMCARBROPENCANSCI (66U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (defined FLTINJ_IMCARBROPENSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (RTE_CONST_FLTINJ_IMCARBROPENSCI != 67U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENSCI (67U)
#  define FLTINJ_IMCARBROPENSCI (67U)
# endif
# if (defined RTE_CONST_FLTINJ_BMWTOC) || (defined FLTINJ_BMWTOC)
#  if (!defined RTE_CONST_FLTINJ_BMWTOC) || (RTE_CONST_FLTINJ_BMWTOC != 68U)
#   error "Enumeration constant <FLTINJ_BMWTOC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_BMWTOC (68U)
#  define FLTINJ_BMWTOC (68U)
# endif
# if (defined RTE_CONST_FLTINJ_PULLCMPACTV) || (defined FLTINJ_PULLCMPACTV)
#  if (!defined RTE_CONST_FLTINJ_PULLCMPACTV) || (RTE_CONST_FLTINJ_PULLCMPACTV != 69U)
#   error "Enumeration constant <FLTINJ_PULLCMPACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PULLCMPACTV (69U)
#  define FLTINJ_PULLCMPACTV (69U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (defined FLTINJ_TRQOVLSTA_LKAFAULT)
#  if (!defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT != 91U)
#   error "Enumeration constant <FLTINJ_TRQOVLSTA_LKAFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT (91U)
#  define FLTINJ_TRQOVLSTA_LKAFAULT (91U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (defined FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND != 100U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100U)
#  define FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (defined FLTINJ_TRQARBLIM_LKACMD)
#  if (!defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (RTE_CONST_FLTINJ_TRQARBLIM_LKACMD != 101U)
#   error "Enumeration constant <FLTINJ_TRQARBLIM_LKACMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQARBLIM_LKACMD (101U)
#  define FLTINJ_TRQARBLIM_LKACMD (101U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (defined FLTINJ_GCCDIAG_VEHSPD)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (RTE_CONST_FLTINJ_GCCDIAG_VEHSPD != 146U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_VEHSPD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_VEHSPD (146U)
#  define FLTINJ_GCCDIAG_VEHSPD (146U)
# endif
# if (defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDASTFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL != 150U)
#   error "Enumeration constant <FLTINJ_DDASTFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
#  define FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
# endif
# if (defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDDMPFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL != 151U)
#   error "Enumeration constant <FLTINJ_DDDMPFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
#  define FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
# endif
# if (defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDRTNFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL != 152U)
#   error "Enumeration constant <FLTINJ_DDRTNFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
#  define FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
# endif
# if (defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (defined FLTINJ_OUTPUTRAMPMULT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD != 153U)
#   error "Enumeration constant <FLTINJ_OUTPUTRAMPMULT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
#  define FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (defined FLTINJ_ASSTEOTLIMIT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD != 154U)
#   error "Enumeration constant <FLTINJ_ASSTEOTLIMIT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
#  define FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND != 155U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155U)
#  define FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (defined FLTINJ_ANAHWTORQUE)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (RTE_CONST_FLTINJ_ANAHWTORQUE != 156U)
#   error "Enumeration constant <FLTINJ_ANAHWTORQUE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTORQUE (156U)
#  define FLTINJ_ANAHWTORQUE (156U)
# endif
# if (defined RTE_CONST_FLTINJ_MTRVEL) || (defined FLTINJ_MTRVEL)
#  if (!defined RTE_CONST_FLTINJ_MTRVEL) || (RTE_CONST_FLTINJ_MTRVEL != 160U)
#   error "Enumeration constant <FLTINJ_MTRVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_MTRVEL (160U)
#  define FLTINJ_MTRVEL (160U)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (defined FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD != 200U)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200U)
#  define FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200U)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (defined FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR != 201U)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201U)
#  define FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (defined FLTINJ_GCCDIAG_MTRTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ != 246U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_MTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ (246U)
#  define FLTINJ_GCCDIAG_MTRTRQ (246U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND != 255U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255U)
#  define FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255U)
# endif

# define Rte_TypeDef_GmStrtStopSt_State_enum
typedef uint8 GmStrtStopSt_State_enum;
# define GmStrtStopSt_State_enum_LowerLimit (0U)
# define GmStrtStopSt_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_GMSTRTSTOPST_FCTINACTV) || (defined GMSTRTSTOPST_FCTINACTV)
#  if (!defined RTE_CONST_GMSTRTSTOPST_FCTINACTV) || (RTE_CONST_GMSTRTSTOPST_FCTINACTV != 0U)
#   error "Enumeration constant <GMSTRTSTOPST_FCTINACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_FCTINACTV (0U)
#  define GMSTRTSTOPST_FCTINACTV (0U)
# endif
# if (defined RTE_CONST_GMSTRTSTOPST_NORMMOD) || (defined GMSTRTSTOPST_NORMMOD)
#  if (!defined RTE_CONST_GMSTRTSTOPST_NORMMOD) || (RTE_CONST_GMSTRTSTOPST_NORMMOD != 1U)
#   error "Enumeration constant <GMSTRTSTOPST_NORMMOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_NORMMOD (1U)
#  define GMSTRTSTOPST_NORMMOD (1U)
# endif
# if (defined RTE_CONST_GMSTRTSTOPST_INTER1MOD) || (defined GMSTRTSTOPST_INTER1MOD)
#  if (!defined RTE_CONST_GMSTRTSTOPST_INTER1MOD) || (RTE_CONST_GMSTRTSTOPST_INTER1MOD != 2U)
#   error "Enumeration constant <GMSTRTSTOPST_INTER1MOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_INTER1MOD (2U)
#  define GMSTRTSTOPST_INTER1MOD (2U)
# endif
# if (defined RTE_CONST_GMSTRTSTOPST_INTER2MOD) || (defined GMSTRTSTOPST_INTER2MOD)
#  if (!defined RTE_CONST_GMSTRTSTOPST_INTER2MOD) || (RTE_CONST_GMSTRTSTOPST_INTER2MOD != 3U)
#   error "Enumeration constant <GMSTRTSTOPST_INTER2MOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_INTER2MOD (3U)
#  define GMSTRTSTOPST_INTER2MOD (3U)
# endif
# if (defined RTE_CONST_GMSTRTSTOPST_STOPMOD) || (defined GMSTRTSTOPST_STOPMOD)
#  if (!defined RTE_CONST_GMSTRTSTOPST_STOPMOD) || (RTE_CONST_GMSTRTSTOPST_STOPMOD != 4U)
#   error "Enumeration constant <GMSTRTSTOPST_STOPMOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_STOPMOD (4U)
#  define GMSTRTSTOPST_STOPMOD (4U)
# endif
# if (defined RTE_CONST_GMSTRTSTOPST_SPLRMFGMOD) || (defined GMSTRTSTOPST_SPLRMFGMOD)
#  if (!defined RTE_CONST_GMSTRTSTOPST_SPLRMFGMOD) || (RTE_CONST_GMSTRTSTOPST_SPLRMFGMOD != 5U)
#   error "Enumeration constant <GMSTRTSTOPST_SPLRMFGMOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_GMSTRTSTOPST_SPLRMFGMOD (5U)
#  define GMSTRTSTOPST_SPLRMFGMOD (5U)
# endif

# define Rte_TypeDef_Haptic_State_enum
typedef uint8 Haptic_State_enum;
# define Haptic_State_enum_LowerLimit (0U)
# define Haptic_State_enum_UpperLimit (2U)
# if (defined RTE_CONST_Haptic_Inactive) || (defined Haptic_Inactive)
#  if (!defined RTE_CONST_Haptic_Inactive) || (RTE_CONST_Haptic_Inactive != 0U)
#   error "Enumeration constant <Haptic_Inactive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Haptic_Inactive (0U)
#  define Haptic_Inactive (0U)
# endif
# if (defined RTE_CONST_Haptic_Active) || (defined Haptic_Active)
#  if (!defined RTE_CONST_Haptic_Active) || (RTE_CONST_Haptic_Active != 1U)
#   error "Enumeration constant <Haptic_Active> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Haptic_Active (1U)
#  define Haptic_Active (1U)
# endif
# if (defined RTE_CONST_Haptic_Waiting) || (defined Haptic_Waiting)
#  if (!defined RTE_CONST_Haptic_Waiting) || (RTE_CONST_Haptic_Waiting != 2U)
#   error "Enumeration constant <Haptic_Waiting> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Haptic_Waiting (2U)
#  define Haptic_Waiting (2U)
# endif

# define Rte_TypeDef_ImcArbrRxSts_enum
typedef uint8 ImcArbrRxSts_enum;
# define ImcArbrRxSts_enum_LowerLimit (0U)
# define ImcArbrRxSts_enum_UpperLimit (2U)
# if (defined RTE_CONST_IMCARBRRXSTS_NODATA) || (defined IMCARBRRXSTS_NODATA)
#  if (!defined RTE_CONST_IMCARBRRXSTS_NODATA) || (RTE_CONST_IMCARBRRXSTS_NODATA != 0U)
#   error "Enumeration constant <IMCARBRRXSTS_NODATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_NODATA (0U)
#  define IMCARBRRXSTS_NODATA (0U)
# endif
# if (defined RTE_CONST_IMCARBRRXSTS_VALID) || (defined IMCARBRRXSTS_VALID)
#  if (!defined RTE_CONST_IMCARBRRXSTS_VALID) || (RTE_CONST_IMCARBRRXSTS_VALID != 1U)
#   error "Enumeration constant <IMCARBRRXSTS_VALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_VALID (1U)
#  define IMCARBRRXSTS_VALID (1U)
# endif
# if (defined RTE_CONST_IMCARBRRXSTS_INVALID) || (defined IMCARBRRXSTS_INVALID)
#  if (!defined RTE_CONST_IMCARBRRXSTS_INVALID) || (RTE_CONST_IMCARBRRXSTS_INVALID != 2U)
#   error "Enumeration constant <IMCARBRRXSTS_INVALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_INVALID (2U)
#  define IMCARBRRXSTS_INVALID (2U)
# endif

# define Rte_TypeDef_LKA_State_enum
typedef uint8 LKA_State_enum;
# define LKA_State_enum_LowerLimit (0U)
# define LKA_State_enum_UpperLimit (4U)
# if (defined RTE_CONST_LKA_Inactive) || (defined LKA_Inactive)
#  if (!defined RTE_CONST_LKA_Inactive) || (RTE_CONST_LKA_Inactive != 0U)
#   error "Enumeration constant <LKA_Inactive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LKA_Inactive (0U)
#  define LKA_Inactive (0U)
# endif
# if (defined RTE_CONST_LKA_Active) || (defined LKA_Active)
#  if (!defined RTE_CONST_LKA_Active) || (RTE_CONST_LKA_Active != 1U)
#   error "Enumeration constant <LKA_Active> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LKA_Active (1U)
#  define LKA_Active (1U)
# endif
# if (defined RTE_CONST_LKA_TemporarilyLimited) || (defined LKA_TemporarilyLimited)
#  if (!defined RTE_CONST_LKA_TemporarilyLimited) || (RTE_CONST_LKA_TemporarilyLimited != 2U)
#   error "Enumeration constant <LKA_TemporarilyLimited> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LKA_TemporarilyLimited (2U)
#  define LKA_TemporarilyLimited (2U)
# endif
# if (defined RTE_CONST_LKA_PermanentlyFailed) || (defined LKA_PermanentlyFailed)
#  if (!defined RTE_CONST_LKA_PermanentlyFailed) || (RTE_CONST_LKA_PermanentlyFailed != 3U)
#   error "Enumeration constant <LKA_PermanentlyFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LKA_PermanentlyFailed (3U)
#  define LKA_PermanentlyFailed (3U)
# endif
# if (defined RTE_CONST_LKA_ManufacturingDisable) || (defined LKA_ManufacturingDisable)
#  if (!defined RTE_CONST_LKA_ManufacturingDisable) || (RTE_CONST_LKA_ManufacturingDisable != 4U)
#   error "Enumeration constant <LKA_ManufacturingDisable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LKA_ManufacturingDisable (4U)
#  define LKA_ManufacturingDisable (4U)
# endif

# define Rte_TypeDef_LOA_State_enum
typedef uint8 LOA_State_enum;
# define LOA_State_enum_LowerLimit (0U)
# define LOA_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_LOAST_NORM) || (defined LOAST_NORM)
#  if (!defined RTE_CONST_LOAST_NORM) || (RTE_CONST_LOAST_NORM != 0U)
#   error "Enumeration constant <LOAST_NORM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_NORM (0U)
#  define LOAST_NORM (0U)
# endif
# if (defined RTE_CONST_LOAST_REDCD) || (defined LOAST_REDCD)
#  if (!defined RTE_CONST_LOAST_REDCD) || (RTE_CONST_LOAST_REDCD != 1U)
#   error "Enumeration constant <LOAST_REDCD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_REDCD (1U)
#  define LOAST_REDCD (1U)
# endif
# if (defined RTE_CONST_LOAST_SWBASDMTGTN) || (defined LOAST_SWBASDMTGTN)
#  if (!defined RTE_CONST_LOAST_SWBASDMTGTN) || (RTE_CONST_LOAST_SWBASDMTGTN != 2U)
#   error "Enumeration constant <LOAST_SWBASDMTGTN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_SWBASDMTGTN (2U)
#  define LOAST_SWBASDMTGTN (2U)
# endif
# if (defined RTE_CONST_LOAST_FADEOUT) || (defined LOAST_FADEOUT)
#  if (!defined RTE_CONST_LOAST_FADEOUT) || (RTE_CONST_LOAST_FADEOUT != 3U)
#   error "Enumeration constant <LOAST_FADEOUT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_FADEOUT (3U)
#  define LOAST_FADEOUT (3U)
# endif
# if (defined RTE_CONST_LOAST_CTRLDSHTDWNREQD) || (defined LOAST_CTRLDSHTDWNREQD)
#  if (!defined RTE_CONST_LOAST_CTRLDSHTDWNREQD) || (RTE_CONST_LOAST_CTRLDSHTDWNREQD != 4U)
#   error "Enumeration constant <LOAST_CTRLDSHTDWNREQD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_CTRLDSHTDWNREQD (4U)
#  define LOAST_CTRLDSHTDWNREQD (4U)
# endif
# if (defined RTE_CONST_LOAST_RPDSHTDWNREQD) || (defined LOAST_RPDSHTDWNREQD)
#  if (!defined RTE_CONST_LOAST_RPDSHTDWNREQD) || (RTE_CONST_LOAST_RPDSHTDWNREQD != 5U)
#   error "Enumeration constant <LOAST_RPDSHTDWNREQD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_RPDSHTDWNREQD (5U)
#  define LOAST_RPDSHTDWNREQD (5U)
# endif

# define Rte_TypeDef_LdwSt_State_enum
typedef uint8 LdwSt_State_enum;
# define LdwSt_State_enum_LowerLimit (0U)
# define LdwSt_State_enum_UpperLimit (3U)
# if (defined RTE_CONST_CALDWST_HAPTCRDY) || (defined CALDWST_HAPTCRDY)
#  if (!defined RTE_CONST_CALDWST_HAPTCRDY) || (RTE_CONST_CALDWST_HAPTCRDY != 0U)
#   error "Enumeration constant <CALDWST_HAPTCRDY> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_HAPTCRDY (0U)
#  define CALDWST_HAPTCRDY (0U)
# endif
# if (defined RTE_CONST_CALDWST_HAPTCACTV) || (defined CALDWST_HAPTCACTV)
#  if (!defined RTE_CONST_CALDWST_HAPTCACTV) || (RTE_CONST_CALDWST_HAPTCACTV != 1U)
#   error "Enumeration constant <CALDWST_HAPTCACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_HAPTCACTV (1U)
#  define CALDWST_HAPTCACTV (1U)
# endif
# if (defined RTE_CONST_CALDWST_TMPLIMD) || (defined CALDWST_TMPLIMD)
#  if (!defined RTE_CONST_CALDWST_TMPLIMD) || (RTE_CONST_CALDWST_TMPLIMD != 2U)
#   error "Enumeration constant <CALDWST_TMPLIMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_TMPLIMD (2U)
#  define CALDWST_TMPLIMD (2U)
# endif
# if (defined RTE_CONST_CALDWST_DI) || (defined CALDWST_DI)
#  if (!defined RTE_CONST_CALDWST_DI) || (RTE_CONST_CALDWST_DI != 3U)
#   error "Enumeration constant <CALDWST_DI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_DI (3U)
#  define CALDWST_DI (3U)
# endif

# define Rte_TypeDef_LkaSt_State_enum
typedef uint8 LkaSt_State_enum;
# define LkaSt_State_enum_LowerLimit (0U)
# define LkaSt_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_CALKAST_TMPLIMD) || (defined CALKAST_TMPLIMD)
#  if (!defined RTE_CONST_CALKAST_TMPLIMD) || (RTE_CONST_CALKAST_TMPLIMD != 0U)
#   error "Enumeration constant <CALKAST_TMPLIMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_TMPLIMD (0U)
#  define CALKAST_TMPLIMD (0U)
# endif
# if (defined RTE_CONST_CALKAST_INACTV) || (defined CALKAST_INACTV)
#  if (!defined RTE_CONST_CALKAST_INACTV) || (RTE_CONST_CALKAST_INACTV != 1U)
#   error "Enumeration constant <CALKAST_INACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_INACTV (1U)
#  define CALKAST_INACTV (1U)
# endif
# if (defined RTE_CONST_CALKAST_ACTV) || (defined CALKAST_ACTV)
#  if (!defined RTE_CONST_CALKAST_ACTV) || (RTE_CONST_CALKAST_ACTV != 2U)
#   error "Enumeration constant <CALKAST_ACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_ACTV (2U)
#  define CALKAST_ACTV (2U)
# endif
# if (defined RTE_CONST_CALKAST_TMPFAILD) || (defined CALKAST_TMPFAILD)
#  if (!defined RTE_CONST_CALKAST_TMPFAILD) || (RTE_CONST_CALKAST_TMPFAILD != 3U)
#   error "Enumeration constant <CALKAST_TMPFAILD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_TMPFAILD (3U)
#  define CALKAST_TMPFAILD (3U)
# endif
# if (defined RTE_CONST_CALKAST_PRMNTFAILD) || (defined CALKAST_PRMNTFAILD)
#  if (!defined RTE_CONST_CALKAST_PRMNTFAILD) || (RTE_CONST_CALKAST_PRMNTFAILD != 4U)
#   error "Enumeration constant <CALKAST_PRMNTFAILD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_PRMNTFAILD (4U)
#  define CALKAST_PRMNTFAILD (4U)
# endif
# if (defined RTE_CONST_CALKAST_MFGDI) || (defined CALKAST_MFGDI)
#  if (!defined RTE_CONST_CALKAST_MFGDI) || (RTE_CONST_CALKAST_MFGDI != 5U)
#   error "Enumeration constant <CALKAST_MFGDI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_MFGDI (5U)
#  define CALKAST_MFGDI (5U)
# endif

# define Rte_TypeDef_ManufModeType
typedef uint8 ManufModeType;
# define ManufModeType_LowerLimit (0U)
# define ManufModeType_UpperLimit (2U)
# if (defined RTE_CONST_ProductionMode) || (defined ProductionMode)
#  if (!defined RTE_CONST_ProductionMode) || (RTE_CONST_ProductionMode != 0U)
#   error "Enumeration constant <ProductionMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ProductionMode (0U)
#  define ProductionMode (0U)
# endif
# if (defined RTE_CONST_ManufacturingMode) || (defined ManufacturingMode)
#  if (!defined RTE_CONST_ManufacturingMode) || (RTE_CONST_ManufacturingMode != 1U)
#   error "Enumeration constant <ManufacturingMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ManufacturingMode (1U)
#  define ManufacturingMode (1U)
# endif
# if (defined RTE_CONST_EngineeringMode) || (defined EngineeringMode)
#  if (!defined RTE_CONST_EngineeringMode) || (RTE_CONST_EngineeringMode != 2U)
#   error "Enumeration constant <EngineeringMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EngineeringMode (2U)
#  define EngineeringMode (2U)
# endif

# define Rte_TypeDef_MtrCurrOffProcessFlag
typedef uint8 MtrCurrOffProcessFlag;
# define MtrCurrOffProcessFlag_LowerLimit (0U)
# define MtrCurrOffProcessFlag_UpperLimit (4U)
# if (defined RTE_CONST_CURROFF_INIT) || (defined CURROFF_INIT)
#  if (!defined RTE_CONST_CURROFF_INIT) || (RTE_CONST_CURROFF_INIT != 0U)
#   error "Enumeration constant <CURROFF_INIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CURROFF_INIT (0U)
#  define CURROFF_INIT (0U)
# endif
# if (defined RTE_CONST_CURROFF_PROCESSING) || (defined CURROFF_PROCESSING)
#  if (!defined RTE_CONST_CURROFF_PROCESSING) || (RTE_CONST_CURROFF_PROCESSING != 1U)
#   error "Enumeration constant <CURROFF_PROCESSING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CURROFF_PROCESSING (1U)
#  define CURROFF_PROCESSING (1U)
# endif
# if (defined RTE_CONST_CURROFF_PASS) || (defined CURROFF_PASS)
#  if (!defined RTE_CONST_CURROFF_PASS) || (RTE_CONST_CURROFF_PASS != 2U)
#   error "Enumeration constant <CURROFF_PASS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CURROFF_PASS (2U)
#  define CURROFF_PASS (2U)
# endif
# if (defined RTE_CONST_CURROFF_FAIL) || (defined CURROFF_FAIL)
#  if (!defined RTE_CONST_CURROFF_FAIL) || (RTE_CONST_CURROFF_FAIL != 3U)
#   error "Enumeration constant <CURROFF_FAIL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CURROFF_FAIL (3U)
#  define CURROFF_FAIL (3U)
# endif

# define Rte_TypeDef_NTCNumber
typedef uint16 NTCNumber;
# define NTCNumber_LowerLimit (0U)
# define NTCNumber_UpperLimit (511U)
# if (defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (defined NTC_Num_FlashWrapperLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (RTE_CONST_NTC_Num_FlashWrapperLgcFlt != 1U)
#   error "Enumeration constant <NTC_Num_FlashWrapperLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashWrapperLgcFlt (1U)
#  define NTC_Num_FlashWrapperLgcFlt (1U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCCorr) || (defined NTC_Num_FlashECCCorr)
#  if (!defined RTE_CONST_NTC_Num_FlashECCCorr) || (RTE_CONST_NTC_Num_FlashECCCorr != 2U)
#   error "Enumeration constant <NTC_Num_FlashECCCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCCorr (2U)
#  define NTC_Num_FlashECCCorr (2U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (defined NTC_Num_FlashECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (RTE_CONST_NTC_Num_FlashECCMemFlt != 3U)
#   error "Enumeration constant <NTC_Num_FlashECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCMemFlt (3U)
#  define NTC_Num_FlashECCMemFlt (3U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (defined NTC_Num_FlashCRCMemFault)
#  if (!defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (RTE_CONST_NTC_Num_FlashCRCMemFault != 4U)
#   error "Enumeration constant <NTC_Num_FlashCRCMemFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashCRCMemFault (4U)
#  define NTC_Num_FlashCRCMemFault (4U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActA) || (defined NTC_Num_NvMBlkDftActA)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActA) || (RTE_CONST_NTC_Num_NvMBlkDftActA != 6U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActA (6U)
#  define NTC_Num_NvMBlkDftActA (6U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActB) || (defined NTC_Num_NvMBlkDftActB)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActB) || (RTE_CONST_NTC_Num_NvMBlkDftActB != 7U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActB (7U)
#  define NTC_Num_NvMBlkDftActB (7U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActC) || (defined NTC_Num_NvMBlkDftActC)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActC) || (RTE_CONST_NTC_Num_NvMBlkDftActC != 8U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActC (8U)
#  define NTC_Num_NvMBlkDftActC (8U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange) || (defined NTC_Num_CurrentSensorCalOutOfRange)
#  if (!defined RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange) || (RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange != 9U)
#   error "Enumeration constant <NTC_Num_CurrentSensorCalOutOfRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange (9U)
#  define NTC_Num_CurrentSensorCalOutOfRange (9U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiag) || (defined NTC_Num_EEPROMDiag)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiag) || (RTE_CONST_NTC_Num_EEPROMDiag != 10U)
#   error "Enumeration constant <NTC_Num_EEPROMDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiag (10U)
#  define NTC_Num_EEPROMDiag (10U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (defined NTC_Num_EEPROMDiagMtrStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (RTE_CONST_NTC_Num_EEPROMDiagMtrStr != 11U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagMtrStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagMtrStr (11U)
#  define NTC_Num_EEPROMDiagMtrStr (11U)
# endif
# if (defined RTE_CONST_NTC_Num_PriSnsrTrqStorFlt) || (defined NTC_Num_PriSnsrTrqStorFlt)
#  if (!defined RTE_CONST_NTC_Num_PriSnsrTrqStorFlt) || (RTE_CONST_NTC_Num_PriSnsrTrqStorFlt != 12U)
#   error "Enumeration constant <NTC_Num_PriSnsrTrqStorFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriSnsrTrqStorFlt (12U)
#  define NTC_Num_PriSnsrTrqStorFlt (12U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (defined NTC_Num_EEPROMDiagPosTrimStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr != 13U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPosTrimStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr (13U)
#  define NTC_Num_EEPROMDiagPosTrimStr (13U)
# endif
# if (defined RTE_CONST_NTC_Num_SecSnsrTrqStorFlt) || (defined NTC_Num_SecSnsrTrqStorFlt)
#  if (!defined RTE_CONST_NTC_Num_SecSnsrTrqStorFlt) || (RTE_CONST_NTC_Num_SecSnsrTrqStorFlt != 14U)
#   error "Enumeration constant <NTC_Num_SecSnsrTrqStorFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SecSnsrTrqStorFlt (14U)
#  define NTC_Num_SecSnsrTrqStorFlt (14U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (defined NTC_Num_EEPROMDiagPolarityStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (RTE_CONST_NTC_Num_EEPROMDiagPolarityStr != 15U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPolarityStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPolarityStr (15U)
#  define NTC_Num_EEPROMDiagPolarityStr (15U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (defined NTC_Num_RAMDiag_GeneralFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (RTE_CONST_NTC_Num_RAMDiag_GeneralFlt != 16U)
#   error "Enumeration constant <NTC_Num_RAMDiag_GeneralFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_GeneralFlt (16U)
#  define NTC_Num_RAMDiag_GeneralFlt (16U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (defined NTC_Num_RAMDiag_WrprLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt != 17U)
#   error "Enumeration constant <NTC_Num_RAMDiag_WrprLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt (17U)
#  define NTC_Num_RAMDiag_WrprLgcFlt (17U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (defined NTC_Num_RAMDiag_ECCCorrIndFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt != 18U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCCorrIndFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
#  define NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (defined NTC_Num_RAMDiag_ECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt != 19U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt (19U)
#  define NTC_Num_RAMDiag_ECCMemFlt (19U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (defined NTC_Num_RAMDiag_CRCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt != 20U)
#   error "Enumeration constant <NTC_Num_RAMDiag_CRCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt (20U)
#  define NTC_Num_RAMDiag_CRCMemFlt (20U)
# endif
# if (defined RTE_CONST_NTC_Num_PLLSlipNrcvrl) || (defined NTC_Num_PLLSlipNrcvrl)
#  if (!defined RTE_CONST_NTC_Num_PLLSlipNrcvrl) || (RTE_CONST_NTC_Num_PLLSlipNrcvrl != 22U)
#   error "Enumeration constant <NTC_Num_PLLSlipNrcvrl> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PLLSlipNrcvrl (22U)
#  define NTC_Num_PLLSlipNrcvrl (22U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (defined NTC_Num_RAMDiag_VIMRamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt != 23U)
#   error "Enumeration constant <NTC_Num_RAMDiag_VIMRamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt (23U)
#  define NTC_Num_RAMDiag_VIMRamFlt (23U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (defined NTC_Num_RAMDiag_NHET1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt != 24U)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt (24U)
#  define NTC_Num_RAMDiag_NHET1RamFlt (24U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (defined NTC_Num_RAMDiag_NHET2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt != 25U)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt (25U)
#  define NTC_Num_RAMDiag_NHET2RamFlt (25U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt) || (defined NTC_Num_RAMDiag_ADC1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt != 26U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADC1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt (26U)
#  define NTC_Num_RAMDiag_ADC1RamFlt (26U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_DCANRamFault) || (defined NTC_Num_RAMDiag_DCANRamFault)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_DCANRamFault) || (RTE_CONST_NTC_Num_RAMDiag_DCANRamFault != 27U)
#   error "Enumeration constant <NTC_Num_RAMDiag_DCANRamFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_DCANRamFault (27U)
#  define NTC_Num_RAMDiag_DCANRamFault (27U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt) || (defined NTC_Num_RAMDiag_ADC2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt != 28U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADC2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt (28U)
#  define NTC_Num_RAMDiag_ADC2RamFlt (28U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt) || (defined NTC_Num_RAMDiag_HETTU1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt != 29U)
#   error "Enumeration constant <NTC_Num_RAMDiag_HETTU1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt (29U)
#  define NTC_Num_RAMDiag_HETTU1RamFlt (29U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt) || (defined NTC_Num_RAMDiag_HETTU2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt != 30U)
#   error "Enumeration constant <NTC_Num_RAMDiag_HETTU2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt (30U)
#  define NTC_Num_RAMDiag_HETTU2RamFlt (30U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_RegVer) || (defined NTC_Num_CPU_RegVer)
#  if (!defined RTE_CONST_NTC_Num_CPU_RegVer) || (RTE_CONST_NTC_Num_CPU_RegVer != 32U)
#   error "Enumeration constant <NTC_Num_CPU_RegVer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_RegVer (32U)
#  define NTC_Num_CPU_RegVer (32U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (defined NTC_Num_CPU_CoreInitFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (RTE_CONST_NTC_Num_CPU_CoreInitFlt != 33U)
#   error "Enumeration constant <NTC_Num_CPU_CoreInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreInitFlt (33U)
#  define NTC_Num_CPU_CoreInitFlt (33U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (defined NTC_Num_CPU_CoreRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt != 34U)
#   error "Enumeration constant <NTC_Num_CPU_CoreRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt (34U)
#  define NTC_Num_CPU_CoreRunTimeFlt (34U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_ClockMon) || (defined NTC_Num_CPU_ClockMon)
#  if (!defined RTE_CONST_NTC_Num_CPU_ClockMon) || (RTE_CONST_NTC_Num_CPU_ClockMon != 35U)
#   error "Enumeration constant <NTC_Num_CPU_ClockMon> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_ClockMon (35U)
#  define NTC_Num_CPU_ClockMon (35U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_eFuseFlt) || (defined NTC_Num_CPU_eFuseFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_eFuseFlt) || (RTE_CONST_NTC_Num_CPU_eFuseFlt != 36U)
#   error "Enumeration constant <NTC_Num_CPU_eFuseFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_eFuseFlt (36U)
#  define NTC_Num_CPU_eFuseFlt (36U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_MPUViolation) || (defined NTC_Num_CPU_MPUViolation)
#  if (!defined RTE_CONST_NTC_Num_CPU_MPUViolation) || (RTE_CONST_NTC_Num_CPU_MPUViolation != 37U)
#   error "Enumeration constant <NTC_Num_CPU_MPUViolation> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_MPUViolation (37U)
#  define NTC_Num_CPU_MPUViolation (37U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_FactPrcsErr) || (defined NTC_Num_CPU_FactPrcsErr)
#  if (!defined RTE_CONST_NTC_Num_CPU_FactPrcsErr) || (RTE_CONST_NTC_Num_CPU_FactPrcsErr != 40U)
#   error "Enumeration constant <NTC_Num_CPU_FactPrcsErr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_FactPrcsErr (40U)
#  define NTC_Num_CPU_FactPrcsErr (40U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (defined NTC_Num_PropExeDiag_InitDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (RTE_CONST_NTC_Num_PropExeDiag_InitDiag != 41U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_InitDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_InitDiag (41U)
#  define NTC_Num_PropExeDiag_InitDiag (41U)
# endif
# if (defined RTE_CONST_NTC_Num_PrgFlwDeadlnFlt) || (defined NTC_Num_PrgFlwDeadlnFlt)
#  if (!defined RTE_CONST_NTC_Num_PrgFlwDeadlnFlt) || (RTE_CONST_NTC_Num_PrgFlwDeadlnFlt != 42U)
#   error "Enumeration constant <NTC_Num_PrgFlwDeadlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PrgFlwDeadlnFlt (42U)
#  define NTC_Num_PrgFlwDeadlnFlt (42U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (defined NTC_Num_PropExeDiag_RunTimeDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag != 43U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_RunTimeDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag (43U)
#  define NTC_Num_PropExeDiag_RunTimeDiag (43U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (defined NTC_Num_PropExeDiag_COPTimeout)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (RTE_CONST_NTC_Num_PropExeDiag_COPTimeout != 44U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_COPTimeout> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_COPTimeout (44U)
#  define NTC_Num_PropExeDiag_COPTimeout (44U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort) || (defined NTC_Num_PropExeDiag_PrefetchAbort)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort) || (RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort != 48U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_PrefetchAbort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort (48U)
#  define NTC_Num_PropExeDiag_PrefetchAbort (48U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_DataAbort) || (defined NTC_Num_PropExeDiag_DataAbort)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_DataAbort) || (RTE_CONST_NTC_Num_PropExeDiag_DataAbort != 49U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_DataAbort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_DataAbort (49U)
#  define NTC_Num_PropExeDiag_DataAbort (49U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (defined NTC_Num_PerDiag_ADC1Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC1Flt != 50U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC1Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC1Flt (50U)
#  define NTC_Num_PerDiag_ADC1Flt (50U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (defined NTC_Num_PerDiag_ADC2Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC2Flt != 51U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC2Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC2Flt (51U)
#  define NTC_Num_PerDiag_ADC2Flt (51U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (defined NTC_Num_PerDiag_ADCCrossChkFlt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt != 52U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADCCrossChkFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt (52U)
#  define NTC_Num_PerDiag_ADCCrossChkFlt (52U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (defined NTC_Num_PerDiag_IllegalAccess)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (RTE_CONST_NTC_Num_PerDiag_IllegalAccess != 53U)
#   error "Enumeration constant <NTC_Num_PerDiag_IllegalAccess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_IllegalAccess (53U)
#  define NTC_Num_PerDiag_IllegalAccess (53U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_DMAFlt) || (defined NTC_Num_PerDiag_DMAFlt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_DMAFlt) || (RTE_CONST_NTC_Num_PerDiag_DMAFlt != 54U)
#   error "Enumeration constant <NTC_Num_PerDiag_DMAFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_DMAFlt (54U)
#  define NTC_Num_PerDiag_DMAFlt (54U)
# endif
# if (defined RTE_CONST_NTC_Num_PeripheralStartupFlt) || (defined NTC_Num_PeripheralStartupFlt)
#  if (!defined RTE_CONST_NTC_Num_PeripheralStartupFlt) || (RTE_CONST_NTC_Num_PeripheralStartupFlt != 55U)
#   error "Enumeration constant <NTC_Num_PeripheralStartupFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PeripheralStartupFlt (55U)
#  define NTC_Num_PeripheralStartupFlt (55U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_CPUWarning) || (defined NTC_Num_PerDiag_CPUWarning)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_CPUWarning) || (RTE_CONST_NTC_Num_PerDiag_CPUWarning != 63U)
#   error "Enumeration constant <NTC_Num_PerDiag_CPUWarning> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_CPUWarning (63U)
#  define NTC_Num_PerDiag_CPUWarning (63U)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonFunc) || (defined NTC_Num_TmpMonFunc)
#  if (!defined RTE_CONST_NTC_Num_TmpMonFunc) || (RTE_CONST_NTC_Num_TmpMonFunc != 64U)
#   error "Enumeration constant <NTC_Num_TmpMonFunc> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonFunc (64U)
#  define NTC_Num_TmpMonFunc (64U)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (defined NTC_Num_TmpMonRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (RTE_CONST_NTC_Num_TmpMonRunTimeFlt != 65U)
#   error "Enumeration constant <NTC_Num_TmpMonRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonRunTimeFlt (65U)
#  define NTC_Num_TmpMonRunTimeFlt (65U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (defined NTC_Num_PowerRelayInitFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (RTE_CONST_NTC_Num_PowerRelayInitFlt != 66U)
#   error "Enumeration constant <NTC_Num_PowerRelayInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayInitFlt (66U)
#  define NTC_Num_PowerRelayInitFlt (66U)
# endif
# if (defined RTE_CONST_NTC_Num_PrechargeFailure) || (defined NTC_Num_PrechargeFailure)
#  if (!defined RTE_CONST_NTC_Num_PrechargeFailure) || (RTE_CONST_NTC_Num_PrechargeFailure != 67U)
#   error "Enumeration constant <NTC_Num_PrechargeFailure> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PrechargeFailure (67U)
#  define NTC_Num_PrechargeFailure (67U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (defined NTC_Num_PowerRelayRunFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (RTE_CONST_NTC_Num_PowerRelayRunFlt != 68U)
#   error "Enumeration constant <NTC_Num_PowerRelayRunFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayRunFlt (68U)
#  define NTC_Num_PowerRelayRunFlt (68U)
# endif
# if (defined RTE_CONST_NTC_Num_Thermistor) || (defined NTC_Num_Thermistor)
#  if (!defined RTE_CONST_NTC_Num_Thermistor) || (RTE_CONST_NTC_Num_Thermistor != 69U)
#   error "Enumeration constant <NTC_Num_Thermistor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Thermistor (69U)
#  define NTC_Num_Thermistor (69U)
# endif
# if (defined RTE_CONST_NTC_Num_RefSupplyVltg) || (defined NTC_Num_RefSupplyVltg)
#  if (!defined RTE_CONST_NTC_Num_RefSupplyVltg) || (RTE_CONST_NTC_Num_RefSupplyVltg != 70U)
#   error "Enumeration constant <NTC_Num_RefSupplyVltg> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RefSupplyVltg (70U)
#  define NTC_Num_RefSupplyVltg (70U)
# endif
# if (defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (defined NTC_Num_TrcvrInterfaceFlt)
#  if (!defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (RTE_CONST_NTC_Num_TrcvrInterfaceFlt != 71U)
#   error "Enumeration constant <NTC_Num_TrcvrInterfaceFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrcvrInterfaceFlt (71U)
#  define NTC_Num_TrcvrInterfaceFlt (71U)
# endif
# if (defined RTE_CONST_NTC_Num_CPUSupplyOvervoltage) || (defined NTC_Num_CPUSupplyOvervoltage)
#  if (!defined RTE_CONST_NTC_Num_CPUSupplyOvervoltage) || (RTE_CONST_NTC_Num_CPUSupplyOvervoltage != 72U)
#   error "Enumeration constant <NTC_Num_CPUSupplyOvervoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPUSupplyOvervoltage (72U)
#  define NTC_Num_CPUSupplyOvervoltage (72U)
# endif
# if (defined RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt) || (defined NTC_Num_BattVltgMeasdCorrlnFlt)
#  if (!defined RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt) || (RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt != 73U)
#   error "Enumeration constant <NTC_Num_BattVltgMeasdCorrlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt (73U)
#  define NTC_Num_BattVltgMeasdCorrlnFlt (73U)
# endif
# if (defined RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr) || (defined NTC_Num_IvtrPwrDiscnctFailr)
#  if (!defined RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr) || (RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr != 74U)
#   error "Enumeration constant <NTC_Num_IvtrPwrDiscnctFailr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr (74U)
#  define NTC_Num_IvtrPwrDiscnctFailr (74U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayInit2Flt) || (defined NTC_Num_PowerRelayInit2Flt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayInit2Flt) || (RTE_CONST_NTC_Num_PowerRelayInit2Flt != 75U)
#   error "Enumeration constant <NTC_Num_PowerRelayInit2Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayInit2Flt (75U)
#  define NTC_Num_PowerRelayInit2Flt (75U)
# endif
# if (defined RTE_CONST_NTC_Num_GateDrvFltInProcess) || (defined NTC_Num_GateDrvFltInProcess)
#  if (!defined RTE_CONST_NTC_Num_GateDrvFltInProcess) || (RTE_CONST_NTC_Num_GateDrvFltInProcess != 76U)
#   error "Enumeration constant <NTC_Num_GateDrvFltInProcess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GateDrvFltInProcess (76U)
#  define NTC_Num_GateDrvFltInProcess (76U)
# endif
# if (defined RTE_CONST_NTC_Num_GateDrvFlt) || (defined NTC_Num_GateDrvFlt)
#  if (!defined RTE_CONST_NTC_Num_GateDrvFlt) || (RTE_CONST_NTC_Num_GateDrvFlt != 77U)
#   error "Enumeration constant <NTC_Num_GateDrvFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GateDrvFlt (77U)
#  define NTC_Num_GateDrvFlt (77U)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateSingleFET) || (defined NTC_Num_OnStateSingleFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateSingleFET) || (RTE_CONST_NTC_Num_OnStateSingleFET != 78U)
#   error "Enumeration constant <NTC_Num_OnStateSingleFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateSingleFET (78U)
#  define NTC_Num_OnStateSingleFET (78U)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateMultiFET) || (defined NTC_Num_OnStateMultiFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateMultiFET) || (RTE_CONST_NTC_Num_OnStateMultiFET != 79U)
#   error "Enumeration constant <NTC_Num_OnStateMultiFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateMultiFET (79U)
#  define NTC_Num_OnStateMultiFET (79U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (defined NTC_Num_PhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (RTE_CONST_NTC_Num_PhaseVoltageVerf != 80U)
#   error "Enumeration constant <NTC_Num_PhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseVoltageVerf (80U)
#  define NTC_Num_PhaseVoltageVerf (80U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseDscnt) || (defined NTC_Num_PhaseDscnt)
#  if (!defined RTE_CONST_NTC_Num_PhaseDscnt) || (RTE_CONST_NTC_Num_PhaseDscnt != 81U)
#   error "Enumeration constant <NTC_Num_PhaseDscnt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseDscnt (81U)
#  define NTC_Num_PhaseDscnt (81U)
# endif
# if (defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (defined NTC_Num_DigPhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (RTE_CONST_NTC_Num_DigPhaseVoltageVerf != 82U)
#   error "Enumeration constant <NTC_Num_DigPhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigPhaseVoltageVerf (82U)
#  define NTC_Num_DigPhaseVoltageVerf (82U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseDscntFailedDisable) || (defined NTC_Num_PhaseDscntFailedDisable)
#  if (!defined RTE_CONST_NTC_Num_PhaseDscntFailedDisable) || (RTE_CONST_NTC_Num_PhaseDscntFailedDisable != 83U)
#   error "Enumeration constant <NTC_Num_PhaseDscntFailedDisable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseDscntFailedDisable (83U)
#  define NTC_Num_PhaseDscntFailedDisable (83U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas1) || (defined NTC_Num_CurrentMeas1)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas1) || (RTE_CONST_NTC_Num_CurrentMeas1 != 84U)
#   error "Enumeration constant <NTC_Num_CurrentMeas1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas1 (84U)
#  define NTC_Num_CurrentMeas1 (84U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas2) || (defined NTC_Num_CurrentMeas2)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas2) || (RTE_CONST_NTC_Num_CurrentMeas2 != 85U)
#   error "Enumeration constant <NTC_Num_CurrentMeas2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas2 (85U)
#  define NTC_Num_CurrentMeas2 (85U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (defined NTC_Num_CurrentMeasCrossChk)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (RTE_CONST_NTC_Num_CurrentMeasCrossChk != 86U)
#   error "Enumeration constant <NTC_Num_CurrentMeasCrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeasCrossChk (86U)
#  define NTC_Num_CurrentMeasCrossChk (86U)
# endif
# if (defined RTE_CONST_NTC_Num_PDSupplyOverVoltage) || (defined NTC_Num_PDSupplyOverVoltage)
#  if (!defined RTE_CONST_NTC_Num_PDSupplyOverVoltage) || (RTE_CONST_NTC_Num_PDSupplyOverVoltage != 87U)
#   error "Enumeration constant <NTC_Num_PDSupplyOverVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PDSupplyOverVoltage (87U)
#  define NTC_Num_PDSupplyOverVoltage (87U)
# endif
# if (defined RTE_CONST_NTC_Num_ChargePumpUnderVoltage) || (defined NTC_Num_ChargePumpUnderVoltage)
#  if (!defined RTE_CONST_NTC_Num_ChargePumpUnderVoltage) || (RTE_CONST_NTC_Num_ChargePumpUnderVoltage != 88U)
#   error "Enumeration constant <NTC_Num_ChargePumpUnderVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ChargePumpUnderVoltage (88U)
#  define NTC_Num_ChargePumpUnderVoltage (88U)
# endif
# if (defined RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr) || (defined NTC_Num_Ivtr2PwrDiscnctFailr)
#  if (!defined RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr) || (RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr != 90U)
#   error "Enumeration constant <NTC_Num_Ivtr2PwrDiscnctFailr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr (90U)
#  define NTC_Num_Ivtr2PwrDiscnctFailr (90U)
# endif
# if (defined RTE_CONST_NTC_Num_SysVltgCorrlnFlt) || (defined NTC_Num_SysVltgCorrlnFlt)
#  if (!defined RTE_CONST_NTC_Num_SysVltgCorrlnFlt) || (RTE_CONST_NTC_Num_SysVltgCorrlnFlt != 91U)
#   error "Enumeration constant <NTC_Num_SysVltgCorrlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysVltgCorrlnFlt (91U)
#  define NTC_Num_SysVltgCorrlnFlt (91U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess) || (defined NTC_Num_Inv2GateDrvFltInProcess)
#  if (!defined RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess) || (RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess != 92U)
#   error "Enumeration constant <NTC_Num_Inv2GateDrvFltInProcess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess (92U)
#  define NTC_Num_Inv2GateDrvFltInProcess (92U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2GateDrvFlt) || (defined NTC_Num_Inv2GateDrvFlt)
#  if (!defined RTE_CONST_NTC_Num_Inv2GateDrvFlt) || (RTE_CONST_NTC_Num_Inv2GateDrvFlt != 93U)
#   error "Enumeration constant <NTC_Num_Inv2GateDrvFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2GateDrvFlt (93U)
#  define NTC_Num_Inv2GateDrvFlt (93U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2OnStateSingleFET) || (defined NTC_Num_Inv2OnStateSingleFET)
#  if (!defined RTE_CONST_NTC_Num_Inv2OnStateSingleFET) || (RTE_CONST_NTC_Num_Inv2OnStateSingleFET != 94U)
#   error "Enumeration constant <NTC_Num_Inv2OnStateSingleFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2OnStateSingleFET (94U)
#  define NTC_Num_Inv2OnStateSingleFET (94U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuIdnFlt) || (defined NTC_Num_EcuIdnFlt)
#  if (!defined RTE_CONST_NTC_Num_EcuIdnFlt) || (RTE_CONST_NTC_Num_EcuIdnFlt != 95U)
#   error "Enumeration constant <NTC_Num_EcuIdnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuIdnFlt (95U)
#  define NTC_Num_EcuIdnFlt (95U)
# endif
# if (defined RTE_CONST_NTC_Num_HwTrqSensor) || (defined NTC_Num_HwTrqSensor)
#  if (!defined RTE_CONST_NTC_Num_HwTrqSensor) || (RTE_CONST_NTC_Num_HwTrqSensor != 96U)
#   error "Enumeration constant <NTC_Num_HwTrqSensor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HwTrqSensor (96U)
#  define NTC_Num_HwTrqSensor (96U)
# endif
# if (defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (defined NTC_Num_AnaVsDigHwTrq)
#  if (!defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (RTE_CONST_NTC_Num_AnaVsDigHwTrq != 97U)
#   error "Enumeration constant <NTC_Num_AnaVsDigHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AnaVsDigHwTrq (97U)
#  define NTC_Num_AnaVsDigHwTrq (97U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (defined NTC_Num_TrqSensorRecoveryFlt)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (RTE_CONST_NTC_Num_TrqSensorRecoveryFlt != 98U)
#   error "Enumeration constant <NTC_Num_TrqSensorRecoveryFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorRecoveryFlt (98U)
#  define NTC_Num_TrqSensorRecoveryFlt (98U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (defined NTC_Num_TrqSensorScaleInvalid)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_TrqSensorScaleInvalid != 100U)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleInvalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleInvalid (100U)
#  define NTC_Num_TrqSensorScaleInvalid (100U)
# endif
# if (defined RTE_CONST_NTC_Num_T1vsT2) || (defined NTC_Num_T1vsT2)
#  if (!defined RTE_CONST_NTC_Num_T1vsT2) || (RTE_CONST_NTC_Num_T1vsT2 != 101U)
#   error "Enumeration constant <NTC_Num_T1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1vsT2 (101U)
#  define NTC_Num_T1vsT2 (101U)
# endif
# if (defined RTE_CONST_NTC_Num_T1OutofRange) || (defined NTC_Num_T1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T1OutofRange) || (RTE_CONST_NTC_Num_T1OutofRange != 102U)
#   error "Enumeration constant <NTC_Num_T1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1OutofRange (102U)
#  define NTC_Num_T1OutofRange (102U)
# endif
# if (defined RTE_CONST_NTC_Num_T2OutofRange) || (defined NTC_Num_T2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T2OutofRange) || (RTE_CONST_NTC_Num_T2OutofRange != 103U)
#   error "Enumeration constant <NTC_Num_T2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T2OutofRange (103U)
#  define NTC_Num_T2OutofRange (103U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1vsT2) || (defined NTC_Num_DigT1vsT2)
#  if (!defined RTE_CONST_NTC_Num_DigT1vsT2) || (RTE_CONST_NTC_Num_DigT1vsT2 != 104U)
#   error "Enumeration constant <NTC_Num_DigT1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1vsT2 (104U)
#  define NTC_Num_DigT1vsT2 (104U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1OutofRange) || (defined NTC_Num_DigT1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT1OutofRange) || (RTE_CONST_NTC_Num_DigT1OutofRange != 105U)
#   error "Enumeration constant <NTC_Num_DigT1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1OutofRange (105U)
#  define NTC_Num_DigT1OutofRange (105U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT2OutofRange) || (defined NTC_Num_DigT2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT2OutofRange) || (RTE_CONST_NTC_Num_DigT2OutofRange != 106U)
#   error "Enumeration constant <NTC_Num_DigT2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT2OutofRange (106U)
#  define NTC_Num_DigT2OutofRange (106U)
# endif
# if (defined RTE_CONST_NTC_Num_RedT1vsT2) || (defined NTC_Num_RedT1vsT2)
#  if (!defined RTE_CONST_NTC_Num_RedT1vsT2) || (RTE_CONST_NTC_Num_RedT1vsT2 != 107U)
#   error "Enumeration constant <NTC_Num_RedT1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RedT1vsT2 (107U)
#  define NTC_Num_RedT1vsT2 (107U)
# endif
# if (defined RTE_CONST_NTC_Num_HWACrossChecks) || (defined NTC_Num_HWACrossChecks)
#  if (!defined RTE_CONST_NTC_Num_HWACrossChecks) || (RTE_CONST_NTC_Num_HWACrossChecks != 108U)
#   error "Enumeration constant <NTC_Num_HWACrossChecks> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWACrossChecks (108U)
#  define NTC_Num_HWACrossChecks (108U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASnsrCommFault) || (defined NTC_Num_HWASnsrCommFault)
#  if (!defined RTE_CONST_NTC_Num_HWASnsrCommFault) || (RTE_CONST_NTC_Num_HWASnsrCommFault != 109U)
#   error "Enumeration constant <NTC_Num_HWASnsrCommFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASnsrCommFault (109U)
#  define NTC_Num_HWASnsrCommFault (109U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorRel) || (defined NTC_Num_HWASensorRel)
#  if (!defined RTE_CONST_NTC_Num_HWASensorRel) || (RTE_CONST_NTC_Num_HWASensorRel != 110U)
#   error "Enumeration constant <NTC_Num_HWASensorRel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorRel (110U)
#  define NTC_Num_HWASensorRel (110U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorAbs) || (defined NTC_Num_HWASensorAbs)
#  if (!defined RTE_CONST_NTC_Num_HWASensorAbs) || (RTE_CONST_NTC_Num_HWASensorAbs != 111U)
#   error "Enumeration constant <NTC_Num_HWASensorAbs> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorAbs (111U)
#  define NTC_Num_HWASensorAbs (111U)
# endif
# if (defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (defined NTC_Num_PriMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (RTE_CONST_NTC_Num_PriMSB_SinCosCorr != 112U)
#   error "Enumeration constant <NTC_Num_PriMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriMSB_SinCosCorr (112U)
#  define NTC_Num_PriMSB_SinCosCorr (112U)
# endif
# if (defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (defined NTC_Num_SecMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (RTE_CONST_NTC_Num_SecMSB_SinCosCorr != 113U)
#   error "Enumeration constant <NTC_Num_SecMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SecMSB_SinCosCorr (113U)
#  define NTC_Num_SecMSB_SinCosCorr (113U)
# endif
# if (defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (defined NTC_Num_PriVsSec_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_PriVsSec_SinCosCorr != 114U)
#   error "Enumeration constant <NTC_Num_PriVsSec_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriVsSec_SinCosCorr (114U)
#  define NTC_Num_PriVsSec_SinCosCorr (114U)
# endif
# if (defined RTE_CONST_NTC_Num_DigMSBFlt) || (defined NTC_Num_DigMSBFlt)
#  if (!defined RTE_CONST_NTC_Num_DigMSBFlt) || (RTE_CONST_NTC_Num_DigMSBFlt != 115U)
#   error "Enumeration constant <NTC_Num_DigMSBFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigMSBFlt (115U)
#  define NTC_Num_DigMSBFlt (115U)
# endif
# if (defined RTE_CONST_NTC_Num_MtrVelFlt) || (defined NTC_Num_MtrVelFlt)
#  if (!defined RTE_CONST_NTC_Num_MtrVelFlt) || (RTE_CONST_NTC_Num_MtrVelFlt != 116U)
#   error "Enumeration constant <NTC_Num_MtrVelFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrVelFlt (116U)
#  define NTC_Num_MtrVelFlt (116U)
# endif
# if (defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (defined NTC_Num_HWAtoMtrAngleCorr)
#  if (!defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (RTE_CONST_NTC_Num_HWAtoMtrAngleCorr != 117U)
#   error "Enumeration constant <NTC_Num_HWAtoMtrAngleCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWAtoMtrAngleCorr (117U)
#  define NTC_Num_HWAtoMtrAngleCorr (117U)
# endif
# if (defined RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr) || (defined NTC_Num_RedPriVsSec_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr != 118U)
#   error "Enumeration constant <NTC_Num_RedPriVsSec_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr (118U)
#  define NTC_Num_RedPriVsSec_SinCosCorr (118U)
# endif
# if (defined RTE_CONST_NTC_Num_IMCLossOfCom) || (defined NTC_Num_IMCLossOfCom)
#  if (!defined RTE_CONST_NTC_Num_IMCLossOfCom) || (RTE_CONST_NTC_Num_IMCLossOfCom != 125U)
#   error "Enumeration constant <NTC_Num_IMCLossOfCom> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IMCLossOfCom (125U)
#  define NTC_Num_IMCLossOfCom (125U)
# endif
# if (defined RTE_CONST_NTC_Num_ImcArbrFault) || (defined NTC_Num_ImcArbrFault)
#  if (!defined RTE_CONST_NTC_Num_ImcArbrFault) || (RTE_CONST_NTC_Num_ImcArbrFault != 127U)
#   error "Enumeration constant <NTC_Num_ImcArbrFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ImcArbrFault (127U)
#  define NTC_Num_ImcArbrFault (127U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (defined NTC_Num_TurnCntr_PosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (RTE_CONST_NTC_Num_TurnCntr_PosLoss != 128U)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLoss (128U)
#  define NTC_Num_TurnCntr_PosLoss (128U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt) || (defined NTC_Num_TurnCntr_MicroProcFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt) || (RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt != 129U)
#   error "Enumeration constant <NTC_Num_TurnCntr_MicroProcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt (129U)
#  define NTC_Num_TurnCntr_MicroProcFlt (129U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt) || (defined NTC_Num_TurnCntr_SensorPosFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt) || (RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt != 130U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SensorPosFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt (130U)
#  define NTC_Num_TurnCntr_SensorPosFlt (130U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SpiComFlt) || (defined NTC_Num_TurnCntr_SpiComFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SpiComFlt) || (RTE_CONST_NTC_Num_TurnCntr_SpiComFlt != 131U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SpiComFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SpiComFlt (131U)
#  define NTC_Num_TurnCntr_SpiComFlt (131U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur) || (defined NTC_Num_TurnCntr_HighQuiescCur)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur) || (RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur != 132U)
#   error "Enumeration constant <NTC_Num_TurnCntr_HighQuiescCur> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur (132U)
#  define NTC_Num_TurnCntr_HighQuiescCur (132U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_MainResets) || (defined NTC_Num_TurnCntr_MainResets)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_MainResets) || (RTE_CONST_NTC_Num_TurnCntr_MainResets != 133U)
#   error "Enumeration constant <NTC_Num_TurnCntr_MainResets> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_MainResets (133U)
#  define NTC_Num_TurnCntr_MainResets (133U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep) || (defined NTC_Num_TurnCntr_PosLossNotSpdDep)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep) || (RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep != 134U)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLossNotSpdDep> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
#  define NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt) || (defined NTC_Num_TurnCntr_SpiDataFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt) || (RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt != 135U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SpiDataFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt (135U)
#  define NTC_Num_TurnCntr_SpiDataFlt (135U)
# endif
# if (defined RTE_CONST_NTC_Num_KinematicIntDiag) || (defined NTC_Num_KinematicIntDiag)
#  if (!defined RTE_CONST_NTC_Num_KinematicIntDiag) || (RTE_CONST_NTC_Num_KinematicIntDiag != 144U)
#   error "Enumeration constant <NTC_Num_KinematicIntDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_KinematicIntDiag (144U)
#  define NTC_Num_KinematicIntDiag (144U)
# endif
# if (defined RTE_CONST_NTC_Num_HighFriction) || (defined NTC_Num_HighFriction)
#  if (!defined RTE_CONST_NTC_Num_HighFriction) || (RTE_CONST_NTC_Num_HighFriction != 145U)
#   error "Enumeration constant <NTC_Num_HighFriction> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HighFriction (145U)
#  define NTC_Num_HighFriction (145U)
# endif
# if (defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (defined NTC_Num_DutyCycleExceeded)
#  if (!defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (RTE_CONST_NTC_Num_DutyCycleExceeded != 148U)
#   error "Enumeration constant <NTC_Num_DutyCycleExceeded> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DutyCycleExceeded (148U)
#  define NTC_Num_DutyCycleExceeded (148U)
# endif
# if (defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (defined NTC_Num_AbsTempThermLimit)
#  if (!defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (RTE_CONST_NTC_Num_AbsTempThermLimit != 149U)
#   error "Enumeration constant <NTC_Num_AbsTempThermLimit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AbsTempThermLimit (149U)
#  define NTC_Num_AbsTempThermLimit (149U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuCrossChk) || (defined NTC_Num_EcuCrossChk)
#  if (!defined RTE_CONST_NTC_Num_EcuCrossChk) || (RTE_CONST_NTC_Num_EcuCrossChk != 150U)
#   error "Enumeration constant <NTC_Num_EcuCrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuCrossChk (150U)
#  define NTC_Num_EcuCrossChk (150U)
# endif
# if (defined RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection) || (defined NTC_Num_ImcSigArbHighOffsetCorrection)
#  if (!defined RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection) || (RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection != 151U)
#   error "Enumeration constant <NTC_Num_ImcSigArbHighOffsetCorrection> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection (151U)
#  define NTC_Num_ImcSigArbHighOffsetCorrection (151U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuConfigMismatch) || (defined NTC_Num_EcuConfigMismatch)
#  if (!defined RTE_CONST_NTC_Num_EcuConfigMismatch) || (RTE_CONST_NTC_Num_EcuConfigMismatch != 152U)
#   error "Enumeration constant <NTC_Num_EcuConfigMismatch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuConfigMismatch (152U)
#  define NTC_Num_EcuConfigMismatch (152U)
# endif
# if (defined RTE_CONST_NTC_Num_MotBasdHwAgFlt) || (defined NTC_Num_MotBasdHwAgFlt)
#  if (!defined RTE_CONST_NTC_Num_MotBasdHwAgFlt) || (RTE_CONST_NTC_Num_MotBasdHwAgFlt != 153U)
#   error "Enumeration constant <NTC_Num_MotBasdHwAgFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MotBasdHwAgFlt (153U)
#  define NTC_Num_MotBasdHwAgFlt (153U)
# endif
# if (defined RTE_CONST_NTC_Num_LatchActive) || (defined NTC_Num_LatchActive)
#  if (!defined RTE_CONST_NTC_Num_LatchActive) || (RTE_CONST_NTC_Num_LatchActive != 160U)
#   error "Enumeration constant <NTC_Num_LatchActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LatchActive (160U)
#  define NTC_Num_LatchActive (160U)
# endif
# if (defined RTE_CONST_NTC_Num_LimpHomeIgnitionCounter) || (defined NTC_Num_LimpHomeIgnitionCounter)
#  if (!defined RTE_CONST_NTC_Num_LimpHomeIgnitionCounter) || (RTE_CONST_NTC_Num_LimpHomeIgnitionCounter != 161U)
#   error "Enumeration constant <NTC_Num_LimpHomeIgnitionCounter> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LimpHomeIgnitionCounter (161U)
#  define NTC_Num_LimpHomeIgnitionCounter (161U)
# endif
# if (defined RTE_CONST_NTC_Num_AgCompDiagc) || (defined NTC_Num_AgCompDiagc)
#  if (!defined RTE_CONST_NTC_Num_AgCompDiagc) || (RTE_CONST_NTC_Num_AgCompDiagc != 167U)
#   error "Enumeration constant <NTC_Num_AgCompDiagc> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AgCompDiagc (167U)
#  define NTC_Num_AgCompDiagc (167U)
# endif
# if (defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (defined NTC_Num_OpTrqVsHwTrq)
#  if (!defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (RTE_CONST_NTC_Num_OpTrqVsHwTrq != 168U)
#   error "Enumeration constant <NTC_Num_OpTrqVsHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpTrqVsHwTrq (168U)
#  define NTC_Num_OpTrqVsHwTrq (168U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentReas) || (defined NTC_Num_CurrentReas)
#  if (!defined RTE_CONST_NTC_Num_CurrentReas) || (RTE_CONST_NTC_Num_CurrentReas != 169U)
#   error "Enumeration constant <NTC_Num_CurrentReas> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentReas (169U)
#  define NTC_Num_CurrentReas (169U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaRpdShutdn) || (defined NTC_Num_LoaRpdShutdn)
#  if (!defined RTE_CONST_NTC_Num_LoaRpdShutdn) || (RTE_CONST_NTC_Num_LoaRpdShutdn != 170U)
#   error "Enumeration constant <NTC_Num_LoaRpdShutdn> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaRpdShutdn (170U)
#  define NTC_Num_LoaRpdShutdn (170U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaCtrldShutdn) || (defined NTC_Num_LoaCtrldShutdn)
#  if (!defined RTE_CONST_NTC_Num_LoaCtrldShutdn) || (RTE_CONST_NTC_Num_LoaCtrldShutdn != 171U)
#   error "Enumeration constant <NTC_Num_LoaCtrldShutdn> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaCtrldShutdn (171U)
#  define NTC_Num_LoaCtrldShutdn (171U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow) || (defined NTC_Num_LoaMgr_HwTqIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow != 172U)
#   error "Enumeration constant <NTC_Num_LoaMgr_HwTqIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
#  define NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow) || (defined NTC_Num_LoaMgr_MotAgIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow != 173U)
#   error "Enumeration constant <NTC_Num_LoaMgr_MotAgIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
#  define NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow) || (defined NTC_Num_LoaMgr_MotCurrIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow != 174U)
#   error "Enumeration constant <NTC_Num_LoaMgr_MotCurrIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
#  define NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow) || (defined NTC_Num_LoaMgr_IvtrIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow != 175U)
#   error "Enumeration constant <NTC_Num_LoaMgr_IvtrIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
#  define NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
# endif
# if (defined RTE_CONST_NTC_Num_OpVoltage) || (defined NTC_Num_OpVoltage)
#  if (!defined RTE_CONST_NTC_Num_OpVoltage) || (RTE_CONST_NTC_Num_OpVoltage != 176U)
#   error "Enumeration constant <NTC_Num_OpVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpVoltage (176U)
#  define NTC_Num_OpVoltage (176U)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageLow) || (defined NTC_Num_ExVoltageLow)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageLow) || (RTE_CONST_NTC_Num_ExVoltageLow != 177U)
#   error "Enumeration constant <NTC_Num_ExVoltageLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageLow (177U)
#  define NTC_Num_ExVoltageLow (177U)
# endif
# if (defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (defined NTC_Num_ReducedAsstLowVoltage)
#  if (!defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (RTE_CONST_NTC_Num_ReducedAsstLowVoltage != 178U)
#   error "Enumeration constant <NTC_Num_ReducedAsstLowVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ReducedAsstLowVoltage (178U)
#  define NTC_Num_ReducedAsstLowVoltage (178U)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageHigh) || (defined NTC_Num_ExVoltageHigh)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageHigh) || (RTE_CONST_NTC_Num_ExVoltageHigh != 180U)
#   error "Enumeration constant <NTC_Num_ExVoltageHigh> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageHigh (180U)
#  define NTC_Num_ExVoltageHigh (180U)
# endif
# if (defined RTE_CONST_NTC_Num_OpVoltageOvrMax) || (defined NTC_Num_OpVoltageOvrMax)
#  if (!defined RTE_CONST_NTC_Num_OpVoltageOvrMax) || (RTE_CONST_NTC_Num_OpVoltageOvrMax != 181U)
#   error "Enumeration constant <NTC_Num_OpVoltageOvrMax> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpVoltageOvrMax (181U)
#  define NTC_Num_OpVoltageOvrMax (181U)
# endif
# if (defined RTE_CONST_NTC_Num_BattTransOverVolt) || (defined NTC_Num_BattTransOverVolt)
#  if (!defined RTE_CONST_NTC_Num_BattTransOverVolt) || (RTE_CONST_NTC_Num_BattTransOverVolt != 182U)
#   error "Enumeration constant <NTC_Num_BattTransOverVolt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BattTransOverVolt (182U)
#  define NTC_Num_BattTransOverVolt (182U)
# endif
# if (defined RTE_CONST_NTC_Num_IgnConfDiag) || (defined NTC_Num_IgnConfDiag)
#  if (!defined RTE_CONST_NTC_Num_IgnConfDiag) || (RTE_CONST_NTC_Num_IgnConfDiag != 184U)
#   error "Enumeration constant <NTC_Num_IgnConfDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IgnConfDiag (184U)
#  define NTC_Num_IgnConfDiag (184U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_LowBattery) || (defined NTC_Num_TurnCntr_LowBattery)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_LowBattery) || (RTE_CONST_NTC_Num_TurnCntr_LowBattery != 185U)
#   error "Enumeration constant <NTC_Num_TurnCntr_LowBattery> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_LowBattery (185U)
#  define NTC_Num_TurnCntr_LowBattery (185U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (defined NTC_Num_EEPROMCloseFailed)
#  if (!defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (RTE_CONST_NTC_Num_EEPROMCloseFailed != 191U)
#   error "Enumeration constant <NTC_Num_EEPROMCloseFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMCloseFailed (191U)
#  define NTC_Num_EEPROMCloseFailed (191U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (defined NTC_Num_SigPath1CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (RTE_CONST_NTC_Num_SigPath1CrossChk != 192U)
#   error "Enumeration constant <NTC_Num_SigPath1CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath1CrossChk (192U)
#  define NTC_Num_SigPath1CrossChk (192U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (defined NTC_Num_SigPath2CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (RTE_CONST_NTC_Num_SigPath2CrossChk != 193U)
#   error "Enumeration constant <NTC_Num_SigPath2CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath2CrossChk (193U)
#  define NTC_Num_SigPath2CrossChk (193U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (defined NTC_Num_SigPath3CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (RTE_CONST_NTC_Num_SigPath3CrossChk != 194U)
#   error "Enumeration constant <NTC_Num_SigPath3CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath3CrossChk (194U)
#  define NTC_Num_SigPath3CrossChk (194U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (defined NTC_Num_SigPath4CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (RTE_CONST_NTC_Num_SigPath4CrossChk != 195U)
#   error "Enumeration constant <NTC_Num_SigPath4CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath4CrossChk (195U)
#  define NTC_Num_SigPath4CrossChk (195U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath5CrossChk) || (defined NTC_Num_SigPath5CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath5CrossChk) || (RTE_CONST_NTC_Num_SigPath5CrossChk != 196U)
#   error "Enumeration constant <NTC_Num_SigPath5CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath5CrossChk (196U)
#  define NTC_Num_SigPath5CrossChk (196U)
# endif
# if (defined RTE_CONST_NTC_Num_DampingFWReached) || (defined NTC_Num_DampingFWReached)
#  if (!defined RTE_CONST_NTC_Num_DampingFWReached) || (RTE_CONST_NTC_Num_DampingFWReached != 197U)
#   error "Enumeration constant <NTC_Num_DampingFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DampingFWReached (197U)
#  define NTC_Num_DampingFWReached (197U)
# endif
# if (defined RTE_CONST_NTC_Num_AssistFWReached) || (defined NTC_Num_AssistFWReached)
#  if (!defined RTE_CONST_NTC_Num_AssistFWReached) || (RTE_CONST_NTC_Num_AssistFWReached != 198U)
#   error "Enumeration constant <NTC_Num_AssistFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AssistFWReached (198U)
#  define NTC_Num_AssistFWReached (198U)
# endif
# if (defined RTE_CONST_NTC_Num_ReturnFWReached) || (defined NTC_Num_ReturnFWReached)
#  if (!defined RTE_CONST_NTC_Num_ReturnFWReached) || (RTE_CONST_NTC_Num_ReturnFWReached != 199U)
#   error "Enumeration constant <NTC_Num_ReturnFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ReturnFWReached (199U)
#  define NTC_Num_ReturnFWReached (199U)
# endif
# if (defined RTE_CONST_NTC_Num_DampingFWFltMode) || (defined NTC_Num_DampingFWFltMode)
#  if (!defined RTE_CONST_NTC_Num_DampingFWFltMode) || (RTE_CONST_NTC_Num_DampingFWFltMode != 200U)
#   error "Enumeration constant <NTC_Num_DampingFWFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DampingFWFltMode (200U)
#  define NTC_Num_DampingFWFltMode (200U)
# endif
# if (defined RTE_CONST_NTC_Num_AssistFWFltMode) || (defined NTC_Num_AssistFWFltMode)
#  if (!defined RTE_CONST_NTC_Num_AssistFWFltMode) || (RTE_CONST_NTC_Num_AssistFWFltMode != 201U)
#   error "Enumeration constant <NTC_Num_AssistFWFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AssistFWFltMode (201U)
#  define NTC_Num_AssistFWFltMode (201U)
# endif
# if (defined RTE_CONST_NTC_Num_VBICFltMode) || (defined NTC_Num_VBICFltMode)
#  if (!defined RTE_CONST_NTC_Num_VBICFltMode) || (RTE_CONST_NTC_Num_VBICFltMode != 202U)
#   error "Enumeration constant <NTC_Num_VBICFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VBICFltMode (202U)
#  define NTC_Num_VBICFltMode (202U)
# endif
# if (defined RTE_CONST_NTC_Num_StaMdsSysC) || (defined NTC_Num_StaMdsSysC)
#  if (!defined RTE_CONST_NTC_Num_StaMdsSysC) || (RTE_CONST_NTC_Num_StaMdsSysC != 203U)
#   error "Enumeration constant <NTC_Num_StaMdsSysC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_StaMdsSysC (203U)
#  define NTC_Num_StaMdsSysC (203U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailureForRotVel) || (defined NTC_NUM_SysFailureForRotVel)
#  if (!defined RTE_CONST_NTC_NUM_SysFailureForRotVel) || (RTE_CONST_NTC_NUM_SysFailureForRotVel != 204U)
#   error "Enumeration constant <NTC_NUM_SysFailureForRotVel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailureForRotVel (204U)
#  define NTC_NUM_SysFailureForRotVel (204U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailForRedntRotVel) || (defined NTC_NUM_SysFailForRedntRotVel)
#  if (!defined RTE_CONST_NTC_NUM_SysFailForRedntRotVel) || (RTE_CONST_NTC_NUM_SysFailForRedntRotVel != 205U)
#   error "Enumeration constant <NTC_NUM_SysFailForRedntRotVel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailForRedntRotVel (205U)
#  define NTC_NUM_SysFailForRedntRotVel (205U)
# endif
# if (defined RTE_CONST_NTC_Num_SysFailureForTrqSnsr) || (defined NTC_Num_SysFailureForTrqSnsr)
#  if (!defined RTE_CONST_NTC_Num_SysFailureForTrqSnsr) || (RTE_CONST_NTC_Num_SysFailureForTrqSnsr != 206U)
#   error "Enumeration constant <NTC_Num_SysFailureForTrqSnsr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysFailureForTrqSnsr (206U)
#  define NTC_Num_SysFailureForTrqSnsr (206U)
# endif
# if (defined RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr) || (defined NTC_Num_SysFailureForRedTrqSnsr)
#  if (!defined RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr) || (RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr != 207U)
#   error "Enumeration constant <NTC_Num_SysFailureForRedTrqSnsr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr (207U)
#  define NTC_Num_SysFailureForRedTrqSnsr (207U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailureForCtrlVolt) || (defined NTC_NUM_SysFailureForCtrlVolt)
#  if (!defined RTE_CONST_NTC_NUM_SysFailureForCtrlVolt) || (RTE_CONST_NTC_NUM_SysFailureForCtrlVolt != 209U)
#   error "Enumeration constant <NTC_NUM_SysFailureForCtrlVolt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailureForCtrlVolt (209U)
#  define NTC_NUM_SysFailureForCtrlVolt (209U)
# endif
# if (defined RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet) || (defined NTC_Num_GlblSgnlOvrwrtDet)
#  if (!defined RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet) || (RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet != 223U)
#   error "Enumeration constant <NTC_Num_GlblSgnlOvrwrtDet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet (223U)
#  define NTC_Num_GlblSgnlOvrwrtDet (223U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_00) || (defined NTC_Num_VLF_00)
#  if (!defined RTE_CONST_NTC_Num_VLF_00) || (RTE_CONST_NTC_Num_VLF_00 != 224U)
#   error "Enumeration constant <NTC_Num_VLF_00> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_00 (224U)
#  define NTC_Num_VLF_00 (224U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_01) || (defined NTC_Num_VLF_01)
#  if (!defined RTE_CONST_NTC_Num_VLF_01) || (RTE_CONST_NTC_Num_VLF_01 != 225U)
#   error "Enumeration constant <NTC_Num_VLF_01> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_01 (225U)
#  define NTC_Num_VLF_01 (225U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_02) || (defined NTC_Num_VLF_02)
#  if (!defined RTE_CONST_NTC_Num_VLF_02) || (RTE_CONST_NTC_Num_VLF_02 != 226U)
#   error "Enumeration constant <NTC_Num_VLF_02> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_02 (226U)
#  define NTC_Num_VLF_02 (226U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_03) || (defined NTC_Num_VLF_03)
#  if (!defined RTE_CONST_NTC_Num_VLF_03) || (RTE_CONST_NTC_Num_VLF_03 != 227U)
#   error "Enumeration constant <NTC_Num_VLF_03> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_03 (227U)
#  define NTC_Num_VLF_03 (227U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_04) || (defined NTC_Num_VLF_04)
#  if (!defined RTE_CONST_NTC_Num_VLF_04) || (RTE_CONST_NTC_Num_VLF_04 != 228U)
#   error "Enumeration constant <NTC_Num_VLF_04> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_04 (228U)
#  define NTC_Num_VLF_04 (228U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_05) || (defined NTC_Num_VLF_05)
#  if (!defined RTE_CONST_NTC_Num_VLF_05) || (RTE_CONST_NTC_Num_VLF_05 != 229U)
#   error "Enumeration constant <NTC_Num_VLF_05> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_05 (229U)
#  define NTC_Num_VLF_05 (229U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_06) || (defined NTC_Num_VLF_06)
#  if (!defined RTE_CONST_NTC_Num_VLF_06) || (RTE_CONST_NTC_Num_VLF_06 != 230U)
#   error "Enumeration constant <NTC_Num_VLF_06> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_06 (230U)
#  define NTC_Num_VLF_06 (230U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_07) || (defined NTC_Num_VLF_07)
#  if (!defined RTE_CONST_NTC_Num_VLF_07) || (RTE_CONST_NTC_Num_VLF_07 != 231U)
#   error "Enumeration constant <NTC_Num_VLF_07> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_07 (231U)
#  define NTC_Num_VLF_07 (231U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_08) || (defined NTC_Num_VLF_08)
#  if (!defined RTE_CONST_NTC_Num_VLF_08) || (RTE_CONST_NTC_Num_VLF_08 != 232U)
#   error "Enumeration constant <NTC_Num_VLF_08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_08 (232U)
#  define NTC_Num_VLF_08 (232U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_09) || (defined NTC_Num_VLF_09)
#  if (!defined RTE_CONST_NTC_Num_VLF_09) || (RTE_CONST_NTC_Num_VLF_09 != 233U)
#   error "Enumeration constant <NTC_Num_VLF_09> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_09 (233U)
#  define NTC_Num_VLF_09 (233U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_10) || (defined NTC_Num_VLF_10)
#  if (!defined RTE_CONST_NTC_Num_VLF_10) || (RTE_CONST_NTC_Num_VLF_10 != 234U)
#   error "Enumeration constant <NTC_Num_VLF_10> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_10 (234U)
#  define NTC_Num_VLF_10 (234U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_11) || (defined NTC_Num_VLF_11)
#  if (!defined RTE_CONST_NTC_Num_VLF_11) || (RTE_CONST_NTC_Num_VLF_11 != 235U)
#   error "Enumeration constant <NTC_Num_VLF_11> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_11 (235U)
#  define NTC_Num_VLF_11 (235U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_12) || (defined NTC_Num_VLF_12)
#  if (!defined RTE_CONST_NTC_Num_VLF_12) || (RTE_CONST_NTC_Num_VLF_12 != 236U)
#   error "Enumeration constant <NTC_Num_VLF_12> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_12 (236U)
#  define NTC_Num_VLF_12 (236U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_13) || (defined NTC_Num_VLF_13)
#  if (!defined RTE_CONST_NTC_Num_VLF_13) || (RTE_CONST_NTC_Num_VLF_13 != 237U)
#   error "Enumeration constant <NTC_Num_VLF_13> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_13 (237U)
#  define NTC_Num_VLF_13 (237U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_14) || (defined NTC_Num_VLF_14)
#  if (!defined RTE_CONST_NTC_Num_VLF_14) || (RTE_CONST_NTC_Num_VLF_14 != 238U)
#   error "Enumeration constant <NTC_Num_VLF_14> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_14 (238U)
#  define NTC_Num_VLF_14 (238U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_15) || (defined NTC_Num_VLF_15)
#  if (!defined RTE_CONST_NTC_Num_VLF_15) || (RTE_CONST_NTC_Num_VLF_15 != 239U)
#   error "Enumeration constant <NTC_Num_VLF_15> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_15 (239U)
#  define NTC_Num_VLF_15 (239U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_16) || (defined NTC_Num_VLF_16)
#  if (!defined RTE_CONST_NTC_Num_VLF_16) || (RTE_CONST_NTC_Num_VLF_16 != 240U)
#   error "Enumeration constant <NTC_Num_VLF_16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_16 (240U)
#  define NTC_Num_VLF_16 (240U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_17) || (defined NTC_Num_VLF_17)
#  if (!defined RTE_CONST_NTC_Num_VLF_17) || (RTE_CONST_NTC_Num_VLF_17 != 241U)
#   error "Enumeration constant <NTC_Num_VLF_17> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_17 (241U)
#  define NTC_Num_VLF_17 (241U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_18) || (defined NTC_Num_VLF_18)
#  if (!defined RTE_CONST_NTC_Num_VLF_18) || (RTE_CONST_NTC_Num_VLF_18 != 242U)
#   error "Enumeration constant <NTC_Num_VLF_18> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_18 (242U)
#  define NTC_Num_VLF_18 (242U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_19) || (defined NTC_Num_VLF_19)
#  if (!defined RTE_CONST_NTC_Num_VLF_19) || (RTE_CONST_NTC_Num_VLF_19 != 243U)
#   error "Enumeration constant <NTC_Num_VLF_19> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_19 (243U)
#  define NTC_Num_VLF_19 (243U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_20) || (defined NTC_Num_VLF_20)
#  if (!defined RTE_CONST_NTC_Num_VLF_20) || (RTE_CONST_NTC_Num_VLF_20 != 244U)
#   error "Enumeration constant <NTC_Num_VLF_20> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_20 (244U)
#  define NTC_Num_VLF_20 (244U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_21) || (defined NTC_Num_VLF_21)
#  if (!defined RTE_CONST_NTC_Num_VLF_21) || (RTE_CONST_NTC_Num_VLF_21 != 245U)
#   error "Enumeration constant <NTC_Num_VLF_21> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_21 (245U)
#  define NTC_Num_VLF_21 (245U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_22) || (defined NTC_Num_VLF_22)
#  if (!defined RTE_CONST_NTC_Num_VLF_22) || (RTE_CONST_NTC_Num_VLF_22 != 246U)
#   error "Enumeration constant <NTC_Num_VLF_22> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_22 (246U)
#  define NTC_Num_VLF_22 (246U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_23) || (defined NTC_Num_VLF_23)
#  if (!defined RTE_CONST_NTC_Num_VLF_23) || (RTE_CONST_NTC_Num_VLF_23 != 247U)
#   error "Enumeration constant <NTC_Num_VLF_23> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_23 (247U)
#  define NTC_Num_VLF_23 (247U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_24) || (defined NTC_Num_VLF_24)
#  if (!defined RTE_CONST_NTC_Num_VLF_24) || (RTE_CONST_NTC_Num_VLF_24 != 248U)
#   error "Enumeration constant <NTC_Num_VLF_24> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_24 (248U)
#  define NTC_Num_VLF_24 (248U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_25) || (defined NTC_Num_VLF_25)
#  if (!defined RTE_CONST_NTC_Num_VLF_25) || (RTE_CONST_NTC_Num_VLF_25 != 249U)
#   error "Enumeration constant <NTC_Num_VLF_25> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_25 (249U)
#  define NTC_Num_VLF_25 (249U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_26) || (defined NTC_Num_VLF_26)
#  if (!defined RTE_CONST_NTC_Num_VLF_26) || (RTE_CONST_NTC_Num_VLF_26 != 250U)
#   error "Enumeration constant <NTC_Num_VLF_26> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_26 (250U)
#  define NTC_Num_VLF_26 (250U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_27) || (defined NTC_Num_VLF_27)
#  if (!defined RTE_CONST_NTC_Num_VLF_27) || (RTE_CONST_NTC_Num_VLF_27 != 251U)
#   error "Enumeration constant <NTC_Num_VLF_27> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_27 (251U)
#  define NTC_Num_VLF_27 (251U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_28) || (defined NTC_Num_VLF_28)
#  if (!defined RTE_CONST_NTC_Num_VLF_28) || (RTE_CONST_NTC_Num_VLF_28 != 252U)
#   error "Enumeration constant <NTC_Num_VLF_28> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_28 (252U)
#  define NTC_Num_VLF_28 (252U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_29) || (defined NTC_Num_VLF_29)
#  if (!defined RTE_CONST_NTC_Num_VLF_29) || (RTE_CONST_NTC_Num_VLF_29 != 253U)
#   error "Enumeration constant <NTC_Num_VLF_29> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_29 (253U)
#  define NTC_Num_VLF_29 (253U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_30) || (defined NTC_Num_VLF_30)
#  if (!defined RTE_CONST_NTC_Num_VLF_30) || (RTE_CONST_NTC_Num_VLF_30 != 254U)
#   error "Enumeration constant <NTC_Num_VLF_30> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_30 (254U)
#  define NTC_Num_VLF_30 (254U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_31) || (defined NTC_Num_VLF_31)
#  if (!defined RTE_CONST_NTC_Num_VLF_31) || (RTE_CONST_NTC_Num_VLF_31 != 255U)
#   error "Enumeration constant <NTC_Num_VLF_31> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_31 (255U)
#  define NTC_Num_VLF_31 (255U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh1) || (defined NTC_Num_BusOffCh1)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh1) || (RTE_CONST_NTC_Num_BusOffCh1 != 256U)
#   error "Enumeration constant <NTC_Num_BusOffCh1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh1 (256U)
#  define NTC_Num_BusOffCh1 (256U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh1NodeMute) || (defined NTC_Num_BusOffCh1NodeMute)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh1NodeMute) || (RTE_CONST_NTC_Num_BusOffCh1NodeMute != 257U)
#   error "Enumeration constant <NTC_Num_BusOffCh1NodeMute> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh1NodeMute (257U)
#  define NTC_Num_BusOffCh1NodeMute (257U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1AAbsent) || (defined NTC_Num_Node1AAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1AAbsent) || (RTE_CONST_NTC_Num_Node1AAbsent != 258U)
#   error "Enumeration constant <NTC_Num_Node1AAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1AAbsent (258U)
#  define NTC_Num_Node1AAbsent (258U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1AFaulty) || (defined NTC_Num_Node1AFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1AFaulty) || (RTE_CONST_NTC_Num_Node1AFaulty != 259U)
#   error "Enumeration constant <NTC_Num_Node1AFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1AFaulty (259U)
#  define NTC_Num_Node1AFaulty (259U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1BAbsent) || (defined NTC_Num_Node1BAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1BAbsent) || (RTE_CONST_NTC_Num_Node1BAbsent != 260U)
#   error "Enumeration constant <NTC_Num_Node1BAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1BAbsent (260U)
#  define NTC_Num_Node1BAbsent (260U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1BFaulty) || (defined NTC_Num_Node1BFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1BFaulty) || (RTE_CONST_NTC_Num_Node1BFaulty != 261U)
#   error "Enumeration constant <NTC_Num_Node1BFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1BFaulty (261U)
#  define NTC_Num_Node1BFaulty (261U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1CAbsent) || (defined NTC_Num_Node1CAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1CAbsent) || (RTE_CONST_NTC_Num_Node1CAbsent != 262U)
#   error "Enumeration constant <NTC_Num_Node1CAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1CAbsent (262U)
#  define NTC_Num_Node1CAbsent (262U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1CFaulty) || (defined NTC_Num_Node1CFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1CFaulty) || (RTE_CONST_NTC_Num_Node1CFaulty != 263U)
#   error "Enumeration constant <NTC_Num_Node1CFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1CFaulty (263U)
#  define NTC_Num_Node1CFaulty (263U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1DAbsent) || (defined NTC_Num_Node1DAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1DAbsent) || (RTE_CONST_NTC_Num_Node1DAbsent != 264U)
#   error "Enumeration constant <NTC_Num_Node1DAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1DAbsent (264U)
#  define NTC_Num_Node1DAbsent (264U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1DFaulty) || (defined NTC_Num_Node1DFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1DFaulty) || (RTE_CONST_NTC_Num_Node1DFaulty != 265U)
#   error "Enumeration constant <NTC_Num_Node1DFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1DFaulty (265U)
#  define NTC_Num_Node1DFaulty (265U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1EAbsent) || (defined NTC_Num_Node1EAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1EAbsent) || (RTE_CONST_NTC_Num_Node1EAbsent != 266U)
#   error "Enumeration constant <NTC_Num_Node1EAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1EAbsent (266U)
#  define NTC_Num_Node1EAbsent (266U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1EFaulty) || (defined NTC_Num_Node1EFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1EFaulty) || (RTE_CONST_NTC_Num_Node1EFaulty != 267U)
#   error "Enumeration constant <NTC_Num_Node1EFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1EFaulty (267U)
#  define NTC_Num_Node1EFaulty (267U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1FAbsent) || (defined NTC_Num_Node1FAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1FAbsent) || (RTE_CONST_NTC_Num_Node1FAbsent != 268U)
#   error "Enumeration constant <NTC_Num_Node1FAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1FAbsent (268U)
#  define NTC_Num_Node1FAbsent (268U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1FFaulty) || (defined NTC_Num_Node1FFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1FFaulty) || (RTE_CONST_NTC_Num_Node1FFaulty != 269U)
#   error "Enumeration constant <NTC_Num_Node1FFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1FFaulty (269U)
#  define NTC_Num_Node1FFaulty (269U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1GAbsent) || (defined NTC_Num_Node1GAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1GAbsent) || (RTE_CONST_NTC_Num_Node1GAbsent != 270U)
#   error "Enumeration constant <NTC_Num_Node1GAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1GAbsent (270U)
#  define NTC_Num_Node1GAbsent (270U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1GFaulty) || (defined NTC_Num_Node1GFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1GFaulty) || (RTE_CONST_NTC_Num_Node1GFaulty != 271U)
#   error "Enumeration constant <NTC_Num_Node1GFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1GFaulty (271U)
#  define NTC_Num_Node1GFaulty (271U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh2) || (defined NTC_Num_BusOffCh2)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh2) || (RTE_CONST_NTC_Num_BusOffCh2 != 272U)
#   error "Enumeration constant <NTC_Num_BusOffCh2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh2 (272U)
#  define NTC_Num_BusOffCh2 (272U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2AAbsent) || (defined NTC_Num_Node2AAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2AAbsent) || (RTE_CONST_NTC_Num_Node2AAbsent != 273U)
#   error "Enumeration constant <NTC_Num_Node2AAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2AAbsent (273U)
#  define NTC_Num_Node2AAbsent (273U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2AFaulty) || (defined NTC_Num_Node2AFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2AFaulty) || (RTE_CONST_NTC_Num_Node2AFaulty != 274U)
#   error "Enumeration constant <NTC_Num_Node2AFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2AFaulty (274U)
#  define NTC_Num_Node2AFaulty (274U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2BAbsent) || (defined NTC_Num_Node2BAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2BAbsent) || (RTE_CONST_NTC_Num_Node2BAbsent != 275U)
#   error "Enumeration constant <NTC_Num_Node2BAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2BAbsent (275U)
#  define NTC_Num_Node2BAbsent (275U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2BFaulty) || (defined NTC_Num_Node2BFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2BFaulty) || (RTE_CONST_NTC_Num_Node2BFaulty != 276U)
#   error "Enumeration constant <NTC_Num_Node2BFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2BFaulty (276U)
#  define NTC_Num_Node2BFaulty (276U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2CAbsent) || (defined NTC_Num_Node2CAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2CAbsent) || (RTE_CONST_NTC_Num_Node2CAbsent != 277U)
#   error "Enumeration constant <NTC_Num_Node2CAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2CAbsent (277U)
#  define NTC_Num_Node2CAbsent (277U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2CFaulty) || (defined NTC_Num_Node2CFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2CFaulty) || (RTE_CONST_NTC_Num_Node2CFaulty != 278U)
#   error "Enumeration constant <NTC_Num_Node2CFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2CFaulty (278U)
#  define NTC_Num_Node2CFaulty (278U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2DAbsent) || (defined NTC_Num_Node2DAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2DAbsent) || (RTE_CONST_NTC_Num_Node2DAbsent != 279U)
#   error "Enumeration constant <NTC_Num_Node2DAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2DAbsent (279U)
#  define NTC_Num_Node2DAbsent (279U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2DFaulty) || (defined NTC_Num_Node2DFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2DFaulty) || (RTE_CONST_NTC_Num_Node2DFaulty != 280U)
#   error "Enumeration constant <NTC_Num_Node2DFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2DFaulty (280U)
#  define NTC_Num_Node2DFaulty (280U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2EAbsent) || (defined NTC_Num_Node2EAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2EAbsent) || (RTE_CONST_NTC_Num_Node2EAbsent != 281U)
#   error "Enumeration constant <NTC_Num_Node2EAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2EAbsent (281U)
#  define NTC_Num_Node2EAbsent (281U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2EFaulty) || (defined NTC_Num_Node2EFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2EFaulty) || (RTE_CONST_NTC_Num_Node2EFaulty != 282U)
#   error "Enumeration constant <NTC_Num_Node2EFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2EFaulty (282U)
#  define NTC_Num_Node2EFaulty (282U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2FAbsent) || (defined NTC_Num_Node2FAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2FAbsent) || (RTE_CONST_NTC_Num_Node2FAbsent != 283U)
#   error "Enumeration constant <NTC_Num_Node2FAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2FAbsent (283U)
#  define NTC_Num_Node2FAbsent (283U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2FFaulty) || (defined NTC_Num_Node2FFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2FFaulty) || (RTE_CONST_NTC_Num_Node2FFaulty != 284U)
#   error "Enumeration constant <NTC_Num_Node2FFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2FFaulty (284U)
#  define NTC_Num_Node2FFaulty (284U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2GAbsent) || (defined NTC_Num_Node2GAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2GAbsent) || (RTE_CONST_NTC_Num_Node2GAbsent != 285U)
#   error "Enumeration constant <NTC_Num_Node2GAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2GAbsent (285U)
#  define NTC_Num_Node2GAbsent (285U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2GFaulty) || (defined NTC_Num_Node2GFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2GFaulty) || (RTE_CONST_NTC_Num_Node2GFaulty != 286U)
#   error "Enumeration constant <NTC_Num_Node2GFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2GFaulty (286U)
#  define NTC_Num_Node2GFaulty (286U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_M) || (defined NTC_Num_InvalidMsg_M)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_M) || (RTE_CONST_NTC_Num_InvalidMsg_M != 288U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_M (288U)
#  define NTC_Num_InvalidMsg_M (288U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_M) || (defined NTC_Num_MissingMsg_M)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_M) || (RTE_CONST_NTC_Num_MissingMsg_M != 289U)
#   error "Enumeration constant <NTC_Num_MissingMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_M (289U)
#  define NTC_Num_MissingMsg_M (289U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (defined NTC_Num_CRCFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (RTE_CONST_NTC_Num_CRCFltMsg_M != 290U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_M (290U)
#  define NTC_Num_CRCFltMsg_M (290U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (defined NTC_Num_PgrsCntFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_M != 291U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_M (291U)
#  define NTC_Num_PgrsCntFltMsg_M (291U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (defined NTC_Num_DataRngFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (RTE_CONST_NTC_Num_DataRngFltMsg_M != 292U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_M (292U)
#  define NTC_Num_DataRngFltMsg_M (292U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (defined NTC_Num_DataRateFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (RTE_CONST_NTC_Num_DataRateFltMsg_M != 293U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_M (293U)
#  define NTC_Num_DataRateFltMsg_M (293U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (defined NTC_Num_DataOtherFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (RTE_CONST_NTC_Num_DataOtherFltMsg_M != 294U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_M (294U)
#  define NTC_Num_DataOtherFltMsg_M (294U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOther2FltMsg_M) || (defined NTC_Num_DataOther2FltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataOther2FltMsg_M) || (RTE_CONST_NTC_Num_DataOther2FltMsg_M != 295U)
#   error "Enumeration constant <NTC_Num_DataOther2FltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOther2FltMsg_M (295U)
#  define NTC_Num_DataOther2FltMsg_M (295U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_N) || (defined NTC_Num_InvalidMsg_N)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_N) || (RTE_CONST_NTC_Num_InvalidMsg_N != 296U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_N (296U)
#  define NTC_Num_InvalidMsg_N (296U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_N) || (defined NTC_Num_MissingMsg_N)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_N) || (RTE_CONST_NTC_Num_MissingMsg_N != 297U)
#   error "Enumeration constant <NTC_Num_MissingMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_N (297U)
#  define NTC_Num_MissingMsg_N (297U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (defined NTC_Num_CRCFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (RTE_CONST_NTC_Num_CRCFltMsg_N != 298U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_N (298U)
#  define NTC_Num_CRCFltMsg_N (298U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (defined NTC_Num_PgrsCntFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_N != 299U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_N (299U)
#  define NTC_Num_PgrsCntFltMsg_N (299U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (defined NTC_Num_DataRngFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (RTE_CONST_NTC_Num_DataRngFltMsg_N != 300U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_N (300U)
#  define NTC_Num_DataRngFltMsg_N (300U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (defined NTC_Num_DataRateFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (RTE_CONST_NTC_Num_DataRateFltMsg_N != 301U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_N (301U)
#  define NTC_Num_DataRateFltMsg_N (301U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (defined NTC_Num_DataOtherFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (RTE_CONST_NTC_Num_DataOtherFltMsg_N != 302U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_N (302U)
#  define NTC_Num_DataOtherFltMsg_N (302U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_N) || (defined NTC_Num_DataOtherFlt2Msg_N)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_N) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_N != 303U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_N (303U)
#  define NTC_Num_DataOtherFlt2Msg_N (303U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_O) || (defined NTC_Num_InvalidMsg_O)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_O) || (RTE_CONST_NTC_Num_InvalidMsg_O != 304U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_O (304U)
#  define NTC_Num_InvalidMsg_O (304U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_O) || (defined NTC_Num_MissingMsg_O)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_O) || (RTE_CONST_NTC_Num_MissingMsg_O != 305U)
#   error "Enumeration constant <NTC_Num_MissingMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_O (305U)
#  define NTC_Num_MissingMsg_O (305U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (defined NTC_Num_CRCFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (RTE_CONST_NTC_Num_CRCFltMsg_O != 306U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_O (306U)
#  define NTC_Num_CRCFltMsg_O (306U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (defined NTC_Num_PgrsCntFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_O != 307U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_O (307U)
#  define NTC_Num_PgrsCntFltMsg_O (307U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (defined NTC_Num_DataRngFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (RTE_CONST_NTC_Num_DataRngFltMsg_O != 308U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_O (308U)
#  define NTC_Num_DataRngFltMsg_O (308U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (defined NTC_Num_DataRateFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (RTE_CONST_NTC_Num_DataRateFltMsg_O != 309U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_O (309U)
#  define NTC_Num_DataRateFltMsg_O (309U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (defined NTC_Num_DataOtherFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (RTE_CONST_NTC_Num_DataOtherFltMsg_O != 310U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_O (310U)
#  define NTC_Num_DataOtherFltMsg_O (310U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_P) || (defined NTC_Num_InvalidMsg_P)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_P) || (RTE_CONST_NTC_Num_InvalidMsg_P != 312U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_P (312U)
#  define NTC_Num_InvalidMsg_P (312U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_P) || (defined NTC_Num_MissingMsg_P)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_P) || (RTE_CONST_NTC_Num_MissingMsg_P != 313U)
#   error "Enumeration constant <NTC_Num_MissingMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_P (313U)
#  define NTC_Num_MissingMsg_P (313U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (defined NTC_Num_CRCFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (RTE_CONST_NTC_Num_CRCFltMsg_P != 314U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_P (314U)
#  define NTC_Num_CRCFltMsg_P (314U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (defined NTC_Num_PgrsCntFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_P != 315U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_P (315U)
#  define NTC_Num_PgrsCntFltMsg_P (315U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (defined NTC_Num_DataRngFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (RTE_CONST_NTC_Num_DataRngFltMsg_P != 316U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_P (316U)
#  define NTC_Num_DataRngFltMsg_P (316U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (defined NTC_Num_DataRateFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (RTE_CONST_NTC_Num_DataRateFltMsg_P != 317U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_P (317U)
#  define NTC_Num_DataRateFltMsg_P (317U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (defined NTC_Num_DataOtherFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (RTE_CONST_NTC_Num_DataOtherFltMsg_P != 318U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_P (318U)
#  define NTC_Num_DataOtherFltMsg_P (318U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (defined NTC_Num_InvalidMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (RTE_CONST_NTC_Num_InvalidMsg_Q != 320U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Q (320U)
#  define NTC_Num_InvalidMsg_Q (320U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Q) || (defined NTC_Num_MissingMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Q) || (RTE_CONST_NTC_Num_MissingMsg_Q != 321U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Q (321U)
#  define NTC_Num_MissingMsg_Q (321U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (defined NTC_Num_CRCFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (RTE_CONST_NTC_Num_CRCFltMsg_Q != 322U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Q (322U)
#  define NTC_Num_CRCFltMsg_Q (322U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (defined NTC_Num_PgrsCntFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Q != 323U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Q (323U)
#  define NTC_Num_PgrsCntFltMsg_Q (323U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (defined NTC_Num_DataRngFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (RTE_CONST_NTC_Num_DataRngFltMsg_Q != 324U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Q (324U)
#  define NTC_Num_DataRngFltMsg_Q (324U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (defined NTC_Num_DataRateFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (RTE_CONST_NTC_Num_DataRateFltMsg_Q != 325U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Q (325U)
#  define NTC_Num_DataRateFltMsg_Q (325U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (defined NTC_Num_DataOtherFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Q != 326U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Q (326U)
#  define NTC_Num_DataOtherFltMsg_Q (326U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q) || (defined NTC_Num_DataOtherFlt2Msg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q != 327U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q (327U)
#  define NTC_Num_DataOtherFlt2Msg_Q (327U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_R) || (defined NTC_Num_InvalidMsg_R)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_R) || (RTE_CONST_NTC_Num_InvalidMsg_R != 328U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_R (328U)
#  define NTC_Num_InvalidMsg_R (328U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_R) || (defined NTC_Num_MissingMsg_R)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_R) || (RTE_CONST_NTC_Num_MissingMsg_R != 329U)
#   error "Enumeration constant <NTC_Num_MissingMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_R (329U)
#  define NTC_Num_MissingMsg_R (329U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (defined NTC_Num_CRCFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (RTE_CONST_NTC_Num_CRCFltMsg_R != 330U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_R (330U)
#  define NTC_Num_CRCFltMsg_R (330U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (defined NTC_Num_PgrsCntFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_R != 331U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_R (331U)
#  define NTC_Num_PgrsCntFltMsg_R (331U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (defined NTC_Num_DataRngFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (RTE_CONST_NTC_Num_DataRngFltMsg_R != 332U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_R (332U)
#  define NTC_Num_DataRngFltMsg_R (332U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (defined NTC_Num_DataRateFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (RTE_CONST_NTC_Num_DataRateFltMsg_R != 333U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_R (333U)
#  define NTC_Num_DataRateFltMsg_R (333U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (defined NTC_Num_DataOtherFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (RTE_CONST_NTC_Num_DataOtherFltMsg_R != 334U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_R (334U)
#  define NTC_Num_DataOtherFltMsg_R (334U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_R) || (defined NTC_Num_DataOtherFlt2Msg_R)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_R) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_R != 335U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_R (335U)
#  define NTC_Num_DataOtherFlt2Msg_R (335U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_S) || (defined NTC_Num_InvalidMsg_S)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_S) || (RTE_CONST_NTC_Num_InvalidMsg_S != 336U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_S (336U)
#  define NTC_Num_InvalidMsg_S (336U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_S) || (defined NTC_Num_MissingMsg_S)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_S) || (RTE_CONST_NTC_Num_MissingMsg_S != 337U)
#   error "Enumeration constant <NTC_Num_MissingMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_S (337U)
#  define NTC_Num_MissingMsg_S (337U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (defined NTC_Num_CRCFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (RTE_CONST_NTC_Num_CRCFltMsg_S != 338U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_S (338U)
#  define NTC_Num_CRCFltMsg_S (338U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (defined NTC_Num_PgrsCntFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_S != 339U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_S (339U)
#  define NTC_Num_PgrsCntFltMsg_S (339U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (defined NTC_Num_DataRngFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (RTE_CONST_NTC_Num_DataRngFltMsg_S != 340U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_S (340U)
#  define NTC_Num_DataRngFltMsg_S (340U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (defined NTC_Num_DataRateFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (RTE_CONST_NTC_Num_DataRateFltMsg_S != 341U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_S (341U)
#  define NTC_Num_DataRateFltMsg_S (341U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (defined NTC_Num_DataOtherFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (RTE_CONST_NTC_Num_DataOtherFltMsg_S != 342U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_S (342U)
#  define NTC_Num_DataOtherFltMsg_S (342U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_T) || (defined NTC_Num_InvalidMsg_T)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_T) || (RTE_CONST_NTC_Num_InvalidMsg_T != 344U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_T (344U)
#  define NTC_Num_InvalidMsg_T (344U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_T) || (defined NTC_Num_MissingMsg_T)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_T) || (RTE_CONST_NTC_Num_MissingMsg_T != 345U)
#   error "Enumeration constant <NTC_Num_MissingMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_T (345U)
#  define NTC_Num_MissingMsg_T (345U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (defined NTC_Num_CRCFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (RTE_CONST_NTC_Num_CRCFltMsg_T != 346U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_T (346U)
#  define NTC_Num_CRCFltMsg_T (346U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (defined NTC_Num_PgrsCntFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_T != 347U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_T (347U)
#  define NTC_Num_PgrsCntFltMsg_T (347U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (defined NTC_Num_DataRngFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (RTE_CONST_NTC_Num_DataRngFltMsg_T != 348U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_T (348U)
#  define NTC_Num_DataRngFltMsg_T (348U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (defined NTC_Num_DataRateFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (RTE_CONST_NTC_Num_DataRateFltMsg_T != 349U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_T (349U)
#  define NTC_Num_DataRateFltMsg_T (349U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (defined NTC_Num_DataOtherFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (RTE_CONST_NTC_Num_DataOtherFltMsg_T != 350U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_T (350U)
#  define NTC_Num_DataOtherFltMsg_T (350U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_U) || (defined NTC_Num_InvalidMsg_U)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_U) || (RTE_CONST_NTC_Num_InvalidMsg_U != 352U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_U (352U)
#  define NTC_Num_InvalidMsg_U (352U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_U) || (defined NTC_Num_MissingMsg_U)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_U) || (RTE_CONST_NTC_Num_MissingMsg_U != 353U)
#   error "Enumeration constant <NTC_Num_MissingMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_U (353U)
#  define NTC_Num_MissingMsg_U (353U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (defined NTC_Num_CRCFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (RTE_CONST_NTC_Num_CRCFltMsg_U != 354U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_U (354U)
#  define NTC_Num_CRCFltMsg_U (354U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (defined NTC_Num_PgrsCntFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_U != 355U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_U (355U)
#  define NTC_Num_PgrsCntFltMsg_U (355U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (defined NTC_Num_DataRngFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (RTE_CONST_NTC_Num_DataRngFltMsg_U != 356U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_U (356U)
#  define NTC_Num_DataRngFltMsg_U (356U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (defined NTC_Num_DataRateFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (RTE_CONST_NTC_Num_DataRateFltMsg_U != 357U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_U (357U)
#  define NTC_Num_DataRateFltMsg_U (357U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (defined NTC_Num_DataOtherFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (RTE_CONST_NTC_Num_DataOtherFltMsg_U != 358U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_U (358U)
#  define NTC_Num_DataOtherFltMsg_U (358U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_V) || (defined NTC_Num_InvalidMsg_V)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_V) || (RTE_CONST_NTC_Num_InvalidMsg_V != 360U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_V (360U)
#  define NTC_Num_InvalidMsg_V (360U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_V) || (defined NTC_Num_MissingMsg_V)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_V) || (RTE_CONST_NTC_Num_MissingMsg_V != 361U)
#   error "Enumeration constant <NTC_Num_MissingMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_V (361U)
#  define NTC_Num_MissingMsg_V (361U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (defined NTC_Num_CRCFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (RTE_CONST_NTC_Num_CRCFltMsg_V != 362U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_V (362U)
#  define NTC_Num_CRCFltMsg_V (362U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (defined NTC_Num_PgrsCntFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_V != 363U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_V (363U)
#  define NTC_Num_PgrsCntFltMsg_V (363U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (defined NTC_Num_DataRngFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (RTE_CONST_NTC_Num_DataRngFltMsg_V != 364U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_V (364U)
#  define NTC_Num_DataRngFltMsg_V (364U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (defined NTC_Num_DataRateFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (RTE_CONST_NTC_Num_DataRateFltMsg_V != 365U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_V (365U)
#  define NTC_Num_DataRateFltMsg_V (365U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (defined NTC_Num_DataOtherFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (RTE_CONST_NTC_Num_DataOtherFltMsg_V != 366U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_V (366U)
#  define NTC_Num_DataOtherFltMsg_V (366U)
# endif
# if (defined RTE_CONST_NTC_Num_IgnitionStatusSigFlt) || (defined NTC_Num_IgnitionStatusSigFlt)
#  if (!defined RTE_CONST_NTC_Num_IgnitionStatusSigFlt) || (RTE_CONST_NTC_Num_IgnitionStatusSigFlt != 367U)
#   error "Enumeration constant <NTC_Num_IgnitionStatusSigFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IgnitionStatusSigFlt (367U)
#  define NTC_Num_IgnitionStatusSigFlt (367U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_W) || (defined NTC_Num_InvalidMsg_W)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_W) || (RTE_CONST_NTC_Num_InvalidMsg_W != 368U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_W (368U)
#  define NTC_Num_InvalidMsg_W (368U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_W) || (defined NTC_Num_MissingMsg_W)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_W) || (RTE_CONST_NTC_Num_MissingMsg_W != 369U)
#   error "Enumeration constant <NTC_Num_MissingMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_W (369U)
#  define NTC_Num_MissingMsg_W (369U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (defined NTC_Num_CRCFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (RTE_CONST_NTC_Num_CRCFltMsg_W != 370U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_W (370U)
#  define NTC_Num_CRCFltMsg_W (370U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (defined NTC_Num_PgrsCntFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_W != 371U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_W (371U)
#  define NTC_Num_PgrsCntFltMsg_W (371U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (defined NTC_Num_DataRngFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (RTE_CONST_NTC_Num_DataRngFltMsg_W != 372U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_W (372U)
#  define NTC_Num_DataRngFltMsg_W (372U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (defined NTC_Num_DataRateFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (RTE_CONST_NTC_Num_DataRateFltMsg_W != 373U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_W (373U)
#  define NTC_Num_DataRateFltMsg_W (373U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (defined NTC_Num_DataOtherFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (RTE_CONST_NTC_Num_DataOtherFltMsg_W != 374U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_W (374U)
#  define NTC_Num_DataOtherFltMsg_W (374U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_X) || (defined NTC_Num_InvalidMsg_X)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_X) || (RTE_CONST_NTC_Num_InvalidMsg_X != 376U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_X (376U)
#  define NTC_Num_InvalidMsg_X (376U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_X) || (defined NTC_Num_MissingMsg_X)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_X) || (RTE_CONST_NTC_Num_MissingMsg_X != 377U)
#   error "Enumeration constant <NTC_Num_MissingMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_X (377U)
#  define NTC_Num_MissingMsg_X (377U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (defined NTC_Num_CRCFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (RTE_CONST_NTC_Num_CRCFltMsg_X != 378U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_X (378U)
#  define NTC_Num_CRCFltMsg_X (378U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (defined NTC_Num_PgrsCntFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_X != 379U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_X (379U)
#  define NTC_Num_PgrsCntFltMsg_X (379U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (defined NTC_Num_DataRngFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (RTE_CONST_NTC_Num_DataRngFltMsg_X != 380U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_X (380U)
#  define NTC_Num_DataRngFltMsg_X (380U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (defined NTC_Num_DataRateFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (RTE_CONST_NTC_Num_DataRateFltMsg_X != 381U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_X (381U)
#  define NTC_Num_DataRateFltMsg_X (381U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (defined NTC_Num_DataOtherFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (RTE_CONST_NTC_Num_DataOtherFltMsg_X != 382U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_X (382U)
#  define NTC_Num_DataOtherFltMsg_X (382U)
# endif
# if (defined RTE_CONST_NTC_Num_WhlSpdSigFlt) || (defined NTC_Num_WhlSpdSigFlt)
#  if (!defined RTE_CONST_NTC_Num_WhlSpdSigFlt) || (RTE_CONST_NTC_Num_WhlSpdSigFlt != 383U)
#   error "Enumeration constant <NTC_Num_WhlSpdSigFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_WhlSpdSigFlt (383U)
#  define NTC_Num_WhlSpdSigFlt (383U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (defined NTC_Num_InvalidMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (RTE_CONST_NTC_Num_InvalidMsg_Y != 384U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Y (384U)
#  define NTC_Num_InvalidMsg_Y (384U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Y) || (defined NTC_Num_MissingMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Y) || (RTE_CONST_NTC_Num_MissingMsg_Y != 385U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Y (385U)
#  define NTC_Num_MissingMsg_Y (385U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (defined NTC_Num_CRCFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (RTE_CONST_NTC_Num_CRCFltMsg_Y != 386U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Y (386U)
#  define NTC_Num_CRCFltMsg_Y (386U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (defined NTC_Num_PgrsCntFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Y != 387U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Y (387U)
#  define NTC_Num_PgrsCntFltMsg_Y (387U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (defined NTC_Num_DataRngFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (RTE_CONST_NTC_Num_DataRngFltMsg_Y != 388U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Y (388U)
#  define NTC_Num_DataRngFltMsg_Y (388U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (defined NTC_Num_DataRateFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (RTE_CONST_NTC_Num_DataRateFltMsg_Y != 389U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Y (389U)
#  define NTC_Num_DataRateFltMsg_Y (389U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (defined NTC_Num_DataOtherFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Y != 390U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Y (390U)
#  define NTC_Num_DataOtherFltMsg_Y (390U)
# endif
# if (defined RTE_CONST_NTC_Num_StePinOffstAnEstInvalid) || (defined NTC_Num_StePinOffstAnEstInvalid)
#  if (!defined RTE_CONST_NTC_Num_StePinOffstAnEstInvalid) || (RTE_CONST_NTC_Num_StePinOffstAnEstInvalid != 391U)
#   error "Enumeration constant <NTC_Num_StePinOffstAnEstInvalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_StePinOffstAnEstInvalid (391U)
#  define NTC_Num_StePinOffstAnEstInvalid (391U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (defined NTC_Num_InvalidMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (RTE_CONST_NTC_Num_InvalidMsg_Z != 392U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Z (392U)
#  define NTC_Num_InvalidMsg_Z (392U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Z) || (defined NTC_Num_MissingMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Z) || (RTE_CONST_NTC_Num_MissingMsg_Z != 393U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Z (393U)
#  define NTC_Num_MissingMsg_Z (393U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (defined NTC_Num_CRCFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (RTE_CONST_NTC_Num_CRCFltMsg_Z != 394U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Z (394U)
#  define NTC_Num_CRCFltMsg_Z (394U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (defined NTC_Num_PgrsCntFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Z != 395U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Z (395U)
#  define NTC_Num_PgrsCntFltMsg_Z (395U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (defined NTC_Num_DataRngFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (RTE_CONST_NTC_Num_DataRngFltMsg_Z != 396U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Z (396U)
#  define NTC_Num_DataRngFltMsg_Z (396U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (defined NTC_Num_DataRateFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (RTE_CONST_NTC_Num_DataRateFltMsg_Z != 397U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Z (397U)
#  define NTC_Num_DataRateFltMsg_Z (397U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (defined NTC_Num_DataOtherFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Z != 398U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Z (398U)
#  define NTC_Num_DataOtherFltMsg_Z (398U)
# endif
# if (defined RTE_CONST_NTC_Num_DSTXORActive) || (defined NTC_Num_DSTXORActive)
#  if (!defined RTE_CONST_NTC_Num_DSTXORActive) || (RTE_CONST_NTC_Num_DSTXORActive != 399U)
#   error "Enumeration constant <NTC_Num_DSTXORActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DSTXORActive (399U)
#  define NTC_Num_DSTXORActive (399U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (defined NTC_Num_InvalidMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (RTE_CONST_NTC_Num_InvalidMsg_AA != 400U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AA (400U)
#  define NTC_Num_InvalidMsg_AA (400U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AA) || (defined NTC_Num_MissingMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AA) || (RTE_CONST_NTC_Num_MissingMsg_AA != 401U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AA (401U)
#  define NTC_Num_MissingMsg_AA (401U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (defined NTC_Num_CRCFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (RTE_CONST_NTC_Num_CRCFltMsg_AA != 402U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AA (402U)
#  define NTC_Num_CRCFltMsg_AA (402U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (defined NTC_Num_PgrsCntFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AA != 403U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AA (403U)
#  define NTC_Num_PgrsCntFltMsg_AA (403U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (defined NTC_Num_DataRngFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (RTE_CONST_NTC_Num_DataRngFltMsg_AA != 404U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AA (404U)
#  define NTC_Num_DataRngFltMsg_AA (404U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (defined NTC_Num_DataRateFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (RTE_CONST_NTC_Num_DataRateFltMsg_AA != 405U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AA (405U)
#  define NTC_Num_DataRateFltMsg_AA (405U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (defined NTC_Num_DataOtherFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AA != 406U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AA (406U)
#  define NTC_Num_DataOtherFltMsg_AA (406U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (defined NTC_Num_InvalidMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (RTE_CONST_NTC_Num_InvalidMsg_AB != 408U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AB (408U)
#  define NTC_Num_InvalidMsg_AB (408U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AB) || (defined NTC_Num_MissingMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AB) || (RTE_CONST_NTC_Num_MissingMsg_AB != 409U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AB (409U)
#  define NTC_Num_MissingMsg_AB (409U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (defined NTC_Num_CRCFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (RTE_CONST_NTC_Num_CRCFltMsg_AB != 410U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AB (410U)
#  define NTC_Num_CRCFltMsg_AB (410U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (defined NTC_Num_PgrsCntFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AB != 411U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AB (411U)
#  define NTC_Num_PgrsCntFltMsg_AB (411U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (defined NTC_Num_DataRngFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (RTE_CONST_NTC_Num_DataRngFltMsg_AB != 412U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AB (412U)
#  define NTC_Num_DataRngFltMsg_AB (412U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (defined NTC_Num_DataRateFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (RTE_CONST_NTC_Num_DataRateFltMsg_AB != 413U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AB (413U)
#  define NTC_Num_DataRateFltMsg_AB (413U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (defined NTC_Num_DataOtherFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AB != 414U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AB (414U)
#  define NTC_Num_DataOtherFltMsg_AB (414U)
# endif
# if (defined RTE_CONST_NTC_Num_StePinOffstDStatSigFlt) || (defined NTC_Num_StePinOffstDStatSigFlt)
#  if (!defined RTE_CONST_NTC_Num_StePinOffstDStatSigFlt) || (RTE_CONST_NTC_Num_StePinOffstDStatSigFlt != 415U)
#   error "Enumeration constant <NTC_Num_StePinOffstDStatSigFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_StePinOffstDStatSigFlt (415U)
#  define NTC_Num_StePinOffstDStatSigFlt (415U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (defined NTC_Num_InvalidMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (RTE_CONST_NTC_Num_InvalidMsg_AC != 416U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AC (416U)
#  define NTC_Num_InvalidMsg_AC (416U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AC) || (defined NTC_Num_MissingMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AC) || (RTE_CONST_NTC_Num_MissingMsg_AC != 417U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AC (417U)
#  define NTC_Num_MissingMsg_AC (417U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (defined NTC_Num_CRCFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (RTE_CONST_NTC_Num_CRCFltMsg_AC != 418U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AC (418U)
#  define NTC_Num_CRCFltMsg_AC (418U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (defined NTC_Num_PgrsCntFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AC != 419U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AC (419U)
#  define NTC_Num_PgrsCntFltMsg_AC (419U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (defined NTC_Num_DataRngFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (RTE_CONST_NTC_Num_DataRngFltMsg_AC != 420U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AC (420U)
#  define NTC_Num_DataRngFltMsg_AC (420U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (defined NTC_Num_DataRateFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (RTE_CONST_NTC_Num_DataRateFltMsg_AC != 421U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AC (421U)
#  define NTC_Num_DataRateFltMsg_AC (421U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (defined NTC_Num_DataOtherFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AC != 422U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AC (422U)
#  define NTC_Num_DataOtherFltMsg_AC (422U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (defined NTC_Num_InvalidMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (RTE_CONST_NTC_Num_InvalidMsg_AD != 424U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AD (424U)
#  define NTC_Num_InvalidMsg_AD (424U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AD) || (defined NTC_Num_MissingMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AD) || (RTE_CONST_NTC_Num_MissingMsg_AD != 425U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AD (425U)
#  define NTC_Num_MissingMsg_AD (425U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (defined NTC_Num_CRCFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (RTE_CONST_NTC_Num_CRCFltMsg_AD != 426U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AD (426U)
#  define NTC_Num_CRCFltMsg_AD (426U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (defined NTC_Num_PgrsCntFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AD != 427U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AD (427U)
#  define NTC_Num_PgrsCntFltMsg_AD (427U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (defined NTC_Num_DataRngFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (RTE_CONST_NTC_Num_DataRngFltMsg_AD != 428U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AD (428U)
#  define NTC_Num_DataRngFltMsg_AD (428U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (defined NTC_Num_DataRateFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (RTE_CONST_NTC_Num_DataRateFltMsg_AD != 429U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AD (429U)
#  define NTC_Num_DataRateFltMsg_AD (429U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (defined NTC_Num_DataOtherFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AD != 430U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AD (430U)
#  define NTC_Num_DataOtherFltMsg_AD (430U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (defined NTC_Num_InvalidMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (RTE_CONST_NTC_Num_InvalidMsg_AE != 432U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AE (432U)
#  define NTC_Num_InvalidMsg_AE (432U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AE) || (defined NTC_Num_MissingMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AE) || (RTE_CONST_NTC_Num_MissingMsg_AE != 433U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AE (433U)
#  define NTC_Num_MissingMsg_AE (433U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (defined NTC_Num_CRCFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (RTE_CONST_NTC_Num_CRCFltMsg_AE != 434U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AE (434U)
#  define NTC_Num_CRCFltMsg_AE (434U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (defined NTC_Num_PgrsCntFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AE != 435U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AE (435U)
#  define NTC_Num_PgrsCntFltMsg_AE (435U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (defined NTC_Num_DataRngFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (RTE_CONST_NTC_Num_DataRngFltMsg_AE != 436U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AE (436U)
#  define NTC_Num_DataRngFltMsg_AE (436U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (defined NTC_Num_DataRateFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (RTE_CONST_NTC_Num_DataRateFltMsg_AE != 437U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AE (437U)
#  define NTC_Num_DataRateFltMsg_AE (437U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (defined NTC_Num_DataOtherFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AE != 438U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AE (438U)
#  define NTC_Num_DataOtherFltMsg_AE (438U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (defined NTC_Num_InvalidMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (RTE_CONST_NTC_Num_InvalidMsg_AF != 440U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AF (440U)
#  define NTC_Num_InvalidMsg_AF (440U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AF) || (defined NTC_Num_MissingMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AF) || (RTE_CONST_NTC_Num_MissingMsg_AF != 441U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AF (441U)
#  define NTC_Num_MissingMsg_AF (441U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (defined NTC_Num_CRCFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (RTE_CONST_NTC_Num_CRCFltMsg_AF != 442U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AF (442U)
#  define NTC_Num_CRCFltMsg_AF (442U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (defined NTC_Num_PgrsCntFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AF != 443U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AF (443U)
#  define NTC_Num_PgrsCntFltMsg_AF (443U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (defined NTC_Num_DataRngFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (RTE_CONST_NTC_Num_DataRngFltMsg_AF != 444U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AF (444U)
#  define NTC_Num_DataRngFltMsg_AF (444U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (defined NTC_Num_DataRateFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (RTE_CONST_NTC_Num_DataRateFltMsg_AF != 445U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AF (445U)
#  define NTC_Num_DataRateFltMsg_AF (445U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (defined NTC_Num_DataOtherFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AF != 446U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AF (446U)
#  define NTC_Num_DataOtherFltMsg_AF (446U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AG) || (defined NTC_Num_InvalidMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AG) || (RTE_CONST_NTC_Num_InvalidMsg_AG != 448U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AG (448U)
#  define NTC_Num_InvalidMsg_AG (448U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AG) || (defined NTC_Num_MissingMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AG) || (RTE_CONST_NTC_Num_MissingMsg_AG != 449U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AG (449U)
#  define NTC_Num_MissingMsg_AG (449U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AG) || (defined NTC_Num_CRCFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AG) || (RTE_CONST_NTC_Num_CRCFltMsg_AG != 450U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AG (450U)
#  define NTC_Num_CRCFltMsg_AG (450U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AG) || (defined NTC_Num_PgrsCntFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AG) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AG != 451U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AG (451U)
#  define NTC_Num_PgrsCntFltMsg_AG (451U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AG) || (defined NTC_Num_DataRngFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AG) || (RTE_CONST_NTC_Num_DataRngFltMsg_AG != 452U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AG (452U)
#  define NTC_Num_DataRngFltMsg_AG (452U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AG) || (defined NTC_Num_DataRateFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AG) || (RTE_CONST_NTC_Num_DataRateFltMsg_AG != 453U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AG (453U)
#  define NTC_Num_DataRateFltMsg_AG (453U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AG) || (defined NTC_Num_DataOtherFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AG) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AG != 454U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AG (454U)
#  define NTC_Num_DataOtherFltMsg_AG (454U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AH) || (defined NTC_Num_InvalidMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AH) || (RTE_CONST_NTC_Num_InvalidMsg_AH != 456U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AH (456U)
#  define NTC_Num_InvalidMsg_AH (456U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AH) || (defined NTC_Num_MissingMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AH) || (RTE_CONST_NTC_Num_MissingMsg_AH != 457U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AH (457U)
#  define NTC_Num_MissingMsg_AH (457U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AH) || (defined NTC_Num_CRCFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AH) || (RTE_CONST_NTC_Num_CRCFltMsg_AH != 458U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AH (458U)
#  define NTC_Num_CRCFltMsg_AH (458U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AH) || (defined NTC_Num_PgrsCntFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AH) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AH != 459U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AH (459U)
#  define NTC_Num_PgrsCntFltMsg_AH (459U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AH) || (defined NTC_Num_DataRngFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AH) || (RTE_CONST_NTC_Num_DataRngFltMsg_AH != 460U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AH (460U)
#  define NTC_Num_DataRngFltMsg_AH (460U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AH) || (defined NTC_Num_DataRateFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AH) || (RTE_CONST_NTC_Num_DataRateFltMsg_AH != 461U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AH (461U)
#  define NTC_Num_DataRateFltMsg_AH (461U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AH) || (defined NTC_Num_DataOtherFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AH) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AH != 462U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AH (462U)
#  define NTC_Num_DataOtherFltMsg_AH (462U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel) || (defined NTC_Num_InvalidMsg_ParkAssistParallel)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel) || (RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel != 464U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_ParkAssistParallel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel (464U)
#  define NTC_Num_InvalidMsg_ParkAssistParallel (464U)
# endif
# if (defined RTE_CONST_NTC_Num_FlexrayCommunicationError) || (defined NTC_Num_FlexrayCommunicationError)
#  if (!defined RTE_CONST_NTC_Num_FlexrayCommunicationError) || (RTE_CONST_NTC_Num_FlexrayCommunicationError != 465U)
#   error "Enumeration constant <NTC_Num_FlexrayCommunicationError> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlexrayCommunicationError (465U)
#  define NTC_Num_FlexrayCommunicationError (465U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AI) || (defined NTC_Num_InvalidMsg_AI)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AI) || (RTE_CONST_NTC_Num_InvalidMsg_AI != 466U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AI (466U)
#  define NTC_Num_InvalidMsg_AI (466U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AI) || (defined NTC_Num_MissingMsg_AI)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AI) || (RTE_CONST_NTC_Num_MissingMsg_AI != 467U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AI (467U)
#  define NTC_Num_MissingMsg_AI (467U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AJ) || (defined NTC_Num_InvalidMsg_AJ)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AJ) || (RTE_CONST_NTC_Num_InvalidMsg_AJ != 472U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AJ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AJ (472U)
#  define NTC_Num_InvalidMsg_AJ (472U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AJ) || (defined NTC_Num_MissingMsg_AJ)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AJ) || (RTE_CONST_NTC_Num_MissingMsg_AJ != 473U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AJ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AJ (473U)
#  define NTC_Num_MissingMsg_AJ (473U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AK) || (defined NTC_Num_InvalidMsg_AK)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AK) || (RTE_CONST_NTC_Num_InvalidMsg_AK != 480U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AK (480U)
#  define NTC_Num_InvalidMsg_AK (480U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AK) || (defined NTC_Num_MissingMsg_AK)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AK) || (RTE_CONST_NTC_Num_MissingMsg_AK != 481U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AK (481U)
#  define NTC_Num_MissingMsg_AK (481U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AM) || (defined NTC_Num_MissingMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AM) || (RTE_CONST_NTC_Num_MissingMsg_AM != 482U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AM (482U)
#  define NTC_Num_MissingMsg_AM (482U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AM) || (defined NTC_Num_InvalidMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AM) || (RTE_CONST_NTC_Num_InvalidMsg_AM != 483U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AM (483U)
#  define NTC_Num_InvalidMsg_AM (483U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AM) || (defined NTC_Num_CRCFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AM) || (RTE_CONST_NTC_Num_CRCFltMsg_AM != 484U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AM (484U)
#  define NTC_Num_CRCFltMsg_AM (484U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AM) || (defined NTC_Num_PgrsCntFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AM) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AM != 485U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AM (485U)
#  define NTC_Num_PgrsCntFltMsg_AM (485U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AM) || (defined NTC_Num_DataRngFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AM) || (RTE_CONST_NTC_Num_DataRngFltMsg_AM != 486U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AM (486U)
#  define NTC_Num_DataRngFltMsg_AM (486U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AL) || (defined NTC_Num_InvalidMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AL) || (RTE_CONST_NTC_Num_InvalidMsg_AL != 488U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AL (488U)
#  define NTC_Num_InvalidMsg_AL (488U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AL) || (defined NTC_Num_MissingMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AL) || (RTE_CONST_NTC_Num_MissingMsg_AL != 489U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AL (489U)
#  define NTC_Num_MissingMsg_AL (489U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AL) || (defined NTC_Num_DataRngFltMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AL) || (RTE_CONST_NTC_Num_DataRngFltMsg_AL != 492U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AL (492U)
#  define NTC_Num_DataRngFltMsg_AL (492U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AL) || (defined NTC_Num_DataOtherFltMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AL) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AL != 494U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AL (494U)
#  define NTC_Num_DataOtherFltMsg_AL (494U)
# endif
# if (defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (defined NTC_Num_SysConsistencyVerf)
#  if (!defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (RTE_CONST_NTC_Num_SysConsistencyVerf != 496U)
#   error "Enumeration constant <NTC_Num_SysConsistencyVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysConsistencyVerf (496U)
#  define NTC_Num_SysConsistencyVerf (496U)
# endif
# if (defined RTE_CONST_NTC_Num_ConfigMisMatch) || (defined NTC_Num_ConfigMisMatch)
#  if (!defined RTE_CONST_NTC_Num_ConfigMisMatch) || (RTE_CONST_NTC_Num_ConfigMisMatch != 497U)
#   error "Enumeration constant <NTC_Num_ConfigMisMatch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ConfigMisMatch (497U)
#  define NTC_Num_ConfigMisMatch (497U)
# endif
# if (defined RTE_CONST_NTC_Num_CalNotPrgmd) || (defined NTC_Num_CalNotPrgmd)
#  if (!defined RTE_CONST_NTC_Num_CalNotPrgmd) || (RTE_CONST_NTC_Num_CalNotPrgmd != 498U)
#   error "Enumeration constant <NTC_Num_CalNotPrgmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CalNotPrgmd (498U)
#  define NTC_Num_CalNotPrgmd (498U)
# endif
# if (defined RTE_CONST_NTC_Num_TunSetNotPrgmd) || (defined NTC_Num_TunSetNotPrgmd)
#  if (!defined RTE_CONST_NTC_Num_TunSetNotPrgmd) || (RTE_CONST_NTC_Num_TunSetNotPrgmd != 499U)
#   error "Enumeration constant <NTC_Num_TunSetNotPrgmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TunSetNotPrgmd (499U)
#  define NTC_Num_TunSetNotPrgmd (499U)
# endif
# if (defined RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong) || (defined NTC_Num_PHAPosnSnsrVsPwrpkDataWrong)
#  if (!defined RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong) || (RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong != 500U)
#   error "Enumeration constant <NTC_Num_PHAPosnSnsrVsPwrpkDataWrong> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
#  define NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMtoFeeCpyError) || (defined NTC_Num_EEPROMtoFeeCpyError)
#  if (!defined RTE_CONST_NTC_Num_EEPROMtoFeeCpyError) || (RTE_CONST_NTC_Num_EEPROMtoFeeCpyError != 500U)
#   error "Enumeration constant <NTC_Num_EEPROMtoFeeCpyError> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMtoFeeCpyError (500U)
#  define NTC_Num_EEPROMtoFeeCpyError (500U)
# endif
# if (defined RTE_CONST_NTC_Num_EOLVehTunNtPerf) || (defined NTC_Num_EOLVehTunNtPerf)
#  if (!defined RTE_CONST_NTC_Num_EOLVehTunNtPerf) || (RTE_CONST_NTC_Num_EOLVehTunNtPerf != 501U)
#   error "Enumeration constant <NTC_Num_EOLVehTunNtPerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EOLVehTunNtPerf (501U)
#  define NTC_Num_EOLVehTunNtPerf (501U)
# endif
# if (defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (defined NTC_Num_MtrSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (RTE_CONST_NTC_Num_MtrSensorNotTrimmed != 502U)
#   error "Enumeration constant <NTC_Num_MtrSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrSensorNotTrimmed (502U)
#  define NTC_Num_MtrSensorNotTrimmed (502U)
# endif
# if (defined RTE_CONST_NTC_Num_PHAScratchPadTrf) || (defined NTC_Num_PHAScratchPadTrf)
#  if (!defined RTE_CONST_NTC_Num_PHAScratchPadTrf) || (RTE_CONST_NTC_Num_PHAScratchPadTrf != 503U)
#   error "Enumeration constant <NTC_Num_PHAScratchPadTrf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PHAScratchPadTrf (503U)
#  define NTC_Num_PHAScratchPadTrf (503U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (defined NTC_Num_HWASensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (RTE_CONST_NTC_Num_HWASensorNotTrimmed != 504U)
#   error "Enumeration constant <NTC_Num_HWASensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorNotTrimmed (504U)
#  define NTC_Num_HWASensorNotTrimmed (504U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (defined NTC_Num_HWASensorTrimNoAttempt)
#  if (!defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (RTE_CONST_NTC_Num_HWASensorTrimNoAttempt != 505U)
#   error "Enumeration constant <NTC_Num_HWASensorTrimNoAttempt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorTrimNoAttempt (505U)
#  define NTC_Num_HWASensorTrimNoAttempt (505U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (defined NTC_Num_TrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_TrqSensorScaleNotSet != 506U)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleNotSet (506U)
#  define NTC_Num_TrqSensorScaleNotSet (506U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (defined NTC_Num_TrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_TrqSensorNotTrimmed != 507U)
#   error "Enumeration constant <NTC_Num_TrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorNotTrimmed (507U)
#  define NTC_Num_TrqSensorNotTrimmed (507U)
# endif
# if (defined RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd) || (defined NTC_Num_AnaHWDiffTqOfstNotTrmd)
#  if (!defined RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd) || (RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd != 508U)
#   error "Enumeration constant <NTC_Num_AnaHWDiffTqOfstNotTrmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
#  define NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (defined NTC_Num_DigTrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet != 509U)
#   error "Enumeration constant <NTC_Num_DigTrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet (509U)
#  define NTC_Num_DigTrqSensorScaleNotSet (509U)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (defined NTC_Num_DigTrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed != 510U)
#   error "Enumeration constant <NTC_Num_DigTrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed (510U)
#  define NTC_Num_DigTrqSensorNotTrimmed (510U)
# endif
# if (defined RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd) || (defined NTC_Num_SENTHWDiffTqOfstNotTrmd)
#  if (!defined RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd) || (RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd != 511U)
#   error "Enumeration constant <NTC_Num_SENTHWDiffTqOfstNotTrmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
#  define NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
# endif

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
# define NvM_RequestResultType_LowerLimit (0U)
# define NvM_RequestResultType_UpperLimit (5U)
# if (defined RTE_CONST_NVM_REQ_OK) || (defined NVM_REQ_OK)
#  if (!defined RTE_CONST_NVM_REQ_OK) || (RTE_CONST_NVM_REQ_OK != 0U)
#   error "Enumeration constant <NVM_REQ_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_OK (0U)
#  define NVM_REQ_OK (0U)
# endif
# if (defined RTE_CONST_NVM_REQ_NOT_OK) || (defined NVM_REQ_NOT_OK)
#  if (!defined RTE_CONST_NVM_REQ_NOT_OK) || (RTE_CONST_NVM_REQ_NOT_OK != 1U)
#   error "Enumeration constant <NVM_REQ_NOT_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NOT_OK (1U)
#  define NVM_REQ_NOT_OK (1U)
# endif
# if (defined RTE_CONST_NVM_REQ_PENDING) || (defined NVM_REQ_PENDING)
#  if (!defined RTE_CONST_NVM_REQ_PENDING) || (RTE_CONST_NVM_REQ_PENDING != 2U)
#   error "Enumeration constant <NVM_REQ_PENDING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_PENDING (2U)
#  define NVM_REQ_PENDING (2U)
# endif
# if (defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (defined NVM_REQ_INTEGRITY_FAILED)
#  if (!defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (RTE_CONST_NVM_REQ_INTEGRITY_FAILED != 3U)
#   error "Enumeration constant <NVM_REQ_INTEGRITY_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_INTEGRITY_FAILED (3U)
#  define NVM_REQ_INTEGRITY_FAILED (3U)
# endif
# if (defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (defined NVM_REQ_BLOCK_SKIPPED)
#  if (!defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (RTE_CONST_NVM_REQ_BLOCK_SKIPPED != 4U)
#   error "Enumeration constant <NVM_REQ_BLOCK_SKIPPED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_BLOCK_SKIPPED (4U)
#  define NVM_REQ_BLOCK_SKIPPED (4U)
# endif
# if (defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (defined NVM_REQ_NV_INVALIDATED)
#  if (!defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (RTE_CONST_NVM_REQ_NV_INVALIDATED != 5U)
#   error "Enumeration constant <NVM_REQ_NV_INVALIDATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NV_INVALIDATED (5U)
#  define NVM_REQ_NV_INVALIDATED (5U)
# endif

# define Rte_TypeDef_NxtrDiagMgrStatus
typedef uint8 NxtrDiagMgrStatus;
# define NxtrDiagMgrStatus_LowerLimit (0U)
# define NxtrDiagMgrStatus_UpperLimit (255U)
# if (defined RTE_CONST_NTC_STATUS_PASSED) || (defined NTC_STATUS_PASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PASSED) || (RTE_CONST_NTC_STATUS_PASSED != 0U)
#   error "Enumeration constant <NTC_STATUS_PASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PASSED (0U)
#  define NTC_STATUS_PASSED (0U)
# endif
# if (defined RTE_CONST_NTC_STATUS_FAILED) || (defined NTC_STATUS_FAILED)
#  if (!defined RTE_CONST_NTC_STATUS_FAILED) || (RTE_CONST_NTC_STATUS_FAILED != 1U)
#   error "Enumeration constant <NTC_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_FAILED (1U)
#  define NTC_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREPASSED) || (defined NTC_STATUS_PREPASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PREPASSED) || (RTE_CONST_NTC_STATUS_PREPASSED != 2U)
#   error "Enumeration constant <NTC_STATUS_PREPASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREPASSED (2U)
#  define NTC_STATUS_PREPASSED (2U)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREFAILED) || (defined NTC_STATUS_PREFAILED)
#  if (!defined RTE_CONST_NTC_STATUS_PREFAILED) || (RTE_CONST_NTC_STATUS_PREFAILED != 3U)
#   error "Enumeration constant <NTC_STATUS_PREFAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREFAILED (3U)
#  define NTC_STATUS_PREFAILED (3U)
# endif

# define Rte_TypeDef_NxtrOpCycle
typedef uint8 NxtrOpCycle;
# define NxtrOpCycle_LowerLimit (0U)
# define NxtrOpCycle_UpperLimit (0U)
# if (defined RTE_CONST_NxtrDefaultOpCycle) || (defined NxtrDefaultOpCycle)
#  if (!defined RTE_CONST_NxtrDefaultOpCycle) || (RTE_CONST_NxtrDefaultOpCycle != 0U)
#   error "Enumeration constant <NxtrDefaultOpCycle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NxtrDefaultOpCycle (0U)
#  define NxtrDefaultOpCycle (0U)
# endif

# define Rte_TypeDef_NxtrOpCycleState
typedef uint8 NxtrOpCycleState;
# define NxtrOpCycleState_LowerLimit (1U)
# define NxtrOpCycleState_UpperLimit (2U)
# if (defined RTE_CONST_NXTR_CYCLE_STATE_START) || (defined NXTR_CYCLE_STATE_START)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_START) || (RTE_CONST_NXTR_CYCLE_STATE_START != 1U)
#   error "Enumeration constant <NXTR_CYCLE_STATE_START> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_START (1U)
#  define NXTR_CYCLE_STATE_START (1U)
# endif
# if (defined RTE_CONST_NXTR_CYCLE_STATE_END) || (defined NXTR_CYCLE_STATE_END)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_END) || (RTE_CONST_NXTR_CYCLE_STATE_END != 2U)
#   error "Enumeration constant <NXTR_CYCLE_STATE_END> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_END (2U)
#  define NXTR_CYCLE_STATE_END (2U)
# endif

# define Rte_TypeDef_PsaAgArbnDiagCmdReq_Enum
typedef uint8 PsaAgArbnDiagCmdReq_Enum;
# define PsaAgArbnDiagCmdReq_Enum_LowerLimit (0U)
# define PsaAgArbnDiagCmdReq_Enum_UpperLimit (2U)
# if (defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGNOACTN) || (defined PSAAGARBNDIAGCMDREQ_DIAGNOACTN)
#  if (!defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGNOACTN) || (RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGNOACTN != 0U)
#   error "Enumeration constant <PSAAGARBNDIAGCMDREQ_DIAGNOACTN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGNOACTN (0U)
#  define PSAAGARBNDIAGCMDREQ_DIAGNOACTN (0U)
# endif
# if (defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGRSTREQ) || (defined PSAAGARBNDIAGCMDREQ_DIAGRSTREQ)
#  if (!defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGRSTREQ) || (RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGRSTREQ != 1U)
#   error "Enumeration constant <PSAAGARBNDIAGCMDREQ_DIAGRSTREQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGRSTREQ (1U)
#  define PSAAGARBNDIAGCMDREQ_DIAGRSTREQ (1U)
# endif
# if (defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGCENTR) || (defined PSAAGARBNDIAGCMDREQ_DIAGCENTR)
#  if (!defined RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGCENTR) || (RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGCENTR != 2U)
#   error "Enumeration constant <PSAAGARBNDIAGCMDREQ_DIAGCENTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNDIAGCMDREQ_DIAGCENTR (2U)
#  define PSAAGARBNDIAGCMDREQ_DIAGCENTR (2U)
# endif

# define Rte_TypeDef_PsaAgArbnSt_Enum
typedef uint8 PsaAgArbnSt_Enum;
# define PsaAgArbnSt_Enum_LowerLimit (0U)
# define PsaAgArbnSt_Enum_UpperLimit (7U)
# if (defined RTE_CONST_PSAAGARBNST_STININ) || (defined PSAAGARBNST_STININ)
#  if (!defined RTE_CONST_PSAAGARBNST_STININ) || (RTE_CONST_PSAAGARBNST_STININ != 0U)
#   error "Enumeration constant <PSAAGARBNST_STININ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STININ (0U)
#  define PSAAGARBNST_STININ (0U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STPND) || (defined PSAAGARBNST_STPND)
#  if (!defined RTE_CONST_PSAAGARBNST_STPND) || (RTE_CONST_PSAAGARBNST_STPND != 1U)
#   error "Enumeration constant <PSAAGARBNST_STPND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STPND (1U)
#  define PSAAGARBNST_STPND (1U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STNOSYNCN) || (defined PSAAGARBNST_STNOSYNCN)
#  if (!defined RTE_CONST_PSAAGARBNST_STNOSYNCN) || (RTE_CONST_PSAAGARBNST_STNOSYNCN != 2U)
#   error "Enumeration constant <PSAAGARBNST_STNOSYNCN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STNOSYNCN (2U)
#  define PSAAGARBNST_STNOSYNCN (2U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STESCSYNCN) || (defined PSAAGARBNST_STESCSYNCN)
#  if (!defined RTE_CONST_PSAAGARBNST_STESCSYNCN) || (RTE_CONST_PSAAGARBNST_STESCSYNCN != 3U)
#   error "Enumeration constant <PSAAGARBNST_STESCSYNCN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STESCSYNCN (3U)
#  define PSAAGARBNST_STESCSYNCN (3U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STDIAGSYNCN) || (defined PSAAGARBNST_STDIAGSYNCN)
#  if (!defined RTE_CONST_PSAAGARBNST_STDIAGSYNCN) || (RTE_CONST_PSAAGARBNST_STDIAGSYNCN != 4U)
#   error "Enumeration constant <PSAAGARBNST_STDIAGSYNCN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STDIAGSYNCN (4U)
#  define PSAAGARBNST_STDIAGSYNCN (4U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STALTVSYNCN) || (defined PSAAGARBNST_STALTVSYNCN)
#  if (!defined RTE_CONST_PSAAGARBNST_STALTVSYNCN) || (RTE_CONST_PSAAGARBNST_STALTVSYNCN != 5U)
#   error "Enumeration constant <PSAAGARBNST_STALTVSYNCN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STALTVSYNCN (5U)
#  define PSAAGARBNST_STALTVSYNCN (5U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_UNUSED) || (defined PSAAGARBNST_UNUSED)
#  if (!defined RTE_CONST_PSAAGARBNST_UNUSED) || (RTE_CONST_PSAAGARBNST_UNUSED != 6U)
#   error "Enumeration constant <PSAAGARBNST_UNUSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_UNUSED (6U)
#  define PSAAGARBNST_UNUSED (6U)
# endif
# if (defined RTE_CONST_PSAAGARBNST_STFAIL) || (defined PSAAGARBNST_STFAIL)
#  if (!defined RTE_CONST_PSAAGARBNST_STFAIL) || (RTE_CONST_PSAAGARBNST_STFAIL != 7U)
#   error "Enumeration constant <PSAAGARBNST_STFAIL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAGARBNST_STFAIL (7U)
#  define PSAAGARBNST_STFAIL (7U)
# endif

# define Rte_TypeDef_PsaApaSt_Cnt_enum
typedef uint8 PsaApaSt_Cnt_enum;
# define PsaApaSt_Cnt_enum_LowerLimit (0U)
# define PsaApaSt_Cnt_enum_UpperLimit (3U)
# if (defined RTE_CONST_PSAAPAST_UNAVL) || (defined PSAAPAST_UNAVL)
#  if (!defined RTE_CONST_PSAAPAST_UNAVL) || (RTE_CONST_PSAAPAST_UNAVL != 0U)
#   error "Enumeration constant <PSAAPAST_UNAVL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPAST_UNAVL (0U)
#  define PSAAPAST_UNAVL (0U)
# endif
# if (defined RTE_CONST_PSAAPAST_AVL) || (defined PSAAPAST_AVL)
#  if (!defined RTE_CONST_PSAAPAST_AVL) || (RTE_CONST_PSAAPAST_AVL != 1U)
#   error "Enumeration constant <PSAAPAST_AVL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPAST_AVL (1U)
#  define PSAAPAST_AVL (1U)
# endif
# if (defined RTE_CONST_PSAAPAST_CTRLPRGS) || (defined PSAAPAST_CTRLPRGS)
#  if (!defined RTE_CONST_PSAAPAST_CTRLPRGS) || (RTE_CONST_PSAAPAST_CTRLPRGS != 2U)
#   error "Enumeration constant <PSAAPAST_CTRLPRGS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPAST_CTRLPRGS (2U)
#  define PSAAPAST_CTRLPRGS (2U)
# endif
# if (defined RTE_CONST_PSAAPAST_DFCT) || (defined PSAAPAST_DFCT)
#  if (!defined RTE_CONST_PSAAPAST_DFCT) || (RTE_CONST_PSAAPAST_DFCT != 3U)
#   error "Enumeration constant <PSAAPAST_DFCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPAST_DFCT (3U)
#  define PSAAPAST_DFCT (3U)
# endif

# define Rte_TypeDef_PsaApaTranCause_Cnt_enum
typedef uint8 PsaApaTranCause_Cnt_enum;
# define PsaApaTranCause_Cnt_enum_LowerLimit (0U)
# define PsaApaTranCause_Cnt_enum_UpperLimit (7U)
# if (defined RTE_CONST_PSAAPATRANCAUSE_NOINTRPT) || (defined PSAAPATRANCAUSE_NOINTRPT)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_NOINTRPT) || (RTE_CONST_PSAAPATRANCAUSE_NOINTRPT != 0U)
#   error "Enumeration constant <PSAAPATRANCAUSE_NOINTRPT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_NOINTRPT (0U)
#  define PSAAPATRANCAUSE_NOINTRPT (0U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_DRVRINTV) || (defined PSAAPATRANCAUSE_DRVRINTV)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_DRVRINTV) || (RTE_CONST_PSAAPATRANCAUSE_DRVRINTV != 1U)
#   error "Enumeration constant <PSAAPATRANCAUSE_DRVRINTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_DRVRINTV (1U)
#  define PSAAPATRANCAUSE_DRVRINTV (1U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_VEHSPDHI) || (defined PSAAPATRANCAUSE_VEHSPDHI)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_VEHSPDHI) || (RTE_CONST_PSAAPATRANCAUSE_VEHSPDHI != 2U)
#   error "Enumeration constant <PSAAPATRANCAUSE_VEHSPDHI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_VEHSPDHI (2U)
#  define PSAAPATRANCAUSE_VEHSPDHI (2U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_AGLERR) || (defined PSAAPATRANCAUSE_AGLERR)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_AGLERR) || (RTE_CONST_PSAAPATRANCAUSE_AGLERR != 3U)
#   error "Enumeration constant <PSAAPATRANCAUSE_AGLERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_AGLERR (3U)
#  define PSAAPATRANCAUSE_AGLERR (3U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_MTRSTALL) || (defined PSAAPATRANCAUSE_MTRSTALL)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_MTRSTALL) || (RTE_CONST_PSAAPATRANCAUSE_MTRSTALL != 4U)
#   error "Enumeration constant <PSAAPATRANCAUSE_MTRSTALL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_MTRSTALL (4U)
#  define PSAAPATRANCAUSE_MTRSTALL (4U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_UNUSED) || (defined PSAAPATRANCAUSE_UNUSED)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_UNUSED) || (RTE_CONST_PSAAPATRANCAUSE_UNUSED != 5U)
#   error "Enumeration constant <PSAAPATRANCAUSE_UNUSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_UNUSED (5U)
#  define PSAAPATRANCAUSE_UNUSED (5U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_THERMLIM) || (defined PSAAPATRANCAUSE_THERMLIM)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_THERMLIM) || (RTE_CONST_PSAAPATRANCAUSE_THERMLIM != 6U)
#   error "Enumeration constant <PSAAPATRANCAUSE_THERMLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_THERMLIM (6U)
#  define PSAAPATRANCAUSE_THERMLIM (6U)
# endif
# if (defined RTE_CONST_PSAAPATRANCAUSE_OTHERERR) || (defined PSAAPATRANCAUSE_OTHERERR)
#  if (!defined RTE_CONST_PSAAPATRANCAUSE_OTHERERR) || (RTE_CONST_PSAAPATRANCAUSE_OTHERERR != 7U)
#   error "Enumeration constant <PSAAPATRANCAUSE_OTHERERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAAPATRANCAUSE_OTHERERR (7U)
#  define PSAAPATRANCAUSE_OTHERERR (7U)
# endif

# define Rte_TypeDef_PsaEpsStLxa_Cnt_enum
typedef uint8 PsaEpsStLxa_Cnt_enum;
# define PsaEpsStLxa_Cnt_enum_LowerLimit (0U)
# define PsaEpsStLxa_Cnt_enum_UpperLimit (4U)
# if (defined RTE_CONST_PSAEPSSTLXA_UNAUTHD) || (defined PSAEPSSTLXA_UNAUTHD)
#  if (!defined RTE_CONST_PSAEPSSTLXA_UNAUTHD) || (RTE_CONST_PSAEPSSTLXA_UNAUTHD != 0U)
#   error "Enumeration constant <PSAEPSSTLXA_UNAUTHD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAEPSSTLXA_UNAUTHD (0U)
#  define PSAEPSSTLXA_UNAUTHD (0U)
# endif
# if (defined RTE_CONST_PSAEPSSTLXA_AUTHD) || (defined PSAEPSSTLXA_AUTHD)
#  if (!defined RTE_CONST_PSAEPSSTLXA_AUTHD) || (RTE_CONST_PSAEPSSTLXA_AUTHD != 1U)
#   error "Enumeration constant <PSAEPSSTLXA_AUTHD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAEPSSTLXA_AUTHD (1U)
#  define PSAEPSSTLXA_AUTHD (1U)
# endif
# if (defined RTE_CONST_PSAEPSSTLXA_AVL) || (defined PSAEPSSTLXA_AVL)
#  if (!defined RTE_CONST_PSAEPSSTLXA_AVL) || (RTE_CONST_PSAEPSSTLXA_AVL != 2U)
#   error "Enumeration constant <PSAEPSSTLXA_AVL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAEPSSTLXA_AVL (2U)
#  define PSAEPSSTLXA_AVL (2U)
# endif
# if (defined RTE_CONST_PSAEPSSTLXA_ACTV) || (defined PSAEPSSTLXA_ACTV)
#  if (!defined RTE_CONST_PSAEPSSTLXA_ACTV) || (RTE_CONST_PSAEPSSTLXA_ACTV != 3U)
#   error "Enumeration constant <PSAEPSSTLXA_ACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAEPSSTLXA_ACTV (3U)
#  define PSAEPSSTLXA_ACTV (3U)
# endif
# if (defined RTE_CONST_PSAEPSSTLXA_DFCT) || (defined PSAEPSSTLXA_DFCT)
#  if (!defined RTE_CONST_PSAEPSSTLXA_DFCT) || (RTE_CONST_PSAEPSSTLXA_DFCT != 4U)
#   error "Enumeration constant <PSAEPSSTLXA_DFCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSAEPSSTLXA_DFCT (4U)
#  define PSAEPSSTLXA_DFCT (4U)
# endif

# define Rte_TypeDef_PsaLxaSt_Cnt_enum
typedef uint8 PsaLxaSt_Cnt_enum;
# define PsaLxaSt_Cnt_enum_LowerLimit (0U)
# define PsaLxaSt_Cnt_enum_UpperLimit (6U)
# if (defined RTE_CONST_PSALXAST_UNAVL) || (defined PSALXAST_UNAVL)
#  if (!defined RTE_CONST_PSALXAST_UNAVL) || (RTE_CONST_PSALXAST_UNAVL != 0U)
#   error "Enumeration constant <PSALXAST_UNAVL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_UNAVL (0U)
#  define PSALXAST_UNAVL (0U)
# endif
# if (defined RTE_CONST_PSALXAST_UNSELD) || (defined PSALXAST_UNSELD)
#  if (!defined RTE_CONST_PSALXAST_UNSELD) || (RTE_CONST_PSALXAST_UNSELD != 1U)
#   error "Enumeration constant <PSALXAST_UNSELD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_UNSELD (1U)
#  define PSALXAST_UNSELD (1U)
# endif
# if (defined RTE_CONST_PSALXAST_SELD) || (defined PSALXAST_SELD)
#  if (!defined RTE_CONST_PSALXAST_SELD) || (RTE_CONST_PSALXAST_SELD != 2U)
#   error "Enumeration constant <PSALXAST_SELD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_SELD (2U)
#  define PSALXAST_SELD (2U)
# endif
# if (defined RTE_CONST_PSALXAST_AUTHD) || (defined PSALXAST_AUTHD)
#  if (!defined RTE_CONST_PSALXAST_AUTHD) || (RTE_CONST_PSALXAST_AUTHD != 3U)
#   error "Enumeration constant <PSALXAST_AUTHD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_AUTHD (3U)
#  define PSALXAST_AUTHD (3U)
# endif
# if (defined RTE_CONST_PSALXAST_ACTV) || (defined PSALXAST_ACTV)
#  if (!defined RTE_CONST_PSALXAST_ACTV) || (RTE_CONST_PSALXAST_ACTV != 4U)
#   error "Enumeration constant <PSALXAST_ACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_ACTV (4U)
#  define PSALXAST_ACTV (4U)
# endif
# if (defined RTE_CONST_PSALXAST_DFCT) || (defined PSALXAST_DFCT)
#  if (!defined RTE_CONST_PSALXAST_DFCT) || (RTE_CONST_PSALXAST_DFCT != 5U)
#   error "Enumeration constant <PSALXAST_DFCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_DFCT (5U)
#  define PSALXAST_DFCT (5U)
# endif
# if (defined RTE_CONST_PSALXAST_COLLRISK) || (defined PSALXAST_COLLRISK)
#  if (!defined RTE_CONST_PSALXAST_COLLRISK) || (RTE_CONST_PSALXAST_COLLRISK != 6U)
#   error "Enumeration constant <PSALXAST_COLLRISK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSALXAST_COLLRISK (6U)
#  define PSALXAST_COLLRISK (6U)
# endif

# define Rte_TypeDef_PsaTunModSt_Cnt_enum
typedef uint8 PsaTunModSt_Cnt_enum;
# define PsaTunModSt_Cnt_enum_LowerLimit (0U)
# define PsaTunModSt_Cnt_enum_UpperLimit (3U)
# if (defined RTE_CONST_PSATUNMODST_NORM) || (defined PSATUNMODST_NORM)
#  if (!defined RTE_CONST_PSATUNMODST_NORM) || (RTE_CONST_PSATUNMODST_NORM != 0U)
#   error "Enumeration constant <PSATUNMODST_NORM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSATUNMODST_NORM (0U)
#  define PSATUNMODST_NORM (0U)
# endif
# if (defined RTE_CONST_PSATUNMODST_SPORT) || (defined PSATUNMODST_SPORT)
#  if (!defined RTE_CONST_PSATUNMODST_SPORT) || (RTE_CONST_PSATUNMODST_SPORT != 1U)
#   error "Enumeration constant <PSATUNMODST_SPORT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSATUNMODST_SPORT (1U)
#  define PSATUNMODST_SPORT (1U)
# endif
# if (defined RTE_CONST_PSATUNMODST_TUN) || (defined PSATUNMODST_TUN)
#  if (!defined RTE_CONST_PSATUNMODST_TUN) || (RTE_CONST_PSATUNMODST_TUN != 2U)
#   error "Enumeration constant <PSATUNMODST_TUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSATUNMODST_TUN (2U)
#  define PSATUNMODST_TUN (2U)
# endif
# if (defined RTE_CONST_PSATUNMODST_FAILD) || (defined PSATUNMODST_FAILD)
#  if (!defined RTE_CONST_PSATUNMODST_FAILD) || (RTE_CONST_PSATUNMODST_FAILD != 3U)
#   error "Enumeration constant <PSATUNMODST_FAILD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PSATUNMODST_FAILD (3U)
#  define PSATUNMODST_FAILD (3U)
# endif

# define Rte_TypeDef_SS_State_enum
typedef uint8 SS_State_enum;
# define SS_State_enum_LowerLimit (0U)
# define SS_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_SS_Normal) || (defined SS_Normal)
#  if (!defined RTE_CONST_SS_Normal) || (RTE_CONST_SS_Normal != 0U)
#   error "Enumeration constant <SS_Normal> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Normal (0U)
#  define SS_Normal (0U)
# endif
# if (defined RTE_CONST_SS_Intermediate1) || (defined SS_Intermediate1)
#  if (!defined RTE_CONST_SS_Intermediate1) || (RTE_CONST_SS_Intermediate1 != 1U)
#   error "Enumeration constant <SS_Intermediate1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Intermediate1 (1U)
#  define SS_Intermediate1 (1U)
# endif
# if (defined RTE_CONST_SS_Stop) || (defined SS_Stop)
#  if (!defined RTE_CONST_SS_Stop) || (RTE_CONST_SS_Stop != 2U)
#   error "Enumeration constant <SS_Stop> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Stop (2U)
#  define SS_Stop (2U)
# endif
# if (defined RTE_CONST_SS_Intermediate2) || (defined SS_Intermediate2)
#  if (!defined RTE_CONST_SS_Intermediate2) || (RTE_CONST_SS_Intermediate2 != 3U)
#   error "Enumeration constant <SS_Intermediate2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Intermediate2 (3U)
#  define SS_Intermediate2 (3U)
# endif
# if (defined RTE_CONST_SS_Fault) || (defined SS_Fault)
#  if (!defined RTE_CONST_SS_Fault) || (RTE_CONST_SS_Fault != 4U)
#   error "Enumeration constant <SS_Fault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Fault (4U)
#  define SS_Fault (4U)
# endif
# if (defined RTE_CONST_SS_Disable) || (defined SS_Disable)
#  if (!defined RTE_CONST_SS_Disable) || (RTE_CONST_SS_Disable != 5U)
#   error "Enumeration constant <SS_Disable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SS_Disable (5U)
#  define SS_Disable (5U)
# endif

# define Rte_TypeDef_SigQlfr_State_enum
typedef uint8 SigQlfr_State_enum;
# define SigQlfr_State_enum_LowerLimit (0U)
# define SigQlfr_State_enum_UpperLimit (2U)
# if (defined RTE_CONST_SIGQLFR_NORES) || (defined SIGQLFR_NORES)
#  if (!defined RTE_CONST_SIGQLFR_NORES) || (RTE_CONST_SIGQLFR_NORES != 0U)
#   error "Enumeration constant <SIGQLFR_NORES> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_NORES (0U)
#  define SIGQLFR_NORES (0U)
# endif
# if (defined RTE_CONST_SIGQLFR_PASS) || (defined SIGQLFR_PASS)
#  if (!defined RTE_CONST_SIGQLFR_PASS) || (RTE_CONST_SIGQLFR_PASS != 1U)
#   error "Enumeration constant <SIGQLFR_PASS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_PASS (1U)
#  define SIGQLFR_PASS (1U)
# endif
# if (defined RTE_CONST_SIGQLFR_FAIL) || (defined SIGQLFR_FAIL)
#  if (!defined RTE_CONST_SIGQLFR_FAIL) || (RTE_CONST_SIGQLFR_FAIL != 2U)
#   error "Enumeration constant <SIGQLFR_FAIL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_FAIL (2U)
#  define SIGQLFR_FAIL (2U)
# endif

# define Rte_TypeDef_StaMd_Users
typedef uint8 StaMd_Users;
# define StaMd_Users_LowerLimit (0U)
# define StaMd_Users_UpperLimit (15U)
# if (defined RTE_CONST_STAMD_STOPCTRL) || (defined STAMD_STOPCTRL)
#  if (!defined RTE_CONST_STAMD_STOPCTRL) || (RTE_CONST_STAMD_STOPCTRL != 0U)
#   error "Enumeration constant <STAMD_STOPCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_STOPCTRL (0U)
#  define STAMD_STOPCTRL (0U)
# endif
# if (defined RTE_CONST_STAMD_VEHPWRMD) || (defined STAMD_VEHPWRMD)
#  if (!defined RTE_CONST_STAMD_VEHPWRMD) || (RTE_CONST_STAMD_VEHPWRMD != 1U)
#   error "Enumeration constant <STAMD_VEHPWRMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_VEHPWRMD (1U)
#  define STAMD_VEHPWRMD (1U)
# endif
# if (defined RTE_CONST_STAMD_DIAGMGR) || (defined STAMD_DIAGMGR)
#  if (!defined RTE_CONST_STAMD_DIAGMGR) || (RTE_CONST_STAMD_DIAGMGR != 2U)
#   error "Enumeration constant <STAMD_DIAGMGR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_DIAGMGR (2U)
#  define STAMD_DIAGMGR (2U)
# endif
# if (defined RTE_CONST_STAMD_PHSDSCNCT) || (defined STAMD_PHSDSCNCT)
#  if (!defined RTE_CONST_STAMD_PHSDSCNCT) || (RTE_CONST_STAMD_PHSDSCNCT != 3U)
#   error "Enumeration constant <STAMD_PHSDSCNCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_PHSDSCNCT (3U)
#  define STAMD_PHSDSCNCT (3U)
# endif
# if (defined RTE_CONST_STAMD_MTRDRVR) || (defined STAMD_MTRDRVR)
#  if (!defined RTE_CONST_STAMD_MTRDRVR) || (RTE_CONST_STAMD_MTRDRVR != 4U)
#   error "Enumeration constant <STAMD_MTRDRVR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_MTRDRVR (4U)
#  define STAMD_MTRDRVR (4U)
# endif
# if (defined RTE_CONST_STAMD_TMPRLMON) || (defined STAMD_TMPRLMON)
#  if (!defined RTE_CONST_STAMD_TMPRLMON) || (RTE_CONST_STAMD_TMPRLMON != 5U)
#   error "Enumeration constant <STAMD_TMPRLMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_TMPRLMON (5U)
#  define STAMD_TMPRLMON (5U)
# endif
# if (defined RTE_CONST_STAMD_HWPWUP) || (defined STAMD_HWPWUP)
#  if (!defined RTE_CONST_STAMD_HWPWUP) || (RTE_CONST_STAMD_HWPWUP != 6U)
#   error "Enumeration constant <STAMD_HWPWUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_HWPWUP (6U)
#  define STAMD_HWPWUP (6U)
# endif
# if (defined RTE_CONST_STAMD_MTRPOSDIAG) || (defined STAMD_MTRPOSDIAG)
#  if (!defined RTE_CONST_STAMD_MTRPOSDIAG) || (RTE_CONST_STAMD_MTRPOSDIAG != 7U)
#   error "Enumeration constant <STAMD_MTRPOSDIAG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_MTRPOSDIAG (7U)
#  define STAMD_MTRPOSDIAG (7U)
# endif

# define Rte_TypeDef_SteerMod_enum
typedef uint8 SteerMod_enum;
# define SteerMod_enum_LowerLimit (0U)
# define SteerMod_enum_UpperLimit (2U)
# if (defined RTE_CONST_STEERMOD_BASEPS) || (defined STEERMOD_BASEPS)
#  if (!defined RTE_CONST_STEERMOD_BASEPS) || (RTE_CONST_STEERMOD_BASEPS != 0U)
#   error "Enumeration constant <STEERMOD_BASEPS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_BASEPS (0U)
#  define STEERMOD_BASEPS (0U)
# endif
# if (defined RTE_CONST_STEERMOD_SEMIATNMS) || (defined STEERMOD_SEMIATNMS)
#  if (!defined RTE_CONST_STEERMOD_SEMIATNMS) || (RTE_CONST_STEERMOD_SEMIATNMS != 1U)
#   error "Enumeration constant <STEERMOD_SEMIATNMS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_SEMIATNMS (1U)
#  define STEERMOD_SEMIATNMS (1U)
# endif
# if (defined RTE_CONST_STEERMOD_FULLYATNMS) || (defined STEERMOD_FULLYATNMS)
#  if (!defined RTE_CONST_STEERMOD_FULLYATNMS) || (RTE_CONST_STEERMOD_FULLYATNMS != 2U)
#   error "Enumeration constant <STEERMOD_FULLYATNMS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_FULLYATNMS (2U)
#  define STEERMOD_FULLYATNMS (2U)
# endif

# define Rte_TypeDef_SysPrfmncSt_Cnt_enum
typedef uint8 SysPrfmncSt_Cnt_enum;
# define SysPrfmncSt_Cnt_enum_LowerLimit (0U)
# define SysPrfmncSt_Cnt_enum_UpperLimit (15U)
# if (defined RTE_CONST_SYSPRFMNCST_NORM) || (defined SYSPRFMNCST_NORM)
#  if (!defined RTE_CONST_SYSPRFMNCST_NORM) || (RTE_CONST_SYSPRFMNCST_NORM != 0U)
#   error "Enumeration constant <SYSPRFMNCST_NORM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_NORM (0U)
#  define SYSPRFMNCST_NORM (0U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN) || (defined SYSPRFMNCST_DUTYCYCDPTWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN) || (RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN != 1U)
#   error "Enumeration constant <SYSPRFMNCST_DUTYCYCDPTWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN (1U)
#  define SYSPRFMNCST_DUTYCYCDPTWARN (1U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM) || (defined SYSPRFMNCST_DUTYCYCDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM) || (RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM != 2U)
#   error "Enumeration constant <SYSPRFMNCST_DUTYCYCDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM (2U)
#  define SYSPRFMNCST_DUTYCYCDPTLIM (2U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_TDPTWARN) || (defined SYSPRFMNCST_TDPTWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_TDPTWARN) || (RTE_CONST_SYSPRFMNCST_TDPTWARN != 3U)
#   error "Enumeration constant <SYSPRFMNCST_TDPTWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_TDPTWARN (3U)
#  define SYSPRFMNCST_TDPTWARN (3U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_TDPTLIM) || (defined SYSPRFMNCST_TDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_TDPTLIM) || (RTE_CONST_SYSPRFMNCST_TDPTLIM != 4U)
#   error "Enumeration constant <SYSPRFMNCST_TDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_TDPTLIM (4U)
#  define SYSPRFMNCST_TDPTLIM (4U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM) || (defined SYSPRFMNCST_ASSISTALLDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM) || (RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM != 6U)
#   error "Enumeration constant <SYSPRFMNCST_ASSISTALLDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM (6U)
#  define SYSPRFMNCST_ASSISTALLDPTLIM (6U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN) || (defined SYSPRFMNCST_HWAGTOMOTAGCORRLN)
#  if (!defined RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN) || (RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN != 8U)
#   error "Enumeration constant <SYSPRFMNCST_HWAGTOMOTAGCORRLN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN (8U)
#  define SYSPRFMNCST_HWAGTOMOTAGCORRLN (8U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_KINEINTDIAGC) || (defined SYSPRFMNCST_KINEINTDIAGC)
#  if (!defined RTE_CONST_SYSPRFMNCST_KINEINTDIAGC) || (RTE_CONST_SYSPRFMNCST_KINEINTDIAGC != 9U)
#   error "Enumeration constant <SYSPRFMNCST_KINEINTDIAGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_KINEINTDIAGC (9U)
#  define SYSPRFMNCST_KINEINTDIAGC (9U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN) || (defined SYSPRFMNCST_LOASWBASDMTGTN)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN) || (RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN != 10U)
#   error "Enumeration constant <SYSPRFMNCST_LOASWBASDMTGTN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN (10U)
#  define SYSPRFMNCST_LOASWBASDMTGTN (10U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_SYSSTDI) || (defined SYSPRFMNCST_SYSSTDI)
#  if (!defined RTE_CONST_SYSPRFMNCST_SYSSTDI) || (RTE_CONST_SYSPRFMNCST_SYSSTDI != 15U)
#   error "Enumeration constant <SYSPRFMNCST_SYSSTDI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_SYSSTDI (15U)
#  define SYSPRFMNCST_SYSSTDI (15U)
# endif

# define Rte_TypeDef_TuningSessionAddrPtrEnum
typedef uint8 TuningSessionAddrPtrEnum;
# define TuningSessionAddrPtrEnum_LowerLimit (0U)
# define TuningSessionAddrPtrEnum_UpperLimit (255U)
# if (defined RTE_CONST_TUN_SESSION_PTR_PERS) || (defined TUN_SESSION_PTR_PERS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_PERS) || (RTE_CONST_TUN_SESSION_PTR_PERS != 0U)
#   error "Enumeration constant <TUN_SESSION_PTR_PERS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_PERS (0U)
#  define TUN_SESSION_PTR_PERS (0U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETS) || (defined TUN_SESSION_PTR_SETS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETS) || (RTE_CONST_TUN_SESSION_PTR_SETS != 1U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETS (1U)
#  define TUN_SESSION_PTR_SETS (1U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (defined TUN_SESSION_PTR_COMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (RTE_CONST_TUN_SESSION_PTR_COMMON != 2U)
#   error "Enumeration constant <TUN_SESSION_PTR_COMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_COMMON (2U)
#  define TUN_SESSION_PTR_COMMON (2U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (defined TUN_SESSION_PTR_SETANDPER)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (RTE_CONST_TUN_SESSION_PTR_SETANDPER != 3U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPER (3U)
#  define TUN_SESSION_PTR_SETANDPER (3U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (defined TUN_SESSION_PTR_SETANDPERANDCOMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON != 4U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPERANDCOMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
#  define TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (defined TUN_SESSION_PTR_CUSTSEG)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (RTE_CONST_TUN_SESSION_PTR_CUSTSEG != 16U)
#   error "Enumeration constant <TUN_SESSION_PTR_CUSTSEG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_CUSTSEG (16U)
#  define TUN_SESSION_PTR_CUSTSEG (16U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (defined TUN_SESSION_PTR_DISABLED)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (RTE_CONST_TUN_SESSION_PTR_DISABLED != 255U)
#   error "Enumeration constant <TUN_SESSION_PTR_DISABLED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_DISABLED (255U)
#  define TUN_SESSION_PTR_DISABLED (255U)
# endif

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
# define WdgM_GlobalStatusType_LowerLimit (0U)
# define WdgM_GlobalStatusType_UpperLimit (255U)
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (defined WDGM_GLOBAL_STATUS_OK)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (RTE_CONST_WDGM_GLOBAL_STATUS_OK != 0U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_OK (0U)
#  define WDGM_GLOBAL_STATUS_OK (0U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (defined WDGM_GLOBAL_STATUS_FAILED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (RTE_CONST_WDGM_GLOBAL_STATUS_FAILED != 1U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_FAILED (1U)
#  define WDGM_GLOBAL_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (defined WDGM_GLOBAL_STATUS_EXPIRED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED != 2U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_EXPIRED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  define WDGM_GLOBAL_STATUS_EXPIRED (2U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (defined WDGM_GLOBAL_STATUS_STOPPED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED != 3U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_STOPPED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED (3U)
#  define WDGM_GLOBAL_STATUS_STOPPED (3U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (defined WDGM_GLOBAL_STATUS_DEACTIVATED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED != 4U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_DEACTIVATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
# endif

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
# define WdgM_LocalStatusType_LowerLimit (0U)
# define WdgM_LocalStatusType_UpperLimit (255U)
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (defined WDGM_LOCAL_STATUS_OK)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (RTE_CONST_WDGM_LOCAL_STATUS_OK != 0U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_OK (0U)
#  define WDGM_LOCAL_STATUS_OK (0U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (defined WDGM_LOCAL_STATUS_FAILED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (RTE_CONST_WDGM_LOCAL_STATUS_FAILED != 1U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_FAILED (1U)
#  define WDGM_LOCAL_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (defined WDGM_LOCAL_STATUS_EXPIRED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED != 2U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_EXPIRED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED (2U)
#  define WDGM_LOCAL_STATUS_EXPIRED (2U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (defined WDGM_LOCAL_STATUS_DEACTIVATED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED != 4U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_DEACTIVATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
# endif

# define Rte_TypeDef_AvgFricLrnRangeCounterSubType
typedef UInt16 AvgFricLrnRangeCounterSubType[3];

# define Rte_TypeDef_AvgFricLrnThetaSubType
typedef Float AvgFricLrnThetaSubType[4];

# define Rte_TypeDef_AvgFricLrnVehLearnedFricType
typedef Float AvgFricLrnVehLearnedFricType[4];

# define Rte_TypeDef_CanMsgType
typedef UInt8 CanMsgType[8];

# define Rte_TypeDef_CoggingCancTrq
typedef UInt16 CoggingCancTrq[512];

# define Rte_TypeDef_CoggingCancTrqRplComp
typedef UInt16 CoggingCancTrqRplComp[9];

# define Rte_TypeDef_CurrTempOffsetTblType
typedef SInt16 CurrTempOffsetTblType[16];

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef UInt8 Dem_MaxDataValueType[3];

# define Rte_TypeDef_HarCompTbl
typedef SInt16 HarCompTbl[1024];

# define Rte_TypeDef_NvM_DestPtr
typedef UInt8 NvM_DestPtr[65535];

# define Rte_TypeDef_EOLChOffsetTrim_DataType
typedef struct
{
  Float HwTqArb_EOLChOffsetTrim_HwNm_f32;
  Boolean HwTqArb_EOLChOffsetTrimPerf_Cnt_lgc;
} EOLChOffsetTrim_DataType;

# define Rte_TypeDef_EOLHwPosTrimType
typedef struct
{
  Float EOLVehCntrOffset_HwDeg_f32;
  UInt16 EOLHwPosTrimPerformed_Cnt_u16;
} EOLHwPosTrimType;

# define Rte_TypeDef_EOLNomMtrParamType
typedef struct
{
  Float NomKe_VpRadpS_f32;
  Float NomRmtr_Ohm_f32;
} EOLNomMtrParamType;

# define Rte_TypeDef_EOTLearned_DataType
typedef struct
{
  Float CWEOTPosition_HwDeg_f32;
  Float CCWEOTPosition_HwDeg_f32;
  Boolean CWEOTFound_Cnt_lgc;
  Boolean CCWEOTFound_Cnt_lgc;
} EOTLearned_DataType;

# define Rte_TypeDef_FaultDataType
typedef struct
{
  UInt8 Byte1_Cnt_u08;
  UInt8 Byte2_Cnt_u08;
  UInt8 Byte3_Cnt_u08;
  UInt8 Byte4_Cnt_u08;
  UInt8 Byte5_Cnt_u08;
  UInt8 Byte6_Cnt_u08;
  UInt8 Reserved1_Cnt_u08;
  UInt8 Reserved2_Cnt_u08;
} FaultDataType;

# define Rte_TypeDef_IS_DAT_DIRA_Msg
typedef struct
{
  CPLE_VOLANT CpleVolant;
  ETAT_DA_2004 EtatDa2004;
  ETAT_DA_DYN EtatDaDyn;
  ETAT_DA_2010 EtatDa2010;
  TRQ_LIMIT_STATE TrqLimitState;
  STEERWHL_HOLD_BY_DRV SteerwhlHoldByDrv;
  EPS_STATE_LKA EpsStateLka;
  AUTOR_ARRET_MOT_DA AutorArretMotDa;
  DDE_REDEM_DA DdeRedemDa;
} IS_DAT_DIRA_Msg;

# define Rte_TypeDef_IS_DYN_DAE_Msg
typedef struct
{
  CPT_PROCESS_4B_DAE CptProcess4bDae;
  CHKSUM_TRME_DYN_DAE ChksumTrmeDynDae;
  CPLE_VOLANT_OPTMSE CpleVolantOptimse;
  CAUSE_DESACTIV_CPK CauseDesactivCpk;
  ETAT_DAE_CPK EtatDaeCpk;
  ANGLE_COLONNE AngleColonne;
  ETAT_SECU_ANGLE_COL EtatSecuAngleCol;
  ETAT_DAE_CAV3_VIRTUEL EtatDaeCav3Virtuel;
  VITESSE_COLONNE VitesseColonne;
} IS_DYN_DAE_Msg;

# define Rte_TypeDef_IS_DYN_VOL_MsgAdd
typedef struct
{
  ETAT_CAPT_VOL EtatCaptVol;
  CALIBRATION_VOL CalibrationVol;
  TRIM_VOL TrimVol;
  CODE_DEFAUT_VOL CodeDefaultVol;
  VITESSE_ROT_VOL_OPTIMISE VitesseRotVolOptimise;
  ANGLE_VOLANT_ORIGINE AngleVolantOrigine;
  FLG_AVOL_ICN FlgAvolIcn;
  FLG_INIT_AVOL FlgInitAvol;
} IS_DYN_VOL_MsgAdd;

# define Rte_TypeDef_IS_DYN_VOL_MsgBase
typedef struct
{
  ANGLE_VOLANT AngleVolant;
  VITESSE_ROT_VOL VitesseRotVol;
  SENS_ROT_VOL SensRotVol;
  CPT_PROCESS_4B_A_VOL CptProcess4bAVol;
  CHKSUM_VOL ChksumVol;
} IS_DYN_VOL_MsgBase;

# define Rte_TypeDef_IS_SUPV_DIRA_Msg
typedef struct
{
  CODE_DEFAUT CodeDefaut;
  STATUS_CONFABSENT StatusConfabsent;
  ETAT_ASSIST_DA EtatAssistDa;
  ETAT_LIGNE_APC EtatLigneApc;
} IS_SUPV_DIRA_Msg;

# define Rte_TypeDef_OvervoltageDataType
typedef struct
{
  Float MaxBattVoltage_Volts_f32;
  UInt16 OvervoltageCounter_Cnt_u16;
} OvervoltageDataType;

# define Rte_TypeDef_PhaseCurrCal_DataType
typedef struct
{
  Float EOLMtrCurrVcalCmd_VoltCnts_f32;
  Float EOLMtrCurr1OffsetLo_Volts_f32;
  Float EOLPhscurr1Gain_AmpspVolt_f32;
  Float EOLPhscurr2Gain_AmpspVolt_f32;
  Float EOLMtrCurr2OffsetLo_Volts_f32;
  Float EOLMtrCurr1OffsetDiff_Volts_f32;
  Float EOLMtrCurr2OffsetDiff_Volts_f32;
} PhaseCurrCal_DataType;

# define Rte_TypeDef_Polarity_DataType
typedef struct
{
  UInt32 Polarity_Cnt_u32;
  UInt32 R_Polarity_Cnt_u32;
} Polarity_DataType;

# define Rte_TypeDef_PsaAgAnLrndOffs_Str
typedef struct
{
  Float MaxOffset;
  Float MinOffset;
  UInt8 MaxSrc;
  UInt8 MinSrc;
} PsaAgAnLrndOffs_Str;

# define Rte_TypeDef_QueueDataType
typedef struct
{
  UInt8 QueueEventIdx_Cnt_u08;
  UInt8 Status_Cnt_u08;
} QueueDataType;

# define Rte_TypeDef_ShutdownTimeType
typedef struct
{
  UInt32 Time_Sec_u32;
  Boolean Valid_Cnt_lgc;
} ShutdownTimeType;

# define Rte_TypeDef_SysOutpCpbySig_Str
typedef struct
{
  Float CwHwAg1;
  Float CwHwAg2;
  Float CwHwAg3;
  Float CwHwAg4;
  Float CwHwAg5;
  Float CcwHwAg1;
  Float CcwHwAg2;
  Float CcwHwAg3;
  Float CcwHwAg4;
  Float CcwHwAg5;
} SysOutpCpbySig_Str;

# define Rte_TypeDef_ThrmlDutyCycle_FltStVal_Datatype
typedef struct
{
  UInt8 Filt3Val_Cnt_u8;
  UInt8 Filt4Val_Cnt_u8;
  UInt8 Filt5Val_Cnt_u8;
  UInt8 Filt6Val_Cnt_u8;
} ThrmlDutyCycle_FltStVal_Datatype;

# define Rte_TypeDef_VehDyn_DataType
typedef struct
{
  Float NVMStoredLastPos_HwDeg_f32;
  Boolean NVMStoredLastPosValid_Cnt_lgc;
} VehDyn_DataType;

# define Rte_TypeDef_AvgFricLrnRangeCounterType
typedef AvgFricLrnRangeCounterSubType AvgFricLrnRangeCounterType[8];

# define Rte_TypeDef_AvgFricLrnThetaType
typedef AvgFricLrnThetaSubType AvgFricLrnThetaType[8];

# define Rte_TypeDef_AvgFricLrnType
typedef struct
{
  Float FricOffset_HwNm_f32;
  Float EOLFric_HwNm_f32;
  Boolean EnableFricOffsetOutput_Cnt_lgc;
  Boolean EnableFricLearning_Cnt_lgc;
  UInt8 OpMode_Cnt_enum;
  AvgFricLrnRangeCounterType RangeCounter_Cnt_u16;
  AvgFricLrnThetaType Theta_HwNm_f32;
  AvgFricLrnVehLearnedFricType VehLearnedFric_HwNm_f32;
} AvgFricLrnType;

# define Rte_TypeDef_CurrTempOffsetType
typedef struct
{
  CurrTempOffsetTblType CurrTempOffsetX_DegC_s10p5;
  CurrTempOffsetTblType CurrOffsetY1_Volts_s4p11;
  CurrTempOffsetTblType CurrOffsetY2_Volts_s4p11;
} CurrTempOffsetType;

# define Rte_TypeDef_DigMSBEOLType
typedef struct
{
  UInt16 MtrPosBEMF_Rev_u0p16;
  UInt16 MtrPosBEMFRedundant_Rev_u0p16;
  HarCompTbl MtrPos1HarCompTbl_Rev_s2p13;
  HarCompTbl MtrPos2HarCompTbl_Rev_s2p13;
  UInt16 CRC_Cnt_u16;
} DigMSBEOLType;

# define Rte_TypeDef_FaultDataArrayType
typedef FaultDataType FaultDataArrayType[60];

# define Rte_TypeDef_QueueDataArrayType
typedef QueueDataType QueueDataArrayType[120];

# define Rte_TypeDef_FaultLogType
typedef struct
{
  FaultDataArrayType CTCFailData;
  FaultDataArrayType CTCPassData;
  QueueDataArrayType QueueData;
} FaultLogType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;
#  define EcuM_UserType_LowerLimit (0U)
#  define EcuM_UserType_UpperLimit (255U)

#  define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;
#  define NvM_BlockIdType_LowerLimit (1U)
#  define NvM_BlockIdType_UpperLimit (32767U)

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit (-8)
#  define SInt4_UpperLimit (7)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit (0U)
#  define UInt4_UpperLimit (15U)

#  define Rte_TypeDef_Dem_InitMonitorKindType
typedef uint8 Dem_InitMonitorKindType;
#  define Dem_InitMonitorKindType_LowerLimit (0U)
#  define Dem_InitMonitorKindType_UpperLimit (2U)
#  if (defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (defined DEM_INIT_MONITOR_CLEAR)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (RTE_CONST_DEM_INIT_MONITOR_CLEAR != 1U)
#    error "Enumeration constant <DEM_INIT_MONITOR_CLEAR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_CLEAR (1U)
#   define DEM_INIT_MONITOR_CLEAR (1U)
#  endif
#  if (defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (defined DEM_INIT_MONITOR_RESTART)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (RTE_CONST_DEM_INIT_MONITOR_RESTART != 2U)
#    error "Enumeration constant <DEM_INIT_MONITOR_RESTART> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_RESTART (2U)
#   define DEM_INIT_MONITOR_RESTART (2U)
#  endif

#  define Rte_TypeDef_Dem_SuppressDTCStatusType
typedef uint8 Dem_SuppressDTCStatusType;
#  define Dem_SuppressDTCStatusType_LowerLimit (0U)
#  define Dem_SuppressDTCStatusType_UpperLimit (1U)
#  if (defined RTE_CONST_DEM_SUPPRESS_DTC_OFF) || (defined DEM_SUPPRESS_DTC_OFF)
#   if (!defined RTE_CONST_DEM_SUPPRESS_DTC_OFF) || (RTE_CONST_DEM_SUPPRESS_DTC_OFF != 0U)
#    error "Enumeration constant <DEM_SUPPRESS_DTC_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_SUPPRESS_DTC_OFF (0U)
#   define DEM_SUPPRESS_DTC_OFF (0U)
#  endif
#  if (defined RTE_CONST_DEM_SUPPRESS_DTC_ON) || (defined DEM_SUPPRESS_DTC_ON)
#   if (!defined RTE_CONST_DEM_SUPPRESS_DTC_ON) || (RTE_CONST_DEM_SUPPRESS_DTC_ON != 1U)
#    error "Enumeration constant <DEM_SUPPRESS_DTC_ON> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_SUPPRESS_DTC_ON (1U)
#   define DEM_SUPPRESS_DTC_ON (1U)
#  endif

#  define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
#  define EcuM_StateType_LowerLimit (16U)
#  define EcuM_StateType_UpperLimit (255U)
#  if (defined RTE_CONST_ECUM_STATE_STARTUP) || (defined ECUM_STATE_STARTUP)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP) || (RTE_CONST_ECUM_STATE_STARTUP != 16U)
#    error "Enumeration constant <ECUM_STATE_STARTUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP (16U)
#   define ECUM_STATE_STARTUP (16U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (defined ECUM_STATE_STARTUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (RTE_CONST_ECUM_STATE_STARTUP_ONE != 17U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_ONE (17U)
#   define ECUM_STATE_STARTUP_ONE (17U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (defined ECUM_STATE_STARTUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (RTE_CONST_ECUM_STATE_STARTUP_TWO != 18U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_TWO (18U)
#   define ECUM_STATE_STARTUP_TWO (18U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP) || (defined ECUM_STATE_WAKEUP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP) || (RTE_CONST_ECUM_STATE_WAKEUP != 32U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP (32U)
#   define ECUM_STATE_WAKEUP (32U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (defined ECUM_STATE_WAKEUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (RTE_CONST_ECUM_STATE_WAKEUP_ONE != 33U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_ONE (33U)
#   define ECUM_STATE_WAKEUP_ONE (33U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (defined ECUM_STATE_WAKEUP_VALIDATION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION != 34U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_VALIDATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION (34U)
#   define ECUM_STATE_WAKEUP_VALIDATION (34U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (defined ECUM_STATE_WAKEUP_REACTION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (RTE_CONST_ECUM_STATE_WAKEUP_REACTION != 35U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_REACTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_REACTION (35U)
#   define ECUM_STATE_WAKEUP_REACTION (35U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (defined ECUM_STATE_WAKEUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (RTE_CONST_ECUM_STATE_WAKEUP_TWO != 36U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TWO (36U)
#   define ECUM_STATE_WAKEUP_TWO (36U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (defined ECUM_STATE_WAKEUP_WAKESLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP != 37U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_WAKESLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#   define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (defined ECUM_STATE_WAKEUP_TTII)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (RTE_CONST_ECUM_STATE_WAKEUP_TTII != 38U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TTII> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TTII (38U)
#   define ECUM_STATE_WAKEUP_TTII (38U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RUN) || (defined ECUM_STATE_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_RUN) || (RTE_CONST_ECUM_STATE_RUN != 48U)
#    error "Enumeration constant <ECUM_STATE_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RUN (48U)
#   define ECUM_STATE_RUN (48U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_RUN) || (defined ECUM_STATE_APP_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_RUN) || (RTE_CONST_ECUM_STATE_APP_RUN != 50U)
#    error "Enumeration constant <ECUM_STATE_APP_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_RUN (50U)
#   define ECUM_STATE_APP_RUN (50U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (defined ECUM_STATE_APP_POST_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (RTE_CONST_ECUM_STATE_APP_POST_RUN != 51U)
#    error "Enumeration constant <ECUM_STATE_APP_POST_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_POST_RUN (51U)
#   define ECUM_STATE_APP_POST_RUN (51U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (defined ECUM_STATE_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (RTE_CONST_ECUM_STATE_SHUTDOWN != 64U)
#    error "Enumeration constant <ECUM_STATE_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SHUTDOWN (64U)
#   define ECUM_STATE_SHUTDOWN (64U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (defined ECUM_STATE_PREP_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (RTE_CONST_ECUM_STATE_PREP_SHUTDOWN != 68U)
#    error "Enumeration constant <ECUM_STATE_PREP_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_PREP_SHUTDOWN (68U)
#   define ECUM_STATE_PREP_SHUTDOWN (68U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (defined ECUM_STATE_GO_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (RTE_CONST_ECUM_STATE_GO_SLEEP != 73U)
#    error "Enumeration constant <ECUM_STATE_GO_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_SLEEP (73U)
#   define ECUM_STATE_GO_SLEEP (73U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (defined ECUM_STATE_GO_OFF_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (RTE_CONST_ECUM_STATE_GO_OFF_ONE != 77U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_ONE (77U)
#   define ECUM_STATE_GO_OFF_ONE (77U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (defined ECUM_STATE_GO_OFF_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (RTE_CONST_ECUM_STATE_GO_OFF_TWO != 78U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_TWO (78U)
#   define ECUM_STATE_GO_OFF_TWO (78U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SLEEP) || (defined ECUM_STATE_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_SLEEP) || (RTE_CONST_ECUM_STATE_SLEEP != 80U)
#    error "Enumeration constant <ECUM_STATE_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SLEEP (80U)
#   define ECUM_STATE_SLEEP (80U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_OFF) || (defined ECUM_STATE_OFF)
#   if (!defined RTE_CONST_ECUM_STATE_OFF) || (RTE_CONST_ECUM_STATE_OFF != 128U)
#    error "Enumeration constant <ECUM_STATE_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_OFF (128U)
#   define ECUM_STATE_OFF (128U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RESET) || (defined ECUM_STATE_RESET)
#   if (!defined RTE_CONST_ECUM_STATE_RESET) || (RTE_CONST_ECUM_STATE_RESET != 144U)
#    error "Enumeration constant <ECUM_STATE_RESET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RESET (144U)
#   define ECUM_STATE_RESET (144U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_ERROR) || (defined ECUM_STATE_ERROR)
#   if (!defined RTE_CONST_ECUM_STATE_ERROR) || (RTE_CONST_ECUM_STATE_ERROR != 255U)
#    error "Enumeration constant <ECUM_STATE_ERROR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_ERROR (255U)
#   define ECUM_STATE_ERROR (255U)
#  endif

#  define Rte_TypeDef_ImcArbrDataSrc_enum
typedef uint8 ImcArbrDataSrc_enum;
#  define ImcArbrDataSrc_enum_LowerLimit (0U)
#  define ImcArbrDataSrc_enum_UpperLimit (255U)
#  if (defined RTE_CONST_IMCARBRDS_SCI) || (defined IMCARBRDS_SCI)
#   if (!defined RTE_CONST_IMCARBRDS_SCI) || (RTE_CONST_IMCARBRDS_SCI != 0U)
#    error "Enumeration constant <IMCARBRDS_SCI> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_IMCARBRDS_SCI (0U)
#   define IMCARBRDS_SCI (0U)
#  endif
#  if (defined RTE_CONST_IMCARBRDS_CAN) || (defined IMCARBRDS_CAN)
#   if (!defined RTE_CONST_IMCARBRDS_CAN) || (RTE_CONST_IMCARBRDS_CAN != 1U)
#    error "Enumeration constant <IMCARBRDS_CAN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_IMCARBRDS_CAN (1U)
#   define IMCARBRDS_CAN (1U)
#  endif

#  define Rte_TypeDef_PsaEpsSt_Cnt_enum
typedef uint8 PsaEpsSt_Cnt_enum;
#  define PsaEpsSt_Cnt_enum_LowerLimit (0U)
#  define PsaEpsSt_Cnt_enum_UpperLimit (2U)
#  if (defined RTE_CONST_PSAEPSST_UNAVL) || (defined PSAEPSST_UNAVL)
#   if (!defined RTE_CONST_PSAEPSST_UNAVL) || (RTE_CONST_PSAEPSST_UNAVL != 0U)
#    error "Enumeration constant <PSAEPSST_UNAVL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PSAEPSST_UNAVL (0U)
#   define PSAEPSST_UNAVL (0U)
#  endif
#  if (defined RTE_CONST_PSAEPSST_AVL) || (defined PSAEPSST_AVL)
#   if (!defined RTE_CONST_PSAEPSST_AVL) || (RTE_CONST_PSAEPSST_AVL != 1U)
#    error "Enumeration constant <PSAEPSST_AVL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PSAEPSST_AVL (1U)
#   define PSAEPSST_AVL (1U)
#  endif
#  if (defined RTE_CONST_PSAEPSST_DFCT) || (defined PSAEPSST_DFCT)
#   if (!defined RTE_CONST_PSAEPSST_DFCT) || (RTE_CONST_PSAEPSST_DFCT != 2U)
#    error "Enumeration constant <PSAEPSST_DFCT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PSAEPSST_DFCT (2U)
#   define PSAEPSST_DFCT (2U)
#  endif

#  define Rte_TypeDef_DT_Array144_s8
typedef SInt8 DT_Array144_s8[144];

#  define Rte_TypeDef_DT_Array2_u16
typedef UInt16 DT_Array2_u16[2];

#  define Rte_TypeDef_Dem_MaxExtendedDataRecordType
typedef UInt8 Dem_MaxExtendedDataRecordType[1];

#  define Rte_TypeDef_IPMCoggingCancTrq
typedef UInt16 IPMCoggingCancTrq[512];

#  define Rte_TypeDef_DiagSettings_Str
typedef struct
{
  UInt16 Threshold;
  UInt16 PStep;
  UInt16 NStep;
} DiagSettings_Str;

#  define Rte_TypeDef_DigHwTrqSENTTrim_DataType
typedef struct
{
  Float k_EOLHwTrqTrim_HwNm_f32;
  Boolean k_EOLHwTrqTrimPerformed_Cnt_Lgc;
} DigHwTrqSENTTrim_DataType;

#  define Rte_TypeDef_MtrPos2Cal_DataType
typedef struct
{
  UInt16 Sin2Offset_Volts_u3p13;
  UInt16 Sin2AmpRec_Uls_u3p13;
  UInt16 Cos2Offset_Volts_u3p13;
  UInt16 Cos2AmpRec_Uls_u3p13;
  SInt16 SinDelta2_Uls_s2p13;
  UInt16 CosDelta2Rec_Uls_u3p13;
} MtrPos2Cal_DataType;

#  define Rte_TypeDef_MtrPos3Cal_DataType
typedef struct
{
  UInt16 BEMFCal_Rev_u0p16;
  UInt16 Sin3Offset_Volts_u3p13;
  UInt16 Sin3AmpRec_Uls_u3p13;
  UInt16 Cos3Offset_Volts_u3p13;
  UInt16 Cos3AmpRec_Uls_u3p13;
  SInt16 SinDelta3_Uls_s2p13;
  UInt16 CosDelta3Rec_Uls_u3p13;
} MtrPos3Cal_DataType;

#  define Rte_TypeDef_MtrPosCal_DataType
typedef struct
{
  UInt16 BEMFCal_Rev_u0p16;
  UInt16 R_BEMFCal_Rev_u0p16;
  UInt16 Sin1Offset_Volts_u3p13;
  UInt16 Sin1AmpRec_Uls_u3p13;
  UInt16 Cos1Offset_Volts_u3p13;
  UInt16 Cos1AmpRec_Uls_u3p13;
  SInt16 SinDelta1_Uls_s2p13;
  UInt16 CosDelta1Rec_Uls_u3p13;
  SInt16 Sin1OffCorr_Volts_s2p13;
  UInt16 Sin1GainCorr_Uls_u1p15;
  SInt16 Cos1OffCorr_Volts_s2p13;
  UInt16 Cos1GainCorr_Uls_u1p15;
  DT_Array144_s8 SinHarTbl_Cnt_sm6p13;
  DT_Array144_s8 CosHarTbl_Cnt_sm6p13;
} MtrPosCal_DataType;

# endif


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_StaMd_Mode_DISABLE (0U)
# define RTE_MODE_StaMd_Mode_OFF (1U)
# define RTE_MODE_StaMd_Mode_OPERATE (2U)
# define RTE_MODE_StaMd_Mode_WARMINIT (3U)
# define RTE_TRANSITION_StaMd_Mode (4U)


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

# if (defined RTE_CONST_D_APASTATEINIT_CNT_U08) || (defined D_APASTATEINIT_CNT_U08)
#  if (!defined RTE_CONST_D_APASTATEINIT_CNT_U08) || (RTE_CONST_D_APASTATEINIT_CNT_U08 != 0U)
#   error "Constant value <D_APASTATEINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_APASTATEINIT_CNT_U08 (0U)
#  define D_APASTATEINIT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08) || (defined D_CAAPAABORTSTNODRVGINTRPT_CNT_U08)
#  if (!defined RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08) || (RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 != 0U)
#   error "Constant value <D_CAAPAABORTSTNODRVGINTRPT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 (0U)
#  define D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08) || (defined D_CAAPAREQSTNOREQ_CNT_U08)
#  if (!defined RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08) || (RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08 != 0U)
#   error "Constant value <D_CAAPAREQSTNOREQ_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08 (0U)
#  define D_CAAPAREQSTNOREQ_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM) || (defined D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM) || (RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM != 0U)
#   error "Constant value <D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM (0U)
#  define D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_SYSPRFMNCSTNORMOPERINIT) || (defined SYSPRFMNCSTNORMOPERINIT)
#  if (!defined RTE_CONST_SYSPRFMNCSTNORMOPERINIT) || (RTE_CONST_SYSPRFMNCSTNORMOPERINIT != 0U)
#   error "Constant value <SYSPRFMNCSTNORMOPERINIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCSTNORMOPERINIT (0U)
#  define SYSPRFMNCSTNORMOPERINIT (0U)
# endif

# if (defined RTE_CONST_D_BMWDRVGDYNIFSTINIT_CNT_ENUM) || (defined D_BMWDRVGDYNIFSTINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_BMWDRVGDYNIFSTINIT_CNT_ENUM) || (RTE_CONST_D_BMWDRVGDYNIFSTINIT_CNT_ENUM != 128U)
#   error "Constant value <D_BMWDRVGDYNIFSTINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BMWDRVGDYNIFSTINIT_CNT_ENUM (128U)
#  define D_BMWDRVGDYNIFSTINIT_CNT_ENUM (128U)
# endif

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC (FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC (TRUE)
# endif

# if (defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (defined D_SFINVMILLI_ULS_F32)
#  if (!defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (RTE_CONST_D_SFINVMILLI_ULS_F32 != 1000)
#   error "Constant value <D_SFINVMILLI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SFINVMILLI_ULS_F32 (1000)
#  define D_SFINVMILLI_ULS_F32 (1000)
# endif

# if (defined RTE_CONST_D_DMCINIT_CNT_ENUM) || (defined D_DMCINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_DMCINIT_CNT_ENUM) || (RTE_CONST_D_DMCINIT_CNT_ENUM != 1U)
#   error "Constant value <D_DMCINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_DMCINIT_CNT_ENUM (1U)
#  define D_DMCINIT_CNT_ENUM (1U)
# endif

# if (defined RTE_CONST_D_ESCSTATEINIT_CNT_U08) || (defined D_ESCSTATEINIT_CNT_U08)
#  if (!defined RTE_CONST_D_ESCSTATEINIT_CNT_U08) || (RTE_CONST_D_ESCSTATEINIT_CNT_U08 != 0U)
#   error "Constant value <D_ESCSTATEINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ESCSTATEINIT_CNT_U08 (0U)
#  define D_ESCSTATEINIT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_100MS_SEC_F32) || (defined D_100MS_SEC_F32)
#  if (!defined RTE_CONST_D_100MS_SEC_F32) || (RTE_CONST_D_100MS_SEC_F32 != 0.1F)
#   error "Constant value <D_100MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_100MS_SEC_F32 (0.1F)
#  define D_100MS_SEC_F32 (0.1F)
# endif

# if (defined RTE_CONST_D_180OVRPI_ULS_F32) || (defined D_180OVRPI_ULS_F32)
#  if (!defined RTE_CONST_D_180OVRPI_ULS_F32) || (RTE_CONST_D_180OVRPI_ULS_F32 != 57.295779513082F)
#   error "Constant value <D_180OVRPI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_180OVRPI_ULS_F32 (57.295779513082F)
#  define D_180OVRPI_ULS_F32 (57.295779513082F)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002F)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002F)
#  define D_2MS_SEC_F32 (0.002F)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796F)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796F)
#  define D_2PI_ULS_F32 (6.2831853071796F)
# endif

# if (defined RTE_CONST_D_CCWEOTINIT_HWDEG_F32) || (defined D_CCWEOTINIT_HWDEG_F32)
#  if (!defined RTE_CONST_D_CCWEOTINIT_HWDEG_F32) || (RTE_CONST_D_CCWEOTINIT_HWDEG_F32 != -360.0F)
#   error "Constant value <D_CCWEOTINIT_HWDEG_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CCWEOTINIT_HWDEG_F32 (-360.0F)
#  define D_CCWEOTINIT_HWDEG_F32 (-360.0F)
# endif

# if (defined RTE_CONST_D_CWEOTINIT_HWDEG_F32) || (defined D_CWEOTINIT_HWDEG_F32)
#  if (!defined RTE_CONST_D_CWEOTINIT_HWDEG_F32) || (RTE_CONST_D_CWEOTINIT_HWDEG_F32 != 360.0F)
#   error "Constant value <D_CWEOTINIT_HWDEG_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CWEOTINIT_HWDEG_F32 (360.0F)
#  define D_CWEOTINIT_HWDEG_F32 (360.0F)
# endif

# if (defined RTE_CONST_D_ESTKE_VPRADPS_F32) || (defined D_ESTKE_VPRADPS_F32)
#  if (!defined RTE_CONST_D_ESTKE_VPRADPS_F32) || (RTE_CONST_D_ESTKE_VPRADPS_F32 != 0.025F)
#   error "Constant value <D_ESTKE_VPRADPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ESTKE_VPRADPS_F32 (0.025F)
#  define D_ESTKE_VPRADPS_F32 (0.025F)
# endif

# if (defined RTE_CONST_D_HALF_ULS_F32) || (defined D_HALF_ULS_F32)
#  if (!defined RTE_CONST_D_HALF_ULS_F32) || (RTE_CONST_D_HALF_ULS_F32 != 0.5F)
#   error "Constant value <D_HALF_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_HALF_ULS_F32 (0.5F)
#  define D_HALF_ULS_F32 (0.5F)
# endif

# if (defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (defined D_MSECPERSEC_ULS_F32)
#  if (!defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (RTE_CONST_D_MSECPERSEC_ULS_F32 != 1000.0F)
#   error "Constant value <D_MSECPERSEC_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MSECPERSEC_ULS_F32 (1000.0F)
#  define D_MSECPERSEC_ULS_F32 (1000.0F)
# endif

# if (defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (defined D_MTRRAMPRATEFALL_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 != -4400.0F)
#   error "Constant value <D_MTRRAMPRATEFALL_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 (-4400.0F)
#  define D_MTRRAMPRATEFALL_MTRNMPS_F32 (-4400.0F)
# endif

# if (defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (defined D_MTRRAMPRATERISE_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 != 4400.0F)
#   error "Constant value <D_MTRRAMPRATERISE_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 (4400.0F)
#  define D_MTRRAMPRATERISE_MTRNMPS_F32 (4400.0F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8F)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (defined D_MTRTRQCMDLOLMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 != -8.8F)
#   error "Constant value <D_MTRTRQCMDLOLMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
#  define D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1.0F)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1.0F)
#  define D_ONE_ULS_F32 (1.0F)
# endif

# if (defined RTE_CONST_D_PIOVR180_ULS_F32) || (defined D_PIOVR180_ULS_F32)
#  if (!defined RTE_CONST_D_PIOVR180_ULS_F32) || (RTE_CONST_D_PIOVR180_ULS_F32 != 0.0174532925199F)
#   error "Constant value <D_PIOVR180_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PIOVR180_ULS_F32 (0.0174532925199F)
#  define D_PIOVR180_ULS_F32 (0.0174532925199F)
# endif

# if (defined RTE_CONST_D_PI_ULS_F32) || (defined D_PI_ULS_F32)
#  if (!defined RTE_CONST_D_PI_ULS_F32) || (RTE_CONST_D_PI_ULS_F32 != 3.1415926535898F)
#   error "Constant value <D_PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PI_ULS_F32 (3.1415926535898F)
#  define D_PI_ULS_F32 (3.1415926535898F)
# endif

# if (defined RTE_CONST_D_RADPERREV_ULS_F32) || (defined D_RADPERREV_ULS_F32)
#  if (!defined RTE_CONST_D_RADPERREV_ULS_F32) || (RTE_CONST_D_RADPERREV_ULS_F32 != 6.28318530718F)
#   error "Constant value <D_RADPERREV_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RADPERREV_ULS_F32 (6.28318530718F)
#  define D_RADPERREV_ULS_F32 (6.28318530718F)
# endif

# if (defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (defined D_SUPPLYCURRINIT_AMP_F32)
#  if (!defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 != 166.67F)
#   error "Constant value <D_SUPPLYCURRINIT_AMP_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 (166.67F)
#  define D_SUPPLYCURRINIT_AMP_F32 (166.67F)
# endif

# if (defined RTE_CONST_D_TRQOSCFREQINIT_F32) || (defined D_TRQOSCFREQINIT_F32)
#  if (!defined RTE_CONST_D_TRQOSCFREQINIT_F32) || (RTE_CONST_D_TRQOSCFREQINIT_F32 != 50.0F)
#   error "Constant value <D_TRQOSCFREQINIT_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOSCFREQINIT_F32 (50.0F)
#  define D_TRQOSCFREQINIT_F32 (50.0F)
# endif

# if (defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (defined D_TRQOSCFREQINIT_HZ_F32)
#  if (!defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 != 50.0F)
#   error "Constant value <D_TRQOSCFREQINIT_HZ_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 (50.0F)
#  define D_TRQOSCFREQINIT_HZ_F32 (50.0F)
# endif

# if (defined RTE_CONST_D_TRQOVLFREQINIT_HZ_F32) || (defined D_TRQOVLFREQINIT_HZ_F32)
#  if (!defined RTE_CONST_D_TRQOVLFREQINIT_HZ_F32) || (RTE_CONST_D_TRQOVLFREQINIT_HZ_F32 != 3.0F)
#   error "Constant value <D_TRQOVLFREQINIT_HZ_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOVLFREQINIT_HZ_F32 (3.0F)
#  define D_TRQOVLFREQINIT_HZ_F32 (3.0F)
# endif

# if (defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (defined D_VECUMIN_VOLTS_F32)
#  if (!defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (RTE_CONST_D_VECUMIN_VOLTS_F32 != 5.0F)
#   error "Constant value <D_VECUMIN_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VECUMIN_VOLTS_F32 (5.0F)
#  define D_VECUMIN_VOLTS_F32 (5.0F)
# endif

# if (defined RTE_CONST_D_VEHWHLBASEINIT_MM_F32) || (defined D_VEHWHLBASEINIT_MM_F32)
#  if (!defined RTE_CONST_D_VEHWHLBASEINIT_MM_F32) || (RTE_CONST_D_VEHWHLBASEINIT_MM_F32 != 3000.0F)
#   error "Constant value <D_VEHWHLBASEINIT_MM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VEHWHLBASEINIT_MM_F32 (3000.0F)
#  define D_VEHWHLBASEINIT_MM_F32 (3000.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_GMSTRTSTOPSTINIT_CNT_U08) || (defined D_GMSTRTSTOPSTINIT_CNT_U08)
#  if (!defined RTE_CONST_D_GMSTRTSTOPSTINIT_CNT_U08) || (RTE_CONST_D_GMSTRTSTOPSTINIT_CNT_U08 != 1U)
#   error "Constant value <D_GMSTRTSTOPSTINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_GMSTRTSTOPSTINIT_CNT_U08 (1U)
#  define D_GMSTRTSTOPSTINIT_CNT_U08 (1U)
# endif

# if (defined RTE_CONST_D_HAPTICSTATEINIT_CNT_U08) || (defined D_HAPTICSTATEINIT_CNT_U08)
#  if (!defined RTE_CONST_D_HAPTICSTATEINIT_CNT_U08) || (RTE_CONST_D_HAPTICSTATEINIT_CNT_U08 != 1U)
#   error "Constant value <D_HAPTICSTATEINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_HAPTICSTATEINIT_CNT_U08 (1U)
#  define D_HAPTICSTATEINIT_CNT_U08 (1U)
# endif

# if (defined RTE_CONST_D_IMCARBRRXSTS_NODATA) || (defined D_IMCARBRRXSTS_NODATA)
#  if (!defined RTE_CONST_D_IMCARBRRXSTS_NODATA) || (RTE_CONST_D_IMCARBRRXSTS_NODATA != 0U)
#   error "Constant value <D_IMCARBRRXSTS_NODATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_IMCARBRRXSTS_NODATA (0U)
#  define D_IMCARBRRXSTS_NODATA (0U)
# endif

# if (defined RTE_CONST_D_IMCSIGSTSINIT_ENUM) || (defined D_IMCSIGSTSINIT_ENUM)
#  if (!defined RTE_CONST_D_IMCSIGSTSINIT_ENUM) || (RTE_CONST_D_IMCSIGSTSINIT_ENUM != 0U)
#   error "Constant value <D_IMCSIGSTSINIT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_IMCSIGSTSINIT_ENUM (0U)
#  define D_IMCSIGSTSINIT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_LKASTATEINIT_CNT_U08) || (defined D_LKASTATEINIT_CNT_U08)
#  if (!defined RTE_CONST_D_LKASTATEINIT_CNT_U08) || (RTE_CONST_D_LKASTATEINIT_CNT_U08 != 0U)
#   error "Constant value <D_LKASTATEINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_LKASTATEINIT_CNT_U08 (0U)
#  define D_LKASTATEINIT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_LOASTATEINIT_CNT_ENUM) || (defined D_LOASTATEINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_LOASTATEINIT_CNT_ENUM) || (RTE_CONST_D_LOASTATEINIT_CNT_ENUM != 0U)
#   error "Constant value <D_LOASTATEINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_LOASTATEINIT_CNT_ENUM (0U)
#  define D_LOASTATEINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08) || (defined D_CALDWSTHAPTCRDY_CNT_U08)
#  if (!defined RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08) || (RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08 != 0U)
#   error "Constant value <D_CALDWSTHAPTCRDY_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08 (0U)
#  define D_CALDWSTHAPTCRDY_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_CALKASTINACTV_CNT_U08) || (defined D_CALKASTINACTV_CNT_U08)
#  if (!defined RTE_CONST_D_CALKASTINACTV_CNT_U08) || (RTE_CONST_D_CALKASTINACTV_CNT_U08 != 1U)
#   error "Constant value <D_CALKASTINACTV_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CALKASTINACTV_CNT_U08 (1U)
#  define D_CALKASTINACTV_CNT_U08 (1U)
# endif

# if (defined RTE_CONST_D_MANUFMODEINIT_CNT_ENUM) || (defined D_MANUFMODEINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_MANUFMODEINIT_CNT_ENUM) || (RTE_CONST_D_MANUFMODEINIT_CNT_ENUM != 0U)
#   error "Constant value <D_MANUFMODEINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MANUFMODEINIT_CNT_ENUM (0U)
#  define D_MANUFMODEINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSAAGARBNSTINIT_CNT_ENUM) || (defined D_PSAAGARBNSTINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSAAGARBNSTINIT_CNT_ENUM) || (RTE_CONST_D_PSAAGARBNSTINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSAAGARBNSTINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSAAGARBNSTINIT_CNT_ENUM (0U)
#  define D_PSAAGARBNSTINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSAAPASTINIT_CNT_ENUM) || (defined D_PSAAPASTINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSAAPASTINIT_CNT_ENUM) || (RTE_CONST_D_PSAAPASTINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSAAPASTINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSAAPASTINIT_CNT_ENUM (0U)
#  define D_PSAAPASTINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSAAPATRANCAUSEINIT_CNT_ENUM) || (defined D_PSAAPATRANCAUSEINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSAAPATRANCAUSEINIT_CNT_ENUM) || (RTE_CONST_D_PSAAPATRANCAUSEINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSAAPATRANCAUSEINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSAAPATRANCAUSEINIT_CNT_ENUM (0U)
#  define D_PSAAPATRANCAUSEINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSAEPSSTLXAINIT_CNT_ENUM) || (defined D_PSAEPSSTLXAINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSAEPSSTLXAINIT_CNT_ENUM) || (RTE_CONST_D_PSAEPSSTLXAINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSAEPSSTLXAINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSAEPSSTLXAINIT_CNT_ENUM (0U)
#  define D_PSAEPSSTLXAINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSALXASTINIT_CNT_ENUM) || (defined D_PSALXASTINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSALXASTINIT_CNT_ENUM) || (RTE_CONST_D_PSALXASTINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSALXASTINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSALXASTINIT_CNT_ENUM (0U)
#  define D_PSALXASTINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_PSATUNMODSTINIT_CNT_ENUM) || (defined D_PSATUNMODSTINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_PSATUNMODSTINIT_CNT_ENUM) || (RTE_CONST_D_PSATUNMODSTINIT_CNT_ENUM != 0U)
#   error "Constant value <D_PSATUNMODSTINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PSATUNMODSTINIT_CNT_ENUM (0U)
#  define D_PSATUNMODSTINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S16) || (defined D_NEGONE_CNT_S16)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S16) || (RTE_CONST_D_NEGONE_CNT_S16 != -1)
#   error "Constant value <D_NEGONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S16 (-1)
#  define D_NEGONE_CNT_S16 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S16) || (defined D_ONE_CNT_S16)
#  if (!defined RTE_CONST_D_ONE_CNT_S16) || (RTE_CONST_D_ONE_CNT_S16 != 1)
#   error "Constant value <D_ONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S16 (1)
#  define D_ONE_CNT_S16 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S32) || (defined D_NEGONE_CNT_S32)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S32) || (RTE_CONST_D_NEGONE_CNT_S32 != -1)
#   error "Constant value <D_NEGONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S32 (-1)
#  define D_NEGONE_CNT_S32 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S32) || (defined D_ONE_CNT_S32)
#  if (!defined RTE_CONST_D_ONE_CNT_S32) || (RTE_CONST_D_ONE_CNT_S32 != 1)
#   error "Constant value <D_ONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S32 (1)
#  define D_ONE_CNT_S32 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S8) || (defined D_NEGONE_CNT_S8)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S8) || (RTE_CONST_D_NEGONE_CNT_S8 != -1)
#   error "Constant value <D_NEGONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S8 (-1)
#  define D_NEGONE_CNT_S8 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S8) || (defined D_ONE_CNT_S8)
#  if (!defined RTE_CONST_D_ONE_CNT_S8) || (RTE_CONST_D_ONE_CNT_S8 != 1)
#   error "Constant value <D_ONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S8 (1)
#  define D_ONE_CNT_S8 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S8) || (defined D_ZERO_CNT_S8)
#  if (!defined RTE_CONST_D_ZERO_CNT_S8) || (RTE_CONST_D_ZERO_CNT_S8 != 0)
#   error "Constant value <D_ZERO_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S8 (0)
#  define D_ZERO_CNT_S8 (0)
# endif

# if (defined RTE_CONST_D_SSSTATEINIT_CNT_U08) || (defined D_SSSTATEINIT_CNT_U08)
#  if (!defined RTE_CONST_D_SSSTATEINIT_CNT_U08) || (RTE_CONST_D_SSSTATEINIT_CNT_U08 != 0U)
#   error "Constant value <D_SSSTATEINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SSSTATEINIT_CNT_U08 (0U)
#  define D_SSSTATEINIT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_SIGQLFRNORES_CNT_ENUM) || (defined D_SIGQLFRNORES_CNT_ENUM)
#  if (!defined RTE_CONST_D_SIGQLFRNORES_CNT_ENUM) || (RTE_CONST_D_SIGQLFRNORES_CNT_ENUM != 0U)
#   error "Constant value <D_SIGQLFRNORES_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SIGQLFRNORES_CNT_ENUM (0U)
#  define D_SIGQLFRNORES_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_STEERMODINIT_CNT_ENUM) || (defined D_STEERMODINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_STEERMODINIT_CNT_ENUM) || (RTE_CONST_D_STEERMODINIT_CNT_ENUM != 0U)
#   error "Constant value <D_STEERMODINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_STEERMODINIT_CNT_ENUM (0U)
#  define D_STEERMODINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_SYSPRFMNCSTNORMINIT) || (defined SYSPRFMNCSTNORMINIT)
#  if (!defined RTE_CONST_SYSPRFMNCSTNORMINIT) || (RTE_CONST_SYSPRFMNCSTNORMINIT != 0U)
#   error "Constant value <SYSPRFMNCSTNORMINIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCSTNORMINIT (0U)
#  define SYSPRFMNCSTNORMINIT (0U)
# endif

# if (defined RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM) || (defined D_TUNSESSIONADRPTRINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM) || (RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM != 255U)
#   error "Constant value <D_TUNSESSIONADRPTRINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM (255U)
#  define D_TUNSESSIONADRPTRINIT_CNT_ENUM (255U)
# endif

# if (defined RTE_CONST_D_CMPVEHLATAINIT_CNT_U16) || (defined D_CMPVEHLATAINIT_CNT_U16)
#  if (!defined RTE_CONST_D_CMPVEHLATAINIT_CNT_U16) || (RTE_CONST_D_CMPVEHLATAINIT_CNT_U16 != 1022U)
#   error "Constant value <D_CMPVEHLATAINIT_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CMPVEHLATAINIT_CNT_U16 (1022U)
#  define D_CMPVEHLATAINIT_CNT_U16 (1022U)
# endif

# if (defined RTE_CONST_D_FIFTEEN_CNT_U16) || (defined D_FIFTEEN_CNT_U16)
#  if (!defined RTE_CONST_D_FIFTEEN_CNT_U16) || (RTE_CONST_D_FIFTEEN_CNT_U16 != 15U)
#   error "Constant value <D_FIFTEEN_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FIFTEEN_CNT_U16 (15U)
#  define D_FIFTEEN_CNT_U16 (15U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1U)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1U)
#  define D_ONE_CNT_U16 (1U)
# endif

# if (defined RTE_CONST_D_SEVEN_CNT_U16) || (defined D_SEVEN_CNT_U16)
#  if (!defined RTE_CONST_D_SEVEN_CNT_U16) || (RTE_CONST_D_SEVEN_CNT_U16 != 7U)
#   error "Constant value <D_SEVEN_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SEVEN_CNT_U16 (7U)
#  define D_SEVEN_CNT_U16 (7U)
# endif

# if (defined RTE_CONST_D_THREE_CNT_U16) || (defined D_THREE_CNT_U16)
#  if (!defined RTE_CONST_D_THREE_CNT_U16) || (RTE_CONST_D_THREE_CNT_U16 != 3U)
#   error "Constant value <D_THREE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_THREE_CNT_U16 (3U)
#  define D_THREE_CNT_U16 (3U)
# endif

# if (defined RTE_CONST_D_TWOPTFIVE_VOLT_U3P13) || (defined D_TWOPTFIVE_VOLT_U3P13)
#  if (!defined RTE_CONST_D_TWOPTFIVE_VOLT_U3P13) || (RTE_CONST_D_TWOPTFIVE_VOLT_U3P13 != 20480U)
#   error "Constant value <D_TWOPTFIVE_VOLT_U3P13> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TWOPTFIVE_VOLT_U3P13 (20480U)
#  define D_TWOPTFIVE_VOLT_U3P13 (20480U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0U)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0U)
#  define D_ZERO_CNT_U16 (0U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U32) || (defined D_ONE_CNT_U32)
#  if (!defined RTE_CONST_D_ONE_CNT_U32) || (RTE_CONST_D_ONE_CNT_U32 != 1U)
#   error "Constant value <D_ONE_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U32 (1U)
#  define D_ONE_CNT_U32 (1U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
# endif

# if (defined RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08) || (defined D_BATTVLTGCORRLNSTSINIT_CNT_U08)
#  if (!defined RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08) || (RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08 != 7U)
#   error "Constant value <D_BATTVLTGCORRLNSTSINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08 (7U)
#  define D_BATTVLTGCORRLNSTSINIT_CNT_U08 (7U)
# endif

# if (defined RTE_CONST_D_FOUR_CNT_U08) || (defined D_FOUR_CNT_U08)
#  if (!defined RTE_CONST_D_FOUR_CNT_U08) || (RTE_CONST_D_FOUR_CNT_U08 != 4U)
#   error "Constant value <D_FOUR_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FOUR_CNT_U08 (4U)
#  define D_FOUR_CNT_U08 (4U)
# endif

# if (defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (defined D_MTRPOLESDIV2_CNT_U8)
#  if (!defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (RTE_CONST_D_MTRPOLESDIV2_CNT_U8 != 3U)
#   error "Constant value <D_MTRPOLESDIV2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRPOLESDIV2_CNT_U8 (3U)
#  define D_MTRPOLESDIV2_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1U)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1U)
#  define D_ONE_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT1_CNT_U8) || (defined D_QUADRANT1_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT1_CNT_U8) || (RTE_CONST_D_QUADRANT1_CNT_U8 != 1U)
#   error "Constant value <D_QUADRANT1_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT1_CNT_U8 (1U)
#  define D_QUADRANT1_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT2_CNT_U8) || (defined D_QUADRANT2_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT2_CNT_U8) || (RTE_CONST_D_QUADRANT2_CNT_U8 != 2U)
#   error "Constant value <D_QUADRANT2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT2_CNT_U8 (2U)
#  define D_QUADRANT2_CNT_U8 (2U)
# endif

# if (defined RTE_CONST_D_QUADRANT3_CNT_U8) || (defined D_QUADRANT3_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT3_CNT_U8) || (RTE_CONST_D_QUADRANT3_CNT_U8 != 3U)
#   error "Constant value <D_QUADRANT3_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT3_CNT_U8 (3U)
#  define D_QUADRANT3_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_QUADRANT4_CNT_U8) || (defined D_QUADRANT4_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT4_CNT_U8) || (RTE_CONST_D_QUADRANT4_CNT_U8 != 4U)
#   error "Constant value <D_QUADRANT4_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT4_CNT_U8 (4U)
#  define D_QUADRANT4_CNT_U8 (4U)
# endif

# if (defined RTE_CONST_D_SEVEN_CNT_U08) || (defined D_SEVEN_CNT_U08)
#  if (!defined RTE_CONST_D_SEVEN_CNT_U08) || (RTE_CONST_D_SEVEN_CNT_U08 != 7U)
#   error "Constant value <D_SEVEN_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SEVEN_CNT_U08 (7U)
#  define D_SEVEN_CNT_U08 (7U)
# endif

# if (defined RTE_CONST_D_THREE_CNT_U08) || (defined D_THREE_CNT_U08)
#  if (!defined RTE_CONST_D_THREE_CNT_U08) || (RTE_CONST_D_THREE_CNT_U08 != 3U)
#   error "Constant value <D_THREE_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_THREE_CNT_U08 (3U)
#  define D_THREE_CNT_U08 (3U)
# endif

# if (defined RTE_CONST_D_TWO_CNT_U08) || (defined D_TWO_CNT_U08)
#  if (!defined RTE_CONST_D_TWO_CNT_U08) || (RTE_CONST_D_TWO_CNT_U08 != 2U)
#   error "Constant value <D_TWO_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TWO_CNT_U08 (2U)
#  define D_TWO_CNT_U08 (2U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0U)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0U)
#  define D_ZERO_CNT_U8 (0U)
# endif

# if defined T_CANMSGINIT_CNT_U08
#  error "Constant value <T_CANMSGINIT_CNT_U08> conflicts with an already defined symbol."
# else
#  define T_CANMSGINIT_CNT_U08 (Rte_T_CANMSGINIT_CNT_U08)
# endif
extern CONST(CanMsgType, RTE_CONST) Rte_T_CANMSGINIT_CNT_U08;

# if defined T_SINELKPTBL_ULS_F32
#  error "Constant value <T_SINELKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_SINELKPTBL_ULS_F32 (Rte_T_SINELKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32;

# if defined T_TANLKPTBL_ULS_F32
#  error "Constant value <T_TANLKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_TANLKPTBL_ULS_F32 (Rte_T_TANLKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_TANLKPTBL_ULS_F32;

# if defined T_HWPOSNCOMPINIT_HWDEG_STR
#  error "Constant value <T_HWPOSNCOMPINIT_HWDEG_STR> conflicts with an already defined symbol."
# else
#  define T_HWPOSNCOMPINIT_HWDEG_STR (Rte_T_HWPOSNCOMPINIT_HWDEG_STR)
# endif
extern CONST(SysOutpCpbySig_Str, RTE_CONST) Rte_T_HWPOSNCOMPINIT_HWDEG_STR;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  ManufModeType value;
} Rte_DE_ManufModeType;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  UInt32 value;
} Rte_DE_UInt32;

typedef struct
{
  TuningSessionAddrPtrEnum value;
} Rte_DE_TuningSessionAddrPtrEnum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SInt8 value;
} Rte_DE_SInt8;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  EnergyModeStateType value;
} Rte_DE_EnergyModeStateType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SInt16 value;
} Rte_DE_SInt16;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SigQlfr_State_enum value;
} Rte_DE_SigQlfr_State_enum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SteerMod_enum value;
} Rte_DE_SteerMod_enum;

typedef struct
{
  LOA_State_enum value;
} Rte_DE_LOA_State_enum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  FETPHASETYPE_ENUM value;
} Rte_DE_FETPHASETYPE_ENUM;

typedef struct
{
  FETFAULTTYPE_ENUM value;
} Rte_DE_FETFAULTTYPE_ENUM;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  PsaTunModSt_Cnt_enum value;
} Rte_DE_PsaTunModSt_Cnt_enum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  PsaLxaSt_Cnt_enum value;
} Rte_DE_PsaLxaSt_Cnt_enum;

typedef struct
{
  PsaApaTranCause_Cnt_enum value;
} Rte_DE_PsaApaTranCause_Cnt_enum;

typedef struct
{
  PsaApaSt_Cnt_enum value;
} Rte_DE_PsaApaSt_Cnt_enum;

typedef struct
{
  PsaEpsStLxa_Cnt_enum value;
} Rte_DE_PsaEpsStLxa_Cnt_enum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  PsaAgArbnSt_Enum value;
} Rte_DE_PsaAgArbnSt_Enum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_HwTqCorrln_HwTqCorrlnCh1CMCLPFSvData;
extern VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_VVHTYPEData;
extern VAR(Boolean, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ElecIntData;
extern VAR(CoggingCancTrq, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqCanc_CogTrqCal;
extern VAR(CoggingCancTrqRplComp, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqCanc_CogTrqRplComp;
extern VAR(EOLHwPosTrimType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_AbsHwPos_EOLVehCntrOffset;
extern VAR(Polarity_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str;
extern VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_CurrParamComp_EOLNomMtrParam;
extern VAR(DigMSBEOLType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_DigMSB_DigMSBEOLData;
extern VAR(EOLChOffsetTrim_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnEOLCh1OffsetTrimData;
extern VAR(PsaAgAnLrndOffs_Str, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_PsaAgArbn_PsaAgArbnLrndOffsData;
extern VAR(ShutdownTimeType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ShutdownTimeData;
extern VAR(IS_DAT_DIRA_Msg, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComOutput_PimIsDatDiraMsg;
extern VAR(IS_DYN_DAE_Msg, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComOutput_PimIsDynDaeMsg;
extern VAR(IS_DYN_VOL_MsgAdd, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComOutput_PimIsDynVolAddMsg;
extern VAR(IS_DYN_VOL_MsgBase, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComOutput_PimIsDynVolBaseMsg;
extern VAR(IS_SUPV_DIRA_Msg, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComOutput_PimIsSupvDiraMsg;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_11_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(CurrTempOffsetType, RTE_VAR_DEFAULT_RTE_Ap_11_PIM_GROUP) Rte_CmMtrCurr_CurrTempOffset;
extern VAR(PhaseCurrCal_DataType, RTE_VAR_DEFAULT_RTE_Ap_11_PIM_GROUP) Rte_CmMtrCurr_ShCurrCal;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_11_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(FaultLogType, RTE_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP) Rte_FaultLog_FaultLog;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_6_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ActivePull_PullCmpLTComp_HwNm_f32;
extern VAR(AvgFricLrnType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_AvgFricLrn_AvgFricLrnData;
extern VAR(OvervoltageDataType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_BatteryVoltage_OvervoltageData;
extern VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_LrnEOT_LearnedEOT;
extern VAR(ThrmlDutyCycle_FltStVal_Datatype, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ThrmlDutyCycle_ThrmlDutyCycle_FltStVal;
extern VAR(VehDyn_DataType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_VehDyn_MotPosReset;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"


# endif


/**********************************************************************************************************************
 * Buffer definitions for implicit access to S/R port elements
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

typedef struct
{
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
} Rte_tsRB_Sa_DigMSB_DigMSB_Per3;

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Per2;

typedef struct
{
  Rte_DE_Float Rte_FiltEstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_PeakCurrEst_PeakCurrEst_Per2;

typedef struct
{
  Rte_DE_Float Rte_HwTqVal_HwNm_f32;
} Rte_tsRB_Sa_HwTqCorrln_HwTqCorrln_Per3;

typedef struct
{
  Rte_DE_UInt8 Rte_MEC_Counter_Cnt_u08;
  Rte_DE_Boolean Rte_SVC_ClearCodes_Cnt_lgc;
} Rte_tsRB_Sa_HwTqArbn_HwTqArbn_Per3;

typedef union
{
  Rte_tsRB_Sa_DigMSB_DigMSB_Per3 Rte_Sa_DigMSB_DigMSB_Per3;
  Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Per2 Rte_Ap_CurrParamComp_CurrParamComp_Per2;
  Rte_tsRB_Ap_PeakCurrEst_PeakCurrEst_Per2 Rte_Ap_PeakCurrEst_PeakCurrEst_Per2;
  Rte_tsRB_Sa_HwTqCorrln_HwTqCorrln_Per3 Rte_Sa_HwTqCorrln_HwTqCorrln_Per3;
  Rte_tsRB_Sa_HwTqArbn_HwTqArbn_Per3 Rte_Sa_HwTqArbn_HwTqArbn_Per3;
} Rte_tuRB_Task_100ms_10;

typedef struct
{
  Rte_tuRB_Task_100ms_10 Rte_RB;
} Rte_tsTask_100ms_10;

typedef struct
{
  Rte_DE_Float Rte_MtrCurr1TempOffset_Volt_f32;
  Rte_DE_Float Rte_MtrCurr2TempOffset_Volt_f32;
} Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per1;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per2;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EngTemp_DegC_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Boolean Rte_ScomAMDefeat_Cnt_lgc;
  Rte_DE_Boolean Rte_ScomTempDataRcvd_Cnt_lgc;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1;

typedef union
{
  Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per1 Rte_Sa_CmMtrCurr_CmMtrCurr_Per1;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per2 Rte_Sa_CtrlTemp_CtrlTemp_Per2;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1 Rte_Ap_MtrTempEst_MtrTempEst_Per1;
} Rte_tuRB_Task_100ms_11;

typedef struct
{
  Rte_DE_Float Rte_I_CtrlTemp_FiltMeasTemp_DegC_f32;
} Rte_tsTB_Task_100ms_11;

typedef struct
{
  Rte_tsTB_Task_100ms_11 Rte_TB;
  Rte_tuRB_Task_100ms_11 Rte_RB;
} Rte_tsTask_100ms_11;

typedef struct
{
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrSt_HwNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per3;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_UInt8 Rte_DmdDelestDa_Cnt_u08;
  Rte_DE_Boolean Rte_EngOn_Cnt_lgc;
  Rte_DE_UInt8 Rte_EtatMT_Cnt_u08;
  Rte_DE_Boolean Rte_SttdSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_ValidEngineStatus_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
} Rte_tsRB_Ap_CustBattDiag_CustBattDiag_Per2;

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Boolean Rte_DefeatDutySvc_Cnt_lgc;
  Rte_DE_Float Rte_FiltMeasTemp_DegC_f32;
  Rte_DE_Float Rte_FilteredPkCurr_AmpSq_f32;
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrPkCurr_AmpSq_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
  Rte_DE_Float Rte_DutyCycleLevel_Uls_f32;
  Rte_DE_Float Rte_ThermLimitPerc_Uls_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
} Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1;

typedef union
{
  Rte_tsRB_Ap_ActivePull_ActivePull_Per3 Rte_Ap_ActivePull_ActivePull_Per3;
  Rte_tsRB_Ap_CustBattDiag_CustBattDiag_Per2 Rte_Ap_CustBattDiag_CustBattDiag_Per2;
  Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1 Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1;
} Rte_tuRB_Task_100ms_9;

typedef struct
{
  Rte_tuRB_Task_100ms_9 Rte_RB;
} Rte_tsTask_100ms_9;

typedef struct
{
  Rte_DE_Float Rte_CntDisMtrTrqCmdMRF_MtrNm_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_FltTrqLmt_Uls_f32;
  Rte_DE_Boolean Rte_ThresholdExceeded_Cnt_lgc;
} Rte_tsRB_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2;

typedef struct
{
  Rte_DE_PsaApaSt_Cnt_enum Rte_APAState_Cnt_enum;
  Rte_DE_PsaApaTranCause_Cnt_enum Rte_APAStateTransitionCause_Cnt_enum;
  Rte_DE_Boolean Rte_AVASelected_Cnt_lgc;
  Rte_DE_Float Rte_AbsltHwPosn_HwDeg_f32;
  Rte_DE_Boolean Rte_AbsltHwPosnLvl1_Cnt_lgc;
  Rte_DE_Boolean Rte_AbsltHwPosnLvl2_Cnt_lgc;
  Rte_DE_Boolean Rte_AbsltHwPosnVld_Cnt_lgc;
  Rte_DE_PsaAgArbnSt_Enum Rte_AgArbnStToSerlCom_Cnt_enum;
  Rte_DE_Boolean Rte_CAVHCSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_CTCFailed_Cnt_lgc;
  Rte_DE_Boolean Rte_CityParkSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_DefaultHwaSCommExportValue_Cnt_lgc;
  Rte_DE_Boolean Rte_DmdDelestDaVld_Cnt_lgc;
  Rte_DE_Boolean Rte_DrvrIntvDetd_Cnt_lgc;
  Rte_DE_PsaEpsStLxa_Cnt_enum Rte_EPSStateForLxa_Cnt_enum;
  Rte_DE_Boolean Rte_ESCOffsCfgSeld_Cnt_lgc;
  Rte_DE_PsaTunModSt_Cnt_enum Rte_ETATDADYN_Cnt_enum;
  Rte_DE_UInt8 Rte_EtatMT_Cnt_u08;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelTorque_HwNm_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Boolean Rte_LXASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaTqLimnActv_Cnt_lgc;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Boolean Rte_RampDwnStatusComplete_Cnt_lgc;
  Rte_DE_Float Rte_RelHwPosnToSerlCom_HwDeg_f32;
  Rte_DE_Boolean Rte_RelHwPosnVldToSerlCom_Cnt_lgc;
  Rte_DE_Boolean Rte_STTdSelected_Cnt_lgc;
  Rte_DE_Float Rte_SrlComHwTrq_HwNm_f32;
  Rte_DE_Boolean Rte_ValidEngineStatus_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
} Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1;

typedef union
{
  Rte_tsRB_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2;
  Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1 Rte_Ap_SrlComOutput_SrlComOutput_Per1;
} Rte_tuRB_Task_10ms_10a;

typedef struct
{
  Rte_tuRB_Task_10ms_10a Rte_RB;
} Rte_tsTask_10ms_10a;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Boolean Rte_BusOff_Cnt_lgc;
  Rte_DE_Boolean Rte_CTermActive_Cnt_lgc;
  Rte_DE_Boolean Rte_ESCOffsCfgSeld_Cnt_lgc;
  Rte_DE_Boolean Rte_RxMsgsSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_UInt8 Rte_ComputerRazGCTRaw_Cnt_u08;
  Rte_DE_UInt8 Rte_EtatMTRaw_Cnt_u08;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_LxaSeln_Cnt_lgc;
  Rte_DE_Float Rte_LxaTqFacReq_Uls_f32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2;

typedef struct
{
  Rte_DE_UInt8 Rte_EtatPrincipSev_Cnt_u08;
  Rte_DE_UInt8 Rte_EtatReseauElec_Cnt_u08;
  Rte_DE_UInt8 Rte_PowerSupplies_Cnt_u08;
  Rte_DE_UInt8 Rte_ShuntPosition_Cnt_u08;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432;

typedef struct
{
  Rte_DE_UInt32 Rte_CompteurTemporelVehiculeRaw_Cnt_u32;
  Rte_DE_UInt32 Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32;
  Rte_DE_UInt32 Rte_Kilometrage_Cnt_u32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552;

typedef struct
{
  Rte_DE_Boolean Rte_DefaultVehSpd_Cnt_lgc;
  Rte_DE_Boolean Rte_APAAuthn_Cnt_lgc;
  Rte_DE_Boolean Rte_APARequest_Cnt_lgc;
  Rte_DE_Boolean Rte_AbsActv_Cnt_lgc;
  Rte_DE_Float Rte_AngleVolant_HwDeg_f32;
  Rte_DE_Boolean Rte_ApaRelaxReq_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaVehicleSpeedValid_Cnt_lgc;
  Rte_DE_Boolean Rte_BSIDataMissing_Cnt_lgc;
  Rte_DE_Boolean Rte_CMMDataMissing_Cnt_lgc;
  Rte_DE_SInt16 Rte_CONSANGLECPK_Cnt_s16;
  Rte_DE_Boolean Rte_CPKOK_Cnt_lgc;
  Rte_DE_Float Rte_ColAngleSetpoint_HwDeg_f32;
  Rte_DE_UInt8 Rte_DMDFCTCPK_Cnt_u08;
  Rte_DE_Boolean Rte_ElectronicIntegration_Cnt_lgc;
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
  Rte_DE_Boolean Rte_EngOn_Cnt_lgc;
  Rte_DE_Boolean Rte_EscAckFromSerlCom_Cnt_lgc;
  Rte_DE_Boolean Rte_EscActv_Cnt_lgc;
  Rte_DE_Boolean Rte_EscDataVldFromSerlCom_Cnt_lgc;
  Rte_DE_Boolean Rte_EscEna_Cnt_lgc;
  Rte_DE_Boolean Rte_EscFltPrsnt_Cnt_lgc;
  Rte_DE_Float Rte_EscOffsFromSerlCom_HwDeg_f32;
  Rte_DE_Float Rte_EscPrecisionFromSerlCom_HwDeg_f32;
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_Boolean Rte_LxaInpVld_Cnt_lgc;
  Rte_DE_PsaLxaSt_Cnt_enum Rte_LxaStateFilt_Cnt_enum;
  Rte_DE_Boolean Rte_MultiModeVld_Cnt_lgc;
  Rte_DE_Float Rte_PosSrvoHwAngle_HwDeg_f32;
  Rte_DE_PsaTunModSt_Cnt_enum Rte_ReqModeDAFinal_Cnt_enum;
  Rte_DE_Boolean Rte_SerialComAngleValid_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehSpd_Kph_f32;
  Rte_DE_Boolean Rte_ValidEngineStatus_Cnt_lgc;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleLatAccel_MpSecSq_f32;
  Rte_DE_Boolean Rte_VehicleLatAccelValid_Cnt_lgc;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Per2;

typedef union
{
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Per1 Rte_Ap_SrlComInput_SrlComInput_Per1;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2 Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_3F2;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432 Rte_Ap_SrlComInput_SrlComInput_MsgIsDatBsi_432;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552 Rte_Ap_SrlComInput_SrlComInput_MsgIsDat4V2Bsi_552;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Per2 Rte_Ap_SrlComInput_SrlComInput_Per2;
} Rte_tuRB_Task_10ms_10b;

typedef struct
{
  Rte_tuRB_Task_10ms_10b Rte_RB;
} Rte_tsTask_10ms_10b;

typedef struct
{
  Rte_DE_UInt32 Rte_ActiveTunOvrPtrAddr_Cnt_u32;
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_TuningSessionAddrPtrEnum Rte_TuningSessionActPtr_Cnt_u8;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
  Rte_DE_Boolean Rte_TunReqGranted_Cnt_lgc;
} Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Per1;

typedef union
{
  Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Per1 Rte_Ap_TuningSelAuth_TuningSelAuth_Per1;
} Rte_tuRB_Task_10ms_11;

typedef struct
{
  Rte_DE_UInt16 Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16;
} Rte_tsTB_Task_10ms_11;

typedef struct
{
  Rte_tsTB_Task_10ms_11 Rte_TB;
  Rte_tuRB_Task_10ms_11 Rte_RB;
} Rte_tsTask_10ms_11;

typedef struct
{
  Rte_DE_UInt32 Rte_CompteurTemporelVehicule_Cnt_u32;
  Rte_DE_UInt8 Rte_ComputerRazGCT_Cnt_u08;
  Rte_DE_UInt32 Rte_ISDAT4V2BSI552MsgRxTime_MSec_u32;
  Rte_DE_Boolean Rte_TxEnabled_Cnt_lgc;
} Rte_tsRB_Ap_FaultLog_FaultLog_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ElectronicIntegration_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_BusOff_Cnt_lgc;
  Rte_DE_Boolean Rte_TxEnabled_Cnt_lgc;
} Rte_tsRB_Cd_SrlComDriver_SrlComDriver_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_UInt32 Rte_ActiveTunOvrPtrAddr_Cnt_u32;
  Rte_DE_TuningSessionAddrPtrEnum Rte_TuningSessionActPtr_Cnt_u8;
} Rte_tsRB_Ap_ApXcp_ApXcp_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_AVASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_CAVHCSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_CityParkSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_DampingSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_DftAsstTbl_Cnt_lgc;
  Rte_DE_Boolean Rte_DrivingDynSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Boolean Rte_EOTImpactSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EOTThermalSrlComSvcDft_Cnt_lgc;
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_FricLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HysAddSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HystCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_KinIntDiagSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LXASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_LimitSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LoaMgrDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MfgDiagInhibit_Cnt_lgc;
  Rte_DE_Boolean Rte_ModIdxSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MultIgnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MultiModeSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_ParkAstSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_ReturnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_RxMsgsSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_STTdSelected_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Boolean Rte_ThermalDCSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_TrqRmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_WhlImbRejSrlComSvcDft_Cnt_lgc;
} Rte_tsRB_Sa_CDDInterface6_CDDInterface6_Per1;

typedef struct
{
  Rte_DE_Float Rte_BatteryVoltage_Volt_f32;
  Rte_DE_Boolean Rte_BusOff_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ElectronicIntegration_Cnt_lgc;
  Rte_DE_UInt8 Rte_EtatMt_Cnt_u08;
} Rte_tsRB_Ap_DemIf_DemIf_Per;

typedef union
{
  Rte_tsRB_Ap_FaultLog_FaultLog_Per1 Rte_Ap_FaultLog_FaultLog_Per1;
  Rte_tsRB_Cd_SrlComDriver_SrlComDriver_Per1 Rte_Cd_SrlComDriver_SrlComDriver_Per1;
  Rte_tsRB_Ap_ApXcp_ApXcp_Per1 Rte_Ap_ApXcp_ApXcp_Per1;
  Rte_tsRB_Sa_CDDInterface6_CDDInterface6_Per1 Rte_Sa_CDDInterface6_CDDInterface6_Per1;
  Rte_tsRB_Ap_DemIf_DemIf_Per Rte_Ap_DemIf_DemIf_Per;
} Rte_tuRB_Task_10ms_6;

typedef struct
{
  Rte_tuRB_Task_10ms_6 Rte_RB;
} Rte_tsTask_10ms_6;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrTrq_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatFricLearning_Cnt_lgc;
  Rte_DE_Boolean Rte_FricLrnCustEna_Cnt_lgc;
  Rte_DE_Float Rte_HwAng_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuthority_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Float Rte_LatAcc_MpSecSq_f32;
  Rte_DE_Float Rte_Temperature_DegC_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_EstFric_HwNm_f32;
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
  Rte_DE_Float Rte_SatEstFric_HwNm_f32;
} Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Boolean Rte_NTCB1Enbl_Cnt_lgc;
} Rte_tsRB_Ap_BVDiag_BVDiag_Per1;

typedef struct
{
  Rte_DE_Float Rte_MtrCurrDax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Float Rte_MtrVoltDax_Volt_f32;
  Rte_DE_Float Rte_MtrVoltQax_Volt_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_ElectricPower_Watt_f32;
  Rte_DE_Float Rte_SupplyCurrent_Amp_f32;
} Rte_tsRB_Ap_ElePwr_ElePwr_Per1;

typedef union
{
  Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Per1 Rte_Ap_AvgFricLrn_AvgFricLrn_Per1;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1 Rte_Ap_LrnEOT_LrnEOT_Per1;
  Rte_tsRB_Ap_BVDiag_BVDiag_Per1 Rte_Ap_BVDiag_BVDiag_Per1;
  Rte_tsRB_Ap_ElePwr_ElePwr_Per1 Rte_Ap_ElePwr_ElePwr_Per1;
} Rte_tuRB_Task_10ms_9;

typedef struct
{
  Rte_DE_Float Rte_I_IoHwAb10_Batt_Volt_f32;
} Rte_tsTB_Task_10ms_9;

typedef struct
{
  Rte_tsTB_Task_10ms_9 Rte_TB;
  Rte_tuRB_Task_10ms_9 Rte_RB;
} Rte_tsTask_10ms_9;

typedef struct
{
  Rte_DE_Float Rte_InputHwTrq_HwNm_f32;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
} Rte_tsRB_Ap_Sweep_Sweep_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
} Rte_tsRB_Ap_HighFreqAssist_HighFreqAssist_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_DutyCycleLevel_Uls_f32;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HwTrqHysAdd_HwNm_f32;
  Rte_DE_Float Rte_IpTrqOvr_HwNm_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
} Rte_tsRB_Ap_Assist_Assist_Per1;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatHystService_Cnt_lgc;
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
} Rte_tsRB_Ap_HystComp_HystComp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_AsstFWActive_Uls_f32;
  Rte_DE_Float Rte_CombinedAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_SysAssistCmd_MtrNm_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
} Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_CorrectedElecMtrPos_Rev_u0p16;
  Rte_DE_Float Rte_CumMechMtrPos_Rev_f32;
  Rte_DE_UInt16 Rte_Die1RxError_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1RxMtrPos_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1RxRevCtr_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1UnderVoltgFltAccum_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxError_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxMtrPos_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxRevCtr_Cnt_u16;
  Rte_DE_SInt8 Rte_MtrPosPolarity_Cnt_s08;
  Rte_DE_UInt16 Rte_RxMtrPosParityAccum_Cnt_u16;
  Rte_DE_UInt16 Rte_UncorrMechMtrPos1_Rev_u0p16;
  Rte_DE_Float Rte_AlignedCumMechMtrPosMRF_Deg_f32;
  Rte_DE_Float Rte_CumMechMtrPosMRF_Deg_f32;
  Rte_DE_UInt8 Rte_CumMechMtrPosStatus_Cnt_u08;
  Rte_DE_Float Rte_SysCCumMechMtrPosMRF_Deg_f32;
} Rte_tsRB_Sa_DigMSB_DigMSB_Per2;

typedef struct
{
  Rte_DE_Float Rte_SysCDiagHwVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCDiagMtrVelMRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_HwVelValid_Cnt_lgc;
} Rte_tsRB_Sa_MtrVel_MtrVel_Per2;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemblyPolarity_Cnt_s08;
  Rte_DE_UInt16 Rte_MechMtrPos2_Rev_u0p16;
  Rte_DE_UInt32 Rte_MechMtrPos2Timestamp_USec_u32;
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Float Rte_SysCHandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCMotorVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel_MtrVel_Per1;

typedef struct
{
  Rte_DE_Float Rte_AlignedCumMechMtrPosCRF_Deg_f32;
  Rte_DE_Float Rte_ComplError_HwDeg_f32;
  Rte_DE_Float Rte_CumMechMtrPosCRF_Deg_f32;
  Rte_DE_Float Rte_AlignedRelHwPos_HwDeg_f32;
  Rte_DE_Float Rte_RelHwPos_HwDeg_f32;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStatusHwPosReducedPerf_Cnt_lgc;
  Rte_DE_Float Rte_I2CHwAbsPos_HwDeg_f32;
  Rte_DE_Boolean Rte_I2CHwAbsPosValid_Cnt_lgc;
  Rte_DE_ManufModeType Rte_ManufMode_Cnt_enum;
  Rte_DE_Float Rte_SensorlessAuthority_Uls_f32;
  Rte_DE_Float Rte_SensorlessHwPos_HwDeg_f32;
  Rte_DE_UInt8 Rte_TurnsCntrValidity_Cnt_u08;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_UInt16 Rte_HwPosSource_Cnt_u16;
  Rte_DE_Float Rte_SrlComHwPos_HwDeg_f32;
  Rte_DE_UInt16 Rte_SrlComHwPosStatus_Cnt_u16;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per2;

typedef struct
{
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CustomDamp_MtrNm_f32;
  Rte_DE_Float Rte_DampingDDFactor_Uls_f32;
  Rte_DE_Boolean Rte_DefeatDampingSvc_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
} Rte_tsRB_Ap_Damping_Damping_Per1;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleLonAccel_KphpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_FrqDepDmpnInrtCmp_MtrNm_f32;
} Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;

typedef struct
{
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PsaDampgCmd_MtrNm_f32;
} Rte_tsRB_Ap_PSADSG_PSADSG_Per1;

typedef struct
{
  Rte_DE_Float Rte_AsstFirewallActive_Uls_f32;
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_Defeat_Damping_Svc_Cnt_lgc;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_InertiaComp_MtrNm_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehicleLonAccel_KphpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_CombinedDamping_MtrNm_f32;
} Rte_tsRB_Ap_DampingFirewall_DampingFirewall_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_Defeat_Return_Svc_Cnt_lgc;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
} Rte_tsRB_Ap_ReturnFirewall_ReturnFirewall_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Boolean Rte_EOTDisable_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_Vehicle_Speed_Kph_f32;
} Rte_tsRB_Ap_EtDmpFw_EtDmpFw_Per1;

typedef struct
{
  Rte_DE_Float Rte_DiagRampRate_XpmS_f32;
  Rte_DE_Float Rte_DiagRampValue_Uls_f32;
  Rte_DE_Float Rte_LoaRateLimit_UlspS_f32;
  Rte_DE_Float Rte_LoaScaleFctr_Uls_f32;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
  Rte_DE_Boolean Rte_RampSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_StrtStopRateLimit_UlspS_f32;
  Rte_DE_Float Rte_StrtStopScaleFctr_Uls_f32;
} Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_AssistEOTLimit_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
  Rte_DE_Float Rte_AstVehSpdLimit_MtrNm_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
} Rte_tsRB_Ap_LmtCod_LmtCod_Per1;

typedef struct
{
  Rte_DE_PsaApaSt_Cnt_enum Rte_ApaState_Cnt_enum;
  Rte_DE_PsaEpsStLxa_Cnt_enum Rte_EPSStateForLxa_Cnt_enum;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_HwTrqRate_HwNmpS_f32;
  Rte_DE_Float Rte_LxaCorrnFacReqLimd_Uls_f32;
  Rte_DE_Boolean Rte_LxaDrvrAbsntHwVelDetd_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaHwAgDetd_Cnt_lgc;
  Rte_DE_Float Rte_PosSrvoCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_PosSrvoEnable_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_ApaOpTrqOv_MtrNm_f32;
  Rte_DE_Boolean Rte_ApaPosSrvoFlt_Cnt_lgc;
  Rte_DE_Float Rte_LxaOpTrqOv_MtrNm_f32;
  Rte_DE_Boolean Rte_LxaTqLimnActv_Cnt_lgc;
} Rte_tsRB_Ap_PSATA_PSATA_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Float Rte_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_AssistEOTLimit_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
  Rte_DE_Float Rte_AssistVehSpdLimit_MtrNm_f32;
  Rte_DE_Float Rte_CombinedDamping_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatLimitService_Cnt_lgc;
  Rte_DE_Float Rte_EotActvCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_HwTqLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_LimitedReturn_MtrNm_f32;
  Rte_DE_Boolean Rte_LrnPnCtrEnable_Cnt_lgc;
  Rte_DE_Float Rte_LrnPnCtrTCmd_MtrNm_f32;
  Rte_DE_Float Rte_OpTrqOvr_MtrNm_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_PowerLimitPerc_Uls_f32;
  Rte_DE_Float Rte_PullCompCmd_MtrNm_f32;
  Rte_DE_Float Rte_TSMitCommand_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimitPerc_Uls_f32;
  Rte_DE_Float Rte_TloaCmd_MtrNm_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_WheelImbalanceCmd_MtrNm_f32;
  Rte_DE_Float Rte_LimitPercentFiltered_Uls_f32;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_TrqLimitMin_MtrNm_f32;
} Rte_tsRB_Ap_AstLmt_AstLmt_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_AssistAssyPolarity_Cnt_s08;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_DiagStsF2Active_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_LOA_State_enum Rte_LoaSt_State_enum;
  Rte_DE_Float Rte_SumLimTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_SysC_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_SysC_MRFMtrTrqCmd_MtrNm_f32;
} Rte_tsRB_Ap_TranlDampg_Ap_TranlDampg_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ATerm_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ControlledDampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_FTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_RampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDnFastWriteComplete_Cnt_lgc;
} Rte_tsRB_Ap_StaMd_StaMd_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_AltFaultActive_Cnt_lgc;
  Rte_DE_Float Rte_CntDisMtrTrqCmdMRF_MtrNm_f32;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_PosServEnable_Cnt_lgc;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmd_MtrNm_f32;
} Rte_tsRB_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1;

typedef struct
{
  Rte_DE_Float Rte_CorrMtrPosElec_Rev_f32;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrCurrDaxRef_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQaxFinalRef_Amp_f32;
  Rte_DE_Float Rte_MtrVoltDax_Volt_f32;
  Rte_DE_Float Rte_MtrVoltQax_Volt_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_TrqLimitMin_MtrNm_f32;
  Rte_DE_UInt8 Rte_MtrCurrIdptSig_Cnt_u08;
} Rte_tsRB_Ap_TqRsDg_TqRsDg_Per1;

typedef struct
{
  Rte_DE_Float Rte_MRFMtrTrqCmd_MtrNm_f32;
} Rte_tsRB_Ap_TrqCmdScl_TrqCmdScl_Per1;

typedef struct
{
  Rte_DE_Float Rte_MRFCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_SInt8 Rte_InstMtrDir_Cnt_s08;
} Rte_tsRB_Ap_QuadDet_QuadDet_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CurrentGainSvc_Cnt_lgc;
  Rte_DE_Boolean Rte_DualEcuMotCtrlMtgnEna_Cnt_lgc;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Boolean Rte_IvtrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_MRFTrqCmdScl_MtrNm_f32;
  Rte_DE_Boolean Rte_MotCurrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_MtrCurrAngle_Rev_f32;
  Rte_DE_Float Rte_MtrVoltDaxFFStatic_Volt_f32;
  Rte_DE_Float Rte_MtrVoltQaxFFStatic_Volt_f32;
} Rte_tsRB_Ap_CurrCmd_CurrCmd_Per1;

typedef struct
{
  Rte_DE_Float Rte_MtrCurrDaxRef_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQaxRef_Amp_f32;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstLd_Henry_f32;
  Rte_DE_Float Rte_EstLq_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
} Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DualEcuMotCtrlMtgnEna_Cnt_lgc;
  Rte_DE_Boolean Rte_IvtrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Boolean Rte_MotCurrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_MtrCurrDax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrDaxRef_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQaxRef_Amp_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_PeakCurrEst_PeakCurrEst_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_CommOffset_Cnt_u16;
  Rte_DE_Boolean Rte_IvtrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_MotCurrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_MtrCurr1TempOffset_Volt_f32;
  Rte_DE_Float Rte_MtrCurr2TempOffset_Volt_f32;
  Rte_DE_SInt8 Rte_MtrPosPolarity_Cnt_s08;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Boolean Rte_ESCOffsCfgSeld_Cnt_lgc;
} Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_SysCVSwitchADC_Cnt_u16;
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
} Rte_tsRB_IoHwAb10_IoHwAb_ReadAdc;

typedef struct
{
  Rte_DE_Float Rte_TorqueCmdCRF_MtrNm_f32;
  Rte_DE_Float Rte_ComplErr_HwDeg_f32;
} Rte_tsRB_Ap_ComplErr_ComplErr_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
} Rte_tsRB_Ap_HwPwUp_HwPwUp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
} Rte_tsRB_Sa_OvrVoltMon_OvrVoltMon_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
  Rte_DE_Boolean Rte_GateDriveResetActive_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
} Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1;

typedef struct
{
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_Boolean Rte_GateDriveResetActive_Cnt_lgc;
  Rte_DE_Float Rte_LRPRCorrectedMtrPosCaptured_Rev_f32;
  Rte_DE_Float Rte_LRPRModulationIndexCaptured_Uls_f32;
  Rte_DE_SInt16 Rte_LRPRPhaseadvanceCaptured_Cnt_s16;
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
  Rte_DE_Float Rte_MotorVelMRFUnfiltered_MtrRadpS_f32;
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
} Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;

typedef struct
{
  Rte_DE_UInt8 Rte_AlignedCumMechMtrPosStatus_Cnt_u08;
  Rte_DE_Float Rte_AlignedRelHwPos_HwDeg_f32;
  Rte_DE_UInt8 Rte_CumMechMtrPosStatus_Cnt_u08;
  Rte_DE_Boolean Rte_EscAckFromSerlCom_Cnt_lgc;
  Rte_DE_Boolean Rte_EscDataVldFromSerlCom_Cnt_lgc;
  Rte_DE_Boolean Rte_EscOffsEna_Cnt_lgc;
  Rte_DE_Float Rte_EscOffsFromSerlCom_HwDeg_f32;
  Rte_DE_Float Rte_EscPrecisionFromSerlCom_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_RelHwPos_HwDeg_f32;
  Rte_DE_Float Rte_SensorlessAuthority_Uls_f32;
  Rte_DE_Float Rte_SensorlessHwPos_HwDeg_f32;
  Rte_DE_Float Rte_TorqueCmdCRF_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_AbsltHwPosn_HwDeg_f32;
  Rte_DE_Boolean Rte_AbsltHwPosnLvl1_Cnt_lgc;
  Rte_DE_Boolean Rte_AbsltHwPosnLvl2_Cnt_lgc;
  Rte_DE_Float Rte_AbsltHwPosnPrecision_HwDeg_f32;
  Rte_DE_Boolean Rte_AbsltHwPosnVld_Cnt_lgc;
  Rte_DE_PsaAgArbnSt_Enum Rte_AgArbnStToSerlCom_Cnt_enum;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_RelHwPosnToSerlCom_HwDeg_f32;
  Rte_DE_Boolean Rte_RelHwPosnVldToSerlCom_Cnt_lgc;
} Rte_tsRB_Ap_PsaAgArbn_PsaAgArbn_Per1;

typedef union
{
  Rte_tsRB_Ap_Sweep_Sweep_Per1 Rte_Ap_Sweep_Sweep_Per1;
  Rte_tsRB_Ap_HighFreqAssist_HighFreqAssist_Per1 Rte_Ap_HighFreqAssist_HighFreqAssist_Per1;
  Rte_tsRB_Ap_Assist_Assist_Per1 Rte_Ap_Assist_Assist_Per1;
  Rte_tsRB_Ap_HystComp_HystComp_Per1 Rte_Ap_HystComp_HystComp_Per1;
  Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1 Rte_Ap_StabilityComp_StabilityComp_Per1;
  Rte_tsRB_Sa_DigMSB_DigMSB_Per2 Rte_Sa_DigMSB_DigMSB_Per2;
  Rte_tsRB_Sa_MtrVel_MtrVel_Per2 Rte_Sa_MtrVel_MtrVel_Per2;
  Rte_tsRB_Sa_MtrVel_MtrVel_Per1 Rte_Sa_MtrVel_MtrVel_Per1;
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per1 Rte_Ap_AbsHwPos_AbsHwPos_Per1;
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per2 Rte_Ap_AbsHwPos_AbsHwPos_Per2;
  Rte_tsRB_Ap_Damping_Damping_Per1 Rte_Ap_Damping_Damping_Per1;
  Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;
  Rte_tsRB_Ap_PSADSG_PSADSG_Per1 Rte_Ap_PSADSG_PSADSG_Per1;
  Rte_tsRB_Ap_DampingFirewall_DampingFirewall_Per1 Rte_Ap_DampingFirewall_DampingFirewall_Per1;
  Rte_tsRB_Ap_ReturnFirewall_ReturnFirewall_Per1 Rte_Ap_ReturnFirewall_ReturnFirewall_Per1;
  Rte_tsRB_Ap_EtDmpFw_EtDmpFw_Per1 Rte_Ap_EtDmpFw_EtDmpFw_Per1;
  Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1 Rte_Ap_StOpCtrl_StOpCtrl_Per1;
  Rte_tsRB_Ap_LmtCod_LmtCod_Per1 Rte_Ap_LmtCod_LmtCod_Per1;
  Rte_tsRB_Ap_PSATA_PSATA_Per1 Rte_Ap_PSATA_PSATA_Per1;
  Rte_tsRB_Ap_AstLmt_AstLmt_Per1 Rte_Ap_AstLmt_AstLmt_Per1;
  Rte_tsRB_Ap_TranlDampg_Ap_TranlDampg_Per1 Rte_Ap_TranlDampg_Ap_TranlDampg_Per1;
  Rte_tsRB_Ap_StaMd_StaMd_Per1 Rte_Ap_StaMd_StaMd_Per1;
  Rte_tsRB_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1;
  Rte_tsRB_Ap_TqRsDg_TqRsDg_Per1 Rte_Ap_TqRsDg_TqRsDg_Per1;
  Rte_tsRB_Ap_TrqCmdScl_TrqCmdScl_Per1 Rte_Ap_TrqCmdScl_TrqCmdScl_Per1;
  Rte_tsRB_Ap_QuadDet_QuadDet_Per1 Rte_Ap_QuadDet_QuadDet_Per1;
  Rte_tsRB_Ap_CurrCmd_CurrCmd_Per1 Rte_Ap_CurrCmd_CurrCmd_Per1;
  Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Per1 Rte_Ap_CurrParamComp_CurrParamComp_Per1;
  Rte_tsRB_Ap_PeakCurrEst_PeakCurrEst_Per1 Rte_Ap_PeakCurrEst_PeakCurrEst_Per1;
  Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per1 Rte_Sa_CDDInterface10_CDDInterface10_Per1;
  Rte_tsRB_IoHwAb10_IoHwAb_ReadAdc Rte_IoHwAb10_IoHwAb_ReadAdc;
  Rte_tsRB_Ap_ComplErr_ComplErr_Per1 Rte_Ap_ComplErr_ComplErr_Per1;
  Rte_tsRB_Ap_HwPwUp_HwPwUp_Per1 Rte_Ap_HwPwUp_HwPwUp_Per1;
  Rte_tsRB_Sa_OvrVoltMon_OvrVoltMon_Per1 Rte_Sa_OvrVoltMon_OvrVoltMon_Per1;
  Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1 Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1;
  Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;
  Rte_tsRB_Ap_PsaAgArbn_PsaAgArbn_Per1 Rte_Ap_PsaAgArbn_PsaAgArbn_Per1;
} Rte_tuRB_Task_2ms_10;

typedef struct
{
  Rte_DE_SigQlfr_State_enum Rte_I_Nhet1CfgAndUse_HwTq1Qlfr_State_enum;
  Rte_DE_UInt8 Rte_I_Nhet1CfgAndUse_HwTq1RollgCntr_Cnt_u08;
  Rte_DE_Float Rte_I_Nhet1CfgAndUse_HwTq1Val_HwNm_f32;
  Rte_DE_SigQlfr_State_enum Rte_I_Nhet1CfgAndUse_HwTq2Qlfr_State_enum;
  Rte_DE_UInt8 Rte_I_Nhet1CfgAndUse_HwTq2RollgCntr_Cnt_u08;
  Rte_DE_Float Rte_I_Nhet1CfgAndUse_HwTq2Val_HwNm_f32;
  Rte_DE_UInt16 Rte_I_HwTqCorrln_HwTqCorrlnSts_Cnt_u16;
  Rte_DE_Float Rte_I_HwTqArbn_HwTqVal_HwNm_f32;
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_I_Sweep_OutputHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_HighFreqAssist_HighFreqAssist_MtrNm_f32;
  Rte_DE_Boolean Rte_I_CDDInterface6_DftAsstTbl_Cnt_lgc;
  Rte_DE_Float Rte_I_Assist_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_MtrTempEst_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_I_HystComp_HysteresisComp_MtrNm_f32;
  Rte_DE_ManufModeType Rte_I_CDDInterface9_MEC_Cnt_enum;
  Rte_DE_Float Rte_I_AssistFirewall_AsstFirewallActive_Uls_f32;
  Rte_DE_Float Rte_I_AssistFirewall_CombinedAssist_MtrNm_f32;
  Rte_DE_Float Rte_I_StabilityComp_AssistCmd_MtrNm_f32;
  Rte_DE_SInt8 Rte_I_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;
  Rte_DE_Float Rte_I_DigMSB_AlignedCumMechMtrPosCRF_Deg_f32;
  Rte_DE_UInt8 Rte_I_DigMSB_AlignedCumMechMtrPosStatus_Cnt_u08;
  Rte_DE_Float Rte_I_DigMSB_CumMechMtrPosCRF_Deg_f32;
  Rte_DE_UInt16 Rte_I_DigMSB_MechMtrPos2_Rev_u0p16;
  Rte_DE_Float Rte_I_MtrVel_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_I_Damping_DampingCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_PsaAgArbn_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_ReturnFirewall_LimitedReturn_MtrNm_f32;
  Rte_DE_Float Rte_I_EtDmpFw_EOTDampingLtd_MtrNm_f32;
  Rte_DE_Boolean Rte_I_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc;
  Rte_DE_Float Rte_I_StOpCtrl_OutputRampMult_Uls_f32;
  Rte_DE_Boolean Rte_I_StOpCtrl_SysStReqDi_Cnt_lgc;
  Rte_DE_Float Rte_I_LmtCod_EOTGainLtd_Uls_f32;
  Rte_DE_Float Rte_I_LmtCod_EOTLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_I_LmtCod_OutputRampMultLtd_Uls_f32;
  Rte_DE_Float Rte_I_LmtCod_StallLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_I_LmtCod_ThermalLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_I_LmtCod_VehSpdLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_I_PSATA_OpTrqOv_MtrNm_f32;
  Rte_DE_Float Rte_I_AstLmt_SumLimTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_Sweep2_OutputMtrTrq_MtrNm_f32;
  Rte_DE_Boolean Rte_I_TranlDampg_CntrlDampComp_Cnt_lgc;
  Rte_DE_Float Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_UInt8 Rte_I_QuadDet_MtrQuad_Cnt_u08;
  Rte_DE_Float Rte_I_CurrParamComp_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_I_CurrParamComp_EstLd_Henry_f32;
  Rte_DE_Float Rte_I_CurrParamComp_EstLq_Henry_f32;
  Rte_DE_Float Rte_I_MtrVel_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Float Rte_I_CurrCmd_MtrCurrDaxRef_Amp_f32;
  Rte_DE_Float Rte_I_CurrCmd_MtrCurrQaxRef_Amp_f32;
} Rte_tsTB_Task_2ms_10;

typedef struct
{
  Rte_tsTB_Task_2ms_10 Rte_TB;
  Rte_tuRB_Task_2ms_10 Rte_RB;
} Rte_tsTask_2ms_10;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemblyPolarity_Cnt_s08;
  Rte_DE_Float Rte_CumMechMtrPosMRF_Deg_f32;
  Rte_DE_UInt32 Rte_MechMtrPos1Timestamp_USec_u32;
  Rte_DE_Float Rte_SysCDiagHwVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCDiagMtrVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Per1;

typedef struct
{
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Per2;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volts_f32;
  Rte_DE_Float Rte_ADCMtrCurr2_Volts_f32;
  Rte_DE_Float Rte_CorrMtrCurrPosition_Rev_f32;
  Rte_DE_Float Rte_MtrCurrAngle_Rev_f32;
  Rte_DE_Float Rte_MtrCurrK1_Amp_f32;
  Rte_DE_Float Rte_MtrCurrK2_Amp_f32;
} Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per2;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volts_f32;
  Rte_DE_Float Rte_ADCMtrCurr2_Volts_f32;
  Rte_DE_Float Rte_MtrVel_MtrRadpS_f32;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VhSpdValid_Cnt_lgc;
  Rte_DE_UInt16 Rte_ComOffset_Cnt_u16;
} Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per3;

typedef struct
{
  Rte_DE_Float Rte_SrlComVehSpeed_Kph_f32;
  Rte_DE_Float Rte_SrlCom_VehicleLonAccel_KphpS_f32;
  Rte_DE_Float Rte_Vehicle_LonAccel_KphpS_f32;
} Rte_tsRB_Ap_SignlCondn_SignlCondn_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_AsstFWActive_Uls_f32;
  Rte_DE_Float Rte_CombinedAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_SysAssistCmd_MtrNm_f32;
} Rte_tsRB_Ap_StabilityComp2_StabilityComp2_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsTempRdPrf_Cnt_lgc;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
  Rte_DE_Float Rte_FiltMeasTemp_DegC_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ATerm_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ControlledDampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_FTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_RampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Ap_StaMd11_StaMd11_Per1;

typedef union
{
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Per1 Rte_Sa_MtrVel2_MtrVel2_Per1;
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Per2 Rte_Sa_MtrVel2_MtrVel2_Per2;
  Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per2 Rte_Sa_CmMtrCurr_CmMtrCurr_Per2;
  Rte_tsRB_Sa_CmMtrCurr_CmMtrCurr_Per3 Rte_Sa_CmMtrCurr_CmMtrCurr_Per3;
  Rte_tsRB_Ap_SignlCondn_SignlCondn_Per1 Rte_Ap_SignlCondn_SignlCondn_Per1;
  Rte_tsRB_Ap_StabilityComp2_StabilityComp2_Per1 Rte_Ap_StabilityComp2_StabilityComp2_Per1;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1 Rte_Sa_CtrlTemp_CtrlTemp_Per1;
  Rte_tsRB_Ap_StaMd11_StaMd11_Per1 Rte_Ap_StaMd11_StaMd11_Per1;
} Rte_tuRB_Task_2ms_11;

typedef struct
{
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
} Rte_tsTB_Task_2ms_11;

typedef struct
{
  Rte_tsTB_Task_2ms_11 Rte_TB;
  Rte_tuRB_Task_2ms_11 Rte_RB;
} Rte_tsTask_2ms_11;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volts_f32;
  Rte_DE_Float Rte_ADCMtrCurr2_Volts_f32;
  Rte_DE_Float Rte_CorrMtrCurrPosition_Rev_f32;
  Rte_DE_Float Rte_CorrMtrPosElec_Rev_f32;
  Rte_DE_UInt16 Rte_CorrectedElecMtrPos_Rev_u0p16;
  Rte_DE_Float Rte_CumMechMtrPos_Rev_f32;
  Rte_DE_UInt16 Rte_Die1RxError_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1RxMtrPos_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1RxRevCtr_Cnt_u16;
  Rte_DE_UInt16 Rte_Die1UnderVoltgFltAccum_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxError_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxMtrPos_Cnt_u16;
  Rte_DE_UInt16 Rte_Die2RxRevCtr_Cnt_u16;
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_SInt16 Rte_LRPRPhaseadvanceCaptured_Cnt_s16;
  Rte_DE_ManufModeType Rte_MEC_Cnt_enum;
  Rte_DE_Float Rte_MechMtrPos1_Rev_f32;
  Rte_DE_UInt32 Rte_MechMtrPos1Timestamp_USec_u32;
  Rte_DE_UInt32 Rte_MechMtrPos2Timestamp_USec_u32;
  Rte_DE_Float Rte_ModIdxFinal_Uls_f32;
  Rte_DE_Float Rte_MtrCurrDax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrK1_Amp_f32;
  Rte_DE_Float Rte_MtrCurrK2_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQaxFinalRef_Amp_f32;
  Rte_DE_Float Rte_MtrVoltDax_Volt_f32;
  Rte_DE_Float Rte_MtrVoltQax_Volt_f32;
  Rte_DE_UInt16 Rte_RxMtrPosParityAccum_Cnt_u16;
  Rte_DE_Float Rte_SysCCorrMtrPosElec_Rev_f32;
  Rte_DE_UInt16 Rte_SysCVSwitchADC_Cnt_u16;
  Rte_DE_UInt16 Rte_UncorrMechMtrPos1_Rev_u0p16;
} Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DftStallLimit_Cnt_lgc;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
} Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1;

typedef struct
{
  Rte_DE_Float Rte_AstVehSpdLimit_MtrNm_f32;
} Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1;

typedef struct
{
  Rte_DE_Float Rte_CcwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CcwFound_Cnt_lgc;
  Rte_DE_Float Rte_CwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CwFound_Cnt_lgc;
  Rte_DE_Boolean Rte_EOTDisable_Cnt_lgc;
  Rte_DE_Float Rte_HandWheelAuth_Uls_f32;
  Rte_DE_Float Rte_HandWheelPos_HwDeg_f32;
  Rte_DE_Float Rte_MotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Float Rte_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_AssistEOTLimit_MtrNm_f32;
} Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Boolean Rte_DefeatReturnSvc_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_PAReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_ReturnDDFactor_Uls_f32;
  Rte_DE_Float Rte_ReturnOffset_HwDeg_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
} Rte_tsRB_Ap_Return_Return_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DisableLearning_Cnt_lgc;
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Float Rte_EstLatAcc_MpSecSq_f32;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Boolean Rte_PullCmpCustLrngDi_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleYawRate_DegpS_f32;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrSt_HwNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PullCompCmd_MtrNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per2;

typedef struct
{
  Rte_DE_Boolean Rte_AbsActv_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaAuthn_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaCmdReq_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaEna_Cnt_lgc;
  Rte_DE_Float Rte_ApaHwAgCmd_HwDeg_f32;
  Rte_DE_Boolean Rte_ApaPosSrvoFlt_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaRelaxReq_Cnt_lgc;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
  Rte_DE_Boolean Rte_CpkOk_Cnt_lgc;
  Rte_DE_Boolean Rte_EscActv_Cnt_lgc;
  Rte_DE_Boolean Rte_EscEna_Cnt_lgc;
  Rte_DE_Boolean Rte_EscFltPrsnt_Cnt_lgc;
  Rte_DE_Boolean Rte_FTermActv_Cnt_lgc;
  Rte_DE_SInt8 Rte_HOWState_Cnt_s08;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Boolean Rte_LpaSeld_Cnt_lgc;
  Rte_DE_Float Rte_LxaHwAgCmd_HwDeg_f32;
  Rte_DE_Boolean Rte_LxaInpVld_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaSelected_Cnt_lgc;
  Rte_DE_PsaLxaSt_Cnt_enum Rte_LxaState_Cnt_enum;
  Rte_DE_Float Rte_LxaTqFacReq_Uls_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_ThermLimitPerc_Uls_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_PsaApaSt_Cnt_enum Rte_ApaState_Cnt_enum;
  Rte_DE_PsaApaTranCause_Cnt_enum Rte_ApaStateTransitionCause_Cnt_enum;
  Rte_DE_Boolean Rte_DrvrIntvDetd_Cnt_lgc;
  Rte_DE_PsaEpsStLxa_Cnt_enum Rte_EPSStateForLxa_Cnt_enum;
  Rte_DE_Float Rte_HwTrqRate_HwNmpS_f32;
  Rte_DE_Boolean Rte_LxaApaConflictReqNTC_Cnt_lgc;
  Rte_DE_Float Rte_LxaCorrnFacReqLimd_Uls_f32;
  Rte_DE_Boolean Rte_LxaDrvrAbsntDetd_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaDrvrAbsntHwVelDetd_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaDrvrAbsntWarn_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaHwAgDetd_Cnt_lgc;
  Rte_DE_Boolean Rte_LxaInactivOnDrvrBhvr_Cnt_lgc;
} Rte_tsRB_Ap_PSASH_PSASH_Per1;

typedef struct
{
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Boolean Rte_PosSrvoEnable_Cnt_lgc;
  Rte_DE_Float Rte_PosSrvoHwAngle_HwDeg_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PosSrvoCmd_MtrNm_f32;
  Rte_DE_Float Rte_PosSrvoReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_PosSrvoSmoothEnable_Uls_f32;
} Rte_tsRB_Ap_PosServo_PosServo_Per1;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysC_Vecu_Volt_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Boolean Rte_VswitchClosed_Cnt_lgc;
} Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1;

typedef struct
{
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_RelHwPos_HwDeg_f32;
  Rte_DE_Float Rte_SrlHwAg_HwDeg_f32;
  Rte_DE_Boolean Rte_SrlHwAgVld_Cnt_lgc;
  Rte_DE_Float Rte_TorqueCmdCRF_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_SensorlessAuthority_Uls_f32;
  Rte_DE_Float Rte_SensorlessHwPos_HwDeg_f32;
} Rte_tsRB_Ap_VehDyn_VehDyn_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_HwTq1Polarity_Cnt_s08;
  Rte_DE_SInt8 Rte_HwTq2Polarity_Cnt_s08;
  Rte_DE_SigQlfr_State_enum Rte_HwTq1Qlfr_State_enum;
  Rte_DE_UInt8 Rte_HwTq1RollgCntr_Cnt_u08;
  Rte_DE_Float Rte_HwTq1Val_HwNm_f32;
  Rte_DE_SigQlfr_State_enum Rte_HwTq2Qlfr_State_enum;
  Rte_DE_UInt8 Rte_HwTq2RollgCntr_Cnt_u08;
  Rte_DE_Float Rte_HwTq2Val_HwNm_f32;
} Rte_tsRB_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2;

typedef struct
{
  Rte_DE_Boolean Rte_CtrldDmpStsCmp_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsCtrldDisRmpPres_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  Rte_DE_Boolean Rte_RampDwnStatusComplete_Cnt_lgc;
} Rte_tsRB_Ap_ePWM2_ePWM2_Per1;

typedef struct
{
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
} Rte_tsRB_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_MotorVelocityMRFUnfiltered_MtrRadpS_f32;
  Rte_DE_Float Rte_OVERRIDESIGDIAGADC_Volt_f32;
  Rte_DE_Float Rte_PMOSDIAGADC_Volt_f32;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscClosed_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Per1;

typedef struct
{
  Rte_DE_UInt8 Rte_DmdDelestDASts_Cnt_u08;
  Rte_DE_Boolean Rte_DmdDelestDaVld_Cnt_lgc;
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EngOn_Cnt_lgc;
  Rte_DE_UInt8 Rte_EtatMT_Cnt_u08;
  Rte_DE_ManufModeType Rte_MEC_Cnt_enum;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Boolean Rte_RampDwnStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_STTdSelected_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
  Rte_DE_Boolean Rte_ATermActive_Cnt_lgc;
  Rte_DE_Boolean Rte_CTermActive_Cnt_lgc;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_TmprlMon_TmprlMon_Per2;

typedef struct
{
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HOWEstimate_Uls_f32;
  Rte_DE_SInt8 Rte_HOWState_Cnt_s08;
} Rte_tsRB_Ap_HOWDetect_HOWDetect_Per1;

typedef struct
{
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_MotAgLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_TrqLoaDi_Cnt_lgc;
  Rte_DE_Float Rte_VehWhlBas_mm_f32;
  Rte_DE_Boolean Rte_VehWhlBasVld_Cnt_lgc;
  Rte_DE_Float Rte_VehicleLatAccel_MpSecSq_f32;
  Rte_DE_Boolean Rte_VehicleLatAccelValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Boolean Rte_TrqLOAAvail_Cnt_lgc;
  Rte_DE_Float Rte_TrqLOACmd_MtrNm_f32;
} Rte_tsRB_Ap_TrqLOA_TrqLOA_Per1;

typedef struct
{
  Rte_DE_PsaTunModSt_Cnt_enum Rte_MultiModSwt_Cnt_enum;
  Rte_DE_Boolean Rte_MultiModeSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_PersSelnInpVld_Cnt_lgc;
  Rte_DE_Boolean Rte_TunReqGranted_Cnt_lgc;
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_PsaTunModSt_Cnt_enum Rte_TunModSt_Cnt_enum;
} Rte_tsRB_Ap_PSADMQ_PSADMQ_Per1;

typedef union
{
  Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Per1 Rte_Sa_CDDInterface9_CDDInterface9_Per1;
  Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1 Rte_Ap_HiLoadStall_HiLoadStall_Per1;
  Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1 Rte_Ap_VehSpdLmt_VehSpdLmt_Per1;
  Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1 Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1;
  Rte_tsRB_Ap_Return_Return_Per1 Rte_Ap_Return_Return_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per1 Rte_Ap_ActivePull_ActivePull_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per2 Rte_Ap_ActivePull_ActivePull_Per2;
  Rte_tsRB_Ap_PSASH_PSASH_Per1 Rte_Ap_PSASH_PSASH_Per1;
  Rte_tsRB_Ap_PosServo_PosServo_Per1 Rte_Ap_PosServo_PosServo_Per1;
  Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1 Rte_Ap_BatteryVoltage_BatteryVoltage_Per1;
  Rte_tsRB_Ap_VehDyn_VehDyn_Per1 Rte_Ap_VehDyn_VehDyn_Per1;
  Rte_tsRB_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2 Rte_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2;
  Rte_tsRB_Ap_ePWM2_ePWM2_Per1 Rte_Ap_ePWM2_ePWM2_Per1;
  Rte_tsRB_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1 Rte_Cd_PhaseAbcFdbkMeas_Cd_PhaseAbcFdbkMeas_Per1;
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Per1 Rte_Sa_BkCpPc_BkCpPc_Per1;
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1 Rte_Ap_VehPwrMd_VehPwrMd_Per1;
  Rte_tsRB_Sa_TmprlMon_TmprlMon_Per2 Rte_Sa_TmprlMon_TmprlMon_Per2;
  Rte_tsRB_Ap_HOWDetect_HOWDetect_Per1 Rte_Ap_HOWDetect_HOWDetect_Per1;
  Rte_tsRB_Ap_TrqLOA_TrqLOA_Per1 Rte_Ap_TrqLOA_TrqLOA_Per1;
  Rte_tsRB_Ap_PSADMQ_PSADMQ_Per1 Rte_Ap_PSADMQ_PSADMQ_Per1;
} Rte_tuRB_Task_2ms_9;

typedef struct
{
  Rte_DE_Float Rte_I_MtrVel_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_I_LrnEOT_CCWPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_LrnEOT_CWPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_PsaAgArbn_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_PsaAgArbn_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_I_Sweep_OutputHwTrq_HwNm_f32;
  Rte_DE_Boolean Rte_I_PSASH_PosSrvoEnable_Cnt_lgc;
  Rte_DE_Float Rte_I_PSASH_PosSrvoHwAngle_HwDeg_f32;
} Rte_tsTB_Task_2ms_9;

typedef struct
{
  Rte_tsTB_Task_2ms_9 Rte_TB;
  Rte_tuRB_Task_2ms_9 Rte_RB;
} Rte_tsTask_2ms_9;

typedef struct
{
  Rte_DE_Float Rte_HwTq1Val_HwNm_f32;
  Rte_DE_Float Rte_HwTq2Val_HwNm_f32;
} Rte_tsRB_Sa_HwTqCorrln_HwTqCorrln_Per2;

typedef struct
{
  Rte_DE_Float Rte_I2CHwAbsPos_HwDeg_f32;
  Rte_DE_Boolean Rte_I2CHwAbsPosValid_Cnt_lgc;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per3;

typedef struct
{
  Rte_DE_Boolean Rte_DiagcStsIvtr1Inactv_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagcStsIvtr2Inactv_Cnt_lgc;
  Rte_DE_UInt8 Rte_HwTqIdptSig_Cnt_u08;
  Rte_DE_Boolean Rte_LoaScaDi_Cnt_lgc;
  Rte_DE_UInt8 Rte_MotCurrIdptSig_Cnt_u08;
  Rte_DE_UInt8 Rte_MtrPosIdptSig_Cnt_u08;
  Rte_DE_SteerMod_enum Rte_SteerMod_Cnt_enum;
  Rte_DE_Boolean Rte_TloaAvail_Cnt_lgc;
  Rte_DE_Boolean Rte_TloaDi_Cnt_lgc;
  Rte_DE_Boolean Rte_HwTqLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Boolean Rte_IvtrLoaMtgtnEn_Cnt_lgc;
  Rte_DE_LOA_State_enum Rte_LOASt_State_enum;
  Rte_DE_Boolean Rte_MotAgLoaMtgtnEn_Cnt_lgc;
  Rte_DE_Boolean Rte_MotCurrLoaMtgtnEn_Cnt_lgc;
} Rte_tsRB_Ap_LoaMgr_LoaMgr_Per1;

typedef union
{
  Rte_tsRB_Sa_HwTqCorrln_HwTqCorrln_Per2 Rte_Sa_HwTqCorrln_HwTqCorrln_Per2;
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per3 Rte_Ap_AbsHwPos_AbsHwPos_Per3;
  Rte_tsRB_Ap_LoaMgr_LoaMgr_Per1 Rte_Ap_LoaMgr_LoaMgr_Per1;
} Rte_tuRB_Task_4ms_10;

typedef struct
{
  Rte_DE_UInt8 Rte_I_HwTqCorrln_HwTqIdptSig_Cnt_u08;
} Rte_tsTB_Task_4ms_10;

typedef struct
{
  Rte_tsTB_Task_4ms_10 Rte_TB;
  Rte_tuRB_Task_4ms_10 Rte_RB;
} Rte_tsTask_4ms_10;

typedef struct
{
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
} Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per2;

typedef union
{
  Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per2 Rte_Ap_BatteryVoltage_BatteryVoltage_Per2;
} Rte_tuRB_Task_4ms_9;

typedef struct
{
  Rte_tuRB_Task_4ms_9 Rte_RB;
} Rte_tsTask_4ms_9;

typedef struct
{
  Rte_DE_SInt8 Rte_MtrPosPolarity_Cnt_s08;
} Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Init1;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
} Rte_tsRB_IoHwAb10_IoHwAb_Init;

typedef struct
{
  Rte_DE_Float Rte_EstLd_Henry_f32;
  Rte_DE_Float Rte_EstLq_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
} Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Init;

typedef struct
{
  Rte_DE_ManufModeType Rte_ManufMode_Cnt_enum;
  Rte_DE_UInt16 Rte_HwPosSource_Cnt_u16;
  Rte_DE_UInt16 Rte_SrlComHwPosStatus_Cnt_u16;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CAVHCSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_CityParkSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_ESCOffsCfgSeld_Cnt_lgc;
  Rte_DE_Boolean Rte_LXASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_MultimodeSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_STTdSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_ApaVehicleSpeedValid_Cnt_lgc;
  Rte_DE_Boolean Rte_CPKOK_Cnt_lgc;
  Rte_DE_Boolean Rte_ElectronicIntegration_Cnt_lgc;
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
  Rte_DE_Float Rte_EscPrecisionFromSerlCom_HwDeg_f32;
  Rte_DE_Boolean Rte_LxaInpVld_Cnt_lgc;
  Rte_DE_Boolean Rte_MultiModeVld_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehSpd_Kph_f32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Init;

typedef union
{
  Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Init1 Rte_Sa_CDDInterface10_CDDInterface10_Init1;
  Rte_tsRB_IoHwAb10_IoHwAb_Init Rte_IoHwAb10_IoHwAb_Init;
  Rte_tsRB_Ap_CurrParamComp_CurrParamComp_Init Rte_Ap_CurrParamComp_CurrParamComp_Init;
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Init1 Rte_Ap_AbsHwPos_AbsHwPos_Init1;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Init Rte_Ap_SrlComInput_SrlComInput_Init;
} Rte_tuRB_Task_Init_10;

typedef struct
{
  Rte_DE_Boolean Rte_I_CDDInterface10_ESCOffsCfgSeld_Cnt_lgc;
  Rte_DE_Boolean Rte_I_CDDInterface10_TurnsCounterSelected_Cnt_lgc;
  Rte_DE_Float Rte_I_CurrParamComp_EstKe_VpRadpS_f32;
} Rte_tsTB_Task_Init_10;

typedef struct
{
  Rte_tsTB_Task_Init_10 Rte_TB;
  Rte_tuRB_Task_Init_10 Rte_RB;
} Rte_tsTask_Init_10;

typedef struct
{
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
} Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Init1;

typedef union
{
  Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Init1 Rte_Ap_TuningSelAuth_TuningSelAuth_Init1;
} Rte_tuRB_Task_Init_11a;

typedef struct
{
  Rte_DE_UInt16 Rte_I_CDDInterface11_DesiredTunSet_Cnt_u16;
} Rte_tsTB_Task_Init_11a;

typedef struct
{
  Rte_tsTB_Task_Init_11a Rte_TB;
  Rte_tuRB_Task_Init_11a Rte_RB;
} Rte_tsTask_Init_11a;

typedef struct
{
  Rte_DE_Float Rte_CumMechMtrPosMRF_Deg_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Init;

typedef struct
{
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Init1;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EngTemp_DegC_f32;
  Rte_DE_Boolean Rte_ScomTempDataRcvd_Cnt_lgc;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Init1;

typedef union
{
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Init Rte_Sa_MtrVel2_MtrVel2_Init;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Init1 Rte_Sa_CtrlTemp_CtrlTemp_Init1;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Init1 Rte_Ap_MtrTempEst_MtrTempEst_Init1;
} Rte_tuRB_Task_Init_11b;

typedef struct
{
  Rte_DE_Float Rte_I_CtrlTemp_FiltMeasTemp_DegC_f32;
} Rte_tsTB_Task_Init_11b;

typedef struct
{
  Rte_tsTB_Task_Init_11b Rte_TB;
  Rte_tuRB_Task_Init_11b Rte_RB;
} Rte_tsTask_Init_11b;

typedef struct
{
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_AVASelected_Cnt_lgc;
} Rte_tsRB_Sa_CDDInterface6_CDDInterface6_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CAVHCSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_CityParkSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_ESCOffsCfgSeld_Cnt_lgc;
  Rte_DE_Boolean Rte_LXASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_MultimodeSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_STTdSelected_Cnt_lgc;
} Rte_tsRB_Cd_SrlComDriver_SrlComDriver_Init1;

typedef union
{
  Rte_tsRB_Sa_CDDInterface6_CDDInterface6_Init1 Rte_Sa_CDDInterface6_CDDInterface6_Init1;
  Rte_tsRB_Cd_SrlComDriver_SrlComDriver_Init1 Rte_Cd_SrlComDriver_SrlComDriver_Init1;
} Rte_tuRB_Task_Init_6;

typedef struct
{
  Rte_DE_Boolean Rte_I_CDDInterface6_CAVHCSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_I_CDDInterface6_CityParkSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_I_CDDInterface6_LXASelected_Cnt_lgc;
  Rte_DE_Boolean Rte_I_CDDInterface6_MultiModeSelected_Cnt_lgc;
  Rte_DE_Boolean Rte_I_CDDInterface6_STTdSelected_Cnt_lgc;
} Rte_tsTB_Task_Init_6;

typedef struct
{
  Rte_tsTB_Task_Init_6 Rte_TB;
  Rte_tuRB_Task_Init_6 Rte_RB;
} Rte_tsTask_Init_6;

typedef struct
{
  Rte_DE_UInt16 Rte_IgnCnt_Cnt_u16;
  Rte_DE_ManufModeType Rte_MEC_Cnt_enum;
  Rte_DE_UInt8 Rte_MECTemp_Cnt_u08;
} Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Init1;

typedef struct
{
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_DefeatDutySvc_Cnt_lgc;
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
} Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1;

typedef struct
{
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
} Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1;

typedef union
{
  Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Init1 Rte_Sa_CDDInterface9_CDDInterface9_Init1;
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1 Rte_Ap_VehPwrMd_VehPwrMd_Init1;
  Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1 Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1;
  Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Init1 Rte_Ap_AvgFricLrn_AvgFricLrn_Init1;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1 Rte_Ap_LrnEOT_LrnEOT_Init1;
} Rte_tuRB_Task_Init_9;

typedef struct
{
  Rte_tuRB_Task_Init_9 Rte_RB;
} Rte_tsTask_Init_9;

typedef struct
{
  Rte_DE_UInt32 Rte_CompteurTemporelVehiculeRaw_Cnt_u32;
  Rte_DE_UInt8 Rte_EtatPrincipSev_Cnt_u08;
  Rte_DE_UInt8 Rte_EtatReseauElec_Cnt_u08;
  Rte_DE_UInt32 Rte_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32;
  Rte_DE_UInt32 Rte_Kilometrage_Cnt_u32;
  Rte_DE_Boolean Rte_LxaSeln_Cnt_lgc;
  Rte_DE_Float Rte_LxaTqFacReq_Uls_f32;
  Rte_DE_UInt8 Rte_PowerSupplies_Cnt_u08;
  Rte_DE_UInt8 Rte_ShuntPosition_Cnt_u08;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Trns2;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
} Rte_tsRB_Ap_HwPwUp_HwPwUp_Trns1;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
} Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Trns1;

typedef union
{
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Trns2 Rte_Ap_SrlComInput_SrlComInput_Trns2;
  Rte_tsRB_Ap_HwPwUp_HwPwUp_Trns1 Rte_Ap_HwPwUp_HwPwUp_Trns1;
  Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Trns1 Rte_Sa_MtrDrvDiag_MtrDrvDiag_Trns1;
} Rte_tuRB_Task_Trns_10;

typedef struct
{
  Rte_tuRB_Task_Trns_10 Rte_RB;
} Rte_tsTask_Trns_10;

typedef struct
{
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscClosed_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns2;

typedef struct
{
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns1;

typedef struct
{
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwAuth_Uls_f32;
} Rte_tsRB_Ap_VehDyn_VehDyn_Trns1;

typedef union
{
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns2 Rte_Sa_BkCpPc_BkCpPc_Trns2;
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns1 Rte_Sa_BkCpPc_BkCpPc_Trns1;
  Rte_tsRB_Ap_VehDyn_VehDyn_Trns1 Rte_Ap_VehDyn_VehDyn_Trns1;
} Rte_tuRB_Task_Trns_9;

typedef struct
{
  Rte_tuRB_Task_Trns_9 Rte_RB;
} Rte_tsTask_Trns_9;

# define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"


#endif /* _RTE_TYPE_H */
