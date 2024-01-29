
#ifndef IL_INC_H
#define IL_INC_H

#define kEFFAC_DEFAULT_DIAG_Default_Memory_Erase 1
#define kCALIBRATION_VOL_Calibrated 1
#define kTRIM_VOL_Trimmed 1
#define kCODE_DEFAUT_VOL_No_Default___Failure 0
#define kANGLE_VOLANT_ORIGINE_Other 3
#define CanRxIS_DAT_BSI_572_HW_OBJ           46
#define CanRxIS_DAT_BSI_572_HW_CHANNEL       0
#define CanRxPROTO_HS1_DYN_UCF_5CD_HW_OBJ    45
#define CanRxPROTO_HS1_DYN_UCF_5CD_HW_CHANNEL 0
#define CanRxIS_ACQ_JDD_CAN_BSI_772          0
#define CanRxPROTO_HS1_DYN_UCF_5CD           1
#define CanRxIS_DAT_BSI_572                  2
#define CanRxIS_ACQ_NEW_JDD_55F              3
#define CanRxIS_DAT4_V2_BSI_552              4
#define CanRxIS_DAT_ABR_50D                  5
#define CanRxIS_DAT_BSI_432                  6
#define CanRxIS_DAT_BSI_412                  7
#define CanRxIS_DAT_BSI_3F2                  8
#define CanRxIS_DYN2_FRE_3CD                 9
#define CanRxIS_DYN_CMM_388                  10
#define CanRxIS_DYN_CDS_34D                  11
#define CanRxIS_DYN2_CMM_348                 12
#define CanRxIS_DYN_VOL                      13
#define CanRxIS_DYN_CMM_208                  14
#define CanRxIS_INTE_ELECTRON_BSI            15
#define CanRxIS_DIAG_UDS_ON_CAN_7FF          16
#define CanRxXCP_RES                         17
#define CanRxXCP_REQ                         18
#define CanRxIS_REQ_DIAG_ON_CAN              19
#define CanRxIS_DYN_ABR                      20
#define CanRxIS_DYN_AAS                      21
#define IlTxMsgHndIS_DYN_VOL                 3
#define kCanInitObj1                         0
# define kCanNoCopyData                      ((vuint8)0x00)
# define kCanCopyData                        ((vuint8)0x01)
# define CanRxActualDLC(rxStruct)            ((*(rxStruct->pChipMsgObj+5)) & 0x000F)
# define CanResetBusOffEnd(a)  


typedef uint8              vuint8;
typedef uint16             vuint16;
typedef uint32             vuint32;
typedef unsigned int       vbittype;
typedef sint8               vsint8;
typedef vsint8              Il_Status;
typedef vuint16            CanInitHandle;
typedef vuint16            CanChannelHandle;
typedef volatile vuint8 *  CanChipMsgPtr;
typedef volatile vuint8 *  CanChipDataPtr;
typedef vuint16            CanReceiveHandle;
typedef vuint16            CanTransmitHandle;
typedef vuint8 IlTransmitHandle;

typedef struct 
{
  CanChannelHandle  Channel;
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanReceiveHandle  Handle;
/* CPU-specific part */
} tCanRxInfoStruct;

typedef tCanRxInfoStruct * CanRxInfoStructPtr;

typedef struct 
{
  CanChipDataPtr     pChipData;
  CanTransmitHandle  Handle;
/* CPU-specific part */
} tCanTxInfoStruct;

typedef tCanTxInfoStruct   CanTxInfoStruct;

typedef struct _c_IS_DYN_DAE_msgTypeTag
{
  vbittype CHKSUM_TRME_DYN_DAE : 4;
  vbittype CPT_PROCESS_4B_DAE : 4;
  vbittype CPLE_VOLANT_OPTMSE : 8;
  vbittype unused0 : 1;
  vbittype ETAT_DAE_CPK : 2;
  vbittype CAUSE_DESACTIV_CPK : 3;
  vbittype unused1 : 2;
  vbittype ANGLE_COLONNE_1 : 8;
  vbittype ANGLE_COLONNE_0 : 8;
  vbittype VITESSE_COLONNE_1 : 8;
  vbittype VITESSE_COLONNE_0 : 4;
  vbittype unused2 : 3;
  vbittype ETAT_SECU_ANGLE_COL : 1;
} _c_IS_DYN_DAE_msgType;

