#ifndef __ILINEPRIMITIVES_H__
#define __ILINEPRIMITIVES_H__

#include "IGeometry.h"
#include "Geometry.h"

class  ILinePrimitives :public IGeometry
{
public:
	virtual void setLineWidth(float width) = 0;

	virtual void setStartPosition(float x, float y, float z) = 0;

	virtual void setEndPosition(float x, float y, float z) = 0;
	
};


#endif	// __ILINEPRIMITIVES_H__
