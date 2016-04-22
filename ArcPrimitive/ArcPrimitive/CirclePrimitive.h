#ifndef __GEO_CIRCLE_PRIMITIVE_H__
#define  __GEO_CIRCLE_PRIMITIVE_H__

#include "VertexArray.h"
#include <osg/Drawable>
#include "ICirclePrimitive.h"
namespace geo
{

	class CirclePrimitive:public osg::Drawable,public  ICirclePrimitive
	{
	public:
		CirclePrimitive();
		CirclePrimitive(Vertex& center, Vertex normal, float radius);
		virtual void drawImplementation(osg::RenderInfo& )const override;
		 virtual void setCenter(float dx, float dy, float dz) override;
		virtual void setCenter(Vertex center) override;
		virtual void setNormal(float dx, float dy, float dz) override;
		virtual void setNormal(Vertex normal) override;
		virtual const Vertex& getCenter() override;
		virtual const Vertex& getNormal() override;
		void getVertex();
		virtual void setRadius(float radius) override;

//internal:
		void setCenter(osg::Vec3 center);
		void setNormal(osg::Vec3 normal);
		const osg::Vec3& getCenter() const;
		const osg::Vec3& getNormal() const;
	protected:
		osg::Vec3 m_center;
		osg::Vec3 m_normal;
		osg::Vec3 m_vertex;
		osg::Vec3 m_face;
		Vertex  v_center;
		Vertex v_normal;
		float m_radius;
	};

}

#endif // __GEO_CIRCLE_PRIMITIVE_H__