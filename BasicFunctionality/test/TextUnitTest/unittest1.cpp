#include "CppUnitTest.h"
#include "TextPrimitives.h"
#include <osgViewer/Viewer>
#include <osg/Billboard>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTextMethod)
		{
			// TODO:  在此输入测试代码
			
			TextPrimitives *text = new TextPrimitives;
			text->setSize(20.0f);
			text->setColor(1.0f, 1.0f, 0.0f);
			text->setPosition(0.0f, 1.0, 0.0f);
			text->setText("22221111");
			osgText::Text *_text =  text->getOsgText();
			osg::Geode* geode = new osg::Geode;
			geode->addChild(_text);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();
		}

		TEST_METHOD(TestTextSize)
		{
			TextPrimitives *text = new TextPrimitives;
			text->setSize(150.0f);
			text->setText("22221111");
			text->setFontFile("fonts/Vera.ttf");

			osgText::Text *_text = text->getOsgText();
			osg::Geode* geode = new osg::Geode;
			geode->addChild(_text);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();
		}
		TEST_METHOD(TestTextColor)
		{
			TextPrimitives *text = new TextPrimitives;
			text->setColor(1.0f, 1.0f, 0.0f); 
			text->setText("22221111");
			osgText::Text *_text = text->getOsgText();
			osg::Geode* geode = new osg::Geode;
			geode->addChild(_text);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();
		}
	};
}