#ifndef __GL3_DEFAULT_SHADER_H__
#define __GL3_DEFAULT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gl3DefaultShader:public IShader
	{
	public:
		Gl3DefaultShader();

		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GL3_DEFAULT_SHADER_H__
