////////////
//    created by 孙庆号
////////////

#ifndef __FIXED_PATH_ANIMATION_H__
#define __FIXED_PATH_ANIMATION_H__
#include <osg/AnimationPath>
#include "MouseManipulatorContainer.h"
#include "CreatePointManipulator.h"
#include <vector>
#include <osg/Group>
#include <osg/Node>
#include <osg/Material>
#include <osgGA/AnimationPathManipulator>
#include <math.h>
#include "DefaultMaterial.h"

namespace bimWorld
{
	namespace Animation
	{
		class FixedPathAnimation :public osg::Node
		{
		public:
			FixedPathAnimation()
			{
				m_createPointManip = NULL;
				m_geode = new osg::Geode();
				m_path = new osg::AnimationPath;
				m_aniCallback = new osg::AnimationPathCallback;
				hasApplied = false;
				m_geom = new osg::Geometry();
				m_geode->addDrawable(m_geom);


				double rgba[4] = { 1.0, 0.0, 0.0, 0.6 };

				auto state = new osg::StateSet();
				DefaultMaterial selectionMat;
				selectionMat.setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(rgba[0], rgba[1], rgba[2], rgba[3]));
				selectionMat.setShininess(osg::Material::FRONT_AND_BACK, 90);
				selectionMat.setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(rgba[0], rgba[1], rgba[2], rgba[3]));
				selectionMat.setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(rgba[0], rgba[1], rgba[2], rgba[3]));
				selectionMat.apply(state, osg::StateAttribute::PROTECTED);
				m_geode->setStateSet(state);
			}
			void Initialize(osg::Group* root, std::function<osg::Vec3(float, float)> getPosFunc, osg::Vec3 downVec)
			{
				root->removeChild(m_geode);
				root->addChild(m_geode);
				m_createPointManip = new Manipulator::CreatePointManipulator(getPosFunc, [this, downVec](const std::vector<osg::Vec3>& points){
					drawLines(points);
					static int time = 0;
					if (points.size() > 0)
					{
						if (points.size() > 1)
						{
							osg::Vec3 down = downVec;
							osg::Vec3 direction = points[points.size() - 2] - points[points.size() - 1];
							auto angle = std::acos((downVec*direction) / (down.normalize()*direction.normalize()));
							//auto y1 = down.
							// (y1*z2-z1*y2, z1*x2-x1*z2, x1*y2-y1*x2)
							//osg::Vec3 axis((), )
							//osg::Quat rotation(angle, axis);
							//if (!m_path->empty())
							//{
							//	m_path->getTimeControlPointMap()[m_path->getLastTime()].setRotation(rotation);
							//}
						}
					}
					AddControlPoint(time++, points[points.size() - 1]);

				});
				m_createPointManip->Enable();
				m_downVec = downVec;
				m_path->clear();
			}
			// <设置循环模式>
			void SetLoopMode(osg::AnimationPath::LoopMode loopmode = osg::AnimationPath::LOOP){
				m_path->setLoopMode(loopmode);
			}

			// <添加控制节点>
			void AddControlPoint(double time)
			{
				m_path->insert(time, osg::AnimationPath::ControlPoint());
			}
			void AddControlPoint(double time, osg::AnimationPath::ControlPoint ctrlPoint){
				m_path->insert(time, ctrlPoint);
			}
			void AddControlPoint(double time, const osg::Vec3d& position){
				m_path->insert(time, osg::AnimationPath::ControlPoint(position));
			}
			void AddControlPoint(double time, const osg::Vec3d& position, const osg::Quat& rotation){
				m_path->insert(time, osg::AnimationPath::ControlPoint(position, rotation));
			}
			void AddControlPoint(double time, const osg::Vec3d& position, const osg::Quat& rotation, const osg::Vec3d& scale){
				m_path->insert(time, osg::AnimationPath::ControlPoint(position, rotation, scale));
			}

			void SetManipulatorContainer(Manipulator::MouseManipulatorContainer* manip)
			{
				if (!manip)
				{
					m_geom->setVertexArray(NULL);
					m_createPointManip->Disable();
					if (m_manipulatorContainer)
					{
						m_manipulatorContainer->removeMouseManipulator("FixedPathAnimation_DraggerManipulator");
					}
					return;
				}
				m_manipulatorContainer = manip;
				m_manipulatorContainer->addOrReplaceMouseManipulator("FixedPathAnimation_DraggerManipulator", m_createPointManip.get());
			}

			// <清空动画节点>
			void Clear()
			{
				m_path->clear();
				m_geom->setVertexArray(NULL);
				if (m_createPointManip)
					m_createPointManip->clear();
			}

			// <将动画应用到指定节点上>
			osgGA::AnimationPathManipulator* Apply(/*osg::Node* node*/){
				if (m_path->empty() || m_path->getTimeControlPointMap().size() < 2)
				{
					return NULL;
				}
				osg::ref_ptr<osgGA::AnimationPathManipulator> manip = new osgGA::AnimationPathManipulator;
				hasApplied = true;
				manip->setAnimationPath(m_path);
				return manip.release();
				//m_currentNode = node;
				//m_parent = node->getParent(0);
				//if (m_parent)
				//{
				//	m_parent->addChild(root);
				//	m_parent->removeChild(node);
				//}
				//root->addChild(node);
				//m_aniCallback->setAnimationPath(m_path);
				//root->setUpdateCallback(m_aniCallback.get());
				//hasApplied = true;
			}

			void Stop()
			{
				root->removeUpdateCallback(m_aniCallback.get());
				m_parent->addChild(m_currentNode);
				root->removeChild(m_currentNode);
			}

			// <重置>
			void Reset(){
				if (!hasApplied)
				{
					osg::notify(osg::WARN) << "Need to apply first. in FixedPathAnimation::Reset";
					return;
				}
				m_aniCallback->reset();
			}

			// <暂停动画>
			void Pause(){
				if (!hasApplied)
				{
					osg::notify(osg::WARN) << "Need to apply first. in FixedPathAnimation::Pause";
					return;
				}
				m_aniCallback->setPause(true);
			}

			// <继续动画>
			void Continue(){
				if (!hasApplied)
				{
					osg::notify(osg::WARN) << "Need to apply first. in FixedPathAnimation::Continue";
					return;
				}
				m_aniCallback->setPause(false);
			}

			// <设置时间偏移>
			void SetTimeOffset(double time){
				if (!hasApplied)
				{
					osg::notify(osg::WARN) << "Need to apply first. in FixedPathAnimation::SetTimeOffset";
					return;
				}
				m_aniCallback->setTimeOffset(time);
			}

			// <设置播放倍数>
			void SetTimeMultiplier(double multiple){
				if (!hasApplied)
				{
					osg::notify(osg::WARN) << "Need to apply first. in FixedPathAnimation::SetTimeMultiplier";
					return;
				}
				m_aniCallback->setTimeMultiplier(multiple);
			}

			void drawLines(const std::vector<osg::Vec3>& points){
				osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(points.size(), points.data());
				m_geom->setVertexArray(vertices);
				m_geom->removePrimitiveSet(0, m_geom->getNumPrimitiveSets());
				m_geom->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, 0, points.size()));
			}

		protected:
			bool hasApplied;
			osg::ref_ptr<osg::Group> m_parent;
			osg::ref_ptr<osg::Node> m_currentNode;
			osg::ref_ptr<osg::MatrixTransform> root;
			osg::ref_ptr<osg::AnimationPath> m_path;
			osg::ref_ptr<osg::Geode> m_geode;
			osg::ref_ptr<osg::Geometry> m_geom;
			osg::ref_ptr<osg::AnimationPathCallback> m_aniCallback;
			osg::ref_ptr<Manipulator::CreatePointManipulator> m_createPointManip;
			osg::ref_ptr<Manipulator::MouseManipulatorContainer> m_manipulatorContainer;
			osg::Vec3 m_downVec;
		private:
		};
	}
}
#endif // __FIXED_PATH_ANIMATION_H__