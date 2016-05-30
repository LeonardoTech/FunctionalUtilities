////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_CORE_FACTORY_IOS_H__
#define __MODEL_CORE_FACTORY_IOS_H__
#include "IModelCore.h"
#include "IModelCoreFactoryIOS.h"
#include <osg/Node>
#include "YZModelCoreInternal.h"

namespace bimWorld{
	class ModelCoreFactoryIOS : public IModelCoreFactoryIOS{
	public:
#ifdef __APPLE__
		virtual std::shared_ptr<IModelCore> getModule(UIView *view,
			bool isGLES2 = false, bool fixedFrameRate = false, int ratio = 2) override;

		//bool readMaterialSettingFromFile(const char *fileName);
#endif
	protected:
		void setupShader(osg::Node *node, std::shared_ptr<YZModelCoreInternal> core);
		
		UIView *view;
		bool useGLES2, fixedFrameRate;
	};
}
#endif // __MODEL_CORE_FACTORY_IOS_H__