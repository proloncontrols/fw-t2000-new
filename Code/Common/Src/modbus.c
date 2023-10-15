
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
#define MB_GLOBAL
#include "basic.h"
#include "modbus.h"
#include "com.h"
#include "e2.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define MB_ERROR_FLAG              0x80

//Read Coils
#define MB_RD_COILS_ADDR_MIN       0x0001   //TBD
#define MB_RD_COILS_ADDR_MAX       0xFFFE   //
#define MB_RD_COILS_MIN            1
#define MB_RD_COILS_MAX            2000

//Read Input Registers
#define MB_RD_IN_REGS_ADDR_MIN     0x0001   //TBD
#define MB_RD_IN_REGS_ADDR_MAX     0xFFFE   //
#define MB_RD_IN_REGS_MIN          1
#define MB_RD_IN_REGS_MAX          125

//Read Holding Registers
#define MB_RD_HLD_REG_ADDR_MIN     0x0001   //TBD
#define MB_RD_HLD_REG_ADDR_MAX     0xFFFE   //
#define MB_RD_HLD_REG_MIN          1
#define MB_RD_HLD_REG_MAX          125

//Read Discrete Inputs
#define MB_RD_DISC_IN_ADDR_MIN     0x0001   //TBD
#define MB_RD_DISC_IN_ADDR_MAX     0xFFFE   //
#define MB_RD_DISC_IN_MIN          1
#define MB_RD_DISC_IN_MAX          2000

//Write Single Coil
#define MB_WR_SGL_COIL_ADDR_MIN    0x0001   //TBD
#define MB_WR_SGL_COIL_ADDR_MAX    0xFFFE   //
#define MB_WR_SGL_COIL_ON          0xFF00
#define MB_WR_SGL_COIL_OFF         0x0000

//Write Multiple Coils
#define MB_WR_MPL_COILS_ADDR_MIN   0x0001   //TBD
#define MB_WR_MPL_COILS_ADDR_MAX   0xFFFE   //
#define MB_WR_MPL_COILS_MIN        1
#define MB_WR_MPL_COILS_MAX        1968

//Write Single Register
#define MB_WR_SGL_REG_ADDR_MIN     0x0001   //TBD
#define MB_WR_SGL_REG_ADDR_MAX     0xFFFE   //

//Write Multiple Registers
#define MB_WR_MPL_REGS_ADDR_MIN    0x0001   //TBD
#define MB_WR_MPL_REGS_ADDR_MAX    0xFFFE   //
#define MB_WR_MPL_REGS_MIN         1
#define MB_WR_MPL_REGS_MAX         120


//=============================================================================
//  M A C R O S
//-----------------------------------------------------------------------------
//#define MB_SWAP_ENDIANESS(x)   ((uint16_t)(((x >> 8) & 0x00FF) + ((x << 8) & 0xFF00)))   //Swap the byte order of a uint16_t type (ModBus is big endian as opposed to STM32 devices which are little endian)


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	MB_Packet_t* PktRx;
	MB_Packet_t* PktTx;
} MB_t;


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static MB_t MB;


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void MB_ReadCoils              (COM_Connexion_t* Conx);
static void MB_ReadInputRegisters     (COM_Connexion_t* Conx);
static void MB_ReadHoldingRegisters   (COM_Connexion_t* Conx);
static void MB_ReadDiscreteInputs     (COM_Connexion_t* Conx);
static void MB_WriteSingleCoil        (COM_Connexion_t* Conx);
static void MB_WriteMultipleCoils     (COM_Connexion_t* Conx);
static void MB_WriteSingleRegister    (COM_Connexion_t* Conx);
static void MB_WriteMultipleRegisters (COM_Connexion_t* Conx);

