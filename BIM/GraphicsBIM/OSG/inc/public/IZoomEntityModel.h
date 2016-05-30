////////////
//    created by 孙庆号
////////////

#ifndef __IZOOM_ENTITY_MODEL_H__
#define __IZOOM_ENTITY_MODEL_H__
#include <string>
#include <vector>
#include "IZoomModel.h"

namespace bimWorld
{

	class YIZHU_EXPORT IZoomEntityModel:public IZoomModel
	{
	public:
		// <构件根节点居中>
		//virtual bool zoomRoot(bool withoutAnimation = true, ViewDirection direction = Front) = 0;

		// <构件居中>
		virtual bool zoomTo(const std::string& id, bool withoutAnimation = true) = 0;

		//// <构件节点居中>
		//virtual bool zoomTo(void* node, bool withoutAnimation = true, ViewDirection direction = Front) = 0;

		// <构件节点居中>
		virtual bool zoomTo(const std::vector<std::string>& nodes, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) = 0;

		//// <构件节点居中>
		//virtual bool zoomTo(void** nodes, int length, bool withoutAnimation = true, ViewDirection direction = Front) = 0;

		//virtual void zoom(double dy) = 0;
	};
}

#endif // __IZOOM_ENTITY_MODEL_H__