/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_Vmm.h
 *   Description:  Header of BSW Scheduler for Vmm
 *********************************************************************************************************************/


#ifndef SCHM_VMM_H
#define SCHM_VMM_H


#include "SchM.h"


#define SchM_Enter_Vmm(area)	SCHM_ENTER_EXCLUSIVE(area)
#define SchM_Exit_Vmm(area)		SCHM_EXIT_EXCLUSIVE(area)


#endif
