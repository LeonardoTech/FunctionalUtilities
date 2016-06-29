#include<sstream>
#include "osg/Geode"
#include "TextPrimitive.h"
#include "YZModelCoreInternal.h"
#include "PlottingScale.h"

using namespace bimWorld;

bimWorld::PlottingScale::PlottingScale(YZModelCoreInternal* host) ://osgGA::MultiTouchTrackballManipulator *mult,osg::Geode* geode
bimWorld::YZModelCoreModule(host)
{
	//_geode = geode;
	//_mutiTouch = mult;
	_scale = 0.0;
	_distance = new GetDistanceCallback((osgGA::MultiTouchTrackballManipulator*)m_host->_CameraManipulator()->getBIMCameraManip());
	//_distance->setChangedCallback(triggerScaleChanged);
	// void Distance::setChangedCallback(std::function<void(float)> changed)
	// void fun(float a){}
	_distance->setChangedCallback(std::bind(&PlottingScale::triggerScaleChanged, this, std::placeholders::_1));

	m_host->_ViewerData()->getModelRoot()->setUpdateCallback(_distance);

	std::function<void()> func = [this](){
		if (!m_initialized || !m_host)
		{
			return;
		}
		m_host->_ViewerData()->getModelRoot()->setUpdateCallback(_distance);
	};
	core::InstanceFunction<void()> insfunc(func, this, "initPlottingScale");
	m_host->_ViewerData()->ModelRootChangedEvent() += insfunc;

	m_initialized = true;
}

//void PlottingScale::bindScaleChanged(long sque,std::function<void(IPlottingScale*)> changed)
//{
//	m_click[sque] = changed;
//}

void bimWorld::PlottingScale::triggerScaleChanged(float /*scale*/)
{
	if (!m_initialized || !m_host)
	{
		return;
	}
	//for (auto it: m_click)
	//{
	//	(it.second)(this);
	//}
	core_Event_Trigger(m_scaleChanged, this);
}

double bimWorld::PlottingScale::getScale()
{
	if (!m_initialized || !m_host)
	{
		return -1.0;
	}
	_scale = _distance->getDistance(); 
	if (_scale == 0)
	{
		_scale = -1;
	}
	else
	{
		_scale = 1000 / _scale;
	}
	return _scale;
}

core::Event<void(IPlottingScale*)>& bimWorld::PlottingScale::scaleChanged()
{
	if (!m_initialized || !m_host)
	{
		return core::Event<void(IPlottingScale*)>();
	}
	return m_scaleChanged;
}
