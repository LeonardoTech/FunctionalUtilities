#include "handle.h"

PickHandler::PickHandler(QuadPrimitive* quad)
{
	_quad = quad;
	_height = 2.0f;
}

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	
	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		_height += 5.0f;
		_quad->setHeight(_height);
	}
	return false;
}