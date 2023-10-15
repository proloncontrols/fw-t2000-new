#include <gui/reset_screen/ResetView.hpp>
#include <gui/reset_screen/ResetPresenter.hpp>

ResetPresenter::ResetPresenter(ResetView& v)
    : view(v)
{

}

void ResetPresenter::activate()
{

}

void ResetPresenter::deactivate()
{

}

void ResetPresenter::PostSystemReset()
{
	model->PostSystemReset();
}
