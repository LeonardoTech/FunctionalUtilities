#ifndef __YZIComponentBSMgr_H__
#define __YZIComponentBSMgr_H__
/*
实体构件二进制流交互管理接口类
*/
#include "Swallow.h"

namespace YZ
{
	class IComponentBSMgr
	{
	public:
		//释放数据
		virtual void free(void) = 0;

		//保存几何构件
		virtual bool saveComponent(void) = 0;

		//保存关系构件
		virtual bool saveModelGroup(void) = 0;

		//读取几何构件
		virtual bool loadComponent(void) = 0;

		//读取关系构件
		virtual bool loadModelGroup(void) = 0;
	};
}
#endif