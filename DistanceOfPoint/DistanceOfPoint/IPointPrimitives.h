
#ifndef __IPOINT_PRIMITIVES_H__
#define __IPOINT_PRIMITIVES_H__
#include "IGeometry.h"

class IPointPrimitives:IGeometry
{
public:
	virtual void setPoint(float size, float red, float green, float blue) = 0;
	virtual void setSize(float size) = 0;
};

#endif // __IPOINT_PRIMITIVES_H__
