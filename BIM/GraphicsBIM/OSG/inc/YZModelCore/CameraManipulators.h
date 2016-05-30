////////////
//    created by 孙庆号
////////////

//
//  CameraManipulators.h
//  ModelViewer
//  Created by sqh on 2015-8-4.
//
#ifndef __CAMERA_MANIPULATOR_H__
#define __CAMERA_MANIPULATOR_H__

#include "YZModelCoreModule.h"
#include <osgGA/KeySwitchMatrixManipulator>
#include "ManipulatorType.h"
//#include "ModelViewerImpl.h"
#include "ZoomModel.h"
#include <osg/Camera>
#include "Pick.h"
#include <memory>
#include "ICameraManipulators.h"
#include "CameraAnimation.h"
//#include "FixedFramerateController.h"
//#include <osgGA/MultiTouchTrackballManipulator>
//#include "fireSelectionEvent.h"
//#include "DragSelectionManipulator.h"
//#include "DraggerManipulator.h"
//#include "MouseManipulatorContainer.h"
//#include "osgGA/FirstPersonManipulator"
//#include "CameraManipulatorPickBase.h"
//#include "BIMFirstPersonManipulator.h"

namespace bimWorld
{
	class BIMCameraManipulator;

	class YIZHU_EXPORT CameraManipulator :public YZModelCoreModule, public ICameraManipulators
	{
	public:
		CameraManipulator(YZModelCoreInternal* host);

		void init();

		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换漫游器. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="emanip">	The emanip. </param>
		///-------------------------------------------------------------------------------------------------
		virtual void switchMatrixManipulator(ManipulatorType emanip) override;

		virtual bimWorld::ViewerMode getCameraManipulatorMode() override;

		virtual void enableFirstPersonControl() override;

		virtual void disableFirstPersonControl() override;

		virtual void setCollisionEnabled(bool enabled) override;

		virtual void setGravityEnabled(bool enabled) override;

		////////////////////////////////////////////////////////视图模式//////////////////////////////////////////////////////////////////////////////////
		virtual void setViewerMode(ViewerMode viewerMode) override;

		virtual std::shared_ptr<bimWorld::IZoomModel> ZoomModel() override;

		virtual const bimWorld::ListenerSet& getListeners() const override;

		virtual void clearSelection() override;

		virtual void updateModelSize() override;

		virtual void setModelCenter(void* center) override;

		// keep eye.
		virtual void setModelCenterKeepViewPoint(void* center) override;

		virtual void bindKeyUpEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) override;

		virtual void bindKeyDownEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) override;

		virtual void bindMouseEvent(bimWorld::MouseButtonMask mouse, bimWorld::CameraOperationTypes operation) override;

		virtual void unbindKeyUpEvent(bimWorld::KeySymbol key) override;

		virtual void unbindKeyDownEvent(bimWorld::KeySymbol key) override;

		virtual void unbindMouseEvent(bimWorld::MouseButtonMask mouse) override;

		virtual void bindButtonUpEvent(int btnId, bimWorld::CameraOperationTypes operation) override;
		
		virtual void unbindButtonUpEvent(int btnId) override;

		virtual void bindButtonDownEvent(int btnId, bimWorld::CameraOperationTypes operation) override;

		virtual void unbindButtonDownEvent(int btnId) override;

		virtual void addButton(int& outBtnId, std::function<void()>& outDownFunc, std::function<void()>& outUpFunc) override;
		
		virtual void pushForward(const float dy);
		
		virtual void panModel(const float dx, const float dy, const float dz = 0);
		
		virtual void pushSide(const float dx, const float dy, const float dz = 0);
		
		virtual void zoomModel(const float dy, bool pushForwardIfNeeded = true);

		virtual void zoomModelLocally(const float pointX, const float pointY, const float dy, bool pushForwardIfNeeded = true);

		virtual void zoomModelWithSelectedCenter(const float dy, bool pushForwardIfNeeded = true);

	//internal:

		virtual std::shared_ptr<bimWorld::CameraAnimation> CameraAnimation();

		virtual osg::Camera* getCamera();

		osgGA::CameraManipulator* getCameraManipulator();

		bimWorld::BIMCameraManipulator* getBIMCameraManip();

		void selectCenterModel();

		// <是否在漫游，包括第一人称和第三人称>
		bool isRoaming();

	protected:
		// <绘制: true，更新: false。在执行 Camera 动画之前，在绘制阶段还是在仅更新阶段。>
		bool origin_draw;

		osg::ref_ptr<osgGA::CameraManipulator> m_d, m_p;

		// <漫游器切换>
		osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> m_ptrKeySwitchMatrixManipulator;

		// BIMCameraManipulator mode.
		bimWorld::ViewerMode m_cameraManipulatorMode;

		std::shared_ptr<bimWorld::ZoomModel> m_zoomModel;

		// <视图监听器集合>
		bimWorld::ListenerSet m_modelViewerListeners;

		std::shared_ptr<bimWorld::CameraAnimation> m_cameraAnimation;

		bool m_isFirstPersonManipEnabled;
		float m_zoomForwardDelta;

		std::map<int, std::function<bool()> > m_buttonUpEventMap;

		std::map<int, std::function<bool()> > m_buttonDownEventMap;

		int m_nextBtnId;
        
        int hasPressed;
		bool m_firstPerson;
	};
}

#endif // __CAMERA_MANIPULATOR_H__