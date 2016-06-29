////////////
//    created by 孙庆号
////////////

#ifndef __ZOOM_MODEL_WRAPPER_H__
#define __ZOOM_MODEL_WRAPPER_H__
#include "IZoomEntityModel.h"
#include "YZModelEntityModule.h"
#include <memory>
namespace bimWorld
{
	class ZoomModelWrapper :public IZoomEntityModel, public YZModelEntityModule
	{
	public:
		ZoomModelWrapper(YZModelEntityInternal* host);

		// <构件根节点居中>
		virtual bool zoomRoot(bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front);

		// <构件节点居中>
		virtual bool zoomTo(void* node, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front);

		// <构件节点居中>
		virtual bool zoomTo(void** nodes, int length, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front);

		virtual void zoom(double dy);
	protected:
		std::unique_ptr<bimWorld::IZoomModel> m_controller;
	};
}
#endif // __ZOOM_MODEL_WRAPPER_H__