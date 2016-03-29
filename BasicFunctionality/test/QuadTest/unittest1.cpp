#include "CppUnitTest.h"
#include "QuadPrimitive.h"
#include <osgViewer/Viewer>

#include "handle.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuadTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(QuadMethod)
		{
			// TODO:  在此输入测试代码
			




			osg::Vec3 center{ 1.0f, 1.0f, 1.0f };
			osg::Vec2 longth{ 10.0, 10.0 };
			osg::Vec3 localX{ 1.0f, 0.0f, 0.0f };
			osg::Vec3 localY{ 0.0f, 1.0f, 0.0f };

			Vertex vertex1 = { 1.0f, 0.0f, 0.0f };
			Vertex vertex2 = { 1.0f, 1.0f, 0.0f };
			Vertex vertex3 = { 0.0f, 1.0f, 0.0f };
			Vertex vertex4 = { 0.0f, 0.0f, 0.0f };

			VertexArray* vertices = new VertexArray(4);
			(*vertices)[0] = vertex1;
			(*vertices)[1] = vertex2;
			(*vertices)[2] = vertex3;
			(*vertices)[3] = vertex4;

			QuadPrimitive *quad = new QuadPrimitive;

			//QuadPrimitive *quad = new QuadPrimitive(vertex1, vertex2, vertex3, vertex4);
			//QuadPrimitive *quad = new QuadPrimitive(center, longth, localX, localY);
			
			quad->createQuad(center, longth, localX, localY);
			quad->setColor(1.0f, 1.0f, 0.0f);

			//调用函数 void QuadPrimitive::createQuad(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4)
			//quad->setVertices(vertex1,vertex2,vertex3,vertex4);
			
			//调用函数 void QuadPrimitive::setVertices(const VertexArray& arr)
			//quad->setVertices(*vertices);

			osg::ref_ptr<osg::Geometry>geoq = quad->getGeometry();
			osg::ref_ptr<osg::Geode> geode = new osg::Geode;
			geode->addDrawable(geoq);
			geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		
			osgViewer::Viewer viewer;
			viewer.setSceneData(geode.get());
			osg::ref_ptr<PickHandler>picker = new PickHandler(quad);
			viewer.addEventHandler(picker.get());
			osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
			viewer.getCamera()->setCullingMode(mode & (~osg::CullSettings::SMALL_FEATURE_CULLING));
			viewer.run();
		}

	};
}