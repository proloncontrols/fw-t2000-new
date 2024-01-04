
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : flash_stm32h735.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : CPU FLASH memory implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "flash_stm32h735.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FLASH_STM32H735_PAGE_SIZE   32   //32 bytes page size


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
//Forced to be 32bit aligned in RAM (needed to write to flash)
static uint8_t __attribute__((section(".flash_page"))) FLASH_STM32H735_PageBuffer[FLASH_STM32H735_PAGE_SIZE];


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_STM32H735_Init(void)
{
	return HAL_OK;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_STM32H735_Reset(void)
{
	return HAL_OK;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_STM32H735_Erase(uint32_t SectorStart, uint32_t SectorCount)
{
	uint32_t SectorError;
	HAL_StatusTypeDef Result;
	FLASH_EraseInitTypeDef Init;

	if((SectorStart + SectorCount) > FLASH_SECTOR_TOTAL)
		return HAL_ERROR;

	Init.TypeErase    = FLASH_TYPEERASE_SECTORS;
	Init.Sector       = SectorStart;
	Init.NbSectors    = SectorCount;
	Init.Banks        = FLASH_BANK_1;
	Init.VoltageRange = FLASH_VOLTAGE_RANGE_3;

	HAL_FLASH_Unlock();
	Result = HAL_FLASHEx_Erase(&Init, &SectorError);
	HAL_FLASH_Lock();

	if(SectorError != 0xFFFFFFFFU)
		Result = HAL_ERROR;

	return Result;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_STM32H735_Write(uint8_t* Data, uint32_t Address, uint16_t Length)
{
	uint16_t DataOffset;
	HAL_StatusTypeDef Result;

	DataOffset = 0;
	do
	{
		//Copy chunk from input data into forced aligned temporary page buffer
		memcpy(FLASH_STM32H735_PageBuffer, &Data[DataOffset], FLASH_STM32H735_PAGE_SIZE);
		//Perform actual flash writing
		HAL_FLASH_Unlock();
	    Result = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, (uint32_t)(Address + DataOffset), (uint32_t)FLASH_STM32H735_PageBuffer);
		HAL_FLASH_Lock();
		//Read back flash memory and compare to buffer data in order to validate its integrity
		for(uint32_t i = 0; i < FLASH_STM32H735_PAGE_SIZE; i++)
		{
			if(*((uint8_t*)(Address + DataOffset + i)) != FLASH_STM32H735_PageBuffer[i])
				Result = HAL_ERROR;
		}
		//Point to next chunk to process
		DataOffset += FLASH_STM32H735_PAGE_SIZE;
	}
	while((DataOffset < Length) && (Result == HAL_OK));

	return Result;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_STM32H735_Read(uint8_t* Data, uint32_t Address, uint16_t Length)
{
	for(uint16_t i = 0; i < Length; i++)
		Data[i] = *((uint8_t*)(Address + i));

	return HAL_OK;
}
