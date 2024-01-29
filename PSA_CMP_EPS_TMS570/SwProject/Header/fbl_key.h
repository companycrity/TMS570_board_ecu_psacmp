/* -----------------------------------------------------------------------------
  Filename:    fbl_key.h
  Program:     PSA_BMPV
  Description: This is a shared header file between bootloader and application.
               This file provides access to security algorithm to the application. Per PSA requirement the actual security algorithm resides in the bootloader.
               This file gives  access to the key algorithm via function pointer. Function pointer resides in FBL_HEADER.
 ----------------------------------------------------------------------------- */

#ifndef FBL_KEY_H
#define FBL_KEY_H

#include "fbl_def.h"
#include "v_def.h"

/* Define function pointer type for "CalculateKey" function */
typedef vuint32 (*FblKeyFct)( vuint32, vuint16 );

/* Define the location of "CalculateKey" function pointer */
#define FblKeyFunctionPtr ((FblKeyFct *)(FBL_HEADER_ADDRESS + 0x000C))

/* Use this macro from Application to access Security Key algorithm function "CalculateKey" */
#define CallFblKey( SecuritySeed, Appli_Key )      (( *FblKeyFunctionPtr )( SecuritySeed, Appli_Key ))

#endif
