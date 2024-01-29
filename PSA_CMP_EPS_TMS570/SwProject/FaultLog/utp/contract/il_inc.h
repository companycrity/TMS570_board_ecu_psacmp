
#ifndef IL_INC_H
#define IL_INC_H

#include "Std_Types.h"

typedef uint16 CanReceiveHandle;

extern void FaultLog_RxISACQJDDCANBSI772(CanReceiveHandle rcvObject);
extern void FaultLog_RxISACQNEWJDD55F(CanReceiveHandle rcvObject);

extern uint8 IlGetRxDATA_ACQ_JDD_BSI_2(void);
extern uint8 IlGetRxDATA_ACQ_JDD_BSI(void);
extern void IlPutTxNumber_of_Frames(uint8 sigData);
extern void IlPutTxFrame_Number(uint8 sigData);
extern void IlPutTxDTC_State(uint8 sigData);
extern void IlPutTxType_of_Message(uint8 sigData);
extern void IlPutTxJDD_Byte1(uint8 sigData);
extern void IlPutTxJDD_Byte2(uint8 sigData);
extern void IlPutTxJDD_Byte3(uint8 sigData);
extern void IlPutTxJDD_Byte4(uint8 sigData);
extern void IlPutTxJDD_Byte5(uint8 sigData);
extern void IlPutTxJDD_Byte6(uint8 sigData);
extern void IlPutTxJDD_Byte7(uint8 sigData);

#endif
