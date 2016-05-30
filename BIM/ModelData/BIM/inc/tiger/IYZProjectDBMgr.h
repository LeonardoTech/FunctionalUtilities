#ifndef __YZIProjectDBMgr_H__
#define __YZIProjectDBMgr_H__
/*
工程数据库交互管理接口类
*/
#include "Tiger.h"

namespace YZ
{
	class IProjectDBMgr
	{
	public:
		//保存工程，楼层，类型到数据库
		virtual bool saveModel(void) = 0;

		//读取工程，楼层，类型到模型
		virtual bool loadModel(void) = 0;

		//
		virtual bool clearModel(void) = 0;

		//保存工程信息
		virtual bool saveProject(void) = 0;

		//读取工程信息
		virtual bool loadProject(void) = 0;

		//
		virtual bool clearProject(void) = 0;

		//保存楼层信息
		virtual bool saveStorey(void) = 0;

		//读取楼层信息
		virtual bool loadStorey(void) = 0;

		//
		virtual bool clearStorey(void) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif