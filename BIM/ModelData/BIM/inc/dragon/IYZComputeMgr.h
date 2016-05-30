#ifndef __YZICOMPUTEMGR_H__
#define __YZICOMPUTEMGR_H__
/*
计算数据管理接口类
*/

#include "Dragon.h"

namespace YZ
{
	struct GCompRadius
	{
		GCompRadius()
			:m_radius(-1), m_id(-1)
		{}

		GCompRadius(float radius, int id)
			:m_radius(radius), m_id(id)
		{}

		float m_radius;
		int m_id;
	};

	class IComputeMgr
	{
	public:
		//清空数据
		virtual void clearModel(void) = 0;

		//
		virtual void setGeometryCompRadiusSorted(bool sorted) = 0;
		virtual bool isGeometryCompRadiusSorted(void) = 0;

		//添加一个几何构件半径数据进行排序
		virtual void sortGeometryCompRadius(float dRadius, int id) = 0;

		//获取根据几何构件半径升序排列的集合
		virtual const std::vector<GCompRadius>& getAscendingGeometryCompRadius(void) = 0;

		//添加排序好的数据
		virtual void addAscendingGeometryCompRaidus(const GCompRadius& result) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif