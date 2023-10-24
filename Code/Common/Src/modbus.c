
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
//         File : modbus.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : ModBus protocol source file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "basic.h"
#include "modbus.h"
#include "com.h"
#include "e2.h"
#include "cfg.h"
#include "framework.h"
#include "app.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define MB_ERROR_FLAG    0x80
#define MB_SECTION_CFG   0
#define MB_SECTION_INP   1


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	MB_Packet_t* PktRx;
	MB_Packet_t* PktTx;
} MB_t;

typedef struct {
	const MB_Register_t* Registers;
	      uint16_t       AddMin;
	      uint16_t       AddMax;
	      uint16_t       QtyMin;
	      uint16_t       QtyMax;
} MB_Section_t;


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static MB_t MB;


//=============================================================================
//  A V A I L A B L E   R E G I S T E R   S E C T I O N S
//-----------------------------------------------------------------------------
static const MB_Section_t MB_Sections[] =
{
	{ CFG_Registers, CFG_MB_ADD_MIN, CFG_MB_ADD_MAX, CFG_MB_QTY_MIN, CFG_MB_QTY_MAX },
	{ APP_Registers, APP_MB_ADD_MIN, APP_MB_ADD_MAX, APP_MB_QTY_MIN, APP_MB_QTY_MAX }
};


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void                 MB_Read        (COM_Connexion_t* Conx, MB_Function_t Function);
static void                 MB_Write       (COM_Connexion_t* Conx, MB_Function_t Function);
static void                 MB_WriteRam    (const MB_Register_t* Register, uint16_t* Data);
static void                 MB_Error       (COM_Connexion_t* Conx, MB_Error_t Err);
static void                 MB_Tx          (COM_Connexion_t* Conx, uint16_t Length);
static const MB_Register_t* MB_GetRegister (const MB_Section_t* Section, uint16_t Register);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void MB_Init(void)
{
}

//-----------------------------------------------------------------------------
void MB_Process(COM_Connexion_t* Conx)
{
	MB.PktRx = (MB_Packet_t*)Conx->PacketIn.Payload;
	MB.PktTx = (MB_Packet_t*)Conx->PacketOut.Payload;

	MB.PktTx->Header.Address  = MB.PktRx->Header.Address;
	MB.PktTx->Header.Function = MB.PktRx->Header.Function;

	switch(MB.PktRx->Header.Function)
	{
		case MbFctRdHldRegs:
		case MbFctRdInpRegs:   { MB_Read  (Conx, MB.PktRx->Header.Function);   break; }
		case MbFctWrSglReg:
		case MbFctWrMplRegs:   { MB_Write (Conx, MB.PktRx->Header.Function);   break; }
		default:               { MB_Error (Conx, MbErrIllegalFunction);        break; }
	}
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static void MB_Read(COM_Connexion_t* Conx, MB_Function_t Function)
{
	MB_FctReadReq_t* Req = (MB_FctReadReq_t*)&MB.PktRx->Function;
	MB_FctReadAns_t* Ans = (MB_FctReadAns_t*)&MB.PktTx->Function;

	const MB_Section_t* Section = &MB_Sections[MB_SECTION_CFG];
	if(Function == MbFctRdInpRegs)
		Section = &MB_Sections[MB_SECTION_INP];

	Req->Address  = REVERSE_ORDER_16(Req->Address) + 1;   //Focus addresses are 0 based
	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);

	if((Req->Address < Section->AddMin) || (Req->Address > Section->AddMax))
		MB_Error(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < Section->QtyMin) || (Req->Quantity > Section->QtyMax))
		MB_Error(Conx, MbErrIllegalDataValue);

	else
	{
		const MB_Register_t* Reg;
		uint16_t* Data = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctReadAns_t));

		Ans->ByteCount = Req->Quantity * sizeof(uint16_t);

		for(uint16_t i = 0; i < Req->Quantity; i++)
		{
			Reg = MB_GetRegister(Section, Req->Address++);
			if(Reg)
			{
				switch(Reg->Type)
				{
					case MbReg8:         { Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Reg->Ram)));   break; }
					case MbReg16:        { Data[i] = REVERSE_ORDER_16(*((uint16_t*)Reg->Ram));              break; }
					case MbRegLoc:
					{
						memcpy(Data, Reg->Ram, CFG_MB_LOC_SIZE);
						for(int i = 0; i < CFG_MB_LOC_SIZE/2; i++)
							Data[i] = REVERSE_ORDER_16(Data[i]);
					}
					break;
					case MbRegTemp:      { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Reg->Ram)));   break; }
					case MBRegPercent:   { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Reg->Ram)));    break; }
				}
			}
		}

		MB_Tx(Conx, sizeof(MB_FctReadAns_t) + Ans->ByteCount);
	}
}

