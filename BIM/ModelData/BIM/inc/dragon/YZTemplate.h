#ifndef __YZTEMPLATE_H__
#define __YZTEMPLATE_H__
/*
模板构件
*/
#include "YZProduct.h"
#include "YZComponent.h"

#define VESRION_TEMPLATE 1

namespace YZ
{
	enum TemplateType
	{
		Template_Unknown = 0,
		//几何构件
		Template_General = 1,
		//引用块
		Template_Blocky = 2,
	};

	class MODEL_API Template : public Product
	{
	public:
		friend class TemplateMgr;

		virtual std::string getStrValue(std::string strKey);
		virtual std::string getStringValue(ModelDataType key);
		virtual void presync(void);
		virtual void sync(void);

		Template();
		Template(const std::string& id, CategoryType type);
		virtual ~Template(void);

	protected:
		//dynamic
		TemplateType m_yzType;//模板类型，内部定义
	};
}
#endif