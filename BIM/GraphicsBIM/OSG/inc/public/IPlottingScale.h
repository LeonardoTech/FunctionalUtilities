#ifndef __IPLOTTING_SCALE_H__
#define __IPLOTTING_SCALE_H__
#include<functional>


#include <Event.h>
namespace bimWorld
{
	class IPlottingScale
	{
	public:
		virtual double getScale() = 0;

		//virtual void bindScaleChanged(long sque,std::function<void(IPlottingScale*)> changed) = 0;

		virtual core::Event<void(IPlottingScale*)>& scaleChanged() = 0;
	};
}

#endif // __IPLOTTING_SCALE_H__