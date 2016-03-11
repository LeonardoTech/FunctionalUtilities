#ifndef MY_HH
#define MY_HH

enum Axis
{
	X_Axis,
	Y_Axis,
	Z_Axis
};


class ICoordinateAxis
{
public:
	//virtual void getAxisDirection(Axis axis, float &x, float &y, float &z) = 0;
	virtual void getAxisDirection( Axis ax, float &x, float &y, float &z) = 0;
	virtual osg::MatrixTransform* setAxis(float x, float y, float radius, osg::Camera *camera) = 0;
};



#endif