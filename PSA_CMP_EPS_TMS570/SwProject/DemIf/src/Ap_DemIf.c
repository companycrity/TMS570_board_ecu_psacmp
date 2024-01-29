/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DemIf.c
 *     Workspace:  C:/Components/PSA_CMP/PSA_CMP_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_DemIf
 *  Generated at:  Tue Mar  6 13:18:17 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DemIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          4 %
 * %derived_by:       nz3337 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version EA3#3
 * 03/21/18    2       RK       CTC Inhibition									                              EA3#13314
 * 03/21/18    3       RK       Added new CTCs (reused old one)					                              EA3#18780
 * 06/15/18    4       RK       CTC for Msg Too Short got suffix 08 (just comments, no functional change)     EA3#20388
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

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

#include "Rte_Ap_DemIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "Dem.h"
#include "Dem_Lcfg.h"
#include "Dem_PBcfg.h"
#include "il_inc.h"
#include "CalConstants.h"

#define D_NUMDTCS_CNT_U16			((uint16)DEM_NUMBER_OF_EVENTS + 1u)
#define D_FAILBITMASK_CNT_U08		3u
#define D_WORDMASK_CNT_U32			0xFFFFul
#define D_BYTEMASK_CNT_U32			0xFFul
#define D_BYTESHIFT_CNT_S16			8

#define D_CTC_INHIB_ESC		 0x01u
#define D_CTC_INHIB_BSI		 0x02u
#define D_CTC_INHIB_CAV		 0x04u
#define D_CTC_INHIB_AAS		 0x08u
#define D_CTC_INHIB_CMM		 0x10u
/* #define D_CTC_INHIB_EPS		 0x20u */ /* For now now nothing to implement for EPS */
#define D_CTC_INHIB_COM		 0x40u
#define D_CTC_INHIB_ELEC_INT	0x80u

