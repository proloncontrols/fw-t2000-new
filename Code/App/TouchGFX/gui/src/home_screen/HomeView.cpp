#include <gui/home_screen/HomeView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <CScreen.hpp>

HomeView::HomeView()
         :menuButtonCallback(this, &HomeView::onMenuButtonClick)
{
//	__background.setColor(touchgfx::Color::getColorFromRGB(35, 35, 35));

//    container.setPosition(convertScreenX(24), convertScreenY(24), 624, 624);
    add(container);

	background.setPosition(0, 0, container.getWidth(), container.getHeight());
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	container.add(background);

	logo.setBitmap(Bitmap(BITMAP_PROLON_176X176_ID));
	logo.setXY((container.getWidth() / 2) - (logo.getWidth() / 2), 0);
	container.add(logo);

	statusImage.setBitmap(Bitmap(BITMAP_COOLINGON_ID));
	statusImage.setXY((container.getWidth() / 2) - (statusImage.getWidth() / 2), 24);
	container.add(statusImage);

	statusIcon.setBitmap(Bitmap(BITMAP_SNOWFLAKE_ID));
	statusIcon.setXY((container.getWidth() / 2) - (statusIcon.getWidth() / 2), 430);
	container.add(statusIcon);

	meterInt.display(21.5, true);
	meterInt.setXY((container.getWidth() / 2) - (meterInt.getWidth() / 2), 130);
	container.add(meterInt);

    settings.initialize(container.getWidth() - Bitmap(BITMAP_SETTING_ID).getWidth(), 0, 0, BITMAP_SETTING_ID, BITMAP_SETTING_DARK2_ID);
    settings.setAction(menuButtonCallback);
    container.add(settings);

	meterExt.display(19, true);
	meterExt.setXY(0, 0);
	container.add(meterExt);

	meterHum.display(45);
	meterHum.setXY(0, container.getHeight() - meterHum.getHeight());
	container.add(meterHum);

	occupency.setBitmap(Bitmap(BITMAP_STANDBYMODE_ID));
	occupency.setXY(container.getWidth() - occupency.getWidth(), container.getHeight() - occupency.getHeight());
	container.add(occupency);

    setpoints.initialize(statusImage.getX(), statusImage.getY(), statusImage.getWidth(), statusImage.getHeight());
    setpoints.setAction(menuButtonCallback);
    container.add(setpoints);
}

void HomeView::setupScreen()
{
    HomeViewBase::setupScreen();
}

void HomeView::tearDownScreen()
{
    HomeViewBase::tearDownScreen();
}

void HomeView::onMenuButtonClick(const touchgfx::AbstractButtonContainer& src)
{
	if(&src == &settings)
		application().gotoMenuMainScreenNoTransition();

	if(&src == &setpoints)
		application().gotoSetpointsScreenNoTransition();
}
