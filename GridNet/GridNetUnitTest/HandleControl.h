#ifndef __HANDLECALLBACK_H__
#define __HANDLECALLBACK_H__
#include <osgGA/GUIEventHandler>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>
#include "GridNet.h"
#include <osg/Geode>

class HandleControl : public osgGA::GUIEventHandler
{
public:
	HandleControl(GridNet* grid);
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override;

	osg::Geode* getRoot();
private:
	GridNet* _grid;
	float num;
	osg::ref_ptr<osg::Geode>_geode;
};


#endif // __HANDLECALLBACK_H__
