#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <CSwipe.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>

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
    touchgfx::Box box1;

    CSwipePage swipePage2;
    touchgfx::Box box2;

    touchgfx::Box box3;
    touchgfx::Box box4;

    TextureMapper textureMapper1;
};

#endif // SPLASHVIEW_HPP
