#include "TextPrimitives.h"

TextPrimitives::TextPrimitives()
{
	_text = new osgText::Text;
	osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
	_text->setFont(g_font.get());
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);	// <�����ֵĴ�С������ͼ�� �ķŴ���С���ı䣬���ԾͰ�������ʾ����Ļ�����ĸ�ʽ>
	_text->setAxisAlignment(osgText::Text::SCREEN);							// <����ʼ�ձ��ִ�ֱ����Ļ����������ͼ�ε���ת����ת>
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


