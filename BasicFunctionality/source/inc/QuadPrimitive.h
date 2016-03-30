#ifndef __QUAD_PRIMITIVE_H__
#define __QUAD_PRIMITIVE_H__

#include <osg/Geometry>

#include "IQuadPrimitive.h"

class QuadPrimitive:public IQuadPrimitive
{
public:
	QuadPrimitive();
	// <构造函数里面设置中心点，边长，向量>
	void createQuad(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY);

	virtual void setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4) override;

	virtual void getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4) override;

	virtual void setColor(float red,float green,float blue) override;

	virtual void setVertices(const VertexArray& arr) override;

	virtual void setHeight(float const height) override;

	virtual void setWidth(float const width) override;

	virtual void setQuadColor(float const red, float const green, float const blue) override;

	virtual void setFrameColor(float const red, float const green, float const blue) override;

	virtual void setFrameWidth(float const width) override;

	virtual osg::Node* getRoot() override;

	virtual void  setCenter(const osg::Vec3& center) override;

	void setNeedDrawOutLine(bool draw) override;

	virtual VertexArray getVertices() const override;
		
	// internal:
	
	virtual osg::Geometry* getQuadGeometry();

	virtual osg::Geometry* getFrameGeometry();

protected:
	void initOutLine();
	osg::Vec3 m_center;
	osg::Vec2 m_unitLength;
	osg::Vec3 m_localX;
	osg::Vec3 m_localY;
	float m_height;
	float m_width;
	osg::ref_ptr<osg::Geometry>_outLine;
	osg::ref_ptr<osg::Geode> _root;
	osg::ref_ptr<osg::Vec3Array> _normalsArray;
	osg::ref_ptr<osg::Vec2Array> _texcoords;
	osg::ref_ptr<osg::Vec3Array> m_vertexArray;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Vec4Array> _quadColors;
	osg::ref_ptr<osg::Vec4Array> _frameColors;
};


#endif // __QUAD_PRIMITIVE_H__
