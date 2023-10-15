
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
//         File : com.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Communication definition header file
//=============================================================================
#ifndef COM_H
#define COM_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "basic.h"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	ComMediaRs485,
	//Add new medias here...
	ComEnd
} COM_Media_t;

typedef enum {
	ComProtocolFmk,
	ComProtocolMb,
	//-----
	ComProtocolCount
} COM_Protocol_t;

typedef enum {
	ComEventRxCplt,
	ComEventTxCplt,
	ComEventTxRxCplt,
	ComEventTxRxProcess,
	ComEventTxRxSuccess,
	ComEventTxRxFailure,
	//-----
	ComEventCount
} COM_Event_t;

#pragma pack(1)

typedef struct {
	uint32_t Length;
	uint8_t* Payload;
} COM_Packet_t;

#pragma pack()

typedef struct {
	COM_Event_t    Event;
	COM_Media_t    Media;
	COM_Protocol_t Protocol;
	COM_Packet_t   PacketIn;
	COM_Packet_t   PacketOut;
	uint8_t        ModBusAddress;
} COM_Connexion_t;

typedef uint16_t COM_Checksum_t;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//----- Public --------------
extern void             COM_Init         (void);
extern void             COM_DeInit       (void);
extern void             COM_Rx           (COM_Connexion_t* Conxn);
extern void             COM_Tx           (COM_Connexion_t* Conxn);
extern uint32_t         COM_TxRx         (COM_Connexion_t* Conxn);
extern bool_t           COM_ValidateCRC  (COM_Connexion_t* Conxn);
extern uint16_t         COM_CRC16        (void* Data, uint16_t Length);
extern COM_Media_t      COM_GetMedia     (void);
extern COM_Connexion_t* COM_GetConnexion (COM_Media_t Media);
//----- Protected -----------
extern void             COM_PostMedia    (COM_Media_t Media);


#endif   //COM_H
