#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include "ui.h"
#include <cfg.h>
#include <CScreen.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)   //<-- T2000 orientation, not its screen
		initializeScreen(CLIENT_ORIGIN_LANDSCAPE_X, CLIENT_ORIGIN_LANDSCAPE_Y, SCR_LANDSCAPE);
	else
	{
		initializeScreen(CLIENT_ORIGIN_PORTRAIT_X, CLIENT_ORIGIN_PORTRAIT_Y, SCR_PORTRAIT);
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
	}
}

void FrontendApplication::handleTickEvent()
{
	if(osMessageQueueGet(UI_QueueScreen, &Screen, NULL, 0) == osOK)
	{
		if(Screen.Action == UiScreenActionSwitch)
		{
		}
	}

    model.tick();
    FrontendApplicationBase::handleTickEvent();
}
