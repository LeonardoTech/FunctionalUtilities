#ifndef __SELECT_FACE_H__
#define __SELECT_FACE_H__

#include <osg/Camera>
#include <osgUtil/LineSegmentIntersector>

#include "ISelectPrimitives.h"
#include "FacePrimitives.h"

// <选择面元的类，继承于ISelectPrimitives接口类>
class SelectFace :public ISelectPrimitives
{
public:

	// <构造函数，初始化私有成员，并把相机传进来>
	SelectFace(osg::Camera* camera);

	// <接口类的外部函数，屏幕上的某一点的坐标作为参数，确定线的位置>
	virtual IDrawElement* select(float x, float y) override;

	//  <接口类的外部函数，获取选择面的顶点位置，获取线元的指针>
	virtual IDrawElement* getSelection() const override;

	// <屏幕上的某一点的坐标作为参数，绘制线，返回线元指针>
	virtual FacePrimitives* selectFace(float x, float y);

	//  <获取选择面的顶点位置，获取线元指针>
	virtual FacePrimitives* getSelectedFace() const;

protected:
	
	// <利用相交运算的结果来确定线的顶点位置>
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	osg::ref_ptr<osg::Vec3Array>_vertices;
	FacePrimitives* m_face;
	osg::Camera* m_camera;
};

#endif // __SELECT_FACE_H__
