#ifndef __YZArc_H__
#define __YZArc_H__
/*
	园弧线，按照右手定则，通过圆心，起点，终点，法向量来确定
*/
#include "YZLine.h"

#define VESRION_ARC 1

namespace YZ
{
	class GEOMETRY_API Arc : public Line
	{
	public:
		//默认值圆心(0,0,0)，起始点(1,0,0)，终止点(0,1,0)，法向量(0,0,1)
		Arc(void);
		Arc(const Position3& center, const Position3& start, const Position3& end, const Direction3& normal);
		Arc(const Arc& cArc);
		//默认为逆时针弧
		//如果三个点是共线的，生成失败
		//Arc(const Position3& point1, const Position3& point2, const Position3& point3, int full = false);

		//正bulge为逆时针弧
		//Arc(const Position3& start, const Position3& end, float bulge, const Vector& normal, int full = false);
		virtual ~Arc(void);

		//
		Arc& operator=(const Arc& arc);

		//
		void set_center(float dx, float dy, float dz);
		void set_center(const Position3& center);
		void set_normal(float dx, float dy, float dz);
		void set_normal(const Direction3& normal);

		const Position3& get_center(void) const;
		const Direction3& get_normal(void) const;

		//
		virtual GeometryItem* clone(void) const;

		//
		virtual void reset(void);

		//
		virtual GeometryItemType type() const;

		//
		virtual void transf(const Transform3& transf);

	protected:
		Position3 m_center;//圆心
 		Direction3 m_normal;//法向量
	};
}
#endif // __YZArc_H__