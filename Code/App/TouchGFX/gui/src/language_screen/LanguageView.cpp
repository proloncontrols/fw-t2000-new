#include <gui/language_screen/LanguageView.hpp>

LanguageView::LanguageView()
             :buttonCallback(this, &LanguageView::onButtonClicked)
{

}

void LanguageView::setupScreen()
{
    LanguageViewBase::setupScreen();
}

void LanguageView::tearDownScreen()
{
	LanguageViewBase::tearDownScreen();
}

void LanguageView::onButtonClicked(const touchgfx::AbstractButtonContainer& src)
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
