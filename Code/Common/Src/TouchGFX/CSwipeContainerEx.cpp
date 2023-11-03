
#include "CSwipeContainerEx.hpp"

#include "cfg.h"


namespace touchgfx
{

CSwipeContainerEx::CSwipeContainerEx()
	: CSwipeContainer()
{

}

void CSwipeContainerEx::handleClickEvent(const ClickEvent& event)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		CSwipeContainer::handleClickEvent(event);
	else
	{

	}
}

}
