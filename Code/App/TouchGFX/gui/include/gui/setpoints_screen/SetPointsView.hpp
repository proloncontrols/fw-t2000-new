#ifndef SETPOINTSVIEW_HPP
#define SETPOINTSVIEW_HPP

#include <gui_generated/setpoints_screen/SetPointsViewBase.hpp>
#include <gui/setpoints_screen/SetPointsPresenter.hpp>

class SetPointsView : public SetPointsViewBase
{
public:
    SetPointsView();
    virtual ~SetPointsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETPOINTSVIEW_HPP
