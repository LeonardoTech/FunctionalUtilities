#pragma once
#include "Selector.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include <iostream>
#include "osgGA/GUIEventHandler"
#include "SelectModelPoint.h"
#include <osgText/Font>
#include <osgText/Text>
#include "osg/Group"

class PickHandler : public osgGA::GUIEventHandler
{ 
public:
	PickHandler(Selector* selector,Selector *selector1, osg::Camera *camera);
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	void setRoot(osg::Group* node);
	osg::Geode* createLine();
	osg::Vec3 get3DAxis(float x, float y);
	osgText::Text* createText();
protected:
	Selector* _select2;
	Selector* _select1;
	osg::Group* _root;
	osg::Vec3 _axis1;
	osg::Vec3 _axis2;
	osg::Camera* _camera;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::Geometry* _geometry;
	osgText::Text *_text;
};
