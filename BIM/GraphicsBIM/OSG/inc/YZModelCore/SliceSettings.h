////////////
//    created by 孙庆号
////////////

#ifndef __YZ_SLICE_SETTINGS_H__
#define __YZ_SLICE_SETTINGS_H__
#include "YZModelCoreModule.h"
#include "config.h"
#include "ISlice.h"
#include <memory>

namespace bimWorld
{
	class YIZHU_EXPORT SliceSettings :public YZModelCoreModule, public ISlice
	{
	public:
		SliceSettings(bimWorld::YZModelCoreInternal* host);

		~SliceSettings();

		virtual void setSlicePlaneEnabled(SlicePlaneDirection direction, bool enabled) override;
		
		virtual bool getSlicePlanePosition(SlicePlaneDirection direction, float& posX, float& posY, float& posZ, float& offset) override;
		
		virtual void setSlicePlanePosition(SlicePlaneDirection direction, float posX, float posY, float posZ, float offset) override;
		
		virtual void setSlicePlaneVisibility(SlicePlaneDirection direction, bool visible) override;

		void apply();

		virtual void setNeedDrawOutLine(bool drawOutLine) override;

		virtual void reset() override;

	protected:
		// <模型会旋转90度，所以在这里处理旋转>
		SlicePlaneDirection changeDirection(SlicePlaneDirection direction);

		bool m_applied;
	};
}

#endif // __YZ_SLICE_SETTINGS_H__