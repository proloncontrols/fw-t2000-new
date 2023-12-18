#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <Gauge/CGaugeExterior.hpp>
#include <Gauge/CGaugeInterior.hpp>
#include <Gauge/CGaugeSetpoint.hpp>
#include <Gauge/CGaugeHumidity.hpp>
#include <CButton.hpp>

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateEnvironment(ENV_Readings_t* Env);
    virtual void moveIt();

protected:
    CGaugeInterior tempInt;
    CGaugeSetpoint tempSet;
    CGaugeExterior tempExt;
    CGaugeHumidity hum;

    CButton btn;

private:
    touchgfx::Callback<SplashView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // SPLASHVIEW_HPP
