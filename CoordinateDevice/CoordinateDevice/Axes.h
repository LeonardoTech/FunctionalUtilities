#ifndef __AXES_H__
#define __AXES_H__
#include "IAxes.h"
#include "osg/geometry"
#include "LinePrimitives.h"
#include "TextPrimitives.h"
#include "osgUtil/SmoothingVisitor"

class Axes:public IAxes
{
public:
	void drawGeomtry(float radius);
	virtual void setCenter(float x, float y, float z) override;
	virtual void getDirection(float &x, float &y, float &z) override;
private:
	osg::ref_ptr<osg::MatrixTransform> textGeode;
};

#endif // __AXES_H__