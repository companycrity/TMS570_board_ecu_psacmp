
#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

typedef struct
{
    uint32 Response : 24;
    uint32 DEMEventID : 8;
} FltRsp_Str;


extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/20/2015 1:19:31 PM *******************/
/****************************** DiagSvc - Rev 6 ******************************/



extern CONST(float32, CAL_CONST) k_VehSpdResetThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_HwTrqResetThresh_Kph_f32;
extern CONST(uint16, CAL_CONST) k_SupplierCode_Cnt_u16;
extern CONST(uint8, CAL_CONST) k_SoftwareVersion_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_SoftwareEdition_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_CalibrationVersion_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_CalibrationEdition_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_NBRPARAMFLT_Cnt_u08;
extern CONST(uint8, CAL_CONST) t_F080Reseved_Cnt_u08[4];
extern CONST(uint8, CAL_CONST) k_VariantCodingIDTLC_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_VariantCodingSTTPO_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_VariantCodingCPKPO_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_VariantCodingCAVPO_Cnt_u08;
extern CONST(uint16, CAL_CONST) k_VariantCodingCPO_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_VariantCodingMPO_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_VariantCodingBVPO_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_VariantCodingPPO_Cnt_u32;
extern CONST(TuningSelectTableType_Str, CAL_CONST) k_TuningSelectTable_Cnt_str[128];
extern CONST(boolean, CAL_CONST) k_NonDefaultCalset_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_JDD2010Selected_Cnt_lgc;
#endif


