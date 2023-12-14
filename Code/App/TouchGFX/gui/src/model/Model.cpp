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
	static int tmp = 0;

	if(osMessageQueueGet(UI_QueueEnv, &EnvReadings, NULL, 0) == osOK)
		modelListener->DisplayEnv(&EnvReadings);

	if(++tmp >= 25)
	{
		tmp = 0;
		modelListener->moveIt();
	}
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
