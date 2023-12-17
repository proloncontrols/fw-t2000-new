#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

//#include <CText.hpp>
//#include <CString.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <Gauge/CGaugeTemperatureInterior.hpp>
//#include <texts/TextKeysAndLanguages.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void moveIt();

protected:
//    CText txt1 = CText(4, 15, T_GAUGE_DIGITS_INTEGER_HUGE, 255, 255, 255);
//    CText txt2 = CText(3, 15, T_GAUGE_DIGITS_DECIMAL_MEDIUM, 255, 255, 255);

//    CString str = CString(T_MENU_BUTTON, 255, 255, 255);

    CGaugeTemperatureInterior tempInt = CGaugeTemperatureInterior();

//    CText::CDigit dig1 = CText::CDigit(T_GAUGE_DIGITS_INTEGER_HUGE, 255, 255, 255);
};

#endif // SPLASHVIEW_HPP
