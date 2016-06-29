////////////
//    created by 孙庆号
////////////

#ifndef __IEVENT_HANDLERS_H__
#define __IEVENT_HANDLERS_H__
#include <memory>
#include "IKeyEventHandlers.h"
#include "IMouseEventHandlers.h"

namespace bimWorld
{
	class IEventHandlers
	{
	public:
		virtual void init() = 0;

		virtual void onResize(int x, int y, int width, int height) = 0;

#ifdef NEED_RAISE_EVENTS

		// <设置鼠标事件>
		virtual void onMousePress(float x, float y, int button)  = 0;

		virtual void onMouseRelease(float x, float y, int button)  = 0;

		virtual void onMouseDoubleClick(float x, float y, int button) = 0;

		virtual void onMouseMove(float x, float y)  = 0;

		// <设置键盘事件>
		virtual void onKeyPress(int key)  = 0;

		virtual void onKeyRelease(int key)  = 0;

#endif

	};
}

#endif // __IEVENT_HANDLERS_H__