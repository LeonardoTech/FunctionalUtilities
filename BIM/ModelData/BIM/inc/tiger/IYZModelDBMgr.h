#ifndef __YZIModelDBMgr_H__
#define __YZIModelDBMgr_H__
/*
	模型数据库交互管理接口类
*/
#include "Tiger.h"

namespace YZ
{
	class IProjectDBMgr;
	class IComponentDBMgr;
	class ITemplateDBMgr;

	class IModelDBMgr
	{
	public:
		//获取数据库管理指针
		virtual IProjectDBMgr* getProjectDBMgr(void) = 0;
		virtual IComponentDBMgr* getComponentDBMgr(void) = 0;
		virtual ITemplateDBMgr* getTemplateDBMgr(void) = 0;

		//保存模型所有数据
		virtual bool saveModel(void) = 0;

		//读取模型所有数据
		virtual bool loadModel(void) = 0;

		//清除模型所有数据
		virtual bool clearModel(void) = 0;

		//打开的数据库版本低于当前版本，数据库升级
		virtual ResultState upgradeDatabase(const std::string& dbVersion) = 0;

		//保存当前数据库版本号
		virtual bool saveVersion(void) = 0;

		//获取当前打开工程数据库版本号
		virtual bool loadVersion(std::string& Main, std::string& Second, std::string& Third) = 0;

		//获取当前数据库版本号
		virtual void getCurrentVersion(std::string& Main, std::string& Second, std::string& Third) = 0;

		//释放所有数据库连接
		virtual void free(void) = 0;

	};
}
#endif