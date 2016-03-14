#include "PickHandler.h"
#include <osgViewer/Viewer>

PickHandler::PickHandler(Selector* selector, Selector *selector1, osg::Camera *camera)
{
	_camera = camera;
	_axis1 = { 0, 0, 0 };
	_axis2 = { 0, 0, 0 };
	_select2= selector;
	_select1 = selector1;
	_isSelect1Down = false;
	_isSelect2Down = false;
}


osg::Camera* createHUDCamera(double left, double right, double bottom, double top)
{
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->setAllowEventFocus(true);
	camera->setProjectionMatrix(
		osg::Matrix::ortho2D(left, right, bottom, top));
	return camera.release();
}


osgText::Text * PickHandler::createText()
{
	osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
	_text = new osgText::Text;
	_text->setFont(g_font.get());
	_text->setCharacterSize(51);
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);
	_text->setAxisAlignment(osgText::Text::SCREEN);
	_text->setDataVariance(osg::Object::DYNAMIC);
	
	return _text;
}



osg::Vec3 PickHandler::get3DAxis(float x, float y)
{
	osg::Vec3 _axis;
	if (_camera)
	{
		osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
			new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
		osgUtil::IntersectionVisitor iv(intersector.get());
		_camera->accept(iv);
		osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());

		osg::Vec3 point = result.getWorldIntersectPoint();
		
		osg::Matrix matrix = osg::computeLocalToWorld(result.nodePath);
		osg::Matrix vpMatrix;
		vpMatrix = _camera->getViewMatrix() * _camera->getProjectionMatrix();
		point = point * vpMatrix;

		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);
		_axis = point*inverseMat * matrix;
	}
	return _axis;
}


bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (ea.getEventType() == osgGA::GUIEventAdapter::MOVE)
	{
	 	

		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		if (!_isSelect1Down)
		{
			_select1->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
		if (!_isSelect2Down)
		{
			//_axis2 = get3DAxis(ea.getX(), ea.getY());
			osg::Vec3Array* selPosition = dynamic_cast<osg::Vec3Array*>(_geometry->getVertexArray());
			
			//(*selVertices)[0] = _axis1;
			//(*selVertices)[1] = _axis2;

			(*selPosition)[0] =  _select1->getPosition();
			_select2->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
			(*selPosition)[1] = _select2->getPosition();
			auto middle = (*selPosition)[0] + (*selPosition)[1];
			middle /= 2.0;
			
			float length = ((*selPosition)[1] - (*selPosition)[0]).length();
			stringstream ss;
			ss << length;
			//ss << "in";
			
			_text->setText(ss.str());
			_text->setPosition(middle);
			_text->dirtyBound();
			selPosition->dirty();
			_geometry->dirtyBound();
		}
	}

	

	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{

		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		bool isExeced = false;
		if (!_isSelect1Down&& !isExeced)
		{
			_isSelect1Down = true;
			isExeced = true;
			//_axis1 = get3DAxis(ea.getX(), ea.getY());
			_select1->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
		if(!_isSelect2Down&&!isExeced)
		{
			isExeced = true;
			_isSelect2Down = true;
			_select2->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
	}

	return false;
}


void PickHandler::setRoot(osg::Group* node)
{
	_root = node;
	_root->addChild(_select2->createSelector());
	_root->addChild(_select1->createSelector());
	_root->addChild(createLine());
	_root->addChild(createText());
}

// ´´½¨Ïß
osg::Geode* PickHandler::createLine()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_geometry = new osg::Geometry;
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(2));
	_geometry->setColorArray(colors.get());
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2));

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_geometry);
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}

