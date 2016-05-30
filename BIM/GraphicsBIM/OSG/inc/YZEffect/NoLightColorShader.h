#ifndef __NO_LIGHT_COLOR_SHADER_H__
#define __NO_LIGHT_COLOR_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class YIZHU_EXPORT NoLightColorShader :public IShader
	{
	public:
		NoLightColorShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __NO_LIGHT_COLOR_SHADER_H__
