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
////#include <touchgfx/containers/SwipeContainer.hpp>
//#include <CSwipeContainerEx.hpp>
//
//namespace touchgfx
//{
//CSwipeContainerEx::CSwipeContainerEx()
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
//    setTouchable(true);
//
//    Container::add(pages);
//    Container::add(pageIndicator);
//}
//
//CSwipeContainerEx::~CSwipeContainerEx()
//{
//    Application::getInstance()->unregisterTimerWidget(this);
//}
//
//void CSwipeContainerEx::add(Drawable& page)
//{
//    pages.add(page);
//
//    pageIndicator.setNumberOfPages(getNumberOfPages() + 1);
//    setSelectedPage(getSelectedPage());
//
//    setWidthHeight(page);
//}
//
//void CSwipeContainerEx::remove(Drawable& page)
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
//void CSwipeContainerEx::setEndSwipeElasticWidth(uint16_t width)
//{
//    endElasticWidth = width;
//}
//
//void CSwipeContainerEx::setSwipeCutoff(uint16_t cutoff)
//{
//    swipeCutoff = cutoff;
//}
//
//void CSwipeContainerEx::setPageIndicatorBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//{
//    pageIndicator.setBitmaps(normalPage, highlightedPage);
//}
//
//void CSwipeContainerEx::setPageIndicatorXY(int16_t x, int16_t y)
//{
//    pageIndicator.setXY(x, y);
//}
//
//void CSwipeContainerEx::setPageIndicatorXYWithCenteredX(int16_t x, int16_t y)
//{
//    setPageIndicatorCenteredX(x);
//    pageIndicator.setY(y);
//}
//
//void CSwipeContainerEx::setPageIndicatorCenteredX()
//{
//    setPageIndicatorCenteredX(getWidth() / 2);
//}
//
//void CSwipeContainerEx::setPageIndicatorCenteredX(int16_t x)
//{
//    pageIndicator.setX(x - pageIndicator.getWidth() / 2);
//}
//
//void CSwipeContainerEx::setSelectedPage(uint8_t pageIndex)
//{
//    if (pageIndex < getNumberOfPages())
//    {
//        pageIndicator.setCurrentPage(pageIndex);
//        adjustPages();
//    }
//}
//
//uint8_t CSwipeContainerEx::getSelectedPage() const
//{
//    return pageIndicator.getCurrentPage();
//}
//
//void CSwipeContainerEx::handleTickEvent()
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
//void CSwipeContainerEx::handleClickEvent(const ClickEvent& event)
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
//void CSwipeContainerEx::handleDragEvent(const DragEvent& event)
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
//void CSwipeContainerEx::handleGestureEvent(const GestureEvent& event)
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
//void CSwipeContainerEx::adjustPages()
//{
//    pages.moveTo(-static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX, 0);
//}
//
//void CSwipeContainerEx::animateSwipeCancelledLeft()
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
//void CSwipeContainerEx::animateSwipeCancelledRight()
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
//void CSwipeContainerEx::animateLeft()
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
//void CSwipeContainerEx::animateRight()
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
//CSwipeContainerEx::PageIndicator::PageIndicator()
//    : Container(),
//      unselectedPages(),
//      selectedPage(),
//      numberOfPages(0),
//      currentPage(0)
//{
//    unselectedPages.setXY(0, 0);
//    selectedPage.setXY(0, 0);
//
//    Container::add(unselectedPages);
//    Container::add(selectedPage);
//}
//
//void CSwipeContainerEx::PageIndicator::setNumberOfPages(uint8_t size)
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
//void CSwipeContainerEx::PageIndicator::setBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
//{
//    selectedPage.setBitmap(highlightedPage);
//    unselectedPages.setBitmap(normalPage);
//    if (numberOfPages > 0)
//    {
//        setNumberOfPages(numberOfPages);
//    }
//}
//
//void CSwipeContainerEx::PageIndicator::goRight()
//{
//    setCurrentPage((currentPage + 1) % numberOfPages);
//}
//
//void CSwipeContainerEx::PageIndicator::goLeft()
//{
//    setCurrentPage((currentPage + numberOfPages - 1) % numberOfPages);
//}
//
//void CSwipeContainerEx::PageIndicator::setCurrentPage(uint8_t page)
//{
//    if (page < numberOfPages && page != currentPage)
//    {
//        currentPage = page;
//        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
//        selectedPage.moveTo(page * dotWidth, selectedPage.getY());
//    }
//}
//
//uint8_t CSwipeContainerEx::PageIndicator::getNumberOfPages() const
//{
//    return numberOfPages;
//}
//
//uint8_t CSwipeContainerEx::PageIndicator::getCurrentPage() const
//{
//    return currentPage;
//}
//} // namespace touchgfx
