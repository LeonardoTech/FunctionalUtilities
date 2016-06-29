#include "TextPrimitive.h"
#include "FontShader.h"

// <构造函数>
#pragma region TextPrimitives

TextPrimitive::TextPrimitive()
{
	_text = new osgText::Text;
	 _font = new osgText::Font;

	 std::string defaultFont;
#if defined(Android)
	 defaultFont = "/system/fonts/DroidSansFallback.ttf";
#elif defined(_WIN32)
	 defaultFont = "fonts/arial.ttf";
#endif

	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);	// <让文字的大小不随着图形 的放大缩小而改变，所以就把文字显示成屏幕像数的格式>
	_text->setAxisAlignment(osgText::Text::SCREEN);							// <文字始终保持垂直于屏幕，不会随着图形的旋转而旋转>
	_text->setDataVariance(osg::Object::DYNAMIC);
	setFontFile(defaultFont);
	bimWorld::FontShader shader;
	shader.apply(_text->getOrCreateStateSet());
	_text->setCharacterSize(18);
}

#pragma endregion

#pragma region SetFontFile

void TextPrimitive::setFontFile(const std::string& fontFile)
{
	//_font = osgText::readFontFile("fonts/arial.ttf");
	_font = osgText::readFontFile(fontFile);
	_text->setFont(_font.get());
}

#pragma endregion

#pragma region SetPosition

void TextPrimitive::setPosition(float x, float y, float z)
{
	_text->setPosition(osg::Vec3{ x, y, z });
}

#pragma endregion

#pragma region SetColor

void TextPrimitive::setColor(float red, float green, float blue)
{
	_text->setColor(osg::Vec4{ red, green, blue, 1.0f });
}

#pragma endregion

#pragma region SetSize

void TextPrimitive::setSize(float size)
{
	_text->setCharacterSize(size);
}

#pragma endregion

#pragma region SetContent

void TextPrimitive::setTextContent(const std::string& content)
{
	_text->setText(content); 
}

#pragma endregion

#pragma region GetOsgText

osgText::Text* TextPrimitive::getOsgText()
{
	return _text;
	//return NULL;
}

#pragma endregion
