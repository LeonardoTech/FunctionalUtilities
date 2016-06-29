////////////
//    created by 孙庆号
////////////

#ifndef __ANIMATION_EDITOR_H__
#define __ANIMATION_EDITOR_H__

#include <osg/AnimationPath>
#include <osg/Node>
#include <osg/Referenced>
#include <osgGA/CameraManipulator>
#include <osgAnimation/BasicAnimationManager>
#include <osgAnimation/UpdateMatrixTransform>
#include <osgAnimation/StackedTranslateElement>
#include "config.h"
#include "MouseManipulatorContainer.h"
#include "DraggerManipulator.h"
#include "AnimationChain.h"

namespace bimWorld
{
	namespace Animation
	{
		class YIZHU_EXPORT AnimationEditor : public osg::Referenced
		{
		public:
			AnimationEditor() :
				m_totalFrameNumber(100),
				m_framePerSecond(30),
				isActionAnimationStarted(false),
				m_currentActionPos(0)
			{
				m_totalTime = m_framePerSecond * m_totalFrameNumber;
				m_draggerManip = new Manipulator::DraggerManipulator();

				//m_channel1 = new osgAnimation::Vec3LinearChannel;
				//m_channel1->setName("position");
				//m_channel1->setTargetName("PathCallback");

				//m_animation = new osgAnimation::Animation;
				//m_animation->setPlayMode(osgAnimation::Animation::LOOP);
				//m_animation->addChannel(m_channel1.get());
				//manager = new osgAnimation::BasicAnimationManager();
				//manager->registerAnimation(m_animation.get());

				//osg::ref_ptr<osgAnimation::UpdateMatrixTransform> updater =
				//	new osgAnimation::UpdateMatrixTransform("PathCallback");
				//updater->getStackedTransforms().push_back(
				//	new osgAnimation::StackedTranslateElement("position"));
			}

			void Enable()
			{
				m_draggerManip->Enable();
			}

			void Disable()
			{
				m_draggerManip->Disable();
			}

			void setSelectedNodes(osg::Node* node)
			{
				m_draggerManip->setSeletedNodes(node);
			}

			void setSelectedNodes(std::vector<osg::Node*> nodes)
			{
				m_draggerManip->setSeletedNodes(nodes);
			}

			void setTotalFrameAndFrameRate(int frames, double framePerSecond)
			{
				m_totalFrameNumber = frames;
				m_framePerSecond = framePerSecond;
				m_totalTime = framePerSecond * frames;
			}

			void setTotalTimeAndFrameRate(double totalSeconds, double framePerSecond)
			{
				m_framePerSecond = framePerSecond;
				m_totalTime = totalSeconds;
				m_totalFrameNumber = static_cast<int>(totalSeconds / framePerSecond);

				// correct value for divide operation.
				m_framePerSecond = totalSeconds / m_totalFrameNumber;
				// just to make sure.
				m_totalTime = m_totalFrameNumber * m_framePerSecond;
			}

			void setTotalTimeAndTotalFrame(double totalSeconds, int frames)
			{
				m_totalTime = totalSeconds;
				m_totalFrameNumber = frames;
				m_framePerSecond = static_cast<int>(totalSeconds / frames);
			}

			/*
						// add animation path if current map doesn't contains specified node.
						osg::AnimationPath* getAnimationPath(osg::Node* node)
						{
						long nodeId = (long)node;
						auto iter = m_pathDic.find(nodeId);
						if (iter == m_pathDic.end())
						{
						// doesn't exist, so create it.
						osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath();
						path->setLoopMode(osg::AnimationPath::LOOP);
						m_pathDic.insert(std::pair<long, osg::ref_ptr<osg::AnimationPath> >(nodeId, path));
						osg::ref_ptr<osg::AnimationPathCallback> apcb = new
						osg::AnimationPathCallback;
						apcb->setAnimationPath(path);
						node->setUpdateCallback(apcb.get());
						}
						return iter->second.get();
						}*/

			// add animation path if current map doesn't contains specified node.
			AnimationKeyframeContainer* getKeyframeContainer(osg::Node* node)
			{
				long nodeId = (long)node;
				auto iter = m_pathDic.find(nodeId);
				if (iter == m_pathDic.end())
				{
					// doesn't exist, so create it.
					osg::ref_ptr<AnimationChain> path = new AnimationChain();
					m_pathDic.insert(std::pair<long, osg::ref_ptr<AnimationChain> >(nodeId, path));
					//osg::ref_ptr<osg::AnimationPathCallback> apcb = new
					//	osg::AnimationPathCallback;
					//apcb->setAnimationPath(path);
					//node->setUpdateCallback(apcb.get());
				}
				return iter->second.get()->getKeyframeContainer();
			}

