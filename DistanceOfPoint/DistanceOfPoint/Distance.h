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
#include "SelectModelPoint.h"
#include <osgText/Font>
#include <osgText/Text>
#include "osg/LineWidth"
#include "osg/Group"
#include "IDistance.h"
#include "TextPrimitives.h"
#include "ILinePrimitives.h"
#include "LinePrimitives.h"
#include "Geometry.h"



//class	<一个测量距离的类，继承于IDistance接口类>
class Distance :  public IDistance
{
public:
	// <构造函数，为私有成员初始化>
	Distance(Selector *select1, Selector *select2);

	// <对接口函数的重写，画出一个点，枚举值Num是确定第一个点还是第二个点>
	bool drawLine(float x, float y, SegmentEndpointType type);
	
	// <创建HUD文字，来表示两个点之间的长度>
	osgText::Text *createText(float size, float red, float green, float blue);
	//osgText::Text *createText(float size, float red, float green, float blue);
	
	// <创建一条动态的线，连接着两个动态的点>
	osg::Geode* createLine(float size, float red, float green, float blue);

	// <将点、线、文字都作为节点加入到组里去，能够让他们在屏幕上显示>
	void setRoot(osg::Group* node);
	
	void setPoint(float size, float red, float green, float blue);


	void setText(float size, float x, float y, float z, float red, float green, float blue);

	void setLine(float size, float red, float green, float blue);


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
