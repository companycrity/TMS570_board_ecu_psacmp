#include "T1_AppInterface.h"
#include "T1_AppInterface_Cfg.h"
#include "Std_Types.h"

#ifdef T1_ENABLE


#define T1_START_SEC_CODE
#include "T1_MemMap.h"

/* Message reception handler. Pass all data back to T1.*/
void GliwaT1_MsgProcess_RxT1HostToTarget(CanReceiveHandle rcvObject)
{
	VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;
	
	CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();
	
	/* Parameter must be at module scope. */
	(void)T1_RxCallback((T1_rawData_t*)&(XCP_RES._c[0]));
	
	if( 0u == CallerIsTrusted_Cnt_T_u32 )
	{
		osSwitchToUserMode();
	}
}

/* Called by T1 when it has data it wants to put on the bus. */
T1_status_t T1_Transmit(T1_rawData_t const * pRawData)
{
	T1_status_t RetVal_Cnt_T_Enum;
	
	XCP_REQ._c[0] = pRawData->d.u8[0];
	XCP_REQ._c[1] = pRawData->d.u8[1];
	XCP_REQ._c[2] = pRawData->d.u8[2];
	XCP_REQ._c[3] = pRawData->d.u8[3];
	XCP_REQ._c[4] = pRawData->d.u8[4];
	XCP_REQ._c[5] = pRawData->d.u8[5];
	XCP_REQ._c[6] = pRawData->d.u8[6];
	XCP_REQ._c[7] = pRawData->d.u8[7];
	
	/* Transmit the message on bus zero (HS). */
	if( kCanTxOk == CanTransmit(CanTxXCP_REQ) )
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
	/* do nothing */
}


#endif
