#ifndef __GL2_FONT_SHADER_H__
#define __GL2_FONT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class Gl2FontShader :public IShader
	{
	public:
		Gl2FontShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __GL2_FONT_SHADER_H__
