#ifndef RESETVIEW_HPP
#define RESETVIEW_HPP

#include <gui_generated/reset_screen/ResetViewBase.hpp>
#include <gui/reset_screen/ResetPresenter.hpp>

class ResetView : public ResetViewBase
{
public:
    ResetView();
    virtual ~ResetView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnScreenTransitionEnd();

protected:
};

#endif // RESETVIEW_HPP
