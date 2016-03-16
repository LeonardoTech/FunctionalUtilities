
#include "../DistanceOfPoint/PickHandler.h"
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
#include "SelectModelPoint.h"
#include <osgText/Font>
#include <osgText/Text>
#include "osg/Group"
#include "../DistanceOfPoint/Distance.h"


// class	PickHandler
// brief	 <继承于osgGA::GUIEventHandler，对数表事件的定义，以及获取鼠标的位置，>
// date	2016/3/14
class PickHandler : public osgGA::GUIEventHandler
{
public:
	// <构造函数，对私有变量进行初始化（定义两个图形）>
	PickHandler(Distance* selector);

	// <对鼠标事件的更改，以完成功能上的要求>
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	// <把点，线，文字等都加到一个组里>
	void setRoot(osg::Group* node);
	// <创建一条线>
	osg::Geode* createLine();

protected:
	Distance* _select;

	osg::Group* _root;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::Geometry* _geometry;
	osgText::Text *_text;
};





osg::Geometry* createSimpleGeometry();