#ifndef __GLES2_DEFAULT_SHADER_H__
#define __GLES2_DEFAULT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gles2DefaultShader :public IShader
	{
	public:
		Gles2DefaultShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GLES2_DEFAULT_SHADER_H__
