#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <gui_generated/home_screen/HomeViewBase.hpp>
#include <gui/home_screen/HomePresenter.hpp>
#include <Screen/CScreenHome.hpp>

class HomeView : public HomeViewBase
{
    CScreenHome screen = CScreenHome(container, buttonCallback);
    Callback<HomeView, const AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const AbstractButtonContainer& src);

public:
    HomeView();
    virtual ~HomeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
};

#endif // HOMEVIEW_HPP
