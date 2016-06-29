#include "TextPrimitives.h"

TextPrimitives::TextPrimitives()
{
	_text = new osgText::Text;
	osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
	_text->setFont(g_font.get());
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);	// <让文字的大小不随着图形 的放大缩小而改变，所以就把文字显示成屏幕像数的格式>
	_text->setAxisAlignment(osgText::Text::SCREEN);							// <文字始终保持垂直于屏幕，不会随着图形的旋转而旋转>
	_text->setDataVariance(osg::Object::DYNAMIC);
}


void TextPrimitives::setPosition(float x, float y, float z)
{
	_text->setPosition(osg::Vec3{ x, y, z });
}

void TextPrimitives::setColor(float red, float green, float blue)
{
	_text->setColor(osg::Vec4{ red, green, blue, 1.0f });
}


void TextPrimitives::setSize(float size)
{
	_text->setCharacterSize(size);
}


