////////////
//    created by 孙庆号
////////////

#ifndef __I_MOUSE_HANDLER_H__
#define __I_MOUSE_HANDLER_H__
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
#include "config.h"

namespace bimWorld
{
	namespace Manipulator
	{
		class YIZHU_EXPORT IMouseHandler
		{
		public:
			IMouseHandler()
			{
			}

			// <处理鼠标抬起事件>
			// <如果返回true，中断事件向下传递>
			virtual bool handleMouseRelease(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) = 0;

			// <处理鼠标按下事件>
			// <如果返回true，中断事件向下传递>
			virtual	bool handleMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) = 0;

			// <处理鼠标拖动事件>
			// <如果返回true，中断事件向下传递>
			virtual	bool handleMouseDrag(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) = 0;
		};
	}
}

#endif // __I_MOUSE_HANDLER_H__