#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <CSwipe.hpp>
#include <CImage.hpp>
#include <CMeterTempInt.hpp>
#include <CMeterTempExt.hpp>
#include <CScreen.hpp>
//#include <gui/containers/cntBlue.hpp>
//#include <gui/containers/cntTempInside.hpp>


class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    touchgfx::Box client;
    CSwipe swipe;

    CSwipePage swipePage1;
//    touchgfx::Box box1;

    CSwipePage swipePage2;
//    touchgfx::Box box2;

    CSwipePage swipePage3;

//    touchgfx::Box box3;
//    touchgfx::Box box4;

//    CImage img1;
    CImage img2;
    CImage img3;

//    cntBlue Blue;
//    cntTempInside tempInside;

    CMeterTempInt MeterTempInt;
    CMeterTempExt MeterTempExt;
};

#endif // SPLASHVIEW_HPP
