#ifndef __IAXES_H__
#define __IAXES_H__

class IAxes
{
public:
	virtual void setCenter(float x,float y,float z) = 0;
	virtual void getDirection(float &x,float &y,float &z) = 0;
};

#endif // __IAXES_H__