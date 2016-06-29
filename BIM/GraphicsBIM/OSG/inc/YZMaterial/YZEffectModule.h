////////////
//    created by 孙庆号
////////////

#ifndef __YZ_MATERIAL_MODULE_H__
#define __YZ_MATERIAL_MODULE_H__
#include "YZModelPlugin.h"
#include "config.h"

namespace bimWorld
{
	class YZEffect;

	class YIZHU_EXPORT YZEffectModule :public YZModelPlugin < YZEffect >
	{
		typedef YZModelPlugin < YZEffect >  Base;
	public:
		YZEffectModule(YZEffect* host);
	};
}

#endif // __YZ_MATERIAL_MODULE_H__