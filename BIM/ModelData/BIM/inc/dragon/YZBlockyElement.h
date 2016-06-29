#ifndef __YZBLOCKYELEMENT_H__
#define __YZBLOCKYELEMENT_H__
/*
块状构件，在插入位置布置块几何
*/
#include "YZGeometryComp.h"
#include "YZTransform3.h"

#define VESRION_BLOCKY_ELEMENT 2

namespace YZ
{
	class BlockyObject;

	class MODEL_API BlockyElement : public GeometryComp
	{
	public:
		friend class ComponentMgr;

		virtual const char* className() const{ return "BlockyElement"; }
		virtual void presync(void);
		virtual void sync(void);

		//坐标变换
		void setTransform(const Transform3& trans);
		const Transform3& getTransform(void) const;

		BlockyElement(void);
		BlockyElement(const std::string& uniqueID, CategoryType type);
		virtual ~BlockyElement(void);

	protected:
		virtual void syncOsgGeometry(void);

	protected:
		Transform3 m_transf;//坐标变换
	};
}
#endif