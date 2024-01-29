/***********************************************************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Linker.cmd
* Module Description: Linker Command File
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
***********************************************************************************************************************/
/***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       fzh7xw %
************************************************************************************************************************
* Change History:
* Date      Rev      Author    Change Description                                                                 CR#
* --------  -------  --------  ---------------------------------------------------------------------------------- -----
* 02/06/14   1       OT        Initial version
* 07/14/14   2       OT        Integrated GliwaT1
* 07/18/14   3       OT        Integrated Dma
* 08/11/14   4       OT        Update for bootloader changes
* 09/11/14   5       OT        Added fixed memory addresses for DIDs shared with bootloader                       12451
* 09/22/14   6       OT        Gliwa alignment fix and CRC category fix                                           12466
* 10/01/14   7       OT        Updates for new customer DIDs                                                      12363
* 10/20/14   8       OT        Added tuning sets                                                                  12266
* 10/31/14   9       OT        Moved global shared RAM out of bss section for math library anomaly                12648
* 12/15/15  10       OT        Moved several cals to Nexteer flash                                             EA3#5275
* 04/07/17  11       AR        Removed unused Tuning set and personalities, Gliwa RAM section changed          EA3#14456
***********************************************************************************************************************/


/*------------------------------------------------------------------------------------*/
/* Linker Settings                                                                    */
--retain="*(.intvecs)"

/*------------------------------------------------------------------------------------*/
/* Memory Map                                                                         */
MEMORY{
	
	/* Bootloader */
	BOOT			(RX) : origin=0x00000000 length=0x0000BFF8
	BOOT_CRC		(R)  : origin=0x0000BFF8 length=0x00000008
	
	/* Application */
	APP_FLASH		(RX) : origin=0x0000C000 length=0x00093F00 fill=0xFFFFFFFF
	APP_BOOTSHARED	(R)  : origin=0x0009FF00 length=0x000000F0 fill=0xFFFFFFFF
	APP_CRC			(R)  : origin=0x0009FFF0 length=0x00000008 fill=0xFFFFFFFF
	APP_BOOTCRC		(R)  : origin=0x0009FFF8 length=0x00000008 fill=0xFFFFFFFF
	
	/* Calibration */
	CAL_FLASH		(R)  : origin=0x000A0000 length=0x0001FFE0 fill=0xFFFFFFFF
	CAL_CRC			(R)  : origin=0x000BFFE0 length=0x00000008 fill=0xFFFFFFFF
	CAL_BOOTCRC		(R)  : origin=0x000BFFE8 length=0x00000008 fill=0xFFFFFFFF
	ECU_STATUS		(R)  : origin=0x000BFFF0 length=0x00000010 fill=0xFFFFFFFF
	
	/* RAM */
	RAM				(RW) : origin=0x08000000 length=0x0001FC00
	STACKS			(RW) : origin=0x0801FC00 length=0x000003F4
	BOOTSHARED		(RW) : origin=0x0801FFF4 length=0x0000000C
	
	/* NHET */
	NHET2RAM		(RW) : origin=0xFF440000 length=0x00000800
	NHETRAM			(RW) : origin=0xFF460000 length=0x00000800
	
	/* System Registers */
	MMC				(RW) : origin=0xFFFFFD00 length=0x40
	DEC				(RW) : origin=0xFFFFFE00 length=0x60
	SYS				(RW) : origin=0xFFFFFFD0 length=0x30
	
}

