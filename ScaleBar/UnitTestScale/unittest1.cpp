#include "stdafx.h"
#include "CppUnitTest.h"

#include "LinePrimitive.h"
#include "osg/Geode"
#include "osgViewer/Viewer"
#include "ScaleBar.h"
#include "ModelController.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestScale
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			
			

			LinePrimitive *line = new LinePrimitive;
			line->setColor(1.0f, 1.0f, 0.0f); 
			line->setStartPosition(0.0f, 0.0f, 0.0f);
			line->setEndPosition(20.0f, 20.0f, 20.0f);
			osg::Geometry *geom = line->getGeometry();
			line->setLineWidth(5.0f);
			osg::ref_ptr<osg::Geode> geode = new osg::Geode();
			geode->addDrawable(geom);
			osgViewer::Viewer viewer;

			auto manip = new osgGA::MultiTouchTrackballManipulator();
			viewer.setCameraManipulator(manip);
			ScaleBar *scale = new ScaleBar(manip);
			osg::ref_ptr<osg::MatrixTransform>trans = new osg::MatrixTransform();
			trans->addChild(geode);
			geode->setUpdateCallback(scale);
			//ModelController * model = new ModelController(trans);
			viewer.setSceneData(geode);
			viewer.run();
		}

	};
}