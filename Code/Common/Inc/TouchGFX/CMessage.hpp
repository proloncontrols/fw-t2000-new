
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
//         File : CMessage.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Messages posting from GFX to application header file
//=============================================================================
#ifndef CMESSAGE_HPP
#define CMESSAGE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <cmsis_os2.h>


namespace touchgfx
{

//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	GFX_READY
} GfxMessage;


//=============================================================================
//  F U N C T I O N S
//-----------------------------------------------------------------------------
//void gfxPostMessage(GfxMessage msg);


class CMessage
{
public:
	CMessage(int x);
	void post(GfxMessage msg);

private:
	osMessageQueueId_t queue;
};

}


#endif   //CMESSAGE_HPP
