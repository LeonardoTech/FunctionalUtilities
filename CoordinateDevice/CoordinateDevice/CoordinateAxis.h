#pragma once
#include "osgViewer/Viewer"
#include "osgDB/readFile"
#include "osg/Geometry"
#include "osgUtil/SmoothingVisitor"
#include "osg/Geometry"
#include "osg/Geode"
#include "osg/MatrixTransform"
#include "osg/PolygonOffset"
#include <osgText/Font>
#include <osgText/Text>
#include <osgText/Font3D>
#include <osgText/Text3D>
#include <osg/LineWidth>
#include "osg/ShapeDrawable"
#include "osg/Point"
#include "osgGA/MultiTouchTrackballManipulator"
#include "ICoordinateAxis.h"
#include <osg/NodeCallback>
#include "CoordinateUpdater.h"

/// @class	CoordinateAxis
///
/// @brief	 �̳���IcoordinateAxis�ӿ��࣬���Ժ������ж���
///
/// @author	Admin
/// @date	2016/3/14
class CoordinateAxis :
	public ICoordinateAxis
{
public:
	///���캯������˽�б������г�ʼ��
	CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip);
	~CoordinateAxis();
	///��ȡ�����᷽��
	virtual void getAxisDirection(Axis ax, float &x, float &y, float &z);
	///ͨ��ָ���Ķ�ά��Ļ���껭������ϵ������ָ������ϵ�İ뾶���ȣ���Ҫ����Ļ�����Ϊ��������ȥ
	virtual osg::MatrixTransform* setAxis( float x, float y, float radius, osg::Camera *camera);
private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	CoordinateUpdater* update;
};

