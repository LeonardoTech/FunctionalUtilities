////////////
//    created by 孙庆号
////////////

#ifndef __IANIMATION_H__
#define __IANIMATION_H__
#include <memory>
#include "config.h"
#include "IKeyFrameAnimation.h"
#include "ICameraAnimationPath.h"

namespace bimWorld
{
	class YIZHU_EXPORT IAnimations
	{
	public:
		virtual std::shared_ptr<Animation::ICameraAnimationPath> CameraPathAnimation() = 0;
		
		virtual std::shared_ptr<Animation::IKeyFrameAnimation> KeyFrameAnimation() = 0;
	protected:
	};
}
#endif // __IANIMATION_H__