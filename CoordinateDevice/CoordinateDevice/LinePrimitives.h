#ifndef __LINEPRIMITIVES_H__
#define __LINEPRIMITIVES_H__
#include "ILinePrimitives.h"
#include "Geometry.h"
#include <osg/Point>
#include <osg/Geode>
#include <osg/Geometry>
#include "osg/LineWidth"


class  LinePrimitives :public ILinePrimitives
{
public:
	LinePrimitives();

	virtual void drawGeometry() override;

	virtual void setLineWidth(float width) override;

	virtual void setColor(float red, float green, float blue) override;

	virtual void setStartPosition(float x, float y, float z)override;

	virtual void setEndPosition(float x, float y, float z) override;

	osg::Geometry*	getGeometry();

protected:
	virtual void setVertex();
	osg::Vec3 _startPosition;
	osg::Vec3 _endPosition;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Vec4Array> _color;
};


#endif // __LINEPRIMITIVES_H__