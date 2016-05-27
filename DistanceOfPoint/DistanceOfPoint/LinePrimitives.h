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
	LinePrimitives(osg::Geometry *geo,osg::Geode* geode);

	virtual void setLineWidth(float width) override;
	virtual void setColor(float red, float green, float blue) override;
	void setCreateState();
private:
	osg::ref_ptr<osg::Geometry> _geo;
	bool _state;
	Geometry *_geometry;
	osg::ref_ptr<osg::Geode>_geode;

};


#endif // __LINEPRIMITIVES_H__