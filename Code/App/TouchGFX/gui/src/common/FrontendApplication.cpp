#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include "ui.h"
#include <cfg.h>
#include <CDisplay.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap),
      transitionCallback()

{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)   //<-- T2000 orientation, not its screen
		Display.initialize(CDisplay::LANDSCAPE, NATIVE_WIDTH, NATIVE_HEIGHT, CLIENT_WIDTH, CLIENT_HEIGHT);
	else
	{
		Display.initialize(CDisplay::PORTRAIT, NATIVE_WIDTH, NATIVE_HEIGHT, CLIENT_WIDTH, CLIENT_HEIGHT);
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

void FrontendApplication::gotoMenuMainScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoMenuMainScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoMenuMainScreenNoTransitionImpl()
{
    touchgfx::makeTransition<MenuMainView, MenuMainPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoSetpointsScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoSetpointsScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoSetpointsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<SetPointsView, SetPointsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
