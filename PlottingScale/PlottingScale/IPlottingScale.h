#ifndef __IPLOTTINGSCALE_H__
#define __IPLOTTINGSCALE_H__
#include<functional>
class IPlottingScale
{
public:
	virtual double getScale() = 0;

	virtual void bindScaleChanged(long sque,std::function<void(IPlottingScale*)> changed) = 0;


};


#endif // __IPLOTTINGSCALE_H__