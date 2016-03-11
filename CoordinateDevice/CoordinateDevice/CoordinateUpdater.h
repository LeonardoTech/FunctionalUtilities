#ifndef MY_H
#define MY_H

#include <osg/NodeCallback>
#include "stdafx.h"
#include <osg/MatrixTransform>
#include "osgGA/MultiTouchTrackballManipulator"
#include "ICoordinateAxis.h"
#include <osgText/Font>
#include <osgText/Text>

class CoordinateUpdater:public osg::NodeCallback
{
public:
	CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip);
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	osg::Vec3 getResult(Axis ax);

private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	osg::Quat rot;
};

#endif