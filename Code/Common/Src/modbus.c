
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
#define MB_ERROR_FLAG              0x80

////Read Coils
//#define MB_RD_COILS_ADDR_MIN       0x0001   //TBD
//#define MB_RD_COILS_ADDR_MAX       0xFFFE   //
//#define MB_RD_COILS_MIN            1
//#define MB_RD_COILS_MAX            2000

//Read Holding Registers
//#define MB_REG_HLD_ADD_MIN         0x0001   //TBD
//#define MB_REG_HLD_ADD_MAX         0xFFFE   //
//#define MB_REG_HLD_QTY_MIN         1
//#define MB_REG_HLD_QTY_MAX         125

//#define MB_RD_HLD_REG_ADDR_MIN     0x0001   //TBD
//#define MB_RD_HLD_REG_ADDR_MAX     0xFFFE   //
//#define MB_RD_HLD_REG_MIN          1
//#define MB_RD_HLD_REG_MAX          125

//Read Input Registers
//#define MB_REG_INP_ADD_MIN         0x0001   //TBD
//#define MB_REG_INP_ADD_MAX         0xFFFE   //
//#define MB_REG_INP_QTY_MIN         1
//#define MB_REG_INP_QTY_MAX         125

//#define MB_RD_IN_REGS_ADDR_MIN     0x0001   //TBD
//#define MB_RD_IN_REGS_ADDR_MAX     0xFFFE   //
//#define MB_RD_IN_REGS_MIN          1
//#define MB_RD_IN_REGS_MAX          125

//Read Discrete Inputs
//#define MB_RD_DISC_IN_ADDR_MIN     0x0001   //TBD
//#define MB_RD_DISC_IN_ADDR_MAX     0xFFFE   //
//#define MB_RD_DISC_IN_MIN          1
//#define MB_RD_DISC_IN_MAX          2000

//Write Single Coil
//#define MB_WR_SGL_COIL_ADDR_MIN    0x0001   //TBD
//#define MB_WR_SGL_COIL_ADDR_MAX    0xFFFE   //
//#define MB_WR_SGL_COIL_ON          0xFF00
//#define MB_WR_SGL_COIL_OFF         0x0000

//Write Multiple Coils
//#define MB_WR_MPL_COILS_ADDR_MIN   0x0001   //TBD
//#define MB_WR_MPL_COILS_ADDR_MAX   0xFFFE   //
//#define MB_WR_MPL_COILS_MIN        1
//#define MB_WR_MPL_COILS_MAX        1968

//Write Single Register
//#define MB_WR_SGL_REG_ADDR_MIN     0x0001   //TBD
//#define MB_WR_SGL_REG_ADDR_MAX     0xFFFE   //

//Write Multiple Registers
//#define MB_WR_MPL_REGS_ADDR_MIN    0x0001   //TBD
//#define MB_WR_MPL_REGS_ADDR_MAX    0xFFFE   //
//#define MB_WR_MPL_REGS_MIN         1
//#define MB_WR_MPL_REGS_MAX         120

#define MB_SECTION_CFG             0
#define MB_SECTION_INP             1


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	MB_Packet_t* PktRx;
	MB_Packet_t* PktTx;
} MB_t;

typedef struct {
	const MB_Register_t* Registers;
//	      uint16_t       RegCount;
	      uint16_t       AddMin;
	      uint16_t       AddMax;
	      uint16_t       QtyMin;
	      uint16_t       QtyMax;
} MB_Section_t;


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static MB_t MB;


static const MB_Section_t MB_Sections[] =
{
	{ CFG_Registers, CFG_MB_ADD_MIN, CFG_MB_ADD_MAX, CFG_MB_QTY_MIN, CFG_MB_QTY_MAX },
	{ APP_Registers, APP_MB_ADD_MIN, APP_MB_ADD_MAX, APP_MB_QTY_MIN, APP_MB_QTY_MAX }
};
//static const MB_Register_t* MB_Registers[] =
//{
//	CFG_Registers
//};


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void MB_Read    (COM_Connexion_t* Conx, MB_Function_t Function);
static void MB_Write   (COM_Connexion_t* Conx, MB_Function_t Function);
//static void MB_Read    (COM_Connexion_t* Conx, const MB_Section_t* Section);
//static void MB_Write   (COM_Connexion_t* Conx);
//static void MB_Read    (COM_Connexion_t* Conx, MB_Function_t Function);
//static void MB_Write   (COM_Connexion_t* Conx, MB_Function_t Function);

//static void MB_GetRam (void* Ram, MB_Reg_t Type, uint16_t* Data);
static void MB_WriteRam (const MB_Register_t* Register, uint16_t* Data);

