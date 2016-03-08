// CoordinateDevice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "osgViewer/Viewer"
#include "osgDB/readFile"
#include "osg/Geometry"
#include "osgUtil/SmoothingVisitor"
#include "osg/Geometry"
#include "osg/Geode"
#include "osg/MatrixTransform"
#include "osg/PolygonOffset"
#include <osgText/Font>
#include <osgText/Text>
#include <osgText/Font3D>
#include <osgText/Text3D>
#include <osg/LineWidth>
#include "osg/ShapeDrawable"

osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
osg::Camera* createHUD(osg::Camera* mainCamera);


osg::Geometry* createSimpleGeometry()
{
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
	(*vertices)[0].set(10.0f, 10.0f, 0.0f);
	(*vertices)[1].set(30.0f, 10.0f, 0.0f);
	(*vertices)[2].set(10.0f, 10.0f, 0.0f);
	(*vertices)[3].set(10.0f, 30.0f, 0.0f);
	(*vertices)[4].set(10.0f, 10.0f, 0.0f);
	(*vertices)[5].set(10.0f, 10.0f, 10.0f);
	/*
		(*vertices)[6].set(0.5f, 0.5f, 0.5f);
		(*vertices)[7].set(-0.5f, 0.5f, 0.5f);
		*/



	osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_LINES, 6);
	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
	(*indices)[4] = 4; (*indices)[5] = 5;

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setDataVariance(osg::Object::DYNAMIC);
	geom->setUseDisplayList(false);
	geom->setUseVertexBufferObjects(true);
	geom->setColorArray(colors.get());
	geom->setVertexArray(vertices.get());
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	geom->addPrimitiveSet(indices.get());

	osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
	LineSize->setWidth(2.0f);
	geom->getOrCreateStateSet()->setAttributeAndModes(LineSize.get(), osg::StateAttribute::ON);
	auto stateSet = geom->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	osgUtil::SmoothingVisitor::smooth(*geom);
	return geom.release();
}
osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color){
	osg::ref_ptr<osgText::Text> Label = new osgText::Text();
	Label->setCharacterSize(5.0f);
	Label->setFont(g_font.get());
	Label->setText(name);
	Label->setAxisAlignment(osgText::Text::SCREEN);
	Label->setDrawMode(osgText::Text::TEXT);

	Label->setAlignment(osgText::Text::CENTER_CENTER);
	Label->setPosition(position);
	Label->setColor(color);
	return Label.release();
}


osg::Camera* createHUDCamera(double left, double right,double bottom, double top)
{
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->setAllowEventFocus(false);
	camera->setProjectionMatrix(
		osg::Matrix::ortho2D(left, right, bottom, top));
	return camera.release();
}



int _tmain(int argc, _TCHAR* argv[])
{
	auto  _xText = createText("x", osg::Vec3(35.0f, 10.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	auto  _yText = createText("y", osg::Vec3(10.0f, 35.0f, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	auto  _zText = createText("z", osg::Vec3(10.0f, 10.0f, 30.0f), osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(createSimpleGeometry());
	//osg::ref_ptr<osg::Node>node = osgDB::readNodeFile("cow.osg");
	
	
	osg::ref_ptr<osg::Group> root = new osg::Group;
	/*root->addChild(geode.get());
	root->addChild(_xText);
	root->addChild(_yText);
	root->addChild(_zText);*/
	
	osgViewer::Viewer view;


	osg::ref_ptr<osg::Geode> textGeode = new osg::Geode;
	osg::Camera* camera = createHUDCamera(0, 1024, 0, 768);
	camera->addChild(textGeode.get());
	camera->addChild(geode.get());
	camera->addChild(_xText);
	camera->addChild(_yText);
	camera->addChild(_zText);

	camera->getOrCreateStateSet()->setMode(
		GL_LIGHTING, osg::StateAttribute::OFF);

	//
	//osg::Camera *camera = new osg::Camera;
	//camera->setProjectionMatrix(osg::Matrix::ortho2D(0, 1280, 0, 1024));
	//camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	//camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	//camera->setRenderOrder(osg::Camera::POST_RENDER);
	//camera->setAllowEventFocus(false);
	//view.setCamera(camera);

	//auto hud = createHUD(view.getCamera());
	//hud->addChild(geode.get());
	//root->addChild(hud);
	root->addChild(camera);
	view.setSceneData(root.get());

	return view.run();
}





