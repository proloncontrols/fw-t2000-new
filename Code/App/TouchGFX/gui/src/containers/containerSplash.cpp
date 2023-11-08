
#include <gui/containers/containerSplash.hpp>


containerSplash::containerSplash()
	: buttonCallback(this, &containerSplash::buttonCallbackHandler)
{
	button = new CButtonCustom(400, 550, 200, 50, &textureMapper1, &textureMapper2);
    button->setAction(buttonCallback);
    add(*button);

	widgets = new CWidgets(splashCount);
	widgets->set(splashImageProlon, new CImage(imageProlon));
	widgets->set(splashTextNewText, new CText(textNewText));
	widgets->set(splashButton,      new CButton(*button));
	widgets->position();
}

void containerSplash::initialize()
{
    containerSplashBase::initialize();
}

void containerSplash::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if(&src == button)
    {
    }
}
