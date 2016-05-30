////////////
//    created by 孙庆号
////////////

#ifndef __IMODEL_ENTITY_H__
#define __IMODEL_ENTITY_H__
#include <memory>
#include "IModelLoader.h"
#include "INodeEntityController.h"
#include "IProgressInfo.h"
#include "IZoomEntityModel.h"

namespace bimWorld
{
	class YIZHU_EXPORT IModelEntity
	{
	public:
		virtual std::shared_ptr<IModelLoader> ModelLoader() = 0;

		virtual std::shared_ptr<IZoomEntityModel> ZoomEntityModel() = 0;

		virtual std::shared_ptr<INodeEntityController> ControlByData() = 0;

		virtual std::shared_ptr<IProgressInfo> ProgressInfo() = 0;
	};
}
#endif // __IMODEL_ENTITY_H__