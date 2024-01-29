/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Usr_RegCkDefs.h
* Module Description: User defined external definitions for uDiag Reg Check
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          1 %
* %derived_by:       fzh7xw %
* %date_modified:    Wed Feb 26 16:29:25 2014 % 
*---------------------------------------------------------------------------*/
#ifndef USR_REGCKDEFS_H
#define USR_REGCKDEFS_H

/* Function Definitions provided for functions that are referenced in the Register
 * Check configuration, but are not available as part of the external API for a 
 * component (i.e. the functions are not defined in a header file).
 */
extern FUNC(void, CD_UDIAG_APPL_CODE) VIM_Fallback(void);											 

#endif /*USR_REGCKDEFS_H*/
