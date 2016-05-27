#include "ScaleBar.h"

ScaleBar::ScaleBar(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
}

void ScaleBar::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	auto trans = dynamic_cast<osg::MatrixTransform*>(node);
	_distance = m_manip->getDistance();
}




