
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : ui_virtual.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : User-Intrerface widget virtual manipulation header file
//=============================================================================
#ifndef UIV_H
#define UIV_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>

#include "cfg.h"



#define UIV_SCREEN_WIDTH      720
#define UIV_SCREEN_HEIGHT     672
#define UIV_SCREEN_ANGLE    (-1.572f)





#define SCREEN_WIDTH    720
#define SCREEN_HEIGHT   672
#define SCREEN_ANGLE    (-1.572f)   //Used for TextureMapper widget's Z angle
//
//
// Thermostat portrait orientation
//
//    LCD (landscape)
//    -------------------------------------   --- ---
//    |                                   |    24  |
//    |        -------------------        |   ---  |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        | Client (square) |        |   624 672
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        -------------------        |   ---  |
//    |                                   |    24  |
//    -------------------------------------   --- ---
//
//    |-- 48 --|------ 624 ------|-- 48 --|
//    |--------------- 720 ---------------|
//
//
//The following defines are according to the thermostat orientation
#define CLIENT_OFFSET_PER   24   //Number of pixels creating an inside perimeter offset

#define CLIENT_ORIGIN_X_P   (((SCREEN_WIDTH - SCREEN_HEIGHT) / 2) + CLIENT_OFFSET_PER)
#define CLIENT_ORIGIN_Y_P   CLIENT_OFFSET_PER

#define CLIENT_ORIGIN_X_L   (SCREEN_HEIGHT - CLIENT_OFFSET_PER)
#define CLIENT_ORIGIN_Y_L   CLIENT_ORIGIN_Y_P








class WidgetEx
{
public:
	virtual void initialize() = 0;

protected:
	touchgfx::Rect RectP;
	touchgfx::Rect RectL;

	void initRect(touchgfx::Widget& Widget)
	{
		RectP = Widget.getRect();
		RectL = Widget.getRect();

		int NewX = RectL.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                      //Becomes the Y coordinate of the rotated screen
		int NewWidth = RectL.height;
		int NewY = SCREEN_HEIGHT - (RectL.x + RectL.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
		int NewHeight = RectL.width;

		RectL.x = NewX;             //Apply new 270 degrees parameters
		RectL.y = NewY;             //
		RectL.width = NewWidth;     //
		RectL.height = NewHeight;   //
	}
//	void rotateRect270deg(touchgfx::Rect& Rect)
//	{
//		int NewX = Rect.y + ((UIV_SCREEN_WIDTH - UIV_SCREEN_HEIGHT) / 2);                                      //Becomes the Y coordinate of the rotated screen
//		int NewWidth = Rect.height;
//		int NewY = UIV_SCREEN_HEIGHT - (Rect.x + Rect.width) + ((UIV_SCREEN_WIDTH - UIV_SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
//		int NewHeight = Rect.width;
//
//		Rect.x = NewX;             //Apply new 270 degrees parameters
//		Rect.y = NewY;             //
//		Rect.width = NewWidth;     //
//		Rect.height = NewHeight;   //
//	}
};



class TextureMapperEx : public WidgetEx
{
private:
	touchgfx::TextureMapper& m_Mapper;

public:
	TextureMapperEx(touchgfx::TextureMapper& Mapper) : m_Mapper { Mapper }
	{
		initRect(Mapper);
	};

