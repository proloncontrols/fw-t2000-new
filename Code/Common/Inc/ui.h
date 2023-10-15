
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


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define UI_TEXT_STRING_LENGTH   16   //Maximum text string length in characters


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	UiPrgInit,
	UiPrgInc
} UI_Prg_t;

typedef struct {
	UI_Prg_t Name;
	uint32_t Steps;
} UI_PrgInit_t;

typedef struct {
	UI_Prg_t Name;
} UI_PrgInc_t;

typedef union {
	UI_Prg_t Name;
	UI_PrgInit_t Initialize;
	UI_PrgInc_t Increment;
} UI_Progress_t;



typedef enum {
	UiScrIdReset,
	UiScrIdMain
} UI_ScrId_t;

typedef enum {
	UiScrSw,
} UI_Scr_t;

typedef struct {
	UI_Scr_t Name;
	UI_ScrId_t Id;
} UI_ScrSw_t;

typedef union {
	UI_Scr_t Name;
	UI_ScrSw_t ScreenSwitch;
} UI_Screen_t;



typedef enum {
	UiTextTemp
} UI_TextLabel_t;

typedef struct {
	UI_TextLabel_t TextLabel;
	uint8_t Text[UI_TEXT_STRING_LENGTH];
} UI_Text_t;


//=============================================================================
//  K E Y S
//-----------------------------------------------------------------------------
typedef enum {
	UiBtnTempUp,
	UiBtnTempDown
} UI_Btn_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
UI_EXTERN osMessageQueueId_t UI_QueueText;
UI_EXTERN osMessageQueueId_t UI_QueueScreen;
UI_EXTERN osMessageQueueId_t UI_QueueProgress;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void     UI_Init               (void);

extern void     UI_ScreenOn           (void);
extern void     UI_ScreenOff          (void);
extern void     UI_ScreenTimeout      (uint16_t Timeout);    //Validate screen OFF timer and turn OFF if needed
extern void     UI_ScreenTimeoutReset (void);                //Reset screen OFF timeout timer
extern void     UI_ScreenSwitchTo     (UI_ScrId_t Id);       //Switch to specified screen

//extern void     UI_PostBtn            (UI_Btn_t Button);     //Post button pressed from frontend for backend to retrieve
//extern UI_Btn_t UI_ReadBtn            (void);                //Retrieve button pressed posted by frontend
extern void     UI_PostText           (UI_Text_t* Text);     //Post text to display on LCD

//extern void     UI_PostEvent          (void);                //Used by backend to post event to application

extern void     UI_ProgressInit       (uint32_t Steps);
extern void     UI_ProgressInc        (void);

#ifdef __cplusplus
}
#endif

#endif   //UI_H
