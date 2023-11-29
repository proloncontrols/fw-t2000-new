/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MENUMAINVIEWBASE_HPP
#define MENUMAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/menumain_screen/MenuMainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>

class MenuMainViewBase : public touchgfx::View<MenuMainPresenter>
{
public:
    MenuMainViewBase();
    virtual ~MenuMainViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }
    touchgfx::Box __background;

private:

};

#endif // MENUMAINVIEWBASE_HPP
