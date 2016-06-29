////////////
//    created by 孙庆号
////////////

#ifndef __IBASIC_SHADER_H__
#define __IBASIC_SHADER_H__
#include "config.h"
#include <osg/StateSet>

namespace bimWorld
{
	class YIZHU_EXPORT IBasicShader
	{
	public:
		virtual void applyNoLightWithTexture(osg::StateSet* stateSet) = 0;
		
		virtual void applyNoLightColor(osg::StateSet* stateSet) = 0;

		virtual void applyColorWithLight(osg::StateSet* stateSet) = 0;

		virtual void applyNoLightNoSliceWithTexture(osg::StateSet* stateSet) = 0;

		virtual void applyNoLightNoSliceWithColor(osg::StateSet* stateSet) = 0;

		virtual void applyNoSliceWithMat(osg::StateSet* stateSet) = 0;

		virtual void applyDefaultWithMat(osg::StateSet* stateSet) = 0;
		
		virtual void applyDefaultWithTexture(osg::StateSet* stateSet) = 0;

		virtual void applyPointSpriteShader(osg::StateSet* stateSet, float pointSize = 60.0) = 0;
		
		virtual void applyFontShader(osg::StateSet* stateSet) = 0;
	};
}
#endif // __IBASIC_SHADER_H__