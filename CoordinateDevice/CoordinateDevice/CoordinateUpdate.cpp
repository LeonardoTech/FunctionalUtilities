
#include "CoordinateUpdater.h"

/// @fn	CoordinateUpdater::CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip);
///
/// @brief	 构造私有成员进行初始化，利用传进来的manip来表示当前的环境
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
/// @brief 	对传进来的manip进行操作.让处于HUD相机的坐标系能够进行操作
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in]	基类函数定义不需要管
/// @param [in]	基类函数定义不需要管.

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
/// @brief	 根据传进来Axis的枚举值，来确定获取哪个轴的结果.
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ax Axis类型的枚举值，代表着X,Y,Z轴
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

