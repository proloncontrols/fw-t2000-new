#include <gui/aboutme_screen/AboutMeView.hpp>

AboutMeView::AboutMeView()
            :buttonCallback(this, &AboutMeView::buttonCallbackHandler)
{

}

void AboutMeView::setupScreen()
{
    AboutMeViewBase::setupScreen();
}

void AboutMeView::tearDownScreen()
{
    AboutMeViewBase::tearDownScreen();
}

void AboutMeView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	application().gotoSettingsScreenNoTransition();
}
