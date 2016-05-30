#ifndef __YZRELATIONCOMP_H__
#define __YZRELATIONCOMP_H__
/*
关系实体构件，没有几何数据的构件
*/
#include "YZComponent.h"

#define VESRION_RELATION_COMP 1

namespace YZ
{
	class MODEL_API RelationComp : public Component
	{
	public:
		friend class ComponentMgr;

		//virtual std::string getStringValue(ModelDataType key);
		virtual void sync(void);
		virtual void unsync(void);

		RelationComp();
		RelationComp(const std::string& id, CategoryType type);
		virtual ~RelationComp(void);
	};
}
#endif