#ifndef __SELECT_LINE_H__
#define __SELECT_LINE_H__

#include "ISelectPrimitives.h"
#include "LinePrimitive.h"


#include <osg/Camera>
#include <osgUtil/LineSegmentIntersector>

// <选择线元的类，继承于ISelectPrimitives接口类>
class SelectLine :public ISelectPrimitives
{
public:

	// <构造函数，初始化私有成员，并把相机传进来>
	SelectLine(osg::Camera* camera);

	// <接口类的外部函数，屏幕上的某一点的坐标作为参数，确定面的位置>
	virtual IDrawElement* select(float x, float y) override;

	//  <接口类的外部函数，获取选择面的顶点位置，获取面元的指针>
	virtual IDrawElement* getSelection() const override;

	// <屏幕上的某一点的坐标作为参数，绘制面>
	virtual LinePrimitive* selectLine(float x, float y);

	//  <获取选择面的顶点位置，获取面元指针>
	virtual LinePrimitive* getSelectedLine() const;


	osg::Node* getRoot() const;


protected:

	// <通过相交算法运算后返回的结果，来确定点的位置，并通过矩阵把二维的坐标转换为三维的，为要画的图形确定顶点坐标>
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);

	LinePrimitive* m_line;
	osg::Camera* m_camera;
};

#endif // __SELECT_LINE_H__
