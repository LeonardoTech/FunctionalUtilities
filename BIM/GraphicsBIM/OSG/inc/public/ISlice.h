////////////
//    created by 孙庆号
////////////

#ifndef __YZ_ISLICE_H__
#define __YZ_ISLICE_H__
#include "config.h"
#include "SlicePlaneDirection.h"

namespace bimWorld
{

	class YIZHU_EXPORT ISlice
	{
	public:
		virtual void setSlicePlaneEnabled(SlicePlaneDirection direction, bool enabled) = 0;
		virtual bool getSlicePlanePosition(SlicePlaneDirection direction, float& posX, float& posY, float& posZ, float& offset) = 0;
		virtual void setSlicePlanePosition(SlicePlaneDirection direction, float posX, float posY, float posZ, float offset) = 0;
		virtual void setSlicePlaneVisibility(SlicePlaneDirection direction, bool visible) = 0;
		virtual void setNeedDrawOutLine(bool drawOutLine) = 0;
		virtual void reset() = 0;
	};
}

#endif // __YZ_ISLICE_H__