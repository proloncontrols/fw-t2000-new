#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os2.h"
#include "app.h"
#include "ui.h"
#include "framework.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	UI_Progress_t Progress;

	if(osMessageQueueGet(APP_Queue, &Version, NULL, 0) == osOK)
		modelListener->DisplayVersion(Version);

	if(osMessageQueueGet(UI_QueueProgress, &Progress, NULL, 0) == osOK)
	{
		if(Progress.Name == UiPrgInit)
			modelListener->ProgressInitialize(Progress.Initialize.Steps);

		if(Progress.Name == UiPrgInc)
			modelListener->ProgressIncrement();
	}
}

void Model::PostSystemReady()
{
	FMK_PostSystemEvent(FmkSysEvtRdy);
}

void Model::PostSystemReset()
{
	FMK_PostSystemEvent(FmkSysEvtRst);
}
