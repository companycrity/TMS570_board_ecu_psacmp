/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Lnk_Symbols.h
* Module Description: This file contains the declarations of Link Time Symbols
*                     used in the application.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * %version:          1 %
 * %derived_by:       fzh7xw %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 06/10/16    1       WH       Initial Version copied from PSA_BMPV version 3
 */

#ifndef LNK_SYMBOLS_H
#define LNK_SYMBOLS_H

#include "Std_Types.h"

extern VAR(uint8, AUTOMATIC) Lnk_PSABootSoftIDNumber_Addr[];
extern VAR(uint8, AUTOMATIC) Lnk_BootRelNum_Addr[];

extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_BSS_Start;
extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_BSS_End;

#endif