			void SetKeyFrame(int frameNum)
			{
				auto trans = m_draggerManip->getTransition();
				auto scale = m_draggerManip->getScale();
				auto rotae = m_draggerManip->getRotation();
				auto nodes = m_draggerManip->getSelectedNodes();
				for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
				{
					SetKeyFrame(*iter, frameNum, trans, rotae, scale);
				}
			}

			void SetKeyFrame(osg::Node* node, int frameNum, const osg::Vec3d& position, const osg::Quat& rotation, const osg::Vec3d& scale)//double time,const ControlPoint& controlPoint
			{
				auto container = getKeyframeContainer(node);
				if (!container)
					return;
				container->transContainer.push_back(osgAnimation::Vec3Keyframe(frameNum * m_framePerSecond, position));
				container->rotateContainer.push_back(osgAnimation::QuatKeyframe(frameNum * m_framePerSecond, rotation));
				container->scaleContainer.push_back(osgAnimation::Vec3Keyframe(frameNum * m_framePerSecond, scale));
			}

			//void SetKeyFrame(osg::Node* node, int frameNum, const osg::Vec3d& position, const osg::Quat& rotation)//double time,const ControlPoint& controlPoint
			//{
			//	auto anima = getKeyframeContainer(node);
			//	if (!anima)
			//		return;
			//	anima->insert(frameNum * m_framePerSecond, osg::AnimationPath::ControlPoint(position, rotation));
			//}

			//void SetKeyFrame(osg::Node* node, int frameNum, const osg::Vec3d& position, const osg::Quat& rotation, const osg::Vec3d& scale)//double time,const ControlPoint& controlPoint
			//{
			//	// ControlPoint(const osg::Vec3d& position, const osg::Quat& rotation, const osg::Vec3d& scale):

			//	auto anima = getAnimationPath(node);
			//	if (!anima)
			//		return;
			//	anima->insert(frameNum * m_framePerSecond, osg::AnimationPath::ControlPoint(position, rotation, scale));
			//}


			void setManipulatorContainer(Manipulator::MouseManipulatorContainer* manip)
			{
				if (!manip)
				{
					if (m_manipulatorContainer)
					{
						m_manipulatorContainer->removeMouseManipulator("AnimationEditor_DraggerManipulator");
					}

					return;
				}
				m_manipulatorContainer = manip;
				m_manipulatorContainer->addOrReplaceMouseManipulator("AnimationEditor_DraggerManipulator", m_draggerManip.get());
			}

			void play()
			{
				if (m_actionSequece.size() <= 0)
					return;
				//m_pathDic
				// start
				m_currentActionPos = 0;
				isActionAnimationStarted = true;
				osg::Timer::instance()->setStartTick();
				m_actionSequece[m_currentActionPos].second();

			}

			void stop()
			{
				//m_pathDic
				isActionAnimationStarted = false;
				m_currentActionPos = 0;
			}

			void playKeyFrame(int /*framePosition*/)
			{
				//m_pathDic
			}

			void addActionToSequece(const std::function<void()>& action, double delayMilliseconds)
			{
				m_actionSequece.push_back(std::pair<double, std::function<void()> >(delayMilliseconds, action));
			}

			void clearActionSequece()
			{
				m_actionSequece.clear();
			}

			void update()
			{
				if (isActionAnimationStarted && m_actionSequece.size() > 0)
				{
					if (osg::Timer::instance()->time_m() > m_actionSequece[m_currentActionPos].first)
					{
						// start next action.
						osg::Timer::instance()->setStartTick();
						m_actionSequece[m_currentActionPos++].second();
						if (m_currentActionPos >= m_actionSequece.size())
							m_currentActionPos = 0;
					}
					return;
				}
			}

		protected:
			bool isActionAnimationStarted;
			int m_currentActionPos;
			std::vector<std::pair<double, std::function<void()> > > m_actionSequece;
			std::map<long, osg::ref_ptr<AnimationChain> > m_pathDic;
			osg::ref_ptr<Manipulator::MouseManipulatorContainer> m_manipulatorContainer;
			double m_totalTime;
			int m_totalFrameNumber;
			double m_framePerSecond;
			osg::ref_ptr<Manipulator::DraggerManipulator> m_draggerManip;
			osg::ref_ptr<osgAnimation::BasicAnimationManager> manager;
			osg::ref_ptr<osgAnimation::Animation> m_animation;
			osg::ref_ptr<osgAnimation::Vec3LinearChannel> m_channel1;
		};
	}
}
#endif // __ANIMATION_EDITOR_H__