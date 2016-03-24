﻿#include "TextPrimitives.h"

// <构造函数>
#pragma region TextPrimitives

TextPrimitives::TextPrimitives()
{
	_text = new osgText::Text;
	 _font = new osgText::Font;
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);	// <让文字的大小不随着图形 的放大缩小而改变，所以就把文字显示成屏幕像数的格式>
	_text->setAxisAlignment(osgText::Text::SCREEN);							// <文字始终保持垂直于屏幕，不会随着图形的旋转而旋转>
	_text->setDataVariance(osg::Object::DYNAMIC);
	setFontFile();
}

#pragma endregion

#pragma region SetFontFile

void TextPrimitives::setFontFile(const std::string& fontFile )
{
	//_font = osgText::readFontFile("fonts/arial.ttf");
	_font = osgText::readFontFile(fontFile);
	_text->setFont(_font.get());
}

#pragma endregion

#pragma region SetPosition

void TextPrimitives::setPosition(float x, float y, float z)
{
	_text->setPosition(osg::Vec3{ x, y, z });
}

#pragma endregion

#pragma region SetColor

void TextPrimitives::setColor(float red, float green, float blue)
{
	_text->setColor(osg::Vec4{ red, green, blue, 1.0f });
}

#pragma endregion

#pragma region SetSize

void TextPrimitives::setSize(float size)
{
	_text->setCharacterSize(size);
}

#pragma endregion

#pragma region SetContent

void TextPrimitives::setTextContent(const std::string& content)
{
	_text->setText(content); 
}

#pragma endregion

#pragma region GetOsgText

osgText::Text* TextPrimitives::getOsgText()
{
	return _text;
}

#pragma endregion
