#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    void setPreviousScreen(touchgfx::ScreenId id)
    {
    	model->setPreviousScreen(id);
    };

    touchgfx::ScreenId getPreviousScreen()
    {
    	return model->getPreviousScreen();
    };





    virtual void DisplayEnv(ENV_Readings_t* Env) {};

    virtual void moveIt() {};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
