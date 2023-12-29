#ifndef UNITVIEW_HPP
#define UNITVIEW_HPP

#include <gui_generated/unit_screen/UnitViewBase.hpp>
#include <gui/unit_screen/UnitPresenter.hpp>
#include <Menu/Settings/CMenuUnit.hpp>

class UnitView : public UnitViewBase
{
    CMenuUnit menu = CMenuUnit(container, buttonCallback);
    touchgfx::Callback<UnitView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

public:
    UnitView();
    virtual ~UnitView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // UNITVIEW_HPP
