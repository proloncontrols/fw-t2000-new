#ifndef CLEARVIEW_HPP
#define CLEARVIEW_HPP

#include <gui_generated/clear_screen/ClearViewBase.hpp>
#include <gui/clear_screen/ClearPresenter.hpp>

class ClearView : public ClearViewBase
{
public:
    ClearView();
    virtual ~ClearView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CLEARVIEW_HPP
