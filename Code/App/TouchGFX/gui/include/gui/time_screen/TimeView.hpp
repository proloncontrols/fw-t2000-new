#ifndef TIMEVIEW_HPP
#define TIMEVIEW_HPP

#include <gui_generated/time_screen/TimeViewBase.hpp>
#include <gui/time_screen/TimePresenter.hpp>
#include <Menu/Settings/CMenuTime.hpp>

class TimeView : public TimeViewBase
{
    CMenuTime menu = CMenuTime(container, buttonCallback);
    touchgfx::Callback<TimeView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

public:
    TimeView();
    virtual ~TimeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TIMEVIEW_HPP
