////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_ENTITY_INTERNAL_H__
#define __MODEL_ENTITY_INTERNAL_H__
#include <string>
#include "IModelEntity.h"
#include "EntitySharedData.h"
#include "ModelLoader.h"
#include "NodeEntityController.h"
#include "ProgressInfo.h"
#include "ZoomEntityModel.h"
#include "InteractionDefine.h"

namespace bimWorld
{
	class YZModelCoreInternal;

	class YIZHU_EXPORT YZModelEntityInternal :public IModelEntity
	{
	public:
		YZModelEntityInternal(YZModelCoreInternal* modelCore);

		SHARED_PROPERTY(bimWorld::EntitySharedData, _SharedData, m_sharedData, _modelCore);

		SHARED_PROPERTY(bimWorld::ModelLoader, _ModelLoader, m_modelLoader, this);

		SHARED_PROPERTY(bimWorld::NodeEntityController, _ControlByData, m_controlByData, this);
		
		SHARED_PROPERTY(bimWorld::ZoomEntityModel, _ZoomEntityModel, m_zoomEntityModel, this);

		SHARED_PROPERTY(bimWorld::ProgressInfo, _ProgressInfo, m_progressInfo, this);


		IMPLEMENT_INTERFACE(IModelLoader, _ModelLoader, ModelLoader);

		IMPLEMENT_INTERFACE(IZoomEntityModel, _ZoomEntityModel, ZoomEntityModel);
		
		IMPLEMENT_INTERFACE(INodeEntityController, _ControlByData, ControlByData);

		IMPLEMENT_INTERFACE(IProgressInfo, _ProgressInfo, ProgressInfo);

		YZModelCoreInternal* _modelCore;
	};
}

#endif // __MODEL_ENTITY_INTERNAL_H__