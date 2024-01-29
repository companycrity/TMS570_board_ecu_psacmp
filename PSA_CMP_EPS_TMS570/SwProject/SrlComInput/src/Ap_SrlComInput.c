/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComInput.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Thu May 17 19:49:17 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          36 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#40
 * 06/12/16    2       WH       Update for msgs 50D, 3CD, 34D and associated NTCs                             EA3#8404
 * 06/13/16    3       WH       Update for msg 3F2 new signal outputs and associated                          EA3#8404
 * 06/14/16    4       WH       Update msg 412 to SCIR 4E (multimode)                                         EA3#8404
 * 06/27/16    5       WH       Update for CF13A inputs                                                       EA3#9195
 * 06/28/16    6       WH       Update EscEna flag                                                            EA3#9195
 * 09/22/16    7       WH       Update problems with multimode and lxa activation flags                       EA3#11121
 * 11/11/16    8       WH       Update enable criteria for 0x158 and 0x159                                    EA3#12451
 * 11/11/16    9       WH       Update consagnlecpk logic                                                     EA3#12451
 * 11/15/16    10       WH       Fix the conditions for updating persselninpvld_lgc                           EA3#12639
 * 11/16/16    11       WH       Updates for SCIR 1B - part 1                                                 EA3#12640
 * 11/16/16    12       WH       Updates for SCIR 1B - update apacmdreq logic                                 EA3#12640
 * 11/29/16    14       WH       Updates for SCIR 1C                                                          EA3#12842
 * 12/01/16    15       WH       AngleVolant Fix                                                              EA3#XXXXX
 * 12/19/16    16       AR       Separate calibration used for IS_DYN_CDS_50D missing condition and 
                                 unused variables / cals are removed                                          EA3#13252
 * 03/09/17    6       AR       Update for SCIR version 2C                                  			      EA3#14168                                 
 * 03/22/17    7       AR       Update for SCIR version 2D                                  			      EA3#14816                                 
 * 04/05/17    8       AR       ESC Data validity and ESC Ack validity flags cleared when 0x5CD goes missing 
                                for more than k_SerlComRxEscOffsTimeout                                       EA3#14816
 * 12/06/17    20       RK      Serial Com refactoring related to CPU Load optimization and MISRA             EA3#18157
 * 12/15/17    21       RK      Changed types of RTE signals after CF13 CF14 and CF24 update                  EA3#18482
 * 12/15/17    22       RK      Fixed logic for signal in msg 0x5CD. Handling of timers was incorrect         EA3#18370
 * 02/09/18	   23       RK      STTd updated on Customer request											  EA3#13267
 * 						MB      0x348 message absent timeout change for EngOn=True->False transition		  EA3#17855
 * 						MB      Unavailable state added for OFFSET. Name changes in SCIR were not implem.	  EA3#18114
 * 03/19/18    24       MB      Changes due to new revisions of CF13 and CF14.                                EA3#19230
 *                                                                                                            EA3#19233
 * 03/21/18    25       RK      CTC Inhibition									                              EA3#13314
 * 03/21/18    26       RK      Removed Node Absent NTCs						                              EA3#19032
 * 								CpkOk signal driven by NTCs						                              EA3#18158
 * 								SrlComInput calibration clean up				                              EA3#19033
 * 								Fixed dead lock problem for DmdDelestDaVld		                              EA3#19030
 * 03/22/18    27       RK      PSA Turns Couter Spec Update V3.1 (CF39)									  EA3#18159
 * 03/22/18    28       RK      Hot fix for NTC status check									  			  EA3#18158
 *																											  EA3#18159
 * 04/12/18    29       RK      Updated logic for LxaInpVld_Cnt_lgc signal									  EA3#19454
 * 								Improved storing procedure of ElecIntegration PIM.							  EA3#18156
 * 								Status of NTC 16D (if known) refreshed cyclically.							  EA3#19497
 * 04/30/18    30       MB      Behavior of LXA and CPK flags updated for case not covered in CFs			  EA3#18231
 *						RK		Vehicle Speed signal Validity flag and synchronization update				  EA3#18110
 * 04/30/18    31       MB      NTC 16d removed from Vehicle Speed signals									  EA3#18110
 * 04/05/18    32       MB      HotFix for Cpk Lxa Mm flags									  				  EA3#18231
 * 05/17/18	   33		MB		SCIR 4C update - validity flags code/spec inconsistency						  EA3#20049
 * 05/17/18	   35		RK		Removed Vehicle Speed Sync signal dedicated to APA	 						  EA3#20115
 * 06/13/18	   36		RK		Clear DTC triggered only if module is outside OFF state	 					  EA3#20284
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


 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComInput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "il_inc.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Dem.h"
#include "Ap_DiagMgr.h"
#include "NtWrap.h"
#include "float.h"

#define D_ISDYNVOLMSGTIMEOUT_MS_U16					11u
#define D_ISDYNABRMSGTIMEOUT_MS_U16					44u
#define D_ISDYNCMMMSGTIMEOUT_MS_U16					44u
#define D_ISDYNAASMSGTIMEOUT_MS_U16					22u
#define D_ISDYNCMM208MSGTIMEOUT_MS_U16				11u
#define D_ISDYN2CMMMSGTIMEOUT_MS_U16				22u
#define D_ISDATBSI3F2MSGTIMEOUT_MS_U16				55u
#define D_ISDATBSI412MSGTIMEOUT_MS_U16				55u
#define D_ISDATBSI432MSGTIMEOUT_MS_U16				55u
#define D_ISDAT4V2BSI552MSGTIMEOUT_MS_U16			1100u
#define D_ISDYNCDS34DMSGTIMEOUT_MS_U16				22u
#define D_ISDATABR50DMSGTIMEOUT_MS_U16				110u
#define D_ISDYN2FRE3CDMSGTIMEOUT_MS_U16				11u
#define D_TESTFAILED_CNT_U08						0u
#define D_TESTPASSED_CNT_U08						1u
#define D_TESTDEADBAND_CNT_U08						2u
#define D_ANGLEVOLANTSCALE_HWDEGPCNT_F32			0.1f
#define D_ANGLEVOLANTPOL_CNT_F32					(-1.0f)
#define D_OFFSETPOL_CNT_F32							(-1.0f)
#define D_ANGLEVOLANTVALIDHI_CNT_S16				7800
#define D_ANGLEVOLANTVALIDLO_CNT_S16				(-7800)
#define D_VEHSPDSCALE_CNT_F32						0.01f
#define D_CONSANGLECPKSCALE_CNT_F32					0.1f
#define D_CONSANGLECPKPOL_CNT_F32					(-1.0f)
#define D_COLANGLESETPOINTPOL_CNT_F32				(-1.0f)
#define D_COLUMNANGLESETPOINTSCALE_CNT_U16			0.1f
#define D_CONSANGLECPKVALIDHI_CNT_S16				7800
#define D_CONSANGLECPKVALIDLO_CNT_S16				(-7800)
#define D_ELECINTCONSECMSGS_CNT_U08					2u
#define D_ELECINTCONSECTIMEOUT_MS_U16				1000u
#define D_COMPUTERRAZGCTINVALID_CNT_U08				0xFFu
#define D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32   0xFFFFFFFFul
#define D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32 10ul
#define D_ANNEEECOULEINVALID_CNT_U08				0xFFu
#define D_JOURECOULEINVALID_CNT_U16					0x0FFFu
#define D_SECONDEECOULEEINVALID_CNT_U32				0x000FFFFFul
#define D_SECONDSPERYEAR_CNT_U32					31536000ul
#define D_SECONDSPERDAY_CNT_U32						86400ul
#define D_ACCELLATVALIDHI_CNT_S16					300
#define D_ACCELLATVALIDLO_CNT_S16					(-300)
#define D_ACCELLATSCALE_CNT_f32						0.05f
#define D_COLANGLESETPOINTVALIDLO_CNT_U16			0x1E78u
#define D_COLANGLESETPOINTVALIDHI_CNT_U16			0x2188u
#define D_LKATRQFACTREQVALIDMAX_CNT_U16				0x64u
#define D_LKATRQFACTSCALE_CNT_F32					(0.01f)
#define D_LKATRQFACREQUNAVAILABLE_CNT_U16			0x7Eu
#define D_LKATRQFACREQINVALID_CNT_U16				0x7Fu
#define D_PROTOHS1DYNUCF5CDMSGTIMEOUT_MS_U16		1100U
#define D_OFFSETSCALE_CNT_F32  						(0.1F)
#define D_OFFSETLOLIM_CNT_F32  						(-1630.0F)
#define D_OFFSETHILIM_CNT_F32  						(1630.0F)
#define D_ISDATBSI572MSGTIMEOUT_MS_U16				110u
#define D_ENGONTIMEOUT_MS_U08						80u
#define D_NTC_TEST_COMPLETED_MASK                   (D_TESTFAILEDBIT_CNT_B8 | D_TESTNOTCOMPLETETHISOPCYCLEBIT_CNT_B8)
#define D_NTC_TEST_COMPLETED_PASSED                 0u
#define D_NTC_TEST_COMPLETED_FAILED                 D_TESTFAILEDBIT_CNT_B8
#define D_ESCPRECISIONFROMSERLCOM_INIT_VALUE		(29.0F)

#define IncToThresh(Counter, Thresh)	( ((Counter) < (Thresh)) ? ((Counter) + 1u) : (Counter) ) /* PRQA S 3453 */

#define SRLCOMINPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) VehicleSpeed_Kph_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) SystemTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI3F2MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI412MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI432MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYN2CMMMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNAASMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNABRMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNCMM208MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNCMM388MsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNVOLMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATABR50DMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYN2FRE3CDMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNCDS34DMsgRxTime_MSec_M_u32;

STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATDIRAMsgTxTime_MSec_M_u32; /* PRQA S 3218 */

