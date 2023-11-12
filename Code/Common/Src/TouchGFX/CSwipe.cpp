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










///******************************************************************************
//* Copyright (c) 2018(-2022) STMicroelectronics.
//* All rights reserved.
//*
//* This file is part of the TouchGFX 4.20.0 distribution.
//*
//* This software is licensed under terms that can be found in the LICENSE file in
//* the root directory of this software component.
//* If no LICENSE file comes with this software, it is provided AS-IS.
//*
//*******************************************************************************/
//
//#include <touchgfx/Application.hpp>
//#include <touchgfx/Bitmap.hpp>
//#include <touchgfx/Drawable.hpp>
//#include <touchgfx/EasingEquations.hpp>
//#include <touchgfx/containers/Container.hpp>
//#include <touchgfx/Color.hpp>
//#include <cfg.h>
//#include <CSwipe.hpp>
//#include <CWidget.hpp>
//
//namespace touchgfx
//{
//CSwipe::CSwipe()
//    : Container(),
//      currentState(NO_ANIMATION),
//      animationCounter(0),
//      swipeCutoff(80),
//      dragX(0),
//      animateDistance(0),
//      startX(0),
//      endElasticWidth(30),
//      pages(EAST),
//      pageIndicator()
//{
//    Application::getInstance()->registerTimerWidget(this);
//
////    curRotation = ROTATION_LANDSCAPE;
//    setTouchable(true);
//
//    Container::add(pages);
//    Container::add(pageIndicator);
//}
//
//CSwipe::~CSwipe()
//{
//    Application::getInstance()->unregisterTimerWidget(this);
//}
//
//void CSwipe::add(Drawable& page)
//{
////	page.setWidthHeight(curWidth, curHeight);
//
//    pages.add(page);
//
//    pageIndicator.setNumberOfPages(getNumberOfPages() + 1);
//    setSelectedPage(getSelectedPage());
//
//    setWidthHeight(page);
//}
//
//void CSwipe::remove(Drawable& page)
//{
//    Drawable* tmp = pages.getFirstChild();
//
//    if (pageIndicator.getNumberOfPages() == 0)
//    {
//        return;
//    }
//
//    // looks for the child matching page
//    // to ensure that the page indicator only counts down if a page is removed
//    while (tmp)
//    {
//        if (tmp == &page)
//        {
//            pages.remove(page);
//            pageIndicator.setNumberOfPages(getNumberOfPages() - 1);
//
//            const uint8_t numPages = getNumberOfPages();
//            if (numPages == 0)
//            {
//                setWidthHeight(0, 0);
//            }
//            else
//            {
//                pageIndicator.invalidateContent();
//                const uint8_t curPage = getSelectedPage();
//                setSelectedPage(MIN(curPage, numPages - 1));
//                pageIndicator.invalidateContent();
//            }
//            return;
//        }
//        else
//        {
//            tmp = tmp->getNextSibling();
//        }
//    }
//}
//
//void CSwipe::setEndSwipeElasticWidth(uint16_t width)
//{
//    endElasticWidth = width;
//}
//
//void CSwipe::setSwipeCutoff(uint16_t cutoff)
//{
//    swipeCutoff = cutoff;
//}
//
//void CSwipe::setPageIndicatorBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//{
//    pageIndicator.setBitmaps(normalPage, highlightedPage);
//}
//
//
//
//
//
//
//
//
////void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
////{
////	client.setPosition(0, 0, width, height);
////	client.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
////	add(client);
////}
////
////void CSwipe::initialize(Rotation rotation, int16_t x, int16_t y, int16_t width, int16_t height)
////{
////	background.setXY(x, y);
////	background.setWidthHeight(100, 50);
////	background.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
////	add(background);
//
//
////	curRotation = rotation;
////    curPosition = INDICATOR_NONE;
////
////	if(curRotation == ROTATION_LANDSCAPE)
////	{
////		curX = x;
////		curY = y;
////		curWidth = width;
////		curHeight = height;
////		curPageHeight = height;
////	}
////	else
////	{
////		curX = y;
////		curY = parent->getHeight()-x-width;
////		curWidth = height;
////		curHeight = width;
////		curPageHeight = width;
////	}
////	Container::setXY(curX, curY);
////
////	background.setPosition(curY, curY, curWidth, curHeight);
////	background.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
////	add(background);
////}
//
////void CSwipe::initialize(Rotation rotation, int16_t x, int16_t y, int16_t width, int16_t height, PageIndicatorPosition position, const Bitmap& normalPage, const Bitmap& highlightedPage)
////{
////    curPosition = position;
////    setPageIndicatorBitmaps(normalPage, highlightedPage);
////}
//
////void CSwipe::initialize(int16_t x, int16_t y, int16_t width, int16_t height, PageIndicatorPosition position, Rotation rotation)
////{
////	curX = x;
////	curY = y;
////	curWidth = width;
////	curHeight = height;
////   	curRotation = rotation;
////   	curPosition = position;
////
////    if(curRotation == ROTATION_LANDSCAPE)
////    {
////    	Container::setPosition(curX, curY, curWidth, curHeight);
////    }
////    else
////    {
////    }
////}
//
//
//
//
//
//
//
//
////void CSwipe::setXY(int16_t x, int16_t y, Rotation rotation)
////{
////   	curRotation = rotation;
////    if(curRotation == ROTATION_LANDSCAPE)
////    {
////    	Container::setXY(x, y);
////    }
////    else
////    {
////    	Container::setXY(y, SCREEN_HEIGHT-x);
////    }
////}
////
////void CSwipe::setPosition(int16_t x, int16_t y, int16_t width, int16_t height, Rotation rotation)
////{
////	curX = x;
////	curY = y;
////	curWidth = width;
////	curHeight = height;
////   	curRotation = rotation;
////    if(curRotation == ROTATION_LANDSCAPE)
////    {
////       	Container::setPosition(x, y, width, height);
////    }
////    else
////    {
////       	Container::setPosition(CLIENT_X+y, SCREEN_HEIGHT-width, height, width);
//////    	pages.setDirection(SOUTH);
////    }
////}
////
////void CSwipe::setPageIndicatorPosition(PageIndicatorPosition position)
////{
//////	#define FRAME_WIDTH 10
//////
//////    int16_t x;
//////    int16_t y;
//////    int16_t width  = (Bitmap(pageIndicator.unselectedPages.getBitmap()).getWidth()  * pageIndicator.numberOfPages) + (2 * FRAME_WIDTH);
//////    int16_t height =  Bitmap(pageIndicator.unselectedPages.getBitmap()).getHeight() + (2 * FRAME_WIDTH);
//////
//////    if(curRotation == ROTATION_LANDSCAPE)
//////	{
//////    	switch(position)
//////    	{
//////    		case INDICATOR_TOP_LEFT:      { x = FRAME_WIDTH;                      y = FRAME_WIDTH;                        break; }
//////    		case INDICATOR_TOP_CENTER:    { x = getWidth()/2 - width/2;           y = FRAME_WIDTH;                        break; }
//////    		case INDICATOR_TOP_RIGHT:     { x = FRAME_WIDTH + getWidth() - width; y = FRAME_WIDTH;                        break; }
//////    		case INDICATOR_BOTTOM_LEFT:   { x = FRAME_WIDTH;                      y = getHeight() - height + FRAME_WIDTH; break; }
//////    		case INDICATOR_BOTTOM_CENTER: { x = getWidth()/2 - width/2;           y = getHeight() - height + FRAME_WIDTH; break; }
//////    		case INDICATOR_BOTTOM_RIGHT:  { x = FRAME_WIDTH + getWidth() - width; y = getHeight() - height + FRAME_WIDTH; break; }
//////    	}
//////	}
//////	else
//////	{
//////	}
//////
//////	pageIndicator.setXY(x, y);
////}
//
//
//
//
//
//
//
//void CSwipe::setPageIndicatorXY(int16_t x, int16_t y)
//{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		pageIndicator.setXY(x, y);
////	else
////		pageIndicator.setXY(y, x);
//    pageIndicator.setXY(x, y);
//}
//
//void CSwipe::setPageIndicatorXYWithCenteredX(int16_t x, int16_t y)
//{
//    setPageIndicatorCenteredX(x);
//    pageIndicator.setY(y);
//}
//
//void CSwipe::setPageIndicatorCenteredX()
//{
//    setPageIndicatorCenteredX(getWidth() / 2);
//}
//
//void CSwipe::setPageIndicatorCenteredX(int16_t x)
//{
//    pageIndicator.setX(x - pageIndicator.getWidth() / 2);
//}
//
//void CSwipe::setSelectedPage(uint8_t pageIndex)
//{
//    if (pageIndex < getNumberOfPages())
//    {
//        pageIndicator.setCurrentPage(pageIndex);
//        adjustPages();
//    }
//}
//
//uint8_t CSwipe::getSelectedPage() const
//{
//    return pageIndicator.getCurrentPage();
//}
//
//void CSwipe::handleTickEvent()
//{
//    if (currentState == ANIMATE_SWIPE_CANCELLED_LEFT)
//    {
//        animateSwipeCancelledLeft();
//    }
//    else if (currentState == ANIMATE_SWIPE_CANCELLED_RIGHT)
//    {
//        animateSwipeCancelledRight();
//    }
//    else if (currentState == ANIMATE_LEFT)
//    {
//        animateLeft();
//    }
//    else if (currentState == ANIMATE_RIGHT)
//    {
//        animateRight();
//    }
//}
//
//void CSwipe::handleClickEvent(const ClickEvent& event)
//{
//    // If an animation is already in progress do not
//    // react to clicks
//    if (currentState != NO_ANIMATION)
//    {
//        return;
//    }
//
//    if (event.getType() == ClickEvent::RELEASED)
//    {
//        // Save current position for use during animation
//        animateDistance = dragX;
//        startX = pages.getX();
//        const uint8_t curPage = getSelectedPage();
//        if (dragX < 0)
//        {
//            if (curPage == getNumberOfPages() - 1 || dragX > -swipeCutoff)
//            {
//                currentState = ANIMATE_SWIPE_CANCELLED_LEFT;
//            }
//            else
//            {
//                currentState = ANIMATE_LEFT;
//            }
//        }
//        else if (dragX > 0)
//        {
//            if (curPage == 0 || dragX < swipeCutoff)
//            {
//                currentState = ANIMATE_SWIPE_CANCELLED_RIGHT;
//            }
//            else
//            {
//                currentState = ANIMATE_RIGHT;
//            }
//        }
//    }
//}
//
//void CSwipe::handleDragEvent(const DragEvent& event)
//{
//    // If an animation is already in progress do not
//    // react to drags
//    if (currentState != NO_ANIMATION)
//    {
//        return;
//    }
//
//    dragX += event.getDeltaX();
//
//    // Do not show too much background next to end pages
//    const uint8_t curPage = getSelectedPage();
//    if (curPage == 0 && dragX > endElasticWidth)
//    {
//        dragX = static_cast<int16_t>(endElasticWidth);
//    }
//    else if (curPage == getNumberOfPages() - 1 && dragX < -endElasticWidth)
//    {
//        dragX = -static_cast<int16_t>(endElasticWidth);
//    }
//
//    adjustPages();
//}
//
//void CSwipe::handleGestureEvent(const GestureEvent& event)
//{
//    // Do not accept gestures while animating
//    if (currentState != NO_ANIMATION)
//    {
//        return;
//    }
//
//    if (event.getType() == GestureEvent::SWIPE_HORIZONTAL)
//    {
//        // Save current position for use during animation
//        animateDistance = dragX;
//        startX = pages.getX();
//
//        const uint8_t curPage = getSelectedPage();
//        if (event.getVelocity() < 0 && curPage < getNumberOfPages() - 1)
//        {
//            currentState = ANIMATE_LEFT;
//        }
//        else if (event.getVelocity() > 0 && curPage > 0)
//        {
//            currentState = ANIMATE_RIGHT;
//        }
//    }
//}
//
//void CSwipe::adjustPages()
//{
//    pages.moveTo(-static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX, 0);
//}
//
//void CSwipe::animateSwipeCancelledLeft()
//{
//    uint8_t duration = 14;
//
//    if (animationCounter <= duration)
//    {
//        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, -animateDistance, duration);
//        dragX = animateDistance + delta;
//
//        adjustPages();
//    }
//    else
//    {
//        // Final step: stop the animation
//        currentState = NO_ANIMATION;
//        animationCounter = 0;
//        dragX = 0;
//        adjustPages();
//    }
//    animationCounter++;
//}
//
//void CSwipe::animateSwipeCancelledRight()
//{
//    uint8_t duration = 14;
//
//    if (animationCounter <= duration)
//    {
//        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, animateDistance, duration);
//        dragX = animateDistance - delta;
//
//        adjustPages();
//    }
//    else
//    {
//        // Final step: stop the animation
//        currentState = NO_ANIMATION;
//        animationCounter = 0;
//        dragX = 0;
//        adjustPages();
//    }
//    animationCounter++;
//}
//
//void CSwipe::animateLeft()
//{
//    uint8_t duration = 10;
//
//    if (animationCounter <= duration)
//    {
//        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() + animateDistance, duration);
//        dragX = animateDistance - delta;
//    }
//    else
//    {
//        // Final step: stop the animation
//        currentState = NO_ANIMATION;
//        animationCounter = 0;
//        dragX = 0;
//        pageIndicator.goRight();
//    }
//    adjustPages();
//    animationCounter++;
//}
//
//void CSwipe::animateRight()
//{
//    uint8_t duration = 10;
//
//    if (animationCounter <= duration)
//    {
//        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() - animateDistance, duration);
//        dragX = animateDistance + delta;
//    }
//    else
//    {
//        // Final step: stop the animation
//        currentState = NO_ANIMATION;
//        animationCounter = 0;
//        dragX = 0;
//        pageIndicator.goLeft();
//    }
//    adjustPages();
//    animationCounter++;
//}
//
//CSwipe::PageIndicator::PageIndicator()
//    : Container(),
//      unselectedPages(),
//      selectedPage(),
//      numberOfPages(0),
////      currentPage(255)
//      currentPage(0)
//{
//    unselectedPages.setXY(0, 0);
//    selectedPage.setXY(0, 0);
//
//    Container::add(unselectedPages);
//    Container::add(selectedPage);
//}
//
//void CSwipe::PageIndicator::setNumberOfPages(uint8_t size)
//{
//    numberOfPages = size;
//
//    assert(numberOfPages > 0 && "At least one dot is needed");
//
//    if (unselectedPages.getBitmapId() != BITMAP_INVALID)
//    {
//        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
//        unselectedPages.setWidth(dotWidth * size);
//
//        // adjust size of container according to the actual bitmaps
//        setWidthHeight(unselectedPages);
//        setCurrentPage(MIN(size, currentPage));
//
//        invalidateContent();
//    }
//}
//
//void CSwipe::PageIndicator::setBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//{
//    selectedPage.setBitmap(highlightedPage);
//    unselectedPages.setBitmap(normalPage);
//    if (numberOfPages > 0)
//    {
//        setNumberOfPages(numberOfPages);
//    }
//}
//
//void CSwipe::PageIndicator::goRight()
//{
//    setCurrentPage((currentPage + 1) % numberOfPages);
//}
//
//void CSwipe::PageIndicator::goLeft()
//{
//    setCurrentPage((currentPage + numberOfPages - 1) % numberOfPages);
//}
//
//void CSwipe::PageIndicator::setCurrentPage(uint8_t page)
//{
//    if (page < numberOfPages && page != currentPage)
//    {
////		currentPage = page;
////		int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
////		if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////			selectedPage.moveTo(page * dotWidth, selectedPage.getY());
////		else
////			selectedPage.moveTo(selectedPage.getX(), (numberOfPages * dotWidth) - ((page+1) * dotWidth));
//        currentPage = page;
//        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
//        selectedPage.moveTo(page * dotWidth, selectedPage.getY());
//    }
//}
//
//uint8_t CSwipe::PageIndicator::getNumberOfPages() const
//{
//    return numberOfPages;
//}
//
//uint8_t CSwipe::PageIndicator::getCurrentPage() const
//{
//    return currentPage;
//}
//} // namespace touchgfx
//
//
//
//
//
//
//
//
//
//
////
////#include <CSwipeContainer.hpp>
////#include <cfg.h>
////#include <CWidget.hpp>
////
////
////namespace touchgfx
////{
////
////CSwipeContainer::CSwipeContainer()
////{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////		pages.setDirection(SOUTH);
////}
////
////CSwipeContainer::~CSwipeContainer()
////{
////}
////
////
////
////
////
////void CSwipeContainer::handleTickEvent()
////{
//////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		CSwipeContainerEx::handleTickEvent();
//////	else
//////	{
//////	}
////}
////
////void CSwipeContainer::handleClickEvent(const ClickEvent& event)
////{
//////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		CSwipeContainerEx::handleClickEvent(event);
//////	else
//////	{
//////	}
////}
////
////void CSwipeContainer::handleDragEvent(const DragEvent& event)
////{
//////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		CSwipeContainerEx::handleDragEvent(event);
//////	else
//////	{
//////	}
////}
////
////void CSwipeContainer::handleGestureEvent(const GestureEvent& event)
////{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		CSwipeContainerEx::handleGestureEvent(event);
////	else
////	{
////	    // Do not accept gestures while animating
////	    if (currentState != NO_ANIMATION)
////	    {
////	        return;
////	    }
////
////	    if (event.getType() == GestureEvent::SWIPE_VERTICAL)
////	    {
////	        // Save current position for use during animation
////	        animateDistance = dragX;
////	        startX = pages.getX();
////
////	        const uint8_t curPage = getSelectedPage();
////	        if (event.getVelocity() < 0 && curPage < getNumberOfPages() - 1)
////	        {
////	            currentState = ANIMATE_LEFT;
////	        }
////	        else if (event.getVelocity() > 0 && curPage > 0)
////	        {
////	            currentState = ANIMATE_RIGHT;
////	        }
////	    }
////	}
////}
////
////
////
////
////
////void CSwipeContainer::setPosition(int16_t x, int16_t y, int16_t width, int16_t height)
////{
////    if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////    	Container::setPosition(x, y, width, height);
////    else
////    	Container::setPosition(SCREEN_OFFSET + y, SCREEN_HEIGHT - x - width, height, width);
////}
////
////void CSwipeContainer::setPageIndicatorXY(int16_t x, int16_t y)
////{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
////		pageIndicator.setXY(x, y);
////	else
////		pageIndicator.setXY(y, x);
////}
////
////
////
////
////
////void CSwipeContainer::setCurrentPage(uint8_t page)
////{
////    if (page < pageIndicator.numberOfPages && page != pageIndicator.currentPage)
////    {
////    	pageIndicator.currentPage = page;
////        int dotWidth = Bitmap(pageIndicator.unselectedPages.getBitmap()).getWidth();
////        if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////        	pageIndicator.selectedPage.moveTo(pageIndicator.selectedPage.getX(), (pageIndicator.numberOfPages * dotWidth) - ((page+1) * dotWidth));
////        else
////        	pageIndicator.selectedPage.moveTo(page * dotWidth, pageIndicator.selectedPage.getY());
////    }
////}
////}
////
////
////
////
//////
//////#include <touchgfx/Application.hpp>
//////#include <touchgfx/Bitmap.hpp>
//////#include <touchgfx/Drawable.hpp>
//////#include <touchgfx/EasingEquations.hpp>
//////#include <touchgfx/containers/Container.hpp>
//////#include <touchgfx/containers/SwipeContainer.hpp>
//////
//////#include <CSwipeContainer.hpp>
//////
//////namespace touchgfx
//////{
//////CSwipeContainer::CSwipeContainer()
//////    : Container(),
//////      currentState(NO_ANIMATION),
//////      animationCounter(0),
//////      swipeCutoff(80),
//////      dragX(0),
//////      animateDistance(0),
//////      startX(0),
//////      endElasticWidth(30),
//////      pages(EAST),
//////      pageIndicator()
//////{
//////    Application::getInstance()->registerTimerWidget(this);
//////
//////    setTouchable(true);
//////
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////		pages.setDirection(SOUTH);
//////
//////    Container::add(pages);
//////    Container::add(pageIndicator);
//////}
//////
//////CSwipeContainer::~CSwipeContainer()
//////{
//////    Application::getInstance()->unregisterTimerWidget(this);
//////}
//////
//////
//////
//////void CSwipeContainer::arrangeChildren()
//////{
//////	CArrangeWidget arrange;
//////	pages.forEachChild(&arrange);
//////	pageIndicator.forEachChild(&arrange);
//////	forEachChild(&arrange);
//////}
//////
//////void CSwipeContainer::setPosition(int16_t x, int16_t y, int16_t width, int16_t height)
//////{
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////    	Container::setPosition(CLIENT_OFFSET + y, SCREEN_HEIGHT - x, height, width);
//////    else
//////    	Container::setPosition(CLIENT_OFFSET + x, y, width, height);
//////}
//////
//////
//////
//////void CSwipeContainer::add(Drawable& page)
//////{
//////    pages.add(page);
//////
//////    pageIndicator.setNumberOfPages(getNumberOfPages() + 1);
//////    setSelectedPage(getSelectedPage());
//////
//////    setWidthHeight(page);
//////}
//////
//////void CSwipeContainer::remove(Drawable& page)
//////{
//////    Drawable* tmp = pages.getFirstChild();
//////
//////    if (pageIndicator.getNumberOfPages() == 0)
//////    {
//////        return;
//////    }
//////
//////    // looks for the child matching page
//////    // to ensure that the page indicator only counts down if a page is removed
//////    while (tmp)
//////    {
//////        if (tmp == &page)
//////        {
//////            pages.remove(page);
//////            pageIndicator.setNumberOfPages(getNumberOfPages() - 1);
//////
//////            const uint8_t numPages = getNumberOfPages();
//////            if (numPages == 0)
//////            {
//////                setWidthHeight(0, 0);
//////            }
//////            else
//////            {
//////                pageIndicator.invalidateContent();
//////                const uint8_t curPage = getSelectedPage();
//////                setSelectedPage(MIN(curPage, numPages - 1));
//////                pageIndicator.invalidateContent();
//////            }
//////            return;
//////        }
//////        else
//////        {
//////            tmp = tmp->getNextSibling();
//////        }
//////    }
//////}
//////
//////void CSwipeContainer::setEndSwipeElasticWidth(uint16_t width)
//////{
//////    endElasticWidth = width;
//////}
//////
//////void CSwipeContainer::setSwipeCutoff(uint16_t cutoff)
//////{
//////    swipeCutoff = cutoff;
//////}
//////
//////void CSwipeContainer::setPageIndicatorBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//////{
//////    pageIndicator.setBitmaps(normalPage, highlightedPage);
//////}
//////
//////void CSwipeContainer::setPageIndicatorXY(int16_t x, int16_t y)
//////{
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////		pageIndicator.setXY(y, x);
//////	else
//////		pageIndicator.setXY(x, y);
//////}
//////
//////void CSwipeContainer::setPageIndicatorXYWithCenteredX(int16_t x, int16_t y)
//////{
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////	{
//////	    setPageIndicatorCenteredX(y);
//////	    pageIndicator.setY(x);
//////	}
//////	else
//////	{
//////	    setPageIndicatorCenteredX(x);
//////	    pageIndicator.setY(y);
//////	}
//////}
//////
//////void CSwipeContainer::setPageIndicatorCenteredX()
//////{
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////	    setPageIndicatorCenteredX(getHeight() / 2);
//////	else
//////		setPageIndicatorCenteredX(getWidth() / 2);
//////}
//////
//////void CSwipeContainer::setPageIndicatorCenteredX(int16_t x)
//////{
//////    if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////		pageIndicator.setY(x - pageIndicator.getHeight() / 2);
//////	else
//////		pageIndicator.setX(x - pageIndicator.getWidth() / 2);
//////}
//////
//////void CSwipeContainer::setSelectedPage(uint8_t pageIndex)
//////{
//////    if (pageIndex < getNumberOfPages())
//////    {
//////        pageIndicator.setCurrentPage(pageIndex);
//////        adjustPages();
//////    }
//////}
//////
//////uint8_t CSwipeContainer::getSelectedPage() const
//////{
//////    return pageIndicator.getCurrentPage();
//////}
//////
//////void CSwipeContainer::handleTickEvent()
//////{
//////    if (currentState == ANIMATE_SWIPE_CANCELLED_LEFT)
//////    {
//////        animateSwipeCancelledLeft();
//////    }
//////    else if (currentState == ANIMATE_SWIPE_CANCELLED_RIGHT)
//////    {
//////        animateSwipeCancelledRight();
//////    }
//////    else if (currentState == ANIMATE_LEFT)
//////    {
//////        animateLeft();
//////    }
//////    else if (currentState == ANIMATE_RIGHT)
//////    {
//////        animateRight();
//////    }
//////}
//////
//////void CSwipeContainer::handleClickEvent(const ClickEvent& event)
//////{
//////    // If an animation is already in progress do not
//////    // react to clicks
//////    if (currentState != NO_ANIMATION)
//////    {
//////        return;
//////    }
//////
//////    if (event.getType() == ClickEvent::RELEASED)
//////    {
//////        // Save current position for use during animation
//////        animateDistance = dragX;
//////        startX = pages.getX();
//////        const uint8_t curPage = getSelectedPage();
//////        if (dragX < 0)
//////        {
//////            if (curPage == getNumberOfPages() - 1 || dragX > -swipeCutoff)
//////            {
//////                currentState = ANIMATE_SWIPE_CANCELLED_LEFT;
//////            }
//////            else
//////            {
//////                currentState = ANIMATE_LEFT;
//////            }
//////        }
//////        else if (dragX > 0)
//////        {
//////            if (curPage == 0 || dragX < swipeCutoff)
//////            {
//////                currentState = ANIMATE_SWIPE_CANCELLED_RIGHT;
//////            }
//////            else
//////            {
//////                currentState = ANIMATE_RIGHT;
//////            }
//////        }
//////    }
//////}
//////
//////void CSwipeContainer::handleDragEvent(const DragEvent& event)
//////{
//////    // If an animation is already in progress do not
//////    // react to drags
//////    if (currentState != NO_ANIMATION)
//////    {
//////        return;
//////    }
//////
//////    dragX += event.getDeltaX();
//////
//////    // Do not show too much background next to end pages
//////    const uint8_t curPage = getSelectedPage();
//////    if (curPage == 0 && dragX > endElasticWidth)
//////    {
//////        dragX = static_cast<int16_t>(endElasticWidth);
//////    }
//////    else if (curPage == getNumberOfPages() - 1 && dragX < -endElasticWidth)
//////    {
//////        dragX = -static_cast<int16_t>(endElasticWidth);
//////    }
//////
//////    adjustPages();
//////}
//////
//////void CSwipeContainer::handleGestureEvent(const GestureEvent& event)
//////{
//////    // Do not accept gestures while animating
//////    if (currentState != NO_ANIMATION)
//////    {
//////        return;
//////    }
//////
//////    if (event.getType() == GestureEvent::SWIPE_HORIZONTAL)
//////    {
//////        // Save current position for use during animation
//////        animateDistance = dragX;
//////        startX = pages.getX();
//////
//////        const uint8_t curPage = getSelectedPage();
//////        if (event.getVelocity() < 0 && curPage < getNumberOfPages() - 1)
//////        {
//////            currentState = ANIMATE_LEFT;
//////        }
//////        else if (event.getVelocity() > 0 && curPage > 0)
//////        {
//////            currentState = ANIMATE_RIGHT;
//////        }
//////    }
//////}
//////
//////void CSwipeContainer::adjustPages()
//////{
////////    pages.moveTo(0, -static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX);
//////    pages.moveTo(-static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX, 0);
//////}
//////
//////void CSwipeContainer::animateSwipeCancelledLeft()
//////{
//////    uint8_t duration = 14;
//////
//////    if (animationCounter <= duration)
//////    {
//////        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, -animateDistance, duration);
//////        dragX = animateDistance + delta;
//////        adjustPages();
//////    }
//////    else
//////    {
//////        // Final step: stop the animation
//////        currentState = NO_ANIMATION;
//////        animationCounter = 0;
//////        dragX = 0;
//////        adjustPages();
//////    }
//////    animationCounter++;
//////}
//////
//////void CSwipeContainer::animateSwipeCancelledRight()
//////{
//////    uint8_t duration = 14;
//////
//////    if (animationCounter <= duration)
//////    {
//////        int16_t delta = EasingEquations::backEaseOut(animationCounter, 0, animateDistance, duration);
//////        dragX = animateDistance - delta;
//////        adjustPages();
//////    }
//////    else
//////    {
//////        // Final step: stop the animation
//////        currentState = NO_ANIMATION;
//////        animationCounter = 0;
//////        dragX = 0;
//////        adjustPages();
//////    }
//////    animationCounter++;
//////}
//////
//////void CSwipeContainer::animateLeft()
//////{
//////    uint8_t duration = 10;
//////
//////    if (animationCounter <= duration)
//////    {
//////        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() + animateDistance, duration);
//////        dragX = animateDistance - delta;
//////    }
//////    else
//////    {
//////        // Final step: stop the animation
//////        currentState = NO_ANIMATION;
//////        animationCounter = 0;
//////        dragX = 0;
//////        pageIndicator.goRight();
//////    }
//////    adjustPages();
//////    animationCounter++;
//////}
//////
//////void CSwipeContainer::animateRight()
//////{
//////    uint8_t duration = 10;
//////
//////    if (animationCounter <= duration)
//////    {
//////        int16_t delta = EasingEquations::cubicEaseOut(animationCounter, 0, getWidth() - animateDistance, duration);
//////        dragX = animateDistance + delta;
//////    }
//////    else
//////    {
//////        // Final step: stop the animation
//////        currentState = NO_ANIMATION;
//////        animationCounter = 0;
//////        dragX = 0;
//////        pageIndicator.goLeft();
//////    }
//////    adjustPages();
//////    animationCounter++;
//////}
//////
//////CSwipeContainer::PageIndicator::PageIndicator()
//////    : Container(),
//////      unselectedPages(),
//////      selectedPage(),
//////      numberOfPages(0),
//////      currentPage(255)   //To force an initial page indicator update
////////      currentPage(0)
//////{
//////    unselectedPages.setXY(0, 0);
//////    selectedPage.setXY(0, 0);
//////
//////    Container::add(unselectedPages);
//////    Container::add(selectedPage);
//////}
//////
//////void CSwipeContainer::PageIndicator::setNumberOfPages(uint8_t size)
//////{
//////    numberOfPages = size;
//////
//////    assert(numberOfPages > 0 && "At least one dot is needed");
//////
//////    if (unselectedPages.getBitmapId() != BITMAP_INVALID)
//////    {
//////        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
//////        if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////        	unselectedPages.setHeight(dotWidth * size);
//////        else
//////            unselectedPages.setWidth(dotWidth * size);
//////
//////        // adjust size of container according to the actual bitmaps
//////        setWidthHeight(unselectedPages);
//////        setCurrentPage(MIN(size, currentPage));
//////
//////        invalidateContent();
//////    }
//////}
//////
//////void CSwipeContainer::PageIndicator::setBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//////{
//////    selectedPage.setBitmap(highlightedPage);
//////    unselectedPages.setBitmap(normalPage);
//////    if (numberOfPages > 0)
//////    {
//////        setNumberOfPages(numberOfPages);
//////    }
//////}
//////
//////void CSwipeContainer::PageIndicator::goRight()
//////{
//////    setCurrentPage((currentPage + 1) % numberOfPages);
//////}
//////
//////void CSwipeContainer::PageIndicator::goLeft()
//////{
//////    setCurrentPage((currentPage + numberOfPages - 1) % numberOfPages);
//////}
//////
//////void CSwipeContainer::PageIndicator::setCurrentPage(uint8_t page)
//////{
//////    if (page < numberOfPages && page != currentPage)
//////    {
//////        currentPage = page;
//////        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
//////        if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//////        	selectedPage.moveTo(selectedPage.getX(), (numberOfPages * dotWidth) - ((page+1) * dotWidth));
//////        else
//////        	selectedPage.moveTo(page * dotWidth, selectedPage.getY());
//////    }
//////}
//////
//////uint8_t CSwipeContainer::PageIndicator::getNumberOfPages() const
//////{
//////    return numberOfPages;
//////}
//////
//////uint8_t CSwipeContainer::PageIndicator::getCurrentPage() const
//////{
//////    return currentPage;
//////}
//////} // namespace touchgfx
