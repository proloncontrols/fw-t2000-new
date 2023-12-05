#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <gui_generated/home_screen/HomeViewBase.hpp>
#include <gui/home_screen/HomePresenter.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <CImage.hpp>
#include <CButton.hpp>
#include <Screen/CScreenHome.hpp>

class HomeView : public HomeViewBase
{
public:
    HomeView();
    virtual ~HomeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
//    CScreenHome screen = CScreenHome(container);
    CScreenHome* screen;

private:
    touchgfx::Callback<HomeView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClick(const touchgfx::AbstractButtonContainer& src);
};

#endif // HOMEVIEW_HPP
