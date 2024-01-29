/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_CtrlPolarityBrshlss.c
 *     Workspace:  C:/Users/sz1dx6/Documents/Synergy/ccm_wa/sz1dx6/CtrlPolarityBrshlss/autosar/Ap_CtrlPolarityBrshlss.dcf
 *     SW-C Type:  Ap_CtrlPolarityBrshlss
 *  Generated at:  Tue Mar 24 09:41:54 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_CtrlPolarityBrshlss>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Mar  9 16:16:48 2015
 * %version:          3 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Mon Mar  9 16:16:48 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/09/15  1.0      M. Story   Initial Creation for FDD 25C                                                 13101
 * 03/23/15  2.0      M. Story   Updated to match existing EA3 components. Inconsistencies noted in the MDD   13151
 * 04/09/15  3.0      M. Story   Corrected the usage of D_ASSMECHPOL_CNT_U32 in MotElecPol write.             13223
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks

 *********************************************************************************************************************/

#include "Rte_Ap_CtrlPolarityBrshlss.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Os.h"

#define D_HWTRQPOL1_CNT_U32					0x0000001U
#define D_HWTRQPOL2_CNT_U32					0x0000002U
#define D_HWTRQPOL3_CNT_U32					0x0000004U
#define D_HWTRQPOL4_CNT_U32					0x0000008U
#define D_HWTRQPOL5_CNT_U32					0x0000010U
#define D_HWTRQPOL6_CNT_U32					0x0000020U
#define D_HWTRQPOL7_CNT_U32					0x0000040U
#define D_HWTRQPOL8_CNT_U32					0x0000080U

#define D_HWPOSPOL1_CNT_U32					0x0000100U
#define D_HWPOSPOL2_CNT_U32					0x0000200U
#define D_HWPOSPOL3_CNT_U32					0x0000400U
#define D_HWPOSPOL4_CNT_U32					0x0000800U
#define D_HWPOSPOL5_CNT_U32					0x0001000U
#define D_HWPOSPOL6_CNT_U32					0x0002000U
#define D_HWPOSPOL7_CNT_U32					0x0004000U
#define D_HWPOSPOL8_CNT_U32					0x0008000U

#define D_MOTMEDPOL1_CNT_U32				0x0010000U
#define D_MOTMEDPOL2_CNT_U32				0x0020000U
#define D_MOTMEDPOL3_CNT_U32				0x0040000U
#define D_MOTMEDPOL4_CNT_U32				0x0080000U
#define D_MOTMEDPOL5_CNT_U32				0x0100000U
#define D_MOTMEDPOL6_CNT_U32				0x0200000U
#define D_MOTMEDPOL7_CNT_U32				0x0400000U
#define D_MOTMEDPOL8_CNT_U32				0x0800000U

#define D_MOTELECPOL_CNT_U32				0x1000000U

#define D_ASSMECHPOL_CNT_U32				0x2000000U

#define D_MotVelPOL_CNT_U32					0x4000000U

