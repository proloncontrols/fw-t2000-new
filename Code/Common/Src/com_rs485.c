
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
//         File : com_rs485.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : RS-485 communication implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "stm32h7xx_ll_usart.h"
#include "com_rs485.h"
#include "framework.h"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	osThreadId_t     ThreadId;
	osEventFlagsId_t Events;
	COM_Connexion_t  Conx;
	bool_t           RxError;
	uint32_t         DataCounter;
	bool_t           TxRxDone;
	uint32_t         AttemptCounter;
	uint8_t          BufferIn[RS485_BUFFER_SIZE];
	uint8_t          BufferOut[RS485_BUFFER_SIZE];
} RS485_t;


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
static const osThreadAttr_t RS485_ThreadAttributes =
{
	.name       = "RS485Thread",
    .stack_size = 128 * 4,
    .priority   = (osPriority_t)osPriorityAboveNormal,
};


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static RS485_t RS485;


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void RS485_Thread(void* Argument);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void RS485_Init(void)
{
	RS485.ThreadId = osThreadNew(RS485_Thread, NULL, &RS485_ThreadAttributes);
	if(RS485.ThreadId == NULL)
		Error_Handler();

	RS485.Events = osEventFlagsNew(NULL);
	RS485.Conx.Media = ComMediaRs485;
	RS485.Conx.PacketIn.Payload = RS485.BufferIn;
	RS485.Conx.PacketOut.Payload = RS485.BufferOut;

	LL_USART_SetRxTimeout(RS485_INSTANCE, RS485_RX_TIMEOUT);
    LL_USART_EnableRxTimeout(RS485_INSTANCE);

    HAL_NVIC_SetPriority(RS485_INSTANCE_IRQ, 5, 0);
    HAL_NVIC_EnableIRQ(RS485_INSTANCE_IRQ);

    RS485_Rx();
}

//-----------------------------------------------------------------------------
void RS485_DeInit(void)
{
}

//-----------------------------------------------------------------------------
int Cnt = 0;
void RS485_Rx(void)
{
	Cnt++;
	RS485.DataCounter = 0;
	RS485.RxError = FALSE;

	LL_USART_ClearFlag_FE(RS485_INSTANCE);
    LL_USART_ClearFlag_PE(RS485_INSTANCE);
    LL_USART_ClearFlag_NE(RS485_INSTANCE);
    LL_USART_ClearFlag_ORE(RS485_INSTANCE);
    LL_USART_EnableIT_RXNE_RXFNE(RS485_INSTANCE);

    LL_USART_ClearFlag_RTO(RS485_INSTANCE);
    LL_USART_EnableIT_RTO(RS485_INSTANCE);
}

//-----------------------------------------------------------------------------
void RS485_Tx(void)
{
	RS485.DataCounter = 0;

	LL_USART_ClearFlag_TC(RS485_INSTANCE);
    LL_USART_EnableIT_TXE_TXFNF(RS485_INSTANCE);
}

//-----------------------------------------------------------------------------
uint32_t RS485_TxRx(void)
{
	osThreadFlagsSet(RS485.ThreadId, NUM2POS(ComEventTxRxProcess));
	osEventFlagsWait(RS485.Events, NUM2POS(ComEventTxRxCplt), osFlagsWaitAny, osWaitForever);
	return RS485.Conx.Event;
}

//-----------------------------------------------------------------------------
COM_Connexion_t* RS485_GetConnexion(void)
{
	return &RS485.Conx;
}


