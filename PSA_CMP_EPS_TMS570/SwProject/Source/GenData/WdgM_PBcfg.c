/*** Generated code, do not change!                                        ***/
/*** Module WdgM_PBcfg, written by Wdg_Mgr_Cfg_Gen 2.0.1 (build 204883) on ***/
/*** Wed 03-Sep-2014 15:42:08                                              ***/

#include "WdgM.h"
#include "WdgM_PBcfg.h"

#define NR_OF_CHECKPOINTS 30
#define NR_OF_ENTITIES 15
#define NR_OF_WATCHDOGS 1
#define NR_OF_TRIGGER_MODES 1
#define NR_OF_ALLOWED_CALLERS 1
#define NR_OF_GLOBAL_TRANSITIONS 11
#define NR_OF_LOCAL_TRANSITIONS 15


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_2ms_9                                                  */
static WdgM_EntityStatusLType EntityStatusL_0;
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE0_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_2ms_9`                                */
static WdgM_AliveCounterLType Alive_CounterL_0;
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_2ms_10                                                 */
static WdgM_EntityStatusLType EntityStatusL_1;
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_2ms_11                                                 */
static WdgM_EntityStatusLType EntityStatusL_2;
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE3_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_2ms_6                                                  */
static WdgM_EntityStatusLType EntityStatusL_3;
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE3_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_2ms_6`                                */
static WdgM_AliveCounterLType Alive_CounterL_1;
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE4_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_4ms_9                                                  */
static WdgM_EntityStatusLType EntityStatusL_4;
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE4_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_4ms_9`                                */
static WdgM_AliveCounterLType Alive_CounterL_2;
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE5_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_4ms_10                                                 */
static WdgM_EntityStatusLType EntityStatusL_5;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE5_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_4ms_10`                               */
static WdgM_AliveCounterLType Alive_CounterL_3;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE6_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_10ms_9                                                 */
static WdgM_EntityStatusLType EntityStatusL_6;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE6_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_10ms_9`                               */
static WdgM_AliveCounterLType Alive_CounterL_4;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE7_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_10ms_10a                                               */
static WdgM_EntityStatusLType EntityStatusL_7;
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE8_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_10ms_6                                                 */
static WdgM_EntityStatusLType EntityStatusL_8;
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE9_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_10ms_10b                                               */
static WdgM_EntityStatusLType EntityStatusL_9;
#define WDGM_SE9_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE10_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_10ms_11                                                */
static WdgM_EntityStatusLType EntityStatusL_10;
#define WDGM_SE10_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE10_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_10ms_11`                              */
static WdgM_AliveCounterLType Alive_CounterL_5;
#define WDGM_SE10_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE11_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_100ms_9                                                */
static WdgM_EntityStatusLType EntityStatusL_11;
#define WDGM_SE11_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE11_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_100ms_9`                              */
static WdgM_AliveCounterLType Alive_CounterL_6;
#define WDGM_SE11_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE12_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_100ms_10                                               */
static WdgM_EntityStatusLType EntityStatusL_12;
#define WDGM_SE12_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE13_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_100ms_11                                               */
static WdgM_EntityStatusLType EntityStatusL_13;
#define WDGM_SE13_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE14_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE_100ms_6                                                */
static WdgM_EntityStatusLType EntityStatusL_14;
#define WDGM_SE14_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE14_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE_100ms_6`                              */
static WdgM_AliveCounterLType Alive_CounterL_7;
#define WDGM_SE14_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* Global Status for Supervised Entities                                     */
static WdgM_EntityStatusGType EntityStatusG_0;
static WdgM_EntityStatusGType EntityStatusG_1;
static WdgM_EntityStatusGType EntityStatusG_2;
static WdgM_EntityStatusGType EntityStatusG_3;
static WdgM_EntityStatusGType EntityStatusG_4;
static WdgM_EntityStatusGType EntityStatusG_5;
static WdgM_EntityStatusGType EntityStatusG_6;
static WdgM_EntityStatusGType EntityStatusG_7;
static WdgM_EntityStatusGType EntityStatusG_8;
static WdgM_EntityStatusGType EntityStatusG_9;
static WdgM_EntityStatusGType EntityStatusG_10;
static WdgM_EntityStatusGType EntityStatusG_11;
static WdgM_EntityStatusGType EntityStatusG_12;
static WdgM_EntityStatusGType EntityStatusG_13;
static WdgM_EntityStatusGType EntityStatusG_14;

