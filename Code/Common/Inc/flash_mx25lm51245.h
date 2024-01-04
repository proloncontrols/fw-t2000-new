
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
//         File : flash_mx25lm51245.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : NOR external FLASH memory header file
//=============================================================================
#ifndef FLASH_MX25LM51245_H
#define FLASH_MX25LM51245_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern HAL_StatusTypeDef FLASH_MX25LM51245_Init  (void);
extern HAL_StatusTypeDef FLASH_MX25LM51245_Reset (void);
extern HAL_StatusTypeDef FLASH_MX25LM51245_Erase (uint32_t SectorStart, uint32_t SectorCount);
extern HAL_StatusTypeDef FLASH_MX25LM51245_Write (uint8_t* Data, uint32_t Address, uint16_t Length);
extern HAL_StatusTypeDef FLASH_MX25LM51245_Read  (uint8_t* Data, uint32_t Address, uint16_t Length);


#endif   //FLASH_MX25LM51245_H