//=============================================================================
//  I N T E R R U P T
//-----------------------------------------------------------------------------
void RS485_IRQHandler()
{
	uint8_t DataIn;

	//=================
	//       RX
	//=================

	if(LL_USART_IsActiveFlag_RTO(RS485_INSTANCE) && LL_USART_IsEnabledIT_RTO(RS485_INSTANCE))
	{
	    LL_USART_ClearFlag_RTO(RS485_INSTANCE);
        LL_USART_ClearFlag_FE(RS485_INSTANCE);
        LL_USART_ClearFlag_PE(RS485_INSTANCE);
        LL_USART_ClearFlag_NE(RS485_INSTANCE);
        LL_USART_ClearFlag_ORE(RS485_INSTANCE);
	    if(RS485.RxError)
	    	RS485.DataCounter = 0;
	    else
	    {
		    LL_USART_DisableIT_RTO(RS485_INSTANCE);
	    	LL_USART_DisableIT_RXNE_RXFNE(RS485_INSTANCE);
	    	osThreadFlagsSet(RS485.ThreadId, NUM2POS(ComEventRxCplt));
	    }
	    RS485.RxError = FALSE;
	}

	else if(LL_USART_IsActiveFlag_RXNE_RXFNE(RS485_INSTANCE) && LL_USART_IsEnabledIT_RXNE_RXFNE(RS485_INSTANCE))
	{
		DataIn = LL_USART_ReceiveData8(RS485_INSTANCE);

		if(RS485.DataCounter < RS485_BUFFER_SIZE)
		{
			RS485.Conx.PacketIn.Payload[RS485.DataCounter++] = DataIn;

			if(LL_USART_IsActiveFlag_PE(RS485_INSTANCE) ||
			   LL_USART_IsActiveFlag_FE(RS485_INSTANCE) ||
			   LL_USART_IsActiveFlag_NE(RS485_INSTANCE) ||
			   LL_USART_IsActiveFlag_ORE(RS485_INSTANCE)
			  )
				RS485.RxError = TRUE;
		}
	}

	//=================
	//       TX
	//=================

	else if(LL_USART_IsActiveFlag_TXE_TXFNF(RS485_INSTANCE) && LL_USART_IsEnabledIT_TXE_TXFNF(RS485_INSTANCE))
	{
		LL_USART_TransmitData8(RS485_INSTANCE, RS485.Conx.PacketOut.Payload[RS485.DataCounter++]);

		LL_USART_ClearFlag_TXFE(RS485_INSTANCE);

		if((RS485.DataCounter >= RS485.Conx.PacketOut.Length) || (RS485.DataCounter >= RS485_BUFFER_SIZE))
		{
			LL_USART_DisableIT_TXE_TXFNF(RS485_INSTANCE);
			LL_USART_ClearFlag_TC(RS485_INSTANCE);
			LL_USART_EnableIT_TC(RS485_INSTANCE);
		}
	}

	else if(LL_USART_IsActiveFlag_TC(RS485_INSTANCE) && LL_USART_IsEnabledIT_TC(RS485_INSTANCE))
	{
		LL_USART_DisableIT_TC(RS485_INSTANCE);
		osThreadFlagsSet(RS485.ThreadId, NUM2POS(ComEventTxCplt));
	}
}


//=============================================================================
//  T H R E A D
//-----------------------------------------------------------------------------
static void RS485_Thread(void* Argument)
{
	uint32_t Flags;

	while(1)
	{
		Flags = osThreadFlagsWait(NUM2POS(ComEventRxCplt) | NUM2POS(ComEventTxCplt) | NUM2POS(ComEventTxRxProcess), osFlagsWaitAny, osWaitForever);

		if(Flags & NUM2POS(ComEventRxCplt))
		{
			RS485.Conx.PacketIn.Length = RS485.DataCounter;
			RS485.Conx.Event = ComEventRxCplt;
			COM_PostMedia(ComMediaRs485);
		}

		else if(Flags & NUM2POS(ComEventTxCplt))
		{
			RS485.Conx.Event = ComEventTxCplt;
			COM_PostMedia(ComMediaRs485);
		}

		else
		{
			RS485.TxRxDone = FALSE;
			RS485.AttemptCounter = 0;
			do
			{
				RS485_Tx();
				Flags = osThreadFlagsWait(NUM2POS(ComEventTxCplt), osFlagsWaitAny, RS485_TXRX_ATTEMPTS_TIMEOUT);
				if(Flags == NUM2POS(ComEventTxCplt))
				{
					RS485_Rx();
					Flags = osThreadFlagsWait(NUM2POS(ComEventRxCplt), osFlagsWaitAny, RS485_TXRX_ATTEMPTS_TIMEOUT);
					if(Flags == NUM2POS(ComEventRxCplt))
						RS485.TxRxDone = TRUE;
				}
				RS485.AttemptCounter++;
			}
			while((RS485.AttemptCounter < RS485_TXRX_ATTEMPTS_COUNT) && (!RS485.TxRxDone));

			RS485.Conx.Event = ComEventTxRxFailure;
			if(RS485.TxRxDone)
				RS485.Conx.Event = ComEventTxRxSuccess;
			osEventFlagsSet(RS485.Events, NUM2POS(ComEventTxRxCplt));
		}
	}
}
