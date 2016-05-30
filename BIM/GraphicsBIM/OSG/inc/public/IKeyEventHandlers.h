////////////
//    created by 孙庆号
////////////

#ifndef __IKEY_EVENT_HANDLERS_H__
#define __IKEY_EVENT_HANDLERS_H__

namespace bimWorld
{
	class IKeyEventHandlers
	{
	public:

#ifdef NEED_RAISE_EVENTS

		// <设置键盘事件>
		virtual void onKeyPress(int key) = 0;

		virtual void onKeyRelease(int key) = 0;

#endif

	};
}

#endif // __IKEY_EVENT_HANDLERS_H__