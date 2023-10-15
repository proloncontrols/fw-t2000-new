
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//-----------------------------------------------------------------------------
//         File : flash.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : FLASH memory implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "flash.h"
#include "flash_stm32h735.h"
#include "flash_mx25lm51245.h"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	HAL_StatusTypeDef (*Init)  (void);
	HAL_StatusTypeDef (*Reset) (void);
	HAL_StatusTypeDef (*Erase) (uint32_t SectorStart, uint32_t SectorCount);
	HAL_StatusTypeDef (*Write) (uint8_t* Data, uint32_t Address, uint16_t Length);
	HAL_StatusTypeDef (*Read)  (uint8_t* Data, uint32_t Address, uint16_t Length);
} FLASH_Handler_t;


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
static const FLASH_Handler_t FLASH_Handler[] =
{
	{ FLASH_STM32H735_Init,   FLASH_STM32H735_Reset,   FLASH_STM32H735_Erase,   FLASH_STM32H735_Write,   FLASH_STM32H735_Read },
	{ FLASH_MX25LM51245_Init, FLASH_MX25LM51245_Reset, FLASH_MX25LM51245_Erase, FLASH_MX25LM51245_Write, FLASH_MX25LM51245_Read }
};


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_Init(FLASH_Device_t Device)
{
	return FLASH_Handler[Device].Init();
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_Reset(FLASH_Device_t Device)
{
	return FLASH_Handler[Device].Reset();
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_Erase(FLASH_Device_t Device, uint32_t SectorStart, uint32_t SectorCount)
{
	return FLASH_Handler[Device].Erase(SectorStart, SectorCount);
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_Write(FLASH_Device_t Device, uint8_t* Data, uint32_t Address, uint16_t Length)
{
	if((Address % Length) != 0)
		return HAL_ERROR;

	return FLASH_Handler[Device].Write(Data, Address, Length);
}

//-----------------------------------------------------------------------------
HAL_StatusTypeDef FLASH_Read(FLASH_Device_t Device, uint8_t* Data, uint32_t Address, uint16_t Length)
{
	return FLASH_Handler[Device].Read(Data, Address, Length);
}
