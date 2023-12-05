#ifndef SPLASHVIEW_HPP
#define SPLASHVIEW_HPP

#include <Screen/CScreen.hpp>
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

protected:
//    CScreen screen = CScreen(container, true);
    CScreen* screen;

private:
    touchgfx::Callback<SplashView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClick(const touchgfx::AbstractButtonContainer& src);
};

#endif // SPLASHVIEW_HPP
