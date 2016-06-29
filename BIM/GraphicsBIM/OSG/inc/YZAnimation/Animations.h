////////////
//    created by 孙庆号
////////////

#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include "config.h"
#include "KeyFrameAnimation.h"
#include "CameraAnimationPath.h"
#include <memory>
#include "IAnimations.h"

namespace bimWorld
{
	class YIZHU_EXPORT Animations: public IAnimations
	{
	public:
		std::shared_ptr<Animation::IKeyFrameAnimation> KeyFrameAnimation() override;
		std::shared_ptr<Animation::ICameraAnimationPath> CameraPathAnimation() override;
	protected:
		std::shared_ptr<Animation::KeyFrameAnimation> m_keyFrameAnimation;
		std::shared_ptr<Animation::CameraAnimationPath> m_cameraPathAnimation;
	};
}

#endif // __ANIMATION_H__