#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include "ui.h"
#include <cfg.h>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)   //<-- T2000 landscape orientation, not the screen
	{
		originX = CLIENT_ORIGIN_PORTRAIT_X;
		originY = CLIENT_ORIGIN_PORTRAIT_Y;
		orientation = SCREEN_PORTRAIT;
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
	}
	else
	{
		originX = CLIENT_ORIGIN_LANDSCAPE_X;
		originY = CLIENT_ORIGIN_LANDSCAPE_Y;
		orientation = SCREEN_LANDSCAPE;
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
