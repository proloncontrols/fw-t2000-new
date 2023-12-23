
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
//         File : CScreenHome.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Home screen class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Screen/CScreenHome.hpp>
#include <BitmapDatabase.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CScreenHome::CScreenHome(Container& owner)
            :CScreen(owner)
{
	client.add(logo);
	logo.setBitmap(BITMAP_PROLON_178X178_ID);
	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);
	logo.transpose();

	client.add(standby);
	standby.setBitmap(BITMAP_STANDBY_MODE_58X58_ID);
	standby.setXY(client.getWidth() - standby.getWidth(), client.getHeight() - standby.getHeight());
	standby.transpose();

	client.add(cooling);
	cooling.setBitmap(BITMAP_COOLING_ON_576X576_ID);
	cooling.setXY((client.getWidth() - cooling.getWidth()) / 2, 50);
	cooling.transpose();

	client.add(snowflake);
	snowflake.setBitmap(BITMAP_SNOWFLAKE_50X50_ID);
	snowflake.setXY((client.getWidth() - snowflake.getWidth()) / 2, 440);
	snowflake.transpose();

	client.add(settings);
	settings.setBitmaps(BITMAP_SETTING_ID, BITMAP_SETTING_DARK2_ID);
	settings.setXY(client.getWidth() - settings.getWidth(), 1);
	settings.transpose();

	client.add(setpoints);
	setpoints.setWidthHeight(200, 200);
	setpoints.setXY((client.getWidth() - setpoints.getWidth()) / 2, (client.getHeight() - setpoints.getHeight()) / 2);
	setpoints.transpose();
}

}   //namespace touchgfx
