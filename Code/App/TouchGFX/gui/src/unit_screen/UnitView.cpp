#include <gui/unit_screen/UnitView.hpp>

UnitView::UnitView()
         :buttonCallback(this, &UnitView::onButtonClicked)
{

}

void UnitView::setupScreen()
{
    UnitViewBase::setupScreen();
}

void UnitView::tearDownScreen()
{
    UnitViewBase::tearDownScreen();
}

void UnitView::onButtonClicked(uint32_t param1, uint32_t param2)
{
//	ButtonId id = menu.getButtonId(src);
//
//	if(id == ButtonId::ButtonHome)
//		application().gotoScreen(ScreenId::ScreenHome);
//
//	else if(id == ButtonId::ButtonBack)
//		application().gotoScreen(menu.previous);
//
//	else
//	{
//	}
}