static void MB_SendError              (COM_Connexion_t* Conx, MB_Error_t Err);
static void MB_Tx                     (COM_Connexion_t* Conx, uint16_t Length);


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
		case MbFctRdCoils:      { MB_ReadCoils              (Conx);                         break; }
		case MbFctRdInRegs:     { MB_ReadInputRegisters     (Conx);                         break; }
		case MbFctRdHldRegs:    { MB_ReadHoldingRegisters   (Conx);                         break; }
		case MbFctRdDscIn:      { MB_ReadDiscreteInputs     (Conx);                         break; }
		case MbFctWrSglCoil:    { MB_WriteSingleCoil        (Conx);                         break; }
		case MbFctWrMplCoils:   { MB_WriteMultipleCoils     (Conx);                         break; }
		case MbFctWrSglReg:     { MB_WriteSingleRegister    (Conx);                         break; }
		case MbFctWrMplRegs:    { MB_WriteMultipleRegisters (Conx);                         break; }
		default:                { MB_SendError              (Conx, MbErrIllegalFunction);   break; }
	}
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static void MB_ReadCoils(COM_Connexion_t* Conx)
{
	MB_FctRdCoilsReq_t* Req = (MB_FctRdCoilsReq_t*)&MB.PktRx->Function;
//	MB_FctRdCoilsAns_t* Ans = (MB_FctRdCoilsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_RD_COILS_ADDR_MIN) || (Req->Address > MB_RD_COILS_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_RD_COILS_MIN) || (Req->Quantity > MB_RD_COILS_MAX))
			MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_ReadInputRegisters(COM_Connexion_t* Conx)
{
	MB_FctRdInRegsReq_t* Req = (MB_FctRdInRegsReq_t*)&MB.PktRx->Function;
//	MB_FctRdInRegsAns_t* Ans = (MB_FctRdInRegsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_RD_IN_REGS_ADDR_MIN) || (Req->Address > MB_RD_IN_REGS_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_RD_IN_REGS_MIN) || (Req->Quantity > MB_RD_IN_REGS_MAX))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_ReadHoldingRegisters(COM_Connexion_t* Conx)
{
	MB_FctRdHldRegsReq_t* Req = (MB_FctRdHldRegsReq_t*)&MB.PktRx->Function;
//	MB_FctRdHldRegsAns_t* Ans = (MB_FctRdHldRegsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_RD_HLD_REG_ADDR_MIN) || (Req->Address > MB_RD_HLD_REG_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_RD_HLD_REG_MIN) || (Req->Quantity > MB_RD_HLD_REG_MAX))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
//		Ans->ByteCount = Req->Quantity * sizeof(uint16_t);
//		uint16_t* AnsData = (uint16_t*)(&Ans + sizeof(MB_FctReadAns_t));
//		uint16_t ReadCount;
//		for(int i = 0; i < Req->Quantity; i++)
//		{
//			ReadCount = E2_Read(&AnsData[i], (Req->Address + (i * sizeof(uint16_t))), sizeof(uint16_t));
//			if(ReadCount == 0)
//			{
//				MB_SendError(Conx, MbErrSlaveDeviceFailure);
//				return;
//			}
//			AnsData[i] = MB_SWAP_ENDIANESS(AnsData[i]);
//		}
//		MB_Tx(Conx, sizeof(MB_FctReadAns_t) + Ans->ByteCount);
	}
}

//-----------------------------------------------------------------------------
static void MB_ReadDiscreteInputs(COM_Connexion_t* Conx)
{
	MB_FctRdDscInsReq_t* Req = (MB_FctRdDscInsReq_t*)&MB.PktRx->Function;
//	MB_FctRdDscInsAns_t* Ans = (MB_FctRdDscInsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_RD_DISC_IN_ADDR_MIN) || (Req->Address > MB_RD_DISC_IN_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_RD_DISC_IN_MIN) || (Req->Quantity > MB_RD_DISC_IN_MAX))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
//		uint8_t Quotient = Req->Quantity / 8;
//		if(Quotient <= 1)
//			Ans->ByteCount = 1;
//		else
//			Ans->ByteCount = Quotient;
//
//		if((Req->Quantity % 8) > 0)
//			Ans->ByteCount++;
	}
}

