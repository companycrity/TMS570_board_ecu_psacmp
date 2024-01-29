
#ifndef NVM_H
#define NVM_H

#include "Std_Types.h"

#define NVM_REQ_OK ((NvM_RequestResultType)0u)
#define Rte_NvmBlock_FaultLog_FaultLog ((NvM_BlockIdType)44)

typedef uint16 NvM_BlockIdType;

extern void NvM_GetErrorStatus( NvM_BlockIdType BlockId, uint8 * RequestResultPtr );
extern Std_ReturnType NvM_WriteBlock( NvM_BlockIdType BlockId, const uint8 * NvM_SrcPtr );

#endif
