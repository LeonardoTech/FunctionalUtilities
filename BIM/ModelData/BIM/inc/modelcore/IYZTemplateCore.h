#ifndef __YZITemplateCore_H__
#define __YZITemplateCore_H__

#include "Stone.h"

#ifdef OSGCORE
#include "YZTemplate.h"

namespace YZ
{
	//获取内存中存在的所有构件
	CORE_API const std::map<std::string, osg::ref_ptr<Template> >& getAllTemplates(void);

	//根据构件ID获取构件
	CORE_API Template* getTemplateByUniqueId(const std::string& uniqueID);

	//判断osg::Node是否为译筑模板构件
	CORE_API bool isTemplate(osg::Node* node);
}
#endif

namespace YZ
{
	//获取专业，类型，小类名称对应表
	CORE_API void getDomainCategoryName(std::map<std::string, MapVecStdString>& result);

	//获取专业，类型，名称对应表
	//CORE_API std::map<std::string, std::map<std::string, std::vector<std::string> > > getDomainCategoryName(void);
}

#endif