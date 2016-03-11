
#include "CoordinateUpdater.h"

CoordinateUpdater::CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
}

void CoordinateUpdater::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	
	auto trans = dynamic_cast<osg::MatrixTransform*>(node);
	rot = m_manip->getRotation();
	/*osg::Vec3 xAxis(1, 0, 0);
	result = rot*xAxis;*/
	trans->setMatrix(osg::Matrix::rotate(rot));
	traverse(node, nv);
}


osg::Vec3 CoordinateUpdater::getResult(Axis ax)
{

	if (ax == X_Axis)
	{
		osg::Vec3 xAxis(1, 0, 0);
		result = rot *xAxis;
	}
	else if (ax == Y_Axis)
	{
		osg::Vec3 yAxis(0, 1, 0);
		result = rot*yAxis;
	}
	else if (ax == Z_Axis)
	{
		osg::Vec3 zAxis(0, 0, 1);
		result = rot*zAxis;
	}
	else
	{
		cout << "print false" << endl;
	}
	return result;
}

