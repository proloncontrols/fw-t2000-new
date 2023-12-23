#ifndef OPTIONSVIEW_HPP
#define OPTIONSVIEW_HPP

#include <gui_generated/options_screen/OptionsViewBase.hpp>
#include <gui/options_screen/OptionsPresenter.hpp>

#include <Menu/CMenuOptions.hpp>

class OptionsView : public OptionsViewBase
{
public:
    OptionsView();
    virtual ~OptionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuOptions menu = CMenuOptions(container, buttonCallback);

private:
    touchgfx::Callback<OptionsView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // OPTIONSVIEW_HPP
