#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <CCanvas.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>



class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnTransitionEnd();

protected:
    CCanvas canvas = CCanvas(container);
};

#endif // SPLASHVIEW_HPP
