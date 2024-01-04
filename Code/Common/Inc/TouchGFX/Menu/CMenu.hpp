
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
//         File : CMenu.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu base class header file
//=============================================================================
#ifndef CMENU_HPP
#define CMENU_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CApp.hpp>
#include <CImage.hpp>
#include <CButton.hpp>
#include <Menu/CMenuItem.hpp>
#include <Menu/CMenuItemSelection.hpp>
#include <Screen/CScreen.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Containers/Listlayout.hpp>
#include <touchgfx/Containers/ScrollableContainer.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//class CMenu : public CScreen
//{
//	const uint8_t titleColorR = 255;
//	const uint8_t titleColorG = 255;
//	const uint8_t titleColorB = 255;
//
//	const BitmapId homeImageReleased = BITMAP_HOME_60X60_ID;
//	const BitmapId homeImagePressed = BITMAP_HOME_60X60_ID;
//	const BitmapId backImageReleased = BITMAP_RETURN_50X50_ID;
//	const BitmapId backImagePressed = BITMAP_RETURN_50X50_ID;
//	const BitmapId logoImage = BITMAP_PROLON_178X178_ID;
//	const BitmapId lineImage = BITMAP_MENU_LINE_WHITE_496X496X6_ID;
//
//	CImage logo;
//	CImage line;
//	CLabel title;
//	ListLayout items;
//	ScrollableContainer scroll;
//
//protected:
//	CButton home;
//	CButton back;
//
//    void setTitle(const TypedText& textType);
//	void setItems(CMenuItemList* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);
//	void setItems(CMenuItemData* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);
//
//public:
//	CMenu(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback);
//
//	ButtonId getButtonId(const AbstractButtonContainer& src);
//	void transpose();
//
//    Callback<CMenu, const AbstractButtonContainer&> btnCallback;
//    void onButtonClicked(const AbstractButtonContainer& src) {}
//};





class CMenu : public CScreen
{
	const uint8_t titleColorR = 255;
	const uint8_t titleColorG = 255;
	const uint8_t titleColorB = 255;

	const BitmapId homeImageReleased = BITMAP_HOME_60X60_ID;
	const BitmapId homeImagePressed = BITMAP_HOME_60X60_ID;
	const BitmapId backImageReleased = BITMAP_RETURN_50X50_ID;
	const BitmapId backImagePressed = BITMAP_RETURN_50X50_ID;
	const BitmapId logoImage = BITMAP_PROLON_178X178_ID;
	const BitmapId lineImage = BITMAP_MENU_LINE_WHITE_496X496X6_ID;

	CImage logo;
	CLabel title;
	ScrollableContainer scroll;

protected:
	CButton home;
	CButton back;
	CImage line;
	ListLayout items;

    void setTitle(const TypedText& textType);
//	void setItems(CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);
//	void setItems(CMenuItem* itemsList, int itemsCount, GenericCallback<uint32_t, uint32_t>& callback);
//	void setItems(CMenuItemData* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);
//	void setItems(CMenuItemList* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);
//	void setItems(CMenuItemData* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);

//    virtual void onButtonClicked(const AbstractButtonContainer& src) {}

public:
//	CMenu(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback);
	CMenu(Container& owner);

	ButtonId getButtonId(const AbstractButtonContainer& src);
	void transpose();

//    Callback<CMenu, const AbstractButtonContainer&> btnCallback;
};





class CMenuList : public CMenu
{
    Callback<CMenuList, const AbstractButtonContainer&> internalCallback;
//    GenericCallback<const CButton&>* externalCallback;
//    GenericCallback<ScreenId>* externalCallback;
    GenericCallback<uint32_t, uint32_t>* externalCallback;

    void internalButtonClicked(const AbstractButtonContainer& src)
    {




//    	ScreenId nextScreen = ((CButton*)&src)->getGotoScreenId();

//    	if(&src == &home)
//    		nextScreen = ScreenId::ScreenHome;
//
//    	else
//    	{
//			CMenuItem* item = (CMenuItem*)items.getFirstChild();
//			while(item)
//			{
//				if(&src == item->getButtonList())
//	    			nextScreen = item->getNextScreenId();
//				item = (CMenuItem*)item->getNextSibling();
//			}
//    	}

//    	externalCallback->execute((uint32_t)nextScreen, 0);

    	externalCallback->execute(((CButton*)&src)->getGotoScreenId(), 0);
    }

public:
//	CMenuList(Container& owner, GenericCallback<const CButton&>& extCallback)
//	CMenuList(Container& owner, GenericCallback<ScreenId>& extCallback)
	CMenuList(Container& owner, GenericCallback<uint32_t, uint32_t>& extCallback)
	         :CMenu(owner),
			  internalCallback(this, &CMenuList::internalButtonClicked),
			  externalCallback(&extCallback)
	{
		home.setAction(internalCallback);
		back.setAction(internalCallback);
	}

//	void setItems(CMenuItemList* itemsList, int itemsCount, GenericCallback<uint32_t, uint32_t>& callback)
	void setItems(CMenuItemList* itemsList, int itemsCount)
	{
		client.add(items);
		items.setDirection(SOUTH);
		items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line

		for(int i = 0; i < itemsCount; i++)
		{
			itemsList[i].setInternalAction(internalCallback);
			itemsList[i].setData(i);
			items.add(itemsList[i]);
		}
	}
};







class CMenuData : public CMenu
{
    Callback<CMenuData, const AbstractButtonContainer&> internalCallback;

    void internalButtonClicked(const AbstractButtonContainer& src)
    {
    }

public:
	CMenuData(Container& owner, GenericCallback<const CButtonToggle&>& extCallback)
	         :CMenu(owner),
			  internalCallback(this, &CMenuData::internalButtonClicked)
	{
		home.setAction(internalCallback);
		back.setAction(internalCallback);
	}

//	void setItems(CMenuItemData* itemsList, int itemsCount, GenericCallback<uint32_t, uint32_t>& callback)
	void setItems(CMenuItemData* itemsList, int itemsCount)
	{
		client.add(items);
		items.setDirection(SOUTH);
		items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line

		for(int i = 0; i < itemsCount; i++)
		{
			itemsList[i].setInternalAction(internalCallback);
			itemsList[i].setData(i);
			items.add(itemsList[i]);
		}
	}
};





}   //namespace touchgfx


#endif   //CMENU_HPP















