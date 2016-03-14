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
/// @brief	 һ���̳���osg::NodeCallback����,�ܹ�ʹ����HUD����µ�����ϵ�ܹ�����������ת�������ܹ�����ˢ��
/// 		 
/// @author	Admin
/// @date	2016/3/14
class CoordinateUpdater:public osg::NodeCallback
{
public:
	/// @brief	 ����˽�г�Ա���г�ʼ�������ô�������manip����ʾ��ǰ�Ļ���
	CoordinateUpdater(osgGA::MultiTouchTrackballManipulator* manip);
	/// �Դ�������manip���в���.
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	/// 	 ���ݴ�����Axis��ö��ֵ����ȷ����ȡ�ĸ���Ľ��.
	osg::Vec3 getResult(Axis ax);

private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	osg::Quat rot;
};

#endif