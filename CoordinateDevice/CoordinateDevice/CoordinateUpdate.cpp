
#include "CoordinateUpdater.h"

/// @fn	CoordinateUpdater::CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip);
///
/// @brief	 ����˽�г�Ա���г�ʼ�������ô�������manip����ʾ��ǰ�Ļ���
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in]	manip	If non-null, the manip.
CoordinateUpdater::CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
}
/// @fn	void CoordinateUpdater::operator()(osg::Node* node, osg::NodeVisitor* nv)
///
/// @brief 	�Դ�������manip���в���.�ô���HUD���������ϵ�ܹ����в���
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in]	���ຯ�����岻��Ҫ��
/// @param [in]	���ຯ�����岻��Ҫ��.

void CoordinateUpdater::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	
	auto trans = dynamic_cast<osg::MatrixTransform*>(node);
	rot = m_manip->getRotation();
	/*osg::Vec3 xAxis(1, 0, 0);
	result = rot*xAxis;*/
	trans->setMatrix(osg::Matrix::rotate(rot));
	traverse(node, nv);
}


/// @fn	osg::Vec3 CoordinateUpdater::getResult(Axis ax)
///
/// @brief	 ���ݴ�����Axis��ö��ֵ����ȷ����ȡ�ĸ���Ľ��.
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ax Axis���͵�ö��ֵ��������X,Y,Z��
///
/// @return	The result.


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

