#ifndef ABOUTMEVIEW_HPP
#define ABOUTMEVIEW_HPP

#include <gui_generated/aboutme_screen/AboutMeViewBase.hpp>
#include <gui/aboutme_screen/AboutMePresenter.hpp>

#include <Menu/Aboutme/CMenuAboutme.hpp>

class AboutmeView : public AboutmeViewBase
{
public:
    AboutmeView();
    virtual ~AboutmeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuAboutme menu = CMenuAboutme(container, buttonCallback);

private:
    touchgfx::Callback<AboutmeView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // ABOUTMEVIEW_HPP
