#ifndef __GLES2_POINT_SPRITE_SHADER_H__
#define __GLES2_POINT_SPRITE_SHADER_H__
#include "IPointSpriteShader.h"

namespace bimWorld
{
	class Gles2PointSpriteShader :public IPointSpriteShader
	{
	public:
		Gles2PointSpriteShader();
		virtual void apply(osg::StateSet* stateSet) override;
		virtual void setPointSize(float pointSize  = 60.0f ) override;
	protected:
		float m_pointSize;
	};
}

#endif // __GLES2_POINT_SPRITE_SHADER_H__
