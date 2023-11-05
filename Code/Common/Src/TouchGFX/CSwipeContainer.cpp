
#include <touchgfx/Application.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Drawable.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>

#include <CSwipeContainer.hpp>

namespace touchgfx
{
CSwipeContainer::CSwipeContainer(bool verticalSwipe)
    : Container(),
      currentState(NO_ANIMATION),
      animationCounter(0),
      swipeCutoff(80),
      dragX(0),
      animateDistance(0),
      startX(0),
      endElasticWidth(30),
      pages(EAST),
      pageIndicator(verticalSwipe)
{
    Application::getInstance()->registerTimerWidget(this);

    setTouchable(true);

    vertical = verticalSwipe;
    if(vertical)
		pages.setDirection(SOUTH);

	Container::add(pages);
    Container::add(pageIndicator);
}

CSwipeContainer::~CSwipeContainer()
{
    Application::getInstance()->unregisterTimerWidget(this);
}

void CSwipeContainer::add(Drawable& page)
{
    pages.add(page);

    pageIndicator.setNumberOfPages(getNumberOfPages() + 1);
    setSelectedPage(getSelectedPage());

    setWidthHeight(page);
}

void CSwipeContainer::remove(Drawable& page)
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

void CSwipeContainer::setEndSwipeElasticWidth(uint16_t width)
{
    endElasticWidth = width;
}

void CSwipeContainer::setSwipeCutoff(uint16_t cutoff)
{
    swipeCutoff = cutoff;
}

void CSwipeContainer::setPageIndicatorBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
{
    pageIndicator.setBitmaps(normalPage, highlightedPage);
}

void CSwipeContainer::setPageIndicatorXY(int16_t x, int16_t y)
{
	if(vertical)
		pageIndicator.setXY(y+24, x);
	else
		pageIndicator.setXY(x, y);
}

void CSwipeContainer::setPageIndicatorXYWithCenteredX(int16_t x, int16_t y)
{
    setPageIndicatorCenteredX(x);
    pageIndicator.setY(y);
}

void CSwipeContainer::setPageIndicatorCenteredX()
{
    setPageIndicatorCenteredX(getWidth() / 2);
}

void CSwipeContainer::setPageIndicatorCenteredX(int16_t x)
{
    pageIndicator.setX(x - pageIndicator.getWidth() / 2);
}

void CSwipeContainer::setSelectedPage(uint8_t pageIndex)
{
    if (pageIndex < getNumberOfPages())
    {
        pageIndicator.setCurrentPage(pageIndex);
        adjustPages();
    }
}

uint8_t CSwipeContainer::getSelectedPage() const
{
    return pageIndicator.getCurrentPage();
}

void CSwipeContainer::handleTickEvent()
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

void CSwipeContainer::handleClickEvent(const ClickEvent& event)
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

void CSwipeContainer::handleDragEvent(const DragEvent& event)
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

void CSwipeContainer::handleGestureEvent(const GestureEvent& event)
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

void CSwipeContainer::adjustPages()
{
    pages.moveTo(-static_cast<int16_t>(getSelectedPage() * getWidth()) + dragX, 0);
}

void CSwipeContainer::animateSwipeCancelledLeft()
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

void CSwipeContainer::animateSwipeCancelledRight()
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

void CSwipeContainer::animateLeft()
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

void CSwipeContainer::animateRight()
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

CSwipeContainer::PageIndicator::PageIndicator(bool verticalSwipe)
    : Container(),
      unselectedPages(),
      selectedPage(),
      numberOfPages(0),
      currentPage(255)   //To force an initial page indicator update
//      currentPage(0)
{
	vertical = verticalSwipe;

    unselectedPages.setXY(0, 0);
    selectedPage.setXY(0, 0);

    Container::add(unselectedPages);
    Container::add(selectedPage);
}

void CSwipeContainer::PageIndicator::setNumberOfPages(uint8_t size)
{
    numberOfPages = size;

    assert(numberOfPages > 0 && "At least one dot is needed");

    if (unselectedPages.getBitmapId() != BITMAP_INVALID)
    {
        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
        if(vertical)
        	unselectedPages.setHeight(dotWidth * size);
        else
            unselectedPages.setWidth(dotWidth * size);

        // adjust size of container according to the actual bitmaps
        setWidthHeight(unselectedPages);
        setCurrentPage(MIN(size, currentPage));

        invalidateContent();
    }
}

void CSwipeContainer::PageIndicator::setBitmaps(const Bitmap& normalPage, const Bitmap& highlightedPage)
{
    selectedPage.setBitmap(highlightedPage);
    unselectedPages.setBitmap(normalPage);
    if (numberOfPages > 0)
    {
        setNumberOfPages(numberOfPages);
    }
}

void CSwipeContainer::PageIndicator::goRight()
{
    setCurrentPage((currentPage + 1) % numberOfPages);
}

void CSwipeContainer::PageIndicator::goLeft()
{
    setCurrentPage((currentPage + numberOfPages - 1) % numberOfPages);
}

void CSwipeContainer::PageIndicator::setCurrentPage(uint8_t page)
{
    if (page < numberOfPages && page != currentPage)
    {
        currentPage = page;
        int dotWidth = Bitmap(unselectedPages.getBitmap()).getWidth();
        if(vertical)
        	selectedPage.moveTo(selectedPage.getX(), (numberOfPages * dotWidth) - ((page+1) * dotWidth));
        else
        	selectedPage.moveTo(page * dotWidth, selectedPage.getY());
    }
}

uint8_t CSwipeContainer::PageIndicator::getNumberOfPages() const
{
    return numberOfPages;
}

uint8_t CSwipeContainer::PageIndicator::getCurrentPage() const
{
    return currentPage;
}
} // namespace touchgfx






//
//#include <CSwipeContainer.hpp>
//#include "cfg.h"
//
//
//namespace touchgfx
//{
//
//CSwipeContainer::CSwipeContainer()
//	: SwipeContainer()
//{
//
//}
//
//void CSwipeContainer::handleClickEvent(const ClickEvent& event)
//{
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		SwipeContainer::handleClickEvent(event);
//	else
//	{
//	}
//}
//
//}