STATIC INLINE FUNC(sint8, AP_POLARITY_CODE) GetPolarity(	VAR(uint32, AUTOMATIC) Polarity_Cnt_T_u32,
															VAR(uint32, AUTOMATIC) PolarityMask_Cnt_T_u32);


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
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_WhlImbAlgFlt (224U)
 *   NTC_Num_PAHwVelFlt (225U)
 *   NTC_Num_AngleCntrlFltC (226U)
 *   NTC_Num_AngleCntrlFltD (227U)
 *   NTC_Num_AngleCntrlFltFG (228U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * Polarity_DataType: Record with elements
 *   Polarity_Cnt_u32 of type UInt32
 *   R_Polarity_Cnt_u32 of type UInt32
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
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Polarity_DataType *Rte_Pim_Polarity_Cnt_Str(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AssiMechPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwPosn8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_HwTq8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotElecMeclPolarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn1Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn2Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn3Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn4Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn5Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn6Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn7Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotMeclPosn8Polarity_Cnt_s08(SInt8 data)
 *   Std_ReturnType Rte_Write_MotVelPolarity_Cnt_s08(SInt8 data)
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

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Polarity_Init1
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) PolarityCfg_PolarityCfgSaved_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) PolarityCfg_PolarityCfgSavedCpl_Cnt_T_u32;
	
	PolarityCfg_PolarityCfgSaved_Cnt_T_u32 = Rte_Pim_Polarity_Cnt_Str()->Polarity_Cnt_u32; 
	PolarityCfg_PolarityCfgSavedCpl_Cnt_T_u32 = Rte_Pim_Polarity_Cnt_Str()-> R_Polarity_Cnt_u32;

	(void)Rte_Write_HwTq1Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL1_CNT_U32));
	(void)Rte_Write_HwTq2Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL2_CNT_U32));
	(void)Rte_Write_HwTq3Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL3_CNT_U32));
	(void)Rte_Write_HwTq4Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL4_CNT_U32));
	(void)Rte_Write_HwTq5Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL5_CNT_U32));
	(void)Rte_Write_HwTq6Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL6_CNT_U32));
	(void)Rte_Write_HwTq7Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL7_CNT_U32));
	(void)Rte_Write_HwTq8Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWTRQPOL8_CNT_U32));

	(void)Rte_Write_HwPosn1Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL1_CNT_U32));
	(void)Rte_Write_HwPosn2Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL2_CNT_U32));
	(void)Rte_Write_HwPosn3Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL3_CNT_U32));
	(void)Rte_Write_HwPosn4Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL4_CNT_U32));
	(void)Rte_Write_HwPosn5Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL5_CNT_U32));
	(void)Rte_Write_HwPosn6Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL6_CNT_U32));
	(void)Rte_Write_HwPosn7Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL7_CNT_U32));
	(void)Rte_Write_HwPosn8Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_HWPOSPOL8_CNT_U32));
	
	(void)Rte_Write_MotMeclPosn1Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL1_CNT_U32));
	(void)Rte_Write_MotMeclPosn2Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL2_CNT_U32));
	(void)Rte_Write_MotMeclPosn3Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL3_CNT_U32));
	(void)Rte_Write_MotMeclPosn4Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL4_CNT_U32));
	(void)Rte_Write_MotMeclPosn5Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL5_CNT_U32));
	(void)Rte_Write_MotMeclPosn6Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL6_CNT_U32));
	(void)Rte_Write_MotMeclPosn7Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL7_CNT_U32));
	(void)Rte_Write_MotMeclPosn8Polarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTMEDPOL8_CNT_U32));

	(void)Rte_Write_MotElecMeclPolarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MOTELECPOL_CNT_U32));

	(void)Rte_Write_AssiMechPolarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_ASSMECHPOL_CNT_U32));

	(void)Rte_Write_MotVelPolarity_Cnt_s08(GetPolarity(PolarityCfg_PolarityCfgSaved_Cnt_T_u32, D_MotVelPOL_CNT_U32));


	if( PolarityCfg_PolarityCfgSaved_Cnt_T_u32 != ~PolarityCfg_PolarityCfgSavedCpl_Cnt_T_u32)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagPolarityStr, 0x01U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMDiagPolarityStr, 0x00U, NTC_STATUS_PASSED);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_ReadPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Polarity_SCom_ReadPolarity(UInt32 *PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_VAR) PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Polarity_SCom_ReadPolarity
 *********************************************************************************************************************/

	*PolarityCfg_PolarityCfgSaved_Cnt_T_u32 = Rte_Pim_Polarity_Cnt_Str()->Polarity_Cnt_u32; 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Polarity_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_Polarity_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Polarity_SCom_SetPolarity
 *********************************************************************************************************************/

	(void)SuspendAllInterrupts();

	Rte_Pim_Polarity_Cnt_Str()->Polarity_Cnt_u32 = PolarityCfg_PolarityCfgSaved_Cnt_T_u32;
	Rte_Pim_Polarity_Cnt_Str()->R_Polarity_Cnt_u32 = ~PolarityCfg_PolarityCfgSaved_Cnt_T_u32;

	
	(void)ResumeAllInterrupts();

	(void)Rte_Call_Polarity_WriteBlock(NULL_PTR);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC INLINE FUNC(sint8, AP_POLARITY_CODE) GetPolarity(	VAR(uint32, AUTOMATIC) Polarity_Cnt_T_u32,
															VAR(uint32, AUTOMATIC) PolarityMask_Cnt_T_u32)
{
	VAR(sint8, AUTOMATIC) Polarity_Cnt_T_s08;

	if ( (Polarity_Cnt_T_u32 & PolarityMask_Cnt_T_u32) == PolarityMask_Cnt_T_u32 )
	{
		Polarity_Cnt_T_s08 = D_ONE_CNT_S8;
	}
	else
	{
		Polarity_Cnt_T_s08 = D_NEGONE_CNT_S8;
	}

	return(Polarity_Cnt_T_s08);
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
