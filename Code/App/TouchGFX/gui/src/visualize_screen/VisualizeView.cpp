#include <gui/visualize_screen/VisualizeView.hpp>

VisualizeView::VisualizeView()
              :buttonCallback(this, &VisualizeView::buttonCallbackHandler)
{

}

void VisualizeView::setupScreen()
{
    VisualizeViewBase::setupScreen();
}

void VisualizeView::tearDownScreen()
{
    VisualizeViewBase::tearDownScreen();
}

void VisualizeView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	application().gotoSettingsScreenNoTransition();
}
