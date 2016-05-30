////////////
//    created by 孙庆号
////////////

#ifndef __DRAGGER_MANIPULATOR_H__
#define __DRAGGER_MANIPULATOR_H__
#include "MouseManipulatorBase.h"
#include <osgManipulator/CommandManager>
#include <osgManipulator/TranslateAxisDragger>
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer/View>
#include <osg/Vec3d>
#include <math.h>

namespace bimWorld
{
	namespace Manipulator
	{

		class YIZHU_EXPORT DraggerManipulator : public MouseManipulatorBase
		{


#define getMaxRadius(axis, nodeCenter, nodeRadius, radius) \
				auto min##axis = abs(nodeCenter.axis() - nodeRadius); \
				auto max##axis = abs(nodeCenter.axis() + nodeRadius); \
				if (min##axis > max##axis) \
					radius = (radius < min##axis) ? min##axis : radius; \
																																																																																																																																																																																																																																																																else \
					radius = (radius < max##axis) ? max##axis : radius;

		public:
			DraggerManipulator() :MouseManipulatorBase()
			{
				m_dragger = new osgManipulator::TranslateAxisDragger;
				m_dragger->setupDefaultGeometry();
				m_selection = new osgManipulator::Selection;
				m_manager = new osgManipulator::CommandManager;
				_activeDragger = NULL;
			}

			osg::Vec3d getTransition()
			{
				return m_dragger->getMatrix().getTrans();
			}

			osg::Quat getRotation()
			{
				return m_dragger->getMatrix().getRotate();
			}

			osg::Vec3d getScale()
			{
				auto cur_sal = m_dragger->getMatrix().getScale();
				auto vx = (m_initScale.x() == 0) ? 0 : cur_sal.x() / m_initScale.x();
				auto vy = (m_initScale.y() == 0) ? 0 : cur_sal.y() / m_initScale.y();
				auto vz = (m_initScale.z() == 0) ? 0 : cur_sal.z() / m_initScale.z();
				return osg::Vec3d(vx, vy, vz);
			}

			std::vector<osg::Node*> getSelectedNodes()
			{
				return m_selectedNodes;
			}

			void setSeletedNodes(osg::Node* node)
			{
				m_selection->removeChildren(0, m_selection->getNumChildren());
				m_selectedNodes.clear();

				float scale = node->getBound().radius() * 1.4f;
				m_initScale = osg::Vec3d(scale, scale, scale);
				m_dragger->setMatrix(osg::Matrix::scale(m_initScale) * osg::Matrix::translate(node->getBound().center()));
				m_selection->addChild(node);
				m_selectedNodes.push_back(node);
			}

			void setSeletedNodes(std::vector<osg::Node*> nodes)
			{
				m_selection->removeChildren(0, m_selection->getNumChildren());
				m_selectedNodes.clear();

				float scaleX, scaleY, scaleZ;
				float radiusX, radiusY, radiusZ;

				osg::Vec3f center = osg::Vec3f(0, 0, 0);
				for (int i = 0; i < nodes.size(); i++)
				{
					auto nodeCenter = nodes[i]->getBound().center();
					auto nodeRadius = nodes[i]->getBound().radius();

					getMaxRadius(x, nodeCenter, nodeRadius, radiusX);
					getMaxRadius(y, nodeCenter, nodeRadius, radiusY);
					getMaxRadius(z, nodeCenter, nodeRadius, radiusZ);

					center += nodeCenter;

					m_selection->addChild(nodes[i]);
					m_selectedNodes.push_back(nodes[i]);
				}

				if (nodes.size() > 1)
					center /= nodes.size();

				scaleX = radiusX * 1.4f;
				scaleY = radiusY * 1.4f;
				scaleZ = radiusZ * 1.4f;
				m_initScale = osg::Vec3d(scaleX, scaleY, scaleZ);
				m_dragger->setMatrix(osg::Matrix::scale(m_initScale) * osg::Matrix::translate(center));
			}

			virtual void Enable() override
			{
				m_manager->connect(*m_dragger, *m_selection);
				MouseManipulatorBase::Enable();
			}

			virtual void Disable() override
			{
				m_manager->disconnect(*m_dragger);
				MouseManipulatorBase::Disable();
			}

			virtual bool dealMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override
			{
				osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
				if (!view)
					return false;

				_pointer.reset();
				osgUtil::LineSegmentIntersector::Intersections hits;
				if (view->computeIntersections(ea, hits))
				{
					_pointer.setCamera(view->getCamera());
					_pointer.setMousePosition(ea.getX(), ea.getY());

					osgUtil::LineSegmentIntersector::Intersections::iterator;
					for (auto hitr = hits.begin(); hitr != hits.end(); ++hitr)
					{
						_pointer.addIntersection(hitr->nodePath,
							hitr->getLocalIntersectPoint());
					}

					osg::NodePath::iterator;
					for (auto itr = _pointer._hitList.front().first.begin();
						itr != _pointer._hitList.front().first.end(); ++itr)
					{
						osgManipulator::Dragger* dragger = dynamic_cast<osgManipulator::Dragger*>(*itr);
						if (dragger)
						{
							dragger->handle(_pointer, ea, aa);
							_activeDragger = dragger;
							break;
						}
					}
				}
				return true;
			}

			virtual bool dealMouseDrag(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override
			{
				osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
				if (!view)
					return false;

				if (!_activeDragger)
					return false;
				_pointer._hitIter = _pointer._hitList.begin();
				_pointer.setCamera(view->getCamera());
				_pointer.setMousePosition(ea.getX(), ea.getY());
				_activeDragger->handle(_pointer, ea, aa);

				return true;
			}

			virtual bool dealMouseRelease(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override
			{
				osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
				if (!view)
					return false;

				if (!_activeDragger)
					return false;

				_pointer._hitIter = _pointer._hitList.begin();
				_pointer.setCamera(view->getCamera());
				_pointer.setMousePosition(ea.getX(), ea.getY());
				_activeDragger->handle(_pointer, ea, aa);


				_activeDragger = NULL;
				_pointer.reset();

				// <操作器暂时不截断事件传递>
				return false;
			}

		protected:
			osg::ref_ptr<osgManipulator::Selection> m_selection;
			std::vector<osg::Node*> m_selectedNodes;
			osg::ref_ptr<osgManipulator::TranslateAxisDragger> m_dragger;
			osg::ref_ptr<osgManipulator::CommandManager> m_manager;

			osg::ref_ptr<osgManipulator::Dragger> _activeDragger;
			osgManipulator::PointerInfo _pointer;

			osg::Vec3d m_initScale;
		};
	}
}

#endif // __DRAGGER_MANIPULATOR_H__