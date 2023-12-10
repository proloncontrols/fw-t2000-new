#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <Screen/CScreen.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

#include <CText.hpp>
#include <texts/TextKeysAndLanguages.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
//    CScreen* screen;

    CText txt1 = CText(T_MENU_BUTTON, 255, 255, 255);
//    CText txt2 = CText(1);
//    CText txt3 = CText(1);

//    CGaugeDigit* md1;
//    CGaugeValue* gv1;

    CDigit dig = CDigit(T_METER_HUGE, 255, 255, 255);
    CValue* val;
};

#endif // SPLASHVIEW_HPP