/* Global Alive Counters for Checkpoints in SE `SE_2ms_9`                    */
static WdgM_AliveCounterGType Alive_CounterG_0;

/* Global Alive Counters for Checkpoints in SE `SE_2ms_6`                    */
static WdgM_AliveCounterGType Alive_CounterG_1;

/* Global Alive Counters for Checkpoints in SE `SE_4ms_9`                    */
static WdgM_AliveCounterGType Alive_CounterG_2;

/* Global Alive Counters for Checkpoints in SE `SE_4ms_10`                   */
static WdgM_AliveCounterGType Alive_CounterG_3;

/* Global Alive Counters for Checkpoints in SE `SE_10ms_9`                   */
static WdgM_AliveCounterGType Alive_CounterG_4;

/* Global Alive Counters for Checkpoints in SE `SE_10ms_11`                  */
static WdgM_AliveCounterGType Alive_CounterG_5;

/* Global Alive Counters for Checkpoints in SE `SE_100ms_9`                  */
static WdgM_AliveCounterGType Alive_CounterG_6;

/* Global Alive Counters for Checkpoints in SE `SE_100ms_6`                  */
static WdgM_AliveCounterGType Alive_CounterG_7;

/* RAM section for Global Status                                             */
static WdgM_DataGType StatusG;
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for Global Shared data                                        */
static WdgM_DataGSType StatusGS;
static WdgM_EntityGSType EntityGS [NR_OF_ENTITIES];
static WdgM_GlobalTransitionFlagGSType GlobalTransitionFlagsGS [NR_OF_GLOBAL_TRANSITIONS];
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TransitionType WdgMTransition [NR_OF_LOCAL_TRANSITIONS] =
  { { 0 /* SE_2ms_9 */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp9_2msStart_CP */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [0]                                                               */
  , { 1 /* SE_2ms_10 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp10_2msStart_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [1]                                                               */
  , { 2 /* SE_2ms_11 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp11_2msStart_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [2]                                                               */
  , { 3 /* SE_2ms_6 */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp6_2msStart_CP */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [3]                                                               */
  , { 4 /* SE_4ms_9 */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp9_4msStart_CP */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [4]                                                               */
  , { 5 /* SE_4ms_10 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp10_4msStart_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [5]                                                               */
  , { 6 /* SE_10ms_9 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp9_10msStart_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [6]                                                               */
  , { 7 /* SE_10ms_10a */ /* EntitySourceId                                  */
    , 0 /* ChkPtAp10_10msaStart_CP */ /* CheckpointSourceId                  */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [7]                                                               */
  , { 8 /* SE_10ms_6 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp6_10msStart_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [8]                                                               */
  , { 9 /* SE_10ms_10b */ /* EntitySourceId                                  */
    , 0 /* ChkPtAp10_10msbStart_CP */ /* CheckpointSourceId                  */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [9]                                                               */
  , { 10 /* SE_10ms_11 */ /* EntitySourceId                                  */
    , 0 /* ChkPtAp11_10msStart_CP */ /* CheckpointSourceId                   */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [10]                                                              */
  , { 11 /* SE_100ms_9 */ /* EntitySourceId                                  */
    , 0 /* ChkPtAp9_100msStart_CP */ /* CheckpointSourceId                   */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [11]                                                              */
  , { 12 /* SE_100ms_10 */ /* EntitySourceId                                 */
    , 0 /* ChkPtAp10_100msStart_CP */ /* CheckpointSourceId                  */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [12]                                                              */
  , { 13 /* SE_100ms_11 */ /* EntitySourceId                                 */
    , 0 /* ChkPtAp11_100msStart_CP */ /* CheckpointSourceId                  */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [13]                                                              */
  , { 14 /* SE_100ms_6 */ /* EntitySourceId                                  */
    , 0 /* ChkPtAp6_100msStart_CP */ /* CheckpointSourceId                   */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [14]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_GlobalTransitionType WdgMGlobalTransition [NR_OF_GLOBAL_TRANSITIONS] =
  { { 0 /* SE_2ms_9 */ /* EntitySourceId                                     */
    , 1 /* ChkPtAp9_2msEnd_CP */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 0 /* GlobalTransitionFlagId                                              */
    } /* [0]                                                               */
  , { 1 /* SE_2ms_10 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp10_2msEnd_CP */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 1 /* GlobalTransitionFlagId                                              */
    } /* [1]                                                               */
  , { 2 /* SE_2ms_11 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp11_2msEnd_CP */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 2 /* GlobalTransitionFlagId                                              */
    } /* [2]                                                               */
  , { 4 /* SE_4ms_9 */ /* EntitySourceId                                     */
    , 1 /* ChkPtAp9_4msEnd_CP */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 3 /* GlobalTransitionFlagId                                              */
    } /* [3]                                                               */
  , { 6 /* SE_10ms_9 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp9_10msEnd_CP */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 4 /* GlobalTransitionFlagId                                              */
    } /* [4]                                                               */
  , { 7 /* SE_10ms_10a */ /* EntitySourceId                                  */
    , 1 /* ChkPtAp10_10msaEnd_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 5 /* GlobalTransitionFlagId                                              */
    } /* [5]                                                               */
  , { 8 /* SE_10ms_6 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp6_10msEnd_CP */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 6 /* GlobalTransitionFlagId                                              */
    } /* [6]                                                               */
  , { 9 /* SE_10ms_10b */ /* EntitySourceId                                  */
    , 1 /* ChkPtAp10_10msbEnd_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 7 /* GlobalTransitionFlagId                                              */
    } /* [7]                                                               */
  , { 11 /* SE_100ms_9 */ /* EntitySourceId                                  */
    , 1 /* ChkPtAp9_100msEnd_CP */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 8 /* GlobalTransitionFlagId                                              */
    } /* [8]                                                               */
  , { 12 /* SE_100ms_10 */ /* EntitySourceId                                 */
    , 1 /* ChkPtAp10_100msEnd_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 9 /* GlobalTransitionFlagId                                              */
    } /* [9]                                                               */
  , { 13 /* SE_100ms_11 */ /* EntitySourceId                                 */
    , 1 /* ChkPtAp11_100msEnd_CP */ /* CheckpointSourceId                    */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 10 /* GlobalTransitionFlagId                                             */
    } /* [10]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_TransitionIdType StartsGlobalTransition_SE_10ms_10b_ChkPtAp10_10msbEnd_CP [1] =
  { 7 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_100ms_10_ChkPtAp10_100msEnd_CP [1] =
  { 9 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_10ms_9_ChkPtAp9_10msEnd_CP [1] =
  { 4 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_100ms_11_ChkPtAp11_100msEnd_CP [1] =
  { 10 /* [0]                                                                */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_2ms_9_ChkPtAp9_2msEnd_CP [1] =
  { 0 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_2ms_11_ChkPtAp11_2msEnd_CP [1] =
  { 2 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_10ms_6_ChkPtAp6_10msEnd_CP [1] =
  { 6 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_4ms_9_ChkPtAp9_4msEnd_CP [1] =
  { 3 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_100ms_9_ChkPtAp9_100msEnd_CP [1] =
  { 8 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_2ms_10_ChkPtAp10_2msEnd_CP [1] =
  { 1 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE_10ms_10a_ChkPtAp10_10msaEnd_CP [1] =
  { 5 /* [0]                                                                 */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_CheckPointType WdgMCheckPoint [NR_OF_CHECKPOINTS] =
  { { 0 /* SE_2ms_9/ChkPtAp9_2msStart_CP */ /* WdgMCheckpointId              */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_0 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_0 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [0]                                                               */
  , { 1 /* SE_2ms_9/ChkPtAp9_2msEnd_CP */ /* WdgMCheckpointId                */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [0] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_2ms_9_ChkPtAp9_2msEnd_CP /* WdgMStartedGlobalT */
     /* ransitionIds       */
    } /* [1]                                                               */
  , { 0 /* SE_2ms_10/ChkPtAp10_2msStart_CP */ /* WdgMCheckpointId            */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [0] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [2]                                                               */
  , { 1 /* SE_2ms_10/ChkPtAp10_2msEnd_CP */ /* WdgMCheckpointId              */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [1] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_2ms_10_ChkPtAp10_2msEnd_CP /* WdgMStartedGloba */
     /* lTransitionIds   */
    } /* [3]                                                               */
  , { 0 /* SE_2ms_11/ChkPtAp11_2msStart_CP */ /* WdgMCheckpointId            */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [1] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [4]                                                               */
  , { 1 /* SE_2ms_11/ChkPtAp11_2msEnd_CP */ /* WdgMCheckpointId              */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [2] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_2ms_11_ChkPtAp11_2msEnd_CP /* WdgMStartedGloba */
     /* lTransitionIds   */
    } /* [5]                                                               */
  , { 0 /* SE_2ms_6/ChkPtAp6_2msStart_CP */ /* WdgMCheckpointId              */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [2] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [6]                                                               */
  , { 1 /* SE_2ms_6/ChkPtAp6_2msEnd_CP */ /* WdgMCheckpointId                */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_1 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_1 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [3] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [7]                                                               */
  , { 0 /* SE_4ms_9/ChkPtAp9_4msStart_CP */ /* WdgMCheckpointId              */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_2 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_2 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [8]                                                               */
  , { 1 /* SE_4ms_9/ChkPtAp9_4msEnd_CP */ /* WdgMCheckpointId                */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [4] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_4ms_9_ChkPtAp9_4msEnd_CP /* WdgMStartedGlobalT */
     /* ransitionIds       */
    } /* [9]                                                               */
  , { 0 /* SE_4ms_10/ChkPtAp10_4msStart_CP */ /* WdgMCheckpointId            */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [3] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [10]                                                              */
  , { 1 /* SE_4ms_10/ChkPtAp10_4msEnd_CP */ /* WdgMCheckpointId              */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_3 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_3 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [5] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [11]                                                              */
  , { 0 /* SE_10ms_9/ChkPtAp9_10msStart_CP */ /* WdgMCheckpointId            */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_4 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_4 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [12]                                                              */
  , { 1 /* SE_10ms_9/ChkPtAp9_10msEnd_CP */ /* WdgMCheckpointId              */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [6] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_10ms_9_ChkPtAp9_10msEnd_CP /* WdgMStartedGloba */
     /* lTransitionIds   */
    } /* [13]                                                              */
  , { 0 /* SE_10ms_10a/ChkPtAp10_10msaStart_CP */ /* WdgMCheckpointId        */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [4] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [14]                                                              */
  , { 1 /* SE_10ms_10a/ChkPtAp10_10msaEnd_CP */ /* WdgMCheckpointId          */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [7] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_10ms_10a_ChkPtAp10_10msaEnd_CP /* WdgMStartedG */
     /* lobalTransit */
     /* ionIds       */
    } /* [15]                                                              */
  , { 0 /* SE_10ms_6/ChkPtAp6_10msStart_CP */ /* WdgMCheckpointId            */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [5] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [16]                                                              */
  , { 1 /* SE_10ms_6/ChkPtAp6_10msEnd_CP */ /* WdgMCheckpointId              */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [8] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_10ms_6_ChkPtAp6_10msEnd_CP /* WdgMStartedGloba */
     /* lTransitionIds   */
    } /* [17]                                                              */
  , { 0 /* SE_10ms_10b/ChkPtAp10_10msbStart_CP */ /* WdgMCheckpointId        */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [6] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [18]                                                              */
  , { 1 /* SE_10ms_10b/ChkPtAp10_10msbEnd_CP */ /* WdgMCheckpointId          */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [9] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_10ms_10b_ChkPtAp10_10msbEnd_CP /* WdgMStartedG */
     /* lobalTransit */
     /* ionIds       */
    } /* [19]                                                              */
  , { 0 /* SE_10ms_11/ChkPtAp11_10msStart_CP */ /* WdgMCheckpointId          */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [7] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [20]                                                              */
  , { 1 /* SE_10ms_11/ChkPtAp11_10msEnd_CP */ /* WdgMCheckpointId            */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_5 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_5 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [10] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [21]                                                              */
  , { 0 /* SE_100ms_9/ChkPtAp9_100msStart_CP */ /* WdgMCheckpointId          */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_6 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_6 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [22]                                                              */
  , { 1 /* SE_100ms_9/ChkPtAp9_100msEnd_CP */ /* WdgMCheckpointId            */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [11] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_100ms_9_ChkPtAp9_100msEnd_CP /* WdgMStartedGlo */
     /* balTransitionI */
     /* ds             */
    } /* [23]                                                              */
  , { 0 /* SE_100ms_10/ChkPtAp10_100msStart_CP */ /* WdgMCheckpointId        */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [8] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [24]                                                              */
  , { 1 /* SE_100ms_10/ChkPtAp10_100msEnd_CP */ /* WdgMCheckpointId          */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [12] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_100ms_10_ChkPtAp10_100msEnd_CP /* WdgMStartedG */
     /* lobalTransit */
     /* ionIds       */
    } /* [25]                                                              */
  , { 0 /* SE_100ms_11/ChkPtAp11_100msStart_CP */ /* WdgMCheckpointId        */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [9] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [26]                                                              */
  , { 1 /* SE_100ms_11/ChkPtAp11_100msEnd_CP */ /* WdgMCheckpointId          */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [13] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE_100ms_11_ChkPtAp11_100msEnd_CP /* WdgMStartedG */
     /* lobalTransit */
     /* ionIds       */
    } /* [27]                                                              */
  , { 0 /* SE_100ms_6/ChkPtAp6_100msStart_CP */ /* WdgMCheckpointId          */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [10] /* WdgMGlobalTransitionsRef                   */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [28]                                                              */
  , { 1 /* SE_100ms_6/ChkPtAp6_100msEnd_CP */ /* WdgMCheckpointId            */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_7 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_7 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [14] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [29]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_SupervisedEntityType WdgMSupervisedEntity [NR_OF_ENTITIES] =
  { { 0 /* SE_2ms_9 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [0] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_0 /* EntityStatusLRef                                     */
    , &EntityStatusG_0 /* EntityStatusGRef                                     */
    } /* [0]                                                               */
  , { 1 /* SE_2ms_10 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [2] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_1 /* EntityStatusLRef                                     */
    , &EntityStatusG_1 /* EntityStatusGRef                                     */
    } /* [1]                                                               */
  , { 2 /* SE_2ms_11 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [4] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_2 /* EntityStatusLRef                                     */
    , &EntityStatusG_2 /* EntityStatusGRef                                     */
    } /* [2]                                                               */
  , { 3 /* SE_2ms_6 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [6] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_3 /* EntityStatusLRef                                     */
    , &EntityStatusG_3 /* EntityStatusGRef                                     */
    } /* [3]                                                               */
  , { 4 /* SE_4ms_9 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [8] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_4 /* EntityStatusLRef                                     */
    , &EntityStatusG_4 /* EntityStatusGRef                                     */
    } /* [4]                                                               */
  , { 5 /* SE_4ms_10 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [10] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_5 /* EntityStatusLRef                                     */
    , &EntityStatusG_5 /* EntityStatusGRef                                     */
    } /* [5]                                                               */
  , { 6 /* SE_10ms_9 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [12] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_6 /* EntityStatusLRef                                     */
    , &EntityStatusG_6 /* EntityStatusGRef                                     */
    } /* [6]                                                               */
  , { 7 /* SE_10ms_10a */ /* WdgMSupervisedEntityId                          */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [14] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_7 /* EntityStatusLRef                                     */
    , &EntityStatusG_7 /* EntityStatusGRef                                     */
    } /* [7]                                                               */
  , { 8 /* SE_10ms_6 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [16] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_8 /* EntityStatusLRef                                     */
    , &EntityStatusG_8 /* EntityStatusGRef                                     */
    } /* [8]                                                               */
  , { 9 /* SE_10ms_10b */ /* WdgMSupervisedEntityId                          */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [18] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_9 /* EntityStatusLRef                                     */
    , &EntityStatusG_9 /* EntityStatusGRef                                     */
    } /* [9]                                                               */
  , { 10 /* SE_10ms_11 */ /* WdgMSupervisedEntityId                          */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [20] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_10 /* EntityStatusLRef                                    */
    , &EntityStatusG_10 /* EntityStatusGRef                                    */
    } /* [10]                                                              */
  , { 11 /* SE_100ms_9 */ /* WdgMSupervisedEntityId                          */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [22] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_11 /* EntityStatusLRef                                    */
    , &EntityStatusG_11 /* EntityStatusGRef                                    */
    } /* [11]                                                              */
  , { 12 /* SE_100ms_10 */ /* WdgMSupervisedEntityId                         */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [24] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_12 /* EntityStatusLRef                                    */
    , &EntityStatusG_12 /* EntityStatusGRef                                    */
    } /* [12]                                                              */
  , { 13 /* SE_100ms_11 */ /* WdgMSupervisedEntityId                         */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [26] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_13 /* EntityStatusLRef                                    */
    , &EntityStatusG_13 /* EntityStatusGRef                                    */
    } /* [13]                                                              */
  , { 14 /* SE_100ms_6 */ /* WdgMSupervisedEntityId                          */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [28] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_14 /* EntityStatusLRef                                    */
    , &EntityStatusG_14 /* EntityStatusGRef                                    */
    } /* [14]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TriggerModeType WdgMTriggerMode  [NR_OF_WATCHDOGS * NR_OF_TRIGGER_MODES] =
  { { 2 /* WdgMTriggerWindowStart                                            */
    , 2000  /* WdgMTicksPerSecond[Hz]=1000000 */ /* WdgMTriggerWindowStartTi */
     /* cks                      */
    , 6 /* WdgMTriggerTimeout                                                  */
    , 6000 /* WdgMTriggerTimeoutTicks                                          */
    , WDGIF_SLOW_MODE /* WdgMWatchdogMode                                      */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
/* [0]: Watchdog `WdgMWatchdog`, trigger mode ID `0`                         */


#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_WatchdogDeviceType WdgMWatchdogDevice [NR_OF_WATCHDOGS] =
  { { &WdgMTriggerMode  [0] /* WdgMTriggerModeRef                            */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_CallersType WdgMAllowedCallers  [NR_OF_ALLOWED_CALLERS] =
  { { 0 /* WdgMAllowedCaller                                                 */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
const WdgM_ConfigType WdgMConfig_Mode0 =
  { 2 /* WdgMConfigMajorVersion                                              */
  , 0 /* WdgMConfigMinorVersion                                              */
  , 0 /* WdgMConfigId                                                        */
  , 0 /* WdgMInitialTriggerModeId                                              */
  , 0 /* WdgMExpiredSupervisionCycleTol                                        */
  , 0 /* WdgMGlobInitialEntityId                                               */
  , 0 /* WdgMGlobInitialCheckpointId                                           */
  , NR_OF_CHECKPOINTS /* NrOfAllCheckpoints                                    */
  , NR_OF_GLOBAL_TRANSITIONS /* NrOfGlobalTransitions                          */
  , NR_OF_WATCHDOGS /* NrOfWatchdogDevices                                     */
  , NR_OF_TRIGGER_MODES /* NrOfTriggerModes                                    */
  , WdgMWatchdogDevice /* WdgMWatchdogDeviceRef                                */
  , NR_OF_ALLOWED_CALLERS /* NrOfAllowedCallers                                */
  , WdgMAllowedCallers  /* WdgMCallersRef                                      */
  , NR_OF_ENTITIES /* NrOfSupervisedEntities                                   */
  , WdgMSupervisedEntity /* WdgMSupervisedEntityRef                            */
  , &StatusG /* DataGRef                                                       */
  , &StatusGS /* DataGSRef                                                     */
  , EntityGS /* EntityGSRef                                                    */
  , GlobalTransitionFlagsGS /* GlobalTransitionFlagsGSRef                      */
  , NULL_PTR /* WdgM_GlobalStateChangeCbk                                      */
  , 180 /* WdgMConfigChecksum                                                  */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
