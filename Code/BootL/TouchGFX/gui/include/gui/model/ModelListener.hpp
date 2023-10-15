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

    virtual void DisplayVersion(uint16_t Version) {};

    uint16_t GetVersion(void)
    {
    	return model->Version;
    }

    virtual void ProgressInitialize(uint32_t Steps) {};
    virtual void ProgressIncrement() {};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
