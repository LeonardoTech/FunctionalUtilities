////////////
//    created by 孙庆号
////////////

#ifndef __YZ_GRAPHICS_H__
#define __YZ_GRAPHICS_H__

#include "config.h"
#include "IGraphics.h"
#include "InteractionDefine.h"

namespace bimWorld
{
	class YIZHU_EXPORT YZGraphics : public IGraphics
	{
	public:
		YZGraphics();
		~YZGraphics();

		//SHARED_PROPERTY(bimWorld::MaterialSetting, _MaterialSetting, m_materialSetting, this);

		//IMPLEMENT_INTERFACE(bimWorld::IMaterialSetting, _MaterialSetting, MaterialSetting);

	private:

	};
}

#endif // __YZ_GRAPHICS_H__
