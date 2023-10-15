#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include "ui.h"

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
	UI_Screen_t Screen;
//	UI_Action_t Action;

    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

    // Reset
    void gotoResetScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

    // Reset
    void gotoResetScreenNoTransitionImpl();

private:
};

#endif // FRONTENDAPPLICATION_HPP
