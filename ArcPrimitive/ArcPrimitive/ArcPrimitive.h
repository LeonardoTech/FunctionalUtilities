#ifndef __GEO_ARC_H__
#define __GEO_ARC_H__
/*
园弧线，按照右手定则，通过圆心，起点，终点，法向量来确定
*/
#include <osg/Geometry>
#include "IArcPrimitive.h"
#include <osg/Drawable>

#define VESRION_ARC 1

namespace geo
{
	class ArcPrimitive:public osg::Drawable , public IArcPrimitive
	{
	public:
		ArcPrimitive(void);
		ArcPrimitive(const Vertex& center, const Vertex& start, const Vertex& end, const Vertex& normal);

		virtual void drawImplementation(osg::RenderInfo&) const override;
		virtual void setCenter(float dx, float dy, float dz) override ;
		virtual void setCenter(const Vertex& center) override;
		virtual void setNormal(float dx, float dy, float dz) override;
		virtual void setNormal(const Vertex& normal) override;
		virtual void setStart(float dx, float dy, float dz) override;
		virtual void setStart(const Vertex& start) override;
		virtual void setEnd(float dx, float dy, float dz) override;
		virtual void setEnd(const Vertex& end) override;
		virtual const Vertex& getCenter(void)  override;
		virtual const Vertex& getNormal(void)  override;

		virtual Vertex& getStart() override;
		virtual Vertex& getEnd() override;
	//internal:
		void setCenter(osg::Vec3 center);
		void setNormal(osg::Vec3 normal);
		void setStart(osg::Vec3 start);
		void setEnd(osg::Vec3 end);
		const osg::Vec3& getCenter() const;
		const osg::Vec3& getNormal() const;



	protected:
		osg::Vec3 m_center;//圆心
		osg::Vec3 m_normal;//法向量
		osg::Vec3 m_start;
		osg::Vec3 m_end;
	 	Vertex v_center;
		Vertex v_normal;
		Vertex v_start;
		Vertex v_end;
		const double PI = 3.1415926;
	};
}
#endif // __GEO_ARC_H__