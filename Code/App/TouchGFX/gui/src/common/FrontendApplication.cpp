#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include "ui.h"
#include <cfg.h>
#include <CScreen.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)   //<-- T2000 orientation, not its screen
	{
		setScrOriginX(CLIENT_ORIGIN_PORTRAIT_X);
		setScrOriginY(CLIENT_ORIGIN_PORTRAIT_Y);
		setScrDirection(SCR_PORTRAIT);
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
	}
	else
	{
		setScrOriginX(CLIENT_ORIGIN_LANDSCAPE_X);
		setScrOriginY(CLIENT_ORIGIN_LANDSCAPE_Y);
		setScrDirection(SCR_LANDSCAPE);
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
