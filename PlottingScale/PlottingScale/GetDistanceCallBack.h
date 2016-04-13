#ifndef __DISTANCE_H__
#define __DISTANCE_H__

#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgText/Text>
#include <functional>

class GetDistanceCallBack :public osg::NodeCallback
{
public:
	GetDistanceCallBack(osgGA::MultiTouchTrackballManipulator* manip);
	// <对传进来的manip进行操作.>
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	double getDistance();

// internal:
	void setChangedCallback(std::function<void(float)> changed);
protected:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	double _distance;
	double _lastDistance;
	std::function<void(float)> _changed;
};



#endif // __DISTANCE_H__