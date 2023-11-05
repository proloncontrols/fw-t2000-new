
#include "stdlib.h"

#include "cfg.h"

#include <CRect.hpp>

namespace touchgfx
{

CRect::CRect(Rect& rect)
{
	CRect(rect.x, rect.y, rect.width, rect.height);
}

CRect::CRect(int16_t newX, int16_t newY, int16_t newWidth, int16_t newHeight)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
	{
		x = newX;
		y = newY;
		width = newWidth;
		height = newHeight;
	}
	else
	{
		x = abs(newX - 672);
	}
}

void CRect::operator=(Rect& rect)
{
}

void CRect::operator=(CRect& rect)
{
}

}
