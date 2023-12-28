#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <gui_generated/home_screen/HomeViewBase.hpp>
#include <gui/home_screen/HomePresenter.hpp>
#include <Screen/CScreenHome.hpp>

class HomeView : public HomeViewBase
{
    Callback<HomeView, const AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const AbstractButtonContainer& src);

protected:
    CScreenHome screen = CScreenHome(container, buttonCallback);

public:
    HomeView();
    virtual ~HomeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
};

#endif // HOMEVIEW_HPP
