#include "CppUnitTest.h"
#include "PickHandler.h"
#include "SelectModelPoint.h"
#include "SelectModelLine.h"
#include "SelectModelFace.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestPoint)
		{
			auto group = osgDB::readNodeFile("cessna.osg");
			group->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
			osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
			trans->addChild(group);
			trans->setMatrix(osg::Matrix::translate(0.0f, 0.0f, 1.0f));

			osgViewer::Viewer viewer;
			osg::ref_ptr<PickHandler> picker = new PickHandler(new SelectModelPoint(viewer.getCamera()));

			osg::ref_ptr<osg::Group> root = new osg::Group;
			root->addChild(trans.get());
			picker->setRoot(root);
			//root->addChild(picker->getSelector()->createPointSelector());  // Caution: It has bound, too
			viewer.setSceneData(root.get());
			viewer.addEventHandler(picker.get());

			osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
			viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
			viewer.run();
		}

		//TEST_METHOD(TestLine)
		//{
		//	auto group = osgDB::readNodeFile("cessna.osg");
		//	group->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
		//	osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
		//	trans->addChild(group);
		//	trans->setMatrix(osg::Matrix::translate(0.0f, 0.0f, 1.0f));

		//	osgViewer::Viewer viewer;
		//	osg::ref_ptr<PickHandler> picker = new PickHandler(new SelectModelLine(viewer.getCamera()));

		//	osg::ref_ptr<osg::Group> root = new osg::Group;
		//	root->addChild(trans.get());
		//	picker->setRoot(root);
		//	//root->addChild(picker->getSelector()->createPointSelector());  // Caution: It has bound, too
		//	viewer.setSceneData(root.get());
		//	viewer.addEventHandler(picker.get());

		//	osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
		//	viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
		//	viewer.run();
		//}

		//TEST_METHOD(TestFace)
		//{
		//	auto group = osgDB::readNodeFile("cessna.osg");
		//	group->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
		//	osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
		//	trans->addChild(group);
		//	trans->setMatrix(osg::Matrix::translate(0.0f, 0.0f, 1.0f));

		//	osgViewer::Viewer viewer;
		//	osg::ref_ptr<PickHandler> picker = new PickHandler(new SelectModelFace(viewer.getCamera()));

		//	osg::ref_ptr<osg::Group> root = new osg::Group;
		//	root->addChild(trans.get());
		//	picker->setRoot(root);
		//	//root->addChild(picker->getSelector()->createPointSelector());  // Caution: It has bound, too
		//	viewer.setSceneData(root.get());
		//	viewer.addEventHandler(picker.get());

		//	osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
		//	viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
		//	viewer.run();
		//}
	};
}