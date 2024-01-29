/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_HOWDetect.c
 *     Workspace:  C:/Rijvi_Synergy/Prep/HOWDetect-1/HOWDetect/autosar
 *     SW-C Type:  Ap_HOWDetect
 *  Generated at:  Mon Apr 14 11:47:22 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_HOWDetect>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Apr 01 09:34:17 2014
 * %version:          1 %
 * %date_modified:    Tue Apr 01 09:54:35 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/17/14   1       Rijvi     Initial component creation for SF-44 v001                                    11571
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_HOWDetect.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_HOWDetect_Cfg.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "fixmath.h"
#include "interpolation.h"
#include "CalConstants.h"


/*** Locally Defined Constants ***/
#define D_HOWESTIMATEMAXLIMIT_ULS_F32    0.5f  
#define D_ABSHFTRQLIMIT_NM_F32        255.0f       
 


/*** Module Internal Variables ***/
#define HOWDETECT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_HOWDETECT_VAR) HOWDetect_HOWEstAftRateLimiter_Uls_M_f32; 
STATIC VAR(float32, AP_HOWDETECT_VAR) HOWDetect_HOWEstAftLimiter_Uls_M_f32; 
STATIC volatile VAR(float32, AP_HOWDETECT_VAR) HOWDetect_AbsHighFreqTrq_HwNm_D_f32; 
STATIC volatile VAR(float32, AP_HOWDETECT_VAR) HOWDetect_AbsLowFreqTrq_HwNm_D_f32; 
#define HOWDETECT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


