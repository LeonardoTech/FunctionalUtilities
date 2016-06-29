////////////
//    created by 孙庆号
////////////

#ifndef __IMODULE_CORE_FACTORY_IOS_H__
#define __IMODULE_CORE_FACTORY_IOS_H__
#include "IModelCore.h"
#include <memory>
#include "config.h"

#ifdef __APPLE__
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#endif

namespace bimWorld
{
	class YIZHU_EXPORT IModelCoreFactoryIOS
	{
	public:
#ifdef __APPLE__
		virtual std::shared_ptr<IModelCore> getModule(UIView *view,
			bool isGLES2 = false, bool fixedFrameRate = false, int ratio = 2) = 0;
#endif // __APPLE__

	protected:
	};
}
#endif // __IMODULE_CORE_FACTORY_IOS_H__