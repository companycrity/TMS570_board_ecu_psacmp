#ifndef __PhaseAbcFdbkMeas_h
#define __PhaseAbcFdbkMeas_h

#define HET_v2 1
#define AID1_7

#include "std_nhet.h"

#define HET_FRCTR_1	(e_HETPROGRAM1_UN.Program1_ST.FRCTR_1)
#define pHET_FRCTR_1  	0

#define HET_P1ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P1ACC_1)
#define pHET_P1ACC_1  	1

#define HET_P2ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P2ACC_1)
#define pHET_P2ACC_1  	2

#define HET_P3ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P3ACC_1)
#define pHET_P3ACC_1  	3

#define HET_END_1	(e_HETPROGRAM1_UN.Program1_ST.END_1)
#define pHET_END_1  	4



typedef union 
{ 
 	HET_MEMORY	Memory1_PST[5];
	struct
	{
		CNT_INSTRUCTION FRCTR_1;
		ECNT_INSTRUCTION P1ACC_1;
		ECNT_INSTRUCTION P2ACC_1;
		ECNT_INSTRUCTION P3ACC_1;
		BR_INSTRUCTION END_1;
	} Program1_ST; 

} HETPROGRAM1_UN;

extern volatile HETPROGRAM1_UN e_HETPROGRAM1_UN;

extern const HET_MEMORY HET_INIT1_PST[5];

#endif

