////////////
//    created by 孙庆号
////////////

#ifndef __IMATERIAL_SETTING_H__
#define __IMATERIAL_SETTING_H__
#include "config.h"
#include <osg/Node>
#include <osg/StateSet>

namespace bimWorld
{
	class YIZHU_EXPORT IMaterialSetting
	{
	public:
		virtual void setToTransparent(void* node, float opacity = 0.8) = 0;

		virtual void setDefaultMaterial(void* node, osg::Vec4 color) = 0;
		
		virtual osg::StateSet* getSelectionRenderModel() = 0;

		virtual void setIsModified(bool modified) = 0;
	};
}
#endif // __IMATERIAL_SETTING_H__