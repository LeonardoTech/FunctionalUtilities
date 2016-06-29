////////////
//    created by 孙庆号
////////////

#ifndef __YZMODEL_CORE_H__
#define __YZMODEL_CORE_H__


#include <memory>
#include "IBillboard.h"
#include "IBackgroundSetting.h"
#include "ICameraManipulators.h"
#include "IRenderingThreads.h"
#include "INodeController.h"
#include "IFixedFrameRate.h"
#include "IScreenCapture.h"
#include "IZoomModel.h"
#include "ISwitchView.h"
#include "IMovingCamera.h"
#include "IEventHandlers.h"
#include "ICoordinate.h"

#include "ICameraSettings.h"
#include "ICameraOperation.h"
#include "ISlice.h"
#include "IPlottingScale.h"

#ifdef USING_QT
#include <QtWidgets/QWidget>
#endif

namespace bimWorld
{
	class YIZHU_EXPORT IModelCore
	{
	public:
		// <viewer data model 不公开到外部>

		virtual std::shared_ptr<bimWorld::ICameraManipulators> CameraManipulator() = 0;

		virtual std::shared_ptr<bimWorld::IFixedFrameRate> FixedFrameRate() = 0;

		virtual std::shared_ptr<bimWorld::IRenderingThreads> RenderingThreads() = 0;

		virtual std::shared_ptr<bimWorld::IBackgroundSetting> BackgroundSetting() = 0;

		virtual std::shared_ptr<bimWorld::IBillboard> Billboard() = 0;

		virtual std::shared_ptr<bimWorld::INodeController> NodeControl() = 0;

		virtual std::shared_ptr<bimWorld::IScreenCapture> ScreenCapture() = 0;

		virtual std::shared_ptr<bimWorld::ICameraSettings> CameraSettings() = 0;
		
		virtual std::shared_ptr<bimWorld::IZoomModel> ZoomModel() = 0;

		virtual std::shared_ptr<bimWorld::ISwitchView> SwitchView() = 0;

		virtual std::shared_ptr<bimWorld::IMovingCamera> MovingCamera() = 0;

		virtual std::shared_ptr<bimWorld::IEventHandlers> EventHandlers() = 0;

		//virtual std::shared_ptr<bimWorld::IEffects> Materials() = 0;

		virtual std::shared_ptr<bimWorld::ICameraOperation> CameraOperations() = 0;
		
		virtual std::shared_ptr<bimWorld::ISlice> SliceSettings() = 0;

		virtual std::shared_ptr<bimWorld::ICoordinate> Coordinates() = 0;

		virtual std::shared_ptr<IPlottingScale> PlottingScales() = 0;

#ifdef USING_QT
		virtual QWidget* getWidget() = 0;
#endif
	};
}

#endif // __YZMODEL_CORE_H__
