#include "PickHandler.h"
#include <osgViewer/Viewer>

PickHandler::PickHandler(Selector* selector)
{
	_select = selector;
}


bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (ea.getEventType() != osgGA::GUIEventAdapter::RELEASE ||
		ea.getButton() != osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON ||
		!(ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_CTRL))
		return false;

	osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);

	_select->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());

	return false;
}


void PickHandler::setRoot(osg::Group* node)
{
	_root = node;
	_root->addChild(_select->createSelector());
}