#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include "QuadPrimitive.h"


class PickHandler : public osgGA::GUIEventHandler
{
public:
	PickHandler(QuadPrimitive* quad);
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
protected:
	QuadPrimitive* _quad;
	float _height;
	float _width;
	osg::Vec3 _center;
};