//static void MB_ReadHoldingRegisters   (COM_Connexion_t* Conx);
//static void MB_ReadInputRegisters     (COM_Connexion_t* Conx);
//static void MB_WriteSingleRegister    (COM_Connexion_t* Conx);
//static void MB_WriteMultipleRegisters (COM_Connexion_t* Conx);
static void  MB_Error              (COM_Connexion_t* Conx, MB_Error_t Err);
static void  MB_Tx                     (COM_Connexion_t* Conx, uint16_t Length);
static const MB_Register_t* MB_GetRegister(const MB_Section_t* Section, uint16_t Register);
//static void MB_ReadCoils              (COM_Connexion_t* Conx);
//static void MB_ReadInputRegisters     (COM_Connexion_t* Conx);
//static void MB_ReadHoldingRegisters   (COM_Connexion_t* Conx);
//static void MB_ReadDiscreteInputs     (COM_Connexion_t* Conx);
//static void MB_WriteSingleCoil        (COM_Connexion_t* Conx);
//static void MB_WriteMultipleCoils     (COM_Connexion_t* Conx);
//static void MB_WriteSingleRegister    (COM_Connexion_t* Conx);
//static void MB_WriteMultipleRegisters (COM_Connexion_t* Conx);
//static void MB_SendError              (COM_Connexion_t* Conx, MB_Error_t Err);
//static void MB_Tx                     (COM_Connexion_t* Conx, uint16_t Length);


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
//		case MbFctRdHldRegs:   { MB_Read  (Conx, &MB_Sections[MB_SECTION_CFG]);   break; }
//		case MbFctRdInpRegs:   { MB_Read  (Conx, &MB_Sections[MB_SECTION_INP]);   break; }
//		case MbFctWrSglReg:
//		case MbFctWrMplRegs:   { MB_Write (Conx);                                 break; }
//		default:               { MB_Error (Conx, MbErrIllegalFunction);           break; }
	}
}
//void MB_Process(COM_Connexion_t* Conx)
//{
//	MB.PktRx = (MB_Packet_t*)Conx->PacketIn.Payload;
//	MB.PktTx = (MB_Packet_t*)Conx->PacketOut.Payload;
//
//	MB.PktTx->Header.Address  = MB.PktRx->Header.Address;
//	MB.PktTx->Header.Function = MB.PktRx->Header.Function;
//
//	switch(MB.PktRx->Header.Function)
//	{
//		case MbFctRdCoils:      { MB_ReadCoils              (Conx);                         break; }
//		case MbFctRdInRegs:     { MB_ReadInputRegisters     (Conx);                         break; }
//		case MbFctRdHldRegs:    { MB_ReadHoldingRegisters   (Conx);                         break; }
//		case MbFctRdDscIn:      { MB_ReadDiscreteInputs     (Conx);                         break; }
//		case MbFctWrSglCoil:    { MB_WriteSingleCoil        (Conx);                         break; }
//		case MbFctWrMplCoils:   { MB_WriteMultipleCoils     (Conx);                         break; }
//		case MbFctWrSglReg:     { MB_WriteSingleRegister    (Conx);                         break; }
//		case MbFctWrMplRegs:    { MB_WriteMultipleRegisters (Conx);                         break; }
//		default:                { MB_SendError              (Conx, MbErrIllegalFunction);   break; }
//	}
//}


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

		Ans->ByteCount = REVERSE_ORDER_16(Req->Quantity * sizeof(uint16_t));

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
//static void MB_Read(COM_Connexion_t* Conx, const MB_Section_t* Section)
//{
//	MB_FctReadReq_t* Req = (MB_FctReadReq_t*)&MB.PktRx->Function;
//	MB_FctReadAns_t* Ans = (MB_FctReadAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address) + 1;   //Focus addresses are 0 based
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < Section->AddMin) || (Req->Address > Section->AddMax))
//		MB_Error(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < Section->QtyMin) || (Req->Quantity > Section->QtyMax))
//		MB_Error(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		const MB_Register_t* Reg;
//		uint16_t* Data = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctReadAns_t));
//
//		Ans->ByteCount = REVERSE_ORDER_16(Req->Quantity * sizeof(uint16_t));
//
//		for(uint16_t i = 0; i < Req->Quantity; i++)
//		{
//			Reg = MB_GetRegister(Section, Req->Address++);
//			if(Reg)
//			{
//				switch(Reg->Type)
//				{
//					case MbReg8:         { Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Reg->Ram)));   break; }
//					case MbReg16:        { Data[i] = REVERSE_ORDER_16(*((uint16_t*)Reg->Ram));              break; }
//					case MbRegLoc:
//					{
//						memcpy(Data, Reg->Ram, CFG_MODBUS_LOC_SIZE);
//						for(int i = 0; i < CFG_MODBUS_LOC_SIZE/2; i++)
//							Data[i] = REVERSE_ORDER_16(Data[i]);
//					}
//					break;
//					case MbRegTemp:      { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Reg->Ram)));   break; }
//					case MBRegPercent:   { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Reg->Ram)));    break; }
//				}
//			}
//		}
//
//		MB_Tx(Conx, sizeof(MB_FctReadAns_t) + Ans->ByteCount);
//	}
//}

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
			Ans->Param = REVERSE_ORDER_16(Req->Param);
			MB_WriteRam(Reg, &Ans->Param);
		}
	}

	else   //Multiple registers write
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
//static void MB_GetRam(void* Ram, MB_Reg_t Type, uint16_t* Data)
//{
//	switch(Type)
//	{
//		case MbReg8:         { *Data = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Ram)));   break; }
//		case MbReg16:        { *Data = REVERSE_ORDER_16(*((uint16_t*)Ram));              break; }
//		case MbRegLoc:
//		{
//			memcpy(Data, Ram, CFG_MODBUS_LOC_SIZE);
//			for(int i = 0; i < CFG_MODBUS_LOC_SIZE/2; i++)
//				Data[i] = REVERSE_ORDER_16(Data[i]);
//		}
//		break;
//		case MbRegTemp:      { *Data = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Ram)));   break; }
//		case MBRegPercent:   { *Data = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Ram)));    break; }
//	}
//}

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
		case MbRegTemp:      { *((int16_t*)Register->Ram) = (int16_t)(REVERSE_ORDER_16(*Data));   break; }
		case MBRegPercent:   { *((int8_t*)Register->Ram) = (int8_t)(REVERSE_ORDER_16(*Data));     break; }
	}
}








