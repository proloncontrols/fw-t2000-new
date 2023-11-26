
#include "event.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	osEventFlagsId_t Flags;
	osMessageQueueId_t Queue;
} EVT_t;


static EVT_t EVT;


void EVT_Init(osEventFlagsId_t AppFlags)
{
	EVT.Flags = AppFlags;
	EVT.Queue = osMessageQueueNew(1, sizeof(EVT_Data_t), NULL);
}

//void EVT_PostToApp(EVT_Event_t* Event)
void EVT_PostToApp(EVT_Group_t Group, EVT_Event_t Event, EVT_DataType_t DataType, void* Data)
{
}

//void EVT_PostToGfx(EVT_Event_t* Event)
//{
//}


#ifdef __cplusplus
}
#endif
