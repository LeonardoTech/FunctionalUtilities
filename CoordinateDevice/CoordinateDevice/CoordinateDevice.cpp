//// CoordinateDevice.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//#include "CoordinateAxis.h"
//#include "CoordinateUpdater.h"
//#include <osg/MatrixTransform>
//#include <osgGA/GUIEventHandler>
//#include <osgViewer/Viewer>
//
//class ModelController : public osgGA::GUIEventHandler
//{
//public:
//	ModelController(osg::MatrixTransform* node, CoordinateAxis *axis) : _model(node){
//		_axis = axis;
//	}
//	virtual bool handle(const osgGA::GUIEventAdapter& ea,
//		osgGA::GUIActionAdapter& aa);
//
//protected:
//	osg::ref_ptr<osg::MatrixTransform> _model;
//	CoordinateAxis *_axis;
//};
//
//
//bool ModelController::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
//{
//	float x = 0.0;
//	float y = 0.0;
//	float z = 0.0;
//	if (!_model) return false;
//	osg::Matrix matrix = _model->getMatrix();
//
//	switch (ea.getEventType())
//	{
//	case osgGA::GUIEventAdapter::KEYDOWN:
//		switch (ea.getKey())
//		{
//		case 'x': case 'X':
//			_axis->getAxisDirection(X_Axis, x, y, z);
//			cout <<"the Axis of X : " <<  x << " " <<  y << " " << z << endl;
//			break;
//		case 'y': case 'Y':
//			_axis->getAxisDirection(Y_Axis, x, y, z);
//			cout << "the Axis of Y : " << x << " " << y << " " << z << endl;
//			break;
//		case 'z': case 'Z':
//			_axis->getAxisDirection(Z_Axis, x, y, z);
//			cout << "the Axis of Z : " << x << " " << y << " " << z << endl;
//			break;
//		default:
//			break;
//		}
//		_model->setMatrix(matrix);
//		break;
//	default:
//		break;
//	}
//	return false;
//}
//
//
//
//osg::Camera* createHUDCamera(double left, double right, double bottom, double top)
//{
//	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
//	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
//	camera->setRenderOrder(osg::Camera::POST_RENDER);
//	camera->setAllowEventFocus(true);
//	camera->setProjectionMatrix(
//		osg::Matrix::ortho2D(left, right, bottom, top));
//	return camera.release();
//}
//
////
////osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
////
////osg::Geometry* createSimpleGeometry()
////{
////	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
////	(*vertices)[0].set(0.0f, 0.0f, 0.0f);
////	(*vertices)[1].set(45.0f, 0.0f, 0.0f);
////	(*vertices)[2].set(0.0f, 0.0f, 0.0f);
////	(*vertices)[3].set(0.0f, 45.0f, 0.0f);
////	(*vertices)[4].set(0.0f, 0.0f, 0.0f);
////	(*vertices)[5].set(0.0f, 0.0f, 45.0f);
////
////	osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_LINES, 6);
////	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
////	(*indices)[4] = 4; (*indices)[5] = 5;
////
////	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
////	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
////	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
////	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
////	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
////	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
////	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
////	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
////	geom->setDataVariance(osg::Object::DYNAMIC);
////	geom->setUseDisplayList(false);
////	geom->setUseVertexBufferObjects(true);
////	geom->setColorArray(colors.get());
////	geom->setVertexArray(vertices.get());
////	geom->setColorArray(colors.get());
////	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
////	geom->addPrimitiveSet(indices.get());
////
////	osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
////	LineSize->setWidth(3.0f);
////	geom->getOrCreateStateSet()->setAttributeAndModes(LineSize.get(), osg::StateAttribute::ON);
////	auto stateSet = geom->getOrCreateStateSet();
////	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
////
////	osgUtil::SmoothingVisitor::smooth(*geom);
////	return geom.release();
////}
////osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color){
////	osg::ref_ptr<osgText::Text> Label = new osgText::Text();
////	Label->setCharacterSize(15.0f);
////	Label->setFont(g_font.get());
////	Label->setText(name);
////	Label->setAxisAlignment(osgText::Text::SCREEN);
////	Label->setDrawMode(osgText::Text::TEXT);
////
////	Label->setAlignment(osgText::Text::CENTER_CENTER);
////	Label->setPosition(position);
////	Label->setColor(color);
////	return Label.release();
////}
////
////int _tmain(int argc, _TCHAR* argv[])
////{
////	auto  _xText = createText("x", osg::Vec3(55.0f, 0.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
////	auto  _yText = createText("y", osg::Vec3(0.0f, 55.0f, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
////	auto  _zText = createText("z", osg::Vec3(0.0f, 0.0f, 55.0f), osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
////	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
////	geode->addDrawable(createSimpleGeometry());
////	//osg::ref_ptr<osg::Node>node = osgDB::readNodeFile("cow.osg");
////	
////	
////	osg::ref_ptr<osg::Group> root = new osg::Group;
////	/*root->addChild(geode.get());
////	root->addChild(_xText);
////	root->addChild(_yText);
////	root->addChild(_zText);*/
////	
////	osgViewer::Viewer view;
////
////	auto manip = new osgGA::MultiTouchTrackballManipulator();
////	view.setCameraManipulator(manip);
////
////	osg::ref_ptr<osg::MatrixTransform> textGeode = new osg::MatrixTransform;
////	osg::Camera* camera = createHUDCamera(0, 1920, 0, 1080);
////	textGeode->setUpdateCallback(new CoordinateUpdater(manip));
////	auto transNode = new osg::MatrixTransform();
////	transNode->setMatrix(osg::Matrix::translate(osg::Vec3(80, 100, -100)));
////	camera->addChild(transNode);
////	transNode->addChild(textGeode.get());
////	textGeode->addChild(geode.get());
////	textGeode->addChild(_xText);
////	textGeode->addChild(_yText);
////	textGeode->addChild(_zText);
////
////	camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
////	
////	root->addChild(camera);
////	//root->addChild(textGeode.get());
////	view.setSceneData(root.get());
////
////	return view.run();
////}
////
////
//
//
//
//int main(int argc, char **argv)
//{
//	/*float x = 0.0;
//	float y = 0.0;
//	float z = 0.0;*/
//	osg::ref_ptr<osg::Group> root = new osg::Group;
//	osgViewer::Viewer view;
//
//	auto manip = new osgGA::MultiTouchTrackballManipulator();
//	view.setCameraManipulator(manip);
//	osg::ref_ptr<osg::Camera> camera = createHUDCamera(0, 1920, 0, 1080);
//	CoordinateAxis *axis = new CoordinateAxis(manip);
//	osg::ref_ptr<osg::MatrixTransform>tran = axis->setAxis( 110.0f, 150.0f, 99.0f, camera);
//	
//	/*axis->getAxisDirection(Y_Axis, x, y, z);
//	cout << x << " " << y << " " << z << endl;*/
//	camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
//	osg::ref_ptr<ModelController> ctrler = new ModelController(tran.get(), axis);
//	view.addEventHandler(ctrler.get());
//	root->addChild(camera);
//	view.setSceneData(root.get());
//	return view.run();
//}
//
//
//
