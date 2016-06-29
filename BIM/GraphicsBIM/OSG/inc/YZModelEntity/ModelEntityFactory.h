////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_ENTITY_FACTORY_H__
#define __MODEL_ENTITY_FACTORY_H__
#include "IModelEntityFactory.h"

namespace bimWorld
{
	class YIZHU_EXPORT ModelEntityFactory :public IModelEntityFactory
	{
	public:
		virtual std::shared_ptr<IModelEntity> getModule(IModelCore* modelCore) override;
	protected:
	private:
	};
}
#endif // __MODEL_ENTITY_FACTORY_H__