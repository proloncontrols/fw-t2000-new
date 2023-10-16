
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
//         File : Loader_Src.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//------------------------------------------------------------------------------
//  Description : STM32CubeProgrammer external loader driver device header file
//==============================================================================
#ifndef LOADER_SRC_H
#define LOADER_SRC_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "stm32h7xx_hal.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define TIMEOUT 5000U


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
int      Init        (void);
int      Write       (uint32_t Address, uint32_t Size, uint8_t *Buffer);
int      Read        (uint32_t Address, uint32_t Size, uint8_t *Buffer);
int      SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress);
int      MassErase   (void);
uint32_t CheckSum    (uint32_t StartAddress, uint32_t Size, uint32_t InitVal);
uint64_t Verify      (uint32_t MemoryAddr, uint32_t BufferAddr, uint32_t Size, uint32_t Missalignement);


#endif   //LOADER_SRC_H
