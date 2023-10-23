
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
//         File : cfg_profile.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Product configuration profile implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "cfg_profile.h"


//=============================================================================
//  P R O F I L E   I N I T I A L I Z A T I O N
//-----------------------------------------------------------------------------
#ifdef PROJECT_APP
const CFG_Data_t __attribute__((section(".app_data"))) CFG_ProfileData =
{
	.DefHeatSP         = CFG_PRO_HEAT_SP,
	.DefCoolSP         = CFG_PRO_COOL_SP,
	.Prop              = CFG_PRO_PROP,
	.CoolInt           = CFG_PRO_COOL_INT,
	.HeatInt           = CFG_PRO_HEAT_INT,
	.MinHeatSP         = CFG_PRO_MIN_HEAT_SP,
	.MaxHeatSP         = CFG_PRO_MAX_HEAT_SP,
	.MinCoolSP         = CFG_PRO_MIN_COOL_SP,
	.MaxCoolSP         = CFG_PRO_MAX_COOL_SP,
	.UnocHeatOff       = CFG_PRO_UNOC_HEAT_Off,
	.UnocCoolOff       = CFG_PRO_UNOC_COOL_Off,
	.UnocHeatSPLim     = CFG_PRO_UNOC_HEAT_SP_LIM,
	.UnocCoolSPLim     = CFG_PRO_UNOC_COOL_SP_LIM,
	.DOSource          = CFG_PRO_DO_SOURCE,
	.DOSP              = CFG_PRO_DO_SP,
	.DOMode            = CFG_PRO_DO_MODE,
	.DOBand            = CFG_PRO_DO_BAND,
	.DORevAct          = CFG_PRO_DO_REV_ACT,
	.AOSource          = CFG_PRO_AO_SOURCE,
	.AOSP              = CFG_PRO_AO_SP,
	.AOMode            = CFG_PRO_AO_MODE,
	.AOBand            = CFG_PRO_AO_BAND,
	.AORevAct          = CFG_PRO_AO_REV_ACT,
	.AOPulsed          = CFG_PRO_AO_PULSED,
	.AORange           = CFG_PRO_AO_RANGE,
	.GrpCode1          = CFG_PRO_GRP_CODE1,
	.GrpCode2          = CFG_PRO_GRP_CODE2,
	.GrpCode3          = CFG_PRO_GRP_CODE3,
	.GrpWeight1        = CFG_PRO_GRP_WEIGHT1,
	.GrpWeight2        = CFG_PRO_GRP_WEIGHT2,
	.GrpWeight3        = CFG_PRO_GRP_WEIGHT3,
	.GblWeight         = CFG_PRO_GLB_WEIGHT,
	.RoomTempCal       = CFG_PRO_ROOM_TEMP_CAL,
	.UnocModeOverrTime = CFG_PRO_UNOC_MODE_OVERR_TIME,
	.RadFloorId        = CFG_PRO_UNOC_MODE_OVERR_TIME,
	.MinSlabTemp       = CFG_PRO_MIN_SLAB_TEMP,
	.MaxSlabTemp       = CFG_PRO_MAX_SLAB_TEMP,
	.MinSlabTempUnoc   = CFG_PRO_MIN_SLAB_TEMP_UNOC,
	.OutTempRadCutOff  = CFG_PRO_OUT_TEMP_RAD_CUTOFF,
	.RadProp           = CFG_PRO_RAD_PROP,
	.RadInt            = CFG_PRO_RAD_INT,
	.CalAuxInTemp      = CFG_PRO_CAL_AUX_IN_TEMP,
	.RadCycleTime      = CFG_PRO_RAD_CYCLE_TIME,
	.AIMode            = CFG_PRO_AI_MODE,
	.MorningWarmUpTime = CFG_PRO_MORNING_WARMUP_TIME,
	//-------------------------
	.Address           = CFG_PRO_ADDRESS,
	.TempUnit          = CFG_PRO_TEMP_UNIT,
	.Location          = CFG_PRO_LOCATION,
	.BaudRate          = CFG_PRO_BAUDRATE,
	.Parity            = CFG_PRO_PARITY,
	.StopBits          = CFG_PRO_STOPBITS,
	.Language          = CFG_PRO_LANGUAGE,
	//-------------------------
	.DisMinSP          = CFG_PRO_DIS_MIN_SP,
	.DisMidSP          = CFG_PRO_DIS_MID_SP,
	.DisMaxSP          = CFG_PRO_DIS_MAX_SP,
	.DisMinDem         = CFG_PRO_DIS_MIN_DEM,
	.DisMidDem         = CFG_PRO_DIS_MID_DEM,
	.DisMaxDem         = CFG_PRO_DIS_MAX_DEM,
	.DisProp           = CFG_PRO_DIS_PROP,
	.DisInt            = CFG_PRO_DIS_INT,
	.DisMode           = CFG_PRO_DIS_MODE,
	.IntDropRate       = CFG_PRO_DIS_DROP_RATE,
	.DOOverr           = CFG_PRO_DO_OVERR,
	.AOOverr           = CFG_PRO_AO_OVERR,
	.SchOverr          = CFG_PRO_SCH_OVERR,
	//-------------------------
	.ScrOrientation    = CFG_PRO_SCR_ORIENTATION,
	.ScrBrightness     = CFG_PRO_SCR_BRIGHTNESS,
	.ScrTimeout        = CFG_PRO_SCR_TIMEOUT
};
#endif
