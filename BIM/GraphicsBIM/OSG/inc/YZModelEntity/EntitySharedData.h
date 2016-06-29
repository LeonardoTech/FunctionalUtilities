////////////
//    created by 孙庆号
////////////

#ifndef __ENTITY_SHARED_DATA_H__
#define __ENTITY_SHARED_DATA_H__
#include <map>
#include <osg/Node>
#include "YZModelCoreInternal.h"

namespace bimWorld
{
	class YIZHU_EXPORT EntitySharedData
	{
	public:
		EntitySharedData(YZModelCoreInternal* modelCore);

		std::map<std::string, osg::Node*>& IdNodeptr() { return m_idNodeptr; }

		void IdNodeptr(std::map<std::string, osg::Node*> val) { m_idNodeptr = val; }

	protected:
		// <uuid 和指针对应关系>
		std::map<std::string, osg::Node*> m_idNodeptr;

		bimWorld::YZModelCoreInternal* _modelCore;
	};
}
#endif // __ENTITY_SHARED_DATA_H__