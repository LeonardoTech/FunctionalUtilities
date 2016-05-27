#include "GridNet.h"
#include <osgText/Text>
#include "ILinePrimitive.h"
#include "LinePrimitive.h"
#include "ArcPrimitive.h"
#include <osg/Drawable>
#include "TextPrimitive.h"
#include "CirclePrimitive.h"
#include <osg/Geode>


using namespace geo;
using namespace YZ;

GridNet::GridNet()
{
	LinePrimitive* line = new LinePrimitive;
	//_circle = new CirclePrimitive
}


osg::Geometry* GridNet::createLine()
{
	LinePrimitive*line = new  LinePrimitive;
	line->setStartPosition(0.0, 0.0, 0.0);
	line->setEndPosition(5.0, 0.0, 0.0);
	osg::ref_ptr<osg::Geometry>geom =  line->getGeometry();
	return geom.release();
}

osg::Geode* GridNet::createCircle(float radius)
{
	CirclePrimitive* circle = new CirclePrimitive;
	circle->setRadius(radius);

	osg::ref_ptr<osg::Geode>root = new osg::Geode;
	root->addDrawable(circle);
	return root.release();
}

osg::Geode* GridNet::createText()
{
	TextPrimitive *text = new TextPrimitive;
	text->setTextContent("Hello World");
	text->setColor(1.0, 0.0, 0.0);
	osg::ref_ptr<osgText::Text>_text =  text->getOsgText();
	osg::ref_ptr<osg::Geode>root = new osg::Geode;
	root->addDrawable(_text);
	return root.release();
}

osg::Group* GridNet::createNode()
{
	TextPrimitive* text = new TextPrimitive;
	text->setTextContent("H");
	text->setColor(1.0, 0.0, 0.0);
	//text->setPosition(-0.3, 0.0, -0.2);
	text->setPosition(0.0, 0.0, 0.0);
	osg::ref_ptr<osgText::Text>_text = text->getOsgText();
	osg::ref_ptr<osg::Geode>troot = new osg::Geode;
	troot->addDrawable(_text);
	CirclePrimitive* circle = new CirclePrimitive;
	circle->setRadius(2);
	osg::ref_ptr<osg::Geode>croot = new osg::Geode;
	croot->addDrawable(circle);

	osg::ref_ptr<osg::Group>root = new osg::Group;
	root->addChild(croot);
	root->addChild(troot);
	return root.release();
}


void GridNet::setCircleRadius(float num)
{
		
}


osg::Group* GridNet::createTemplate()
{
	TextPrimitive* text1 = new TextPrimitive;
	text1->setTextContent("1");
	text1->setSize(30);
	text1->setColor(0.0, 1.0, 1.0);
	text1->setPosition(0.0, 0.0, 0.0);
	osg::ref_ptr<osgText::Text>_text1 = text1->getOsgText();
	
	TextPrimitive* text2 = new TextPrimitive;
	text2->setTextContent("2");
	text2->setColor(0.0, 1.0, 1.0);
	text2->setPosition(10.0, 0.0, 0.0);
	osg::ref_ptr<osgText::Text>_text2 = text2->getOsgText();

	CirclePrimitive* circle1 = new CirclePrimitive;
	circle1->setRadius(1.0);
	circle1->setCenter(0.0, 0.0, 0.0);

	CirclePrimitive* circle2 = new CirclePrimitive;
	circle2->setRadius(1.0);
	circle2->setCenter(10.0, 0.0, 0.0);
	
	//ArcPrimitive* arc = new ArcPrimitive(Vertex{ 5.0, 0.0, 2.0 }, Vertex{ 0.0, 0.0, 2.0 }, Vertex{ 10.0, 0.0, 2.0 }, Vertex{ 0.0, -1.0, 0.0 });
	ArcPrimitive* arc = new ArcPrimitive;
	arc->setStart(0.0, 0.0, 1.0);
	arc->setEnd(10.0, 0.0, 1.0);
	arc->setCenter(5.0, 0.0, 2.0);
	arc->setNormal(0.0, -1.0, 0.0);


	osg::ref_ptr<osg::Geode>geode = new osg::Geode;
	geode->addDrawable(arc);
	geode->addDrawable(circle1);
	geode->addDrawable(circle2);
	geode->addDrawable(_text1);
	geode->addDrawable(_text2);

	osg::ref_ptr<osg::Group>root = new osg::Group;
	root->addChild(geode);
	return root.release();
}

