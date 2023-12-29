#include <gui/aboutme_screen/AboutMeView.hpp>

AboutmeView::AboutmeView()
            :buttonCallback(this, &AboutmeView::buttonCallbackHandler)
{

}

void AboutmeView::setupScreen()
{
    AboutmeViewBase::setupScreen();
}

void AboutmeView::tearDownScreen()
{
    AboutmeViewBase::tearDownScreen();
}

void AboutmeView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
//	application().gotoSettingsScreenNoTransition();
}
