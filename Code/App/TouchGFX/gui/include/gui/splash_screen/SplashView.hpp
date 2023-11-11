#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <CSwipe.hpp>
#include <CWidget.hpp>
#include <CWidgets.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <touchgfx/containers/Container.hpp>
#include <gui/containers/ctnrSplash.hpp>
#include <gui/containers/ctnrHome.hpp>
#include <gui/containers/containerBlue.hpp>
#include <gui/containers/containerRed.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}

    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void OnScreenTransitionEnd();

protected:
    CSwipe swipe;

//    touchgfx::Box back;
//    touchgfx::Container backPage;
//
//    touchgfx::Container splashPage;
//    touchgfx::Box splashPageBackground;
//
//    static const uint16_t TEXTAREA1_SIZE = 10;
//    touchgfx::TextAreaWithOneWildcard textArea1;
//    touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];







//    touchgfx::Box back2;
//    touchgfx::Container backPage2;

//    touchgfx::Container swipePageSplash;
//    ctnrSplash splash;
//
//    touchgfx::Container swipePageHome;
//    ctnrHome home;
//
//    touchgfx::Container swipePageBlue;
//    containerBlue blue;
//
//    touchgfx::Container swipePageRed;
//    containerRed red;
};

#endif // SPLASHVIEW_HPP
