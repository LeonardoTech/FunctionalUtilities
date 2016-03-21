#ifndef __IAXES_H__
#define __IAXES_H__
enum Coordinate
{
	X_Coordinate,
	Y_Coordinate,
	Z_Coordinate
};


class IAxes
{
public:
	virtual void setCenter(float x,float y) = 0;
	virtual void getDirection(Coordinate co,float &x,float &y,float &z) = 0;
};

#endif // __IAXES_H__