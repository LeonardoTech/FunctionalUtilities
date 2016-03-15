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
#include "Selector.h"
using namespace std;

class SelectModelLine :public Selector
{
public:
	// <初始化私有成员>
	SelectModelLine(osg::Camera* camera)
		: _selector(0), _camera(camera) {}
	// <创建一条线>
	osg::Geode* createSelector();
	// <根据二维坐标来画一条线>
	bool drawbyCoordinate(float x, float y, osg::Camera* camera);
	// <通过相交算法运算后返回的结果，来确定点的位置，并通过矩阵把二维的坐标转换为三维的，为要画的图形确定顶点坐标>
	virtual void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
protected:
	osg::ref_ptr<osg::Geometry> _selector;
	osg::observer_ptr<osg::Camera> _camera;
};
