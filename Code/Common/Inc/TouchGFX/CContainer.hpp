
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
//         File : CContainer.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Container base class header file
//=============================================================================
#ifndef CCONTAINER_HPP
#define CCONTAINER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//class CContainer : public Container
//{
//	Container& owner;
//
//public:
//	CContainer(Container& ownerContainer)
//	          :owner(ownerContainer)
//	{
//	}
//
//	void render()
//	{
//		dsp.setPosition(*this, owner);
//
//		CContainer* c = (CContainer*)getFirstChild();
//		while(c)
//		{
//			c->render();
//			c = (CContainer*)c->getNextSibling();
//		}
//	}
//};



class CImage2 : public Container
{
	const float zAngleLandscape = -3.142;
    const float zAnglePortrait = 1.565;

	TextureMapper mapper;

public:
	CImage2(Container& owner)
	{
		owner.add(*this);
	}

	void setImage(BitmapId id)
	{
		mapper.setBitmap(id);

		if(dsp.orientation == CDisplay::LANDSCAPE)
			mapper.setAngles(0.0f, 0.0f, zAngleLandscape);

		if(dsp.orientation == CDisplay::PORTRAIT)
			mapper.setAngles(0.0f, 0.0f, zAnglePortrait);

		mapper.setScale(1.0f);
		mapper.setBitmapPosition(0.0f, 0.0f);
		mapper.setOrigo((float)(mapper.getWidth()/2), (float)(mapper.getHeight()/2), 1000.0f);
		mapper.setCameraDistance(1000.0f);
		mapper.setCamera(mapper.getWidth()/2, mapper.getHeight()/2);
		mapper.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

		add(mapper);
	}

	void render()
	{
		dsp.setPosition(mapper, *this);
	}
};



class CButton2 : public Container
{
	CImage2 img = CImage2(*this);

public:
	CButton2(Container& owner)
	{
		owner.add(*this);
	}
};

}   //namespace touchgfx


#endif   //CCONTAINER_HPP































