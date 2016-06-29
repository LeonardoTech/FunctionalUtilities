#ifndef __GLES2_FONT_SHADER_H__
#define __GLES2_FONT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gles2FontShader :public IShader
	{
	public:
		Gles2FontShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GLES2_FONT_SHADER_H__
