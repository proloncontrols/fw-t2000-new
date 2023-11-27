#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

//#include <CSwipe.hpp>
//#include <CImage.hpp>
//#include <CScreen.hpp>
//#include <CMeterInt.hpp>
//#include <CMeterSet.hpp>
//#include <CMeterExt.hpp>
//#include <CMeterHum.hpp>
#include <CButton.hpp>


class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnTransitionEnd();

protected:
//    touchgfx::Box client;
//    CSwipe swipe;
//
//    CSwipePage swipePage1;
////    touchgfx::Box box1;
//
//    CSwipePage swipePage2;
////    touchgfx::Box box2;
//
//    CSwipePage swipePage3;
//
////    touchgfx::Box box3;
////    touchgfx::Box box4;
//
////    CImage img1;
//    CImage img2;
//    CImage img3;
//
////    cntBlue Blue;
////    cntTempInside tempInside;
//
//    CMeterInt m1;
//    CMeterSet m2;
//    CMeterExt m3;
//    CMeterHum m4;

    CButton b1;
//    CButton b2;

private:
//    touchgfx::Callback<SplashView, const touchgfx::AbstractButton&> buttonCallback;
//    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    touchgfx::Callback<SplashView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // SPLASHVIEW_HPP
