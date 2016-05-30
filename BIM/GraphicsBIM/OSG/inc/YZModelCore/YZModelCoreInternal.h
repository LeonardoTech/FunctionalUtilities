////////////
//    created by 孙庆号
////////////

#ifndef __INTERNAL_OF_MODEL_CORE_h__
#define __INTERNAL_OF_MODEL_CORE_h__

#include "Billboard.h"
#include "BackgroundSetting.h"
#include "CameraManipulators.h"
#include "ViewerDataModel.h"
#include "RenderingThreads.h"
#include "Coordinate.h"
#include "NodeController.h"
#include "FixedFrameRate.h"
#include "ScreenCapture.h"
#include "CameraSettings.h"
#include "ZoomModel.h"
#include "SwitchView.h"
#include "MovingCamera.h"
#include "CameraOperation.h"
#include "SliceSettings.h"

#include "IModelCoreInternal.h"
#include "IBillboard.h"
#include "IBackgroundSetting.h"
#include "ICameraManipulators.h"
#include "IRenderingThreads.h"
#include "ICoordinate.h"
#include "INodeController.h"
#include "IFixedFrameRate.h"
#include "IScreenCapture.h"
#include "ISwitchView.h"
#include "IMovingCamera.h"
#include "IEventHandlers.h"

#include "IViewerDataModel.h"

#include "InteractionDefine.h"
#include "EventHandlers.h"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\\inc\\YZMaterial\\YZEffect.h"
#include "PlottingScale\PlottingScale.h"

namespace bimWorld
{
	class YIZHU_EXPORT YZModelCoreInternal : public IModelCoreInternal
	{
	public:
		YZModelCoreInternal();

		~YZModelCoreInternal();

		SHARED_PROPERTY(bimWorld::ViewerDataModel, _ViewerData, m_viewerData, this);

		SHARED_PROPERTY(bimWorld::CameraManipulator, _CameraManipulator, m_cameraManip, this);

		SHARED_PROPERTY(bimWorld::FixedFrameRate, _FixedFrameRate, m_fixedFramerate, this);

		SHARED_PROPERTY(bimWorld::RenderingThreads, _RenderingThreads, m_renderingThreads, this);

		SHARED_PROPERTY(bimWorld::BackgroundSetting, _BackgroundSetting, m_backgroundSetting, this);

		SHARED_PROPERTY(bimWorld::Coordinate, _Coordinate, m_coordinate, this);

		SHARED_PROPERTY(bimWorld::Billboard, _Billboard, m_billboard, this);

		SHARED_PROPERTY(bimWorld::NodeController, _NodeControl, m_nodeController, this);

		SHARED_PROPERTY(bimWorld::ScreenCapture, _ScreenCapture, m_screenCapture, this);

		SHARED_PROPERTY(bimWorld::CameraSettings, _CameraSettings, m_cameraSettings, this);

		SHARED_PROPERTY(bimWorld::ZoomModel, _ZoomModel, m_zoomModel, this);

		SHARED_PROPERTY(bimWorld::SwitchView, _SwitchView, m_switchView, this);

		SHARED_PROPERTY(bimWorld::MovingCamera, _MovingCamera, m_movingCamera, this);

		SHARED_PROPERTY(bimWorld::EventHandlers, _EventHandlers, m_eventHandlers, this);
		
		SHARED_PROPERTY(bimWorld::CameraOperation, _CameraOperations, m_cameraOperations, this);
		
		SHARED_PROPERTY(bimWorld::SliceSettings, _SliceSettings, m_sliceSettings, this);

		SHARED_PROPERTY(bimWorld::PlottingScale, _PlottingScales, m_plottingScales, this);

		IMPLEMENT_INTERFACE(bimWorld::IViewerDataModel, _ViewerData, ViewerData);


		IMPLEMENT_INTERFACE(bimWorld::IScreenCapture, _ScreenCapture, ScreenCapture);
		
		IMPLEMENT_INTERFACE(bimWorld::ICameraSettings, _CameraSettings, CameraSettings);
		
		IMPLEMENT_INTERFACE(bimWorld::ICameraManipulators, _CameraManipulator, CameraManipulator);

		IMPLEMENT_INTERFACE(bimWorld::IFixedFrameRate, _FixedFrameRate, FixedFrameRate);

		IMPLEMENT_INTERFACE(bimWorld::IRenderingThreads, _RenderingThreads, RenderingThreads);

		IMPLEMENT_INTERFACE(bimWorld::IBackgroundSetting, _BackgroundSetting, BackgroundSetting);

		IMPLEMENT_INTERFACE(bimWorld::ICoordinate, _Coordinate, Coordinates);

		IMPLEMENT_INTERFACE(bimWorld::IBillboard, _Billboard, Billboard);

		IMPLEMENT_INTERFACE(bimWorld::INodeController, _NodeControl, NodeControl);

		IMPLEMENT_INTERFACE(bimWorld::IZoomModel, _ZoomModel, ZoomModel);
		
		IMPLEMENT_INTERFACE(bimWorld::ISwitchView, _SwitchView, SwitchView);

		IMPLEMENT_INTERFACE(bimWorld::IMovingCamera, _MovingCamera, MovingCamera);

		IMPLEMENT_INTERFACE(bimWorld::IEventHandlers, _EventHandlers, EventHandlers);
		
		IMPLEMENT_INTERFACE(bimWorld::ICameraOperation, _CameraOperations, CameraOperations);
		
		IMPLEMENT_INTERFACE(bimWorld::ISlice, _SliceSettings, SliceSettings);

		IMPLEMENT_INTERFACE(IPlottingScale, _PlottingScales, PlottingScales);

#ifdef USING_QT
		virtual QWidget* getWidget() override;
#endif // USING_QT

		// module

		SHARED_MODULE(bimWorld::YZEffect, _Materials, m_materials);

		//IMPLEMENT_INTERFACE(bimWorld::IEffects, _Materials, Materials);

	//internal:

	};
}


#endif // __INTERNAL_OF_MODEL_CORE_h__
