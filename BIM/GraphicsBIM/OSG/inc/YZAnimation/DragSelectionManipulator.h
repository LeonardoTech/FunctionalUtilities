////////////
//    created by 孙庆号
////////////

#ifndef __DRAG_SELECTION_MANIPULATOR_H__
#define __DRAG_SELECTION_MANIPULATOR_H__
#include "MouseManipulatorBase.h"

namespace bimWorld
{
	namespace Manipulator
	{

		class YIZHU_EXPORT DragSelectionManipulator : public MouseManipulatorBase
		{
		public:
			DragSelectionManipulator() :MouseManipulatorBase()
			{
			}

			virtual bool dealMouseRelease(const osgGA::GUIEventAdapter& /*ea*/, osgGA::GUIActionAdapter& /*aa*/) override
			{
				return true;
			}

			virtual bool dealMousePush(const osgGA::GUIEventAdapter& /*ea*/, osgGA::GUIActionAdapter& /*aa*/) override
			{
				return true;
			}

			virtual bool dealMouseDrag(const osgGA::GUIEventAdapter& /*ea*/, osgGA::GUIActionAdapter& /*aa*/) override
			{

				return true;
			}

		protected:

		};
	}
}

#endif // __DRAG_SELECTION_MANIPULATOR_H__