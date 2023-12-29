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
		//From any screen, goto...:
		case ScreenId::ScreenHome:        { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoHomeScreenNoTransitionImpl);        break; }

		//From Home screen, goto...:
		case ScreenId::ScreenSettings:    { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoSettingsScreenNoTransitionImpl);    break; }

		//From Settings screen, goto...:
		case ScreenId::ScreenOptions:     { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoOptionsScreenNoTransitionImpl);     break; }
		case ScreenId::ScreenLanguage:    { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoLanguageScreenNoTransitionImpl);    break; }
		case ScreenId::ScreenUnit:        { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoUnitScreenNoTransitionImpl);        break; }
		case ScreenId::ScreenTime:        { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoTimeScreenNoTransitionImpl);        break; }
		case ScreenId::ScreenOrientation: { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoOrientationScreenNoTransitionImpl); break; }
		case ScreenId::ScreenAboutme:     { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoAboutmeScreenNoTransitionImpl);     break; }
		case ScreenId::ScreenVisualize:   { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoVisualizeScreenNoTransitionImpl);   break; }
		case ScreenId::ScreenDevice:      { transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoDeviceScreenNoTransitionImpl);      break; }

		default: return;
	}
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoHomeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<HomeView, HomePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoSettingsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<SettingsView, SettingsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
void FrontendApplication::gotoLanguageScreenNoTransitionImpl()
{
    touchgfx::makeTransition<LanguageView, LanguagePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
void FrontendApplication::gotoUnitScreenNoTransitionImpl()
{
    touchgfx::makeTransition<UnitView, UnitPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
void FrontendApplication::gotoTimeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<TimeView, TimePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
void FrontendApplication::gotoOrientationScreenNoTransitionImpl()
{
    touchgfx::makeTransition<OrientationView, OrientationPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}



void FrontendApplication::gotoOptionsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<OptionsView, OptionsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoAboutmeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<AboutmeView, AboutmePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoVisualizeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<VisualizeView, VisualizePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplication::gotoDeviceScreenNoTransitionImpl()
{
    touchgfx::makeTransition<DeviceView, DevicePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
