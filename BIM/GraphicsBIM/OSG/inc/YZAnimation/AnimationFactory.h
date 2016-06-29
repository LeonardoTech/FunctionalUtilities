////////////
//    created by 孙庆号
////////////

#ifndef __ANIMATION_FACTORY_H__
#define __ANIMATION_FACTORY_H__
#include "IAnimationFactory.h"

namespace bimWorld
{
	class YIZHU_EXPORT AniamtionFactory : public IAnimationFactory
	{
	public:
		virtual std::shared_ptr<IAnimations> getModule() override;
	protected:
	};
}
#endif // __ANIMATION_FACTORY_H__