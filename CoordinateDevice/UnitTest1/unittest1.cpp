#include "CppUnitTest.h"
#include "ModelController.h"
#include "../ICoordinate/CoordinateAxis.h"
#include "LinePrimitive.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			osg::ref_ptr<osg::Group> root = new osg::Group;
			osgViewer::Viewer view;

			auto manip = new osgGA::MultiTouchTrackballManipulator();
			view.setCameraManipulator(manip);
			osg::ref_ptr<osg::Geode> textGeode = new osg::Geode;
			osg::ref_ptr<osg::Camera> camera = createHUDCamera(0, 1920, 0, 1080);

			CoordinateAxisImplement *axis = new CoordinateAxisImplement(manip);

			axis->setRadius(380);
			axis->setOriginPoint(400, 400);

			//axis->setEnableUpdate(false);
			osg::ref_ptr<osg::MatrixTransform>tran = axis->getNode();
			camera->addChild(tran);


			osg::ref_ptr<osgText::Text>text = new osgText::Text;
			osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
			text->setFont(g_font.get());
			text->setCharacterSize(20.0f);
			text->setAxisAlignment(osgText::TextBase::XY_PLANE);
			text->setDataVariance(osg::Object::DYNAMIC);
			text->setPosition(osg::Vec3(750.0f, 700.0f, 0.0f));
			textGeode->addDrawable(text);
			camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
			osg::ref_ptr<ModelController> ctrler = new ModelController(tran.get(), axis, text);
			camera->addChild(textGeode);
			view.addEventHandler(ctrler.get());
			root->addChild(camera);
			view.setSceneData(root.get());
			view.run();
		}

	};
}