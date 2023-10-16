
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

extern struct StorageInfo StrInfo;
