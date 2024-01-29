/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PSADSG.c
 *     Workspace:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea3/PSADSG-nz2999/PSADSG/autosar
 *     SW-C Type:  Ap_PSADSG
 *  Generated at:  Tue Feb  6 14:46:06 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PSADSG>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_PSADSG.c
 * Module Description: Implementation of CF096A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 02/02/18  1        KByrski   Initial version (based on CF096A Design_1.0.0)                                EA3#18851
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Runnable Entities:
 ==================
  PSADSG_Per1
    PSADSG_Per1 should be called after Dampg_Per1 (SF003A periodic) and before DampgFwl_Per1 (SF035A periodic).

 *********************************************************************************************************************/

#include "Rte_Ap_PSADSG.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "CalConstants.h"
#include "fixmath.h"
#include "interpolation.h"
#include "GlobalMacro.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */
/* PRQA S 4395 EOF
   MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */
/* MISRA-C:2004 Rule 11.4: Casting to different object pointer type. */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/*********************************************** Module level variables **********************************************/
#define PSADSG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(float32, AP_PSADSG_VAR) PsaDSG_PsaDampgCmdFac_Uls_D_f32;                  /* PRQA S 3218 */
#define PSADSG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

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
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSADSG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSADSG_Per1
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
 *   Float Rte_IRead_PSADSG_Per1_DampingCmd_MtrNm_f32(void)
 *   Float Rte_IRead_PSADSG_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PSADSG_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSADSG_Per1_PsaDampgCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PSADSG_Per1_PsaDampgCmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSADSG_APPL_CODE) PSADSG_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSADSG_Per1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) DampingCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;

    /* Temporary */
    VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
    VAR(uint16,  AUTOMATIC) HwTorqueAbs_HwNm_T_u4p12;
    VAR(uint16,  AUTOMATIC) DampgCmdFac_Uls_T_u1p15;
    VAR(float32, AUTOMATIC) DampgCmdFac_Uls_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) PsaDampgCmd_MtrNm_T_f32;

     /* Read Inputs */
    DampingCmd_MtrNm_T_f32 = Rte_IRead_PSADSG_Per1_DampingCmd_MtrNm_f32();
    HwTorque_HwNm_T_f32    = Rte_IRead_PSADSG_Per1_HwTorque_HwNm_f32();
    VehicleSpeed_Kph_T_f32 = Rte_IRead_PSADSG_Per1_VehicleSpeed_Kph_f32();

    VehicleSpeed_Kph_T_u9p7  = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
    HwTorqueAbs_HwNm_T_u4p12 = FPM_FloatToFixed_m(Abs_f32_m(HwTorque_HwNm_T_f32), u4p12_T);

    /* PRQA S 310 BilnrIntpl */
    DampgCmdFac_Uls_T_u1p15 = BilinearXMYM_u16_u16XMu16YM_Cnt(
            VehicleSpeed_Kph_T_u9p7,
            HwTorqueAbs_HwNm_T_u4p12,
            t_PsaDSG_DampgCmdFacVehSpdBndTbl_Kph_u9p7,
            TableSize_m(t_PsaDSG_DampgCmdFacVehSpdBndTbl_Kph_u9p7),
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaDSG_DampgCmdFacHwTqX_HwNm_u4p12,
            (P2CONST(uint16, AUTOMATIC, AUTOMATIC)) t2_PsaDSG_DampgCmdFacY_Uls_u1p15,
            TableSize_m(t2_PsaDSG_DampgCmdFacHwTqX_HwNm_u4p12[0]));
    /*PRQA L:BilnrIntpl */

    DampgCmdFac_Uls_T_f32 = FPM_FixedToFloat_m(DampgCmdFac_Uls_T_u1p15, u1p15_T);
    PsaDSG_PsaDampgCmdFac_Uls_D_f32 = DampgCmdFac_Uls_T_f32;

    PsaDampgCmd_MtrNm_T_f32 = DampgCmdFac_Uls_T_f32 * DampingCmd_MtrNm_T_f32;
    PsaDampgCmd_MtrNm_T_f32 = Limit_m(PsaDampgCmd_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);

    /* Write outputs */
    Rte_IWrite_PSADSG_Per1_PsaDampgCmd_MtrNm_f32(PsaDampgCmd_MtrNm_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSADSG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
