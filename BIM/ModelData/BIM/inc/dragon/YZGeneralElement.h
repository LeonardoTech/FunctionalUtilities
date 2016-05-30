#ifndef __YZGENERALELEMENT_H__
#define __YZGENERALELEMENT_H__
/*
真实几何构件
*/
#include "YZGeometryComp.h"

#define VESRION_GENERAL_ELEMENT 2

namespace YZ
{
	class GeneralObject;

	class MODEL_API GeneralElement : public GeometryComp
	{
	public:
		friend class ComponentMgr;

		virtual const char* className() const{ return "GeneralElement"; }
		virtual void presync(void);
		virtual void sync(void);

		//几何数据
		//void setGeometry(osg::Geode* geo);
		//osg::Geode* getGeode(void) const;

		//
		//GeneralObject* geometryTemplate(void) const;

		GeneralElement(void);
		GeneralElement(const std::string& id, CategoryType type);
		virtual ~GeneralElement(void);

	protected:
		virtual void syncOsgGeometry(void);

	protected:
		//osg::ref_ptr<GeometryItem> m_actualGeo;//真实几何
	};
}
#endif