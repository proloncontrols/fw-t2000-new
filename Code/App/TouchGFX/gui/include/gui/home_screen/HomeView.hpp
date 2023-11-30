#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <gui_generated/home_screen/HomeViewBase.hpp>
#include <gui/home_screen/HomePresenter.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <CImage.hpp>
#include <CButton.hpp>
#include <Meter/CMeterInt.hpp>
#include <Meter/CMeterExt.hpp>
#include <Meter/CMeterHum.hpp>

class HomeView : public HomeViewBase
{
public:
    HomeView();
    virtual ~HomeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    Container container;
    touchgfx::Box background;
    CImage logo;
    CImage statusImage;
    CImage statusIcon;
    CImage occupency;
    CButton settings;
    CButton setpoints;
    CMeterInt meterInt;
    CMeterExt meterExt;
    CMeterHum meterHum;

private:
    touchgfx::Callback<HomeView, const touchgfx::AbstractButtonContainer&> menuButtonCallback;
    void onMenuButtonClick(const touchgfx::AbstractButtonContainer& src);
};

#endif // HOMEVIEW_HPP
