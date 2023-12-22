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
//	dsp.orientation = CDisplay::NATIVE;  //Testing
//	if(CFG.Dta.ScrOrientation == CfgScrOrientP)   //<-- T2000 orientation, not the display
//		dsp.orientation = CDisplay::LANDSCAPE;
//	else
//	{
//		dsp.orientation = CDisplay::PORTRAIT;
//	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
//	}

	Texts::setLanguage(dsp.language);
	dsp.orientation = CDisplay::NATIVE;
 	if(dsp.orientation == CDisplay::PORTRAIT)
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
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
//    touchgfx::makeTransition<SetPointsView, SetPointsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
