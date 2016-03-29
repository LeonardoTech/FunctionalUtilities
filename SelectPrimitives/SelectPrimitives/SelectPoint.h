#ifndef __SELECT_POINT_H__
#define __SELECT_POINT_H__

#include <osg/Camera>
#include <osgUtil/LineSegmentIntersector>

#include "ISelectPrimitives.h"
#include "PointPrimitives.h"

// <选择线元的类，继承于ISelectPrimitives接口类>
class SelectPoint :public ISelectPrimitives
{
public:
	// <构造函数，初始化私有成员，并把相机传进来>
	SelectPoint(osg::Camera* camera);

	// <接口类的外部函数，屏幕上的某一点的坐标作为参数，确定面的位置>
	virtual IDrawElement* select(float x, float y) override;

	//  <接口类的外部函数，获取选择面的顶点位置，获取点元的指针>
	virtual IDrawElement* getSelection() const override;

// internal:
	// <屏幕上的某一点的坐标作为参数，绘制点>
	virtual PointPrimitives* selectPoint(float x, float y);

	//  <获取选择点的顶点位置，获取点元指针>
	virtual PointPrimitives* getSelectedPoint() const;

	osg::Node* getRoot() const;

	void setPointPosition(const osg::Vec3& pos);

protected:

	// <利用相交运算的结果来确定线的顶点位置>
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	PointPrimitives* m_point;
	osg::Camera* m_camera;
};

#endif // __SELECT_POINT_H__
