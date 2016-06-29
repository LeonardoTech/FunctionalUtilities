#ifndef __ISHADER_H__
#define __ISHADER_H__
#include "osg/StateSet"

namespace bimWorld
{
	class IShader
	{
	public:
		virtual void apply(osg::StateSet* stateSet) = 0;
	};
}

#endif // __ISHADER_H__