typedef struct _c_IS_DYN_VOL_msgTypeTag
{
  vbittype ANGLE_VOLANT_1 : 8;
  vbittype ANGLE_VOLANT_0 : 8;
  vbittype VITESSE_ROT_VOL : 8;
  vbittype SENS_ROT_VOL : 1;
  vbittype CODE_DEFAUT_VOL : 4;
  vbittype TRIM_VOL : 1;
  vbittype CALIBRATION_VOL : 1;
  vbittype ETAT_CAPT_VOL : 1;
  vbittype CHKSUM_VOL : 4;
  vbittype CPT_PROCESS_4B_A_VOL : 4;
  vbittype VITESSE_ROT_VOL_OPTIMISE : 8;
  vbittype FLG_INIT_AVOL : 1;
  vbittype FLG_AVOL_ICN : 1;
  vbittype ANGLE_VOLANT_ORIGINE : 2;
  vbittype RESERVED : 4;
} _c_IS_DYN_VOL_msgType;

typedef union _c_IS_DYN_DAE_bufTag
{
  vuint8 _c[7];
  _c_IS_DYN_DAE_msgType IS_DYN_DAE;
} _c_IS_DYN_DAE_buf;
typedef union _c_IS_DYN_VOL_bufTag
{
  vuint8 _c[7];
  _c_IS_DYN_VOL_msgType IS_DYN_VOL;
} _c_IS_DYN_VOL_buf;
extern _c_IS_DYN_VOL_buf IS_DYN_VOL;
extern _c_IS_DYN_DAE_buf IS_DYN_DAE;

