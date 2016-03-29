#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/LOD>

#include "CppUnitTest.h"
#include "../Thumbtack/Thumbtack.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace thumbtack_thumbtack_thumbtack;

namespace ThumbtackUnitTest
{		
	void mm(IThumbtack* yy)
	{
		std::cout << "123213123123"<<std::endl;
	}
	int nthumbtack = 0;
	TEST_CLASS(UnitTest1)
	{
	public:
	
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
 			Thumbtack* thumbtack = new Thumbtack();
			osg::ref_ptr<osg::Group> root = new osg::Group;

			string level0Path = "..\\img\\3.jpg";
			string level1Path = "\\img\\1.jpg";
			string level2Path = "D:\\yz\\FunctionalUtilities\\Thumbtack\\img\\2.jpg";
			string changgePath = "D:\\yz\\FunctionalUtilities\\Thumbtack\\img\\4.jpg";
			thumbtack->setLevelWidthAndHeight(10, 10, 20, 20, 30, 30);
			thumbtack->setLevelImage(level0Path, level1Path, level2Path);
			
			//测试绑定的点击事件
			thumbtack->bindClick(1, mm);
			thumbtack->triggerClick();

			// <手动变更图层的图钉>
 	/*		if (nthumbtack != thumbtack->getScale())
 			{
 				thumbtack->setSize(80,80);
 				thumbtack->changImage(changgePath, Layer::Level1);
 			}

 			osg::ref_ptr<osg::Geometry> geometry = thumbtack->getGeometry();
 			root->addChild(geometry);*/
 			

			// <调用设置不同比例尺和重置大小的接口>
			thumbtack->setLevelScale(1, 0.5, 0.2);
			thumbtack->showDiffrentLevelThumbtack();
			osg::ref_ptr<osg::Geometry> newGeometry = thumbtack->getGeometry();
			root->addChild(newGeometry);
		

	

			osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
			viewer->setSceneData(root);
			viewer->run();

		}

	};
}