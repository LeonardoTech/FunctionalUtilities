////////////
//    created by 孙庆号
////////////

#include "ModelEntityFactory.h"
#include "YZModelEntityInternal.h"

std::shared_ptr<bimWorld::IModelEntity> bimWorld::ModelEntityFactory::getModule(IModelCore* modelCore)
{
	auto core = static_cast<YZModelCoreInternal*>(modelCore);
	if (!core)
	{
		return NULL;
	}
	return std::make_shared<YZModelEntityInternal>(core);
}
