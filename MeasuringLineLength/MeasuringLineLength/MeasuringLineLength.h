#pragma once

#include "Selector.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include <iostream>
#include "osgGA/GUIEventHandler"
#include "SelectPoint.h"
#include <osgText/Font>
#include <osgText/Text>
#include "osg/Group"
#include "IMeasuringLineLength.h"
#include "TextPrimitive.h"
#include "PointPrimitive.h"


class MeasuringLineLength : public IMeasuringLineLength
{
public:

	MeasuringLineLength(Selector *select1, Selector *select2);
	
	//bool setPoint(float x, float y,Num num);

	osgText::Text *createText();

	osg::Geode* createLine();

	void setRoot(osg::Group* node);

	virtual void setStartPoint(float x, float y) override;

	virtual void setEndPoint(float x, float y) override;

	virtual void setLabel(string name, float x, float y) override;

	virtual float getDistance() override;

private:
	osgText::Text *_text;
	osg::Geometry *_geometry;
	osg::Group* _root;
	Selector *_select1;
	Selector *_select2;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::ref_ptr<osg::Camera>_camera;
};



