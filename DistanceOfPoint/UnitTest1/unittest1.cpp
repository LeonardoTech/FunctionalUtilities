#include "CppUnitTest.h"
#include "../DistanceOfPoint/PickHandler.h"
#include "SelectModelPoint.h"
#include "test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
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
			osg::ref_ptr<PickHandler> picker = new PickHandler(new SelectModelPoint(camera), new SelectModelPoint(camera));

			osg::ref_ptr<osg::Group> root = new osg::Group;
			root->addChild(trans.get());
			picker->setRoot(root);
			viewer.setSceneData(root.get());
			viewer.addEventHandler(picker.get());

			osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
			viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
			viewer.run();
		}

	};
}