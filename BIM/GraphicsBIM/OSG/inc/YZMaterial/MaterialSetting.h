////////////
//    created by 孙庆号
////////////

#ifndef __MATERIAL_SETTING_H__
#define __MATERIAL_SETTING_H__
#include "config.h"
#include <osg/StateSet>
#include <mutex>
#include "YZEffectModule.h"
#include "IMaterialSetting.h"
#include <osg/BlendFunc>

namespace bimWorld
{
	class YIZHU_EXPORT MaterialSetting :public YZEffectModule, public IMaterialSetting
	{
	public:
		MaterialSetting(YZEffect* host);

		virtual bool saveMaterialSettingToFile(const char *fileName);

		virtual bool readMaterialSettingFromFile(const char *fileName);

		osg::StateSet* getSelectionRenderModel() override;

		virtual void setToTransparent(void* node, float opacity = 0.8) override;

		virtual void setDefaultMaterial(void* node, osg::Vec4 color) override;

		void setIsModified(bool modified) override;

		bool isModified();

	// internal:

		osg::BlendFunc* getBlendFunc();

		void setNodeState(osg::Node* node, osg::Vec4f color);

	protected:
		// <选中部分的材质，高亮状态>
		osg::ref_ptr<osg::StateSet> m_selectionRenderMode;
		std::mutex _lock;
		bool m_materialModified;

		// <颜色混合>
		osg::ref_ptr<osg::BlendFunc> m_blendFunc;
	};
}

#endif // __MATERIAL_SETTING_H__