#ifndef UNITVIEW_HPP
#define UNITVIEW_HPP

#include <gui_generated/unit_screen/UnitViewBase.hpp>
#include <gui/unit_screen/UnitPresenter.hpp>
#include <Menu/Settings/CMenuUnit.hpp>

class UnitView : public UnitViewBase
{
	int programmedSelection;

    CMenuUnit menu = CMenuUnit(container, buttonCallback);
    touchgfx::Callback<UnitView, uint32_t, uint32_t> buttonCallback;
    void onButtonClicked(uint32_t, uint32_t);

public:
    UnitView();
    virtual ~UnitView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // UNITVIEW_HPP
