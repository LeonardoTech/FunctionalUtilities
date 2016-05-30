////////////
//    created by 孙庆号
////////////

#ifndef __YZ_EVENT_HANDLERS_H__
#define __YZ_EVENT_HANDLERS_H__
#include "YZModelCoreModule.h"
#include "config.h"
#include "IEventHandlers.h"

namespace bimWorld
{
	class KeyEventHandlers;
	class MouseEventHandlers;

	class YIZHU_EXPORT EventHandlers :public YZModelCoreModule, public IEventHandlers
	{
	public:
		EventHandlers(bimWorld::YZModelCoreInternal* host);

		void init();

		void onResize(int x, int y, int width, int height) override;

#ifdef NEED_RAISE_EVENTS

		// <设置鼠标事件>
		virtual void onMousePress(float x, float y, int button) override;

		virtual void onMouseRelease(float x, float y, int button) override;

		virtual void onMouseDoubleClick(float x, float y, int button) override;

		virtual void onMouseMove(float x, float y) override;

		// <设置键盘事件>
		virtual void onKeyPress(int key) override;

		virtual void onKeyRelease(int key) override;

#endif

	protected:

		friend class KeyEventHandlers;
		friend class MouseEventHandlers;

		std::shared_ptr<bimWorld::MouseEventHandlers> _MouseEventHandlers();
		std::shared_ptr<bimWorld::KeyEventHandlers> _KeyEventHandlers();

		std::shared_ptr<bimWorld::MouseEventHandlers> m_mouseEventHandlers;
		std::shared_ptr<bimWorld::KeyEventHandlers> m_keyEventHandlers;
		
	};
}

#endif // __YZ_EVENT_HANDLERS_H__