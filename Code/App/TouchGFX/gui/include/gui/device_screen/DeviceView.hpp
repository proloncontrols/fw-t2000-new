#ifndef DEVICEVIEW_HPP
#define DEVICEVIEW_HPP

#include <gui_generated/device_screen/DeviceViewBase.hpp>
#include <gui/device_screen/DevicePresenter.hpp>

#include <Menu/Device/CMenuDevice.hpp>

class DeviceView : public DeviceViewBase
{
public:
    DeviceView();
    virtual ~DeviceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuDevice menu = CMenuDevice(container, buttonCallback);

private:
    touchgfx::Callback<DeviceView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // DEVICEVIEW_HPP
