#ifndef __TEXTPRIMITIVES_H__
#define __TEXTPRIMITIVES_H__

#include <osgText/Font>
#include <osgText/Text>

#include "ITextPrimitives.h"


// <绘制文本的实现类，继承于ITextPrimitives接口类>
class TextPrimitives :public ITextPrimitives
{
public:
	
	// <构造函数，初始化私有成员> 
	TextPrimitives();

	// <设置文字显示的位置>
	virtual void setPosition(float x, float y, float z) override;

	// <设置文字的颜色，三个浮点值参数分别表示红、绿、蓝，透明度默认为1.0f>
	virtual void setColor(float red, float green, float blue) override;

	// <设置文字的大小>
	virtual void setSize(float size) override;

	// <设置文字的类型，默认值是"fonts/arial.ttf">
	virtual void setFontFile(const std::string& fontFile = "fonts/arial.ttf") override;

	// <设置文本的内容>
	virtual void setTextContent(const std::string& content) override;

	// <获取osgText::Text 类型 的指针>
	osgText::Text* getOsgText();


private:
	osg::ref_ptr<osgText::Text> _text;
	osg::ref_ptr<osgText::Font> _font;
};

#endif