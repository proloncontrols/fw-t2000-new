
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
//         File : products.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Products definition header file
//=============================================================================
#ifndef PRODUCTS_H
#define PRODUCTS_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "basic.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define PRD_SIZE_BANNER          32
#define PRD_SIZE_SERIAL_NUMBER   6


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef uint8_t PRD_Banner_t[PRD_SIZE_BANNER];


//=============================================================================
//  B L A N K
//-----------------------------------------------------------------------------
#define PRD_BLANK_HEADER   {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
#define PRD_BLANK_FOOTER   {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}


//=============================================================================
//  B O O T L O A D E R
//-----------------------------------------------------------------------------
#define PRD_BOOTLOADER                 0x00   //Family
//-----------------------------------------
#define PRD_BOOTLOADER_BOOT            0x01
#define PRD_BOOTLOADER_HEADER         {'B','O','O','T','L','O','A','D','E','R','_','H','E','A','D','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define PRD_BOOTLOADER_FOOTER         {'B','O','O','T','L','O','A','D','E','R','_','F','O','O','T','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//-----------------------------------------
#define PRD_BOOTUPDATER_BOOT           0x02
#define PRD_BOOTUPDATER_HEADER        {'B','O','O','T','U','P','D','A','T','E','R','_','H','E','A','D','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define PRD_BOOTUPDATER_FOOTER        {'B','O','O','T','U','P','D','A','T','E','R','_','F','O','O','T','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0}


//=============================================================================
//  T H E R M O S T A T
//-----------------------------------------------------------------------------
#define PRD_THERMOSTAT                 0x10   //Family
//-----------------------------------------
#define PRD_THERMOSTAT_T2000           0x01
#define PRD_THERMOSTAT_T2000_HEADER   {'T','2','0','0','0','_','H','E','A','D','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define PRD_THERMOSTAT_T2000_FOOTER   {'T','2','0','0','0','_','F','O','O','T','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//-----------------------------------------
//--- Add new thermostat IDs here ...


//=============================================================================
//  C O N T R O L L E R
//-----------------------------------------------------------------------------
#define PRD_CONTROLLER                 0x20   //Family
//-----------------------------------------
#define PRD_CONTROLLER_xxxxx           0x01
#define PRD_CONTROLLER_xxxxx_HEADER   {'x','x','x','x','x','_','H','E','A','D','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define PRD_CONTROLLER_xxxxx_FOOTER   {'x','x','x','x','x','_','F','O','O','T','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//-----------------------------------------
//--- Add new controller IDs here ...


//=============================================================================
//  N E T W O R K
//-----------------------------------------------------------------------------
#define PRD_NETWORK                    0x30   //Family
//-----------------------------------------
#define PRD_NETWORK_xxxxx              0x01
#define PRD_NETWORK_xxxxx_HEADER      {'x','x','x','x','x','_','H','E','A','D','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define PRD_NETWORK_xxxxx_FOOTER      {'x','x','x','x','x','_','F','O','O','T','E','R',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//-----------------------------------------
//--- Add new network IDs here ...


#endif   //PRODUCTS_H
