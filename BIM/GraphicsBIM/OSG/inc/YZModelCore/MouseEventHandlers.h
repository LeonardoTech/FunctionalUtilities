////////////
//    created by 孙庆号
////////////

#ifndef __MOUSE_EVENT_HANDLERS_H__
#define __MOUSE_EVENT_HANDLERS_H__
#include "IMouseEventHandlers.h"
#include <osg/Version>
#if OPENSCENEGRAPH_SOVERSION < 130
#include "osgGA/GUIEventHandler"
#else
#include "osgGA/EventHandler"
#endif

namespace bimWorld
{
	class EventHandlers;

	class MouseEventHandlers :public IMouseEventHandlers
	{
	public:
		MouseEventHandlers(bimWorld::EventHandlers* module);

		void init();

#ifdef NEED_RAISE_EVENTS

		// <设置鼠标事件>
		virtual void onMousePress(float x, float y, int button) override;

		virtual void onMouseRelease(float x, float y, int button) override;

		virtual void onMouseDoubleClick(float x, float y, int button) override;

		virtual void onMouseMove(float x, float y) override;

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


#endif // __MOUSE_EVENT_HANDLERS_H__
