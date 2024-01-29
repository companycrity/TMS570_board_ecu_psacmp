/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqLOA.c
 *     Workspace:  C:/SynergyEA3/Working/TrqLOA/autosar
 *     SW-C Type:  Ap_TrqLOA
 *  Generated at:  Tue Nov 24 17:00:50 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqLOA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:	
 * Date Created:      Mon Feb 19 18:34:17 2015
 * %version:          EA3#3 %
 * %date_modified:    Fri Feb 27 11:37:51 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/27/15	 1		  SB		Initial Release for this component. 										  13016
 * 05/22/15	 2		  SB		Implement Version 2					 										  13328
 * 11/12/15	 3		  SB		Updated to SF048A Version 3			 										  EA3#4029 
 */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TrqLOA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "CalConstants.h"
#include "fixmath.h"
#include "interpolation.h"
#include "GlobalMacro.h"
#include "filters.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */ 

/* PRQA S 4395 EOF
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */ 

#define D_TRQLOADEG2RAD_RADPDEG_F32				D_PIOVR180_ULS_F32
#define D_TRQLOAKPH2MPSEC_MPSECPKPH_F32 		0.2778f
#define D_TRQLOAGRAVITATIONALCONST_MPSECSQ_F32 	9.81f
#define D_INVGRAVITATIONALCONST_SECSQPM_F2		(1.0f/D_TRQLOAGRAVITATIONALCONST_MPSECSQ_F32)
#define D_UNITCNVNGAIN_MPMM_F32					0.001f	
#define D_VEHWHLBASLOWRLIM_MM_F32				1000.0f
#define D_VEHWHLBASUPPRLIM_MM_F32				20000.0f
#define D_MINHWAUTH_ULS_F32						0.99f
#define D_TRQLOAMINSCALE_ULS_F32				D_ZERO_ULS_F32
#define D_TRQLOAMAXSCALE_ULS_F32				D_ONE_ULS_F32

#define TRQLOA_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
 STATIC VAR(float32, AP_TRQLOA_VAR) TrqLOA_ScaledMtrTrqCmd_MtrNm_M_f32;/* PRQA S 3218 */   
 STATIC VAR(float32, AP_TRQLOA_VAR) TrqLOA_LatAccScaleFactor_Uls_M_f32;/* PRQA S 3218 */ 
 STATIC VAR(float32, AP_TRQLOA_VAR) TrqLOA_TrqBasedScaleFactor_Uls_M_f32;/* PRQA S 3218 */
 STATIC VAR(float32, AP_TRQLOA_VAR) TrqLOA_TloaCmd_MtrNm_M_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_FinalScaleFactor_Uls_D_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_LatAccEst_G_D_f32;/* PRQA S 3218 */ 
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_LatAccScaleFactor_Uls_D_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_MtrVelScaleFactor_Uls_D_f32;/* PRQA S 3218 */ 
  STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_ScaledMtrTrqCmd_MtrNm_D_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_TempMtrTrqCmd_MtrNm_D_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_VehSpdScaleFactor_Uls_D_f32;/* PRQA S 3218 */
 STATIC volatile VAR(float32, AP_TRQLOA_VAR) TrqLOA_VehWhlBasUsed_mm_D_f32;/* PRQA S 3218 */
 
#define TRQLOA_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define TRQLOA_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
 STATIC	volatile VAR(boolean, AP_TRQLOA_VAR) TrqLOA_VehWhlBasUnavailable_Cnt_D_lgc; /* PRQA S 3218 */

#define TRQLOA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TRQLOA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
 STATIC	VAR(LPF32KSV_Str, AP_TRQLOA_VAR) TrqLOA_LatAccelSV_g_M_Str;

