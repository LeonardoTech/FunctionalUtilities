////////////
//    created by 孙庆号
////////////

#ifndef __ZOOM_MODEL_H__
#define __ZOOM_MODEL_H__

#include <string>
#include "YZModelCoreModule.h"
#include "IZoomModel.h"

namespace bimWorld
{
	class YIZHU_EXPORT ZoomModel :public YZModelCoreModule, public IZoomModel
	{
	public:
		ZoomModel(YZModelCoreInternal* host);

		/////////////////////////节点zoom/////////////////////////////////

		//// <构件居中>
		//virtual bool zoomTo(const std::string& id, bool withoutAnimation = true) override;
		// <构件节点居中>
		virtual bool zoomTo(void* node, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) override;
		//// <构件节点居中>
		//virtual bool zoomTo(const std::string* nodes, int length, bool withoutAnimation = true) override;
		// <构件节点居中>
		virtual bool zoomTo(void** nodes, int length, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) override;
		
		// <构件根节点居中>
		virtual bool zoomRoot(bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) override;

		virtual void zoom(double dy) override;
	protected:
	};
}

#endif // __ZOOM_MODEL_H__