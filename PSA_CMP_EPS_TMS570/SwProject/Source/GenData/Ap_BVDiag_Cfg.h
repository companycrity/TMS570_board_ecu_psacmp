
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_BVDiag_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 31.01.2014 16:27:23
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Wed Feb 26 16:36:22 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 09/16/13	  2       NRAR      Added Cfg constant to enable NTC B1 as per customer requirement                8712
 * 11/14/13   3       Jared     Added config constant to enable using ElPw input for SrlCom to conditionally
 *                              set NTC B1 for some programs.                                                  9935
 */

#ifndef AP_BVDIAG_CFG_H
#define AP_BVDIAG_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


/* Disable all checkpoints that are not enabled */
#define Rte_Call_BVDiag_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */
#define Rte_Call_BVDiag_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */


#define BC_B1_BATTVOLTDIAG STD_OFF   /* Configure this constant to ON or OFF based on customer requirements */
#define BC_B1_BATTVOLTDIAG_ELPW STD_OFF   /* Configure this constant to ON or OFF based on customer requirements */

#endif /* BVDIAG_CFG_H */

/*** End of file **************************************************************/
