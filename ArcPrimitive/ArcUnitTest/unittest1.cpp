#include "CppUnitTest.h"
#include <osg/Program>
#include <osg/LineWidth>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Drawable>
#include "ArcPrimitive.h"

#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

using namespace geo;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArcUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(ArcTestMethod)
		{
			// TODO:  在此输入测试代码
			//Vertex _center = { -25.5176325819944, 39.388833860873, 13.1088172370929 };
			//Vertex _normal = { 0.0, 0.374606593415913, 0.927183854566787 };
			//Vertex _start = { -29.7922411387276, 35.6185110076384, 14.6321265496653 };
			//Vertex _end = { -25.561884432643, 44.8589141768177, 10.8987613320266 };
			//osg::Vec3 noma = { 5.0, 4.0, 3.0 };
			//noma.normalize();
			//osg::Vec3 mm = noma;
			osgViewer::Viewer viewer;
			viewer.getCamera()->setClearColor(osg::Vec4f(1.0f, 1.0f, 1.0f, 1.0f));
			osg::ref_ptr<osg::Geode> root = new osg::Geode;
			//ArcPrimitive* arc = new ArcPrimitive(_center,_start,_end,_normal);
			ArcPrimitive* arc = new ArcPrimitive;
			arc->setCenter(osg::Vec3{0.0,0.0,0.0});
			arc->setNormal(osg::Vec3{ 0.0, -1.0, 0.0 });
			arc->setStart(osg::Vec3{ 1.0, 0.0, 0.0 });
			arc->setEnd(osg::Vec3{ -1.0, 0.0, 0.0 });
			//arc->set_center(0.0,0.0,0.0);
			root->addDrawable(arc);
			viewer.setSceneData(root.get());
			viewer.run();
		}

	};
}