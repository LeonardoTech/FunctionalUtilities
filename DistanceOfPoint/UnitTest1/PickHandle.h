﻿#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/PolygonOffset>
#include <osgViewer/Viewer>
#include <osgGA/GUIEventHandler>
#include <osg/Group>
#include <iostream>
#include <vector>
#include "MeasuringLineLength.h"

using namespace measuringlinelength;
// class	PickHandler
// brief	 <继承于osgGA::GUIEventHandler，对数表事件的定义，以及获取鼠标的位置，>
// date	2016/3/14
class PickHandler : public osgGA::GUIEventHandler
{
public:
	// <构造函数，对私有变量进行初始化（定义两个图形）>
	PickHandler(osg::Group* root, MeasuringLineLengthImplement* selector);

	// <对鼠标事件的更改，以完成功能上的要求>
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	// <把点，线，文字等都加到一个组里>
	osg::Group* getRoot();
	// <创建一条线>
	osg::Geode* createLine();

protected:
	MeasuringLineLengthImplement* _select;
	std::vector<MeasuringLineLengthImplement*>_lineVector;
	osg::ref_ptr<osg::Group> _root;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::Geometry* _geometry;
	osgText::Text *_text;
};





osg::Geometry* createSimpleGeometry();