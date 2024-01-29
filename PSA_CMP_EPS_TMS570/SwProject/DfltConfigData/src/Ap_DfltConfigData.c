/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.c
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/* Version Control:
* %version:          28 %
* %derived_by:       nz3337 %
*----------------------------------------------------------------------------------------------------------------------
* Date       Rev     Author   Change Description                                                                SCR #
* --------   ------  -------  -------------------------------------------------------------------------------  -------
* 06/10/16    1       WH       Initial Version copied from PSA_BMPV version                                    EA3#35
* 07/27/16    2       WH       Updated for new polarity component (ES-25C)                                     EA3#9275
* 07/29/16    3       WH       Update Software Name, release number, block/boot compatibility and manuf date   EA3#9275
* 08/30/16    4       WH       Update Software Name, release number, and manuf date   						   EA3#10606
* 08/30/16    5       WH       Update Software Name, release number, and manuf date   						   EA3#10606
* 09/22/16    6       WH       Update Software Name, release number, and manuf date   						   EA3#10606
* 11/13/16    7       WH       Update Software Name, release number, and manuf date   						   EA3#12483
* 11/17/16    8       WH       Update Software Name, release number, and manuf date   						   EA3#12454
* 11/23/16    9       WH       Update Software Name, release number, and manuf date   						   EA3#12792
* 11/24/16    10      WH       Update Software Name, release number, and manuf date, and block compatibility   EA3#12842
* 12/02/16    11      WH       Update Software Name, release number, and manuf date                            EA3#12963
* 12/19/16    12      AR       Update Software Name, release number, and manuf date, and block compatibility   EA3#13243
* 04/07/17    13      AR       Update Software Name, release number, and manuf date, and block compatibility   EA3#14785
* 04/27/17    14      AR       Update Software Name, release number, and manuf date, and block compatibility   EA3#15476
* 06/01/17    15      AR       Update Software Name, release number, and manuf date, and block compatibility   EA3#16065
* 06/01/17    17      RK       Update Software Name, release number, and manuf date, and block compatibility   EA3#16065
* 02/10/18    18      RK       Update block compatibility due to CalConstant clean up						   EA3#18194
* 02/12/18    19      RK       Update release number and manufacturing date									   EA3#18194
* 02/12/18    20      RK       Update release number and manufacturing date	after hot fix for NTC status	   EA3#18158
* 04/30/18    21      RK       Update release number and manufacturing date									   EA3#19793
* 05/05/18    22      RK       Update release number and manufacturing date	after hotfix for ->				   EA3#18231
* 05/18/18    23      RK       Update Software Name, release number, and manuf date, and block compatibility   EA3#19911
* 06/06/18    24      RK       Calibration compatibility break due to SrlComInput cal clean up				   EA3#20171
* 06/06/18    25      RK       Update release number and manufacturing date									   EA3#20115
* 06/13/18    26      RK       Update release number and manufacturing date									   EA3#20284
* 06/15/18    27      RK       Update release number and manufacturing date									   EA3#20388
* 07/17/18    28      RK       Update release number and manufacturing date									   EA3#20489
 */


#define RTE_MICROSAR_PIM_EXPORT
#include "Ap_DfltConfigData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "Cd_NvMProxy.h"
#include "DiagSvc.h"


/* Select the release suffix based on the build type*/
#if	defined(ENABLE_UTILIZATION_MONITOR)
	#define D_SUFFIX    "_U"
#elif defined(ENABLE_CPUUSE_METRICS)
	#define D_SUFFIX    "_T"
#elif defined(ENABLE_METRICS)
	#define D_SUFFIX    "_O"
#elif defined(SWEEPBUILD)
	#define D_SUFFIX    "_SWP1"
#else
	#define D_SUFFIX
#endif


#define D_BLOCKVERSIONCHECK_CNT_U16		114u
#define D_BOOTCOMPATIBILITY_CNT_U16		100u


/* Current Sw Release Number (from CM Synergy) - multiple strings are combined at compile time */
#pragma DATA_SECTION(k_SWRelNum_Cnt_u8,".SWRelNum");
CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[] = "PSA_CMP_05.04.00" D_SUFFIX;

CONST(ECUManufacturingDateType_Str, DIAGSVC_CONST) D_MANUFDATEINIT_CNT_STR = { 17u,		/* Day   -> 1 to 31 */
																			    7u,     /* Month -> 1 to 12 */
																			   18u };	/* Year  -> 0 to 99 */


