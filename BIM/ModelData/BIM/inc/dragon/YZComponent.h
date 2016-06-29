#ifndef __YZCOMPONENT_H__
#define __YZCOMPONENT_H__
/*
	实体构件
*/
#include "YZProduct.h"

#define VESRION_COMPONENT 3

namespace YZ
{
	//译筑内部定义的构件类型
	enum ComponentType
	{
		Component_Unknown = 0,
		//几何构件，只是单纯的几何数据
		Component_General = 1,

		//引用块数据形成的构件
		Component_Blocky = 2,

		//模型组构件
		Component_Group = 3

		//断面路径拉伸体数据形成的构件
		//Component_Linear = 5,

		//面状拉身体数据形成的构件
		//Component_Facet = 4,

		//Component_FlowSegment,
		//Component_Pipe,
		//Component_FlexFlowSegment,
	};

	class Storey;
	class Template;
	class GroupElement;
	class UserProperty;

	class MODEL_API Component : public Product
	{
	public:
		friend class ComponentMgr;

		virtual std::string getStrValue(std::string strKey);
		virtual std::string getStringValue(ModelDataType key);
		virtual void presync(void);
		virtual void sync(void);
		virtual void unsync(void);

		//楼层
		bool isMultiFloor(void);
		void setMultiFloor(bool flr);

		void setFloorID(int id);
		int getFloorID(void) const;
		Storey* getFloor(void) const;

		//模板
		void setTemplateID(int id);
		int getTemplateID(void) const;
		void setTemplate(Template* temp);
		Template* getTemplate(void) const;

		//模型组
		void setGroupID(int group);
		int getGroupID(void) const;
		GroupElement* getGroup(void) const;

		//RevitID
		void setRevitID(int id);
		int getRevitID(void) const;

		//颜色
		void setColor(const osg::Vec4& color);
		osg::Vec4* getColor(void) const;

		//
		ComponentType getYZType(void) const;

		Component();
		Component(const std::string& id, CategoryType type);
		virtual ~Component(void);

	protected:
		//static
		int m_templateID;//所属模板构件
		bool m_multiFloor;//是否跨层构件，暂时无用
		int m_storeyID;//所在楼层
		int m_groupID;//所在的模型组（一对一）
		int m_rvtEntityID;//Revit ID，方便在Revit中查找数据

		osg::Vec4* m_color;//颜色

		//dynamic
		Template* m_template;
		Storey* m_storey;
		GroupElement* m_group;

		ComponentType m_yzType;//构件类型，内部定义

	public:
		UserProperty* userProperty;
	};
}
#endif