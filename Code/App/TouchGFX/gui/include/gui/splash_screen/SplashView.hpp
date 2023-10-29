#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

#include "widget.hpp"
#include "widgets.hpp"

enum splashWidgets
{
	splashImgProlon,
	splashCount
};

class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnScreenTransitionEnd();

protected:
    CWidgets* Widgets;
};

#endif // SPLASHVIEW_HPP
