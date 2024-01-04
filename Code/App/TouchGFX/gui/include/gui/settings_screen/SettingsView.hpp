#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <gui_generated/settings_screen/SettingsViewBase.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>
#include <Menu/Settings/CMenuSettings.hpp>

class SettingsView : public SettingsViewBase
{
    CMenuSettings menu = CMenuSettings(container, buttonCallback);

//    touchgfx::Callback<SettingsView, const touchgfx::AbstractButtonContainer&> buttonCallback;
//    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);
//    touchgfx::Callback<SettingsView, ScreenId> buttonCallback;
    touchgfx::Callback<SettingsView, uint32_t, uint32_t> buttonCallback;
//    void onButtonClicked(ScreenId id)

public:
    SettingsView();
    virtual ~SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void onButtonClicked(uint32_t param1, uint32_t param2);
};

#endif // SETTINGSVIEW_HPP
