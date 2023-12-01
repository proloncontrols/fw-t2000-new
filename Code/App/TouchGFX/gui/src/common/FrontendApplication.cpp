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
		Display.initialize(CDisplay::LANDSCAPE, CLIENT_SIZE);
	else
	{
		Display.initialize(CDisplay::PORTRAIT, CLIENT_SIZE);
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
	}
}

void FrontendApplication::handleTickEvent()
{
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
