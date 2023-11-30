#include <gui/containers/SetpointHeat.hpp>
#include <BitmapDatabase.hpp>

SetpointHeat::SetpointHeat()
             :buttonCallback(this, &SetpointHeat::onButtonClick)
{
    home.initialize(0, 0, 0, BITMAP_HOME_ID, BITMAP_HOME_ID);
    home.setAction(buttonCallback);
	container1.add(home);

    logo.setBitmap(BITMAP_PROLON_176X176_ID);
	logo.setXY((container1.getWidth() - logo.getBitmap().getWidth()) / 2 , 0);
	container1.add(logo);

    minus.setBitmap(BITMAP_MINUS_ID);
    minus.setXY(20, 295);
	container1.add(minus);

    plus.setBitmap(BITMAP_PLUS_ID);
    plus.setXY(568, 295);
	container1.add(plus);

    flame.setBitmap(BITMAP_FLAMME_ID);
    flame.setXY((container1.getWidth() - flame.getBitmap().getWidth()) / 2 , 520);
	container1.add(flame);
}

void SetpointHeat::initialize()
{
    SetpointHeatBase::initialize();
}

void SetpointHeat::onButtonClick(const touchgfx::AbstractButtonContainer& src)
{
	application().gotoHomeScreenNoTransition();
}
