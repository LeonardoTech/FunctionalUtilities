////////////
//    created by 孙庆号
////////////

#ifndef __YZ_GRAPHICS_MODULE_H__
#define __YZ_GRAPHICS_MODULE_H__
#include "YZModelPlugin.h"
#include "config.h"

namespace bimWorld
{
	class YZGraphics;

	class YIZHU_EXPORT YZGraphicsModule :public YZModelPlugin < YZGraphics >
	{
		typedef YZModelPlugin < YZGraphics >  Base;
	public:
		YZGraphicsModule(YZGraphics* host);
	};
}

#endif // __YZ_GRAPHICS_MODULE_H__