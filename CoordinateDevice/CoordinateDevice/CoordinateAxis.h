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


class CoordinateAxis :
	public ICoordinateAxis
{
public:
	CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip);
	~CoordinateAxis();
	virtual void getAxisDirection(Axis ax, float &x, float &y, float &z);
	virtual osg::MatrixTransform* setAxis( float x, float y, float radius, osg::Camera *camera);
private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	CoordinateUpdater* update;
};

