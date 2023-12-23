#ifndef ABOUTMEVIEW_HPP
#define ABOUTMEVIEW_HPP

#include <gui_generated/aboutme_screen/AboutMeViewBase.hpp>
#include <gui/aboutme_screen/AboutMePresenter.hpp>

#include <Menu/CMenuAboutMe.hpp>

class AboutMeView : public AboutMeViewBase
{
public:
    AboutMeView();
    virtual ~AboutMeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuAboutMe menu = CMenuAboutMe(container, buttonCallback);

private:
    touchgfx::Callback<AboutMeView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // ABOUTMEVIEW_HPP
