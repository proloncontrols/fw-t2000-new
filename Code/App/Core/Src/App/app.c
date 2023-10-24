
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
#include "event.h"
#include "app.h"
#include "stdio.h"
#include "modbus.h"
#include "ui.h"
#include "cfg.h"


//=============================================================================
//  M O D B U S   R E G I S T E R S   D E F I N I T I O N
//-----------------------------------------------------------------------------
const MB_Register_t APP_Registers[] =
{
	{ 1,   MbRegTemp,      100,   &APP.Env.Temp },
	{ 2,   MbRegTemp,      100,   &APP.HeatSP   },
	{ 3,   MbRegTemp,      100,   &APP.CoolSP   },
	{ 4,   MBRegPercent,     1,   &APP.Demand   }
};


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void APP_OnInitBegin(void)
{
	//Called once before the OS Kernel starts
	//(from beginning of calling function)
//	BSP_OSPI_NOR_Read(0, Tmp, 0x901802E0, 16);
}
void APP_OnInitEnd(void)
{
	//Called once before the OS Kernel starts
	//(from end of calling function)

	ENV_Init();

////----- For test purposes only. TODO: To be removed -----------------------------------------------
//	uint16_t Ver = APP_VERSION;
//	APP_Queue = osMessageQueueNew(1, sizeof(uint16_t), NULL);
//	osMessageQueuePut(APP_Queue, &Ver, 0, 0);
////-------------------------------------------------------------------------------------------------
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

	UI_ScreenTimeout(CFG.Dta.ScrTimeout);
//	UI_ScreenTimeout(FMK_Config.ScreenTimeout);
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

	if(Flag & NUM2POS(EvtGrpUi))
		UI_ScreenTimeoutReset();

	if(Flag & NUM2POS(EvtGrpEnv))
	{
		if(!APP.SplashDone)
			UI_ScreenSwitchTo(UiScrIdMain);
		APP.SplashDone = TRUE;

		ENV_Read(&APP.Env);
		if(APP.Env.Device > EnvDevPowerup)
		{
			if(APP.Env.Device > EnvDevNone)
			{
//				UI_Text_t Text;
//
//				Text.TextLabel = UiTextTemp;
//				if(CFG.Dta.TempUnit == CfgEnvTempC)
////				if(FMK_Config.TempUnit == CfgTempC)
//					sprintf((char*)Text.Text, "%f", APP.Env.TempC);
////					sprintf((char*)Text.Text, "%.1f°C", APP.Env.TempC);
//				else
//					sprintf((char*)Text.Text, "%f", APP.Env.TempF);
////					sprintf((char*)Text.Text, "%.1f°F", APP.Env.TempF);
				UI_PostEnv(&APP.Env);
////				UI_PostText(&Text);
			}
		}
	}
}

























