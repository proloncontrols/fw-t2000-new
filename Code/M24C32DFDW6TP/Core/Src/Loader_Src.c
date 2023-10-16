
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
//  Description : STM32CubeProgrammer external loader driver device implementation file
//==============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "Dev_Inf.h"
#include "Loader_Src.h"
#include "e2.h"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
int Init(void)
{
	__disable_irq();
	MX_I2C2_Init_External();
	__enable_irq();

	return 1;
}

//-----------------------------------------------------------------------------
int Write(uint32_t Address, uint32_t Size, uint8_t *Buffer)
{
	if(E2_Write(Buffer, Address - StorageInfo.DeviceStartAddress, Size) == 0)
		return 0;

	return 1;
}

//-----------------------------------------------------------------------------
int Read(uint32_t Address, uint32_t Size, uint8_t *Buffer)
{
	if(E2_Read(Buffer, (uint16_t)(Address - StorageInfo.DeviceStartAddress), (uint16_t)Size) == 0)
		return 0;

	return 1;
}

//-----------------------------------------------------------------------------
int SectorErase(uint32_t EraseStartAddress ,uint32_t EraseEndAddress)
{
	return 1;
}

//-----------------------------------------------------------------------------
int MassErase(void)
{
	return 1;
}

//-----------------------------------------------------------------------------
uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)
{
	return 0;
}

//-----------------------------------------------------------------------------
uint64_t Verify(uint32_t MemoryAddr, uint32_t BufferAddr, uint32_t Size, uint32_t Missalignement)
{
	return 0;
}
