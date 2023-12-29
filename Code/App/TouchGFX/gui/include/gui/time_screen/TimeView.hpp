#ifndef TIMEVIEW_HPP
#define TIMEVIEW_HPP

#include <gui_generated/time_screen/TimeViewBase.hpp>
#include <gui/time_screen/TimePresenter.hpp>

class TimeView : public TimeViewBase
{
public:
    TimeView();
    virtual ~TimeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TIMEVIEW_HPP
