
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
#include <stddef.h>
#include <CImage.hpp>
#include <CButton.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//class CMenuItem : public Container
//{
//	const uint8_t buttonTextColorReleasedR = 255;
//	const uint8_t buttonTextColorReleasedG = 255;
//	const uint8_t buttonTextColorReleasedB = 255;
//	const uint8_t buttonTextColorPressedR = 75;
//	const uint8_t buttonTextColorPressedG = 75;
//	const uint8_t buttonTextColorPressedB = 75;
//
//	const int16_t itemWidth = 500;
//	const int16_t itemHeight = 110;
//	const int16_t buttonHeight = 76;   //This is the height ot the button inside the image
//	const int16_t lineHeight = 4;      //This is the height of the separator line inside the image
//
//	const BitmapId lineImage = BITMAP_MENU_LINE_GRAY_494X494X4_ID;
//
//	CImage line;
//
//protected:
//	const BitmapId buttonImage = BITMAP_MENU_BUTTON_496X496X76_ID;
//
//	CButton button;
//
//public:
//	CMenuItem();
//
//	void setButtonText(const TypedText& textType);
//    void setButtonAction(GenericCallback<const AbstractButtonContainer&>& callback);
//    void setButtonGotoScreenId(ScreenId id);
//    CButton* getButton();
//
//    void transpose();
//};



class CMenuItem : public Container
{
	const uint8_t buttonTextColorReleasedR = 255;
	const uint8_t buttonTextColorReleasedG = 255;
	const uint8_t buttonTextColorReleasedB = 255;
	const uint8_t buttonTextColorPressedR = 75;
	const uint8_t buttonTextColorPressedG = 75;
	const uint8_t buttonTextColorPressedB = 75;

	const int16_t itemWidth = 500;
	const int16_t itemHeight = 110;
	const int16_t buttonHeight = 76;   //This is the height ot the button inside the image
	const int16_t lineHeight = 4;      //This is the height of the separator line inside the image

	const BitmapId buttonImage = BITMAP_MENU_BUTTON_496X496X76_ID;
	const BitmapId buttonImageSelected = BITMAP_MENU_SELECTED_496X496X76_ID;
	const BitmapId lineImage = BITMAP_MENU_LINE_GRAY_494X494X4_ID;

	CImage line;
	CButton* btnList;
	CButtonToggle* btnData;

public:
	enum menuMode {
		MenuModeList,
		MenuModeData
	};

	CMenuItem()
	{
		setWidthHeight(itemWidth, itemHeight);

		add(line);
		line.setXY(0, itemHeight - lineHeight);
		line.setBitmap(lineImage);

		btnList = NULL;
		btnData = NULL;
	}

	void setMode(menuMode mode)
	{
		if(mode == MenuModeList)
		{
			btnList = new CButton;
			add(*btnList);
			btnList->setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
			btnList->setBitmaps(buttonImage, buttonImage);
			btnList->setTouchHeight(76);
			btnList->setTextPosition(30, 4);
			btnList->setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
					               Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
		}
		else
		{
			btnData = new CButtonToggle;
			add(*btnData);
			btnData->setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
			btnData->setBitmaps(buttonImage, buttonImageSelected);
			btnData->setTouchHeight(76);
			btnData->setTextPosition(30, 4);
			btnData->setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
					               Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
		}
	}
	menuMode getMode()
	{
		if(btnList)
			return MenuModeList;
		return MenuModeData;
	}

	const CButton* getButtonList()
	{
		return btnList;
	}

	const CButtonToggle* getButtonData()
	{
		return btnData;
	}

	void setText(const TypedText& textType)
	{
		if(btnList)
			btnList->setText(textType);
		else
			btnData->setText(textType);
	}

	void setAction(GenericCallback<const AbstractButtonContainer&>& callback)
	{
		if(btnList)
			btnList->setAction(callback);
		else
			btnData->setAction(callback);
	}

	void setNextScreenId(ScreenId id)
	{
		if(btnList)
			btnList->setGotoScreenId(id);
		else
			btnData->setGotoScreenId(id);
	}
	ScreenId getNextScreenId()
	{
		if(btnList)
			return btnList->getGotoScreenId();
		return btnData->getGotoScreenId();
	}

	void setData(uint32_t data)
	{
		if(btnList)
			btnList->setData(data);
		else
			btnData->setData(data);
	}
	uint32_t getData()
	{
		if(btnList)
			return btnList->getData();
		return btnData->getData();
	}

	bool getState()
	{
		return btnData->getState();
	}

    void transpose()
    {
		if(dsp.orientation != CDisplay::NATIVE)
		{
			dsp.transpose(*this);
			line.transpose();
			if(btnList)
				btnList->transpose();
			else
				btnData->transpose();
		}

		invalidate();
    }
};



//class CMenuItemList : public CMenuItem
//{
//	const BitmapId buttonImage = BITMAP_MENU_BUTTON_496X496X76_ID;
//
//	CButton button;
//
//public:
//	CMenuItemList()
//	{
//		add(button);
//		button.setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
//		button.setBitmaps(buttonImage, buttonImage);
//		button.setTouchHeight(76);
//		button.setTextPosition(30, 4);
//		button.setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
//				             Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
//	}
//
//	virtual void setButtonText(const TypedText& textType)
//	{
//		button.setText(textType);
//	}
//
//	virtual void setButtonAction(GenericCallback<const AbstractButtonContainer&>& callback)
//	{
//
//	}
//
//	virtual void setButtonGotoScreenId(ScreenId id)
//	{
//
//	}
//
//	CButton* getButton()
//	{
//		return &button;
//	}
//
//	virtual void transpose()
//	{
//		if(dsp.orientation != CDisplay::NATIVE)
//		{
//			dsp.transpose(*this);
//			line.transpose();
//			button.transpose();
//		}
//
//		invalidate();
//	}
//};
//
//
//
//class CMenuItemData : public CMenuItem
//{
//	const BitmapId buttonImageOff = BITMAP_MENU_BUTTON_496X496X76_ID;
//	const BitmapId buttonImageOn = BITMAP_MENU_SELECTED_496X496X76_ID;
//
//	CButtonToggle button;
//
//public:
//	CMenuItemData()
//	{
//		add(button);
//		button.setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
//		button.setBitmaps(buttonImageOff, buttonImageOn);
//		button.setTouchHeight(76);
//		button.setTextPosition(30, 4);
//		button.setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
//				             Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
//	}
//
//	virtual void setButtonText(const TypedText& textType)
//	{
//		button.setText(textType);
//	}
//
//	virtual void setButtonAction(GenericCallback<const AbstractButtonContainer&>& callback)
//	{
//
//	}
//
//	virtual void setButtonGotoScreenId(ScreenId id)
//	{
//
//	}
//
//	CButtonToggle* getButton()
//	{
//		return &button;
//	}
//
//	virtual void transpose()
//	{
//		if(dsp.orientation != CDisplay::NATIVE)
//		{
//			dsp.transpose(*this);
//			line.transpose();
//			button.transpose();
//		}
//
//		invalidate();
//	}
//};

}   //namespace touchgfx


#endif   //CMENU_ITEM_HPP
