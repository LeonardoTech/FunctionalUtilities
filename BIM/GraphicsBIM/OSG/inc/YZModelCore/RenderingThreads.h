////////////
//    created by 孙庆号
////////////

#ifndef __RENDERING_THREADS_H__
#define __RENDERING_THREADS_H__

#include "RenderingThread.h"
#include "IRenderingThreads.h"

namespace bimWorld
{
	class YIZHU_EXPORT RenderingThreads : public IRenderingThreads
	{
	public:
		RenderingThreads(YZModelCoreInternal* host);

		// <开启一个渲染线程>
		virtual void startRendering() override;

		virtual void setIsExternalRendering(bool value) override;

		virtual void setNeedUpdateAndDraw(bool value, int delay = 0) override;

		virtual bool getNeedUpdateAndDraw() override;

#ifndef YZOSG_START_NEW_THREAD
		virtual bool loop(bool hasDrawn = false) override;
#endif // YZOSG_START_NEW_THREAD

		virtual bool isGoingToRender() override;

		// <刷新>
		virtual void updateSeveralTimes(int times = 3) override;

		virtual void onlyUpdateFrame() override;

		void bindAbortValue(osg::State* state);

		virtual double getFrameTime() override;

		virtual double getLastFrameTime();

		void setIgnoreUpdate(bool ignore);

		// <绘制前更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& PreFrameUpdateEvent() override;

		// <绘制后更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& PostFrameUpdateEvent() override;

		// <无绘制更新事件>
		virtual core::IEvent<void(std::chrono::system_clock::time_point)>& NoneFrameUpdateEvent() override;

		void setBlockAnimation(unsigned int totalFrame, core::InstanceFunction<void(float)> pre, core::InstanceFunction<void(float)> post);

		virtual void abortRendering();

		// <以后不直接提供frame函数>
		// virtual void frame();
	protected:
		// <渲染线程>
		osg::ref_ptr<CRenderingThread> m_rendering;
	private:
		bool m_started;
	};
}

#endif // __RENDERING_THREADS_H__