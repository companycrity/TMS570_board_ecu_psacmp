/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Data.c
* Module Description: Definition file for data communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * %version:          5 %
 * %derived_by:       tzyksv %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/10/16   1       WH        Initial version based off PSA_BMPV version 11
 * 06/10/16   2       WH        Duplicate of v1
 * 06/22/16   3       WH        Updates for SF99B to include all the new LOA reads                              EA3#9081
 * 03/15/17   4       AR        Updates for Turns counter implementation                                        EA3#14457
 */


#include "Std_Types.h"
#include "CDD_Const.h"
#include "CDD_Data.h"


#define CDDDATA0_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint16,  CDD_DATA_VAR) CDD_DCPhsComp_Cnt_G_u16[3];
VAR(uint16,  CDD_DATA_VAR) CDD_PWMPeriod_Cnt_G_u16;
VAR(uint16,  CDD_DATA_VAR) CDD_MechMtrPos1_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_CommOffset_Cnt_G_u16;
VAR(uint16,  CDD_DATA_VAR) CDD_ADC2OffsetComp_Cnt_G_u8p8;
VAR(uint16,  CDD_DATA_VAR) CDD_ADC2OffsetComp_Cnt_G_u8p8;
VAR(uint16,  CDD_DATA_VAR) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_CorrectedElecMtrPos_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxError_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxMtrPos_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxRevCtr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die1UnderVoltgFltAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxError_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxMtrPos_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxRevCtr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_RxMtrPosParityAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_SysCCorrectedElecMtrPos_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_SysCVSwitchADC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,  CDD_DATA_VAR) CDD_UncorrMechMtrPos1_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA0_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA0_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(float32, CDD_DATA_VAR) CDD_MtrCurr1_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurr2_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(sint32,  CDD_DATA_VAR) CDD_CumMechMtrPos_Rev_G_s15p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_MechMtrPos1TimeStamp_uSec_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_MechMtrPos2TimeStamp_uSec_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurrK1_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurrK2_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurrQaxFinalRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrVoltDax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrVoltQax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA0_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, CDD_DATA_VAR) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */



#define CDDDATA6_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
VAR(sint8,   CDD_DATA_VAR) CDD_MtrElecPol_Cnt_G_s8;
VAR(uint8,   CDD_DATA_VAR) CDD_EnergyModeState_Cnt_G_u08;
VAR(uint8,   CDD_DATA_VAR) CDD_DesiredTuningSet_Cnt_G_u08;
VAR(uint8,   CDD_DATA_VAR) CDD_DemIdSnapshot_Cnt_G_u08;
#define CDDDATA6_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA6_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint32,  CDD_DATA_VAR) CDD_EOLSrlComSvcDft_Cnt_G_b32;
VAR(float32, CDD_DATA_VAR) CDD_DwnldAsstGain_Uls_G_f32;
#define CDDDATA6_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA6_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, CDD_DATA_VAR) CDD_DftAsstTbl_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_ModIdxSrlComSvcDft_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_AVASelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_CAVHCSelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_CityParkSelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_STTdSelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_MultiModeSelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_LXASelected_Cnt_G_lgc;
VAR(boolean, CDD_DATA_VAR) CDD_ESCOffsCfgSeld_Cnt_G_lgc;
#define CDDDATA6_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */



#define CDDDATA9_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint16,  CDD_DATA_VAR) CDD_ePWM4CMPB_Cnt_G_u16;
VAR(uint16,  CDD_DATA_VAR) CDD_CDDDataAccessBfr_Cnt_G_u16;
#define CDDDATA9_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA9_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32,  CDD_DATA_VAR) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA9_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, CDD_DATA_VAR) CDD_MotCurrLoaMtgtnEn_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
VAR(boolean, CDD_DATA_VAR) CDD_IvtrLoaMtgtnEn_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA10_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
VAR(sint8,   CDD_DATA_VAR) CDD_MtrPosPolarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA10_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint16,  CDD_DATA_VAR) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
VAR(uint16,  CDD_DATA_VAR) CDD_MtrCurrOffComOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA10_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(float32, CDD_DATA_VAR) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurr1TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_MtrCurr2TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_DATA_VAR) CDD_SrlComVehSpd_Kph_G_f32;
#define CDDDATA10_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(Rte_ModeType_StaMd_Mode, CDD_DATA_VAR) CDD_SysState_Cnt_G_Enum[D_APPCDDBFRSIZE_CNT_U16];
#define CDDDATA10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


