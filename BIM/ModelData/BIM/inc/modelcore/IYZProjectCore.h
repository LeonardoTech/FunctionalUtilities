#ifndef __YZIProjectCore_H__
#define __YZIProjectCore_H__
#include "Stone.h"

#ifdef OSGCORE
#include "YZStorey.h"

namespace YZ
{
	//根据楼层名称获取楼层
	CORE_API Storey* getFloorByName(const std::string& name);
}
#endif

namespace YZ
{
	//获取楼层名称列表
	CORE_API void getFloorName(std::vector<std::string>& vctName);
}
#endif