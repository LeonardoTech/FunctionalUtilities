#include "PickHandler.h"
#include <osgViewer/Viewer>
#include "LinePrimitives.h"
#include "PointPrimitives.h"
//#include "FacePrimitives.h"

PickHandler::PickHandler(Selector* selector)
{
	//_select = selector;
}

PickHandler::PickHandler(ISelectPrimitives* selector)
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

	//_select->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
	_select->select(ea.getX(), ea.getY());

	return false;
}


void PickHandler::setRoot(osg::Group* node)
{
	_root = node;
	//_root->addChild(_select->createSelector());
	auto line = dynamic_cast<LinePrimitives*>(_select->getSelection());
	if (line)
		_root->addChild(line->getGeometry());
	auto point = dynamic_cast<PointPrimitives*>(_select->getSelection());
	if (point)
		_root->addChild(point->getGeometry());
}