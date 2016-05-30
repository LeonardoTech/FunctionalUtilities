#ifndef __GL3_FONT_SHADER_H__
#define __GL3_FONT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gl3FontShader :public IShader
	{
	public:
		Gl3FontShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GL3_FONT_SHADER_H__
