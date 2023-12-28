#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include <Screen/CScreen.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
    //Home screen
    void gotoSettingsScreenNoTransitionImpl();

    //Settings screen
    void gotoOptionsScreenNoTransitionImpl();
    void gotoAboutmeScreenNoTransitionImpl();
    void gotoVisualizeScreenNoTransitionImpl();
    void gotoDeviceScreenNoTransitionImpl();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

public:
	FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

    void gotoScreen(ScreenId nextScreen);
};

#endif // FRONTENDAPPLICATION_HPP
