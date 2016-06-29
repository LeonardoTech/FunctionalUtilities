#ifndef __YZBLOCKYOBJECT_H__
#define __YZBLOCKYOBJECT_H__
/*
块引用模板
*/
#include "YZTemplate.h"

#define VESRION_BLOCKY_OBJECT 2

namespace YZ
{
	class MODEL_API BlockyObject : public Template
	{
	public:
		friend class TemplateMgr;

		virtual const char* className() const{ return "BlockyObject"; }
		virtual void presync(void);
		virtual void sync(void);

		//块几何
		//void setBlock(osg::Geode* blck);
		osg::Geode* getBlock(void) const;

		BlockyObject(void);
		BlockyObject(const std::string& uniqueID, CategoryType type);
		virtual ~BlockyObject(void);

	protected:
		//static
		osg::ref_ptr<osg::Geode> m_geometry;//几何
	};
}
#endif