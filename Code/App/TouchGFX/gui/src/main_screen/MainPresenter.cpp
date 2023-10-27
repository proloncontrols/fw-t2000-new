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

void MainPresenter::DisplayEnv(ENV_Readings_t* Env)
{
	view.DisplayEnv(Env);
}

void MainPresenter::PostSystemReady()
{
	model->PostSystemReady();
}
