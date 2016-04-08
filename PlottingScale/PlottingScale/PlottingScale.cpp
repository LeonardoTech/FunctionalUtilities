#include "PlottingScale.h"
#include "osg/Geode"
#include "TextPrimitive.h"
#include<sstream>



PlottingScale::PlottingScale(osgGA::MultiTouchTrackballManipulator *mult,osg::Geode* geode)
{
	_geode = geode;
	_mutiTouch = mult;
	_scale = 0.0;
	_distance = new GetDistanceCallback(_mutiTouch);
	//_distance->setChangedCallback(triggerScaleChanged);
	// void Distance::setChangedCallback(std::function<void(float)> changed)
	// void fun(float a){}
	_distance->setChangedCallback(std::bind(&PlottingScale::triggerScaleChanged, this, std::placeholders::_1));
	
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
		(it.second)(this);
	}
}

double PlottingScale::getScale()
{
	_scale = _distance->getDistance();
	return _scale;
}
