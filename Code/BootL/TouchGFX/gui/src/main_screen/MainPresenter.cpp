#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::DisplayVersion(uint16_t Version)
{
	view.DisplayVersion(Version);
}

void MainPresenter::ProgressInitialize(uint32_t Steps)
{
	view.ProgressInitialize(Steps);
}

void MainPresenter::ProgressIncrement()
{
	view.ProgressIncrement();
}

void MainPresenter::PostSystemReady()
{
	model->PostSystemReady();
}
