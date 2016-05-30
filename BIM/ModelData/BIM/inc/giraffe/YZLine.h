#ifndef __YZLine_H__
#define __YZLine_H__
/*
	线段
*/
#include "YZCurve.h"

#define VESRION_LINE 1

namespace YZ
{
	class GEOMETRY_API Line : public Curve
	{
	public:
		//默认值(0,0,0)，(1,1,1)
		Line(void);
		Line(const Position3& start, const Position3& end);
		Line(const Line& cLine);
		virtual ~Line(void);

		//
		Line& operator=(const Line& line);

		//
		void set_start(float dx, float dy, float dz);
		void set_start(const Position3& start);
		void set_end(float dx, float dy, float dz);
		void set_end(const Position3& end);

		const Position3& get_start(void) const;
		const Position3& get_end(void) const;

		//
		virtual GeometryItem* clone(void) const;
		virtual void reset(void);//(0,0,0),(1,1,1)
		virtual GeometryItemType type(void) const;
		virtual void transf(const Transform3& transf);

// 		virtual Position3 get_first_pt(void) const;
// 		virtual Position3 get_last_pt(void) const;
// 		virtual void set_first_pt(const Position3& pt);
// 		virtual void set_last_pt(const Position3& pt);

		//转换为Vector，起点到终点的向量
		Vector3 as_vector(void) const;

		//转换为Direction3，起点到终点的向量
		Direction3 as_direction(void) const;

	protected:
		Position3 m_start;
		Position3 m_end;
	};
}
#endif // __YZLine_H__