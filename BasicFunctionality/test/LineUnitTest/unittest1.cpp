#include "CppUnitTest.h"
#include "LinePrimitives.h"
#include <osgViewer/Viewer>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LineUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(LineMethod)
		{
			// TODO:  在此输入测试代码
		
			LinePrimitives *line = new LinePrimitives;
			line->setColor(1.0, 0.0, 1.0);
			line->setLineWidth(5.0f);
			line->setStartPosition(0.0f, 0.0f, 0.0f);
			line->setEndPosition(50.0f, 50.0f, 50.0f);
			osg::Geometry *geo =  line->getGeometry();
			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geo);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();

		}

	};
}