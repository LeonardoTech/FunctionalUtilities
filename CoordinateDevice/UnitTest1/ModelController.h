
#ifndef __MODELCONTROLLER_H__
#define __MODELCONTROLLER_H__

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <mutex>

#include "../ICoordinate/CoordinateAxis.h"



using namespace coordinatedevice_coordinate_coordinate;

class ModelController : public osgGA::GUIEventHandler
{
public:
// 	ModelController(osg::MatrixTransform* node, CoordinateAxis *axis, osgText::Text* text) : _model(node){
// 		_text = text;
// 		_axis = axis;
// 	}
	ModelController(osg::MatrixTransform* node, CoordinateAxis *axis, osgText::Text* text) : _model(node){
		_text = text;
		_axis1 = axis;
	}
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);

protected:
	osg::ref_ptr<osg::MatrixTransform> _model;
	CoordinateAxis *_axis;

	CoordinateAxis* _axis1;
	osgText::Text *_text;
	std::mutex mutex;
};


osg::Camera* createHUDCamera(double left, double right, double bottom, double top);

#endif