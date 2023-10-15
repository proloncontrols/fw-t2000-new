
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
//         File : event.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : System/application events header file
//=============================================================================
#ifndef EVT_H
#define EVT_H


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define EVT_ALL_GROUPS_MASK   0x007FFFFF   //Maximum number of user defined events allowed by the OS (23 events)


//=============================================================================
//  E V E N T   G R O U P S
//-----------------------------------------------------------------------------
typedef enum {
	EvtGrpSys,     //System event group
	EvtGrpCom,     //Communication event group
	EvtGrpUi,      //User-Interface event group
	EvtGrpEnv,     //Environmental readings event group
	EvtGrpAnl      //Analog inputs readings event group
	//...
} EVT_Group_t;


#endif   //EVT_H
