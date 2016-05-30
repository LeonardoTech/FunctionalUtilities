////////////
//    created by 孙庆号
////////////

#ifndef __KEY_FRAME_ANIMATION_H__
#define __KEY_FRAME_ANIMATION_H__

#include <vector>
#include <string>
#include "config.h"
#include "IKeyFrameAnimation.h"

namespace bimWorld
{
	namespace Animation
	{
		class YIZHU_EXPORT KeyFrameAnimation :public IKeyFrameAnimation
		{
		public:
			void setKeyFrame(int framePosition) override;

			void enableAnimationEditor() override;

			void disableAnimationEditor() override;

			void setAnimatingNodes(void* node) override;

			void setAnimatingNodes(std::vector<void*> nodes) override;

			void addActionToSequece(int red, int green, int blue, const std::string& id, double delayMilliseconds) override;

			void addActionToSequece(int red, int green, int blue, std::vector < std::string > id, double delayMilliseconds) override;

			void clearActionSequece() override;

			void play() override;

			void stop() override;

			void playKeyFrame(int framePosition) override;

			void setFrameMode(bool isFrameMode) override;

		};
	}
}
#endif // __KEY_FRAME_ANIMATION_H__