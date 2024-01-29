/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_XCP.Interface.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations that are used for XCP services. This file
* may need to be modified based on SIP versions and changes between programs.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Jul 17 11:00:00 2013
 * %version:          2 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Wed Feb 26 16:27:20 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version 2
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "XcpProf.h"	/* Required for XCP structure access */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_XCP_DATAINT_H
#define EPS_DIAGSRVCS_XCP_DATAINT_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* XCP IDs
 * These IDs are used with the diagnostic service and should be updated if they do not match the program
 */
#define D_XCP_MASTER_ID_ULS_U32				0x000007AEu
#define D_XCP_SLAVE_ID_ULS_U32				0x000007B0u
#define D_XCP_FLEXRAY_BASE_CYCLE_ULS_U8		0u
#define D_XCP_FLEXRAY_CYCLE_REP_ULS_U8		0u

/* XCP Structure Access 
 * Note: The following may need to change between programs and versions XCP driver from vector */
extern VAR(tXcpData, XCP_VAR) xcp;

/* Copied from XcpProf.c, required for downloads/uploads. */
#define XcpUserSetMta(p,e) 				(xcp.Mta = (p))

/* Transport layer limits */
#define D_XCP_TL_MAXCTO				kCanXcpMaxCTO
#define D_XCP_TL_MAXREQLEN			8U	/* Keep all max lengths to 8 bytes. Common between Flexray and CAN. */

/* XCP Vector User Functions (see EPS_DiagSrvcs_XCP.Vector.c) */
extern FUNC(void, EPSXCPDIAGSRVCS_CODE) XcpUserFreeDaq(void);
extern FUNC(void, EPSXCPDIAGSRVCS_CODE) XcpUserMemSet( BYTEPTR p, vuint16 n, vuint8 b );
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserAllocDaq(vuint8 daqCount);
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserAllocOdt( vuint8 daq, vuint8 odtCount );
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserAllocOdtEntry( vuint8 daq, vuint8 odt, vuint8 odtEntryCount );
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserAllocMemory( void );
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserSetDaqListMode( vuint8 Mode, vuint8 daq, vuint8 event, uint8 prescale );
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserSetDaqPtr( vuint8 daq, vuint8 odt, vuint8 idx);
extern FUNC(vuint8, EPSXCPDIAGSRVCS_CODE) XcpUserWriteDaq( vuint8 bitOffset, vuint8 daqSize, vuint8 addrExtension, vuint32 address );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


 
#endif /* EPS_DIAGSRVCS_XCP_DATAINT_H */
