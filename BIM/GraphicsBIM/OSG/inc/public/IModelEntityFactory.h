////////////
//    created by 孙庆号
////////////

#ifndef __IMODEL_ENTITY_FACTORY_H__
#define __IMODEL_ENTITY_FACTORY_H__
#include "IModelCore.h"
#include "IModelEntity.h"
#include <memory>
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT IModelEntityFactory
	{
	public:
		virtual std::shared_ptr<IModelEntity> getModule(IModelCore* modelCore) = 0;
	protected:
	};
}
#endif // __IMODEL_ENTITY_FACTORY_H__