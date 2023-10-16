
//==============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//------------------------------------------------------------------------------
//         File : Dev_Inf.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//------------------------------------------------------------------------------
//  Description : STM32CubeProgrammer external loader driver device information header file
//==============================================================================
#ifndef DEV_INF_H
#define DEV_INF_H


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define MCU_FLASH 	 1
#define NAND_FLASH   2
#define NOR_FLASH    3
#define SRAM         4
#define PSRAM        5
#define PC_CARD      6
#define SPI_FLASH    7
#define I2C_FLASH    8
#define SDRAM        9
#define I2C_EEPROM   10

#define SECTOR_NUM   10   //Maximum number of sector types


//=============================================================================
//  S T R U C T U R E S
//-----------------------------------------------------------------------------
struct DeviceSectors  
{
	unsigned long SectorNum;    //Number of sectors
	unsigned long SectorSize;   //Sector size in bytes
};

struct StorageInfo  
{
	char                 DeviceName[100];       //Device name and description
	unsigned short       DeviceType;            //Device type: ONCHIP, EXT8BIT, EXT16BIT, ...
	unsigned long        DeviceStartAddress;    //Default device start address
	unsigned long        DeviceSize;            //Total size of device
	unsigned long        PageSize;              //Programming page size
	unsigned char        EraseValue;            //Content of erased memory
	struct DeviceSectors sectors[SECTOR_NUM];
};


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
extern struct StorageInfo StorageInfo;


#endif   //DEV_INF_H
