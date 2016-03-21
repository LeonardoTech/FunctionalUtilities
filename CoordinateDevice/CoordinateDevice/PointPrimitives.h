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
	PointPrimitives();
	virtual void drawGeometry() override;
	virtual void setPosition(float x, float y, float z) override;
	virtual void setSize(float size) override;
	virtual void setColor(float red, float green, float blue) override;
	void setGeode();
	osg::Geometry *getGeometry();
private:
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::Vec3 _vertex;
	osg::ref_ptr<osg::Vec4Array> _color;
};



#endif // __POINT_PRIMITIVES_H__