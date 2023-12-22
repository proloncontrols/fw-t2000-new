#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <BitmapDatabase.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <Gauge/CGaugeExterior.hpp>
#include <Gauge/CGaugeInterior.hpp>
#include <Gauge/CGaugeSetpoint.hpp>
#include <Gauge/CGaugeHumidity.hpp>
#include <CLabel.hpp>
#include <CImage.hpp>
#include <CButton.hpp>
#include <CString.hpp>
#include <Screen/CScreen.hpp>
#include <Menu/CMenu.hpp>
//#include <Menu/CMenuItem.hpp>
#include <Menu/CMenuSettings.hpp>

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
//    CGaugeInterior tempInt;
//    CGaugeSetpoint tempSet;
//    CGaugeExterior tempExt;
//    CGaugeHumidity hum;
//
//    CButton btn;
//
//    CScreen screen = CScreen(container);
//
//    CMenuSettings menu = CMenuSettings(container, buttonCallback);
//
    CMenuSettings menu = CMenuSettings(container, buttonCallback);
//
//    CImage img; // = CImage(BITMAP_MENU_LINE_GRAY_494X494X3_ID);





//    CImage img;
//    Box box;
//    Container container2;
//    Box box2;
//
//    CString str;

//    CLabel lbl;

//    CButton btn;

private:
    touchgfx::Callback<SplashView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // SPLASHVIEW_HPP
