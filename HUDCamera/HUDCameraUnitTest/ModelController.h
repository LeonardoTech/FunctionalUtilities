#ifndef __MODELCONTROLLER_H__
#define __MODELCONTROLLER_H__

#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include "LinePrimitive.h"
#include "PointPrimitive.h"
#include "QuadPrimitive.h"
#include "IPrimitiveFactor.h"

class PickHandler : public osgGA::GUIEventHandler
{
public:
	PickHandler(QuadPrimitive * factor);
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
protected:
	QuadPrimitive* _quad;
	PointPrimitive* _point;
	IPrimitiveFactor* _factor;
	float _xAxis;
	float _yAxis;
	osg::Vec3 _center;
	osg::ref_ptr<osg::Vec3Array> _vertices;
	osg::ref_ptr<osg::Camera>_camera;
};






#endif // __MODELCONTROLLER_H__