
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
//         File : com_rs485.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : RS-485 communication header file
//=============================================================================
#ifndef RS485_H
#define RS485_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"
#include "com.h"


//=============================================================================
//  C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
#define RS485_INSTANCE               (huart3.Instance)   //Actual peripheral instance
#define RS485_INSTANCE_IRQ            USART3_IRQn        //Peripheral instance interrupt line
#define RS485_RX_TIMEOUT              1150               //Number of bits that make the receive timeout (at 57600 baud, ~20msec)
#define RS485_OVERHEAD_SIZE           16                 //Communication packet header/checksum maximum size in bytes
#define RS485_PAYLOAD_SIZE            1024               //Communication packet data payload maximum size in bytes
#define RS485_BUFFER_SIZE            (RS485_OVERHEAD_SIZE + RS485_PAYLOAD_SIZE)   //Communication packet maximum size in bytes
#define RS485_TXRX_ATTEMPTS_COUNT     3                  //Number of synchronized communication attempts
#define RS485_TXRX_ATTEMPTS_TIMEOUT   1000               //Synchronized communication attempts time interval in msec


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void             RS485_Init         (void);
extern void             RS485_DeInit       (void);
extern void             RS485_Rx           (void);
extern void             RS485_Tx           (void);
extern uint32_t         RS485_TxRx         (void);
extern COM_Connexion_t* RS485_GetConnexion (void);
extern void             RS485_IRQHandler   (void);


#endif   //RS485_H
