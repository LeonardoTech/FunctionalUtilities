#ifndef __YZSTOREY_H__
#define __YZSTOREY_H__
/*
楼层构件，一个工程只提供一个楼层标准
*/
#include "YZElement.h"

#define VESRION_STOREY 1

namespace YZ
{
	class Component;

	class MODEL_API Storey : public Element
	{
	public:
		friend class ProjectMgr;

		virtual std::string getStringValue(ModelDataType key);

		//楼层底标高
		void setElevation(float elevation);
		float getElevation(void);

		//楼层顶标高
		float getTopElevation(void);

		//楼层高度
		void setHeight(float height);
		float getHeight(void);

		//楼层下的几何构件
		void addRelComponent(Component* comp);
		void delRelComponent(Component* comp);
		const std::vector <Component*>& getRelComponent(void) const;
		void clearRelComponent(void);

		//楼层下的关系构件
		void addRelModelGroup(Component* comp);
		void delRelModelGroup(Component* comp);
		const std::vector <Component*>& getRelModelGroup(void) const;
		void clearRelModelGroup(void);

		Storey(void);
		Storey(const std::string& uniqueID);
		virtual ~Storey(void);

	protected:
		//static
		float m_elevation;//底标高
		float m_height;//楼层高度

		//dynamic
		//楼层包含的几何构件
		std::vector<Component*> m_relComponent;
		//楼层包含的关系构件
		std::vector<Component*> m_relModelGroup;
	};
}
#endif