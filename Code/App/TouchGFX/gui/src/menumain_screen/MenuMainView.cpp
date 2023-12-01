#include <gui/menumain_screen/MenuMainView.hpp>
#include <touchgfx/Color.hpp>
#include <CScreen.hpp>

MenuMainView::MenuMainView()
             :menuButtonCallback(this, &MenuMainView::onMenuButtonClick)
{
//    __background.setColor(touchgfx::Color::getColorFromRGB(35, 35, 35));

    menuItems[0].setText((char*)"Options");
    menuItems[1].setText((char*)"About me");
    menuItems[2].setText((char*)"Visualize");
    menuItems[3].setText((char*)"Device");

    menu = new CMenu((char*)"Menu", false, menuItems, menuItemsCount, menuButtonCallback);
//    menu->setXY(convertScreenX(24), convertScreenY(24));

    add(*menu);
}

void MenuMainView::setupScreen()
{
    MenuMainViewBase::setupScreen();
}

void MenuMainView::tearDownScreen()
{
    MenuMainViewBase::tearDownScreen();
}

void MenuMainView::onMenuButtonClick(const touchgfx::AbstractButtonContainer& src)
{
//	ButtonId button = menu->getButtonId(src);

//	if(button == buttonHome)
//		application().gotoHomeScreenNoTransition();
}
