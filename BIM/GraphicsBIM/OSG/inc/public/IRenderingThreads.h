////////////
//    created by 孙庆号
////////////

#ifndef __IRENDERING_THREADS_H__
#define __IRENDERING_THREADS_H__
#include "IEvent.h"
#include <chrono>

namespace bimWorld
{
	class YIZHU_EXPORT IRenderingThreads
	{
	public:

		// <开启一个渲染引擎>
		virtual void startRendering() = 0;

		virtual void	setIsExternalRendering(bool value) = 0;

		virtual void setNeedUpdateAndDraw(bool value, int delay = 0) = 0;

		virtual bool getNeedUpdateAndDraw() = 0;
		
#ifndef YZOSG_START_NEW_THREAD
		virtual bool loop(bool hasDrawn = false) = 0;
#endif // YZOSG_START_NEW_THREAD

		virtual bool isGoingToRender() = 0;

		// <刷新>
		virtual void	updateSeveralTimes(int times = 3) = 0;

		virtual void onlyUpdateFrame() = 0;

		virtual double getFrameTime() = 0;

		// <绘制前更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& PreFrameUpdateEvent() = 0;

		// <绘制后更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& PostFrameUpdateEvent() = 0;

		// <无绘制更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& NoneFrameUpdateEvent() = 0;

		// <以后不直接提供frame函数>
		// virtual void frame() = 0;
		virtual void abortRendering() = 0;
	};
}

#endif // __IRENDERING_THREADS_H__