////////////
//    created by 孙庆号
////////////

#ifndef __IZOOM_MODEL_H__
#define __IZOOM_MODEL_H__

#include <string>
#include "config.h"

namespace bimWorld
{
	// <视图方向>
	enum class ViewDirection
	{
		Front,
		Back,
		Left,
		Right,
		Top,
		Bottom,
	};

	class YIZHU_EXPORT IZoomModel
	{
	public:
		// <构件根节点居中>
		virtual bool zoomRoot(bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) = 0;

		//// <构件居中>
		//virtual bool zoomTo(const std::string& id, bool withoutAnimation = true) = 0;
		
		// <构件节点居中>
		virtual bool zoomTo(void* node, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) = 0;
		
		//// <构件节点居中>
		//virtual bool zoomTo(const std::string* nodes, int length, bool withoutAnimation = true) = 0;
		
		// <构件节点居中>
		virtual bool zoomTo(void** nodes, int length, bool withoutAnimation = true, ViewDirection direction = ViewDirection::Front) = 0;

		virtual void zoom(double dy) = 0;
	};
}

#endif // __ZOOM_MODEL_H__