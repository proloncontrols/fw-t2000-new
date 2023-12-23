#include <gui/device_screen/DeviceView.hpp>

DeviceView::DeviceView()
           :buttonCallback(this, &DeviceView::buttonCallbackHandler)
{

}

void DeviceView::setupScreen()
{
    DeviceViewBase::setupScreen();
}

void DeviceView::tearDownScreen()
{
    DeviceViewBase::tearDownScreen();
}

void DeviceView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
//	application().gotoSettingsScreenNoTransition();
}
