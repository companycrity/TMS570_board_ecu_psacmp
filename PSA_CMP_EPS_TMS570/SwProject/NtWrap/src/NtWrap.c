/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NtWrap.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  NtWrap
 *  Generated at:  Thu Feb  8 17:25:44 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <NtWrap>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          6 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version 10
 * 07/26/16    2       WH       Updated for new polarity and nhet components									EA3#9275
 * 08/30/16    3       WH       Updated for new application port type for hwtq functions     					EA3#10606
 * 04/01/17    4       WH       Updated for new application port type for PsaAgArbn functions     			    EA3#15004
 * 12/06/17    6       RK       Serial Com refactoring related to CPU Load optimization and MISRA               EA3#18157
 * 02/08/18    7       RK       Fix for CAN bus off recovery scenario											EA3#17854
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_NtWrap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "NtWrap.h"
#include "tcb.h"

#include "Adc.h"
#include "Adc2.h"
#include "Ap_ApXcp.h"
#include "Cd_NvMProxy.h"
#include "Dem.h"
#include "Dma.h"
#include "fbl_def.h"
#include "PwmCdd.h"
#include "Ap_StaMd.h"
#include "Wdg_TMS570LS3x.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "EPS_DiagSrvcs_ISO.h"


typedef struct
{
	boolean EnableManualCtrl;
	float32 MtrTrqCmd_MtrNm_f32;
} NtPar1_Type;

typedef struct
{
	float32 NomKe_VpRadpS_f32;
	float32 NomRmtr_Ohm_f32;
} NtPar2_Type;

typedef struct
{
	const CoggingCancTrq * CogTrqCalPtr;
	uint16                 ID;
} NtPar3_Type;

typedef struct
{
	boolean	EnableFricLearning_Cnt_lgc;
	boolean	EnableOffsetOutput_Cnt_lgc;
	uint8	OpMode_Uls_u08;
} NtPar4_Type;

typedef struct
{
	uint8 *	SrvcData_Cnt_u08;
	uint16	RequestDataIdx_Cnt_T_u16;
} NtPar5_Type;

typedef struct
{
	Dem_DTCType			DTC;
	Dem_DTCKindType		DTCKind;
	Dem_DTCOriginType	DTCOrigin;
} NtPar6_Type;


/* 
* This design provides a seperate return buffer for each non-trusted function interface.  This provides the ability
* to call non-trusted funcitons from different preemption levels without concern for return buffer consistiency.
* However, it does not allow re-entrant calling for the same function, as both invocations will be accessing the same
* buffer.
*/

typedef union
{ /* PRQA S 750 */
	Std_ReturnType 			Std_Return;
	Dem_ReturnClearDTCType	Dem_ReturnClearDTC;
} RetBuf_Type;

#define NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(RetBuf_Type, AUTOMATIC) NtWrap_RetBuf[osdNumberOfNonTrustedFunctions];
#define NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
 * MtrCurrOffProcessFlag: Enumeration of integer in interval [0...4] with enumerators
 *   CURROFF_INIT (0U)
 *   CURROFF_PROCESSING (1U)
 *   CURROFF_PASS (2U)
 *   CURROFF_FAIL (3U)
 * PsaAgArbnDiagCmdReq_Enum: Enumeration of integer in interval [0...2] with enumerators
 *   PSAAGARBNDIAGCMDREQ_DIAGNOACTN (0U)
 *   PSAAGARBNDIAGCMDREQ_DIAGRSTREQ (1U)
 *   PSAAGARBNDIAGCMDREQ_DIAGCENTR (2U)
 *
 * Array Types:
 * ============
 * CoggingCancTrq: Array with 512 element(s) of type UInt16
 *
 * Record Types:
 * =============
 * PhaseCurrCal_DataType: Record with elements
 *   EOLMtrCurrVcalCmd_VoltCnts_f32 of type Float
 *   EOLMtrCurr1OffsetLo_Volts_f32 of type Float
 *   EOLPhscurr1Gain_AmpspVolt_f32 of type Float
 *   EOLPhscurr2Gain_AmpspVolt_f32 of type Float
 *   EOLMtrCurr2OffsetLo_Volts_f32 of type Float
 *   EOLMtrCurr1OffsetDiff_Volts_f32 of type Float
 *   EOLMtrCurr2OffsetDiff_Volts_f32 of type Float
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