	virtual void initialize()
	{
		float AngleZ = 0.0;
		touchgfx::Rect* CurRect = &RectP;
	    touchgfx::Bitmap ImageBit = m_Mapper.getBitmap();

    	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		{
    		CurRect = &RectL;
    		AngleZ = SCREEN_ANGLE;
		}
    	m_Mapper.setPosition(CurRect->x, CurRect->y, CurRect->width, CurRect->height);
	    float NewBitmapX = (((float)CurRect->width / 2.0) - ((float)ImageBit.getWidth() / 2.0));
	    float NewBitmapY = (((float)CurRect->height / 2.0) - ((float)ImageBit.getHeight() / 2.0));
	    m_Mapper.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
	    m_Mapper.setOrigo((float)(CurRect->width / 2), (float)(CurRect->height / 2), 1000.0);
	    m_Mapper.setCamera((float)(CurRect->width / 2), (float)(CurRect->height / 2));
	    m_Mapper.setAngles(0.0, -0.0, AngleZ);




//	    touchgfx::Bitmap ImageBit  = m_Mapper.getBitmap();
//    	//touchgfx::Rect   ImageRect = m_Mapper.getAbsoluteRect();
//
//    	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//	    {
//	    	m_Mapper.setPosition(RectP.x, RectP.y, RectP.width, RectP.height);
//		    float NewBitmapX = (((float)RectP.width / 2.0f) - ((float)ImageBit.getWidth() / 2.0f));
//		    float NewBitmapY = (((float)RectP.height / 2.0f) - ((float)ImageBit.getHeight() / 2.0f));
//		    m_Mapper.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
//		    m_Mapper.setOrigo((float)(RectP.width / 2), (float)(RectP.height / 2), 1000.0f);
//		    m_Mapper.setCamera((float)(RectP.width / 2), (float)(RectP.height / 2));
//		    m_Mapper.setAngles(0.0f, -0.0f, 0.0f);
//	    }
//		else
//		{
//	    	//rotateRect270deg(ImageRect);
//	    	m_Mapper.setPosition(RectL.x, RectL.y, RectL.width, RectL.height);
//		    float NewBitmapX = (((float)RectL.width / 2.0f) - ((float)ImageBit.getWidth() / 2.0f));
//		    float NewBitmapY = (((float)RectL.height / 2.0f) - ((float)ImageBit.getHeight() / 2.0f));
//		    m_Mapper.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
//		    m_Mapper.setOrigo((float)(RectL.width / 2), (float)(RectL.height / 2), 1000.0f);
//		    m_Mapper.setCamera((float)(RectL.width / 2), (float)(RectL.height / 2));
//		    m_Mapper.setAngles(0.0f, -0.0f, SCREEN_ANGLE);
//		}

//		if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//	    {
//		    touchgfx::Bitmap ImageBit  = m_Mapper.getBitmap();
//	    	touchgfx::Rect   ImageRect = m_Mapper.getAbsoluteRect();
//
//	    	rotateRect270deg(ImageRect);
//	    	m_Mapper.setPosition(ImageRect.x, ImageRect.y, ImageRect.width, ImageRect.height);
//		    float NewBitmapX = (((float)ImageRect.width / 2.0f) - ((float)ImageBit.getWidth() / 2.0f));
//		    float NewBitmapY = (((float)ImageRect.height / 2.0f) - ((float)ImageBit.getHeight() / 2.0f));
//		    m_Mapper.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
//		    m_Mapper.setOrigo((float)(ImageRect.width / 2), (float)(ImageRect.height / 2), 1000.0f);
//		    m_Mapper.setCamera((float)(ImageRect.width / 2), (float)(ImageRect.height / 2));
//		    m_Mapper.setAngles(0.0f, -0.0f, UIV_SCREEN_ANGLE);
//	    }
	};
};



class TextAreaEx : public WidgetEx
{
private:
	touchgfx::TextArea& m_Area;

public:
	TextAreaEx(touchgfx::TextArea& Area)
	    : m_Area { Area }
	{
	};

	virtual void initialize()
	{
		if(CFG.Dta.ScrOrientation == CfgScrOrientL)
	    {
			touchgfx::Rect TextRect = m_Area.getAbsoluteRect();

//			rotateRect270deg(TextRect);
			m_Area.setPosition(TextRect.x, TextRect.y, TextRect.width, TextRect.height);
			m_Area.setRotation(touchgfx::TEXT_ROTATE_270);
	    }
	};
};



class ButtonEx : public WidgetEx
{
private:
	touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& m_Button;

public:
	ButtonEx(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button)
	    : m_Button { Button }
	{
	};

	virtual void initialize()
	{
		if(CFG.Dta.ScrOrientation == CfgScrOrientL)
	    {
			touchgfx::Rect ButtonRect = m_Button.getRect();

//			rotateRect270deg(ButtonRect);
			m_Button.setPosition(ButtonRect.x, ButtonRect.y, ButtonRect.width, ButtonRect.height);
	    }
	};
};





//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void UIV_placeText       (touchgfx::TextArea& Text);
extern void UIV_placeTexture    (touchgfx::TextureMapper& Image);
extern void UIV_placeButtonFlex (touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button);


#endif   //UIV_H
