#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <gui_generated/settings_screen/SettingsViewBase.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>
#include <Menu/CMenuSettings.hpp>

class SettingsView : public SettingsViewBase
{
public:
    touchgfx::Callback<SettingsView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

protected:
    CMenuSettings menu = CMenuSettings(container, buttonCallback);

public:
    SettingsView();
    virtual ~SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
};

#endif // SETTINGSVIEW_HPP
