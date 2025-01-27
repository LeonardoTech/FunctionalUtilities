#ifndef __PLOTTINGSCALE_H__
#define __PLOTTINGSCALE_H__ 

#include "IPlottingScale.h"
#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgText/Text>
#include "GetDistanceCallBack.h"
#include <memory>

class PlottingScale :public IPlottingScale
{
public:
	PlottingScale(osgGA::MultiTouchTrackballManipulator *mult,osg::Node* geode);
	PlottingScale();
	void triggerScaleChanged(float scale = 0.0f);
	void bindScaleChanged(long sque, std::function<void(IPlottingScale*)> changed);
	virtual double getScale() override;

protected:
	osg::ref_ptr<osgGA::MultiTouchTrackballManipulator> _mutiTouch;
	osg::ref_ptr<osg::Node> _geode;
	double _scale; 
	GetDistanceCallBack *_distance;
	std::map<long,std::function<void(IPlottingScale*)>> m_click;
};



#endif // __PLOTTINGSCALE_H__