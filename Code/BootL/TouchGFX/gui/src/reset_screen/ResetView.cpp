#include <gui/reset_screen/ResetView.hpp>

ResetView::ResetView()
{

}

void ResetView::setupScreen()
{
    ResetViewBase::setupScreen();
}

void ResetView::tearDownScreen()
{
    ResetViewBase::tearDownScreen();
}

void ResetView::OnScreenTransitionEnd()
{
	presenter->PostSystemReset();
}
