#ifndef MODEL_HPP
#define MODEL_HPP

#include "basic.h"
#include "ui.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void PostSystemReady();
    void PostSystemReset();

	UI_Text_t UiText;

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
