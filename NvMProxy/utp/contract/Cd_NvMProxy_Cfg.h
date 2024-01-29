/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_NvMProxy_Cfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          2 %
 * %derived_by:       czgng4 %
 * %date_modified:    Thu Nov 21 09:39:36 2013 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 */

#ifndef NVMPROXY_CFG_H
#define NVMPROXY_CFG_H

/* Include defs for data block types */
#define RTE_MICROSAR_PIM_EXPORT /* Define the Rte constant to allow exporting of PIM types to this CDD */
#include "Rte_Type.h"
#include "NvM.h"
#include "Ap_DiagMgr.h"

typedef P2CONST(uint8, AUTOMATIC, AUTOMATIC) NvMP_FailActionDataType;
typedef P2FUNC(void, AUTOMATIC, NvMP_FailActFuncType)(void);

typedef enum {
	NVMPROXY_NONE = 0x00,
	NVMPROXY_CRC16 = 0x01,
	NVMPROXY_REDUNDANT = 0x02,
	NVMPROXY_ZERODATA = 0x03
}NvMProxy_InitHandling;

typedef enum {
	NVMPROXY_NOTAPPLICABLE = 0x00,
	NVMPROXY_NTC_0A = 0x01,
	NVMPROXY_NTC_08_ROMDEF = 0x02,
	NVMPROXY_NTC_08_NOTIFFUNC = 0x03,
	NVMPROXY_NTC_07_ROMDEF = 0x04,
	NVMPROXY_NTC_07_NOTIFFUNC = 0x05,
	NVMPROXY_NTC_06_ROMDEF = 0x06,
	NVMPROXY_NTC_06_NOTIFFUNC = 0x07
}NvMProxy_FailResponse;

typedef struct {
	CONST(NvM_BlockIdType, AUTOMATIC) NvMBlock;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) unsecurePtr;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) securePtr;
	CONST(uint16, AUTOMATIC) secureSize;
	CONST(NvMProxy_InitHandling, AUTOMTIC) initHandling;
	CONST(NvMProxy_FailResponse, AUTOMTIC) failResponse;
	CONST(NvMP_FailActionDataType, AUTOMATIC) failActData;
	CONST(NvMP_FailActFuncType, AUTOMATIC) failActFunc;
} NvMProxyCfg_Type;

#define D_NUMPRXYBLOCKS_CNT_U16    1U
#define NVMPROXY_REPORTERRORSTATUS		NxtrDiagMgr10_ReportNTCStatus

extern CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[ D_NUMPRXYBLOCKS_CNT_U16 ];
extern VAR(uint8, AUTOMATIC) NvMProxy_MtrPosSnsr_EOLData[];

#endif
