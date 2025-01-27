#include "PlottingScale.h"
#include "osg/Geode"
#include<sstream>
#include "GetDistanceCallBack.h"


PlottingScale::PlottingScale(osgGA::MultiTouchTrackballManipulator *mult, osg::Node* geode)
{
	_geode = geode;
	_mutiTouch = mult;
	_scale = 0.0;
	_distance = new GetDistanceCallBack(_mutiTouch);
	//_distance->setChangedCallback(triggerScaleChanged);
	// void Distance::setChangedCallback(std::function<void(float)> changed)
	// void fun(float a){}
	_distance->setChangedCallback(bind(&PlottingScale::triggerScaleChanged, this, std::placeholders::_1));
	_geode->setUpdateCallback(_distance);
}

void PlottingScale::bindScaleChanged(long sque,std::function<void(IPlottingScale*)> changed)
{
	m_click[sque] = changed;	
}

void PlottingScale::triggerScaleChanged(float scale)
{
	for (auto it: m_click)
	{
		// it.second代表着函数指针
		// this代表类的对象
		(it.second)(this);
	}
}

double PlottingScale::getScale()
{
	_scale = _distance->getDistance();
	return 1000.0/_scale;
}