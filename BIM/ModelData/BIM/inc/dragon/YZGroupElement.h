#ifndef __YZGROUPELEMENT_H__
#define __YZGROUPELEMENT_H__
/*
模型组构件
*/
#include "YZRelationComp.h"

#define VESRION_GROUP_ELEMENT 1

namespace YZ
{
	class MODEL_API GroupElement : public RelationComp
	{
	public:
		friend class ComponentMgr;

		virtual const char* className() const{ return "GroupElement"; }
		//virtual void sync(void);

		void addRelComponent(Component* comp);
		void delRelComponent(Component* comp);
		const std::vector <Component*>& getRelComponent(void) const;
		void clearRelComponent(void);

		GroupElement();
		GroupElement(const std::string& id, CategoryType type);
		virtual ~GroupElement(void);

	protected:
		//dynamic
		std::vector<Component*> m_relComponent;
	};
}
#endif