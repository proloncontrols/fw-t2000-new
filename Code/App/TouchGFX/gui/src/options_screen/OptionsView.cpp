#include <gui/options_screen/OptionsView.hpp>

OptionsView::OptionsView()
            :buttonCallback(this, &OptionsView::buttonCallbackHandler)
{

}

void OptionsView::setupScreen()
{
    OptionsViewBase::setupScreen();
}

void OptionsView::tearDownScreen()
{
    OptionsViewBase::tearDownScreen();
}

void OptionsView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
//	application().gotoSettingsScreenNoTransition();
}
