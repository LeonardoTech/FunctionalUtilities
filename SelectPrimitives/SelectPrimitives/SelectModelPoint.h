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

class SelectModelPoint :public Selector
{
public:
	SelectModelPoint(osg::Camera* camera)
		: _selector(0), _camera(camera) {}
	osg::Geode* createSelector();
	bool drawbyCoordinate(float x, float y, osg::Camera* camera);
	virtual void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	osg::Vec3 getPosition();
protected:
	osg::ref_ptr<osg::Geometry> _selector;
	osg::observer_ptr<osg::Camera> _camera;
	osg::Vec3 _position;
};
