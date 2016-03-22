
#ifndef __IPOINT_PRIMITIVES_H__
#define __IPOINT_PRIMITIVES_H__
#include "IDrawElement.h"

class IPointPrimitives :IDrawElement
{
public:
	virtual void getPosition(float& x, float& y, float& z) const = 0;
	virtual void setPosition(float x, float y, float z) = 0;
	virtual float getSize() const = 0;
	virtual void setSize(float size) = 0;
};

#endif // __IPOINT_PRIMITIVES_H__
