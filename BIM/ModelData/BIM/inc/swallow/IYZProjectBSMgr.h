#ifndef __YZIProjectBSMgr_H__
#define __YZIProjectBSMgr_H__
/*
工程二进制流交互管理接口类
*/
#include "Swallow.h"

namespace YZ
{
	class IProjectBSMgr
	{
	public:
		//保存工程，楼层
		virtual bool saveModel(void) = 0;

		//读取工程，楼层
		virtual bool loadModel(void) = 0;

		//释放数据
		virtual void free(void) = 0;

		virtual bool saveProject(void) = 0;
		virtual bool loadProject(void) = 0;

		virtual bool saveStorey(void) = 0;
		virtual bool loadStorey(void) = 0;
	};
}
#endif