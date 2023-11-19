//
////=============================================================================
////         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
////         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
////         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
////         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
////         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
////
////                        (c) Copyright  2022-2023
////-----------------------------------------------------------------------------
////         File : CMeterTempExt.cpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : Exterior temperature meter widget class implementation file
////=============================================================================
//
//
////=============================================================================
////  I N C L U D E S
////-----------------------------------------------------------------------------
//#include <CWidgets.hpp>
//#include <CMeterTempExt.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
//#include <BitmapDatabase.hpp>
//
//
//namespace touchgfx
//{
//
////=============================================================================
////  D E F I N E S
////-----------------------------------------------------------------------------
//#define COLOR_RED     186
//#define COLOR_GREEN   188
//#define COLOR_BLUE    190
//#define IMAGE_ID      BITMAP_OUTSIDE_24X24_ID
//
//
////=============================================================================
////  C O N S T R U C T O R S
////-----------------------------------------------------------------------------
//CMeterTempExt::CMeterTempExt()
//	: CMeterTemp(COLOR_RED, COLOR_GREEN, COLOR_BLUE, touchgfx::TypedText(T_T2000_METER_SMALL), touchgfx::TypedText(T_T2000_METER_TINY))
//{
//    image.setXY(0, 0);
//    image.setBitmap(touchgfx::Bitmap(IMAGE_ID));
//    Bitmap img = image.getBitmap();
//    image.setWidth(img.getWidth());
//    image.setHeight(img.getHeight());
//    image.setBitmapPosition(0.0f, 0.0f);
//    image.setScale(1.0f);
//    image.setCameraDistance(1000.0f);
//    image.setOrigo(90.0f, 90.0f, 1000.0f);
//    image.setCamera(image.getWidth()/2, image.getHeight()/2);
//    image.setAngles(0.0f, 0.0f, 0.0f);
//    image.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
//    rotateTextureMapper(image);
//    add(image);
//}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CMeterTempExt::display(double value, bool celsius)
//{
//	CMeterTemp::display(value, celsius);
//
//	setWidth(MAX(getWidth(), unit.getX() + image.getWidth() + firstCharLeftWidth));
//    image.setXY(unit.getX() + firstCharLeftWidth, curBaseline - image.getHeight());
//	background.setPosition(*this);
//}
//
//}   //namespace touchgfx
