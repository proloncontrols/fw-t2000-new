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

	dsp.orientation = CDisplay::NATIVE;
	Texts::setLanguage(dsp.language);
 	if(dsp.orientation == CDisplay::PORTRAIT)
	    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
}

void FrontendApplication::handleTickEvent()
{
    model.tick();
    FrontendApplicationBase::handleTickEvent();
}



//void FrontendApplication::gotoSetpointsScreenNoTransition()
//{
//    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoSetpointsScreenNoTransitionImpl);
//    pendingScreenTransitionCallback = &transitionCallback;
//}

//void FrontendApplication::gotoSetpointsScreenNoTransitionImpl()
//{
//    touchgfx::makeTransition<SetPointsView, SetPointsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
//}



//void FrontendApplication::gotoSettingsScreenNoTransition()
//{
//    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoSettingsScreenNoTransitionImpl);
//    pendingScreenTransitionCallback = &transitionCallback;
//}
//void FrontendApplication::gotoSettingsScreenNoTransitionImpl()
//{
//    touchgfx::makeTransition<SettingsView, SettingsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
//}



void FrontendApplication::gotoOptionsScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoOptionsScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
void FrontendApplication::gotoOptionsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<OptionsView, OptionsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoAboutMeScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoAboutMeScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
void FrontendApplication::gotoAboutMeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<AboutMeView, AboutMePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoVisualizeScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoVisualizeScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
void FrontendApplication::gotoVisualizeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<VisualizeView, VisualizePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoDeviceScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoDeviceScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
void FrontendApplication::gotoDeviceScreenNoTransitionImpl()
{
    touchgfx::makeTransition<DeviceView, DevicePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}





































