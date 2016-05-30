////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_ANIMATION_PATH_H__
#define __CAMERA_ANIMATION_PATH_H__

#include <string>
#include "config.h"
#include "ICameraAnimationPath.h"

namespace bimWorld
{
	namespace Animation
	{
		class YIZHU_EXPORT CameraAnimationPath : public ICameraAnimationPath
		{
		public:

			void beginRecordAnimationControlPoint() override;

			void endRecordAnimationControlPoint() override;

			void applyAnimationPath(void* node) override;

			void applyAnimationPath(const std::string& entityId) override;

		protected:
		private:
		};
	}
}

#endif // __CAMERA_ANIMATION_PATH_H__