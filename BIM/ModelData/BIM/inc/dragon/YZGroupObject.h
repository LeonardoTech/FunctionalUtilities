#ifndef __YZGROUPOBJECT_H__
#define __YZGROUPOBJECT_H__
/*

*/
#include "YZTemplate.h"
#define VESRION_GROUP_OBJECT 1
namespace YZ
{
	class MODEL_API GroupObject : public Template
	{
	public:
		friend class TemplateMgr;

		virtual const char* className() const{ return "GroupObject"; }
		//virtual void sync(IModelMgr* mgr);

		GroupObject(void);
		GroupObject(const std::string& uniqueID, CategoryType type);
		virtual ~GroupObject(void);

	protected:
	};
}
#endif