//static void MB_ReadCoils(COM_Connexion_t* Conx)
//{
//	MB_FctRdCoilsReq_t* Req = (MB_FctRdCoilsReq_t*)&MB.PktRx->Function;
////	MB_FctRdCoilsAns_t* Ans = (MB_FctRdCoilsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_RD_COILS_ADDR_MIN) || (Req->Address > MB_RD_COILS_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_RD_COILS_MIN) || (Req->Quantity > MB_RD_COILS_MAX))
//			MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//	}
//}

//#define REQ_COUNT 16
//uint16_t ReqCnt;
//uint16_t ReqAdd[REQ_COUNT];
//uint16_t ReqQty[REQ_COUNT];
//-----------------------------------------------------------------------------
//static void MB_ReadHoldingRegisters(COM_Connexion_t* Conx)
//{
//	MB_FctRdHldRegsReq_t* Req = (MB_FctRdHldRegsReq_t*)&MB.PktRx->Function;
//	MB_FctRdHldRegsAns_t* Ans = (MB_FctRdHldRegsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address) + 1;   //Focus holding registers are 0 based
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	ReqAdd[ReqCnt] = Req->Address;
//	ReqQty[ReqCnt] = Req->Quantity;
//	ReqCnt++;
//	ReqCnt &= (REQ_COUNT-1);
//
//	if((Req->Address < MB_RD_HLD_REG_ADDR_MIN) || (Req->Address > MB_RD_HLD_REG_ADDR_MAX))
//		MB_Error(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_RD_HLD_REG_MIN) || (Req->Quantity > MB_RD_HLD_REG_MAX))
//		MB_Error(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		uint16_t* Ptr = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctRdHldRegsAns_t));
//
//		Ans->ByteCount = Req->Quantity * sizeof(uint16_t);
//		CFG_Read(Req->Address, Req->Quantity, Ptr);
//		MB_Tx(Conx, sizeof(MB_FctRdHldRegsAns_t) + Ans->ByteCount);
//	}
//}
//static void MB_ReadHoldingRegisters(COM_Connexion_t* Conx)
//{
//	MB_FctRdHldRegsReq_t* Req = (MB_FctRdHldRegsReq_t*)&MB.PktRx->Function;
//	MB_FctRdHldRegsAns_t* Ans = (MB_FctRdHldRegsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address) + 1;   //Focus holding registers are 0 based
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_RD_HLD_REG_ADDR_MIN) || (Req->Address > MB_RD_HLD_REG_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_RD_HLD_REG_MIN) || (Req->Quantity > MB_RD_HLD_REG_MAX))
//		MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		uint16_t* Ptr = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctRdHldRegsAns_t));
//
//		Ans->ByteCount = Req->Quantity * sizeof(uint16_t);
//
//		if(Req->Address == CfgHrDevType)
//		{
//			*Ptr = REVERSE_ORDER_16(4);   //4 simulates a T1100
//		}
//
//		else if(Req->Address == CfgHrSoftVer)
//		{
//			*Ptr = REVERSE_ORDER_16(APP_VERSION);
//		}
//
//		else if(Req->Address == CfgHrHardVer)
//		{
//			*Ptr = REVERSE_ORDER_16(FMK_GetSharedFlash()->HardwareVersion);
//		}
//
//		else
//		{
//			for(uint16_t i = 0; i < Req->Quantity; i++)
//			{
//				CFG_Read(Req->Address++, &Ptr[i]);
//				Ptr[i] = REVERSE_ORDER_16(Ptr[i]);
//			}
//		}
//		MB_Tx(Conx, sizeof(MB_FctRdHldRegsAns_t) + Ans->ByteCount);
//	}
//}

