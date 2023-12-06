#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <Screen/CScreen.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CScreen* screen;
};

#endif // SPLASHVIEW_HPP
