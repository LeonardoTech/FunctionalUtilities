////////////
//    created by 孙庆号
////////////

#ifndef __KEY_EVENT_HANDLERS_H__
#define __KEY_EVENT_HANDLERS_H__
#include "IKeyEventHandlers.h"
#include <osg/Version>
#if OPENSCENEGRAPH_SOVERSION < 130
#include "osgGA/GUIEventHandler" // 100
#else
#include "osgGA/EventHandler"
#endif

namespace bimWorld
{
	class EventHandlers;

	class KeyEventHandlers:public IKeyEventHandlers
	{
	public:
		KeyEventHandlers(bimWorld::EventHandlers* module);

		void init();

#ifdef NEED_RAISE_EVENTS

		// <设置键盘事件>
		virtual void onKeyPress(int key) override;

		virtual void onKeyRelease(int key) override;

#endif

	protected:
		bimWorld::EventHandlers* m_eventModule;
#if OPENSCENEGRAPH_SOVERSION < 130
		osg::ref_ptr<osgGA::GUIEventHandler> m_eventHandler;
#else
		osg::ref_ptr<osgGA::EventHandler> m_eventHandler;
#endif
	};
}


#endif // __KEY_EVENT_HANDLERS_H__
