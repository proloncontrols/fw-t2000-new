#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <CSwipeContainer.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
//#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
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

//    virtual void handleClickEvent(const ClickEvent& evt);

protected:
    CWidgets* Widgets;

    CSwipeContainer* swipeContainer11;
    touchgfx::Container swipeContainer1Page1;
    touchgfx::Box box1;
    touchgfx::Container swipeContainer1Page2;
    touchgfx::Box box2;
};

#endif // SPLASHVIEW_HPP
