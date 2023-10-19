#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <gui/reset_screen/ResetView.hpp>
#include <touchgfx/transitions/NoTransition.hpp>

#include <BitmapDatabase.hpp>

#include "framework.h"
#include "ui.h"
#include "cfg.h"

#define SCREEN_WIDTH      720
#define SCREEN_HEIGHT     672
#define SCREEN_ANGLE    (-1.572f)

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

void FrontendApplication::handleTickEvent()
{
	if(osMessageQueueGet(UI_QueueScreen, &Screen, NULL, 0) == osOK)
	{
		if(Screen.Name == UiScrSw)
		{
			if (Screen.ScreenSwitch.Id == UiScrIdReset)
				gotoResetScreenNoTransition();

			if (Screen.ScreenSwitch.Id == UiScrIdMain)
				gotoMainScreenNoTransition();
		}
	}

    model.tick();
    FrontendApplicationBase::handleTickEvent();
}





// Reset

void FrontendApplication::gotoResetScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoResetScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoResetScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ResetView, ResetPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Main

void FrontendApplication::gotoMainScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoMainScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoMainScreenNoTransitionImpl()
{
    touchgfx::makeTransition<MainView, MainPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}





static void FEA_GetRect270(touchgfx::Rect& Rect0)
{
	int NewX = Rect0.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                   //Becomes the Y coordinate of the rotated screen
	int NewWidth = Rect0.height;
	int NewY = SCREEN_HEIGHT - (Rect0.x + Rect0.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
	int NewHeight = Rect0.width;

	Rect0.x = NewX;             //Apply new 270 degrees parameters
	Rect0.y = NewY;             //
	Rect0.width = NewWidth;     //
	Rect0.height = NewHeight;   //
}

void FEA_PlaceText(touchgfx::TextArea& Text)
{
	if(CFG_Data.ScrOrientation == CfgScrOrientL)
	{
		touchgfx::Rect TextRect = Text.getAbsoluteRect();

    	FEA_GetRect270(TextRect);
		Text.setPosition(TextRect.x, TextRect.y, TextRect.width, TextRect.height);
		Text.setRotation(touchgfx::TEXT_ROTATE_270);
	}
}

void FEA_PlaceButtonLabel(touchgfx::ButtonWithLabel& Button)
{
    if(CFG_Data.ScrOrientation == CfgScrOrientL)
	{
    	touchgfx::Rect ButtonRect = Button.getRect();

    	Button.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_270_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_270_ID));
    	FEA_GetRect270(ButtonRect);
    	Button.setPosition(ButtonRect.x, ButtonRect.y, ButtonRect.width, ButtonRect.height);
	    Button.setLabelRotation(touchgfx::TEXT_ROTATE_270);
	}
}

void FEA_PlaceButtonIcon(touchgfx::ButtonWithIcon& Button)
{
    if(CFG_Data.ScrOrientation == CfgScrOrientL)
	{
    	touchgfx::Rect ButtonRect = Button.getRect();

//    	Button.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_270_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_270_ID));
    	FEA_GetRect270(ButtonRect);
    	Button.setPosition(ButtonRect.x, ButtonRect.y, ButtonRect.width, ButtonRect.height);
//	    Button.setLabelRotation(touchgfx::TEXT_ROTATE_270);
	}
}

void FEA_PlaceImage(touchgfx::TextureMapper& Image)
{
    if(CFG_Data.ScrOrientation == CfgScrOrientL)
    {
	    touchgfx::Bitmap ImageBit  = Image.getBitmap();
    	touchgfx::Rect   ImageRect = Image.getAbsoluteRect();

    	FEA_GetRect270(ImageRect);
    	Image.setPosition(ImageRect.x, ImageRect.y, ImageRect.width, ImageRect.height);
	    float NewBitmapX = (((float)ImageRect.width / 2.0f) - ((float)ImageBit.getWidth() / 2.0f));
	    float NewBitmapY = (((float)ImageRect.height / 2.0f) - ((float)ImageBit.getHeight() / 2.0f));
	    Image.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
	    Image.setOrigo((float)(ImageRect.width / 2), (float)(ImageRect.height / 2), 1000.0f);
	    Image.setCamera((float)(ImageRect.width / 2), (float)(ImageRect.height / 2));
	    Image.setAngles(0.0f, -0.0f, SCREEN_ANGLE);
    }
}
