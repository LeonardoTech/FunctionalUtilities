#pragma once
#include "osgViewer/Viewer"
#include "osgDB/readFile"
#include "osg/Geometry"
#include "osgUtil/SmoothingVisitor"
#include "osg/Geometry"
#include "osg/Geode"
#include "osg/MatrixTransform"
#include "osg/PolygonOffset"
#include <osgText/Font>
#include <osgText/Text>
#include <osgText/Font3D>
#include <osgText/Text3D>
#include <osg/LineWidth>
#include "osg/ShapeDrawable"
#include "osg/Point"
#include "osgGA/MultiTouchTrackballManipulator"
#include "ICoordinateAxis.h"
#include <osg/NodeCallback>
#include "CoordinateUpdater.h"
#include "LinePrimitives.h"
#include "TextPrimitives.h"
#include "Axes.h"

//class	CoordinateAxis
//
// brief	 <继承于IcoordinateAxis接口类，并对函数进行定义>
//
// author	Admin
// date	2016/3/14
class CoordinateAxis :
	public ICoordinateAxis
{
public:
	//<构造函数，对私有变量进行初始化>
	CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip);
	~CoordinateAxis();
	//<获取坐标轴方向>
	 void getAxisDirection(Coordinate ax, float &x, float &y, float &z);
	//<通过指定的二维屏幕坐标画出坐标系，可以指定坐标系的半径长度，需要把屏幕相机作为参数传进去>
	virtual osg::MatrixTransform* setAxis( float x, float y, float radius, osg::Camera *camera);
private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	CoordinateUpdater* update;
	Axes* _axes;
	
};

