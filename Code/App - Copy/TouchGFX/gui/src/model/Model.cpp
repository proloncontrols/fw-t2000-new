#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os2.h"
#include "ui.h"
#include "framework.h"

//-----------------------------------------------------------------------------
Model::Model() : modelListener(0)
{

}

//-----------------------------------------------------------------------------
void Model::tick()
{
	if(osMessageQueueGet(UI_QueueEnv, &EnvReadings, NULL, 0) == osOK)
		modelListener->DisplayEnv(&EnvReadings);
}

//-----------------------------------------------------------------------------
void Model::PostSystemReady()
{
	FMK_PostSystemEvent(FmkSysEvtRdy);
}

//-----------------------------------------------------------------------------
void Model::PostSystemReset()
{
	FMK_PostSystemEvent(FmkSysEvtRst);
}
