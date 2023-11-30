
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
//         File : CMenuItem.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu item class header file
//=============================================================================
#ifndef CMENU_ITEM_HPP
#define CMENU_ITEM_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CButton.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{

typedef enum {
	buttonNone = -3,
	buttonHome = -2,
	buttonBack = -1,
	buttonUser =  0
} ButtonId;


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuItem : public Container
{
public:
	CMenuItem();
	void setText(char* newText);
    void setAction(GenericCallback<const AbstractButtonContainer&>& callback);
    CButton* getButton();

private:
	static const int16_t itemWidth = 500;
	static const int16_t itemHeight = 110;
	static const int16_t buttonHeight = 72;   //This is the height ot the button inside the image
	static const int16_t lineHeight = 3;      //This is the height of the separator line inside the image

    CButton button;
	CImage line;
    touchgfx::Box background;
};

}   //namespace touchgfx


#endif   //CMENU_ITEM_HPP
