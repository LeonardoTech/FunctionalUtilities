#pragma once
#include "osgGA/GUIEventHandler"
#include "osg/Group"
#include "Selector.h"

class PickHandler : public osgGA::GUIEventHandler
{
public:
	PickHandler(Selector* selector);

	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);


	void setRoot(osg::Group* node);

protected:
	Selector* _select;
	osg::Group* _root;
};

