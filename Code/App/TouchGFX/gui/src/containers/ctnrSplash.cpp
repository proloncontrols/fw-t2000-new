#include <gui/containers/ctnrSplash.hpp>

ctnrSplash::ctnrSplash()
	: buttonCallback(this, &ctnrSplash::buttonCallbackHandler)
{
	button = new CButtonCustom(400, 550, 200, 50, &textureMapper1, &textureMapper2);
    button->setAction(buttonCallback);
    add(*button);

	widgets = new CWidgets(splashCount, (Rotation)CFG.Dta.ScrOrientation);
	widgets->set(splashImageProlon, new CImage(imageProlon));
	widgets->set(splashTextNewText, new CText(textNewText));
	widgets->set(splashButton, new CButton(*button));
	widgets->position();
}

void ctnrSplash::initialize()
{
    ctnrSplashBase::initialize();
}

void ctnrSplash::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if(&src == button)
    {
    }
}