//uint16_t Tbl[4] = { 81, 82, 83, 84 };
//-----------------------------------------------------------------------------
//static void MB_ReadInputRegisters(COM_Connexion_t* Conx)
//{
//	MB_FctRdInRegsReq_t* Req = (MB_FctRdInRegsReq_t*)&MB.PktRx->Function;
//	MB_FctRdInRegsAns_t* Ans = (MB_FctRdInRegsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address) + 1;   //Focus holding registers are 0 based
////	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_RD_IN_REGS_ADDR_MIN) || (Req->Address > MB_RD_IN_REGS_ADDR_MAX))
//		MB_Error(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_RD_IN_REGS_MIN) || (Req->Quantity > MB_RD_IN_REGS_MAX))
//		MB_Error(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		uint16_t* Ptr = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctRdInRegsAns_t));
//
//		Ans->ByteCount = Req->Quantity * sizeof(uint16_t);
//		Ptr[0] = Tbl[0];
//		Ptr[1] = Tbl[1];
//		Ptr[2] = Tbl[2];
//		Ptr[3] = Tbl[3];
////		CFG_Read(Req->Address, Req->Quantity, Ptr);
//		MB_Tx(Conx, sizeof(MB_FctRdInRegsAns_t) + Ans->ByteCount);
//	}
//}

//-----------------------------------------------------------------------------
//static void MB_ReadDiscreteInputs(COM_Connexion_t* Conx)
//{
//	MB_FctRdDscInsReq_t* Req = (MB_FctRdDscInsReq_t*)&MB.PktRx->Function;
////	MB_FctRdDscInsAns_t* Ans = (MB_FctRdDscInsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_RD_DISC_IN_ADDR_MIN) || (Req->Address > MB_RD_DISC_IN_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_RD_DISC_IN_MIN) || (Req->Quantity > MB_RD_DISC_IN_MAX))
//		MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
////		uint8_t Quotient = Req->Quantity / 8;
////		if(Quotient <= 1)
////			Ans->ByteCount = 1;
////		else
////			Ans->ByteCount = Quotient;
////
////		if((Req->Quantity % 8) > 0)
////			Ans->ByteCount++;
//	}
//}

//-----------------------------------------------------------------------------
//static void MB_WriteSingleCoil(COM_Connexion_t* Conx)
//{
//	MB_FctWrSglCoilReq_t* Req = (MB_FctWrSglCoilReq_t*)&MB.PktRx->Function;
////	MB_FctWrSglCoilAns_t* Ans = (MB_FctWrSglCoilAns_t*)&MB.PktTx->Function;
//
//	Req->Address = REVERSE_ORDER_16(Req->Address);
//	Req->Value   = REVERSE_ORDER_16(Req->Value);
//
//	if((Req->Address < MB_WR_SGL_COIL_ADDR_MIN) || (Req->Address > MB_WR_SGL_COIL_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Value != MB_WR_SGL_COIL_ON) && (Req->Value != MB_WR_SGL_COIL_OFF))
//		MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}

//-----------------------------------------------------------------------------
//static void MB_WriteMultipleCoils(COM_Connexion_t* Conx)
//{
//	MB_FctWrMplCoilsReq_t* Req = (MB_FctWrMplCoilsReq_t*)&MB.PktRx->Function;
////	MB_FctWrMplCoilsAns_t* Ans = (MB_FctWrMplCoilsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_WR_MPL_COILS_ADDR_MIN) || (Req->Address > MB_WR_MPL_COILS_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_WR_MPL_COILS_MIN) && (Req->Quantity > MB_WR_MPL_COILS_MAX))
//		MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}

