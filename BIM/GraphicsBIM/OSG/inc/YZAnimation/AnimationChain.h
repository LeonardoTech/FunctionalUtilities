////////////
//    created by 孙庆号
////////////

#ifndef __ANIMATION_CHAIN_H__
#define __ANIMATION_CHAIN_H__

#include <osgAnimation/Keyframe>
#include <osgAnimation/Channel>
#include <osg/Vec3>
#include <osg/Quat>
#include <osg/Referenced>

namespace bimWorld
{
	namespace Animation
	{
		struct AnimationKeyframeContainer
		{
			osgAnimation::Vec3KeyframeContainer transContainer;
			osgAnimation::QuatKeyframeContainer rotateContainer;
			osgAnimation::Vec3KeyframeContainer scaleContainer;
		};

		class AnimationChain : public osg::Referenced
		{
		public:
			AnimationChain()
			{}

			void addKeyFrame(double time, const osg::Vec3& pos, const osg::Quat& quat, const osg::Vec3& scale)
			{
				auto posFrame = osgAnimation::Vec3Keyframe(time, pos);
				auto quatFrame = osgAnimation::QuatKeyframe(time, quat);
				auto scaleFrame = osgAnimation::Vec3Keyframe(time, scale);

				return addKeyFrame(time, posFrame, quatFrame, scaleFrame);
			}

			void addKeyFrame(double /*time*/, const osgAnimation::Vec3Keyframe& posFrame, const osgAnimation::QuatKeyframe& quatFrame, const osgAnimation::Vec3Keyframe& scaleFrame)
			{
				positionChannel->getOrCreateSampler()->getOrCreateKeyframeContainer()->push_back(
					posFrame);
				rotationChannel->getOrCreateSampler()->getOrCreateKeyframeContainer()->push_back(
					quatFrame);
				scaleChannel->getOrCreateSampler()->getOrCreateKeyframeContainer()->push_back(
					scaleFrame);
			}

			AnimationKeyframeContainer* getKeyframeContainer()
			{
				auto result = new AnimationKeyframeContainer();
				result->transContainer = *this->positionChannel->getOrCreateSampler()->getOrCreateKeyframeContainer();
				result->rotateContainer = *this->rotationChannel->getOrCreateSampler()->getOrCreateKeyframeContainer();
				result->scaleContainer = *this->scaleChannel->getOrCreateSampler()->getOrCreateKeyframeContainer();
				return result;
			}

		protected:
			osg::ref_ptr<osgAnimation::Vec3LinearChannel> positionChannel;
			osg::ref_ptr<osgAnimation::QuatSphericalLinearChannel> rotationChannel;
			osg::ref_ptr<osgAnimation::Vec3LinearChannel> scaleChannel;
		};
	}
}
#endif // __ANIMATION_CHAIN_H__