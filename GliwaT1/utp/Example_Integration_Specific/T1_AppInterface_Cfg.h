#ifndef T1_APPINTERFACE_CFG_H
#define T1_APPINTERFACE_CFG_H

#include "il_inc.h"
#include "can_cfg.h"
#include "can_par.h"

#define D_I2CNXT_CNT_U08 T1_Isr_I2c_ID
#define D_SPINXT1_CNT_U08 0u /* This interrupt is defined in C1xx, but not used. */
#define D_SPINXT2_CNT_U08 0u /* This interrupt is defined in C1xx, but not used. */

#define PollT1HostToTarget() (void)CanRxFullCANObjTask(CanRxT1_HostToTarget_HW_CHANNEL, CanRxT1_HostToTarget_HW_OBJ)

#define D_GLIWAT1_SWITCHTOPRIVMODE_CNT_LGC STD_ON
#define D_GLIWAT1_SLOWWAITSTATES_CNT_LGC STD_ON /* slow here means 3dws 1aws. */

#endif
