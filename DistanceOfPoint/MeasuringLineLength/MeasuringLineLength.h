#pragma once
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include <iostream>
#include <osgGA/GUIEventHandler>
#include <osgText/Font>
#include <osgText/Text>
#include <osg/Group>
#include <memory>

#include "SelectPoint.h"
#include "IMeasuringLineLength.h"
#include "SelectPoint.h"
#include "TextPrimitives.h"
#include "LinePrimitives.h"

class MeasuringLineLength :
	public IMeasuringLineLength
{
public:
	MeasuringLineLength(osg::Camera* camera);
	~MeasuringLineLength();
	virtual void setStartPoint(float x, float y) override;

	void updateLineAndLabelPos();

	virtual void setEndPoint(float x, float y) override;
	virtual void setLabel(string name, float x, float y, float z) /*override*/;
	virtual void setLabel(string name, SHOW_METHOD method) override;
	virtual float getDistance() override;


	virtual void getStartPoint(float& x, float& y, float& z) override;
	virtual void getEndPoint(float& x, float& y, float& z) override;
	void CreateNewSelector();

	//bool setPoint(float x, float y, Num num);
	osg::Group* getRoot();
protected:
	osg::Group* _root;
	osg::ref_ptr<osg::Camera>_camera;
	std::shared_ptr<TextPrimitives> _text;
	std::shared_ptr<LinePrimitives> _line;
	std::shared_ptr<SelectPoint> _select1;
	std::shared_ptr<SelectPoint> _select2;

	SHOW_METHOD m_showMethod;
};