/*------------------------------------------------------------------------------------*/
/* Section Configuration                                                              */
SECTIONS{
	
	/*----------------------------------------------------------------------------*/
	/*                        Sections with Fixed Addresses                       */
	/*----------------------------------------------------------------------------*/
	
	.FblHeader				:	{} > 0x00000100
	
	.PSABootSoftIDNumber	: 	{
									Lnk_PSABootSoftIDNumber_Addr = .;
								} > 0x0000BFB0
	
	.BoolRelNum				: 	{
									Lnk_BootRelNum_Addr = .;
								} > 0x0000BFC0
	
	.AppBlockHeader			: 	{} > 0x0000C000
	
	.SWRelNum				: 	{} > 0x0000C004
	
	.osresetvect			:	{} > 0x00020060
	.osarmvect				:	{} > 0x00020064
	
	.SupplierCode			: 	{} > 0x0009FF00
	.SoftwareVersion		: 	{} > 0x0009FF04
	.SoftwareEdition		: 	{} > 0x0009FF08
	.CalibrationVersion		: 	{} > 0x0009FF0C
	.CalibrationEdition		: 	{} > 0x0009FF10
	.NBRPARAMFLT			: 	{} > 0x0009FF14
	.F080Reserved			: 	{} > 0x0009FF18
	
	.CalBlockHeader			: 	{} > 0x000A0000
	
	.EcuStatus				: 	{} > ECU_STATUS
	
	.resetcause				:	{} > 0x0801FFF4
	
	.MagicFlag				:	{} > 0x0801FFF8
	
	
	
	/*----------------------------------------------------------------------------*/
	/*                                RAM Segments                                */
	/*----------------------------------------------------------------------------*/
	
	.gsdata		:	{
						. = align(16384);   /* align to region size 16384 */
						_osGlobalSharedStartGlobalShared=.;
						/* Nexteer patch for math library global share requirement */
						*(.ossGlobalShared)
						*(.T1_bss)
						*(.T1_traceBuffer)
						rtsv7R4_T_be_v3D16_eabi.lib<*>(.data)
						_osGlobalSharedEndGlobalShared=.;
						. = . + 1;
						_osGlobalSharedSizeGlobalShared = _osGlobalSharedEndGlobalShared - _osGlobalSharedStartGlobalShared + 1;
						. = align(16384); /* Use 8 subregions with size 2048*/
					} > 0x08000000
	
	.bss    	:  	LOAD_END(Lnk_BSS_End),
					LOAD_START(Lnk_BSS_Start)
					{
						#include "./Source/GenDataOS/osobjs.inc"
						*(.ossctxdata)
					} > RAM
	
	.data   	: 	{
						#include "./Source/GenDataOS/osobjs_init.inc"
						*(.osstack)
					} > RAM
	

	.noclear	:	{} > RAM
	
	.stack		:	{
						_StackSVC_   = .+ (0x0100);
						_StackUSER_  = .+ (0x0200);
						_StackUND_   = .+ (0x0300); /* Share stacks for undefined instruction and data abort */
						_StackABORT_ = .+ (0x0300);
						_StackFIQ_   = .+ (0x0380);
						_StackIRQ_   = .+ (0x03F4);
					} > STACKS
	
	
	
	/*----------------------------------------------------------------------------*/
	/*                            Calibration Segment                             */
	/*----------------------------------------------------------------------------*/
	
	.TunSet0CalSeg	: {} > CAL_FLASH
	.TunSet1CalSeg	: {} > CAL_FLASH
	.TunSet2CalSeg	: {} > CAL_FLASH
	.TunSet3CalSeg	: {} > CAL_FLASH
	.TunSet4CalSeg	: {} > CAL_FLASH
	
	.FlashCalSeg	: {} > CAL_FLASH
    
    .TunCal0Per0CalSeg  : {} > CAL_FLASH
    .TunCal0Per1CalSeg  : {} > CAL_FLASH
    .TunCal0Per2CalSeg  : {} > CAL_FLASH
    .TunCal1Per0CalSeg  : {} > CAL_FLASH
    .TunCal1Per1CalSeg  : {} > CAL_FLASH
    .TunCal1Per2CalSeg  : {} > CAL_FLASH
    .TunCal2Per0CalSeg  : {} > CAL_FLASH
    .TunCal2Per1CalSeg  : {} > CAL_FLASH
    .TunCal2Per2CalSeg  : {} > CAL_FLASH
    .TunCal3Per0CalSeg  : {} > CAL_FLASH
    .TunCal3Per1CalSeg  : {} > CAL_FLASH
    .TunCal3Per2CalSeg  : {} > CAL_FLASH
    .TunCal4Per0CalSeg  : {} > CAL_FLASH
    .TunCal4Per1CalSeg  : {} > CAL_FLASH
    .TunCal4Per2CalSeg  : {} > CAL_FLASH

	/*----------------------------------------------------------------------------*/
	/*                             Application Segment                            */
	/*----------------------------------------------------------------------------*/
	
	.cinit     	:	{} > APP_FLASH
	
	.text     	:	{} > APP_FLASH
	
	.const     	:	{} > APP_FLASH
	
	.FlashAppSeg :	{} > APP_FLASH
	
	.OSAPPFLASH	:	{
						*(.osvtable)
						*(.oscode)
						*(.osconst)
						.=((.-1)/4)*4+4;  /* Force align to 32bits as osconfig is structure */
						/* Note this checksum has to run prior to the overall flash checksum */
						CCT_Range_00_Start = .;
						CCT_Range_00_BitAddrGran = 8;
						CCT_Range_00_Category = 300;
						CCT_Range_00_Algorithm = 10;
						*(.osconfig)
						CCT_Range_00_Length = . - CCT_Range_00_Start-2;
						CCT_Range_00_Address = CCT_Range_00_Start + CCT_Range_00_Length;
					} > APP_FLASH, palign(64)
	
	
	.T1_code	:	{} > APP_FLASH
	.T1_const	:	{} > APP_FLASH
	
	.T1_aligned	:	{
						. = align(16);
						*(.T1_codeFast:T1_TraceEvent_)
						. = align(16);
						*(.T1_codeFast:T1_TraceEventFast_)
						. = align(16);
						*(.T1_codeFast:T1_TraceEventNoSusp_)
						. = align(16);
						*(.T1_codeFast)
					} > APP_FLASH
	
	
	
	/*----------------------------------------------------------------------------*/
	/*                                NHET Segments                               */
	/*----------------------------------------------------------------------------*/
	
	.HETCODE	:	{ e_HETPROGRAM0_UN = .; } > 0xFF460000
	.HET2CODE	:	{ e_HETPROGRAM1_UN = .; } > 0xFF440000
	
	
	
	/*----------------------------------------------------------------------------*/
	/*                              System Registers                              */
	/*----------------------------------------------------------------------------*/
	
	.MMC     	: 	{ _e_SARMMC_ST = .; } > MMC
	.DEC     	:	{ _e_SARDEC_ST = .; } > DEC
	.SYS     	:	{ _e_SARSYS_ST = .; } > SYS
	
	
	
	/*----------------------------------------------------------------------------*/
	/*                            Checksum Definitions                            */
	/*----------------------------------------------------------------------------*/
	
	.APPCHECKSUM :	{
						CCT_Range_10_Address = .;
						CCT_Range_10_Start = 0xC000;
						CCT_Range_10_Length = 0x93FF0;
						CCT_Range_10_BitAddrGran = 8;
						CCT_Range_10_Category = 200;
						CCT_Range_10_Algorithm = 12;
					} > APP_CRC
	
	.APPBOOTCRC :	{
						CCT_Range_20_Address = . + 6;
						CCT_Range_20_Start = 0xC000;
						CCT_Range_20_Length = 0x93FFE;
						CCT_Range_20_BitAddrGran = 8;
						CCT_Range_20_Category = 200;
						CCT_Range_20_Algorithm = 10;
					} > APP_BOOTCRC
	
	.CALCHECKSUM :	{
						CCT_Range_11_Address = .;
						CCT_Range_11_Start = 0xA0000;
						CCT_Range_11_Length = 0x1FFE0;
						CCT_Range_11_BitAddrGran = 8;
						CCT_Range_11_Category = 200;
						CCT_Range_11_Algorithm = 12;
					} > CAL_CRC
	
	.CALBOOTCRC :	{
						CCT_Range_21_Address = . + 6;
						CCT_Range_21_Start = 0xA0000;
						CCT_Range_21_Length = 0x1FFEE;
						CCT_Range_21_BitAddrGran = 8;
						CCT_Range_21_Category = 200;
						CCT_Range_21_Algorithm = 10;
					} > CAL_BOOTCRC
	
	.BOOTCHECKSUM :	{
						BootCRC_Address = .;
						BootCRC_Start = 0;
					} > BOOT_CRC
	
	
}

