////////////
//    created by 孙庆号
////////////

#include "ModelViewer.h"
#include "ModelCoreFactory.h"
#include "ModelEntityFactory.h"
#include "AnimationFactory.h"
#include "SelectionController.h"

#ifdef _WIN32
#ifdef USING_QT
//bimWorld::ModelViewer::ModelViewer(int width, int height)
bimWorld::ModelViewer::ModelViewer(QWidget* widget)
{
	m_initialized = false;
	m_animation = AniamtionFactory().getModule();
	//m_modelCore = ModelCoreFactory().getModule(width, height);
	m_modelCore = ModelCoreFactory().getModule(widget);
	m_modelEntity = ModelEntityFactory().getModule(m_modelCore.get());
	m_initialized = true;
	m_selectionCtrler = std::make_shared<bimWorld::SelectionController>(this);
	m_testModule = ModelCoreFactory().getTestModule(m_modelCore.get());
	m_plottingScale = ModelCoreFactory().getPlottingScale(m_modelCore.get());
}

QWidget* bimWorld::ModelViewer::getWidget()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->getWidget();
}

#else
bimWorld::ModelViewer::ModelViewer(HWND hwnd)
{
	m_initialized = false;
	m_animation = AniamtionFactory().getModule();
	//m_billboard = new bimWorld::Billboard();
	//m_backgroundSetting = new bimWorld::BackgroundSetting();
	//m_cameraManipulator = new bimWorld::CameraManipulator();
	//m_pick = new bimWorld::Pick();
	//m_coordinate = new bimWorld::Coordinate();
	//m_screenCapture = new bimWorld::ScreenCapture();
	//m_renderingThread = new bimWorld::RenderingThread();
	//m_nodeControl = new bimWorld::NodeController();
	//m_progressInfo = new bimWorld::ProgressInfo();
	//m_cameraSetting = new bimWorld::CameraSetting();
	//m_config = new bimWorld::Config();
	//m_animation = new bimWorld::AniamtionBLL();
	m_modelCore = ModelCoreFactory().getModule(hwnd);
	m_modelEntity = ModelEntityFactory().getModule(m_modelCore.get());
	//m_material = std::make_shared<bimWorld::MaterialSetting>();
	m_initialized = true;
	m_selectionCtrler = std::make_shared<bimWorld::SelectionController>(this);
}
#endif
#elif Android
bimWorld::ModelViewer::ModelViewer(int x,int y,int width,int height)
{
	m_initialized = false;
	m_animation = AniamtionFactory().getModule();
	m_modelCore = ModelCoreFactory().getModule(x, y, width, height);
	m_modelEntity = ModelEntityFactory().getModule(m_modelCore.get());
	m_initialized = true;
    m_selectionCtrler = std::make_shared<bimWorld::SelectionController>(this);
}
#elif __APPLE__
#else

#endif // _WIN32


//bimWorld::ModelViewer::~ModelViewer()
//{
	//m_modelCore->RenderingThreads()->setDone(true);
//}


bimWorld::IBillboard* bimWorld::ModelViewer::Billboard()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->Billboard().get();
}

bimWorld::IBackgroundSetting* bimWorld::ModelViewer::BackgroundSetting()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->BackgroundSetting().get();
}

bimWorld::ICameraManipulators* bimWorld::ModelViewer::CameraManipulator()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->CameraManipulator().get();
}

bimWorld::IScreenCapture* bimWorld::ModelViewer::ScreenCapture()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->ScreenCapture().get();
}

bimWorld::IRenderingThreads* bimWorld::ModelViewer::RenderingThread()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->RenderingThreads().get();
}

//bimWorld::INodeController* bimWorld::ModelViewer::NodeControl()
//{
//	return m_modelCore->NodeControl().get();
//}

bimWorld::IProgressInfo* bimWorld::ModelViewer::ProgressInfo()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	//return m_modelCore->pro().get();
	return NULL;
}

bimWorld::ICameraSettings* bimWorld::ModelViewer::CameraSetting()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->CameraSettings().get();
}

bimWorld::Animation::ICameraAnimationPath* bimWorld::ModelViewer::CameraPathAnimation()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_animation->CameraPathAnimation().get();
}

bimWorld::Animation::IKeyFrameAnimation* bimWorld::ModelViewer::KeyFrameAnimation()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_animation->KeyFrameAnimation().get();
}

bimWorld::IFixedFrameRate* bimWorld::ModelViewer::FixedFrameRate()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->FixedFrameRate().get();
}

bimWorld::IZoomEntityModel* bimWorld::ModelViewer::ZoomModel()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelEntity->ZoomEntityModel().get();
}

bimWorld::INodeEntityController* bimWorld::ModelViewer::NodeControl()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelEntity->ControlByData().get();
}

bimWorld::IModelLoader* bimWorld::ModelViewer::ModelLoader()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelEntity->ModelLoader().get();
}

bimWorld::ISwitchView* bimWorld::ModelViewer::SwitchView()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->SwitchView().get();
}

bimWorld::IMovingCamera* bimWorld::ModelViewer::MovingCamera()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->MovingCamera().get();
}

bimWorld::IEventHandlers* bimWorld::ModelViewer::EventHandlers()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->EventHandlers().get();
}

bimWorld::ISelectionController* bimWorld::ModelViewer::SelectionController()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_selectionCtrler.get();
}

bimWorld::ICameraOperation* bimWorld::ModelViewer::CameraOperation()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->CameraOperations().get();
}

bimWorld::ISlice* bimWorld::ModelViewer::SliceSettings()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->SliceSettings().get();
}

bimWorld::ICoordinate* bimWorld::ModelViewer::Coordinates()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_modelCore->Coordinates().get();
}

bimWorld::IPlottingScale* bimWorld::ModelViewer::PlottingScales()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	//return m_modelCore->PlottingScales().get();
	return m_plottingScale.get();
}

bimWorld::ITestModule* bimWorld::ModelViewer::TestModules()
{
	if (!m_initialized)
	{
		std::cerr << "bimWorld::ModelViewer not initialized." << std::endl;
		return NULL;
	}
	return m_testModule.get();
	//return m_modelCore->TestModules().get();
}



