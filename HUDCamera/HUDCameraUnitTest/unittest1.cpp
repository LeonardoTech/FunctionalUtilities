#include "stdafx.h"
#include "CppUnitTest.h"
#include "HUDCamera.h"
#include "LinePrimitive.h"
#include "PointPrimitive.h"
#include "QuadPrimitive.h"
#include <osg/Geode>
#include <osg/Geometry>
#include <osgViewer/Viewer>
#include "ModelController.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HUDCameraUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			// TODO:  在此输入测试代码
			

			Vertex vertex1 = { 100.0f, 100.0f, 0.0f };
			Vertex vertex2 = { 100.0f, 200.0f, 0.0f };
			Vertex vertex3 = { 200.0f, 200.0f, 0.0f };
			Vertex vertex4 = { 200.0f, 100.0f, 0.0f };


			HUDCamera *hudCamera = new HUDCamera;
			osg::ref_ptr<osg::Camera>camera = hudCamera->getHUDCamera();
			
			LinePrimitive *mline = new LinePrimitive;
			mline->setStartPosition(750.0f, 700.0f, 0.0f);
			mline->setEndPosition(150.0f, 450.0f, 0.0f);
			mline->setColor(0.0, 1.0, 1.0);
			mline->setLineWidth(10.0f);
			osg::ref_ptr<osg::Geometry>geom = mline->getGeometry();


			PointPrimitive *mpoint = new PointPrimitive;
			mpoint->setPosition(800.0f, 700.0f, 0.0f);
			mpoint->setColor(1.0,1.0,0.0);
			mpoint->setSize(10.0);
			osg::ref_ptr<osg::Geometry>geop = mpoint->getGeometry();

			QuadPrimitive *mquad = new QuadPrimitive;
			mquad->setVertices(vertex1, vertex2, vertex3, vertex4);
			mquad->setColor(1.0,0.0,1.0);
			osg::ref_ptr<osg::Geometry>geoq = mquad->getQuadGeometry();
			osg::ref_ptr<PickHandler>pick = new PickHandler(mquad);
			osg::ref_ptr<osg::Geode>geode = new osg::Geode;
			geode->addDrawable(geop);
			geode->addDrawable(geom);
			geode->addDrawable(geoq);
			camera->addChild(geode);
			osgViewer::Viewer viewer;
			viewer.addEventHandler(pick.get());
			viewer.setSceneData(camera.get());
			viewer.run();
			
		}
	};
}