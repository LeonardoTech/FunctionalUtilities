////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_ANIMATOR_H__
#define __CAMERA_ANIMATOR_H__

//#include <osg/NodeCallback>
#include "DataModel.h"
#include <vector>
#include <osg/Vec3>
#include <osg/Referenced>
//#include "CameraManipulators.h"
//#include <osg/Camera>
//#include <osgViewer/Viewer>
#include "YZModelCoreModule.h"
#include <functional>


#define CAMERA_ANIMATOR_VALIDATION_MASK 423789273

namespace bimWorld
{

	struct CameraVector
	{
		osg::Vec3 eye;
		osg::Vec3 center;
		osg::Vec3 up;
	};

	class CameraAnimator :
		public osg::Referenced, public YZModelCoreModule
	{
	public:

		CameraAnimator(YZModelCoreInternal* sender);

		void addCompleteCallback(std::function<void()>);

		void addUpdateCallback(std::function<void(const CameraAnimator*)>);

		void play()
		{
			if (!isValid())
				return;
			resetAnimation();
			m_isAnimating = true;
		}

		void finish();

		void setPath(std::vector<bimWorld::CameraVector> path)
		{
			if (!isValid())
				return;

			resetAnimation();
			m_path = path;
		}

		bimWorld::CameraVector* getCameraViewStruct();

		bool isAnimating()
		{
			if (!isValid())
				return false;

			return m_isAnimating;
		}

		bool isFinished()
		{
			if (!isValid())
				return false;

			return m_isFinished;
		}

		bool hasAnimation()
		{
			if (!isValid())
				return false;

			return m_path.size() > 0;
		}

		void clearAnimation()
		{
			if (!isValid())
				return;

			m_path.clear();
			resetAnimation();
		}

	protected:
		bool m_isAnimating;
		bool m_isFinished;
		std::vector<bimWorld::CameraVector> m_path;
		int m_index;
		
		std::vector<std::function<void()> > m_completeCallback;
		std::vector<std::function<void(const CameraAnimator*)> > m_updateCallback;

		void resetAnimation()
		{
			if (!isValid())
				return;

			m_isAnimating = false;
			m_isFinished = false;
			m_index = 0;
		}

		bool isValid()
		{
			return (this->m_validCode == CAMERA_ANIMATOR_VALIDATION_MASK);
		}

	private:
		int m_validCode;
	};

	//
	//class UpdateCameraCallback :public osg::NodeCallback
	//{
	//public:
	//	UpdateCameraCallback(std::vector<bimWorld::CameraView> vector, osgViewer::Viewer* viewer)
	//	{
	//		m_vector = vector;
	//		m_viewer = viewer;
	//		m_index = 0;
	//	}
	//
	//	/** Callback method called by the NodeVisitor when visiting a node.*/
	//	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override
	//	{
	//		// note, callback is responsible for scenegraph traversal so
	//		// they must call traverse(node,nv) to ensure that the
	//		// scene graph subtree (and associated callbacks) are traversed.
	//		if (node)
	//		{
	//			auto manipulator = static_cast<bimWorld::BIMCameraManipulator*>(m_viewer->getCameraManipulator());
	//			auto camera = static_cast<osg::Camera*>(node);
	//			if (manipulator && m_index >= 0 && m_index < m_vector.size())
	//			{
	//				auto cameraView = m_vector.at(m_index++);
	//				manipulator->setHomePosition(
	//					osg::Vec3d(cameraView.position[0], cameraView.position[1], cameraView.position[2]),
	//					osg::Vec3d(cameraView.target[0], cameraView.target[1], cameraView.target[2]),
	//					osg::Vec3d(cameraView.upVector[0], cameraView.upVector[1], cameraView.upVector[2])
	//					);
	//				manipulator->home(0.0);
	//			}
	//		}
	//
	//		traverse(node, nv);
	//	}
	//protected:
	//	std::vector<bimWorld::CameraView> m_vector;
	//	osg::ref_ptr<osgViewer::Viewer> m_viewer;
	//	int m_index;
	//private:
	//};
	//
	//class AnimeCompletedCallback :public osgGA::AnimationPathManipulator::AnimationCompletedCallback
	//{
	//public:
	//	AnimeCompletedCallback(osgViewer::Viewer* viewer, osgGA::CameraManipulator* cameraManipulator) :
	//		m_viewer(viewer),
	//		m_origianl_cameraManipulator(cameraManipulator)
	//	{
	//	}
	//
	//	virtual void completed(const osgGA::AnimationPathManipulator* apm) override
	//	{
	//		m_viewer->setCameraManipulator(m_origianl_cameraManipulator);
	//	}
	//protected:
	//	osgGA::CameraManipulator* m_origianl_cameraManipulator;
	//	osgViewer::Viewer* m_viewer;
	//private:
	//};

}
#endif // __CAMERA_ANIMATOR_H__