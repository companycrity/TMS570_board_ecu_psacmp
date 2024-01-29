
#ifndef DMA_H
#define DMA_H

typedef struct
{
	uint16	FastSPI_Cnt_u16[3];
	uint16	SlowSPI_Cnt_u16[3];
	uint16	SlowADC_Cnt_u16[4];
	uint16	FastADC_Cnt_u16[4];
	uint16	PWMCmp_Cnt_u16[4][2];
	uint32	PWMPeriod_Cnt_u32;
} DMADataType_Str;

extern volatile VAR(DMADataType_Str, DMA_VAR) DMAData_G_str;

extern FUNC(boolean, DMA_CODE) Dma_SlowADCGroupValidity(void);

#endif