extern void CanTask(void);
extern void IlRxTask(void);
extern void IlTxTask(void);
extern void IlRxStart(void);
extern void IlTxStart(void);
extern void IlTxStop(void);
extern uint8 IlGetRxLXA_ACTIVATION(void);
extern uint8 IlGetRxLKA_STATE(void);
extern uint8 IlGetRxLKA_TRQ_FACT_REQ(void);
extern uint8 IlGetRxMsg552_Byte0(void);
extern uint8 IlGetRxMsg552_Byte1(void);
extern uint8 IlGetRxMsg552_Byte2(void);
extern uint8 IlGetRxMsg552_Byte3(void);
extern uint8 IlGetRxMsg552_Byte4(void);
extern uint8 IlGetRxMsg552_Byte5(void);
extern uint8 IlGetRxMsg552_Byte6(void);
extern uint8 IlGetRxMsg552_Byte7(void);
extern uint8 IlGetRxETAT_PRINCIP_SEV(void);
extern uint8 IlGetRxPower_Supplies(void);
extern uint8 IlGetRxShunt_Position(void);
extern uint8 IlGetRxETAT_RESEAU_ELEC(void);
extern uint8 IlGetRxMARCHE_AR_BVM(void);
extern uint8 IlGetRxDMD_DELEST_DA(void);
extern uint8 IlGetRxETAT_MT(void);
extern uint8 IlGetRxDIAG_MUX_ON(void);
extern uint8 IlGetRxEFFAC_DEFAULT_DIAG(void);
extern uint8 IlGetRxMODE_DIAG(void);
extern uint8 IlGetRxDIAG_INTEGRA_ELEC(void);
extern uint16 IlGetRxVITESSE_VEHICLE_BV(void);
extern uint16 IlGetRxCOLUMN_ANGLE_SETPOINT(void);
extern uint8 IlGetRxRegul_ABR(void);         
extern uint8 IlGetRxREQ_Lampe_DEF_ESP(void); 
extern uint8 IlGetRxRegul_ESP(void);         
extern uint8 IlGetRxESP_Deconnecte(void);
extern uint16 IlGetRxAccel_Lat(void);
extern uint8 IlGetRxReq_Mode_DA(void);
extern uint8 IlGetRxCONFIG_VHL(void);
extern Il_Status IlStopCycle(IlTransmitHandle ilTxHnd);
extern void IlPutTxSystem_Code(vuint8 sigData);
extern void IlPutTxDownload_Day(vuint8 sigData);
extern void IlPutTxDownload_Month(vuint8 sigData);
extern void IlPutTxDownload_Year(vuint8 sigData);
extern void IlPutTxApplication_Code(vuint8 sigData);
extern void IlPutTxSoftware_Version(vuint8 sigData);
extern void IlPutTxSoftware_Edition_MSB(vuint8 sigData);
extern void IlPutTxSoftware_Edition_LSB(vuint8 sigData);
extern void IlPutTxCODE_DEFAUT(vuint8 sigData);
extern void IlPutTxSTATUS_CONFABSENT(vuint32 sigData);
extern void IlPutTxETAT_ASSIST_DA(vuint8 sigData);
extern void IlPutTxETAT_LIGNE_APC(vuint8 sigData);
extern void IlPutTxANGLE_COLONNE(vuint16 sigData);
extern void IlPutTxVITESSE_COLONNE(vuint16 sigData);
extern void IlPutTxCPLE_VOLANT(vuint8 sigData);
extern void IlPutTxETAT_DA_DYN(vuint8 sigData);
extern void IlPutTxETAT_DA_2004(vuint8 sigData);
extern void IlPutTxETAT_DA_2010(vuint8 sigData);
extern void IlPutTxAUTOR_ARRET_MOT_DA(vuint8 sigData);
extern void IlPutTxDDE_REDEM_DA(vuint8 sigData);
extern void IlPutTxCPT_PROCESS_4B_DAE(vuint8 sigData);
extern void IlPutTxCHKSUM_TRME_DYN_DAE(vuint8 sigData);
extern void IlPutTxCPLE_VOLANT_OPTMSE(vuint8 sigData);
extern void IlPutTxCAUSE_DESACTIV_CPK(vuint8 sigData);
extern void IlPutTxETAT_DAE_CPK(vuint8 sigData);
extern void IlPutTxETAT_SECU_ANGLE_COL(vuint8 sigData);
extern void IlPutTxEPS_STATE_LKA(vuint8 sigData);
extern void IlPutTxSTEERWHL_HOLD_BY_DRV(vuint8 sigData);
extern void ApplCanAddCanInterruptDisable(CanChannelHandle channel);
extern void ApplCanAddCanInterruptRestore(CanChannelHandle channel);


extern void IlPutTxANGLE_VOLANT(vuint16 sigData);
extern void IlPutTxVITESSE_ROT_VOL(vuint8 sigData);
extern void IlPutTxETAT_CAPT_VOL(vuint8 sigData);
extern void IlPutTxCALIBRATION_VOL(vuint8 sigData);
extern void IlPutTxTRIM_VOL(vuint8 sigData);
extern void IlPutTxCODE_DEFAUT_VOL(vuint8 sigData);
extern void IlPutTxSENS_ROT_VOL(vuint8 sigData);
extern void IlPutTxVITESSE_ROT_VOL_OPTIMISE(vuint8 sigData);
extern void IlPutTxRESERVED(vuint8 sigData);
extern void IlPutTxANGLE_VOLANT_ORIGINE(vuint8 sigData);
extern void IlPutTxFLG_INIT_AVOL(vuint8 sigData);
extern void IlPutTxFLG_AVOL_ICN(vuint8 sigData);   
extern void IlPutTxETAT_DAE_CAV3_VIRTUEL(vuint8 sigData);   
extern void ApplIlTxStart(void);   


