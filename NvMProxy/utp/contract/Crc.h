
/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined CRC_H_)
#define CRC_H_

typedef P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataRefType;

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(Crc_DataRefType Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16);

#endif
/* ---- End of File --------------------------------------------------------- */
