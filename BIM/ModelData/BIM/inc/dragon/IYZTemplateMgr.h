#ifndef __YZITEMPLATEMGR_H__
#define __YZITEMPLATEMGR_H__
/*
模板构件数据管理接口类
*/
#include "YZTemplate.h"

namespace YZ
{
	class ITemplateMgr
	{
	public:
		typedef std::map<std::string, osg::ref_ptr<Template> > MapTemplate;

		//释放数据
		virtual void free(void) = 0;

		//创建模板构件并加入当前管理，创建失败返回false，已经存在该ID返回该构件指针comp和false
		virtual bool createTemplate(const std::string& uniqueID, CategoryType categoryType, TemplateType tempType, Template*& temp) = 0;

		//创建模板构件，不加入当前管理
		virtual Template* newTemplate(const std::string& uniqueID, CategoryType categoryType, TemplateType tempType) = 0;

		//添加模板构件到当前管理，如果有重复ID，不添加返回false
		virtual bool addTemplate(Template* temp, bool autoID = false) = 0;

		//获取所有模板构件
		virtual const MapTemplate& getTemplate(void) = 0;

		//通过id获取模板构件，如果没有返回为空
		virtual Template* getTemplateByID(int ID) = 0;
		virtual Template* getTemplateByUniqueID(const std::string& uniqueID) = 0;

		//判断该id的模板构件是否存在
		virtual bool isTemplateExist(int ID) = 0;
		virtual bool isTemplateExist(const std::string& uniqueID) = 0;

		//获取需要加载的模板构件id集合
		//virtual std::vector<std::string> getTemplateIDNeedLoad(const std::vector<std::string>& templateIds) = 0;

		//删除模板构件，成功返回true，没有找到返回false
		virtual bool removeTemplateByID(int ID) = 0;
		virtual bool removeTemplateByUniqueID(const std::string& uniqueID) = 0;

		//清空模板构件
		virtual void clearTemplate(void) = 0;

		//预同步数据
		virtual void preSyncTemplate(void) = 0;

		//同步数据
		virtual void syncTemplate(void) = 0;
	};
}
#endif