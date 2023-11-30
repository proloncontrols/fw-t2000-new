/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETPOINTSVIEWBASE_HPP
#define SETPOINTSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/setpoints_screen/SetPointsPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <gui/containers/SetpointCool.hpp>
#include <gui/containers/SetpointHeat.hpp>

class SetPointsViewBase : public touchgfx::View<SetPointsPresenter>
{
public:
    SetPointsViewBase();
    virtual ~SetPointsViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::SwipeContainer swipeContainer1;
    touchgfx::Container swipeContainer1Page1;
    SetpointCool setpointCool1;
    touchgfx::Container swipeContainer1Page2;
    SetpointHeat setpointHeat1;

private:

};

#endif // SETPOINTSVIEWBASE_HPP