/******************************************************************************
* Copyright (c) 2018(-2022) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.20.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

#include <touchgfx/Application.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Drawable.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/containers/Container.hpp>
#include <CSwipe.hpp>

namespace touchgfx
{
CSwipe::CSwipe()
    : Container(),
      currentState(NO_ANIMATION),
      animationCounter(0),
      swipeCutoff(80),
      dragX(0),
      animateDistance(0),
      startX(0),
      endElasticWidth(30),
      pages(EAST),
      pageIndicator()
{
    Application::getInstance()->registerTimerWidget(this);

    setTouchable(true);

    Container::add(pages);
    Container::add(pageIndicator);
}

CSwipe::~CSwipe()
{
    Application::getInstance()->unregisterTimerWidget(this);
}





void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
	Container::setPosition(x, y, width, height);
	pageWidth = width;
	pageHeight = height;
	clientRect.x = 0;
	clientRect.y = 0;
	clientRect.width = width;
	clientRect.height = height;
}

void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height, IndicatorLocation location, const Bitmap& normalPage, const Bitmap& highlightedPage)
{
	initialize(x, y, width, height);

	curLocation = location;
	pageIndicator.setBitmaps(normalPage, highlightedPage);

	int16_t bitmapHeight = MAX(normalPage.getHeight(), highlightedPage.getHeight());
	clientRect.x = 0;
	clientRect.y = 0;
	if((location == INDICATOR_TOP_LEFT) || (location == INDICATOR_TOP_CENTER) || location == INDICATOR_TOP_RIGHT)
		clientRect.y = bitmapHeight;
	clientRect.width = width;
	clientRect.height = height - bitmapHeight;
}

void CSwipe::addPage(CSwipePage& page)
{
	page.initialize(pageWidth, pageHeight, clientRect);
    add(page);

    //Re-calculate page indicator location according to new number of pages
	int16_t x;
	int16_t y;
    switch(curLocation)
    {
		case INDICATOR_TOP_LEFT:      x = 0;                                            y = 0;                                      break;
		case INDICATOR_TOP_CENTER:    x = (pageWidth/2) - (pageIndicator.getWidth()/2); y = 0;                                      break;
		case INDICATOR_TOP_RIGHT:     x = pageWidth - pageIndicator.getWidth();         y = 0;                                      break;
		case INDICATOR_BOTTOM_LEFT:   x = 0;                                            y = pageHeight - pageIndicator.getHeight(); break;
		case INDICATOR_BOTTOM_CENTER: x = (pageWidth/2) - (pageIndicator.getWidth()/2); y = pageHeight - pageIndicator.getHeight(); break;
		case INDICATOR_BOTTOM_RIGHT:  x = pageWidth - pageIndicator.getWidth();         y = pageHeight - pageIndicator.getHeight(); break;
    }
    setPageIndicatorXY(x, y);
}

Rect& CSwipe::getClientRect()
{
	return clientRect;
}





void CSwipe::add(Drawable& page)
{
    pages.add(page);

    pageIndicator.setNumberOfPages(getNumberOfPages() + 1);
    setSelectedPage(getSelectedPage());

//    setWidthHeight(page);  //JFB: Done in initialize method with setPosition
}

void CSwipe::remove(Drawable& page)
{
    Drawable* tmp = pages.getFirstChild();

    if (pageIndicator.getNumberOfPages() == 0)
    {
        return;
    }

    // looks for the child matching page
    // to ensure that the page indicator only counts down if a page is removed
    while (tmp)
    {
        if (tmp == &page)
        {
            pages.remove(page);
            pageIndicator.setNumberOfPages(getNumberOfPages() - 1);

            const uint8_t numPages = getNumberOfPages();
            if (numPages == 0)
            {
                setWidthHeight(0, 0);
            }
            else
            {
                pageIndicator.invalidateContent();
                const uint8_t curPage = getSelectedPage();
                setSelectedPage(MIN(curPage, numPages - 1));
                pageIndicator.invalidateContent();
            }
            return;
        }
        else
        {
            tmp = tmp->getNextSibling();
        }
    }
}

void CSwipe::setEndSwipeElasticWidth(uint16_t width)
{
    endElasticWidth = width;
}

void CSwipe::setSwipeCutoff(uint16_t cutoff)
{
    swipeCutoff = cutoff;
}

void CSwipe::setPageIndicatorBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
{
    pageIndicator.setBitmaps(normalPage, highlightedPage);
}

void CSwipe::setPageIndicatorXY(int16_t x, int16_t y)
{
    pageIndicator.setXY(x, y);
}

void CSwipe::setPageIndicatorXYWithCenteredX(int16_t x, int16_t y)
{
    setPageIndicatorCenteredX(x);
    pageIndicator.setY(y);
}

void CSwipe::setPageIndicatorCenteredX()
{
    setPageIndicatorCenteredX(getWidth() / 2);
}

void CSwipe::setPageIndicatorCenteredX(int16_t x)
{
    pageIndicator.setX(x - pageIndicator.getWidth() / 2);
}

void CSwipe::setSelectedPage(uint8_t pageIndex)
{
    if (pageIndex < getNumberOfPages())
    {
        pageIndicator.setCurrentPage(pageIndex);
        adjustPages();
    }
}

uint8_t CSwipe::getSelectedPage() const
{
    return pageIndicator.getCurrentPage();
}

void CSwipe::handleTickEvent()
{
    if (currentState == ANIMATE_SWIPE_CANCELLED_LEFT)
    {
        animateSwipeCancelledLeft();
    }
    else if (currentState == ANIMATE_SWIPE_CANCELLED_RIGHT)
    {
        animateSwipeCancelledRight();
    }
    else if (currentState == ANIMATE_LEFT)
    {
        animateLeft();
    }
    else if (currentState == ANIMATE_RIGHT)
    {
        animateRight();
    }
}

void CSwipe::handleClickEvent(const ClickEvent& event)
{
    // If an animation is already in progress do not
    // react to clicks
    if (currentState != NO_ANIMATION)
    {
        return;
    }

    if (event.getType() == ClickEvent::RELEASED)
    {
        // Save current position for use during animation
        animateDistance = dragX;
        startX = pages.getX();
        const uint8_t curPage = getSelectedPage();
        if (dragX < 0)
        {
            if (curPage == getNumberOfPages() - 1 || dragX > -swipeCutoff)
            {
                currentState = ANIMATE_SWIPE_CANCELLED_LEFT;
            }
            else
            {
                currentState = ANIMATE_LEFT;
            }
        }
        else if (dragX > 0)
        {
            if (curPage == 0 || dragX < swipeCutoff)
            {
                currentState = ANIMATE_SWIPE_CANCELLED_RIGHT;
            }
            else
            {
                currentState = ANIMATE_RIGHT;
            }
        }
    }
}

void CSwipe::handleDragEvent(const DragEvent& event)
{
    // If an animation is already in progress do not
    // react to drags
    if (currentState != NO_ANIMATION)
    {
        return;
    }

    dragX += event.getDeltaX();

    // Do not show too much background next to end pages
    const uint8_t curPage = getSelectedPage();
    if (curPage == 0 && dragX > endElasticWidth)
    {
        dragX = static_cast<int16_t>(endElasticWidth);
    }
    else if (curPage == getNumberOfPages() - 1 && dragX < -endElasticWidth)
    {
        dragX = -static_cast<int16_t>(endElasticWidth);
    }

    adjustPages();
}

void CSwipe::handleGestureEvent(const GestureEvent& event)
{
    // Do not accept gestures while animating
    if (currentState != NO_ANIMATION)
    {
        return;
    }

    if (event.getType() == GestureEvent::SWIPE_HORIZONTAL)
    {
        // Save current position for use during animation
        animateDistance = dragX;
        startX = pages.getX();

        const uint8_t curPage = getSelectedPage();
        if (event.getVelocity() < 0 && curPage < getNumberOfPages() - 1)
        {
            currentState = ANIMATE_LEFT;
        }
        else if (event.getVelocity() > 0 && curPage > 0)
        {
            currentState = ANIMATE_RIGHT;
        }
    }
}

void CSwipe::adjustPages()
{
    pages.moveTo(-static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX, 0);
}

void CSwipe::animateSwipeCancelledLeft()
{
    uint8_t duration = 14;

    if (animationCounter <= duration)
    {
        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, -animateDistance, duration);
        dragX = animateDistance + delta;

        adjustPages();
    }
    else
    {
        // Final step: stop the animation
        currentState = NO_ANIMATION;
        animationCounter = 0;
        dragX = 0;
        adjustPages();
    }
    animationCounter++;
}

void CSwipe::animateSwipeCancelledRight()
{
    uint8_t duration = 14;

    if (animationCounter <= duration)
    {
        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, animateDistance, duration);
        dragX = animateDistance - delta;

        adjustPages();
    }
    else
    {
        // Final step: stop the animation
        currentState = NO_ANIMATION;
        animationCounter = 0;
        dragX = 0;
        adjustPages();
    }
    animationCounter++;
}

void CSwipe::animateLeft()
{
    uint8_t duration = 10;

    if (animationCounter <= duration)
    {
        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() + animateDistance, duration);
        dragX = animateDistance - delta;
    }
    else
    {
        // Final step: stop the animation
        currentState = NO_ANIMATION;
        animationCounter = 0;
        dragX = 0;
        pageIndicator.goRight();
    }
    adjustPages();
    animationCounter++;
}

void CSwipe::animateRight()
{
    uint8_t duration = 10;

    if (animationCounter <= duration)
    {
        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() - animateDistance, duration);
        dragX = animateDistance + delta;
    }
    else
    {
        // Final step: stop the animation
        currentState = NO_ANIMATION;
        animationCounter = 0;
        dragX = 0;
        pageIndicator.goLeft();
    }
    adjustPages();
    animationCounter++;
}

CSwipe::PageIndicator::PageIndicator()
    : Container(),
      unselectedPages(),
      selectedPage(),
      numberOfPages(0),
      currentPage(0)
{
    unselectedPages.setXY(0, 0);
    selectedPage.setXY(0, 0);

    Container::add(unselectedPages);
    Container::add(selectedPage);
}

void CSwipe::PageIndicator::setNumberOfPages(uint8_t size)
{
    numberOfPages = size;

    assert(numberOfPages > 0 && "At least one dot is needed");

    if (unselectedPages.getBitmapId() != BITMAP_INVALID)
    {
        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
        unselectedPages.setWidth(dotWidth * size);

        // adjust size of container according to the actual bitmaps
        setWidthHeight(unselectedPages);
        setCurrentPage(MIN(size, currentPage));

        invalidateContent();
    }
}

void CSwipe::PageIndicator::setBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
{
    selectedPage.setBitmap(highlightedPage);
    unselectedPages.setBitmap(normalPage);
    if (numberOfPages > 0)
    {
        setNumberOfPages(numberOfPages);
    }
}

void CSwipe::PageIndicator::goRight()
{
    setCurrentPage((currentPage + 1) % numberOfPages);
}

void CSwipe::PageIndicator::goLeft()
{
    setCurrentPage((currentPage + numberOfPages - 1) % numberOfPages);
}

void CSwipe::PageIndicator::setCurrentPage(uint8_t page)
{
    if (page < numberOfPages && page != currentPage)
    {
        currentPage = page;
        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
        selectedPage.moveTo(page * dotWidth, selectedPage.getY());
    }
}

uint8_t CSwipe::PageIndicator::getNumberOfPages() const
{
    return numberOfPages;
}

uint8_t CSwipe::PageIndicator::getCurrentPage() const
{
    return currentPage;
}
} // namespace touchgfx
