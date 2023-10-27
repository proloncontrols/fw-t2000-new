
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
//         File : ui.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : User-Interface implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#define UI_GLOBAL
#include "ui.h"
#include "main.h"
#include "event.h"
#include "app.h"
#include "framework.h"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	bool_t   ScreenIsOn;
	uint16_t ScreenTimeout;
} UI_t;


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static UI_t UI;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void UI_Init(void)
{
	UI_Flags = osEventFlagsNew(NULL);
	UI_QueueEnv = osMessageQueueNew(1, sizeof(ENV_Readings_t), NULL);
	UI_QueueScreen = osMessageQueueNew(1, sizeof(UI_Screen_t), NULL);
	UI_QueueProgress = osMessageQueueNew(1, sizeof(UI_Progress_t), NULL);
	UI_ScreenOn();
}

//-----------------------------------------------------------------------------
void UI_ScreenOn(void)
{
	if(!UI.ScreenIsOn)
	{
		UI.ScreenIsOn = TRUE;
		UI.ScreenTimeout = 0;
	    HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_SET);
	}
}
//---------------------------
void UI_ScreenOff(void)
{
	UI.ScreenIsOn = FALSE;
    HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_RESET);
}
//---------------------------
void UI_ScreenTimeout(uint16_t Timeout)
{
	if(Timeout == 0)   //0=feature disabled
		UI_ScreenOn();
	else if(UI.ScreenIsOn)
	{
		UI.ScreenTimeout += APP_IDLE_PERIODIC_TIMEOUT;
		if(UI.ScreenTimeout >= (Timeout * 1000))   //Convert sec timeout value into msec
			UI_ScreenOff();
	}
}
//---------------------------
void UI_ScreenTimeoutReset(void)
{
	UI.ScreenTimeout = 0;
	UI_ScreenOn();
}

//-----------------------------------------------------------------------------
void UI_PostEnv(ENV_Readings_t* Env)
{
	osMessageQueuePut(UI_QueueEnv, Env, 0, 0);
}

//-----------------------------------------------------------------------------
void UI_ScreenSwitchTo(UI_ScreenId_t Id)
{
	UI_Screen_t Screen;

	Screen.Action = UiScreenActionSwitch;
	Screen.Switch.Id = Id;
	osMessageQueuePut(UI_QueueScreen, &Screen, 0, 0);

	osEventFlagsWait(UI_Flags, 1, osFlagsWaitAny, 1000);
}
//---------------------------
void UI_ScreenSwitchCplt(void)
{
	osEventFlagsSet(UI_Flags, 1);
}

//-----------------------------------------------------------------------------
void UI_ProgressInit(uint32_t Steps)
{
	UI_Progress_t Progress;

	Progress.Action = UiProgressActionInit;
	Progress.Initialize.Steps = Steps;
	osMessageQueuePut(UI_QueueProgress, &Progress, 0, 0);
}
//---------------------------
void UI_ProgressInc(void)
{
	UI_Progress_t Progress;

	Progress.Action = UiProgressActionInc;
	osMessageQueuePut(UI_QueueProgress, &Progress, 0, 0);
}

































