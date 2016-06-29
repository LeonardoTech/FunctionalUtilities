////////////
//    created by 孙庆号
////////////

#ifndef __YZ_MODEL_CORE_MODULE_H__
#define __YZ_MODEL_CORE_MODULE_H__
#include "YZModelPlugin.h"
#include "config.h"

namespace bimWorld
{
	class YZModelCoreInternal;

	class YIZHU_EXPORT YZModelCoreModule :public YZModelPlugin < YZModelCoreInternal >
	{
		typedef YZModelPlugin < YZModelCoreInternal >  Base;
	public:
		YZModelCoreModule(YZModelCoreInternal* host);
	};
}

#endif // __YZ_MODEL_CORE_MODULE_H__