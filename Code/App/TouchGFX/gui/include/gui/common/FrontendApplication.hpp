#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include <Screen/CScreen.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
	FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

//    void gotoSetpointsScreenNoTransition();

//    void gotoSettingsScreenNoTransition();

    void gotoScreen(ScreenId nextScreen);

//    void gotoOptionsScreenNoTransition();
//    void gotoAboutMeScreenNoTransition();
//    void gotoVisualizeScreenNoTransition();
//    void gotoDeviceScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

private:
//    void gotoSetpointsScreenNoTransitionImpl();

//    void gotoSettingsScreenNoTransitionImpl();

//    void gotoHomeScreenNoTransitionImpl();

    //Home screen
    void gotoSettingsScreenNoTransitionImpl();

    //Settings screen
    void gotoOptionsScreenNoTransitionImpl();
    void gotoAboutmeScreenNoTransitionImpl();
    void gotoVisualizeScreenNoTransitionImpl();
    void gotoDeviceScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATION_HPP
