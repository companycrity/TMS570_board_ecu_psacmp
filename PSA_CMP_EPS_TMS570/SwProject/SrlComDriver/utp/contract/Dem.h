
#ifndef DEM_H
#define DEM_H

#define DEM_DTC_GROUP_ALL_DTCS                            0xffffffuL
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                     0x01u


typedef uint32 Dem_DTCGroupType;
typedef uint8 Dem_ReturnControlEventUpdateType;
typedef uint8 Dem_DTCOriginType;
typedef uint8 Dem_ReturnClearDTCType;

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_DisableEventStatusUpdate(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind);
FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_EnableEventStatusUpdate(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind);
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);

#endif
