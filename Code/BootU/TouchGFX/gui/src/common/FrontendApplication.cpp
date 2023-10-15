#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <gui/main_screen/MainView.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include "ui.h"

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

void FrontendApplication::handleTickEvent()
{
	if(osMessageQueueGet(UI_QueueScreen, &Screen, NULL, 0) == osOK)
	{
		if(Screen.Name == UiScrSw)
		{
			if (Screen.ScreenSwitch.Id == UiScrIdReset)
				gotoResetScreenNoTransition();
		}
	}

    model.tick();
    FrontendApplicationBase::handleTickEvent();
}

// Reset

void FrontendApplication::gotoResetScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoResetScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoResetScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ResetView, ResetPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
