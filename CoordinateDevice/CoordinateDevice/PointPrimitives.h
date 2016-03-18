#ifndef __POINT_PRIMITIVES_H__
#define __POINT_PRIMITIVES_H__
#include "IPointPrimitives.h"
#include "Geometry.h"
#include <osg/Point>
#include <osg/Geode>
#include <osg/Geometry>

class PointPrimitives :public IPointPrimitives
{
public:
	PointPrimitives(osg::Geode* geode);
	virtual void drawGeometry() override;
	virtual void setPoint(float size, float red, float green, float blue) override;
	virtual void setSize(float size) override;
	virtual void setColor(float red, float green, float blue) override;
	void setGeode();
private:
	osg::ref_ptr<osg::Geometry> _geo;
	Geometry *_geometry;
	osg::ref_ptr<osg::Geode>_geode;
};



#endif // __POINT_PRIMITIVES_H__