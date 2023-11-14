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

    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

private:
};

#endif // FRONTENDAPPLICATION_HPP