/* Set up headers for logical blocks */
#pragma DATA_SECTION(T_AppBlockHeader_Cnt_u16,".AppBlockHeader");
CONST(uint16, CDD_PARTNUMBER) T_AppBlockHeader_Cnt_u16[2u] = { D_BLOCKVERSIONCHECK_CNT_U16, D_BOOTCOMPATIBILITY_CNT_U16 }; /* PRQA S 3408 */
#pragma DATA_SECTION(T_CalBlockHeader_Cnt_u16,".CalBlockHeader");
CONST(uint16, CDD_PARTNUMBER) T_CalBlockHeader_Cnt_u16[1u] = { D_BLOCKVERSIONCHECK_CNT_U16 }; /* PRQA S 3408 */


/* Ecu Status for Bootloader */
#pragma DATA_SECTION(T_EcuStatus_Cnt_u08,".EcuStatus");
CONST(uint8, CDD_PARTNUMBER) T_EcuStatus_Cnt_u08[16u] = { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, /* PRQA S 3408 */
														  0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu };


/* Initialized locally */
STATIC CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8 = 0xFEu; /* PRQA S 3218 */
STATIC CONST(float32, CDD_PARTNUMBER) T_InitTorqueCmdSF_Uls_f32 = 1.0f; /* PRQA S 3218 */


/* Initialized in driver */

CONST(PhaseCurrCal_DataType, AP_DFLTCONFIGDATA_CONST) T_ShCurrCalInit_Cnt_str =
					{ 53200.0f, 2.5f, 100.0f, 100.0f, 2.5f, 0.0f, 0.0f };

CONST(uint16, AP_DFLTCONFIGDATA_CONST) T_CogTrqCalInit_Cnt_u16[512] =
					  { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
						0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };

CONST(uint16, AP_DFLTCONFIGDATA_CONST) T_CogTrqRplCompInit_Cnt_u16[9] =
					  { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };

CONST(float32, AP_DFLTCONFIGDATA_CONST) T_TorqueCmdSFInit_Uls_f32 = 1.0f;

CONST(EOTLearned_DataType, AP_DFLTCONFIGDATA_CONST) T_LearnedEOTInit_Cnt_str =
					  { 0.0f, 0.0f, FALSE, FALSE };

CONST(AvgFricLrnType, AP_DFLTCONFIGDATA_CONST) T_AvgFricLrnDataInit_Cnt_str =
					  { 0.0f,
						0.0f,
						FALSE,
						TRUE,
						1u,
						{ {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u},
						  {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u} },
						{ {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
						  {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
						  {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
						  {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f} },
						{0.0f, 0.0f, 0.0f, 0.0f} };


/* Deprecated blocks */
#define DFLTCONFIGDATA_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint8, NVM_APPL_DATA) Deprecated_CmMtrCurr_CurrTempOffset[98u];
VAR(uint8, NVM_APPL_DATA) Deprecated_AbsHwPos_EOLVehCntrOffset[10u];
VAR(uint8, NVM_APPL_DATA) Deprecated_Dem_NvData[60u];
#define DFLTCONFIGDATA_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */


/* Processing Functions */
FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void)
{
	VAR(NvM_RequestResultType, AUTOMATIC) BlockStatus = 0u;
	VAR(ManufModeType, AUTOMATIC) NxtrMEC_Uls_T_enum;
	
	/* Nexteer MEC */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_NXTRMEC, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_NMEC_Cnt_u8 = T_InitNMEC_Cnt_u8;
	}
	
	EPS_DiagSrvcs_Init();
	
	/* Read MEC */
	NxtrMEC_Uls_T_enum = NxtrMEC_Uls_G_enum;
	
	/* The following section are block checks that require the MEC to be set in Manufacturing Mode */
	if (NxtrMEC_Uls_T_enum == ManufacturingMode )
	{
		
		/* Torque Command Scale Factor */
		NvM_GetErrorStatus((NvM_BlockIdType)Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			*((float32*)NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32) = T_InitTorqueCmdSF_Uls_f32; /* PRQA S 310 */
			(void)NvM_WriteBlock((NvM_BlockIdType)Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, NULL_PTR);
		}
		
	}
	
}


