#include "stdafx.h"
#include "CppUnitTest.h"
#include "GridNet.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osgViewer/Viewer>
#include "LinePrimitive.h"
#include <osg/MatrixTransform>
#include "HandleControl.h"


using namespace geo;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GridNetUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码

			GridNet *grid = new GridNet;
			//osg::ref_ptr<osg::Geode>geode = grid->createCircle(10);
			//osg::ref_ptr<HandleControl>handle = new HandleControl(grid);
			//osg::ref_ptr<osg::Geode>root = new osg::Geode;
			//root->addChild(geode);
			//root = grid->createText();
			//osg::ref_ptr<osg::Geode >root = handle->getRoot();
			osgViewer::Viewer viewer;
			//viewer.getCamera()->setClearColor(osg::Vec4f(1.0f, 1.0f, 1.0f, 1.0f));
			//viewer.addEventHandler(handle);
			osg::ref_ptr<osg::Group>root = grid->createTemplate();
			viewer.setSceneData(root);
			viewer.run();
		}
	};
}