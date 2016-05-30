////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_VIEWER_IOS_H__
#define __MODEL_VIEWER_IOS_H__
#include "ModelViewer.h"
#ifdef __APPLE__
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#endif

namespace bimWorld
{
	class ModelViewerIOS : public ModelViewer
	{
	public:
#if __APPLE__
		ModelViewerIOS(UIView *view, int ratio,
			bool isGLES2 = false, bool fixedFrameRate = false);
#endif
	};
}
#endif // __MODEL_VIEWER_IOS_H__
