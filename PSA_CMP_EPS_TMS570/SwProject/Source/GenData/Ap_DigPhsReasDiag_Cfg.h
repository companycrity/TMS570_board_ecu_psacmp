
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DigPhsReasDiag_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 31.01.2014 16:28:02
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Wed Feb 26 16:36:30 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef AP_DIGPHSREASDIAG_CFG_H
#define AP_DIGPHSREASDIAG_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/



/* Disable all checkpoints that are not enabled */
#define Rte_Call_DigPhsReasDiag_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_DigPhsReasDiag_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 

#define D_NHETFREQUENCY_HZ_F32		80000000.0F
#define D_MAXPWMFREQ_HZ_U32 18000U
   
#endif /* DIGPHSREASDIAG_CFG_H */

/*** End of file **************************************************************/