/* Declare Filter Structure variable */
#define HOWDETECT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPF1_Cnt_M_str; 
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPF2_Cnt_M_str; 
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPF3_Cnt_M_str; 
STATIC VAR(HPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_HPF_Cnt_M_str; 
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPFFinal_Cnt_M_str; 
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPFEstimate_Cnt_M_str; 
STATIC VAR(LPF32KSV_Str, AP_HOWDETECT_VAR) HOWDetect_LPFState_Cnt_M_str; 
#define HOWDETECT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */



/*** Locally defined tables ***/
#define HOWDETECT_START_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */
/* HOW State values: -3=High Confidence On, +3=High Confidence Off */
STATIC CONST(sint16, AP_HOWDETECT_VAR) T_HOWStateValues_Cnt_s15p0[7] = { -3, -2, -1, 0, 1, 2, 3 };
#define HOWDETECT_STOP_SEC_CONST_16
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
 * SInt8: Integer in interval [-128...127] (standard type)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_HOWDETECT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HOWDetect_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HOWDETECT_APPL_CODE) HOWDetect_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HOWDetect_Init1
 *********************************************************************************************************************/

	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWTrqInitLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPF1_Cnt_M_str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWTrqInitLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPF2_Cnt_M_str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWTrqInitLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPF3_Cnt_M_str);
	
	HPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWTrqHPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_HPF_Cnt_M_str);
	
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWTrqFinalLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPFFinal_Cnt_M_str);
	
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWEstLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPFEstimate_Cnt_M_str);
	
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_HOWStateLPFKn_Hz_f32, D_2MS_SEC_F32, &HOWDetect_LPFState_Cnt_M_str);
	
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HOWDetect_Per1
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
 *   Float Rte_IRead_HOWDetect_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_HOWDetect_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HOWDetect_Per1_HOWEstimate_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_HOWDetect_Per1_HOWEstimate_Uls_f32(void)
 *   void Rte_IWrite_HOWDetect_Per1_HOWState_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_HOWDetect_Per1_HOWState_Cnt_s08(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HOWDETECT_APPL_CODE) HOWDetect_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HOWDetect_Per1
 *********************************************************************************************************************/

	
	/*** Temporary Variables ***/
	
	/* Module Inputs */
	VAR(float32, AUTOMATIC)   HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC)   VehSpd_Kph_T_f32;
	
	/* Module Outputs */
	VAR(float32, AUTOMATIC)   HOWEstimate_Uls_T_f32;
	VAR(sint8, AUTOMATIC)     HOWState_Cnt_T_s08;
	
	/* Filter HwTrq */
	VAR(float32, AUTOMATIC)   HighFreqGain_Uls_T_f32;
	VAR(uint16, AUTOMATIC)    VehSpd_Kph_T_u9p7;
	VAR(float32, AUTOMATIC)   AbsHighFreqTrq_Nm_T_f32;
	VAR(float32, AUTOMATIC)   AbsLowFreqTrq_Nm_T_f32;
	VAR(float32, AUTOMATIC)   LPF1Output_HwNm_T_f32;
	VAR(float32, AUTOMATIC)   LPF2Output_HwNm_T_f32;
	VAR(float32, AUTOMATIC)   LPF3Output_HwNm_T_f32;
	VAR(float32, AUTOMATIC)   HPFOutput_HwNm_T_f32;
	
	
	/* Calculate HOW Estimate AND Determine HOW State*/
	VAR(float32, AUTOMATIC)   AbsHighFreqTrqAftLimiter_Nm_T_f32;
	VAR(float32, AUTOMATIC)   HighFreqLookupTableOutput_UlspS_T_f32;
	VAR(float32, AUTOMATIC)   LowFreqLookupTableOutput_UlspS_T_f32;
	VAR(float32, AUTOMATIC)   EstLPFOutput_Uls_T_f32;
	VAR(float32, AUTOMATIC)   StateLPFOutput_Uls_T_f32;
	

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_HOWDetect_Per1_CP0_CheckpointReached();

	
	/* Read RTE Inputs */
	HwTrq_HwNm_T_f32 = Rte_IRead_HOWDetect_Per1_HwTrq_HwNm_f32();
	VehSpd_Kph_T_f32 = Rte_IRead_HOWDetect_Per1_VehSpd_Kph_f32();
		
	
	/* ---------------[ Filter HwTrq ]------------------------------------------------------------------------------------------ */
	/* Look up High Frequency Gain */
	VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m( VehSpd_Kph_T_f32, u9p7_T );
	HighFreqGain_Uls_T_f32 = FPM_FixedToFloat_m( IntplVarXY_u16_u16Xu16Y_Cnt ( t_HOWVehSpd_Kph_u9p7, t_HOWHighFreqGainY_Uls_u9p7, 
	                                                                           TableSize_m(t_HOWVehSpd_Kph_u9p7), VehSpd_Kph_T_u9p7 
													                         ),
						                          u9p7_T 
					                            );	
											   
	/* Initial LPF 1 */
	LPF1Output_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTrq_HwNm_T_f32, &HOWDetect_LPF1_Cnt_M_str);
	
	/* Initial LPF 2 */
	LPF2Output_HwNm_T_f32 = LPF_OpUpdate_f32_m(LPF1Output_HwNm_T_f32, &HOWDetect_LPF2_Cnt_M_str);
	
	/* Initial LPF 3 */
	LPF3Output_HwNm_T_f32 = LPF_OpUpdate_f32_m(LPF2Output_HwNm_T_f32, &HOWDetect_LPF3_Cnt_M_str);
	
	AbsLowFreqTrq_Nm_T_f32 = Abs_f32_m( LPF3Output_HwNm_T_f32 );
	HOWDetect_AbsLowFreqTrq_HwNm_D_f32 = AbsLowFreqTrq_Nm_T_f32;
	
	/* HPF */
	HPFOutput_HwNm_T_f32 = HPF_OpUpdate_f32_m( LPF3Output_HwNm_T_f32, &HOWDetect_HPF_Cnt_M_str );
	
	/* Final LPF */
	AbsHighFreqTrq_Nm_T_f32 = LPF_OpUpdate_f32_m( Abs_f32_m( HPFOutput_HwNm_T_f32 * HighFreqGain_Uls_T_f32 ), 
												  &HOWDetect_LPFFinal_Cnt_M_str
												);
	
	HOWDetect_AbsHighFreqTrq_HwNm_D_f32 = AbsHighFreqTrq_Nm_T_f32;
	
	
	/* ---------------[ Calculate HOW Estimate ] & [ Determine HOW State ]------------------------------------------------------- */
	AbsHighFreqTrqAftLimiter_Nm_T_f32 = Limit_m(AbsHighFreqTrq_Nm_T_f32, D_ZERO_ULS_F32, D_ABSHFTRQLIMIT_NM_F32);
	
	/* High Frequency lookup Table */
	HighFreqLookupTableOutput_UlspS_T_f32 = FPM_FixedToFloat_m( BilinearXMYM_s16_u16XMs16YM_Cnt( VehSpd_Kph_T_u9p7, 
																								 FPM_FloatToFixed_m( AbsHighFreqTrqAftLimiter_Nm_T_f32, u8p8_T ), 
																								 t_HOWVehSpd_Kph_u9p7, 
																								 TableSize_m(t_HOWVehSpd_Kph_u9p7), 
																								 t2_HOWHFRateX_HwNm_u8p8[0], 
																								 t2_HOWHFRateY_UlspS_s7p8[0], 
																								 TableSize_m( t2_HOWHFRateX_HwNm_u8p8[0] )
																							   ),
						                                        s7p8_T
					                                          );	
														  
	/* Low Frequency lookup Table */
	LowFreqLookupTableOutput_UlspS_T_f32 = FPM_FixedToFloat_m( BilinearXMYM_s16_u16XMs16YM_Cnt( VehSpd_Kph_T_u9p7, 
																							    FPM_FloatToFixed_m( AbsLowFreqTrq_Nm_T_f32, u8p8_T ), 
																							    t_HOWVehSpd_Kph_u9p7, 
														                                        TableSize_m(t_HOWVehSpd_Kph_u9p7), 
														                                        t2_HOWLFRateX_HwNm_u8p8[0], 
														                                        t2_HOWLFRateY_UlspS_s7p8[0], 
														                                        TableSize_m( t2_HOWLFRateX_HwNm_u8p8[0] )
											                                                  ),
															   s7p8_T
					                                         );	
		

	/* Rate Limiter */
	HOWDetect_HOWEstAftRateLimiter_Uls_M_f32 = Limit_m(  (( (HighFreqLookupTableOutput_UlspS_T_f32 + LowFreqLookupTableOutput_UlspS_T_f32) * D_2MS_SEC_F32 ) 
															+ (HOWDetect_HOWEstAftLimiter_Uls_M_f32 * k_HOWDecaySF_Uls_f32)),
			                                             (HOWDetect_HOWEstAftRateLimiter_Uls_M_f32 - ( k_HOWSlewRate_HwNmpS_f32 * D_2MS_SEC_F32 )),
			                                             (HOWDetect_HOWEstAftRateLimiter_Uls_M_f32 + ( k_HOWSlewRate_HwNmpS_f32 * D_2MS_SEC_F32 ))
	                                                  );
	
	/* Limiter */
	HOWDetect_HOWEstAftLimiter_Uls_M_f32 = Limit_m( HOWDetect_HOWEstAftRateLimiter_Uls_M_f32, -D_HOWESTIMATEMAXLIMIT_ULS_F32, D_HOWESTIMATEMAXLIMIT_ULS_F32 );
	
	/* LPF Estimate */
	EstLPFOutput_Uls_T_f32 = LPF_OpUpdate_f32_m( HOWDetect_HOWEstAftLimiter_Uls_M_f32, &HOWDetect_LPFEstimate_Cnt_M_str );
	
	if( VehSpd_Kph_T_f32 > k_HOWMinVehSpd_Kph_f32 )
	{
		HOWEstimate_Uls_T_f32 = EstLPFOutput_Uls_T_f32 + D_HOWESTIMATEMAXLIMIT_ULS_F32;
		
		/* LPF State */
		StateLPFOutput_Uls_T_f32 = LPF_OpUpdate_f32_m( HOWEstimate_Uls_T_f32, &HOWDetect_LPFState_Cnt_M_str );
		
		/* HOW State Look up Table */
		HOWState_Cnt_T_s08 = ( sint8 )( IntplVarXY_s16_u16Xs16Y_Cnt( t_HOWStateThresholds_Uls_u8p8, 
															         T_HOWStateValues_Cnt_s15p0, 
															         TableSize_m(t_HOWStateThresholds_Uls_u8p8), 
															         FPM_FloatToFixed_m( StateLPFOutput_Uls_T_f32, u8p8_T )
														           )	     	 
									  );
	}
	else
	{
		HOWEstimate_Uls_T_f32 = D_HOWESTIMATEMAXLIMIT_ULS_F32;
		
		/* LPF State */
		LPF_OpUpdate_f32_m( HOWEstimate_Uls_T_f32, &HOWDetect_LPFState_Cnt_M_str );
		
		HOWState_Cnt_T_s08 = D_ZERO_CNT_S8;
	}
		
	
	HOWEstimate_Uls_T_f32 = Limit_m(HOWEstimate_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	
	/* Write local copies to module outputs */
	Rte_IWrite_HOWDetect_Per1_HOWEstimate_Uls_f32(HOWEstimate_Uls_T_f32);
	Rte_IWrite_HOWDetect_Per1_HOWState_Cnt_s08(HOWState_Cnt_T_s08);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_HOWDetect_Per1_CP1_CheckpointReached();
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_HOWDETECT_APPL_CODE
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
