#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

#include "widget.hpp"

#define  SPLASH_WIDGET_COUNT   1

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnScreenTransitionEnd();

protected:
    CWidget* List[SPLASH_WIDGET_COUNT];

private:
    void updateScreen();
};

#endif // SPLASHVIEW_HPP
