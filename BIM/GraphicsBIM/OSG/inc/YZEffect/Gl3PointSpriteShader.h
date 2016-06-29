#ifndef __GL3_POINT_SPRITE_SHADER_H__
#define __GL3_POINT_SPRITE_SHADER_H__
#include "IPointSpriteShader.h"

namespace bimWorld
{
	class Gl3PointSpriteShader :public IPointSpriteShader
	{
	public:
		Gl3PointSpriteShader();
		virtual void apply(osg::StateSet* stateSet) override;
		virtual void setPointSize(float pointSize = 60.0f);
	protected:
		float m_pointSize;
	};
}

#endif // __GL3_POINT_SPRITE_SHADER_H__
