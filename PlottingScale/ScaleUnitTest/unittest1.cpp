#include "stdafx.h"
#include "CppUnitTest.h"
#include "FacePrimitive.h"
#include <osgViewer/Viewer>
#include<iostream>
#include  "IplottingScale.h"
#include "PlottingScale.h"
#include "TextPrimitive.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScaleUnitTest
{		
	//std::function<void(IPlottingScale*)
	void funName(IPlottingScale* iplottingscale)
	{
		double Scale  = 0.0;
		Scale =  iplottingscale->getScale();
		std::cout << Scale << std::endl;
	}
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			FacePrimitive *face = new FacePrimitive;
			face->setColor(1.0f, 1.0f, 0.0f);
			face->setPosition(10.0f, 1.0f, 0.0f, 5.0f, 10.0f, 10.0f, 25.0f, 26.0f, 0.0f);
			osg::ref_ptr<osg::Geometry> geom = face->getGeometry();

			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geom);

			osgViewer::Viewer viewer;

			auto manip = new osgGA::MultiTouchTrackballManipulator();
			viewer.setCameraManipulator(manip);
			osg::ref_ptr<osg::MatrixTransform>trans = new osg::MatrixTransform();
			PlottingScale *scale = new PlottingScale(manip,geode);
			scale->bindScaleChanged(1, funName);
			scale->triggerScaleChanged(0);

			trans->addChild(geode);
			viewer.setSceneData(geode.get());
			viewer.run();

		}

	};
}