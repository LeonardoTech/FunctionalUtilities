////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_VIEWER_H__
#define __MODEL_VIEWER_H__
#include "config.h"
#include "IModelViewer.h"

#include "IAnimations.h"
#include "IModelCore.h"
#include "IModelEntity.h"
//#include "ConstructSelectListener.h"
//#include "Material.h"

#ifdef _WIN32
#ifdef USING_QT
#else
#include <Windows.h>
#endif
#endif // _WIN32
#include <atomic>

namespace bimWorld
{
	class YIZHU_EXPORT ModelViewer : public IModelViewer
	{
	public:
#ifdef _WIN32
#ifdef USING_QT
		ModelViewer(QWidget* widget);
		QWidget* getWidget() override;
#else
		ModelViewer(HWND hwnd);
#endif
#elif Android
		ModelViewer(int x,int y,int width,int height);
#elif __APPLE__
#else
#endif // _WIN32

		//#ifdef _WIN32
		//		virtual void initGraphicContext(/*osg::GraphicsContext::Traits* traits*/HWND hwnd);
		//#else
		//		void loadParam();
		//		void* reorganize();
		//#endif // _WIN32


#pragma region Core
		bimWorld::IBackgroundSetting* BackgroundSetting() override;
		bimWorld::IBillboard* Billboard() override;
		bimWorld::ICameraManipulators* CameraManipulator() override;
		virtual bimWorld::ICameraOperation* CameraOperation() override;
		//bimWorld::IPick* Pick override;
		bimWorld::ICoordinate* Coordinates() override;
		bimWorld::ICameraSettings* CameraSetting() override;
		bimWorld::IFixedFrameRate* FixedFrameRate() override;
		//bimWorld::INodeController* NodeControl override;
		bimWorld::IRenderingThreads* RenderingThread() override;
		bimWorld::IScreenCapture* ScreenCapture() override;
		//bimWorld::IZoomModel* ZoomModel() override;
		bimWorld::ISwitchView* SwitchView() override;
		bimWorld::IMovingCamera* MovingCamera() override;
		//bimWorld::IConfig* Config() override;  
		bimWorld::IEventHandlers* EventHandlers() override;
		virtual bimWorld::ISlice* SliceSettings() override;
		virtual bimWorld::IPlottingScale* PlottingScales() override;
		virtual bimWorld::ITestModule* TestModules() override;
#pragma endregion

#pragma region Animation
		bimWorld::Animation::IKeyFrameAnimation* KeyFrameAnimation() override;
		bimWorld::Animation::ICameraAnimationPath* CameraPathAnimation() override;
#pragma endregion

#pragma region Entity
		//bimWorld::IModelEntity* ModelEntity() override; 
		bimWorld::INodeEntityController* NodeControl() override;
		bimWorld::IModelLoader* ModelLoader() override;
		bimWorld::IZoomEntityModel* ZoomModel() override;
		bimWorld::IProgressInfo* ProgressInfo() override;
#pragma endregion

#pragma region BLL
		virtual bimWorld::ISelectionController* SelectionController() override;
		//virtual bimWorld::ITestModule* TestModules() override;
#pragma endregion


		//bimWorld::MaterialSetting* Material() override;


	protected:
		std::shared_ptr<bimWorld::IModelCore> m_modelCore;
		//bimWorld::Billboard* m_billboard;
		//bimWorld::BackgroundSetting* m_backgroundSetting;
		//bimWorld::CameraManipulator* m_cameraManipulator;
		//bimWorld::Pick* m_pick;
		//bimWorld::Coordinate* m_coordinate;
		//bimWorld::ScreenCapture* m_screenCapture;
		//bimWorld::RenderingThreads* m_renderingThread;
		//bimWorld::NodeController* m_nodeControl;
		//bimWorld::ProgressInfo* m_progressInfo;
		//bimWorld::CameraSetting* m_cameraSetting;
		//bimWorld::Config* m_config;
		std::shared_ptr<bimWorld::IAnimations> m_animation;
		std::shared_ptr<bimWorld::IModelEntity> m_modelEntity;
		//bimWorld::MaterialSetting* m_material;
		std::shared_ptr<bimWorld::ISelectionController> m_selectionCtrler;
		std::shared_ptr<bimWorld::ITestModule> m_testModule;
		std::shared_ptr<bimWorld::IPlottingScale>m_plottingScale;
		// is initialize finished
		std::atomic_bool m_initialized;
	};
}

#endif // __MODEL_VIEWER_H__