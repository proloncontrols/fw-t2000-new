
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
//         File : CSwipe.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Custom swipe control widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CSwipe.hpp>


namespace touchgfx
{
//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
	Container::setPosition(x, y, width, height);
	pageWidth = width;
	pageHeight = height;
	clientRect.x = 0;
	clientRect.y = 0;
	clientRect.width = width;
	clientRect.height = height;
	usingIndicator = false;
	showBackgroundRect = false;
}

//-----------------------------------------------------------------------------
void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height, IndicatorLocation location, const Bitmap& normalPage, const Bitmap& highlightedPage)
{
	initialize(x, y, width, height);

	curLocation = location;
	setPageIndicatorBitmaps(normalPage, highlightedPage);

	bitmapWidth  = MAX(normalPage.getWidth(), highlightedPage.getWidth());
	bitmapHeight = MAX(normalPage.getHeight(), highlightedPage.getHeight());
	clientRect.x = 0;
	clientRect.y = 0;
	if((location == INDICATOR_TOP_LEFT) || (location == INDICATOR_TOP_CENTER) || location == INDICATOR_TOP_RIGHT)
		clientRect.y = bitmapHeight;
	clientRect.width = width;
	clientRect.height = height - bitmapHeight;
	usingIndicator = true;
	showBackgroundRect = false;
}

//-----------------------------------------------------------------------------
void CSwipe::showBackground()
{
	showBackgroundRect = true;
}

//-----------------------------------------------------------------------------
void CSwipe::addPage(CSwipePage& page)
{
	page.initialize(pageWidth, pageHeight, clientRect, showBackgroundRect);
    add(page);

    if(usingIndicator)
    {
		//Re-calculate page indicator location according to new number of pages
		int16_t x;
		int16_t y;
		int16_t indicatorWidth = getNumberOfPages() * bitmapWidth;
		switch(curLocation)
		{
			case INDICATOR_TOP_LEFT:      x = 0;                                  y = 0;                         break;
			case INDICATOR_TOP_CENTER:    x = (pageWidth/2) - (indicatorWidth/2); y = 0;                         break;
			case INDICATOR_TOP_RIGHT:     x = pageWidth - indicatorWidth;         y = 0;                         break;
			case INDICATOR_BOTTOM_LEFT:   x = 0;                                  y = pageHeight - bitmapHeight; break;
			case INDICATOR_BOTTOM_CENTER: x = (pageWidth/2) - (indicatorWidth/2); y = pageHeight - bitmapHeight; break;
			case INDICATOR_BOTTOM_RIGHT:  x = pageWidth - indicatorWidth;         y = pageHeight - bitmapHeight; break;
		}
		setPageIndicatorXY(x, y);
    }
}

//-----------------------------------------------------------------------------
Rect& CSwipe::getClientRect()
{
	return clientRect;
}

} // namespace touchgfx
