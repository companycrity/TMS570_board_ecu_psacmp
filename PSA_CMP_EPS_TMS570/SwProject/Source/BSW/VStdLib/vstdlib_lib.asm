;/**********************************************************************************************************************
;| Project Name: vstdlib library
;|    File Name: vstdlib_lib.asm
;|
;|  Description: Low level part of the implementation of standard Vector functions.
;|               ARM core specific implementation.
;|
;|----------------------------------------------------------------------------------------------------------------------
;|               C O P Y R I G H T
;|----------------------------------------------------------------------------------------------------------------------
;|   Copyright (c) by Vector Informatik GmbH.     All rights reserved.
;|
;|   This software is copyright protected and proprietary to 
;|   Vector Informatik GmbH. Vector Informatik GmbH grants to you 
;|   only those rights as set out in the license conditions. All 
;|   other rights remain with Vector Informatik GmbH.
;|
;|----------------------------------------------------------------------------------------------------------------------
;|               A U T H O R   I D E N T I T Y
;|----------------------------------------------------------------------------------------------------------------------
;| Initials     Name                      Company
;| --------     ---------------------     ------------------------------------------------------------------------------
;| Pl           Georg Pfluegel            Vector Informatik GmbH
;|----------------------------------------------------------------------------------------------------------------------
;|               R E V I S I O N   H I S T O R Y
;|----------------------------------------------------------------------------------------------------------------------
;| Date       Version   Author  Description
;|----------  --------  ------  ----------------------------------------------------------------------------------------
;| 2013-02-27  01.00.00    Pl     - Creation
;|                        
;|********************************************************************************************************************/

; This ASM-functions located in vstdlib_lib.asm get and set the value of the PRIMASK register.
; They are only for use in vstdlib.c together with TI compiler and an Cotex M3 CPU.
                   
               .global _getPRIMASK
               .global _setPRIMASK


;|********************************************************************************************************************/
;| Name:             _getPRIMASK
;| Parameters:       none
;| Return values:    R0 contains value of PRIMASK
;|********************************************************************************************************************/

_getPRIMASK:
               MRS r0, PRIMASK
               MOV pc, lr



;|********************************************************************************************************************/
;| Name:             _setPRIMASK
;| Parameters:       R0 contains new value for PRIMASK 
;| Return values:    none
;|********************************************************************************************************************/

_setPRIMASK:
               MSR PRIMASK, r0
               MOV pc, lr