//-----------------------------------------------------------------------------
static void MB_WriteSingleCoil(COM_Connexion_t* Conx)
{
	MB_FctWrSglCoilReq_t* Req = (MB_FctWrSglCoilReq_t*)&MB.PktRx->Function;
//	MB_FctWrSglCoilAns_t* Ans = (MB_FctWrSglCoilAns_t*)&MB.PktTx->Function;

	Req->Address = SWAP_ENDIANESS(Req->Address);
	Req->Value   = SWAP_ENDIANESS(Req->Value);

	if((Req->Address < MB_WR_SGL_COIL_ADDR_MIN) || (Req->Address > MB_WR_SGL_COIL_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Value != MB_WR_SGL_COIL_ON) && (Req->Value != MB_WR_SGL_COIL_OFF))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_WriteMultipleCoils(COM_Connexion_t* Conx)
{
	MB_FctWrMplCoilsReq_t* Req = (MB_FctWrMplCoilsReq_t*)&MB.PktRx->Function;
//	MB_FctWrMplCoilsAns_t* Ans = (MB_FctWrMplCoilsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_WR_MPL_COILS_ADDR_MIN) || (Req->Address > MB_WR_MPL_COILS_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_WR_MPL_COILS_MIN) && (Req->Quantity > MB_WR_MPL_COILS_MAX))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_WriteSingleRegister(COM_Connexion_t* Conx)
{
	MB_FctWrSglRegReq_t* Req = (MB_FctWrSglRegReq_t*)&MB.PktRx->Function;
//	MB_FctWrSglRegAns_t* Ans = (MB_FctWrSglRegAns_t*)&MB.PktTx->Function;

	Req->Address = SWAP_ENDIANESS(Req->Address);
	Req->Value   = SWAP_ENDIANESS(Req->Value);

	if((Req->Address < MB_WR_SGL_REG_ADDR_MIN) || (Req->Address > MB_WR_SGL_REG_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_WriteMultipleRegisters(COM_Connexion_t* Conx)
{
	MB_FctWrMplRegsReq_t* Req = (MB_FctWrMplRegsReq_t*)&MB.PktRx->Function;
//	MB_FctWrMplRegsAns_t* Ans = (MB_FctWrMplRegsAns_t*)&MB.PktTx->Function;

	Req->Address  = SWAP_ENDIANESS(Req->Address);
	Req->Quantity = SWAP_ENDIANESS(Req->Quantity);

	if((Req->Address < MB_WR_MPL_REGS_ADDR_MIN) || (Req->Address > MB_WR_MPL_REGS_ADDR_MAX))
		MB_SendError(Conx, MbErrIllegalDataAddress);

	else if((Req->Quantity < MB_WR_MPL_REGS_MIN) && (Req->Quantity > MB_WR_MPL_REGS_MAX))
		MB_SendError(Conx, MbErrIllegalDataValue);

	else
	{
	}
}

//-----------------------------------------------------------------------------
static void MB_SendError(COM_Connexion_t* Conx, MB_Error_t Err)
{
	MB.PktTx->Header.Function |= MB_ERROR_FLAG;
	MB.PktTx->Function.Error.Code = Err;
	MB_Tx(Conx, sizeof(MB_FctError_t));
}

//-----------------------------------------------------------------------------
static void MB_Tx(COM_Connexion_t* Conx, uint16_t Length)
{
	Conx->PacketOut.Length = sizeof(MB_PktHeader_t) + Length;
	COM_Checksum_t Checksum = SWAP_ENDIANESS(COM_CRC16(Conx->PacketOut.Payload, Conx->PacketOut.Length));
	COM_Checksum_t* ChecksumPtr = (COM_Checksum_t*)(Conx->PacketOut.Payload + Conx->PacketOut.Length);
	*ChecksumPtr = Checksum;
	Conx->PacketOut.Length += sizeof(COM_Checksum_t);
	COM_Tx(Conx);
}























