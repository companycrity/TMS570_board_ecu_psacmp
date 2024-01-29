#include "T1_AppInterface.h"
#include "T1_AppInterface_Cfg.h"

#ifdef T1_ENABLE


#define T1_START_SEC_NO_INIT_8
#include "T1_MemMap.h"
static uint8 Buffer_Cnt_T_u08[8u];
#define T1_STOP_SEC_NO_INIT_8
#include "T1_MemMap.h"

#define T1_START_SEC_CODE
#include "T1_MemMap.h"
/* Message reception handler. Pass all data back to T1.*/
void GliwaT1_MsgProcess_RxT1HostToTarget(CanReceiveHandle rcvObject)
{
	VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;

	CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();

	IlGetRxT1_HostToTarget(Buffer_Cnt_T_u08);

	/* Parameter must be at module scope. */
	(void)T1_RxCallback((T1_rawData_t*)Buffer_Cnt_T_u08);

	if(0u == CallerIsTrusted_Cnt_T_u32)
	{
		osSwitchToUserMode();
	}
}

/* Called by T1 when it has data it wants to put on the bus. */
T1_status_t T1_Transmit(T1_rawData_t const * pRawData)
{
	T1_status_t RetVal_Cnt_T_Enum;
	tCanMsgTransmitStruct Message_Cnt_T_Str;

	/* Send a raw message using exactly the data passsed from T1. */
	CanMsgTransmitSetStdId(&Message_Cnt_T_Str, 0x7FAu);
	CanMsgTransmitSetDlc(&Message_Cnt_T_Str, 8u);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 0u, pRawData->d.u8[0]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 1u, pRawData->d.u8[1]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 2u, pRawData->d.u8[2]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 3u, pRawData->d.u8[3]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 4u, pRawData->d.u8[4]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 5u, pRawData->d.u8[5]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 6u, pRawData->d.u8[6]);
	CanMsgTransmitSetData(&Message_Cnt_T_Str, 7u, pRawData->d.u8[7]);

	/* Transmit the message on bus zero (HS). */
	if(kCanTxOk == CanMsgTransmit(0u, &Message_Cnt_T_Str))
	{
		RetVal_Cnt_T_Enum = T1_OK;
	}
	else
	{
		RetVal_Cnt_T_Enum = T1_FAILED;
	}

	return RetVal_Cnt_T_Enum;
}

#define T1_STOP_SEC_CODE
#include "T1_MemMap.h"

#else

void GliwaT1_MsgProcess_RxT1HostToTarget(CanReceiveHandle rcvObject)
{
	/* Do nothing. */
}

#endif
