#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include "ui.h"

#define CLIENT_ORIGIN_LANDSCAPE_X   24
#define CLIENT_ORIGIN_LANDSCAPE_Y   0
#define CLIENT_ORIGIN_PORTRAIT_X    0
#define CLIENT_ORIGIN_PORTRAIT_Y    24
#define CLIENT_WIDTH                672
#define CLIENT_HEIGHT               672

typedef enum {
	SCREEN_LANDSCAPE,
	SCREEN_PORTRAIT
} ScreenOrientation;

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
	int16_t originX;
	int16_t originY;
	ScreenOrientation orientation;

	UI_Screen_t Screen;

    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

private:
};

#endif // FRONTENDAPPLICATION_HPP
