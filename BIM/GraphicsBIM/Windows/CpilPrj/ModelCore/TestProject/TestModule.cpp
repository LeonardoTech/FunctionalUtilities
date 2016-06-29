////////////
//    created by 孙庆号
////////////

#include "TestModule.h"
#include "YZModelCoreInternal.h"
#include "CameraManipulators.h"
#include "BIMCameraManipulator.h"
#include "IPlottingScale.h"


bimWorld::TestModule::TestModule(YZModelCoreInternal* host) :YZModelCoreModule(host)
{
	//m_string = "test";
	//m_initialized = true;
	m_host = host;
}

void bimWorld::TestModule::test()
{
	//if (!m_initialized || !m_host)
	//{	
	//	return;
	//}
	//auto center = m_host->_CameraManipulator()->getBIMCameraManip()->getCenter();
	//osg::ref_ptr<osg::Camera>camera = m_host->_CameraManipulator()->getCamera();
	//osgGA::MultiTouchTrackballManipulator* cmanip = m_host->_CameraManipulator()->getBIMCameraManip();
	//std::cout << m_string << center.x() << std::endl;
	TestHigh *teh = new TestHigh(m_host);
}
