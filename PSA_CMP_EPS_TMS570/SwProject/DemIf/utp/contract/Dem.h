
#ifndef DEM_H
#define DEM_H

#include "Std_Types.h"
#include "Rte_Type.h"

FUNC(void, DEM_CODE) Dem_Shutdown(void);
FUNC(void, DEM_CODE) Dem_Init(void);
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState);

#endif
