/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface6.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface6
 *  Generated at:  Sun Nov 12 11:07:07 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface6>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          4 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version 2
 * 03/14/17    2       AR       Updated for CMP DSR version 002A                                              EA3#14457
 * 04/01/17    3       AR       Updates fros DSR 2A                                                           EA3#15003
 * 12/12/17    4       RK       Added LoaMgr defear. QAC clean up                                             EA3#18400
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface6.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "CDD_Data.h"
#include "CDD_Func.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"


#define D_DEFEATENGON_CNT_B32			0x01u
#define D_DEFEATFREQDEPDMP_CNT_B32		0x02u
#define D_DEFEATKININTDIAG_CNT_B32		0x04u
#define D_DEFEATTHERMALDC_CNT_B32		0x08u
#define D_DEFEATEOTIMPACT_CNT_B32		0x10u
#define D_DEFEATEOTTHERMAL_CNT_B32		0x20u
#define D_DEFEATMTRVELNRMLRN_CNT_B32	0x40u
#define D_DEFEATMTRPARMNRMLRN_CNT_B32	0x80u
#define D_DEFEATTRQRMP_CNT_B32			0x0100u
#define D_DEFEATMODIDX_CNT_B32			0x0200u
#define D_DEFEATPULLCOMP_CNT_B32		0x0400u
#define D_DEFEATWHLIMBREJ_CNT_B32		0x0800u
#define D_DEFEATPARKAST_CNT_B32			0x1000u
#define D_DEFEATDRIVINGDYN_CNT_B32		0x2000u
#define D_DEFEATHYSTCOMP_CNT_B32		0x4000u
#define D_DEFEATHYSTADD_CNT_B32			0x8000u
#define D_DEFEATRETURN_CNT_B32			0x010000u
#define D_DEFEATDAMPING_CNT_B32			0x020000u
#define D_DEFEATLIMIT_CNT_B32			0x040000u
#define D_DEFEATFRICLRN_CNT_B32			0x100000u
#define D_DEFEATLOA_CNT_B32				(1ul << 22)
#define D_DEFEATRXMSGS_CNT_B32			0x08000000u
#define D_DEFEATMULTIGNMASK_CNT_B32		0x50000000u

