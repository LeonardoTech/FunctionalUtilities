#ifndef __YZIComputeBSMgr_H__
#define __YZIComputeBSMgr_H__
/*
计算数据二进制流交互管理接口类
*/
#include "Swallow.h"

namespace YZ
{
	class IComputeBSMgr
	{
	public:
		//保存
		virtual bool saveModel(void) = 0;

		//读取
		virtual bool loadModel(void) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif