
#ifndef EVT_H
#define EVT_H


#ifdef __cplusplus
extern "C" {
#endif


#include "basic.h"
#include "cmsis_os2.h"


typedef enum {
	EVT_GROUP_SYS,     //System event group
	EVT_GROUP_COM,     //Communication event group
	EVT_GROUP_GFX,     //User-Interface event group
	EVT_GROUP_ENV,     //Environmental readings event group
	EVT_GROUP_ANL      //Analog inputs readings event group
	//...
} EVT_Group_t;

typedef enum {
	EVT_GFX_READY
} EVT_Event_t;

typedef enum {
	EVT_DATA_TYPE_NONE,
	EVT_DATA_TYPE_8,
	EVT_DATA_TYPE_16,
	EVT_DATA_TYPE_32,
	EVT_DATA_TYPE_FLOAT,
	EVT_DATA_TYPE_DOUBLE
	//...
} EVT_DataType_t;

//typedef struct {
//	EVT_Group_t Group;
//	uint16_t Event;
//	EVT_DataType_t DataType;
//	union {
//		uint8_t  data8;
//		uint16_t data16;
//		uint32_t data32;
//		float    dataFloat;
//		double   dataDouble;
//		//...
//	} Data;
//} EVT_Event_t;

typedef union {
	uint8_t  data8;
	uint16_t data16;
	uint32_t data32;
	float    dataFloat;
	double   dataDouble;
	//...
} EVT_Data_t;


void EVT_Init(osEventFlagsId_t AppFlags);
//void EVT_PostToApp(EVT_Event_t* Event);
void EVT_PostToApp(EVT_Group_t Group, EVT_Event_t Event, EVT_DataType_t DataType, void* Data);
//void EVT_PostToGfx(EVT_Event_t* Event);


#ifdef __cplusplus
}
#endif










//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : event.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : System/application events header file
//=============================================================================
//#ifndef EVT_H
//#define EVT_H


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define EVNT_ALL_GROUPS_MASK   0x007FFFFF   //Maximum number of user defined events allowed by the OS (23 events)


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
} EVNT_Group_t;


#endif   //EVT_H
