
#include "CppUnitTest.h"
#include "FacePrimitive.h"
#include <osgViewer/Viewer>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FaceUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFaceMethod)
		{
			// TODO:  在此输入测试代码
			
			FacePrimitive *face = new FacePrimitive;
			face->setColor(1.0f, 1.0f, 0.0f);
			face->setPosition(10.0f, 1.0f, 0.0f, 5.0f, 10.0f, 10.0f, 25.0f, 26.0f, 0.0f);
			osg::ref_ptr<osg::Geometry> geom = face->getGeometry();
			
			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geom);

			osgViewer::Viewer viewer;
			viewer.setSceneData(geode.get());
			viewer.run();
		}

	};
}