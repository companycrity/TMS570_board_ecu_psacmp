#ifndef T1_APPINTERFACE_CFG_H
#define T1_APPINTERFACE_CFG_H

#include "can_par.h"

#define D_SPINXT1_CNT_U08 0u
#define D_SPINXT2_CNT_U08 0u

#define PollT1HostToTarget() (void)0

#define D_GLIWAT1_SWITCHTOPRIVMODE_CNT_LGC STD_ON
#define D_GLIWAT1_SLOWWAITSTATES_CNT_LGC STD_ON /* slow here means 3dws 1aws. */

#endif
