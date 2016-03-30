#include "Distance.h"
#include<sstream>

Distance::Distance(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
	_distance = 0.0f;
	_lastDistance = 0.0f;
}

void Distance::setChangedCallback(std::function<void(float)> changed)
{
	_changed = changed;
}


void Distance::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	auto trans = dynamic_cast<osg::MatrixTransform*>(node);
	_distance = m_manip->getDistance();

	if (_lastDistance != _distance)
	{
		_changed(_distance);
	}
	_lastDistance = _distance;
}




double Distance::getDistance()
{
	return _distance;
}

