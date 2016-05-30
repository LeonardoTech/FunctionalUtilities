#ifndef __YZIComponentCore_H__
#define __YZIComponentCore_H__
#include "Stone.h"

#ifdef OSGCORE
#include "YZComponent.h"

namespace YZ
{
	//获取内存中存在的所有构件
	CORE_API const std::map<std::string, osg::ref_ptr<Component> >& getAllComponents(void);

	//根据楼层获取内存中存在的构件
	CORE_API void getComponentByFloorName(const std::string& name, std::vector<Component*>& result);
	CORE_API void getComponentByFloorName(const std::vector<std::string>& name, std::vector<Component*>& result);

	//根据体积升序排列所有构件
	CORE_API std::vector<Component*> getAscendingVolumnComponents(void);

	//获取内存中存在的所有模型组
	CORE_API const std::map<std::string, osg::ref_ptr<Component> >& getAllModelGroups(void);

	//根据构件ID获取实体构件
	CORE_API Component* getComponentByUniqueId(const std::string& uniqueID);

	//根据构件ID获取模型组构件
	CORE_API Component* getModelGroupByUniqueId(const std::string& uniqueID);

	//判断osg::Node是否为译筑实体构件
	CORE_API bool isComponent(osg::Node* node);

	//判断osg::Node是否为译筑模型组构件
	CORE_API bool isModelGroup(osg::Node* node);

	//获取实体构件的外包盒
	CORE_API osg::BoundingBox getAllComponentBoundingBox();
}
#endif

namespace YZ
{
	//是否标准的构件关键字
	CORE_API bool isValidComponentKey(std::string key);

	//获取属性组的列表
	CORE_API bool getPropertyGroup(std::vector<std::string>& result);

	//获取符合专业，类型，名称的实体构件集合
	CORE_API bool getComponentByProperty(std::string& domain, std::string& category, std::string& type, std::vector<std::string>& component);

	//根据关键字key，在相应的类型type中查找符合条件的 实体构件集合
	CORE_API bool getComponentByKeySearch(const std::string& key, ModelDataType type, std::vector<std::string>& component);

	//获取专业，类型，类型对应表
	//CORE_API void getDomainCategoryName(std::map<std::string, MapVecStdString>& result);

	//获取一个实体构件的所有属性
	CORE_API bool getComponentProperty(const std::string& uniqueID, MapMapStdString& result);

	//获取一个实体构件的楼层，专业，类型，名称
	CORE_API bool getComponentProperty(const std::string& uniqueID, std::string& floor, std::string& domain, std::string& category, std::string& name, int& rvtId);

	//获取一个模型组构件的名称
	CORE_API bool getModelGroupProperty(const std::string& uniqueID, std::string& floor, std::string& name, int& rvtId);

	//获取一个模型组构件下所有实体构件公共属性
	CORE_API bool getModelGroupProperty(const std::string& uniqueID, MapMapStdString& result);

	//判断构件是否为译筑实体构件
	CORE_API bool isComponent(const std::string& componentID);

	//判断构件是否为译筑模型组构件
	CORE_API bool isModelGroup(const std::string& groupID);

	//根据构件ID获取其最外层组ID，如果没有返回空
	CORE_API std::string getComponentOutmostGroup(const std::string& componentID);

	//根据组ID获取其所包含的构件ID，如果集合为空返回false
	CORE_API bool getGroupRelComponent(const std::string& groupID, std::vector<std::string>& vctComponent);

	//
	CORE_API bool getGroupIdByName(const std::string& name, std::string& groupID);
}
#endif