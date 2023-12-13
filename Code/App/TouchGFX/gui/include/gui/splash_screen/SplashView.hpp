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

//    CText txt1 = CText(T_MENU_BUTTON, 255, 255, 255);
//    CText txt2 = CText(T_MENU_TITLE, 255, 255, 255);

//    CGaugeTemperature temp = CGaugeTemperature(4, T_GAUGE_HUGE, 2, T_GAUGE_MEDIUM, T_MENU_TITLE, 15, 255, 255, 255);

//    CDigit dig0 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig1 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig2 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig3 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig4 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig5 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig6 = CDigit(T_GAUGE_HUGE, 255, 255, 255);
//    CDigit dig3 = CDigit(T_GAUGE_MEDIUM, 255, 255, 255);

    CText txt1 = CText(4, 15, T_GAUGE_HUGE, 255, 255, 255);
    CText txt2 = CText(3, 15, T_TEMP_SMALL_C, 255, 255, 255);
    CText txt3 = CText(3, 15, T_GAUGE_MEDIUM, 255, 255, 255);

    CString str = CString(T_MENU_BUTTON, 255, 255, 255);
};

#endif // SPLASHVIEW_HPP
