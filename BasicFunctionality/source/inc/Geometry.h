#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "IColorable.h"
#include <osg/Geometry>
#include <osg/Geode>

class Geometry :public IColorable
{
public:
	virtual void setColor(float red, float green, float blue);

	osg::Geometry * getGeometry();

private:
	osg::ref_ptr<osg::Geometry> _geometry;
};


#endif // __GEOMETRY_H__