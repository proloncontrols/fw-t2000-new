#ifndef MODEL_HPP
#define MODEL_HPP

#include "basic.h"

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

    uint16_t Version;

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