STATIC VAR(float32, AP_SRLCOMINPUT_VAR) SrlComVehSpd_Kph_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) CONSANGLECPK_HwDeg_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) AngleVolant_HwDeg_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) IgnTimeOff_Sec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ElecIntTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) EffacDefaultDiagTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) ManVehSpd_Kph_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) IgnOnTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNVOLMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNAASMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNABRMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNCDS34DMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATABR50DMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYN2FRE3CDMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI412MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI432MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATDIRASentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) EngOnAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DmdDelestDATimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ComputerRazGCTSigInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DateInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DiagMuxOnAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CityParkInputMsgTimer_mS_M_u32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) AccelLat_MpSecSq_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) ColumnAngleSetpoint_HwDeg_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) LxATqFacReq_Uls_M_f32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevPROTOHS1DYNUCF5CDMsgRxTime_MSec_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI572MsgRxTime_MSec_M_u32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) EscOffsFromSerlCom_HwDeg_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) EscPrecisionFromSerlCom_HwDeg_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI572MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DmdDelestDaStsTime_MSec_M_u32;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATDIRASentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATABR50DMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCDS34DMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATABR50DMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCDS34DMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATABR50DMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2FRE3CDMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) EtatMTSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) EtatMTSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CONSANGLECPKSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CONSANGLECPKSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDFCTCPKSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRelaxeConsistentCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDFCTCPKSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRELAXECPKSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRELAXECPKSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVRampValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVRampInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehiculeRouesSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ANGLEVOLANTSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ANGLEVOLANTSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VITESSEROTVOLANTSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CompteurTemporelVehiculeSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ComputerRazGCTSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DateValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AccelLatValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AccelLatInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AccelLatValidityCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AccelLatInvalidityCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLChkSumInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLChkSumValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASChkSumInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASChkSumValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRChkSumInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRChkSumValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCountInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCountValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCountInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCountValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCountInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCountValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CityParkInputConsistentCount_Cnt_M_u16;
STATIC VAR(sint16, AP_SRLCOMINPUT_VAR) CONSANGLECPK_Cnt_M_s16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) LKATrqFactReqInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) LKAStateInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) LKATrqFactReqValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) LKAStateValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ColumnAngleSetpointValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ColumnAngleSetpointInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) MultimodeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) MultimodeInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetDataConsistentCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetDataInconsistentCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PrecisionOffsetSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgChkSumInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgCountInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) OffsetSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) PrecisionOffsetSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) Offset_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI572MsgTimeValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI572MsgLenValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI572MsgLenInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ConfigVhlSigValidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ConfigVhlSigInvalidCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ConfigVhlSigUpdCount_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DmdDelestDASigUpdCount_Cnt_M_u16;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) EtatMT_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) SystemState_Cnt_M_enum;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) LKAState_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI3F2MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI412MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI432MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYN2CMMMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNAASMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNABRMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNCMM208MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNCMM388MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNVOLMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYN2FRE3CDMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNCDS34DMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATABR50DMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevEtatMT_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) CountEtatMT_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DMDFCTCPK_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DMDRELAXECPK_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDiagIntegraElec_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevModeDiag_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ElecIntCount_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) EffacDefaultDiagCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) VVHTYPE1Count_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) VVHTYPE2Count_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ValidEngineStatusCount_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) EngOnDLCInvalidCount_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDMDFCTCPK_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDMDRELAXECPK_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) MultimodeSwReq_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ReqModeDAChangedState_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) MultimodeSwReqChangedStateCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevConfigVhl_Cnt_M_u08;
STATIC VAR(EnergyModeStateType, AP_SRLCOMINPUT_VAR) EnergyModeState_Cnt_M_enum;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevPROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PROTOHS1DYNUCF5CDMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI572MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrecisionOffset_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DmdDelestDA_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DmdDelestDaSts_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDmdDelestDA_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(Std_ReturnType, AP_SRLCOMINPUT_VAR) ElectronicIntegrationWriteSucceeded_Cnt_M_lgc;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CTermActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) EpsEn_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) RxMsgsSrlComSvcDft_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CAVHCSelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ESCOffsCfgSeld_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) AccelLatValidity_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) MultimodeVld_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ResetTimers_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) DiagOn_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) NetOn_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BattOk_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) EngOn_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) PrevVitesseVehicleBVValid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ClearDTCs_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) MultimodeSelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) STTdSelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) LXASelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CityParkSelected_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ElectronicIntegrationCmd_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CPKOK_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehSpdControl_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg348Valid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg432Valid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg552Valid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) StartupTimeCalculated_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehTimeValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehSpdSync_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) APARequest_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehicleSpeedValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ApaVehicleSpeedValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ApaRelaxReq_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) AcqInterruptDae_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) EscDataVldFromSerlCom_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ReqModeDAStateChanged_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) DmdDelestDaVld_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ReInitializeComponent_M_lgc;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ReInit(void);

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetCpkOk(void);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_EscAckAndDataValid(CONSTP2VAR(boolean, AUTOMATIC, AP_SRLCOMINPUT_CONST) EscAck_Cnt_T_lgc, CONSTP2VAR(boolean, AUTOMATIC, AP_SRLCOMINPUT_CONST) EscDataVld_Cnt_T_lgc);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MissingMessageNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ValidityNTCProcessing(	VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
																P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																P2VAR(uint16, AUTOMATIC, AUTOMATIC) InvalidCount_Cnt_T_u16,
																VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																VAR(uint16, AUTOMATIC) InvalidThresh_Cnt_T_u16,
																VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MixedTimeValidityNTCProcessing(	VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
																		VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																		VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																		P2VAR(uint32, AUTOMATIC, AUTOMATIC) SigTimer_mS_T_u32,
																		P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																		VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																		VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																		VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ResetFltAcc(	P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
													VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
													VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) GetLXANTCsStatus ( void );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetMultimodeNTCsStatus ( void );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetVehicleLatAccelNTCsStatus ( void );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetSCommAngleValidNTCsStatus ( void );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetValidEngineStatus ( void );

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetNetOn(	VAR(boolean, AUTOMATIC) NetOn_Cnt_T_lgc,
																VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc);

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetBattOk(VAR(boolean, AUTOMATIC) BattOk_Cnt_T_lgc,
																VAR(float32, AUTOMATIC) Batt_Volt_T_f32);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDat4V2Bsi_552(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatAbr_50D(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_3F2(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_412(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_432(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_572(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDyn2Cmm_348(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDyn2Fre_3CD(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynAas_2EB(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynAbr_38D(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCds_34D(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCmm_208(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCmm_388(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynVol_305(void);
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgProtoHs1DynUcf_5CD(void);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetTimers(void);

STATIC FUNC(uint8, AP_SRLCOMINPUT_CODE) SrlComInput_CalculateCheckSum(	CONSTP2CONST(CanMsgType, AUTOMATIC, AUTOMATIC) buffer,
																		VAR(uint8, AUTOMATIC) seed);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_UpdateVVHType( VAR(uint8, AUTOMATIC) VVHType_Cnt_T_u08);

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
 * IoHwAb_BoolType: Integer in interval [0...1]
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
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
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
 *   NTC_Num_PLLSlipNrcvrl (22U)
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
 *   NTC_Num_PeripheralStartupFlt (55U)
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
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90U)
 *   NTC_Num_SysVltgCorrlnFlt (91U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_EcuIdnFlt (95U)
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
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_IMCLossOfCom (125U)
 *   NTC_Num_ImcArbrFault (127U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_TurnCntr_SpiDataFlt (135U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_EcuCrossChk (150U)
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151U)
 *   NTC_Num_EcuConfigMismatch (152U)
 *   NTC_Num_MotBasdHwAgFlt (153U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
 *   NTC_Num_AgCompDiagc (167U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
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
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
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
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
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
 *   NTC_Num_DataOtherFlt2Msg_Q (327U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
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
 *   NTC_Num_DSTXORActive (399U)
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
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AM (482U)
 *   NTC_Num_InvalidMsg_AM (483U)
 *   NTC_Num_CRCFltMsg_AM (484U)
 *   NTC_Num_PgrsCntFltMsg_AM (485U)
 *   NTC_Num_DataRngFltMsg_AM (486U)
 *   NTC_Num_InvalidMsg_AL (488U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_DataRngFltMsg_AL (492U)
 *   NTC_Num_DataOtherFltMsg_AL (494U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_PHAScratchPadTrf (503U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
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
 * PsaLxaSt_Cnt_enum: Enumeration of integer in interval [0...6] with enumerators
 *   PSALXAST_UNAVL (0U)
 *   PSALXAST_UNSELD (1U)
 *   PSALXAST_SELD (2U)
 *   PSALXAST_AUTHD (3U)
 *   PSALXAST_ACTV (4U)
 *   PSALXAST_DFCT (5U)
 *   PSALXAST_COLLRISK (6U)
 * PsaTunModSt_Cnt_enum: Enumeration of integer in interval [0...3] with enumerators
 *   PSATUNMODST_NORM (0U)
 *   PSATUNMODST_SPORT (1U)
 *   PSATUNMODST_TUN (2U)
 *   PSATUNMODST_FAILD (3U)
 *
 * Array Types:
 * ============
 * CanMsgType: Array with 8 element(s) of type UInt8
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * ShutdownTimeType: Record with elements
 *   Time_Sec_u32 of type UInt32
 *   Valid_Cnt_lgc of type Boolean
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
 * PsaLxaSt_Cnt_enum: D_PSALXASTINIT_CNT_ENUM = 0U
 * PsaTunModSt_Cnt_enum: D_PSATUNMODSTINIT_CNT_ENUM = 0U
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt8 *Rte_Pim_VVHTYPEData(void)
 *   Boolean *Rte_Pim_ElecIntData(void)
 *   ShutdownTimeType *Rte_Pim_ShutdownTimeData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
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
 *   Boolean Rte_IRead_SrlComInput_Init_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_MultimodeSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_SrlComInput_Init_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Init_LxaInpVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_LxaInpVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_MultiModeVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_MultiModeVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Init_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Init_SrlComVehSpd_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Init
 *********************************************************************************************************************/

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */


	EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
	PrevEtatMT_Cnt_M_u08 = (uint8)kETAT_MT_Cut;
	ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;

	ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);

	ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCDS34DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATABR50DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2FRE3CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DmdDelestDATimer_mS_M_u32 = SystemTime_mS_M_u32;
	CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DateInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
	CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI572MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	IgnOnTimer_mS_M_u32 = SystemTime_mS_M_u32;
	BattOk_Cnt_M_lgc = TRUE;
	EscOffsFromSerlCom_HwDeg_M_f32 = 0.0F;
	EscPrecisionFromSerlCom_HwDeg_M_f32 = D_ESCPRECISIONFROMSERLCOM_INIT_VALUE;
	CPKOK_Cnt_M_lgc = TRUE;
	AcqInterruptDae_Cnt_M_lgc = FALSE;
	EscDataVldFromSerlCom_Cnt_M_lgc = FALSE;
	DmdDelestDaSts_Cnt_M_u08 = (uint8)kDMD_DELEST_DA_Not_Requested;
	DmdDelestDaVld_Cnt_M_lgc = FALSE;
	DmdDelestDaStsTime_MSec_M_u32 = SystemTime_mS_M_u32;
	MultimodeVld_Cnt_M_lgc = TRUE;
	AngleVolant_HwDeg_M_f32 = 0.0F;
	
	/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
	* They cannot interrupt each other. Also access to it is atomic */
	ElectronicIntegrationCmd_Cnt_M_lgc = *Rte_Pim_ElecIntData();
	LXASelected_Cnt_M_lgc = CDD_LXASelected_Cnt_G_lgc;              /* Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc();       */
	STTdSelected_Cnt_M_lgc = CDD_STTdSelected_Cnt_G_lgc;            /* Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc();      */
	MultimodeSelected_Cnt_M_lgc = CDD_MultiModeSelected_Cnt_G_lgc;  /* Rte_IRead_SrlComInput_Init_MultimodeSelected_Cnt_lgc(); */
	ESCOffsCfgSeld_Cnt_M_lgc = CDD_ESCOffsCfgSeld_Cnt_G_lgc;        /* Rte_IRead_SrlComInput_Init_ESCOffsCfgSeld_Cnt_lgc();    */
	CAVHCSelected_Cnt_M_lgc = CDD_CAVHCSelected_Cnt_G_lgc;          /* Rte_IRead_SrlComInput_Init_CAVHCSelected_Cnt_lgc();     */
	CityParkSelected_Cnt_M_lgc = CDD_CityParkSelected_Cnt_G_lgc;    /* Rte_IRead_SrlComInput_Init_CityParkSelected_Cnt_lgc();  */

	SrlComInput_UpdateVVHType(*Rte_Pim_VVHTYPEData());

	/*NTC 164, 165, 166, 138 and 139 configuration based status*/
	if (FALSE == k_JDD2010Selected_Cnt_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0u, NTC_STATUS_PASSED);	/* 0x138 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0u, NTC_STATUS_PASSED);	/* 0x139 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x164 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x165 */
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x166 */
	}

	/*NTC 146 configuration based status*/
	if (FALSE == STTdSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x146 */
	}

	/*NTC 140,141 configuration based status*/
	if ( (FALSE == LXASelected_Cnt_M_lgc) && (FALSE == STTdSelected_Cnt_M_lgc) )
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x140 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x141 */
	}

	/*NTC 178, 179, 170, 171, 144, 145, 147 configuration based status */
	if (FALSE == LXASelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x144 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x145 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_Q, 0u, NTC_STATUS_PASSED); /* 0x147 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0u, NTC_STATUS_PASSED);	/* 0x170 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_W, 0u, NTC_STATUS_PASSED);	/* 0x171 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0u, NTC_STATUS_PASSED);	/* 0x178 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X, 0u, NTC_STATUS_PASSED);	/* 0x179 */
	}

	/*NTC 158, 159 and 15C configuration based status */
	if (FALSE == MultimodeSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0u, NTC_STATUS_PASSED);	 /* 0x158 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_T, 0u, NTC_STATUS_PASSED);	 /* 0x159 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_T, 0u, NTC_STATUS_PASSED); /* 0x15C */
	}

	if(TRUE == ESCOffsCfgSeld_Cnt_M_lgc)
	{
		EnergyModeState_Cnt_M_enum = NORMAL; /*  0 */
	}
	else
	{
		EnergyModeState_Cnt_M_enum = TRANSPORTATION; /*  2 */

		/* During init, if ESCOffsetCfg is NOT selected, all enabled NTCs between  180 and  18E,
		inclusive, shall be cleared.*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Y, 0u, NTC_STATUS_PASSED);	/* 0x180 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Y, 0u, NTC_STATUS_PASSED);	/* 0x181 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Y, 0u, NTC_STATUS_PASSED);/* 0x184 */

		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x188 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x189 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18A */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18B */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18C */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18D */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18E */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0u, NTC_STATUS_PASSED);	/* 0x18F */
	}

	if (FALSE == CAVHCSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_S, 0u, NTC_STATUS_PASSED);  /* NTC 0x150 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x151 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x152 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x153 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x154 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_S, 0u, NTC_STATUS_PASSED);  /* NTC 0x155 */
	}

	if (FALSE == CityParkSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x148 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x149 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14A */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14B */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14C */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14D */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14E */
	}

	ElectronicIntegrationWriteSucceeded_Cnt_M_lgc = E_OK;

	/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
	* They cannot interrupt eachother. Aslo access to it is atomic */
	Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(*Rte_Pim_ElecIntData());
	Rte_IWrite_SrlComInput_Init_EnergyModeState_Cnt_enum(EnergyModeState_Cnt_M_enum);
	SrlComVehSpd_Kph_M_f32 = k_VehSpdInit_Kph_f32;
	Rte_IWrite_SrlComInput_Init_SrlComVehSpd_Kph_f32(SrlComVehSpd_Kph_M_f32);	/* Init value of the signal can't be calibrable, this is best we can do */
	/* Workaround to not change R port in CF component */
	Rte_IWrite_SrlComInput_Init_CPKOK_Cnt_lgc(CPKOK_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Init_LxaInpVld_Cnt_lgc(TRUE);
	Rte_IWrite_SrlComInput_Init_MultiModeVld_Cnt_lgc(MultimodeVld_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Init_EscPrecisionFromSerlCom_HwDeg_f32(EscPrecisionFromSerlCom_HwDeg_M_f32);
	ApaVehicleSpeedValid_Cnt_M_lgc = TRUE;
	Rte_IWrite_SrlComInput_Init_ApaVehicleSpeedValid_Cnt_lgc(ApaVehicleSpeedValid_Cnt_M_lgc);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDat4V2Bsi_552
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDAT4V2BSI552MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_KilometrageIn_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaShutdownTimeData(void)
 *   void Rte_Exit_EaShutdownTimeData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDat4V2Bsi_552(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDat4V2Bsi_552
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ISDAT4V2BSI552MsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) EEPROMCloseFailed_Cnt_T_lgc;
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) StartupTime_Sec_T_u32;
	VAR(uint16,  AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint32,  AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) Kilometrage_Cnt_T_u32;

	(void)Rte_Read_ISDAT4V2BSI552MsgDLCError_Cnt_u08(&ISDAT4V2BSI552MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_AnneeEcoule_Cnt_u08(&AnneeEcoule_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_EEPROMCloseFailed, &EEPROMCloseFailed_Cnt_T_lgc);
	(void)Rte_Read_CompteurTemporelVehicule_Cnt_u32(&CompteurTemporelVehicule_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_JourEcoule_Cnt_u16(&JourEcoule_Cnt_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_SecondeEcoulee_Cnt_u32(&SecondeEcoulee_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(&PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_KilometrageIn_Cnt_u32(&Kilometrage_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	/* Kept old behavior (signal taken from Driver, doesn't matter if received or not) */
	Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_Kilometrage_Cnt_u32(Kilometrage_Cnt_T_u32);
	/* Kept old behavior (signal taken from Driver, doesn't matter if received or not) */
	Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32);
	Rte_IWrite_SrlComInput_MsgIsDat4V2Bsi_552_CompteurTemporelVehiculeRaw_Cnt_u32(CompteurTemporelVehicule_Cnt_T_u32);

	if( ISDAT4V2BSI552MsgDLCError_Cnt_T_u08 == PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08 )
	{
		/* No need to uses Exclusive Area cause provider of data operates in lower priority task and uses EA */
		/* Rte_Enter_EaShutdownTimeData(); */

		if( (StartupTimeCalculated_Cnt_M_lgc == FALSE) &&
			(EEPROMCloseFailed_Cnt_T_lgc == FALSE) &&
			((Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc == TRUE) &&
			(Msg552Valid_Cnt_M_lgc == TRUE) )
		{
			if( k_JDD2010Selected_Cnt_lgc == TRUE )
			{
				if( CompteurTemporelVehicule_Cnt_T_u32 != D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32 )
				{
					StartupTime_Sec_T_u32 = CompteurTemporelVehicule_Cnt_T_u32 / D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32;

					StartupTimeCalculated_Cnt_M_lgc = TRUE;
				}
			}
			else
			{
				if( (AnneeEcoule_Cnt_T_u08 != D_ANNEEECOULEINVALID_CNT_U08) &&
					(JourEcoule_Cnt_T_u16 != D_JOURECOULEINVALID_CNT_U16) &&
					(SecondeEcoulee_Cnt_T_u32 != D_SECONDEECOULEEINVALID_CNT_U32) )
				{
					StartupTime_Sec_T_u32 = (((uint32)AnneeEcoule_Cnt_T_u08) * D_SECONDSPERYEAR_CNT_U32) +
											(((uint32)JourEcoule_Cnt_T_u16) * D_SECONDSPERDAY_CNT_U32) +
											SecondeEcoulee_Cnt_T_u32;

					StartupTimeCalculated_Cnt_M_lgc = TRUE;
				}
			}

			if( (StartupTimeCalculated_Cnt_M_lgc == TRUE) &&
				(StartupTime_Sec_T_u32 > (Rte_Pim_ShutdownTimeData())->Time_Sec_u32) )
			{
				IgnTimeOff_Sec_M_u32 = StartupTime_Sec_T_u32 - (Rte_Pim_ShutdownTimeData())->Time_Sec_u32;
				VehTimeValid_Cnt_M_lgc = TRUE;
			}
		}

		/* No need to uses Exclusive Area cause provider of data operates in lower priority task and uses EA */
		/* Rte_Exit_EaShutdownTimeData(); */

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;

		Msg552Valid_Cnt_M_lgc = TRUE;

	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08 = ISDAT4V2BSI552MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDat4V2Bsi_552();
		Msg552Valid_Cnt_M_lgc = FALSE;
	}

	/* NTC 160 - Invalid Message (too short) (Msg ID 552) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16,
						  &ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDAT4V2BSI552MsgLenValidThresh_Cnt_u16,
						  k_ISDAT4V2BSI552MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatAbr_50D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATABR50DMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatAbr_50D(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDatAbr_50D
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDATABR50DMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(&PrevISDATABR50DMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATABR50DMsgDLCError_Cnt_u08(&ISDATABR50DMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */

	if (PrevISDATABR50DMsgDLCError_Cnt_M_u08 == ISDATABR50DMsgDLCError_Cnt_T_u08)
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDATABR50DMsgDLCError_Cnt_M_u08 = ISDATABR50DMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDatAbr_50D();
	}

	/* NTC 178 - Invalid Message (too short) (Msg ID 50D) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDATABR50DMsgLenValidCount_Cnt_M_u16,
						  &ISDATABR50DMsgLenInvalidCount_Cnt_M_u16,
						  k_ISDATABR50DMsgLenValidThresh_Cnt_u16,
						  k_ISDATABR50DMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_X);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_3F2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI3F2MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ColumnAngleSetpoint_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_LKAState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_LKATrqFactReq_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_LXAActivation_Cnt_u08(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_3F2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDatBsi_3F2
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDATBSI3F2MsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) LKATrqFactReq_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) ColumnAngleSetpoint_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) LKAState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DataOtherFltMsgQ_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) LXAActivation_Cnt_T_u08;

	(void)Rte_Read_LKATrqFactReq_Cnt_u08(&LKATrqFactReq_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI3F2MsgDLCError_Cnt_u08(&ISDATBSI3F2MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ColumnAngleSetpoint_Cnt_u16(&ColumnAngleSetpoint_Cnt_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_LKAState_Cnt_u08(&LKAState_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(&PrevISDATBSI3F2MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_LXAActivation_Cnt_u08(&LXAActivation_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	/* Kept old behavior (signal taken from Driver, doesn't matter if received or not) */
	Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaSeln_Cnt_lgc((boolean)LXAActivation_Cnt_T_u08);

	if( ISDATBSI3F2MsgDLCError_Cnt_T_u08 == PrevISDATBSI3F2MsgDLCError_Cnt_M_u08 )
	{
	    if (TRUE == LXASelected_Cnt_M_lgc)
	    {
			if ( ( LKATrqFactReq_Cnt_T_u08 <= D_LKATRQFACTREQVALIDMAX_CNT_U16 ) ||
			     ( LKATrqFactReq_Cnt_T_u08 == D_LKATRQFACREQUNAVAILABLE_CNT_U16 ) )
			{
				LKATrqFactReqValidCount_Cnt_M_u16 = IncToThresh(LKATrqFactReqValidCount_Cnt_M_u16,
																k_LKATrqFactReqValidThresh_Cnt_u16);
				LKATrqFactReqInvalidCount_Cnt_M_u16 = 0u;

				if ( D_LKATRQFACREQUNAVAILABLE_CNT_U16 != LKATrqFactReq_Cnt_T_u08 )
				{
				    LxATqFacReq_Uls_M_f32 = (float32)LKATrqFactReq_Cnt_T_u08 * D_LKATRQFACTSCALE_CNT_F32;
				}
				else
				{
				    LxATqFacReq_Uls_M_f32 = 0.0f;
				}
			}
			else
			{
				LKATrqFactReqInvalidCount_Cnt_M_u16 = IncToThresh(LKATrqFactReqInvalidCount_Cnt_M_u16,
																  k_LKATrqFactReqInvalidThresh_Cnt_u16);
				LKATrqFactReqValidCount_Cnt_M_u16 = 0u;
			
				LxATqFacReq_Uls_M_f32 = 0.0f;
			}

            if ( (uint8)kLKA_STATE_Reserved == LKAState_Cnt_T_u08 )
            {
                LKAStateInvalidCount_Cnt_M_u16 = IncToThresh(LKAStateInvalidCount_Cnt_M_u16,
                                                             k_LKAStateInvalidThresh_Cnt_u16);
                LKAStateValidCount_Cnt_M_u16 = 0u;
            }
            else
            {
                LKAState_Cnt_M_u08 =  LKAState_Cnt_T_u08;

                LKAStateValidCount_Cnt_M_u16 = IncToThresh(LKAStateValidCount_Cnt_M_u16,
                                                            k_LKAStateValidThresh_Cnt_u16);
                LKAStateInvalidCount_Cnt_M_u16 = 0u;
            }

            if ( (ColumnAngleSetpoint_Cnt_T_u16 < D_COLANGLESETPOINTVALIDHI_CNT_U16) &&
                 (ColumnAngleSetpoint_Cnt_T_u16 > D_COLANGLESETPOINTVALIDLO_CNT_U16) )
            {
                ColumnAngleSetpointInvalidCount_Cnt_M_u16 = IncToThresh(ColumnAngleSetpointInvalidCount_Cnt_M_u16,
                                                                        k_ColumnAngleSetpointInvalidThresh_Cnt_u16);
                ColumnAngleSetpointValidCount_Cnt_M_u16 = 0u;
            }
            else
            {
                ColumnAngleSetpointValidCount_Cnt_M_u16 = IncToThresh(ColumnAngleSetpointValidCount_Cnt_M_u16,
                                                                      k_ColumnAngleSetpointValidThresh_Cnt_u16);
                ColumnAngleSetpointInvalidCount_Cnt_M_u16 = 0u;

                if (ColumnAngleSetpoint_Cnt_T_u16 < 0x2000u )
                {
                    ColumnAngleSetpoint_HwDeg_M_f32 = (float32)(ColumnAngleSetpoint_Cnt_T_u16);
                }
                else
                {
                    ColumnAngleSetpoint_Cnt_T_u16 = ((ColumnAngleSetpoint_Cnt_T_u16) | 0xC000u); /* Intentional casting of s13 to s16 variable */
                    ColumnAngleSetpoint_HwDeg_M_f32 = (float32)((sint16)ColumnAngleSetpoint_Cnt_T_u16); /* PRQA S 2856 */ /* Look above. This is intentional casting s13 kept in u16 */
                }
                ColumnAngleSetpoint_HwDeg_M_f32 = D_COLANGLESETPOINTPOL_CNT_F32 *
                                                  ColumnAngleSetpoint_HwDeg_M_f32 *
                                                  D_COLUMNANGLESETPOINTSCALE_CNT_U16;

                ColumnAngleSetpoint_HwDeg_M_f32 = Limit_m(ColumnAngleSetpoint_HwDeg_M_f32,
                                                          -k_ColumnAngleSetpointLimit_HwDeg_f32,
                                                          k_ColumnAngleSetpointLimit_HwDeg_f32);

            }
	    }

        if (TRUE == STTdSelected_Cnt_M_lgc)
        {
            if (PrevDmdDelestDA_Cnt_M_u08 == DmdDelestDA_Cnt_M_u08)
            {
                DmdDelestDASigUpdCount_Cnt_M_u16 = IncToThresh(DmdDelestDASigUpdCount_Cnt_M_u16, k_DmdDelestDaValidThresh_Uls_u16);
            }
            else
            {
                DmdDelestDASigUpdCount_Cnt_M_u16 = 1u;
                PrevDmdDelestDA_Cnt_M_u08 = DmdDelestDA_Cnt_M_u08;
            }

			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DmdDelestDaStsTime_MSec_M_u32);

			if (DmdDelestDASigUpdCount_Cnt_M_u16 >= k_DmdDelestDaValidThresh_Uls_u16)
            {
                DmdDelestDaSts_Cnt_M_u08 = DmdDelestDA_Cnt_M_u08;

                (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_Q, &DataOtherFltMsgQ_Cnt_T_lgc);
                if (FALSE == DataOtherFltMsgQ_Cnt_T_lgc)
                {
                    DmdDelestDaVld_Cnt_M_lgc = TRUE;
                }
            }
        }

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDATBSI3F2MsgDLCError_Cnt_M_u08 = ISDATBSI3F2MsgDLCError_Cnt_T_u08;
		DmdDelestDASigUpdCount_Cnt_M_u16 = 0u;

		SrlComInput_ResetMsgIsDatBsi_3F2();
		LKAStateValidCount_Cnt_M_u16 = 0u;
	}


	if (TRUE == LXASelected_Cnt_M_lgc)
	{
		/* NTC 147 - Column Angle Setpoint Invalid */
		if(ColumnAngleSetpointInvalidCount_Cnt_M_u16 >= k_ColumnAngleSetpointInvalidThresh_Cnt_u16)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_Q, 0u, NTC_STATUS_FAILED);
		}
		else
		{
			if(ColumnAngleSetpointValidCount_Cnt_M_u16 >= k_ColumnAngleSetpointValidThresh_Cnt_u16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_Q, 0u, NTC_STATUS_PASSED);
			}
		}

		/* NTC 144 - LKA Trq request invalid */
		if(LKATrqFactReqInvalidCount_Cnt_M_u16 >= k_LKATrqFactReqInvalidThresh_Cnt_u16)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Q, 0u, NTC_STATUS_FAILED);
		}
		else
		{
			if(LKATrqFactReqValidCount_Cnt_M_u16 >= k_LKATrqFactReqValidThresh_Cnt_u16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Q, 0u, NTC_STATUS_PASSED);
			}
		}

		/* NTC 145 - LKA state reserved */
		if(LKAStateInvalidCount_Cnt_M_u16 >= k_LKAStateInvalidThresh_Cnt_u16)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Q, 0u, NTC_STATUS_FAILED);
		}
		else
		{
			if(LKAStateValidCount_Cnt_M_u16 >= k_LKAStateValidThresh_Cnt_u16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Q, 0u, NTC_STATUS_PASSED);
			}
		}
	}

	/* NTC 140 - IS_DAT_BSI_3F2 Invalid Message (too short) (Msg ID 3F2) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDATBSI3F2MsgLenValidCount_Cnt_M_u16,
						  &ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDATBSI3F2MsgLenValidThresh_Cnt_u16,
						  k_ISDATBSI3F2MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_Q);
						  
	Rte_IWrite_SrlComInput_MsgIsDatBsi_3F2_LxaTqFacReq_Uls_f32(LxATqFacReq_Uls_M_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_412
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI412MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ReqModeDA_Cnt_u08(UInt8 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_412(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDatBsi_412
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDATBSI412MsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) MultimodeVldTestStatus_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ReqModeDA_Cnt_T_u08;

	(void)Rte_Read_ISDATBSI412MsgDLCError_Cnt_u08(&ISDATBSI412MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ReqModeDA_Cnt_u08(&ReqModeDA_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(&PrevISDATBSI412MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDATBSI412MsgDLCError_Cnt_T_u08 == PrevISDATBSI412MsgDLCError_Cnt_M_u08 )
	{
		if (ReqModeDA_Cnt_T_u08 < (uint8)kReq_Mode_DA_Reserved)
		{
			/* When REQ_MODE_DA changes state, MultiModSwt_Cnt_u08 shall retain the previous value
			   until REQ_MODE_DA has maintained the new state for 3 consecutive frames */
			if(MultimodeSwReq_Cnt_M_u08 != ReqModeDA_Cnt_T_u08)
			{
				/* First time ReqModeDA state changed */
				if(ReqModeDAStateChanged_Cnt_M_lgc == FALSE)
				{
					ReqModeDAChangedState_Cnt_M_u08 = ReqModeDA_Cnt_T_u08;
					ReqModeDAStateChanged_Cnt_M_lgc = TRUE;
					MultimodeSwReqChangedStateCount_Cnt_M_u08 = 1u;
				}
				else
				{
					/* Check if ReqModeDA State still maintained */
					if(ReqModeDAChangedState_Cnt_M_u08 == ReqModeDA_Cnt_T_u08)
					{
						MultimodeSwReqChangedStateCount_Cnt_M_u08++;
					}
					else
					{
						/* Consecutive messages are not having same state. Clear the flag */
						ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
					}

				}
				/* REQ_MODE_DA has maintained the new state for 3 consecutive frames*/
				if(( MultimodeSwReqChangedStateCount_Cnt_M_u08 >= 3u) && (ReqModeDAStateChanged_Cnt_M_lgc == TRUE))
				{
					MultimodeSwReq_Cnt_M_u08 = ReqModeDA_Cnt_T_u08;
					ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
					MultimodeSwReqChangedStateCount_Cnt_M_u08 = 0u;
				}
				else
				{
					/* Nothing to do. Wait until threshold reached */
				}
			}
			else
			{
				/* ReqModeDA didn't change. Continue to use previous value */
				ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
			}

			MultimodeVldTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		else
		{
			MultimodeVldTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
		}

		ValidityNTCProcessing(MultimodeVldTestStatus_Cnt_T_u08,
							  &MultimodeValidCount_Cnt_M_u16,
							  &MultimodeInvalidCount_Cnt_M_u16,
							  k_MultimodeValidCountThresh_Cnt_u16,
							  k_MultimodeInvalidCountThresh_Cnt_u16,
							  NTC_Num_DataRngFltMsg_T);

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDATBSI412MsgDLCError_Cnt_M_u08 = ISDATBSI412MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDatBsi_412();
		MultimodeValidCount_Cnt_M_u16 = 0u;
		ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
	}

	/* NTC 158 - IS_DAT_BSI_412 Invalid Message (too short) (Msg ID 412) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDATBSI412MsgLenValidCount_Cnt_M_u16,
						  &ISDATBSI412MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDATBSI412MsgLenValidThresh_Cnt_u16,
						  k_ISDATBSI412MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_T);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_432
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI432MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EtatPrincipSevIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatReseauElecIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_PowerSuppliesIn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ShuntPositionIn_Cnt_u08(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_432(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDatBsi_432
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) ISDATBSI432MsgDLCError_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ShuntPosition_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PowerSupplies_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EtatPrincipSev_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EtatReseauElec_Cnt_T_u08;

	(void)Rte_Read_ISDATBSI432MsgDLCError_Cnt_u08(&ISDATBSI432MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(&PrevISDATBSI432MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ShuntPositionIn_Cnt_u08(&ShuntPosition_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_PowerSuppliesIn_Cnt_u08(&PowerSupplies_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_EtatPrincipSevIn_Cnt_u08(&EtatPrincipSev_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_EtatReseauElecIn_Cnt_u08(&EtatReseauElec_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */

	Rte_IWrite_SrlComInput_MsgIsDatBsi_432_ShuntPosition_Cnt_u08(ShuntPosition_Cnt_T_u08);
	Rte_IWrite_SrlComInput_MsgIsDatBsi_432_PowerSupplies_Cnt_u08(PowerSupplies_Cnt_T_u08);
	Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatPrincipSev_Cnt_u08(EtatPrincipSev_Cnt_T_u08);
	Rte_IWrite_SrlComInput_MsgIsDatBsi_432_EtatReseauElec_Cnt_u08(EtatReseauElec_Cnt_T_u08);
	if( ISDATBSI432MsgDLCError_Cnt_T_u08 == PrevISDATBSI432MsgDLCError_Cnt_M_u08 )
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;

		Msg432Valid_Cnt_M_lgc = TRUE;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDATBSI432MsgDLCError_Cnt_M_u08 = ISDATBSI432MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDatBsi_432();
		Msg432Valid_Cnt_M_lgc = FALSE;
	}

	/* NTC 138 - Invalid Message (too short) (Msg ID 432) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDATBSI432MsgLenValidCount_Cnt_M_u16,
						  &ISDATBSI432MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDATBSI432MsgLenValidThresh_Cnt_u16,
						  k_ISDATBSI432MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_P);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDatBsi_572
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDATBSI572MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ConfigVhl_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDatBsi_572(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDatBsi_572
 *********************************************************************************************************************/

	VAR(uint8,  AUTOMATIC) ISDATBSI572MsgDLCError_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ConfigVhl_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ConfigVhlTestStatus_Cnt_T_u08;

	(void)Rte_Read_ConfigVhl_Cnt_u08(&ConfigVhl_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI572MsgDLCError_Cnt_u08(&ISDATBSI572MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(&PrevISDATBSI572MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDATBSI572MsgDLCError_Cnt_T_u08 == PrevISDATBSI572MsgDLCError_Cnt_M_u08 ) /* No DLC error */
	{
		/* If Config Vehicle received with invalid value, then log NTC 184 - CONFIG_VHL Invalid */
		if(ConfigVhl_Cnt_T_u08 < (uint8)kCONFIG_VHL_INVALID)
		{
			ConfigVhlTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		else
		{
			ConfigVhlTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}

		/* NTC 184 - CONFIG_VHL Invalid (Msg ID 572) */
		ValidityNTCProcessing(ConfigVhlTestStatus_Cnt_T_u08,
							  &ConfigVhlSigValidCount_Cnt_M_u16,
							  &ConfigVhlSigInvalidCount_Cnt_M_u16,
							  k_ConfigVhlSigValidThresh_Cnt_u16,
							  k_ConfigVhlSigInvalidThresh_Cnt_u16,
							  NTC_Num_DataRngFltMsg_Y);

		/* For evaluating CONFIG_VHL, still kCONFIG_VHL_INVALID value shall be considered */
		if(ConfigVhl_Cnt_T_u08 == PrevConfigVhl_Cnt_M_u08)
		{
			ConfigVhlSigUpdCount_Cnt_M_u16++;
		}
		else
		{
			ConfigVhlSigUpdCount_Cnt_M_u16 = 0U;
		}

		if(ConfigVhlSigUpdCount_Cnt_M_u16 >= k_ISDATBSI572MsgCntrThresh_Cnt_u16)
		{
			if((ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_FITTING) || /*0*/
			   (ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_PLANT) || /*1*/
			   (ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_CHECK) ||/*2*/
			   (ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_CLIENT) ||/*4*/
			   (ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_APV) ||/*5*/
			   (ConfigVhl_Cnt_T_u08 == (uint8)kCONFIG_VHL_INVALID))/*7*/
			{
				EnergyModeState_Cnt_M_enum = NORMAL; /* 0 */
			}
			else /* For kCONFIG_VHL_SHOW_ROOM ( 3) and kCONFIG_VHL_STORAGE___TRANSPORT ( 6) */
			{
				EnergyModeState_Cnt_M_enum = TRANSPORTATION; /* 2 */
			}
		}

		/* Update PrevConfigVhl_Cnt_M_u08 only when a VALID message received */
		PrevConfigVhl_Cnt_M_u08 = ConfigVhl_Cnt_T_u08;
		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else /* DLC Error */
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDATBSI572MsgDLCError_Cnt_M_u08 = ISDATBSI572MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDatBsi_572();
	}

	/* NTC 180 - Invalid Message (too short) (Msg ID 572) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDATBSI572MsgLenValidCount_Cnt_M_u16,
						  &ISDATBSI572MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDATBSI572MsgLenValidThresh_Cnt_u16,
						  k_ISDATBSI572MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_Y);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDyn2Cmm_348
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYN2CMMMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Cmm_348(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDyn2Cmm_348
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYN2CMMMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) EtatMTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYN2CMMMsgDLCError_Cnt_u08(&ISDYN2CMMMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(&PrevISDYN2CMMMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYN2CMMMsgDLCError_Cnt_T_u08 == PrevISDYN2CMMMsgDLCError_Cnt_M_u08 )
	{
		/* Engine Status */
		EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
		EngOnDLCInvalidCount_Cnt_M_u08 = 0u;

		if( EtatMT_Cnt_M_u08 == PrevEtatMT_Cnt_M_u08 )
		{
			if( CountEtatMT_Cnt_M_u08 < 3u )
			{
				CountEtatMT_Cnt_M_u08++;

				if( CountEtatMT_Cnt_M_u08 >= 3u )
				{
					if( (EtatMT_Cnt_M_u08 == (uint8)kETAT_MT_Engine_Running) ||
						(EtatMT_Cnt_M_u08 == (uint8)kETAT_MT_Stopped) ||
						(EtatMT_Cnt_M_u08 == (uint8)kETAT_MT_Driven_Restart) ||
						(EtatMT_Cnt_M_u08 == (uint8)kETAT_MT_Autonomous_Restart) ||
						(EtatMT_Cnt_M_u08 == (uint8)kETAT_MT_Degraded_Restart) )
					{
						EngOn_Cnt_M_lgc = TRUE;
					}
					else
					{
						EngOn_Cnt_M_lgc = FALSE;
					}
				}
			}
		}
		else
		{
			CountEtatMT_Cnt_M_u08 = 1u;
			PrevEtatMT_Cnt_M_u08 = EtatMT_Cnt_M_u08;
		}


		if( (EtatMT_Cnt_M_u08 > (uint8)kETAT_MT_Engine_Preparing) &&
			(EtatMT_Cnt_M_u08 != (uint8)kETAT_MT_Autonomous_Starting) &&
			(EtatMT_Cnt_M_u08 != (uint8)kETAT_MT_Autonomous_Restart) )
		{
			EtatMTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			ValidEngineStatusCount_Cnt_M_u08 = 0u;
		}
		else
		{
			EtatMTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			ValidEngineStatusCount_Cnt_M_u08 = IncToThresh(ValidEngineStatusCount_Cnt_M_u08, 3u);
		}

		/* NTC 12C - Engine State Invalid (Msg ID 348) */
		ValidityNTCProcessing(EtatMTTestStatus_Cnt_T_u08,
							  &EtatMTSigValidCount_Cnt_M_u16,
							  &EtatMTSigInvalidCount_Cnt_M_u16,
							  k_EtatMTSigValidThresh_Cnt_u16,
							  k_EtatMTSigInvalidThresh_Cnt_u16,
							  NTC_Num_DataRngFltMsg_N);


		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;

		Msg348Valid_Cnt_M_lgc = TRUE;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYN2CMMMsgDLCError_Cnt_M_u08 = ISDYN2CMMMsgDLCError_Cnt_T_u08;
		ValidEngineStatusCount_Cnt_M_u08 = 0u;

		SrlComInput_ResetMsgIsDyn2Cmm_348();
		CountEtatMT_Cnt_M_u08 = 0u;

		if( EngOnDLCInvalidCount_Cnt_M_u08 < 3u )
		{
			EngOnDLCInvalidCount_Cnt_M_u08++;

			if( EngOnDLCInvalidCount_Cnt_M_u08 >= 3u )
			{
				EngOn_Cnt_M_lgc = FALSE;
			}
		}


		Msg348Valid_Cnt_M_lgc = FALSE;
	}

	/* NTC 128 - Invalid Message (too short) (Msg ID 348) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDYN2CMMMsgLenValidCount_Cnt_M_u16,
						  &ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16,
						  k_ISDYN2CMMMsgLenValidThresh_Cnt_u16,
						  k_ISDYN2CMMMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_N);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDyn2Fre_3CD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYN2FRE3CDMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AccelLat_Cnt_s16(SInt16 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDyn2Fre_3CD(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDyn2Fre_3CD
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYN2FRE3CDMsgDLCError_Cnt_T_u08;
	VAR(sint16,  AUTOMATIC) AccelLat_Cnt_T_s16;
	VAR(uint8,   AUTOMATIC) AccelLatTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYN2FRE3CDMsgDLCError_Cnt_u08(&ISDYN2FRE3CDMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_AccelLat_Cnt_s16(&AccelLat_Cnt_T_s16); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(&PrevISDYN2FRE3CDMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if (PrevISDYN2FRE3CDMsgDLCError_Cnt_M_u08 == ISDYN2FRE3CDMsgDLCError_Cnt_T_u08)
	{

		if ((AccelLat_Cnt_T_s16 >= D_ACCELLATVALIDLO_CNT_S16) && (AccelLat_Cnt_T_s16 <= D_ACCELLATVALIDHI_CNT_S16))
		{
			AccelLatValidityCount_Cnt_M_u16 = IncToThresh(AccelLatValidityCount_Cnt_M_u16, k_AccelLatValidityThresh_Cnt_u16);
			AccelLatInvalidityCount_Cnt_M_u16 = 0u;
			AccelLat_MpSecSq_M_f32 = (float32)AccelLat_Cnt_T_s16 * D_ACCELLATSCALE_CNT_f32;

			AccelLatTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		else
		{
			AccelLatInvalidityCount_Cnt_M_u16 = IncToThresh(AccelLatInvalidityCount_Cnt_M_u16, k_AccelLatInvalidityThresh_Cnt_u16);
			AccelLatValidityCount_Cnt_M_u16 = 0u;

			AccelLatTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}

		/* NTC 194 - Signal Invalid */
		ValidityNTCProcessing(AccelLatTestStatus_Cnt_T_u08,
							  &AccelLatValidCount_Cnt_M_u16,
							  &AccelLatInvalidCount_Cnt_M_u16,
							  k_AccelLatValidThresh_Cnt_u16,
							  k_AccelLatInvalidThresh_Cnt_u16,
							  NTC_Num_DataRngFltMsg_AA);

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYN2FRE3CDMsgDLCError_Cnt_M_u08 = ISDYN2FRE3CDMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDyn2Fre_3CD();
		AccelLatInvalidityCount_Cnt_M_u16 = 0u;
		AccelLatValidityCount_Cnt_M_u16 = 0u;
		AccelLatInvalidCount_Cnt_M_u16 = 0u;
	}

	/* NTC 190 - Invalid Message (too short) (Msg ID 3CD) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16,
						  &ISDYN2FRE3CDMsgLenInvalidCount_Cnt_M_u16,
						  k_ISDYN2FRE3CDMsgLenValidThresh_Cnt_u16,
						  k_ISDYN2FRE3CDMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_AA);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynAas_2EB
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNAASMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNAASMsg_Cnt_u08(UInt8 *data)
#else
 *   Std_ReturnType Rte_Read_ISDYNAASMsg_Cnt_u08(CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Read_ISDYNAASMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNAASMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAas_2EB(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynAas_2EB
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYNAASMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Checksum_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ChkSumTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCount_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCountTestStatus_Cnt_T_u08;
	VAR(sint16,  AUTOMATIC) CONSANGLECPK_Cnt_T_s16;
	VAR(uint8,   AUTOMATIC) CONSANGLECPKTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDFCTCPK_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDFCTCPKTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDRELAXECPK_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDRELAXECPKTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(CanMsgType, AUTOMATIC) ISDYNAASMsg_Cnt_T_u08;

	(void)Rte_Read_ISDYNAASMsg_Cnt_u08(&ISDYNAASMsg_Cnt_T_u08);
	(void)Rte_Read_ISDYNAASMsgDLCError_Cnt_u08(&ISDYNAASMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNAASMsgRxTime_MSec_u32(&PrevISDYNAASMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYNAASMsgDLCError_Cnt_T_u08 == PrevISDYNAASMsgDLCError_Cnt_M_u08 )
	{

		/* Checksum */

		Checksum_Cnt_T_u08 = SrlComInput_CalculateCheckSum((const CanMsgType*)&ISDYNAASMsg_Cnt_T_u08, 11u);

		if( Checksum_Cnt_T_u08 != 0x0Fu )
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}


		/* Message Progress Counter */

		MsgCount_Cnt_T_u08 = ISDYNAASMsg_Cnt_T_u08[3] & 0x0Fu;

		if( MsgCount_Cnt_T_u08 != ISDYNAASMsgCount_Cnt_M_u08 )
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		ISDYNAASMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;


		/* City Park Commanded Angle */

		CONSANGLECPK_Cnt_T_s16 = (sint16)((((uint16)ISDYNAASMsg_Cnt_T_u08[0]) << 8) + ISDYNAASMsg_Cnt_T_u08[1]); /* PRQA S 4394 */ /* Intentional conversion of s16 kept on u16 */

		if( (CONSANGLECPK_Cnt_T_s16 >= D_CONSANGLECPKVALIDLO_CNT_S16) &&
			(CONSANGLECPK_Cnt_T_s16 <= D_CONSANGLECPKVALIDHI_CNT_S16) )
		{
			CONSANGLECPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		else
		{
			CONSANGLECPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}


		/* City Park Command Request */

		DMDFCTCPK_Cnt_T_u08 = (ISDYNAASMsg_Cnt_T_u08[2] >> 6) & 0x03u; /* PRQA S 2985 */

		if( DMDFCTCPK_Cnt_T_u08 == (uint8)kDMD_FCT_CPK_Invalid )
		{
			DMDFCTCPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			DMDFCTCPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}


		/* City Park Relaxe Request */

		DMDRELAXECPK_Cnt_T_u08 = (ISDYNAASMsg_Cnt_T_u08[2] >> 4) & 0x03u;

		if( (DMDRELAXECPK_Cnt_T_u08 == (uint8)kDMD_RELAXE_CPK_Reserved) ||
			(DMDRELAXECPK_Cnt_T_u08 == (uint8)kDMD_RELAXE_CPK_Invalid) )
		{
			DMDRELAXECPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			DMDRELAXECPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* NTC 14A - IS_DYN_AAS Checksum Failure (Msg ID 2EB) */
		ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
							&ISDYNAASChkSumValidCount_Cnt_M_u16,
							&ISDYNAASChkSumInvalidCount_Cnt_M_u16,
							k_ISDYNAASChkSumValidThresh_Cnt_u16,
							k_ISDYNAASChkSumInvalidThresh_Cnt_u16,
							NTC_Num_CRCFltMsg_R);

		/* NTC 14B - IS_DYN_AAS Process Counter Failure (Msg ID 2EB) */
		ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
							&ISDYNAASMsgCountValidCount_Cnt_M_u16,
							&ISDYNAASMsgCountInvalidCount_Cnt_M_u16,
							k_ISDYNAASMsgCountValidThresh_Cnt_u16,
							k_ISDYNAASMsgCountInvalidThresh_Cnt_u16,
							NTC_Num_PgrsCntFltMsg_R);

		/* NTC 14C - CONS_ANGLE_CPK Invalid (Msg ID 2EB) */
		ValidityNTCProcessing(CONSANGLECPKTestStatus_Cnt_T_u08,
							&CONSANGLECPKSigValidCount_Cnt_M_u16,
							&CONSANGLECPKSigInvalidCount_Cnt_M_u16,
							k_CONSANGLECPKSigValidThresh_Cnt_u16,
							k_CONSANGLECPKSigInvalidThresh_Cnt_u16,
							NTC_Num_DataRngFltMsg_R);

		/* NTC 14D - DMD_FCT_CPK Invalid (Msg ID 2EB) */
		ValidityNTCProcessing(DMDFCTCPKTestStatus_Cnt_T_u08,
							&DMDFCTCPKSigValidCount_Cnt_M_u16,
							&DMDFCTCPKSigInvalidCount_Cnt_M_u16,
							k_DMDFCTCPKSigValidThresh_Cnt_u16,
							k_DMDFCTCPKSigInvalidThresh_Cnt_u16,
							NTC_Num_DataRateFltMsg_R);

		/* NTC 14E - DMD_RELAXE_CPK Invalid (Msg ID 2EB) */
		ValidityNTCProcessing(DMDRELAXECPKTestStatus_Cnt_T_u08,
							&DMDRELAXECPKSigValidCount_Cnt_M_u16,
							&DMDRELAXECPKSigInvalidCount_Cnt_M_u16,
							k_DMDRELAXECPKSigValidThresh_Cnt_u16,
							k_DMDRELAXECPKSigInvalidThresh_Cnt_u16,
							NTC_Num_DataOtherFltMsg_R);


		if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
		{
			if (CONSANGLECPKTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08)
			{
				CONSANGLECPK_Cnt_M_s16 = CONSANGLECPK_Cnt_T_s16;
				CONSANGLECPK_HwDeg_M_f32 = (float32)CONSANGLECPK_Cnt_T_s16 * D_CONSANGLECPKSCALE_CNT_F32 * D_CONSANGLECPKPOL_CNT_F32;
				CONSANGLECPK_HwDeg_M_f32 = Limit_m(CONSANGLECPK_HwDeg_M_f32, k_CONSANGLECPKMin_HwDeg_f32, k_CONSANGLECPKMax_HwDeg_f32);
			}

			DMDFCTCPK_Cnt_M_u08 = DMDFCTCPK_Cnt_T_u08;
			DMDRELAXECPK_Cnt_M_u08 = DMDRELAXECPK_Cnt_T_u08;

			if (DMDRELAXECPK_Cnt_M_u08 == PrevDMDRELAXECPK_Cnt_M_u08)
			{
				DMDRelaxeConsistentCount_Cnt_M_u16 = IncToThresh(DMDRelaxeConsistentCount_Cnt_M_u16, k_DMDRelaxeConsistentThresh_Cnt_u16);
			}
			else
			{
				DMDRelaxeConsistentCount_Cnt_M_u16 = 1u;
				PrevDMDRELAXECPK_Cnt_M_u08 = DMDRELAXECPK_Cnt_M_u08;
			}

			if(DMDFCTCPK_Cnt_T_u08 == PrevDMDFCTCPK_Cnt_M_u08)
			{
				CityParkInputConsistentCount_Cnt_M_u16 = IncToThresh(CityParkInputConsistentCount_Cnt_M_u16, k_DMDFCTCPKValidCount_Cnt_u16);
			}
			else
			{
				CityParkInputConsistentCount_Cnt_M_u16 = 1u;
				PrevDMDFCTCPK_Cnt_M_u08 = DMDFCTCPK_Cnt_T_u08;
			}

		}
		else
		{
			DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
		}

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;

	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNAASMsgDLCError_Cnt_M_u08 = ISDYNAASMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynAas_2EB();
		DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
	}

	/* NTC 148 - IS_DYN_AAS (too short) (Msg ID 2EB) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						&ISDYNAASMsgLenValidCount_Cnt_M_u16,
						&ISDYNAASMsgLenInvalidCount_Cnt_M_u16,
						k_ISDYNAASMsgLenValidThresh_Cnt_u16,
						k_ISDYNAASMsgLenInvalidThresh_Cnt_u16,
						NTC_Num_InvalidMsg_R);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynAbr_38D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNABRMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNABRMsg_Cnt_u08(UInt8 *data)
#else
 *   Std_ReturnType Rte_Read_ISDYNABRMsg_Cnt_u08(CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Read_ISDYNABRMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNABRMsgRxTime_MSec_u32(UInt32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynAbr_38D(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynAbr_38D
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYNABRMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Checksum_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
	VAR(uint8,   AUTOMATIC) MsgCount_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
	VAR(uint16,  AUTOMATIC) VitesseVehiculeRoues_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) VitesseVehiculeRouesTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(CanMsgType, AUTOMATIC) ISDYNABRMsg_Cnt_T_u08;

	(void)Rte_Read_ISDYNABRMsg_Cnt_u08(&ISDYNABRMsg_Cnt_T_u08);
	(void)Rte_Read_ISDYNABRMsgDLCError_Cnt_u08(&ISDYNABRMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNABRMsgRxTime_MSec_u32(&PrevISDYNABRMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYNABRMsgDLCError_Cnt_T_u08 == PrevISDYNABRMsgDLCError_Cnt_M_u08 )
	{
		/* Checksum */
		Checksum_Cnt_T_u08 = SrlComInput_CalculateCheckSum((const CanMsgType*)&ISDYNABRMsg_Cnt_T_u08, 8u);
		if( Checksum_Cnt_T_u08 == 0x0Fu )
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}


		/* Message Progress Counter */
		MsgCount_Cnt_T_u08 = (ISDYNABRMsg_Cnt_T_u08[5] >> 4u) & 0x0Fu; /* PRQA S 2985 */
		if( MsgCount_Cnt_T_u08 == ISDYNABRMsgCount_Cnt_M_u08 )
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		ISDYNABRMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;


		/* Vehicle Speed */
		VitesseVehiculeRoues_Cnt_T_u16 = (((uint16)ISDYNABRMsg_Cnt_T_u08[0]) << 8) + ISDYNABRMsg_Cnt_T_u08[1];
		if( VitesseVehiculeRoues_Cnt_T_u16 != (uint16)kVITESSE_VEHICULE_ROUES_Invalid )
		{
			VitesseVehiculeRouesTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(VitesseVehiculeRouesTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
		{
			if( *Rte_Pim_VVHTYPEData() < 2u )
			{
				if( VVHTYPE2Count_Cnt_M_u08 < 10u )
				{
					VVHTYPE2Count_Cnt_M_u08++;
				}
				else
				{
					SrlComInput_UpdateVVHType(2u);
				}
			}

			if( *Rte_Pim_VVHTYPEData() == 2u )
			{
				SrlComVehSpd_Kph_M_f32 = ((float32)VitesseVehiculeRoues_Cnt_T_u16) * D_VEHSPDSCALE_CNT_F32;
			}
		}

		if( *Rte_Pim_VVHTYPEData() == 2u )
		{
			/* NTC 132 - Vehicle Speed Message Checksum Failure (Msg ID 38D) */
			ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
								&ISDYNABRChkSumValidCount_Cnt_M_u16,
								&ISDYNABRChkSumInvalidCount_Cnt_M_u16,
								k_ISDYNABRChkSumValidThresh_Cnt_u16,
								k_ISDYNABRChkSumInvalidThresh_Cnt_u16,
								NTC_Num_CRCFltMsg_O);

			/* NTC 133 - Vehicle Speed Message Progress Counter Failure (Msg ID 38D) */
			ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
								&ISDYNABRMsgCountValidCount_Cnt_M_u16,
								&ISDYNABRMsgCountInvalidCount_Cnt_M_u16,
								k_ISDYNABRMsgCountValidThresh_Cnt_u16,
								k_ISDYNABRMsgCountInvalidThresh_Cnt_u16,
								NTC_Num_PgrsCntFltMsg_O);

			/* NTC 134 - Invalid Vehicle Speed Data (Msg ID 38D) */
			ValidityNTCProcessing(VitesseVehiculeRouesTestStatus_Cnt_T_u08,
								&VitesseVehiculeRouesSigValidCount_Cnt_M_u16,
								&VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16,
								k_VitesseVehiculeRouesSigValidThresh_Cnt_u16,
								k_VitesseVehiculeRouesSigInvalidThresh_Cnt_u16,
								NTC_Num_DataRngFltMsg_O);
		}

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNABRMsgDLCError_Cnt_M_u08 = ISDYNABRMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynAbr_38D();
	}


	if( *Rte_Pim_VVHTYPEData() == 2u )
	{
		/* NTC 130 - Invalid Message (too short) (Msg ID 38D) */
		ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
							&ISDYNABRMsgLenValidCount_Cnt_M_u16,
							&ISDYNABRMsgLenInvalidCount_Cnt_M_u16,
							k_ISDYNABRMsgLenValidThresh_Cnt_u16,
							k_ISDYNABRMsgLenInvalidThresh_Cnt_u16,
							NTC_Num_InvalidMsg_O);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCds_34D
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCDS34DMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCds_34D(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynCds_34D
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYNCDS34DMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYNCDS34DMsgDLCError_Cnt_u08(&ISDYNCDS34DMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(&PrevISDYNCDS34DMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if (PrevISDYNCDS34DMsgDLCError_Cnt_M_u08 == ISDYNCDS34DMsgDLCError_Cnt_T_u08)
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNCDS34DMsgDLCError_Cnt_M_u08 = ISDYNCDS34DMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynCds_34D();
	}
	/* NTC 170 - Invalid Message (too short) (Msg ID 34D) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDYNCDS34DMsgLenValidCount_Cnt_M_u16,
						  &ISDYNCDS34DMsgLenInvalidCount_Cnt_M_u16,
						  k_ISDYNCDS34DMsgLenValidThresh_Cnt_u16,
						  k_ISDYNCDS34DMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_W);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCmm_208
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCMM208MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_208(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynCmm_208
 *********************************************************************************************************************/

	VAR(uint8,   AUTOMATIC) ISDYNCMM208MsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYNCMM208MsgDLCError_Cnt_u08(&ISDYNCMM208MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(&PrevISDYNCMM208MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYNCMM208MsgDLCError_Cnt_T_u08 == PrevISDYNCMM208MsgDLCError_Cnt_M_u08 )
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNCMM208MsgDLCError_Cnt_M_u08 = ISDYNCMM208MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynCmm_208();
	}

	/* NTC 120 - Invalid Message (too short) (Msg ID 208) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDYNCMM208MsgLenValidCount_Cnt_M_u16,
						  &ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16,
						  k_ISDYNCMM208MsgLenValidThresh_Cnt_u16,
						  k_ISDYNCMM208MsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_M);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynCmm_388
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNCMM388MsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_VitesseVehicleBV_Cnt_u16(UInt16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VVHType_Cnt_u08(UInt8 data)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynCmm_388(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynCmm_388
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYNCMM388MsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) VitesseVehicleBV_Cnt_T_u16;
	VAR(float32, AUTOMATIC) VitesseVehicleBV_Kph_T_f32;
	VAR(uint8,   AUTOMATIC) VitesseVehicleBVRampTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
	VAR(uint8,   AUTOMATIC) NtcDataRateFltMsgVStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYNCMM388MsgDLCError_Cnt_u08(&ISDYNCMM388MsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_VitesseVehicleBV_Cnt_u16(&VitesseVehicleBV_Cnt_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(&PrevISDYNCMM388MsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYNCMM388MsgDLCError_Cnt_T_u08 == PrevISDYNCMM388MsgDLCError_Cnt_M_u08 )
	{

		if( VitesseVehicleBV_Cnt_T_u16 != (uint16)kVITESSE_VEHICLE_BV_Invalid )
		{
			VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		if( (*Rte_Pim_VVHTYPEData() < 1u) &&
			(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
		{
			if( VVHTYPE1Count_Cnt_M_u08 < 10u )
			{
				VVHTYPE1Count_Cnt_M_u08++;
			}
			else
			{
				SrlComInput_UpdateVVHType(1u);
			}
		}

		if( 1u == *Rte_Pim_VVHTYPEData() )
		{
			VitesseVehicleBV_Kph_T_f32 = ((float32)VitesseVehicleBV_Cnt_T_u16) * D_VEHSPDSCALE_CNT_F32;

			/* NTC 16C - IS_DYN_CMM Vehicle Speed Invalid (Msg ID 388) */
			ValidityNTCProcessing(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08,
								  &VitesseVehicleBVSigValidCount_Cnt_M_u16,
								  &VitesseVehicleBVSigInvalidCount_Cnt_M_u16,
								  k_VitesseVehicleBVSigValidThresh_Cnt_u16,
								  k_VitesseVehicleBVSigInvalidThresh_Cnt_u16,
								  NTC_Num_DataRngFltMsg_V);

			/* NTC 16D - IS_DYN_CMM Vehicle Speed Invalid Rate (Msg ID 388) */
			if( (PrevVitesseVehicleBVValid_Cnt_M_lgc == TRUE) &&
				(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
			{
				if( ((SrlComVehSpd_Kph_M_f32 - VitesseVehicleBV_Kph_T_f32) > 14.0f) &&
					(VitesseVehicleBV_Kph_T_f32 < 5.0f) )
				{
					VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else if (VitesseVehicleBV_Kph_T_f32 > k_VitesseVehicleBVSpeedPassThresh_kph_f32)
				{
					VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				else
				{
					VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTDEADBAND_CNT_U08;
				}

				ValidityNTCProcessing(VitesseVehicleBVRampTestStatus_Cnt_T_u08,
									  &VitesseVehicleBVRampValidCount_Cnt_M_u16,
									  &VitesseVehicleBVRampInvalidCount_Cnt_M_u16,
									  k_VitesseVehicleBVRampValidThresh_Cnt_u16,
									  1u,
									  NTC_Num_DataRateFltMsg_V);

				/* Workaround for CTC Inhibition:
				 * Refresh status of the NTC to force passing it over to DEM when CTC Inhibition is gone.
				 * It's done mainly for FAILED scenario cause it's triggered by specific event,
				 * which cannot be generated consecutively.
				 * Problem was: When event was triggered during Inhibition, report of FAILED status was skipped.
				 * Later, when Inhibition is gone and NTC was still FAILED, NTC status was not passed to DEM */
				(void) Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_V, &NtcDataRateFltMsgVStatus_Cnt_T_u08);

				/* Protection against not tested this op cycle or tested but cleared by Clear NTC */
				if (0u == (NtcDataRateFltMsgVStatus_Cnt_T_u08 & D_TESTNOTCOMPLETETHISOPCYCLEBIT_CNT_B8))
				{
					if (0u == (NtcDataRateFltMsgVStatus_Cnt_T_u08 & D_TESTFAILEDBIT_CNT_B8))
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_V, 0u, NTC_STATUS_PASSED);
					}
					else
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_V, 0u, NTC_STATUS_FAILED);
					}
				}
			}

			if( VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
			{
				SrlComVehSpd_Kph_M_f32 = VitesseVehicleBV_Kph_T_f32;
				PrevVitesseVehicleBVValid_Cnt_M_lgc = TRUE;
			}
			else
			{
				PrevVitesseVehicleBVValid_Cnt_M_lgc = FALSE;
			}
		}

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNCMM388MsgDLCError_Cnt_M_u08 = ISDYNCMM388MsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynCmm_388();
	}

	if( 1u == *Rte_Pim_VVHTYPEData() )
	{
		/* NTC 168 - Invalid Message (too short) (Msg ID 388) */
		ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
							  &ISDYNCMM388MsgLenValidCount_Cnt_M_u16,
							  &ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16,
							  k_ISDYNCMM388MsgLenValidThresh_Cnt_u16,
							  k_ISDYNCMM388MsgLenInvalidThresh_Cnt_u16,
							  NTC_Num_InvalidMsg_V);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsDynVol_305
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISDYNVOLMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_ISDYNVOLMsg_Cnt_u08(UInt8 *data)
#else
 *   Std_ReturnType Rte_Read_ISDYNVOLMsg_Cnt_u08(CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(UInt32 *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsDynVol_305(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsDynVol_305
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) ISDYNVOLMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Checksum_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ChkSumTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCount_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCountTestStatus_Cnt_T_u08;
	VAR(CanMsgType, AUTOMATIC) ISDYNVOLMsg_Cnt_T_u08;
	VAR(sint16,  AUTOMATIC) ANGLEVOLANT_Cnt_T_s16;
	VAR(uint8,   AUTOMATIC) ANGLEVOLANTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VITESSEROTVOLANT_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VITESSEROTVOLANTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;

	(void)Rte_Read_ISDYNVOLMsg_Cnt_u08(&ISDYNVOLMsg_Cnt_T_u08);
	(void)Rte_Read_ISDYNVOLMsgDLCError_Cnt_u08(&ISDYNVOLMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(&PrevISDYNVOLMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ISDYNVOLMsgDLCError_Cnt_T_u08 == PrevISDYNVOLMsgDLCError_Cnt_M_u08 ) /* No DLC error */
	{
		/* Checksum */
		Checksum_Cnt_T_u08 = 	ISDYNVOLMsg_Cnt_T_u08[0] ^
								ISDYNVOLMsg_Cnt_T_u08[1] ^
								ISDYNVOLMsg_Cnt_T_u08[2] ^
								ISDYNVOLMsg_Cnt_T_u08[3] ^
								ISDYNVOLMsg_Cnt_T_u08[4];

		Checksum_Cnt_T_u08 = (Checksum_Cnt_T_u08 ^ (Checksum_Cnt_T_u08 >> 4)) & 0x0Fu;

		if( Checksum_Cnt_T_u08 != 0u )
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}


		/* Message Progress Counter */
		MsgCount_Cnt_T_u08 = ISDYNVOLMsg_Cnt_T_u08[4] & 0x0Fu;

		if( MsgCount_Cnt_T_u08 != ISDYNVOLMsgCount_Cnt_M_u08 )
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		ISDYNVOLMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;


		/* Handwheel Angle */

		ANGLEVOLANT_Cnt_T_s16 = (sint16)(((uint16)ISDYNVOLMsg_Cnt_T_u08[0] << 8) + ISDYNVOLMsg_Cnt_T_u08[1]); /* PRQA S 4394 */ /* Intentional conversion of s16 kept in u16 */

		if( (ANGLEVOLANT_Cnt_T_s16 >= D_ANGLEVOLANTVALIDLO_CNT_S16) &&
			(ANGLEVOLANT_Cnt_T_s16 <= D_ANGLEVOLANTVALIDHI_CNT_S16) )
		{
			ANGLEVOLANTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}
		else
		{
			ANGLEVOLANTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}


		/* Handwheel Speed */

		VITESSEROTVOLANT_Cnt_T_u08 = ISDYNVOLMsg_Cnt_T_u08[2];

		if( VITESSEROTVOLANT_Cnt_T_u08 == (uint8)kVITESSE_ROT_VOL_Invalid )
		{
			VITESSEROTVOLANTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			VITESSEROTVOLANTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* NTC 152 - IS_DYN_CAV Checksum Failure (Msg ID 305) */
		ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
						  &ISDYNVOLChkSumValidCount_Cnt_M_u16,
						  &ISDYNVOLChkSumInvalidCount_Cnt_M_u16,
						  k_ISDYNVOLChkSumValidThresh_Cnt_u16,
						  k_ISDYNVOLChkSumInvalidThresh_Cnt_u16,
						  NTC_Num_CRCFltMsg_S);

		/* NTC 153 - IS_DYN_CAV Process Counter Failure (Msg ID 305) */
		ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
						  &ISDYNVOLMsgCountValidCount_Cnt_M_u16,
						  &ISDYNVOLMsgCountInvalidCount_Cnt_M_u16,
						  k_ISDYNVOLMsgCountValidThresh_Cnt_u16,
						  k_ISDYNVOLMsgCountInvalidThresh_Cnt_u16,
						  NTC_Num_PgrsCntFltMsg_S);

		/* NTC 154 - ANGLE_VOLANT Invalid (Msg ID 305) */
		ValidityNTCProcessing(ANGLEVOLANTTestStatus_Cnt_T_u08,
						  &ANGLEVOLANTSigValidCount_Cnt_M_u16,
						  &ANGLEVOLANTSigInvalidCount_Cnt_M_u16,
						  k_ANGLEVOLANTSigValidThresh_Cnt_u16,
						  k_ANGLEVOLANTSigInvalidThresh_Cnt_u16,
						  NTC_Num_DataRngFltMsg_S);

		/* NTC 155 - VITESSE_ROT_VOLANT Invalid (Msg ID 305) */
		ValidityNTCProcessing(VITESSEROTVOLANTTestStatus_Cnt_T_u08,
						  &VITESSEROTVOLANTSigValidCount_Cnt_M_u16,
						  &VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16,
						  k_VITESSEROTVOLANTSigValidThresh_Cnt_u16,
						  k_VITESSEROTVOLANTSigInvalidThresh_Cnt_u16,
						  NTC_Num_DataRateFltMsg_S);

		if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(ANGLEVOLANTTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
		{
			AngleVolant_HwDeg_M_f32 = (float32)ANGLEVOLANT_Cnt_T_s16 * D_ANGLEVOLANTSCALE_HWDEGPCNT_F32 * D_ANGLEVOLANTPOL_CNT_F32;
		}

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevISDYNVOLMsgDLCError_Cnt_M_u08 = ISDYNVOLMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgIsDynVol_305();
	}

	/* NTC 150 - Invalid Message (too short) (Msg ID 305) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &ISDYNVOLMsgLenValidCount_Cnt_M_u16,
						  &ISDYNVOLMsgLenInvalidCount_Cnt_M_u16,
						  k_ISDYNVOLMsgLenValidThresh_Cnt_u16,
						  k_ISDYNVOLMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_S);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgIsInteElectronBsi_092
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <ISINTEELECTRONBSIMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagIntegraElec_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EffacDefaultDiag_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ModeDiag_Cnt_u08(UInt8 *data)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgIsInteElectronBsi_092(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgIsInteElectronBsi_092
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) DiagIntegraElec_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ModeDiag_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,   AUTOMATIC) EffacDefaultDiag_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) i;

	(void)Rte_Read_DiagIntegraElec_Cnt_u08(&DiagIntegraElec_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ModeDiag_Cnt_u08(&ModeDiag_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_EffacDefaultDiag_Cnt_u08(&EffacDefaultDiag_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( (DiagOn_Cnt_M_lgc == TRUE) ||
		(SystemState_Cnt_M_enum == RTE_MODE_StaMd_Mode_OPERATE) )
	{
		ElecIntCount_Cnt_M_u08 = 0u;
		EffacDefaultDiagCount_Cnt_M_u08 = 0u;
	}
	else
	{
		if( (DiagIntegraElec_Cnt_T_u08 == PrevDiagIntegraElec_Cnt_M_u08) &&
			(ModeDiag_Cnt_T_u08 == PrevModeDiag_Cnt_M_u08) )
		{
			if( ElecIntCount_Cnt_M_u08 < D_ELECINTCONSECMSGS_CNT_U08 )
			{
				ElecIntTimer_mS_M_u32[ElecIntCount_Cnt_M_u08] = SystemTime_mS_M_u32;
				ElecIntCount_Cnt_M_u08++;
			}
			else
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ElecIntTimer_mS_M_u32[0u], &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

				if( ElapsedTime_mS_T_u16 > D_ELECINTCONSECTIMEOUT_MS_U16 )
				{
					for( i = 0u; i < (D_ELECINTCONSECMSGS_CNT_U08 - 1u); i++ ) /* PRQA S 2877 */
					{
						ElecIntTimer_mS_M_u32[i] = ElecIntTimer_mS_M_u32[i + 1u]; /* PRQA S 2984 */
					}

					ElecIntTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08 - 1u] = SystemTime_mS_M_u32;
				}
				else if( (ModeDiag_Cnt_T_u08 == (uint8)kMODE_DIAG_Operation_and_Comm_Inhibited) &&
						(DiagIntegraElec_Cnt_T_u08 == (uint8)kDIAG_INTEGRA_ELEC_No_Frame_Transmission) )
				{
					ElectronicIntegrationCmd_Cnt_M_lgc = TRUE;
				}
				else if( (ModeDiag_Cnt_T_u08 == (uint8)kMODE_DIAG_No_Particular_Operation) &&
						(DiagIntegraElec_Cnt_T_u08 == (uint8)kDIAG_INTEGRA_ELEC_No_Particular_Operation) )
				{
					ElectronicIntegrationCmd_Cnt_M_lgc = FALSE;
				}
				else
				{
					/* do nothing */
				}
			}
		}
		else
		{
			ElecIntTimer_mS_M_u32[0u] = SystemTime_mS_M_u32;
			ElecIntCount_Cnt_M_u08 = 1u;

			PrevDiagIntegraElec_Cnt_M_u08 = DiagIntegraElec_Cnt_T_u08;
			PrevModeDiag_Cnt_M_u08 = ModeDiag_Cnt_T_u08;
		}

		if( EffacDefaultDiag_Cnt_T_u08 == (uint8)kEFFAC_DEFAULT_DIAG_Default_Memory_Erase )
		{
			if( EffacDefaultDiagCount_Cnt_M_u08 < D_ELECINTCONSECMSGS_CNT_U08 )
			{
				EffacDefaultDiagTimer_mS_M_u32[EffacDefaultDiagCount_Cnt_M_u08] = SystemTime_mS_M_u32;
				EffacDefaultDiagCount_Cnt_M_u08++;
			}
			else
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EffacDefaultDiagTimer_mS_M_u32[0u], &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

				if( ElapsedTime_mS_T_u16 > D_ELECINTCONSECTIMEOUT_MS_U16 )
				{
					for( i = 0u; i < (D_ELECINTCONSECMSGS_CNT_U08 - 1u); i++ ) /* PRQA S 2877 */
					{
						EffacDefaultDiagTimer_mS_M_u32[i] = EffacDefaultDiagTimer_mS_M_u32[i + 1u]; /* PRQA S 2984 */
					}

					EffacDefaultDiagTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08 - 1u] = SystemTime_mS_M_u32;
				}
				else
				{
					EffacDefaultDiagCount_Cnt_M_u08 = 0u;
					ClearDTCs_Cnt_M_lgc = TRUE;
				}
			}
		}
		else
		{
			EffacDefaultDiagCount_Cnt_M_u08 = 0u;
		}

	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_MsgProtoHs1DynUcf_5CD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MSec_u32> of PortPrototype <PROTOHS1DYNUCF5CDMsgRxTime>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08(UInt8 *data)
#else
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08(CanMsgType *data)
#endif
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 *data)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProtoHs1DynUcf_5CD(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_MsgProtoHs1DynUcf_5CD
 *********************************************************************************************************************/
	VAR(uint8,  AUTOMATIC) PROTOHS1DYNUCF5CDMsgDLCError_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Checksum_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ChkSumTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCount_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCountTestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) Offset_Cnt_T_u16;
	VAR(float32, AUTOMATIC) Offset_Cnt_T_f32;
	VAR(uint8, AUTOMATIC) OffsetTestStatus_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) OffsetInvalidTestStatus_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PrecisionOffset_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PrecisionOffsetTestStatus_Cnt_T_u08;
	VAR(CanMsgType, AUTOMATIC) PROTOHS1DYNUCF5CDMsg_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,   AUTOMATIC) OffsetDataConsistentTestStatus_Cnt_T_u08;

	(void)Rte_Read_PROTOHS1DYNUCF5CDMsgDLCError_Cnt_u08(&PROTOHS1DYNUCF5CDMsgDLCError_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_PROTOHS1DYNUCF5CDMsg_Cnt_u08(&PROTOHS1DYNUCF5CDMsg_Cnt_T_u08);
	(void)Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(&PrevPROTOHS1DYNUCF5CDMsgRxTime_MSec_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( PROTOHS1DYNUCF5CDMsgDLCError_Cnt_T_u08 == PrevPROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08 ) /* No DLC error */
	{
		/* Checksum */
		Checksum_Cnt_T_u08 = SrlComInput_CalculateCheckSum((const CanMsgType*)&PROTOHS1DYNUCF5CDMsg_Cnt_T_u08, 0xEu);

		if( Checksum_Cnt_T_u08 != 0x0Fu )
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* Message Progress Counter */
		MsgCount_Cnt_T_u08 = PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[0] & 0x0Fu;

		if( MsgCount_Cnt_T_u08 != PROTOHS1DYNUCF5CDMsgCount_Cnt_M_u08 )
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		PROTOHS1DYNUCF5CDMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;

		/* Offset value */

		Offset_Cnt_T_u16 = (((uint16)PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[1]) << 8) + PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[2U];
		Offset_Cnt_T_f32 = ((float32)((sint16)Offset_Cnt_T_u16))* D_OFFSETSCALE_CNT_F32 * D_OFFSETPOL_CNT_F32;

		/* Offset validity */
		if(((Offset_Cnt_T_u16 != ((uint16)kOFFSET_Invalid)) &&
		    (Offset_Cnt_T_u16 != ((uint16)kOFFSET_Unavailable))) &&
		    ((Offset_Cnt_T_f32 < D_OFFSETLOLIM_CNT_F32 ) || (Offset_Cnt_T_f32 > D_OFFSETHILIM_CNT_F32)))
		{
			OffsetTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			OffsetTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* Offset invalid */

		if (Offset_Cnt_T_u16 == ((uint16)kOFFSET_Invalid))
		{
			OffsetInvalidTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			OffsetInvalidTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* Precision offset value */
		PrecisionOffset_Cnt_T_u08 = ((PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[3] & 0xF8u) >> 3);

		/* Precision offset validity */
		if(PrecisionOffset_Cnt_T_u08 == (uint8)kPRECISION_OFFSET_Invalid)
		{
			PrecisionOffsetTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			PrecisionOffsetTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* OFFSET Data Inconsistent */
		if(((PrecisionOffset_Cnt_T_u08 == (uint8)kPRECISION_OFFSET_Invalid) && (Offset_Cnt_T_u16 != (uint16)kOFFSET_Invalid)) ||
			((PrecisionOffset_Cnt_T_u08 != (uint8)kPRECISION_OFFSET_Invalid) && (Offset_Cnt_T_u16 == (uint16)kOFFSET_Invalid)))
		{
			OffsetDataConsistentTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		}
		else
		{
			OffsetDataConsistentTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
		}

		/* NTC 18A - Checksum Invalid (Msg ID 5CD) */
		ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
							  &PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16,
							  &PROTOHS1DYNUCF5CDMsgChkSumInvalidCount_Cnt_M_u16,
							  k_PROTOHS1DYNUCF5CDMsgChkSumValidThresh_Cnt_u16,
							  k_PROTOHS1DYNUCF5CDMsgChkSumInvalid_Cnt_u16,
							  NTC_Num_CRCFltMsg_Z);

		/* NTC 18B - Process counter Invalid (Msg ID 5CD) */
		ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
							  &PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16,
							  &PROTOHS1DYNUCF5CDMsgCountInvalidCount_Cnt_M_u16,
							  k_ROTOHS1DYNUCF5CDMsgCountValidThresh_Cnt_u16,
							  k_PROTOHS1DYNUCF5CDMsgCountInvalidThresh_Cnt_u16,
							  NTC_Num_PgrsCntFltMsg_Z);

		/* NTC 18C - Offset data out-of-range (Msg ID 5CD) */
		ValidityNTCProcessing(OffsetTestStatus_Cnt_T_u08,
							  &OffsetSigValidCount_Cnt_M_u16,
							  &OffsetSigInvalidCount_Cnt_M_u16,
							  k_ROTOHS1DYNUCF5CDOffsetSigValidThresh_Cnt_u16,
							  k_PROTOHS1DYNUCF5CDOffsetSigInvalidThresh_Cnt_u16,
							  NTC_Num_DataRngFltMsg_Z);


		/* NTC 18D - Precision Offset data invalid (Msg ID 5CD) */
		ValidityNTCProcessing(PrecisionOffsetTestStatus_Cnt_T_u08,
							  &PrecisionOffsetSigValidCount_Cnt_M_u16,
							  &PrecisionOffsetSigInvalidCount_Cnt_M_u16,
							  k_PrecisionOffsetValidThresh_Cnt_u16,
							  k_PrecisionOffsetInvalidThresh_Cnt_u16,
							  NTC_Num_DataRateFltMsg_Z);

		/* NTC 18E - Precision Offset Data Inconsistent (Msg ID 5CD) */
		ValidityNTCProcessing(OffsetDataConsistentTestStatus_Cnt_T_u08,
							  &OffsetDataConsistentCount_Cnt_M_u16,
							  &OffsetDataInconsistentCount_Cnt_M_u16,
							  k_OffsetDataConsistentThresh_Cnt_u16,
							  k_OffsetDataInconsistentThresh_Cnt_u16,
							  NTC_Num_DataOtherFltMsg_Z);

		/* NTC 18F - Offset Invalid (Msg ID 5CD) */
		ValidityNTCProcessing(OffsetInvalidTestStatus_Cnt_T_u08,
							  &OffsetValidCount_Cnt_M_u16,
							  &OffsetInvalidCount_Cnt_M_u16,
							  k_OffsetValidThresh_Cnt_u16,
							  k_OffsetInvalidThresh_Cnt_u16,
							  NTC_Num_DSTXORActive);	/* FIXME: NTC to be renamed in the future. Surely... */

		/* DLC OK, Checksum OK, Process Counter OK */
		if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
			(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
		{
			/* ACQ_INTERRUPT_DAE */
			AcqInterruptDae_Cnt_M_lgc = (boolean)((PROTOHS1DYNUCF5CDMsg_Cnt_T_u08[3] >> 2u) & 0x01u);

			/* Update offset & Precision  */
			if (((Offset_Cnt_T_u16 != ((uint16)kOFFSET_Invalid)) &&
				 (Offset_Cnt_T_u16 != ((uint16)kOFFSET_Unavailable))) &&
				 (D_TESTPASSED_CNT_U08 == OffsetTestStatus_Cnt_T_u08) &&
			 	 (PrecisionOffset_Cnt_T_u08 != (uint8)kPRECISION_OFFSET_Invalid) &&
				 (PrecisionOffset_Cnt_T_u08 != (uint8)kPRECISION_OFFSET_Unavailable))
			{
				EscOffsFromSerlCom_HwDeg_M_f32 = Offset_Cnt_T_f32;
				EscPrecisionFromSerlCom_HwDeg_M_f32 = (float32)PrecisionOffset_Cnt_T_u08;
			}

			if( (AcqInterruptDae_Cnt_M_lgc == TRUE )   ||
				(Offset_Cnt_M_u16 != Offset_Cnt_T_u16) ||
				(PrecisionOffset_Cnt_M_u08 != PrecisionOffset_Cnt_T_u08) ||
				(Offset_Cnt_T_u16 == ((uint16)kOFFSET_Unavailable)) ||
				(PrecisionOffset_Cnt_T_u08 == (uint8)kPRECISION_OFFSET_Unavailable))
			{
				EscDataVldFromSerlCom_Cnt_M_lgc = FALSE;
			}
			else
			{
				EscDataVldFromSerlCom_Cnt_M_lgc = TRUE;
			}

			/* M Variables for EscDataVld evaluation - validity of signal irrelevant*/
			PrecisionOffset_Cnt_M_u08 = PrecisionOffset_Cnt_T_u08;
			Offset_Cnt_M_u16 = Offset_Cnt_T_u16;
		}

		DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
	}
	else /* DLC Error */
	{
		DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
		PrevPROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08 = PROTOHS1DYNUCF5CDMsgDLCError_Cnt_T_u08;

		SrlComInput_ResetMsgProtoHs1DynUcf_5CD();
	}

	/* NTC  188 - Invalid  5CD Message (too short) (Msg ID  5CD) */
	ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
						  &PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16,
						  &PROTOHS1DYNUCF5CDMsgLenInvalidCount_Cnt_M_u16,
						  k_PROTOHS1DYNUCF5CDMsgLenValidThresh_Cnt_u16,
						  k_PROTOHS1DYNUCF5CDMsgLenInvalidThresh_Cnt_u16,
						  NTC_Num_InvalidMsg_Z);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ComputerRazGCT_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DiagMuxOn_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DmdDelestDA_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_EtatMT_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_ISDATDIRAMsgTxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNAASMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNABRMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_SrlComInput_Per1_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_ESCOffsCfgSeld_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per1_EtatMTRaw_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_EtatMTRaw_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per1
 *********************************************************************************************************************/
	VAR(uint8,   AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(float32, AUTOMATIC) Batt_Volt_T_f32;
	VAR(uint8,   AUTOMATIC) ComputerRazGCT_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint8,   AUTOMATIC) DiagMuxOn_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDAT4V2BSI552MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDATBSI3F2MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDATBSI412MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDATBSI432MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDATDIRAMsgTxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYN2CMMMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNAASMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNABRMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNCMM208MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNCMM388MsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNVOLMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYN2FRE3CDMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDYNCDS34DMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) ISDATABR50DMsgRxTime_MSec_T_u32;
	VAR(uint32,  AUTOMATIC) PROTOHS1DYNUCF5CDMsgRxTime_MSec_T_u32;
	VAR(boolean, AUTOMATIC) ISDATDIRAMsgTxInProgress_Cnt_T_lgc;
	VAR(uint16,  AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint32,  AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,   AUTOMATIC) CompteurTemporelVehiculeTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ComputerRazGCTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DateTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) BusOffCh1_Cnt_T_lgc;
	VAR(uint32,  AUTOMATIC) ISDATBSI572MsgRxTime_MSec_T_u32;

	if (TRUE == ReInitializeComponent_M_lgc)
	{
		ReInitializeComponent_M_lgc = FALSE;
		SrlComInput_ReInit();
	}


	(void)Rte_Read_AnneeEcoule_Cnt_u08(&AnneeEcoule_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	Batt_Volt_T_f32 = Rte_IRead_SrlComInput_Per1_Batt_Volt_f32();
	BusOffCh1_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc();
	CTermActive_Cnt_M_lgc = Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc();
	(void)Rte_Read_CompteurTemporelVehicule_Cnt_u32(&CompteurTemporelVehicule_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ComputerRazGCT_Cnt_u08(&ComputerRazGCT_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	Rte_IWrite_SrlComInput_Per1_ComputerRazGCTRaw_Cnt_u08(ComputerRazGCT_Cnt_T_u08);
	(void)Rte_Read_DiagMuxOn_Cnt_u08(&DiagMuxOn_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_DmdDelestDA_Cnt_u08(&DmdDelestDA_Cnt_M_u08);
	(void)Rte_Read_EtatMT_Cnt_u08(&EtatMT_Cnt_M_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	Rte_IWrite_SrlComInput_Per1_EtatMTRaw_Cnt_u08(EtatMT_Cnt_M_u08);
	(void)Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(&ISDAT4V2BSI552MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI3F2MsgRxTime_MSec_u32(&ISDATBSI3F2MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI412MsgRxTime_MSec_u32(&ISDATBSI412MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATBSI432MsgRxTime_MSec_u32(&ISDATBSI432MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATDIRAMsgTxTime_MSec_u32(&ISDATDIRAMsgTxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYN2CMMMsgRxTime_MSec_u32(&ISDYN2CMMMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCDS34DMsgRxTime_MSec_u32(&ISDYNCDS34DMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDATABR50DMsgRxTime_MSec_u32(&ISDATABR50DMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYN2FRE3CDMsgRxTime_MSec_u32(&ISDYN2FRE3CDMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNAASMsgRxTime_MSec_u32(&ISDYNAASMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNABRMsgRxTime_MSec_u32(&ISDYNABRMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCMM208MsgRxTime_MSec_u32(&ISDYNCMM208MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNCMM388MsgRxTime_MSec_u32(&ISDYNCMM388MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDYNVOLMsgRxTime_MSec_u32(&ISDYNVOLMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	(void)Rte_Read_ISDATDIRAMsgTxInProgress_Cnt_lgc(&ISDATDIRAMsgTxInProgress_Cnt_T_lgc); /* PRQA S 3426 */ /* PRQA S 3417 */

	/* To satisfy MISRA, read ISDATBSI572MsgRxTime_MSec_T_u32 no matter if ESCOffsCfgSeld_Cnt_M_lgc == TRUE */
	(void)Rte_Read_ISDATBSI572MsgRxTime_MSec_u32(&ISDATBSI572MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	/* To satisfy MISRA, read PROTOHS1DYNUCF5CDMsgRxTime_MSec_T_u32 no matter if ESCOffsCfgSeld_Cnt_M_lgc == TRUE */
	(void)Rte_Read_PROTOHS1DYNUCF5CDMsgRxTime_MSec_u32(&PROTOHS1DYNUCF5CDMsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	(void)Rte_Read_JourEcoule_Cnt_u16(&JourEcoule_Cnt_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
	RxMsgsSrlComSvcDft_Cnt_M_lgc = Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc();
	(void)Rte_Read_SecondeEcoulee_Cnt_u32(&SecondeEcoulee_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	VehicleSpeed_Kph_M_f32 = Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32();
	SystemState_Cnt_M_enum = Rte_Mode_SystemState_Mode();
	(void)Rte_Call_EpsEn_OP_GET(&EpsEn_Cnt_M_lgc);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	if( ResetTimers_Cnt_M_lgc == TRUE )
	{
		SrlComInput_ResetTimers();
		ResetTimers_Cnt_M_lgc = FALSE;
	}

	if( RxMsgsSrlComSvcDft_Cnt_M_lgc == FALSE )
	{
		/* NetOn */
		NetOn_Cnt_M_lgc = SrlComInput_GetNetOn(NetOn_Cnt_M_lgc, EpsEn_Cnt_M_lgc);

		/* BattOk */
		BattOk_Cnt_M_lgc = SrlComInput_GetBattOk(BattOk_Cnt_M_lgc, Batt_Volt_T_f32);

		/* DiagOn */
		if( ISDYNCMM208MsgRxTime_MSec_T_u32 != PrevISDYNCMM208MsgRxTime_MSec_M_u32 )
		{
			DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
			ElapsedTime_mS_T_u16 = 0u;
		}
		else
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DiagMuxOnAbsentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
		}

		if( (NetOn_Cnt_M_lgc == TRUE) &&
			(DiagMuxOn_Cnt_T_u08 == (uint8)kDIAG_MUX_ON_Enable_SCom_Diagnostics) &&
			(ElapsedTime_mS_T_u16 <= k_DiagMuxOnAbsentTimeout_mS_u16) &&
			(BattOk_Cnt_M_lgc == TRUE) &&
			(BusOffCh1_Cnt_T_lgc == FALSE) )
		{
			DiagOn_Cnt_M_lgc = TRUE;
		}
		else
		{
			DiagOn_Cnt_M_lgc = FALSE;
		}

		/* EngOn */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngOnAbsentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
		if( ElapsedTime_mS_T_u16 >= D_ENGONTIMEOUT_MS_U08 )
		{
			EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
			CountEtatMT_Cnt_M_u08 = 0u;
			EngOn_Cnt_M_lgc = FALSE;
		}

		/* NTC 101 - EPS Mute */
		if (DiagOn_Cnt_M_lgc == TRUE)
		{
			if( ISDATDIRAMsgTxInProgress_Cnt_T_lgc == FALSE )
			{
				ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;
				if( ISDATDIRAMsgTxTime_MSec_T_u32 != PrevISDATDIRAMsgTxTime_MSec_M_u32 )
				{
					ISDATDIRASentFltAcc_Cnt_M_u16 = DiagNStep_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str);
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATDIRASentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
				if( ElapsedTime_mS_T_u16 >= k_ISDATDIRASentTimeout_mS_u16 )
				{
					ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;
					ISDATDIRASentFltAcc_Cnt_M_u16 = DiagPStep_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str);
				}
			}
		}
		else
		{
			ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;
			ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);
		}
		PrevISDATDIRAMsgTxTime_MSec_M_u32 = ISDATDIRAMsgTxTime_MSec_T_u32;

		if( ISDATDIRASentFltAcc_Cnt_M_u16 == 0u )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1NodeMute, 0u, NTC_STATUS_PASSED);
		}
		else if( DiagFailed_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str) == TRUE)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1NodeMute, 0u, NTC_STATUS_FAILED);
		}
		else
		{
			;
		}

		/*** IS_DYN_VOL Message Handling ***/
		if(CAVHCSelected_Cnt_M_lgc == TRUE)   /* Process  305 only when CAV_HC enabled */
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNVOLMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 151 - Missing IS_DYN_VOL Message (Msg ID 305) */
			MissingMessageNTCProcessing(ISDYNVOLMsgRxTime_MSec_T_u32,
										PrevISDYNVOLMsgRxTime_MSec_M_u32,
										&ISDYNVOLMsgTimer_mS_M_u32,
										&ISDYNVOLMsgTimeValidCount_Cnt_M_u16,
										k_Cav305MsgTimeout_mS_u16,
										k_ISDYNVOLMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_S);

			if( ElapsedTime_mS_T_u16 > D_ISDYNVOLMSGTIMEOUT_MS_U16 ) /* Message missing */
			{
				SrlComInput_ResetMsgIsDynVol_305();
			}
		}

		/*** IS_DYN_ABR Message Handling ***/
		if( *Rte_Pim_VVHTYPEData() == 2u )
		{
            (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNABRMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

            /* NTC 131 - Missing IS_DYN_ABR Message (Msg ID 38D) */
			MissingMessageNTCProcessing(ISDYNABRMsgRxTime_MSec_T_u32,
										PrevISDYNABRMsgRxTime_MSec_M_u32,
										&ISDYNABRMsgTimer_mS_M_u32,
										&ISDYNABRMsgTimeValidCount_Cnt_M_u16,
										k_Esc38DMsgTimeout_mS_u16,
										k_ISDYNABRMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_O);

			if( ElapsedTime_mS_T_u16 > D_ISDYNABRMSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDynAbr_38D();
			}
		}
		else
		{
		    ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		}

		/*** IS_DYN_CMM_388 Message Handling ***/
		if( *Rte_Pim_VVHTYPEData() == 1u )
		{
            (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNCMM388MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 169 - Missing IS_DYN_CMM Message (Msg ID 388) */
			MissingMessageNTCProcessing(ISDYNCMM388MsgRxTime_MSec_T_u32,
										PrevISDYNCMM388MsgRxTime_MSec_M_u32,
										&ISDYNCMM388MsgTimer_mS_M_u32,
										&ISDYNCMM388MsgTimeValidCount_Cnt_M_u16,
										k_CMM388MsgTimeout_mS_u16,
										k_ISDYNCMM388MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_V);

			if( ElapsedTime_mS_T_u16 > D_ISDYNCMMMSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDynCmm_388();
			}
		}
		else
		{
			ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		}

		/*** IS_DYN_AAS Message Handling ***/
		if( CityParkSelected_Cnt_M_lgc == TRUE )
		{
		    (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNAASMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

		    /* NTC 149 - Missing IS_DYN_AAS Message (Msg ID 2EB) */
			MissingMessageNTCProcessing(ISDYNAASMsgRxTime_MSec_T_u32,
										PrevISDYNAASMsgRxTime_MSec_M_u32,
										&ISDYNAASMsgTimer_mS_M_u32,
										&ISDYNAASMsgTimeValidCount_Cnt_M_u16,
										k_Aas2EBMsgTimeout_mS_u16,
										k_ISDYNAASMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_R);

			if( ElapsedTime_mS_T_u16 > D_ISDYNAASMSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDynAas_2EB();
			}
			else
			{
                CityParkInputMsgTimer_mS_M_u32 = ISDYNAASMsgRxTime_MSec_T_u32;
            }

            (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CityParkInputMsgTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
            if( ElapsedTime_mS_T_u16 > D_ISDYNAASMSGTIMEOUT_MS_U16 )
            {
                DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
                CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
            }
		}


		/*** IS_DYN_CMM_208 Message Handling ***/
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNCMM208MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

		/* NTC 121 - Missing IS_DYN_CMM Message (Msg ID 208) */
		MissingMessageNTCProcessing(ISDYNCMM208MsgRxTime_MSec_T_u32,
									PrevISDYNCMM208MsgRxTime_MSec_M_u32,
									&ISDYNCMM208MsgTimer_mS_M_u32,
									&ISDYNCMM208MsgTimeValidCount_Cnt_M_u16,
									k_Emn208MsgTimeout_mS_u16,
									k_ISDYNCMM208MsgTimeValidThresh_Cnt_u16,
									NTC_Num_MissingMsg_M);

		if( ElapsedTime_mS_T_u16 > D_ISDYNCMM208MSGTIMEOUT_MS_U16 )
		{
			SrlComInput_ResetMsgIsDynCmm_208();
		}

		/*** IS_DYN2_CMM Message Handling ***/
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYN2CMMMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

		/* NTC 129 - Missing IS_DYN2_CMM Message (Msg ID 348) */
		MissingMessageNTCProcessing(ISDYN2CMMMsgRxTime_MSec_T_u32,
									PrevISDYN2CMMMsgRxTime_MSec_M_u32,
									&ISDYN2CMMMsgTimer_mS_M_u32,
									&ISDYN2CMMMsgTimeValidCount_Cnt_M_u16,
									k_Emn348MsgTimeout_mS_u16,
									k_ISDYN2CMMMsgTimeValidThresh_Cnt_u16,
									NTC_Num_MissingMsg_N);

		if( ElapsedTime_mS_T_u16 > D_ISDYN2CMMMSGTIMEOUT_MS_U16 )
		{
			EngOnDLCInvalidCount_Cnt_M_u08 = 0u;
			Msg348Valid_Cnt_M_lgc = FALSE;
			ValidEngineStatusCount_Cnt_M_u08 = 0u;
			SrlComInput_ResetMsgIsDyn2Cmm_348();
		}

		/*** IS_DAT_BSI_3F2 Message Handling ***/
		if( (TRUE == STTdSelected_Cnt_M_lgc) || (TRUE == LXASelected_Cnt_M_lgc) )
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI3F2MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 141 - Missing IS_DAT_BSI_3F2 (Msg ID 3F2) */
			MissingMessageNTCProcessing(ISDATBSI3F2MsgRxTime_MSec_T_u32,
										PrevISDATBSI3F2MsgRxTime_MSec_M_u32,
										&ISDATBSI3F2MsgTimer_mS_M_u32,
										&ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16,
										k_Bsi3F2MsgTimeout_mS_u16, /* TCONF_LKA_DEF*/
										k_ISDATBSI3F2MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_Q);

			if( ElapsedTime_mS_T_u16 > D_ISDATBSI3F2MSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDatBsi_3F2();
			}
		}

		if (TRUE == STTdSelected_Cnt_M_lgc)
		{
			/* NTC 146 - Invalid Power Cut Request (Msg ID 3F2) */
			if( (DmdDelestDA_Cnt_M_u08 != (uint8)kDMD_DELEST_DA_Power_Cut_Request) ||
				(VehicleSpeed_Kph_M_f32 < k_PowerCutVehSpdLowThresh_Kph_f32) ||
				(VehicleSpeedValid_Cnt_M_lgc == FALSE) )
			{
				DmdDelestDATimer_mS_M_u32 = SystemTime_mS_M_u32;
			}

			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DmdDelestDATimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			if( (DmdDelestDA_Cnt_M_u08 == (uint8)kDMD_DELEST_DA_Power_Cut_Request) &&
					( (ElapsedTime_mS_T_u16 >= k_PowerCutVehSpdLowTimeout_mS_u16) ||
					( (VehicleSpeed_Kph_M_f32 >= k_PowerCutVehSpdHighThresh_Kph_f32) &&
						(VehicleSpeedValid_Cnt_M_lgc == TRUE) ) ) )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_FAILED);
				DmdDelestDaVld_Cnt_M_lgc = FALSE;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_PASSED);
			}
		}

		/*** IS_DAT_BSI_412 Message Handling ***/
		if( MultimodeSelected_Cnt_M_lgc == TRUE )
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI412MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
			/* NTC 159 - Missing IS_DAT_BSI_412 Message (Msg ID 412) */
			MissingMessageNTCProcessing(ISDATBSI412MsgRxTime_MSec_T_u32,
										PrevISDATBSI412MsgRxTime_MSec_M_u32,
										&ISDATBSI412MsgTimer_mS_M_u32,
										&ISDATBSI412MsgTimeValidCount_Cnt_M_u16,
										k_Bsi412MsgTimeout_mS_u16,
										k_ISDATBSI412MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_T);

			if( ElapsedTime_mS_T_u16 > D_ISDATBSI412MSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDatBsi_412();
				MultimodeValidCount_Cnt_M_u16 = 0u;
			}
		}

		/*** IS_DAT_BSI_432 Message Handling ***/
		if( k_JDD2010Selected_Cnt_lgc == TRUE )
		{
            (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI432MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 139 - Missing IS_DAT_BSI Message (Msg ID 432) */
			MissingMessageNTCProcessing(ISDATBSI432MsgRxTime_MSec_T_u32,
										PrevISDATBSI432MsgRxTime_MSec_M_u32,
										&ISDATBSI432MsgTimer_mS_M_u32,
										&ISDATBSI432MsgTimeValidCount_Cnt_M_u16,
										k_Bsi432MsgTimeout_mS_u16,
										k_ISDATBSI432MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_P);

			if( ElapsedTime_mS_T_u16 > D_ISDATBSI432MSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDatBsi_432();
                Msg432Valid_Cnt_M_lgc = FALSE;
			}
		}

		/*** IS_DAT_BSI_572 (Msg ID  572) Message Handling ***/
		if(ESCOffsCfgSeld_Cnt_M_lgc == TRUE)   /* Process  572 only when Turns Counter enabled */
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI572MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 181 - Missing IS_DAT_BSI_572 Message (Msg ID 572) */
			MissingMessageNTCProcessing(ISDATBSI572MsgRxTime_MSec_T_u32,
										PrevISDATBSI572MsgRxTime_MSec_M_u32,
										&ISDATBSI572MsgTimer_mS_M_u32,
										&ISDATBSI572MsgTimeValidCount_Cnt_M_u16,
										k_Bsi572MsgTimeout_mS_u16,
										k_ISDATBSI572MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_Y);


			if( ElapsedTime_mS_T_u16 > D_ISDATBSI572MSGTIMEOUT_MS_U16 ) /* message not received for more than periodicity + 10% of time. Clear all valid counters */
			{
				SrlComInput_ResetMsgIsDatBsi_572();
			}
		}

		/*** IS_DAT4_V2_BSI_552 Message Handling ***/
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDAT4V2BSI552MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

		/* NTC 161 - Missing IS_DAT4_BSI_552 Message (Msg ID 552) */
		MissingMessageNTCProcessing(ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
									PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
									&ISDAT4V2BSI552MsgTimer_mS_M_u32,
									&ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16,
									k_Bsi552MsgTimeout_mS_u16,
									k_ISDAT4V2BSI552MsgTimeValidThresh_Cnt_u16,
									NTC_Num_MissingMsg_U);

		if( ElapsedTime_mS_T_u16 > D_ISDAT4V2BSI552MSGTIMEOUT_MS_U16 )
		{
			SrlComInput_ResetMsgIsDat4V2Bsi_552();
			Msg552Valid_Cnt_M_lgc = FALSE;
		}

		if( k_JDD2010Selected_Cnt_lgc == TRUE )
		{
			/* NTC 164 - CPT_TEMPOREL Invalid (Msg ID 552) */
			if( CompteurTemporelVehicule_Cnt_T_u32 == D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32 )
			{
				CompteurTemporelVehiculeTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			else
			{
				CompteurTemporelVehiculeTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}

			MixedTimeValidityNTCProcessing(CompteurTemporelVehiculeTestStatus_Cnt_T_u08,
										   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
										   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
										   &CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32,
										   &CompteurTemporelVehiculeSigValidCount_Cnt_M_u16,
										   k_CptTemporelSigInvalidTimeout_mS_u16,
										   k_CptTemporelSigValidThresh_Cnt_u16,
										   NTC_Num_DataRngFltMsg_U);

			/* NTC 165 - COMPUTER_RAZ_GCT Invalid (Msg ID 552) */
			if( ComputerRazGCT_Cnt_T_u08 == D_COMPUTERRAZGCTINVALID_CNT_U08 )
			{
				ComputerRazGCTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			else
			{
				ComputerRazGCTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}

			MixedTimeValidityNTCProcessing(ComputerRazGCTTestStatus_Cnt_T_u08,
										   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
										   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
										   &ComputerRazGCTSigInvalidTimer_mS_M_u32,
										   &ComputerRazGCTSigValidCount_Cnt_M_u16,
										   k_ComputerRazGCTSigInvalidTimeout_mS_u16,
										   k_ComputerRazGCTSigValidThresh_Cnt_u16,
										   NTC_Num_DataRateFltMsg_U);
		}
		else
		{
			/* NTC 166 - Date 2004 invalid (Msg ID 552) */
			if( (AnneeEcoule_Cnt_T_u08 == D_ANNEEECOULEINVALID_CNT_U08) ||
				(JourEcoule_Cnt_T_u16 == D_JOURECOULEINVALID_CNT_U16) ||
				(SecondeEcoulee_Cnt_T_u32 == D_SECONDEECOULEEINVALID_CNT_U32) )
			{
				DateTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			else
			{
				DateTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}

			MixedTimeValidityNTCProcessing(DateTestStatus_Cnt_T_u08,
										   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
										   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
										   &DateInvalidTimer_mS_M_u32,
										   &DateValidCount_Cnt_M_u16,
										   k_DateValidSigInvalidTimeout_mS_u16,
										   k_DateValidThresh_Cnt_u16,
										   NTC_Num_DataOtherFltMsg_U);
		}

		/*** ISDYNCDS34D Message Handling ***/
		if (TRUE == LXASelected_Cnt_M_lgc)
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNCDS34DMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
			/* NTC 171 - Missing IS_DYN_CDS_34D Message (Msg ID 34D) */
			MissingMessageNTCProcessing(ISDYNCDS34DMsgRxTime_MSec_T_u32,
										PrevISDYNCDS34DMsgRxTime_MSec_M_u32,
										&ISDYNCDS34DMsgTimer_mS_M_u32,
										&ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16,
										k_CDS34DMsgTimeout_mS_u16,
										k_ISDYNCDS34DMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_W);

			if( ElapsedTime_mS_T_u16 > D_ISDYNCDS34DMSGTIMEOUT_MS_U16 )
			{
				SrlComInput_ResetMsgIsDynCds_34D();
			}
		}

		/*** ISDATABR50D Message Handling ***/
		if (TRUE == LXASelected_Cnt_M_lgc)
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATABR50DMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
			/* NTC 179 - Missing IS_DYN_CDS_50D Message (Msg ID 50D) */
			MissingMessageNTCProcessing(ISDATABR50DMsgRxTime_MSec_T_u32,
										PrevISDATABR50DMsgRxTime_MSec_M_u32,
										&ISDATABR50DMsgTimer_mS_M_u32,
										&ISDATABR50DMsgTimeValidCount_Cnt_M_u16,
										k_CDS50DMsgTimeout_mS_u16,
										k_ISDATABR50DMsgTimeValidCount_Cnt_u16,
										NTC_Num_MissingMsg_X);

			if (ElapsedTime_mS_T_u16 > D_ISDATABR50DMSGTIMEOUT_MS_U16)
			{
				SrlComInput_ResetMsgIsDatAbr_50D();
			}
		}

		/*** ISDYN2FRE3CD Message Handling ***/
		if (2u == *Rte_Pim_VVHTYPEData())
		{
            (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYN2FRE3CDMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 191 - Missing IS_DYN2_FRE_3CD Message (Msg ID 3CD) */
			MissingMessageNTCProcessing(ISDYN2FRE3CDMsgRxTime_MSec_T_u32,
										PrevISDYN2FRE3CDMsgRxTime_MSec_M_u32,
										&ISDYN2FRE3CDMsgTimer_mS_M_u32,
										&ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16,
										k_Esc3CDMsgTimeout_mS_u16,
										k_ISDYN2FRE3CDMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_AA);

			if( ElapsedTime_mS_T_u16 > D_ISDYN2FRE3CDMSGTIMEOUT_MS_U16 )
			{
                AccelLatInvalidityCount_Cnt_M_u16 = 0u;
                AccelLatValidityCount_Cnt_M_u16 = 0u;
				SrlComInput_ResetMsgIsDyn2Fre_3CD();
			}
		}
        else
        {
            ISDYN2FRE3CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
        }

		/*** PROTO_HS1_DYN_UCF_5CD (Msg ID  5CD) Message Handling ***/
		if(ESCOffsCfgSeld_Cnt_M_lgc == TRUE)   /* Process  5CD only when Turns Counter enabled */
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PROTOHS1DYNUCF5CDMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

			/* NTC 189 - Missing PROTO_HS1_DYN_UCF_5CD Message (Msg ID 5CD) */
			MissingMessageNTCProcessing(PROTOHS1DYNUCF5CDMsgRxTime_MSec_T_u32,
										PrevPROTOHS1DYNUCF5CDMsgRxTime_MSec_M_u32,
										&PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32,
										&PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16,
										k_Esc5CDMsgTimeout_mS_u16,
										k_PROTOHS1DYNUCF5CDMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_Z);


			if( ElapsedTime_mS_T_u16 > D_PROTOHS1DYNUCF5CDMSGTIMEOUT_MS_U16 ) /* Message missing */
			{
				SrlComInput_ResetMsgProtoHs1DynUcf_5CD();
			}
		}
	}
	else /* ( RxMsgsSrlComSvcDft_Cnt_M_lgc == TRUE ) */
	{
		ISDATBSI572MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgChkSumInvalidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16 = 0u;
		PROTOHS1DYNUCF5CDMsgCountInvalidCount_Cnt_M_u16 = 0u;
		OffsetSigValidCount_Cnt_M_u16 = 0u;
		OffsetSigInvalidCount_Cnt_M_u16 = 0u;
		PrecisionOffsetSigValidCount_Cnt_M_u16 = 0u;
		PrecisionOffsetSigInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI572MsgTimeValidCount_Cnt_M_u16 = 0u;
		ISDATBSI572MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI572MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ConfigVhlSigValidCount_Cnt_M_u16 = 0u;
		ConfigVhlSigInvalidCount_Cnt_M_u16 = 0u;
		PrevConfigVhl_Cnt_M_u08 = 0u;
		ConfigVhlSigUpdCount_Cnt_M_u16 = 0u;
		ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
		EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
		CountEtatMT_Cnt_M_u08 = 0u;
		PrevEtatMT_Cnt_M_u08 = (uint8)kETAT_MT_Cut;
		ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);
		ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
		CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
		EtatMTSigValidCount_Cnt_M_u16 = 0u;
		EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		DmdDelestDATimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYNCDS34DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDATABR50DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDYN2FRE3CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCDS34DMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATABR50DMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYN2FRE3CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
		CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
		ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
		CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
		ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
		DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
		DateInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
		DateValidCount_Cnt_M_u16 = 0u;
		AccelLatInvalidCount_Cnt_M_u16 = 0u;
		AccelLatValidCount_Cnt_M_u16 = 0u;
		AccelLatInvalidityCount_Cnt_M_u16 = 0u;
		AccelLatValidityCount_Cnt_M_u16 = 0u;
		ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16 = 0u;
		ISDYNCDS34DMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATABR50DMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATABR50DMsgTimeValidCount_Cnt_M_u16 = 0u;
		ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16 = 0u;
		ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16 = 0u;

		DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
		CityParkInputConsistentCount_Cnt_M_u16 = 0u;

		ColumnAngleSetpointValidCount_Cnt_M_u16 = 0u;
		ColumnAngleSetpointInvalidCount_Cnt_M_u16 = 0u;
		LKATrqFactReqValidCount_Cnt_M_u16 = 0u;
		LKAStateValidCount_Cnt_M_u16 = 0u;
		LKATrqFactReqInvalidCount_Cnt_M_u16 = 0u;
		LKAStateInvalidCount_Cnt_M_u16 = 0u;
		DmdDelestDASigUpdCount_Cnt_M_u16 = 0u;
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ESPDeconnecte_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_RegulAbr_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_RegulEsp_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ReqLampeDefEsp_Cnt_u08(UInt8 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_Per2_DefaultVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DmdDelestDaSts_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DmdDelestDaVld_Cnt_lgc(Boolean data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per2_APAAuthn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_APAAuthn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_APARequest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_APARequest_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_AbsActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_AbsActv_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_AngleVolant_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_AngleVolant_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(void)
 *   void Rte_IWrite_SrlComInput_Per2_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_SrlComInput_Per2_EnergyModeState_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_EngOn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EngOn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscActv_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscEna_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscEna_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Per2_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Per2_LxaInpVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_LxaInpVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_LxaStateFilt_Cnt_enum(PsaLxaSt_Cnt_enum data)
 *   PsaLxaSt_Cnt_enum *Rte_IWriteRef_SrlComInput_Per2_LxaStateFilt_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_MultiModeVld_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_MultiModeVld_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(PsaTunModSt_Cnt_enum data)
 *   PsaTunModSt_Cnt_enum *Rte_IWriteRef_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(void)
 *   void Rte_IWrite_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_SrlComVehSpd_Kph_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehTimeValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(void)
 *   void Rte_IWrite_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DmdDelestDa(void)
 *   void Rte_Exit_DmdDelestDa(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) SrlComVehSpd_Kph_T_f32;
	VAR(uint8, AUTOMATIC) InvalidMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VehicleSpeedFaultStatus_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SerialComAngleValid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) MissingMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) CRCFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PgrsCntFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgV_Cnt_T_u08;
	VAR(float32, AUTOMATIC) AbsVehSpdDelta_Kph_T_f32;
	VAR(boolean, AUTOMATIC) LXANTCsOk_Cnt_T_lgc = TRUE;
	VAR(boolean, AUTOMATIC) DefaultVehSpd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ESPDeconnecte_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RegulAbr_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RegulEsp_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) ReqLampeDefEsp_Cnt_T_lgc = TRUE;
	VAR(boolean, AUTOMATIC) ESPDeconnecte_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) RegulAbr_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) RegulEsp_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) ReqLampeDefEsp_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CMMDataMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BSIDataMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ValidEngineStatus_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ElectronicIntegration_Cnt_T_lgc;
	VAR(Dem_ReturnClearDTCType, AUTOMATIC) ClearDTCRetVal_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) EscDataVldFromSerlCom_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EscAckFromSerlCom_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	DefaultVehSpd_Cnt_T_lgc = Rte_IRead_SrlComInput_Per2_DefaultVehSpd_Cnt_lgc();
	(void)Rte_Read_ESPDeconnecte_Cnt_u08(&ESPDeconnecte_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_RegulAbr_Cnt_u08(&RegulAbr_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_RegulEsp_Cnt_u08(&RegulEsp_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ReqLampeDefEsp_Cnt_u08(&ReqLampeDefEsp_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
	* They cannot interrupt eachother. Aslo access to it is atomic */
	ElectronicIntegration_Cnt_T_lgc = *Rte_Pim_ElecIntData();

	if( RxMsgsSrlComSvcDft_Cnt_M_lgc == FALSE )
	{
		if( ElectronicIntegration_Cnt_T_lgc == TRUE )
		{
			if( (DiagOn_Cnt_M_lgc == TRUE) ||
				(ElectronicIntegrationCmd_Cnt_M_lgc == FALSE) ||
				(CTermActive_Cnt_M_lgc == TRUE) ||
				(EpsEn_Cnt_M_lgc == FALSE) )
			{
				ElecIntCount_Cnt_M_u08 = 0u;
				ElectronicIntegrationCmd_Cnt_M_lgc = FALSE;
				/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
				* They cannot interrupt eachother. Aslo access to it is atomic */
				*Rte_Pim_ElecIntData() = FALSE;
				ElectronicIntegrationWriteSucceeded_Cnt_M_lgc = Rte_Call_ElecInt_WriteBlock(NULL_PTR);

				(void)Rte_Call_SrlComDriver_SCom_ElecIntStop(); /* PRQA S 3426 */ /* PRQA S 3417 */
			}
		}
		else
		{
			if( (ElectronicIntegrationCmd_Cnt_M_lgc == TRUE) &&
				(DiagOn_Cnt_M_lgc == FALSE) &&
				(CTermActive_Cnt_M_lgc == FALSE) &&
				(SystemState_Cnt_M_enum != RTE_MODE_StaMd_Mode_OPERATE) )
			{
				ElecIntCount_Cnt_M_u08 = 0u;
				/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
				* They cannot interrupt eachother. Aslo access to it is atomic */
				*Rte_Pim_ElecIntData() = TRUE;
				ElectronicIntegrationWriteSucceeded_Cnt_M_lgc = Rte_Call_ElecInt_WriteBlock(NULL_PTR);

				(void)Rte_Call_SrlComDriver_SCom_ElecIntStart(); /* PRQA S 3426 */ /* PRQA S 3417 */
			}
		}

		if (E_NOT_OK == ElectronicIntegrationWriteSucceeded_Cnt_M_lgc)
		{
			ElectronicIntegrationWriteSucceeded_Cnt_M_lgc = Rte_Call_ElecInt_WriteBlock(NULL_PTR);
		}

		if( ClearDTCs_Cnt_M_lgc == TRUE )
		{
			if (SystemState_Cnt_M_enum != RTE_MODE_StaMd_Mode_OFF)
			{
				ClearDTCRetVal_Cnt_T_enum = NtWrapC_Dem_ClearDTC(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS, (Dem_DTCOriginType)DEM_DTC_ORIGIN_PRIMARY_MEMORY);

				if( ClearDTCRetVal_Cnt_T_enum != (Dem_ReturnClearDTCType)DEM_DTC_PENDING )
				{
					ClearDTCs_Cnt_M_lgc = FALSE;
				}
			}
			else
			{
				ClearDTCs_Cnt_M_lgc = FALSE;
			}
		}

		/* Serial Com Angle Validity */
		if (TRUE == CAVHCSelected_Cnt_M_lgc)
		{
			SerialComAngleValid_Cnt_T_lgc = SrlComInput_GetSCommAngleValidNTCsStatus();
		}
		else
		{
			SerialComAngleValid_Cnt_T_lgc = FALSE;
		}

		/* Multimode Validity */
		MultimodeVld_Cnt_M_lgc = SrlComInput_GetMultimodeNTCsStatus();

		/* Lateral Acceleration and validity */
		AccelLatValidity_Cnt_M_lgc = SrlComInput_GetVehicleLatAccelNTCsStatus();

		/* LXA Validity */
		LXANTCsOk_Cnt_T_lgc = GetLXANTCsStatus();

		/* Vehicle Speed and Validity */
		if ((0u == *Rte_Pim_VVHTYPEData()) ||
			(DefaultVehSpd_Cnt_T_lgc == TRUE))
		{
			SrlComVehSpd_Kph_T_f32 = k_DefaultVehSpd_Kph_f32;
			VehicleSpeedValid_Cnt_M_lgc = FALSE;
			VehSpdSync_Cnt_M_lgc = FALSE;
			ApaVehicleSpeedValid_Cnt_M_lgc = FALSE;
		}
		else
		{
			SrlComVehSpd_Kph_T_f32 = SrlComVehSpd_Kph_M_f32;
			AbsVehSpdDelta_Kph_T_f32 = Abs_f32_m(VehicleSpeed_Kph_M_f32 - SrlComVehSpd_Kph_T_f32);

			if ( 2u == *Rte_Pim_VVHTYPEData() )
			{
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_O, &InvalidMsgO_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_O, &MissingMsgO_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_O, &CRCFltMsgO_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_O, &PgrsCntFltMsgO_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_O, &DataRngFltMsgO_Cnt_T_u08);

				VehicleSpeedFaultStatus_Cnt_T_u08 = InvalidMsgO_Cnt_T_u08 	 |
													MissingMsgO_Cnt_T_u08 	 |
													CRCFltMsgO_Cnt_T_u08	 |
													PgrsCntFltMsgO_Cnt_T_u08 |
													DataRngFltMsgO_Cnt_T_u08;

			}
			else /* ( 1u == *Rte_Pim_VVHTYPEData() ) */
			{
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_V, &InvalidMsgV_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_V, &MissingMsgV_Cnt_T_u08);
				(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_V, &DataRngFltMsgV_Cnt_T_u08);

				VehicleSpeedFaultStatus_Cnt_T_u08 = InvalidMsgV_Cnt_T_u08 	 |
													MissingMsgV_Cnt_T_u08 	 |
													DataRngFltMsgV_Cnt_T_u08;
			}


			if (D_NTC_TEST_COMPLETED_PASSED != (VehicleSpeedFaultStatus_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK))
			{
				VehicleSpeedValid_Cnt_M_lgc = FALSE;
				VehSpdSync_Cnt_M_lgc = FALSE;
			}
			else
			{
				if (AbsVehSpdDelta_Kph_T_f32 < FLT_EPSILON)
				{
					VehSpdSync_Cnt_M_lgc = TRUE;
				}

				if (TRUE == VehSpdSync_Cnt_M_lgc)
				{
					VehicleSpeedValid_Cnt_M_lgc = TRUE;
				}
				else
				{
					VehicleSpeedValid_Cnt_M_lgc = FALSE;
				}
			}

			if (D_TESTFAILEDBIT_CNT_B8 == (VehicleSpeedFaultStatus_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK))
			{
				ApaVehicleSpeedValid_Cnt_M_lgc = FALSE;
			}
			else
			{
				ApaVehicleSpeedValid_Cnt_M_lgc = TRUE;
			}
		}

		/*LKA Signals*/
		ESPDeconnecte_Cnt_T_lgc = (ESPDeconnecte_Cnt_T_u08 == 0u) ? TRUE : FALSE;
		RegulAbr_Cnt_T_lgc = (RegulAbr_Cnt_T_u08 == 1u) ? TRUE : FALSE;
		RegulEsp_Cnt_T_lgc = (RegulEsp_Cnt_T_u08 == 1u) ? TRUE : FALSE;
		ReqLampeDefEsp_Cnt_T_lgc = (ReqLampeDefEsp_Cnt_T_u08 == 1u) ? TRUE : FALSE;

		/* APA Request */
		if ( (CityParkInputConsistentCount_Cnt_M_u16 >= k_DMDFCTCPKValidCount_Cnt_u16) &&
			 ( (DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_SCP9_Control_Request) ||
			   (DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_SCP6_Control_Request) ) )
		{
			APARequest_Cnt_M_lgc = TRUE;
		}
		else if ( (CityParkInputConsistentCount_Cnt_M_u16 >= k_DMDFCTCPKValidCount_Cnt_u16) &&
				(DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_No_Request) )
		{
			APARequest_Cnt_M_lgc = FALSE;
		}
		else
		{
		}

		CPKOK_Cnt_M_lgc = SrlComInput_GetCpkOk();

		/* Demande Relaxe CityPark */
		if ( (DMDRelaxeConsistentCount_Cnt_M_u16 >= k_DMDRelaxeConsistentThresh_Cnt_u16) &&
			 (DMDRELAXECPK_Cnt_M_u08 == (uint8)kDMD_RELAXE_CPK_No_Request) )

		{
			ApaRelaxReq_Cnt_M_lgc = FALSE;
		}
		else
		{
			if(DMDRELAXECPK_Cnt_M_u08 == (uint8)kDMD_RELAXE_CPK_Relaxe_Request)
			{
				ApaRelaxReq_Cnt_M_lgc = TRUE;
			}
		}

		/* City Park Authorization */
		if( ((uint8)kETAT_MT_Engine_Running == EtatMT_Cnt_M_u08) &&
			(TRUE == EngOn_Cnt_M_lgc) )
		{
			ApaAuthn_Cnt_T_lgc = TRUE;
		}
		else
		{
			ApaAuthn_Cnt_T_lgc = FALSE;
		}

		/* STTa Determination */
		ValidEngineStatus_Cnt_T_lgc = SrlComInput_GetValidEngineStatus();


		/* CMM Info Pertinence */
		CMMDataMissing_Cnt_T_lgc = (boolean) (FALSE == Msg348Valid_Cnt_M_lgc);


		/* BSI Info Pertinence */
		if( (Msg432Valid_Cnt_M_lgc == TRUE) &&
			(Msg552Valid_Cnt_M_lgc == TRUE) )
		{
			BSIDataMissing_Cnt_T_lgc = FALSE;
		}
		else
		{
			BSIDataMissing_Cnt_T_lgc = TRUE;
		}


		/* Esc Ack and Data valid */
		SrlComInput_EscAckAndDataValid(&EscAckFromSerlCom_Cnt_T_lgc, &EscDataVldFromSerlCom_Cnt_T_lgc);
	}
	else /* ( RxMsgsSrlComSvcDft_Cnt_M_lgc == TRUE ) */
	{
		SrlComVehSpd_Kph_T_f32 = ManVehSpd_Kph_M_f32;
		SerialComAngleValid_Cnt_T_lgc = FALSE;
		CMMDataMissing_Cnt_T_lgc = FALSE;
		BSIDataMissing_Cnt_T_lgc = FALSE;
		ApaAuthn_Cnt_T_lgc = FALSE;
		ValidEngineStatus_Cnt_T_lgc = TRUE;
		VehicleSpeedValid_Cnt_M_lgc = TRUE;
		EscAckFromSerlCom_Cnt_T_lgc = FALSE;
		EscDataVldFromSerlCom_Cnt_T_lgc = FALSE;
	}


	if( VehicleSpeedValid_Cnt_M_lgc == TRUE )
	{
		CDD_SrlComVehSpd_Kph_G_f32 = SrlComVehSpd_Kph_T_f32;
	}
	else
	{
		CDD_SrlComVehSpd_Kph_G_f32 = 0.0f;
	}

	if( VehSpdControl_Cnt_M_lgc == TRUE )
	{
		SrlComVehSpd_Kph_T_f32 = 0.0f;
		VehicleSpeedValid_Cnt_M_lgc = TRUE;
	}

	if (TRUE == STTdSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DmdDelestDaStsTime_MSec_M_u32, &ElapsedTime_mS_T_u16);
		if (k_DmdDelestVldTimeout_mS_u16 < ElapsedTime_mS_T_u16)
		{
			DmdDelestDaVld_Cnt_M_lgc = FALSE;
			DmdDelestDASigUpdCount_Cnt_M_u16 = 0u;
		}
	}

	Rte_IWrite_SrlComInput_Per2_MultiModeVld_Cnt_lgc(MultimodeVld_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_ReqModeDAFinal_Cnt_enum(MultimodeSwReq_Cnt_M_u08);
	Rte_IWrite_SrlComInput_Per2_ColAngleSetpoint_HwDeg_f32(ColumnAngleSetpoint_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per2_LxaInpVld_Cnt_lgc(LXANTCsOk_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_VehicleLatAccel_MpSecSq_f32(AccelLat_MpSecSq_M_f32);
	Rte_IWrite_SrlComInput_Per2_VehicleLatAccelValid_Cnt_lgc(AccelLatValidity_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_APARequest_Cnt_lgc(APARequest_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_ApaRelaxReq_Cnt_lgc(ApaRelaxReq_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_APAAuthn_Cnt_lgc(ApaAuthn_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_AngleVolant_HwDeg_f32(AngleVolant_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per2_BSIDataMissing_Cnt_lgc(BSIDataMissing_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_CMMDataMissing_Cnt_lgc(CMMDataMissing_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_CONSANGLECPK_Cnt_s16(CONSANGLECPK_Cnt_M_s16);
	Rte_IWrite_SrlComInput_Per2_CPKOK_Cnt_lgc(CPKOK_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_DMDFCTCPK_Cnt_u08(DMDFCTCPK_Cnt_M_u08);
	/* Rte_Pim_ElecIntData PIM is read/write only from runables mapped to same task.
	 * They cannot interrupt each other. Also access to it is atomic */
	Rte_IWrite_SrlComInput_Per2_ElectronicIntegration_Cnt_lgc(*Rte_Pim_ElecIntData());
	Rte_IWrite_SrlComInput_Per2_EngOn_Cnt_lgc(EngOn_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_IgnTimeOff_Cnt_u32(IgnTimeOff_Sec_M_u32);
	Rte_IWrite_SrlComInput_Per2_PosSrvoHwAngle_HwDeg_f32(CONSANGLECPK_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per2_SerialComAngleValid_Cnt_lgc(SerialComAngleValid_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_SrlComVehSpd_Kph_f32(SrlComVehSpd_Kph_T_f32);
	Rte_IWrite_SrlComInput_Per2_ValidEngineStatus_Cnt_lgc(ValidEngineStatus_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_VehTimeValid_Cnt_lgc(VehTimeValid_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_VehicleSpeedValid_Cnt_lgc(VehicleSpeedValid_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_ApaVehicleSpeedValid_Cnt_lgc(ApaVehicleSpeedValid_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per2_AbsActv_Cnt_lgc(RegulAbr_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_EscEna_Cnt_lgc(ESPDeconnecte_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_EscActv_Cnt_lgc(RegulEsp_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_EscFltPrsnt_Cnt_lgc(ReqLampeDefEsp_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_LxaStateFilt_Cnt_enum(LKAState_Cnt_M_u08);
	Rte_IWrite_SrlComInput_Per2_EnergyModeState_Cnt_enum(EnergyModeState_Cnt_M_enum);
	Rte_IWrite_SrlComInput_Per2_EscOffsFromSerlCom_HwDeg_f32(EscOffsFromSerlCom_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per2_EscPrecisionFromSerlCom_HwDeg_f32(EscPrecisionFromSerlCom_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per2_EscAckFromSerlCom_Cnt_lgc(EscAckFromSerlCom_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per2_EscDataVldFromSerlCom_Cnt_lgc(EscDataVldFromSerlCom_Cnt_T_lgc);
	Rte_Enter_DmdDelestDa();
	(void)Rte_Write_DmdDelestDaSts_Cnt_u08(DmdDelestDaSts_Cnt_M_u08);
	(void)Rte_Write_DmdDelestDaVld_Cnt_lgc(DmdDelestDaVld_Cnt_M_lgc);
	Rte_Exit_DmdDelestDa();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_GetNetworkDiagFltAcc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNetworkDiagFltAcc> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_GetNetworkDiagFltAcc(UInt16 *MuteFltAcc_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_GetNetworkDiagFltAcc
 *********************************************************************************************************************/

	*MuteFltAcc_Cnt_T_u16 = ISDATDIRASentFltAcc_Cnt_M_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ManualVehSpd
 *********************************************************************************************************************/

	ManVehSpd_Kph_M_f32 = VehSpd_Kph_T_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ResetTimers
 *********************************************************************************************************************/

	ResetTimers_Cnt_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_VehSpdControl
 *********************************************************************************************************************/

	VehSpdControl_Cnt_M_lgc = Enable_Cnt_T_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EaShutdownTimeData(void)
 *   void Rte_Exit_EaShutdownTimeData(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Trns1
 *********************************************************************************************************************/


	VAR(uint8,   AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ISDAT4V2BSI552MsgRxTime_MSec_T_u32;
	VAR(uint16,  AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint32,  AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) InvalidMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRateFltMsgU_Cnt_T_lgc;


	(void)Rte_Read_AnneeEcoule_Cnt_u08(&AnneeEcoule_Cnt_T_u08); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_CompteurTemporelVehicule_Cnt_u32(&CompteurTemporelVehicule_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(&ISDAT4V2BSI552MsgRxTime_MSec_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_JourEcoule_Cnt_u16(&JourEcoule_Cnt_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Read_SecondeEcoulee_Cnt_u32(&SecondeEcoulee_Cnt_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_U, &InvalidMsgU_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_U, &MissingMsgU_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_U, &DataRngFltMsgU_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRateFltMsg_U, &DataRateFltMsgU_Cnt_T_lgc);

	Rte_Enter_EaShutdownTimeData(); /* PRQA S 3138 */ /* PRQA S 3112 */
	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		if( (CompteurTemporelVehicule_Cnt_T_u32 != D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32) &&
			(ISDAT4V2BSI552MsgRxTime_MSec_T_u32 > 0ul) &&
			(InvalidMsgU_Cnt_T_lgc == FALSE) &&
			(MissingMsgU_Cnt_T_lgc == FALSE) &&
			(DataRngFltMsgU_Cnt_T_lgc == FALSE) &&
			(DataRateFltMsgU_Cnt_T_lgc == FALSE) )
		{
			(Rte_Pim_ShutdownTimeData())->Time_Sec_u32 = CompteurTemporelVehicule_Cnt_T_u32 / D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32;
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = TRUE;
		}
		else
		{
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = FALSE;
		}
	}
	else
	{
		if( (AnneeEcoule_Cnt_T_u08 != D_ANNEEECOULEINVALID_CNT_U08) &&
			(JourEcoule_Cnt_T_u16 != D_JOURECOULEINVALID_CNT_U16) &&
			(SecondeEcoulee_Cnt_T_u32 != D_SECONDEECOULEEINVALID_CNT_U32) &&
			(ISDAT4V2BSI552MsgRxTime_MSec_T_u32 > 0ul) &&
			(InvalidMsgU_Cnt_T_lgc == FALSE) &&
			(MissingMsgU_Cnt_T_lgc == FALSE) )
		{
			(Rte_Pim_ShutdownTimeData())->Time_Sec_u32 = (((uint32)AnneeEcoule_Cnt_T_u08) * D_SECONDSPERYEAR_CNT_U32) +
														(((uint32)JourEcoule_Cnt_T_u16) * D_SECONDSPERDAY_CNT_U32) +
														SecondeEcoulee_Cnt_T_u32;

			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = TRUE;
		}
		else
		{
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = FALSE;
		}
	}
	Rte_Exit_EaShutdownTimeData(); /* PRQA S 3138 */ /* PRQA S 3112 */
	(void)Rte_Call_ShutdownTime_WriteBlock(NULL_PTR);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Trns2_Kilometrage_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_LxaSeln_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Trns2_LxaSeln_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(void)
 *   void Rte_IWrite_SrlComInput_Trns2_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Trns2_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Trns2_ShuntPosition_Cnt_u08(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Trns2
 *********************************************************************************************************************/
	PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32 = Rte_InitValue_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32;
	LxATqFacReq_Uls_M_f32 = Rte_InitValue_LxaTqFacReq_Uls_f32;

	Rte_IWrite_SrlComInput_Trns2_CompteurTemporelVehiculeRaw_Cnt_u32(Rte_InitValue_CompteurTemporelVehiculeRaw_Cnt_u32);
	Rte_IWrite_SrlComInput_Trns2_EtatPrincipSev_Cnt_u08(Rte_InitValue_EtatPrincipSev_Cnt_u08);
	Rte_IWrite_SrlComInput_Trns2_EtatReseauElec_Cnt_u08(Rte_InitValue_EtatReseauElec_Cnt_u08);
	Rte_IWrite_SrlComInput_Trns2_ISDAT4V2BSI552MsgRxTimeRaw_MSec_u32(PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32);
	Rte_IWrite_SrlComInput_Trns2_Kilometrage_Cnt_u32(Rte_InitValue_Kilometrage_Cnt_u32);
	Rte_IWrite_SrlComInput_Trns2_LxaSeln_Cnt_lgc(Rte_InitValue_LxaSeln_Cnt_lgc);
	Rte_IWrite_SrlComInput_Trns2_LxaTqFacReq_Uls_f32(LxATqFacReq_Uls_M_f32);
	Rte_IWrite_SrlComInput_Trns2_PowerSupplies_Cnt_u08(Rte_InitValue_PowerSupplies_Cnt_u08);
	Rte_IWrite_SrlComInput_Trns2_ShuntPosition_Cnt_u08(Rte_InitValue_ShuntPosition_Cnt_u08);

	ReInitializeComponent_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ReInit(void)
{
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_M_u32); /* PRQA S 3426 */ /* PRQA S 3417 */

	VehicleSpeed_Kph_M_f32 = 0.0f;
	PrevISDATBSI3F2MsgRxTime_MSec_M_u32 = 0u;
	PrevISDATBSI412MsgRxTime_MSec_M_u32 = 0u;
	PrevISDATBSI432MsgRxTime_MSec_M_u32 = 0u;
	PrevISDYN2CMMMsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNAASMsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNABRMsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNCMM208MsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNCMM388MsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNVOLMsgRxTime_MSec_M_u32 = 0u;
	PrevISDATABR50DMsgRxTime_MSec_M_u32 = 0u;
	PrevISDYN2FRE3CDMsgRxTime_MSec_M_u32 = 0u;
	PrevISDYNCDS34DMsgRxTime_MSec_M_u32 = 0u;
	PrevISDATDIRAMsgTxTime_MSec_M_u32 = 0u;
	CONSANGLECPK_HwDeg_M_f32 = 0.0f;
	AccelLat_MpSecSq_M_f32 = 0.0f;
	ColumnAngleSetpoint_HwDeg_M_f32 = 0.0f;
	PrevPROTOHS1DYNUCF5CDMsgRxTime_MSec_M_u32 = 0u;
	PrevISDATBSI572MsgRxTime_MSec_M_u32 = 0u;
	ISDYNVOLMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
	EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
	EtatMTSigValidCount_Cnt_M_u16 = 0u;
	CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
	CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
	DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
	DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
	DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
	DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
	DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
	ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
	ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
	VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
	VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
	CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
	ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
	DateValidCount_Cnt_M_u16 = 0u;
	AccelLatValidCount_Cnt_M_u16 = 0u;
	AccelLatInvalidCount_Cnt_M_u16 = 0u;
	AccelLatValidityCount_Cnt_M_u16 = 0u;
	AccelLatInvalidityCount_Cnt_M_u16 = 0u;
	ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
	CityParkInputConsistentCount_Cnt_M_u16 = 0u;
	CONSANGLECPK_Cnt_M_s16 = 0;
	LKATrqFactReqInvalidCount_Cnt_M_u16 = 0u;
	LKAStateInvalidCount_Cnt_M_u16 = 0u;
	LKATrqFactReqValidCount_Cnt_M_u16 = 0u;
	LKAStateValidCount_Cnt_M_u16 = 0u;
	ColumnAngleSetpointValidCount_Cnt_M_u16 = 0u;
	ColumnAngleSetpointInvalidCount_Cnt_M_u16 = 0u;
	MultimodeValidCount_Cnt_M_u16 = 0u;
	MultimodeInvalidCount_Cnt_M_u16 = 0u;
	OffsetDataConsistentCount_Cnt_M_u16 = 0u;
	OffsetDataInconsistentCount_Cnt_M_u16 = 0u;
	OffsetValidCount_Cnt_M_u16 = 0u;
	OffsetInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16 = 0u;
	OffsetSigValidCount_Cnt_M_u16 = 0u;
	PrecisionOffsetSigValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgChkSumInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgCountInvalidCount_Cnt_M_u16 = 0u;
	OffsetSigInvalidCount_Cnt_M_u16 = 0u;
	PrecisionOffsetSigInvalidCount_Cnt_M_u16 = 0u;
	Offset_Cnt_M_u16 = 0u;
	ISDATBSI572MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigValidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigInvalidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigUpdCount_Cnt_M_u16 = 0u;
	DmdDelestDASigUpdCount_Cnt_M_u16 = 0u;
	EtatMT_Cnt_M_u08 = 0u;
	LKAState_Cnt_M_u08 = 0u;
	PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDATBSI3F2MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDATBSI412MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDATBSI432MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYN2CMMMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNAASMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNABRMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNCMM208MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNCMM388MsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNVOLMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYN2FRE3CDMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDYNCDS34DMsgDLCError_Cnt_M_u08 = 0u;
	PrevISDATABR50DMsgDLCError_Cnt_M_u08 = 0u;
	CountEtatMT_Cnt_M_u08 = 0u;
	ISDYNAASMsgCount_Cnt_M_u08 = 0u;
	DMDFCTCPK_Cnt_M_u08 = 0u;
	DMDRELAXECPK_Cnt_M_u08 = 0u;
	ISDYNABRMsgCount_Cnt_M_u08 = 0u;
	ISDYNVOLMsgCount_Cnt_M_u08 = 0u;
	PrevDiagIntegraElec_Cnt_M_u08 = 0u;
	PrevModeDiag_Cnt_M_u08 = 0u;
	ElecIntCount_Cnt_M_u08 = 0u;
	EffacDefaultDiagCount_Cnt_M_u08 = 0u;
	VVHTYPE1Count_Cnt_M_u08 = 0u;
	VVHTYPE2Count_Cnt_M_u08 = 0u;
	ValidEngineStatusCount_Cnt_M_u08 = 0u;
	EngOnDLCInvalidCount_Cnt_M_u08 = 0u;
	PrevDMDFCTCPK_Cnt_M_u08 = 0u;
	PrevDMDRELAXECPK_Cnt_M_u08 = 0u;
	MultimodeSwReq_Cnt_M_u08 = 0u;
	ReqModeDAChangedState_Cnt_M_u08 = 0u;
	MultimodeSwReqChangedStateCount_Cnt_M_u08 = 0u;
	PrevConfigVhl_Cnt_M_u08 = 0u;
	PrevPROTOHS1DYNUCF5CDMsgDLCError_Cnt_M_u08 = 0u;
	PROTOHS1DYNUCF5CDMsgCount_Cnt_M_u08 = 0u;
	PrevISDATBSI572MsgDLCError_Cnt_M_u08 = 0u;
	PrecisionOffset_Cnt_M_u08 = 0u;
	DmdDelestDA_Cnt_M_u08 = 0u;
	PrevDmdDelestDA_Cnt_M_u08 = 0u;
	/* Don't reinitialize it. Leave it for its own. Should be reinitialized by the own algorithm */
	/* ElectronicIntegrationWriteSucceeded_Cnt_M_lgc = E_OK; */
	CTermActive_Cnt_M_lgc = FALSE;
	EpsEn_Cnt_M_lgc = FALSE;
	RxMsgsSrlComSvcDft_Cnt_M_lgc = FALSE;
	AccelLatValidity_Cnt_M_lgc = FALSE;
	ResetTimers_Cnt_M_lgc = FALSE;
	DiagOn_Cnt_M_lgc = FALSE;
	NetOn_Cnt_M_lgc = FALSE;
	/* Don't reinitialize it. Leave it for its own. Should be reinitialized by the own algorithm */
	/* BattOk_Cnt_M_lgc = FALSE; */
	EngOn_Cnt_M_lgc = FALSE;
	PrevVitesseVehicleBVValid_Cnt_M_lgc = FALSE;
	ClearDTCs_Cnt_M_lgc = FALSE;
	/* No need to reinitialize it. It follows PIM stored to NvM */
	/* ElectronicIntegrationCmd_Cnt_M_lgc = FALSE; */
	CPKOK_Cnt_M_lgc = TRUE;
	VehSpdControl_Cnt_M_lgc = FALSE;
	Msg348Valid_Cnt_M_lgc = FALSE;
	Msg432Valid_Cnt_M_lgc = FALSE;
	Msg552Valid_Cnt_M_lgc = FALSE;
	StartupTimeCalculated_Cnt_M_lgc = FALSE;
	VehTimeValid_Cnt_M_lgc = FALSE;
	VehSpdSync_Cnt_M_lgc = FALSE;
	APARequest_Cnt_M_lgc = FALSE;
	VehicleSpeedValid_Cnt_M_lgc = FALSE;
	ApaVehicleSpeedValid_Cnt_M_lgc = TRUE;
	ApaRelaxReq_Cnt_M_lgc = FALSE;
	ReqModeDAStateChanged_Cnt_M_lgc = FALSE;
	IgnTimeOff_Sec_M_u32 = 0u;
	/* No need to re-initialize those arrays. They get fully filled in before first use */
	/* ElecIntTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; */
	/* EffacDefaultDiagTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; */
	ManVehSpd_Kph_M_f32 = 0.0f;


	EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
	PrevEtatMT_Cnt_M_u08 = (uint8)kETAT_MT_Cut;
	ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;

	ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);

	ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCDS34DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATABR50DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2FRE3CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DmdDelestDATimer_mS_M_u32 = SystemTime_mS_M_u32;
	CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DateInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
	CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI572MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	IgnOnTimer_mS_M_u32 = SystemTime_mS_M_u32;
	EscOffsFromSerlCom_HwDeg_M_f32 = 0.0F;
	EscPrecisionFromSerlCom_HwDeg_M_f32 = D_ESCPRECISIONFROMSERLCOM_INIT_VALUE;
	AcqInterruptDae_Cnt_M_lgc = FALSE;
	EscDataVldFromSerlCom_Cnt_M_lgc = FALSE;
	DmdDelestDaSts_Cnt_M_u08 = (uint8)kDMD_DELEST_DA_Not_Requested;
	DmdDelestDaVld_Cnt_M_lgc = FALSE;
	DmdDelestDaStsTime_MSec_M_u32 = SystemTime_mS_M_u32;
	MultimodeVld_Cnt_M_lgc = TRUE;
	AngleVolant_HwDeg_M_f32 = 0.0F;

	SrlComInput_UpdateVVHType(*Rte_Pim_VVHTYPEData());

	/*NTC 164, 165, 166, 138 and 139 configuration based status*/
	if (FALSE == k_JDD2010Selected_Cnt_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0u, NTC_STATUS_PASSED);	/* 0x138 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0u, NTC_STATUS_PASSED);	/* 0x139 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x164 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x165 */
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_U, 0u, NTC_STATUS_PASSED);	/* 0x166 */
	}

	/*NTC 146 configuration based status*/
	if (FALSE == STTdSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x146 */
	}

	/*NTC 140,141 configuration based status*/
	if ( (FALSE == LXASelected_Cnt_M_lgc) && (FALSE == STTdSelected_Cnt_M_lgc) )
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x140 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x141 */
	}

	/*NTC 178, 179, 170, 171, 144, 145, 147 configuration based status */
	if (FALSE == LXASelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x144 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Q, 0u, NTC_STATUS_PASSED);	/* 0x145 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_Q, 0u, NTC_STATUS_PASSED); /* 0x147 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0u, NTC_STATUS_PASSED);	/* 0x170 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_W, 0u, NTC_STATUS_PASSED);	/* 0x171 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0u, NTC_STATUS_PASSED);	/* 0x178 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X, 0u, NTC_STATUS_PASSED);	/* 0x179 */
	}

	/*NTC 158, 159 and 15C configuration based status */
	if (FALSE == MultimodeSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0u, NTC_STATUS_PASSED);	 /* 0x158 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_T, 0u, NTC_STATUS_PASSED);	 /* 0x159 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_T, 0u, NTC_STATUS_PASSED); /* 0x15C */
	}

	if(TRUE == ESCOffsCfgSeld_Cnt_M_lgc)
	{
		EnergyModeState_Cnt_M_enum = NORMAL; /*  0 */
	}
	else
	{
		EnergyModeState_Cnt_M_enum = TRANSPORTATION; /*  2 */

		/* During init, if ESCOffsetCfg is NOT selected, all enabled NTCs between  180 and  18E,
		inclusive, shall be cleared.*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Y, 0u, NTC_STATUS_PASSED);	/* 0x180 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Y, 0u, NTC_STATUS_PASSED);	/* 0x181 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Y, 0u, NTC_STATUS_PASSED);/* 0x184 */

		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x188 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x189 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18A */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18B */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18C */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18D */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0u, NTC_STATUS_PASSED);	/* 0x18E */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0u, NTC_STATUS_PASSED);	/* 0x18F */
	}

	if (FALSE == CAVHCSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_S, 0u, NTC_STATUS_PASSED);  /* NTC 0x150 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x151 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x152 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x153 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_S, 0u, NTC_STATUS_PASSED); /* NTC 0x154 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_S, 0u, NTC_STATUS_PASSED);  /* NTC 0x155 */
	}

	if (FALSE == CityParkSelected_Cnt_M_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x148 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x149 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14A */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14B */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14C */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14D */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_R, 0u, NTC_STATUS_PASSED);	/* 0x14E */
	}

	SrlComVehSpd_Kph_M_f32 = k_VehSpdInit_Kph_f32;
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetCpkOk(void)
{
    VAR(uint8, AUTOMATIC) DataRngFltMsgN_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) CRCFltMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) PgrsCntFltMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) DataRngFltMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) DataRateFltMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) DataOtherFltMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) BusOffCh1_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) InvalidMsgN_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MissingMsgN_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) InvalidMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MissingMsgR_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) InvalidMsgS_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MissingMsgS_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) CRCFltMsgS_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) PgrsCntFltMsgS_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) DataRngFltMsgS_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) DataRateFltMsgS_Cnt_T_u08;

    VAR(boolean, AUTOMATIC) CPKOK_Cnt_T_lgc;

    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_N  , &DataRngFltMsgN_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_R      , &CRCFltMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_R  , &PgrsCntFltMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_R  , &DataRngFltMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_R , &DataRateFltMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_R, &DataOtherFltMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1        , &BusOffCh1_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_N     , &InvalidMsgN_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_N     , &MissingMsgN_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_R     , &InvalidMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_R     , &MissingMsgR_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_S     , &InvalidMsgS_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_S     , &MissingMsgS_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_S      , &CRCFltMsgS_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_S  , &PgrsCntFltMsgS_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_S  , &DataRngFltMsgS_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_S , &DataRateFltMsgS_Cnt_T_u08);

    if ((D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgN_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgR_Cnt_T_u08        & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgR_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgR_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgR_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (DataOtherFltMsgR_Cnt_T_u08  & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1_Cnt_T_u08         & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1NodeMute_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgN_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (MissingMsgN_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgR_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (MissingMsgR_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgS_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (MissingMsgS_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgS_Cnt_T_u08        & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgS_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgS_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgS_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK))    )
    {
        CPKOK_Cnt_T_lgc = FALSE;
    }
    else
    {
        CPKOK_Cnt_T_lgc = TRUE;
    }

    return CPKOK_Cnt_T_lgc;
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_EscAckAndDataValid(CONSTP2VAR(boolean, AUTOMATIC, AP_SRLCOMINPUT_CONST) EscAck_Cnt_T_lgc, CONSTP2VAR(boolean, AUTOMATIC, AP_SRLCOMINPUT_CONST) EscDataVld_Cnt_T_lgc)
{
    VAR(uint8, AUTOMATIC) InvalidMsgZ_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) MissingMsgZ_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) CRCFltMsgZ_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) PgrsCntFltMsgZ_Cnt_T_u08;

	VAR(uint8, AUTOMATIC) DataRngFltMsgZ_T_u08;
	VAR(uint8, AUTOMATIC) DataRateFltMsgZ_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgO_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgO_T_u08;
	VAR(uint8, AUTOMATIC) CRCFltMsgO_T_u08;
	VAR(uint8, AUTOMATIC) PgrsCntFltMsgO_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgO_T_u08;
	VAR(uint8, AUTOMATIC) DataOtherFltMsgZ_T_u08;
	VAR(uint8, AUTOMATIC) DSTXORActive_T_u08;

	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_Z    , &InvalidMsgZ_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_Z    , &MissingMsgZ_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_Z  	, &CRCFltMsgZ_Cnt_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_Z , &PgrsCntFltMsgZ_Cnt_T_u08);
   	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_Z 	, &DataRngFltMsgZ_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_Z	, &DataRateFltMsgZ_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_O		, &InvalidMsgO_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_O 		, &MissingMsgO_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_O 		, &CRCFltMsgO_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_O 	, &PgrsCntFltMsgO_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_O		, &DataRngFltMsgO_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_Z 	, &DataOtherFltMsgZ_T_u08);
    (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DSTXORActive 		, &DSTXORActive_T_u08);

    if ((D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgZ_Cnt_T_u08    	& D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (MissingMsgZ_Cnt_T_u08      & D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgZ_Cnt_T_u08    	& D_NTC_TEST_COMPLETED_MASK)) ||
        (D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgZ_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK))   )
    {
    	*EscAck_Cnt_T_lgc = FALSE;
    }
    else
    {
    	*EscAck_Cnt_T_lgc = AcqInterruptDae_Cnt_M_lgc;
    }

   	if ((D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgZ_Cnt_T_u08    	& D_NTC_TEST_COMPLETED_MASK)) ||
   	    (D_NTC_TEST_COMPLETED_FAILED == (MissingMsgZ_Cnt_T_u08      & D_NTC_TEST_COMPLETED_MASK)) ||
   	    (D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgZ_Cnt_T_u08    	& D_NTC_TEST_COMPLETED_MASK)) ||
   	    (D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgZ_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK)) ||
   		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgZ_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgZ_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgO_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgO_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgO_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgO_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgO_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataOtherFltMsgZ_T_u08 	& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DSTXORActive_T_u08 		& D_NTC_TEST_COMPLETED_MASK)))
   	{
   		*EscDataVld_Cnt_T_lgc = FALSE;
   	}
   	else
   	{
   		*EscDataVld_Cnt_T_lgc = EscDataVldFromSerlCom_Cnt_M_lgc;
   	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MissingMessageNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if( PrevMsgRxTime_MSec_T_u32 != MsgRxTime_MSec_T_u32 )
	{
		*MsgTimer_mS_T_u32 = MsgRxTime_MSec_T_u32;

		*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);

		if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED);
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*MsgTimer_mS_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */

		if( ElapsedTime_mS_T_u16 >= Timeout_mS_T_u16 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED);
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(MsgTimer_mS_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) InvalidCount_Cnt_T_u16,
															VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
															VAR(uint16, AUTOMATIC) InvalidThresh_Cnt_T_u16,
															VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	if( TestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
	{
		*InvalidCount_Cnt_T_u16 = 0u;

		*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);

		if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED);
		}
	}
	else if ( TestStatus_Cnt_T_u08 == D_TESTDEADBAND_CNT_U08 )
	{
		*InvalidCount_Cnt_T_u16 = 0u;

		*ValidCount_Cnt_T_u16 = 0u;
	}
	else
	{
		*ValidCount_Cnt_T_u16 = 0u;

		*InvalidCount_Cnt_T_u16 = IncToThresh(*InvalidCount_Cnt_T_u16, InvalidThresh_Cnt_T_u16);

		if( *InvalidCount_Cnt_T_u16 >= InvalidThresh_Cnt_T_u16 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED);
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MixedTimeValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
																	VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	P2VAR(uint32, AUTOMATIC, AUTOMATIC) SigTimer_mS_T_u32,
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if( TestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(SigTimer_mS_T_u32); /* PRQA S 3426 */ /* PRQA S 3417 */
		if( MsgRxTime_MSec_T_u32 != PrevMsgRxTime_MSec_T_u32 )
		{
			*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);

			if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED);
			}
		}
	}
	else
	{
		*ValidCount_Cnt_T_u16 = 0u;
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*SigTimer_mS_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
		if( ElapsedTime_mS_T_u16 >= Timeout_mS_T_u16 )
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED);
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ResetFltAcc( P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
													VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
													VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(boolean, AUTOMATIC) NTCFailed_Cnt_T_lgc;

	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNum_Cnt_T_u16, &NTCFailed_Cnt_T_lgc);

	if( NTCFailed_Cnt_T_lgc == TRUE )
	{
		*FltAcc_Cnt_T_u16 = DiagSettings_Cnt_T_str.Threshold;
	}
	else
	{
		*FltAcc_Cnt_T_u16 = 0u;
	}
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) GetLXANTCsStatus ( void )
{
	VAR(uint8, AUTOMATIC) LXASignalsValid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) BusOffCh1_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgW_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgW_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgX_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgQ_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgQ_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgQ_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataOtherFlt2MsgQ_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) CRCFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PrgrsCntFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgO_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgMsgX_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRateFltMsgQ_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) InvalidMsgS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) CRCFltMsgS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) PgrsCntFltMsgS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRateFltMsgS_Cnt_T_u08;

	/* LXA Signal Validity */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1, &BusOffCh1_Cnt_T_u08);  /* NTC 0x100 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_u08);  /* NTC 0x101 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_O, &InvalidMsgO_Cnt_T_u08); /* NTC 0x130 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_O, &MissingMsgO_Cnt_T_u08);  /* NTC 0x131 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_O, &CRCFltMsgO_Cnt_T_u08); /* NTC 0x132 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_O, &PrgrsCntFltMsgO_Cnt_T_u08);  /* NTC 0x133 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_O, &DataRngFltMsgO_Cnt_T_u08);  /* NTC 0x134 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_Q, &InvalidMsgQ_Cnt_T_u08);  /* NTC 0x140 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_Q, &MissingMsgQ_Cnt_T_u08);  /* NTC 0x141 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_Q, &DataRngFltMsgQ_Cnt_T_u08);  /* NTC 0x144 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_Q, &DataRateFltMsgQ_Cnt_T_u08); /* NTC 0x145 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFlt2Msg_Q, &DataOtherFlt2MsgQ_Cnt_T_u08);   /* NTC 0x147 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_S, &InvalidMsgS_Cnt_T_u08);  /* NTC 0x150*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_S, &MissingMsgS_Cnt_T_u08); /* NTC 0x151*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_S, &CRCFltMsgS_Cnt_T_u08); /* NTC 0x152*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_S, &PgrsCntFltMsgS_Cnt_T_u08); /* NTC 0x153*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_S, &DataRngFltMsgS_Cnt_T_u08); /* NTC 0x154*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_S, &DataRateFltMsgS_Cnt_T_u08);  /* NTC 0x155*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_W, &InvalidMsgW_Cnt_T_u08);  /* NTC 0x170 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_W, &MissingMsgW_Cnt_T_u08);  /* NTC 0x171 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_X, &InvalidMsgMsgX_Cnt_T_u08); /* NTC 0x178*/
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_X, &MissingMsgX_Cnt_T_u08);  /* NTC 0x179 */

	if ((D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1_Cnt_T_u08         & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1NodeMute_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgO_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgO_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgO_Cnt_T_u08        & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (PrgrsCntFltMsgO_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgO_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgQ_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgQ_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgQ_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgQ_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataOtherFlt2MsgQ_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgS_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgS_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgS_Cnt_T_u08        & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgS_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgS_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgS_Cnt_T_u08   & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgW_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgW_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgMsgX_Cnt_T_u08    & D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgX_Cnt_T_u08       & D_NTC_TEST_COMPLETED_MASK))   )
	{
		LXASignalsValid_Cnt_T_lgc = FALSE;
	}
	else
	{
		LXASignalsValid_Cnt_T_lgc = TRUE;
	}

	return (LXASignalsValid_Cnt_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetMultimodeNTCsStatus ( void )
{
	VAR(boolean, AUTOMATIC) MultimodeNTCsOk_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) InvalidMsgT_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsgT_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsgT_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BusOffCh1_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_u08;

	/* LXA Signal Validity */
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1, &BusOffCh1_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_T, &InvalidMsgT_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_T, &MissingMsgT_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_T, &DataRngFltMsgT_Cnt_T_u08);

	if ((D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1_Cnt_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1NodeMute_Cnt_T_u08	& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgT_Cnt_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgT_Cnt_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgT_Cnt_T_u08 		& D_NTC_TEST_COMPLETED_MASK)))
	{
		MultimodeNTCsOk_Cnt_T_lgc = FALSE;
	}
	else
	{
		MultimodeNTCsOk_Cnt_T_lgc = TRUE;
	}

	return (MultimodeNTCsOk_Cnt_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetVehicleLatAccelNTCsStatus ( void )
{
	VAR(boolean, AUTOMATIC) VehicleLatAccelNTCsOk_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) InvalidMsg_AA_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsg_AA_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsg_AA_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BusOffCh1_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_u08;

	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1, &BusOffCh1_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AA, &InvalidMsg_AA_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_AA, &MissingMsg_AA_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_AA, &DataRngFltMsg_AA_Cnt_T_u08);

	if ((D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1_Cnt_T_u08 			& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (BusOffCh1NodeMute_Cnt_T_u08	& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (InvalidMsg_AA_Cnt_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsg_AA_Cnt_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsg_AA_Cnt_T_u08 	& D_NTC_TEST_COMPLETED_MASK)) ||
		(2u != *Rte_Pim_VVHTYPEData()) )
	{
		VehicleLatAccelNTCsOk_Cnt_T_lgc = FALSE;
	}
	else
	{

		VehicleLatAccelNTCsOk_Cnt_T_lgc = TRUE;
	}

	return (VehicleLatAccelNTCsOk_Cnt_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetSCommAngleValidNTCsStatus ( void )
{
	VAR(boolean, AUTOMATIC) SCommAngleValidNTCsOK;
	VAR(boolean, AUTOMATIC) InvalidMsgS_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) MissingMsgS_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCFltMsgS_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PgrsCntFltMsgS_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DataRngFltMsgS_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DataRateFltMsgS_Cnt_T_u08;

	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_S, &InvalidMsgS_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_S, &MissingMsgS_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_CRCFltMsg_S, &CRCFltMsgS_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_PgrsCntFltMsg_S, &PgrsCntFltMsgS_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_S, &DataRngFltMsgS_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRateFltMsg_S, &DataRateFltMsgS_Cnt_T_u08);

	if ((D_NTC_TEST_COMPLETED_FAILED == (InvalidMsgS_Cnt_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (MissingMsgS_Cnt_T_u08		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (CRCFltMsgS_Cnt_T_u08 		& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (PgrsCntFltMsgS_Cnt_T_u08 	& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRngFltMsgS_Cnt_T_u08 	& D_NTC_TEST_COMPLETED_MASK)) ||
		(D_NTC_TEST_COMPLETED_FAILED == (DataRateFltMsgS_Cnt_T_u08 	& D_NTC_TEST_COMPLETED_MASK)))
	{
		SCommAngleValidNTCsOK = FALSE;
	}
	else
	{
		SCommAngleValidNTCsOK = TRUE;
	}

	return (SCommAngleValidNTCsOK);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetValidEngineStatus ( void )
{
	VAR(boolean, AUTOMATIC) ValidEngineStatus_T_lgc;
	VAR(uint8, AUTOMATIC) InvalidMsg_N_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) MissingMsg_N_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DataRngFltMsg_N_Cnt_T_u08;

	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_N, 	&InvalidMsg_N_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_MissingMsg_N, 	&MissingMsg_N_Cnt_T_u08);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_N,&DataRngFltMsg_N_Cnt_T_u08);

	if (((D_NTC_TEST_COMPLETED_PASSED == (InvalidMsg_N_Cnt_T_u08 	& D_NTC_TEST_COMPLETED_MASK)) &&
		 (D_NTC_TEST_COMPLETED_PASSED == (MissingMsg_N_Cnt_T_u08	& D_NTC_TEST_COMPLETED_MASK)) &&
		 (D_NTC_TEST_COMPLETED_PASSED == (DataRngFltMsg_N_Cnt_T_u08 & D_NTC_TEST_COMPLETED_MASK))) ||
		(ValidEngineStatusCount_Cnt_M_u08 >= 3u))
	{
		ValidEngineStatus_T_lgc = TRUE;
	}
	else
	{

		ValidEngineStatus_T_lgc = FALSE;
	}

	return (ValidEngineStatus_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetNetOn(VAR(boolean, AUTOMATIC) NetOn_Cnt_T_lgc,
																VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc)
{
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;

	if( EpsEn_Cnt_T_lgc == TRUE )
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IgnOnTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3426 */ /* PRQA S 3417 */
		if( ElapsedTime_mS_T_u16 >= k_IgnOnTimeout_mS_u16 )
		{
			NetOn_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		NetOn_Cnt_T_lgc = FALSE;
		IgnOnTimer_mS_M_u32 = SystemTime_mS_M_u32;
	}

	return NetOn_Cnt_T_lgc;
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) SrlComInput_GetBattOk(VAR(boolean, AUTOMATIC) BattOk_Cnt_T_lgc,
																VAR(float32, AUTOMATIC) Batt_Volt_T_f32)
{
	if( BattOk_Cnt_T_lgc == TRUE )
	{
		if( (Batt_Volt_T_f32 >= k_BattOvHi_Volt_f32) ||
			(Batt_Volt_T_f32 <= k_BattUvLo_Volt_f32) )
		{
			BattOk_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		if( (Batt_Volt_T_f32 >= k_BattUvHi_Volt_f32) &&
			(Batt_Volt_T_f32 <= k_BattOvLo_Volt_f32) )
		{
			BattOk_Cnt_T_lgc = TRUE;
		}
	}

	return BattOk_Cnt_T_lgc;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDat4V2Bsi_552(void)
{
	ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
	CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
	ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
	DateValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatAbr_50D(void)
{
	ISDATABR50DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgLenValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_3F2(void)
{
	ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
	ColumnAngleSetpointValidCount_Cnt_M_u16 = 0u;
	LKATrqFactReqValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_412(void)
{
	ISDATBSI412MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
}
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_432(void)
{
	ISDATBSI432MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDatBsi_572(void)
{
	ISDATBSI572MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgLenValidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDyn2Cmm_348(void)
{
	ISDYN2CMMMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
	EtatMTSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDyn2Fre_3CD(void)
{
	ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16 = 0u;
	AccelLatValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynAas_2EB(void)
{
	ISDYNAASMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
	CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
	DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
	DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynAbr_38D(void)
{
	ISDYNABRMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
	VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCds_34D(void)
{
	ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgLenValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCmm_208(void)
{
	ISDYNCMM208MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynCmm_388(void)
{
	ISDYNCMM388MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgIsDynVol_305(void)
{
	ISDYNVOLMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
	ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
	VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetMsgProtoHs1DynUcf_5CD(void)
{
	PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16 = 0u;
	OffsetSigValidCount_Cnt_M_u16 = 0u;
	PrecisionOffsetSigValidCount_Cnt_M_u16 = 0u;
}

STATIC FUNC(uint8, AP_SRLCOMINPUT_CODE) SrlComInput_CalculateCheckSum(	CONSTP2CONST(CanMsgType, AUTOMATIC, AUTOMATIC) buffer,
																		VAR(uint8, AUTOMATIC) seed)
{
	VAR(uint8, AUTOMATIC) Checksum_Cnt_T_u08;

	Checksum_Cnt_T_u08 = (uint8)(	((*buffer)[0] & 0x0Fu) + (((*buffer)[0] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[1] & 0x0Fu) + (((*buffer)[1] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[2] & 0x0Fu) + (((*buffer)[2] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[3] & 0x0Fu) + (((*buffer)[3] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[4] & 0x0Fu) + (((*buffer)[4] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[5] & 0x0Fu) + (((*buffer)[5] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[6] & 0x0Fu) + (((*buffer)[6] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									((*buffer)[7] & 0x0Fu) + (((*buffer)[7] >> 4) & 0x0Fu) + /* PRQA S 2985 */
									seed );

	return Checksum_Cnt_T_u08 & 0x0Fu;
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_UpdateVVHType( VAR(uint8, AUTOMATIC) VVHType_Cnt_T_u08)
{
	if (*Rte_Pim_VVHTYPEData() != VVHType_Cnt_T_u08)
	{
		/* Rte_Pim_VVHTYPEData PIM is read/write only from runnables mapped to same task.
		 * They cannot interrupt each other. Also access to it is atomic */
		*Rte_Pim_VVHTYPEData() = VVHType_Cnt_T_u08;
		(void)Rte_Call_VHHTYPE_WriteBlock(NULL_PTR);
	}
	(void)Rte_Write_VVHType_Cnt_u08(*Rte_Pim_VVHTYPEData());

	/* Clean up NTCs belonging to messages not supported for new VVHType */

	if (0u != VVHType_Cnt_T_u08)
	{
		/* NTCs belonging to messages supported for VVHType == 0 */
	}

	if (1u != VVHType_Cnt_T_u08)
	{
		/* NTCs belonging to messages supported for VVHType == 1 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_V, 0u, NTC_STATUS_PASSED); /* 0x168 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0u, NTC_STATUS_PASSED); /* 0x169 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_V, 0u, NTC_STATUS_PASSED);	/* 0x16C */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_V, 0u, NTC_STATUS_PASSED);	/* 0x16D */
	}

	if (2u != VVHType_Cnt_T_u08)
	{
		/* NTCs belonging to messages supported for VVHType == 2 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0u, NTC_STATUS_PASSED);	/* 0x130 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_O, 0u, NTC_STATUS_PASSED);	/* 0x131 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_O, 0u, NTC_STATUS_PASSED);	/* 0x132 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_O, 0u, NTC_STATUS_PASSED);/* 0x133 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_O, 0u, NTC_STATUS_PASSED);/* 0x134 */

		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0u, NTC_STATUS_PASSED);		/* 0x190 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0u, NTC_STATUS_PASSED);		/* 0x191 */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0u, NTC_STATUS_PASSED);	/* 0x194 */
	}
}

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) SrlComInput_ResetTimers(void)
{
	ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_M_u32;


	ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYNCDS34DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATABR50DMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDYN2FRE3CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ISDATBSI572MsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	PROTOHS1DYNUCF5CDMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;

	CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_M_u32;
	CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DmdDelestDATimer_mS_M_u32 = SystemTime_mS_M_u32;
	DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_M_u32;
	DateInvalidTimer_mS_M_u32 = SystemTime_mS_M_u32;

	ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
	ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
	ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
	ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
	VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
	VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
	ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
	CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
	CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
	DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
	DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
	DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
	DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
	CityParkInputConsistentCount_Cnt_M_u16 = 0u;
	DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
	ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
	ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
	VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
	VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
	EtatMTSigValidCount_Cnt_M_u16 = 0u;
	EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgLenValidCount_Cnt_M_u16 = 0u;
	ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDYNCDS34DMsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgLenInvalidCount_Cnt_M_u16 = 0u;
	CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
	ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
	DateValidCount_Cnt_M_u16 = 0u;
	AccelLatInvalidCount_Cnt_M_u16 = 0u;
	AccelLatValidCount_Cnt_M_u16 = 0u;
	ISDYN2FRE3CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATABR50DMsgTimeValidCount_Cnt_M_u16 = 0u;
	ColumnAngleSetpointValidCount_Cnt_M_u16 = 0u;
	ColumnAngleSetpointInvalidCount_Cnt_M_u16 = 0u;
	LKATrqFactReqValidCount_Cnt_M_u16 = 0u;
	LKAStateValidCount_Cnt_M_u16 = 0u;
	LKATrqFactReqInvalidCount_Cnt_M_u16 = 0u;
	LKAStateInvalidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgTimeValidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgLenValidCount_Cnt_M_u16 = 0u;
	ISDATBSI572MsgLenInvalidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigValidCount_Cnt_M_u16 = 0u;
	ConfigVhlSigInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgTimeValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgLenValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgLenInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgChkSumValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgChkSumInvalidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgCountValidCount_Cnt_M_u16 = 0u;
	PROTOHS1DYNUCF5CDMsgCountInvalidCount_Cnt_M_u16 = 0u;
	OffsetSigValidCount_Cnt_M_u16 = 0u;
	OffsetSigInvalidCount_Cnt_M_u16 = 0u;
	PrecisionOffsetSigValidCount_Cnt_M_u16 = 0u;
	PrecisionOffsetSigInvalidCount_Cnt_M_u16 = 0u;
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
