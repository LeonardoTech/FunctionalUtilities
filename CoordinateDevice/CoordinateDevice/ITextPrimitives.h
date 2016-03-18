#ifndef __ITEXTPRIMITIVES_H__
#define __ITEXTPRIMITIVES_H__
#include "IGeometry.h"

class ITextPrimitives:public IGeometry
{
public:
	virtual void setPosition(float x, float y, float z) = 0;

	virtual void setSize(float size) = 0;
};


#endif // __ITEXTPRIMITIVES_H__