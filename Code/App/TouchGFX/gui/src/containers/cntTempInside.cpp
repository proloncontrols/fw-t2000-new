//#include <CWidgets.hpp>
//
//cntTempInside::cntTempInside()
//{
//	const Font* font;
//	const GlyphNode* glyph;
//
//
//
//	Unicode::fromUTF8((uint8_t*)"1", txtTempIntegralUnitsBuffer, TXTTEMPINTEGRALUNITS_SIZE);
//
//	font = txtTempIntegralUnits.getTypedText().getFont();
//
//	glyph = font->getGlyph(txtTempIntegralUnits.getWildcard1()[0]);
//
//	txtTempIntegralUnits.setWidth(glyph->left + glyph->width());
//
//	txtTempIntegralUnits.setX(line1.getX() - 10 - txtTempIntegralUnits.getWidth());
//
//	txtTempIntegralUnits.invalidate();
//
//
//
//	Unicode::fromUTF8((uint8_t*)"1", txtTempIntegralTenthsBuffer, TXTTEMPINTEGRALTENTHS_SIZE);
//
//	font = txtTempIntegralTenths.getTypedText().getFont();
//
//	glyph = font->getGlyph(txtTempIntegralTenths.getWildcard1()[0]);
//
//	txtTempIntegralTenths.setWidth(glyph->left + glyph->width());
//
//	txtTempIntegralTenths.setX(txtTempIntegralUnits.getX() - 10 - txtTempIntegralTenths.getWidth());
//
//	txtTempIntegralTenths.invalidate();
//
//
//
//	Unicode::fromUTF8((uint8_t*)"-", txtTempIntegralSignBuffer, TXTTEMPINTEGRALSIGN_SIZE);
//
//	font = txtTempIntegralSign.getTypedText().getFont();
//
//	glyph = font->getGlyph(txtTempIntegralSign.getWildcard1()[0]);
//
//	txtTempIntegralSign.setWidth(glyph->left + glyph->width());
//
//	txtTempIntegralSign.setX(txtTempIntegralTenths.getX() - 10 - txtTempIntegralSign.getWidth());
//
//	txtTempIntegralSign.invalidate();
//
//
//
//
//
//
//
//
////	uint16_t len = Unicode::strlen(txtTempIntegral.getWildcard1());
//
//
//
//////	int16_t deltaX = (txtTempIntegral - getStringWidth(txtTempIntegral, TXTTEMPINTEGRAL_SIZE)) / 2;
////
//////	txtTempIntegral.setX(line1.getX() - getStringWidth(txtTempIntegral, TXTTEMPINTEGRAL_SIZE));
////
////
////	int16_t lineX = line1.getX();
////	int16_t widgetWidth = txtTempIntegral.getWidth();
////	int16_t textWidth = getStringWidth(txtTempIntegral, TXTTEMPINTEGRAL_SIZE);
////	int16_t deltaX = (widgetWidth - textWidth) / 2;
////
////
////	txtTempIntegral.setX(lineX - widgetWidth + deltaX);
////
////
//////	int16_t Indentation = txtTempIntegral.getIndentation();
//////	int16_t widgetWidth = txtTempIntegral.getWidth();
//////
//////	txtTempIntegral.resizeToCurrentTextWithAlignment();
//////	txtTempIntegral.setX(line1.getX() - txtTempIntegral.getWidth() + 10);
//}
//
//void cntTempInside::initialize()
//{
//    cntTempInsideBase::initialize();
//}
