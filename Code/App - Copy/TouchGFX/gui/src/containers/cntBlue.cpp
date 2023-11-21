#include <gui_generated/containers/cntBlueBase.hpp>
#include <gui/containers/cntBlue.hpp>
#include <CScreen.hpp>
#include <CWidgets.hpp>

cntBlue::cntBlue()
{
	rotateBox(box1);

	rotateTextureMapper(textureMapper1);
	rotateTextureMapper(textureMapper2);
	rotateTextureMapper(textureMapper3);
	rotateTextureMapper(textureMapper4);
	rotateTextureMapper(textureMapper5);
	rotateTextureMapper(textureMapper6);
	rotateTextureMapper(textureMapper7);

	rotateTextArea(textArea1);
}

void cntBlue::initialize()
{
    cntBlueBase::initialize();
}