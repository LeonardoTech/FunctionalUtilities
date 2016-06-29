
#ifndef __IPOINT_PRIMITIVES_H__
#define __IPOINT_PRIMITIVES_H__
#include "IGeometry.h"

class IPointPrimitives :IGeometry
{
public:
	virtual void setPosition(float x, float y, float z) = 0;
	virtual void setSize(float size) = 0;
};

#endif // __IPOINT_PRIMITIVES_H__
