#ifndef __IGEOMETRY_H__
#define __IGEOMETRY_H__
#include "iostream"
#include "string.h"
#include "string"
using namespace std;


class IGeometry
{
public:
	virtual void setColor(float red, float green, float blue) = 0;
	virtual void drawGeometry() = 0;
private:

};

#endif
