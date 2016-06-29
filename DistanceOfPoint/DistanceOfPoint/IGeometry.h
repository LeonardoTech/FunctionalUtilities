#ifndef __IGEOMETRY_H__
#define __IGEOMETRY_H__
class IGeometry
{
public:
	virtual void setColor(float red, float green, float blue) = 0;
	virtual void drawGeometry() = 0;
private:

};
#endif
