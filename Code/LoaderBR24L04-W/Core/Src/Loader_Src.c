
#include "Dev_Inf.h"
#include "Loader_Src.h"
#include "e2.h"

//int Init(void)
//{
//	SystemInit();
//
//	SCB->VTOR = 0x20000000 | 0x200;
//
////	HAL_DeInit();
////	HAL_Init();
//
//	/* Configure the system clock */
////	SystemClock_Config();
//
//	/* Initialize all configured peripherals */
////	MX_GPIO_Init();
////	MX_I2C2_Init();
//
//	return 1;
//}
//
//int Write(uint32_t Address, uint32_t Size, uint8_t *Buffer)
//{
//	if(E2_Write(Buffer, Address - StorageInfo.DeviceStartAddress, Size) == 0)
//		return 0;
//
//	return 1;
//}
//
//int Read(uint32_t Address, uint32_t Size, uint8_t *Buffer)
//{
//	if(E2_Read(Buffer, Address - StorageInfo.DeviceStartAddress, Size) == 0)
//		return 0;
//
//	return 1;
//}
//
//int SectorErase(uint32_t EraseStartAddress ,uint32_t EraseEndAddress)
//{
//	return 1;
//}
//
//int MassErase(void)
//{
//	return 1;
//}
//
//uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)
//{
//	return 0;
//}
//
//uint64_t Verify(uint32_t MemoryAddr, uint32_t BufferAddr, uint32_t Size, uint32_t Missalignement)
//{
//	return 0;
//}
