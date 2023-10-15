#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os2.h"
//#include "app.h"
#include "ui.h"
#include "framework.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
//	if(osMessageQueueGet(APP_Queue, &Version, NULL, 0) == osOK)
//		modelListener->DisplayVersion(Version);

	if(osMessageQueueGet(UI_QueueText, &UiText, NULL, 0) == osOK)
	{
		switch(UiText.TextLabel)
		{
			case UiTextTemp:
				modelListener->DisplayTemp(UiText.Text);
			break;
		}
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
