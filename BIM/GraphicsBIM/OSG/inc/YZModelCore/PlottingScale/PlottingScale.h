#ifndef __PLOTTING_SCALE_H__
#define __PLOTTING_SCALE_H__ 

#include "YZModelCoreModule.h"
#include "IPlottingScale.h"
#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgText/Text>
#include "GetDistanceCallback.h"
#include <Event.h>
#include <memory>
namespace bimWorld
{

	class YIZHU_EXPORT PlottingScale :public YZModelCoreModule, public IPlottingScale
	{
	public:
		PlottingScale(YZModelCoreInternal* host);	//osgGA::MultiTouchTrackballManipulator *mult, osg::Geode* geode

		void triggerScaleChanged(float scale = 0.0f);

		//void bindScaleChanged(long sque, std::function<void(IPlottingScale*)> changed);

		virtual double getScale() override;

		virtual core::Event<void(IPlottingScale*)>& scaleChanged() override;

	protected:
		//osg::ref_ptr<osgGA::MultiTouchTrackballManipulator> _mutiTouch;
		//osg::ref_ptr<osg::Geode> _geode;
		double _scale;
		GetDistanceCallback *_distance;
		//std::map<long,std::function<void(IPlottingScale*)>> m_click;
		core::Event<void(IPlottingScale*)> m_scaleChanged;

	};

}


#endif // __PLOTTING_SCALE_H__