#define RTE_START_SEC_NTWRAP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_CustClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustClrTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_CustClrTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AbsHwPos_SCom_CustClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustClrTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AbsHwPos_SCom_CustClrTrim
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AbsHwPos_SCom_CustClrTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_CustSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_CustSetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AbsHwPos_SCom_CustSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_CustSetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AbsHwPos_SCom_CustSetTrim (returns application error)
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AbsHwPos_SCom_CustSetTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
	return NtWrap_RetBuf[NtWrapS_AbsHwPos_SCom_CustSetTrim].Std_Return;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_NxtClearTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtClearTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_NxtClearTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AbsHwPos_SCom_NxtClearTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtClearTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AbsHwPos_SCom_NxtClearTrim
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AbsHwPos_SCom_NxtClearTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AbsHwPos_SCom_NxtSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtSetTrim> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AbsHwPos_SCom_TrimNotPerformed, RTE_E_AbsHwPos_SCom_ValueNotAccepted
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AbsHwPos_SCom_TrimNotPerformed
 *   RTE_E_AbsHwPos_SCom_ValueNotAccepted
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPos_SCom_NxtSetTrim(Float Offset_HwDeg_T_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AbsHwPos_SCom_NxtSetTrim (returns application error)
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AbsHwPos_SCom_NxtSetTrim, (NonTrustedFunctionParameterRefType)&Offset_HwDeg_T_f32);
	
	return NtWrap_RetBuf[NtWrapS_AbsHwPos_SCom_NxtSetTrim].Std_Return;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_ActivePull_SCom_SetLTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLTComp> of PortPrototype <ActivePull_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_ActivePull_SCom_SetLTComp
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_ActivePull_SCom_SetLTComp, (NonTrustedFunctionParameterRefType)&LTComp_HwNm_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_ActivePull_SCom_SetSTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSTComp> of PortPrototype <ActivePull_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_ActivePull_SCom_SetSTComp
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_ActivePull_SCom_SetSTComp, (NonTrustedFunctionParameterRefType)&STComp_HwNm_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AstLmt_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AstLmt_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH, RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AstLmt_Scom_ManualTrqCmd (returns application error)
 *********************************************************************************************************************/
	
	VAR(NtPar1_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.EnableManualCtrl = EnableManualCtrl;
	Args_T_str.MtrTrqCmd_MtrNm_f32 = MtrTrqCmd_MtrNm_f32;
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AstLmt_Scom_ManualTrqCmd, &Args_T_str);
	
	return NtWrap_RetBuf[NtWrapS_AstLmt_Scom_ManualTrqCmd].Std_Return;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_InitLearnedTables
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitLearnedTables> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_InitLearnedTables(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_InitLearnedTables(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AvgFricLrn_SCom_InitLearnedTables
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AvgFricLrn_SCom_InitLearnedTables, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_ResetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToZero> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_ResetToZero(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_ResetToZero(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_ResetToZero(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AvgFricLrn_SCom_ResetToZero
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AvgFricLrn_SCom_ResetToZero, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLFric> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AvgFricLrn_SCom_SetEOLFric
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AvgFricLrn_SCom_SetEOLFric, (NonTrustedFunctionParameterRefType)&EOLFric_HwNm_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AvgFricLrn_SCom_SetOffsetOutputDefeat
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AvgFricLrn_SCom_SetOffsetOutputDefeat, (NonTrustedFunctionParameterRefType)&DefeatOffsetOutput_Cnt_lgc);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_AvgFricLrn_SCom_SetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSelect> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AvgFricLrn_SCom_SetSelect
 *********************************************************************************************************************/
	
	VAR(NtPar4_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.EnableFricLearning_Cnt_lgc = EnableFricLearning_Cnt_lgc;
	Args_T_str.EnableOffsetOutput_Cnt_lgc = EnableOffsetOutput_Cnt_lgc;
	Args_T_str.OpMode_Uls_u08 = OpMode_Uls_u08;
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_AvgFricLrn_SCom_SetSelect, &Args_T_str);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_BatteryVoltage_SCom_ClearTransOvData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearTransOvData> of PortPrototype <BatteryVoltage_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_BatteryVoltage_SCom_ClearTransOvData(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_BatteryVoltage_SCom_ClearTransOvData(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_BatteryVoltage_SCom_ClearTransOvData
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_BatteryVoltage_SCom_ClearTransOvData, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_CalGain(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr_SCom_CalGain (returns application error)
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_CmMtrCurr_SCom_CalGain, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
	return NtWrap_RetBuf[NtWrapS_CmMtrCurr_SCom_CalGain].Std_Return;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_CalOffset(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr_SCom_CalOffset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr_SCom_CalOffset (returns application error)
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_CmMtrCurr_SCom_CalOffset, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
	return NtWrap_RetBuf[NtWrapS_CmMtrCurr_SCom_CalOffset].Std_Return;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <CmMtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(const PhaseCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_CmMtrCurr_SCom_SetMtrCurrCals, (NonTrustedFunctionParameterRefType)ShCurrCalPtr); /* PRQA S 311 */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_ClrTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_ClrTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTqArbn_SCom_ClrTrqTrim (returns application error)
 *********************************************************************************************************************/

	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_HwTqArbn_SCom_ClrTrqTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
    return NtWrap_RetBuf[NtWrapS_HwTqArbn_SCom_ClrTrqTrim].Std_Return;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_SetTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTqArbn_SCom_SetTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_2TqADAS_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_SetTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTqArbn_SCom_SetTrqTrim (returns application error)
 *********************************************************************************************************************/

	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_HwTqArbn_SCom_SetTrqTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
    return NtWrap_RetBuf[NtWrapS_HwTqArbn_SCom_SetTrqTrim].Std_Return;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_HwTqArbn_SCom_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteHwTrqArbOffsetTrim> of PortPrototype <HwTqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim(Float EOLChOffsetTrim_HwNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTqArbn_SCom_WriteData(Float EOLChOffsetTrim_HwNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTqArbn_SCom_WriteData
 *********************************************************************************************************************/

	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_HwTqArbn_SCom_WriteData, (NonTrustedFunctionParameterRefType) &EOLChOffsetTrim_HwNm_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_IoHwAb_Adc_ResetAdcEnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetAdcEnable> of PortPrototype <IoHwAb_Adc>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_IoHwAb_Adc_ResetAdcEnable(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_IoHwAb_Adc_ResetAdcEnable(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_IoHwAb_Adc_ResetAdcEnable(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_IoHwAb_Adc_ResetAdcEnable
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_IoHwAb_Adc_ResetAdcEnable, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_LrnEOT_Scom_ResetEOT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetEOT> of PortPrototype <LrnEOT_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_LrnEOT_Scom_ResetEOT(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_LrnEOT_Scom_ResetEOT
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_LrnEOT_Scom_ResetEOT, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_Polarity_SCom_SetPolarity
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_Polarity_SCom_SetPolarity, (NonTrustedFunctionParameterRefType)&PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_PsaAgArbn_SCom_PsaAaCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PsaAaCmd> of PortPrototype <PsaAgArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_PsaAgArbn_SCom_PsaAaCmd(PsaAgArbnDiagCmdReq_Enum DiagCmd_Cnt_enum)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_PsaAgArbn_SCom_PsaAaCmd
 *********************************************************************************************************************/

	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_PsaAgArbn_SCom_PsaAaCmd, (NonTrustedFunctionParameterRefType)&DiagCmd_Cnt_enum);
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SCom_EOLNomMtrParam_Set
 *********************************************************************************************************************/
	
	VAR(NtPar2_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.NomKe_VpRadpS_f32 = NomKe_VpRadpS_f32;
	Args_T_str.NomRmtr_Ohm_f32 = NomRmtr_Ohm_f32;
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SCom_EOLNomMtrParam_Set, &Args_T_str);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_ElecIntStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStart> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_ElecIntStart(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComDriver_SCom_ElecIntStart
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComDriver_SCom_ElecIntStart, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_ElecIntStop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStop> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_ElecIntStop(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComDriver_SCom_ElecIntStop
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComDriver_SCom_ElecIntStop, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComDriver_SCom_SendMsgOnChange
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendMsgOnChange> of PortPrototype <SrlComDriver_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_SendMsgOnChange(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComDriver_SCom_SendMsgOnChange(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_SendMsgOnChange(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComDriver_SCom_SendMsgOnChange
 *********************************************************************************************************************/

	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComDriver_SCom_SendMsgOnChange, (NonTrustedFunctionParameterRefType)NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComInput_SCom_ManualVehSpd
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComInput_SCom_ManualVehSpd, (NonTrustedFunctionParameterRefType)&VehSpd_Kph_T_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_ResetTimers(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_ResetTimers(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComInput_SCom_ResetTimers
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComInput_SCom_ResetTimers, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SrlComInput_SCom_VehSpdControl
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_SrlComInput_SCom_VehSpdControl, (NonTrustedFunctionParameterRefType)&Enable_Cnt_T_lgc);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_TrqCanc_Scom_SetCogTrqCal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCogTrqCal> of PortPrototype <TrqCanc_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
#else
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
#else
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TrqCanc_Scom_SetCogTrqCal
 *********************************************************************************************************************/
	
	VAR(NtPar3_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.CogTrqCalPtr = CogTrqCalPtr;
	Args_T_str.ID = ID;
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_TrqCanc_Scom_SetCogTrqCal, &Args_T_str);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_TrqCmdScl_SCom_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TrqCmdScl_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TrqCmdScl_SCom_Set(Float Par_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TrqCmdScl_SCom_Set
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_TrqCmdScl_SCom_Set, (NonTrustedFunctionParameterRefType)&Par_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrapC_VehDyn_SCom_ResetCenter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetCenter> of PortPrototype <VehDyn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_VehDyn_SCom_ResetCenter(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_VehDyn_SCom_ResetCenter(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ResetCenter(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_VehDyn_SCom_ResetCenter
 *********************************************************************************************************************/
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_VehDyn_SCom_ResetCenter, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrap_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrap_Per1
 *********************************************************************************************************************/

	/* 	INFO!!!
	 * This is workaround. "Potential" call of this SrlComDriver Server forces DaVinci Developer to
	 * generate Exclusive Area for BusOff really equipped in Interrupt Suspend/Resume.
	 * Otherwise just fake EA was generated. */
	/* Rte_Call_C_SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16) */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_NTWRAP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/***** Non-RTE Client Functions *****/


FUNC(Dem_ReturnClearDTCType, NTWRAP_CODE) NtWrapC_Dem_ClearDTC(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin)
{
	VAR(NtPar6_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.DTC = DTC;
	Args_T_str.DTCKind = DTCKind;
	Args_T_str.DTCOrigin = DTCOrigin;
	
	(void)CallNonTrustedFunction((NonTrustedFunctionIndexType)NtWrapS_Dem_ClearDTC, &Args_T_str);
	
	return NtWrap_RetBuf[NtWrapS_Dem_ClearDTC].Dem_ReturnClearDTC;
}


FUNC(void, NTWRAP_CODE) TWrapC_CallFblStart(void)
{
	(void)CallTrustedFunction(TWrapS_CallFblStart, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_Adc_Init( void * ConfigSet )
{
	(void)CallTrustedFunction(TWrapS_Adc_Init, (TrustedFunctionParameterRefType)ConfigSet);
}


FUNC(void, NTWRAP_CODE) TWrapC_Adc2_Init1(void)
{
	(void)CallTrustedFunction(TWrapS_Adc2_Init1, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_PwmCdd_Init(void)
{
	(void)CallTrustedFunction(TWrapS_PwmCdd_Init, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_StaMd_Init0(void)
{
	(void)CallTrustedFunction(TWrapS_StaMd_Init0, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_Wdg_TMS570LS3x_Init( P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr )
{
	(void)CallTrustedFunction(TWrapS_Wdg_TMS570LS3x_Init, (TrustedFunctionParameterRefType)ConfigPtr); /* PRQA S 311 */
}


FUNC(void, NTWRAP_CODE) TWrapC_WdgM_Init( P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr )
{
	(void)CallTrustedFunction(TWrapS_WdgM_Init, (TrustedFunctionParameterRefType)WdgMConfigPtr); /* PRQA S 311 */
}


FUNC(void, NTWRAP_CODE) TWrapC_NvMProxy_Init(void)
{
	(void)CallTrustedFunction(TWrapS_NvMProxy_Init, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_Dma_InvalidateSlowADCGroup(void)
{
	(void)CallTrustedFunction(TWrapS_Dma_InvalidateSlowADCGroup, (TrustedFunctionParameterRefType)NULL_PTR);
}


FUNC(void, NTWRAP_CODE) TWrapC_ProcessF0FF( P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16)
{
	VAR(NtPar5_Type, AUTOMATIC) Args_T_str;
	
	Args_T_str.SrvcData_Cnt_u08 = t_SrvcData_Cnt_T_u08;
	Args_T_str.RequestDataIdx_Cnt_T_u16 = RequestDataIdx_Cnt_T_u16;
	
	(void)CallTrustedFunction(TWrapS_ProcessF0FF, &Args_T_str);
}


/***** Non-Trusted Functions *****/


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp6( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ApXcpWriteCommon();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_Dem_ClearDTC( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Dem_ClearDTC(((NtPar6_Type*)FunctionParams)->DTC, ((NtPar6_Type*)FunctionParams)->DTCKind, ((NtPar6_Type*)FunctionParams)->DTCOrigin); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp9( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ApXcpWriteCommon();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp10( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ApXcpWriteCommon();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp11( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ApXcpWriteCommon();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_CustClrTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	(void)Rte_Call_C_AbsHwPos_SCom_CustClrTrim();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_CustSetTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_AbsHwPos_SCom_CustSetTrim();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_NxtClearTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	(void)Rte_Call_C_AbsHwPos_SCom_NxtClearTrim();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AbsHwPos_SCom_NxtSetTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_AbsHwPos_SCom_NxtSetTrim(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_ActivePull_SCom_SetLTComp( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_ActivePull_SCom_SetLTComp(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_ActivePull_SCom_SetSTComp( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_ActivePull_SCom_SetSTComp(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AstLmt_Scom_ManualTrqCmd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_AstLmt_Scom_ManualTrqCmd(((NtPar1_Type*)FunctionParams)->EnableManualCtrl, ((NtPar1_Type*)FunctionParams)->MtrTrqCmd_MtrNm_f32); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_InitLearnedTables( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_AvgFricLrn_SCom_InitLearnedTables();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_ResetToZero( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_AvgFricLrn_SCom_ResetToZero();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetOffsetOutputDefeat( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_AvgFricLrn_SCom_SetOffsetOutputDefeat(*((Boolean*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetEOLFric( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_AvgFricLrn_SCom_SetEOLFric(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_AvgFricLrn_SCom_SetSelect( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_AvgFricLrn_SCom_SetSelect(((NtPar4_Type*)FunctionParams)->EnableFricLearning_Cnt_lgc, ((NtPar4_Type*)FunctionParams)->EnableOffsetOutput_Cnt_lgc, ((NtPar4_Type*)FunctionParams)->OpMode_Uls_u08); /* PRQA S 316 */
}

FUNC(void, NTWRAP_CODE)  NONTRUSTED_NtWrapS_PsaAgArbn_SCom_PsaAaCmd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_PsaAgArbn_SCom_PsaAaCmd(*((PsaAgArbnDiagCmdReq_Enum*)FunctionParams)); /* PRQA S 316 */
}

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_BatteryVoltage_SCom_ClearTransOvData( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_BatteryVoltage_SCom_ClearTransOvData();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_CalGain( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_CmMtrCurr_SCom_CalGain();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_CalOffset( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_CmMtrCurr_SCom_CalOffset();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_CmMtrCurr_SCom_SetMtrCurrCals( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals((const PhaseCurrCal_DataType*)FunctionParams); /* PRQA S 316 */
}

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_HwTqArbn_SCom_ClrTrqTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_HwTqArbn_SCom_ClrHwTrqArbOffsetTrim();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_HwTqArbn_SCom_SetTrqTrim( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NtWrap_RetBuf[FunctionIndex].Std_Return = Rte_Call_C_HwTqArbn_SCom_SetHwTrqArbOffsetTrim();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_HwTqArbn_SCom_WriteData( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_HwTqArbn_SCom_WriteHwTrqArbOffsetTrim(*((Float *) FunctionParams)); /* PRQA S 316 */
}

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_IoHwAb_Adc_ResetAdcEnable( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	(void)Rte_Call_C_IoHwAb_Adc_ResetAdcEnable();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_LrnEOT_Scom_ResetEOT( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	(void)Rte_Call_C_LrnEOT_Scom_ResetEOT();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_Polarity_SCom_SetPolarity( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_Polarity_SCom_SetPolarity(*((UInt32*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SCom_EOLNomMtrParam_Set( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SCom_EOLNomMtrParam_Set(((NtPar2_Type*)FunctionParams)->NomKe_VpRadpS_f32, ((NtPar2_Type*)FunctionParams)->NomRmtr_Ohm_f32); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_ElecIntStart( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComDriver_SCom_ElecIntStart();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_ElecIntStop( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComDriver_SCom_ElecIntStop();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComDriver_SCom_SendMsgOnChange( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComDriver_SCom_SendMsgOnChange();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_ManualVehSpd( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComInput_SCom_ManualVehSpd(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_ResetTimers( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComInput_SCom_ResetTimers();
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_SrlComInput_SCom_VehSpdControl( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_SrlComInput_SCom_VehSpdControl(*((Boolean*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_TrqCanc_Scom_SetCogTrqCal( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(((NtPar3_Type*)FunctionParams)->CogTrqCalPtr, ((NtPar3_Type*)FunctionParams)->ID); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_TrqCmdScl_SCom_Set( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_TrqCmdScl_SCom_Set(*((Float*)FunctionParams)); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_VehDyn_SCom_ResetCenter( VAR(NonTrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(NonTrustedFunctionParameterRefType, AUTOMATIC) FunctionParams ) /* PRQA S 3673 */
{
	(void)Rte_Call_C_VehDyn_SCom_ResetCenter();
}


/***** Trusted Functions *****/


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp0( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ApXcpWriteCommon();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_CallFblStart( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	CallFblStart(FBL_START_PARAM);
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Adc_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	Adc_Init((void*)FunctionParams);
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Adc2_Init1( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	Adc2_Init1();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_PwmCdd_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	PwmCdd_Init();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_StaMd_Init0( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	StaMd_Init0();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Wdg_TMS570LS3x_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	Wdg_TMS570LS3x_Init((const Wdg_TMS570LS3x_ConfigType*)FunctionParams); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_WdgM_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	WdgM_Init((const WdgM_ConfigType*)FunctionParams); /* PRQA S 316 */
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_NvMProxy_Init( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	NvMProxy_Init();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_Dma_InvalidateSlowADCGroup( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	Dma_InvalidateSlowADCGroup();
}


FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_ProcessF0FF( VAR(TrustedFunctionIndexType, AUTOMATIC) FunctionIndex, VAR(TrustedFunctionParameterRefType, AUTOMATIC) FunctionParams )
{
	ProcessF0FF(((NtPar5_Type*)FunctionParams)->SrvcData_Cnt_u08, ((NtPar5_Type*)FunctionParams)->RequestDataIdx_Cnt_T_u16); /* PRQA S 316 */
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
