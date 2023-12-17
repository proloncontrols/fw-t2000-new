#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

//#include <CText.hpp>
//#include <CString.hpp>
//#include <CLabel.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
#include <Gauge/CGaugeTemperatureInterior.hpp>
#include <Gauge/CGaugeTemperatureSetpoint.hpp>
#include <Gauge/CGaugeTemperatureExterior.hpp>

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

//    CLabel lbl1 = CLabel(T_GAUGE_UNIT_C_SMALL, 255, 255, 255);

    CGaugeTemperatureInterior tempInt = CGaugeTemperatureInterior();

    CGaugeTemperatureSetpoint tempSet = CGaugeTemperatureSetpoint();

    CGaugeTemperatureExterior tempExt = CGaugeTemperatureExterior();

//    CText::CDigit dig1 = CText::CDigit(T_GAUGE_DIGITS_INTEGER_HUGE, 255, 255, 255);
};

#endif // SPLASHVIEW_HPP
