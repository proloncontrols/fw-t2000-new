
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : cfg_profile_defaults.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Product configuration default profile header file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "cfg.h"


//=============================================================================
//  V A L U E S
//-----------------------------------------------------------------------------
#define CFG_PRO_HEAT_SP                2150
#define CFG_PRO_COOL_SP                2250
#define CFG_PRO_PROP                   300
#define CFG_PRO_COOL_INT               30
#define CFG_PRO_HEAT_INT               30
#define CFG_PRO_MIN_HEAT_SP            1900
#define CFG_PRO_MAX_HEAT_SP            2500
#define CFG_PRO_MIN_COOL_SP            2000
#define CFG_PRO_MAX_COOL_SP            2600
#define CFG_PRO_UNOC_HEAT_Off          300
#define CFG_PRO_UNOC_COOL_Off          500
#define CFG_PRO_UNOC_HEAT_SP_LIM       1500
#define CFG_PRO_UNOC_COOL_SP_LIM       3000
#define CFG_PRO_DO_SOURCE              0
#define CFG_PRO_DO_SP                  50
#define CFG_PRO_DO_MODE                1
#define CFG_PRO_DO_BAND                40
#define CFG_PRO_DO_REV_ACT             0
#define CFG_PRO_AO_SOURCE              0
#define CFG_PRO_AO_SP                  25
#define CFG_PRO_AO_MODE                0
#define CFG_PRO_AO_BAND                75
#define CFG_PRO_AO_REV_ACT             0
#define CFG_PRO_AO_PULSED              0
#define CFG_PRO_AO_RANGE               0
#define CFG_PRO_GRP_CODE1              0
#define CFG_PRO_GRP_CODE2              0
#define CFG_PRO_GRP_CODE3              0
#define CFG_PRO_GRP_WEIGHT1            0
#define CFG_PRO_GRP_WEIGHT2            0
#define CFG_PRO_GRP_WEIGHT3            0
#define CFG_PRO_GLB_WEIGHT             1
#define CFG_PRO_ROOM_TEMP_CAL          0
#define CFG_PRO_UNOC_MODE_OVERR_TIME   0
#define CFG_PRO_RAD_FLOOR_ID           0
#define CFG_PRO_MIN_SLAB_TEMP          2100
#define CFG_PRO_MAX_SLAB_TEMP          2700
#define CFG_PRO_MIN_SLAB_TEMP_UNOC     1900
#define CFG_PRO_OUT_TEMP_RAD_CUTOFF    1500
#define CFG_PRO_RAD_PROP               100
#define CFG_PRO_RAD_INT                60
#define CFG_PRO_CAL_AUX_IN_TEMP        0
#define CFG_PRO_RAD_CYCLE_TIME         15
#define CFG_PRO_AI_MODE                0
#define CFG_PRO_MORNING_WARMUP_TIME    0
//-------------------------
#define CFG_PRO_ADDRESS                123
#define CFG_PRO_TEMP_UNIT              CfgEnvTempC
#define CFG_PRO_LOCATION              {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0}
#define CFG_PRO_BAUDRATE               CfgComBaud57600
#define CFG_PRO_PARITY                 CfgComParityNone
#define CFG_PRO_STOPBITS               CfgComStopBits1
#define CFG_PRO_LANGUAGE               0
//-------------------------
#define CFG_PRO_DIS_MIN_SP             1300
#define CFG_PRO_DIS_MID_SP             2100
#define CFG_PRO_DIS_MAX_SP             3000
#define CFG_PRO_DIS_MIN_DEM           -100
#define CFG_PRO_DIS_MID_DEM            0
#define CFG_PRO_DIS_MAX_DEM            100
#define CFG_PRO_DIS_PROP               2000
#define CFG_PRO_DIS_INT                15
#define CFG_PRO_DIS_MODE               0
#define CFG_PRO_DIS_DROP_RATE          3
#define CFG_PRO_DO_OVERR               255
#define CFG_PRO_AO_OVERR               255
#define CFG_PRO_SCH_OVERR              255
//-------------------------
#define CFG_PRO_SCR_ORIENTATION        CfgScrOrientP
#define CFG_PRO_SCR_BRIGHTNESS         0
#define CFG_PRO_SCR_TIMEOUT            0
