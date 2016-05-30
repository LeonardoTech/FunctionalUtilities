////////////
//    created by 孙庆号
////////////

#ifndef __IANIMATION_FACTORY_H__
#define __IANIMATION_FACTORY_H__
#include <memory>
#include "config.h"
#include "IAnimations.h"

namespace bimWorld
{
	class YIZHU_EXPORT IAnimationFactory
	{
	public:
		virtual std::shared_ptr<IAnimations> getModule() = 0;
	protected:
	};
}

#endif // __IANIMATION_FACTORY_H__