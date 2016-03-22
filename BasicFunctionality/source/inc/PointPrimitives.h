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
	virtual void getPosition(float& x, float& y, float& z) const override;
	virtual void setPosition(float x, float y, float z) override;
	virtual float getSize() const override;
	virtual void setSize(float size) override;
	virtual void setColor(float red, float green, float blue) override;
	virtual VertexArray getVertices() const override;
	virtual void setVertices(const VertexArray& arr) override;
// internal:
	osg::Geometry *getGeometry();
private:
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::Vec3 _vertex;
	osg::ref_ptr<osg::Vec4Array> _color;
	float _size;
};



#endif // __POINT_PRIMITIVES_H__