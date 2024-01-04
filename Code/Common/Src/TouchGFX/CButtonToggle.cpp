
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
//         File : CButtonToggle.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Toggle button class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CButtonToggle.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CButtonToggle::CButtonToggle()
{
	state = false;
}


//=============================================================================
//  E V E N T S
//-----------------------------------------------------------------------------
void CButtonToggle::handleClickEvent(const ClickEvent& event)
{
	bool wasPressed = getPressed();
	bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
	if((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
	{
		if(newPressedValue)
		{
			if(text)
				text->setColor(textColorPressed);
		}
		else
		{
			state = !state;
			if(state)
			{
				if(imgReleased)
					imgReleased->setVisible(true);
				if(imgPressed)
					imgPressed->setVisible(false);
			}
			else
			{
				if(imgReleased)
					imgReleased->setVisible(false);
				if(imgPressed)
					imgPressed->setVisible(true);
			}

			if(text)
				text->setColor(textColorReleased);
		}

		invalidate();

		setPressed(newPressedValue);
	}
	if(wasPressed && (event.getType() == ClickEvent::RELEASED))
		executeAction();
}



//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButtonToggle::setState(bool newState)
{
	state = newState;
}

bool CButtonToggle::getState()
{
	return state;
}

}   //namespace touchgfx
