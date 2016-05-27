// PlottingScaleConsole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PlottingScale.h"
#include "IPlottingScale.h"

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/ShapeDrawable>
#include <iostream>

void funName(IPlottingScale* plot)
{
	double scale = 0;
	double unScale = 0;
	scale = plot->getScale();
	unScale = 1000/scale;
	std::cout <<  unScale << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	osg::ref_ptr<osg::ShapeDrawable>shape = new osg::ShapeDrawable;
	shape->setShape(new osg::Box(osg::Vec3{ 0.0, 0.0, 0.0 }, 1000));
	//shape->setShape(new osg::Sphere(osg::Vec3(0.0,0.0,0.0),500));

	osg::ref_ptr<osg::Geode>geode = new osg::Geode ;
	geode->addDrawable(shape);
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	{
		osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
		traits->x = 700;
		traits->y = 40;
		traits->width = 1200;
		traits->height = 960;
		traits->windowDecoration = true;
		traits->doubleBuffer = true;
		traits->sharedContext = 0;
		osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
		osg::ref_ptr<osg::Camera> camera = new osg::Camera;
		camera->setGraphicsContext(gc.get());
		camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
		GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
		camera->setDrawBuffer(buffer);
		camera->setReadBuffer(buffer);
		viewer->addSlave(camera.get());
	}
	auto manip = new osgGA::MultiTouchTrackballManipulator();
	PlottingScale *scale = new PlottingScale(manip, geode);// <这个是在堆栈里面，手动释放>
	viewer->setCameraManipulator(manip);

	scale->bindScaleChanged(1, funName);
	scale->triggerScaleChanged(0);
	osg::ref_ptr<osg::Group>root = new osg::Group;
	root->addChild(geode);

	viewer->setSceneData(root.get());
	return viewer->run();
}