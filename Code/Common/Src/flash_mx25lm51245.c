
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
//         File : flash_mx25lm51245.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : NOR external FLASH memory implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "framework.h"
#include "flash_mx25lm51245.h"
#include "stm32h735g_discovery_ospi.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FLASH_MX25LM51245_START_OFFSET    FMK_ADDR_EXT_FLASH_START   //Device address offset
#define FLASH_MX25LM51245_PAGE_SIZE       256     //256 bytes page size
#define FLASH_MX25LM51245_SECTOR_SIZE     65536   //64KB sector size
#define FLASH_MX25LM51245_TIME            10      //10 milliseconds timeout granularity
#define FLASH_MX25LM51245_ERASE_TIMEOUT   1000    //1 second


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_MX25LM51245_Init()
{
	BSP_OSPI_NOR_DisableMemoryMappedMode(0);
	return HAL_OK;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_MX25LM51245_Reset()
{
	BSP_OSPI_NOR_EnableMemoryMappedMode(0);
	return HAL_OK;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_MX25LM51245_Erase(uint32_t SectorStart, uint32_t SectorCount)
{
	int32_t Result = HAL_ERROR;
	uint32_t Timeout;

	for(uint32_t i = 0; i < SectorCount; i++)
	{
	    if(BSP_OSPI_NOR_Erase_Block(0, ((SectorStart + i) * FLASH_MX25LM51245_SECTOR_SIZE), MX25LM51245G_ERASE_64K) != BSP_ERROR_NONE)
	    	Result = HAL_ERROR;
	    else
	    {
		    Timeout = 0;
		    do
		    {
		    	Result = BSP_OSPI_NOR_GetStatus(0);
		    	if(Result != BSP_ERROR_NONE)
		    	{
		    		osDelay(FLASH_MX25LM51245_TIME);
		    		Timeout += FLASH_MX25LM51245_TIME;
		    		if(Timeout >= FLASH_MX25LM51245_ERASE_TIMEOUT)
		    	    	Result = HAL_ERROR;
		    	}
		    }
		    while(Result != BSP_ERROR_NONE);
	    }
	}

	return Result;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_MX25LM51245_Write(uint8_t* Data, uint32_t Address, uint16_t Length)
{
	int32_t Result = HAL_OK;

	if(BSP_OSPI_NOR_Write(0, Data, Address - (uint32_t)&FLASH_MX25LM51245_START_OFFSET, Length) != BSP_ERROR_NONE)
    	Result = HAL_ERROR;

	return Result;
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_MX25LM51245_Read(uint8_t* Data, uint32_t Address, uint16_t Length)
{
	return HAL_OK;
}
