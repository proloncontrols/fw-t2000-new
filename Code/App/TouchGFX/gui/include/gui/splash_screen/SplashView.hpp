#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <Gauge/CGaugeExterior.hpp>
#include <Gauge/CGaugeInterior.hpp>
#include <Gauge/CGaugeSetpoint.hpp>
#include <Gauge/CGaugeHumidity.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void moveIt();

protected:
    CGaugeInterior tempInt = CGaugeInterior();
    CGaugeSetpoint tempSet = CGaugeSetpoint();
    CGaugeExterior tempExt = CGaugeExterior();
    CGaugeHumidity hum = CGaugeHumidity();
};

#endif // SPLASHVIEW_HPP
