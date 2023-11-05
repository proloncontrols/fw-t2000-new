
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//-----------------------------------------------------------------------------
//         File : widget.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget class/tools header file
//=============================================================================
#ifndef WGT_H
#define WGT_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>

#include "cfg.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define SCREEN_WIDTH      720
#define SCREEN_HEIGHT     672
#define SCREEN_ANGLE      (-1.572f)   //Used for TextureMapper widget's Z angle
#define SCREEN_OFFSET     24
//#define SCREEN_OFFSET_Y   0
#define SCREEN_FRAME      24
//
//
// Thermostat portrait orientation
//
//    Screen (landscape)
//    -------------------------------------   ---
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |     Client (square)     |    |   672
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    -------------------------------------   ---
//
//    |-24-|---------- 672 ----------|-24-|
//    |--------------- 720 ---------------|
//
//






//
//
// Thermostat portrait orientation
//
//    Screen (landscape)
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
//#define CLIENT_OFFSET_PER   24   //Number of pixels creating an inside perimeter offset
//
//#define CLIENT_ORIGIN_P_X   (((SCREEN_WIDTH - SCREEN_HEIGHT) / 2) + CLIENT_OFFSET_PER)
//#define CLIENT_ORIGIN_P_Y   CLIENT_OFFSET_PER
//
//#define CLIENT_ORIGIN_L_X   (SCREEN_HEIGHT - CLIENT_OFFSET_PER)
//#define CLIENT_ORIGIN_L_Y   CLIENT_ORIGIN_P_Y

//#define CLIENT_OFFSET       24
//#define CLIENT_ORIGIN_X     (((SCREEN_WIDTH - SCREEN_HEIGHT) / 2) + CLIENT_OFFSET)
//#define CLIENT_ORIGIN_Y     CLIENT_OFFSET


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CRect
{
public:
	int16_t x;
	int16_t y;
	int16_t width;
	int16_t height;

	void operator=(const CRect& rect)
	{
		x = rect.x;
		y = rect.y;
		width = rect.width;
		height = rect.height;
	}

	void operator=(const touchgfx::Rect& rect)
	{
		x = rect.x;
		y = rect.y;
		width = rect.width;
		height = rect.height;
	}
};

//-----------------------------------------------------------------------------
class CWidget
{
public:
	CWidget(touchgfx::Widget& widget);
	CWidget(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& button);

	virtual void place() = 0;
	virtual void getPosition(CRect& rect) = 0;
	virtual void setPosition(CRect& rect) = 0;



	virtual touchgfx::Rect getRect() = 0;

protected:
	CRect pRect;
	CRect lRect;



	CRect vRect;   //Virtual CRect
	CRect fRect;   //Formatted CRect
//	CRect RectP;
//	CRect RectL;

	CRect oRect;
	CRect cRect;
	CRect sRect;

//	CRect* getRect();
	void formatRect();
	CRect& getVRect();
	void getRect(CRect& rect);
	void setRect(CRect& rect);

	void screenToClient(CRect& rect);
//	void screenToClient(const touchgfx::Rect& rect);
	void clientToScreen(CRect& rect);

	CRect* getCurRect();

private:
//	void rotate270deg(CRect& rect);

	void createRect270deg();
};






class CWidget2
{
public:
	CWidget2(touchgfx::Widget& widget);
	CWidget2(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& button);

	virtual void position() = 0;
	virtual void getPosition(CRect& rect) = 0;
	virtual void setPosition(CRect& rect) = 0;
};






#endif   //WGT_H

















































