#pragma once
#include "osgGA/GUIEventHandler"
#include "osg/Group"
#include "Selector.h"
#include "ISelectPrimitives.h"

class PickHandler : public osgGA::GUIEventHandler
{
public:
	PickHandler(Selector* selector);
	PickHandler(ISelectPrimitives* selector);

	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);


	void setRoot(osg::Group* node);

protected:
	//Selector* _select;
	ISelectPrimitives* _select;
	osg::Group* _root;
};

