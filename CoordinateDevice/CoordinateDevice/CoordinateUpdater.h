#ifndef MY_H
#define MY_H

#include <osg/NodeCallback>
#include "stdafx.h"
#include <osg/MatrixTransform>
#include "osgGA/MultiTouchTrackballManipulator"
#include "ICoordinateAxis.h"
#include <osgText/Font>
#include <osgText/Text>

/// @class	CoordinateUpdater
///
/// @brief	 一个继承于osg::NodeCallback的类,能够使处于HUD相机下的坐标系能够用鼠标控制旋转，并且能够计数刷新
/// 		 
/// @author	Admin
/// @date	2016/3/14
class CoordinateUpdater:public osg::NodeCallback
{
public:
	/// @brief	 构造私有成员进行初始化，利用传进来的manip来表示当前的环境
	CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip);
	/// 对传进来的manip进行操作.
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	/// 	 根据传进来Axis的枚举值，来确定获取哪个轴的结果.
	osg::Vec3 getResult(Axis ax);

private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	osg::Quat rot;
};

#endif