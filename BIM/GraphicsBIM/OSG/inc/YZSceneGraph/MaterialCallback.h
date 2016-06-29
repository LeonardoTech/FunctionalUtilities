////////////
//    created by 孙庆号
////////////

#ifndef __MATERIAL_CALLBACK_H__
#define __MATERIAL_CALLBACK_H__
#include <osg/NodeCallback>
#include <osg/Group>
#include <osg/UserDataContainer>
#include <mutex>
#include "UserDataDefine.h"
#include "YZModelCoreInternal.h"

namespace bimWorld
{
	class MaterialCallback :public osg::NodeCallback
	{
	public:
		YZModelCoreInternal* m_host;
		MaterialCallback(bimWorld::YZModelCoreInternal* host);
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

		void update(osg::Node* node);

		osg::StateSet* getTopStateSet(osg::Node* child);
	};

}

#endif // __MATERIAL_CALLBACK_H__