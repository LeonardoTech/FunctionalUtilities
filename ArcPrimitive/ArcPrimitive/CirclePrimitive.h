#ifndef __CIRCLE_H__
#define  __CIRCLE_H__

#include "VertexArray.h"
#include <osg/Drawable>
namespace geo
{

	class CirclePrimitive:public osg::Drawable
	{
	public:
		CirclePrimitive();
		CirclePrimitive(Vertex& center, Vertex normal, float radius);
		virtual void drawImplementation(osg::RenderInfo& )const override;
		void setCenter(float dx, float dy, float dz);
		void setCenter(Vertex center);
		const Vertex& getCenter() const;
		void setNormal(float dx, float dy, float dz);
		void setNormal(Vertex normal);
		const Vertex& getNormal() const;
		void getVertex();
		void setRadius(float radius);

//internal:
		void setCenter(osg::Vec3 center);
		void setNormal(osg::Vec3 normal);
		osg::Vec3& getCenter();
		osg::Vec3& getNormal();
	private:
		osg::Vec3 m_center;
		osg::Vec3 m_normal;
		osg::Vec3 m_vertex;
		osg::Vec3 m_face;
		osg::ref_ptr<osg::Vec3Array> m_centerArray;
		osg::ref_ptr<osg::Vec3Array> m_normalArray;
		Vertex  v_center;
		Vertex v_normal;
		float m_radius;
	};

}

#endif // __CIRCLE_H__