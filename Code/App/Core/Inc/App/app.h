
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
//         File : app.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Application header file
//=============================================================================
#ifndef APP_H
#define APP_H

#ifdef APP_GLOBAL
#define APP_EXTERN
#else
#define APP_EXTERN   extern
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"
#include "framework.h"
#include "com.h"
#include "env.h"


//=============================================================================
//  V E R S I O N
//-----------------------------------------------------------------------------
#define APP_VERSION   760   //Version 7.6.0


//=============================================================================
//  C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
#define APP_IDLE_PERIODIC_TIMEOUT   1000   //1 second


//=============================================================================
//  H A R D W A R E
//-----------------------------------------------------------------------------
#define APP_I2C_HW   hi2c5   //I2C bus for environment sensors and real-time-clock


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	bool_t         SplashDone;
	ENV_Readings_t Env;
} APP_Obj_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
APP_EXTERN osMessageQueueId_t APP_Queue;   //TODO: For test purposes only, to be revomed
APP_EXTERN APP_Obj_t          APP;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void APP_OnInitBegin  (void);
extern void APP_OnInitEnd    (void);
extern void APP_OnEntryBegin (void);
extern void APP_OnEntryEnd   (void);
extern void APP_OnPeriodic   (void);
extern void APP_OnCom        (COM_Connexion_t* Conx);
extern void APP_OnFlag       (uint32_t Flag);


#endif   //APP_H
