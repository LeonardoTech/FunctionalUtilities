#ifndef __YZCurve_H__
#define __YZCurve_H__
/*
	所有线的基类
*/
#include "YZGeometryItem.h"

#define VESRION_CURVE 1

namespace YZ
{
	class GEOMETRY_API Curve : public GeometryItem
	{
	public:
		Curve(void);
		virtual ~Curve(void);

		//获取曲线起始点（闭合的随意取一点，组合曲线取第一条曲线第一点）
		//virtual Position3 get_first_pt(void) const;
		//virtual Position3 get_last_pt(void) const;
		//virtual void set_first_pt(const Position3& pt);
		//virtual void set_last_pt(const Position3& pt);

		//获取get_first_point的方向（弧线为切线）
		//virtual Direction3 get_first_direction(void) const;
	};
}
#endif // __YZCurve_H__