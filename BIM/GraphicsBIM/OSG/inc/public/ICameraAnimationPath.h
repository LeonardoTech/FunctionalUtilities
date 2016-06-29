////////////
//    created by 孙庆号
////////////

#ifndef __ICAMERA_ANIMATION_PATH_H__
#define __ICAMERA_ANIMATION_PATH_H__

#include <string>
#include "config.h"

namespace bimWorld
{
	namespace Animation
	{
		class YIZHU_EXPORT ICameraAnimationPath
		{
		public:

			virtual void beginRecordAnimationControlPoint() = 0;

			virtual void endRecordAnimationControlPoint() = 0;

			virtual void applyAnimationPath(void* node) = 0;

			virtual void applyAnimationPath(const std::string& entityId) = 0;

		};
	}
}

#endif // __ICAMERA_ANIMATION_PATH_H__