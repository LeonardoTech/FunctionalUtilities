#include "CppUnitTest.h"
#include "TextPrimitive.h"
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
			
			TextPrimitive *text = new TextPrimitive;
			text->setSize(20.0f);
			text->setColor(1.0f, 1.0f, 0.0f);
			text->setPosition(0.0f, 1.0, 0.0f);
			text->setTextContent("22221111");
			osgText::Text *_text =  text->getOsgText();
			osg::Geode* geode = new osg::Geode;
			geode->addChild(_text);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();
		}

		TEST_METHOD(TestTextSize)
		{
			TextPrimitive *text = new TextPrimitive;
			text->setSize(150.0f);
			text->setTextContent("22221111");
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
			TextPrimitive *text = new TextPrimitive;
			text->setColor(1.0f, 1.0f, 0.0f); 
			text->setTextContent("22221111");
			osgText::Text *_text = text->getOsgText();
			osg::Geode* geode = new osg::Geode;
			geode->addChild(_text);
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode);
			viewer.run();
		}
	};
}