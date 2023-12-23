#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <gui_generated/settings_screen/SettingsViewBase.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>

#include <Menu/CMenuSettings.hpp>

class SettingsView : public SettingsViewBase
{
public:
    SettingsView();
    virtual ~SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuSettings menu = CMenuSettings(container, buttonCallback);

private:
    touchgfx::Callback<SettingsView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // SETTINGSVIEW_HPP
