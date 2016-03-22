#ifndef __LINEPRIMITIVES_H__
#define __LINEPRIMITIVES_H__
#include "ILinePrimitives.h"
#include "Geometry.h"
#include <osg/Point>
#include <osg/Geode>
#include <osg/Geometry>
#include "osg/LineWidth"
#include "VertexArray.h"

class  LinePrimitives :public ILinePrimitives
{
public:
	LinePrimitives();

	virtual void setLineWidth(float width) override;

	virtual void setColor(float red, float green, float blue) override;

	virtual void getStartPosition(float& x, float& y, float& z) override;

	virtual void getEndPosition(float& x, float& y, float& z) override;

	virtual void setStartPosition(float x, float y, float z)override;

	virtual void setEndPosition(float x, float y, float z) override;

	virtual void setVertices(const VertexArray& arr) override;

	virtual VertexArray getVertices() const override;

// internal:
	osg::Geometry*	getGeometry();

protected:
	osg::Vec3 _startPosition;
	osg::Vec3 _endPosition;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Vec4Array> _color;
	osg::ref_ptr<osg::Vec3Array>_vertices;
};


#endif // __LINEPRIMITIVES_H__