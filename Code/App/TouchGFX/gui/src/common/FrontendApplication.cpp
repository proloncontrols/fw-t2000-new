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

void FrontendApplication::gotoScreen(ScreenId nextScreen)
{
	switch(nextScreen)
	{
		//From any screen, goto:
		case ScreenId::ScreenHome:       { gotoHomeScreenNoTransition(); return; }

		//From Home screen, goto:
		case ScreenId::ScreenSettings:   { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoSettingsScreenNoTransitionImpl);  break; }

		//From Settings screen, goto:
		case ScreenId::ScreenOptions:    { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoOptionsScreenNoTransitionImpl);   break; }
		case ScreenId::ScreenAboutme:    { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoAboutmeScreenNoTransitionImpl);   break; }
		case ScreenId::ScreenVisualize:  { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoVisualizeScreenNoTransitionImpl); break; }
		case ScreenId::ScreenDevice:     { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoDeviceScreenNoTransitionImpl);    break; }

		default: return;
	}
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoSettingsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<SettingsView, SettingsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoOptionsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<OptionsView, OptionsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoAboutmeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<AboutMeView, AboutMePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoVisualizeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<VisualizeView, VisualizePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoDeviceScreenNoTransitionImpl()
{
    touchgfx::makeTransition<DeviceView, DevicePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
