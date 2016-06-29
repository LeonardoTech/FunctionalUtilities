#include "ModelViewerIOS.h"
#include "ModelCoreFactoryIOS.h"
#include "ModelEntityFactory.h"
#include "AnimationFactory.h"
#include "SelectionController.h"

#if __APPLE__
bimWorld::ModelViewerIOS::ModelViewerIOS(UIView *view, int ratio /*= 2*/, bool isGLES2 /*= false*/, bool fixedFrameRate /*= false*/)
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
	m_modelCore = ModelCoreFactoryIOS().getModule(view, isGLES2, fixedFrameRate, ratio);
	m_modelEntity = ModelEntityFactory().getModule(m_modelCore.get());
	//m_material = std::make_shared<bimWorld::MaterialSetting>();
	m_initialized = true;
	m_selectionCtrler = std::make_shared<bimWorld::SelectionController>(this);
}

#endif