#include "stdafx.h"
#include "CppUnitTest.h"
#include <osg/Program>
#include <osg/LineWidth>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Drawable>
#include "CirclePrimitive.h"
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

using namespace geo;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleUnitTest
{		
	TEST_CLASS(CircleUnitTest)
	{
	public:
		
		TEST_METHOD(CircleTestMethod)
		{
			// TODO:  在此输入测试代码
			Vertex center{ 5.0, 0.0, 0.0 };
			osg::Vec3 cen{ 1.0, 0.0, 0.0 };
			osgViewer::Viewer viewer;
			viewer.getCamera()->setClearColor(osg::Vec4f(1.0f, 1.0f, 1.0f, 1.0f));
			osg::ref_ptr<osg::Geode> root = new osg::Geode;
			CirclePrimitive *circle = new CirclePrimitive;
			circle->setRadius(1);
			//circle->setCenter(center);
			//circle->setCenter(0.0,0.0,0.0);
			circle->setNormal(osg::Vec3{0.0,-1.0,0.0});
			root->addDrawable(circle);
			viewer.setSceneData(root.get());
			viewer.run();

		}

	};
}