//-----------------------------------------------------------------------------
//static void MB_WriteSingleRegister(COM_Connexion_t* Conx)
//{
//	MB_FctWrSglRegReq_t* Req = (MB_FctWrSglRegReq_t*)&MB.PktRx->Function;
////	MB_FctWrSglRegAns_t* Ans = (MB_FctWrSglRegAns_t*)&MB.PktTx->Function;
//
//	Req->Address = REVERSE_ORDER_16(Req->Address);
//	Req->Value   = REVERSE_ORDER_16(Req->Value);
//
//	if((Req->Address < MB_WR_SGL_REG_ADDR_MIN) || (Req->Address > MB_WR_SGL_REG_ADDR_MAX))
//		MB_Error(Conx, MbErrIllegalDataAddress);
//
//	else
//	{
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}

//-----------------------------------------------------------------------------
//static void MB_WriteMultipleRegisters(COM_Connexion_t* Conx)
//{
//	MB_FctWrMplRegsReq_t* Req = (MB_FctWrMplRegsReq_t*)&MB.PktRx->Function;
//	MB_FctWrMplRegsAns_t* Ans = (MB_FctWrMplRegsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_WR_MPL_REGS_ADDR_MIN) || (Req->Address > MB_WR_MPL_REGS_ADDR_MAX))
//		MB_Error(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_WR_MPL_REGS_MIN) && (Req->Quantity > MB_WR_MPL_REGS_MAX))
//		MB_Error(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		uint16_t* Ptr = (uint16_t*)((uint32_t)Ans + sizeof(MB_FctWrMplRegsReq_t));
//
//		Ans->Address = REVERSE_ORDER_16(Req->Address);
//		Ans->QtyWritten = REVERSE_ORDER_16(Req->Quantity);
//		CFG_Write(Req->Address, Req->Quantity, Ptr);
//		MB_Tx(Conx, sizeof(MB_FctWrMplRegsAns_t) + Req->Quantity * sizeof(uint16_t));
//
//
//
//
//
////		uint16_t* Ptr = (uint16_t*)((uint32_t)Req + sizeof(MB_FctWrMplRegsReq_t));
////
////		Ans->Address = REVERSE_ORDER_16(Req->Address);
////		Ans->QtyWritten = REVERSE_ORDER_16(Req->Quantity);
////		for(uint16_t i = 0; i < Req->Quantity; i++)
////		{
////			Ptr[i] = REVERSE_ORDER_16(Ptr[i]);
//////			CFG_Write(Req->Address++, &Ptr[i]);
////		}
////		MB_Tx(Conx, sizeof(MB_FctWrMplRegsAns_t));
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}
//static void MB_WriteMultipleRegisters(COM_Connexion_t* Conx)
//{
//	MB_FctWrMplRegsReq_t* Req = (MB_FctWrMplRegsReq_t*)&MB.PktRx->Function;
//	MB_FctWrMplRegsAns_t* Ans = (MB_FctWrMplRegsAns_t*)&MB.PktTx->Function;
//
//	Req->Address  = REVERSE_ORDER_16(Req->Address);
//	Req->Quantity = REVERSE_ORDER_16(Req->Quantity);
//
//	if((Req->Address < MB_WR_MPL_REGS_ADDR_MIN) || (Req->Address > MB_WR_MPL_REGS_ADDR_MAX))
//		MB_SendError(Conx, MbErrIllegalDataAddress);
//
//	else if((Req->Quantity < MB_WR_MPL_REGS_MIN) && (Req->Quantity > MB_WR_MPL_REGS_MAX))
//		MB_SendError(Conx, MbErrIllegalDataValue);
//
//	else
//	{
//		uint16_t* Ptr = (uint16_t*)((uint32_t)Req + sizeof(MB_FctWrMplRegsReq_t));
//
//		Ans->Address = REVERSE_ORDER_16(Req->Address);
//		Ans->QtyWritten = REVERSE_ORDER_16(Req->Quantity);
//		for(uint16_t i = 0; i < Req->Quantity; i++)
//		{
//			Ptr[i] = REVERSE_ORDER_16(Ptr[i]);
////			CFG_Write(Req->Address++, &Ptr[i]);
//		}
//		MB_Tx(Conx, sizeof(MB_FctWrMplRegsAns_t));
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}

//-----------------------------------------------------------------------------
static const MB_Register_t* MB_GetRegister(const MB_Section_t* Section, uint16_t Register)
{
	uint16_t Size = *(&Section->Registers + 1) - Section->Registers;

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
