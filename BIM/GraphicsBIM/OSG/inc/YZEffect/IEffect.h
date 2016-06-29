////////////
//    created by 孙庆号
////////////

#ifndef __YZ_IEFFECT_H__
#define __YZ_IEFFECT_H__
#include "config.h"
#include <memory>
#include "osg/Node"

namespace bimWorld
{
	class YIZHU_EXPORT IEffect
	{
	public:
		virtual bool apply(osg::Node* node) = 0;
	};
}

#endif // __YZ_IEFFECT_H__