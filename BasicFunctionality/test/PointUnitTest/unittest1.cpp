#include "CppUnitTest.h"
#include "PointPrimitives.h"
#include "IPointPrimitives.h"

#include <osgViewer/Viewer>
#include <osg/Billboard>
#include <osg/ShapeDrawable>
#include <osg/Point>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestPointMethod)
		{

			osg::Vec3 _vertex = { 0.0f, 1.0f, 0.0f };
			osg::ref_ptr<osg::Vec3Array>verties = new osg::Vec3Array(1);
			(*verties)[0] = _vertex;

			PointPrimitives *point = new PointPrimitives;
			osg::Geometry  *geo = point->getGeometry();

			point->setPosition(0.0f, 1.0f, 0.0f);
			point->setColor(1.0f, 0.0f, 1.0f);
			point->setSize(20.0f);

			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geo);
			geode->addDrawable(new osg::ShapeDrawable(new osg::Box()));

			osgViewer::Viewer viewer;
			viewer.setSceneData(geode.get());
			viewer.run();

		}

		TEST_METHOD(TestPaintPoint)
		{
			osg::Vec3 _vertex = { 0.0f, 1.0f, 0.0f };
			osg::ref_ptr<osg::Vec3Array>verties = new osg::Vec3Array(1);
			(*verties)[0] = _vertex;

			osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
			(*colors)[0] = osg::Vec4{ 1.0f, 1.0f, 0.0f, 1.0f };


			osg::Geometry  *geo = new osg::Geometry;
			//geo->setDataVariance(osg::Object::DYNAMIC);
			geo->setUseDisplayList(false);
			geo->setUseVertexBufferObjects(true);
			geo->setVertexArray(verties);
			geo->setColorArray(colors.get());
			geo->setColorBinding(osg::Geometry::BIND_OVERALL);
			geo->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
			geo->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
			geo->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geo);
			geode->addDrawable(new osg::ShapeDrawable(new osg::Box()));
			geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
			geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
			//geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
			//geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

			osgViewer::Viewer viewer;
			viewer.setSceneData(geode.get());
			viewer.run();
		}
	};
}