#define CDDINTERFACE6_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint8, CDDINTERFACE_VAR_NOINIT) PrevMtrElecMechPolarity_Cnt_M_s08;
#define CDDINTERFACE6_STOP_SEC_VAR_CLEARED_8
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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EnergyModeStateType: Enumeration of integer in interval [0...3] with enumerators
 *   NORMAL (0U)
 *   PRODUCTION (1U)
 *   TRANSPORTATION (2U)
 *   FLASH (3U)
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
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_CCWEOTINIT_HWDEG_F32 = -360.0F
 * Float: D_CWEOTINIT_HWDEG_F32 = 360.0F
 * Float: D_ESTKE_VPRADPS_F32 = 0.025F
 * Float: D_HALF_ULS_F32 = 0.5F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400.0F
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_SUPPLYCURRINIT_AMP_F32 = 166.67F
 * Float: D_TRQOSCFREQINIT_F32 = 50.0F
 * Float: D_TRQOSCFREQINIT_HZ_F32 = 50.0F
 * Float: D_TRQOVLFREQINIT_HZ_F32 = 3.0F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_VEHWHLBASEINIT_MM_F32 = 3000.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_CMPVEHLATAINIT_CNT_U16 = 1022U
 * UInt16: D_FIFTEEN_CNT_U16 = 15U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_SEVEN_CNT_U16 = 7U
 * UInt16: D_THREE_CNT_U16 = 3U
 * UInt16: D_TWOPTFIVE_VOLT_U3P13 = 20480U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_BATTVLTGCORRLNSTSINIT_CNT_U08 = 7U
 * UInt8: D_FOUR_CNT_U08 = 4U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_SEVEN_CNT_U08 = 7U
 * UInt8: D_THREE_CNT_U08 = 3U
 * UInt8: D_TWO_CNT_U08 = 2U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE6_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface6_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface6_Init1_AVASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_AVASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_LXASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_LXASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Init1_STTdSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Init1_STTdSelected_Cnt_lgc(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface6_Init1
 *********************************************************************************************************************/
	
	
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;
	
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface6_Init1_MtrElecMechPolarity_Cnt_s08();
	
	(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
	PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	
	Rte_IWrite_CDDInterface6_Init1_AVASelected_Cnt_lgc(CDD_AVASelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Init1_CAVHCSelected_Cnt_lgc(CDD_CAVHCSelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Init1_CityParkSelected_Cnt_lgc(CDD_CityParkSelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Init1_STTdSelected_Cnt_lgc(CDD_STTdSelected_Cnt_G_lgc);
    Rte_IWrite_CDDInterface6_Init1_LXASelected_Cnt_lgc(CDD_LXASelected_Cnt_G_lgc);
    Rte_IWrite_CDDInterface6_Init1_MultiModeSelected_Cnt_lgc(CDD_MultiModeSelected_Cnt_G_lgc);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface6_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface6_Per1_AVASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_AVASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_CDDInterface6_Per1_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LXASelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LXASelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_STTdSelected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_STTdSelected_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE6_APPL_CODE) CDDInterface6_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface6_Per1
 *********************************************************************************************************************/
	
	
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;
	
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface6_Per1_MtrElecMechPolarity_Cnt_s08();
	
	if (MtrElecMechPolarity_Cnt_T_s08 != PrevMtrElecMechPolarity_Cnt_M_s08)
	{
		(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
		PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	}
	
	/* DIAGNOSTIC SERVICE INTERFACE - ASSIST GAIN FUNCTION */
	Rte_IWrite_CDDInterface6_Per1_DftAsstTbl_Cnt_lgc(CDD_DftAsstTbl_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Per1_DwnldAsstGain_Uls_f32(CDD_DwnldAsstGain_Uls_G_f32);
	
	/* DIAGNOSTIC SERVICE INTERFACE - SRLCOMSVC DEFEAT */
	Rte_IWrite_CDDInterface6_Per1_SrlComSvcDft_Cnt_b32(CDD_EOLSrlComSvcDft_Cnt_G_b32);
	
	/* DIAGNOSTIC SERVICE INTERFACE - ENERGY MODE */
	Rte_IWrite_CDDInterface6_Per1_EnergyModeState_Cnt_enum((EnergyModeStateType)CDD_EnergyModeState_Cnt_G_u08);
	
	/* DIAGNOSTIC SERVICE INTERFACE - MFGDIAGINHIBIT */
	Rte_IWrite_CDDInterface6_Per1_MfgDiagInhibit_Cnt_lgc(MfgDiagInhibit_Uls_G_lgc);
	
	/* DIAGNOSTIC SERVICE INTERFACE - TUNING SELECT */
	Rte_IWrite_CDDInterface6_Per1_AVASelected_Cnt_lgc(CDD_AVASelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Per1_CAVHCSelected_Cnt_lgc(CDD_CAVHCSelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Per1_CityParkSelected_Cnt_lgc(CDD_CityParkSelected_Cnt_G_lgc);
	Rte_IWrite_CDDInterface6_Per1_STTdSelected_Cnt_lgc(CDD_STTdSelected_Cnt_G_lgc);
    Rte_IWrite_CDDInterface6_Per1_LXASelected_Cnt_lgc(CDD_LXASelected_Cnt_G_lgc);
    Rte_IWrite_CDDInterface6_Per1_MultiModeSelected_Cnt_lgc(CDD_MultiModeSelected_Cnt_G_lgc);
	
	/* REQUEST TRANSITION TO OPERATE/RUN STATE */
	if (D_DEFEATENGON_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATENGON_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_EngONSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATFREQDEPDMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATFREQDEPDMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATKININTDIAG_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATKININTDIAG_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATTHERMALDC_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATTHERMALDC_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATEOTIMPACT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATEOTIMPACT_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATEOTTHERMAL_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATEOTTHERMAL_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATMTRVELNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATMTRVELNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATMTRPARMNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATMTRPARMNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATTRQRMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATTRQRMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATMODIDX_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATMODIDX_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(TRUE);
		CDD_ModIdxSrlComSvcDft_Cnt_G_lgc = TRUE;
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_ModIdxSrlComSvcDft_Cnt_lgc(FALSE);
		CDD_ModIdxSrlComSvcDft_Cnt_G_lgc = FALSE;
	}
	
	if (D_DEFEATPULLCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATPULLCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_PullCompSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATWHLIMBREJ_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATWHLIMBREJ_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATPARKAST_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATPARKAST_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_ParkAstSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATDRIVINGDYN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATDRIVINGDYN_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATHYSTCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATHYSTCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_HystCompSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATHYSTADD_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATHYSTADD_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_HysAddSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATRETURN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATRETURN_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_ReturnSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATDAMPING_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATDAMPING_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_DampingSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATLIMIT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATLIMIT_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_LimitSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATFRICLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATFRICLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_FricLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	if (D_DEFEATLOA_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATLOA_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_LoaMgrDft_Cnt_lgc(FALSE);
	}

	/* DEFEAT RECEPTION OF SRLCOMINPUT MESSAGES */
	if (D_DEFEATRXMSGS_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATRXMSGS_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	/* MULTIPLE IGNITION CYCLE DEFEATS - store EOLSrlComSvcDft */
	if (D_DEFEATMULTIGNMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_DEFEATMULTIGNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface6_Per1_MultIgnSrlComSvcDft_Cnt_lgc(FALSE);
	}
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE6_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


FUNC(void, CDDInterface_CODE) CDDPorts_ApplyMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8)
{
	CDD_MtrElecPol_Cnt_G_s8 = MtrElecMechPol_Cnt_s8;
	CDD_ApplyPWMMtrElecMechPol(CDD_MtrElecPol_Cnt_G_s8);
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
