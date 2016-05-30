#ifndef __FONT_SHADER_H__
#define __FONT_SHADER_H__
#include "IShader.h"

namespace bimWorld
{
	class YIZHU_EXPORT FontShader :public IShader
	{
	public:
		FontShader();
		virtual void apply(osg::StateSet* stateSet) override;
	protected:
	};
}

#endif // __FONT_SHADER_H__
