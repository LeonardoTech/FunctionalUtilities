////////////
//    created by 孙庆号
////////////

//
//  fireSelectionEvent.h
//  ModelViewer
//
//  Created by yizhu on 15-4-13.
//  Copyright (c) 2015年 wlw. All rights reserved.
//
#ifndef __FIRE_SELECTION_EVENT_H__
#define __FIRE_SELECTION_EVENT_H__

#include "FixedFramerate.h"

namespace bimWorld
{
	template<class ListenerSet>
	void fireSelectionEvent(const ListenerSet& modelViewerListeners, void** ptrs, size_t n)
	{
		typename ListenerSet::const_iterator begin = modelViewerListeners.begin(), end = modelViewerListeners.end();
		while(begin != end)
		{
			(*begin)->onSelect(ptrs, n);
			++begin;
		}
	}

	template<class ListenerSet>
	void fireModelLoadEvent(const ListenerSet& modelViewerListeners)
	{
		typename ListenerSet::const_iterator begin = modelViewerListeners.begin(), end = modelViewerListeners.end();
		while(begin != end)
		{
			(*begin)->onModelLoad();
			++begin;
		}
	}

	template<class ListenerSet>
	void fireModelUnloadEvent(const ListenerSet& modelViewerListeners)
	{
		typename ListenerSet::const_iterator begin = modelViewerListeners.begin(), end = modelViewerListeners.end();
		while(begin != end)
		{
			(*begin)->onModelUnload();
			++begin;
		}
	}
}

#endif // __FIRE_SELECTION_EVENT_H__