extern vuint8 SrlComDriver_PreRxISDATBSI(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreTxISDATDIRA(CanTxInfoStruct ctis);
extern vuint8 SrlComDriver_PreTxISDYNVOL(CanTxInfoStruct ctis);
extern vuint8 SrlComDriver_PreTxISDYNDAE(CanTxInfoStruct ctis);
extern vuint8 SrlComDriver_PreRxISDAT4V2BSI552(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNAAS(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxPROTOHS1DYNUCF5CD(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNABR(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNVOL(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreTxISSUPVDIRA(CanTxInfoStruct ctis);
extern void SrlComDriver_TxISDATDIRA(CanTransmitHandle txObject);
extern void SrlComDriver_TxISDYNVOL(CanTransmitHandle txObject);
extern void SrlComDriver_TxISDYNDAE(CanTransmitHandle txObject);
extern void SrlComDriver_RxISDATBSI432(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATBSI412(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATBSI3F2(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYNCMM388(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYN2CMM(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYNCMM208(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISINTEELECTRONBSI(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATABR50D(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYN2FRE3CD(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYNCDS34D(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATBSI572(CanReceiveHandle rcvObject);
extern void CanStart(void);
extern void CanStop(void);
extern void CanOnline(void);
extern void CanOffline(void);
extern void ApplCanBusOff(void);
extern void ApplCanMsgDlcFailed( CanRxInfoStructPtr rxStruct );
extern void CanResetBusOffStart( CanInitHandle initObject );



typedef struct _c_IS_SUPV_DIRA_Group_msgTypeTag
{
  vbittype CODE_DEFAUT : 8;
  vbittype STATUS_CONFABSENT_3 : 8;
  vbittype STATUS_CONFABSENT_2 : 8;
  vbittype STATUS_CONFABSENT_1 : 8;
  vbittype STATUS_CONFABSENT_0 : 8;
  vbittype ETAT_LIGNE_APC : 1;
  vbittype ETAT_ASSIST_DA : 3;
  vbittype unused0 : 4;
} _c_IS_SUPV_DIRA_Group_msgType;
typedef struct _c_IS_DAT_DIRA_Group_msgTypeTag
{
  vbittype CPLE_VOLANT : 8;
  vbittype ETAT_DA_2010 : 2;
  vbittype ETAT_DA_DYN : 2;
  vbittype unused0 : 2;
  vbittype ETAT_DA_2004 : 2;
  vbittype DDE_REDEM_DA : 1;
  vbittype unused1 : 1;
  vbittype AUTOR_ARRET_MOT_DA : 1;
  vbittype EPS_STATE_LKA : 3;
  vbittype STEERWHL_HOLD_BY_DRV : 1;
  vbittype TRQ_LIMIT_STATE : 1;
} _c_IS_DAT_DIRA_Group_msgType;
typedef struct _c_IS_DYN_VOL_GroupBase_msgTypeTag
{
  vbittype ANGLE_VOLANT_1 : 8;
  vbittype ANGLE_VOLANT_0 : 8;
  vbittype VITESSE_ROT_VOL : 8;
  vbittype SENS_ROT_VOL : 1;
  vbittype unused0 : 7;
  vbittype CHKSUM_VOL : 4;
  vbittype CPT_PROCESS_4B_A_VOL : 4;
} _c_IS_DYN_VOL_GroupBase_msgType;
typedef struct _c_IS_DYN_VOL_GroupAdd_msgTypeTag
{
  vbittype unused0 : 1;
  vbittype CODE_DEFAUT_VOL : 4;
  vbittype TRIM_VOL : 1;
  vbittype CALIBRATION_VOL : 1;
  vbittype ETAT_CAPT_VOL : 1;
  vbittype unused1 : 8;
  vbittype VITESSE_ROT_VOL_OPTIMISE : 8;
  vbittype FLG_INIT_AVOL : 1;
  vbittype FLG_AVOL_ICN : 1;
  vbittype ANGLE_VOLANT_ORIGINE : 2;
  vbittype RESERVED : 4;
} _c_IS_DYN_VOL_GroupAdd_msgType;
typedef struct _c_IS_DYN_DAE_Group_msgTypeTag
{
  vbittype CHKSUM_TRME_DYN_DAE : 4;
  vbittype CPT_PROCESS_4B_DAE : 4;
  vbittype CPLE_VOLANT_OPTMSE : 8;
  vbittype unused0 : 1;
  vbittype ETAT_DAE_CPK : 2;
  vbittype CAUSE_DESACTIV_CPK : 3;
  vbittype unused1 : 2;
  vbittype ANGLE_COLONNE_1 : 8;
  vbittype ANGLE_COLONNE_0 : 8;
  vbittype VITESSE_COLONNE_1 : 8;
  vbittype VITESSE_COLONNE_0 : 4;
  vbittype ETAT_DAE_CAV3_VIRTUEL : 3;
  vbittype ETAT_SECU_ANGLE_COL : 1;
} _c_IS_DYN_DAE_Group_msgType;



typedef union _c_IS_SUPV_DIRA_Group_bufTag
{
  vuint8 _c[6];
  _c_IS_SUPV_DIRA_Group_msgType IS_SUPV_DIRA_Group;
} _c_IS_SUPV_DIRA_Group_buf;
typedef union _c_IS_DAT_DIRA_Group_bufTag
{
  vuint8 _c[3];
  _c_IS_DAT_DIRA_Group_msgType IS_DAT_DIRA_Group;
} _c_IS_DAT_DIRA_Group_buf;
typedef union _c_IS_DYN_VOL_GroupBase_bufTag
{
  vuint8 _c[5];
  _c_IS_DYN_VOL_GroupBase_msgType IS_DYN_VOL_GroupBase;
} _c_IS_DYN_VOL_GroupBase_buf;
typedef union _c_IS_DYN_VOL_GroupAdd_bufTag
{
  vuint8 _c[4];
  _c_IS_DYN_VOL_GroupAdd_msgType IS_DYN_VOL_GroupAdd;
} _c_IS_DYN_VOL_GroupAdd_buf;
typedef union _c_IS_DYN_DAE_Group_bufTag
{
  vuint8 _c[7];
  _c_IS_DYN_DAE_Group_msgType IS_DYN_DAE_Group;
} _c_IS_DYN_DAE_Group_buf;

#define V_MEMRAM0
#define V_MEMRAM1
#define V_MEMRAM2

V_MEMRAM0 V_MEMRAM1 _c_IS_SUPV_DIRA_Group_buf V_MEMRAM2 IS_SUPV_DIRA_Group;
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT_DIRA_Group_buf V_MEMRAM2 IS_DAT_DIRA_Group;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_VOL_GroupBase_buf V_MEMRAM2 IS_DYN_VOL_GroupBase;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_VOL_GroupAdd_buf V_MEMRAM2 IS_DYN_VOL_GroupAdd;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_DAE_Group_buf V_MEMRAM2 IS_DYN_DAE_Group;

extern void IlPutTxIS_SUPV_DIRA_GroupShadowBuffer(_c_IS_SUPV_DIRA_Group_buf* pBuffer);
extern void IlPutTxIS_DAT_DIRA_GroupShadowBuffer(_c_IS_DAT_DIRA_Group_buf* pBuffer);
extern void IlPutTxIS_DYN_VOL_GroupBaseShadowBuffer(_c_IS_DYN_VOL_GroupBase_buf* pBuffer);
extern void IlPutTxIS_DYN_VOL_GroupAddShadowBuffer(_c_IS_DYN_VOL_GroupAdd_buf* pBuffer);
extern void IlPutTxIS_DYN_DAE_GroupShadowBuffer(_c_IS_DYN_DAE_Group_buf* pBuffer);

/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Group Access Redefines
 ----------------------------------------------------------------------------- */

#define IlPutTxIS_SUPV_DIRA_Group()          (IlPutTxIS_SUPV_DIRA_GroupShadowBuffer(&IS_SUPV_DIRA_Group))
#define IlPutTxIS_DAT_DIRA_Group()           (IlPutTxIS_DAT_DIRA_GroupShadowBuffer(&IS_DAT_DIRA_Group))
#define IlPutTxIS_DYN_VOL_GroupBase()        (IlPutTxIS_DYN_VOL_GroupBaseShadowBuffer(&IS_DYN_VOL_GroupBase))
#define IlPutTxIS_DYN_VOL_GroupAdd()         (IlPutTxIS_DYN_VOL_GroupAddShadowBuffer(&IS_DYN_VOL_GroupAdd))
#define IlPutTxIS_DYN_DAE_Group()            (IlPutTxIS_DYN_DAE_GroupShadowBuffer(&IS_DYN_DAE_Group))

#endif
