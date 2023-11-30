#ifndef MENUMAINVIEW_HPP
#define MENUMAINVIEW_HPP

#include <gui_generated/menumain_screen/MenuMainViewBase.hpp>
#include <gui/menumain_screen/MenuMainPresenter.hpp>
#include <Menu/CMenu.hpp>

class MenuMainView : public MenuMainViewBase
{
public:
    MenuMainView();
    virtual ~MenuMainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    static const int menuItemsCount = 4;

    CMenu* menu;
    CMenuItem menuItems[menuItemsCount];

private:
    touchgfx::Callback<MenuMainView, const touchgfx::AbstractButtonContainer&> menuButtonCallback;
    void onMenuButtonClick(const touchgfx::AbstractButtonContainer& src);
};

#endif // MENUMAINVIEW_HPP
