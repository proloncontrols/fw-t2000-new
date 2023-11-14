
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
//         File : CSwipe.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Custom swipe control widget class header file
//=============================================================================
#ifndef CSWIPE_HPP
#define CSWIPE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{
//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	INDICATOR_TOP_LEFT,
	INDICATOR_TOP_CENTER,
	INDICATOR_TOP_RIGHT,
	INDICATOR_BOTTOM_LEFT,
	INDICATOR_BOTTOM_CENTER,
	INDICATOR_BOTTOM_RIGHT
} IndicatorLocation;


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CSwipePage : public Container
{
public:
    touchgfx::Box background;
	Rect client;

    void initialize(int16_t width, int16_t height, Rect& rect, bool showClient)
    {
    	client = rect;
    	setWidth(width);
    	setHeight(height);
        background.setPosition(0, 0, width, height);
        if(showClient)
        	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
        else
        	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
        add(background);
    }

    void addToClient(Drawable& d)
    {
    	d.setXY(d.getX()+client.x, d.getY()+client.y);
    	add(d);
    }
};

//-----------------------------------------------------------------------------
class CSwipe : public SwipeContainer
{
public:
    void initialize(int16_t x, int16_t y, int16_t width, int16_t height);
    void initialize(int16_t x, int16_t y, int16_t width, int16_t height, bool showClient);
    void initialize(int16_t x, int16_t y, int16_t width, int16_t height, IndicatorLocation location, const Bitmap& normalPage, const Bitmap& highlightedPage);
    void initialize(int16_t x, int16_t y, int16_t width, int16_t height, IndicatorLocation location, const Bitmap& normalPage, const Bitmap& highlightedPage, bool showClient);

    void addPage(CSwipePage& page);
	Rect& getClientRect();

private:
    int16_t pageWidth;
    int16_t pageHeight;
    int16_t bitmapWidth;
    int16_t bitmapHeight;
    IndicatorLocation curLocation;
    Rect clientRect;
    bool showClientRect;
    bool usingIndicator;
};

} // namespace touchgfx


#endif // TOUCHGFX_SWIPECONTAINER_HPP
