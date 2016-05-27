#include "ModelController.h"

PickHandler::PickHandler(QuadPrimitive* factor)
{
	_quad = factor;
	_vertices = new osg::Vec3Array;
	//_point = point;
	_xAxis = 0.0f;
	_yAxis = 0.0f;
	_center = { 0.0f, 0.0f, 0.0f };
}

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	_xAxis = ea.getX();
	_yAxis = ea.getY();

	//if (ea.getEventType() != osgGA::GUIEventAdapter::RELEASE || ea.getButton() != osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	if (ea.getEventType() == osgGA::GUIEventAdapter::DRAG)
	{
		//_point->setPosition(ea.getX(),ea.getY(),0.0);
		//_quad->setCenter(osg::Vec3{ ea.getX(), ea.getY(), 0.0 });
		
		osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, ea.getX(), ea.getY());
		osgUtil::IntersectionVisitor iv(intersector.get());
		osg::ref_ptr<osgViewer::View>view = dynamic_cast<osgViewer::View*>(&aa);
		
		_camera = view->getCamera();
		_camera->accept(iv);

		// <根据屏幕上的点求相交运算，返回三个三维坐标>
		if (intersector->containsIntersections())
		{
			osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
			doUserOperations(result);
		}
	}
	return false;
}



void PickHandler::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
{
	osg::Geometry* geom = dynamic_cast<osg::Geometry*>(result.drawable.get());
	
	//auto quad =_factor->create(geom);
	auto quad = dynamic_cast<QuadPrimitive*>(_factor->create(geom));
	if (quad)
	{
		int i = 0;
		quad->setPosition(_xAxis, _yAxis, 0);
	}
	
	auto line = dynamic_cast<LinePrimitive*>(_factor->create(geom));
	if (line)
	{
		line->setPosition(_xAxis,_yAxis,0);
	}
	
	auto point = dynamic_cast<PointPrimitive*>(_factor->create(geom));
	if (point)
	{
		point->setPosition(_xAxis, _yAxis, 0);
	}

	//_vertices->push_back(osg::Vec3{ _xAxis, _yAxis, 0.0f });
	//geom->setVertexArray(_vertices);
}
