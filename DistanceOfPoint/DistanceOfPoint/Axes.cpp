
#include "Axes.h"

void Axes::drawGeomtry(float radius)
{
	LinePrimitives* linex = new LinePrimitives;
	linex->drawGeometry();
	linex->setStartPosition(0.0f, 0.0f, 0.0f);
	linex->setEndPosition(radius, 0.0f, 0.0f);
	linex->setColor(1.0f, 0.0f, 0.0f);
	linex->setLineWidth(0.03f*radius); 
	osg::ref_ptr<osg::Geometry> geomx= linex->getGeometry();
	osgUtil::SmoothingVisitor::smooth(*geomx);
	
	LinePrimitives* liney = new LinePrimitives;
	liney->drawGeometry();
	liney->setStartPosition(0.0f, 0.0f, 0.0f);
	liney->setEndPosition(0.0f, radius, 0.0f);
	liney->setColor(1.0f, 0.0f, 0.0f);
	liney->setLineWidth(0.03f*radius);
	osg::ref_ptr<osg::Geometry> geomy = linex->getGeometry();
	osgUtil::SmoothingVisitor::smooth(*geomy);

	LinePrimitives* linez = new LinePrimitives;
	linez->drawGeometry();
	linez->setStartPosition(0.0f, 0.0f, 0.0f);
	linez->setEndPosition(0.0f, 0.0f, radius);
	linez->setColor(1.0f, 0.0f, 0.0f);
	linez->setLineWidth(0.03f*radius);
	osg::ref_ptr<osg::Geometry> geomz = linex->getGeometry();
	osgUtil::SmoothingVisitor::smooth(*geomz);
	auto fontSize = radius * 0.5;
	TextPrimitives* text_X = new TextPrimitives;
	text_X->drawGeometry();
	text_X->setText("x");
	text_X->setPosition(radius + fontSize*0.6, 0.0f, 0.0f);
	text_X->setColor(1.0f, 0.0f, 0.0f);
	osgText::Text *textx = text_X->getOsgText();

	TextPrimitives* text_Y = new TextPrimitives;
	text_Y->drawGeometry();
	text_Y->setText("y");
	text_Y->setPosition(0.0f, radius + fontSize*0.6, 0.0f);
	text_Y->setColor(0.0f, 1.0f, 0.0f);
	osgText::Text *texty = text_Y->getOsgText();
	
	TextPrimitives* text_Z = new TextPrimitives;
	text_Z->drawGeometry();
	text_Z->setText("z");
	text_Z->setPosition(0.0f, 0.0f, radius + fontSize*0.6);
	text_Z->setColor(0.0f, 0.0f, 1.0f);
	osgText::Text *textz = text_Z->getOsgText();

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geomx);
	geode->addDrawable(geomy);
	geode->addDrawable(geomz);

	textGeode = new osg::MatrixTransform;
	textGeode->addChild(geode.get());
	textGeode->addChild(textx);
	textGeode->addChild(texty);
	textGeode->addChild(textz);
}





void Axes::setCenter(float x, float y, float z)
{

}

void Axes::getDirection(float &x, float &y, float &z)
{
	
}

