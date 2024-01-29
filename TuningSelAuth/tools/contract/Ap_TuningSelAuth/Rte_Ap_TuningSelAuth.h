/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_TuningSelAuth.h
 *     Workspace:  C:/SynergyEA3/Working/TuningSelAuth/autosar
 *     SW-C Type:  Ap_TuningSelAuth
 *  Generated at:  Thu May 19 15:31:22 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_TuningSelAuth> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TUNINGSELAUTH_H
# define _RTE_AP_TUNINGSELAUTH_H

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

typedef P2CONST(struct Rte_CDS_Ap_TuningSelAuth, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ActiveTunOvrPtrAddr_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ActiveTunPers_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_ActiveTunSet_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_DesiredTunPers_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_DesiredTunSet_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_TunReqGranted_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TuningSessionActPtr_Cnt_u8 ((TuningSessionAddrPtrEnum)255u)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_TuningSelAuth_Init1_DesiredTunPers_Cnt_u16() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_DesiredTunPers_Cnt_u16->value)

# define Rte_IRead_TuningSelAuth_Init1_DesiredTunSet_Cnt_u16() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_DesiredTunSet_Cnt_u16->value)

# define Rte_IWrite_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_ActiveTunPers_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16() \
  (&Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_ActiveTunPers_Cnt_u16->value)

# define Rte_IWrite_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_ActiveTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16() \
  (&Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Init1_ActiveTunSet_Cnt_u16->value)

# define Rte_IRead_TuningSelAuth_Per1_ActiveTunOvrPtrAddr_Cnt_u32() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_ActiveTunOvrPtrAddr_Cnt_u32->value)

# define Rte_IRead_TuningSelAuth_Per1_DesiredTunPers_Cnt_u16() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_DesiredTunPers_Cnt_u16->value)

# define Rte_IRead_TuningSelAuth_Per1_DesiredTunSet_Cnt_u16() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_DesiredTunSet_Cnt_u16->value)

# define Rte_IRead_TuningSelAuth_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_TuningSelAuth_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_TuningSelAuth_Per1_TuningSessionActPtr_Cnt_u8() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_TuningSessionActPtr_Cnt_u8->value)

# define Rte_IRead_TuningSelAuth_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_ActiveTunPers_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16() \
  (&Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_ActiveTunPers_Cnt_u16->value)

# define Rte_IWrite_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_ActiveTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16() \
  (&Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_ActiveTunSet_Cnt_u16->value)

# define Rte_IWrite_TuningSelAuth_Per1_TunReqGranted_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_TunReqGranted_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_TuningSelAuth_Per1_TunReqGranted_Cnt_lgc() \
  (&Rte_Inst_Ap_TuningSelAuth->TuningSelAuth_Per1_TunReqGranted_Cnt_lgc->value)




# define RTE_START_SEC_AP_TUNINGSELAUTH_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TuningSelAuth_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_TuningSelAuth_Init1_DesiredTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_TuningSelAuth_Init1_DesiredTunSet_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(void)
 *   void Rte_IWrite_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TUNINGSELAUTH_APPL_CODE) TuningSelAuth_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TuningSelAuth_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_TuningSelAuth_Per1_ActiveTunOvrPtrAddr_Cnt_u32(void)
 *   UInt16 Rte_IRead_TuningSelAuth_Per1_DesiredTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_TuningSelAuth_Per1_DesiredTunSet_Cnt_u16(void)
 *   Float Rte_IRead_TuningSelAuth_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_TuningSelAuth_Per1_HwTorque_HwNm_f32(void)
 *   TuningSessionAddrPtrEnum Rte_IRead_TuningSelAuth_Per1_TuningSessionActPtr_Cnt_u8(void)
 *   Float Rte_IRead_TuningSelAuth_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(void)
 *   void Rte_IWrite_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(void)
 *   void Rte_IWrite_TuningSelAuth_Per1_TunReqGranted_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TuningSelAuth_Per1_TunReqGranted_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TUNINGSELAUTH_APPL_CODE) TuningSelAuth_Per1(void);

# define RTE_STOP_SEC_AP_TUNINGSELAUTH_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1463688610
#    error "The magic number of the generated file <C:/SynergyEA3/Working/TuningSelAuth/tools/contract/Ap_TuningSelAuth/Rte_Ap_TuningSelAuth.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1463688610
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TUNINGSELAUTH_H */
