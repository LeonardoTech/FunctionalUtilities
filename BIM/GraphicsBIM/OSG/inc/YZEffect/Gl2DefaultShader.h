#ifndef __GL2_DEFAULT_SHADER_H__
#define __GL2_DEFAULT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gl2DefaultShader :public IShader
	{
	public:
		Gl2DefaultShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GL2_DEFAULT_SHADER_H__
