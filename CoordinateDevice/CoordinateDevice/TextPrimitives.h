#ifndef __TEXTPRIMITIVES_H__
#define __TEXTPRIMITIVES_H__
#include "ITextPrimitives.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osgText/Font>
#include <osgText/Text>

class TextPrimitives :public ITextPrimitives
{
public:
	TextPrimitives();

	virtual void setPosition(float x, float y, float z) override;

	virtual void setColor(float red, float green, float blue) override;

	
	virtual void drawGeometry() override;

	virtual void setSize(float size) override;

	void setText(string content);


	osgText::Text* getOsgText();


private:
	osg::ref_ptr<osgText::Text> _text;
};

#endif