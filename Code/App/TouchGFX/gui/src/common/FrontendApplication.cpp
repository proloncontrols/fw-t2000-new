#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <gui/clear_screen/ClearView.hpp>
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
		if(Screen.Action == UiScreenActionSwitch)
		{
			if (Screen.Switch.Id == UiScreenIdClear)
				gotoClearScreenNoTransition();

			if (Screen.Switch.Id == UiScreenIdMain)
				gotoMainScreenNoTransition();
		}
	}

    model.tick();
    FrontendApplicationBase::handleTickEvent();
}

// Reset

void FrontendApplication::gotoClearScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoClearScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoClearScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ClearView, ClearPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Main

void FrontendApplication::gotoMainScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoMainScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoMainScreenNoTransitionImpl()
{
    touchgfx::makeTransition<MainView, MainPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}










