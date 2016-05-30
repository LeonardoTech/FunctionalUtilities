#ifndef __IPOINT_SPRITE_SHADER_H__
#define __IPOINT_SPRITE_SHADER_H__
#include "osg/StateSet"

namespace bimWorld
{
	class IPointSpriteShader
	{
	public:
		virtual void apply(osg::StateSet* stateSet) = 0;

		virtual void setPointSize(float pointSize = 60.0f) = 0;
	};
}

#endif // __IPOINT_SPRITE_SHADER_H__
