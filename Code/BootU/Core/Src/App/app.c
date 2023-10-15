
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
//         File : app.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Application implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#define APP_GLOBAL
#include "app.h"
#include "modbus.h"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void APP_OnInitBegin(void)
{
	//Called once before the OS Kernel starts
	//(from beginning of calling function)
}
void APP_OnInitEnd(void)
{
	//Called once before the OS Kernel starts
	//(from end of calling function)

//----- For test purposes only. TODO: To be removed -----------------------------------------------
	uint16_t Ver = APP_VERSION;
	APP_Queue = osMessageQueueNew(1, sizeof(uint16_t), NULL);
	osMessageQueuePut(APP_Queue, &Ver, 0, 0);
//-------------------------------------------------------------------------------------------------
}

//-----------------------------------------------------------------------------
void APP_OnEntryBegin(void)
{
	//Called once after the OS Kernel has started but before the main loop starts
	//(from beginning of calling function)
}
void APP_OnEntryEnd(void)
{
	//Called once after the OS Kernel has started but before the main loop starts
	//(from end of calling function)
}

//-----------------------------------------------------------------------------
void APP_OnPeriodic(void)
{
	//Called every periodic timeout (defined in app.h APP_IDLE_PERIODIC_TIMEOUT)
}

//-----------------------------------------------------------------------------
void APP_OnCom(COM_Connexion_t* Conx)
{
	//Called when received ModBus packet integrity is validated (CRC OK)  AND  if address is 0 (broadcast)  OR  if address matches that of current module

	MB_Process(Conx);
}

//-----------------------------------------------------------------------------
void APP_OnFlag(uint32_t Flag)
{
	//Called on unhandled events (flags)
}
