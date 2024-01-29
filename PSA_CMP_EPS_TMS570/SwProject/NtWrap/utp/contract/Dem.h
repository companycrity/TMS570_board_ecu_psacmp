
#include "Std_Types.h"

typedef uint32 Dem_DTCType;
typedef uint8 Dem_DTCKindType;
typedef uint8 Dem_DTCOriginType;

typedef uint8 Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                      0x00  /* DTC successfully cleared */
#define DEM_CLEAR_WRONG_DTC                               0x01  /* Wrong DTC */
#define DEM_CLEAR_WRONG_DTCORIGIN                         0x02  /* Wrong DTC origin */
#define DEM_CLEAR_WRONG_DTCKIND                           0x03  /* DTC kind wrong */
#define DEM_CLEAR_FAILED                                  0x04  /* DTC not cleared */
#define DEM_DTC_PENDING                                   0x05  /* Clearing of DTC is pending */

extern Dem_ReturnClearDTCType Dem_ClearDTC(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);
