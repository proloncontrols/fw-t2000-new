#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include <Screen/CScreen.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
	//From any screen, goto...:
    void gotoHomeScreenNoTransitionImpl();

	//From Home screen, goto...:
    void gotoSettingsScreenNoTransitionImpl();

    //From Settings screen, goto...:
    void gotoOptionsScreenNoTransitionImpl();
    void gotoAboutmeScreenNoTransitionImpl();
    void gotoVisualizeScreenNoTransitionImpl();
    void gotoDeviceScreenNoTransitionImpl();

    //From Options screen, goto...:
   	void gotoLanguageScreenNoTransitionImpl();
   	void gotoUnitScreenNoTransitionImpl();
   	void gotoTimeScreenNoTransitionImpl();
   	void gotoOrientationScreenNoTransitionImpl();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

public:
	FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

    void gotoScreen(ScreenId nextScreen);
};

#endif // FRONTENDAPPLICATION_HPP
