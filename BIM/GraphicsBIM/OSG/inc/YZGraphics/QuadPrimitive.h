#ifndef __QUAD_PRIMITIVE_H__
#define __QUAD_PRIMITIVE_H__

#include <osg/Geometry>

#include "IQuadPrimitive.h"
#include "Nullable.h"
#include <functional>

class QuadPrimitive:public IQuadPrimitive
{
public:
	QuadPrimitive();

	// <构造函数里面设置中心点，边长，向量>
	void updateQuad(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY);
	
	virtual void setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4) override;

	virtual void getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4) override;

	virtual void setColor(float red,float green,float blue) override;

	virtual void setVertices(const VertexArray& arr) override;

	void setHeight(float height);

	void setWidth(float width);

	virtual VertexArray getVertices() const override;

	void setNeedDrawOutLine(bool draw);

	void setCenter(const osg::Vec3f& center);

	void setSize(float width, float height);

// internal:

	virtual osg::Node* getRoot();
	
	virtual osg::Geometry* getGeometry();
	
	virtual osg::Geometry* getOutLine();

	void setGeoEffect(std::function<void(osg::Node*)> func);

	void setLineEffect(std::function<void(osg::Node*)> func);

protected:
	void applyGeoShader(osg::StateSet* stateSet);

	void applyLineShader(osg::StateSet* stateSet);

	void initGeo();

	void initOutLine();

	osg::Vec3 m_center;
	osg::Vec2 m_unitLength;
	osg::Vec3 m_localX;
	osg::Vec3 m_localY;
	float m_height;
	float m_width;
	osg::ref_ptr<osg::Vec3Array> m_vertexArray;
	osg::ref_ptr<osg::Group> _root;
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Geometry> _outLine;
	osg::ref_ptr<osg::Vec4Array> _colors;
	bool m_drawOutLine;

	Nullable<std::function<void(osg::Node*)>> m_geoEffect;
	Nullable<std::function<void(osg::Node*)>> m_lineEffect;
};


#endif // __QUAD_PRIMITIVE_H__
