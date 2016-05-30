////////////
//    created by 孙庆号
////////////

#ifndef __FIXED_FRAME_RATE_H__
#define __FIXED_FRAME_RATE_H__
#include "YZModelCoreModule.h"
#include "FixedFramerateController.h"
#include "IFixedFrameRate.h"
#include <chrono>
#include <atomic>

//#define PC_DEBUG_ANDROID

#if defined(Android) || defined(PC_DEBUG_ANDROID)
#define MAX_FRAME_LEVEL 100
#else
#define MAX_FRAME_LEVEL 10
#endif
#define COM_EACH_FRAME_LEVEL 112

#ifdef _WIN32
#define ADJUST_HIGH 40
#else
#define ADJUST_HIGH 40
#endif

namespace bimWorld
{
	class YIZHU_EXPORT FixedFrameRate :public YZModelCoreModule, public IFixedFrameRate
	{
	public:
		FixedFrameRate(YZModelCoreInternal* host);

		void setupFrameRateController(osg::Node *root);

		virtual void cancelFixedFramerate() override;
		
		virtual void startFixedFramerate() override;

		void adjust(double frameTime, double lastFrameTime);

		void setCanceling(bool canceling) /*override*/;
		
		bool canceling();

		void cancelCurrentLevel();

		void setIgnoreFrame(bool ignore) override;

		void setMaxFrameLevel(int level);

		virtual void hide(int level) override;

		void setAnimating(bool animating);

	// internal:
		void setVolumeTree(osg::Group* tree);

		void unhide(int level = 1);

		void unhideAll();
	protected:
		bimWorld::FixedFramerateController	 fixedFramerateController;
		osg::Group* m_volumeTree;
		std::atomic_int m_currentLevel;
		std::atomic_bool m_canceling;
		std::atomic_bool m_ignore;
		std::atomic_bool m_animating;
		int m_maxFrameLevel;
		std::atomic_int m_ignoreCount;
		std::chrono::system_clock::time_point m_lastHidingTime;
		std::chrono::system_clock::time_point m_firstHidingTime;
		std::atomic_bool m_isUnhideAll;
	};
}

#endif // __FIXED_FRAME_RATE_H__