#define TRQLOA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_VEHWHLBASEINIT_MM_F32 = 3000
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQLOA_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqLOA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqLOA_Init1
 *********************************************************************************************************************/
 LPF_KUpdate_f32_m(k_TrqLOA_LPF_Hz_f32, D_2MS_SEC_F32, &TrqLOA_LatAccelSV_g_M_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqLOA_Per1
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
 *   Float Rte_IRead_TrqLOA_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_TrqLOA_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_TrqLoaDi_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehWhlBasVld_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehWhlBas_mm_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_TrqLOA_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(void)
 *   void Rte_IWrite_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQLOA_APPL_CODE) TrqLOA_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqLOA_Per1
 *********************************************************************************************************************/

	 VAR(float32, AUTOMATIC) HwAuthority_Uls_T_f32;
	 VAR(float32, AUTOMATIC) HwPosn_HwDeg_T_f32;
	 VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32; 
	 VAR(float32, AUTOMATIC) VehWhlBas_mm_T_f32;
	 VAR(float32, AUTOMATIC) LatA_MpSecSq_T_f32;
	 VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	 VAR(float32, AUTOMATIC) LatAccEst_g_T_f32;
	 VAR(float32, AUTOMATIC) Usquare_MSqpSecSq_T_f32;
	 VAR(float32, AUTOMATIC) LatAccelMeas_MpSecSq_T_f32;
	 VAR(float32, AUTOMATIC) VehWhlBasUsed_mm_T_f32;
	 VAR(float32, AUTOMATIC) VehWhlBasUsed_m_T_f32;
	 VAR(float32, AUTOMATIC) AbsDiffScale_g_T_f32;
	 VAR(float32, AUTOMATIC) Cmd_MtrNm_T_f32;
	 VAR(float32, AUTOMATIC) DiffScale_g_T_f32;
	 VAR(float32, AUTOMATIC) FinalScaleFactor_Uls_T_f32;
	 VAR(float32, AUTOMATIC) LatAccScaleFactor_Uls_T_f32;	 
	 VAR(float32, AUTOMATIC) MtrVelScaleFactor_Uls_T_f32;
	 VAR(float32, AUTOMATIC) NomDrvTrq_MtrNm_T_f32;
	 VAR(float32, AUTOMATIC) ScaledMtrTrqCmd_MtrNm_T_f32;
	 VAR(float32, AUTOMATIC) SpdDependentGainTbl_Uls_T_f32;
	 VAR(float32, AUTOMATIC) TempMtrTrqCmd_MtrNm_T_f32;
	 VAR(float32, AUTOMATIC) TempTrqCmdSatLkpTbl_Uls_T_f32;
	 VAR(float32, AUTOMATIC) TrqBasedScaleFactor_Uls_T_f32;
	 VAR(float32, AUTOMATIC) VehSpdScaleFactor_Uls_T_f32;
	 VAR(float32, AUTOMATIC) FiltLatAccEst_g_T_f32;
	 VAR(boolean, AUTOMATIC) MotAgLoaMtgtnEn_Cnt_T_lgc;
	 VAR(boolean, AUTOMATIC) TrqLoaDi_Cnt_T_lgc;
	 VAR(boolean, AUTOMATIC) VehWhlBasVld_Cnt_T_lgc;
	 VAR(boolean, AUTOMATIC) VehLatAVld_Cnt_T_lgc; 	 
	 VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_lgc; 	
	 VAR(boolean, AUTOMATIC) VehWhlBasUnavailable_Cnt_T_lgc;
	 VAR(boolean, AUTOMATIC) TloaAvail_Cnt_T_lgc;
	 VAR(uint16,  AUTOMATIC) DiffScale_g_T_u1p15;
	 VAR(uint16,  AUTOMATIC) VehSpd_Kph_T_u10p6;
	 VAR(uint16,  AUTOMATIC) TempTrqCmdSatLkpTbl_Uls_T_u4p12;
	 VAR(uint16,  AUTOMATIC) VehBasedSpdDependentGainTbl_Uls_T_u1p15;
	 VAR(uint16,  AUTOMATIC) SpdDependentGainTbl_Uls_T_u4p12;
	 VAR(uint16,  AUTOMATIC) AbsDiffScale_g_T_u2p14;

     HwAuthority_Uls_T_f32 		= 	Rte_IRead_TrqLOA_Per1_HandwheelAuthority_Uls_f32();
	 HwPosn_HwDeg_T_f32 		= 	Rte_IRead_TrqLOA_Per1_HandwheelPosition_HwDeg_f32();
	 MotAgLoaMtgtnEn_Cnt_T_lgc 	= 	Rte_IRead_TrqLOA_Per1_MotAgLoaMtgtnEn_Cnt_lgc();
	 MtrVel_MtrRadpS_T_f32 		= 	Rte_IRead_TrqLOA_Per1_MtrVelCRF_MtrRadpS_f32();
	 TrqLoaDi_Cnt_T_lgc 		= 	Rte_IRead_TrqLOA_Per1_TrqLoaDi_Cnt_lgc();
	 VehWhlBasVld_Cnt_T_lgc 	= 	Rte_IRead_TrqLOA_Per1_VehWhlBasVld_Cnt_lgc();
	 VehWhlBas_mm_T_f32 		= 	Rte_IRead_TrqLOA_Per1_VehWhlBas_mm_f32();	 
	 VehLatAVld_Cnt_T_lgc 		= 	Rte_IRead_TrqLOA_Per1_VehicleLatAccelValid_Cnt_lgc(); 
	 LatA_MpSecSq_T_f32 		= 	Rte_IRead_TrqLOA_Per1_VehicleLatAccel_MpSecSq_f32();
	 VehSpdVld_Cnt_T_lgc 		= 	Rte_IRead_TrqLOA_Per1_VehicleSpeedValid_Cnt_lgc(); 
	 VehSpd_Kph_T_f32 		= 	Rte_IRead_TrqLOA_Per1_VehicleSpeed_Kph_f32();
	 
	 LatAccelMeas_MpSecSq_T_f32 = LatA_MpSecSq_T_f32 * k_TrqLOA_LatAccConversionFactor_Uls_f32;
	 
	 /* Determine Wheelbase */
	 if((k_TrqLOA_UseVehWhlBasCal_Cnt_lgc == FALSE) && (VehWhlBasVld_Cnt_T_lgc == TRUE))
	 {
		 VehWhlBasUsed_mm_T_f32 = VehWhlBas_mm_T_f32;
		 VehWhlBasUnavailable_Cnt_T_lgc = FALSE;
	 }
	 else if((k_TrqLOA_UseVehWhlBasCal_Cnt_lgc == FALSE) && (VehWhlBasVld_Cnt_T_lgc == FALSE))
	 {
		 VehWhlBasUsed_mm_T_f32 = VehWhlBas_mm_T_f32;
		 VehWhlBasUnavailable_Cnt_T_lgc = TRUE;
	 }
	 else
	 {
		 VehWhlBasUsed_mm_T_f32 = k_Cmn_VehWhlBas_mm_f32;
		 VehWhlBasUnavailable_Cnt_T_lgc = FALSE;
	 }
	 VehWhlBasUsed_mm_T_f32 = Limit_m(VehWhlBasUsed_mm_T_f32, D_VEHWHLBASLOWRLIM_MM_F32, D_VEHWHLBASUPPRLIM_MM_F32);	 
	 TrqLOA_VehWhlBasUsed_mm_D_f32 = VehWhlBasUsed_mm_T_f32;
	 
	 VehWhlBasUsed_m_T_f32 = VehWhlBasUsed_mm_T_f32 * D_UNITCNVNGAIN_MPMM_F32;	 
	 TrqLOA_VehWhlBasUnavailable_Cnt_D_lgc = VehWhlBasUnavailable_Cnt_T_lgc;		
	 
	 /* Estimate Lateral Acceleration */
	 Usquare_MSqpSecSq_T_f32 = (VehSpd_Kph_T_f32 * D_TRQLOAKPH2MPSEC_MPSECPKPH_F32) * 
								(VehSpd_Kph_T_f32 * D_TRQLOAKPH2MPSEC_MPSECPKPH_F32);
	 LatAccEst_g_T_f32 = ((HwPosn_HwDeg_T_f32/k_TrqLOA_SteerRatio_Uls_f32) * D_TRQLOADEG2RAD_RADPDEG_F32 )* 
							(Usquare_MSqpSecSq_T_f32 / 
							((k_TrqLOA_UndersteerGrad_RadpG_f32 * Usquare_MSqpSecSq_T_f32) + 
							(VehWhlBasUsed_m_T_f32 * D_TRQLOAGRAVITATIONALCONST_MPSECSQ_F32)));
	 TrqLOA_LatAccEst_G_D_f32 = LatAccEst_g_T_f32;
	 /* Calculate Temp TrqCmd */
	 VehSpd_Kph_T_u10p6 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u10p6_T);
	 SpdDependentGainTbl_Uls_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt (t_TrqLOA_X_Kph_u10p6,
																	t_TrqLOA_LatAccGain_Y_MtrNmpG_u4p12,
																	TableSize_m(t_TrqLOA_X_Kph_u10p6),
																	VehSpd_Kph_T_u10p6);
	 SpdDependentGainTbl_Uls_T_f32 = FPM_FixedToFloat_m(SpdDependentGainTbl_Uls_T_u4p12, u4p12_T);
	 NomDrvTrq_MtrNm_T_f32 = (LatAccEst_g_T_f32 * SpdDependentGainTbl_Uls_T_f32);
	 /*DeadZone */				
	 Cmd_MtrNm_T_f32 =	((NomDrvTrq_MtrNm_T_f32 > k_TrqLOA_NomDrvTrq_MtrNm_f32) ? (NomDrvTrq_MtrNm_T_f32 - k_TrqLOA_NomDrvTrq_MtrNm_f32) :\
						((NomDrvTrq_MtrNm_T_f32 < (-k_TrqLOA_NomDrvTrq_MtrNm_f32)) ? (NomDrvTrq_MtrNm_T_f32 + k_TrqLOA_NomDrvTrq_MtrNm_f32) :\
						(D_ZERO_ULS_F32) ) ) ;
	 TempTrqCmdSatLkpTbl_Uls_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt (t_TrqLOA_X_Kph_u10p6,
													t_TrqLOA_TempTrqCmdSatYTbl_MtrNm_u4p12,
													TableSize_m(t_TrqLOA_X_Kph_u10p6),
													VehSpd_Kph_T_u10p6); 
	 TempTrqCmdSatLkpTbl_Uls_T_f32 = FPM_FixedToFloat_m(TempTrqCmdSatLkpTbl_Uls_T_u4p12, u4p12_T);
	 TempMtrTrqCmd_MtrNm_T_f32 = Limit_m(Cmd_MtrNm_T_f32, -TempTrqCmdSatLkpTbl_Uls_T_f32, TempTrqCmdSatLkpTbl_Uls_T_f32);
	 TrqLOA_TempMtrTrqCmd_MtrNm_D_f32 = TempMtrTrqCmd_MtrNm_T_f32;
	 /* Scaling */ 
	 /* MtrVelBasedScaling */	
	 /*Torque-Velocity Based */
	 if((TrqLOA_ScaledMtrTrqCmd_MtrNm_M_f32 >= k_TrqLOA_AbsAssistThreshold_MtrNm_f32) && (MtrVel_MtrRadpS_T_f32 >= k_TrqLOA_AbsVelThreshold_MtrRadpS_f32))
	 {
		 TrqBasedScaleFactor_Uls_T_f32 = k_TrqLOA_MaxScaleFactor_Uls_f32;
	 }
	 else if((TrqLOA_ScaledMtrTrqCmd_MtrNm_M_f32 <= (-k_TrqLOA_AbsAssistThreshold_MtrNm_f32)) && (MtrVel_MtrRadpS_T_f32 <= (-k_TrqLOA_AbsVelThreshold_MtrRadpS_f32)))
	 {
		 TrqBasedScaleFactor_Uls_T_f32 = k_TrqLOA_MaxScaleFactor_Uls_f32;
	 }
	 else
	 {
		 TrqBasedScaleFactor_Uls_T_f32 = k_TrqLOA_MinScaleFactor_Uls_f32;
	 } 
	 TrqLOA_TrqBasedScaleFactor_Uls_M_f32 = Limit_m(TrqBasedScaleFactor_Uls_T_f32, 
														(TrqLOA_TrqBasedScaleFactor_Uls_M_f32 + 
														(k_TrqLOA_FallingRampRate_UlspS_f32  * D_2MS_SEC_F32)), 
														(TrqLOA_TrqBasedScaleFactor_Uls_M_f32 + 
														(k_TrqLOA_RisingRampRate_UlspS_f32 *D_2MS_SEC_F32 )));
	 /* MtrVelBasedScaling */
	 MtrVelScaleFactor_Uls_T_f32 = Limit_m(TrqLOA_TrqBasedScaleFactor_Uls_M_f32, D_TRQLOAMINSCALE_ULS_F32, D_TRQLOAMAXSCALE_ULS_F32);
	 TrqLOA_MtrVelScaleFactor_Uls_D_f32 = MtrVelScaleFactor_Uls_T_f32;
	 /* VehicleSpeedBasedScaling */
	 VehBasedSpdDependentGainTbl_Uls_T_u1p15 = IntplVarXY_u16_u16Xu16Y_Cnt (t_TrqLOA_HighSpeedTrqBlend_X_Kph_u10p6,
																	t_TrqLOA_HighSpeedTrqBlend_Y_Uls_u1p15, 
																	TableSize_m(t_TrqLOA_HighSpeedTrqBlend_X_Kph_u10p6),
																	VehSpd_Kph_T_u10p6);																
	 VehSpdScaleFactor_Uls_T_f32 = FPM_FixedToFloat_m(VehBasedSpdDependentGainTbl_Uls_T_u1p15, u1p15_T); 
	 VehSpdScaleFactor_Uls_T_f32 = Limit_m(VehSpdScaleFactor_Uls_T_f32, D_TRQLOAMINSCALE_ULS_F32, D_TRQLOAMAXSCALE_ULS_F32);
	 TrqLOA_VehSpdScaleFactor_Uls_D_f32 = VehSpdScaleFactor_Uls_T_f32;
	 /* LatAccSBasedScaling */
	 FiltLatAccEst_g_T_f32 = LPF_OpUpdate_f32_m(LatAccEst_g_T_f32, &TrqLOA_LatAccelSV_g_M_Str);
	 AbsDiffScale_g_T_f32	= Abs_f32_m(FiltLatAccEst_g_T_f32 - ((-LatAccelMeas_MpSecSq_T_f32) *(D_INVGRAVITATIONALCONST_SECSQPM_F2)));
	 AbsDiffScale_g_T_u2p14 = FPM_FloatToFixed_m(AbsDiffScale_g_T_f32, u2p14_T);
	 DiffScale_g_T_u1p15 = BilinearXYM_u16_u16Xu16YM_Cnt(VehSpd_Kph_T_u10p6,
															AbsDiffScale_g_T_u2p14,
															t_TrqLOA_X_Kph_u10p6,
															TableSize_m(t_TrqLOA_X_Kph_u10p6),
															t_TrqLOA_DiffGainX_G_u2p14,
															t2_TrqLOA_DiffGainY_Uls_u1p15[0],
															TableSize_m(t_TrqLOA_DiffGainX_G_u2p14));
	 DiffScale_g_T_f32 = FPM_FixedToFloat_m(DiffScale_g_T_u1p15, u1p15_T);																	
	 TrqLOA_LatAccScaleFactor_Uls_M_f32 = Limit_m(DiffScale_g_T_f32, 
													(TrqLOA_LatAccScaleFactor_Uls_M_f32 + 
													(k_TrqLOA_DiffScaleRateLimiterFalling_UlspS_f32  * D_2MS_SEC_F32) ), 
													(TrqLOA_LatAccScaleFactor_Uls_M_f32 + 
													(k_TrqLOA_DiffScaleRateLimiterRising_UlspS_f32 * D_2MS_SEC_F32)));
	 LatAccScaleFactor_Uls_T_f32 = Limit_m(TrqLOA_LatAccScaleFactor_Uls_M_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	 TrqLOA_LatAccScaleFactor_Uls_D_f32 = LatAccScaleFactor_Uls_T_f32;
	 /* Scaling */
	 FinalScaleFactor_Uls_T_f32 = (MtrVelScaleFactor_Uls_T_f32 * VehSpdScaleFactor_Uls_T_f32 * LatAccScaleFactor_Uls_T_f32);
	 FinalScaleFactor_Uls_T_f32 = Limit_m(FinalScaleFactor_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	 TrqLOA_FinalScaleFactor_Uls_D_f32 = FinalScaleFactor_Uls_T_f32;
	 ScaledMtrTrqCmd_MtrNm_T_f32 = TempMtrTrqCmd_MtrNm_T_f32 * FinalScaleFactor_Uls_T_f32;
	 TrqLOA_ScaledMtrTrqCmd_MtrNm_D_f32 = ScaledMtrTrqCmd_MtrNm_T_f32;
	 TrqLOA_ScaledMtrTrqCmd_MtrNm_M_f32 = ScaledMtrTrqCmd_MtrNm_T_f32;
	 TrqLOA_TloaCmd_MtrNm_M_f32 = Limit_m(ScaledMtrTrqCmd_MtrNm_T_f32, (-k_TrqLOA_LimOutput_MtrNm_f32), k_TrqLOA_LimOutput_MtrNm_f32);
	 /* ValidityCheck */
	 if((VehSpdVld_Cnt_T_lgc == FALSE)|| 
		(VehLatAVld_Cnt_T_lgc == FALSE)|| 
		(HwAuthority_Uls_T_f32 <= D_MINHWAUTH_ULS_F32)||
		(MotAgLoaMtgtnEn_Cnt_T_lgc == TRUE)||
		(TrqLoaDi_Cnt_T_lgc == TRUE)||
		(VehWhlBasUnavailable_Cnt_T_lgc == TRUE))
	 {
		 TloaAvail_Cnt_T_lgc = FALSE;
	 }
	 else
	 {
		 TloaAvail_Cnt_T_lgc = TRUE;
	 }
	 Rte_IWrite_TrqLOA_Per1_TrqLOAAvail_Cnt_lgc(TloaAvail_Cnt_T_lgc);
	 Rte_IWrite_TrqLOA_Per1_TrqLOACmd_MtrNm_f32(TrqLOA_TloaCmd_MtrNm_M_f32); 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQLOA_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


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
