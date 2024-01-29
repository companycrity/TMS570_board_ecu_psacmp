
#ifndef EPS_DIAGSRVCS_SRVCLUTBL_H
#define EPS_DIAGSRVCS_SRVCLUTBL_H

#include "Rte_Type.h"

#define Rte_NvmBlock_Polarity_Polarity_Cnt_Str (6)
#define Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32 (7)
#define NVM_BLOCK_CMS_NXTRMEC (13)

extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_AppBlock_Start;
extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_AppBlock_Length;
extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_CalBlock_Start;
extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_CalBlock_Length;
extern VAR(ManufModeType, EPSDIAGSRVCS_VAR) NxtrMEC_Uls_G_enum;
extern VAR(uint8, NVM_APPL_DATA) Nvm_NMEC_Cnt_u8;

extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetErrorStatus(NvM_BlockIdType BlockId, P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr);
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock(NvM_BlockIdType BlockId, P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr);
extern FUNC(void, EPSDIAGSRVCS_CODE) EPS_DiagSrvcs_Init(void);

#endif
