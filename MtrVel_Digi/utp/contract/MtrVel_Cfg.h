
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_MtrVel_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 30.11.2012 08:09:43
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          3 %
 * %date_modified:    Thu Aug 22 15:11:13 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 */

#ifndef MTRVEL_CFG_H
#define MTRVEL_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/



#define D_MTRVELOSBUFSZ_CNT_U08    8u   /*Based on the Buffer size*/
   
#define MtrVel_Read_MechMtrPos1_Rev_u0p16(ptr)  (*ptr)  = 1U /* From DigMSBSigCorr 50 MicroSec runnable*/
#define MtrVel_Read_MechMtrPos1TimeStamp_uS_u32(ptr)   (*ptr) =1U    /* From DigMSBSigCorr 50 MicroSec runnable*/

#endif /* MTRVEL_CFG_H */

/*** End of file **************************************************************/

