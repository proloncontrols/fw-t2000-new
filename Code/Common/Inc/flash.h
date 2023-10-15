
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
//         File : flash.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : FLASH memory header file
//=============================================================================
#ifndef FLASH_H
#define FLASH_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	FlashDeviceCpu,
	FlashDeviceExt
} FLASH_Device_t;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern HAL_StatusTypeDef FLASH_Init  (FLASH_Device_t Device);
extern HAL_StatusTypeDef FLASH_Reset (FLASH_Device_t Device);
extern HAL_StatusTypeDef FLASH_Erase (FLASH_Device_t Device, uint32_t SectorStart, uint32_t SectorCount);
extern HAL_StatusTypeDef FLASH_Write (FLASH_Device_t Device, uint8_t* Data, uint32_t Address, uint16_t Length);
extern HAL_StatusTypeDef FLASH_Read  (FLASH_Device_t Device, uint8_t* Data, uint32_t Address, uint16_t Length);


#endif   //FLASH_H
