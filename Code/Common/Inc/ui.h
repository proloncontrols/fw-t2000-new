
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//-----------------------------------------------------------------------------
//         File : ui.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : User-Intrerface header file
//=============================================================================
#ifndef UI_H
#define UI_H

#ifdef UI_GLOBAL
#define UI_EXTERN
#else
#define UI_EXTERN   extern
#endif

#ifdef __cplusplus
extern "C" {
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "cmsis_os2.h"
#include "basic.h"
#include "com.h"
#include "env.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define UI_TEXT_STRING_LENGTH   16   //Maximum text string length in characters


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	UiScreenIdClear,
	UiScreenIdMain
} UI_ScreenId_t;

typedef enum {
	UiScreenActionSwitch,
} UI_ScreenAction_t;

typedef struct {
	UI_ScreenAction_t Action;
	UI_ScreenId_t Id;
} UI_ScreenActionSwitch_t;

typedef union {
	UI_ScreenAction_t Action;
	UI_ScreenActionSwitch_t Switch;
} UI_Screen_t;



typedef enum {
	UiProgressActionInit,
	UiProgressActionInc
} UI_ProgressAction_t;

typedef struct {
	UI_ProgressAction_t Action;
	uint32_t Steps;
} UI_ProgressActionInit_t;

typedef struct {
	UI_ProgressAction_t Action;
} UI_ProgressActionInc_t;

typedef union {
	UI_ProgressAction_t Action;
	UI_ProgressActionInit_t Initialize;
	UI_ProgressActionInc_t Increment;
} UI_Progress_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
UI_EXTERN osEventFlagsId_t   UI_Flags;
UI_EXTERN osMessageQueueId_t UI_QueueEnv;
UI_EXTERN osMessageQueueId_t UI_QueueScreen;
UI_EXTERN osMessageQueueId_t UI_QueueProgress;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void     UI_Init               (void);
extern void     UI_ScreenOn           (void);
extern void     UI_ScreenOff          (void);
extern void     UI_ScreenTimeout      (uint16_t Timeout);      //Validate screen OFF timer and turn OFF if needed
extern void     UI_ScreenTimeoutReset (void);                  //Reset screen OFF timeout timer
extern void     UI_ScreenSwitchTo     (UI_ScreenId_t Id);      //Switch to specified screen
extern void     UI_ScreenSwitchCplt   (void);
extern void     UI_ProgressInit       (uint32_t Steps);
extern void     UI_ProgressInc        (void);
extern void     UI_PostEnv            (ENV_Readings_t* Env);   //Post environmental data to display on LCD



#ifdef __cplusplus
}
#endif

#endif   //UI_H























