#ifndef __YZPRODUCT_H__
#define __YZPRODUCT_H__
/*
	构件基类，这里的类型是数据源软件自身的构件类型
*/
#include "YZElement.h"
#include "YZCategoryType.h"
#include "YZDomainType.h"

#define VESRION_PRODUCT 1

namespace YZ
{
	class Project;

	class MODEL_API Product : public Element
	{
	public:
		virtual std::string getStrValue(std::string strKey);
		virtual std::string getStringValue(ModelDataType key);
		virtual void presync(void);
		virtual void sync(void);
		virtual void unsync(void);

		//类型
		void setCategory(CategoryType type);
		CategoryType getCategory(void) const;

		//专业
		void setDomain(DomainType domain);
		DomainType getDomain(void) const;

		//工程
		void setProjectID(int id);
		int getProjectID(void) const;

		Product(void);//默认构造函数在读取数据库时使用，其填充数据不需要逻辑
		Product(const std::string& uniqueID, CategoryType type);//管理类使用的构造函数，必须确保id和category的正确性
		virtual ~Product(void);

	protected:
		//static
		CategoryType m_category;//类型
		DomainType m_domain;//专业
		int m_projectID;//所属项目ID

		//dynamic
		Project* m_project;
	};
}
#endif