#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
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
		}
	}

    model.tick();
    FrontendApplicationBase::handleTickEvent();
}
