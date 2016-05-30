////////////
//    created by 孙庆号
////////////

#ifndef __IFIXED_FRAME_RATE_H__
#define __IFIXED_FRAME_RATE_H__

#include "config.h"
#include "DataModel.h"
namespace bimWorld
{
	class YIZHU_EXPORT IFixedFrameRate
	{
	public:

		virtual void cancelFixedFramerate() = 0;

		virtual void startFixedFramerate() = 0;

		virtual void setIgnoreFrame(bool ignore) = 0;

		virtual void hide(int level) = 0;

		//virtual void setCanceling(bool canceling) = 0;

	};

}
#endif // __IFIXED_FRAME_RATE_H__