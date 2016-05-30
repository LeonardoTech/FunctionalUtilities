#ifndef __GLES3_DEFAULT_SHADER_H__
#define __GLES3_DEFAULT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gles3DefaultShader :public IShader
	{
	public:
		Gles3DefaultShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GLES3_DEFAULT_SHADER_H__
