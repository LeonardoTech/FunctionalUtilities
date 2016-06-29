#ifndef __YZGENERALOBJECT_H__
#define __YZGENERALOBJECT_H__
/*
常规模板
*/
#include "YZTemplate.h"
#define VESRION_GENERAL_OBJECT 1
namespace YZ
{
	class MODEL_API GeneralObject : public Template
	{
	public:
		friend class TemplateMgr;

		virtual const char* className() const{ return "GeneralObject"; }
		//virtual void sync(void);

		GeneralObject(void);
		GeneralObject(const std::string& uniqueID, CategoryType type);
		virtual ~GeneralObject(void);

	protected:
	};
}
#endif