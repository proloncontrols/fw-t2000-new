#include <gui/orientation_screen/OrientationView.hpp>

OrientationView::OrientationView()
                :buttonCallback(this, &OrientationView::onButtonClicked)
{

}

void OrientationView::setupScreen()
{
    OrientationViewBase::setupScreen();
}

void OrientationView::tearDownScreen()
{
    OrientationViewBase::tearDownScreen();
}

void OrientationView::onButtonClicked(const touchgfx::AbstractButtonContainer& src)
{
	ButtonId id = menu.getButtonId(src);

	if(id == ButtonId::ButtonHome)
		application().gotoScreen(ScreenId::ScreenHome);

	else if(id == ButtonId::ButtonBack)
		application().gotoScreen(menu.previous);

	else
	{
	}
}
