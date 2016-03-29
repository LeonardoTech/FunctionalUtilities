#ifndef __FACE_PRIMITIVE_H__
#define __FACE_PRIMITIVE_H__

#include <osg/Geometry>

#include "VertexArray.h"
#include  "IFacePrimitive.h"


// <绘制面元的实现类，继承于IFacePrimitives>.
class  FacePrimitive :public IFacePrimitive
{
public:
	// <构造函数，用于初始化私有变量>
	FacePrimitive();
	
	// <设置三角面的位置，3个顶点需要9个浮点值表示>
	virtual void setPosition(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	
	// <获取三角面的位置，用引用的形式获取>
	virtual void getPosition(float& x1, float& y1, float& z1, float& x2, float& y2, float& z2, float& x3, float& y3, float& z3);

	// <设置三角面的位置，用osg::Vec3类型作为参数>
	virtual void setPosition(osg::Vec3 vertices1, osg::Vec3 vertices2, osg::Vec3 vertices3);

	// <获取三角面的位置，用引用的的形式，参数是osg::Vec3类型>
	virtual void getPosition(osg::Vec3 &vertices1, osg::Vec3 &vertices2, osg::Vec3 &vertices3);
	
	// <设置面的颜色，三个浮点值参数分别表示红、绿、蓝，透明度默认为1.0f>
	virtual void setColor(float red, float green, float blue) override;

	// <设置顶点坐标，参数是Vertex，包含三个顶点的位置> 
	virtual void setVertices(const VertexArray& arr) override;

	// <获取顶点的坐标，以VertexArray类型返回>
	virtual VertexArray getVertices() const override;

// internal:
	// <获取Geometry指针> 
	osg::Geometry*	getGeometry();

protected:
	osg::Vec3 _position;
	osg::Vec3 _vertices1;
	osg::Vec3 _vertices2;
	osg::Vec3 _vertices3;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Vec4Array> _color;
	osg::ref_ptr<osg::Vec3Array>_vertices;
};


#endif //__FACE_PRIMITIVE_H__