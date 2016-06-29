////////////
//    created by 孙庆号
////////////

#ifndef __YZ_MODEL_ENTITY_MODULE_H__
#define __YZ_MODEL_ENTITY_MODULE_H__
#include "YZModelPlugin.h"
#include "config.h"

namespace bimWorld
{
	class YZModelEntityInternal;

	class YIZHU_EXPORT YZModelEntityModule :public YZModelPlugin < YZModelEntityInternal >
	{
		typedef YZModelPlugin < YZModelEntityInternal >  Base;
	public:
		YZModelEntityModule(YZModelEntityInternal* host);
	};
}
#endif // __YZ_MODEL_ENTITY_MODULE_H__