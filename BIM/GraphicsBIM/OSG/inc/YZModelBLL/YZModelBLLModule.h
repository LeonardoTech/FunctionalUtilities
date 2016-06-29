////////////
//    created by 孙庆号
////////////

#ifndef __YZ_MODEL_BLL_MODULE_H__
#define __YZ_MODEL_BLL_MODULE_H__
#include "YZModelPlugin.h"
#include "config.h"

namespace bimWorld
{
	class IModelViewer;

	class YIZHU_EXPORT YZModelBLLModule :public YZModelPlugin < IModelViewer >
	{
		typedef YZModelPlugin < IModelViewer >  Base;
	public:
		YZModelBLLModule(IModelViewer* host);
	};
}

#endif // __YZ_MODEL_BLL_MODULE_H__