////////////
//    created by 孙庆号
////////////

#ifndef __IKEY_FRAME_ANIMATION_H__
#define __IKEY_FRAME_ANIMATION_H__

#include <vector>
#include <string>
#include "config.h"

namespace bimWorld
{
	namespace Animation
	{
		class YIZHU_EXPORT IKeyFrameAnimation
		{
		public:
			virtual void setKeyFrame(int framePosition) = 0;

			virtual void enableAnimationEditor() = 0;

			virtual void disableAnimationEditor() = 0;

			virtual void setAnimatingNodes(void* node) = 0;

			virtual void setAnimatingNodes(std::vector<void*> nodes) = 0;

			virtual void addActionToSequece(int red, int green, int blue, const std::string& id, double delayMilliseconds) = 0;

			virtual void addActionToSequece(int red, int green, int blue, std::vector < std::string > id, double delayMilliseconds) = 0;

			virtual void clearActionSequece() = 0;

			virtual void play() = 0;

			virtual void stop() = 0;

			virtual void playKeyFrame(int framePosition) = 0;

			virtual void setFrameMode(bool isFrameMode) = 0;

		};
	}
}
#endif // __IKEY_FRAME_ANIMATION_H__