#ifndef __AXESUPDATE_H__
#define __AXESUPDATE_H__
#include "Axes.h"
#include "ICoordinateAxis.h"

class AxesUpdate :public osg::NodeCallback
{
public:

	AxesUpdate(osgGA::MultiTouchTrackballManipulator* manip);

	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

	osg::Vec3 getResult(Coordinate axis);
private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	osg::Quat rot;
};




#endif