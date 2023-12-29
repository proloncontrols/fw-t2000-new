#ifndef MODEL_HPP
#define MODEL_HPP

#include <CApp.hpp>
#include <Screen/CScreen.hpp>
#include "env.h"

class ModelListener;

class Model
{
	touchgfx::ScreenId previousScreen;

public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void PostSystemReady();
    void PostSystemReset();

	ENV_Readings_t EnvReadings;

    ModelListener* modelListener;
};

#endif // MODEL_HPP
