
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
//         File : e2.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Serial EEPROM implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "e2.h"
#include "basic.h"


//=============================================================================
//  M A C R O S
//-----------------------------------------------------------------------------
#define E2_WRITE_ENABLE()    (HAL_GPIO_WritePin(E2_WP_GPIO_Port, E2_WP_Pin, GPIO_PIN_RESET))
#define E2_WRITE_DISABLE()   (HAL_GPIO_WritePin(E2_WP_GPIO_Port, E2_WP_Pin, GPIO_PIN_SET))

#define E2_ADDRESS_MSB(x)    (E2_I2C_ADDRESS | ((x >> 7) & E2_I2C_ADDRESS_MASK))
#define E2_ADDRESS_LSB(x)    (x & 0xFFU)


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//  Read from device.
//  Parameters:
//    pData   -> Pointer to buffer where to store data read
//    Address -> Device address where to start reading data
//    Count   -> Number of bytes to read
//  Return:
//    Returns 0 on error (invalid arguments, access out of bounds or actual read error)
//    or returns the actual number of bytes read on success
//  Note:
//    Blocking but times out after E2_TIMEOUT.
//-----------------------------------------------------------------------------
uint16_t E2_Read(void* pData, uint16_t Address, uint16_t Count)
{
	//Validate arguments
	if((pData == NULL) || (Address >= E2_SIZE) || (Count == 0))
		return 0;

	//Validate access range
	if((Address + Count) > E2_SIZE)
		return 0;

	//Make sure writing to device is disabled in case it was left enabled somehow
	E2_WRITE_DISABLE();

	//Read data
	if(HAL_I2C_Mem_Read(&E2_I2C, E2_ADDRESS_MSB(Address), E2_ADDRESS_LSB(Address), 1, pData, Count, E2_TIMEOUT) != HAL_OK)
		return 0;

	return Count;
}

//-----------------------------------------------------------------------------
//  Write to device.
//  Parameters:
//    pData   -> Pointer to buffer where to retrieve data to be written
//    Address -> Device address where to start writing data
//    Count   -> Number of bytes to write
//  Return:
//    Returns 0 on error (invalid arguments, access out of bounds or actual write error)
//    or returns the actual number of bytes written on success
//  Note:
//    Blocking but times out after E2_TIMEOUT.
//    Writing operations smaller than page size are managed without loss of data.
//    Writing operations across device pages are managed.
//-----------------------------------------------------------------------------
uint16_t E2_Write(void* pData, uint16_t Address, uint16_t Count)
{
	uint16_t Page;
	uint16_t Offset;
	uint16_t Index;
	uint8_t  TmpBuffer[E2_PAGE_SIZE];
	bool_t   Error;
	uint8_t* Data;

	//Validate arguments
	if((pData == NULL) || (Address >= E2_SIZE) || (Count == 0))
		return 0;

	//Validate access range
	if((Address + Count) > E2_SIZE)
		return 0;

	Data = (uint8_t*)pData;

	//Write data
	Index = 0;   //Pointer to data in input buffer
	Error = FALSE;

	//Enable writing to device
	E2_WRITE_ENABLE();

	do
	{
		//Get base page address where to write data
		Page   = (Address / E2_PAGE_SIZE) * E2_PAGE_SIZE;
		Offset = Address % E2_PAGE_SIZE;

		//Read contents of that page in temporary buffer
		if(HAL_I2C_Mem_Read(&E2_I2C, E2_ADDRESS_MSB(Page), E2_ADDRESS_LSB(Page), 1, TmpBuffer, E2_PAGE_SIZE, E2_TIMEOUT) != HAL_OK)
			Error = TRUE;

		//Write data from input buffer to current page range
		do
		{
			TmpBuffer[Offset] = Data[Index];
			Offset++;
			Index++;
			Address++;
			Count--;
		}
		while((Offset < E2_PAGE_SIZE) && (Count > 0));

		//Write page back to E2
		if(HAL_I2C_Mem_Write(&E2_I2C, E2_ADDRESS_MSB(Page), E2_ADDRESS_LSB(Page), 1, TmpBuffer, E2_PAGE_SIZE, E2_TIMEOUT) != HAL_OK)
			Error = TRUE;

		//Wait for write cycle to complete
		if(HAL_I2C_IsDeviceReady(&E2_I2C, E2_I2C_ADDRESS, E2_BUSY_CHECK, E2_TIMEOUT) != HAL_OK)
			Error = TRUE;
	}
	while((Count > 0) && (!Error));

	//Disable writing to device
	E2_WRITE_DISABLE();

	if(Error)
		return 0;

	return Index;
}


//uint16_t E2_Write(void* pData, uint16_t Address, uint16_t Count)
//{
//	uint16_t Page;
//	uint16_t Offset;
//	uint16_t Index;
//	uint8_t  TmpBuffer[E2_PAGE_SIZE];
//	bool_t   Error;
//
//	//Validate arguments
//	if((pData == NULL) || (Address >= E2_SIZE) || (Count == 0))
//		return 0;
//
//	//Validate access range
//	if((Address + Count) > E2_SIZE)
//		return 0;
//
//	//Write data
//	Index = 0;   //Pointer to data in input buffer
//	Error = FALSE;
//
//	//Enable writing to device
//	E2_WRITE_ENABLE();
//
//	do
//	{
//		//Get base page address where to write data
//		Page = Address & ~(E2_PAGE_SIZE - 1);
//
//		//Read contents of that page in temporary buffer
//		if(HAL_I2C_Mem_Read(&E2_I2C, E2_ADDRESS_MSB(Page), E2_ADDRESS_LSB(Page), 1, TmpBuffer, E2_PAGE_SIZE, E2_TIMEOUT) != HAL_OK)
//			Error = TRUE;
//
//		//Write data from input buffer to current page range
//		Offset = Address - Page;
//		do
//		{
//			TmpBuffer[Offset++] = *(uint8_t*)(pData + Index++);
//			Address++;
//			Count--;
//		}
//		while((Offset < E2_PAGE_SIZE) && (Count > 0));
//
//		//Write page back to E2
//		if(HAL_I2C_Mem_Write(&E2_I2C, E2_ADDRESS_MSB(Page), E2_ADDRESS_LSB(Page), 1, TmpBuffer, E2_PAGE_SIZE, E2_TIMEOUT) != HAL_OK)
//			Error = TRUE;
//
//		//Wait for write cycle to complete
//		if(HAL_I2C_IsDeviceReady(&E2_I2C, E2_I2C_ADDRESS, E2_BUSY_CHECK, E2_TIMEOUT) != HAL_OK)
//			Error = TRUE;
//	}
//	while((Count > 0) && (!Error));
//
//	//Disable writing to device
//	E2_WRITE_DISABLE();
//
//	if(Error)
//		return 0;
//
//	return Index;
//}









