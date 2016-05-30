////////////
//    created by 孙庆号
////////////

#ifndef __CREATE_POINT_MANIPULATOR_H__
#define __CREATE_POINT_MANIPULATOR_H__
#include "MouseManipulatorBase.h"
#include <osgManipulator/CommandManager>
#include <osgManipulator/TranslateAxisDragger>
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer/View>
#include <osg/Vec3d>
#include <functional>
#include <math.h>

namespace bimWorld
{
	namespace Manipulator
	{

		class YIZHU_EXPORT CreatePointManipulator : public MouseManipulatorBase
		{


#define getMaxRadius(axis, nodeCenter, nodeRadius, radius) \
				auto min##axis = abs(nodeCenter.axis() - nodeRadius); \
				auto max##axis = abs(nodeCenter.axis() + nodeRadius); \
				if (min##axis > max##axis) \
					radius = (radius < min##axis) ? min##axis : radius; \
																																																																																																																																																																																																																																																																else \
					radius = (radius < max##axis) ? max##axis : radius;

		public:
			// getPosFunc: <将所给点由屏幕坐标系转换为模型坐标系>
			// <getPosFunc 中的z值要获取俯视图屏幕的z轴坐标>
			CreatePointManipulator(std::function<osg::Vec3(float, float)> getPosFunc, std::function<void(const std::vector<osg::Vec3>&)> addPosFunc) :MouseManipulatorBase()
			{
				m_getPosFunc = getPosFunc;
				m_addPosFunc = addPosFunc;
				m_createdPoints.clear();
			}

			void clear()
			{
				m_createdPoints.clear();
			}

			//virtual void Enable() override
			//{
			//	m_manager->connect(*m_dragger, *m_selection);
			//	MouseManipulatorBase::Enable();
			//}

			//virtual void Disable() override
			//{
			//	m_manager->disconnect(*m_dragger);
			//	MouseManipulatorBase::Disable();
			//}

			virtual bool dealMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override
			{
				osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
				if (!view)
					return false;

				auto point = m_getPosFunc(ea.getX(), ea.getY());
				m_createdPoints.push_back(point);
				m_addPosFunc(m_createdPoints);
				return true;
			}

			virtual bool dealMouseDrag(const osgGA::GUIEventAdapter& /*ea*/, osgGA::GUIActionAdapter& /*aa*/) override
			{
				return true;
			}

			virtual bool dealMouseRelease(const osgGA::GUIEventAdapter& /*ea*/, osgGA::GUIActionAdapter& /*aa*/) override
			{
				return true;
			}

		protected:
			std::vector<osg::Vec3> m_createdPoints;
			std::function<osg::Vec3(float, float)> m_getPosFunc;
			std::function<void(const std::vector<osg::Vec3>&)> m_addPosFunc;
		};
	}
}

#endif // __CREATE_POINT_MANIPULATOR_H__