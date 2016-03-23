#ifndef __LINEPRIMITIVES_H__
#define __LINEPRIMITIVES_H__

#include <osg/Geometry>

#include "VertexArray.h"
#include "ILinePrimitives.h"


//  <绘制线元的实现类，继承于ILinePrimitives> 
class  LinePrimitives :public ILinePrimitives
{
public:

	// <构造函数，用于初始化私有成员>
	LinePrimitives();
	// <设置线宽>
	virtual void setLineWidth(float width) override;

	 // <设置线的颜色，三个浮点值参数分别表示红、绿、蓝，透明度默认为1.0f>
	virtual void setColor(float red, float green, float blue) override;
	
	// <获取点的起始位置>
	virtual void getStartPosition(float& x, float& y, float& z) override;
	
	// <获取点的结束位置>
	virtual void getEndPosition(float& x, float& y, float& z) override;

	// <设置点的起始位置>
	virtual void setStartPosition(float x, float y, float z)override;

	// <设置点的结束位置>
	virtual void setEndPosition(float x, float y, float z) override;

	// <设置点的顶点位置，VertexArray能包含多个顶点的坐标参数>
	virtual void setVertices(const VertexArray& arr) override;

	// <获取顶点的位置坐标, 并用VertexArray类型返回>
	virtual VertexArray getVertices() const override;

// internal:
	osg::Geometry*	getGeometry();

	virtual osg::Vec3 getStartPosition() const;

	virtual osg::Vec3 getEndPosition() const;

	virtual void setStartPosition(osg::Vec3 pos);

	virtual void setEndPosition(osg::Vec3 pos);

protected:
	osg::Vec3 _startPosition;
	osg::Vec3 _endPosition;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Vec4Array> _color;
	osg::ref_ptr<osg::Vec3Array>_vertices;
};


#endif // __LINEPRIMITIVES_H__