#ifndef __YZIComponentDBMgr_H__
#define __YZIComponentDBMgr_H__
/*
实体构件数据库管理接口类
*/
#include "Tiger.h"
#include "IYZParameterList.h"

namespace YZ
{
	class IComponentDBMgr
	{
	public:
		//释放数据
		virtual void free(void) = 0;

		//保存几何构件
		virtual bool saveComponent(void) = 0;

		//读取几何构件
		virtual bool loadComponent(void) = 0;

		//根据楼层id读取几何构件
		virtual bool loadComponentByFloor(int id) = 0;

		//清空几何构件（onlyData=true只清空Data数据）
		virtual bool clearComponent(bool onlyData = true) = 0;

		//保存模型组构件
		virtual bool saveModelGroup(void) = 0;

		//读取模型组构件
		virtual bool loadModelGroup(void) = 0;

		//清空模型组构件（onlyData=true只清空Data数据）
		virtual bool clearModelGroup(bool onlyData = true) = 0;

		//根据几何构件id读取属性（构件+模板）
		virtual bool getComponentParameter(const std::string& id, IParameterList* parlist) = 0;

		virtual bool getComponentParameter(const std::string& id, int& compId, int& domain, int& category, std::string& name, int& rvtId) = 0;

		virtual bool getComponentFloorName(const int& compId, std::string& name) = 0;

		//获取所有属性组名称列表
		virtual bool getParameterGroupName(std::vector<std::string>& result) = 0;

		//获取符合专业，类型，名称条件的构件id
		virtual bool getComponentByProperty(int domain, int category, std::string& name, std::vector<std::string>& component) = 0;

		//根据关键字key，在相应的类型type中查找符合条件的 实体构件集合（几何和模型组都会查找）
		//目前type只实现了MODEL_COMPONENT_NAME和MODEL_COMPONENT_RVTID
		virtual bool getComponentByKeySearch(const std::string& key, ModelDataType type, std::vector<std::string>& component) = 0;
	};
}
#endif