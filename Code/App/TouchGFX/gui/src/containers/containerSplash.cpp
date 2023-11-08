#include <gui/containers/containerSplash.hpp>
#include <touchgfx/Color.hpp>

containerSplash::containerSplash()
{
	Button = new CButtonCustom(400, 550, 200, 50, &textureMapper1, &textureMapper2);
    Button->setAction(ButtonCallback);

    add(*Button);

	widgets = new CWidgets(splashCount);

	widgets->set(splashImageProlon, new CImage(imageProlon));
	widgets->set(splashTextNewText, new CText(textNewText));
	widgets->set(splashButton,      new CButton(*Button));

	widgets->position();
}

void containerSplash::initialize()
{
    containerSplashBase::initialize();
}
