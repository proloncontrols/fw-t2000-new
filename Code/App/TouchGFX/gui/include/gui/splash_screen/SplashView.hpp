#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <CScreenLogo.hpp>
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <touchgfx/Containers/Buttons/AbstractButtonContainer.hpp>



class SplashView : public SplashViewBase
{
public:
    SplashView();
    virtual ~SplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnTransitionEnd();

protected:
    CScreenLogo screen = CScreenLogo(container);

private:
    touchgfx::Callback<SplashView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClick(const touchgfx::AbstractButtonContainer& src);
};

#endif // SPLASHVIEW_HPP
