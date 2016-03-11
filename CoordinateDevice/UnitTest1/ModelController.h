
#ifndef MY_HHH
#define MY_HHH

#include "stdafx.h"
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include "stdlib.h"
#include "../CoordinateDevice/CoordinateAxis.h"
#include "../CoordinateDevice/CoordinateUpdater.h"
#include <mutex>

class ModelController : public osgGA::GUIEventHandler
{
public:
	ModelController(osg::MatrixTransform* node, CoordinateAxis *axis,osgText::Text* text) : _model(node){
		_text = text;
		_axis = axis;
	}    
	virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);

protected:
	osg::ref_ptr<osg::MatrixTransform> _model;
	CoordinateAxis *_axis;
	osgText::Text *_text;
	std::mutex mutex;
};


osg::Camera* createHUDCamera(double left, double right, double bottom, double top);

#endif