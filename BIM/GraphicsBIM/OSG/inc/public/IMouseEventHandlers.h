////////////
//    created by 孙庆号
////////////

#ifndef __IMOUSE_EVENT_HANDLERS_H__
#define __IMOUSE_EVENT_HANDLERS_H__

namespace bimWorld
{
	class IMouseEventHandlers
	{
	public:

#ifdef NEED_RAISE_EVENTS

		// <设置鼠标事件>
		virtual void onMousePress(float x, float y, int button) = 0;

		virtual void onMouseRelease(float x, float y, int button) = 0;

		virtual void onMouseMove(float x, float y) = 0;

		virtual void onMouseDoubleClick(float x, float y, int button) = 0;

#endif

	protected:
	};
}

#endif // __IMOUSE_EVENT_HANDLERS_H__