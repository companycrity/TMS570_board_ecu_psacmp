
#include "Std_Types.h"

typedef uint32 Dem_DTCType;
#define DEM_DTC_GROUP_ALL_DTCS                            0xffffffuL        /* ISO 14229-1 Annex D.1: groupOfDTC parameter, All Groups (all DTCs) */

typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                             0x01  /* Select all DTCs */

typedef uint8 Dem_DTCOriginType;
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                     0x01  /* Event information located in the primary memory. */
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                      0x02  /* Event information located in the mirror memory. */
#define DEM_DTC_ORIGIN_PERMANENT                          0x03  /* not supported yet */
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY                   0x04  /* Event information located in the secondary memory. */

typedef uint8 Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                      0x00  /* DTC successfully cleared */
#define DEM_CLEAR_WRONG_DTC                               0x01  /* Wrong DTC */
#define DEM_CLEAR_WRONG_DTCORIGIN                         0x02  /* Wrong DTC origin */
#define DEM_CLEAR_WRONG_DTCKIND                           0x03  /* DTC kind wrong */
#define DEM_CLEAR_FAILED                                  0x04  /* DTC not cleared */
#define DEM_DTC_PENDING                                   0x05  /* Clearing of DTC is pending */