//-----------------------------------------------------------------------------
static void MB_Write(COM_Connexion_t* Conx, MB_Function_t Function)
{
	MB_FctWriteReq_t* Req = (MB_FctWriteReq_t*)&MB.PktRx->Function;
	MB_FctWriteAns_t* Ans = (MB_FctWriteAns_t*)&MB.PktTx->Function;

	const MB_Register_t* Reg;
	const MB_Section_t* Section = &MB_Sections[MB_SECTION_CFG];

	Req->Address = REVERSE_ORDER_16(Req->Address) + 1;   //Focus addresses are 0 based

	if((Req->Address < Section->AddMin) || (Req->Address > Section->AddMax))
		MB_Error(Conx, MbErrIllegalDataAddress);

	if(Function == MbFctWrSglReg)
	{
		Reg = MB_GetRegister(Section, Req->Address);
		if(Reg)
		{
			Ans->Address = Req->Address;
			Ans->Param = REVERSE_ORDER_16(Req->Param);   //Data to write
			MB_WriteRam(Reg, &Ans->Param);
		}
	}

	else   //Multiple register write
	{
		if((Req->Param < Section->QtyMin) || (Req->Param > Section->QtyMax))
			MB_Error(Conx, MbErrIllegalDataValue);

		else
		{
			uint16_t* Data = (uint16_t*)((uint32_t)Req + sizeof(MB_FctWriteReq_t));
			Req->Param = REVERSE_ORDER_16(Req->Param);   //Quantity of registers to write
			Ans->Param = Req->Param;
			for(uint16_t i = 0; i < Req->Param; i++)
			{
				Reg = MB_GetRegister(Section, Req->Address++);
				if(Reg)
					MB_WriteRam(Reg, Data);
			}
		}
	}

	MB_Tx(Conx, sizeof(MB_FctWriteAns_t));
}


//-----------------------------------------------------------------------------
static void MB_WriteRam(const MB_Register_t* Register, uint16_t* Data)
{
	switch(Register->Type)
	{
		case MbReg8:         { *((uint8_t*)Register->Ram) = (uint8_t)(REVERSE_ORDER_16(*Data));     break; }
		case MbReg16:        { *((uint16_t*)Register->Ram) = (uint16_t)(REVERSE_ORDER_16(*Data));   break; }
		case MbRegLoc:
		{
			for(int i = 0; i < CFG_MB_LOC_SIZE/2; i++)
				Data[i] = REVERSE_ORDER_16(Data[i]);
			memcpy(Register->Ram, Data, CFG_MB_LOC_SIZE);
		}
		break;
		case MbRegTemp:      { *((int16_t*)Register->Ram) = (int16_t)(REVERSE_ORDER_16(*Data));     break; }
		case MBRegPercent:   { *((int8_t*)Register->Ram) = (int8_t)(REVERSE_ORDER_16(*Data));       break; }
	}
}


//-----------------------------------------------------------------------------
static const MB_Register_t* MB_GetRegister(const MB_Section_t* Section, uint16_t Register)
{
	uint16_t Size = *(&Section->Registers + 1) - Section->Registers;   //Get the number of registers in section

	for(uint16_t i = 0; i < Size; i++)
	{
		if(Section->Registers[i].Number == Register)
			return &Section->Registers[i];
	}
	return NULL;
}

//-----------------------------------------------------------------------------
static void MB_Error(COM_Connexion_t* Conx, MB_Error_t Err)
{
	MB.PktTx->Header.Function |= MB_ERROR_FLAG;
	MB.PktTx->Function.Error.Code = Err;
	MB_Tx(Conx, sizeof(MB_FctError_t));
}

//-----------------------------------------------------------------------------
static void MB_Tx(COM_Connexion_t* Conx, uint16_t Length)
{
	Conx->PacketOut.Length = sizeof(MB_PktHeader_t) + Length;
	COM_Checksum_t Checksum = REVERSE_ORDER_16(COM_CRC16(Conx->PacketOut.Payload, Conx->PacketOut.Length));
	COM_Checksum_t* ChecksumPtr = (COM_Checksum_t*)(Conx->PacketOut.Payload + Conx->PacketOut.Length);
	*ChecksumPtr = Checksum;
	Conx->PacketOut.Length += sizeof(COM_Checksum_t);
	COM_Tx(Conx);
}
