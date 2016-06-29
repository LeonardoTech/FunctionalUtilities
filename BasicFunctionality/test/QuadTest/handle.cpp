#include "handle.h"

PickHandler::PickHandler(QuadPrimitive* quad)
{
	_quad = quad;
	_height = 2.0f;
	_width = 2.0f;
	_center = { 0.0f, 0.0f, 0.0f };
}

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	
	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		//_center.x() += 1.0f;
		//_quad->setCenter(_center);
		_width += 5.0f;
		_quad->setWidth(_width);
	}
	return false;
}