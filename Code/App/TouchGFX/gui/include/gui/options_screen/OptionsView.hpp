#ifndef OPTIONSVIEW_HPP
#define OPTIONSVIEW_HPP

#include <gui_generated/options_screen/OptionsViewBase.hpp>
#include <gui/options_screen/OptionsPresenter.hpp>
#include <Menu/Settings/CMenuOptions.hpp>

class OptionsView : public OptionsViewBase
{
    CMenuOptions menu = CMenuOptions(container, buttonCallback);
    touchgfx::Callback<OptionsView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

public:
    OptionsView();
    virtual ~OptionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
};

#endif // OPTIONSVIEW_HPP
