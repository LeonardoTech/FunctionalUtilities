////////////
//    created by 孙庆号
////////////

#ifndef __BASIC_SHADER_H__
#define __BASIC_SHADER_H__
#include "config.h"
#include <osg/StateSet>
#include "YZEffectModule.h"
#include "IBasicShader.h"

namespace bimWorld
{
	class YIZHU_EXPORT BasicShader :public YZEffectModule, public IBasicShader
	{
	public:
		BasicShader(YZEffect* host);

		virtual void applyNoLightWithTexture(osg::StateSet* stateSet) override;
		
		virtual void applyNoLightColor(osg::StateSet* stateSet) override;

		virtual void applyColorWithLight(osg::StateSet* stateSet) override;

		virtual void applyNoLightNoSliceWithColor(osg::StateSet* stateSet) override;
		
		virtual void applyNoSliceWithMat(osg::StateSet* stateSet) override;

		virtual void applyNoLightNoSliceWithTexture(osg::StateSet* stateSet) override;

		virtual void applyDefaultWithMat(osg::StateSet* stateSet) override;

		virtual void applyDefaultWithTexture(osg::StateSet* stateSet) override;

		// no light with texture.
		virtual void applyPointSpriteShader(osg::StateSet* stateSet, float pointSize = 60.0) override;
		
		virtual void applyFontShader(osg::StateSet* stateSet) override;

	// internal:

	protected:
		void gl3DefaultShader(osg::StateSet* stateSet);

		void gl2DefaultShader(osg::StateSet* stateSet);

		void gles2DefaultShader(osg::StateSet* stateSet);

		void gles3DefaultShader(osg::StateSet* stateSet);

		void gl3NoSliceShader(osg::StateSet* stateSet);

		void gles2NoSliceShader(osg::StateSet* stateSet);

		void gles3NoSliceShader(osg::StateSet* stateSet);

		void gles2PointSpriteShader(osg::StateSet* stateSet, float pointSize = 60.0);
		
		void gl3PointSpriteShader(osg::StateSet* stateSet, float pointSize = 60.0);

	};
}

#endif // __BASIC_SHADER_H__