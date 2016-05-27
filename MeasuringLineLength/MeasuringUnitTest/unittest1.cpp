#include "stdafx.h"
#include "CppUnitTest.h"
#include "PickHandle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MeasuringUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
		
			osg::ref_ptr<osg::Geode>geode = new osg::Geode;
			geode->addDrawable(createSimpleGeometry());
			geode->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
			osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
			auto file = osgDB::readNodeFile("cessna.osg");
			trans->addChild(geode);
			trans->setMatrix(osg::Matrix::translate(0.0f, 0.0f, 1.0f));

			osgViewer::Viewer viewer;
			osg::ref_ptr<osg::Camera> camera = viewer.getCamera();
			MeasuringLineLength* dis = new MeasuringLineLength(new SelectModelPoint(camera), new SelectModelPoint(camera));

			osg::ref_ptr<osg::Group> root = new osg::Group;
			root->addChild(trans.get());
			dis->setRoot(root);
			viewer.setSceneData(root.get());
			osg::ref_ptr<PickHandler>picker = new PickHandler(dis);
			viewer.addEventHandler(picker.get());

			osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
			viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
			viewer.run();
		}

	};
}