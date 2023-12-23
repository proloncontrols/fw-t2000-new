#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
	typedef enum {
		Home,
		Settings,
		Options,
		AboutMe,
		Visualize,
		Device
	} ScreenId;

	FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

//    void gotoSetpointsScreenNoTransition();

//    void gotoSettingsScreenNoTransition();

    void gotoScreen(ScreenId newScreen);

//    void gotoOptionsScreenNoTransition();
//    void gotoAboutMeScreenNoTransition();
//    void gotoVisualizeScreenNoTransition();
//    void gotoDeviceScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

private:
//    void gotoSetpointsScreenNoTransitionImpl();

//    void gotoSettingsScreenNoTransitionImpl();
    void gotoOptionsScreenNoTransitionImpl();
    void gotoAboutMeScreenNoTransitionImpl();
    void gotoVisualizeScreenNoTransitionImpl();
    void gotoDeviceScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATION_HPP
