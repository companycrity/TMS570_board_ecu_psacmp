/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_IoHwAb10.h
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  IoHwAb10
 *  Generated at:  Tue Aug 26 16:12:14 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <IoHwAb10> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB10_H
# define _RTE_IOHWAB10_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_IoHwAb10, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Batt_Volt_f32 (0.0F)
# define Rte_InitValue_BattSwitched_Volt_f32 (0.0F)
# define Rte_InitValue_SysCVSwitch_Volt_f32 (0.0F)
# define Rte_InitValue_SysCVSwitchADC_Cnt_u16 (0U)
# define Rte_InitValue_TemperatureADC_Volt_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb10_IoHwAb_Adc_ResetAdcEnable(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb10_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_IoHwAb_Init_BattSwitched_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_Init_BattSwitched_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_Init_BattSwitched_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_Init_BattSwitched_Volt_f32->value)

# define Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_Init_Batt_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_Init_Batt_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_Init_Batt_Volt_f32->value)

# define Rte_IWrite_IoHwAb_Init_SysCVSwitch_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_Init_SysCVSwitch_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_Init_SysCVSwitch_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_Init_SysCVSwitch_Volt_f32->value)

# define Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_Init_TemperatureADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_Init_TemperatureADC_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_Init_TemperatureADC_Volt_f32->value)

# define Rte_IRead_IoHwAb_ReadAdc_SysCVSwitchADC_Cnt_u16() \
  (Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_SysCVSwitchADC_Cnt_u16->value)

# define Rte_IWrite_IoHwAb_ReadAdc_BattSwitched_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_BattSwitched_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_ReadAdc_BattSwitched_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_BattSwitched_Volt_f32->value)

# define Rte_IWrite_IoHwAb_ReadAdc_Batt_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_Batt_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_ReadAdc_Batt_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_Batt_Volt_f32->value)

# define Rte_IWrite_IoHwAb_ReadAdc_SysCVSwitch_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_SysCVSwitch_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_ReadAdc_SysCVSwitch_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_SysCVSwitch_Volt_f32->value)

# define Rte_IWrite_IoHwAb_ReadAdc_TemperatureADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_TemperatureADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb_ReadAdc_TemperatureADC_Volt_f32() \
  (&Rte_Inst_IoHwAb10->IoHwAb_ReadAdc_TemperatureADC_Volt_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_IoHwAb_Adc_ResetAdcEnable Rte_Call_IoHwAb10_IoHwAb_Adc_ResetAdcEnable
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_IoHwAb10_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_IOHWAB10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb_Init_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_TemperatureADC_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) IoHwAb_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_ReadAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_IoHwAb_ReadAdc_SysCVSwitchADC_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb_ReadAdc_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadAdc_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadAdc_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadAdc_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadAdc_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadAdc_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadAdc_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadAdc_TemperatureADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_Adc_ResetAdcEnable(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) IoHwAb_ReadAdc(void);

# define RTE_STOP_SEC_IOHWAB10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1409086341
#    error "The magic number of the generated file <C:/Users/nzx5jd/Desktop/DVOutput/IoHwAb10/Rte_IoHwAb10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1409086341
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_IOHWAB10_H */
