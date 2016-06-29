#ifndef __YZIMODEL_H__
#define __YZIMODEL_H__
#include "Dragon.h"
#include "YZCategoryType.h"
#include "YZDomainType.h"
#include "YZProjectType.h"

namespace YZ
{
	class IModelMgr;

	//创建并获取模型管理对象指针
	//modelMgr为创建的模型管理指针
	MODEL_API IModelMgr* createModelMgr(void);

	//根据构件类型获取构件类型名
	MODEL_API std::string getCategoryName(CategoryType eType);

	//根据构件类型名获取构件类型
	MODEL_API CategoryType getCategoryType(std::string strType);

	//根据专业类型获取专业类型名
	MODEL_API std::string getDomainName(DomainType eType);

	//根据专业类型名获取专业类型
	MODEL_API DomainType getDomainType(std::string strType);

	//根据构件类型获取默认专业类型
	MODEL_API DomainType getDomainByCategory(CategoryType eType);

	//根据工程类型获取工程类型名
	MODEL_API std::string getProjectName(ProjectType eType);
}
#endif