#define DEMIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_DEMIF_VAR) CTCFailed_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_DEMIF_VAR) VehSpdControl_Cnt_M_lgc; /* PRQA S 3218 */
#define DEMIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define DEMIF_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_DEMIF_VAR) CTCInhibitionState_Cnt_M_u08; /* PRQA S 3218 */
#define DEMIF_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define DEMIF_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionEsc_Cnt_M_u32;
STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionBsi_Cnt_M_u32;
STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionCav_Cnt_M_u32;
STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionAas_Cnt_M_u32;
STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionCmm_Cnt_M_u32;
/*STATIC VAR(uint32, AP_DEMIF_VAR) CTCInhibitionEps_Cnt_M_u32; */
#define DEMIF_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_DEMIF_VAR) CTCFailedBuf_Cnt_M_lgc[D_NUMDTCS_CNT_U16]; /* PRQA S 3218 */
#define DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define DEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(uint8, AP_DEMIF_CONST) CTCInhibitionMask_Cnt_M_u08[D_NUMDTCS_CNT_U16] = /* PRQA S 3218 */
{
	0u,
	0u				|0u					|0u					|D_CTC_INHIB_AAS	|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 01	0xD31D83	U131D.83	AAS ECU Incorrect Checksum                                          */
	0u				|0u					|0u					|D_CTC_INHIB_AAS	|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 02	0xD31D82	U131D.82	AAS ECU Incorrect Process Counter                                   */
	0u				|0u					|0u					|D_CTC_INHIB_AAS	|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 03	0xD31D08	U131D.08	AAS ECU Message Too Short                                           */
	0u				|D_CTC_INHIB_BSI	|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 04	0xD31808	U1318.08	BSI ECU Message Too Short                                           */
	D_CTC_INHIB_ESC |0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 05	0xD31383	U1313.83	ABS/ESC ECU Incorrect Checksum                                      */
	D_CTC_INHIB_ESC |0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 06	0xD31382	U1313.82	ABS/ESC ECU Incorrect Process Counter                               */
	D_CTC_INHIB_ESC |0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 07	0xD31308	U1313.08	ABS/ESC ECU Message Too Short                                       */
	0u				|0u					|0u					|0u					|D_CTC_INHIB_CMM	|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 08	0xD30808	U1308.08	CMM ECU Message Too Short                                           */
	0u				|0u					|D_CTC_INHIB_CAV	|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 09	0xD30583	U1305.83	Steering Wheel Sensor Incorrect Checksum                            */
	0u				|0u					|D_CTC_INHIB_CAV	|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0A	0xD30582	U1305.82	Steering Wheel Sensor Incorrect Process Counter                     */
	0u				|0u					|D_CTC_INHIB_CAV	|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0B	0xD30508	U1305.08	Steering Wheel Sensor Message Too Short                             */
	0u				|0u					|0u					|D_CTC_INHIB_AAS	|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0C	0xD21D81	U121D.81	AAS ECU Invalid or Reserved                                         */
	0u				|D_CTC_INHIB_BSI	|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0D	0xD21881	U1218.81	BSI ECU Message Invalid Or Reserved                                 */
	D_CTC_INHIB_ESC |0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0E	0xD21381	U1213.81	ABS/ESC Data Invalid Or Reserved                                    */
	0u				|0u					|0u					|0u					|D_CTC_INHIB_CMM	|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 0F	0xD20881	U1208.81	Engine State Invalid or Reserved                                    */
	0u				|0u					|D_CTC_INHIB_CAV	|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 10	0xD20581	U1205.81	Steering Wheel Sensor Invalid Data                                  */
	0u				|0u					|0u					|D_CTC_INHIB_AAS	|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 11	0xD11D87	U111D.87	AAS ECU Missing Message                                             */
	0u				|D_CTC_INHIB_BSI	|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 12	0xD11887	U1118.87	BSI Node Absent                                                     */
	D_CTC_INHIB_ESC |0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 13	0xD11387	U1113.87	ABS/ESC Node Absent                                                 */
	0u				|0u					|0u					|0u					|D_CTC_INHIB_CMM	|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 14	0xD10887	U1108.87	CMM Node Absent                                                     */
	0u				|0u					|D_CTC_INHIB_CAV	|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 15	0xD10587	U1105.87	Steering Wheel Sensor Missing Message                               */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 16	0xD00388	U1003.88	Bus Off                                                             */
	0u				|0u					|0u					|0u					|0u					|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 17	0xD00008	U1000.08	EPS Mute                                                            */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 18	0x564404	C1644.04	Failure to Close EEPROM                                             */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 19	0x563A8F	C163A.8F	Duty Cycle Exceeded (Reduced Performance)                           */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1A	0x55668F	C1566.8F	Incorrect Power Cut Request                                         */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1B	0x540D00	C140D.00	Cross Check Firewall Failure                                        */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1C	0x540C00	C140C.00	Column Angle Request CONSISTENCY                                    */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1D	0x540B16	C140B.16	STTa Under Voltage                                                  */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1E	0x540698	C1406.98	Absolute Temperature Thermal Limit                                  */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 1F	0x539855	C1398.55	EOL Variant Coding Not Performed                                    */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 20	0x520E00	C120E.00	Offset  from ESC inconsistent                                       */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 21	0x520DA2	C120D.A2	Turns Counter Low Battery Fault                                     */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 22	0x520901	C1209.01	Loss of Ignition Signal                                             */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 23	0x513662	C1136.62	Inconsistent relative angle                                         */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 24	0x510C98	C110C.98	Internal EPS Failure: System Or Component Temperature Out of Range  */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 25	0x510C96	C110C.96	Internal EPS Failure: Internal Component Failure                    */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 26	0x510C62	C110C.62	Internal EPS Failure: Internal Signal Reasonableness Failure        */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 27	0x510C43	C110C.43	Internal EPS Failure: Memory Failure                                */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 28	0x510C1C	C110C.1C	Internal EPS Failure: Voltage Out Of Range                          */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 29	0x510C04	C110C.04	Internal EPS Failure: General Failure                               */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 2A	0x510C01	C110C.01	Internal EPS Failure: Internal Harness                              */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 2B	0x510BA3	C110B.A3	Over Voltage                                                        */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 2C	0x510BA2	C110B.A2	Under Voltage                                                       */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 2D	0x510BA1	C110B.A1	Under Voltage: Reduced Performance                                  */
	0u				|0u					|0u					|0u					|0u					|0u			|0u					|D_CTC_INHIB_ELEC_INT,	/* 2E	0x510A51	C110A.51	EOL Tuning Not Performed                                            */
	0u				|0u					|0u					|0u					|D_CTC_INHIB_CMM	|0u			|D_CTC_INHIB_COM	|D_CTC_INHIB_ELEC_INT,	/* 2F	0x050192	P0501.92	Message 388 Vehicle Speed Rate of Change                            */
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u,
	0u
};
#define DEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_CheckVoltageRange(
		CONST(float32, AUTOMATIC) voltage_Volt_T_f32,
		CONST(float32, AUTOMATIC) min_Volt_T_f32,
		CONST(float32, AUTOMATIC) max_Volt_T_f32,
		CONST(uint32, AUTOMATIC) time_cnt_T_u32,
		CONSTP2VAR(uint32, AUTOMATIC, ANY) timer_cnt_T_u32);

STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_EvaluateLogicalCondition(CONST(uint32, AUTOMATIC) Time_ms_T_u32);

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
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_DTCType: Integer in interval [0...4294967295]
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
 * Dem_DTCKindType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_DTC_KIND_ALL_DTCS (1U)
 *   DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * NxtrOpCycle: Enumeration of integer in interval [0...0] with enumerators
 *   NxtrDefaultOpCycle (0U)
 * NxtrOpCycleState: Enumeration of integer in interval [1...2] with enumerators
 *   NXTR_CYCLE_STATE_START (1U)
 *   NXTR_CYCLE_STATE_END (2U)
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


#define RTE_START_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_DTCStatusChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <DTCStatusChange>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CTCFailed_Cnt_lgc(Boolean data)
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
 *   Std_ReturnType DemIf_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_DTCStatusChanged(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_DTCStatusChanged (returns application error)
 *********************************************************************************************************************/
	
	
	VAR(uint16,  AUTOMATIC) DTCNumber_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) DTCFTB_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DTCFound_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) DTCIndex_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) i;
	
	
	DTCNumber_Cnt_T_u16 = (uint16)((DTC >> D_BYTESHIFT_CNT_S16) & D_WORDMASK_CNT_U32);
	DTCFTB_Cnt_T_u08 = (uint8)(DTC & D_BYTEMASK_CNT_U32);
	
	DTCFound_Cnt_T_lgc = FALSE;
	
	for( i = 1u; (i < D_NUMDTCS_CNT_U16) && (DTCFound_Cnt_T_lgc == FALSE); i++ )
	{
		if( (Dem_DTCNumberTable[i] == DTCNumber_Cnt_T_u16) &&
			(Dem_DTC_FTB_Table[i] == DTCFTB_Cnt_T_u08) )
		{
			DTCFound_Cnt_T_lgc = TRUE;
			DTCIndex_Cnt_T_u08 = (uint8)i;
		}
	}
	
	if( DTCFound_Cnt_T_lgc == TRUE )
	{
		if( (DTCStatusNew & D_FAILBITMASK_CNT_U08) == D_FAILBITMASK_CNT_U08 )
		{
			CTCFailedBuf_Cnt_M_lgc[DTCIndex_Cnt_T_u08] = TRUE;
			
			CTCFailed_Cnt_M_lgc = TRUE;
		}
		else
		{
			CTCFailedBuf_Cnt_M_lgc[DTCIndex_Cnt_T_u08] = FALSE;
			
			CTCFailed_Cnt_M_lgc = FALSE;
			
			for( i = 0u; i < D_NUMDTCS_CNT_U16; i++ )
			{
				if( CTCFailedBuf_Cnt_M_lgc[i] == TRUE )
				{
					CTCFailed_Cnt_M_lgc = TRUE;
				}
			}
		}
	}
	
	Rte_Write_CTCFailed_Cnt_lgc(CTCFailed_Cnt_M_lgc); /* PRQA S 3200 */
	
	return RTE_E_OK;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_DemShutdown
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DemShutdown> of PortPrototype <DemIf>
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
 *   void DemIf_DemShutdown(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DemShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_DemShutdown
 *********************************************************************************************************************/
	
	Dem_Shutdown();
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Init
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_Init
 *********************************************************************************************************************/

	VAR(uint32, AUTOMATIC) Time_ms_T_u32;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Time_ms_T_u32);

	CTCInhibitionEsc_Cnt_M_u32 = Time_ms_T_u32;
	CTCInhibitionBsi_Cnt_M_u32 = Time_ms_T_u32;
	CTCInhibitionCav_Cnt_M_u32 = Time_ms_T_u32;
	CTCInhibitionAas_Cnt_M_u32 = Time_ms_T_u32;
	CTCInhibitionCmm_Cnt_M_u32 = Time_ms_T_u32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Per
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
 *   Float Rte_IRead_DemIf_Per_BatteryVoltage_Volt_f32(void)
 *   Boolean Rte_IRead_DemIf_Per_BusOff_Cnt_lgc(void)
 *   Boolean Rte_IRead_DemIf_Per_CTerm_Cnt_lgc(void)
 *   Boolean Rte_IRead_DemIf_Per_ElectronicIntegration_Cnt_lgc(void)
 *   UInt8 Rte_IRead_DemIf_Per_EtatMt_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_Ignition_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
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

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Per(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_Per
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) BatteryVoltage_Volt_T_f32;
	VAR(uint32, AUTOMATIC) Time_ms_T_u32;
	VAR(uint16, AUTOMATIC) ElapseTime_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) ElectronicIntegration_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOff_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) CTCInhibitionState_Cnt_T_u08;

	BatteryVoltage_Volt_T_f32 = Rte_IRead_DemIf_Per_BatteryVoltage_Volt_f32();
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Time_ms_T_u32);
	ElectronicIntegration_Cnt_T_lgc = Rte_IRead_DemIf_Per_ElectronicIntegration_Cnt_lgc();
	BusOff_Cnt_T_lgc = Rte_IRead_DemIf_Per_BusOff_Cnt_lgc();

	DemIf_EvaluateLogicalCondition(Time_ms_T_u32);

	DemIf_CheckVoltageRange(BatteryVoltage_Volt_T_f32, k_EscActvVBattMin_Volt_f32, k_EscActvVBattMax_Volt_f32, Time_ms_T_u32, &CTCInhibitionEsc_Cnt_M_u32);
	DemIf_CheckVoltageRange(BatteryVoltage_Volt_T_f32, k_BsiActvVBattMin_Volt_f32, k_BsiActvVBattMax_Volt_f32, Time_ms_T_u32, &CTCInhibitionBsi_Cnt_M_u32);
	DemIf_CheckVoltageRange(BatteryVoltage_Volt_T_f32, k_CavActvVBattMin_Volt_f32, k_CavActvVBattMax_Volt_f32, Time_ms_T_u32, &CTCInhibitionCav_Cnt_M_u32);
	DemIf_CheckVoltageRange(BatteryVoltage_Volt_T_f32, k_AasActvVBattMin_Volt_f32, k_AasActvVBattMax_Volt_f32, Time_ms_T_u32, &CTCInhibitionAas_Cnt_M_u32);
	DemIf_CheckVoltageRange(BatteryVoltage_Volt_T_f32, k_CmmActvVBattMin_Volt_f32, k_CmmActvVBattMax_Volt_f32, Time_ms_T_u32, &CTCInhibitionCmm_Cnt_M_u32);

	CTCInhibitionState_Cnt_T_u08 = 0u;

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CTCInhibitionEsc_Cnt_M_u32, &ElapseTime_Cnt_T_u16);
	if (ElapseTime_Cnt_T_u16 < k_EscActvTimeout_mS_u16)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_ESC;
	}

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CTCInhibitionBsi_Cnt_M_u32, &ElapseTime_Cnt_T_u16);
	if (ElapseTime_Cnt_T_u16 < k_BsiActvTimeout_mS_u16)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_BSI;
	}

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CTCInhibitionCav_Cnt_M_u32, &ElapseTime_Cnt_T_u16);
	if (ElapseTime_Cnt_T_u16 < k_CavActvTimeout_mS_u16)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_CAV;
	}

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CTCInhibitionAas_Cnt_M_u32, &ElapseTime_Cnt_T_u16);
	if (ElapseTime_Cnt_T_u16 < k_AasActvTimeout_mS_u16)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_AAS;
	}

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CTCInhibitionCmm_Cnt_M_u32, &ElapseTime_Cnt_T_u16);
	if (ElapseTime_Cnt_T_u16 < k_CmmActvTimeout_mS_u16)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_CMM;
	}

	if ((TRUE == BusOff_Cnt_T_lgc) ||
		(TRUE == VehSpdControl_Cnt_M_lgc))
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_COM;
	}

	if (TRUE == ElectronicIntegration_Cnt_T_lgc)
	{
		CTCInhibitionState_Cnt_T_u08 |= D_CTC_INHIB_ELEC_INT;
	}

	CTCInhibitionState_Cnt_M_u08 = CTCInhibitionState_Cnt_T_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_RestartDem
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestartDem> of PortPrototype <DemIf>
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
 *   void DemIf_RestartDem(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_RestartDem
 *********************************************************************************************************************/
	
	Dem_Init();
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetEventStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEventStatus> of PortPrototype <DemIf>
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
 *   Std_ReturnType DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemIf_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetEventStatus (returns application error)
 *********************************************************************************************************************/
	VAR (Std_ReturnType, AUTOMATIC) result = E_OK;

	if (RTE_CONST_NTC_STATUS_FAILED == EventStatus)
	{
		if (0u == (CTCInhibitionMask_Cnt_M_u08[EventId] & CTCInhibitionState_Cnt_M_u08))
		{
			result = Dem_SetEventStatus(EventId, EventStatus);
		}
	}
	else
	{
		result = Dem_SetEventStatus(EventId, EventStatus);
	}

	return result;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <DemIf>
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
 *   void DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetOperationCycleState
 *********************************************************************************************************************/
	
	Dem_SetOperationCycleState(NxtrOperationCycleId, NxtrCycleState); /* PRQA S 3200 */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <DemIf>
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
 *   void DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_VehSpdControl(Boolean Enable_Cnt_T_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_VehSpdControl
 *********************************************************************************************************************/

	VehSpdControl_Cnt_M_lgc = Enable_Cnt_T_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Name          : DemIf_CheckVoltageRange
 * Description   : Resets given Timer if Voltage is out of limits
 * Inputs        :  voltage_Volt_T_f32	- voltage
 * 					min_Volt_T_f32		- min limit
 * 					max_Volt_T_f32		- max limit
 * 					time_cnt_T_u32		- current system time
 * 					timer_cnt_T_u32		- timer to be reset
 * Outputs       : New value for timer, returned via pointer.
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_CheckVoltageRange(
		CONST(float32, AUTOMATIC) voltage_Volt_T_f32,
		CONST(float32, AUTOMATIC) min_Volt_T_f32,
		CONST(float32, AUTOMATIC) max_Volt_T_f32,
		CONST(uint32, AUTOMATIC) time_cnt_T_u32,
		CONSTP2VAR(uint32, AUTOMATIC, ANY) timer_cnt_T_u32)
{
	if ((voltage_Volt_T_f32 < min_Volt_T_f32) ||
		(max_Volt_T_f32 < voltage_Volt_T_f32))
	{
		*timer_cnt_T_u32 = time_cnt_T_u32;
	}
}


/***********************************************************************************************************************
 * Name          : DemIf_EvaluateLogicalCondition
 * Description   : Basing on logical conditions for CTC Inhibition function resets (or not) the timers
 * Inputs        :  Time_cnt_T_u32 - current system time
 * 					Rte_Call_Ignition_OP_GET()
 * 					Rte_Read_Ap_DemIf_CTerm_Cnt_lgc()
 * 					Rte_Read_Ap_DemIf_EtatMt_Cnt_u08()
 * 					Rte_Mode_SystemState_Mode()
 * Outputs       : 	CTCInhibitionEsc_Cnt_M_u32
					CTCInhibitionBsi_Cnt_M_u32
					CTCInhibitionCav_Cnt_M_u32
					CTCInhibitionAas_Cnt_M_u32
					CTCInhibitionCmm_Cnt_M_u32
 * Usage Notes   : None
 **********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_EvaluateLogicalCondition(CONST(uint32, AUTOMATIC) Time_ms_T_u32)
{
	VAR(IoHwAb_BoolType, AUTOMATIC) Ignition_Cnt_T_enum;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(uint8, AUTOMATIC) EtatMt_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CTerm_Cnt_T_lgc;
	(void)Rte_Call_Ignition_OP_GET(&Ignition_Cnt_T_enum);
	CTerm_Cnt_T_lgc = Rte_IRead_DemIf_Per_CTerm_Cnt_lgc();
	EtatMt_Cnt_T_u08 = Rte_IRead_DemIf_Per_EtatMt_Cnt_u08();
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();

	if (IoHwAb_BoolType_LowerLimit == Ignition_Cnt_T_enum)
	{
		if ((FALSE == CTerm_Cnt_T_lgc)						  &&
			(RTE_MODE_StaMd_Mode_OPERATE != SystemState_Cnt_T_enum))
		{
			CTCInhibitionEsc_Cnt_M_u32 = Time_ms_T_u32;
			CTCInhibitionBsi_Cnt_M_u32 = Time_ms_T_u32;
			CTCInhibitionCmm_Cnt_M_u32 = Time_ms_T_u32;
		}
		CTCInhibitionCav_Cnt_M_u32 = Time_ms_T_u32;
		CTCInhibitionAas_Cnt_M_u32 = Time_ms_T_u32;
	}

	if (((uint8)kETAT_MT_Starting == EtatMt_Cnt_T_u08)	 ||
		((uint8)kETAT_MT_Autonomous_Starting == EtatMt_Cnt_T_u08))
	{
		CTCInhibitionEsc_Cnt_M_u32 = Time_ms_T_u32;
		CTCInhibitionCav_Cnt_M_u32 = Time_ms_T_u32;
		CTCInhibitionAas_Cnt_M_u32 = Time_ms_T_u32;
	}
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
