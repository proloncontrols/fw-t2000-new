#include <gui/containers/containerSplash.hpp>
#include <touchgfx/Color.hpp>

containerSplash::containerSplash()
{
	flexButton2 = new CButtonCustom(170, 336, 200, 50, &textureMapper1, &textureMapper2);

//	flexButton2.setAlpha(127);
//    flexButton2.setBoxWithBorderPosition(0, 0, 200, 50);
//    flexButton2.setBorderSize(0);
//    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
//    flexButton2.setPosition(170, 336, 200, 50);
//    flexButton2.setImages(&textureMapper1, &textureMapper2);
//    flexButton2.setAction(flexButtonCallback);
    flexButton2->setAction(flexButtonCallback);

    add(*flexButton2);

	widgets = new CWidgets(splashCount);

	widgets->set(splashImageProlon, new CImage(imageProlon));
	widgets->set(splashTextNewText, new CText(textNewText));
	widgets->set(splashButton2,     new CButton(*flexButton2));

	widgets->position();
}

void containerSplash::initialize()
{
    containerSplashBase::initialize();
}
