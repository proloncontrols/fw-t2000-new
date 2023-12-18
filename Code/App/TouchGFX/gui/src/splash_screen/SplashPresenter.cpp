#include <gui/splash_screen/SplashView.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>

SplashPresenter::SplashPresenter(SplashView& v)
    : view(v)
{

}

void SplashPresenter::activate()
{

}

void SplashPresenter::deactivate()
{

}

void SplashPresenter::DisplayEnv(ENV_Readings_t* Env)
{
	view.updateEnvironment(Env);
}

void SplashPresenter::moveIt()
{
	view.moveIt();
}
