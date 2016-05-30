////////////
//    created by 孙庆号
////////////

#ifndef __ZOOM_ENTITY_MODEL_H__
#define __ZOOM_ENTITY_MODEL_H__
#include "ZoomModelWrapper.h"
#include "IZoomEntityModel.h"
#include "YZModelEntityModule.h"

namespace bimWorld
{
	class ZoomEntityModel:public ZoomModelWrapper
	{
	public:
		ZoomEntityModel(YZModelEntityInternal* host);

		// <构件居中>
		virtual bool zoomTo(const std::string& id, bool withoutAnimation = true) override;

		// <构件节点居中>
		virtual bool zoomTo(const std::vector<std::string>& nodes, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) override;

	protected:
	};
}
#endif // __ZOOM_ENTITY_MODEL_H__