#ifndef __YZGEOMETRYELEMENT_H__
#define __YZGEOMETRYELEMENT_H__
/*
几何实体构件
*/
#include "YZComponent.h"

#define VESRION_GEOMETRY_COMP 1

namespace YZ
{
	class MODEL_API GeometryComp : public Component
	{
	public:
		friend class ComponentMgr;

		virtual std::string getStringValue(ModelDataType key);
		virtual void presync(void);
		virtual void sync(void);
		virtual void unsync(void);

		osg::Geode* getGeode(void) const;

		GeometryComp();
		GeometryComp(const std::string& id, CategoryType type);
		virtual ~GeometryComp(void);

	protected:
		//同步几何数据
		virtual void syncOsgGeometry(void){}

		//同步几何颜色
		virtual void syncOsgColor(void);

		//
		virtual void computeBoundindBox(void);

	protected:
		osg::ref_ptr<osg::Geode> m_geode;//真实几何
	};
}
#endif