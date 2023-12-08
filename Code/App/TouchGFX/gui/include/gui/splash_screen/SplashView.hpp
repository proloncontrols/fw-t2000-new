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

//    CText txt1 = CText(1);
//    CText txt2 = CText(1);
//    CText txt3 = CText(1);

    CMeterDigit* md1;
};

#endif // SPLASHVIEW_HPP
