#ifndef __ISHADER_H__
#define __ISHADER_H__
#include "osg/StateSet"
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT IShader
	{
	public:
		virtual void apply(osg::StateSet* stateSet) = 0;
	};
}

#endif // __ISHADER_H__
