#include <gui/containers/containerSplash.hpp>
#include <touchgfx/Color.hpp>

containerSplash::containerSplash()
{
    flexButton2.setBoxWithBorderPosition(0, 0, 170, 60);
    flexButton2.setBorderSize(0);
    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton2.setPosition(170, 336, 170, 60);
    flexButton2.setAction(flexButtonCallback);

    add(flexButton2);

	widgets = new CWidgets(splashCount);

	widgets->set(splashImageProlon, new CImage(imageProlon));
	widgets->set(splashTextNewText, new CText(textNewText));
//	widgets->set(splashButton1,     new CButton(flexButton1));

	widgets->position();
}

void containerSplash::initialize()
{
    containerSplashBase::initialize();
}
