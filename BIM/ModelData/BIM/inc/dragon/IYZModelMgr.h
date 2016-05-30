#ifndef __YZIMODELMGR_H__
#define __YZIMODELMGR_H__
/*
	模型数据管理接口类
*/
#include "Dragon.h"

namespace YZ
{
 	class IProjectMgr;
	class ITemplateMgr;
	class IComponentMgr;
	class IComputeMgr;
	class IParameterList;

	class IModelMgr
	{
	public:
		//获取工程数据管理指针
		virtual IProjectMgr* getProjectMgr(void) = 0;

		//获取模板构件数据管理指针
		virtual ITemplateMgr* getTemplateMgr(void) = 0;

		//获取实体构件数据管理指针
		virtual IComponentMgr* getComponentMgr(void) = 0;

		//获取计算数据管理指针
		virtual IComputeMgr* getComputeMgr(void) = 0;

		//获取一个临时创建的属性集合指针，自己释放
		virtual IParameterList* getParameterList(void) = 0;

		//预处理时同步所有数据（主要是几何数据的处理）
		virtual void preSynchronize(void) = 0;

		//打开时同步所有数据（主要获取可直接使用的指针数据）
		virtual void synchronize(void) = 0;

		virtual void free(void) = 0;
	};
}
#endif