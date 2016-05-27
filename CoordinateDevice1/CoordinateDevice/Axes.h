#ifndef __AXES_H__
#define __AXES_H__

#include "IAxes.h"
#include "osg/geometry"
#include "LinePrimitives.h"
#include "TextPrimitives.h"
#include "osgUtil/SmoothingVisitor"
#include "osgGA/MultiTouchTrackballManipulator"
#include "AxesUpdate.h"

class Axes:public IAxes
{
public:
	void drawGeomtry(float radius);
	virtual void setCenter(float x, float y) override;
	virtual void getDirection(Coordinate ax,float &x, float &y, float &z) override;
	osg::MatrixTransform* getMatrix();
	void setCamera(osg::Camera* camera);
	void setMaip(osgGA::MultiTouchTrackballManipulator* manip);
private:
	osg::ref_ptr<osg::MatrixTransform> _textGeode;
	osg::Camera* _camera;
	osgGA::MultiTouchTrackballManipulator* m_manip;
	//AxesUpdate*  _update;
};





#endif // __AXES_H__